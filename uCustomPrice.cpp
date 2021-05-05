//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uCustomPrice.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "LgSelect"
#pragma resource "*.dfm"
TfCustomPrice *fCustomPrice;
//---------------------------------------------------------------------------
__fastcall TfCustomPrice::TfCustomPrice(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfCustomPrice::FormShow(TObject *Sender)
{
    edPrice->SetFocus();
}
//---------------------------------------------------------------------------

