//---------------------------------------------------------------------------

#pragma hdrstop

#include "uAdditionalInfoLinker.h"
#include <Vcl.Graphics.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include "uDMcassa.h"

TAdditionalInfoLinker::TAdditionalInfoLinker() : TObject()
{
}
TAdditionalInfoLinker::TAdditionalInfoLinker(
					String mainInfoTable, String imageTable) : TObject()
{
	performLink(mainInfoTable, imageTable);
}

int TAdditionalInfoLinker::_getLegendaWidth(TCanvas * canv)
{
	if (linker.empty())
	{
		return 0;
	}
	AddInfoLinkStruct::iterator current_maximum_index = linker.begin();
	int max_text_len = current_maximum_index->second.first.Length();
	AddInfoLinkStruct::iterator liter = linker.begin();
	++liter;
	while (liter != linker.end())
	 {
			if (liter->second.first.Length() > max_text_len)
			{
				max_text_len = liter->second.first.Length();
				current_maximum_index = liter;
			}
			++liter;
	 }
	 int max_image_width = linker.begin()->second.second.second->Width;
	 for (AddInfoLinkStruct::iterator pr = linker.begin(); pr != linker.end(); ++pr)
	 {
			if (pr->second.second.second->Width > max_image_width)
			{
				max_image_width = pr->second.second.second->Width;
			}
	 }
	 return canv->TextWidth(current_maximum_index->second.first)
								+ 10
								+ max_image_width;
}
int TAdditionalInfoLinker::_getLegendaHeight()
{
	 int total_height = 0;
	 for (AddInfoLinkStruct::iterator pr = linker.begin(); pr != linker.end(); ++pr)
	 {
			total_height += pr->second.second.second->Height + 1;
	 }
   return total_height;
}

TPoint TAdditionalInfoLinker::_drawItem(TAdditionalInfoType& currentItem, TPoint currentPoint, TCanvas* img)
{
	img->Draw(currentPoint.x, currentPoint.y, currentItem.second.second);
	TPoint text_point(
		 currentPoint.x + currentItem.second.second->Width + 10,
		 currentPoint.y + 2
	);
	img->TextOut(text_point.x, text_point.y,currentItem.first);
	currentPoint.y = currentPoint.y + currentItem.second.second->Height + 1;
	return currentPoint;
}

void TAdditionalInfoLinker::performLink(String mainInfoTable, String imageTable)
{
		dmCassa->qq->SQL->Text =
		"select denumirea, cod1 from " + mainInfoTable + " "
		"where cod = 320 and tip = 'G0' order by 1";
	dmCassa->qq->Open();
	std::vector<std::pair<int, String> > id_name_binds;
	int temp_id = 0;
	while (!dmCassa->qq->Eof)
	{
			temp_id = dmCassa->qq->Fields->operator[](1)->AsInteger;
			if (temp_id != 0)
			{
				id_name_binds.push_back(std::make_pair(temp_id,
								dmCassa->qq->Fields->operator[](0)->AsString));
			}
			dmCassa->qq->Next();
	}
	dmCassa->qq->Close();

	dmCassa->qq->SQL->Text =
	"select SABLONF1, VERSIONID from "+ imageTable +
		" where SABLONCOD='cassa_addinfo_image_320'";
	dmCassa->qq->Prepare();
	dmCassa->qq->Open();

	std::map<int, TGraphic*> t_map;
	while (!dmCassa->qq->Eof)
	{
			temp_id = dmCassa->qq->Fields->operator[](1)->AsInteger;
			TGraphic* img = new TBitmap();
			TStream * mstream = dmCassa->qq->CreateBlobStream(dmCassa->qq->Fields->operator[](0), bmRead);
			img->LoadFromStream(mstream);
			t_map[temp_id] = img;
			mstream->DisposeOf();
			dmCassa->qq->Next();
	}
	dmCassa->qq->Close();

	dmCassa->qq->SQL->Text =
	"select SABLONF1, VERSIONID from "+ imageTable +
		" where SABLONCOD='cassa_addinfo_icon_320'";
	dmCassa->qq->Prepare();
	dmCassa->qq->Open();
	std::map<int, TGraphic*> i_map;
	while (!dmCassa->qq->Eof)
	{
			temp_id = dmCassa->qq->Fields->operator[](1)->AsInteger;
			TGraphic* img = new TBitmap();
			TStream * mstream = dmCassa->qq->CreateBlobStream(dmCassa->qq->Fields->operator[](0), bmRead);
			img->LoadFromStream(mstream);
			i_map[temp_id] = img;
			mstream->DisposeOf();
			dmCassa->qq->Next();
	}
	dmCassa->qq->Close();
	for (std::vector<std::pair<int, String> > ::iterator tpair = id_name_binds.begin();
						tpair != id_name_binds.end(); ++tpair)
	{
		 insertLink(tpair->first, tpair->second,i_map[tpair->first],
							t_map[tpair->first]);
	}
}
void TAdditionalInfoLinker::insertLink(int id, String text, TGraphic* image, TGraphic* largeImage)
{
	linker[id] = std::make_pair(text, std::make_pair(image, largeImage));
}
String TAdditionalInfoLinker::getName(int id)
{
	return linker[id].first;
}
TGraphic* TAdditionalInfoLinker::getImage(int id)
{
	return linker[id].second.second;
}

