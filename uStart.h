//---------------------------------------------------------------------------
#ifndef uStartH
#define uStartH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Mask.hpp>
#include <Db.hpp>
#include "MemDS.hpp"
#include "Ora.hpp"
#include <ExtCtrls.hpp>
#include "DBAccess.hpp"
#include "OdacVcl.hpp"
#include "LgSelect.h"
#include <Vcl.Menus.hpp>
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TfStart : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TMaskEdit *meDispName;
        TLabel *Label2;
        TMaskEdit *meOperName;
        TMaskEdit *meOperPasw;
        TLabel *Label6;
        TSpeedButton *SpeedButton1;
        TLabel *lblMetka;
        TLabel *Label4;
        TMaskEdit *meOperPasw1;
        TLabel *Label5;
        TLabel *Label8;
        TPanel *pnlUsPa;
        TLabel *lbUsername;
        TLabel *lbPassword;
        TEdit *edUsername;
        TMaskEdit *edPassword;
        TComboBox *edServer;
        TLabel *lbServer;
        TSpeedButton *SpeedButton2;
  TComboBox *LangCB;
  TUnLangSelector *LS;
	TcxButton *btOk;
	TcxButton *btnCancel;
        void __fastcall btOkClick(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
  void __fastcall LangCBChange(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
private:	// User declarations
bool ccl;
    TConnectDialog*FConnectDialog;
    long FRetries;
    bool FOldCreateOrder;

    void __fastcall SetConnectDialog(TConnectDialog*Value);
    bool GetCmdParam(String sParam); // overload
    bool GetCmdParam(String sParam, String &sValue);
protected:
		void virtual DoInit();
		void virtual DoConnect();

public:		// User declarations
        __fastcall TfStart(TComponent* Owner);
        bool __fastcall IDVer();
        bool __fastcall registerCompAndUser();
        void __fastcall setVisORAPassw();


  bool extConfig;

__published:
    __property TConnectDialog* ConnectDialog = {read=FConnectDialog,write=SetConnectDialog};

    __property bool OldCreateOrder = { read=FOldCreateOrder,write=FOldCreateOrder};
};
//---------------------------------------------------------------------------
extern PACKAGE TfStart *fStart;
//---------------------------------------------------------------------------
#endif
