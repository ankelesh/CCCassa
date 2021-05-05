#include <vcl.h>
#pragma hdrstop

#include "uControlPerr.h"
#include "uUsers.h"
#include "uDMcassa.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBAccess"
#pragma link "MemDS"
#pragma link "Ora"
#pragma link "OraSmart"
#pragma link "RzDlgBtn"
#pragma link "SagiEdit"
#pragma link "SagiODACSmartQueryLIB"
#pragma link "RzDBBnEd"
#pragma link "RzDBEdit"
#pragma link "LgSelect"
#pragma link "RzEdit"
#pragma link "RzPanel"
#pragma resource "*.dfm"
TfControlDePerron *fControlDePerron;

// ---------------------------------------------------------------------------
__fastcall TfControlDePerron::TfControlDePerron(TComponent* Owner)
	: TForm(Owner)
{
}

// ---------------------------------------------------------------------------
void __fastcall selectPerrControl(TDate sDATA, String sRUTA)
{
	if (!fUsers)
		Application->CreateForm(__classid(TfUsers), &fUsers);
	if (!fControlDePerron)
		fControlDePerron = new TfControlDePerron(Application);
	fControlDePerron->V1LISTIMB_VPRONM->Close();
	fControlDePerron->V1LISTIMB_VPRONM->ParamByName("data")->AsDateTime = int(sDATA);
	fControlDePerron->V1LISTIMB_VPRONM->ParamByName("ruta")->AsString = sRUTA;
	fControlDePerron->V1LISTIMB_VPRONM->Open();
	if (fControlDePerron->V1LISTIMB_VPRONM->RecordCount == 0)
	{
		throw Exception("Lista de imbarcare este nedefinita!");
	}
	EDIT(fControlDePerron->V1LISTIMB_VPRONM)
		fControlDePerron->ShowModal();
}

void __fastcall TfControlDePerron::FormCloseQuery(TObject *Sender,
	bool &CanClose)
{
	CanClose = true;
	switch (ModalResult)
	{
	case mrOk:
		if (ISEDIT(V1LISTIMB_VPRONM))
			POST(V1LISTIMB_VPRONM)
				dmCassa->DB_Commit();
		break;
	default:
		if (ISEDIT(V1LISTIMB_VPRONM))
			CANCEL(V1LISTIMB_VPRONM)
	}

}

// ---------------------------------------------------------------------------
void __fastcall TfControlDePerron::FormShow(TObject *Sender)
{
	ActiveControl = SagiEdit1;
}
// ---------------------------------------------------------------------------

void __fastcall TfControlDePerron::FormKeyPress(TObject *Sender, wchar_t &Key)
{
	if (Key == VK_ESCAPE)
		ModalResult = mrCancel;
	if (Key == VK_RETURN)
		ModalResult = mrOk;
}
// ---------------------------------------------------------------------------

void __fastcall TfControlDePerron::SagiEdit1ButtonClick(TObject *Sender)
{
	selectUser(V1LISTIMB_VPRONMCODCONTROLER, V1LISTIMB_VPRONMCODCONTROLER_T);
}
// ---------------------------------------------------------------------------

void __fastcall TfControlDePerron::SagiEdit2ButtonClick(TObject *Sender)
{
	selectUser(V1LISTIMB_VPRONMCODCONTROLER2, V1LISTIMB_VPRONMCODCONTROLER2_T);
}
// ---------------------------------------------------------------------------

void __fastcall TfControlDePerron::SagiEdit3ButtonClick(TObject *Sender)
{
	selectUser(V1LISTIMB_VPRONMCODCONTROLER3, V1LISTIMB_VPRONMCODCONTROLER3_T);
}
// ---------------------------------------------------------------------------

void __fastcall TfControlDePerron::SagiEdit1KeyPress(TObject *Sender,
	wchar_t &Key)
{
	if (iswalpha(Key))
	{
		selectUser(V1LISTIMB_VPRONMCODCONTROLER, V1LISTIMB_VPRONMCODCONTROLER_T, Key);
		SagiEdit2->SetFocus();
	}
	else
		if (Key == L'\b')
		{
			V1LISTIMB_VPRONMCODCONTROLER->Clear();
			V1LISTIMB_VPRONMCODCONTROLER_T->Clear();
		}
}
// ---------------------------------------------------------------------------

void __fastcall TfControlDePerron::SagiEdit2KeyPress(TObject *Sender,
	wchar_t &Key)
{
	if (iswalpha(Key))
	{
		selectUser(V1LISTIMB_VPRONMCODCONTROLER2, V1LISTIMB_VPRONMCODCONTROLER2_T, Key);
		SagiEdit2->SetFocus();
	}
	else
		if (Key == L'\b')
		{
			V1LISTIMB_VPRONMCODCONTROLER2->Clear();
			V1LISTIMB_VPRONMCODCONTROLER2_T->Clear();
		}
}
// ---------------------------------------------------------------------------

void __fastcall TfControlDePerron::SagiEdit3KeyPress(TObject *Sender,
	wchar_t &Key)
{
	if (iswalpha(Key))
	{
		selectUser(V1LISTIMB_VPRONMCODCONTROLER3, V1LISTIMB_VPRONMCODCONTROLER3_T, Key);
	}
	else
		if (Key == L'\b')
		{
			V1LISTIMB_VPRONMCODCONTROLER3->Clear();
			V1LISTIMB_VPRONMCODCONTROLER3_T->Clear();
		}
}
// ---------------------------------------------------------------------------
