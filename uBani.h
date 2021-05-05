//---------------------------------------------------------------------------
#ifndef uBaniH
#define uBaniH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "DBGridMy1.h"
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <ActnList.hpp>
#include <Mask.hpp>
#include "StaticDBGrid.h"
#include "LgSelect.h"
#include "UnDBCtrl.h"
#include "UnSDGrid.h"
#include "DBAccess.hpp"
#include "MemDS.hpp"
#include "Ora.hpp"
#include "OraSmart.hpp"
#include "SagiODACSmartQueryLIB.h"
#include <Db.hpp>
#include <System.Actions.hpp>
//---------------------------------------------------------------------------
class TfBaniiCassa : public TForm
{
__published:	// IDE-managed Components
  TUnDBGrid *dbgrCasa;
        TPanel *Panel1;
  TUnDBGrid *dbgrCasaP;
        TPanel *Panel2;
        TSplitter *Splitter1;
        TPanel *Panel3;
        TBitBtn *BitBtn1;
        TLabel *Label1;
        TMaskEdit *meSold;
        TActionList *ActionList1;
        TAction *Action1;
        TLabel *Label2;
  TUnLangSelector *LS;
  TSplitter *Splitter2;
  TSagiODACSmartQuery *sqSold;
  TOraDataSource *dsSold;
  TStringField *sqSoldVALUTA;
  TFloatField *sqSoldSOLDINIT;
  TFloatField *sqSoldPRIM;
  TFloatField *sqSoldOTD;
  TFloatField *sqSoldsoldfin;
  TPanel *PanSold;
  TPanel *Panel4;
  TBitBtn *BtnRefresh;
  TUnDBGrid *grCassaSold;
        void __fastcall dbgrCasaEditButtonClick(TObject *Sender);
        void __fastcall dbgrCasaPEditButtonClick(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Action1Execute(TObject *Sender);
        void __fastcall FormKeyPress(TObject *Sender, wchar_t &Key);
        void __fastcall meSoldKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall BitBtn1Click(TObject *Sender);
  void __fastcall sqSoldCalcFields(TDataSet *DataSet);
  void __fastcall BtnRefreshClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfBaniiCassa(TComponent* Owner);
        void __fastcall processSold();
};
//---------------------------------------------------------------------------
extern PACKAGE TfBaniiCassa *fBaniiCassa;
//---------------------------------------------------------------------------
#endif
