//---------------------------------------------------------------------------

#ifndef uAdditionalInfoLinkerH
#define uAdditionalInfoLinkerH
#include <map>
#include <System.Classes.hpp>
#include <Vcl.Graphics.hpp>
#include <vector>
#include <Vcl.Controls.hpp>


typedef std::pair<String, std::pair<TGraphic*, TGraphic*> > TAdditionalInfoType;

class TAdditionalInfoLinker : public TObject
{
private:
	typedef std::map<int, TAdditionalInfoType > AddInfoLinkStruct;
	AddInfoLinkStruct linker;
	static TAdditionalInfoLinker* _instanse;

	TAdditionalInfoLinker();
	TAdditionalInfoLinker(String mainInfoTable, String imageTable);
	int _getLegendaWidth(TCanvas * canvas);
	int _getLegendaHeight();
	TPoint _drawItem(TAdditionalInfoType& currentItem, TPoint currentPoint, TCanvas* img);
public:
	void performLink(String mainInfoTable, String imageTable);
	void insertLink(int id, String text, TGraphic* image, TGraphic* largeImage);
	String getName(int id);
	TGraphic* getIcon(int id);
	TGraphic* getImage(int id);
	TAdditionalInfoType& getAdditionalInfo(int id);
	static TAdditionalInfoLinker* instanse();
	static void init(String mainInfoTable, String imageTable);
	TStrings * getAllNames();
	TImageList* getAllImages();
	TImageList * getAllIcons();
	TPicture* getLegendaImage();
};
//---------------------------------------------------------------------------
#endif

