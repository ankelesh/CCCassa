//---------------------------------------------------------------------------

#ifndef uSaledTicksH
#define uSaledTicksH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "DBGridMy1.h"
#include "StaticDBGrid.h"
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include "RzButton.hpp"
#include "RzDlgBtn.hpp"
#include "RzRadChk.hpp"
#include "UnDBCtrl.h"
#include "UnSDGrid.h"
#include "LgSelect.h"
#include "RzPanel.hpp"
#include <Data.DB.hpp>
//---------------------------------------------------------------------------
class TfSaledTickets : public TForm
{
__published:	// IDE-managed Components
				TPanel *Panel2;
	TUnDBGrid *grCasaLenta;
  TUnDBGrid *grBilets;
        TSplitter *Splitter1;
        TRzDialogButtons *RzDialogButtons1;
				TRzCheckBox *cbxReTipar;
  TUnLangSelector *LS;
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfSaledTickets(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfSaledTickets *fSaledTickets;
//---------------------------------------------------------------------------
#endif
