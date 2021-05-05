object dmCassa: TdmCassa
  OldCreateOrder = False
  Height = 528
  Width = 726
  object dsBiltets: TDataSource
    DataSet = qsBiltets
    Left = 112
    Top = 112
  end
  object dsV1_CASALENTA: TDataSource
    DataSet = qsV1_CASALENTA
    Left = 104
    Top = 64
  end
  object dsDocs: TDataSource
    DataSet = qsDocs
    Left = 272
    Top = 8
  end
  object dsD_Cassa: TDataSource
    DataSet = qsD_Cassa
    Left = 272
    Top = 56
  end
  object dsCasaTotals: TDataSource
    DataSet = qsCasaTotals
    Left = 272
    Top = 168
  end
  object dsD_CassaP: TDataSource
    DataSet = qsD_CassaP
    Left = 272
    Top = 104
  end
  object qq: TSmartQuery
    AutoCommit = False
    Left = 8
    Top = 56
  end
  object spCF: TOraStoredProc
    StoredProcName = 'CALL_FUNCT'
    SQL.Strings = (
      'begin'
      '  :RESULT := CALL_FUNCT(:FN, :P1, :P2, :P3);'
      'end;')
    Left = 112
    Top = 272
    ParamData = <
      item
        DataType = ftString
        Name = 'RESULT'
        ParamType = ptOutput
        Size = 2000
        Value = nil
      end
      item
        DataType = ftString
        Name = 'FN'
        ParamType = ptInput
        Size = 2000
        Value = nil
      end
      item
        DataType = ftString
        Name = 'P1'
        ParamType = ptInput
        Size = 2000
        Value = nil
      end
      item
        DataType = ftString
        Name = 'P2'
        ParamType = ptInput
        Size = 2000
        Value = nil
      end
      item
        DataType = ftString
        Name = 'P3'
        ParamType = ptInput
        Size = 2000
        Value = nil
      end>
  end
  object spDavaiProd: TOraStoredProc
    StoredProcName = 'CASADAVAIPRODAVAI'
    SQL.Strings = (
      'begin'
      
        '  CASADAVAIPRODAVAI(:VDATA, :VRUTA, :VCASIR, :VCASA, :VCODORAS, ' +
        ':VCODGARA, :VIDCASLENTA, :VNRLOCSEL, :STRLOCSEL, :VBRONI_ORD_RES' +
        ');'
      'end;')
    Left = 112
    Top = 320
    ParamData = <
      item
        DataType = ftDateTime
        Name = 'VDATA'
        ParamType = ptInput
        Value = nil
      end
      item
        DataType = ftString
        Name = 'VRUTA'
        ParamType = ptInput
        Size = 10
        Value = nil
      end
      item
        DataType = ftFloat
        Name = 'VCASIR'
        ParamType = ptInput
        Value = nil
      end
      item
        DataType = ftString
        Name = 'VCASA'
        ParamType = ptInput
        Size = 5
        Value = nil
      end
      item
        DataType = ftFloat
        Name = 'VCODORAS'
        ParamType = ptInput
        Value = nil
      end
      item
        DataType = ftFloat
        Name = 'VCODGARA'
        ParamType = ptInput
        Value = nil
      end
      item
        DataType = ftFloat
        Name = 'VIDCASLENTA'
        ParamType = ptInput
        Value = nil
      end
      item
        DataType = ftFloat
        Name = 'VNRLOCSEL'
        ParamType = ptInput
        Value = nil
      end
      item
        DataType = ftString
        Name = 'STRLOCSEL'
        ParamType = ptInput
        Size = 2000
        Value = nil
      end
      item
        DataType = ftFloat
        Name = 'VBRONI_ORD_RES'
        ParamType = ptInput
        Value = nil
      end>
  end
  object spWonaToSell: TOraStoredProc
    StoredProcName = 'CASAWONATOSELL'
    SQL.Strings = (
      'begin'
      
        '  CASAWONATOSELL(:VRUTA, :VDATA, :VBILETCOUNT, :VLOCURES, :VCODO' +
        'RAS);'
      'end;')
    Left = 176
    Top = 320
    ParamData = <
      item
        DataType = ftString
        Name = 'VRUTA'
        ParamType = ptInput
        Size = 10
        Value = nil
      end
      item
        DataType = ftDateTime
        Name = 'VDATA'
        ParamType = ptInput
        Value = nil
      end
      item
        DataType = ftFloat
        Name = 'VBILETCOUNT'
        ParamType = ptInput
        Value = nil
      end
      item
        DataType = ftString
        Name = 'VLOCURES'
        ParamType = ptInput
        Size = 2000
        Value = nil
      end
      item
        DataType = ftFloat
        Name = 'VCODORAS'
        ParamType = ptInput
        Value = nil
      end>
  end
  object qsDocs: TSmartQuery
    SQL.Strings = (
      'SELECT TMDB_DOCS.*  FROM TMDB_DOCS'
      'where COD=:COD')
    FetchRows = 1
    Left = 344
    Top = 8
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'COD'
        Value = nil
      end>
    object qsDocsCOD: TFloatField
      FieldName = 'COD'
      Required = True
    end
    object qsDocsDATAMANUAL: TDateTimeField
      FieldName = 'DATAMANUAL'
      Required = True
    end
    object qsDocsDATA: TDateTimeField
      FieldName = 'DATA'
      Required = True
    end
    object qsDocsTIP: TStringField
      FieldName = 'TIP'
      Size = 1
    end
    object qsDocsCODF: TIntegerField
      FieldName = 'CODF'
    end
    object qsDocsUSERID: TIntegerField
      FieldName = 'USERID'
    end
    object qsDocsNRMANUAL: TStringField
      FieldName = 'NRMANUAL'
      Size = 25
    end
  end
  object qsD_Cassa: TSagiODACSmartQuery
    FullRefresh = True
    SQLInsert.Strings = (
      'INSERT INTO TMDB_CASSA'
      '  (COD, DATA, PERS_ID, SUMA)'
      'VALUES'
      '  (:COD, :DATA, :PERS_ID, :SUMA)')
    SQLUpdate.Strings = (
      'UPDATE TMDB_CASSA'
      'SET'
      '  DATA = :DATA,'
      '  SUMA = :SUMA'
      'WHERE'
      '  COD = :OLD_COD and'
      '  DATA = :OLD_DATA')
    SQLRefresh.Strings = (
      'WHERE'
      '  COD = :COD and'
      '  DATA = :DATA')
    SQLLock.Strings = (
      'SELECT * FROM VMDB_CASA'
      'WHERE'
      '  COD = :COD and'
      '  DATA = :DATA'
      'FOR UPDATE NOWAIT')
    SQL.Strings = (
      'SELECT VMDB_CASA.*  FROM VMDB_CASA'
      ' WHERE '
      '(COD=:COD and ISPREDAT IS NULL)')
    MasterSource = dsDocs
    RefreshOptions = [roAfterInsert, roAfterUpdate, roBeforeEdit]
    Options.RequiredFields = False
    Options.FullRefresh = True
    AfterPost = qsD_CassaAfterPost
    OnCalcFields = qsD_CassaCalcFields
    OnNewRecord = qsD_CassaNewRecord
    SagiKeyFields = 'COD;DATA'
    SagiMode = True
    SagiTableLive = 'VMDB_CASA'
    SagiFilterSYS = 'COD=:COD and ISPREDAT IS NULL'
    SagiSimpleRefresh = True
    SagiEditRefreshNotNeed = True
    SagiSQLServer = True
    Left = 344
    Top = 56
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'COD'
        Value = nil
      end>
    object qsD_CassaCOD: TFloatField
      FieldName = 'COD'
      Required = True
    end
    object qsD_CassaDATA: TDateTimeField
      FieldName = 'DATA'
    end
    object qsD_CassaISPREDAT: TIntegerField
      FieldName = 'ISPREDAT'
    end
    object qsD_CassaPERS_ID: TFloatField
      FieldName = 'PERS_ID'
      Required = True
    end
    object qsD_CassaSUMA: TFloatField
      FieldName = 'SUMA'
    end
    object qsD_CassaPERS_IDT: TStringField
      FieldName = 'PERS_IDT'
      Size = 122
    end
    object qsD_CassaCasir: TStringField
      FieldKind = fkCalculated
      FieldName = 'Casir'
      Size = 100
      Calculated = True
    end
    object qsD_CassaSUMAVAL: TFloatField
      FieldName = 'SUMAVAL'
    end
    object qsD_CassaVALUTA: TStringField
      FieldName = 'VALUTA'
      Size = 3
    end
  end
  object qsD_CassaP: TSagiODACSmartQuery
    FullRefresh = True
    SQLInsert.Strings = (
      'INSERT INTO TMDB_CASSA'
      '  (COD, DATA, ISPREDAT, PERS_ID, SUMA)'
      'VALUES'
      '  (:COD, :DATA, 1, :PERS_ID, :SUMA)')
    SQLUpdate.Strings = (
      'UPDATE TMDB_CASSA'
      'SET'
      '  DATA = :DATA,'
      '  ISPREDAT = 1,'
      '  PERS_ID = :PERS_ID,'
      '  SUMA = :SUMA'
      'WHERE'
      '  COD = :OLD_COD and'
      '  DATA = :OLD_DATA')
    SQLRefresh.Strings = (
      'WHERE'
      '  COD = :COD and'
      '  DATA = :DATA')
    SQL.Strings = (
      'SELECT VMDB_CASA.*  FROM VMDB_CASA'
      ' WHERE '
      '(COD=:COD and ISPREDAT=1)')
    MasterSource = dsDocs
    RefreshOptions = [roAfterInsert, roAfterUpdate, roBeforeEdit]
    Options.RequiredFields = False
    Options.FullRefresh = True
    AfterPost = qsD_CassaPAfterPost
    OnCalcFields = qsD_CassaPCalcFields
    OnNewRecord = qsD_CassaPNewRecord
    SagiKeyFields = 'COD;DATA'
    SagiMode = True
    SagiTableLive = 'VMDB_CASA'
    SagiFilterSYS = 'COD=:COD and ISPREDAT=1'
    SagiSimpleRefresh = True
    SagiEditRefreshNotNeed = True
    SagiSQLServer = True
    Left = 344
    Top = 104
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'COD'
        Value = nil
      end>
    object qsD_CassaPCasir: TStringField
      FieldKind = fkCalculated
      FieldName = 'Casir'
      Size = 100
      Calculated = True
    end
    object qsD_CassaPCOD: TFloatField
      FieldName = 'COD'
      Required = True
    end
    object qsD_CassaPDATA: TDateTimeField
      FieldName = 'DATA'
    end
    object qsD_CassaPISPREDAT: TIntegerField
      FieldName = 'ISPREDAT'
    end
    object qsD_CassaPPERS_ID: TFloatField
      FieldName = 'PERS_ID'
      Required = True
    end
    object qsD_CassaPSUMA: TFloatField
      FieldName = 'SUMA'
    end
    object qsD_CassaPPERS_IDT: TStringField
      FieldName = 'PERS_IDT'
      Size = 122
    end
    object qsD_CassaPSUMAVAL: TFloatField
      FieldName = 'SUMAVAL'
    end
    object qsD_CassaPVALUTA: TStringField
      FieldName = 'VALUTA'
      Size = 3
    end
  end
  object qqCheckLockRuta: TSmartQuery
    SQL.Strings = (
      'select * from VS_WHATCASASELL'
      'where RUTA=:CODU and trunc(DATA)=:DATA')
    Left = 344
    Top = 320
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CODU'
        Value = nil
      end
      item
        DataType = ftDateTime
        Name = 'DATA'
        ParamType = ptInput
        Value = nil
      end>
  end
  object qsV1_CASALENTA: TSagiODACSmartQuery
    FullRefresh = True
    DMLRefresh = True
    SQLUpdate.Strings = (
      'UPDATE V1_CASALENTA_VAL'
      'SET'
      '  SUMA_PRIM = :SUMA_PRIM,'
      '  DESCR = :DESCR,'
      '  ISRET = :ISRET,'
      '  ACCEPT = :ACCEPT,'
      '  SUMAVAL_PRIM = :SUMAVAL_PRIM,'
      '  VALUTA = :VALUTA'
      'WHERE'
      '  ID = :OLD_ID')
    SQLRefresh.Strings = (
      'WHERE'
      '  ID = :ID')
    SQL.Strings = (
      'SELECT *  FROM V1_CASALENTA_VAL'
      'where id = :id')
    MasterSource = dsSetBlits
    RefreshOptions = [roAfterInsert, roAfterUpdate]
    Options.FullRefresh = True
    AfterOpen = qsV1_CASALENTAAfterOpen
    AfterClose = qsV1_CASALENTAAfterClose
    OnCalcFields = qsV1_CASALENTACalcFields
    SagiSimpleRefresh = True
    SagiEditRefreshNotNeed = True
    Left = 176
    Top = 64
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'id'
        Value = nil
      end>
    object qsV1_CASALENTAID: TIntegerField
      FieldName = 'ID'
      Required = True
    end
    object qsV1_CASALENTACASIR: TIntegerField
      FieldName = 'CASIR'
      Required = True
    end
    object qsV1_CASALENTACASA: TStringField
      FieldName = 'CASA'
      Required = True
      Size = 5
    end
    object qsV1_CASALENTASUMA_PACH: TFloatField
      FieldName = 'SUMA_PACH'
      Required = True
    end
    object qsV1_CASALENTASUMA_PRIM: TFloatField
      FieldName = 'SUMA_PRIM'
      OnChange = qsV1_CASALENTASUMA_PRIMChange
    end
    object qsV1_CASALENTADATA: TDateTimeField
      FieldName = 'DATA'
    end
    object qsV1_CASALENTAclcSumaRest: TFloatField
      FieldKind = fkCalculated
      FieldName = 'clcSumaRest'
      DisplayFormat = '### ### ### ##0.00'
      EditFormat = '### ### ### ##0.00'
      Calculated = True
    end
    object qsV1_CASALENTADESCR: TStringField
      FieldName = 'DESCR'
      Size = 50
    end
    object qsV1_CASALENTAISRET: TStringField
      FieldName = 'ISRET'
      Size = 1
    end
    object qsV1_CASALENTAACCEPT: TIntegerField
      FieldName = 'ACCEPT'
    end
    object qsV1_CASALENTASUMAVAL_PACH: TFloatField
      FieldName = 'SUMAVAL_PACH'
    end
    object qsV1_CASALENTASUMAVAL_PRIM: TFloatField
      FieldName = 'SUMAVAL_PRIM'
    end
    object qsV1_CASALENTAVALUTA: TStringField
      FieldName = 'VALUTA'
      Size = 3
    end
  end
  object qsCasaTotals: TSagiODACSmartQuery
    DMLRefresh = True
    SQL.Strings = (
      'select distinct C1.casir,C1.casa,--sum(C1.suma_pach),'
      '('
      'select sum(C3.suma_pach) from T1CASALENTA C3'
      'where isret is null and '
      
        'C3.CASIR=:CASIR and C3.CASA=:CASA and trunc(C3.DATA)=trunc(to_da' +
        'te(:DATA))'
      'group by C3.casir,C3.casa'
      ') SUMA_PRIM,'
      '('
      'select sum(C2.suma_prim) from T1CASALENTA C2'
      'where isret is not null and '
      
        'C2.CASIR=:CASIR and C2.CASA=:CASA and trunc(C2.DATA)=trunc(to_da' +
        'te(:DATA))'
      'group by C2.casir,C2.casa'
      ') SUMA_RET'
      ' from T1CASALENTA C1'
      ' where '
      'C1.CASIR=:CASIR'
      ' and '
      'C1.CASA=:CASA'
      ' and'
      'trunc(C1.DATA)=trunc(to_date(:DATA))')
    AfterOpen = qsCasaTotalsAfterOpen
    Left = 344
    Top = 152
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CASIR'
        Value = nil
      end
      item
        DataType = ftUnknown
        Name = 'CASA'
        Value = nil
      end
      item
        DataType = ftUnknown
        Name = 'DATA'
        Value = nil
      end>
    object qsCasaTotalsCASIR: TIntegerField
      FieldName = 'CASIR'
      Required = True
    end
    object qsCasaTotalsCASA: TStringField
      FieldName = 'CASA'
      Required = True
      Size = 5
    end
    object qsCasaTotalsSUMA_PRIM: TFloatField
      FieldName = 'SUMA_PRIM'
    end
    object qsCasaTotalsSUMA_RET: TFloatField
      FieldName = 'SUMA_RET'
    end
  end
  object qsBiltets: TSagiODACSmartQuery
    SQLDelete.Strings = (
      'DELETE FROM V0_BILETS'
      'WHERE'
      '  COD = :COD')
    SQLUpdate.Strings = (
      'UPDATE V0_BILETS'
      'SET'
      '  INLESN = :INLESN,'
      '  DEPART = :DEPART,'
      '  CERTIFICAT = :CERTIFICAT,'
      '  PERS_NUMELE = :PERS_NUMELE,'
      '  PERS_PRUMELE = :PERS_PRUMELE,'
      '  PERS_PATRON = :PERS_PATRON,'
      '  PASAPORT = :PASAPORT,'
      '  BAGAJ = :BAGAJ'
      'WHERE'
      '  COD = :OLD_COD')
    SQLRefresh.Strings = (
      'WHERE'
      '  COD = :COD')
    SQLLock.Strings = (
      'SELECT * FROM V0_BILETS'
      'WHERE'
      '  COD = :COD'
      'FOR UPDATE NOWAIT')
    SQL.Strings = (
      
        'SELECT  COD, DATA, to_char(date_time, '#39'hh24:mi'#39') s_time, RUTA, L' +
        'OC, IDCASLENTA, '
      ' CODADD, INLESN, DEPART, CERTIFICAT, PERS_NUMELE, '
      ' PERS_PRUMELE, PERS_PATRON, PASAPORT, BAGAJ, INPIC, '
      ' PRINTS'
      
        ', decode(nvl(sys_context('#39'GRACONTEXT'#39','#39'SESS_ValCURS_D'#39'),1.0),1.0' +
        ', SUMAT,SUMAVALT) SUMAT'
      
        '--  *un$to_number(nvl(sys_context('#39'GRACONTEXT'#39','#39'SESS_ValCURS_D'#39')' +
        ',1.0)) SUMAT'
      ', CECU'
      ',PRET_BRONARE_ESTIMAT'
      ',RIND_LOC_STRING'
      ' FROM V0_BILETS'
      'WHERE'
      '(IDCASLENTA=:ID)'
      'ORDER BY loc')
    MasterSource = dsSetBlits
    FetchAll = True
    BeforeInsert = qsBiltetsBeforeInsert
    BeforeEdit = qsBiltetsBeforeEdit
    AfterEdit = qsSetBlitsAfterEdit
    AfterPost = qsBiltetsAfterPost
    OnEditError = qsBiltetsEditError
    SagiKeyFields = 'COD'
    SagiMode = True
    SagiGroupField = 'loc'
    SagiFilterSYS = 'IDCASLENTA=:ID'
    SagiSQL1.Strings = (
      
        'SELECT  COD, DATA, to_char(date_time, '#39'hh24:mi'#39') s_time, RUTA, L' +
        'OC, IDCASLENTA, '
      ' CODADD, INLESN, DEPART, CERTIFICAT, PERS_NUMELE, '
      ' PERS_PRUMELE, PERS_PATRON, PASAPORT, BAGAJ, INPIC, '
      ' PRINTS'
      
        ', decode(nvl(sys_context('#39'GRACONTEXT'#39','#39'SESS_ValCURS_D'#39'),1.0),1.0' +
        ', SUMAT,SUMAVALT) SUMAT'
      
        '--  *un$to_number(nvl(sys_context('#39'GRACONTEXT'#39','#39'SESS_ValCURS_D'#39')' +
        ',1.0)) SUMAT'
      ', CECU'
      ',PRET_BRONARE_ESTIMAT'
      ',RIND_LOC_STRING'
      ' FROM V0_BILETS')
    SagiSimpleRefresh = True
    SagiEditRefreshNotNeed = True
    SagiSQLServer = True
    Left = 176
    Top = 120
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'ID'
        Value = nil
      end>
    object qsBiltetsCOD: TStringField
      FieldName = 'COD'
      Required = True
      Size = 15
    end
    object qsBiltetsDATA: TDateTimeField
      FieldName = 'DATA'
    end
    object qsBiltetsRUTA: TStringField
      FieldName = 'RUTA'
      Required = True
      Size = 10
    end
    object qsBiltetsLOC: TIntegerField
      FieldName = 'LOC'
    end
    object qsBiltetsIDCASLENTA: TIntegerField
      FieldName = 'IDCASLENTA'
    end
    object qsBiltetsCODADD: TStringField
      FieldName = 'CODADD'
      Size = 15
    end
    object qsBiltetsINLESN: TStringField
      FieldName = 'INLESN'
      OnChange = qsBiltetsINLESNChange
      Size = 2
    end
    object qsBiltetsDEPART: TFloatField
      FieldName = 'DEPART'
    end
    object qsBiltetsCERTIFICAT: TStringField
      FieldName = 'CERTIFICAT'
      Size = 50
    end
    object qsBiltetsPERS_NUMELE: TStringField
      FieldName = 'PERS_NUMELE'
      Size = 50
    end
    object qsBiltetsPERS_PRUMELE: TStringField
      FieldName = 'PERS_PRUMELE'
      Size = 1
    end
    object qsBiltetsPERS_PATRON: TStringField
      FieldName = 'PERS_PATRON'
      Size = 1
    end
    object qsBiltetsPASAPORT: TStringField
      FieldName = 'PASAPORT'
      Size = 50
    end
    object qsBiltetsBAGAJ: TIntegerField
      FieldName = 'BAGAJ'
    end
    object qsBiltetsINPIC: TIntegerField
      FieldName = 'INPIC'
    end
    object qsBiltetsPRINTS: TIntegerField
      FieldName = 'PRINTS'
    end
    object qsBiltetsSUMAT: TFloatField
      FieldName = 'SUMAT'
    end
    object qsBiltetsCECU: TStringField
      FieldName = 'CECU'
      ProviderFlags = []
      ReadOnly = True
      Size = 4000
      Transliterate = False
    end
    object qsBiltetsPRET_BRONARE_ESTIMAT: TFloatField
      FieldName = 'PRET_BRONARE_ESTIMAT'
    end
    object qsBiltetsRIND_LOC_STRING: TStringField
      FieldName = 'RIND_LOC_STRING'
      Size = 4000
    end
    object qsBiltetsS_TIME: TStringField
      FieldName = 'S_TIME'
      Size = 5
    end
  end
  object qqIsVinzEn: TSmartQuery
    SQL.Strings = (
      'select codu from t1ruta_m '
      'where CODU=:CODU and trunc(DATA)=trunc(to_date(:DATA))'
      'for update')
    Left = 240
    Top = 320
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CODU'
        Value = nil
      end
      item
        DataType = ftDateTime
        Name = 'DATA'
        ParamType = ptInput
        Value = nil
      end>
  end
  object SQLMonitor: TOraSQLMonitor
    Active = False
    Options = [moDialog, moSQLMonitor, moCustom]
    Left = 32
    Top = 120
  end
  object qsSetBlits: TSagiODACSmartQuery
    DMLRefresh = True
    SQLInsert.Strings = (
      'INSERT INTO V1_CASALENTA'
      
        '  (ID, CASIR, CASA, SUMA_PACH, SUMA_PRIM, DATA, DESCR, ISRET, AC' +
        'CEPT)'
      'VALUES'
      
        '  (:ID, :CASIR, :CASA, :SUMA_PACH, :SUMA_PRIM, :DATA, :DESCR, :I' +
        'SRET, :ACCEPT)'
      'RETURNING'
      
        '  ID, CASIR, CASA, SUMA_PACH, SUMA_PRIM, DATA, DESCR, ISRET, ACC' +
        'EPT'
      'INTO'
      
        '  :ID, :CASIR, :CASA, :SUMA_PACH, :SUMA_PRIM, :DATA, :DESCR, :IS' +
        'RET, :ACCEPT')
    SQLDelete.Strings = (
      'DELETE FROM V1_CASALENTA'
      'WHERE'
      '  ID = :ID')
    SQLUpdate.Strings = (
      'UPDATE V1_CASALENTA'
      'SET'
      '  ID = :ID,'
      '  CASIR = :CASIR,'
      '  CASA = :CASA,'
      '  SUMA_PACH = :SUMA_PACH,'
      '  SUMA_PRIM = :SUMA_PRIM,'
      '  DATA = :DATA,'
      '  DESCR = :DESCR,'
      '  ISRET = :ISRET,'
      '  ACCEPT = :ACCEPT'
      'WHERE'
      '  ID = :OLD_ID'
      'RETURNING'
      
        '  ID, CASIR, CASA, SUMA_PACH, SUMA_PRIM, DATA, DESCR, ISRET, ACC' +
        'EPT'
      'INTO'
      
        '  :ID, :CASIR, :CASA, :SUMA_PACH, :SUMA_PRIM, :DATA, :DESCR, :IS' +
        'RET, :ACCEPT')
    SQLRefresh.Strings = (
      'WHERE'
      '  ID = :ID')
    SQLLock.Strings = (
      'SELECT * FROM V1_CASALENTA'
      'WHERE'
      '  ID = :ID'
      'FOR UPDATE NOWAIT')
    SQL.Strings = (
      'SELECT V1_CASALENTA.ID  FROM V1_CASALENTA'
      ' WHERE'
      '(ID=:ID)')
    AfterOpen = qsV1_CASALENTAAfterOpen
    OnCalcFields = qsV1_CASALENTACalcFields
    SagiKeyFields = 'ID'
    SagiSimpleRefresh = True
    SagiEditRefreshNotNeed = True
    Left = 176
    Top = 8
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'ID'
        Value = nil
      end>
    object qsSetBlitsID: TIntegerField
      FieldName = 'ID'
      Required = True
    end
  end
  object dsSetBlits: TDataSource
    DataSet = qsSetBlits
    Left = 112
    Top = 8
  end
  object ospSetCasaGroup: TOraStoredProc
    StoredProcName = 'SETNIVELCASA'
    SQL.Strings = (
      'begin'
      '  SETNIVELCASA(:VIDNIVEL);'
      'end;')
    Left = 176
    Top = 272
    ParamData = <
      item
        DataType = ftFloat
        Name = 'VIDNIVEL'
        ParamType = ptInput
        Value = nil
      end>
  end
  object osqIMB: TOraStoredProc
    StoredProcName = 'G2002REPS.LISTA_DE_IMBARCARE'
    SQL.Strings = (
      'begin'
      
        '  :RESULT := G2002REPS.LISTA_DE_IMBARCARE(:VPDATA, :PRUTA, :PIDC' +
        'ASALENTA, :PCLIENTAPPTYPE, :PPRINTGR);'
      'end;')
    Left = 24
    Top = 296
    ParamData = <
      item
        DataType = ftString
        Name = 'RESULT'
        ParamType = ptOutput
        Value = nil
      end
      item
        DataType = ftDateTime
        Name = 'VPDATA'
        ParamType = ptInput
        Value = nil
      end
      item
        DataType = ftString
        Name = 'PRUTA'
        ParamType = ptInput
        Value = nil
      end
      item
        DataType = ftFloat
        Name = 'PIDCASALENTA'
        ParamType = ptInput
        Value = nil
      end
      item
        DataType = ftFloat
        Name = 'PCLIENTAPPTYPE'
        ParamType = ptInput
        Value = 2
      end
      item
        DataType = ftFloat
        Name = 'PPRINTGR'
        ParamType = ptInput
        Value = nil
      end>
  end
  object osmFullCasaLentaPrev: TSagiODACSmartQuery
    FullRefresh = True
    DMLRefresh = True
    SQL.Strings = (
      'SELECT FullCasaLentaPrev.* FROM FullCasaLentaPrev'
      ' ORDER BY data desc,ruta desc')
    ReadOnly = True
    Options.FullRefresh = True
    AfterOpen = qsV1_CASALENTAAfterOpen
    OnCalcFields = qsV1_CASALENTACalcFields
    SagiMode = True
    SagiTableLive = 'FullCasaLentaPrev'
    SagiGroupField = 'data desc,ruta desc'
    SagiSQL1.Strings = (
      'SELECT C.*'
      
        ',(SELECT r.DENUMIREA||'#39','#39'||TO_CHAR(m.D1,'#39'HH24:MI'#39') FROM T0BILET ' +
        'b ,T1RUTA_M  m, T0RUTA r WHERE  r.codu=m.RUTADEBAZA AND b.RUTA=m' +
        '.CODU AND TRUNC(b.data)=TRUNC(m.data) AND b.IDCASLENTA=C.ID AND ' +
        'ROWNUM=1) RUTA'
      
        ',(SELECT PRINTGR FROM T1LISTIMB_VPRON P WHERE P.IDCASLENTA=C.ID)' +
        ' PRINTGR'
      ' FROM V1_CASALENTA C')
    SagiSimpleRefresh = True
    SagiEditRefreshNotNeed = True
    SagiSQLServer = True
    Left = 176
    Top = 176
    object osmFullCasaLentaPrevID: TIntegerField
      FieldName = 'ID'
      Required = True
    end
    object osmFullCasaLentaPrevCASIR: TIntegerField
      FieldName = 'CASIR'
      Required = True
    end
    object osmFullCasaLentaPrevCASA: TStringField
      FieldName = 'CASA'
      Required = True
      Size = 5
    end
    object osmFullCasaLentaPrevSUMA_PACH: TFloatField
      FieldName = 'SUMA_PACH'
      Required = True
    end
    object osmFullCasaLentaPrevSUMA_PRIM: TFloatField
      FieldName = 'SUMA_PRIM'
    end
    object osmFullCasaLentaPrevDATA: TDateTimeField
      FieldName = 'DATA'
    end
    object osmFullCasaLentaPrevDESCR: TStringField
      FieldName = 'DESCR'
      Size = 50
    end
    object osmFullCasaLentaPrevISRET: TStringField
      FieldName = 'ISRET'
      FixedChar = True
      Size = 1
    end
    object osmFullCasaLentaPrevACCEPT: TIntegerField
      FieldName = 'ACCEPT'
    end
    object osmFullCasaLentaPrevRUTA: TStringField
      FieldName = 'RUTA'
      Size = 31
    end
    object osmFullCasaLentaPrevPRINTGR: TFloatField
      FieldName = 'PRINTGR'
    end
    object osmFullCasaLentaPrevVALUTA: TStringField
      FieldName = 'VALUTA'
      Size = 3
    end
  end
  object dsmFullCasaLentaPrev: TDataSource
    DataSet = osmFullCasaLentaPrev
    Left = 112
    Top = 160
  end
  object qsT1RUTABRONI: TSagiODACSmartQuery
    SQLInsert.Strings = (
      'INSERT INTO T1RUTABRONI'
      
        '  (IDCASALENTA, RUTA, DATA, TIPBRONI, DOCUMENT, ADDINFO, BILETCO' +
        'UNT, STAREA)'
      'VALUES'
      
        '  (:IDCASALENTA, :RUTA, :DATA, :TIPBRONI, :DOCUMENT, :ADDINFO, :' +
        'BILETCOUNT, :STAREA)')
    SQLUpdate.Strings = (
      'UPDATE T1RUTABRONI'
      'SET'
      '  IDCASALENTA = :IDCASALENTA,'
      '  RUTA = :RUTA,'
      '  DATA = :DATA,'
      '  TIPBRONI = :TIPBRONI,'
      '  DOCUMENT = :DOCUMENT,'
      '  ADDINFO = :ADDINFO,'
      '  BILETCOUNT = :BILETCOUNT,'
      '  STAREA = :STAREA'
      'WHERE'
      '  IDCASALENTA = :OLD_IDCASALENTA')
    SQLRefresh.Strings = (
      'WHERE'
      '  IDCASALENTA = :IDCASALENTA')
    SQL.Strings = (
      'SELECT T1RUTABRONI.*  FROM T1RUTABRONI '
      ' WHERE '
      '(idcasalenta=:ID)')
    MasterSource = dsSetBlits
    LockMode = lmNone
    AfterInsert = qsT1RUTABRONIAfterInsert
    SagiKeyFields = 'idcasalenta'
    SagiModeNotAbort = True
    SagiTableLive = 'T1RUTABRONI'
    SagiFilterSYS = 'idcasalenta=:ID'
    SagiEditRefreshNotNeed = True
    SagiSQLServer = True
    Left = 112
    Top = 224
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'ID'
        Value = nil
      end>
    object qsT1RUTABRONIIDCASALENTA: TIntegerField
      FieldName = 'IDCASALENTA'
      Required = True
    end
    object qsT1RUTABRONIRUTA: TStringField
      FieldName = 'RUTA'
      Size = 10
    end
    object qsT1RUTABRONIDATA: TDateTimeField
      FieldName = 'DATA'
    end
    object qsT1RUTABRONITIPBRONI: TIntegerField
      FieldName = 'TIPBRONI'
    end
    object qsT1RUTABRONIDOCUMENT: TStringField
      FieldName = 'DOCUMENT'
      Size = 200
    end
    object qsT1RUTABRONIADDINFO: TStringField
      FieldName = 'ADDINFO'
      Size = 200
    end
    object qsT1RUTABRONIBILETCOUNT: TIntegerField
      FieldName = 'BILETCOUNT'
    end
    object qsT1RUTABRONISTAREA: TIntegerField
      FieldName = 'STAREA'
    end
  end
  object dsT1RUTABRONI: TOraDataSource
    DataSet = qsT1RUTABRONI
    Left = 48
    Top = 224
  end
  object sqValuta: TSagiODACSmartQuery
    SQL.Strings = (
      'SELECT TMS_SYSS.* FROM TMS_SYSS'
      ' WHERE '
      '(tip='#39'S'#39' and cod=3 and um<>'#39'*'#39') order by cod1')
    LockMode = lmNone
    AfterInsert = qsT1RUTABRONIAfterInsert
    SagiKeyFields = 'cod1'
    SagiModeNotAbort = True
    SagiGroupField = 'cod1'
    SagiFilterSYS = 'tip='#39'S'#39' and cod=3'
    SagiEditRefreshNotNeed = True
    SagiSQLServer = True
    Left = 344
    Top = 200
  end
  object ConnectDialog1: TConnectDialog
    DialogClass = 'TfStart'
    Caption = 'Connect'
    ConnectButton = 'Connect'
    CancelButton = 'Cancel'
    Server.Caption = 'Server'
    Server.Visible = True
    Server.Order = 1
    UserName.Caption = 'User Name'
    UserName.Visible = True
    UserName.Order = 2
    Password.Caption = 'Password'
    Password.Visible = True
    Password.Order = 3
    Home.Caption = 'Home Name'
    Home.Visible = False
    Home.Order = 0
    Direct.Caption = 'Direct'
    Direct.Visible = False
    Direct.Order = 6
    Schema.Caption = 'Schema'
    Schema.Visible = False
    Schema.Order = 4
    Role.Caption = 'Connect Mode'
    Role.Visible = False
    Role.Order = 5
    LabelSet = lsCustom
    Left = 32
    Top = 176
  end
  object db: TSagiOraSession
    Username = 'tickets'
    Server = 'cloudbd'
    AutoCommit = False
    ConnectDialog = ConnectDialog1
    Left = 8
    Top = 8
    EncryptedPassword = '8BFF96FF9CFF94FF9AFF8BFF8CFF'
  end
  object qComplexFilt: TSmartQuery
    KeyFields = 'ID'
    Session = db
    SQL.Strings = (
      'select id, denumirea from tms_syss'
      '  where cod1 > 0 and cod = :cod and tip = :tip and um=:um'
      '  order by cod1')
    Left = 504
    Top = 8
    ParamData = <
      item
        DataType = ftFloat
        Name = 'cod'
        ParamType = ptInput
        Value = 33
      end
      item
        DataType = ftString
        Name = 'tip'
        ParamType = ptInput
        Value = 'G0'
      end
      item
        DataType = ftUnknown
        Name = 'um'
        Value = nil
      end>
  end
  object dsComplexFilt: TDataSource
    DataSet = qComplexFilt
    Left = 424
    Top = 8
  end
  object spAccess: TOraStoredProc
    StoredProcName = 'ISUSERVALID'
    Session = db
    SQL.Strings = (
      'begin'
      '  :RESULT := ISUSERVALID(:USER, :PASSW);'
      'end;')
    Left = 584
    Top = 16
    ParamData = <
      item
        DataType = ftFloat
        Name = 'RESULT'
        ParamType = ptOutput
        Value = nil
      end
      item
        DataType = ftString
        Name = 'USER'
        ParamType = ptInput
        Size = 2000
        Value = nil
      end
      item
        DataType = ftString
        Name = 'PASSW'
        ParamType = ptInput
        Size = 2000
        Value = nil
      end>
  end
  object spRegComp: TOraStoredProc
    StoredProcName = 'REGISTERCOMP'
    Session = db
    SQL.Strings = (
      'begin'
      '  :RESULT := REGISTERCOMP(:COMPID, :VUSERID, :NRDOC);'
      'end;')
    AfterExecute = spRegCompAfterExecute
    Left = 584
    Top = 72
    ParamData = <
      item
        DataType = ftString
        Name = 'RESULT'
        ParamType = ptOutput
        Size = 2000
        Value = nil
      end
      item
        DataType = ftString
        Name = 'COMPID'
        ParamType = ptInput
        Size = 2000
        Value = nil
      end
      item
        DataType = ftFloat
        Name = 'VUSERID'
        ParamType = ptInput
        Value = nil
      end
      item
        DataType = ftFloat
        Name = 'NRDOC'
        ParamType = ptOutput
        Value = nil
      end>
  end
  object spGetUserInfo: TOraStoredProc
    StoredProcName = 'getuserinfo'
    Session = db
    SQL.Strings = (
      'begin'
      '  getuserinfo(:V_USER_ID, :V_CANNOT_PRINT, :V_IS_SUBAGENT);'
      'end;')
    Left = 584
    Top = 128
    ParamData = <
      item
        DataType = ftFloat
        Name = 'V_USER_ID'
        ParamType = ptInput
        Value = nil
      end
      item
        DataType = ftFloat
        Name = 'V_CANNOT_PRINT'
        ParamType = ptOutput
        Value = nil
      end
      item
        DataType = ftFloat
        Name = 'V_IS_SUBAGENT'
        ParamType = ptOutput
        Value = nil
      end>
  end
  object spGetPrnScript: TOraStoredProc
    StoredProcName = 'ticket_print.get_printer_script'
    Session = db
    SQL.Strings = (
      'begin'
      
        '  :RESULT := ticket_print.get_printer_script(:P_TICKET_NR, :P_TI' +
        'CKET_TYPE);'
      'end;')
    Left = 592
    Top = 192
    ParamData = <
      item
        DataType = ftOraClob
        Name = 'RESULT'
        ParamType = ptOutput
        Value = ''
      end
      item
        DataType = ftString
        Name = 'P_TICKET_NR'
        ParamType = ptInput
        Value = nil
      end
      item
        DataType = ftString
        Name = 'P_TICKET_TYPE'
        ParamType = ptInput
        Value = nil
      end>
  end
  object qCheckBroni: TSmartQuery
    Session = db
    SQL.Strings = (
      'select * from v0online_broni')
    Left = 624
    Top = 360
  end
  object dsCheckBroni: TOraDataSource
    DataSet = qCheckBroni
    Left = 624
    Top = 408
  end
  object dsT1RUTABRONIDETAILS1: TOraDataSource
    DataSet = qsT1RUTABRONIDETAILS
    Left = 80
    Top = 456
  end
  object qsT1RUTABRONIDETAILS: TSagiODACSmartQuery
    SQLInsert.Strings = (
      'INSERT INTO T1RUTABRONI_DETAIL'
      '  (IDCASALENTA, FIRST_NAME, LAST_NAME)'
      'VALUES'
      '  (:IDCASALENTA, :FIRST_NAME, :LAST_NAME)')
    SQLDelete.Strings = (
      'DELETE FROM T1RUTABRONI_DETAIL'
      'WHERE'
      '  IDCASALENTA = :Old_IDCASALENTA')
    SQLUpdate.Strings = (
      'UPDATE T1RUTABRONI_DETAIL'
      'SET'
      '  FIRST_NAME = :FIRST_NAME, LAST_NAME = :LAST_NAME'
      'WHERE'
      '  IDCASALENTA = :Old_IDCASALENTA')
    SQLRefresh.Strings = (
      
        'SELECT IDCASALENTA, FIRST_NAME, LAST_NAME FROM T1RUTABRONI_DETAI' +
        'L'
      'WHERE'
      '  IDCASALENTA = :IDCASALENTA')
    SQLLock.Strings = (
      'FOR UPDATE NOWAIT')
    SQLRecCount.Strings = (
      'SELECT Count(*) FROM ('
      'SELECT * FROM T1RUTABRONI_DETAIL'
      ''
      ')')
    Session = db
    SQL.Strings = (
      
        'SELECT IDCASALENTA, FIRST_NAME, LAST_NAME  FROM T1RUTABRONI_DETA' +
        'IL '
      ' WHERE '
      '(idcasalenta=:ID)')
    MasterFields = 'ID'
    DetailFields = 'IDCASALENTA'
    MasterSource = dsSetBlits
    LockMode = lmNone
    Options.SetFieldsReadOnly = False
    Options.ExtendedFieldsInfo = False
    Left = 32
    Top = 456
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'ID'
        Value = nil
      end>
  end
  object qsCASALENTA_PAYTYPE: TSagiODACSmartQuery
    SQLInsert.Strings = (
      'INSERT INTO T1CASALENTA'
      '  (PAY_TYPE)'
      'VALUES'
      '  (:PAY_TYPE)'
      'RETURNING ID into :ID')
    SQLDelete.Strings = (
      'DELETE FROM T1CASALENTA'
      'WHERE'
      '  ID = :Old_ID')
    SQLUpdate.Strings = (
      'UPDATE T1CASALENTA'
      'SET'
      '  PAY_TYPE = :PAY_TYPE'
      'WHERE'
      '  ID = :Old_ID')
    SQLRefresh.Strings = (
      'SELECT ID, PAY_TYPE FROM T1CASALENTA'
      'WHERE'
      '  ID = :ID')
    SQLLock.Strings = (
      'SELECT ID, PAY_TYPE FROM T1CASALENTA'
      'WHERE'
      '  ID = :Old_ID'
      'FOR UPDATE NOWAIT')
    SQLRecCount.Strings = (
      'SELECT Count(*) FROM ('
      'SELECT * FROM T1CASALENTA'
      ''
      ')')
    Session = db
    SQL.Strings = (
      'SELECT * FROM T1CASALENTA')
    MasterFields = 'IDCASALENTA'
    DetailFields = 'ID'
    MasterSource = dsT1RUTABRONI
    BeforePost = qsCASALENTA_PAYTYPEBeforePost
    Left = 128
    Top = 456
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'IDCASALENTA'
        Value = nil
      end>
  end
end
