//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uCheckBroni.h"
#include "uDMCassa.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBAccess"
#pragma link "MemDS"
#pragma link "Ora"
#pragma link "OraSmart"
#pragma link "DBGridMy1"
#pragma link "StaticDBGrid"
#pragma link "UnDBCtrl"
#pragma link "UnSDGrid"
#pragma resource "*.dfm"
TfCheckBroni *fCheckBroni;
//---------------------------------------------------------------------------
__fastcall TfCheckBroni::TfCheckBroni(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfCheckBroni::btnAnullClick(TObject *Sender)
{
  if (MessageDlg("¬ы уверены что хотите аннулировать бронь?", mtConfirmation,
    TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
  {
    grCheckBroni->DataSource->DataSet->DisableControls();

    TBookmark TempBookmark = grCheckBroni->DataSource->DataSet->GetBookmark();
    for (int i = 0; i < grCheckBroni->SelectedRows->Count; i++)
    {
        grCheckBroni->DataSource->DataSet->Bookmark = grCheckBroni->SelectedRows->Items[i];
        Variant vv[1];
        dmCassa->db->ExecSQL("Call broni.BroniCancel ( " +
          grCheckBroni->DataSource->DataSet->FieldByName("idcasalenta")->AsString + ")", vv, 0);
    }

    grCheckBroni->DataSource->DataSet->GotoBookmark(TempBookmark);
    grCheckBroni->DataSource->DataSet->FreeBookmark(TempBookmark);
    grCheckBroni->DataSource->DataSet->Refresh();
    grCheckBroni->DataSource->DataSet->EnableControls();
  }
}
//---------------------------------------------------------------------------

void __fastcall TfCheckBroni::FormShow(TObject *Sender)
{
  btnAnull->Enabled = dmCassa->qCheckBroni->RecordCount;
}
//---------------------------------------------------------------------------


