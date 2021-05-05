#include <vcl.h>
#pragma hdrstop

#include "uTipBilet.h"
#include "uDMcassa.h"
#include "uUnivers.h"
#include "uSelInlesn.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SagiEdit"
#pragma link "MemDS"
#pragma link "Ora"
#pragma link "OraSmart"
#pragma link "DBAccess"
#pragma link "LgSelect"
#pragma resource "*.dfm"
TfBiletInput *fBiletInput;
//---------------------------------------------------------------------------
__fastcall TfBiletInput::TfBiletInput(TComponent* Owner)
: TForm(Owner)
{
  dsBilets->DataSet = dmCassa->qsBiltets;
  prepar();
  LoadRgItems();
}
//---------------------------------------------------------------------------
void __fastcall TfBiletInput::LoadRgItems()
{
  rgTipBilet->Items->Clear();
  for (int i = 1; i <= 9; i++)
  {
    if (dmCassa->isPridn && ((i == 7) || (i == 8)))
      continue;
    rgTipBilet->Items->Add(LS->Text[i]);
  }
}
//---------------------------------------------------------------------------
void __fastcall TfBiletInput::rgTipBiletClick(TObject *Sender)
{
  int it = rgTipBilet->ItemIndex + 1;

  lbBag->Visible = false;


  lbInl->Visible = (it > 2);
  lbDep->Visible = (it > 3);
  lbCert->Visible = (it > 2 && it != 8);
  lbPasp->Visible = (it == 2 || it == 2 || (!dmCassa->isPridn && it == 7) || it == 8);
  lbPN->Visible = (it == 2 || (!dmCassa->isPridn && it != 2));

  lbCert->Visible = false;

  seInl->Visible = lbInl->Visible;
  seDep->Visible = lbDep->Visible;
  dbCert->Visible = lbCert->Visible ;
  dbPN->Visible = lbPN->Visible ;
  dbPasp->Visible = lbPasp->Visible ;
  dbBag->Visible = lbBag->Visible ;
  lbPasp->Caption =
      (it == 7 && !dmCassa->isPridn) ? LS->Text["BazeDoc"] : LS->Text["Passport"];

  seInl->Enabled = false;
  TField *fINLESN = dmCassa->qsBiltetsINLESN;

  switch (it)
  {
    case 1:
      //  Исправлено мной для повышения надежности и читабельности кода (А.Г.)
      if (fINLESN->AsString != "B")
        fINLESN->Clear();
      break;
      //  Было так (break по условию):
      //if (fINLESN->AsString == "B")
      //  break;
    case 2 :
      fINLESN->Clear();
      break;
    case 3 :
      fINLESN->AsString = "C";
      break;
    case 4 :
      fINLESN->AsString = "PE";
      seInl->Enabled = true;
      break;
    case 5 :
      fINLESN->AsString = "IR";
      seInl->Enabled = true;
      break;
    case 6 :
      fINLESN->AsString = "ST";
	  break;
	case 7 :
		if (dmCassa->isPridn)
			fINLESN->AsString = "DS";
		else
			fINLESN->AsString = "M";
	  break;
    //case 8 :
    //case 9 :
    default :
      fINLESN->Clear();
      seInl->Enabled = true;
  }
  if (fINLESN->AsString.IsEmpty())
    dmCassa->qsBiltetsDEPART->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TfBiletInput::prepar(int mm)
{
  if (!mm)
    qsBilAView->Close();

  qsBilAView->ParamByName("INL")->AsString = dmCassa->qsBiltetsINLESN->AsString;

  if (!mm)
  {
    qsBilAView->ParamByName("CODB")->AsString = dmCassa->qsBiltetsCOD->AsString;
    qsBilAView->Open();
  }
}
//---------------------------------------------------------------------------
void __fastcall TfBiletInput::seDepBtnPress(TObject *Sender)
{
  selectFromUnivDepart(dmCassa->qsBiltetsDEPART, NULL,
      dmCassa->qsBiltetsINLESN->AsString);
}
//---------------------------------------------------------------------------
void __fastcall TfBiletInput::seInlBtnPress(TObject *Sender)
{
  SelectInlesn(dmCassa->qsBiltets->Session, dmCassa->qsBiltetsINLESN,
      dmCassa->qsBiltetsRUTA->AsString);
}
//---------------------------------------------------------------------------
void __fastcall TfBiletInput::FormCloseQuery(TObject *Sender, bool &CanClose)
{
  CanClose = false;
  try
  {
    if (ModalResult == mrOk || ModalResult == mrAll)
      POST(dmCassa->qsBiltets)
    else
      CANCEL(dmCassa->qsBiltets)
    CanClose = true;
  }
  catch (Exception& E)
  {
    ShowMessage(LS->Text["ATTENTION"] + "\n\n" + E.Message);
  }
}
//---------------------------------------------------------------------------
void __fastcall TfBiletInput::FormShow(TObject *Sender)
{
  rgTipBilet->ItemIndex = 2;
}
//---------------------------------------------------------------------------
void __fastcall TfBiletInput::LSSetLanguage(TUnLangSelector *ASelector,
      TUnLanguage APrevLang)
{
  LoadRgItems();
}
//---------------------------------------------------------------------------

void __fastcall TfBiletInput::btOkClick(TObject *Sender)
{
	if (rgTipBilet->ItemIndex == 6 || cbApplyToAll->Checked)
		ModalResult = mrAll;
}
//---------------------------------------------------------------------------

