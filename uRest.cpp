#include <vcl.h>
#pragma hdrstop

#include "uDMcassa.h"
#include "uRest.h"
#include "uPrintSetup.h"
#include "uMain.h"
#include "uVinz.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBGridMy1"
#pragma link "SagiQueryLIB"
#pragma link "MemDS"
#pragma link "Ora"
#pragma link "OraSmart"
#pragma link "SagiODACSmartQueryLIB"
#pragma link "StaticDBGrid"
#pragma link "DBAccess"
#pragma link "RzButton"
#pragma link "RzCmboBx"
#pragma link "RzDBCmbo"
#pragma link "RzDBChk"
#pragma link "RzRadChk"
#pragma link "UnDBCtrl"
#pragma link "UnSDGrid"
#pragma link "LgSelect"
#pragma resource "*.dfm"
TfRest *fRest;
//---------------------------------------------------------------------------
__fastcall TfRest::TfRest(TComponent* Owner)
        : TForm(Owner)
{
  DBGridMy11->Load();
  viziMode(1);
  dbePrim->DataSource=dmCassa->dsV1_CASALENTA;
  osmT1LISTIMB_VPRON_RESTIT->MasterSource=dmCassa->dsV1_CASALENTA;

}
//---------------------------------------------------------------------------
void __fastcall TfRest::OpenClose(int mm,bool viiewMess)
{
if(mm==1) // close
 {
 if(osmT1LISTIMB_VPRON_RESTIT->Active&&ISEDIT(osmT1LISTIMB_VPRON_RESTIT)) CANCEL(osmT1LISTIMB_VPRON_RESTIT)
 qsRest->Close();
 qsRestT->Close();
 osmT1LISTIMB_VPRON_RESTIT->Close();
 }else //open
 {

  if(dmCassa->isPridn)
  {

  dmCassa->qq->Close();
  dmCassa->qq->SQL->Text="begin :Rez:=GVALUTA.SetOnRetBiletValuta( :vBILETCOD); end;";
  dmCassa->qq->Prepare();
  dmCassa->qq->ParamByName("Rez")->ParamType= ptOutput;
  dmCassa->qq->ParamByName("Rez")->DataType= ftString	;
  dmCassa->qq->ParamByName("vBILETCOD")->AsString=meNrBilet->Text;
  dmCassa->qq->ExecSQL();
  dmCassa->SessValuta=dmCassa->qq->ParamByName("Rez")->AsString;
  dmCassa->qq->Close();
  }


 qsRestT->ParamByName("CC")->AsString=meNrBilet->Text;
 qsRestT->Open();
 if(qsRestT->RecordCount==0)//||!dmCassa->qsBiltets->Locate( "COD",meNrBilet->Text,TLocateOptions()))
    {
    if(viiewMess)
       ShowMessage(fMain->LS->Text["noticket"]);
    qsRestT->Close();
    return;
    }
 if(dmCassa->isCassaPerron)
     {
        dmCassa->qq->Close();
        dmCassa->qq->SQL->Text="SELECT count(*) CC  FROM T1LISTIMB_VPRON_RESTIT where COD_REST_BILET=:BB";
        dmCassa->qq->ParamByName("BB")->AsString=meNrBilet->Text;
        dmCassa->qq->Open();
        if(dmCassa->qq->FieldByName("CC")->AsInteger)
           {
             dmCassa->qq->Close();
             ShowMessage(fMain->LS->Text["alreadyret"]);
             return;
           }
        dmCassa->qq->Close();
     }

 String mess;
 if(dmCassa->CheckRuta(qsRestTDATA->AsDateTime,qsRestTRUTA->AsString,mess))
    {
    ShowMessage(mess);
    qsRestT->Close();
    return;
    }

 qsRest->Open();

 dmCassa->anuVerniom(qsRestTCOD->AsString,0,"R",qsRestTDATA->AsDateTime,qsRestTRUTA->AsString);
 dmCassa->RST_StartEdit();

 rbIP->Enabled=bool(qsRestTIP->AsFloat);
 rbRB->Enabled=bool(qsRestTRB->AsFloat);
 rbRB->Checked=bool(qsRestTRB->AsFloat);
 rbIP->Checked=!rbRB->Checked;


 recalcTot();
 osmT1LISTIMB_VPRON_RESTIT->Open();
 //dmCassa->qsBiltets->Locate( "COD",meNrBilet->Text,TLocateOptions());

 tsInpRest->TabVisible=bool(dmCassa->isCassaPerron&&dmCassa->qsV1_CASALENTAclcSumaRest->AsFloat==0);
 tsInpRest->TabVisible = ((tsInpRest->TabVisible) || (dmCassa->isPridn));
 tsDescSpec->TabVisible=tsInpRest->TabVisible;
 pgcRestInfo->ActivePage=(tsInpRest->TabVisible)?tsInpRest:tsBilet;
 if(tsInpRest->TabVisible) //&&osmT1LISTIMB_VPRON_RESTIT->RecordCount==0)
     {
     INSERT(osmT1LISTIMB_VPRON_RESTIT)
     actCalcRest->Execute();
     }
 }
 viziMode(mm);
 /*if(//btnLaTipar->Enabled&&dmCassa->qsV1_CASALENTAclcSumaRest->AsFloat==0 //dmCassa->qsV1_CASALENTASUMA_PRIM->AsFloat==0
 //&&    //dmCassa->isCassaPerron==0&&
      (qsRestTNRORD->AsInteger!=0||qsRest->RecordCount!=1||qsRestUPL->AsFloat!=0.0))
        {
        btnLaTipar->Enabled=false;
        if(btAnul->Enabled)
            btAnul->SetFocus();
        }*/
// else
// {
 /*if(!tsInpRest->TabVisible)
  rzdbProcEdit->SetFocus();*/
// }
}

