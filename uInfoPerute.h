//---------------------------------------------------------------------------

#ifndef uInfoPeruteH
#define uInfoPeruteH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "DBGridMy1.h"
#include "SagiQueryLIB.h"
#include <Db.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include "StaticDBGrid.h"
#include "DBAccess.hpp"
#include "MemDS.hpp"
#include "Ora.hpp"
#include "OraSmart.hpp"
#include "SagiODACSmartQueryLIB.h"
//---------------------------------------------------------------------------
class TfInfoPeRute : public TForm
{
__published:	// IDE-managed Components
        TDataSource *dsVRutes;
        TDataSource *dsVRutesD;
        TDBGridMy1 *DBGridMy11;
        TDBGridMy1 *DBGridMy12;
        TSplitter *Splitter1;
        TPanel *Panel1;
        TBitBtn *BitBtn1;
	TSagiODACSmartQuery *qsVRutes;
	TSagiODACSmartQuery *qsVRutesD;
private:	// User declarations
public:		// User declarations
        __fastcall TfInfoPeRute(TComponent* Owner);
        void __fastcall ShowInfroPeRUTE();
};
//---------------------------------------------------------------------------
extern PACKAGE TfInfoPeRute *fInfoPeRute;
//---------------------------------------------------------------------------
#endif
