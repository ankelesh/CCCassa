//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uSubscription.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBGridMy1"
#pragma link "StaticDBGrid"
#pragma link "UnDBCtrl"
#pragma link "UnSDGrid"
#pragma link "DBAccess"
#pragma link "MemDS"
#pragma link "Ora"
#pragma link "OraSmart"
#pragma link "SagiODACSmartQueryLIB"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxDBEdit"
#pragma link "cxImage"
#pragma resource "*.dfm"
TfSubscription *fSubscription;
//---------------------------------------------------------------------------
__fastcall TfSubscription::TfSubscription(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfSubscription::FormShow(TObject *Sender)
{
	qsContracts->Open();
	qsRoutes->Open();
	lbBarcode->Caption = qsContracts->FieldByName("barcode")->AsString;
}
//---------------------------------------------------------------------------
void __fastcall TfSubscription::btnFindClick(TObject *Sender)
{
	Barcode = edBarcode->Text;
	edBarcode->Text = "";

	qsContracts->ParamByName("barcode")->AsString = Barcode;
	qsContracts->Refresh();

	if (!qsContracts->RecordCount)
	{
		lbBarcode->Caption = Barcode + ": ничего не найдено";
		pnlActions->Visible = false;
	}
	else
	{
		pnlActions->Visible = true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TfSubscription::qsContractsAfterScroll(TDataSet *DataSet)
{
	lbBarcode->Caption = qsContracts->FieldByName("barcode")->AsString;
}
//---------------------------------------------------------------------------
void __fastcall TfSubscription::btnCheckInClick(TObject *Sender)
{
	spCheckIn->ParamByName("p_subscription_id")->AsInteger = qsContracts->FieldByName("id_tip_contract")->AsInteger;
	spCheckIn->ParamByName("p_event_id")->AsInteger = qsRoutes->FieldByName("codu")->AsInteger;
	spCheckIn->ParamByName("p_event_date")->AsDateTime = qsRoutes->FieldByName("data")->AsDateTime;
	spCheckIn->Execute();

	edBarcode->SetFocus();

	lbBarcode->Caption = Barcode + ": " + qsRoutes->FieldByName("data")->AsString + " - проход";
	qsRoutes->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TfSubscription::edBarcodeKeyPress(TObject *Sender, System::WideChar &Key)

{
	if (Key == VK_RETURN)
		btnFind->Click();
	else if (Key == '$')
		Key = 0;
}
//---------------------------------------------------------------------------

