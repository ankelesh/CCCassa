//---------------------------------------------------------------------------
#ifndef uSelectH
#define uSelectH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "DBGridMy1.h"
#include "SagiQueryLIB.h"
#include <Buttons.hpp>
#include <Db.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include "DBAccess.hpp"
#include "FieldTimer.h"
#include "LgSelect.h"
#include "MemDS.hpp"
#include "Ora.hpp"
#include "OraSmart.hpp"
#include "RzButton.hpp"
#include "RzCmboBx.hpp"
#include "RzEdit.hpp"
#include "SagiODACSmartQueryLIB.h"
#include "StaticDBGrid.h"
#include "UnDBCtrl.h"
#include "UnSDGrid.h"
#include "MemDS.hpp"
#include "Ora.hpp"
#include "OraSmart.hpp"
#include "SagiODACSmartQueryLIB.h"
#include "FieldTimer.h"
#include "StaticDBGrid.h"
#include "DBAccess.hpp"
#include "RzButton.hpp"
#include "RzCmboBx.hpp"
#include "UnDBCtrl.h"
#include "UnSDGrid.h"
#include "LgSelect.h"
#include "RzEdit.hpp"
#include <System.Actions.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Imaging.GIFImg.hpp>
#include <Vcl.Imaging.PNGImage.hpp>
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "OraPackage.hpp"
#include "cxClasses.hpp"
#include "dxBar.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxImage.hpp"
#include <Vcl.Samples.Spin.hpp>
#include "ieview.hpp"
#include "imageenview.hpp"
#include "imageenproc.hpp"
#include <Vcl.Graphics.hpp>
#include "imageenio.hpp"
//---------------------------------------------------------------------------
//#define maxLocs 1000

enum TPlaceClass { pePlace, peSector };

// Ñîñòîÿíèÿ ìåñò
enum TPlaceState { pstFree,            // Ñâîáîäíî
				   pstReserved,        // Âûêóïëåíî
				   pstSelected,        // Âûáðàíî
				   pstSelectedByOther, // Âûáðàíî äðóãèì ïîëüçîâàòåëåì
				   pstBookPaid,        // Áðîíü îïëà÷åíà
				   pstBookUnpaid,      // Áðîíü íåîïëà÷åíà
				   pstSubscribed       // Àáîíåìåíò
				 };

class TImgInstance
{
public:
   TMemoryStream* ImgStream;
   TDateTime UpdateTime;
   String Name;
};

// ---------------------------------------------------------------------------
typedef struct
{
  int Left, Top, Width;
  TFont* Font;
} TCenterRect;

typedef struct
{
  int Price, X, Y;
} TPriceTextPoint;

class TSpotParams
{
public:
  ~TSpotParams();

  int VisibleRadius, ClickableRadius;
  TCenterRect *HCenter, *DCenter;
  bool OldLabelPrinting;
  bool PrintPlaceNr;
};
// ---------------------------------------------------------------------------
class TPlace
{
public:
  int Id;
  int AbsNr;
  bool CheckingForFree; // Ïðîâåêà åñëè ìåñòî àâòîìàòè÷åñêè íå îñâîáîäèëîñü
  String Nr;
  String Row;
  int X, Y, Price;
  int State, TypeLoc;
  String Casalenta;
  String Cashier, Username;
  String ActionState;
	String Color;
	int PictureId;
};
// ---------------------------------------------------------------------------
// Locked place action states
const String lpstPrint = "1";    // Ïå÷àòàåòñÿ
const String lpstPaid = "2";     // Âûêóïëåíî
// ---------------------------------------------------------------------------
class TLockedPlace
{
public:
  int AbsNr;
  String Cashier, Username;
  String ActionState;
};
// ---------------------------------------------------------------------------
class TRow
{
	TList* FPlaces;
public:
  int Nr;
  String Text;

  __fastcall TRow(int ANr, String AText);
  __fastcall ~TRow();

