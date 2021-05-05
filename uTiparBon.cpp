//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uTiparBon.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "LgSelect"
#pragma resource "*.dfm"
TTiparBonForm *TiparBonForm;
//---------------------------------------------------------------------------
__fastcall TTiparBonForm::TTiparBonForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
int __fastcall TiparBon() {
TiparBonForm->RichEdit->Lines->Clear();
TiparBonForm->printTry = false;
TiparBonForm->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TTiparBonForm::BtnPrintClick(TObject *Sender)
{
printTry = true;
if(rgroup->ItemIndex == 0) {
	bool zz = false;
	dmCassa->BonuriLaTipar(zz);
	bool openCheck = false;
	openCheck = fPrintSetup->OpenCheckDAISY_SX();
	// bonuri deschise
	if(!openCheck){
		RichEdit->Lines->Clear();
		RichEdit->SelAttributes->Color = clRed;
// 		RichEdit->SelText = "S-a efectuat operatia de tiparirea bonului fiscal."
//		"Nu exista bonuri deschise. Verificati tiparirea lui"
//		" pe printerul fiscal!!!";
	 RichEdit->SelText = "���� ��������� �������� ���������� ����������� ����."
		"� �������� ��� �������� �����. ��������� ������ �� ���������� ��������!!!";
	} else {
		fPrintSetup->CancelOpenCheckDAISY_SX();
		RichEdit->Lines->Clear();
		RichEdit->SelAttributes->Color = clRed;
//		RichEdit->SelText = "In printer a fost depistat un bon deschis.\n";
		RichEdit->SelText = "� �������� ��� ��������� �������� ���.\n";
		RichEdit->SelAttributes->Color = clRed;
//		RichEdit->SelText = "S-a efectuat operatia de anulare a ultimului bon\n";
		RichEdit->SelText = "���� ��������� �������� ������ ���������� ����.\n";
		RichEdit->SelAttributes->Color = clGreen;
//		RichEdit->SelText = "Puteti retipari bonul. \n";
		RichEdit->SelText = "������ ������������ ���. \n";
	}
// Copie duplicat
} else if (rgroup->ItemIndex == 1) {
		int result;
		result = fPrintSetup->DuplicateLastCheck();
		bool openCheck;
		openCheck = fPrintSetup->OpenCheckDAISY_SX();
		if(!openCheck){
			RichEdit->Lines->Clear();
			RichEdit->SelAttributes->Color = clRed;
//			RichEdit->SelText = "S-a efectuat operatia de tiparire duplicat.\n"
//			"Verificati tiparirea duplicatului de la printer!";
			RichEdit->SelText = "���� ��������� �������� ���������� ��������� "
			"���������� ����.\n"
			"��������� ������ �� ���������� ��������!!!";
		}
}
}
//---------------------------------------------------------------------------


void __fastcall TTiparBonForm::BitBtn1Click(TObject *Sender)
{

bool openCheck = false;
openCheck = fPrintSetup->OpenCheckDAISY_SX();
// bonuri deschise
if(!openCheck){
	RichEdit->Lines->Clear();
	RichEdit->SelAttributes->Color = clGreen;
//	RichEdit->SelText = "Nu exista bonuri deschise in printer.";
	RichEdit->SelText = "� �������� ��� �������� �����";
} else {
	fPrintSetup->CancelOpenCheckDAISY_SX();
	RichEdit->Lines->Clear();
	RichEdit->SelAttributes->Color = clRed;
	//RichEdit->SelAttributes->Color = clGreen;
//	RichEdit->SelText = "In printer a fost depistat un bon deschis.\n";
	RichEdit->SelText = "� �������� ��� ��������� �������� ���.\n";
	RichEdit->SelAttributes->Color = clGreen;
//	RichEdit->SelText = "S-a efectuat operatia de anulare a ultimului bon";
	RichEdit->SelText = "���� ��������� �������� ������ ���������� ����.\n";
}
}
//---------------------------------------------------------------------------


void __fastcall TTiparBonForm::InchideClick(TObject *Sender)
{
	ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

void __fastcall TTiparBonForm::BtnOkClick(TObject *Sender)
{
if(printTry){
	ModalResult = mrOk;
}
else {
	RichEdit->Lines->Clear();
	RichEdit->SelAttributes->Color = clGreen;
//	RichEdit->SelText = "De la deschiderea formei, nu s-a incercat"
//	"printarea unui bon\n Apasait Inchide daca ati deschis din greseala.";
	RichEdit->SelText = "C ������� �������� �����, �� ���� �������"
	" ����������� ���\n ������� ������ ���� �������� ������� �����.";
}
}
//---------------------------------------------------------------------------

