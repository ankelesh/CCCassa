//---------------------------------------------------------------------------

#ifndef uAddSelectH
#define uAddSelectH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include "dxGDIPlusClasses.hpp"
#include "frxClass.hpp"
#include <Vcl.Imaging.GIFImg.hpp>

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
class TfAddSel : public TForm
{
__published:	// IDE-managed Components
	TImage *ImgSchema;
	TLabel *LbState;
	TImage *imgMainSchema;
	TImage *ImgCursor;
	TLabel *lbDetail;
	TLabel *lbHeader;
	TImage *imgMenu;
	TImage *imgSelection;
	void __fastcall FormActivate(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TfAddSel(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfAddSel *fAddSel;
//---------------------------------------------------------------------------
#endif
