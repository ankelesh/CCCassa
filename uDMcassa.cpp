// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "uDMcassa.h"

#include "uMain.h"
#include "uPrintSetup.h"
#include "uProcedures.h"
#include "uUnivers.h"
#include "uStart.h"
#include "LangDM.h"
#include "uTipBilet.h"
#include "extgaralink.h"
#include "uSaledTicks.h"
#include "uVinz.h"
#include "uPrintListaImb.h"
#include "uControlPerr.h"
#include "uRetiparBil.h"
#include "Frdm.h"
#include "uCheckBroni.h"
#include "TSCPrinter.h"
#include "uSelect.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MemDS"
#pragma link "Ora"
#pragma link "OraSmart"
#pragma link "SagiODACSmartQueryLIB"
#pragma link "OraSQLMonitor"
#pragma link "DBAccess"
#pragma link "SagiOraSession"
#pragma link "DASQLMonitor"
#pragma link "OraCall"
#pragma resource "*.dfm"

TdmCassa *dmCassa;

// ---------------------------------------------------------------------------
__fastcall TdmCassa::TdmCassa(TComponent *Owner) : TDataModule(Owner)
{
	String compName;
	if (GGetComputerName(compName))
		if (compName.SubString(1, 3).UpperCase() == "CAS")
			new TMainInstance(NULL);

	if (db->Connected)
	{
		ShowMessage(
			"Warning! In exe Database property Connected=true \n STOP!");
		Abort();
	}
	/* try {
	 db->Connected=true;
	 }
	 catch(...)
	 {
	 db->Config();
	 db->Connected=true;
	 } */

	bBookingMode = false;

	String sServer, sUser, sPassword;

	if (GetCmdParam("b")) // booking mode
		if (GetCmdParam("s", sServer) && GetCmdParam("u", sUser) && GetCmdParam
			("p", sPassword))
			bBookingMode = true;

	if (bBookingMode)
	{
		db->sagiSetOraParams(sServer);
		db->Server = sServer;
		// db->Password = sPassword;
		// db->Username = sUser;

		try
		{
			db->Options->Net = db->Server.Pos(":");
			db->ConnectPrompt = false;

			db->Connect();

			spAccess->ParamByName("user")->AsString = sUser;
			spAccess->ParamByName("passw")->AsString = sPassword;
			spAccess->ExecProc();
			UserID = spAccess->ParamByName("Result")->AsInteger;
			if (UserID)
			{
				if (!registerCompAndUser())
					throw 0;
				dmLang->ChangeDBLangSQL->Session = db;
				dmLang->LM->AfterSetLanguage(NULL);
				OpenAll();
			}

		}
		catch (...)
		{
			db->ConnectPrompt = true;
			db->Connect();
		}
	}
	else
	  db->Connect();


	FrDMF->SetSession(db);

	slTicketPrint = new TStringList();
	slTicketPrint_SX = new TStringList();
	// Application->OnException = AppException;
}

// ---------------------------------------------------------------------------
bool TdmCassa::registerCompAndUser()
{
	String compName;
	if (!GGetComputerName(compName))
	{
		UserID = 0;
		return false;
	}

	spRegComp->ParamByName("CompID")->AsString = compName;
	spRegComp->ParamByName("vUserID")->AsInteger = UserID;
	try
	{
		spRegComp->ExecProc();
	}
	catch (Exception &E)
	{
		UserID = 0;
		return false;
	}
	NrCassa = spRegComp->ParamByName("Result")->AsString;
	casaNrDoc = spRegComp->ParamByName("nrdoc")->AsInteger;
	if (casaNrDoc <= 0)
	{
		UserID = 0;
		return false;
	}
	return casaNrDoc > 0;
}

// ---------------------------------------------------------------------------
bool TdmCassa::GetCmdParam(String sParam)
{
	String s;
	return GetCmdParam(sParam, s);
}

// ---------------------------------------------------------------------------
bool TdmCassa::GetCmdParam(String sParam, String &sValue)
{
	for (int i = 1; i < ParamCount(); i++)
	{
		String sParamName = ParamStr(i).SubString(2, ParamStr(i).Length() - 1);
		if (sParamName == sParam)
		{
			if (ParamStr(i + 1) != NULL && ParamStr(i + 1)[1] != '\\')
				sValue = ParamStr(i + 1);

			return true;
		}
	}
	return false;
}

// ---------------------------------------------------------------------------
void __fastcall TdmCassa::ProjectRun(int mode)
{
	setSessionUniv(db);
}

// ---------------------------------------------------------------------------
double __fastcall StrToFloatUNIAC1(String Astring)
{
	return _wtof(StringReplace(Astring, ",", ".",
		TReplaceFlags() << rfReplaceAll).c_str());
	/*
	 try {
	 int i=1;
	 for (int i=1;i<Astring.Length();i++)
	 if (Astring[i]==*",") Astring[i]=*".";
	 return _wtof(Astring.c_str());
	 } catch(...) {return 0.0;}
	 */
}

// ---------------------------------------------------------------------------
void __fastcall TdmCassa::OpenAll()
{
	callProc("GARASTART", "");
	qsDocs->ParamByName("COD")->AsInteger = casaNrDoc;
	qsDocs->Open();
	if (qsDocs->RecordCount == 0)
	{
		throw Exception("Document casierul na fost inregistrat.");
	}
	qsD_Cassa->Open();
	qsD_CassaP->Open();
	qsCasaTotals->ParamByName("CASA")->AsString = NrCassa;
	qsCasaTotals->ParamByName("CASIR")->AsInteger = UserID;
	qsCasaTotals->ParamByName("DATA")->AsDateTime =
		qsDocsDATAMANUAL->AsDateTime;
	String dss = (qsDocsDATAMANUAL->AsDateTime - 1).DateTimeString();
	try
	{
		soldStart = StrToFloatUNIAC1(callProc("GRA.GETSOLDFORCASIR", dss));
	}
	catch (...)
	{
	}

	qq->Close();
	qq->SQL->Text = "SELECT ISPERRONVINZ, ISPERRON, isBroni\
	, SYS_CONTEXT('GRACONTEXT','def_Val') defval , nvl(SYS_CONTEXT('GRACONTEXT','ispridn'),'0') ispridn \
	, isAdmin\
		 FROM T0CASSA WHERE COD='" + NrCassa + "'";
	qq->Open();
	isCassaPerron = qq->FieldByName("ISPERRON")->AsInteger;
	isCassaPerronVinzare = qq->FieldByName("ISPERRONVINZ")->AsInteger;
	isBroni = qq->FieldByName("isBroni")->AsInteger;
	isPridn = qq->FieldByName("ispridn")->AsInteger;
	isAdmin = qq->FieldByName("isadmin")->AsInteger;
	defValuta = qq->FieldByName("defval")->AsString;
	SessValuta = defValuta;
	SessValutaDepCode = -1;
	qq->Close();
	DB_Commit();
}

// ---------------------------------------------------------------------------
String __fastcall TdmCassa::callProc(String FN, String p1,
	String p2, String p3)
{
	spCF->ParamByName("fn")->AsString = FN;
	spCF->ParamByName("P1")->AsString = p1;
	spCF->ParamByName("P2")->AsString = p2;
	spCF->ParamByName("P3")->AsString = p3;
	spCF->ExecProc();
	return spCF->ParamByName("Result")->AsString;

}

