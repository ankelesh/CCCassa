#include <vcl.h>
#pragma hdrstop
//
#include <ctime>
#include <iostream>
#include <fstream>
#include <map>
//
#include "uSelect.h"
#include "uDMcassa.h"
#include "uPrintSetup.h"
#include "uVinz.h"
#include "uMain.h"
#include "uAddSelect.h"
#include "LangDM.h"
#include <Vcl.Imaging.jpeg.hpp>
#include "uAdditionalInfoLinker.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBGridMy1"
#pragma link "SagiQueryLIB"

#pragma link "MemDS"
#pragma link "Ora"
#pragma link "OraSmart"
#pragma link "SagiODACSmartQueryLIB"
#pragma link "FieldTimer"
#pragma link "StaticDBGrid"
#pragma link "DBAccess"
#pragma link "RzButton"
#pragma link "RzCmboBx"
#pragma link "UnDBCtrl"
#pragma link "UnSDGrid"
#pragma link "LgSelect"
#pragma link "RzEdit"
#pragma link "DBAccess"
#pragma link "FieldTimer"
#pragma link "LgSelect"
#pragma link "MemDS"
#pragma link "Ora"
#pragma link "OraSmart"
#pragma link "RzButton"
#pragma link "RzCmboBx"
#pragma link "RzEdit"
#pragma link "SagiODACSmartQueryLIB"
#pragma link "StaticDBGrid"
#pragma link "UnDBCtrl"
#pragma link "UnSDGrid"
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "OraPackage"
#pragma link "ieview"
#pragma link "imageenview"
#pragma link "imageenproc"
#pragma link "imageenio"
#pragma resource "*.dfm"

TfSelRuta *fSelRuta;

TCriticalSection* csUpdate;
TCriticalSection* csReadingLockedPlaces;

// ---------------------------------------------------------------------------
TSpotParams::~TSpotParams()
{
	if (HCenter)
		delete HCenter;
	if (DCenter)
		delete DCenter;
}
// ---------------------------------------------------------------------------
__fastcall TRow::TRow(int ANr, String AText)
{
	FPlaces = new TList();
	Nr = ANr;
	Text = AText;
}
__fastcall TRow::~TRow()
{
	for (int i = 0; i < FPlaces->Count; i++)
		delete (TPlace*)FPlaces->Items[i];

	delete FPlaces;
}
TPlace* __fastcall TRow::GetPlace(int AIndex)
{
	return (TPlace*)FPlaces->Items[AIndex];
}
void __fastcall TRow::SetPlace(int AIndex, TPlace* APlace)
{
	FPlaces->Items[AIndex] = APlace;
}

void __fastcall TRow::Clear()
{
	for (int i = 0; i < FPlaces->Count; i++)
		delete (TPlace*)FPlaces->Items[i];

	FPlaces->Clear();
}
void __fastcall TRow::Add(TPlace* APlace)
{
	FPlaces->Add(APlace);
}
void __fastcall TRow::Delete(int AIndex)
{
	delete (TPlace*)FPlaces->Items[AIndex];
	FPlaces->Delete(AIndex);
}
int __fastcall TRow::GetCount()
{
	return FPlaces->Count;
}
// ---------------------------------------------------------------------------
__fastcall TRowList::TRowList()
{
	FRows = new TList();
}
__fastcall TRowList::~TRowList()
{
	for (int i = 0; i < FRows->Count; i++)
		delete (TRow*)FRows->Items[i];

	delete FRows;
}
TRow* __fastcall TRowList::GetRow(int AIndex)
{
	return (TRow*)FRows->Items[AIndex];
}
void __fastcall TRowList::SetRow(int AIndex, TRow* ARow)
{
	FRows->Items[AIndex] = ARow;
}

void __fastcall TRowList::Clear()
{
	if (FRows)
	{
		for (int i = 0; i < FRows->Count; i++)
			delete (TRow*)FRows->Items[i];

		FRows->Clear();
    }
}
void __fastcall TRowList::Add(TRow* ARow)
{
	FRows->Add(ARow);
}
void __fastcall TRowList::Delete(int AIndex)
{
	delete (TPlace*)FRows->Items[AIndex];
	FRows->Delete(AIndex);
}
int __fastcall TRowList::GetCount()
{
	return FRows->Count;
}
// ---------------------------------------------------------------------------
__fastcall TSector::TSector(int SecNr)
	: TRowList()
{
	Nr = SecNr;
}
__fastcall TSector::~TSector()
{

}
// ---------------------------------------------------------------------------
//Image ratio Width
double DeltaX(TImage *Image)
{
	if (!Image || !Image->Picture->Graphic || Image->Width == 0)
				return 1;
		return Image->Width / (double)Image->Picture->Graphic->Width;
}
// ---------------------------------------------------------------------------
//Image ratio Height
double DeltaY(TImage *Image)
{
	if (!Image || !Image->Picture->Graphic || Image->Height == 0)
        return 1;
		return Image->Height / (double)Image->Picture->Graphic->Height;
}
// ---------------------------------------------------------------------------
//Venue Query
void TArenaPlaces::GetMarcaParams(int cod_autobus, String tip)
{
	if (sMarcaCodAutobus == cod_autobus && sMarcaTip == tip)
		return;

	sMarcaCodAutobus = cod_autobus;
	sMarcaTip = tip;

	ClearSpotParams();

	TSmartQuery *q = new TSmartQuery(NULL);
	q->Session = sSession;
	q->SQL->Text = "select * from t0marca"
		" where autobus = :cod_autobus"
		" and tip = :tip";
	q->ParamByName("cod_autobus")->AsInteger = cod_autobus;
	q->ParamByName("tip")->AsString = tip;
	q->Open();
	if (!q->RecordCount)
		return;

	SpotParams = GetGeneralSpotParams(q);

	delete q;
}
// ---------------------------------------------------------------------------
TSpotParams* TArenaPlaces::GetGeneralSpotParams(TSmartQuery* q)
{
	TSpotParams* Params = new TSpotParams();

	Params->OldLabelPrinting = q->FieldByName("old_label_printing")->AsInteger;
	Params->PrintPlaceNr = q->FieldByName("print_place_nr")->AsInteger;
	Params->VisibleRadius = q->FieldByName("place_visible_radius")->AsInteger;
	Params->ClickableRadius = q->FieldByName("place_clickable_radius")->AsInteger;
	Params->HCenter = GetCenter(q, "h");
	Params->DCenter = GetCenter(q, "d");


	return Params;
}
// ---------------------------------------------------------------------------
TStringList* TArenaPlaces::GetGeneralPolyCoords(TSmartQuery* q)
{
	TStringList* PolyCoords = new TStringList();
	for (q->First(); !q->Eof; q->Next())
	{
		if( !q->FieldByName("POLY_COORDS")->AsString.IsEmpty())
			PolyCoords->Add(q->FieldByName("POLY_COORDS")->AsString);
	}
	return PolyCoords;
}
void TArenaPlaces::ClearSpotParams()
{
	if (SpotParams)
    {
		delete SpotParams;
		SpotParams = NULL;
	}
}
// ---------------------------------------------------------------------------
void TArenaPlaces::InitSectorList(int cod_autobus, String tip)
{
	if (SecList)
	{
		for (int i = 0; i < SecList->Count; i++)
			delete (TSector*)SecList->Items[i];
		delete SecList;
		SecList = NULL;
	}
	SecList = new TList();

	TSmartQuery *q = new TSmartQuery(NULL);
	q->Session = sSession;
	//q->SQL->Text = "select * from v0marca_sectors"
	q->SQL->Text = "select * from V0MARCA_SECTORS_RESTRICTED"
		" where autobus = :cod_autobus"
		"   and tip = :tip"
		"   order by nrord";
	q->ParamByName("cod_autobus")->AsInteger = cod_autobus;
	q->ParamByName("tip")->AsString = tip;
	q->Open();

	for (q->First(); !q->Eof; q->Next())
	{
		TSmartQuery *z = new TSmartQuery(NULL);
		z->Session = sSession;
		z->SQL->Text = "select * from T0MARCA_SECTORS_poly_coords"
			" where autobus = :cod_autobus"
			"   and id = :id";
		z->ParamByName("cod_autobus")->AsInteger = cod_autobus;
		z->ParamByName("id")->AsInteger = q->FieldByName("id")->AsInteger;
		z->Open();
		TSector* Sector = new TSector(q->FieldByName("nrord")->AsInteger);

		Sector->X = q->FieldByName("coord_x")->AsInteger;
		Sector->Y = q->FieldByName("coord_y")->AsInteger;
		Sector->ImageName = q->FieldByName("template_image_name")->AsString;
		Sector->Text = q->FieldByName("name_short")->AsString;
		Sector->SpotParams = GetGeneralSpotParams(q);
		Sector->PolyCoords = GetGeneralPolyCoords(z);
		Sector->IsPolygon = q->FieldByName("ispolygon")->AsInteger == 1;
		Sector->IsStandSector = q->FieldByName("can_select_places")->AsInteger == 0;

		SecList->Add(Sector);
    delete z;
	}

	delete q;
}
// ---------------------------------------------------------------------------
void TArenaPlaces::GetPlaceParams(int cod_autobus, String tip, String codu, TDateTime data)
{
	TSmartQuery *q = new TSmartQuery(NULL);
	q->Session = sSession;
	q->FetchAll = true;
	q->FetchRows = 2000;

	q->SQL->Text = "select max(abs_nr) + 1 a from t0marca_places"
		" where cod_autobus = :cod_autobus"
		"   and tip = :tip";
	q->ParamByName("cod_autobus")->AsInteger = cod_autobus;
	q->ParamByName("tip")->AsString = tip;
	q->Open();

	if (AbsPlaces)
    {
		for (int i = 0; i < AbsPlacesCount; i++)
			if (AbsPlaces[i])
			{
				delete AbsPlaces[i];
				AbsPlaces[i] = NULL;
        	}
		AbsPlaces = NULL;
	}

	int AbsPlacesCount = q->FieldByName("a")->AsInteger;
	if (!AbsPlaces)
	{
		AbsPlaces = new TPlace*[AbsPlacesCount];
		for (int i = 0; i < AbsPlacesCount; i++)
			AbsPlaces[i] = NULL;
	}

	q->SQL->Text = "select count(*) sector_count from V0MARCA_SECTORS_RESTRICTED"
	" where autobus = :autobus"
	" and tip = :tip";
	q->ParamByName("autobus")->AsInteger = cod_autobus;
	q->ParamByName("tip")->AsString = tip;
	q->Open();

	SecCount = q->FieldByName("sector_count")->AsInteger;



	q->SQL->Text =
"select sector_nr, row_nr, place_nr, id, abs_nr, x, y, row_text, place_text, price , delphicolor "
", ( select l.pay_type from t0bilet b, t1casalenta l "
"	where b.idcaslenta = l.id "
"		and b.nrord_nonactiv = 0 and b.ruta=p.codu and  b.loc=p.abs_nr ) as pay_type "
" from v2ruta_m_places p "
" where cod_autobus = :cod_autobus "
"		 and tip = :tip "
"		 and codu = :codu "
"		 and data = :data ";

	q->ParamByName("cod_autobus")->AsInteger = cod_autobus;
	q->ParamByName("tip")->AsString = tip;
	q->ParamByName("codu")->AsString = codu;
	q->ParamByName("data")->AsDateTime = data;
 //	q->ParamByName("sector_nr")->AsString = nSectorNr;
	q->Open();

	TotalPlaces = q->RecordCount;

	if (!TotalPlaces)
		return;

	int CurSec = 0;
	int CurRow = 0;
	TRowList* List = NULL;
	TRow* Row = NULL;
	TPlace *Place = NULL;

	if (SecCount)
		InitSectorList(cod_autobus, tip);
	else
		List = RowList;

	if (List)
		List->Clear();

	for (q->First(); !q->Eof; q->Next()) // Place Init
	{
		if (SecCount && CurSec != q->FieldByName("sector_nr")->AsString)// New Sector
		{
			CurSec = q->FieldByName("sector_nr")->AsInteger;
			List = (TSector*)SecList->Items[CurSec - 1];
			CurRow = 0;
		}

		if (CurRow != q->FieldByName("row_nr")->AsInteger)// New Row
		{
			CurRow = q->FieldByName("row_nr")->AsInteger;

			bool bFound = false;
			for (int i = 0; i < List->Count; i++)
			{
				if (List->Items[i]->Nr == CurRow)
				{
					Row = List->Items[i];
					bFound = true;
					break;
				}
			}
			if (!bFound)
			{
				Row = new TRow(CurRow, q->FieldByName("row_text")->AsString);
				List->Add(Row);
			}
		}

		Place = new TPlace();
		Place->Id = q->FieldByName("id")->AsInteger;
		Place->Row = q->FieldByName("row_text")->AsString;
		Place->Nr = q->FieldByName("place_text")->AsString;
		Place->X = q->FieldByName("x")->AsInteger;
		Place->Y = q->FieldByName("y")->AsInteger;
		Place->Price = q->FieldByName("price")->AsInteger;
		Place->AbsNr = q->FieldByName("abs_nr")->AsInteger;
        Place->Color = q->FieldByName("delphicolor")->AsString;
		Place->CheckingForFree = false;
		Place->PictureId = q->FieldByName("pay_type")->AsInteger;

		Row->Add(Place);


		AbsPlaces[Place->AbsNr] = Place;
	}
	delete q;
}
// ---------------------------------------------------------------------------
void TArenaPlaces::GoToSector(TSector* Sector, TRowList*& CurRowList)
{
	fSelRuta->UnlockLockedPlaces();
	LockedPlacesThread->UpdatePlaceRange(Sector);
	RowList = Sector;
	CurRowList = RowList;
	ActiveSector = Sector;
}
// ---------------------------------------------------------------------------
void TArenaPlaces::GoToMainSchema(TRowList*& CurRowList)
{
	ActiveSector = NULL;
	CurRowList = RowList;
}
// ---------------------------------------------------------------------------
void TArenaPlaces::SwitchSchema(int cod_autobus, String tip, String codu, int nSectorNr, TDateTime data,
	TPngImage* bmpArena, bool bSectorMode)
{
  fSelRuta->cbSectors->ItemIndex = -1;
	static bInside = false;
	if (bInside)
		return;
	bInside = true;
	try
	{
		Suspended = false;

		HasSectors = bSectorMode;
		ActiveSector = NULL;

		bool NoRefresh = true;
		NoRefresh &= sMarcaCodAutobus == cod_autobus;
		NoRefresh &= sMarcaTip == tip;
		NoRefresh &= nSector == nSectorNr;

		sCodu = codu;
		Date = data;

	   /*	if (NoRefresh)
		{    ShowMessage("FUck");
			RefreshPrices();
			return;
		}      */

		dmCassa->qq->SQL->Text = "begin gracontext.setval('codu', :codu); end;";
		dmCassa->qq->ParamByName("codu")->ParamType = ptInput;
		dmCassa->qq->ParamByName("codu")->AsString = codu;
		dmCassa->qq->Execute();
		GetPlaceParams(cod_autobus, tip, codu, data);
		GetMarcaParams(cod_autobus, tip);

		nSector = nSectorNr;
		sMarcaCodAutobus = cod_autobus;
		sMarcaTip = tip;

		bmpMainSchema = bmpArena;
		bmpMainMenuSchema = bmpMainSchema;


		if (SecList && !HasSectors)
			ActiveSector = (TSector*)SecList->Items[nSectorNr - 1];
		fSelRuta->cbSectors->Items->Clear();
		if (SecList)
		{
			for (int i = 0; i < SecList->Count; i++) {
				TSector* Sector = (TSector*)SecList->Items[i];
				fSelRuta->cbSectors->Items->AddObject(Sector->Text,(TObject*)Sector);
			}
		}
	}
	__finally
	{
		if (!LockedPlacesThread)
			LockedPlacesThread = new TLockedPlacesThread(false, this, dmCassa->db);
		LockedPlacesThread->UpdateEventId();
		if (LockedPlacesThread->Suspended)
			LockedPlacesThread->Start();
		bInside = false;
    }
}
// ---------------------------------------------------------------------------
void TArenaPlaces::RefreshPrices()
{
	TSmartQuery *q = new TSmartQuery(NULL);
	q->Session = sSession;
	q->FetchAll = true;
	q->FetchRows = 2000;

	q->SQL->Text = "select abs_nr, price from v1ruta_m_places"
		" where cod_autobus = :cod_autobus"
		"   and tip = :tip"
		"   and codu = :codu"
		"   and data = :data";
	//	"   and sector_nr = :sector_nr";
	q->ParamByName("cod_autobus")->AsInteger = sMarcaCodAutobus;
	q->ParamByName("tip")->AsString = sMarcaTip;
	q->ParamByName("codu")->AsString = sCodu;
	q->ParamByName("data")->AsDateTime = Date;
	q->Open();

	if (!q->RecordCount)
		return;

	for (q->First(); !q->Eof; q->Next()) // Èíèöèàëèçàöèÿ ìåñò
	{
		TPlace* Place = AbsPlaces[q->FieldByName("abs_nr")->AsInteger];
		if (Place)
			Place->Price = q->FieldByName("price")->AsInteger;
	}
	delete q;
}
// ---------------------------------------------------------------------------
void TArenaPlaces::Suspend()
{
	Suspended = true;
	ChageImgVisible(false, true);
}
// ---------------------------------------------------------------------------
TSpotParams* TArenaPlaces::GetActiveSpotParams()
{
	if (ActiveSector)
		return ActiveSector->SpotParams;
	else
		return SpotParams;
}
// ---------------------------------------------------------------------------
TArenaPlaces::TArenaPlaces(TSagiOraSession *sSession_, TRowList* RowList_)
	: sSession(sSession_), RowList(RowList_)
{
	FormsList = new TList(); // Ñïèñîê äîïîëíèòåëüíûõ ôîðì ñî ñõåìàìè
	PriceList = new TList(); // Ñïèñîê öåí íà ìåñòà
	LockedPlaces = new TList(); // Ñïèñîê çàáëîêèðîâàííûõ ìåñò (îíëàéí)
	SecList = NULL; // Ñïèñîê ñåêòîðîâ
	ActiveSector = NULL;
	ZoomLevel = (double)dmCassa->iSelZoomPercent/100;

	bResizing = false;
	nSector = -1;
	SpotParams = NULL;
	sMarcaTip = NULL;
	sCodu = NULL;
	AbsPlacesCount = 0;
	LockedPlacesThread = NULL;
	bmpMainMenuSchema = NULL;
	bmpMainSchema = NULL;

    Suspended = true;
}
// ---------------------------------------------------------------------------