  TPlace* __fastcall GetPlace(int AIndex);
  void __fastcall SetPlace(int AIndex, TPlace* APlace);

  int __fastcall GetCount();

  void __fastcall Clear();
  void __fastcall Add(TPlace* APlace);
  void __fastcall Delete(int AIndex);

  __property TPlace* Places[int Index] = { read = GetPlace, write = SetPlace };
  __property int Count = { read = GetCount };
};

// ---------------------------------------------------------------------------
class TRowList
{

protected:
  TList* FRows;

public:
  __fastcall TRowList();
  __fastcall ~TRowList();

  TRow* __fastcall GetRow(int AIndex);
  void __fastcall SetRow(int AIndex, TRow* ARow);

  int __fastcall GetCount();

  void __fastcall Clear();
  void __fastcall Add(TRow* ARow);
  void __fastcall Delete(int AIndex);

  __property TRow* Items[int Index] = { read = GetRow, write = SetRow };
  __property TList* RowList = { read = FRows };
  __property int Count = { read = GetCount };
};
// ---------------------------------------------------------------------------
class TSector : public TRowList
{
public:
  int Nr, X, Y;
  String ImageName;
  String Text;
  TSpotParams* SpotParams;
	TStringList* PolyCoords;
	bool IsPolygon;
  bool IsStandSector;

  __fastcall TSector(int SecNr);
  __fastcall ~TSector();
};

struct PolyStruct {
	TPoint* points;
	int count;
};
// ---------------------------------------------------------------------------
class TArenaPlaces
{
  friend class TLockedPlacesThread;

  TSagiOraSession* sSession;
  // int ImageOriginalWidth, ImageOriginalHeight;

  TList* FormsList;
  TList* PriceList;
  TRowList* RowList;

	int SecCount;

  // Schema Keys
  int sMarcaCodAutobus;
  String sMarcaTip, sCodu;
  TDateTime Date;
  int nSector;
  bool bResizing;

	TPoint *points;
	PolyStruct* ps;
	TStringList* slSectors;
	PolyStruct* GetPolygon(String sPolygonCoords);
  void GetMarcaParams(int cod_autobus, String tip);
  void ClearSpotParams();
  void InitSectorList(int cod_autobus, String tip);
  TSpotParams* GetGeneralSpotParams(TSmartQuery* q);
	TStringList* GetGeneralPolyCoords(TSmartQuery* q);
  void GetPlaceParams(int cod_autobus, String tip, String codu, TDateTime data);
  void RefreshPrices();

  String GetFitLine(TCanvas *Canvas, String str, int rect_width);
  void PrintTextToArena(TCanvas* Canvas, TRect* rect, TPoint& cur, String str, bool fscenter);
  void PrintTextToCenterRect(TCanvas *Canvas, TCenterRect* Center, String Text, bool fscenter);

  void __fastcall SecondFormOnKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);

  TColor InvColor(TColor AColor);

  TCenterRect* GetCenter(TSmartQuery* q, String prefix);

	void __fastcall FormResize(TObject* Sender);

public:
  TPngImage* bmpMainMenuSchema;
  TPngImage* bmpMainSchema;

  TSpotParams* SpotParams;
  TLockedPlacesThread* LockedPlacesThread;
  TList* LockedPlaces;

	String HeaderText;
	String HeaderTextAdd;
  String DetailText;

  double ZoomLevel;
  TPoint MouseDownLeftPos;

  bool HasSectors;
  TSector* ActiveSector;
  bool Suspended;

  int TotalPlaces;

  TList* SecList;
  int AbsPlacesCount;
  TPlace** AbsPlaces; // Äîñòóï ê ìåñòàì ïî àáñîëþòíîìó íîìåðó

	TArenaPlaces(TSagiOraSession*, TRowList*);
  ~TArenaPlaces();

  TPlace* FindPlace(TImage*, int, int);
	TSector* FindSector(TImage*, int, int);
	void ImgResize(TImage* img, int FormWidth, int FormHeight, bool bZoom);
  void ChageImgVisible(bool bState, bool bHideForms = false);
	void RedrawPlaces(TImage* Image, int nFormLeft);
	void MoveCursor(int x, int y);
  void HideCursor();


  void SwitchSchema(int cod_autobus, String tip, String codu,
	int nSectorNr, TDateTime data, TPngImage* bmpArena_, bool bSectorMode);
  void GoToSector(TSector* Sector, TRowList*& CurRowList);
  TSector* GetSectorByNr(int nr);
  void GoToMainSchema(TRowList*& CurRowList);
  void Suspend();
  TSpotParams* GetActiveSpotParams();

  void __fastcall ShowSectorMenu(TSector* Sector);
	void __fastcall HideSectorMenu();
	void __fastcall AddSelResize(TObject *Sender);
};

