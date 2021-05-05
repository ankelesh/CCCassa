#ifndef VizionH
#define VizionH
//---------------------------------------------------------------------------
#include "TTF160_TLB.hpp"
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include "DBGridMy1.h"
#include <Dialogs.hpp>
#include <FileCtrl.hpp>
#include <Menus.hpp>
#include "SagiQueryLIB.h"
#include <ImgList.hpp>
#include "StaticDBGrid.h"
#include "DBAccess.hpp"
#include "MemDS.hpp"
#include "Ora.hpp"
#include "OraSmart.hpp"
#include "SagiODACSmartQueryLIB.h"
#include <ActnList.hpp>
#include "UnDBCtrl.h"
#include "UnSDGrid.h"
#include "LgSelect.h"
#include "cxControls.hpp"
#include "cxSplitter.hpp"
#include "cxPC.hpp"
#include "cxCalendar.hpp"
#include "cxContainer.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCheckBox.hpp"
#include "cxLabel.hpp"
#include "cxGroupBox.hpp"
#include "SagiEdit.h"
#include "cxButtons.hpp"
#include "UnScList.h"
#include "cxRadioGroup.hpp"
#include "cxDBEdit.hpp"
#include "cxMemo.hpp"
#include "cxDateUtils.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "dxBarBuiltInMenu.hpp"
#include "dxCore.hpp"
#include "SynEdit.hpp"
#include "SynEditHighlighter.hpp"
#include "SynHighlighterSQL.hpp"
#include "SynEditMiscClasses.hpp"
#include "SynEditSearch.hpp"
#include "UnSynEdit.h"
#include "UnSynEditPLSQL.h"
 //---------------------------------------------------------------------------
enum TSQLType { sqltQuery, sqltCommand };
enum TBreakType { btSuccess, btFail, btUser };
 //---------------------------------------------------------------------------
