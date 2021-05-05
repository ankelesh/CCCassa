//---------------------------------------------------------------------------
#ifndef uRestH
#define uRestH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include "DBGridMy1.h"
#include "SagiQueryLIB.h"
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ActnList.hpp>
#include "MemDS.hpp"
#include "Ora.hpp"
#include "OraSmart.hpp"
#include "SagiODACSmartQueryLIB.h"
#include <ComCtrls.hpp>
#include "StaticDBGrid.h"
#include "DBAccess.hpp"
#include "RzButton.hpp"
#include "RzCmboBx.hpp"
#include "RzDBCmbo.hpp"
#include "RzDBChk.hpp"
#include "RzRadChk.hpp"
#include "UnDBCtrl.h"
#include "UnSDGrid.h"
#include "LgSelect.h"
#include <System.Actions.hpp>
//---------------------------------------------------------------------------
class TfRest : public TForm
{
__published:	// IDE-managed Components
        TPanel *pnlFind;
        TPanel *pnlRest;
        TLabel *Label1;
        TMaskEdit *meNrBilet;
  TUnDBGrid *DBGridMy11;
        TDataSource *dsRest;
        TDataSource *dsRestT;
        TDBEdit *dbedIP;
        TDBEdit *dbedRB;
        TSpeedButton *btFindBil;
        TGroupBox *rgpCauza;
        TRadioButton *rbIP1;
        TRadioButton *rbRB1;
        TLabel *Label6;
        TDBEdit *dbePrim;
        TBitBtn *btnLaTipar;
        TBitBtn *btAnul;
        TBitBtn *btnIesir1;
        TLabel *Label4;
        TActionList *ActionList1;
        TAction *rbIP;
        TAction *rbRB;
        TDBEdit *DBEdit2;
        TDBEdit *DBEdit1;
        TLabel *Label3;
        TLabel *Label2;
        TAction *btnIesir;
        TSagiODACSmartQuery *qsRestT;
        TSagiODACSmartQuery *qsRest;
        TStringField *qsRestTCOD;
        TFloatField *qsRestTIP;
        TFloatField *qsRestTRB;
        TDateTimeField *qsRestTDATA;
        TStringField *qsRestTRUTA;
        TStringField *qsRestTCECU;
        TIntegerField *qsRestTNRORD;
        TStringField *qsRestCOD;
        TFloatField *qsRestSC;
        TStringField *qsRestDESCR;
        TFloatField *qsRestUPL;
        TFloatField *qsRestRESTREAL;
        TFloatField *qsRestR5161;
        TFloatField *qsRestR5162;
        TFloatField *qsRestPROCENTRET;
        TSagiODACSmartQuery *osmT1LISTIMB_VPRON_RESTIT;
        TDataSource *dsmT1LISTIMB_VPRON_RESTIT;
        TPageControl *pgcRestInfo;
        TTabSheet *tsBilet;
        TTabSheet *tsInpRest;
        TDBRichEdit *dbmemoBilet;
        TLabel *Label5;
        TDBEdit *DBEdit3;
        TLabel *Label7;
        TIntegerField *osmT1LISTIMB_VPRON_RESTITIDCASLENTA;
        TStringField *osmT1LISTIMB_VPRON_RESTITCOD_REST_BILET;
        TFloatField *osmT1LISTIMB_VPRON_RESTITREST_PROCENT;
        TIntegerField *osmT1LISTIMB_VPRON_RESTITREST_MODE;
        TFloatField *osmT1LISTIMB_VPRON_RESTITREST_SUMA;
        TFloatField *osmT1LISTIMB_VPRON_RESTITREST_SUMA_C31;
        TFloatField *osmT1LISTIMB_VPRON_RESTITREST_SUMA_C32;
        TFloatField *osmT1LISTIMB_VPRON_RESTITREST_SUMA_C33;
        TFloatField *osmT1LISTIMB_VPRON_RESTITREST_SUMA_C34;
        TFloatField *osmT1LISTIMB_VPRON_RESTITREST_SUMA_C35;
        TFloatField *osmT1LISTIMB_VPRON_RESTITREST_SUMA_C36;
        TRzButton *rzBiletRecalc;
        TAction *actCalcRest;
        TRzDBComboBox *rzdbProcEdit;
        TIntegerField *osmT1LISTIMB_VPRON_RESTITREST_FULLSUMS;
        TDBCheckBox *DBCheckBox1;
        TTabSheet *tsDescSpec;
        TLabel *Label39;
        TLabel *Label40;
        TLabel *Label41;
        TLabel *Label42;
        TLabel *Label43;
        TLabel *Label44;
        TLabel *Label55;
        TLabel *Label56;
        TLabel *Label57;
        TLabel *Label58;
        TLabel *Label59;
        TLabel *Label60;
        TDBEdit *DBEdit23;
        TDBEdit *DBEdit24;
        TDBEdit *DBEdit25;
        TDBEdit *DBEdit26;
        TDBEdit *DBEdit27;
        TDBEdit *DBEdit28;
  TUnLangSelector *LS;
  TDataSource *dsRestBilet;
  TSagiODACSmartQuery *qsRestBilet;
  TStringField *qsRestBiletCECU;
  TBitBtn *BtnBezPrint;
        void __fastcall btFindBilClick(TObject *Sender);
        void __fastcall meNrBiletKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall meNrBiletChange(TObject *Sender);
        void __fastcall btAnulClick(TObject *Sender);
        void __fastcall btnLaTiparClick(TObject *Sender);
        void __fastcall rbIPClick(TObject *Sender);
        void __fastcall rbRBClick(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall btnIesir1Click(TObject *Sender);
        void __fastcall FormDeactivate(TObject *Sender);
        void __fastcall osmT1LISTIMB_VPRON_RESTITAfterInsert(
          TDataSet *DataSet);
        void __fastcall osmT1LISTIMB_VPRON_RESTITPostError(
          TDataSet *DataSet, EDatabaseError *E, TDataAction &Action);
        void __fastcall dbePrimChange(TObject *Sender);
        void __fastcall actCalcRestExecute(TObject *Sender);
        void __fastcall rzdbProcEditChange(TObject *Sender);
        void __fastcall osmT1LISTIMB_VPRON_RESTITREST_PROCENTChange(
          TField *Sender);
        void __fastcall BtnBezPrintClick(TObject *Sender);
		void __fastcall CalcRest();
        void __fastcall RestRecalcPrep(String vErrTick);
private:	// User declarations
public:		// User declarations
        __fastcall TfRest(TComponent* Owner);
        void __fastcall OpenClose(int mm,bool viiewMess=true);
        void __fastcall recalcTot();
        void __fastcall viziMode(int mode);
};
//---------------------------------------------------------------------------
extern PACKAGE TfRest *fRest;
//---------------------------------------------------------------------------
#endif
