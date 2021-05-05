#include <vcl.h>
#pragma hdrstop

#include "uDMcassa.h"
#include "uVinz.h"
#include "uSelect.h"
#include "uSelInlesn.h"
#include "uMain.h"
#include "uUnivers.h"
#include "uRest.h"
#include "uTipBilet.h"
#include "uPrintSetup.h"
#include "uPrintListaImb.h"
#include "uCustomPrice.h"
#include "uCheckBroni.h"
#include "uAdditionalInfoLinker.h"
#include <Vcl.Dialogs.hpp>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBGridMy1"
#pragma link "GaraMonthCalendar"
#pragma link "StaticDBGrid"
#pragma link "RzDBStat"
#pragma link "RzStatus"
#pragma link "RzButton"
#pragma link "RzRadChk"
#pragma link "RzDBEdit"
#pragma link "Ora"
#pragma link "UnDBCtrl"
#pragma link "UnSDGrid"
#pragma link "LgSelect"
#pragma link "DBAccess"
#pragma link "RzEdit"
#pragma link "MemDS"
#pragma resource "*.dfm"
TfVinz *fVinz;


// ---------------------------------------------------------------------------
__fastcall TfVinz::TfVinz(TComponent *Owner) : TForm(Owner)
{
	calInt = true;
	mmc->Date = (int)Now();
	FormActivate(NULL); // Calculate mmc->MinDate && mmc->MaxDate
	calInt = false;

	dbgrV->Load();

	cmbAuto->Visible = !dmCassa->isCassaPerron;
	lblGrupaCasei->Visible = cmbAuto->Visible;

	cbxBroni->Visible = dmCassa->isBroni;
	actBroni->Enabled = dmCassa->isBroni;

	cbxPerron->Visible = dmCassa->isCassaPerronVinzare;
	cbxPerron->Enabled = !dmCassa->isCassaPerron;

	cbxPerron->Checked = dmCassa->isCassaPerron;
	cbxPerronClick(NULL);
	actVinzPeeron->Enabled = cbxPerron->Enabled && cbxPerron->Visible;

	dbgrV->DataSource = dmCassa->dsBiltets;
	dbmemoBilet->DataSource = dmCassa->dsBiltets;
	dbePlata->DataSource = dmCassa->dsV1_CASALENTA;
	dbBaniiPrim->DataSource = dmCassa->dsV1_CASALENTA;
	dbRest->DataSource = dmCassa->dsV1_CASALENTA;
	dsT1RUTABRONI->DataSet = dmCassa->qsT1RUTABRONI;

	ViziMode(0);
	lasdbgrVSelectedIndex = 0;
	srvTimerTimer(NULL);
	cbxBroniClick(NULL);
	stCursVal->Caption = "";
	try
	{

		cmbAuto->Clear();

		dmCassa->qq->Close();
		dmCassa->qq->SQL->Text =
			"SELECT * FROM V0casagroups WHERE IDCASAGROUP=NVL(GETGRA_N_VAL('CUCASANIVEL'),0)";
		dmCassa->qq->Open();

		cmbAuto->Items->AddObject(dmCassa->qq->FieldByName("DENUMIREA")
			->AsString, (TObject *)(dmCassa->qq->FieldByName("IDCASAGROUP")
			->AsInteger));
		String sFilt1 = dmCassa->qq->FieldByName("LST_AGROUPS")->AsString;


    // Получение фильтров по "маршрутам" (спектаклям)
    TSmartQuery* qFilts = dmCassa->qComplexFilt;
    
    qFilts->SQL->Text = (String) "select id, denumirea from tms_syss"
      " where cod1 > 0 and cod = :cod and tip = :tip and number1=:cassa"
      " order by cod1";
    qFilts->ParamByName("cod")->AsString = "33";
    qFilts->ParamByName("tip")->AsString = "G0";
    qFilts->ParamByName("cassa")->AsInteger = dmCassa->qq->FieldByName("IDCASAGROUP")->AsInteger;
    qFilts->Open();


		dmCassa->qq->Close();

		if (sFilt1 != "")
		{
			dmCassa->qq->SQL->Text =
				"SELECT * FROM V0casagroups WHERE IDCASAGROUP in (" +
				sFilt1 + ")";
			dmCassa->qq->Open();
			while (!dmCassa->qq->Eof)
			{
				cmbAuto->Items->AddObject
					(dmCassa->qq->FieldByName("DENUMIREA")->AsString,
					(TObject *)(dmCassa->qq->FieldByName("IDCASAGROUP")
					->AsInteger));
				dmCassa->qq->Next();
			}

			dmCassa->qq->Close();

		}

    dmCassa->qCheckBroni->Open();
		CheckBroniCount = dmCassa->qCheckBroni->RecordCount;
	}
	catch (Exception &E)
	{
		ShowMessage(E.Message);
	}

	pnlSel->Height = dmCassa->isPridn ? 90 : 90;
	cmbValuta->Enabled = dmCassa->isPridn;
	SelectComboValuta(dmCassa->defValuta); // cmbValuta->ItemIndex=0;
	// cmbValuta->Text=dmCassa->SessValuta;

	dmCassa->qq->Close();
	cmbAuto->ItemIndex = 0;
	dmCassa->sqValuta->Open();
	cmbValuta->Clear();
	for (dmCassa->sqValuta->First(); !dmCassa->sqValuta->Eof;
	dmCassa->sqValuta->Next())
		cmbValuta->Items->Add(dmCassa->sqValuta->FieldByName("UM")->AsString);
	cmbValuta->ItemIndex = 0;

  meFilter->KeyValue = 317077; // Magia filter

	if (dmCassa->isPridn)
	{
		EdTickCount->Text = UpdateTickCount(0);
	}
	LbTickCounter->Visible = dmCassa->isPridn;
	EdTickCount->Visible = dmCassa->isPridn;
	SBtnResetTickCounter->Visible = dmCassa->isPridn;

	fPrintSetup->InitializeINISection();

	if (fPrintSetup->DisableF11HotKey)
	{
	  toPasaport->ShortCut = 0;
	}
	TAdditionalInfoLinker::init("TMS_SYSS", "XSABLONS");
	fillAddInfoBox(this);
}

