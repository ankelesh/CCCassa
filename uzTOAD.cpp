#include <vcl.h>
#pragma hdrstop

#include "uzTOAD.h"
#include "uDMcassa.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UnDBCtrl"
#pragma link "UnSDGrid"
#pragma link "LgSelect"
#pragma link "cxControls"
#pragma link "cxSplitter"
#pragma link "cxPC"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCheckBox"
#pragma link "cxLabel"
#pragma link "cxGroupBox"
#pragma link "SagiEdit"
#pragma link "cxButtons"
#pragma link "UnScList"
#pragma link "cxRadioGroup"
#pragma link "cxDBEdit"
#pragma link "cxMemo"
#pragma link "cxDateUtils"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "dxBarBuiltInMenu"
#pragma link "dxCore"
#pragma link "SynEdit"
#pragma link "SynEditHighlighter"
#pragma link "SynHighlighterSQL"
#pragma link "SynEditMiscClasses"
#pragma link "SynEditSearch"
#pragma link "UnSynEdit"
#pragma link "UnSynEditPLSQL"
#pragma resource "*.dfm"
 TfTOAD *fTOAD;
//---------------------------------------------------------------------------
__fastcall TExecThread::TExecThread(bool CreateSuspended)
: TThread(CreateSuspended)
{
	ExecTime = 0;
}
//---------------------------------------------------------------------------
void __fastcall TExecThread::Execute()
{
	while (true)
	{
		if (Terminated)
			break;
		ExecTime += 0.1;
		ExecTimeText = "Время: " + FloatToStrF(ExecTime, ffFixed, 10, 1) + " сек.";
		Synchronize(UpdateTimer);
		Sleep(100);
	}
}
//---------------------------------------------------------------------------
void __fastcall TExecThread::UpdateTimer()
{
	fTOAD->sbSQL->Panels->Items[1]->Text = ExecTimeText;
}
//---------------------------------------------------------------------------
__fastcall TfTOAD::TfTOAD(TComponent* Owner)
: TForm(Owner)
{
  pcTOAD->ActivePageIndex = 1;
  rgObject->ItemIndex = -1;

  grSold->Load();
  grCheck->Load();
  btCheckRefreshList->Click();
}
//---------------------------------------------------------------------------
void __fastcall TfTOAD::FormCreate(TObject *Sender)
{
  pcTOAD->ActivePageIndex = 1;
  ActiveControl = dcmQuery;
  cbxSqlMonitor->Checked = dmCassa->SQLMonitor->Active;
}
//---------------------------------------------------------------------------
void __fastcall TfTOAD::FormClose(TObject *Sender, TCloseAction &Action)
{
  if (sqq->Executing() || sqq->Fetching())
	StopExecTimer(btUser);

  Action = caFree;
  fTOAD = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TfTOAD::gotoRegAdj(long cod)
{
}
//---------------------------------------------------------------------------
void __fastcall TfTOAD::rgObjectClick(TObject *Sender)
{
  sqObjects->Params->Items[0]->AsString = rgObject->ItemIndex ? "VIEW" : "TABLE";
  sbRefObjectsClick(this);
}
//---------------------------------------------------------------------------
void __fastcall TfTOAD::sbRefObjectsClick(TObject *Sender)
{
  if (sqObjects->Active)
    sqObjects->Refresh();
  else
    sqObjects->Open();
}
//---------------------------------------------------------------------------
void __fastcall TfTOAD::sbRefCustomClick(TObject *Sender)
{
  if (sqCustom->Active)
	sqCustom->Refresh();
  else
	sqCustom->Open();
}
//---------------------------------------------------------------------------
void __fastcall TfTOAD::dbgrTVQColEnter(TObject *Sender)
{
  dbmField->DataField = dbgrTVQ->SelectedField->FieldName;
}
//---------------------------------------------------------------------------
void __fastcall TfTOAD::sqqAfterOpen(TDataSet *DataSet)
{
  dbmField->DataField = sqq->Fields->Fields[0]->FieldName;
}
//---------------------------------------------------------------------------
//int __fastcall Pos(const String& ASource, char* APattern, int AFrom)
//{
//  if (AFrom > ASource.Length())
//	return 0;
//  char *p0 = AnsiString(ASource).c_str();
//  if (!p0)
//	return 0;
//  char *p = strstr(AnsiString(ASource).c_str() + AFrom - 1, APattern);
//  if (!p)
//	return 0;
//  return p - p0 + 1;
//}
////---------------------------------------------------------------------------
//static String __fastcall RemoveComments(const String ASource)
//{
//  String asResult;
//  int nLen = ASource.Length();
//  int nPos1 = 1;
//  while (nPos1 <= nLen)
//  {
//	int nPos2a = Pos(ASource, "/*", nPos1);
//	int nPos2b = Pos(ASource, "--", nPos1);
//	if (!nPos2a && !nPos2b)
//	  break;
//	int nPos2 = nPos2a;
//	char *p = "*/";
//	if (!nPos2a || (nPos2b < nPos2a))
//	{
//	  p = "\n";
//	  nPos2 = nPos2b;
//	}
//	asResult += ASource.SubString(nPos1, nPos2 - nPos1 - 1);
//	nPos1 = Pos(ASource, p, nPos2);
//	if (!nPos1)
//	  break;
//	if (nPos2 == nPos2a)
//	  nPos1 += 2;
//  }
//  if (nPos1 && (nPos1 <= nLen))
//	asResult += ASource.SubString(nPos1, nLen);
//  return asResult;
//}
//---------------------------------------------------------------------------
void __fastcall TfTOAD::SQLExecute(bool LikeToad)
{
  dsTVQ->DataSet = NULL;

  String asSQL = dcmQuery->ExecuteStatement(LikeToad);

  sqq->Close();
  sqq->SQL->Clear();
  String asOper = asSQL.SubString(1, 6).UpperCase();
  bool bSelect = (asOper == "SELECT");

  sqq->SQL->Text = asSQL;

  if (!asSQL.Pos(" ") && !asSQL.Pos(";") && !asSQL.Pos("\n") && !asSQL.Pos("\t"))
  {
    sqq->SQL->Text = "SELECT * FROM " + asSQL;
    bSelect = true;
  }

  if (bSelect)
	StartExecTimer(sqltQuery);
  else
 	StartExecTimer(sqltCommand);
}
//---------------------------------------------------------------------------
void __fastcall TfTOAD::StartExecTimer(TSQLType QueryType)
{
	ExecSQLType = QueryType;
	sbSQL->Panels->Items[1]->Text = "";

	try
	{
		ExecThread = new TExecThread(true);

		if (ExecSQLType == sqltQuery)
		{
			sbSQL->Panels->Items[0]->Text = "Выполнение запроса...";
			ExecThread->Start();

			sqq->Open();
			dsTVQ->DataSet = sqq;
		}
		else if (ExecSQLType == sqltCommand)
		{
			sbSQL->Panels->Items[0]->Text = "Выполнение выражения...";
			ExecThread->Start();

			sqq->ExecSQL();
		}

	}
	catch (Exception& E)
	{
		if (ExecSQLType == sqltQuery)
			sbSQL->Panels->Items[0]->Text = "Ошибка при выполнении запроса";
		else if (ExecSQLType == sqltCommand)
			sbSQL->Panels->Items[0]->Text = "Ошибка при выполнении выражения";

		StopExecTimer(btFail);

		throw E;
	}
}
//---------------------------------------------------------------------------
void __fastcall TfTOAD::StopExecTimer(TBreakType BreakType)
{
	if (!ExecThread)
		return;

	ExecThread->Terminate();
	ExecThread->WaitFor();
	delete ExecThread;
	ExecThread = NULL;

	if (BreakType == btSuccess)
	{
		if (ExecSQLType == sqltQuery)
			sbSQL->Panels->Items[0]->Text = "Выполнение запроса успешно завершено";
		else if (ExecSQLType == sqltCommand)
			sbSQL->Panels->Items[0]->Text = "Выполнение выражения успешно завершено";
	}
	else if (BreakType == btUser)
	{
		sbSQL->Panels->Items[0]->Text = "Выполнение отменено пользователем";
		sqq->BreakExec();
	}
}
//---------------------------------------------------------------------------

void __fastcall TfTOAD::dcmQueryKeyDown(TObject*, WORD& Key, TShiftState Shift)
{
  if (!ExecThread)
  {
	if ((Key == VK_F9) || ((Key == VK_RETURN) && Shift.Contains(ssCtrl)))
	  SQLExecute(true);
	else if (Key == VK_F8)
	  SQLExecute(false);
  }

  if (Key == VK_ESCAPE && Shift.Contains(ssShift))
  	StopExecTimer(btUser);
}
//---------------------------------------------------------------------------
void __fastcall TfTOAD::sqObjectsAfterScroll(TDataSet *DataSet)
{
  if (!sqObjects->RecordCount)
    return;
  String asName = sqObjectsNAME->AsString;
  sqCustom->Close();
  sqCustom->SagiTableLive = "";
  sqCustom->SQL->Text = "";
  sqCustom->SagiTableLive = asName;
  sqCustom->Open();
}
//---------------------------------------------------------------------------
void __fastcall TfTOAD::cbxSqlMonitorClick(TObject *Sender)
{
  dmCassa->SQLMonitor->Active = cbxSqlMonitor->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TfTOAD::dbmFieldKeyDown(TObject *Sender, WORD &Key,
    TShiftState Shift)
{
  if ((Key == 'A') && Shift.Contains(ssCtrl))
    dbmField->SelectAll();
}
//---------------------------------------------------------------------------
void __fastcall TfTOAD::MakeSoldCmd()
{
  String asFields = (String)
      (cbSoldCont->Checked ? "A" : "") +
      (cbSoldCont1->Checked ? "B" : "") +
      (cbSoldSC->Checked ? "C" : "") +
      (cbSoldDep->Checked ? "D" : "") +
      (cbSoldSC1->Checked ? "E" : "") +
      (cbSoldNrDoc->Checked ? "F" : "") +
      (cbSoldStrSC->Checked ? "G" : "") +
      (cbSoldNrCM->Checked ? "H" : "") +
      (cbSoldData->Checked ? "I" : "") +
      (!cbSoldMethodOLD->Checked && cbSoldAP->Checked ? "J" : "") +
      (!cbSoldMethodOLD->Checked && cbSoldSmart->Checked ? "*" : "") +
      (!cbSoldMethodOLD->Checked && cbSoldShowZero->Checked ? "0" : "") +
      (cbSoldCant->Checked ? "1" : "") +
      (cbSoldPret->Checked ? "2" : "") +
      (cbSoldSumaVal->Checked ? "3" : "") +
      (cbSoldSumaGaap->Checked ? "4" : "") +
      (cbSoldCant1->Checked ? "5" : "");

  String asCmd = (String)
      (cbSoldMethodOLD->Checked ? "UN$SOLD.GET_SOLDT" : "UN$SLD.MAKE") +
      "('" + edSoldDate->Text + "'" +
      ",'" + edSoldID->Text + "'" +
      ",'" + asFields + "'" +
      ",'" + edSoldCont->Text + "'" +
      ",'" + edSoldCont1->Text + "'" +
      ",'" + edSoldSC->Text + "'" +
      ",'" + edSoldDep->Text + "'" +
      ",'" + edSoldSC1->Text + "'" +
      ",'" + edSoldNrDoc->Text + "'" +
      ",'" + edSoldStrSC->Text + "'" +
      ",'" + edSoldNrCM->Text + "'" +
      ",'" + edSoldData->Text + "'";

  while (asCmd.SubString(asCmd.Length() - 2, 3) == ",''")
    asCmd.SetLength(asCmd.Length() - 3);

  String asNull;
  if (!cbSoldMethodOLD->Checked)
    asCmd += (String)
        (edSoldFilter->Text.IsEmpty() ? asNull :
            ",pTableFilter=>'" + edSoldFilter->Text + "'") +
        (cbSoldNoActual->Checked ? ",pOldMethod=>TRUE" : "");

  asCmd += ")";

  edSoldCmd->Text = asCmd;
}
//---------------------------------------------------------------------------
void __fastcall TfTOAD::SoldParametersChange(TObject *Sender)
{
  MakeSoldCmd();
}
//---------------------------------------------------------------------------
void __fastcall TfTOAD::cbCheckActiveDSClick(TObject *Sender)
{
  try
  {
    sqCheck->Active = cbCheckActiveDS->Checked;
  }
  __finally
  {
    cbCheckActiveDS->Checked = sqCheck->Active;
  }
}
//---------------------------------------------------------------------------
void __fastcall TfTOAD::btCheckRefreshListClick(TObject *Sender)
{
  TSmartQuery *qq = dmCassa->qq;
  qq->Close();

  qq->SQL->Text =
      "select procedure_name n from all_procedures\n"
      "where owner='UN4PUBLIC' and object_name='UN$SCHEMA_CHECK'\n"
      "and procedure_name like 'CHECK\\_%' ESCAPE '\\'";
  qq->Open();

  btCheckRunAll->Enabled = qq->RecordCount;
  btCheckRunOne->Enabled = qq->RecordCount;

  TLocateOptions lo;
  rbCheckLostChars->Enabled = qq->Locate("N", "CHECK_LOST_CHARS", lo);
  rbCheckCMSPType->Enabled = qq->Locate("N", "CHECK_CM_SPTYPE", lo);
  rbCheckTXSLD->Enabled = qq->Locate("N", "CHECK_TXSLD", lo);
  rbCheckSequences->Enabled = qq->Locate("N", "CHECK_SEQUENCES", lo);
  rbCheckTunigIssues->Enabled = qq->Locate("N", "CHECK_TUNING_ISSUES", lo);

  qq->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfTOAD::sqqAfterExecute(TObject *Sender, bool Result)
{
	StopExecTimer(btSuccess);
}
//---------------------------------------------------------------------------

