#include <vcl.h>
#pragma hdrstop

#include "uInfoPerute.h"
#include "uDMcassa.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBGridMy1"
#pragma link "SagiQueryLIB"
#pragma link "StaticDBGrid"
#pragma link "DBAccess"
#pragma link "MemDS"
#pragma link "Ora"
#pragma link "OraSmart"
#pragma link "SagiODACSmartQueryLIB"
#pragma resource "*.dfm"
TfInfoPeRute *fInfoPeRute;
//---------------------------------------------------------------------------
__fastcall TfInfoPeRute::TfInfoPeRute(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfInfoPeRute::ShowInfroPeRUTE()
{
qsVRutes->Close();
qsVRutes->Open();
qsVRutesD->Open();
fInfoPeRute->ShowModal();

}