// ---------------------------------------------------------------------------
void __fastcall TfVinz::SetToday()
{
	// ShowMessage("TfVinz::SetToday() begin");

	TDate dtNow = (int)Now();

	bool calSaved = calInt;
	calInt = true;
	try
	{
		dtNow.DecodeDate(&year, &month, &day);
		String asYear = year;
		String asMask = (String)"00.00.2";
		String asYear2 = (String)"\\" + asYear[2];
		String asYear3 = (String)"\\" + asYear[3];
		String asYear4 = (String)"\\" + asYear[4];
		if (month > 9)
		{
			asYear4 = "0";
			if (asYear[4] == '9')
			{
				asYear3 = "0";
				if (asYear[3] == '9')
					asYear2 = "0";
			}
		}
		meData->EditMask = asMask + asYear2 + asYear3 + asYear4;

		mmc->Date = dtNow;
		String asNow = dtNow.DateString();
		meData->Text = asNow;
	}
	__finally
	{
		calInt = calSaved;
	}

	// ShowMessage("TfVinz::SetToday() end");
}

// ---------------------------------------------------------------------------
void __fastcall TfVinz::SpeedButton1Click(TObject *Sender)
{
	String ErrTick = dmCassa->CheckError();
	bool fl = !ErrTick.IsEmpty();
	while (fl)
	{
		fl = ErrTick.IsEmpty();
		String DlgMes = "Билет " + ErrTick +
			" не напечатан. Пропустить = Yes, Анулировать = NO.";
		if (MessageDlg(DlgMes, mtConfirmation,
			TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
		{
			dmCassa->FixError(ErrTick);
		}
		else
		{
			fRest->RestRecalcPrep(ErrTick);
			return;
		}
		ErrTick = dmCassa->CheckError();
		fl = !ErrTick.IsEmpty();
	}

	TDate dC = TDate(meData->Text);
	if (int(dC) != int(mmc->Date))
	{
		ShowMessage(fMain->LS->Text["incordate"]);
		return;
	}

	if (fPrintSetup->cbxStationFiltruNotEmpty->Checked && meFilter->Text == "")
	{
		ShowMessage(fMain->LS->Text["filterenter"]);
		meFilter->SetFocus();
		return;
	}
	dmCassa->DB_Commit();
	dmCassa->setcasaGroup((long)(cmbAuto->Items->Objects[cmbAuto->ItemIndex]));

	updateSumaPachDataSet();

	int resultSel = selectRutaDir(dC, meFilter->Text, cbxBroni->Checked);

	if (resultSel == 1 && (fSelRuta->qsDirect->RecordCount ||
		fSelRuta->qsT0RUTA->RecordCount))
	{
		AddInfoAndTypeBox->ClearSelection();
    AddInfoAndTypeBox->Text = String();
		dbgrV->ReadOnly = dmCassa->isCassaPerron;
		actRutaPlecat->Enabled = actVinzPeeron->Enabled;
		cbxStopRuta->Enabled = actRutaPlecat->Enabled;

		bool vinzareaDavai = false;
		bool vinzareaMesto = true;
		String broniMesto = "";

	dmCassa->isBroniLaPlata = fSelRuta->broniButton == fSelRuta->btnBroniLaPlata;

		if (dmCassa->isBroniLaPlata)
		{

			if (fSelRuta->broniInternTip != 2)
			{
				vinzareaDavai = true;
				vinzareaMesto = false;
		        dmCassa->broni_changeStarea(fSelRuta->broniCasaLenta, 1);
				// FindBadBilet(fSelRuta->broniCasaLenta);
        		// dmCassa->qsBiltets->Refresh();
				// fSelRuta->broniButton==fSelRuta->btnBroniLaPlata?1:2);
			}
			else
			{
				dmCassa->qq->Close();
				dmCassa->qq->SQL->Text =
					"begin :Rez:=Broni.getNewTicketFromCancelBroni( :vcasalenta); end;";
				dmCassa->qq->Prepare();
				dmCassa->qq->ParamByName("Rez")->ParamType = ptOutput;
				dmCassa->qq->ParamByName("Rez")->DataType = ftString;
				dmCassa->qq->ParamByName("vcasalenta")->AsInteger =
					fSelRuta->broniCasaLenta;
				dmCassa->qq->ExecSQL();
				broniMesto = "," + dmCassa->qq->ParamByName("Rez")->AsString;
				dmCassa->qq->Close();

			}
		}
		if (fSelRuta->broniButton == fSelRuta->btnBroniLaRestit)
		{
			// BroniCancel
			// цикл по всем билетам внутри
			Variant vv[1];
			dmCassa->db->ExecSQL("Call broni.BroniCancel ( " +
				String(fSelRuta->broniCasaLenta) + ")", vv, 0);
			vinzareaMesto = false;
		}

		if (fSelRuta->broniButton == fSelRuta->btnReturnOnline)
		{
			// Returnin online tickets
			Variant vv[1];
		   	dmCassa->db->ExecSQL("Call gra_add.create_return_doc ( " +
				String(fSelRuta->broniCasaLenta) + ")", vv, 0);

			vinzareaMesto = false;
		}

		if (vinzareaMesto)
		{
			if (int(dC) != int(mmc->Date))
				mmc->Date = dC;

			if (fSelRuta->qsDirect->RecordCount)
				meSelDest->Text = fSelRuta->qsDirectDENUMIREA->AsString;
			else
				meSelDest->Text = fSelRuta->qsT0RUTADENUMIREA->AsString;


			meRuta->Text = fSelRuta->qsT0RUTA->FieldByName("CODU")->AsString +
				", " + fSelRuta->qsT0RUTA->FieldByName("DENUMIREA")->AsString;

			TList* mm = new TList();
			for (int i = 0; i < fSelRuta->RowList->Count; i++)
				for (int j = 0; j < fSelRuta->RowList->Items[i]->Count; j++)
				{
				  TPlace* Place = fSelRuta->RowList->Items[i]->Places[j];

				  if (fSelRuta->broniInternTip != 2)
				  {
					if (Place->State == pstSelected)
					  mm->Add(&Place->AbsNr);
				  }
				  else
				  {
					if (broniMesto.Pos("," + String(Place->AbsNr) + ","))
					  mm->Add(&Place->AbsNr);
				  }
				}

			int nCodOras;
			TDateTime dtDate;
			if (fSelRuta->pgc->ActivePage == fSelRuta->tbsComplex)
			{
				dtDate = fSelRuta->qsT0RUTA->FieldByName("data")->AsDateTime;
				nCodOras = fSelRuta->qsT0RUTA->FieldByName("codoras")->AsInteger;

			}
			else
			{
				dtDate = dC;
				nCodOras = fSelRuta->qsDirectID->AsInteger;
			}

			vinzareaDavai = dmCassa->davaiProdavai(mm->Count, mm, dtDate,
				fSelRuta->qsT0RUTA->FieldByName("CODU")->AsString, nCodOras,
				0 /* vGARA */ , -1,
				fSelRuta->broniInternTip, fSelRuta->rzLocsInpManual->Text);

		}

		if (vinzareaDavai)
		{
			dbgrV->ReadOnly = false;
			ViziMode(1);

			if (cbxBroni->Checked)
			{
				Clipboard()->AsText = dmCassa->qsBiltets->FieldByName("idcaslenta")->AsString;
				edBookingDoc->SetFocus();
			}
			else
			{
				dbBaniiPrim->SetFocus();
			}

			mmInfo->Lines->Clear();
			mmInfo->Lines->Add("Lenta = "+dmCassa->qsV1_CASALENTAID->AsString);

			if (IsBiletBagajOnly()) // only bagaj
				ToBagajInl(1, true);
		}
		else
		{ // vozvrat broni
			ViziMode(0);
			// if(!dmCassa->GotoCasaOper(dmCassa->qsV1_CASALENTAID->AsInteger))  {ShowMessage("Nu pot porni transactia pentru restituirea biletelor"); return;}
			dmCassa->BileteOk();
		}
	}
	else
		ViziMode(0);
}

// ---------------------------------------------------------------------------
bool __fastcall TfVinz::IsBiletBagajOnly()
{
	return 0;
}

// ---------------------------------------------------------------------------
void __fastcall TfVinz::ViziMode(int mo)
{
	// ShowMessage((String)"TfVinz::ViziMode(" + mo + ")");
	switch (mo)
	{
	case -1: // select
		fSelRuta->UnlockLockedPlaces();
	case 0: // select
		// if(!mo)
		{
			SetToday();
			meCntBlt->Text = "1";
		} cmbAuto->ItemIndex = 0;
		pnlSel->Enabled = true;
		pnlTipar->Enabled = false;
		// dmCassa->dsV1_CASALENTA->Enabled=false;
		fMain->SetToolbMode(true); // fMain->Menu=fMain->MainMenu1;
		cbxStopRuta->Checked = false;
		actRutaPlecat->Enabled = false;
		actVinzPeeron->Enabled = true;
		actBroni->Enabled = cbxBroni->Visible;
		dmCassa->qq->SQL->Text = "begin gracontext.setval('show_days_cassalenta', ''); end;";
		dmCassa->qq->Execute();
		break;
	case 1: // tipar
		pnlSel->Enabled = false;
		pnlTipar->Enabled = true;
		fMain->SetToolbMode(false); // fMain->Menu=NULL;

		actVinzPeeron->Enabled = false;
		actBroni->Enabled = false;
		break;
	default: ;
	}

	mmc->Enabled = pnlSel->Enabled;
	btSelect->Enabled = pnlSel->Enabled;
	meCntBlt->Enabled = pnlSel->Enabled;

	pnlgrV->Enabled = pnlTipar->Enabled;
	btnLaTipar->Enabled = pnlTipar->Enabled;
	btAnul->Enabled = pnlTipar->Enabled;
	ToAn->Enabled = pnlTipar->Enabled;
	ToTipar->Enabled = pnlTipar->Enabled;
	btnBiletToClipboard->Enabled = pnlTipar->Enabled;
	BtPterminal->Enabled = pnlTipar->Enabled;

	dbBaniiPrim->Enabled = pnlTipar->Enabled;
	btFullOk->Enabled = false;
	btLaTiparBon->Enabled = false;
	ToFullOk->Enabled = false;
	btnLaTiparLISTADEIMB->Enabled = btFullOk->Enabled;

	dbgrV->SelectedField = dmCassa->qsBiltetsCOD;
	try
	{
		if (Visible)
		{
			if (mo > 0)
				ActiveControl = dbBaniiPrim;
			else
				ActiveControl = meFilter;
		}
	}
	catch (...)
	{
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfVinz::meDataChange(TObject *Sender)
{
	if (calInt)
		return;

	String asDate = meData->Text;

	// ShowMessage("TfVinz::meDataChange(" + asDate + ") begin");

	TDate dtNew;
	try
	{
		dtNew = StrToDate(meData->Text);
	}
	catch (...)
	{
		// ShowMessage("TfVinz::meDataChange(" + asDate + ") Incorrect date");
		meData->Color = clRed;
		Beep();
		return;
	}

	TDate dtMin = (int)mmc->MinDate;
	TDate dtMax = (int)mmc->MaxDate;
	if ((dtNew < dtMin) || ((0 < (int)dtMax) && (dtNew > dtMax)))
	{
		// ShowMessage("TfVinz::meDataChange(" + asDate + ") Date is not in period");
		meData->Color = clYellow;
		return;
	}

	calInt = true;
	try
	{
		try
		{
			meData->Color = clWindow;
			mmc->Date = dtNew;
			UpdateValutaInfo();
		}
		catch (EMonthCalError &E)
		{
			// ShowMessage("TfVinz::meDataChange(" + asDate + ") EMonthCalError: " + E.Message);
			String asDate = mmc->Date.DateString();
			if (meData->Text != asDate)
				meData->Text = asDate;
			Beep();
		}
		catch (Exception &E)
		{
			// ShowMessage("TfVinz::meDataChange(" + asDate + ") Exception: " + E.Message);
			meData->Color = clRed;
			Beep();
		}
	}
	__finally
	{
		calInt = false;
	}

	// ShowMessage("TfVinz::meDataChange(" + asDate + ") end");
}

// ---------------------------------------------------------------------------
void __fastcall TfVinz::mmcClick(TObject *Sender)
{
	if (calInt)
		return;

	calInt = true;
	try
	{
		String asDate = mmc->Date.DateString();
		if (meData->Text != asDate)
			meData->Text = asDate;
	}
	__finally
	{
		calInt = false;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfVinz::FormActivate(TObject *Sender)
{
	// ShowMessage((String)"TfVinz::FormActivate(" + mmc->Date + ")");
	TDate minDate = (int)Now();
	mmc->MinDate = 0;
	mmc->MaxDate = minDate + 91;
	mmc->MinDate = minDate;
}

// ---------------------------------------------------------------------------
void __fastcall TfVinz::mmcChange(TDate dd)
{
	if (calInt)
		return;

	String asDate = dd.DateString();

	// ShowMessage("TfVinz::mmcChange(" + asDate + ") begin");

	if (meData->Text != asDate)
		meData->Text = asDate;
	/*
	 try
	 {
	 if ((TDate)meData->Text != (TDate)mmc->Date && !calInt)
	 mmcClick(NULL);
	 }
	 catch (...) {}
	 */

	// ShowMessage("TfVinz::mmcChange(" + asDate + ") end");
}

// ---------------------------------------------------------------------------
void __fastcall TfVinz::dbgrVEditButtonClick(TObject *Sender)
{
	if (dbgrV->SelectedField == dmCassa->qsBiltetsINLESN &&
		(dbgrV->SelectedField->IsNull || Sender))
		SelectInlesn(dmCassa->qsBiltets->Session, dmCassa->qsBiltetsINLESN,
		dmCassa->qsBiltetsRUTA->AsString);

	if (dbgrV->SelectedField == dmCassa->qsBiltetsDEPART &&
		(dbgrV->SelectedField->IsNull || Sender))
	{
		if (selectFromUnivDepart(dmCassa->qsBiltetsDEPART, NULL,
			dmCassa->qsBiltetsINLESN->AsString) == -1)
			dbgrV->SelectedIndex = dbgrV->SelectedIndex +
				(dbgrV->SelectedIndex > lasdbgrVSelectedIndex ? 1 : -1);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfVinz::btnLaTiparClick(TObject *Sender)
{
	if (((!dmCassa->isPridn || !NotDefValuta())
		&& dmCassa->qsV1_CASALENTASUMA_PACH->AsFloat > dbBaniiPrim->Value) ||
		(dmCassa->qsV1_CASALENTASUMAVAL_PACH->AsFloat > dbBaniiPrim->Value))
	{
		ShowMessage(fMain->LS->Text["entersum"]);
		dbBaniiPrim->SetFocus();
	}
	else
	{
		bool zz = btFullOk->Enabled;
		dmCassa->BileteLaTipar(zz,1, cbxBroni->Checked);
		//Daca s-a apasat mai intai btnLaTipar, trebuie dezactivat BtnPterminal
		if(!zz)
      BtPterminal->Enabled = false;
		fSelRuta->PayLockedPlaces();
		btFullOk->Enabled = true;
		btLaTiparBon->Enabled = true;
		ToFullOk->Enabled = false;
		btnLaTiparLISTADEIMB->Enabled = btFullOk->Enabled;

		dbgrV->ReadOnly = true;
		btAnul->Enabled = false;
		// pnlgrV->Enabled = false;
		dbBaniiPrim->Enabled = false;
		btFullOk->SetFocus();
		if (dmCassa->UserCanPrint && fPrintSetup->cbxListeBiletePrint->Checked && dmCassa->isCassaPerron)
			btnLaTiparLISTADEIMBClick(NULL);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TfVinz::btFullOkClick(TObject *Sender)
{
	EdTickCount->Text = UpdateTickCount(StrToInt(meCntBlt->Text.Trim()));
	dmCassa->BileteOk();
	ViziMode(0);
	cmbValuta->ItemIndex = 0;
	UpdateValutaInfo();
}

// ---------------------------------------------------------------------------
void __fastcall TfVinz::btAnulClick(TObject *Sender)
{
	dmCassa->BileteAnulare();
	ViziMode(-1);
}

// ---------------------------------------------------------------------------
void __fastcall TfVinz::dbBaniiPrimChange(TObject *Sender)
{
	if (ISEDIT(dmCassa->qsV1_CASALENTA))
		dmCassa->calcRest(dbBaniiPrim->Value);
}
// ---------------------------------------------------------------------------

void __fastcall TfVinz::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if (pnlTipar->Enabled)
	{
		if (dbBaniiPrim->Value == 0 && btAnul->Enabled)
			btAnul->Click();
		else
		{
			ShowMessage(fMain->LS->Text["termin"]);
			CanClose = false;
		}
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfVinz::dbBaniiPrimKeyDown(TObject *Sender, WORD &Key,
	TShiftState Shift)
{
	if (Key == VK_RETURN)
	{
		btnLaTipar->Click();
		Key = 0;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfVinz::meFilter_oldKeyDown(TObject *Sender, WORD &Key,
	TShiftState Shift)
{
	if (Key == VK_RETURN)
	{
		btSelect->Click();
		Key = 0;
	}
	else if (Key == 107 || Key == 109)
	{
		if (Shift.Contains(ssCtrl) || dmCassa->isCassaPerron)
		{
			long newnum = meCntBlt->Text.Trim().ToInt() + (Key == 107 ? 1 : -1);
			if (newnum > 0 && newnum < 99)
				meCntBlt->Text = String(newnum);
		}
		else
		{
			mmc->Date = mmc->Date + (Key == 107 ? 1 : -1);
			mmcClick(NULL);
		}
		meFilter->ReadOnly = true;
		Key = 0;
	}
	else
		meFilter->ReadOnly = false;

}

// ---------------------------------------------------------------------------
void __fastcall TfVinz::ToBagajInl(int mo, bool isAutoEd) // 0 - inl 1 - bagaj
{
	if (pnlgrV->Enabled && (dbBaniiPrim->Enabled || !isAutoEd))
	{
		/*if (ActiveControl == dbgrV)
		{
			try
			{
				if (ISEDIT(dmCassa->qsBiltets))
					POST(dmCassa->qsBiltets)
			}
			catch (...)
			{
					if (ISEDIT(dmCassa->qsBiltets))
						throw;
			}
			if (dbBaniiPrim->Enabled)
				dbBaniiPrim->SetFocus();
			else if (btFullOk->Enabled)
				btFullOk->SetFocus();
		}
		else
		*/
		{
			dbgrV->SetFocus();
			if (isAutoEd && !ISEDIT(dmCassa->qsBiltets))
			{
				Variant vv;
				vv.ChangeType(varNull);
				if (dmCassa->qsBiltets->Locate("CODADD", vv,
					TLocateOptions()) && !ISEDIT(dmCassa->qsBiltets))
					EDIT(dmCassa->qsBiltets)
			}
			if (mo == 0)
			{
				if (dbgrV->SelectedField != dmCassa->qsBiltetsINLESN)
					dbgrV->SelectedField = dmCassa->qsBiltetsINLESN;
				else if (ISEDIT(dmCassa->qsBiltets))
					dbgrVEditButtonClick(NULL);
			}
			else if (mo == 1)
			{
				if (dbgrV->SelectedField != dmCassa->qsBiltetsBAGAJ)
					dbgrV->SelectedField = dmCassa->qsBiltetsBAGAJ;
			}
			else
			{
				if (dbgrV->SelectedField != dmCassa->qsBiltetsPERS_NUMELE)
					dbgrV->SelectedField = dmCassa->qsBiltetsPERS_NUMELE;
			}
			dbePlata->SetFocus();
		}
	}
}

void __fastcall TfVinz::toInlExecute(TObject *Sender)
{
	ToBagajInl(Sender == toPasaport ? 2 : 0, Sender != toInl);
}
// ---------------------------------------------------------------------------

void __fastcall TfVinz::dbgrVColEnter(TObject *Sender)
{
	if (ISEDIT(dmCassa->qsBiltets))
		dbgrVEditButtonClick(NULL);
	lasdbgrVSelectedIndex = dbgrV->SelectedIndex;
}
// ---------------------------------------------------------------------------

void __fastcall TfVinz::meDataKeyDown(TObject *Sender, WORD &Key,
	TShiftState Shift)
{
 // Disabled with meCntBlt->Visible == false
 //	if (Key == VK_RETURN)
 //	{
 //		Key = 0;
 //		meCntBlt->SetFocus();
 //	}
}
// ---------------------------------------------------------------------------

void __fastcall TfVinz::meDataEnter(TObject *Sender)
{
	meData->SelStart = 0;
}
// ---------------------------------------------------------------------------

void __fastcall TfVinz::meCntBltKeyDown(TObject *Sender, WORD &Key,
	TShiftState Shift)
{
	if (Key == VK_RETURN)
	{
		Key = 0;
		meFilter->SetFocus();
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfVinz::toBagajExecute(TObject *Sender)
{
	ToBagajInl(1, true);
}

// ---------------------------------------------------------------------------
void __fastcall TfVinz::FindBadBilet(long pID)
{
	if (btSelect->Enabled && dmCassa->FindBadBilet(pID))
	{
		ViziMode(1);
		ToAn->Enabled = false;
		btAnul->Enabled = false;
		dbBaniiPrim->Enabled = false;
		btnLaTipar->SetFocus();
		btnLaTiparLISTADEIMB->Enabled = true;
		btFullOk->Enabled = true;
    btLaTiparBon->Enabled = true;
		btAnul->Enabled = true;
		actRutaPlecat->Enabled = false;
		cbxStopRuta->Enabled = false;
    BtPterminal->Enabled = false;
	}
}
// ---------------------------------------------------------------------------
bool __fastcall TfVinz::FindBookedTicket(long pID)
{
	if (dmCassa->FindBookedTicket(pID))
	{
		ViziMode(1);
		ToAn->Enabled = false;
		btAnul->Enabled = false;
		dbBaniiPrim->Enabled = false;
		btnLaTipar->SetFocus();
		btnLaTiparLISTADEIMB->Enabled = true;
		btFullOk->Enabled = true;
		btLaTiparBon->Enabled = true;
		btAnul->Enabled = true;
		actRutaPlecat->Enabled = false;
		cbxStopRuta->Enabled = false;
    return true;
	}
  return false;
}

// ---------------------------------------------------------------------------
void __fastcall TfVinz::srvTimerTimer(TObject *Sender)
{
	static TDateTime tti = 0;
	static int mustRestart = 0, zzcc = 1;
	try
	{
		if (fVinz->Timer1->Enabled != fPrintSetup->cbxAniMatedBilet->Checked)
			fVinz->Timer1->Enabled = fPrintSetup->cbxAniMatedBilet->Checked;

		if (mustRestart == 0) // int(tti)==0)
		{
			unsigned short year, month, day, hour, min, sec, msec;
			TSmartQuery *qqcc = new TSmartQuery(NULL);
			qqcc->Session = dmCassa->qq->Session;
			qqcc->SQL->Text = "select sysdate as DD from dual";
			qqcc->Open();
			tti = qqcc->FieldByName("DD")->AsDateTime;
			if (zzcc)
			{
				tti.DecodeDate(&year, &month, &day);
				tti.DecodeTime(&hour, &min, &sec, &msec);
				SYSTEMTIME stime;
				stime.wYear = year;
				stime.wMonth = month;
				stime.wDay = day;
				stime.wHour = hour;
				stime.wMinute = min;
				stime.wSecond = sec;
				stime.wMilliseconds = msec;
				SetLocalTime(&stime);
				zzcc = 0;
			}
			qqcc->Close();
			delete qqcc;
			qqcc = NULL;
		}

		lblTimp->Caption = tti.TimeString();
		fMain->stb->Panels->Items[5]->Text = lblTimp->Caption;

		tti += 1. / (24 *60 *60);
		mustRestart++;
		if (mustRestart == 100)
			mustRestart = 0;
	}
	catch (Exception &E)
	{
		fMain->stb->Panels->Items[0]->Text = E.Message;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfVinz::Timer1Timer(TObject *Sender)
{
	static TMessage msg;
	static int dir = SB_LINEDOWN;
	static int wait = 0;
	static TWinControl *wcc;
	bool bb1;
	if (fPrintSetup && !fPrintSetup->cbxAniMatedBilet->Checked)
	{
		Timer1->Enabled = false;
		return;
	}

	if (wait == 0)
	{
		if (fMain->ActiveMDIChild != fVinz && fRest)
		{
			wcc = fRest->dbmemoBilet;
			bb1 = fRest->qsRest->Active;
		}
		else
		{
			wcc = dbmemoBilet;
			bb1 = !pnlSel->Enabled;
		}
		// if(dmCassa->db->InTransaction) 20022007

		if (bb1)
		{
			msg.Result = SendMessage(wcc->Handle, EM_SCROLL, dir, 0);
			if (msg.ResultLo == 0)
			{
				dir = (dir == SB_LINEDOWN) ? SB_LINEUP : SB_LINEDOWN;
				wait = 10;
			}
		}
		else
			SendMessage(wcc->Handle, EM_SCROLL, SB_PAGEUP, 0);
	}
	else
		wait--;
}
// ---------------------------------------------------------------------------

void __fastcall TfVinz::dbgrVKeyDown(TObject *Sender, WORD &Key,
	TShiftState Shift)
{
  if (Key == VK_F6)
  {
    if (!dmCassa->qsBiltets->Active)
      return;

    fCustomPrice = new TfCustomPrice(this);
    fCustomPrice->edPrice->Text = dmCassa->qsBiltets->FieldByName("sumat")->AsString;
    if (fCustomPrice->ShowModal() == mrOk)
    {
      spSetCustomPrice->ParamByName("p_id_casalenta")->AsString = dmCassa->qsBiltets->FieldByName("idcaslenta")->AsString;
      spSetCustomPrice->ParamByName("p_summ")->AsString = fCustomPrice->edPrice->Text;
      spSetCustomPrice->ParamByName("p_comment")->AsString = fCustomPrice->mComment->Lines->Text;
			spSetCustomPrice->Execute();

      dmCassa->qsBiltets->Refresh();
      dmCassa->qsV1_CASALENTA->Refresh();
    }
    delete fCustomPrice;
  }
}
// ---------------------------------------------------------------------------

void __fastcall TfVinz::dbmemoBiletExit(TObject *Sender)
{
	dbmemoBilet->Undo();
}
// ---------------------------------------------------------------------------

void __fastcall TfVinz::dbmemoBiletEnter(TObject *Sender)
{
	// if(!ISEDIT(dmCassa->dsBiltets)) EDIT(dmCassa->qsBiltets)
}
// ---------------------------------------------------------------------------

void __fastcall TfVinz::btnLaTiparLISTADEIMBClick(TObject *Sender)
{
	if (btnLaTiparLISTADEIMB->Visible == false ||
		btnLaTiparLISTADEIMB->Enabled == false)
		return;
	dmCassa->PrintListImb(dmCassa->qsBiltetsDATA->AsDateTime,
		dmCassa->qsBiltetsRUTA->AsString, dmCassa->qsV1_CASALENTAID->AsInteger);
	if (cbxStopRuta->Checked)
		dmCassa->StopPerronRUTA(dmCassa->qsBiltetsRUTA->AsString,
		dmCassa->qsBiltetsDATA->AsDateTime);
}
// ---------------------------------------------------------------------------

void __fastcall TfVinz::actVinzPeeronExecute(TObject *Sender)
{
	cbxPerron->Checked = !cbxPerron->Checked;
	cbxPerronClick(NULL);
}

// ---------------------------------------------------------------------------
void __fastcall TfVinz::cbxPerronClick(TObject *Sender)
{
	dmCassa->isCassaPerron = cbxPerron->Checked;
	btnLaTiparLISTADEIMB->Visible = dmCassa->isCassaPerron;
	cbxStopRuta->Visible = dmCassa->isCassaPerron;
	meData->Enabled = !dmCassa->isCassaPerron;
}
// ---------------------------------------------------------------------------

void __fastcall TfVinz::actRutaPlecatExecute(TObject *Sender)
{
	cbxStopRuta->Checked = !cbxStopRuta->Checked;
}
// ---------------------------------------------------------------------------

void __fastcall TfVinz::cbxBroniClick(TObject *Sender)
{
	dmCassa->isBroni = cbxBroni->Checked;
	pnlBroni->Visible = cbxBroni->Checked;
}
// ---------------------------------------------------------------------------

void __fastcall TfVinz::actBroniExecute(TObject *Sender)
{
	cbxBroni->Checked = !cbxBroni->Checked;
	cbxBroniClick(NULL);
}
// ---------------------------------------------------------------------------

void __fastcall TfVinz::cmbValutaChange(TObject *Sender)
{
	UpdateValutaInfo();
}

// ---------------------------------------------------------------------------
String __fastcall TfVinz::GetSessValuta()
{
	return cmbValuta->Text;
}

bool __fastcall TfVinz::NotDefValuta()
{
	return (dmCassa->SessValuta /* GetSessValuta() */ != dmCassa->defValuta);
}

// ---------------------------------------------------------------------------
void __fastcall TfVinz::UpdateValutaInfo()
{
	if (!dmCassa->isPridn)
		return;
	double cval = dmCassa->Sess_SetValuta(mmc->Date, GetSessValuta());
	if (cval)
		stCursVal->Caption = String(cval);
	else
		stCursVal->Caption = "?!? КУРС ?!?";
}

// ---------------------------------------------------------------------------
bool __fastcall TfVinz::SelectComboValuta(String pVal)
{
	int kk = cmbValuta->Items->IndexOf(pVal);
	if (kk >= 0)
		cmbValuta->ItemIndex = kk;

	return kk >= 0;
}

// ---------------------------------------------------------------------------
void __fastcall TfVinz::updateSumaPachDataSet()
{
	if (dmCassa->isPridn)
	{
		if (!NotDefValuta())
		{
			dbePlata->DataField = "SUMA_PACH"; // dmCassa->
			dbBaniiPrim->DataField = "SUMA_PRIM"; // dmCassa->
		}
		else
		{
			dbePlata->DataField = "SUMAVAL_PACH"; // dmCassa->
			dbBaniiPrim->DataField = "SUMAVAL_PRIM"; // dmCassa->
		}
	}
}

// ---------------------------------------------------------------------------
int __fastcall TfVinz::UpdateTickCount(int TickInc)
{
	TIniFile *fini = new TIniFile(fPrintSetup->sIniPath);
	int TickCount = fini->ReadInteger("Cassa", "TickCount", 0);
	if (dmCassa->isPridn)
		fini->WriteInteger("Cassa", "TickCount", TickCount + TickInc);
	else
		fini->WriteInteger("Cassa", "TickCount", 0);
	delete fini;
	return (TickCount + TickInc);
}

// ---------------------------------------------------------------------------
void __fastcall TfVinz::SBtnResetTickCounterClick(TObject *Sender)
{
	TIniFile *fini = new TIniFile(fPrintSetup->sIniPath);
	fini->WriteInteger("Cassa", "TickCount", 0);
	EdTickCount->Text = 0;
	delete fini;
	WideString MCmd = "510=";
	fPrintSetup->MiniReports(MCmd);
}
// ---------------------------------------------------------------------------

void __fastcall TfVinz::EdTickCountChange(TObject *Sender)
{
	TIniFile *fini = new TIniFile(fPrintSetup->sIniPath);
	// int MaxTickCount = fini->ReadInteger("Cassa", "MaxTickCount", 120);
	String asMaxTickCount = fini->ReadString("Cassa", "MaxTickCount",
		"120");
	int MaxTickCount = StrToInt(asMaxTickCount);
	int CurTickCount = StrToInt(EdTickCount->Text.Trim());
	LbWarningTickCount->Visible = (CurTickCount >= MaxTickCount);
	delete fini;
}
// ---------------------------------------------------------------------------

void __fastcall TfVinz::btnBiletToClipboardClick(TObject *Sender)
{
  TSagiODACSmartQuery* q = dmCassa->qsBiltets;

  q->DisableControls();

  TBookmark b = q->GetBookmark();

  String s;
  for (q->First(); !q->Eof; q->Next())
    s += q->FieldByName("cecu")->AsString + "\n";

  Clipboard()->AsText = s;

  q->GotoBookmark(b);
  q->FreeBookmark(b);

  q->EnableControls();
}
//---------------------------------------------------------------------------
void __fastcall TfVinz::FormShow(TObject *Sender)
{
	TIniFile *fini = new TIniFile(fPrintSetup->sIniPath);
	fMain->DrawPricesFromDB = fini->ReadString("Other", "DrawPricesFromDB", "false").LowerCase() == (String)("true") ;
	delete fini;
  if (dmCassa->bBookingMode)
		btSelect->Click();
}
//---------------------------------------------------------------------------
void __fastcall TfVinz::btnBroniClick(TObject *Sender)
{
  fCheckBroni->ShowModal();
  CheckBroniFlick->Enabled = false;
  btnBroni->ParentFont = true;
}
//---------------------------------------------------------------------------
void __fastcall TfVinz::TimerCheckBroniTimer(TObject *Sender)
{
  dmCassa->qCheckBroni->Refresh();
  if (CheckBroniCount < dmCassa->qCheckBroni->RecordCount)
  {                                    
    CheckBroniCount = dmCassa->qCheckBroni->RecordCount;
    CheckBroniFlick->Enabled = true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfVinz::CheckBroniFlickTimer(TObject *Sender)
{
  if (btnBroni->Font->Color != clRed)
    btnBroni->Font->Color = clRed;
  else
    btnBroni->Font->Color = clBlack;
}

void __fastcall TfVinz::actCustomExecute(TObject *Sender)
{
    if (!dmCassa->qsBiltets->Active)
      return;

    fCustomPrice = new TfCustomPrice(this);
    fCustomPrice->edPrice->Text = dmCassa->qsBiltets->FieldByName("sumat")->AsString;
    if (fCustomPrice->ShowModal() == mrOk)
    {
      spSetCustomPrice->ParamByName("p_id_casalenta")->AsString = dmCassa->qsBiltets->FieldByName("idcaslenta")->AsString;
      spSetCustomPrice->ParamByName("p_summ")->AsString = fCustomPrice->edPrice->Text;
			spSetCustomPrice->ParamByName("p_comment")->AsString = fCustomPrice->mComment->Lines->Text;
			spSetCustomPrice->Execute();

			dmCassa->qsBiltets->Refresh();
			dmCassa->qsV1_CASALENTA->Refresh();
		}
		delete fCustomPrice;
}
//---------------------------------------------------------------------------

void __fastcall TfVinz::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if ( Key == VK_RETURN)
	{
		if (!btnLaTipar->Enabled)
			btSelect->Click();
	}
}
//---------------------------------------------------------------------------

void __fastcall TfVinz::btLaTiparBonClick(TObject *Sender)
{
/*	if (((!dmCassa->isPridn || !NotDefValuta())
		&& dmCassa->qsV1_CASALENTASUMA_PACH->AsFloat > dbBaniiPrim->Value) ||
		(dmCassa->qsV1_CASALENTASUMAVAL_PACH->AsFloat > dbBaniiPrim->Value))
	{
		ShowMessage(fMain->LS->Text["entersum"]);
		dbBaniiPrim->SetFocus();
	}
	else
	{
*/
//		bool zz = btFullOk->Enabled;
//		bool zz = false;
//		dmCassa->BonuriLaTipar(zz);
		dbgrV->ReadOnly = true;
		TiparBon();
}
//---------------------------------------------------------------------------
//Codul e similar cu btnLaTiparClick
void __fastcall TfVinz::BtPterminalClick(TObject *Sender)
{
	if (((!dmCassa->isPridn || !NotDefValuta())
		&& dmCassa->qsV1_CASALENTASUMA_PACH->AsFloat > dbBaniiPrim->Value) ||
		(dmCassa->qsV1_CASALENTASUMAVAL_PACH->AsFloat > dbBaniiPrim->Value))
	{
		ShowMessage(fMain->LS->Text["entersum"]);
		dbBaniiPrim->SetFocus();
	}
	else
	{
		bool zz = btFullOk->Enabled;
    // Plata cu card
		dmCassa->BileteLaTipar(zz,2, cbxBroni->Checked);
		fSelRuta->PayLockedPlaces();
		btFullOk->Enabled = true;
    btLaTiparBon->Enabled = true;
		ToFullOk->Enabled = false;
		btnLaTiparLISTADEIMB->Enabled = btFullOk->Enabled;

		dbgrV->ReadOnly = true;
		btAnul->Enabled = false;
		// pnlgrV->Enabled = false;
		dbBaniiPrim->Enabled = false;
		btFullOk->SetFocus();
		if (dmCassa->UserCanPrint && fPrintSetup->cbxListeBiletePrint->Checked && dmCassa->isCassaPerron)
			btnLaTiparLISTADEIMBClick(NULL);
		//Dezactivam Butonul de plata Terminal
    BtPterminal->Enabled = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TfVinz::fillAddInfoBox(TObject* Sender)
{
	AddInfoAndTypeBox->Images = TAdditionalInfoLinker::instanse()->getAllIcons();
	AddInfoAndTypeBox->Items = TAdditionalInfoLinker::instanse()->getAllNames();
	for (int i = 0; i < AddInfoAndTypeBox->Items->Count; ++i)
	{
			if (i >= AddInfoAndTypeBox->Images->Count)
			{
			 break;
			}
			AddInfoAndTypeBox->ItemsEx->operator [](i)->ImageIndex = i;
	}
}

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TfVinz::AddInfoAndTypeBoxSelect(TObject *Sender)
{
	dmCassa->qsT1RUTABRONI->Edit();
	dmCassa->qsCASALENTA_PAYTYPE->Edit();
	dmCassa->qsT1RUTABRONI->FieldByName("ADDINFO")->AsString =
		AddInfoAndTypeBox->Text;
	dmCassa->qsCASALENTA_PAYTYPE->FieldByName("PAY_TYPE")->AsInteger =
		- (AddInfoAndTypeBox->ItemIndex + 1);
	dmCassa->qsCASALENTA_PAYTYPE->Post();
	dmCassa->qsT1RUTABRONI->Post();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

