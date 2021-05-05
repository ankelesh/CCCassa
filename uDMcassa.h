//---------------------------------------------------------------------------

#ifndef uDMcassaH
#define uDMcassaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

//#include "ConfDatabase.h"
#include "SagiQueryLIB.h"
#include "MemDS.hpp"
#include "Ora.hpp"
#include "OraSmart.hpp"
#include "SagiODACSmartQueryLIB.h"
#include <Db.hpp>
#include "MainInstance.hpp"
#include "OraSQLMonitor.hpp"
#include "DBAccess.hpp"
#include "SagiOraSession.h"
#include "DASQLMonitor.hpp"
#include "OdacVcl.hpp"
#include "OraCall.hpp"
//---------------------------------------------------------------------------
class TdmCassa : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *dsBiltets;
        TDataSource *dsV1_CASALENTA;
        TDataSource *dsDocs;
        TDataSource *dsD_Cassa;
        TDataSource *dsCasaTotals;
        TDataSource *dsD_CassaP;
        TSmartQuery *qq;
        TOraStoredProc *spCF;
        TOraStoredProc *spDavaiProd;
        TOraStoredProc *spWonaToSell;
        TSmartQuery *qsDocs;
        TSagiODACSmartQuery *qsD_Cassa;
        TFloatField *qsD_CassaCOD;
        TDateTimeField *qsD_CassaDATA;
        TIntegerField *qsD_CassaISPREDAT;
        TFloatField *qsD_CassaPERS_ID;
        TFloatField *qsD_CassaSUMA;
        TStringField *qsD_CassaPERS_IDT;
        TStringField *qsD_CassaCasir;
        TFloatField *qsDocsCOD;
        TDateTimeField *qsDocsDATAMANUAL;
        TDateTimeField *qsDocsDATA;
        TStringField *qsDocsTIP;
        TIntegerField *qsDocsCODF;
        TIntegerField *qsDocsUSERID;
        TStringField *qsDocsNRMANUAL;
        TSagiODACSmartQuery *qsD_CassaP;
        TFloatField *qsD_CassaPCOD;
        TDateTimeField *qsD_CassaPDATA;
        TIntegerField *qsD_CassaPISPREDAT;
        TFloatField *qsD_CassaPPERS_ID;
        TFloatField *qsD_CassaPSUMA;
        TStringField *qsD_CassaPPERS_IDT;
        TStringField *qsD_CassaPCasir;
        TSmartQuery *qqCheckLockRuta;
				TSagiODACSmartQuery *qsV1_CASALENTA;
        TIntegerField *qsV1_CASALENTAID;
        TIntegerField *qsV1_CASALENTACASIR;
        TStringField *qsV1_CASALENTACASA;
        TFloatField *qsV1_CASALENTASUMA_PACH;
        TFloatField *qsV1_CASALENTASUMA_PRIM;
        TDateTimeField *qsV1_CASALENTADATA;
        TStringField *qsV1_CASALENTADESCR;
        TStringField *qsV1_CASALENTAISRET;
        TIntegerField *qsV1_CASALENTAACCEPT;
        TFloatField *qsV1_CASALENTAclcSumaRest;
        TSagiODACSmartQuery *qsCasaTotals;
        TIntegerField *qsCasaTotalsCASIR;
        TStringField *qsCasaTotalsCASA;
        TFloatField *qsCasaTotalsSUMA_PRIM;
        TFloatField *qsCasaTotalsSUMA_RET;
        TSagiODACSmartQuery *qsBiltets;
        TSmartQuery *qqIsVinzEn;
        TStringField *qsBiltetsCOD;
        TDateTimeField *qsBiltetsDATA;
        TStringField *qsBiltetsRUTA;
        TIntegerField *qsBiltetsLOC;
        TIntegerField *qsBiltetsIDCASLENTA;
        TStringField *qsBiltetsCODADD;
        TStringField *qsBiltetsINLESN;
        TFloatField *qsBiltetsDEPART;
        TStringField *qsBiltetsCERTIFICAT;
        TStringField *qsBiltetsPERS_NUMELE;
        TStringField *qsBiltetsPERS_PRUMELE;
        TStringField *qsBiltetsPERS_PATRON;
        TStringField *qsBiltetsPASAPORT;
        TIntegerField *qsBiltetsBAGAJ;
        TIntegerField *qsBiltetsINPIC;
        TIntegerField *qsBiltetsPRINTS;
        TFloatField *qsBiltetsSUMAT;
	TOraSQLMonitor *SQLMonitor;
        TSagiODACSmartQuery *qsSetBlits;
        TDataSource *dsSetBlits;
        TOraStoredProc *ospSetCasaGroup;
        TStringField *qsBiltetsCECU;
        TOraStoredProc *osqIMB;
        TIntegerField *qsSetBlitsID;
        TSagiODACSmartQuery *osmFullCasaLentaPrev;
        TDataSource *dsmFullCasaLentaPrev;
        TIntegerField *osmFullCasaLentaPrevID;
        TIntegerField *osmFullCasaLentaPrevCASIR;
        TStringField *osmFullCasaLentaPrevCASA;
        TFloatField *osmFullCasaLentaPrevSUMA_PACH;
        TFloatField *osmFullCasaLentaPrevSUMA_PRIM;
        TDateTimeField *osmFullCasaLentaPrevDATA;
        TStringField *osmFullCasaLentaPrevDESCR;
        TStringField *osmFullCasaLentaPrevISRET;
        TIntegerField *osmFullCasaLentaPrevACCEPT;
        TStringField *osmFullCasaLentaPrevRUTA;
        TFloatField *osmFullCasaLentaPrevPRINTGR;
        TSagiODACSmartQuery *qsT1RUTABRONI;
        TOraDataSource *dsT1RUTABRONI;
        TIntegerField *qsT1RUTABRONIIDCASALENTA;
        TStringField *qsT1RUTABRONIRUTA;
        TDateTimeField *qsT1RUTABRONIDATA;
        TIntegerField *qsT1RUTABRONITIPBRONI;
        TStringField *qsT1RUTABRONIDOCUMENT;
        TStringField *qsT1RUTABRONIADDINFO;
        TIntegerField *qsT1RUTABRONIBILETCOUNT;
        TIntegerField *qsT1RUTABRONISTAREA;
        TFloatField *qsV1_CASALENTASUMAVAL_PACH;
        TFloatField *qsV1_CASALENTASUMAVAL_PRIM;
        TStringField *qsV1_CASALENTAVALUTA;
  TSagiODACSmartQuery *sqValuta;
  TFloatField *qsD_CassaSUMAVAL;
  TStringField *qsD_CassaVALUTA;
  TFloatField *qsD_CassaPSUMAVAL;
  TStringField *qsD_CassaPVALUTA;
  TStringField *osmFullCasaLentaPrevVALUTA;
  TConnectDialog *ConnectDialog1;
  TSagiOraSession *db;
  TFloatField *qsBiltetsPRET_BRONARE_ESTIMAT;
  TStringField *qsBiltetsRIND_LOC_STRING;
  TSmartQuery *qComplexFilt;
  TDataSource *dsComplexFilt;
  TOraStoredProc *spAccess;
  TOraStoredProc *spRegComp;
  TStringField *qsBiltetsS_TIME;
  TOraStoredProc *spGetUserInfo;
  TOraStoredProc *spGetPrnScript;
  TSmartQuery *qCheckBroni;
  TOraDataSource *dsCheckBroni;
	TOraDataSource *dsT1RUTABRONIDETAILS1;
	TSagiODACSmartQuery *qsT1RUTABRONIDETAILS;
	TSagiODACSmartQuery *qsCASALENTA_PAYTYPE;
        void __fastcall qsBiltetsBeforeInsert(TDataSet *DataSet);
        void __fastcall qsBiltetsBeforeEdit(TDataSet *DataSet);
        void __fastcall qsV1_CASALENTASUMA_PRIMChange(TField *Sender);
        void __fastcall qsV1_CASALENTACalcFields(TDataSet *DataSet);
        void __fastcall qsBiletAddNewRecord(TDataSet *DataSet);
        void __fastcall qsCasaTotalsAfterOpen(TDataSet *DataSet);
				void __fastcall qsV1_CASALENTAAfterOpen(TDataSet *DataSet);
				void __fastcall qsD_CassaAfterPost(TDataSet *DataSet);
        void __fastcall qsD_CassaPAfterPost(TDataSet *DataSet);
        void __fastcall qsD_CassaPNewRecord(TDataSet *DataSet);
        void __fastcall qsD_CassaCalcFields(TDataSet *DataSet);
        void __fastcall qsD_CassaPCalcFields(TDataSet *DataSet);
        void __fastcall qsSetBlitsAfterEdit(TDataSet *DataSet);
        void __fastcall qsBiltetsINLESNChange(TField *Sender);
        void __fastcall qsBiltetsEditError(TDataSet *DataSet,
          EDatabaseError *E, TDataAction &Action);
        void __fastcall dbError(TObject *Sender, EDAError *E, bool &Fail);
        void __fastcall qsV1_CASALENTAAfterClose(TDataSet *DataSet);
        void __fastcall qsT1RUTABRONIAfterInsert(TDataSet *DataSet);
  void __fastcall qsD_CassaNewRecord(TDataSet *DataSet);
  void __fastcall qsBiltetsAfterPost(TDataSet *DataSet);
  void __fastcall spRegCompAfterExecute(TObject *Sender, bool Result);
	void __fastcall qsCASALENTA_PAYTYPEBeforePost(TDataSet *DataSet);

