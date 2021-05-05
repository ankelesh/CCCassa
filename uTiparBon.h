//---------------------------------------------------------------------------

#ifndef uTiparBonH
#define uTiparBonH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "LgSelect.h"
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "uDMcassa.h"
#include "uPrintSetup.h"
//---------------------------------------------------------------------------
class TTiparBonForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *pnlUp;
	TRadioGroup *rgroup;
	TUnLangSelector *LS;
	TRichEdit *RichEdit;
	TBitBtn *BitBtn1;
	TBitBtn *BtnPrint;
	TBitBtn *BtnOk;
	TBitBtn *Inchide;
	void __fastcall BtnPrintClick(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall InchideClick(TObject *Sender);
	void __fastcall BtnOkClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	bool printTry;
	__fastcall TTiparBonForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
int __fastcall TiparBon();
extern PACKAGE TTiparBonForm *TiparBonForm;
//---------------------------------------------------------------------------
#endif