class TExecThread : public TThread
{
private:
	double ExecTime;
	String ExecTimeText;
protected:
	void __fastcall Execute();
public:
	__fastcall TExecThread(bool CreateSuspended);
	void __fastcall UpdateTimer();
};
//---------------------------------------------------------------------------
class TfTOAD : public TForm
{
__published:	// IDE-managed Components
  TDataSource *dsObjects;
  TDataSource *dsTVQ;
  TcxPageControl *pcTOAD;
  TcxTabSheet *tsTables;
  TPanel *panLeft;
  TcxTabSheet *tsQueries;
  TPanel *panQuery;
	TUnSynEditPLSQL *dcmQuery;
  TSagiODACSmartQuery *sqq;
  TSagiODACSmartQuery *sqObjects;
  TcxSplitter *splQuery;
  TUnDBGrid *grObjects;
  TUnDBGrid *grCustom;
  TStringField *sqObjectsNAME;
  TSagiODACSmartQuery *sqCustom;
  TDataSource *dsCustom;
  TPanel *panTop;
  TRadioGroup *rgObject;
  TcxSplitter *splObjects;
  TPanel *panRefresh;
  TSpeedButton *sbRefObjects;
  TSpeedButton *sbRefCustom;
  TcxTabSheet *tsOptions;
		TCheckBox *cbxSqlMonitor;
  TUnLangSelector *LS;
  TPanel *panResult;
  TDBGridMy1 *dbgrTVQ;
  TcxSplitter *splMemo;
  TDBMemo *dbmField;
  TcxTabSheet *tsSold;
  TcxGroupBox *gbSoldOptions;
  TUnDBGrid *grSold;
  TcxDateEdit *edSoldDate;
  TcxCheckBox *cbSoldMethodOLD;
  TcxCheckBox *cbSoldNoActual;
  TcxLabel *lbSoldDate;
  TcxCheckBox *cbSoldShowZero;
  TcxCheckBox *cbSoldSmart;
  TcxCheckBox *cbSoldAP;
  TcxCheckBox *cbSoldCont;
  TcxCheckBox *cbSoldCont1;
  TcxCheckBox *cbSoldSC;
  TcxCheckBox *cbSoldDep;
  TcxCheckBox *cbSoldSC1;
  TcxTextEdit *edSoldCont;
  TcxTextEdit *edSoldCont1;
  TUnScList *edSoldSC;
  TUnScList *edSoldDep;
  TUnScList *edSoldSC1;
  TcxCheckBox *cbSoldNrDoc;
  TcxTextEdit *edSoldNrDoc;
  TcxCheckBox *cbSoldStrSC;
  TcxTextEdit *edSoldStrSC;
  TcxCheckBox *cbSoldNrCM;
  TcxTextEdit *edSoldNrCM;
  TcxCheckBox *cbSoldData;
  TcxTextEdit *edSoldData;
  TcxCheckBox *cbSoldCant;
  TcxCheckBox *cbSoldPret;
  TcxCheckBox *cbSoldSumaVal;
  TcxCheckBox *cbSoldSumaGaap;
  TcxCheckBox *cbSoldCant1;
  TcxTextEdit *edSoldCmd;
  TcxButton *btMakeSold;
  TcxButton *btSoldTestTXSLD;
  TcxButton *btSoldRebuildTXSLD;
  TcxButton *btSoldRebuildTSLD;
  TcxButton *btSoldClearZTEMP;
  TcxLabel *lbSoldID;
  TcxTextEdit *edSoldID;
  TcxLabel *lbSoldFilter;
  TcxTextEdit *edSoldFilter;
  TSmartQuery *sqSold;
  TDataSource *dsSold;
  TcxTabSheet *tsCheck;
  TPanel *panCheckTop;
  TSmartQuery *sqCheck;
  TDataSource *dsCheck;
  TUnDBGrid *grCheck;
  TcxDBMemo *dmCheckText;
  TcxCheckBox *cbCheckActiveDS;
  TcxButton *btCheckRunAll;
  TcxButton *btCheckRunOne;
  TcxButton *btCheckClearAll;
  TcxButton *btCheckRefreshList;
  TcxRadioButton *rbCheckLostChars;
  TcxRadioButton *rbCheckCMSPType;
  TcxRadioButton *rbCheckTXSLD;
  TcxRadioButton *rbCheckSequences;
  TcxRadioButton *rbCheckTunigIssues;
	TStatusBar *sbSQL;

  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
  void __fastcall rgObjectClick(TObject *Sender);
  void __fastcall dbgrTVQColEnter(TObject *Sender);
  void __fastcall sqqAfterOpen(TDataSet *DataSet);
  void __fastcall dcmQueryKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
  void __fastcall sqObjectsAfterScroll(TDataSet *DataSet);
  void __fastcall sbRefObjectsClick(TObject *Sender);
  void __fastcall sbRefCustomClick(TObject *Sender);
        void __fastcall cbxSqlMonitorClick(TObject *Sender);
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall dbmFieldKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
  void __fastcall SoldParametersChange(TObject *Sender);
  void __fastcall cbCheckActiveDSClick(TObject *Sender);
  void __fastcall btCheckRefreshListClick(TObject *Sender);
	void __fastcall sqqAfterExecute(TObject *Sender, bool Result);
private:	// User declarations
  TExecThread* ExecThread;
  TSQLType ExecSQLType;
  void __fastcall SQLExecute(bool LikeToad);
  void __fastcall MakeSoldCmd();

  void __fastcall StartExecTimer(TSQLType QueryType);
  void __fastcall StopExecTimer(TBreakType BreakType);
public:		// User declarations
  __fastcall TfTOAD(TComponent* Owner);
  void __fastcall gotoRegAdj(long cod);

};
//---------------------------------------------------------------------------
extern PACKAGE TfTOAD *fTOAD;
//---------------------------------------------------------------------------
#endif

