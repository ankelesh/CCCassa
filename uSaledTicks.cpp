#include <vcl.h>
#pragma hdrstop

#include "uSaledTicks.h"
#include "uDMcassa.h"
#include "uMain.h"
#include "uVinz.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBGridMy1"
#pragma link "StaticDBGrid"
#pragma link "RzButton"
#pragma link "RzDlgBtn"
#pragma link "RzRadChk"
#pragma link "UnDBCtrl"
#pragma link "UnSDGrid"
#pragma link "LgSelect"
#pragma link "RzPanel"
#pragma resource "*.dfm"
TfSaledTickets *fSaledTickets;
//---------------------------------------------------------------------------
__fastcall TfSaledTickets::TfSaledTickets(TComponent* Owner)
        : TForm(Owner)
{
grCasaLenta->Load();
grBilets->Load();
grCasaLenta->DataSource=dmCassa->dsmFullCasaLentaPrev;
grBilets->DataSource=dmCassa->dsBiltets;
//grBilets->ReadOnly=true;
}
//---------------------------------------------------------------------------

void __fastcall TfSaledTickets::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Shift.Contains(ssAlt)&&Key=='E')
   cbxReTipar->Checked=!cbxReTipar->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TfSaledTickets::FormShow(TObject *Sender)
{
dmCassa->qsBiltets->Open();
//dmCassa->qsBiltets->Refresh();
dmCassa->osmFullCasaLentaPrev->Refresh();
}
//---------------------------------------------------------------------------