TArenaPlaces::~TArenaPlaces()
{
	for (int i = 0; i < FormsList->Count; i++)
		delete(TForm *)FormsList->Items[i];
	FormsList->Clear();
	delete FormsList;
	FormsList = NULL;

	for (int i = 0; i < PriceList->Count; i++)
		delete (TPriceTextPoint*)PriceList->Items[i];
	PriceList->Clear();
	delete PriceList;
	PriceList = NULL;

	if (HasSectors)
	{
		for (int i = 0; i < SecList->Count; i++)
			delete (TSector*)SecList->Items[i];

		SecList->Clear();
		delete SecList;
		SecList = NULL;
	}
	ActiveSector = NULL;

	ClearSpotParams();
	delete RowList;
}
// ---------------------------------------------------------------------------
TCenterRect* TArenaPlaces::GetCenter(TSmartQuery* q, String prefix = "")
{
	TCenterRect* Center = new TCenterRect();
	Center->Left = q->FieldByName(prefix + "center_left")->AsInteger;
	Center->Top =  q->FieldByName(prefix + "center_top")->AsInteger;
	Center->Width = q->FieldByName(prefix + "center_width")->AsInteger;

	Center->Font = new TFont();
	Center->Font->Name = q->FieldByName(prefix + "center_font_name")->AsString;
	Center->Font->Size = q->FieldByName(prefix + "center_font_size")->AsInteger;
	Center->Font->Quality = TFontQuality::fqAntialiased;

	if (!Center->Left || !Center->Top || !Center->Width)
	{
		delete Center->Font;
		delete Center;
		Center = NULL;
	}
	return Center;
}

// ---------------------------------------------------------------------------
String TArenaPlaces::GetFitLine(TCanvas *Canvas, String str, int rect_width)
{
	int nSpace, nNewLine, nPos;

	int nStrLength = str.Length();

	nSpace = str.Pos(" ");
	nNewLine = str.Pos("\n");

	nPos = (nSpace < nNewLine) ? nSpace : (nSpace > nNewLine) ? nNewLine : 0;
	nPos = (nPos == 0 && (nSpace || nNewLine)) ? (nSpace ? nSpace : nNewLine) : nPos;

	if (!nPos)
		nPos = nStrLength;

	String substr = str.SubString(1, nPos);

	int nWordWidth = Canvas->TextWidth(substr);

	if (rect_width - nWordWidth < 0)
		return "";
  else if (nPos == nStrLength)
			return str;

	str.Delete(1, substr.Length());

	if (nPos == nNewLine)
		return substr;

	substr += GetFitLine(Canvas, str, rect_width - nWordWidth);

	return substr;
}

// ---------------------------------------------------------------------------
void TArenaPlaces::PrintTextToArena(TCanvas *Canvas, TRect *rect, TPoint &cur,
	String str, bool fscenter = false)
{
	if (str.IsEmpty())
		return;

	String substr = GetFitLine(Canvas, str, rect->Width());

	if (substr.IsEmpty())
		substr = str;

	int nTextHeight = Canvas->TextHeight(substr);

	int n = substr.Pos("\n");
	if (n == substr.Length())
	{
		substr.Delete(n, 1);
		str.Delete(n, 1);
	}

	int nLeft = rect->Left;
	if (fscenter)
		nLeft += (rect->Width() - Canvas->TextWidth(substr)) / 2;

	Canvas->TextOut(nLeft, cur.y, substr); // Âûâîä òåêñòà

	cur.y += nTextHeight;

	str.Delete(1, substr.Length());

	PrintTextToArena(Canvas, rect, cur, str, fscenter);
}
// ---------------------------------------------------------------------------

TPlace* TArenaPlaces::FindPlace(TImage *Image, int x, int y)
{
	if (!Image || !Image->Picture->Graphic)
		return NULL;

	x /= DeltaX(Image);
	y /= DeltaY(Image);

	for (int i = 0; i < RowList->Count; i++)
		for (int j = 0; j < RowList->Items[i]->Count; j++)
		{

			TPlace* Place = RowList->Items[i]->Places[j];

            int Radius;
			if (ActiveSector)
				Radius = ActiveSector->SpotParams->ClickableRadius;
			else
				Radius = SpotParams->ClickableRadius;

			if (abs(Place->X - x) <= Radius && abs(Place->Y - y) <= Radius)
				return Place;
		}

	return NULL;
}
// ---------------------------------------------------------------------------
int pnpoly(int nvert, PolyStruct* pa, float testx, float testy) {
	int i, j, c = 0;
	for (i = 0, j = nvert - 1; i < nvert; j = i++) {
		if (((pa->points[i].Y > testy) != (pa->points[j].Y > testy)) && (testx <
				(pa->points[j].X - pa->points[i].X) * (testy - pa->points[i].Y) / (pa->points[j].Y - pa->points[i].Y) +
				pa->points[i].X))
			c = !c;
	}
	return c;
}
String ParcePolygonCoords(String sCoords)
{
	String sResult;
	String sTmp = StringReplace(sCoords,",","\n", TReplaceFlags() << rfReplaceAll);
	sResult = StringReplace(sTmp,":","\n", TReplaceFlags() << rfReplaceAll);
	return sResult;
}
PolyStruct* TArenaPlaces::GetPolygon(String sPolygonCoords)
{
	TStringList* ss = new TStringList();

	ss->Text = ParcePolygonCoords(sPolygonCoords);
	points = new TPoint[ss->Count/2];
	for (int i = 0; i < ss->Count; i++) {
		if((i+1)%2==0)
			points[(i+1)/2-1].Y = StrToInt(ss->Strings[i]);
		else
			points[(i+2)/2-1].X = StrToInt(ss->Strings[i]);
	}
	ps = new PolyStruct;
	ps->points = points;
	ps->count = (ss->Count/2)-1;
  delete ss;
	return ps;
}
TSector* TArenaPlaces::FindSector(TImage *Image, int x, int y)
{
	x /= DeltaX(Image);
	y /= DeltaY(Image);

	if (SecList)
		for (int i = 0; i < SecList->Count; i++)
		{
			TSector* Sector = (TSector*)SecList->Items[i];
			if( !Sector->IsPolygon )
			{
			int Radius = SpotParams->ClickableRadius;

			if (abs(Sector->X - x) <= Radius && abs(Sector->Y - y) <= Radius)
				return Sector;
			}
			else
			{
				for (int i = 0; i < Sector->PolyCoords->Count; i++) {
					PolyStruct* ss = dynamic_cast<PolyStruct*>(GetPolygon(Sector->PolyCoords->Strings[i]));
					if(pnpoly(ss->count+1, ss , x, y)>0)
					{
						return Sector;
						break;
					}
				}
			}
		}

	return NULL;
}
// ---------------------------------------------------------------------------
TSector* TArenaPlaces::GetSectorByNr(int nr)
{
	if (SecList)
		for (int i = 0; i < SecList->Count; i++)
		{
			TSector* Sector = (TSector*)SecList->Items[i];
			if (Sector->Nr == nr)
				return Sector;
		}

	return NULL;
}
// ---------------------------------------------------------------------------
void TArenaPlaces::ImgResize(TImage *img, int FormWidth, int FormHeight, bool bZoom = true)
{
  if (!this || bResizing || !img->Picture->Graphic)
	return;

  bResizing = true;
	if (FormHeight <= img->Picture->Graphic->Height ||
	FormWidth <= img->Picture->Graphic->Width)
	{
		double coef = img->Picture->Graphic->Width / (double)
			img->Picture->Graphic->Height;
		if (FormWidth > FormHeight || FormWidth == FormHeight && coef < 1)
		{
			img->Height = FormHeight ;
			img->Width = FormHeight * coef;
		}
		else if (FormWidth < FormHeight || FormWidth == FormHeight && coef > 1)
		{
			img->Width = FormWidth;
			img->Height = FormWidth / coef;
		}
		else
		{
			img->Height = FormHeight;
			img->Width = FormWidth;
		}

		if (img->Height > FormHeight)
		{
		  img->Height = FormHeight;
			img->Width = FormHeight * coef;
		}
		else if (img->Width > FormWidth)
		{
		 	img->Width = FormWidth;
		 	img->Height = FormWidth / coef;
		}
	}
	else
	{
		img->Width = img->Picture->Graphic->Width;
		img->Height = img->Picture->Graphic->Height;
	}

  if (bZoom)
  {
		if( img->Name != "imgMainSchema")
		{
			img->Width *= ZoomLevel;
			img->Height *= ZoomLevel;
		}
  }

	img->Left = (FormWidth - img->Width) / 2;
	img->Top = (FormHeight - img->Height) / 2;

  if (img->Picture->Graphic->ClassType() == __classid(TPngImage))
  {
		TPngImage* Png = (TPngImage*)img->Picture->Graphic;
		Png->Canvas->StretchDraw(Png->Canvas->ClipRect, Png);
	}

	bResizing = false;
}
// ---------------------------------------------------------------------------
void __fastcall TArenaPlaces::FormResize(TObject *Sender)
{
	TfAddSel *f = dynamic_cast<TfAddSel*>(Sender);

	ImgResize(f->ImgSchema, f->ClientWidth, f->ClientHeight, false);

	f->LbState->Left = (f->ClientWidth - f->LbState->Width) / 2;
	f->LbState->Top = (f->ClientHeight - f->LbState->Height) / 2;

}
// ---------------------------------------------------------------------------
void __fastcall TArenaPlaces::AddSelResize(TObject *Sender)
{
	TfAddSel *f = dynamic_cast<TfAddSel*>(Sender);

	double dOldZoomLvl = ZoomLevel;

	ZoomLevel = (double)dmCassa->iAddSelZoomPercent/100;
	ImgResize(f->ImgSchema, f->ClientWidth , f->ClientHeight , true);
	ZoomLevel = dOldZoomLvl;

}
// ---------------------------------------------------------------------------
void TArenaPlaces::ChageImgVisible(bool bState, bool bHideForms)
{
	if (!this || !FormsList || !FormsList->Count)
		return;
	TColor Color = bState ? clWhite : clBtnFace;

	for (int i = 0; i < FormsList->Count; i++)
	{
		TfAddSel *f = (TfAddSel*)FormsList->Items[i];

		if (bState)
		{
			if (!f->Visible)
			{

				Vcl::Forms::TMonitor* SecMonitor;
				if (fSelRuta->Monitor->Primary)
				{
					for (int y = 0; y < Screen->MonitorCount; y++)
						if (!Screen->Monitors[y]->Primary)
							SecMonitor = Screen->Monitors[y];
				}
				else
				{
					SecMonitor = Screen->PrimaryMonitor;
				}

				f->WindowState = wsMinimized;
				f->Left = SecMonitor->Left + 10;
				f->Top = SecMonitor->Top + 10;
				f->Show();

				f->WindowState = wsMaximized;
			}
		}
		else if (bHideForms)
			f->Hide();

		if (f->Visible)
		{
			f->Color = Color;

			f->ImgSchema->Visible = bState;
			f->lbHeader->Visible = bState;
			f->lbDetail->Visible = bState;

			if (ActiveSector && bState)
			{
				f->imgMenu->Visible = bState;
				f->imgSelection->Visible = bState;
			}
			f->LbState->Visible = !bState;

			if (f->LbState->Visible)
			{
				f->LbState->Caption = fSelRuta->LS->Text["please_wait"];
				f->LbState->Left = (f->ClientWidth - f->LbState->Width) / 2;
				f->LbState->Top = (f->ClientHeight - f->LbState->Height) / 2;
			}

			f->lbHeader->Caption = HeaderText;
			f->lbDetail->Caption = DetailText;

		}
	}
}

// ---------------------------------------------------------------------------
TColor TArenaPlaces::InvColor(TColor AColor)
{
	int R, G, B;
	int C = ColorToRGB(AColor);

	R = GetRValue(C);
	G = GetGValue(C);
	B = GetBValue(C);

	double a = 1 - (0.3 * R + 0.59 * G + 0.11 * B) / 255;

	if (a < 0.5)
		return clBlack;
	else
		return clWhite;
}
// ---------------------------------------------------------------------------
void TArenaPlaces::PrintTextToCenterRect(TCanvas *Canvas, TCenterRect* Center, String Text, bool fscenter = false)
{
	if (!Center)
		return;

	Canvas->Font = Center->Font;
	Canvas->Font->Color = InvColor(Canvas->Pixels[Center->Left + Center->Width / 2][Center->Top]);
  	SetBkMode(Canvas->Handle, TRANSPARENT);

	TPoint lt(Center->Left, Center->Top);
	TPoint rb(Center->Left + Center->Width, Center->Top + Center->Width);
	TRect *rect = new TRect(lt, rb);

	PrintTextToArena(Canvas, rect, lt, Text, fscenter);

  delete rect;
	// Òåñòîâàÿ ëèíèÿ îáëàñòè ïå÷àòè
	// Canvas->MoveTo(Center->Left, Center->Top);
	// Canvas->LineTo(Center->Left + Center->Width, Center->Top);
}