// ---------------------------------------------------------------------------
bool __fastcall TdmCassa::LockRutaTable(TDateTime vDATA, String vRUTA,
	int isCloseAutomat)
{
	bool isRutaBusy = 1;
	try
	{
		qqIsVinzEn->Close();
		qqIsVinzEn->ParamByName("CODU")->AsString = vRUTA;
		qqIsVinzEn->ParamByName("DATA")->AsDateTime = vDATA;
//**   		qqIsVinzEn->Open();
		if (isCloseAutomat)
			qqIsVinzEn->Close();
	}
	catch (...)
	{
		isRutaBusy = 0;
	}
	return isRutaBusy;
}

// ---------------------------------------------------------------------------
bool __fastcall TdmCassa::davaiProdavai(int CntBlt, TList* mesta, TDateTime vDATA,
	String vRUTA, long vDEST, long vGARA, long TipBiletSpecial,
	int BroniTipSelected, String sLocsInpManual)
{
	long iTRS = 0;
	// String ddd[45];
	// TDate gdd=Now();

	qsV1_CASALENTA->Close();
	qsBiltets->Close();
	// ddd[0]=Now()-gdd;
	// qsBiltets->SagiFilterSYS="";
	if (BroniTipSelected != 2)
		DB_Rollback();
	// ddd[1]=Now()-gdd;
	try
	{
		String pp1 = "";

		if (TipBiletSpecial <= 0) // обычный билет
		{
			if (sLocsInpManual != "")
				pp1 = sLocsInpManual;
			else
			{
				for (int i = 0; i < mesta->Count; i++)
        {
          pp1 += String(*(int*)mesta->Items[i]) + ",";
        }
        /*
				for (int i = 0; i < CntBlt; i++)
					if (mesta[i] > 0)
						pp1 = pp1 + String(mesta[i]) + ",";
       */
				if (pp1.Length() > 1) // удаляем последнюю запятую
						pp1 = pp1.SubString(1, pp1.Length() - 1);
			}
		}
		else
		{
			CntBlt = 1;
			pp1 = "200";
		}

		spWonaToSell->ParamByName("vRUTA")->AsString = vRUTA;
		spWonaToSell->ParamByName("vDATA")->AsDateTime = vDATA;
		spWonaToSell->ParamByName("vBILETCOUNT")->AsInteger = CntBlt;
		spWonaToSell->ParamByName("vLOCURES")->AsString = pp1;
		spWonaToSell->ParamByName("vCODORAS")->AsInteger = vDEST;
		spWonaToSell->ExecProc();


		dmCassa->qq->SQL->Text =
		"declare\
		  pragma autonomous_transaction;\
		begin\
		  pkg_places.lock_places_for_print;\
		  commit;\
		end;";
		dmCassa->qq->Execute();

		// ddd[2]=Now()-gdd;
		db->StartTransaction();
		// ddd[3]=Now()-gdd;

		if (LockRutaTable(vDATA, vRUTA) == 0)
		{
			ShowMessage(fMain->LS->Text["routeblock"]);
			DB_Rollback();
			return false;
		}
		// ddd[4]=Now()-gdd;

		if (fVinz->cbxBroni->Checked == false || BroniTipSelected == 2)
			iTRS = callProc("GRA.CASACACHEDELIVERYTRANSACTION", "0").ToInt();
		else
		{
			qq->Close();
			qq->SQL->Text =
				"begin :Rez:=broni.CASACACHEDELIVERYTRANSACTION( :vTipBRONI, :vRUTA, :vDATA, :vBILETCOUNT); end;";
			qq->Prepare();
			qq->ParamByName("Rez")->ParamType = ptOutput;
			qq->ParamByName("Rez")->DataType = ftInteger;
			qq->ParamByName("vTipBRONI")->AsInteger = 0;
			qq->ParamByName("vDATA")->AsDateTime = vDATA;
			qq->ParamByName("vRUTA")->AsString = vRUTA;
			qq->ParamByName("vBILETCOUNT")->AsInteger = CntBlt;
			qq->ExecSQL();
			iTRS = qq->ParamByName("Rez")->AsInteger;
			qq->Close();
		}

		// ddd[5]=Now()-gdd;
		spDavaiProd->ParamByName("vDATA")->AsDateTime = vDATA;
		spDavaiProd->ParamByName("vRUTA")->AsString = vRUTA;
		spDavaiProd->ParamByName("vCASIR")->AsInteger = UserID;
		spDavaiProd->ParamByName("vCASA")->AsString = NrCassa;
		spDavaiProd->ParamByName("vCODORAS")->AsInteger = vDEST;
		spDavaiProd->ParamByName("vCODGARA")->AsInteger = vGARA;
		spDavaiProd->ParamByName("vIDCASLENTA")->AsInteger = iTRS;

		spDavaiProd->ParamByName("STRLOCSEL")->AsString = pp1;
		spDavaiProd->ParamByName("vNRLOCSEL")->AsInteger = CntBlt;
		// 1 - broni
		spDavaiProd->ParamByName("vBroni_ORD_RES")->AsInteger =
			fVinz->cbxBroni->Checked;

		// ddd[7]=Now()-gdd;
		spDavaiProd->ExecProc();
		// ddd[8]=Now()-gdd;

	}
	catch (EOraError& e)
	{
		if (e.Message.Pos("T0BILET_LOC_OCUPAT"))
		{
			ShowMessage(fMain->LS->Text["loc_ocupat"]);
			DB_Rollback();
			Abort();
		}
		fSelRuta->UnlockLockedPlaces();

				throw;
	}
	catch (...)
	{
		DB_Rollback();
		fSelRuta->UnlockLockedPlaces();
		throw;
	}
	// ddd[9]=Now()-gdd;

	if (!GotoCasaOper(iTRS))
	{
		ShowMessage(StringReplace(fMain->LS->Text["notranz"], "|", "\n",
			TReplaceFlags() << rfReplaceAll));

		DB_Rollback();
		return false;
	}
	// ddd[10]=Now()-gdd;
	dsV1_CASALENTA->Enabled = true;
	// ddd[11]=Now()-gdd;
	qsBiltets->ReadOnly = false;
	qsBiltets->Open();
	// ddd[12]=Now()-gdd;

	return true;

}
// ---------------------------------------------------------------------------

void __fastcall TdmCassa::qsBiltetsBeforeInsert(TDataSet *DataSet)
{
	Abort();
}
// ---------------------------------------------------------------------------

void __fastcall TdmCassa::qsBiltetsBeforeEdit(TDataSet *DataSet)
{
	/* if(qsBiltetsPRINTS->AsInteger)  //qsBiltetsCODADD->IsNull==false)
	 {
	 ShowMessage("I02 - Scuzati, redactare imposibila.\nAnulati si incercati inca odata \n\n Извините, но редактирование во 2-й раз невозможно, \n отмените операцию и попробуйте ещё раз.");
	 Abort();
	 }
	 */
}
// ---------------------------------------------------------------------------

void __fastcall TdmCassa::qsV1_CASALENTASUMA_PRIMChange(TField *Sender)
{
	qsV1_CASALENTACalcFields(NULL);
}
// ---------------------------------------------------------------------------

void __fastcall TdmCassa::qsV1_CASALENTACalcFields(TDataSet *DataSet)
{
	calcRest(isPridn && fVinz->NotDefValuta() ?
		(qsV1_CASALENTASUMAVAL_PRIM->AsFloat) :
		(qsV1_CASALENTASUMA_PRIM->AsFloat));
}

// ---------------------------------------------------------------------------
void __fastcall TdmCassa::calcRest(double suma)
{
	if (!isPridn || !fVinz->NotDefValuta())
		qsV1_CASALENTAclcSumaRest->AsFloat = suma ?
			-qsV1_CASALENTASUMA_PACH->AsFloat + suma : 0.00;
	else
	{
		qsV1_CASALENTAclcSumaRest->AsFloat = suma ?
			-qsV1_CASALENTASUMAVAL_PACH->AsFloat + suma : 0.00;

	}
}

