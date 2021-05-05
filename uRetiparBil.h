//---------------------------------------------------------------------------

#ifndef uRetiparBilH
#define uRetiparBilH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "RzDlgBtn.hpp"
#include <ExtCtrls.hpp>
#include "LgSelect.h"
#include "RzPanel.hpp"
//---------------------------------------------------------------------------
class TfRetiparBil : public TForm
{
__published:	// IDE-managed Components
        TRadioGroup *rgRezult;
        TRzDialogButtons *RzDialogButtons1;
        TCheckBox *cbBiletZero;
  TUnLangSelector *LS;
	TCheckBox *cbRePrint;
private:	// User declarations
public:		// User declarations
        __fastcall TfRetiparBil(TComponent* Owner);
};
//---------------------------------------------------------------------------
int __fastcall retiparBileta();
extern PACKAGE TfRetiparBil *fRetiparBil;
//---------------------------------------------------------------------------
#endif