// ---------------------------------------------------------------------------
void TArenaPlaces::MoveCursor(int x, int y)
{
	for (int i = 0; i < FormsList->Count; i++)
	{
		TfAddSel *f = (TfAddSel*)FormsList->Items[i];

		double coef  = (double)f->ImgSchema->Picture->Height / (double)f->ImgSchema->Picture->Width;

		if(
		 (double)f->ImgSchema->Picture->Height  / (double)f->ImgSchema->Height
		 >
		 (double)f->ImgSchema->Picture->Width  / (double)f->ImgSchema->Width )
		{
			f->ImgCursor->Left = ((double)f->ImgSchema->Width - ( (double)f->ImgSchema->Height / coef )) / 2

			+ x * (((double)f->ImgSchema->Height / coef ) / (double)f->ImgSchema->Picture->Width);

			f->ImgCursor->Top = f->ImgSchema->Top + y * DeltaY(f->ImgSchema);
		}
		else
		{
		   f->ImgCursor->Left = f->ImgSchema->Left + x * DeltaX(f->ImgSchema);

		   f->ImgCursor->Top = f->ImgSchema->Top + ((double)f->ImgSchema->Height - ( (double)f->ImgSchema->Width * coef )) / 2

		   +
			 y * (( (double)f->ImgSchema->Width * coef ) / (double)f->ImgSchema->Picture->Height) ;
		}

		f->ImgCursor->Visible = true;
  }
}

