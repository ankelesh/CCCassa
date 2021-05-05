//---------------------------------------------------------------------------

#ifndef uFindBookedTicketH
#define uFindBookedTicketH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "DBAccess.hpp"
#include "DBGridMy1.h"
#include "LgSelect.h"
#include "MemDS.hpp"
#include "Ora.hpp"
#include "OraSmart.hpp"
#include "SagiODACSmartQueryLIB.h"
#include "StaticDBGrid.h"
#include "UnDBCtrl.h"
#include "UnSDGrid.h"
#include <Buttons.hpp>
#include <Db.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include "SagiEdit.h"
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfBookedTickets : public TForm
{
__published:	// IDE-managed Components
  TUnDBGrid *UnDBGrid;
  TPanel *Panel1;
  TBitBtn *btOk;
  TBitBtn *btCancel;
  TDataSource *dsCasalenta;
  TSagiODACSmartQuery *qsCasalenta;
  TUnLangSelector *LS;
  TIntegerField *qsCasalentaID;
  TStringField *qsCasalentaCASA;
  TFloatField *qsCasalentaSUMA_PACH;
  TFloatField *qsCasalentaSUMA_PRIM;
  TDateTimeField *qsCasalentaDATA;
  TStringField *qsCasalentaDESCR;
  TStringField *qsCasalentaISRET;
  TIntegerField *qsCasalentaACCEPT;
  TIntegerField *qsCasalentaCASIR;
  TPanel *Panel2;
  TDataSource *dsUsers;
  TSagiODACSmartQuery *qsUsers;
  TPanel *Panel3;
  TGroupBox *GroupBox2;
  TUnDBGrid *UnDBGrid2;
  TDateTimePicker *dtFrom;
  TDateTimePicker *dtTill;
  TLabel *Label1;
  TLabel *Label2;
  TGroupBox *GroupBox1;
  TUnDBGrid *s;
  TDataSource *dsBilets;
  TSagiODACSmartQuery *qsBilets;
  TIntegerField *qsUsersUSER_ID;
  TStringField *qsUsersUSER_NAME;
  TStringField *qsBiletsCOD;
  TDateTimeField *qsBiletsDATA;
  TIntegerField *qsBiletsLOC;
  TIntegerField *qsBiletsIDCASLENTA;
  TStringField *qsBiletsINLESN;
  TFloatField *qsBiletsDEPART;
  TStringField *qsBiletsPERS_NUMELE;
  TStringField *qsBiletsPASAPORT;
  TIntegerField *qsBiletsPRINTS;
  TFloatField *qsBiletsSUMAT;
  TFloatField *qsBiletsPRET_BRONARE_ESTIMAT;
  TStringField *qsBiletsRIND_LOC_STRING;
  TStringField *qsBiletsDENUMIREA;
  TSplitter *Splitter1;
  TSplitter *Splitter2;
  void __fastcall dtFromChange(TObject *Sender);
  void __fastcall dtTillChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TfBookedTickets(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfBookedTickets *fBookedTickets;
//---------------------------------------------------------------------------
#endif