// ---------------------------------------------------------------------------
void __fastcall TdmCassa::qsBiletAddNewRecord(TDataSet *DataSet)
{
	//
}
// ---------------------------------------------------------------------------

void __fastcall TdmCassa::anuVerniom(String vBilet, int mm, String Rtip,
	TDateTime vDATA, String vRUTA)
{
	if (mm == 0)
	{
		qsV1_CASALENTA->Close();
		DB_Rollback();

		spWonaToSell->ParamByName("vRUTA")->AsString = vRUTA;
		spWonaToSell->ParamByName("vDATA")->AsDateTime = vDATA;
		spWonaToSell->ParamByName("vBILETCOUNT")->AsInteger = -1;
		spWonaToSell->ParamByName("vLOCURES")->AsString = "Restituirea";
		spWonaToSell->ParamByName("vCODORAS")->AsInteger = 0;
		spWonaToSell->ExecProc();

		db->StartTransaction();
		if (LockRutaTable(vDATA, vRUTA, false) == 0)
		{
			ShowMessage(fMain->LS->Text["routeblock2"]);
			DB_Rollback();
			return;
		}
		long iTRS = callProc("GRA.CASACACHEDELIVERYTRANSACTION", "0", vBilet,
			Rtip).ToInt();

		if (!GotoCasaOper(iTRS))
		{
			ShowMessage(fMain->LS->Text["norettranz"]);

			return;
		}
		dsV1_CASALENTA->Enabled = true;
	}

}

// ---------------------------------------------------------------------------
void __fastcall TdmCassa::qsCasaTotalsAfterOpen(TDataSet *DataSet)
{
	RefreshTotals();
}

// ---------------------------------------------------------------------------
void __fastcall TdmCassa::qsV1_CASALENTAAfterOpen(TDataSet *DataSet)
{
	if (db->InTransaction == false)
		RefreshTotals(1); // qsCasaTotals->RefreshQuery();
	fMain->ReportEnabled(false);
}

// ---------------------------------------------------------------------------
// Inainte exista un singur event qsV1_CASALENTAAfterOpen, legat de AfterPost
//la qsD_Cassa si la alte SmartQuery, ce nu e corect
void __fastcall TdmCassa::qsD_CassaAfterPost(TDataSet *DataSet)
{
	if (db->InTransaction == false)
		RefreshTotals(1); // qsCasaTotals->RefreshQuery();
	fMain->ReportEnabled(false);
	//CashInput
	fPrintSetup->CashInOut(qsD_CassaSUMA->AsInteger);
}

// ---------------------------------------------------------------------------
// Inainte exista un singur event qsV1_CASALENTAAfterOpen, legat de AfterPost
//la qsD_Cassa si la alte SmartQuery, ce nu e corect
void __fastcall TdmCassa::qsD_CassaPAfterPost(TDataSet *DataSet)
{
	if (db->InTransaction == false)
		RefreshTotals(1); // qsCasaTotals->RefreshQuery();
	fMain->ReportEnabled(false);
	//CashOutput
	fPrintSetup->CashInOut(-qsD_CassaPSUMA->AsFloat);
}

// ---------------------------------------------------------------------------
void __fastcall TdmCassa::GFC()
{
	callProc("GRA.GENDOCS_CASA", String(casaNrDoc));
}

// ---------------------------------------------------------------------------
void __fastcall TdmCassa::BileteAnulare()
{
	if (qsT1RUTABRONI->Active && ISEDIT(qsT1RUTABRONI))
	{
		CANCEL(qsT1RUTABRONI)
		CANCEL(qsT1RUTABRONIDETAILS)
    CANCEL(qsCASALENTA_PAYTYPE)
		if (ISEDIT(qsBiltets))
			CANCEL(qsBiltets)
			if (ISEDIT(qsV1_CASALENTA))
				CANCEL(qsV1_CASALENTA) DB_Rollback();
	}
	if (qsV1_CASALENTA->Active)
		qsV1_CASALENTA->Refresh();
	if (qsBiltets->Active)
		qsBiltets->Refresh();
	RefreshTotals(1);
}
// ---------------------------------------------------------------------------
String LeftPad(String Text, wchar_t Symbol, int TotalWidth, wchar_t EndSymbol)
{
	int TextLength = Text.Length(); // 8
	int EndSymbolPos = Text.Pos(EndSymbol); // 6
	int EndSymbolLength = TextLength - EndSymbolPos + 1;
	int FillLength = TotalWidth + EndSymbolLength - TextLength;

	if (TextLength - EndSymbolLength < TotalWidth)
	{
		TotalWidth += EndSymbolLength;
		Text.SetLength(TotalWidth);

		for (int i = TotalWidth - EndSymbolLength + 1; i <= TotalWidth; i++)
		{
			Text[i] = Text[i - FillLength];
			Text[i - FillLength] = Symbol;
		}

		for (int i = TextLength - EndSymbolLength + 2; i <= TotalWidth - EndSymbolLength; i++)
			Text[i] = Symbol;
	}

	return Text;
}
// ---------------------------------------------------------------------------