void __fastcall TfRest::btFindBilClick(TObject *Sender)
{
  OpenClose(1);
  OpenClose(0);
}
//---------------------------------------------------------------------------

void __fastcall TfRest::meNrBiletKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key==VK_RETURN||Key==VK_F2)
  {
  btFindBil->Click();
  Key=0;
  } /*else
  if(Ky==VK_ESCAPE) {btnIesir->Click();Key=0;}*/
}
//---------------------------------------------------------------------------

void __fastcall TfRest::meNrBiletChange(TObject *Sender)
{
//  OpenClose(1);
//  if(meNrBilet->Text.Length()==7)
//      OpenClose(0);//,false);
//    else
//  if(meNrBilet->Text.Length()==8)
//      OpenClose(0);
}
//---------------------------------------------------------------------------

void __fastcall TfRest::btAnulClick(TObject *Sender)
{
  OpenClose(1);
  dmCassa->VR_endTransaction(false);
  BtnBezPrint->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TfRest::btnLaTiparClick(TObject *Sender)
{
  double ssRest=dmCassa->qsV1_CASALENTAclcSumaRest->AsFloat;
  String sqlText = "select (select cod1 from tms_syss where TIP='S' and COD=3 and um=nvl(VALUTA,'RUP')) valnom from t0bilet b, T1CASALENTA_VAL l where l.ID(+)=b.IDCASLENTA and b.COD="+ QuotedStr(qsRestTCOD->AsString);
  dmCassa->qq->SQL->Text = sqlText;
  //dmCassa->qq->ParamByName("codu")->AsString = qsRestTCOD->AsString;
  dmCassa->qq->Open();
  fVinz->cmbValuta->ItemIndex = dmCassa->qq->FieldByName("valnom")->AsInteger-1;
  fVinz->UpdateValutaInfo();
 // if( dmCassa->qsV1_CASALENTAclcSumaRest->AsFloat || dmCassa->isPridn) // dmCassa->qsV1_CASALENTASUMA_PRIM->AsFloat||osmT1LISTIMB_VPRON_RESTITREST_SUMA->AsFloat)
  {
    if (osmT1LISTIMB_VPRON_RESTIT->Active&&ISEDIT(osmT1LISTIMB_VPRON_RESTIT))
      POST(osmT1LISTIMB_VPRON_RESTIT)
    dmCassa->qsV1_CASALENTAISRET->AsString=rbIP->Checked?"I":"R";
    if(dmCassa->isPridn&&fVinz->NotDefValuta())
    {
      if(osmT1LISTIMB_VPRON_RESTITREST_SUMA->AsFloat)
        dmCassa->qsV1_CASALENTASUMAVAL_PRIM->AsFloat=osmT1LISTIMB_VPRON_RESTITREST_SUMA->AsFloat;
    }
    else
    {
      if(osmT1LISTIMB_VPRON_RESTITREST_SUMA->AsFloat)
        dmCassa->qsV1_CASALENTASUMA_PRIM->AsFloat=osmT1LISTIMB_VPRON_RESTITREST_SUMA->AsFloat;
    }
    String sUpd=dmCassa->qsV1_CASALENTA->SQLUpdate->Text;
    //dmCassa->qq->SQL->Text
    dmCassa->qsV1_CASALENTA->SQLUpdate->Text="UPDATE V1_CASALENTA_VAL \
      SET                                                               \
      SUMA_PRIM = :SUMA_PRIM, \
      SUMA_PACH = :SUMA_PACH, \
      DESCR = :DESCR,           \
      ISRET = :ISRET,            \
      ACCEPT = :ACCEPT,           \
      SUMAVAL_PRIM = :SUMAVAL_PRIM,\
      SUMAVAL_PACH = :SUMAVAL_PACH,\
      VALUTA = :VALUTA              \
      WHERE                            \
      ID = :OLD_ID";
    try
    {
      POST(dmCassa->qsV1_CASALENTA)
    }
    __finally
    {
      dmCassa->qsV1_CASALENTA->SQLUpdate->Text=sUpd;
    }
    dmCassa->callProc("GRA.GENBILETREST",qsRestTCOD->AsString,rbIP->Checked?"1":"0",dmCassa->qsV1_CASALENTAID->AsString);
    dmCassa->VR_endTransaction();
    if(fPrintSetup->rgPrinterType->ItemIndex==4/*&&0==1*/) //casa MINI500.02 i MercText)
    {
      BeginPrintTransaction();
      PrintString(qsRestBiletCECU->AsString);
      if (fPrintSetup->rgPrinterType->ItemIndex != 4)
        EndPrintTransaction(true,0,dmCassa->qsV1_CASALENTAclcSumaRest->AsFloat,0,dmCassa->SessValutaDepCode,dmCassa->qsV1_CASALENTAID->AsInteger);
      String sqlText = "select (select cod1 from tms_syss where TIP='S' and COD=3 and um=nvl(VALUTA,'RUP')) valnom from t0bilet b, T1CASALENTA_VAL l where l.ID(+)=b.IDCASLENTA and b.COD="+ QuotedStr(qsRestTCOD->AsString);
      dmCassa->qq->SQL->Text = sqlText;
      //dmCassa->qq->ParamByName("codu")->AsString = qsRestTCOD->AsString;
      dmCassa->qq->Open();
      if (fPrintSetup->rgPrinterType->ItemIndex == 4)
        fPrintSetup->PrintMINI500_02(ssRest, dmCassa->qq->FieldByName("valnom")->AsInteger, true);
      //else if (fPrintSetup->rgPrinterType->ItemIndex == 5)
      //  fPrintSetup->Print130fText(ssRest, dmCassa->qq->FieldByName("valnom")->AsInteger, true);
      qsRestT->RefreshQuery();
    }
    if(rbIP->Enabled && rbRB->Enabled && rbRB->Checked && fPrintSetup->rgPrinterType->ItemIndex < 4)
    {
      qsRestT->RefreshQuery();
      BeginPrintTransaction();
      PrintString(qsRestBiletCECU->AsString);
      //if(fPrintSetup->rgPrinterType->ItemIndex!=2)
      PrintString("\n\n\n\n\n\n\n\n\n\n\n");
      EndPrintTransaction(true);
    }
  }
 /* else
  {
    ShowMessage(fMain->LS->Text["retsum"]);
    btnLaTipar->Enabled=false;
  }    */
  dmCassa->FixError(meNrBilet->Text);
  dmCassa->VR_endTransaction();
  viziMode(1);
  dmCassa->qsV1_CASALENTA->RefreshQuery();
  fVinz->cmbValuta->ItemIndex = 0;
  fVinz->UpdateValutaInfo();
}
//---------------------------------------------------------------------------
void __fastcall TfRest::recalcTot()
{
  if(dmCassa->isPridn&&fVinz->NotDefValuta())
  {
  if(rbIP->Checked)
    {
     dmCassa->qsV1_CASALENTASUMAVAL_PRIM->AsFloat=qsRestTIP->AsFloat+qsRestTRB->AsFloat;
    } else
  if(rbRB->Checked)
    {
     dmCassa->qsV1_CASALENTASUMAVAL_PRIM->AsFloat=qsRestTIP->AsFloat+qsRestTRB->AsFloat;
    }

  return;
  }

if(rbIP->Checked)
  {
   dmCassa->qsV1_CASALENTASUMA_PRIM->AsFloat=qsRestTIP->AsFloat+qsRestTRB->AsFloat;
  } else
if(rbRB->Checked)
  {
   dmCassa->qsV1_CASALENTASUMA_PRIM->AsFloat=qsRestTIP->AsFloat+qsRestTRB->AsFloat;
  }

}

void __fastcall TfRest::rbIPClick(TObject *Sender)
{
rbRB->Checked=false;
rbIP->Checked=rbIP1->Checked;
recalcTot();
}
//---------------------------------------------------------------------------

void __fastcall TfRest::rbRBClick(TObject *Sender)
{
rbIP->Checked=false;
rbRB->Checked=rbRB1->Checked;
recalcTot();
}
//---------------------------------------------------------------------------

void __fastcall TfRest::viziMode(int mode)
{
if(mode==0)
 {

 pnlFind->Enabled=false;
 pnlRest->Enabled=true;
 fMain->SetToolbMode(false);
 }
 else {
 pnlRest->Enabled=false;
 pnlFind->Enabled=true;
 dmCassa->dsV1_CASALENTA->Enabled=false;
 fMain->SetToolbMode(true);
 }

btFindBil->Enabled=pnlFind->Enabled;
btnIesir->Enabled=pnlFind->Enabled;

btnLaTipar->Enabled=pnlRest->Enabled;
dbmemoBilet->Visible=pnlRest->Enabled;

btAnul->Enabled=pnlRest->Enabled;
try {
if(btFindBil->Enabled&&Visible&&meNrBilet->Focused()==false) {meNrBilet->SelectAll();meNrBilet->SetFocus();}
//if(btnLaTipar->Enabled&&Visible&&btnLaTipar->Focused()==false) btnLaTipar->SetFocus();
if(btAnul->Enabled&&Visible&&btAnul->Focused()==false) btAnul->SetFocus();
}
catch (...) {}
}


void __fastcall TfRest::FormCloseQuery(TObject *Sender, bool &CanClose)
{
if(btAnul->Enabled) btAnul->Click();
//CanClose=btnIesir->Enabled;
}
//---------------------------------------------------------------------------

void __fastcall TfRest::btnIesir1Click(TObject *Sender)
{
fMain->toRest->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TfRest::FormDeactivate(TObject *Sender)
{
if(btAnul->Enabled) btAnul->Click();
}
//---------------------------------------------------------------------------

void __fastcall TfRest::osmT1LISTIMB_VPRON_RESTITAfterInsert(
      TDataSet *DataSet)
{
  osmT1LISTIMB_VPRON_RESTITCOD_REST_BILET->AsString=meNrBilet->Text;
  if (dmCassa->isPridn)
    osmT1LISTIMB_VPRON_RESTITREST_FULLSUMS->AsInteger=0;
  else
    osmT1LISTIMB_VPRON_RESTITREST_FULLSUMS->AsInteger=1;
}
//---------------------------------------------------------------------------


void __fastcall TfRest::osmT1LISTIMB_VPRON_RESTITPostError(
      TDataSet *DataSet, EDatabaseError *E, TDataAction &Action)
{
//
if(E->Message.Pos("ORA-00001"))
  ShowMessage(fMain->LS->Text["alreadyret"]+"\n\n"+E->Message);
}
//---------------------------------------------------------------------------
void __fastcall TfRest::dbePrimChange(TObject *Sender)
{
  if(btnLaTipar->Enabled==false&&
    dmCassa->qsV1_CASALENTAclcSumaRest->AsFloat)
  btnLaTipar->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TfRest::actCalcRestExecute(TObject *Sender)
{
  CalcRest();
}
//---------------------------------------------------------------------------
void __fastcall TfRest::rzdbProcEditChange(TObject *Sender)
{
  btnLaTipar->Enabled=!dmCassa->isCassaPerron;
}
//---------------------------------------------------------------------------
void __fastcall TfRest::osmT1LISTIMB_VPRON_RESTITREST_PROCENTChange(
      TField *Sender)
{
  btnLaTipar->Enabled=!dmCassa->isCassaPerron;
}
//---------------------------------------------------------------------------
void __fastcall TfRest::BtnBezPrintClick(TObject *Sender)
{
  String sqlText = "select (select cod1 from tms_syss where TIP='S' and COD=3 and um=nvl(VALUTA,'RUP')) valnom from t0bilet b, T1CASALENTA_VAL l where l.ID(+)=b.IDCASLENTA and b.COD="+ QuotedStr(qsRestTCOD->AsString);
  dmCassa->qq->SQL->Text = sqlText;
  //dmCassa->qq->ParamByName("codu")->AsString = qsRestTCOD->AsString;
  dmCassa->qq->Open();
  fVinz->cmbValuta->ItemIndex = dmCassa->qq->FieldByName("valnom")->AsInteger-1;
  fVinz->UpdateValutaInfo();
  if( dmCassa->qsV1_CASALENTAclcSumaRest->AsFloat || dmCassa->isPridn) // dmCassa->qsV1_CASALENTASUMA_PRIM->AsFloat||osmT1LISTIMB_VPRON_RESTITREST_SUMA->AsFloat)
  {
    if (osmT1LISTIMB_VPRON_RESTIT->Active&&ISEDIT(osmT1LISTIMB_VPRON_RESTIT))
      POST(osmT1LISTIMB_VPRON_RESTIT)
    dmCassa->qsV1_CASALENTAISRET->AsString=rbIP->Checked?"I":"R";
    if(dmCassa->isPridn&&fVinz->NotDefValuta())
    {
      if(osmT1LISTIMB_VPRON_RESTITREST_SUMA->AsFloat)
        dmCassa->qsV1_CASALENTASUMAVAL_PRIM->AsFloat=osmT1LISTIMB_VPRON_RESTITREST_SUMA->AsFloat;
    }
    else
    {
      if(osmT1LISTIMB_VPRON_RESTITREST_SUMA->AsFloat)
        dmCassa->qsV1_CASALENTASUMA_PRIM->AsFloat=osmT1LISTIMB_VPRON_RESTITREST_SUMA->AsFloat;
    }
	String sUpd=dmCassa->qsV1_CASALENTA->SQLUpdate->Text;
    //dmCassa->qq->SQL->Text
    dmCassa->qsV1_CASALENTA->SQLUpdate->Text="UPDATE V1_CASALENTA_VAL \
      SET                                                               \
      SUMA_PRIM = :SUMA_PRIM, \
      SUMA_PACH = :SUMA_PACH, \
      DESCR = :DESCR,           \
      ISRET = :ISRET,            \
      ACCEPT = :ACCEPT,           \
      SUMAVAL_PRIM = :SUMAVAL_PRIM,\
      SUMAVAL_PACH = :SUMAVAL_PACH,\
      VALUTA = :VALUTA              \
      WHERE                            \
      ID = :OLD_ID";
    try
    {
      POST(dmCassa->qsV1_CASALENTA)
    }
    __finally
    {
      dmCassa->qsV1_CASALENTA->SQLUpdate->Text=sUpd;
    }
    dmCassa->callProc("GRA.GENBILETREST",qsRestTCOD->AsString,rbIP->Checked?"1":"0",dmCassa->qsV1_CASALENTAID->AsString);
    dmCassa->VR_endTransaction();
  }
  else
  {
    ShowMessage(fMain->LS->Text["retsum"]);
    btnLaTipar->Enabled=false;
  }
  dmCassa->FixError(meNrBilet->Text);
  BtnBezPrint->Enabled=false;
  dmCassa->VR_endTransaction();
  viziMode(1);
  dmCassa->qsV1_CASALENTA->RefreshQuery();
  fVinz->cmbValuta->ItemIndex = 0;
  fVinz->UpdateValutaInfo();
  BtnBezPrint->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfRest::CalcRest()
{
  if(osmT1LISTIMB_VPRON_RESTIT->Active&&ISEDIT(osmT1LISTIMB_VPRON_RESTIT))
   try
   {
     POST(osmT1LISTIMB_VPRON_RESTIT)
   }
   catch(Exception&E)
   {
     btAnulClick(NULL);
     Abort();//throw;
   }

  if(ISEDIT(dmCassa->qsV1_CASALENTA))
  {
   dmCassa->qsV1_CASALENTAISRET->AsString=" ";
   POST(dmCassa->qsV1_CASALENTA);
  }
  EDIT(dmCassa->qsV1_CASALENTA)
  dmCassa->qsV1_CASALENTAISRET->AsString="!";
  qsRestT->Refresh();
  recalcTot();                       // poluceti valuta is gra.enviroment (gra)
  dmCassa->calcRest(dmCassa->isPridn&&fVinz->NotDefValuta()?(dmCassa->qsV1_CASALENTASUMAVAL_PRIM->AsFloat):(dmCassa->qsV1_CASALENTASUMA_PRIM->AsFloat));
  dbePrimChange(NULL);
  if (qsRestBilet->Active)
   qsRestBilet->Close();
  qsRestBilet->ParamByName("pcod")->AsString = meNrBilet->Text;
  //qsRestBilet->ParamByName("prest")->AsFloat = StrToFloat(dbePrim->Text);
  qsRestBilet->ParamByName("prest")->AsFloat = dbePrim->Field->AsFloat;
  qsRestBilet->Open();
}
//---------------------------------------------------------------------------
void __fastcall TfRest::RestRecalcPrep(String vErrTick)
{
  //fRest->Show();
  //fRest->WindowState = wsMaximized;
  fRest->Show();
  WindowState = wsMaximized;
  meNrBilet->Text = vErrTick;
  OpenClose(1);
  OpenClose(0);
  EDIT(osmT1LISTIMB_VPRON_RESTIT);
  osmT1LISTIMB_VPRON_RESTIT->FieldByName("REST_FULLSUMS")->AsInteger = 1;
  POST(osmT1LISTIMB_VPRON_RESTIT)
  BtnBezPrint->Enabled = true;
  CalcRest();
}
