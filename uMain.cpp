#include <vcl.h>
#pragma hdrstop

#include "uMain.h"
#include "uVinz.h"
#include "uRest.h"
#include "uDMcassa.h"
#include "uBani.h"
#include "uPrintSetup.h"
// #include "uInfoPerute.h"
#include "uProcedures.h"
#include "uInfoCasa.h"
#include "uFindBookedTicket.h"
#include "uSaledTicks.h"
#include "uzTOAD.h"
#include "LangDM.h"
#include "uSubscription.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TTF160_TLB"
#pragma link "shutdown"
#pragma link "UNWinSourceA"
#pragma link "LgSelect"
#pragma link "cxClasses"
#pragma link "dxBar"
#pragma link "dxBarApplicationMenu"
#pragma link "dxRibbon"
#pragma link "cxBarEditItem"
#pragma link "cxCalendar"
#pragma link "cxGraphics"
#pragma resource "*.dfm"
TfMain *fMain;

#define GFCREP if(isWasGFC) FinisareazileiGFC1Click(NULL);

#define SSCreateForm(a,b)  {if(!a) a=new b (Application);SagiSetupFormMDI(a);}
#define VerForm(a)             \
{                              \
  static bool bInside = false; \
  if (bInside)                 \
	return;                    \
  bInside = true;              \
  try                          \
  {                            \
	a                          \
  }                            \
  __finally                    \
  {                            \
	bInside = false;           \
  }                            \
}

// ---------------------------------------------------------------------------
TdxBarItemVisible DxBarVisible(bool Visible)
{
	if (!Visible)
		return ivNever;
	return ivAlways;
}
//---------------------------------------------------------------------------
__fastcall TfMain::TfMain(TComponent* Owner)
	: TForm(Owner)
{
	Caption = Caption + " on " + dmCassa->db->Username + "@" + dmCassa->db->Server + "; Nr" + dmCassa->NrCassa +
		"; Document nr:" + String(dmCassa->casaNrDoc) + " ver." + dmCassa->VersionInfo;
	// LockWindowUpdate(Handle);
	dmCassa->qsCasaTotals->Open();
	isWasGFC = true;
	fMain->ReportEnabled(false);
	UNWinSourceA1->Session = dmCassa->db;
	UNWinSourceA1->LoadAllDLLLibraries();
	ReportDP->EditValue = Date();
	scurt->Visible = DxBarVisible(!dmCassa->isPridn);
	DailyCasRep->Visible = DxBarVisible(dmCassa->isPridn);
	MiMiniReportsNew->Visible = DxBarVisible(dmCassa->isPridn);
	MiMiniReports->Visible = DxBarVisible(dmCassa->isPridn);
	bbSql->Visible = DxBarVisible(dmCassa->isAdmin);
}
// ---------------------------------------------------------------------------
void __fastcall TfMain::SagiSetupFormMDI(TForm *Sender)
{
  Sender->FormStyle = fsMDIChild;
  if ((Sender->WindowState == wsMaximized) && (Sender->Width < ClientWidth))
	Sender->WindowState = wsNormal;
  Sender->Show();
  Sender->WindowState = wsMaximized;
}
// ---------------------------------------------------------------------------
void __fastcall TfMain::SetToolbMode(bool ee)
{
	ToolbarButton971->Enabled = ee;
	ToolbarButton973->Enabled = ee;
	tbWind->Enabled = ee;
	ToolbarButton975->Enabled = ee;
	tbAux->Enabled = ee;
	SpeedButton1->Enabled = ee;

	toVinz->Enabled = ee;
	toRest->Enabled = ee;
	toAux->Enabled = ee;
	toExit->Enabled = ee;
	WindowClose1->Enabled = ee;
	ActRestart->Enabled = ee;
}