void __fastcall TdmCassa::BileteLaTipar(int mpde, int pay_type, bool isBroni)
	// mpde - 0 превая печать 1 - повторная
	// pay_type 1-numerar, 2-card. Implicit=1
{
		bool bShowScriptOnly = GetKeyState(VK_LCONTROL) < 0;

	// fMain->stb->Panels->Items[0]->Text=fMain->stb->Panels->Items[0]->Text+" 0";
	int PrintBiletOnlyCurrent = 0; // mrYes;
	double CasaTotalSuma;
	bool PrTranzRez;
	String CurTickCod;
	TStringList *SL = new TStringList();
	// Для Приднестровья берем сумму в валюте
	if (isPridn)
	{
		CasaTotalSuma = qsV1_CASALENTASUMAVAL_PACH->AsFloat;
		if (CasaTotalSuma == 0)
			CasaTotalSuma = qsV1_CASALENTASUMA_PACH->AsFloat;
	}
	else
		CasaTotalSuma = qsV1_CASALENTASUMA_PACH->AsFloat;
	// Смотрим надо ли билеты печатать отдельно
	bool PrintTicksApart = fPrintSetup->PrintTicksApart->Checked;

	if (ISEDIT(qsT1RUTABRONI))
		POST(qsT1RUTABRONI)
	if (ISEDIT(qsT1RUTABRONIDETAILS))
		POST(qsT1RUTABRONIDETAILS)
	if (ISEDIT(qsCASALENTA_PAYTYPE))
	{
    POST(qsCASALENTA_PAYTYPE)
	}
	callProc("GRA.CASADELIVERYTRANSACTIONVERIFY", qsV1_CASALENTAID->AsString);
	if (ISEDIT(qsV1_CASALENTA))
		POST(qsV1_CASALENTA)

	//La prima printare inregistram in baza tipul de plata
	if(!mpde && !isBroni){
		qq->Close();
		qq->SQL->Text ="begin "
			"pkg_alf.payment_type(:id_cas, :type); "
			" end;";
		qq->ParamByName("id_cas")->AsString = qsV1_CASALENTAID->AsString;
		qq->ParamByName("type")->AsString = pay_type;
		qq->ExecSQL();
	}
	//

	BilCommit(false);

	if (!CasaTotalSuma && isBroni && !isBroniLaPlata)
		return;
	if (!this->UserCanPrint)
		return;

	if (mpde)
		// ||(PrintBiletOnlyCurrent=MessageDlg("I01 - Tiparim toate bilete de la inceput ?\n( [No] - de la bilet current \n [Cancel] - numai bilet current)  \n\n Распечатать билеты с самого \n первого (если нет [No] - с текущего билета \n [Cancel] - только текущий билет )", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo << mbCancel, 0)) == mrYes)
	{
		PrintBiletOnlyCurrent = retiparBileta();
		if (PrintBiletOnlyCurrent < 0)
			return;
		if (fRetiparBil->cbBiletZero->Checked)
			CasaTotalSuma = 0.0;
	}

	if (PrintBiletOnlyCurrent == 0)
		qsBiltets->First();
	// aa else qsT0BILET->Locate( "COD",qsBiltetsCOD->AsString,TLocateOptions());
	qq->Close();
	db->StartTransaction();
	if (!PrintTicksApart)
	{
		BeginPrintTransaction();
		if (fPrintSetup->rgPrinterType->ItemIndex < 2) // printer
				PrintString(
			"\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24");
	}

	slTicketPrint->Clear();
	slTicketPrint_SX->Clear();
	qsBiltets->DisableControls();
	TBookmark vBookmark = qsBiltets->GetBookmark();
	try
	{
		if (qsBiltets->Eof)
		{
			qsBiltets->Prior();
			qsBiltets->Next();
		}


		while (!qsBiltets->Eof)
		{
			// print(qsT0BILET->COD,qsT0BILET->TPR)
			// if (net)
			// aa if(qsBiltets->Locate( "COD",qsT0BILETCOD->AsString,TLocateOptions()))

			if (PrintTicksApart)
			{
				BeginPrintTransaction();
				if (fPrintSetup->rgPrinterType->ItemIndex < 2) // printer
						PrintString(
					"\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24");
				PrintString(qsBiltetsCECU->AsString);
				//fPrintSetup->PrintNFTextDAISY_SX(qsBiltetsCECU->AsString);
				PrTranzRez = EndPrintTransaction(true, 0, qsBiltetsSUMAT->AsFloat,
					0, SessValutaDepCode, qsV1_CASALENTAID->AsInteger);
				if (!PrTranzRez)
				{
					RegError(qsBiltetsCOD->AsString);
				}
				if (fPrintSetup->EdSleepAfterTick->Enabled &&
					(fPrintSetup->EdSleepAfterTick->Text.Length()))
					Sleep(StrToInt(fPrintSetup->EdSleepAfterTick->Text.Trim()
					) *1000);
			}
			else
			{
				PrintString(qsBiltetsCECU->AsString);
				//fPrintSetup->PrintNFTextDAISY_SX(qsBiltetsCECU->AsString);
				SL->Add(qsBiltetsCOD->AsString);
				//String Product = "Bilet " + qsBiltetsCOD->AsString + ";A;" + qsBiltetsSUMAT->AsString + "*1";
				if (CasaTotalSuma > 0 &&
					qsBiltetsINLESN->AsString != "MT" &&
					qsBiltetsINLESN->AsString != "M" &&
					qsBiltetsSUMAT->AsInteger > 0)
				{
					String Product = "Bilet;A;" + qsBiltetsSUMAT->AsString + "*1";
					slTicketPrint->Add(LeftPad(Product, ' ', 36, ';'));
				}
			}
			try
			{
				qq->SQL->Text =
					"UPDATE T0BILET SET PRINTS=nvl(PRINTS,0)+1 WHERE COD=:COD";
				qq->ParamByName("COD")->AsString = qsBiltetsCOD->AsString;
				qq->ExecSQL();
				BilCommit(false);
			}
			catch (...)
			{
				if (PrintTicksApart)
				{
					if (fPrintSetup->rgPrinterType->ItemIndex < 2) // printer
							PrintString("\n\n\n\n\n\n\n\n\n\n\n");
					PrTranzRez = EndPrintTransaction(!true, 0,
						qsBiltetsSUMAT->AsFloat, 0, SessValutaDepCode,
						qsV1_CASALENTAID->AsInteger);
					if (!PrTranzRez)
					{
						RegError(qsBiltetsCOD->AsString);
					}
				}
				else
					PrTranzRez = EndPrintTransaction(!true, 0, CasaTotalSuma, 0,
					SessValutaDepCode, qsV1_CASALENTAID->AsInteger);
				if (!PrTranzRez)
				{
					RegError(qsBiltetsCOD->AsString);
				}
				DB_Rollback();
				throw;
			}
			if (PrintBiletOnlyCurrent == 2) // только текущий
				break;
			qsBiltets->Next();
		}
		fPrintSetup->slTickets = slTicketPrint;
		fPrintSetup->ReceivedSumm = qsBiltetsSUMAT->AsFloat;

		if (!PrintTicksApart)
		{
			if (fPrintSetup->rgPrinterType->ItemIndex < 2) // printer
					PrintString("\n\n\n\n\n\n\n\n\n\n\n");
			PrTranzRez = EndPrintTransaction(true, 0, CasaTotalSuma, 0,
				SessValutaDepCode, qsV1_CASALENTAID->AsInteger);
			if (!PrTranzRez)
			{
				for (int i = 0; i < SL->Count; i++)
					RegError(SL->Strings[i]);
			}
		}

		if (fPrintSetup->rgReportPrinterType->ItemIndex > 1)
		{
			BeginPrintTransaction(1);

			// Инициализация драйвера принтера TSC
			TTSCPrinterHelper* TSC = new TTSCPrinterHelper("tsclib.dll", fPrintSetup->ReportPrinterPath->Text);
			try
			{
				if (!TSC->Active)
				{
					ShowMessage("Unable to load tsclib.dll");
					return;
				}

				if (fPrintSetup->rgReportPrinterType->ItemIndex == 2) // Template
				{
					qsBiltets->GotoBookmark(vBookmark);
					for (; !qsBiltets->Eof; qsBiltets->Next())
					{
						spGetPrnScript->ParamByName("P_TICKET_NR")->AsString = qsBiltetsCOD->AsString;
						spGetPrnScript->ParamByName("P_TICKET_TYPE")->AsString = fPrintSetup->cbTicketType->Text;
						spGetPrnScript->Execute();

						String sScript = spGetPrnScript->ParamByName("result")->AsString;

						if (bShowScriptOnly)
							throw Exception(sScript);

						TSC->Sendcommand(sScript);

						if (PrintBiletOnlyCurrent == 2) // только текущий
							break;
					}
				}
			}
			__finally
			{
				delete TSC;
			}

			EndPrintTransaction1(true, 1);
		}
	}
	__finally
	{
		qsBiltets->GotoBookmark(vBookmark);
		qsBiltets->FreeBookmark(vBookmark);
		qsBiltets->EnableControls();
		}

	BilCommit();
}

