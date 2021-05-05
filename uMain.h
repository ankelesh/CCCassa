//---------------------------------------------------------------------------
#ifndef uMainH
#define uMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <System.Actions.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.AxCtrls.hpp>
#include <Vcl.OleCtrls.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.StdActns.hpp>
#include <Data.Db.hpp>#include "Ora.hpp"
#include "OraSmart.hpp"
#include "UNWinSourceA.h"
#include "LgSelect.h"
#include "TTF160_TLB.hpp"
#include "shutdown.hpp"
#include "cxClasses.hpp"
#include "dxBar.hpp"
#include "dxBarApplicationMenu.hpp"
#include "dxRibbon.hpp"
#include "cxBarEditItem.hpp"
#include "cxCalendar.hpp"
#include "cxGraphics.hpp"
#include <System.ImageList.hpp>
//---------------------------------------------------------------------------
class TfMain : public TForm
{
__published:	// IDE-managed Components
        TStatusBar *stb;
	TF1Book *ExcTempl;
        TActionList *ActionList1;
        TAction *toVinz;
        TAction *toRest;
        TAction *toAux;
        TAction *toExit;
        TWindowClose *WindowClose1;
        TAction *specForF1;
   TShutdown *Shutdown1;
   TAction *ActRestart;
        TUNWinSourceA *UNWinSourceA1;
  TUnLangSelector *LS;
	TdxBarManager *dxBarManager;
	TdxBarApplicationMenu *dxBarApplicationMenu;
	TdxBar *dxBarManager1Bar1;
	TdxBarButton *ToolbarButton971;
	TdxBarButton *ToolbarButton973;
	TdxBarButton *ToolbarButton972;
	TdxBarButton *ToolbarButton975;
	TdxBarButton *SpeedButton1;
	TcxBarEditItem *ReportDP;
	TdxBarButton *Primireapredareabanii2;
	TdxBarButton *scurt;
	TdxBarButton *MiMiniReportsNew;
	TdxBarButton *MiMiniReports;
	TdxBarButton *RaportTotal2;
	TdxBarButton *RestituireaBiletelor2;
	TdxBarButton *Vinzareabiletelorcuinlesniri2;
	TdxBarButton *DailyCasRep;
	TdxBarButton *Raportmonetar2;
	TdxBarButton *Printersetup1;
	TdxBarButton *Print1;
	TdxBarButton *Calculator1;
	TdxBarButton *Informatiaperute1;
	TdxBarButton *Ultimulbiletneacceptat1;
	TdxBarButton *Listabiletelorvindute1;
	TdxBarButton *Subagent1;
	TdxBarButton *Close;
	TdxBarButton *Maximize1;
	TdxBarButton *Minimize1;
	TdxBarButton *WWWW;
	TdxBarSubItem *MiLang;
	TdxBarSubItem *Windows;
	TdxBarButton *MiLangEng;
	TdxBarButton *MiLangRom;
	TdxBarButton *MiLangRus;
	TdxBarSubItem *tbAux;
	TdxBarSubItem *tbWind;
	TdxBarButton *bbSql;
	TdxBarButton *dxBarButton1;
	TdxBarButton *dxBarButton2;
	TdxBarButton *bbCheckSubscription;
	TcxImageList *ilMenu;
        void __fastcall Orar1Click(TObject *Sender);
        void __fastcall Sosire1Click(TObject *Sender);
        void __fastcall Primireapredareabanii1Click(TObject *Sender);
        void __fastcall FinisareazileiGFC1Click(TObject *Sender);
   void __fastcall RestituireaBiletelor1Click(TObject *Sender);
   void __fastcall Vinzareabiletelorcuinlesniri1Click(TObject *Sender);
   void __fastcall Raportmonetar1Click(TObject *Sender);
        void __fastcall Exei1Click(TObject *Sender);
        void __fastcall Printersetup1Click(TObject *Sender);
        void __fastcall RaportTotal2Click(TObject *Sender);
        void __fastcall CloseClick(TObject *Sender);
        void __fastcall Maximize1Click(TObject *Sender);
        void __fastcall Minimize1Click(TObject *Sender);
        void __fastcall Print1Click(TObject *Sender);
        void __fastcall specForF1Execute(TObject *Sender);
        void __fastcall Informatiaperute1Click(TObject *Sender);
        void __fastcall Calculator1Click(TObject *Sender);
        void __fastcall Ultimulbiletneacceptat1Click(TObject *Sender);
   void __fastcall scurtClick(TObject *Sender);
   void __fastcall ActRestartExecute(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        String __fastcall UNWinSourceA1STRINGparam(
          String parames);
        int __fastcall UNWinSourceA1LONGparam(String parames);
        void __fastcall Listabiletelorvindute1Click(TObject *Sender);
  void __fastcall MiLangEngClick(TObject *Sender);
  void __fastcall MiLangRomClick(TObject *Sender);
  void __fastcall MiLangRusClick(TObject *Sender);
  void __fastcall MiMiniReportsClick(TObject *Sender);
  void __fastcall DailyCasRepClick(TObject *Sender);
  void __fastcall MiMiniReportsNewClick(TObject *Sender);
  void __fastcall FormDestroy(TObject *Sender);
  void __fastcall Subagent1Click(TObject *Sender);
	void __fastcall tbAuxPopup(TObject *Sender);
	void __fastcall bbSqlClick(TObject *Sender);
	void __fastcall dxBarButton2Click(TObject *Sender);
	void __fastcall bbCheckSubscriptionClick(TObject *Sender);
private:	// User declarations
	void __fastcall SagiSetupFormMDI(TForm *Sender);
public:		// User declarations
        __fastcall TfMain(TComponent* Owner);
        void __fastcall ReportEnabled(bool ee);
        void __fastcall SetToolbMode(bool ee);
				bool isWasGFC;
				bool DrawPricesFromDB;
};
//---------------------------------------------------------------------------
extern PACKAGE TfMain *fMain;
//---------------------------------------------------------------------------
#endif