void __fastcall TfMain::Orar1Click(TObject *Sender)
{
	fVinz->Show();
	fVinz->WindowState = wsMaximized;
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::Sosire1Click(TObject *Sender)
{
	fRest->OpenClose(1);
	fRest->Show();
	fRest->WindowState = wsMaximized;
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::Primireapredareabanii1Click(TObject *Sender)
{
	fBaniiCassa->Show();
	fBaniiCassa->WindowState = wsMaximized;
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::FinisareazileiGFC1Click(TObject *Sender)
{
	dmCassa->GFC();
	fMain->ReportEnabled(true);
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::RestituireaBiletelor1Click(TObject *Sender)
{
	GFCREP
		// dmRpProcs->rRaportMonetar1(Date(), dmCassa->UserID, dmCassa->NrCassa, dmCassa->casaNrDoc);
	}
// ---------------------------------------------------------------------------

void __fastcall TfMain::Vinzareabiletelorcuinlesniri1Click(TObject *Sender)
{
	GFCREP
		// dmRpProcs->rRaportMonetar2(Date(), dmCassa->UserID, dmCassa->NrCassa, dmCassa->casaNrDoc);
	}
// ---------------------------------------------------------------------------

void __fastcall TfMain::Exei1Click(TObject *Sender)
{
	Application->Terminate();
}

// ---------------------------------------------------------------------------
void __fastcall TfMain::ReportEnabled(bool ee)
{
	isWasGFC = !ee;
	// RestituireaBiletelor2->Enabled=ee;
	// Vinzareabiletelorcuinlesniri2->Enabled=ee;
	// Raportmonetar2->Enabled=ee;
	// RestituireaBiletelor1

}
// ---------------------------------------------------------------------------


void __fastcall TfMain::Printersetup1Click(TObject *Sender)
{
	fPrintSetup->Caption = u"Настройка принтера";
	fPrintSetup->ShowModal();

	dmCassa->SQLMonitor->Active = fPrintSetup->cbxSqlMonitor->Checked;
}
// ---------------------------------------------------------------------------
#define DF_RUNREPORT(a,b) UNWinSourceA1->switchToWindow(0,"");UNWinSourceA1->switchToWindow(1,a);UNWinSourceA1->RunAction(b);

void __fastcall TfMain::RaportTotal2Click(TObject *Sender)
{
	// GFCREP
	// dmRpProcs->rConsolidatedReport(Date(), dmCassa->UserID, dmCassa->NrCassa, dmCassa->casaNrDoc);
	// ActiveMDIChild->Caption=ActiveMDIChild->Caption+" (raport urmator - F3)";

	// RaportSt1(FirstDayOfMonth(dtpPeriod->Date),LastDayOfMonth(dtpPeriod->Date));
	// UNWinSourceA1->P1=ExcTempl;
	GFCREP
		DF_RUNREPORT("RapMon", -1)
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::CloseClick(TObject *Sender)
{
	ActiveMDIChild->Close();
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::Maximize1Click(TObject *Sender)
{
	ActiveMDIChild->WindowState = wsMaximized;
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::Minimize1Click(TObject *Sender)
{
	ActiveMDIChild->WindowState = wsMinimized;
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::Print1Click(TObject *Sender)
{
	if (ActiveMDIChild->Name == "frmPreviewF1")
	{
		// ((TfrmPreviewF1*)ActiveMDIChild)->F1Book1->FilePrint(1);
	}

}
// ---------------------------------------------------------------------------
void __fastcall TfMain::specForF1Execute(TObject *Sender)
{
	if (ActiveMDIChild->Name == "frmPreviewF1")
	{
		// ((TfrmPreviewF1*)ActiveMDIChild)->F1Book1->Sheet=
		// ((((TfrmPreviewF1*)ActiveMDIChild)->F1Book1->Sheet==((TfrmPreviewF1*)ActiveMDIChild)->F1Book1->NumSheets)?
		// 1:((TfrmPreviewF1*)ActiveMDIChild)->F1Book1->Sheet+1);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::Informatiaperute1Click(TObject *Sender)
{
	// fInfoPeRute->ShowInfroPeRUTE();
	if (!fInfoCasa)
		fInfoCasa = new TfInfoCasa(NULL);
	fInfoCasa->Show();
	fInfoCasa->WindowState = wsMaximized;
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::Calculator1Click(TObject *Sender)
{
	WinExec("calc.exe", SW_SHOW);
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::Ultimulbiletneacceptat1Click(TObject *Sender)
{
	Orar1Click(NULL);
	fVinz->FindBadBilet();
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::scurtClick(TObject *Sender)
{
GFCREP
		dmCassa->PrintItog();
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::ActRestartExecute(TObject *Sender)
{
	String compName;
	if (GGetComputerName(compName))
	{
		if (compName.UpperCase().SubString(1, 3) == "CAS")
		{
			if (MessageDlg(fMain->LS->Text["relod"], mtConfirmation, TMsgDlgButtons() << mbNo << mbYes, 0) == mrYes);
			Shutdown1->Execute();
		}
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfMain::FormShow(TObject *Sender)
{
	// dmCassa->ProjectRun();
}
// ---------------------------------------------------------------------------

String __fastcall TfMain::UNWinSourceA1STRINGparam(
	String parames)
{
	if (parames == "casa")
		return dmCassa->NrCassa;
	else
		if (parames == "isPerrnZilnicRep")
			return dmCassa->isCassaPerron ? "1" : "";
	return "";
}
// ---------------------------------------------------------------------------

int __fastcall TfMain::UNWinSourceA1LONGparam(String parames)
{
	if (parames == "casir")
		return dmCassa->UserID;
	else
		if (parames == "nrdoc")
			return dmCassa->casaNrDoc;
		else
			if (parames == "data")
				return ReportDP->EditValue; // Date();
			else
				if (parames == "databeg" || parames == "dataend")
					return ReportDP->EditValue; // Date();
	return 0;
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::Listabiletelorvindute1Click(TObject *Sender)
{
	/* if(!fSaledTickets) Application->CreateForm(__classid(TfSaledTickets), &fSaledTickets);
	 fSaledTickets->WindowState=wsMaximized;
	 fSaledTickets->Show(); */
	dmCassa->viewSaledTickets();
}

// ---------------------------------------------------------------------------
void __fastcall TfMain::Raportmonetar1Click(TObject *Sender)
{
	GFCREP
		DF_RUNREPORT("RaportZilnic", -1)
}

// ---------------------------------------------------------------------------
void __fastcall TfMain::MiLangEngClick(TObject *Sender)
{
	dmLang->LM->UnLanguage = lnEng;
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::MiLangRomClick(TObject *Sender)
{
	dmLang->LM->UnLanguage = lnRom;
}

// ---------------------------------------------------------------------------
void __fastcall TfMain::MiLangRusClick(TObject *Sender)
{
	dmLang->LM->UnLanguage = lnRus;
}

// ---------------------------------------------------------------------------
void __fastcall TfMain::MiMiniReportsClick(TObject *Sender)
{
	if (MessageDlg(fMain->LS->Text["zrepfisc"], mtConfirmation, TMsgDlgButtons() << mbNo << mbYes, 0) == mrYes)
	{
		WideString MCmd = "102=";
		fPrintSetup->MiniReports(MCmd);
		MCmd = "502=";
		fPrintSetup->MiniReports(MCmd);
		MCmd = "501=";
		fPrintSetup->MiniReports(MCmd);
		MCmd = "101=";
		fPrintSetup->MiniReports(MCmd);
		MCmd = "507=";
		fPrintSetup->MiniReports(MCmd);
		MCmd = "510=";
		fPrintSetup->MiniReports(MCmd);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::DailyCasRepClick(TObject *Sender)
{
	GFCREP
		DF_RUNREPORT("DailyCasRep", -1)
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::MiMiniReportsNewClick(TObject *Sender)
{
	if (MessageDlg(fMain->LS->Text["zrepfisc"], mtConfirmation, TMsgDlgButtons() << mbNo << mbYes, 0) == mrYes)
	{
		WideString MCmd = "502=";
		fPrintSetup->MiniReports(MCmd);
		MCmd = "510=";
		fPrintSetup->MiniReports(MCmd);
		MCmd = "501=";
		fPrintSetup->MiniReports(MCmd);
		MCmd = "507=";
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::FormDestroy(TObject *Sender)
{
	if (dmCassa->bBookingMode)
		ExitWindowsEx(EWX_LOGOFF, 0);
}
// ---------------------------------------------------------------------------

void __fastcall TfMain::Subagent1Click(TObject *Sender)
{
	dmCassa->qq->SQL->Text = "begin gracontext.setval('show_days_cassalenta', '180'); end;";
	dmCassa->qq->Execute();

	if (fBookedTickets->qsUsers->Active)
		fBookedTickets->qsUsers->Close();

	if (fBookedTickets->qsCasalenta->Active)
		fBookedTickets->qsCasalenta->Open();

	fBookedTickets->qsUsers->Open();
	fBookedTickets->qsCasalenta->Open();
	fBookedTickets->qsBilets->Open();

	if (fBookedTickets->ShowModal() == mrOk)
	{
		if (fVinz->FindBookedTicket(fBookedTickets->qsCasalenta->FieldByName("id")->AsInteger))
			return;
	}

	dmCassa->qq->SQL->Text = "begin gracontext.setval('show_days_cassalenta', ''); end;";
	dmCassa->qq->Execute();
}
// ---------------------------------------------------------------------------



void __fastcall TfMain::tbAuxPopup(TObject *Sender)
{
	Print1->Enabled = bool(ActiveMDIChild->Name == "frmPreviewF1");
}
//---------------------------------------------------------------------------


void __fastcall TfMain::bbSqlClick(TObject *Sender)
{
///  if (!dmCassa->AdminLevel)
   // return;

  VerForm(SSCreateForm(fTOAD, TfTOAD))

  fTOAD->pcTOAD->ActivePageIndex = 1;
}
//---------------------------------------------------------------------------



void __fastcall TfMain::dxBarButton2Click(TObject *Sender)
{
	TOpenDialog* OpenDialog = new TOpenDialog(NULL);
	try
	{
		if (!OpenDialog->Execute(NULL))
			return;
		String sFile = OpenDialog->FileName;
		dmCassa->qq->SQL->Text = "begin pkg_ticket_import.import_iticket_csv(:file, :ruta, :data, :sectors); end;";
		dmCassa->qq->ParamByName("ruta")->AsString = "200168";
		dmCassa->qq->ParamByName("data")->AsString = "11.06.2015";
		dmCassa->qq->ParamByName("sectors")->AsString = "";
		dmCassa->qq->ParamByName("file")->ParamType = ptInput;
		dmCassa->qq->ParamByName("file")->AsOraClob->CreateTemporary(ltClob);
		dmCassa->qq->ParamByName("file")->AsOraClob->LoadFromFile(sFile);
		dmCassa->qq->ParamByName("file")->AsOraClob->WriteLob();
		dmCassa->qq->ExecSQL();
		dmCassa->qq->ParamByName("file")->AsOraClob->FreeLob();

		dmCassa->db->Commit();
	}
	__finally
	{
		delete OpenDialog;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfMain::bbCheckSubscriptionClick(TObject *Sender)
{
	SSCreateForm(fSubscription, TfSubscription);
}
//---------------------------------------------------------------------------

