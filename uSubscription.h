//---------------------------------------------------------------------------

#ifndef uSubscriptionH
#define uSubscriptionH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "DBGridMy1.h"
#include "StaticDBGrid.h"
#include "UnDBCtrl.h"
#include "UnSDGrid.h"
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "DBAccess.hpp"
#include "MemDS.hpp"
#include "Ora.hpp"
#include "OraSmart.hpp"
#include "SagiODACSmartQueryLIB.h"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxDBEdit.hpp"
#include "cxImage.hpp"
//---------------------------------------------------------------------------
class TfSubscription : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TUnDBGrid *grRoutes;
	TPanel *Panel1;
	TEdit *edBarcode;
	TButton *btnFind;
	TGroupBox *GroupBox2;
	TUnDBGrid *grSubscriptions;
	TSagiODACSmartQuery *qsContracts;
	TSagiODACSmartQuery *qsRoutes;
	TDataSource *dsContracts;
	TDataSource *dsRoutes;
	TSplitter *Splitter1;
	TLabel *Label1;
	TcxLabel *lbBarcode;
	TPanel *pnlActions;
	TButton *btnCheckIn;
	TOraStoredProc *spCheckIn;
	TcxDBImage *imgClient;
	TSplitter *Splitter2;
	TSplitter *Splitter3;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btnFindClick(TObject *Sender);
	void __fastcall qsContractsAfterScroll(TDataSet *DataSet);
	void __fastcall btnCheckInClick(TObject *Sender);
	void __fastcall edBarcodeKeyPress(TObject *Sender, System::WideChar &Key);

private:	// User declarations
	String Barcode;
public:		// User declarations
	__fastcall TfSubscription(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfSubscription *fSubscription;
//---------------------------------------------------------------------------
#endif
