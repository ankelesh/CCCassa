#include <vcl.h>
#pragma hdrstop

#include "uRetiparBil.h"
#include "uPrintSetup.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RzDlgBtn"
#pragma link "LgSelect"
#pragma link "RzPanel"
#pragma resource "*.dfm"
TfRetiparBil *fRetiparBil;
//---------------------------------------------------------------------------
__fastcall TfRetiparBil::TfRetiparBil(TComponent* Owner)
: TForm(Owner)
{
}
//---------------------------------------------------------------------------
int __fastcall retiparBileta()
{
  fRetiparBil->rgRezult->ItemIndex = 0;
  fRetiparBil->cbBiletZero->Checked = fPrintSetup->cbxRetiparBiletNull->Checked;
  if (fRetiparBil->ShowModal() != mrOk)
    return -1;

  return fRetiparBil->rgRezult->ItemIndex;
}
//---------------------------------------------------------------------------