//Procedura de tiparire a bonurilor e similara cu cea biletelor
void __fastcall TdmCassa::BonuriLaTipar(int mpde)
	// mpde - 0 превая печать 1 - повторная
{

	int PrintBiletOnlyCurrent = 0; // mrYes;
	double CasaTotalSuma;
	bool PrTranzRez;
	String CurTickCod;
	TStringList *SL = new TStringList();
	// Для Приднестровья берем сумму в валюте
	if (isPridn)
	{
		CasaTotalSuma = qsV1_CASALENTASUMAVAL_PACH->AsFloat;
		if (CasaTotalSuma == 0)
			CasaTotalSuma = qsV1_CASALENTASUMA_PACH->AsFloat;
	}
	else
		CasaTotalSuma = qsV1_CASALENTASUMA_PACH->AsFloat;
	// Смотрим надо ли билеты печатать отдельно
	bool PrintTicksApart = fPrintSetup->PrintTicksApart->Checked;

	if (ISEDIT(qsT1RUTABRONI))
		POST(qsT1RUTABRONI)
	if (ISEDIT(qsT1RUTABRONIDETAILS))
	{
		POST(qsT1RUTABRONIDETAILS)
	}
	if (ISEDIT(qsCASALENTA_PAYTYPE))
	{
    POST(qsCASALENTA_PAYTYPE)
	}
	callProc("GRA.CASADELIVERYTRANSACTIONVERIFY", qsV1_CASALENTAID->AsString);
	if (ISEDIT(qsV1_CASALENTA))
		POST(qsV1_CASALENTA)

//	BilCommit(false);

	if (!CasaTotalSuma && isBroni && !isBroniLaPlata)
		return;
	if (!this->UserCanPrint)
		return;

	if (PrintBiletOnlyCurrent == 0)
		qsBiltets->First();
	// aa else qsT0BILET->Locate( "COD",qsBiltetsCOD->AsString,TLocateOptions());
	qq->Close();
//	db->StartTransaction();
	if (!PrintTicksApart)
	{
		BeginPrintTransaction();
		if (fPrintSetup->rgPrinterType->ItemIndex < 2) // printer
				PrintString(
			"\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24");
	}

	slTicketPrint->Clear();
	slTicketPrint_SX->Clear();

	qsBiltets->DisableControls();
	TBookmark vBookmark = qsBiltets->GetBookmark();
	try
	{
		if (qsBiltets->Eof)
		{
			qsBiltets->Prior();
			qsBiltets->Next();
		}


		while (!qsBiltets->Eof)
		{
			// print(qsT0BILET->COD,qsT0BILET->TPR)
			// if (net)
			// aa if(qsBiltets->Locate( "COD",qsT0BILETCOD->AsString,TLocateOptions()))

			if (PrintTicksApart)
			{
				BeginPrintTransaction();
				if (fPrintSetup->rgPrinterType->ItemIndex < 2) // printer
						PrintString(
					"\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24\x1b\x6a\x24");
				PrintString(qsBiltetsCECU->AsString);
				PrTranzRez = EndPrintTransaction(true, 0, qsBiltetsSUMAT->AsFloat,
					0, SessValutaDepCode, qsV1_CASALENTAID->AsInteger);
				if (!PrTranzRez)
				{
					RegError(qsBiltetsCOD->AsString);
				}
				if (fPrintSetup->EdSleepAfterTick->Enabled &&
					(fPrintSetup->EdSleepAfterTick->Text.Length()))
					Sleep(StrToInt(fPrintSetup->EdSleepAfterTick->Text.Trim()
					) *1000);
			}
			else
			{
				//PrintString(qsBiltetsCECU->AsString); comentat
				//SL->Add(qsBiltetsCOD->AsString);

				//String Product = "Bilet " + qsBiltetsCOD->AsString + ";A;" + qsBiltetsSUMAT->AsString + "*1";
				if (CasaTotalSuma > 0 &&
					qsBiltetsINLESN->AsString != "MT" &&
					qsBiltetsINLESN->AsString != "M" &&
					qsBiltetsSUMAT->AsInteger > 0)
				{
          fPrintSetup->PrintNFTextDAISY_SX(qsBiltetsCECU->AsString);
					String Product = "Bilet;A;" + qsBiltetsSUMAT->AsString + "*1";
					slTicketPrint->Add(LeftPad(Product, ' ', 36, ';'));

					//Completare randuri check pentru Daisy Expert SX
					// Vezi protocl Daisy Expert de la Daisy Technology
					Product = String("Bilet")+char(9)+"A"+qsBiltetsSUMAT->AsString+"*1.0";
					slTicketPrint_SX->Add(Product);
				}
			}
			try
			{
//				qq->SQL->Text = --comentat
//					"UPDATE T0BILET SET PRINTS=nvl(PRINTS,0)+1 WHERE COD=:COD";
//				qq->ParamByName("COD")->AsString = qsBiltetsCOD->AsString;
//				qq->ExecSQL();
//				BilCommit(false);
				;
			}
			catch (...)
			{
				if (PrintTicksApart)
				{
					if (fPrintSetup->rgPrinterType->ItemIndex < 2) // printer
							PrintString("\n\n\n\n\n\n\n\n\n\n\n");
					PrTranzRez = EndPrintTransaction(!true, 0,
						qsBiltetsSUMAT->AsFloat, 0, SessValutaDepCode,
						qsV1_CASALENTAID->AsInteger);
					if (!PrTranzRez)
					{
						RegError(qsBiltetsCOD->AsString);
					}
				}
				else
					PrTranzRez = EndPrintTransaction(!true, 0, CasaTotalSuma, 0,
					SessValutaDepCode, qsV1_CASALENTAID->AsInteger);
				if (!PrTranzRez)
				{
					RegError(qsBiltetsCOD->AsString);
				}
				DB_Rollback();
				throw;
			}
//			if (PrintBiletOnlyCurrent == 2) // только текущий
//				break;
			qsBiltets->Next();
		}

		//Verificam tipul de plata efectuat
		qq->Close();
		qq->Prepare();
		qq->SQL->Text ="begin "
			" :Rez := pkg_alf.get_paytype(:id_cas); "
			" end;";
		qq->ParamByName("id_cas")->AsString = qsV1_CASALENTAID->AsString;
		qq->ParamByName("Rez")->ParamType = ptOutput;
		qq->ParamByName("Rez")->DataType = ftInteger;
		qq->ExecSQL();
		int p_type = qq->ParamByName("Rez")->AsInteger;
		qq->Close();

		fPrintSetup->slTickets = slTicketPrint;
		fPrintSetup->slTickets_SX = slTicketPrint_SX;
		fPrintSetup->ReceivedSumm = qsBiltetsSUMAT->AsFloat;
		fPrintSetup->payType = p_type;

		if (!PrintTicksApart)
		{
			if (fPrintSetup->rgPrinterType->ItemIndex < 2) // printer
					PrintString("\n\n\n\n\n\n\n\n\n\n\n");
			PrTranzRez = EndPrintTransaction(true, 0, CasaTotalSuma, 0,
				SessValutaDepCode, qsV1_CASALENTAID->AsInteger);
			if (!PrTranzRez)
			{
				for (int i = 0; i < SL->Count; i++)
					RegError(SL->Strings[i]);
			}
		}
	}
	__finally
	{
		qsBiltets->GotoBookmark(vBookmark);
		qsBiltets->FreeBookmark(vBookmark);
		qsBiltets->EnableControls();
		}
}
// ---------------------------------------------------------------------------
void __fastcall TdmCassa::BileteOk()
{
	if (qsV1_CASALENTA->Active)
	{
		EDIT(qsV1_CASALENTA) qsV1_CASALENTAACCEPT->AsInteger = 1;
		POST(qsV1_CASALENTA)
	}
	VR_endTransaction(true);
}

// ---------------------------------------------------------------------------
void __fastcall TdmCassa::qsD_CassaNewRecord(TDataSet *DataSet)
{
	qsD_CassaDATA->AsDateTime = Now();
}

// ---------------------------------------------------------------------------
void __fastcall TdmCassa::qsD_CassaPNewRecord(TDataSet *DataSet)
{
	qsD_CassaPDATA->AsDateTime = Now();
	qsD_CassaPISPREDAT->AsInteger = 1;
}

// ---------------------------------------------------------------------------
void __fastcall TdmCassa::qsD_CassaCalcFields(TDataSet *DataSet)
{
	if (!qsD_CassaPERS_IDT->AsString.IsEmpty() && !qsD_CassaPERS_ID->IsNull)
		qsD_CassaCasir->AsString = qsD_CassaPERS_IDT->AsString;
}

