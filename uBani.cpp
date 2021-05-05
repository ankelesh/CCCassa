#include <vcl.h>
#pragma hdrstop

#include "uBani.h"
#include "uDMcassa.h"
#include "uUnivers.h"
#include "uMain.h"
#include "uSYSS.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBGridMy1"
#pragma link "StaticDBGrid"
#pragma link "LgSelect"
#pragma link "UnDBCtrl"
#pragma link "UnSDGrid"
#pragma link "DBAccess"
#pragma link "MemDS"
#pragma link "Ora"
#pragma link "OraSmart"
#pragma link "SagiODACSmartQueryLIB"
#pragma resource "*.dfm"
TfBaniiCassa *fBaniiCassa;

// ---------------------------------------------------------------------------
__fastcall TfBaniiCassa::TfBaniiCassa(TComponent* Owner)
	: TForm(Owner)
{
	dbgrCasa->Load();
	dbgrCasaP->Load();
	dbgrCasa->DataSource = dmCassa->dsD_Cassa;
	dbgrCasaP->DataSource = dmCassa->dsD_CassaP;
	// qsCasaTotals->ParamByName("CASA")->AsString=NrCassa;
	// qsCasaTotals->ParamByName("CASIR")->AsInteger=UserID;
	// qsCasaTotals->ParamByName("DATA")->AsDateTime=qsDocsDATAMANUAL->AsDateTime;
	PanSold->Visible = dmCassa->isPridn;
	sqSold->ParamByName("CASIR")->AsInteger = dmCassa->UserID;
	sqSold->ParamByName("CASA")->AsString = dmCassa->NrCassa;
	sqSold->ParamByName("DATA")->AsDateTime = dmCassa->qsDocsDATAMANUAL->AsDateTime;
	sqSold->Open();
}

// ---------------------------------------------------------------------------
void __fastcall TfBaniiCassa::dbgrCasaEditButtonClick(TObject *Sender)
{
	if (dbgrCasa->SelectedField == dmCassa->qsD_CassaCasir)
		selectFromUniv(dmCassa->qsD_CassaPERS_ID, dmCassa->qsD_CassaCasir, 4);
	if (dbgrCasa->SelectedField == dmCassa->qsD_CassaVALUTA)
		selectFromSYSS(dmCassa->qsD_CassaVALUTA, NULL, 3, false, "UM", "S", NULL, NULL);
}

// ---------------------------------------------------------------------------
void __fastcall TfBaniiCassa::dbgrCasaPEditButtonClick(TObject *Sender)
{
	if (dbgrCasaP->SelectedField == dmCassa->qsD_CassaPCasir)
		selectFromUniv(dmCassa->qsD_CassaPPERS_ID, dmCassa->qsD_CassaPCasir, 4);
	else
		if (dbgrCasaP->SelectedField == dmCassa->qsD_CassaPVALUTA)
			selectFromSYSS(dmCassa->qsD_CassaPVALUTA, NULL,
			3, false, "UM", "S", NULL, NULL);
}

// ---------------------------------------------------------------------------
void __fastcall TfBaniiCassa::processSold()
{
	dbgrCasaP->keyBuf = "";
	dbgrCasaP->SetFocus();
	INSERT(dmCassa->qsD_CassaP)
		dbgrCasaPEditButtonClick(NULL);
	dbgrCasaP->SelectedField = dmCassa->qsD_CassaPSUMA;

	if (meSold->Text.Length())
	{
		dmCassa->qsD_CassaPSUMA->AsFloat = dmCassa->soldFin - meSold->Text.ToDouble();
		meSold->Text = "";
		POST(dmCassa->qsD_CassaP);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfBaniiCassa::FormKeyDown(TObject *Sender, WORD &Key,
	TShiftState Shift)
{
	if (Key == 107 && ISEDIT(dmCassa->qsD_Cassa) == false && ISEDIT(dmCassa->qsD_CassaP) == false)
	{
		Key = 0;
		dbgrCasa->keyBuf = "";
		dbgrCasa->SetFocus();
		INSERT(dmCassa->qsD_Cassa)
			dbgrCasaEditButtonClick(NULL);
		dbgrCasa->SelectedField = dmCassa->qsD_CassaSUMA;
		Key = 0;
	}
	// 109
	if (Key == 109 && ISEDIT(dmCassa->qsD_Cassa) == false && ISEDIT(dmCassa->qsD_CassaP) == false)
	{
		Key = 0;
		processSold();
		Key = 0;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TfBaniiCassa::Action1Execute(TObject *Sender)
{
	// meSold->SetFocus();
	String ss;
	if (InputQuery("Introduceti suma, care ramane in sold (20 lei)", ">", ss))
	{
		try
		{
			ss.ToInt();
		}
		catch (Exception &E)
		{
			ShowMessage(fMain->LS->Text["incorsum"] + "\n" + E.Message);
			return;
		}
		meSold->Text = ss;
		processSold();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfBaniiCassa::FormKeyPress(TObject *Sender, wchar_t &Key)
{
	// if(Key==187||Key==189) Key=0;
	if (Key == L'-' || Key == L'+')
		Key = 0;
}
// ---------------------------------------------------------------------------

void __fastcall TfBaniiCassa::meSoldKeyDown(TObject *Sender, WORD &Key,
	TShiftState Shift)
{
	/* if(Key==VK_RETURN)
	 {
	 Key=109;
	 FormKeyDown(Sender, Key,
	 TShiftState ());
	 Key=0;
	 } */
}
// ---------------------------------------------------------------------------

void __fastcall TfBaniiCassa::BitBtn1Click(TObject *Sender)
{
	fMain->toRest->Execute();
}
// ---------------------------------------------------------------------------

void __fastcall TfBaniiCassa::sqSoldCalcFields(TDataSet *DataSet)
{
	sqSoldsoldfin->AsFloat = sqSoldSOLDINIT->AsFloat + sqSoldPRIM->AsFloat + sqSoldOTD->AsFloat;
}
// ---------------------------------------------------------------------------

void __fastcall TfBaniiCassa::BtnRefreshClick(TObject *Sender)
{
	sqSold->ParamByName("CASIR")->AsInteger = dmCassa->UserID;
	sqSold->ParamByName("CASA")->AsString = dmCassa->NrCassa;
	sqSold->ParamByName("DATA")->AsDateTime = dmCassa->qsDocsDATAMANUAL->AsDateTime;
	sqSold->Close();
	sqSold->Open();
}
// ---------------------------------------------------------------------------
