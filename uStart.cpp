#include <vcl.h>
#pragma hdrstop

#include "uStart.h"
#include "uDMcassa.h"
#include "uProcedures.h"
#include "LangDM.h"
#include "uErrDialog.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MemDS"
#pragma link "Ora"
#pragma link "DBAccess"
#pragma link "LgSelect"
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
TfStart *fStart;

// ---------------------------------------------------------------------------
String __fastcall GetAppExeFileVersion()
{
  String asVersion;

  String asFileName = Application->ExeName;

  DWORD dwHandle;

  unsigned int nSize = GetFileVersionInfoSize(asFileName.c_str(), &dwHandle);
  Win32Check(nSize);

  wchar_t *pVerInfo = new wchar_t[nSize];
  try
  {
	Win32Check(GetFileVersionInfo(asFileName.c_str(), dwHandle, nSize, pVerInfo));

    int *pLang;
    if (VerQueryValue(pVerInfo, L"\\VarFileInfo\\Translation", (void**)&pLang, &nSize))
    {
      wchar_t *pFileVersion;
      String asResource = "\\StringFileInfo\\" +
          IntToHex(LOWORD(*pLang), 4) +
          IntToHex(HIWORD(*pLang), 4) + "\\FileVersion";

      VerQueryValue(pVerInfo, asResource.c_str(), (void**)&pFileVersion, &nSize);

      asVersion = pFileVersion;
    }
  }
  __finally
  {
    delete[] pVerInfo;
  }

  return asVersion;
}
//---------------------------------------------------------------------------
__fastcall TfStart::TfStart(TComponent *Owner) : TForm(Owner)
{
	String sRegPath = "Software\\UNISIM-SOFT\\\Tickets\CCCassa";
    String sFIniName;
	TRegistry* Reg = new TRegistry();
	try
	{
		Reg->RootKey = HKEY_CURRENT_USER;
		Reg->OpenKey(sRegPath, true);
		sFIniName = Reg->ReadString("IniFile");
		Reg->CloseKey();
	}
	__finally
	{
        delete Reg;
    }

	if (sFIniName == "")
		sFIniName = "rutacasa.ini";

	TIniFile *fini = new TIniFile(sFIniName);
	LangCB->ItemIndex = fini->ReadInteger("GENERAL", "DefaultLang", 0);
	dmCassa->iSelZoomPercent = fini->ReadInteger("GENERAL", "SelZoomPercent", 100);
	dmCassa->iAddSelZoomPercent = fini->ReadInteger("GENERAL", "AddSelZoomPercent", 100);
	dmCassa->bAddSelHideSoldPlacesCount = fini->ReadBool("GENERAL", "AddSelHideSoldPlacesCount", false);
	delete fini;
	dmLang->LM->UnLanguage = (TUnLanguage)LangCB->ItemIndex;
	dmCassa->UserID = 0;
	ccl = true;
	lblMetka->Top = pnlUsPa->Top;
	dmCassa->VersionInfo = GetAppExeFileVersion();
	Label8->Caption = "ver. "+ dmCassa->VersionInfo;
}

// ---------------------------------------------------------------------------
bool __fastcall TfStart::registerCompAndUser()
{
	String compName;
	if (!GGetComputerName(compName))
	{
		dmCassa->UserID = 0;
		ShowMessage(LS->Text["unknown"] + "\n " + LS->Text["network"]);
		return false;
	}

	dmCassa->spRegComp->ParamByName("CompID")->AsString = compName;
	dmCassa->spRegComp->ParamByName("vUserID")->AsInteger = dmCassa->UserID;
	try
	{
		dmCassa->spRegComp->ExecProc();
	}
	catch (Exception &E)
	{
		dmCassa->UserID = 0;
		ShowMessage(LS->Text["register"] + "\n" + E.Message);
		return false;
	}
	meDispName->Text = dmCassa->spRegComp->ParamByName("Result")->AsString;
	dmCassa->casaNrDoc = dmCassa->spRegComp->ParamByName("nrdoc")->AsInteger;
	if (dmCassa->casaNrDoc <= 0)
	{
		dmCassa->UserID = 0;
		ShowMessage(LS->Text["casadocument"] + "\n " +
			LS->Text["casablock"] + "\n");
		return false;
	}
	return dmCassa->casaNrDoc > 0;
}

// ---------------------------------------------------------------------------
bool __fastcall TfStart::IDVer()
{
	if (ShowModal() != mrOk || dmCassa->UserID == 0)
		Application->Terminate();
	return dmCassa->UserID;
}

// ---------------------------------------------------------------------------
void __fastcall TfStart::btOkClick(TObject *Sender)
{
	DoConnect();
	if( !FConnectDialog->Session->Connected )
		return;

	ccl = false;
	dmCassa->spAccess->ParamByName("user")->AsString = meOperName->Text;
	dmCassa->spAccess->ParamByName("passw")->AsString =
		meOperPasw->Text + meOperPasw1->Text;
	dmCassa->spAccess->ExecProc();
	dmCassa->UserID = dmCassa->spAccess->ParamByName("Result")->AsInteger;
	if (dmCassa->UserID)
	{
		if (!registerCompAndUser())
		{
			dmCassa->UserID = 0;
			return;
		}
		dmCassa->NrCassa = meDispName->Text;
		dmCassa->OpenAll();
		ModalResult = mrOk;
	}
	ccl = true;
  dmLang->ChangeDBLangSQL->Session = dmCassa->db;
	dmLang->LM->AfterSetLanguage(Sender);
}

