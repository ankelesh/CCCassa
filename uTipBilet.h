//---------------------------------------------------------------------------

#ifndef uTipBiletH
#define uTipBiletH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include "SagiEdit.h"
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "MemDS.hpp"
#include "Ora.hpp"
#include "OraSmart.hpp"
#include <Db.hpp>
#include "DBAccess.hpp"
#include "LgSelect.h"
//---------------------------------------------------------------------------
class TfBiletInput : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TBitBtn *btOk;
        TBitBtn *btCancel;
        TPanel *Panel2;
        TLabel *lbInl;
        TLabel *lbDep;
        TLabel *lbCert;
        TDBEdit *dbCert;
        TLabel *lbPN;
        TDBEdit *dbPN;
        TLabel *lbPasp;
        TLabel *lbBag;
        TDBEdit *dbBag;
        TLabel *Label7;
        TDBEdit *DBEdit7;
        TSagiEdit *seDep;
        TSagiEdit *seInl;
        TSmartQuery *qsBilAView;
        TOraDataSource *dsBilets;
  TUnLangSelector *LS;
  TDBMemo *dbPasp;
	TRadioGroup *rgTipBilet;
	TCheckBox *cbApplyToAll;
        void __fastcall rgTipBiletClick(TObject *Sender);
        void __fastcall seDepBtnPress(TObject *Sender);
        void __fastcall seInlBtnPress(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall LSSetLanguage(TUnLangSelector *ASelector,
          TUnLanguage APrevLang);
	void __fastcall btOkClick(TObject *Sender);
private:	// User declarations
        void ChangeField(TDBGrid* Grid, TField* Field);
public:		// User declarations
        __fastcall TfBiletInput(TComponent* Owner);
        void __fastcall LoadRgItems();
        void __fastcall prepar(int mm=0);
};
//---------------------------------------------------------------------------
extern PACKAGE TfBiletInput *fBiletInput;
//---------------------------------------------------------------------------
#endif
