//---------------------------------------------------------------------------

#ifndef uCheckBroniH
#define uCheckBroniH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "DBAccess.hpp"
#include "MemDS.hpp"
#include "Ora.hpp"
#include "OraSmart.hpp"
#include <Db.hpp>
#include "DBGridMy1.h"
#include "StaticDBGrid.h"
#include "UnDBCtrl.h"
#include "UnSDGrid.h"
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfCheckBroni : public TForm
{
__published:	// IDE-managed Components
  TUnDBGrid *grCheckBroni;
  TPanel *Panel1;
  TPanel *Panel2;
  TButton *btnAnull;
  TButton *Button1;
  void __fastcall btnAnullClick(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TfCheckBroni(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfCheckBroni *fCheckBroni;
//---------------------------------------------------------------------------
#endif