TGraphic* TAdditionalInfoLinker::getIcon(int id)
{
	return linker[id].second.first;
}


TAdditionalInfoType& TAdditionalInfoLinker::getAdditionalInfo(int id)
{
	return linker[id];
}

TAdditionalInfoLinker* TAdditionalInfoLinker::_instanse = NULL;
TAdditionalInfoLinker* TAdditionalInfoLinker::instanse()
{
	if (_instanse == NULL)
	{
	 _instanse = new TAdditionalInfoLinker();
	}
	return _instanse;
}
void TAdditionalInfoLinker::init(String mainInfoTable, String imageTable)
{
	if (_instanse == NULL)
	{
	 _instanse  = new TAdditionalInfoLinker(mainInfoTable, imageTable);
	}
	else
		_instanse->performLink(mainInfoTable, imageTable);
}
TStrings * TAdditionalInfoLinker::getAllNames()
{
	 TStrings * container = new TStringList();
	 for (AddInfoLinkStruct::iterator pr = linker.begin(); pr != linker.end(); ++pr)
	 {
			container->Add(pr->second.first);
	 }
	 return container;
}
TImageList* TAdditionalInfoLinker::getAllImages()
{
	TImageList* container = new TImageList(NULL);
	for (AddInfoLinkStruct::iterator pr = linker.begin(); pr != linker.end(); ++pr)
	 {
		container->Add(static_cast<TBitmap*>(pr->second.second.second), NULL);
	 }
	 return container;
}
TImageList * TAdditionalInfoLinker::getAllIcons()
{
	TImageList* container = new TImageList(NULL);
	for (AddInfoLinkStruct::iterator pr = linker.begin(); pr != linker.end(); ++pr)
	 {
		container->Add(static_cast<TBitmap*>(pr->second.second.first), NULL);
	 }
	 return container;

}
TPicture* TAdditionalInfoLinker::getLegendaImage()
{
	TPngImage * img = new TPngImage(2, 16, 1,1);
	img->Resize(_getLegendaWidth(img->Canvas), _getLegendaHeight());
  img->Canvas->FillRect(TRect(0,0,img->Width, img->Height));
	TPoint currentPoint(0,0);
	for (AddInfoLinkStruct::iterator pr = linker.begin(); pr != linker.end(); ++pr)
	{
			currentPoint = _drawItem(pr->second, currentPoint, img->Canvas);
	}
	TPicture * p = new TPicture();
	p->Assign(img);
	return p;
}
