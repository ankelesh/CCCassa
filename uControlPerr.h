//---------------------------------------------------------------------------

#ifndef uControlPerrH
#define uControlPerrH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "DBAccess.hpp"
#include "MemDS.hpp"
#include "Ora.hpp"
#include "OraSmart.hpp"
#include "RzDlgBtn.hpp"
#include "SagiEdit.h"
#include "SagiODACSmartQueryLIB.h"
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include "RzDBBnEd.hpp"
#include "RzDBEdit.hpp"
#include "LgSelect.h"
#include "RzEdit.hpp"
#include "RzPanel.hpp"
//---------------------------------------------------------------------------
class TfControlDePerron : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TRzDialogButtons *RzDialogButtons1;
        TSagiODACSmartQuery *V1LISTIMB_VPRONM;
        TDataSource *dsV1LISTIMB_VPRONM;
        TLabel *Label2;
        TLabel *Label3;
        TIntegerField *V1LISTIMB_VPRONMCODCONTROLER;
        TIntegerField *V1LISTIMB_VPRONMCODCONTROLER2;
        TIntegerField *V1LISTIMB_VPRONMCODCONTROLER3;
        TStringField *V1LISTIMB_VPRONMCODCONTROLER_T;
        TStringField *V1LISTIMB_VPRONMCODCONTROLER2_T;
        TStringField *V1LISTIMB_VPRONMCODCONTROLER3_T;
        TRzDBButtonEdit *SagiEdit1;
        TRzDBButtonEdit *SagiEdit2;
        TRzDBButtonEdit *SagiEdit3;
  TUnLangSelector *LS;
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall FormShow(TObject *Sender);
		void __fastcall FormKeyPress(TObject *Sender, wchar_t &Key);
        void __fastcall SagiEdit1ButtonClick(TObject *Sender);
        void __fastcall SagiEdit2ButtonClick(TObject *Sender);
        void __fastcall SagiEdit3ButtonClick(TObject *Sender);
		void __fastcall SagiEdit1KeyPress(TObject *Sender, wchar_t &Key);
		void __fastcall SagiEdit2KeyPress(TObject *Sender, wchar_t &Key);
        void __fastcall SagiEdit3KeyPress(TObject *Sender, wchar_t &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TfControlDePerron(TComponent* Owner);
};
//---------------------------------------------------------------------------
void __fastcall selectPerrControl(TDate sDATA,String sRUTA);
extern PACKAGE TfControlDePerron *fControlDePerron;
//---------------------------------------------------------------------------
#endif
