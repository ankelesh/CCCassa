//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uAddSelect.h"
#include "uSelect.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma resource "*.dfm"
TfAddSel *fAddSel;
//---------------------------------------------------------------------------
__fastcall TfAddSel::TfAddSel(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfAddSel::FormActivate(TObject *Sender)
{
  fSelRuta->AddSelResize(this);
}
//---------------------------------------------------------------------------