// ---------------------------------------------------------------------------
void __fastcall TdmCassa::qsD_CassaPCalcFields(TDataSet *DataSet)
{
	if (!qsD_CassaPPERS_IDT->AsString.IsEmpty() && !qsD_CassaPPERS_ID->IsNull)
		qsD_CassaPCasir->AsString = qsD_CassaPPERS_IDT->AsString;
}

// ---------------------------------------------------------------------------
void __fastcall TdmCassa::PrintItog()
{
	// spRepItog->ParamByName("PDATA")->AsDateTime
	// spRepItog->ParamByName("PMART_NR")->
	// spRepItog->ParamByName("Pcasa")->AsString
	qq->Close();
	qq->SQL->Text =
		"select RAPORT_ITOG_CASIR (null,null, null) Result from dual";
	try
	{
		qq->Open();
		BeginPrintTransaction();
		PrintString(qq->FieldByName("Result")->AsString);
		PrintString("\n\n\n\n\n\n\n\n\n\n\n");
		EndPrintTransaction(true);
		qq->Close();
	}
	catch (Exception &E)
	{
		EndPrintTransaction(!true);
		qq->Close();
		throw E;
	}

}

// ---------------------------------------------------------------------------
bool __fastcall TdmCassa::CheckRuta(TDateTime vDATA, String vRUTA,
	String &mess)
{
	bool rr = false;
	try
	{
		mess = "";
		qqCheckLockRuta->Close();
		qqCheckLockRuta->ParamByName("CODU")->AsString = vRUTA;
		qqCheckLockRuta->ParamByName("DATA")->AsDateTime = vDATA;
		qqCheckLockRuta->Open();
		if (qqCheckLockRuta->RecordCount)
		{
			rr = true;
			mess = qqCheckLockRuta->FieldByName("DescrOperatiei")->AsString +
				"\n\n CASA № " + qqCheckLockRuta->FieldByName("CASA")
				->AsString + "     CASIR: " + qqCheckLockRuta->FieldByName
				("CASIRNAME")->AsString + "\n\n Computer:" +
				qqCheckLockRuta->FieldByName("TERMINAL")->AsString +
				", OS USER=" + qqCheckLockRuta->FieldByName("OSUser")
				->AsString + "\n KILL ID=" + qqCheckLockRuta->FieldByName
				("procID")->AsString + ", AUDSID=" +
				qqCheckLockRuta->FieldByName("xUID")->AsString;
		}
	}
	catch (Exception &E)
	{
		mess = mess + "\n" + E.Message;
		rr = true;
	}
	qqCheckLockRuta->Close();
	return rr;
}

// ---------------------------------------------------------------------------
bool __fastcall TdmCassa::VR_endTransaction(bool isComitt, int mode)
{
	if (isComitt == false && ISEDIT(dmCassa->qsV1_CASALENTA))
		CANCEL(dmCassa->qsV1_CASALENTA)

			qqIsVinzEn->Close();
	// if(db->InTransaction)
	// {
	if (isComitt)
		BilCommit();
	else
		// {
			DB_Rollback();
	// }
	// }
	return false;
}

// ---------------------------------------------------------------------------
void __fastcall TdmCassa::RST_StartEdit()
{
	EDIT(dmCassa->qsV1_CASALENTA) dmCassa->qsV1_CASALENTAISRET->AsString = "!";

}

// ---------------------------------------------------------------------------
bool __fastcall TdmCassa::FindBadBilet(long pID)
{
	long ID_cek = pID;
	try
	{
		if (!pID)
		{
			qq->Close();
			qq->SQL->Text = "select max(id) ID from v1_casalenta";
			//  " where rownum = 1"
			//  " order by data desc, id desc";
			qq->Open();
			if (qq->RecordCount)
			{
				ID_cek = qq->FieldByName("ID")->AsInteger;
				if (isPridn)
				{
					qq->Close();
					qq->SQL->Text =
						"select id,valuta from v1_casalenta_val where id=" +
						String(ID_cek);
					qq->Open();
					fVinz->SelectComboValuta
						(qq->FieldByName("valuta")->AsString);
					fVinz->UpdateValutaInfo();
					fVinz->updateSumaPachDataSet();
				}
			}

		}

		if ((pID && GotoCasaOper(pID)) ||
			(!pID && ID_cek && GotoCasaOper(ID_cek) && qsV1_CASALENTAISRET->IsNull))
		{
			if (qsBiltets->Active)
				qsBiltets->Refresh();
			else
				qsBiltets->Open();
			dsV1_CASALENTA->Enabled = true;
			EDIT(qsV1_CASALENTA) qq->Close();
			if (!dmCassa->isBroni)
				qsBiltets->ReadOnly = true;
			return true;
		}
		else
			ShowMessage(fMain->LS->Text["nonoprint"]);
	} // catch(Exception&E)
	__finally
	{
		qq->Close();
		// qsV1_CASALENTA->Close();
		// throw E;
	}

	return false;
}
// ---------------------------------------------------------------------------

bool __fastcall TdmCassa::FindBookedTicket(long pID)
{
	try
	{
		if (pID && GotoCasaOper(pID))
		{
			if (qsBiltets->Active)
				qsBiltets->Refresh();
			else
				qsBiltets->Open();
			dsV1_CASALENTA->Enabled = true;
			EDIT(qsV1_CASALENTA) qq->Close();
			if (!dmCassa->isBroni)
				qsBiltets->ReadOnly = true;
			return true;
		}
		else
			ShowMessage(fMain->LS->Text["nonoprint"]);
	} // catch(Exception&E)
	__finally
	{
		qq->Close();
		// qsV1_CASALENTA->Close();
		// throw E;
	}

	return false;
}
// ---------------------------------------------------------------------------

void __fastcall TdmCassa::RefreshTotals(int mode)
{
	if (mode == 1)
		qsCasaTotals->Refresh();
	soldFin = ROUND(soldStart + qsCasaTotalsSUMA_PRIM->AsFloat -
		qsCasaTotalsSUMA_RET->AsFloat, 2);
	if (fMain)
	{
		fMain->stb->Panels->Items[1]->Text = "S  " + String(soldStart);
		fMain->stb->Panels->Items[2]->Text =
			"+" + qsCasaTotalsSUMA_PRIM->AsString;
		fMain->stb->Panels->Items[3]->Text =
			"-" + qsCasaTotalsSUMA_RET->AsString;
		fMain->stb->Panels->Items[4]->Text = " = " + String(soldFin);
	}

}

// ---------------------------------------------------------------------------
void __fastcall TdmCassa::BilCommit(bool totalsRefrssh)
{
	DB_Commit();
	if (totalsRefrssh)
		RefreshTotals(1);
}

