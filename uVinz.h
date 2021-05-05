//---------------------------------------------------------------------------
#ifndef uVinzH
#define uVinzH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ActnList.hpp>
#include <Data.Db.hpp>
#include <System.Actions.hpp>

#include "Ora.hpp"
#include "DBAccess.hpp"
#include "RzDBStat.hpp"
#include "RzStatus.hpp"
#include "RzButton.hpp"
#include "RzRadChk.hpp"
#include "RzEdit.hpp"
#include "RzDBEdit.hpp"

#include "GaraMonthCalendar.h"
#include "DBGridMy1.h"
#include "StaticDBGrid.h"
#include "LgSelect.h"
#include "UnDBCtrl.h"
#include "UnSDGrid.h"
#include "MemDS.hpp"
#include "uTiparBon.h"
//---------------------------------------------------------------------------
class TfVinz : public TForm
{
__published:	// IDE-managed Components
        TPanel *pnlSel;
        TMaskEdit *meData;
        TMaskEdit *meSelDest;
        TLabel *Label1;
        TLabel *Label2;
        TPanel *Panel2;
        TPanel *pnlTipar;
  TUnDBGrid *dbgrV;
        TLabel *Label3;
        TMaskEdit *meRuta;
        TLabel *Label4;
        TBitBtn *btSelect;
        TPanel *Panel1;
        TBitBtn *btFullOk;
        TBitBtn *btnLaTipar;
        TBitBtn *btAnul;
        TLabel *Label7;
        TLabel *Label6;
        TLabel *Label5;
        TLabel *Label8;
        TActionList *ActionList1;
        TAction *toInl;
        TAction *ToInlQuick;
        TAction *ToAn;
        TAction *ToTipar;
        TAction *ToFullOk;
        TMaskEdit *meCntBlt;
        TAction *toBagaj;
        TAction *toPasaport;
        TPanel *pnlTimerCal;
        TGaraMonthCalendar *mmc;
        TLabel *lblTimp;
        TTimer *srvTimer;
        TTimer *Timer1;
        TLabel *lblGrupaCasei;
        TComboBox *cmbAuto;
        TCheckBox *cbxPerron;
        TBitBtn *btnLaTiparLISTADEIMB;
        TPanel *Panel3;
        TMemo *mmInfo;
        TRzDBStatusPane *RzDBStatusPane1;
	TRzDBNumericEdit *dbePlata;
	TRzDBNumericEdit *dbBaniiPrim;
	TRzDBNumericEdit *dbRest;
        TRzCheckBox *cbxStopRuta;
        TAction *actVinzPeeron;
        TAction *actRutaPlecat;
        TAction *actListImb;
        TCheckBox *cbxBroni;
        TPanel *pnlgrV;
        TPanel *pnlBroni;
        TOraDataSource *dsT1RUTABRONI;
        TLabel *Label10;
        TDBEdit *DBEdit1;
        TLabel *Label12;
	TDBEdit *edBookingDoc;
        TLabel *Label13;
        TLabel *Label14;
        TDBEdit *DBEdit4;
        TAction *actBroni;
        TLabel *Label15;
        TDBEdit *DBEdit5;
        TComboBox *cmbValuta;
        TLabel *lblValuta;
        TStaticText *stCursVal;
  TUnLangSelector *LS;
  TMaskEdit *EdTickCount;
  TLabel *LbTickCounter;
  TSpeedButton *SBtnResetTickCounter;
  TLabel *Label16;
  TLabel *LbWarningTickCount;
  TDBLookupComboBox *meFilter;
  TPanel *pnlBilet;
  TRzDBRichEdit *dbmemoBilet;
  TButton *btnBiletToClipboard;
	TOraStoredProc *spSetCustomPrice;
  TButton *btnBroni;
  TTimer *TimerCheckBroni;
  TTimer *CheckBroniFlick;
	TAction *actCustom;
	TAction *actSel;
	TBitBtn *btLaTiparBon;
	TBitBtn *BtPterminal;
	TDBEdit *ReservationNameBox;
	TDBEdit *ReservationSurnameBox;
	TLabel *ReservationNameInfo;
	TLabel *ReservationSurnameInfo;
	TComboBoxEx *AddInfoAndTypeBox;
	TButton *ToInlCallButton;
	TButton *F12ToInlButton;

	void __fastcall fillAddInfoBox(TObject* Sender);
				void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall meDataChange(TObject *Sender);
        void __fastcall mmcClick(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall mmcChange(TDate dd);
        void __fastcall dbgrVEditButtonClick(TObject *Sender);
        void __fastcall btnLaTiparClick(TObject *Sender);
        void __fastcall btAnulClick(TObject *Sender);
        void __fastcall dbBaniiPrimChange(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall btFullOkClick(TObject *Sender);
        void __fastcall dbBaniiPrimKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall meFilter_oldKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall toInlExecute(TObject *Sender);
        void __fastcall dbgrVColEnter(TObject *Sender);
        void __fastcall meDataKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall meDataEnter(TObject *Sender);
        void __fastcall meCntBltKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall toBagajExecute(TObject *Sender);
        void __fastcall srvTimerTimer(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall dbgrVKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall dbmemoBiletExit(TObject *Sender);
        void __fastcall dbmemoBiletEnter(TObject *Sender);
        void __fastcall btnLaTiparLISTADEIMBClick(TObject *Sender);
        void __fastcall actVinzPeeronExecute(TObject *Sender);
        void __fastcall actRutaPlecatExecute(TObject *Sender);
        void __fastcall cbxPerronClick(TObject *Sender);
        void __fastcall cbxBroniClick(TObject *Sender);
        void __fastcall actBroniExecute(TObject *Sender);
        void __fastcall cmbValutaChange(TObject *Sender);
  void __fastcall SBtnResetTickCounterClick(TObject *Sender);
  void __fastcall EdTickCountChange(TObject *Sender);
  void __fastcall btnBiletToClipboardClick(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
  void __fastcall btnBroniClick(TObject *Sender);
  void __fastcall TimerCheckBroniTimer(TObject *Sender);
  void __fastcall CheckBroniFlickTimer(TObject *Sender);
	void __fastcall actCustomExecute(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall btLaTiparBonClick(TObject *Sender);
	void __fastcall BtPterminalClick(TObject *Sender);
	void __fastcall AddInfoAndTypeBoxSelect(TObject *Sender);
private:	// User declarations
bool calInt;
int CheckBroniCount;
unsigned short year, month, day;
long lasdbgrVSelectedIndex;
public:		// User declarations
				__fastcall TfVinz(TComponent* Owner);
        void __fastcall ViziMode(int mo);
        void __fastcall SetToday();
				void __fastcall ToBagajInl(int mo,bool isAutoEd);
		void __fastcall FindBadBilet(long pID=0);
		    bool __fastcall FindBookedTicket(long pID);
        bool __fastcall IsBiletBagajOnly();

        void __fastcall UpdateValutaInfo();
		String __fastcall GetSessValuta();
        bool __fastcall NotDefValuta();
				bool __fastcall SelectComboValuta(String pVal);
				void __fastcall updateSumaPachDataSet();
				int __fastcall UpdateTickCount(int TickInc);
};
//---------------------------------------------------------------------------
extern PACKAGE TfVinz *fVinz;
//---------------------------------------------------------------------------
#endif