// ---------------------------------------------------------------------------
void __fastcall TfStart::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	CanClose = ccl;
	ccl = true;
}

// ---------------------------------------------------------------------------
void __fastcall TfStart::FormKeyDown(TObject *Sender, WORD &Key,
	TShiftState Shift)
{
	if (Shift.Contains(ssCtrl) && Key == VK_F12)
	{
		meOperName->Text = "Pavel";
		meOperPasw->Text = "ppp";
		meDispName->Text = "0";
		if (edPassword->Text == "")
			edPassword->Text = edUsername->Text;
		btOk->Click();
	}
	else if (Shift.Contains(ssCtrl) && Key == 'I')
	{
		setVisORAPassw();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfStart::SpeedButton1Click(TObject *Sender)
{
	btOkClick(NULL);
}

// ---------------------------------------------------------------------------
void TfStart::DoInit()
{
	FRetries = FConnectDialog->Retries;
	Caption = FConnectDialog->Caption;

	lbUsername->Caption = FConnectDialog->UsernameLabel;
	lbPassword->Caption = FConnectDialog->PasswordLabel;
	lbServer->Caption = FConnectDialog->ServerLabel;
	// btConnect->Caption= FConnectDialog->ConnectButton;
	// btCancel->Caption= FConnectDialog->CancelButton;

	// dmCassa->db->sagiGetSessionsList(edServer->Items);
	extConfig = bool(edServer->Items->Count);
	if (!extConfig)
		FConnectDialog->GetServerList
			(edServer->Items /* ,dmCassa->db->Options->Net */);

	edServer->ItemIndex = 0;                                                          
	edUsername->Text = FConnectDialog->Session->Username;
	edPassword->Text = FConnectDialog->Session->Password;
	if (edPassword->Text == "" /*&& edUsername->Text.LowerCase() == "tickets"*/)
		edPassword->Text = edUsername->Text;
	edServer->Text = FConnectDialog->Session->Server;

	/* Ovidiu
	if ((edUsername->Text != "") && (edPassword->Text == ""))
	{
		setVisORAPassw();
		ActiveControl = edPassword;
	}
	*/
}

// ---------------------------------------------------------------------------
void __fastcall TfStart::setVisORAPassw()
{
	if( !pnlUsPa->Visible )
	{
		lblMetka->Top = pnlUsPa->Top + pnlUsPa->Height + 3;
	}
	else
	{
		lblMetka->Top = pnlUsPa->Top - pnlUsPa->Height - 3;
	}
	pnlUsPa->Visible = !pnlUsPa->Visible;
}
// ---------------------------------------------------------------------------
void TfStart::DoConnect()
{
	if (extConfig)
		dmCassa->db->sagiSetOraParams(edServer->Text);
	else
	{
		FConnectDialog->Session->Password = edPassword->Text;
		FConnectDialog->Session->Server = edServer->Text;
		FConnectDialog->Session->Username = edUsername->Text;
	}
	try
	{
		FConnectDialog->Session->Options->Net =
			FConnectDialog->Session->Server.Pos(":");
		FConnectDialog->Session->ConnectPrompt = false;
		FConnectDialog->Session->Connect();
	}
	catch (EOraError &E)
	{
		/*
		EOraError* s;
		s = new EOraError(E.ErrorCode, E.Message, E.Component);
		*/
		UniAccShowException(E.Message);
		FConnectDialog->Session->ConnectPrompt = true;
		FRetries--;
		if (FRetries == 0)
			ModalResult = mrCancel;
		switch (E.ErrorCode)
		{
		case 1005:
			ActiveControl = edPassword;
			break;
		case 1017:
			if (ActiveControl != edUsername)
				ActiveControl = edPassword;
			break;
		case 12203:
		case 12154:
			ActiveControl = edServer;
		}

	}
}

// ---------------------------------------------------------------------------
void __fastcall TfStart::SetConnectDialog(TConnectDialog *Value)
{
	FConnectDialog = Value;
	DoInit();
}

// ---------------------------------------------------------------------------
void initialization1(void);

#pragma startup initialization1

// ---------------------------------------------------------------------------
void initialization1(void)
{
	TMetaClass *MetaClass = __classid(TfStart);
	if (GetClass("TfStart") == NULL)
		RegisterClass(MetaClass);
}

// ---------------------------------------------------------------------------
void __fastcall TfStart::SpeedButton2Click(TObject *Sender)
{
	dmCassa->db->sagiEditSessionsList();
}

// ---------------------------------------------------------------------------
void __fastcall TfStart::LangCBChange(TObject *Sender)
{
	dmLang->LM->UnLanguage = (TUnLanguage)LangCB->ItemIndex;
}

// ---------------------------------------------------------------------------
void __fastcall TfStart::FormShow(TObject *Sender)
{
  if (dmCassa->bBookingMode)
  {
//      btOk->Click();
      btOkClick(this);
//      Close();
	ModalResult = mrOk;
  }
}
//---------------------------------------------------------------------------

