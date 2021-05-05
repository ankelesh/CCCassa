//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "uFindBookedTicket.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBAccess"
#pragma link "DBGridMy1"
#pragma link "LgSelect"
#pragma link "MemDS"
#pragma link "Ora"
#pragma link "OraSmart"
#pragma link "SagiODACSmartQueryLIB"
#pragma link "StaticDBGrid"
#pragma link "UnDBCtrl"
#pragma link "UnSDGrid"
#pragma link "SagiEdit"
#pragma resource "*.dfm"
TfBookedTickets *fBookedTickets;
//---------------------------------------------------------------------------
__fastcall TfBookedTickets::TfBookedTickets(TComponent* Owner)
  : TForm(Owner)
{
  dtFrom->Date = Now();
  dtTill->Date = Now();

  qsCasalenta->Params->ParamByName("date_from")->AsDateTime = dtFrom->Date;
  qsCasalenta->Params->ParamByName("date_till")->AsDateTime = dtTill->Date;
}
//---------------------------------------------------------------------------


void __fastcall TfBookedTickets::dtFromChange(TObject *Sender)
{
  qsCasalenta->Params->ParamByName("date_from")->AsDateTime = dtFrom->Date;
  qsCasalenta->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TfBookedTickets::dtTillChange(TObject *Sender)
{

  qsCasalenta->Params->ParamByName("date_till")->AsDateTime = dtTill->Date;
  qsCasalenta->Refresh();
}
//---------------------------------------------------------------------------