// ---------------------------------------------------------------------------
bool __fastcall TdmCassa::GotoCasaOper(long vID)
{
	if (qsSetBlits->Active)
	{
		qsT1RUTABRONI->Close();
		qsT1RUTABRONIDETAILS->Close();
    qsCASALENTA_PAYTYPE->Close();
		qsSetBlits->Close();
		qsV1_CASALENTA->Close();
		qsSetBlits->Close();
	}
	qsSetBlits->ParamByName("id")->AsInteger = vID;
	qsSetBlits->Open();
	qsV1_CASALENTA->ParamByName("id")->AsInteger = vID;
	qsV1_CASALENTA->Open();

	if (isBroni)
	{
		if (!qsV1_CASALENTA->RecordCount)
		{
			if (MessageDlg(fMain->LS->Text["anotherbroni"], mtConfirmation,
				TMsgDlgButtons() << mbYes << mbNo << mbCancel, 0) != mrYes)
				return false;

			qq->Close();
			qq->SQL->Text =
				"update t1casalenta set data = sysdate"
				", casir = getgra_n_val('cuUserID')"
				", casa = getgra_v_val('cuCasaID')"
				" where id = :id";
			qq->Params->ParamByName("id")->AsInteger = vID;
			qq->ExecSQL();

			qsV1_CASALENTA->Close();
			qsSetBlits->Close();
			qsSetBlits->ParamByName("id")->AsInteger = vID;
			qsSetBlits->Open();
				qsV1_CASALENTA->ParamByName("id")->AsInteger = vID;
			qsV1_CASALENTA->Open();
		}
		qsT1RUTABRONI->Open();
		qsT1RUTABRONIDETAILS->Open();
    qsCASALENTA_PAYTYPE->Open();
	}
	return qsV1_CASALENTA->RecordCount;
}