// ---------------------------------------------------------------------------
const int LockedPlacesTimeout = 1500;

class TLockedPlacesThread : public TThread
{
private:
	TOraSession* FOraSession;
	TSmartQuery* FRefresher;

	TArenaPlaces* FArenaPlaces;

protected:
	void __fastcall Execute();

	void __fastcall UpdateVisualComponents();
	void __fastcall SyncLockList();

public:
	__fastcall TLockedPlacesThread(bool CreateSuspended, TArenaPlaces* ArenaPlaces, TOraSession* OraSession);
	__fastcall ~TLockedPlacesThread();

	void __fastcall UpdateEventId();
	void __fastcall UpdatePlaceRange(TSector* Sector);
	void __fastcall UpdateLockList();
	void __fastcall RefreshData();
};

// ---------------------------------------------------------------------------
class TfSelRuta : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TBitBtn *btOk;
	TBitBtn *btCancel;
	TDataSource *dsT0RUTA;
	TDataSource *dsDirect;
	TCheckBox *cbxFaraDirect;
	TDataSource *dsFreeLoc;
	TDataSource *dsDirectV;
	TActionList *ActionList1;
	TAction *Action1;
	TPageControl *pgc;
	TAction *actVinz;
	TAction *actAlteD;
	TAction *actPretNeed;
	TSagiODACSmartQuery *qsDirect;
	TSmartQuery *qqIsVinzEn;
	TSagiODACSmartQuery *qsFreeLoc;
	TFloatField *qsDirectID;
	TStringField *qsDirectDENUMIREA;
	TStringField *qsT0RUTACODU;
	TDateTimeField *qsT0RUTADATA;
	TStringField *qsT0RUTADENUMIREA;
	TStringField *qsT0RUTATIME_OUT;
	TStringField *qsT0RUTATIME_IN;
	TStringField *qsT0RUTAAUTABUS;
	TStringField *qsT0RUTATIP;
	TStringField *qsT0RUTARUTADEBAZA;
	TStringField *qsT0RUTATRANSIT;
	TFloatField *qsT0RUTAMAXAUTOLOC;
	TIntegerField *qsT0RUTALOCURINEED;
	TFloatField *qsT0RUTAPRETC;
	TFloatField *qsT0RUTAPRETN;
	TFieldTimer *fDirect_ID;
	TFieldTimer *fRuta_COD;
	TRzButton *btnStopRuta;
	TAction *actRutaplecat;
	TStringField *qsT0RUTANRSTATAUTO;
	TDataSource *dsBroni;
	TSagiODACSmartQuery *qsBroni;
	TUnLangSelector *LS;
	TRzEdit *rzLocsInpManual;
	TTabSheet *tbsComplex;
	TSagiODACSmartQuery *qsT0RUTA;
	TCheckBox *cbxBroni;
	TLabel *lbBilCnt;
	TFloatField *qsT0RUTAcodoras;
	TComboBox *LangCb;
	TStringField *qsT0RUTAday_name;
	TFloatField *qsT0RUTAis_day_off;
	TPanel *GridPanel;
	TUnDBGrid *dbgrComplex;
	TSplitter *Splitter4;
	TcxButton *btPlusBlt;
	TcxButton *btMinusBlt;
	TScrollBox *pnlComplex;
	TLabel *lbArena;
	TButton *btZoomIn;
	TButton *btZoomOut;
	TPanel *pnlBroni;
	TUnDBGrid *dbgrBroni;
	TIntegerField *qsT0RUTAAUTOBUS;
	TSagiODACSmartQuery *qsMarcaSectors;
	TDataSource *dsMarcaSectors;
	TButton *btnSchemaBack;
	TIntegerField *qsT0RUTALOC_TOTAL;
	TImage *imgArena;
	TEdit *meCntBlt;
	TLabel *lbHeader;
	TLabel *lbDetail;
	TImage *imgMainSchema;
	TImage *imgSelection;
	TBalloonHint *BalloonHint;
	TFloatField *qsT0RUTAPLACES_SOLD;
	TOraSQL *sqlPlaceUnlock;
	TOraSQL *sqlPlaceLock;
	TOraSQL *sqlPlaceUnlockAll;
	TOraSQL *sqlPlacePayAll;
	TSagiODACSmartQuery *qsBroniSearch;
	TSplitter *spBroni;
	TPanel *pnlActions;
	TBitBtn *btnFindBook;
	TBitBtn *btnBroniLaPlata;
	TBitBtn *btnBroniLaRestit;
	TBitBtn *btnBookShowAll;
	TComboBox *cbSectors;
	TLabel *Label1;
	TPanel *Panel2;
	TSpinEdit *SpinEdit1;
	TBitBtn *btnReturnOnline;
	TImageEnView *ImageEnView1;
	TImage *imgposter;
	TImage *imgPrices;
	void __fastcall qsFreeLocAfterOpen(TDataSet *DataSet);
	void __fastcall qsT0RUTABeforeOpen(TDataSet *DataSet);
	void __fastcall qsDirectBeforeOpen(TDataSet *DataSet);
	void __fastcall btOkClick(TObject *Sender);

	 void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall fDirect_IDFieldsChange(TObject *Sender);
	void __fastcall fDirect_IDFieldsBeginToChange(TObject *Sender);
	void __fastcall fRuta_CODFieldsChange(TObject *Sender);
	void __fastcall fRuta_CODFieldsBeginToChange(TObject *Sender);
	void __fastcall qsT0RUTABeforeClose(TDataSet *DataSet);
	void __fastcall pgcChanging(TObject *Sender, bool &AllowChange);
	void __fastcall actRutaplecatExecute(TObject *Sender);
	void __fastcall qsT0RUTAAfterOpen(TDataSet *DataSet);
	void __fastcall btnBroniLaPlataClick(TObject *Sender);
	void __fastcall btnBroniLaRestitClick(TObject *Sender);
	void __fastcall qsBroniAfterScroll(TDataSet *DataSet);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cbxBroniClick(TObject *Sender);
	void __fastcall meCntBltKeyDown(TObject *Sender, WORD &Key,
		TShiftState Shift);
	void __fastcall meCntBltChange(TObject *Sender);
	void __fastcall pnlComplexResize(TObject *Sender);
	void __fastcall dbgrComplexDrawColumnCell(TObject *Sender,
		const TRect &Rect, int DataCol, TColumn *Column,
		TGridDrawState State);
	void __fastcall LangCbChange(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall btPlusBltClick(TObject *Sender);
	void __fastcall btMinusBltClick(TObject *Sender);
	void __fastcall btZoomInClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall pnlComplexMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall imgArenaMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall imgArenaMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall imgMainSchemaMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall imgSelectionMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall qsT0RUTABeforeScroll(TDataSet *DataSet);
	void __fastcall imgArenaMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Action1Execute(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall lbHeaderMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall lbHeaderMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall lbHeaderMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall FormHide(TObject *Sender);
	void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall imgMainSchemaMouseEnter(TObject *Sender);
	void __fastcall imgArenaMouseEnter(TObject *Sender);
	void __fastcall lbHeaderMouseEnter(TObject *Sender);
	void __fastcall lbDetailMouseEnter(TObject *Sender);
	void __fastcall pnlComplexMouseEnter(TObject *Sender);
	void __fastcall btnSchemaBackClick(TObject *Sender);
	void __fastcall btnFindBookClick(TObject *Sender);
	void __fastcall btnBookShowAllClick(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall cbSectorsChange(TObject *Sender);
	void __fastcall SpinEdit1Change(TObject *Sender);
	void __fastcall btZoomOutClick(TObject *Sender);
	void __fastcall btnReturnOnlineClick(TObject *Sender);



private:	// User declarations
	TList *ImgList;
	TPngImage* bmpArena;
	TBitmap* bmpDetail;
	TPngImage* bmpMainSchema;
	TImage* imgRectangle;

	TArenaPlaces* ArenaPlaces;
	String ImageTemplateName;
	TSector* SectorZero;

	bool IsMainMenu;
	bool IsSectorSchema;
	bool SelectionActive;

	//bool GridHidden;
	//int GridWidth;

	void ChangeArenaState(bool bVisible);
	void ZoomArena(double nZoomLevel);
	void __fastcall GetImageFromSources(String ImageTemplateName, TPngImage* Bmp);
	void __fastcall OpenBroni();
	void __fastcall SuspendArena();
	void __fastcall UpdateMainSelection(TSector* Sector);
	void  _setSelectBroniQuery();
	int __fastcall LockPlace(String EventId, TDateTime Date, TPlace* Place, String& ResultMsg);
	void __fastcall UnlockPlace(String EventId, TDateTime Date, TPlace* Place);
public:		// User declarations
	int skipSyncThread ;
	int nLocationTotalPlaces; // Êîëè÷åñòâî ìåñò â âûáðàííîé ëîêàöèè (ñåêòîðå)
	int nLocationFreePlaces; // Ñâîáîäíûå ìåñòà â âûáðàííîé ëîêàöèè (ñåêòîðå)
	bool UseLockedPlacesThread;

	String lastKey;
	TDateTime DateVinz;
	long maxNMB;
	bool fDirectID_intFlag1,fRutaCOD_intFlag1;

	TBitBtn *broniButton;// êîììàíäà íàä âûáðàííàÿ áðîíü
	long broniCasaLenta;// âûáðàííàÿ áðîíü
	int broniInternTip;// 2-c ïðåäîïëàòîé

	TRowList* RowList;
	String strDest;
	int countSel;
	bool isUserSelect;
	bool isCanSalectThisItemByMouse;

	int isRutaBusy;

	__fastcall TfSelRuta(TComponent* Owner);
	void __fastcall GoToMainSchema();
	void __fastcall SetActiveSector(TSector* Sector);

	bool __fastcall RedrawArena();
	void __fastcall ResyncQuery(TSmartQuery* q);
	void __fastcall refreshOnlinePlaces();
	void __fastcall freeSel(bool OnlineOnly = false);
	void __fastcall setSel(TPlace* SelPlace, bool Redraw);
	void __fastcall prepareForOpen(void);
	void __fastcall ForOpenCloseRuta(bool isOp,bool isFastRefresh=false);
	void __fastcall SetCapt();
	bool __fastcall CheckBroni();
	void __fastcall DisableSelectLocBilet();
	void __fastcall SetMainMenuVisible(bool bVisible);
	bool __fastcall WasPlaceBooked(String Casalenta);
	void __fastcall SetFreeLocSectorParams(TSmartQuery* Query);
	void __fastcall UnlockLockedPlaces();
	void __fastcall PayLockedPlaces();
	void __fastcall SetCbSector(TSector *ASector);
	void __fastcall AddSelResize(TObject *Sender);
};
//---------------------------------------------------------------------------
int __fastcall selectRutaDir(TDate&dd,String strDest="", bool isBroniNeed=false);
extern PACKAGE TfSelRuta *fSelRuta;
//---------------------------------------------------------------------------
#endif