// ---------------------------------------------------------------------------
void TArenaPlaces::HideCursor()
{
	for (int i = 0; i < FormsList->Count; i++)
	{
		TfAddSel *f = (TfAddSel*)FormsList->Items[i];

		f->ImgCursor->Visible = false;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TArenaPlaces::SecondFormOnKeyDown(TObject *Sender, WORD &Key,
	TShiftState Shift)
{
	if (Key == VK_ESCAPE)
	{
		if (fSelRuta->Visible)
			fSelRuta->Close();
	}
}
// ---------------------------------------------------------------------------
void TArenaPlaces::RedrawPlaces(TImage* Image, int nFormLeft)
{
	if (!bmpMainSchema || !Image)
		return;
	TPngImage* Bitmap = new TPngImage();
	TPngImage* BitmapAdd = new TPngImage();


	Bitmap->Canvas->Font->Color = clBlack ;

	try
	{
		Bitmap->Assign(bmpMainSchema);

//		Bitmap->Canvas->Brush->Color = clWhite;
//		Bitmap->Canvas->Pen->Color = clWhite;
//	  Bitmap->Canvas->Rectangle( 1,1, Bitmap->Width, Bitmap->Height);
		TSpotParams* Params = GetActiveSpotParams();

		if (!SecList || SecList && ActiveSector)
		{
			if (!SecList || ActiveSector && !ActiveSector->IsStandSector)
			{
				for (int i = 0; i < RowList->Count; i++)
					for (int j = 0; j < RowList->Items[i]->Count; j++)
					{
						TPlace* Place = RowList->Items[i]->Places[j];

						if (Place->Color != "non")
							{
							// -1 - Çàíÿòîå ìåñòî
							// 0 - Ñâîáîäíîå ìåñòî
							// 1 - Âûáðàííîå ìåñòî

							Bitmap->Canvas->Brush->Color = TColor(StrToInt64(Place->Color));
							Bitmap->Canvas->Pen->Color = clWhite ;
							int x = Place->X;
							int y = Place->Y;
							int r = Params->VisibleRadius;
							Bitmap->Canvas->Font->Name = "Gill Sans MT";
							Bitmap->Canvas->Font->Height = r * 2;

							// Ðèñóåì ìåñòî
							if (Bitmap->Canvas->Brush->Color != TColor(StrToInt64("$00FFFFFF")))
							{
								Bitmap->Canvas->Brush->Style = bsSolid;
							}
							else
							{
								Bitmap->Canvas->Brush->Style = bsClear;
							}

						   if(  Place->State == pstFree )
							{
								Bitmap->Canvas->Ellipse(x - r, y - r, x + r, y + r);
							}

							if(  Place->State == pstSelected )
							{
								Bitmap->Canvas->Brush->Color = clRed;
								Bitmap->Canvas->Ellipse(x - r, y - r, x + r, y + r);
							}

							if(  Place->State != pstFree )
							{
								if(  Place->State == pstSelected )
								{
									Bitmap->Canvas->Brush->Color = TColor(StrToInt64(Place->Color));
								}
								else
								{
									Bitmap->Canvas->Brush->Color = clGray;
								}

								Bitmap->Canvas->Pen->Color = Bitmap->Canvas->Brush->Color ;
								Bitmap->Canvas->Ellipse(x - r / 2, y - r / 2 , x + r / 2, y + r / 2);
								Bitmap->Canvas->Pen->Color = clWhite ;

								if(  Place->State == pstBookUnpaid || Place->State == pstSelectedByOther)
								{
									if (Place->PictureId < 0)
									{
										TGraphic * gr = TAdditionalInfoLinker::instanse()->getImage(-(Place->PictureId));
										Bitmap->Canvas->Draw(x - gr->Width / 2, y - gr->Height / 2 , gr );
									}
									else
									{
									if(dmCassa->isBroni && fSelRuta->WasPlaceBooked(Place->Casalenta))
									Bitmap->Canvas->Brush->Color = clRed;
									Bitmap->Canvas->Rectangle(x - r / 2, y - r / 2 , x + r / 2, y + r / 2);
                  }
								}
							}

							if (Place->State == pstFree)
							{
								Bitmap->Canvas->Brush->Style = bsClear;
								int tx = x - Bitmap->Canvas->TextWidth(Place->Nr) / 2;
								int ty = y - Bitmap->Canvas->TextHeight(Place->Nr) / 2;
								Bitmap->Canvas->TextOutW(tx, ty, Place->Nr);
							}
						}
						else
						{
							switch (Place->State)
							{
								case pstSubscribed: // Àáîíåìåíò
									Bitmap->Canvas->Brush->Color = clRed;
									break;

								case pstBookUnpaid: // Íåîïëà÷åííàÿ áðîíü
									if (dmCassa->isBroni && fSelRuta->WasPlaceBooked(Place->Casalenta)) // Âûáðàííàÿ áðîíü
										Bitmap->Canvas->Brush->Color = clGray;
									else // Îñòàëüíûå áðîíè
										Bitmap->Canvas->Brush->Color = clOlive;
									break;

								case pstBookPaid: // Îïëà÷åííàÿ áðîíü
									if (dmCassa->isBroni && fSelRuta->WasPlaceBooked(Place->Casalenta)) // Âûáðàííàÿ áðîíü
										Bitmap->Canvas->Brush->Color = clGray;
									else // Îñòàëüíûå áðîíè
										Bitmap->Canvas->Brush->Color = clInfoBk;
									break;

								case pstReserved: // Âûêóïëåííîå ìåñòî
									Bitmap->Canvas->Brush->Color = clYellow;
									break;

								case pstSelected: // Âûáðàííîå ìåñòî
									Bitmap->Canvas->Brush->Color = clGreen;
									break;

								case pstSelectedByOther: // Âûáðàííîå äðóãèì êàññèðîì ìåñòî
									Bitmap->Canvas->Brush->Color = clTeal;
									break;

								case pstFree: // Ñâîáîäíîå ìåñòî
									continue;
							}

							int x = Place->X;
							int y = Place->Y;
							int r = Params->VisibleRadius;

							// Ðèñóåì ìåñòî
							Bitmap->Canvas->Brush->Style = bsSolid;
							Bitmap->Canvas->Ellipse(x - r, y - r, x + r, y + r);

							if (Params->PrintPlaceNr)
							{
								SetBkMode(Bitmap->Canvas->Handle, TRANSPARENT);
								int tx = x - Bitmap->Canvas->TextWidth(Place->Nr) / 2;
								int ty = y - Bitmap->Canvas->TextHeight(Place->Nr) / 2;
								Bitmap->Canvas->TextOutW(tx, ty, Place->Nr);
							}

						}
					}
			}

			for (int i = 0; i < PriceList->Count; i++)
			{
				TPriceTextPoint* p = (TPriceTextPoint*)PriceList->Items[i];
			 	Bitmap->Canvas->TextOut(p->X, p->Y, String(p->Price));
			}
		}

		BitmapAdd->Assign(Bitmap);

		if (Params && Params->OldLabelPrinting)
		{
		   	PrintTextToCenterRect(Bitmap->Canvas, Params->HCenter, HeaderText, true);
			PrintTextToCenterRect(Bitmap->Canvas, Params->DCenter, DetailText);
		}

		if (Params && Params->OldLabelPrinting)
		{
			PrintTextToCenterRect(BitmapAdd->Canvas, Params->HCenter, HeaderTextAdd, true);
			PrintTextToCenterRect(BitmapAdd->Canvas, Params->DCenter, DetailText);
		}
		Bitmap->Canvas->Brush->Color = clTransparent;
		Bitmap->Canvas->Pen->Width = 2;
		Bitmap->Canvas->Pen->Color = clBlack;
	 // Bitmap->Canvas->Rectangle( 1,1, Bitmap->Width, Bitmap->Height);
		Image->Picture->Assign(Bitmap);
    //^^
		Image->Proportional = True;
	//^^

		if (fPrintSetup->MonitorSetup.MonState == TMonState::msNone)
		{
			for (int i = 0; i < FormsList->Count; i++)
			{
				delete(TfAddSel*)FormsList->Items[i];
				FormsList->Delete(i--);
			}
			return;
		}

		if (FormsList->Count)
		{
			for (int i = 0; i < FormsList->Count; i++)
			{
				TfAddSel* f = (TfAddSel*)FormsList->Items[i];

				f->ImgSchema->Picture->Assign(BitmapAdd);

				if (f->Visible)
				{
					FormResize(f);

					AddSelResize(f);

					if (Params && Params->OldLabelPrinting)
					{
						f->lbHeader->Caption = "";
						f->lbDetail->Caption = "";
					}
					else
					{
						f->lbHeader->Caption = HeaderText;
						f->lbDetail->Caption = DetailText;
					}
				}
			}
		}
		else
		{
			nFormLeft += 10;
			int ready = 0;
			bool manual = fPrintSetup->MonitorSetup.MonState == msManual;
			// Ðó÷íàÿ íàñòðîéêà äîï. ìîíèòîðîâ

			for (int i = 0; i < Screen->MonitorCount && !ready || manual; i++)
			{
				int Left = Screen->Monitors[i]->Left;
				int Right = Left + Screen->Monitors[i]->Width - 1;
				// Îñíîâíîé ìîíèòîð
				if (!manual && nFormLeft >= Left && nFormLeft <= Right)
					continue;

				TfAddSel *f = new TfAddSel(Application);
				f->DoubleBuffered = true;
				f->OnResize = FormResize;
				f->OnKeyDown = SecondFormOnKeyDown;

				f->ImgSchema->Picture->Assign(BitmapAdd);

				if (Params && Params->OldLabelPrinting)
				{
					f->lbHeader->Caption = "";
					f->lbDetail->Caption = "";
				}
				else
				{
					f->lbHeader->Caption = HeaderText;
					f->lbDetail->Caption = DetailText;
				}

				FormsList->Add(f);

				f->Show();

				if (manual)
				{
					TMultiMonitorSetup* m = &fPrintSetup->MonitorSetup;

					f->Left = (m->Left != -1) ? m->Left : Screen->Monitors[i]->Left;
					f->Top = (m->Top != -1) ? m->Top : Screen->Monitors[i]->Top;
					f->Width = (m->Width != -1) ? m->Width : Screen->Monitors[i]->Width;
					f->Height = (m->Height != -1) ? m->Height : Screen->Monitors[i]->Height;

					if (m->Width != -1 || m->Height != -1)
					 f->WindowState = wsMaximized;

					manual = false;
				}
				else
				{
					f->Left = Screen->Monitors[i]->Left;
					f->Top = Screen->Monitors[i]->Top;
					f->WindowState = wsMaximized;
				}

				f->LbState->Visible = true;

				ready++;

				fSelRuta->SetFocus();
			}
		}
	}
	__finally
	{
		delete Bitmap;
		delete BitmapAdd;
	}
}
// ---------------------------------------------------------------------------
void __fastcall TArenaPlaces::ShowSectorMenu(TSector* Sector)
{
	for (int i = 0; i < FormsList->Count; i++)
	{

	  TfAddSel *f = (TfAddSel*)FormsList->Items[i];

	  f->imgMenu->Picture->Assign(bmpMainMenuSchema);
	  ImgResize(f->imgMenu, f->imgMenu->Width, f->imgMenu->Height);

	  ((TGIFImage*)f->imgSelection->Picture->Graphic)->Animate = false;
	  f->imgSelection->Visible = false;

	  f->imgSelection->Left = f->imgMenu->Left + Sector->X * DeltaX(f->imgMenu) - f->imgSelection->Width / 2;
	  f->imgSelection->Top = f->imgMenu->Top + Sector->Y * DeltaY(f->imgMenu) - f->imgSelection->Height / 2;

	  ((TGIFImage*)f->imgSelection->Picture->Graphic)->AnimateLoop = glEnabled;
	  ((TGIFImage*)f->imgSelection->Picture->Graphic)->Animate = true;
	  f->imgSelection->Visible = true;
	}
}
// ---------------------------------------------------------------------------
void __fastcall TArenaPlaces::HideSectorMenu()
{
	for (int i = 0; i < FormsList->Count; i++)
	{
		TfAddSel *f = (TfAddSel*)FormsList->Items[i];

		f->imgMenu->Visible = false;
		f->imgSelection->Visible = false;

		TGIFImage* Gif = (TGIFImage*)f->imgSelection->Picture->Graphic;
		Gif->AnimateLoop = glDisabled;
		Gif->Animate = false;
	}
}
// ---------------------------------------------------------------------------
// TLockedPlacesThread =======================================================
// ---------------------------------------------------------------------------
__fastcall TLockedPlacesThread::TLockedPlacesThread(bool CreateSuspended,
	TArenaPlaces* ArenaPlaces, TOraSession* OraSession)
	: TThread(CreateSuspended)
{
	FArenaPlaces = ArenaPlaces;

	FOraSession = new TOraSession(NULL, OraSession->ConnectString);
    FOraSession->LoginPrompt = false;
	FOraSession->Connect();

	FRefresher = new TSmartQuery(NULL);
	FRefresher->Session = FOraSession;
	FRefresher->SQL->Text = "select abs_nr, cashdesk_name, user_name, action from xplaces_lock"
		" where event_id = :event_id"
		" and event_date = :event_date"
		" and (sector_id = :sector_id or :sector_id is null)";
	FRefresher->ParamByName("event_id")->AsString = FArenaPlaces->sCodu;
	FRefresher->ParamByName("event_date")->AsDateTime = FArenaPlaces->Date;
}
// ---------------------------------------------------------------------------
__fastcall TLockedPlacesThread::~TLockedPlacesThread()
{
	delete FRefresher;
	delete FOraSession;
    delete csUpdate;
}
// ---------------------------------------------------------------------------
void __fastcall TLockedPlacesThread::Execute()
{
	while (true)
	{
		try
		{
			while (!FArenaPlaces ||
				FArenaPlaces->Suspended ||
				!FArenaPlaces->ActiveSector && FArenaPlaces->HasSectors ||
				!FArenaPlaces->RowList)
				Sleep(100);

			csUpdate->Acquire();
			try
			{
				RefreshData();
			}
			__finally
			{
				csUpdate->Release();
			}

			csReadingLockedPlaces->Acquire();
			try
			{
				SyncLockList();
			}
			__finally
			{
				csReadingLockedPlaces->Release();
			}

			Synchronize(UpdateVisualComponents);

			if (FArenaPlaces->Suspended)
				continue;

			Sleep(LockedPlacesTimeout);
		}
		catch ( ... ) {}
	}
}
// ---------------------------------------------------------------------------
void __fastcall TLockedPlacesThread::RefreshData()
{
		if (FRefresher->Active)
			FRefresher->Close();
		FRefresher->Open();
		UpdateLockList();
}
// ---------------------------------------------------------------------------
void __fastcall TLockedPlacesThread::UpdateVisualComponents()
{
	/*ofstream myfile;
	TDateTime TTime  = Time();
	AnsiString S1 =  FormatDateTime("hh:nn:ss:zzz",TTime).c_str();   */

	if(!fSelRuta->skipSyncThread)
	fSelRuta->RedrawArena();

	/*
	myfile.open ("TLockedPlacesThread.txt", std::ios_base::app);
	AnsiString S2 =  FormatDateTime("hh:nn:ss:zzz",Time()).c_str();
	AnsiString S3 =  FormatDateTime("hh:nn:ss:zzz",TTime - Time() ).c_str();
	myfile << "Star(" << S1.c_str() << ")" << " End(" << S2.c_str() << ") " << S3.c_str() << std::endl ;
	myfile.close();    */
}
// ---------------------------------------------------------------------------
void __fastcall TLockedPlacesThread::UpdateLockList()
{
	for (int i = FArenaPlaces->LockedPlaces->Count - 1; i >= 0 ; i--)
		delete (TLockedPlace*)FArenaPlaces->LockedPlaces->Items[i];
	FArenaPlaces->LockedPlaces->Clear();

	FRefresher->First();
	while (!FRefresher->Eof)
	{
		TLockedPlace* LockedPlace = new TLockedPlace();
		LockedPlace->AbsNr = FRefresher->FieldByName("abs_nr")->AsInteger;
		LockedPlace->Cashier = FRefresher->FieldByName("cashdesk_name")->AsString;
		LockedPlace->Username = FRefresher->FieldByName("user_name")->AsString;
		LockedPlace->ActionState = FRefresher->FieldByName("action")->AsString;

		FArenaPlaces->LockedPlaces->Add(LockedPlace);
		FRefresher->Next();
	}
}
// ---------------------------------------------------------------------------
void __fastcall TLockedPlacesThread::SyncLockList()
{
	fSelRuta->freeSel(true);
}
// ---------------------------------------------------------------------------
void __fastcall TLockedPlacesThread::UpdateEventId()
{
	csUpdate->Acquire();
	try
	{
		FRefresher->ParamByName("event_id")->AsString = FArenaPlaces->sCodu;
		FRefresher->ParamByName("event_date")->AsDateTime = FArenaPlaces->Date;
		FRefresher->ParamByName("sector_id")->AsString = "";
		RefreshData();
	}
	__finally
	{
		csUpdate->Release();
	}
}
// ---------------------------------------------------------------------------
void __fastcall TLockedPlacesThread::UpdatePlaceRange(TSector* Sector)
{
	csUpdate->Acquire();
	try
	{
		if( FRefresher && Sector)
		{
			FRefresher->ParamByName("sector_id")->AsString = IntToStr(Sector->Nr);
		RefreshData();
		}
	}
	__finally
	{
		csUpdate->Release();
	}
}
// ---------------------------------------------------------------------------
int __fastcall TfSelRuta::LockPlace(String EventId, TDateTime Date, TPlace* Place, String& ResultMsg)
{
	csUpdate->Acquire();
	try
	{
		sqlPlaceLock->ParamByName("event_id")->AsString = EventId;
		sqlPlaceLock->ParamByName("event_date")->AsDateTime = Date;
		sqlPlaceLock->ParamByName("place_id")->AsString = Place->Id;
		sqlPlaceLock->Execute();

		ResultMsg = sqlPlaceLock->ParamByName("result_msg")->AsString;

		switch (sqlPlaceLock->ParamByName("result")->AsInteger)
		{
			case 0:
				Place->State = pstSelected;
				break;
			case 1:
				Place->State = pstReserved;
				break;
			case 2:
				Place->State = pstSelectedByOther;
				break;
		}

		return sqlPlaceLock->ParamByName("result")->AsInteger;
	}
	__finally
	{
        csUpdate->Release();
	}

    return -1;
}
// ---------------------------------------------------------------------------
void __fastcall TfSelRuta::UnlockPlace(String EventId, TDateTime Date, TPlace* Place)
{
	csUpdate->Acquire();
	try
	{
		sqlPlaceUnlock->ParamByName("event_id")->AsString = EventId;
		sqlPlaceUnlock->ParamByName("event_date")->AsDateTime = Date;
		sqlPlaceUnlock->ParamByName("place_id")->AsInteger = Place->Id;
		sqlPlaceUnlock->Execute();

		Place->State = pstFree;
	}
	__finally
	{
        csUpdate->Release();
    }
}
// ---------------------------------------------------------------------------
// TfSelRuta =================================================================
// ---------------------------------------------------------------------------

__fastcall TfSelRuta::TfSelRuta(TComponent *Owner) : TForm(Owner)
{
	RowList = new TRowList;
    skipSyncThread = 0;

	imgRectangle = new TImage(pnlComplex);
	imgRectangle->Parent = pnlComplex;
	imgRectangle->Transparent = True;
	imgRectangle->BringToFront();
	imgRectangle->Visible = false;
	imgRectangle->OnMouseMove = imgArenaMouseMove;
	imgRectangle->OnMouseUp = imgArenaMouseUp;

	isUserSelect = true;
	freeSel();
	isCanSalectThisItemByMouse = true;

	pnlComplex->DoubleBuffered = true;

	Application->OnDeactivate = FormHide;

	csUpdate = new TCriticalSection();
	csReadingLockedPlaces = new TCriticalSection();

	ArenaPlaces = new TArenaPlaces(dmCassa->db, RowList);

    SpinEdit1->OnChange = NULL;
	SpinEdit1->Value = (int)(dmCassa->iSelZoomPercent);
	SpinEdit1->OnChange = SpinEdit1Change;
  _setSelectBroniQuery();
}
// ---------------------------------------------------------------------------
void __fastcall TfSelRuta::prepareForOpen(void)
{
	ForOpenCloseRuta(false);

	qsDirect->ParamByName("DDATE")->AsDateTime = DateVinz;
	if (!qsDirect->Active)
		qsDirect->Open();
	lastKey = "";
	freeSel();
}
// ---------------------------------------------------------------------------

static long LastOras = 0;
static String LastRuta = "";
// ---------------------------------------------------------------------------

void __fastcall TfSelRuta::ForOpenCloseRuta(bool isOp, bool isFastRefresh)
{
	if (isOp)
	{
		if (qsT0RUTA->Active)
			qsT0RUTA->RefreshQuery();
		else
			qsT0RUTA->Open();
		if (LastRuta != "" && fSelRuta->qsT0RUTA->Locate("CODU", LastRuta,
			TLocateOptions()));
		LastRuta = "";
	}
	else
	{
		if (!isFastRefresh)
		{
			qsFreeLoc->Close();
			qsT0RUTA->Close();
		}
	}
}
// ---------------------------------------------------------------------------

int __fastcall selectRutaDir(TDate &dd, String strDest,
	bool isBroniNeed
	)
{
	fSelRuta->isRutaBusy = 0;
	fSelRuta->DateVinz = dd;
	fSelRuta->strDest = strDest;
	fSelRuta->btnStopRuta->Visible = dmCassa->isCassaPerron;
	fSelRuta->fDirectID_intFlag1 = false;
	fSelRuta->fRutaCOD_intFlag1 = false;

	fSelRuta->LangCb->ItemIndex = (int)dmLang->LM->UnLanguage;

	if (dmCassa->bBookingMode)
	{
		fSelRuta->cbxBroni->Enabled = false;
		fSelRuta->cbxBroni->Checked = true;
	}
	else
		fSelRuta->cbxBroni->Checked = isBroniNeed;

	fSelRuta->pnlBroni->Visible = isBroniNeed;

	fSelRuta->broniButton = NULL;
	fSelRuta->broniCasaLenta = 0;
	fSelRuta->broniInternTip = -1;
	fSelRuta->ForOpenCloseRuta(false);

	fSelRuta->qsDirect->Close();

	if (strDest.Length())
	{
		String sFilt = "UPPER(DENUMIREA) LIKE UPPER('%" + strDest + "%')";
	}
	else
	{
		fSelRuta->qsDirect->SagiFilterSYS = "";
	}

	fSelRuta->prepareForOpen();
	fSelRuta->pgc->ActivePage = fSelRuta->tbsComplex;
	fSelRuta->ActiveControl = fSelRuta->dbgrComplex;

	fSelRuta->SetMainMenuVisible(false);

	fSelRuta->SetCapt();

	int mrrr = fSelRuta->ShowModal();
	if (mrrr == mrOk)
	{
		dd = fSelRuta->DateVinz;
		LastOras = fSelRuta->qsDirectID->AsInteger;
		LastRuta = fSelRuta->qsT0RUTA->FieldByName("CODU")->AsString;
	}
	else
		fSelRuta->UnlockLockedPlaces();


	return (mrrr == mrOk);
}
// ---------------------------------------------------------------------------
void __fastcall TfSelRuta::UnlockLockedPlaces()
{
	if (this && ArenaPlaces)
		sqlPlaceUnlockAll->Execute();
}
// ---------------------------------------------------------------------------
void __fastcall TfSelRuta::PayLockedPlaces()
{
	if (this && ArenaPlaces)
		sqlPlacePayAll->Execute();
}
// ---------------------------------------------------------------------------

void __fastcall TfSelRuta::SetCapt()
{
	String ss22 = "";
	if (dmCassa->isPridn)
		ss22 = "Val.=" + fVinz->GetSessValuta() + " ";

	fSelRuta->Caption = ss22 + fMain->LS->Text["ondate"] + DateToStr(DateVinz) +
		fMain->LS->Text["filt"] + strDest + fMain->LS->Text["seldistandrout"];
	rzLocsInpManual->Text = "";
}
// ---------------------------------------------------------------------------
void __fastcall TfSelRuta::refreshOnlinePlaces()
{

	if (ArenaPlaces && ArenaPlaces->LockedPlaces)
	{
		csReadingLockedPlaces->Acquire();
		try
		{
			for (int i = 0; i < ArenaPlaces->LockedPlaces->Count; i++)
			{
				TLockedPlace* LockedPlace = (TLockedPlace*)ArenaPlaces->LockedPlaces->Items[i];
				TPlace* Place = ArenaPlaces->AbsPlaces[LockedPlace->AbsNr];
				if (Place)
				{
					Place->Cashier = LockedPlace->Cashier;
					Place->Username = LockedPlace->Username;
					Place->ActionState = LockedPlace->ActionState;

					if (Place->State == pstFree || Place->State == pstSelected)
					{
						if (LockedPlace->ActionState == lpstPaid)
							Place->State = pstReserved;
						else if (Place->State != pstSelected)
							Place->State = pstSelectedByOther;
						else
							Place->CheckingForFree = false;
					}
				}
			}
		}
		__finally
		{
			csReadingLockedPlaces->Release();
		}
	}
	for (int i = 0; i < RowList->Count; i++)
	{
		for (int j = 0; j < RowList->Items[i]->Count; j++)
		{
			TPlace* Place = RowList->Items[i]->Places[j];
			if (Place->CheckingForFree == true)
			{
				Place->State = pstFree;
			   	Place->CheckingForFree = false;
			}
		}
	}
}
// ---------------------------------------------------------------------------
void __fastcall TfSelRuta::freeSel(bool OnlineOnly)
{
	nLocationFreePlaces = 0;
	nLocationTotalPlaces = 0;

	for (int i = 0; i < RowList->Count; i++)
	{
		for (int j = 0; j < RowList->Items[i]->Count; j++)
		{
			TPlace* Place = RowList->Items[i]->Places[j];

			if (OnlineOnly)
			{
				if (Place->State == pstSelectedByOther)
				{
					Place->State = pstFree;
					Place->Cashier = "";
					Place->Username = "";
					Place->ActionState = "";
                }
				else if (Place->State == pstFree)
					nLocationFreePlaces++;
				else if (Place->State == pstSelected)
					Place->CheckingForFree = true;
			}
			else
				Place->State = pstReserved;

			nLocationTotalPlaces++;
		}
	}

	if (OnlineOnly)
	{
		refreshOnlinePlaces();
		return;
	}

	if (qsBroni->Active)
		qsBroni->DisableControls();
	try
	{
		if (qsT0RUTA->Active && qsFreeLoc->Active)
		{
			SetFreeLocSectorParams(qsFreeLoc);
			qsFreeLoc->Refresh();

			for (qsFreeLoc->First(); !qsFreeLoc->Eof; qsFreeLoc->Next())
			{
				if (!qsFreeLoc->FieldByName("LOCLIBER")->IsNull)
				{
					 // ShowMessage(qsFreeLoc->FieldByName("LOCLIBER")->AsInteger);
           int res = qsFreeLoc->FieldByName("LOCLIBER")->AsInteger;
						 TPlace* Place = ArenaPlaces->AbsPlaces[qsFreeLoc->FieldByName("LOCLIBER")->AsInteger];

						Place->Casalenta = "";
						if (Place->State == pstSelectedByOther)
							continue;
						nLocationFreePlaces++;
						Place->State = psFree;

				}
				else if (qsBroni->Active)
				{
					TPlace* Place = ArenaPlaces->AbsPlaces[qsFreeLoc->FieldByName("LOC")->AsInteger];
					if (Place)
					{
						Place->Casalenta = qsFreeLoc->FieldByName("IDCASLENTA")->AsString;
						if (qsBroni->Locate("idcasalenta", Place->Casalenta, TLocateOptions()))
						{
							if (qsBroni->FieldByName("is_subscription")->AsInteger > 0)
								Place->State = pstSubscribed; // Àáîíåìåíò
							else if (qsBroni->FieldByName("starea")->AsInteger == 1)
								Place->State = pstBookPaid; // Áðîíü îïëà÷åíà
							else
								Place->State = pstBookUnpaid; // Áðîíü íå îïëà÷åíà
						}
					}
				}
			}
			refreshOnlinePlaces();
		}
	}
	__finally
	{
		if (qsBroni->Active)
		{
			qsBroni->First();
			qsBroni->EnableControls();
		}
	}

	countSel = 0;
}
// ---------------------------------------------------------------------------
TColor InvColor(TColor AColor)
{
  int R, G, B;
  int C = ColorToRGB(AColor);

  R = GetRValue(C);
  G = GetGValue(C);
  B = GetBValue(C);

  double a = 1 - ( 0.3 * R + 0.59 * G + 0.11 * B)/255;

	if (a < 0.5)
		return clBlack;
	else
		return clWhite;
}
// ---------------------------------------------------------------------------

bool __fastcall TfSelRuta::RedrawArena()
{
	if (!ArenaPlaces)
		return false;

	TDateTime dt;
	TDateTime dtime;
	TSpotParams* Params = ArenaPlaces->GetActiveSpotParams();
	lbHeader->Caption = "";
	lbDetail->Caption = "";

	if (Params)
	{
		String sHeader;
		String sHeaderAdd;


		dt = qsT0RUTA->FieldByName("data")->AsDateTime;
		dtime = qsT0RUTA->FieldByName("time_in")->AsDateTime;
		sHeader += FormatDateTime("dd.mm.yyyy", dt) + " " + FormatDateTime("hh:mm", dtime) + "\n";
		sHeader += qsT0RUTA->FieldByName("denumirea")->AsString + "\n";

		if (ArenaPlaces->ActiveSector)
			sHeader += LS->Text["sector"] + ": " + ArenaPlaces->ActiveSector->Text + "\n\n";

		int SoldPlaces = qsT0RUTA->FieldByName("places_sold")->AsInteger;
		int FreePlaces = ArenaPlaces->TotalPlaces - SoldPlaces;

		sHeaderAdd = sHeader;

		sHeader += LS->Text["total_sold_places"] + ": " + String(SoldPlaces) + "\n";
		sHeader += LS->Text["total_free_places"] + ": " + String(FreePlaces) +
			"(" + String(ArenaPlaces->TotalPlaces) + ")\n";

		//^^
		if( !dmCassa->bAddSelHideSoldPlacesCount )
			sHeaderAdd += LS->Text["total_sold_places"] + ": " + String(SoldPlaces) + "\n";
		sHeaderAdd += LS->Text["total_free_places"] + ": " + String(FreePlaces) +
			"(" + String(ArenaPlaces->TotalPlaces) + ")\n";
		//--


		if (ArenaPlaces->ActiveSector)
		{
			sHeader += LS->Text["free_places_sector"] + ": " + String(nLocationFreePlaces) +
				+ "(" + String(nLocationTotalPlaces) + ")\n";
			sHeaderAdd += LS->Text["free_places_sector"] + ": " + String(nLocationFreePlaces) +
				+ "(" + String(nLocationTotalPlaces) + ")\n";
		}

		ArenaPlaces->HeaderText = sHeader;
		ArenaPlaces->HeaderTextAdd = sHeaderAdd;

		int nTotal = 0;
		int nSelectedPlaces = 0;

		String sMaster = "";
		TStringList* PlacesPriceList = new TStringList();

		try
		{
			for (int i = 0; i < RowList->Count; i++)
				for (int j = 0; j < RowList->Items[i]->Count; j++)
				{
					TPlace* Place = RowList->Items[i]->Places[j];

					if (Place->State == pstSelected)
					{
						int n = _wtoi(PlacesPriceList->Values[Place->Price].c_str());
						PlacesPriceList->Values[Place->Price] = String(n + 1);
					}
				}

			if (PlacesPriceList->Count)
			{
				for (int i = 0; i < PlacesPriceList->Count; i++)
				{
					String Name = PlacesPriceList->Names[i];
					int NameVal = Name.ToInt();
					int NameCount = PlacesPriceList->Values[Name].ToInt();
					nSelectedPlaces += NameCount;
					nTotal += NameVal * NameCount;

					sMaster += Name + " MDL (" + String(NameCount) + "), ";

				}

				sMaster.Delete(sMaster.Length() - 1, 2);

				sMaster += ";\n" + LS->Text["arena_total"] + ": " + String(nTotal) + " MDL"
				 " (" + String(nSelectedPlaces) + ")";
			}
		}
		__finally
		{
			delete PlacesPriceList;
		}

		ArenaPlaces->DetailText = sMaster;

		if (!Params->OldLabelPrinting)
		{
			lbHeader->Caption = ArenaPlaces->HeaderText;
			lbDetail->Caption = ArenaPlaces->DetailText;
		}
	}

	ArenaPlaces->RedrawPlaces(imgArena, this->Left);

	//ñãëàæèâàíèå êàðòèíêè
	/*
		ImageEnView1->Width = imgArena->Picture->Graphic->Width;
		ImageEnView1->Height = imgArena->Picture->Graphic->Height;
		ImageEnView1->Bitmap->Assign(imgArena->Picture->Graphic);
		ImageEnView1->Proc->Resample(imgArena->Width, imgArena->Height, rfLanczos3, False);
		ImageEnView1->Proc->Resample(imgArena->Picture->Graphic->Width, imgArena->Picture->Graphic->Height, rfLanczos3, False);
		imgArena->Picture->Graphic->Assign(ImageEnView1->Bitmap);
	 */
		imgArena->Update();
	//
	return true;
}
// ---------------------------------------------------------------------------

void __fastcall TfSelRuta::setSel(TPlace* SelPlace, bool Redraw = true)
{
	if (SelPlace->State == pstSelected)
	{
		UnlockPlace(qsT0RUTACODU->AsString, qsT0RUTADATA->AsDateTime, SelPlace);
		countSel--;
	}
	else
	{
		if (SelPlace->State == pstSelectedByOther)
			return;


		String ResultMsg;
		int Result = LockPlace(qsT0RUTACODU->AsString, qsT0RUTADATA->AsDateTime, SelPlace, ResultMsg);
		if (Result != 0)
		{
			if (fPrintSetup->ShowPlaceHint)
			{
				BalloonHint->Title = ResultMsg;
				BalloonHint->HideAfter = 10000;
				BalloonHint->ShowHint(Mouse->CursorPos);
			}
		}
		else
			countSel++;
	}

	maxNMB = countSel;

	if (Redraw) {

	skipSyncThread = 1;

		//	TDateTime TTime  = Time();

		RedrawArena();
		 /*
		ofstream myfile;
		myfile.open ("RedrawPlacesLog.txt", std::ios_base::app);
		AnsiString S1 =  FormatDateTime("hh:nn:ss:zzz",TTime).c_str();
		AnsiString S2 =  FormatDateTime("hh:nn:ss:zzz",Time()).c_str();
		AnsiString S3 =  FormatDateTime("hh:nn:ss:zzz",TTime - Time()).c_str();
		myfile << S1.c_str() << "||" << S2.c_str()<< "=" << S3.c_str() << std::endl ;
		myfile.close();     */

	skipSyncThread = 0;
	}
}
// ---------------------------------------------------------------------------
void __fastcall TfSelRuta::qsFreeLocAfterOpen(TDataSet *DataSet)
{
	if (DataSet)
		freeSel();
	isRutaBusy = 0;
	try
	{
		qqIsVinzEn->Close();
		qqIsVinzEn->ParamByName("CODU")->AsString =
			qsT0RUTA->FieldByName("CODU")->AsString;
		qqIsVinzEn->ParamByName("DATA")->AsDateTime =
			qsT0RUTA->FieldByName("DATA")->AsDateTime;

		isRutaBusy = qqIsVinzEn->RecordCount;

	}
	catch (...)
	{
	}

	if (this->Visible && RedrawArena())
	{
		pnlComplexResize(this);

		if (!imgArena->Visible)
			ChangeArenaState(true);
	}

	qqIsVinzEn->Close();
}
// ---------------------------------------------------------------------------
bool __fastcall TfSelRuta::WasPlaceBooked(String Casalenta)
{
	return qsBroni->Active && Casalenta != "" && Casalenta == qsBroni->FieldByName("idcasalenta")->AsString;
}
// ---------------------------------------------------------------------------

void __fastcall TfSelRuta::qsDirectBeforeOpen(TDataSet *DataSet)
{
	String s2;
	// &PERRCOND
	if (dmCassa->isCassaPerron)
	{
		s2 = "ISPERRON=1";
		if (fPrintSetup && fPrintSetup->cbxLimit1ora->Checked)
			s2 += " AND SYSDATE<=DATIVINZSTOP ";
		qsDirect->SQL->Text = Sysutils::StringReplace(qsDirect->SQL->Text, "&PERRCOND",
			s2, TReplaceFlags() << rfReplaceAll << rfIgnoreCase);
	}
	else
		qsDirect->SQL->Text = StringReplace(qsDirect->SQL->Text,
		"&PERRCOND", "sysdate<=DATIVINZSTOP and ISPERRON=0",
		TReplaceFlags() << rfReplaceAll << rfIgnoreCase);

	// --
	if (qsT0RUTA->Active && qsT0RUTA->RecordCount)
		qsDirect->ParamByName("DDATE")->AsDateTime =
			qsT0RUTA->FieldByName("DATA")->AsDateTime;
	else
		qsDirect->ParamByName("DDATE")->AsDateTime = int(DateVinz);

	qsDirect->ParamByName("CASAGR")->AsInteger = dmCassa->casaGroup1;
}
// ---------------------------------------------------------------------------
void __fastcall TfSelRuta::btOkClick(TObject *Sender)
{
	if( countSel )
		ModalResult = mrOk;
	else
    ModalResult = mrCancel;
}
// ---------------------------------------------------------------------------

void __fastcall TfSelRuta::qsT0RUTABeforeOpen(TDataSet *DataSet)
{
	qsT0RUTA->ParamByName("ruta_filt")->AsString = "%" + fVinz->meFilter->Text + "%";
}
// ---------------------------------------------------------------------------

void __fastcall TfSelRuta::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if (dmCassa->bBookingMode
		&& MessageBox(this->Handle, LS->Text["exit_query"].c_str(), LS->Text["booking"].c_str(), MB_OKCANCEL) != IDOK)
	{
		CanClose = false;
		return;
	}

	CanClose = true;
	if (ModalResult == mrOk)
	{
		qsFreeLocAfterOpen(NULL);
		if (isRutaBusy)
		{
			CanClose =
				(MessageDlg(String(fMain->LS->Text["CanClose"]) + "\n" +
				/*reMessage->Text*/ + "\n" + String
				(fMain->LS->Text["accept"]), mtConfirmation,
				TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes);
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfSelRuta::fDirect_IDFieldsChange(TObject *Sender)
{
	// static bool fDirectID_intFlag1=false;
	if (!fDirectID_intFlag1)
	{
		fDirectID_intFlag1 = true;
		// fDirect_ID->Enabled=false;
		try
		{
			try
			{
				ForOpenCloseRuta(true);

				dsDirect->Enabled = true;
				dsT0RUTA->Enabled = true;

				fRuta_COD->DataActive = true;
				fDirectID_intFlag1 = false;
			}
			catch (Exception &E)
			{
				if (MessageDlg(E.Message + "\nRepetam?", mtConfirmation,
					TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
					fDirectID_intFlag1 = false;
				else
					Abort();

			}
		}
		__finally
		{
			// fDirect_ID->Enabled=false;
		}

	}

}
// ---------------------------------------------------------------------------

void __fastcall TfSelRuta::fDirect_IDFieldsBeginToChange(TObject *Sender)
{
	ForOpenCloseRuta(false, true);

	dsT0RUTA->Enabled = false;
	dsDirect->Enabled = false;

	fRuta_COD->DataActive = false;
	fRuta_CODFieldsBeginToChange(NULL);
}
// ---------------------------------------------------------------------------
 TFileTime DateTimeToFileTime(TDateTime FileTime)
 {
   TFileTime LocalFileTime, Ft;
   TSystemTime SystemTime;
   TFileTime Result;

   Result.dwLowDateTime  = 0;
   Result.dwHighDateTime = 0;
   DateTimeToSystemTime(FileTime, SystemTime);
   SystemTimeToFileTime(&SystemTime, &LocalFileTime);
   LocalFileTimeToFileTime(&LocalFileTime, &Ft);
   Result = Ft;
   return Result;
 }

// ---------------------------------------------------------------------------
 TDateTime FileTimeToDateTime(TFileTime FileTime)
 {
   TFileTime ModifiedTime;
   TSystemTime SystemTime;

   TDateTime Result = 0;
   if (FileTime.dwLowDateTime == 0 && FileTime.dwHighDateTime == 0)
     return Result;
   try
   {
	 FileTimeToLocalFileTime(&FileTime, &ModifiedTime);
	 FileTimeToSystemTime(&ModifiedTime, &SystemTime);
	 Result = SystemTimeToDateTime(SystemTime);
   }
   catch(...) {}

	 return Result;
 }

void ResizeBitmap(TPngImage* Bitmap, int width, int height)
{
	TRect R;
	TPngImage * B;
	int X = 0;
	int Y = 0;
	if (Bitmap!= NULL)
	{
		B= new TPngImage();
		try
		{
			if (Bitmap->Width > Bitmap->Height )
			{
				R.Right = width;
				R.Bottom = ((width * Bitmap->Height) % Bitmap->Width);
				X = 0;
				Y = (height % 2) - (R.Bottom % 2);
			}
			else
			{
				R.Right = ((height * Bitmap->Width) % Bitmap->Height);
				R.Bottom = height;
				X = (width % 2) - (R.Right % 2);
				Y = 0;
			}
			R.Left = 0;
			R.Top = 0;
			B->Resize(width, height);
			B->Canvas->Brush->Color = clWhite;
			B->Canvas->FillRect(B->Canvas->ClipRect);
			B->Canvas->StretchDraw(R, Bitmap);
			Bitmap->Resize(width, height);
			Bitmap->Canvas->Brush->Color = clWhite;
			Bitmap->Canvas->FillRect(Bitmap->Canvas->ClipRect);
			Bitmap->Canvas->Draw(X, Y, B);
			}
		__finally
		{
			B->Free();
		}
   }
}


// ---------------------------------------------------------------------------
void __fastcall TfSelRuta::GetImageFromSources(String ImageTemplateName, TPngImage* Bmp)
{
  TSmartQuery *q = new TSmartQuery(this);
  q->Session = dmCassa->db;
  q->SQL->Text = "select update_time from xsablons"
	" where userid = 0 and versionid = 0"
	" and sabloncod = :template_name";
  q->ParamByName("template_name")->AsString = ImageTemplateName;
  q->Open();
  /*
  q->SQL->Text = "select sysdate update_time from V1EVENT_IMAGES"
	" where event_id = :template_name and rownum =1";
  q->ParamByName("template_name")->AsString = ImageTemplateName;
  q->Open();        */

  String ImageDir = ExtractFilePath(Application->ExeName) + "\\res";
  String ImageFilePath = ImageDir + "\\" + ImageTemplateName + ".png";

  TDateTime ImageUpdateTime = q->FieldByName("update_time")->AsDateTime;

	TPngImage* png = new TPngImage();

  // Ïîèñê èçîáðàæåíèÿ â ïàìÿòè
  bool bFoundInMemory = false;
  if (ImgList)
  {
    for (int i = 0; i < ImgList->Count; i++)
    {
	  TImgInstance* Item = (TImgInstance*)ImgList->Items[i];
      if (Item->Name == ImageTemplateName && Item->UpdateTime == ImageUpdateTime)
			{
        Item->ImgStream->Position = 0;
		png->LoadFromStream(Item->ImgStream);
				png->AssignTo(Bmp);

		bFoundInMemory = true;
        break;
      }
	}
  }

	TMemoryStream *ms = NULL;

  // Ïîèñê â ôàéëàõ
  bool bFileFound = false;
  if (!bFoundInMemory && FileExists(ImageFilePath))
  {
    HANDLE hFile = CreateFile(ImageFilePath.c_str(), FILE_READ_ATTRIBUTES,
      FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	FILETIME file_time;
	GetFileTime(hFile, &file_time, (LPFILETIME)NULL,(LPFILETIME)NULL);
	CloseHandle(hFile);
	TDateTime dt = FileTimeToDateTime(file_time);

	if (q->FieldByName("update_time")->AsDateTime == dt)
    {
      ms = new TMemoryStream();
	  ms->LoadFromFile(ImageFilePath);
	  ms->Position = 0;

      png->LoadFromStream(ms);
      png->AssignTo(Bmp);

      bFileFound = true;
    }
  }

  // Ïîèñê â ÁÄ
  if (!bFoundInMemory && !bFileFound && q->RecordCount)
  {
	q->SQL->Text = "select sablonf1 from xsablons"
	  " where userid = 0 and versionid = 0"
	  " and sabloncod = :template_name";
	q->ParamByName("template_name")->AsString = ImageTemplateName;
	q->Open();

	TBlobField *Blob = (TBlobField*)q->Fields->FieldByName("sablonf1");

	ms = new TMemoryStream();
	Blob->SaveToStream(ms);
    ms->Position = 0;

    png->LoadFromStream(ms);
	png->AssignTo(Bmp);

	CreateDir(ImageDir);
	ms->SaveToFile(ImageFilePath);

    HANDLE hFile = CreateFile(ImageFilePath.c_str(), FILE_WRITE_ATTRIBUTES,
	  FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, OPEN_EXISTING,
	  FILE_ATTRIBUTE_NORMAL, NULL);
	FILETIME file_time = DateTimeToFileTime(ImageUpdateTime);
	SetFileTime(hFile, &file_time,(LPFILETIME)NULL,(LPFILETIME)NULL);
	CloseHandle(hFile);
  }

  // Íè÷åãî íå íàéäåíî
  if (!bFoundInMemory && !bFileFound && !q->RecordCount)
	  Bmp->Canvas->FillRect(Bmp->Canvas->ClipRect);

  if (!bFoundInMemory && ms)
  {
	if (!ImgList)
	  ImgList = new TList();
	TImgInstance* Item = new TImgInstance();
	ms->Position = 0;
	Item->ImgStream = ms;
	Item->Name = ImageTemplateName;
	Item->UpdateTime = ImageUpdateTime;
	ImgList->Add(Item);
  }

  delete q;
  delete png;
}
// ---------------------------------------------------------------------------
void __fastcall TfSelRuta::fRuta_CODFieldsChange(TObject *Sender)
{
	static bInside = false;
	if (bInside)
		return;
	bInside = true;
	try
	{
		TSmartQuery *q = new TSmartQuery(this);


		q->Session = dmCassa->db;
		q->SQL->Text = "select m.template_image_name name from t0marca m"
			" where m.autobus = :autobus and m.tip = :tip";
		q->ParamByName("autobus")->AsInteger = qsT0RUTAAUTOBUS->AsInteger;
		q->ParamByName("tip")->AsString = qsT0RUTATIP->AsString;
		q->Open();

		qsMarcaSectors->ParamByName("cod_autobus")->AsInteger = qsT0RUTAAUTOBUS->AsInteger;
		qsMarcaSectors->ParamByName("tip")->AsString = qsT0RUTATIP->AsString;

		if (!qsMarcaSectors->Active)
			qsMarcaSectors->Open();
		else
			qsMarcaSectors->Refresh();

		this->IsSectorSchema = qsMarcaSectors->RecordCount;

		if (q->RecordCount && q->FieldByName("name")->AsString != ImageTemplateName)
		{
			if (!bmpArena)
				bmpArena = new TPngImage();
			GetImageFromSources(q->FieldByName("name")->AsString, bmpArena);
			//^^  îòðèñîâêà êàðòèíêè ñ öåíàìè
			if( fMain->DrawPricesFromDB )
			{
				q->Close();
				q->SQL->Text = "select sablonff, xsablonff, ysablonff from xsablons_u_footer uf, "
				" XSABLONS_FOOTER f where uf.cods = f.cods and codu = :codu and :datar between datab and datae";
				q->ParamByName("codu")->AsInteger = qsT0RUTACODU->AsInteger;
				q->ParamByName("datar")->AsDateTime = qsT0RUTADATA->AsDateTime;
				q->Open();
				if ( q->RecordCount )
				{
					TMemoryStream *ms = NULL;
					TJPEGImage *jpeg = new TJPEGImage;
					ms = new TMemoryStream();
					((TBlobField*)q->FieldByName("sablonff"))->SaveToStream(ms);
					ms->Position = 0;
					jpeg->LoadFromStream(ms);
					bmpArena->Canvas->Draw(Math::Max((int)(bmpArena->Width/2 - jpeg->Width/2),0),
																 Math::Max((int)(bmpArena->Height - jpeg->Height),0),jpeg);
					delete ms;
					delete jpeg;
				}
			}
			//^^
		}

		SetMainMenuVisible(false);
		imgArenaMouseEnter(Sender);

		UnlockLockedPlaces();

		ArenaPlaces->SwitchSchema(qsT0RUTAAUTOBUS->AsInteger,
			qsT0RUTATIP->AsString, qsT0RUTACODU->AsString, 1, qsT0RUTADATA->AsDateTime,
			bmpArena, IsSectorSchema);
		//07.09.2017 O.Rotari prices by color defined
		TSmartQuery *pl = new TSmartQuery(this);
		pl->Session = dmCassa->db;
		pl->SQL->Text = " select price , delphicolor from v1event_price_colors"
										" where codu = :codu "
										" order by price";
		pl->ParamByName("codu")->AsInteger = qsT0RUTACODU->AsInteger;
		pl->Open();

		bmpArena->Canvas->Font->Height = bmpArena->Height * 4 / 100 ;

		TColor OldColor = bmpArena->Canvas->Brush->Color;

		bmpDetail = new TBitmap();
		bmpDetail->SetSize( Math::Max( bmpArena->Height / 20 , 40) * 1.5 * (pl->RecordCount + 2) , Math::Max( bmpArena->Height /20 , 40) );
		bmpDetail->Canvas->Font->Height = bmpDetail->Height / 2;

		double imgDD = bmpDetail->Width / (pl->RecordCount + 2);


		for (pl->First(); !pl->Eof; pl->Next()){

            bmpDetail->Canvas->TextOut( imgDD , bmpDetail->Height / 4 , "MDL" );

			String Price =  pl->FieldByName("price")->AsString;

			bmpDetail->Canvas->Pen->Style = psClear;
			bmpDetail->Canvas->Brush->Color = TColor(StrToInt64(pl->FieldByName("delphicolor")->AsString));

			bmpDetail->Canvas->Ellipse(
			imgDD * (1 + pl->RecNo) - bmpDetail->Height / 2,
			bmpDetail->Height / 4,
			imgDD * (1 + pl->RecNo) + bmpDetail->Height / 2,
			bmpDetail->Height * 3 / 4);

			bmpDetail->Canvas->Brush->Style = bsClear;

			bmpDetail->Canvas->TextOut(
			imgDD * (1 + pl->RecNo) - bmpDetail->Canvas->TextWidth(Price) / 2 ,
			bmpDetail->Height / 4,
			Price);

		}

		int oldh = bmpArena->Height;
		bmpArena->Canvas->Pen->Style = psClear;
		bmpArena->SetSize( bmpArena->Width , bmpArena->Height + bmpDetail->Height );
		bmpArena->Canvas->Rectangle( 0 , oldh , bmpArena->Width + 1 , bmpArena->Height + 1 );
		bmpArena->Canvas->Draw( (bmpArena->Width - bmpDetail->Width) / 2 , oldh , bmpDetail ) ;

		delete bmpDetail;

		pl->Close();
		bmpArena->Canvas->Brush->Color = OldColor;
		delete pl;
		//---
		cbSectors->Items->Clear();
		if (ArenaPlaces->SecList)
		{
			for (int i = 0; i < ArenaPlaces->SecList->Count; i++) {
				TSector* Sector = (TSector*)ArenaPlaces->SecList->Items[i];
				cbSectors->Items->AddObject(Sector->Text,(TObject*)Sector);
			}
		}
        btnFindBook->Visible = IsSectorSchema;

		OpenBroni();
		ArenaPlaces->HideSectorMenu();

		delete q;

		if (fRutaCOD_intFlag1)
			return;
		fRutaCOD_intFlag1 = true;
		fRuta_COD->Enabled = false;
		try
		{
			if (qsT0RUTA->FieldByName("LOCURINEED")->AsInteger && !qsFreeLoc->Active)
			{
				SetFreeLocSectorParams(qsFreeLoc);
				qsFreeLoc->Open();
			}
			else if (qsT0RUTA->FieldByName("LOCURINEED")->AsInteger == 0 && qsFreeLoc->Active)
				qsFreeLoc->Close();
		}
		__finally
		{
			fRutaCOD_intFlag1 = false;
			fRuta_COD->Enabled = true;
			this->IsMainMenu = true;
		}
	}
	__finally
	{
        bInside = false;
	}
}
// ---------------------------------------------------------------------------
void __fastcall TfSelRuta::SetFreeLocSectorParams(TSmartQuery* Query)
{
	Query->ParamByName("sec")->AsString = "";
	Query->ParamByName("sector_selection")->AsString = "";

	if (ArenaPlaces)
	{
		if (ArenaPlaces->ActiveSector)
		{
			Query->ParamByName("sec")->AsInteger = ArenaPlaces->ActiveSector->Nr;
			Query->ParamByName("sector_selection")->AsString = "";
		}
		else if (ArenaPlaces->SecList)
		{
			Query->ParamByName("sector_selection")->AsString = "1";
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfSelRuta::DisableSelectLocBilet()
{
	isRutaBusy = 0; // gluc next busy
	qsFreeLoc->Close();
}

// ---------------------------------------------------------------------------

void TfSelRuta::ChangeArenaState(bool bVisible)
{
	if (bVisible)
		pnlComplex->Color = clWhite;
	else
		pnlComplex->Color = clBtnFace;

	pnlComplex->HorzScrollBar->Visible = bVisible;
	pnlComplex->VertScrollBar->Visible = bVisible;

	imgArena->Visible = bVisible;
	lbArena->Visible = !bVisible;
	lbHeader->Visible =  bVisible;
	lbDetail->Visible =  bVisible;

	if (lbArena->Visible)
	{
		lbArena->Left = (pnlComplex->ClientWidth - lbArena->Width) / 2;
		lbArena->Top = (pnlComplex->ClientHeight - lbArena->Height) / 2;
	}

	if (ArenaPlaces)
	{
		ArenaPlaces->HeaderText  = lbHeader->Caption;
		ArenaPlaces->DetailText  = lbDetail->Caption;
		ArenaPlaces->ChageImgVisible(bVisible);
	}
}

// ---------------------------------------------------------------------------

void __fastcall TfSelRuta::fRuta_CODFieldsBeginToChange(TObject *Sender)
{
	ChangeArenaState(false);

	DisableSelectLocBilet();
}
// ---------------------------------------------------------------------------



void __fastcall TfSelRuta::qsT0RUTABeforeClose(TDataSet *DataSet)
{
	qsBroni->Close();
}
// ---------------------------------------------------------------------------


void __fastcall TfSelRuta::pgcChanging(TObject *Sender, bool &AllowChange)
{
	if (dmCassa->isCassaPerron)
	{
		ShowMessage(fMain->LS->Text["noperron"]);
		AllowChange = false;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfSelRuta::actRutaplecatExecute(TObject *Sender)
{
	dmCassa->PrintListImb(int(qsT0RUTA->FieldByName("DATA")->AsDateTime),
		qsT0RUTA->FieldByName("CODU")->AsString, 0);
	dmCassa->StopPerronRUTA(qsT0RUTA->FieldByName("CODU")->AsString,
		int(qsT0RUTA->FieldByName("DATA")->AsDateTime), 1);
	qsDirect->Refresh();
}
// ---------------------------------------------------------------------------

void __fastcall TfSelRuta::qsT0RUTAAfterOpen(TDataSet *DataSet)
{
	if (!qsT0RUTA->RecordCount)
	{
		lbArena->Caption = LS->Text["nothing_found"];
		lbArena->Left = (pnlComplex->ClientWidth - lbArena->Width) / 2;
		lbArena->Top = (pnlComplex->ClientHeight - lbArena->Height) / 2;
	}
	OpenBroni();
}
// ---------------------------------------------------------------------------

bool __fastcall TfSelRuta::CheckBroni()
{
	broniCasaLenta = qsBroni->FieldByName("idcasalenta")->AsInteger;
	broniInternTip = qsBroni->FieldByName("TIPBRONI")->AsInteger;
	if (!broniCasaLenta)
		return false;
	int nStarea = qsBroni->FieldByName("starea")->AsInteger;
	if (nStarea != 0 && nStarea != 4)
	{
		ShowMessage(fMain->LS->Text["noactivebroni"]);
		return false;
	}
	return true;
}
// ---------------------------------------------------------------------------

void __fastcall TfSelRuta::btnBroniLaPlataClick(TObject *Sender)
{
	if (!CheckBroni())
		return;
	broniButton = btnBroniLaPlata;
	ModalResult = mrOk;
}
// ---------------------------------------------------------------------------
void __fastcall TfSelRuta::btnReturnOnlineClick(TObject *Sender)
{
	broniCasaLenta = qsBroni->FieldByName("idcasalenta")->AsInteger;
	broniButton = btnReturnOnline;
	ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TfSelRuta::btnBroniLaRestitClick(TObject *Sender)
{
	if (!CheckBroni() || MessageDlg(fMain->LS->Text["otmbroni"], mtConfirmation,
		TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes)
		return;
	broniButton = btnBroniLaRestit;
	ModalResult = mrOk;
}
// ---------------------------------------------------------------------------

void __fastcall TfSelRuta::qsBroniAfterScroll(TDataSet *DataSet)
{
	if (!qsBroni->RecordCount ||
		qsBroni->ControlsDisabled() ||
		!ArenaPlaces ||
		ArenaPlaces->Suspended ||
		ArenaPlaces->HasSectors && !ArenaPlaces->ActiveSector)
        return;

	RedrawArena();
}
// ---------------------------------------------------------------------------


void __fastcall TfSelRuta::FormClose(TObject *Sender, TCloseAction &Action)
{
	SuspendArena();
}
// ---------------------------------------------------------------------------
void __fastcall TfSelRuta::SuspendArena()
{
	ImageTemplateName = "";
	if (ArenaPlaces)
		ArenaPlaces->Suspend();
}
// ---------------------------------------------------------------------------

void __fastcall TfSelRuta::cbxBroniClick(TObject *Sender)
{
	dmCassa->isBroni = cbxBroni->Checked;

	fVinz->cbxBroni->Checked = cbxBroni->Checked;
	fVinz->pnlBroni->Visible = cbxBroni->Checked;
	pnlBroni->Visible = cbxBroni->Checked;

	OpenBroni();

	if (dmCassa->isBroni)
	{
		dbgrComplex->Align = alTop;
		spBroni->Align = alTop;
		pnlBroni->Align = alClient;

		spBroni->Visible = true;
	}
	else
	{
		pnlBroni->Align = alBottom;
		spBroni->Align = alBottom;
		dbgrComplex->Align = alClient;

		spBroni->Visible = false;
	}

	freeSel();
    UnlockLockedPlaces();
	RedrawArena();
}
// ---------------------------------------------------------------------------
void __fastcall TfSelRuta::OpenBroni()
{
	//if (dmCassa->isBroni)
	//{
		qsBroni->ParamByName("autobus")->AsString = qsT0RUTAAUTOBUS->AsString;
		qsBroni->ParamByName("tip")->AsString = qsT0RUTATIP->AsString;

		qsBroni->ParamByName("ruta")->AsString = qsT0RUTACODU->AsString;
		qsBroni->ParamByName("data")->AsDateTime = qsT0RUTADATA->AsDateTime;

		SetFreeLocSectorParams(qsBroni);

		if (qsBroni->Active)
			qsBroni->Refresh();
		else
			qsBroni->Open();
	//}
}
// ---------------------------------------------------------------------------

void __fastcall TfSelRuta::meCntBltKeyDown(TObject *Sender, WORD &Key,
	TShiftState Shift)
{
	if (Key == VK_UP)
		btPlusBlt->Click();
  else if (Key == VK_DOWN)
			btMinusBlt->Click();
}
// ---------------------------------------------------------------------------

void __fastcall TfSelRuta::meCntBltChange(TObject *Sender)
{
	if (ArenaPlaces == NULL || ArenaPlaces->ActiveSector == NULL /*|| !ArenaPlaces->ActiveSector->IsStandSector*/)
		return;

	maxNMB = _wtoi(meCntBlt->Text.c_str());

	try
	{
		// Óìåíüøåíèå êîë-âà âûáðàííûõ ìåñò
		while (countSel > maxNMB)
		{
			for (int i = 0; i < RowList->Count; i++)
			{
				for (int j = 0; j < RowList->Items[i]->Count; j++)
				{
					TPlace* Place = RowList->Items[i]->Places[j];

					if (Place->State == pstSelected)
					{
						countSel--;
						UnlockPlace(qsT0RUTACODU->AsString, qsT0RUTADATA->AsDateTime, Place);


						if (countSel <= maxNMB)
							return;

						if (countSel == 0)
						{
							maxNMB = countSel;
							meCntBlt->Text = (String)maxNMB;
							return;
						}
					}
				}
			}

			break;
		}

		// Óâåëè÷åíèå êîë-âà âûáðàííûõ ìåñò
		while (countSel < maxNMB)
		{
			bool found = false;
			for (int i = 0; i < RowList->Count && !found; i++)
			{
				for (int j = 0; j < RowList->Items[i]->Count && !found; j++)
				{
					TPlace* Place = RowList->Items[i]->Places[j];

					if (Place->State != pstFree)
						continue;

					String ResultMsg;
					int Result = LockPlace(qsT0RUTACODU->AsString, qsT0RUTADATA->AsDateTime, Place, ResultMsg);
					if (Result == 0) // Óñïåøíîå çàíÿòèå ìåñòà
					{
						countSel++;
						found = true;
						break;
					}
				}
			}

			if (!found)
			{
				// Íåò ñâîáîäíûõ ìåñò
				maxNMB = countSel;
				meCntBlt->Text = (String)maxNMB;
				break;
			}

		}
	}
	__finally
	{
		RedrawArena();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TfSelRuta::pnlComplexResize(TObject *Sender)
{
	lbArena->Left = (pnlComplex->ClientWidth - lbArena->Width) / 2;
	lbArena->Top = (pnlComplex->ClientHeight - lbArena->Height) / 2;

	int nOffset = imgMainSchema->Left;
	imgMainSchema->Left = pnlComplex->Width - imgMainSchema->Width;
	nOffset -= imgMainSchema->Left;
	imgSelection->Left -= nOffset;

	if (ArenaPlaces)
	{
		ArenaPlaces->ImgResize(imgArena, pnlComplex->ClientWidth , pnlComplex->ClientHeight - lbHeader->Height - lbDetail->Height);

		if(imgArena->Top < lbHeader->Height)
			imgArena->Top = lbHeader->Height ;
		pnlComplex->HorzScrollBar->Range = imgArena->Width;
		pnlComplex->VertScrollBar->Range = imgArena->Height + lbHeader->Height + lbDetail->Height;

	}
}
// ---------------------------------------------------------------------------

void __fastcall TfSelRuta::dbgrComplexDrawColumnCell(TObject *Sender,
	const TRect &Rect, int DataCol, TColumn *Column, TGridDrawState State)
{
	if (State.Contains(gdFocused))
	{
		dbgrComplex->DefaultDrawColumnCell(Rect, DataCol, Column, State);
		return;
	}

	TDateTime d = StrToTime("13");

	if (Column->FieldName == "day_name")
	{
		if (dbgrComplex->DataSource->DataSet->FieldByName("is_day_off")->AsInteger)
			dbgrComplex->Canvas->Brush->Color = clRed; // Âûõîäíîé
		else
			dbgrComplex->Canvas->Brush->Color = TColor(16491099); // Áóäíèé
	}
	else
	{
		if (!dbgrComplex->DataSource->DataSet->FieldByName("time_in")->IsNull
			&& dbgrComplex->DataSource->DataSet->FieldByName("time_in")->AsDateTime >= d)
			dbgrComplex->Canvas->Brush->Color = clGreen; // Ïîñëå îáåäà
		else
			dbgrComplex->Canvas->Brush->Color = clWhite; // Äî îáåäà
	}

	dbgrComplex->DefaultDrawColumnCell(Rect, DataCol, Column, State);
}
// ---------------------------------------------------------------------------

void __fastcall TfSelRuta::ResyncQuery(TSmartQuery* q)
{
	TBookmark pBookmark = q->GetBookmark();
	q->DisableControls();

	q->Close();
	q->Open();

	q->GotoBookmark(pBookmark);
	q->FreeBookmark(pBookmark);

	q->EnableControls();
}
// ---------------------------------------------------------------------------

void __fastcall TfSelRuta::LangCbChange(TObject *Sender)
{
	dmLang->LM->UnLanguage = (TUnLanguage)LangCb->ItemIndex;
	dmLang->LM->AfterSetLanguage(Sender);

	RedrawArena();
}
// ---------------------------------------------------------------------------

void __fastcall TfSelRuta::FormResize(TObject *Sender)
{
	btCancel->Left = this->ClientWidth - btCancel->Width - 30;
	btOk->Left = btCancel->Left - btOk->Width - 10;
}
// ---------------------------------------------------------------------------

void __fastcall TfSelRuta::btPlusBltClick(TObject *Sender)
{
	int n = _wtoi(meCntBlt->Text.c_str()) + 1;
	if (n <= 999)
		meCntBlt->Text = String(n);
	meCntBlt->SetFocus();
}
// ---------------------------------------------------------------------------

void __fastcall TfSelRuta::btMinusBltClick(TObject *Sender)
{
	int n = _wtoi(meCntBlt->Text.c_str()) - 1;
	if (n >= 0)
		meCntBlt->Text = String(n);
	meCntBlt->SetFocus();
}
// ---------------------------------------------------------------------------

void TfSelRuta::ZoomArena(double nZoomLevel)
{
	if (!ArenaPlaces)
		return;

	//ArenaPlaces->ZoomLevel += nZoomLevel;

	if (ArenaPlaces->ZoomLevel + nZoomLevel < 0.6 || ArenaPlaces->ZoomLevel + nZoomLevel > 10)
	{
		//ArenaPlaces->ZoomLevel -= nZoomLevel;
		return;
	}

  if (pnlComplex->HorzScrollBar->IsScrollBarVisible())
		pnlComplex->HorzScrollBar->Position = 0;

	if (pnlComplex->VertScrollBar->IsScrollBarVisible())
		pnlComplex->VertScrollBar->Position = 0;

	ArenaPlaces->ZoomLevel += nZoomLevel;
	ArenaPlaces->ImgResize(imgArena, pnlComplex->ClientWidth , pnlComplex->ClientHeight - lbHeader->Height - lbDetail->Height);

	int h_pos = pnlComplex->HorzScrollBar->Position;
	int v_pos = pnlComplex->VertScrollBar->Position;

	double h_rng_coef = (double)imgArena->Width / pnlComplex->HorzScrollBar->Range;
	double v_rng_coef = (double)imgArena->Height / pnlComplex->VertScrollBar->Range;

	pnlComplex->HorzScrollBar->Range = imgArena->Width;
	pnlComplex->VertScrollBar->Range = imgArena->Height + lbHeader->Height + lbDetail->Height;

	imgArena->Top = lbHeader->Height ;

	if (pnlComplex->HorzScrollBar->IsScrollBarVisible())
	{
		pnlComplex->HorzScrollBar->Position = 0;
		imgArena->Left = 0;

		int h_offset = h_pos * h_rng_coef - h_pos;
		pnlComplex->HorzScrollBar->Position = h_pos + h_offset;
	}
	if (pnlComplex->VertScrollBar->IsScrollBarVisible())
	{
		pnlComplex->VertScrollBar->Position = 0;

		if (!v_pos)
			v_pos = 1;

		int v_offset = v_pos * v_rng_coef - v_pos;
		pnlComplex->VertScrollBar->Position = v_pos + v_offset;
	}

	SpinEdit1->OnChange = NULL;
	SpinEdit1->Value = (int)(ArenaPlaces->ZoomLevel*100);
	SpinEdit1->OnChange = SpinEdit1Change;
}
// ---------------------------------------------------------------------------

void __fastcall TfSelRuta::btZoomInClick(TObject *Sender)
{
	ZoomArena(0.2);
}
// ---------------------------------------------------------------------------
void __fastcall TfSelRuta::FormShow(TObject *Sender)
{
	lbArena->Caption = LS->Text["please_wait"];
	lbArena->Left = (pnlComplex->ClientWidth - lbArena->Width) / 2;
	lbArena->Top = (pnlComplex->ClientHeight - lbArena->Height) / 2;

	SpinEdit1->OnChange = NULL;
	SpinEdit1->Value = (int)(ArenaPlaces->ZoomLevel*100);
	SpinEdit1->OnChange = SpinEdit1Change;
}
// ---------------------------------------------------------------------------
void __fastcall TfSelRuta::imgArenaMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	SelectionActive = false;
  if (dmCassa->isAdmin && GetKeyState(VK_SHIFT) < 0)
  {
	ShowMessage((String)"X = " + X + " Y = " + Y);
	return;
  }

  if (IsSectorSchema && IsMainMenu)
  {
	SetActiveSector(ArenaPlaces->FindSector(imgArena, X, Y));
		SetCbSector(ArenaPlaces->FindSector(imgArena, X, Y));
  }
  else
  {
	if (ArenaPlaces->ActiveSector != NULL && ArenaPlaces->ActiveSector->IsStandSector)
        return;

	SelectionActive = true;
	imgRectangle->BoundsRect = imgArena->BoundsRect;
	imgRectangle->Canvas->Pen->Color = clBlack;
	imgRectangle->Canvas->Pen->Style = psDot;
	imgRectangle->Canvas->Brush->Style = bsSolid;
	imgRectangle->Canvas->FillRect(imgRectangle->Canvas->ClipRect);
	imgRectangle->Visible = true;
  }

	ArenaPlaces->MouseDownLeftPos.x = X / DeltaX(fSelRuta->imgArena);
	ArenaPlaces->MouseDownLeftPos.y = Y / DeltaY(fSelRuta->imgArena);

}

//---------------------------------------------------------------------------
void __fastcall TfSelRuta::SetActiveSector(TSector* Sector)
{
	if (Sector == NULL || Sector == ArenaPlaces->ActiveSector)
		return;

    bool WasMainMenu = IsMainMenu;

	 if (WasMainMenu)
	 {
		IsMainMenu = false;
		btnSchemaBack->Visible = true;

		if (!bmpMainSchema)
			bmpMainSchema = new TPngImage();
		bmpMainSchema->Assign(bmpArena);
		ArenaPlaces->bmpMainMenuSchema = bmpMainSchema;
	 }

	  GetImageFromSources(Sector->ImageName, bmpArena);
	  ArenaPlaces->GoToSector(Sector, RowList);

	  OpenBroni();

	  if (!qsFreeLoc->Active)
	  	qsFreeLoc->Open();
	  freeSel();

	  RedrawArena();
		ArenaPlaces->ImgResize(imgArena, pnlComplex->ClientWidth, pnlComplex->ClientHeight);
	  ChangeArenaState(true);

	  imgMainSchema->Picture->Assign(bmpMainSchema);
	  if (WasMainMenu)
	  {
			ArenaPlaces->ImgResize(imgMainSchema, imgMainSchema->Width, imgMainSchema->Height);
		  imgMainSchema->Left = pnlComplex->Width - imgMainSchema->Width;
		  imgMainSchema->Top = 0;
		  imgMainSchema->Visible = true;
	  }

	  ArenaPlaces->ShowSectorMenu(Sector);
	  UpdateMainSelection(Sector);

	  lbBilCnt->Visible = true;
	  btMinusBlt->Visible = true;
	  meCntBlt->Visible = true;
	  btPlusBlt->Visible = true;
	  meCntBlt->Text = "0";
      meCntBlt->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TfSelRuta::UpdateMainSelection(TSector* Sector)
{
	if (!Sector)
		return;
	((TGIFImage*)imgSelection->Picture->Graphic)->Animate = false;
	imgSelection->Visible = false;

	imgSelection->Left = imgMainSchema->Left + Sector->X * DeltaX(imgMainSchema) - imgSelection->Width / 2;
	imgSelection->Top = imgMainSchema->Top + Sector->Y * DeltaY(imgMainSchema) - imgSelection->Height / 2;

	((TGIFImage*)imgSelection->Picture->Graphic)->AnimateLoop = glEnabled;
	((TGIFImage*)imgSelection->Picture->Graphic)->Animate = true;
	imgSelection->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TfSelRuta::pnlComplexMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
  if(ArenaPlaces)
    ArenaPlaces->HideCursor();
}
//---------------------------------------------------------------------------
void __fastcall TfSelRuta::GoToMainSchema()
{
	this->IsMainMenu = true;
	btnSchemaBack->Visible = false;

	lbBilCnt->Visible = false;
	btMinusBlt->Visible = false;
	meCntBlt->Visible = false;
	btPlusBlt->Visible = false;

	bmpArena->Assign(bmpMainSchema);
	ArenaPlaces->GoToMainSchema(RowList);
	OpenBroni();
	freeSel();

	RedrawArena();
	ArenaPlaces->ImgResize(imgArena, pnlComplex->ClientWidth, pnlComplex->ClientHeight);
	ChangeArenaState(true);
	SetMainMenuVisible(false);

	ArenaPlaces->HideSectorMenu();
}
//---------------------------------------------------------------------------
void __fastcall TfSelRuta::SetMainMenuVisible(bool bVisible)
{
	imgMainSchema->Visible = bVisible;
	imgSelection->Visible = bVisible;

	TGIFImage* Gif = (TGIFImage*)imgSelection->Picture->Graphic;
	if (bVisible)
		Gif->AnimateLoop = glEnabled;
	else
		Gif->AnimateLoop = glDisabled;
	Gif->Animate = bVisible;
}
//---------------------------------------------------------------------------
void __fastcall TfSelRuta::imgArenaMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{
	if (!ArenaPlaces)
	return;

	if (Shift.Contains(ssLeft))
  {
	int x_offset = (X - ArenaPlaces->MouseDownLeftPos.x);
	int y_offset = (Y - ArenaPlaces->MouseDownLeftPos.y);

	  /* ìåøàåò ïðè çóìå âûáèðàòü ìíîæåñòâåííûå ïîçèöèè
    if (pnlComplex->HorzScrollBar->IsScrollBarVisible())
	  pnlComplex->HorzScrollBar->Position -= x_offset;
    if (pnlComplex->VertScrollBar->IsScrollBarVisible())
		pnlComplex->VertScrollBar->Position -= y_offset;
    */

	if (SelectionActive && ArenaPlaces && (!IsSectorSchema || (IsSectorSchema && !IsMainMenu)))
	{
		static int l_r = 1;
		static int l_b = 1;

		int r = X;
		int b = Y;
		/*
		int l = ArenaPlaces->MouseDownLeftPos.x;
		int t = ArenaPlaces->MouseDownLeftPos.y;
    */
		int l = ArenaPlaces->MouseDownLeftPos.x * DeltaX(fSelRuta->imgArena);
		int t = ArenaPlaces->MouseDownLeftPos.y * DeltaY(fSelRuta->imgArena);

		if (r < 1)
			r = 1;
		else if (r > imgRectangle->Width)
		r = imgRectangle->Width;
		if (b < 1)
			b = 1;
		else if (b > imgRectangle->Height)
			b = imgRectangle->Height;

		if (r != l_r || b != l_b)
		{
			l_r = r;
			l_b = b;
			imgRectangle->BringToFront();
			imgRectangle->Canvas->FillRect(imgRectangle->Canvas->ClipRect);
			imgRectangle->Canvas->Rectangle(l, t, r, b);
		}

	}
  }
	else if (fPrintSetup->ShowPlaceHint &&
 (ArenaPlaces && ArenaPlaces->ActiveSector || !ArenaPlaces->HasSectors))
  {
	if (ArenaPlaces->ActiveSector != NULL && ArenaPlaces->ActiveSector->IsStandSector)
        return;

  	static TPlace* LastPlace = NULL;
	TPlace* Place = ArenaPlaces->FindPlace(imgArena, X, Y);

	if (Place && Place != LastPlace)
	{

		BalloonHint->Title = "";
		if (Place->State == pstSelected)
			BalloonHint->Title += LS->Text["selected_place"];
		if (Place->State == pstReserved)
			BalloonHint->Title += LS->Text["bought_place"];
		else if (Place->State == pstBookPaid)
			BalloonHint->Title += LS->Text["booking"] + " " +  LS->Text["payed"] + " #" + Place->Casalenta;
		else if (Place->State == pstBookUnpaid)
			BalloonHint->Title += LS->Text["booking"] + " " + LS->Text["unpaid"] + " #" + Place->Casalenta;
		else if (Place->State == pstSubscribed)
			BalloonHint->Title += "Àáîíåìåíò";
		else if (Place->State == pstSelectedByOther)
		{
			BalloonHint->Title += LS->Text["occupied"];
			if (Place->ActionState == lpstPrint)
				BalloonHint->Title += " (" + LS->Text["printing"] + ")";
		}

		if (Place->State != pstFree && Place->State != pstSelected)
		{
			if (Place->Cashier != "" || Place->Username != "")
			{
				if (Place->Cashier != "")
					BalloonHint->Title += "\n" + LS->Text["cashbox"] + ": " + Place->Cashier;
				if (Place->Username != "")
					BalloonHint->Title += "\n"+ LS->Text["user"] +": " + Place->Username;
			}
		}

		if (Place->State != pstFree)
			BalloonHint->Title += "\n";

		BalloonHint->Title += LS->Text["row"]+ ": " + Place->Row + "\n"+LS->Text["place"]+ ": "+ Place->Nr;
		BalloonHint->HideAfter = 5000;
		TPoint Point;
		Point = imgArena->ClientToScreen(Point);
		Point.X += Place->X * DeltaX(fSelRuta->imgArena) + 12;
		Point.Y += Place->Y * DeltaY(fSelRuta->imgArena);
		BalloonHint->ShowHint(Point);
	}
	else if (!Place)
	{
		BalloonHint->HideHint();
    }
	LastPlace = Place;
  }

	int delta_x = X / DeltaX(fSelRuta->imgArena);
	int delta_y = Y / DeltaY(fSelRuta->imgArena);
	try
	{
		ArenaPlaces->MoveCursor(delta_x, delta_y);
	}
	catch(...)
  {}

}
//---------------------------------------------------------------------------
void __fastcall TfSelRuta::imgMainSchemaMouseDown(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y)
{
	SetActiveSector(ArenaPlaces->FindSector(imgMainSchema, X, Y));
	SetCbSector(ArenaPlaces->FindSector(imgMainSchema, X, Y));
}
//---------------------------------------------------------------------------

void __fastcall TfSelRuta::imgSelectionMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	imgMainSchemaMouseDown(this, mbLeft, TShiftState(),
	  X + imgSelection->Left - imgMainSchema->Left,
	  Y + imgSelection->Top - imgMainSchema->Top);
}
//---------------------------------------------------------------------------

void __fastcall TfSelRuta::qsT0RUTABeforeScroll(TDataSet *DataSet)
{
	qsFreeLoc->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfSelRuta::imgArenaMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	if (!SelectionActive)
		return;

	bool bCtrl = GetKeyState(VK_LCONTROL) < 0; // Ctrl çàæàò;

	SelectionActive = false;
	imgRectangle->Visible = false;

	ArenaPlaces->MouseDownLeftPos.x *= DeltaX(imgArena);
	ArenaPlaces->MouseDownLeftPos.y *= DeltaY(imgArena);

	TSpotParams* Params = ArenaPlaces->GetActiveSpotParams();
	int r = Params->VisibleRadius;
	int x_offset = abs(ArenaPlaces->MouseDownLeftPos.x - X);
	int y_offset = abs(ArenaPlaces->MouseDownLeftPos.y - Y);

	if (x_offset < r * 1.7 && y_offset < r * 1.7)
	{
		TPlace* Place = ArenaPlaces->FindPlace(imgArena, X, Y);

		if (Place)
		{
			if (dmCassa->isAdmin && GetKeyState(VK_MENU) < 0)
			{
				String sPlaceInfo = "Place:\n";
				sPlaceInfo += "AbsNr = " + (String)Place->AbsNr + "\n\n"
					"Nr = " + Place->Nr + "\n"
					"Row = " + Place->Row + "\n"
					"X = " + Place->X + "\n"
					"Y = " + Place->Y + "\n"
					"Price = " + Place->Price + "\n\n"
					"State = " + Place->State + "\n"
					"Casalenta = " + Place->Casalenta + "\n";
				ShowMessage(sPlaceInfo);
				return;
			}

			if (qsFreeLoc->Locate("LOCLIBER", Place->AbsNr, TLocateOptions())) // Çàíÿòèå ìåñòà
			{
				setSel(Place);
			}
			else if (Place->State == pstBookUnpaid || Place->State == pstBookPaid) // Ïîçèöèîíèðîâàíèå íà áðîíè
			{
				qsBroni->Locate("idcasalenta", Place->Casalenta, TLocateOptions());
			}
		}
		return;
	}

	if (!bCtrl)
	{
		for (int i = 0; i < RowList->Count; i++)
			for (int j = 0; j < RowList->Items[i]->Count; j++)
			{
				TPlace* Place = RowList->Items[i]->Places[j];
				if (Place->State == pstSelected)
					setSel(Place, false);
          	}
	}

	int left = Math::Min(ArenaPlaces->MouseDownLeftPos.x, X);
	int top = Math::Min(ArenaPlaces->MouseDownLeftPos.y, Y);
	int right = Math::Max(ArenaPlaces->MouseDownLeftPos.x, X);
	int bottom = Math::Max(ArenaPlaces->MouseDownLeftPos.y, Y);

	for (int x = left; x < right; x += r)
	  for (int y = top; y < bottom; y += r)
	  {
		TPlace* Place = ArenaPlaces->FindPlace(imgArena, x, y);
		if (Place && Place->State == psFree)
			setSel(Place, false);
	  }


	RedrawArena();
}
//---------------------------------------------------------------------------

void __fastcall TfSelRuta::Action1Execute(TObject *Sender)
{
	ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TfSelRuta::FormDestroy(TObject *Sender)
{
	UnlockLockedPlaces();
	delete imgRectangle;
}
//---------------------------------------------------------------------------

void __fastcall TfSelRuta::lbHeaderMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	int rel_x = X - imgArena->Left;
	int rel_y = Y - imgArena->Top;
	if (!rel_x || !rel_y)
		return;

	// Ïåðåíàïðàâëåíèå êëèêà â ñëó÷àå åñëè íàäïèñü ïåðåêðûâàåò èçîáðàæåíèå
	imgArenaMouseDown(Sender, Button, Shift, rel_x, rel_y);
}
//---------------------------------------------------------------------------

void __fastcall TfSelRuta::lbHeaderMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	int rel_x = X - imgArena->Left;
	int rel_y = Y - imgArena->Top;
	if (!rel_x || !rel_y)
		return;

	// Ïåðåíàïðàâëåíèå êëèêà â ñëó÷àå åñëè íàäïèñü ïåðåêðûâàåò èçîáðàæåíèå
	imgArenaMouseUp(Sender, Button, Shift, rel_x, rel_y);
}
//---------------------------------------------------------------------------

void __fastcall TfSelRuta::lbHeaderMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	int rel_x = X - imgArena->Left;
	int rel_y = Y - imgArena->Top;
	if (!rel_x || !rel_y)
		return;

	// Ïåðåíàïðàâëåíèå êëèêà â ñëó÷àå åñëè íàäïèñü ïåðåêðûâàåò èçîáðàæåíèå
	imgArenaMouseMove(Sender, Shift, rel_x, rel_y);
}
//---------------------------------------------------------------------------
void __fastcall TfSelRuta::FormHide(TObject *Sender)
{
	BalloonHint->HideHint();
}
//---------------------------------------------------------------------------

void __fastcall TfSelRuta::FormDeactivate(TObject *Sender)
{
	BalloonHint->HideHint();
}
//---------------------------------------------------------------------------

void __fastcall TfSelRuta::imgMainSchemaMouseEnter(TObject *Sender)
{
	imgMainSchema->Width = 449;
	imgMainSchema->Height = 350;
	ArenaPlaces->ImgResize(imgMainSchema, imgMainSchema->Width, imgMainSchema->Height);
	imgMainSchema->Left = pnlComplex->Width - imgMainSchema->Width;
	imgMainSchema->Top = 0;
	UpdateMainSelection(ArenaPlaces->ActiveSector);
}
//---------------------------------------------------------------------------
void __fastcall TfSelRuta::imgArenaMouseEnter(TObject *Sender)
{
	imgMainSchema->Width = 307;
	imgMainSchema->Height = 240;
	ArenaPlaces->ImgResize(imgMainSchema, imgMainSchema->Width, imgMainSchema->Height);
	imgMainSchema->Left = pnlComplex->Width - imgMainSchema->Width;
	imgMainSchema->Top = 0;
	if (!imgMainSchema->Visible)
		return;
	UpdateMainSelection(ArenaPlaces->ActiveSector);
}
//---------------------------------------------------------------------------

void __fastcall TfSelRuta::lbHeaderMouseEnter(TObject *Sender)
{
	imgArenaMouseEnter(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TfSelRuta::lbDetailMouseEnter(TObject *Sender)
{
	imgArenaMouseEnter(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TfSelRuta::pnlComplexMouseEnter(TObject *Sender)
{
	imgArenaMouseEnter(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TfSelRuta::btnSchemaBackClick(TObject *Sender)
{
  fSelRuta->cbSectors->ItemIndex = -1;
	GoToMainSchema();
}
//---------------------------------------------------------------------------

void __fastcall TfSelRuta::btnFindBookClick(TObject *Sender)
{
	if (ArenaPlaces == NULL)
	{
		ShowMessage(LS->Text["arena_is_null"]);
		return;
	}

	String Val;
	while (InputQuery(LS->Text["input_booking_nr"], LS->Text["booking_search"], Val))
	{
		qsBroniSearch->ParamByName("idcasalenta")->AsString = Val;
		qsBroniSearch->Open();

		try
		{
			if (qsBroniSearch->RecordCount == 0)
			{
				ShowMessage(LS->Text["book_not_found"]);
				continue;
			}

			String Ruta = qsBroniSearch->FieldByName("ruta")->AsString;
			String Data = qsBroniSearch->FieldByName("data")->AsString;

			fRuta_COD->Enabled = false;
			qsT0RUTA->DisableControls();
			TBookmark Bookmark = qsT0RUTA->GetBookmark();
			try
			{
				bool found = false;
				for (qsT0RUTA->First(); !qsT0RUTA->Eof; qsT0RUTA->Next())
				{
					String CmpRuta = qsT0RUTA->FieldByName("codu")->AsString;
					String CmpData = qsT0RUTA->FieldByName("data")->AsString;

					if (Ruta == CmpRuta && Data == CmpData)
					{
						found = true;
						break;
					}
				}

				if (!found)
				{
					qsT0RUTA->GotoBookmark(Bookmark);
					ShowMessage(LS->Text["session_not_found"] + " " + Ruta + ", " + Data);
					continue;
				}
			}
			__finally
			{
				qsT0RUTA->FreeBookmark(Bookmark);
				qsT0RUTA->EnableControls();
			}

			fRuta_CODFieldsBeginToChange(qsT0RUTA);
			fRuta_CODFieldsChange(qsT0RUTA);

			int SectorNr = qsBroniSearch->FieldByName("sector_nr")->AsInteger;
			TSector* Sector = ArenaPlaces->GetSectorByNr(SectorNr);
			if (Sector == NULL)
			{
				ShowMessage(LS->Text["sector_not_found"] + " " + (String)SectorNr);
				continue;
			}

			SetActiveSector(Sector);
			SetCbSector(Sector);

			qsBroni->Locate("idcasalenta", Val, TLocateOptions());

            break;
		}
		__finally
		{
			qsBroniSearch->Close();
			fRuta_COD->Enabled = true;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TfSelRuta::btnBookShowAllClick(TObject *Sender)
{
 	qsBroni->ParamByName("sector_selection")->AsString = "";
 	qsBroni->ParamByName("sec")->AsString = "";

	if (qsBroni->Active)
		qsBroni->Refresh();
	else
		qsBroni->Open();
}
//---------------------------------------------------------------------------

void __fastcall TfSelRuta::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Shift.Contains(ssAlt))
	{
		switch (Key)
		{
			case 'B':
                cbxBroni->Checked = !cbxBroni->Checked;
				break;
			case 'S':
                btnBookShowAll->Click();
				break;
			case 'X':
				btnFindBook->Click();
				break;
			case 'P':
				btnBroniLaPlata->Click();
				break;
			case 'T':
                btnBroniLaRestit->Click();
				break;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TfSelRuta::cbSectorsChange(TObject *Sender)
{
	//if( cbSectors->ItemIndex > -1)
	SetActiveSector((TSector*)cbSectors->Items->Objects[cbSectors->ItemIndex]);
}
//---------------------------------------------------------------------------
void __fastcall TfSelRuta::SetCbSector(TSector *ASector)
{
	if( !ASector )
		return;
	for (int i = 0; i < cbSectors->Items->Count; i++) {
		TSector* Sector = (TSector*)cbSectors->Items->Objects[i];

		if( ASector->Nr == Sector->Nr && ASector->Text == Sector->Text)
		{
			cbSectors->ItemIndex = i;
			break;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TfSelRuta::AddSelResize(TObject *Sender)
{
	ArenaPlaces->AddSelResize(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TfSelRuta::SpinEdit1Change(TObject *Sender)
{
	if( (double)ArenaPlaces->ZoomLevel > 0 && (double)SpinEdit1->Value > 0)
	{
		double lZoomLevel;
		/*
		double lZoomLevel = -(ArenaPlaces->ZoomLevel-(double)(SpinEdit1->Value)/100);
		if( lZoomLevel != 0)
			ZoomArena(lZoomLevel);
		*/
		if( ArenaPlaces->ZoomLevel*100 > SpinEdit1->Value)
			lZoomLevel = -0.01;
		else
			lZoomLevel = 0.01;

		ZoomArena(lZoomLevel);
	}
}
//---------------------------------------------------------------------------
void __fastcall TfSelRuta::btZoomOutClick(TObject *Sender)
{
	ZoomArena(-0.2);
}
//---

void  TfSelRuta::_setSelectBroniQuery()
{
	dmCassa->qq->SQL->Text = "select sablonf1 from xsablons "
	"where sabloncod = 'cassa_broni_list_request' and versionid = 320";
	dmCassa->qq->Open();
	if (!dmCassa->qq->Eof)
	{
			TStream* stream = dmCassa->qq->CreateBlobStream(dmCassa->qq->Fields->operator[](0), bmRead);

			TStreamReader* reader = new TStreamReader(stream);
			String s = reader->ReadToEnd();
			if (!s.IsEmpty())
			{
				qsBroni->SQL->Text = s;
			}
			reader->DisposeOf();
			stream->DisposeOf();
	}
	dmCassa->qq->Close();
}