// ---------------------------------------------------------------------------
void TdmCassa::ChangeRows(TDBGrid *Grid, int nModalResult)
{
	if (ISEDIT(qsBiltets))
		POST(qsBiltets)

	String sCasLenta = qsBiltetsIDCASLENTA->AsString;
	String sInlesn = qsBiltetsINLESN->AsString;
	String sDep = qsBiltetsDEPART->AsString;
	String sCer = qsBiltetsCERTIFICAT->AsString;
	String sNum = qsBiltetsPERS_NUMELE->AsString;
	String sPasp = qsBiltetsPASAPORT->AsString;

	if (nModalResult == mrAll)
	{
		qq->SQL->Text = "begin "
		"pkg_alf.update_inlesn_caslenta(:id_cas, :inl, :dep, :cer, :num, :pas); "
		" end;";
		qq->ParamByName("id_cas")->AsString = sCasLenta;
		qq->ParamByName("inl")->AsString = sInlesn;
		qq->ParamByName("dep")->AsString = sDep;
		qq->ParamByName("cer")->AsString = sCer;
		qq->ParamByName("num")->AsString = sNum;
		qq->ParamByName("pas")->AsString = sPasp;
		qq->ExecSQL();

		qsBiltets->Refresh();
		qsBiltetsAfterPost(qsBiltets);
		return;
	}

	if (Grid->SelectedRows->Count <= 1)
		return;

	qsBiltets->DisableControls();
	TBookmark vBookmark = qsBiltets->GetBookmark();

	try
	{
		for (int i = 0; i < Grid->SelectedRows->Count; i++)
		{
			qsBiltets->GotoBookmark(Grid->SelectedRows->Items[i]);

			EDIT(qsBiltets)
			qsBiltetsINLESN->AsString = sInlesn;
			qsBiltetsDEPART->AsString = sDep;
			qsBiltetsCERTIFICAT->AsString = sCer;
			qsBiltetsPERS_NUMELE->AsString = sNum;
			qsBiltetsPASAPORT->AsString = sPasp;
			POST(qsBiltets)
		}
	}
	__finally
	{
		qsBiltets->GotoBookmark(vBookmark);
		qsBiltets->FreeBookmark(vBookmark);
		qsBiltets->EnableControls();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TdmCassa::qsSetBlitsAfterEdit(TDataSet *DataSet)
{
	static bool bInside = false;
	if (bInside)
		return;

	fBiletInput = new TfBiletInput((TComponent*)NULL);
	bInside = true;

	try
	{
		if (!ISEDIT(dmCassa->qsBiltets))
			EDIT(dmCassa->qsBiltets)

		if (fVinz->IsBiletBagajOnly()) // only bagaj
		{
			qsBiltetsINLESN->AsString = "B";
			qsBiltetsBAGAJ->AsInteger = 1;
		}

		int nModalResult = fBiletInput->ShowModal();
		if (nModalResult == mrOk || nModalResult == mrAll)
		{
			ChangeRows(fVinz->dbgrV, nModalResult);
		}
		else
		{
			if (ISEDIT(dmCassa->qsBiltets))
				CANCEL(dmCassa->qsBiltets)
		}
				qsBiltets->Refresh();
	}
	__finally
	{
		delete fBiletInput;
		bInside = false;
		}
}
// ---------------------------------------------------------------------------

void __fastcall TdmCassa::qsBiltetsINLESNChange(TField *Sender)
{
	if (fBiletInput)
		fBiletInput->prepar(1);
}
// ---------------------------------------------------------------------------

TOraSession *getCurrentSession()
{
	return dmCassa->db;
}

void __fastcall TdmCassa::setcasaGroup(int iidGroup)
{
	casaGroup1 = iidGroup;
	ospSetCasaGroup->ParamByName("VIDNIVEL")->AsInteger = iidGroup;
	ospSetCasaGroup->ExecProc();
}

void __fastcall TdmCassa::qsBiltetsEditError(TDataSet *DataSet,
	EDatabaseError *E, TDataAction &Action)
{
	//
}
// ---------------------------------------------------------------------------

void __fastcall TdmCassa::dbError(TObject *Sender, EDAError *E, bool &Fail)
{
	//

}
// ---------------------------------------------------------------------------

void __fastcall TdmCassa::AppException(TObject *Sender, Exception *E)
{
	Application->ShowException(E);
}

String __fastcall TdmCassa::GetViewText(String svv)
{
	String srr;
	qq->Close();
	qq->SQL->Text = "SELECT  Text FROM USER_VIEWS WHERE View_NAME='" +
		svv + "'";
	qq->Open();
	srr = qq->FieldByName("text")->AsString;
	qq->Close();
	return srr;
}

// ---------------------------------------------------------------------------
void __fastcall TdmCassa::PrintListImb(TDate sDATA, String sRUTA,
	long pCASALENTAID)
{
	// selectPerrControl(sDATA,sRUTA);

	String RR;
	osqIMB->ParamByName("vpdata")->AsDateTime = sDATA;
	osqIMB->ParamByName("pruta")->AsString = sRUTA;
	osqIMB->ParamByName("PIDCASALENTA")->AsInteger = pCASALENTAID;
	osqIMB->ExecProc();
	RR = osqIMB->ParamByName("result")->AsString;
	osqIMB->ParamByName("result")->AsString = "";

	int kp;

	if ((kp = printLSTIMB(RR, false, 2)) != 0)
	{
		BeginPrintTransaction(1);
		do
		{
			PrintString(RR, 1);
			kp--;
		}
		while (kp);

		int iCNTAddLinesLIMB =
			_wtoi(fPrintSetup->meCNTAddLinesLIMB->Text.c_str());
		if (iCNTAddLinesLIMB > 0)
			PrintString(RR.StringOfChar('\n', iCNTAddLinesLIMB));
		else if (iCNTAddLinesLIMB == -1)
			PrintString("\x0C");

		EndPrintTransaction1(true, 1);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TdmCassa::viewSaledTickets()
{
	/* if(!) Application->CreateForm(__classid(TfSaledTickets), &fSaledTickets);
	 fSaledTickets->WindowState=wsMaximized;
	 fSaledTickets->Show(); */
	if (!isCassaPerronVinzare)
		return;
	fSaledTickets = new TfSaledTickets(NULL);

	try
	{
			osmFullCasaLentaPrev->Close();
		osmFullCasaLentaPrev->Open();
		// osmFullCasaLentaPrev->RefreshQuery();
		osmFullCasaLentaPrev->First();
		qsBiltets->MasterSource = dsmFullCasaLentaPrev;

		if (fSaledTickets->ShowModal()
			== mrOk && fSaledTickets->cbxReTipar->Checked)
		{
			fVinz->FindBadBilet(dmCassa->osmFullCasaLentaPrevID->AsInteger);
			fMain->Orar1Click(NULL);
		}

	}

	__finally
	{

			qsBiltets->MasterSource = dsSetBlits;

		delete fSaledTickets;
	}

}

void __fastcall TdmCassa::qsV1_CASALENTAAfterClose(TDataSet *DataSet)
{
	///
}
// ---------------------------------------------------------------------------

void __fastcall TdmCassa::StopPerronRUTA(String vRUTA, TDate vDATA,
	int IsCommit)
{
	// ubrano po prosibe S. Kupnogo
	/*
	 if(MessageDlg(fMain->LS->Text["busgone"], mtConfirmation, TMsgDlgButtons() << mbNo << mbYes <<mbCancel, 0) != mrNo)
	 return;
	 qq->Close();
	 qq->SQL->Text="call G2002procs.PerStopRUTA(:RUTA,:DATA,:CC)";
	 qq->Params->ParamByName("RUTA")->AsString=vRUTA;
	 qq->Params->ParamByName("DATA")->AsDateTime=int(vDATA);
	 qq->Params->ParamByName("CC")->AsInteger=IsCommit;
	 qq->ExecSQL();
	 */

}

// ---------------------------------------------------------------------------
void __fastcall TdmCassa::DB_Rollback()
{
	qq->Close();
	qq->SQL->Text = "Rollback";
	qq->ExecSQL();
	db->Rollback();
}

// ---------------------------------------------------------------------------
void __fastcall TdmCassa::DB_Commit()
{
  qq->Close();
  qq->SQL->Text = "Commit";
	qq->ExecSQL();
	db->Commit();
}

// ---------------------------------------------------------------------------
void __fastcall TdmCassa::qsT1RUTABRONIAfterInsert(TDataSet *DataSet)
{
	qsT1RUTABRONIRUTA->AsVariant = qsBiltetsRUTA->AsVariant;
	qsT1RUTABRONIDATA->AsVariant = qsBiltetsDATA->AsVariant;
	qsT1RUTABRONITIPBRONI->AsInteger = 0;
}

// ---------------------------------------------------------------------------
void __fastcall TdmCassa::broni_changeStarea(long vcasalenta, long vstarea)
{
	if (vcasalenta == 0)
		return;

	qq->Close();
	qq->SQL->Text = "begin broni.changeStarea(:vcasalenta, :vstarea); end;";
	qq->Prepare();
	qq->ParamByName("vcasalenta")->AsInteger = vcasalenta;
	qq->ParamByName("vstarea")->AsInteger = vstarea;
	qq->ExecSQL();

	if (vstarea == 1) // выкупленная бронь
	{
		if (FindBadBilet(vcasalenta))
		  qsBiltets->Refresh();
	}
}

// ---------------------------------------------------------------------------
double __fastcall TdmCassa::Sess_SetValuta(TDateTime vDATA, String vVal,
	double vCurs)
{
	static String selLastValuta = "";
	SessValuta = vVal;
	if ((selLastValuta == "" || selLastValuta == vVal) && vVal == defValuta)
		return 1;
	selLastValuta = vVal;

	String pVal = vVal;
	if (vVal == "")
		pVal = Sess_GetValuta();
	qq->Close();
	qq->SQL->Text = "begin :ValCURS:=GRAENVIROMENT.CPERR_setSalesSessParams(:CASASALESDAY, :Val); \
               select COD1 into :Cod1Val from tms_syss where tip='S' and cod=3 and UM=:Val; \
               end;";
	qq->Prepare();
	qq->ParamByName("ValCURS")->ParamType = ptOutput;
	qq->ParamByName("ValCURS")->DataType = ftFloat;
	qq->ParamByName("Cod1Val")->ParamType = ptOutput;
	qq->ParamByName("Cod1Val")->DataType = ftFloat;
	qq->ParamByName("CASASALESDAY")->AsDateTime = vDATA;
	qq->ParamByName("Val")->AsString = pVal;
	qq->ExecSQL();
  
	double retCurs = qq->ParamByName("ValCURS")->AsFloat;
	SessValutaDepCode = qq->ParamByName("Cod1Val")->AsFloat;
	qq->Close();
	return retCurs;

}

// ---------------------------------------------------------------------------
String __fastcall TdmCassa::Sess_GetValuta()
{
	return SessValuta; // =vVal;
	/* if (!fVinz)
	 return "";
	 return fVinz->cmbValuta->Text; */
}

// ---------------------------------------------------------------------------
void TdmCassa::RegError(String vCodBil)
{
	qq->SQL->Text = "begin \
		vinz_control.RegPrintErr(:vCODbilet, :vCasa, :vCassir, :vCassError);\
	 end;";
	qq->ParamByName("vCODbilet")->AsString = vCodBil;
	qq->ParamByName("vCasa")->AsString = NrCassa;
	qq->ParamByName("vCassir")->AsInteger = UserID;
	qq->ParamByName("vCassError")->AsString = 1;
	qq->ExecSQL();
}

// ---------------------------------------------------------------------------
String TdmCassa::CheckError()
{
	qq->SQL->Text = "begin \
		:vCODbilet := vinz_control.CheckErr(:vCasa, :vCassir);\
	 end;";
	qq->ParamByName("vCasa")->ParamType = ptInput;
	qq->ParamByName("vCasa")->AsString = NrCassa;
	qq->ParamByName("vCasa")->Size = 32000;
	qq->ParamByName("vCassir")->ParamType = ptInput;
	qq->ParamByName("vCassir")->AsInteger = UserID;
	qq->ParamByName("vCODbilet")->Size = 32000;
	qq->ParamByName("vCODbilet")->ParamType = ptResult;
	qq->ParamByName("vCODbilet")->DataType = ftString;
	qq->ExecSQL();
	return qq->ParamByName("vCODbilet")->AsString;
}

// ---------------------------------------------------------------------------
void TdmCassa::FixError(String vCodBil)
{
	qq->SQL->Text = "begin \
		vinz_control.CloseErr(:vCODbilet, :vCasa, :vCassir);\
	 end;";
	qq->ParamByName("vCODbilet")->AsString = vCodBil;
	qq->ParamByName("vCasa")->AsString = NrCassa;
	qq->ParamByName("vCassir")->AsInteger = UserID;
	qq->ExecSQL();
}
// ---------------------------------------------------------------------------

void __fastcall TdmCassa::qsBiltetsAfterPost(TDataSet *DataSet)
{
	bool isEditLE = ISEDIT(qsV1_CASALENTA);
	if (isEditLE)
		POST(qsV1_CASALENTA) qsV1_CASALENTA->RefreshRecord();
	if (isEditLE)
		EDIT(qsV1_CASALENTA)
}
// ---------------------------------------------------------------------------

void __fastcall TdmCassa::spRegCompAfterExecute(TObject *Sender,
			bool Result)
{
	spGetUserInfo->ParamByName("v_user_id")->AsInteger = UserID;
	spGetUserInfo->ExecProc();

	UserCanPrint = !spGetUserInfo->ParamByName("v_cannot_print")->AsBoolean;
	IsUserSubAgent = spGetUserInfo->ParamByName("v_is_subagent")->AsBoolean;
	IsUserSubAgent = spGetUserInfo->ParamByName("v_is_subagent")->AsBoolean;
}
// ---------------------------------------------------------------------------


void __fastcall TdmCassa::qsCASALENTA_PAYTYPEBeforePost(TDataSet *DataSet)
{
	int a = 0;

}
//---------------------------------------------------------------------------

