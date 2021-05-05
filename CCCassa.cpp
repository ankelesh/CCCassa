//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("..\SDK\uErrDialog.cpp", fmError);
USEFORM("..\SDK\LangDM.cpp", dmLang); /* TDataModule: File Type */
USEFORM("..\SDK\uGrafikPC.cpp", fGrafikPC);
USEFORM("..\SDK\uPrintSetup.cpp", fPrintSetup);
USEFORM("..\SDK\uMarca.cpp", fMarca);
USEFORM("uzTOAD.cpp", fTOAD);
USEFORM("uVinz.cpp", fVinz);
USEFORM("..\Dispetcher\uPrintListaImb.cpp", fLstImb);
USEFORM("..\Infocassa\uInfoCasa.cpp", fInfoCasa);
USEFORM("..\FastRep\Frdm.cpp", FrDMF); /* TDataModule: File Type */
USEFORM("..\SDK\uUniversGosNom.cpp", fUniversGosNom);
USEFORM("..\SDK\uUnivers.cpp", fUnivList1);
USEFORM("..\SDK\uUsers.cpp", fUsers);
USEFORM("..\SDK\uzOraMsg.cpp", fmOraMsg);
USEFORM("..\SDK\uWordPad.cpp", fWordPad);
USEFORM("..\SDK\uRuta.cpp", fRute);
USEFORM("..\SDK\uRutaAdd.cpp", fRutaAdd);
USEFORM("..\SDK\uSYSS.cpp", fSYSS);
USEFORM("..\SDK\uSelInlesn.cpp", fInlesn);
USEFORM("uControlPerr.cpp", fControlDePerron);
USEFORM("uCheckBroni.cpp", fCheckBroni);
USEFORM("uCustomPrice.cpp", fCustomPrice);
USEFORM("uFindBookedTicket.cpp", fBookedTickets);
USEFORM("uDMcassa.cpp", dmCassa); /* TDataModule: File Type */
USEFORM("uBani.cpp", fBaniiCassa);
USEFORM("uAddSelect.cpp", fAddSel);
USEFORM("uStart.cpp", fStart);
USEFORM("uSelect.cpp", fSelRuta);
USEFORM("uSubscription.cpp", fSubscription);
USEFORM("uTipBilet.cpp", fBiletInput);
USEFORM("uTiparBon.cpp", TiparBonForm);
USEFORM("uMain.cpp", fMain);
USEFORM("uInfoPerute.cpp", fInfoPeRute);
USEFORM("uRest.cpp", fRest);
USEFORM("uSaledTicks.cpp", fSaledTickets);
USEFORM("uRetiparBil.cpp", fRetiparBil);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = false;
		Application->CreateForm(__classid(TdmLang), &dmLang);
		Application->CreateForm(__classid(TFrDMF), &FrDMF);
		Application->CreateForm(__classid(TdmCassa), &dmCassa);
		Application->CreateForm(__classid(TfMain), &fMain);
		Application->CreateForm(__classid(TfPrintSetup), &fPrintSetup);
		Application->CreateForm(__classid(TfInlesn), &fInlesn);
		Application->CreateForm(__classid(TfUnivList1), &fUnivList1);
		Application->CreateForm(__classid(TfRest), &fRest);
		Application->CreateForm(__classid(TfBaniiCassa), &fBaniiCassa);
		Application->CreateForm(__classid(TfVinz), &fVinz);
		Application->CreateForm(__classid(TfLstImb), &fLstImb);
		Application->CreateForm(__classid(TfRetiparBil), &fRetiparBil);
		Application->CreateForm(__classid(TfSYSS), &fSYSS);
		Application->CreateForm(__classid(TfmOraMsg), &fmOraMsg);
		Application->CreateForm(__classid(TfSelRuta), &fSelRuta);
		Application->CreateForm(__classid(TfAddSel), &fAddSel);
		Application->CreateForm(__classid(TfBookedTickets), &fBookedTickets);
		Application->CreateForm(__classid(TfCustomPrice), &fCustomPrice);
		Application->CreateForm(__classid(TfCheckBroni), &fCheckBroni);
		Application->CreateForm(__classid(TfTOAD), &fTOAD);
		Application->CreateForm(__classid(TTiparBonForm), &TiparBonForm);
		Application->Run();
	}
	catch (EAbort& exception)
	{
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