private:	// User declarations
  bool GetCmdParam(String sParam);
  bool GetCmdParam(String sParam, String &sValue);
  bool registerCompAndUser();
  void ChangeRows(TDBGrid* Grid, int nModalResult);

public:		// User declarations
		__fastcall TdmCassa(TComponent* Owner);

		double soldStart,soldFin;
		bool __fastcall davaiProdavai(int CntBlt,TList* mesta,TDateTime vDATA,String vRUTA,long vDEST,long vGARA, long TipBiletSpecial, int BroniTipSelected=-1, String sLocsInpManual="");
		void __fastcall anuVerniom(String vBilet,int mm,String Rtip,TDateTime vDATA,String vRUTA);
		void __fastcall OpenAll();
		String __fastcall callProc(String FN,String p1="",String p2="",String p3="");
		long UserID,casaNrDoc,casaGroup1;
		bool IsUserSubAgent, UserCanPrint;
		String NrCassa;
		bool isCassaPerron;        // 0-обычная 1-только перронка
		bool isCassaPerronVinzare; // 0-обычная 1-может продавать перроны тоже (для обычных касс)
		bool isBroni;              // 0-обычная 1-наконец-то Бронь
		bool isBroniLaPlata;       // Оплата брони
		bool isPridn;              // 0-обычная 1-теперь и наши друзья с правого береге днестра
		bool isAdmin;
		int SessValutaDepCode;
		String defValuta,SessValuta;
		TStringList* slTicketPrint;
		TStringList* slTicketPrint_SX;

		bool bBookingMode;
		String VersionInfo;
		int iSelZoomPercent;
		int iAddSelZoomPercent;
		bool bAddSelHideSoldPlacesCount;

		void __fastcall calcRest(double suma);
		void __fastcall GFC();
				void __fastcall BileteLaTipar(int mpde, int pay_type = 1, bool isBroni = false);
				void __fastcall BonuriLaTipar(int mpde);
				void __fastcall BileteOk();
        void __fastcall BileteAnulare();
        bool __fastcall LockRutaTable(TDateTime vDATA,String vRUTA,int isCloseAutomat=true);

        bool __fastcall CheckRuta(TDateTime vDATA,String vRUTA,String&mess);

        bool __fastcall VR_endTransaction(bool isComitt=true,int mode=0);

        void __fastcall PrintItog();
        void __fastcall ProjectRun(int mode=0);

        void __fastcall RST_StartEdit();

        bool __fastcall FindBadBilet(long pID=0);
        bool __fastcall FindBookedTicket(long pID);

        void __fastcall RefreshTotals(int mode=0);

        void __fastcall BilCommit(bool totalsRefrssh=true);
				void __fastcall setcasaGroup(int iidGroup);

        bool __fastcall GotoCasaOper(long vID);
        void __fastcall AppException(TObject *Sender, Exception *E);
        String __fastcall GetViewText(String  svv);
        void  __fastcall PrintListImb(TDate sDATA,String sRUTA,long pCASALENTAID);
        void __fastcall viewSaledTickets();
        void __fastcall StopPerronRUTA(String vRUTA,TDate vDATA,int IsCommit=0 );

        void __fastcall DB_Rollback();
        void __fastcall DB_Commit();

        void __fastcall broni_changeStarea( long vcasalenta, long vstarea);

        double __fastcall Sess_SetValuta(TDateTime vDATA,String vVal="",double vCurs=0);
        String __fastcall Sess_GetValuta();
        void RegError(String vCodBil);
        String CheckError();
        void FixError(String vCodBil);
};
//---------------------------------------------------------------------------
double __fastcall StrToFloatUNIAC1(String Astring);
extern PACKAGE TdmCassa *dmCassa;
//---------------------------------------------------------------------------
#endif
