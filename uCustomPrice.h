//---------------------------------------------------------------------------

#ifndef uCustomPriceH
#define uCustomPriceH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "LgSelect.h"
//---------------------------------------------------------------------------
class TfCustomPrice : public TForm
{
__published:	// IDE-managed Components
  TButton *Button1;
  TButton *Button2;
  TLabel *Label1;
  TLabel *Label2;
  TEdit *edPrice;
  TMemo *mComment;
  TUnLangSelector *LS;
  void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TfCustomPrice(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfCustomPrice *fCustomPrice;
//---------------------------------------------------------------------------
#endif
