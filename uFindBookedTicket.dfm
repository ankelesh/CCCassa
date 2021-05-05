object fBookedTickets: TfBookedTickets
  Left = 500
  Top = 112
  Caption = 'Subagent tickets'
  ClientHeight = 598
  ClientWidth = 520
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 0
    Top = 156
    Width = 520
    Height = 10
    Cursor = crVSplit
    Align = alTop
  end
  object Splitter2: TSplitter
    Left = 0
    Top = 271
    Width = 520
    Height = 10
    Cursor = crVSplit
    Align = alTop
  end
  object Panel1: TPanel
    Left = 0
    Top = 556
    Width = 520
    Height = 42
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    object btOk: TBitBtn
      Left = 72
      Top = 8
      Width = 97
      Height = 25
      Caption = 'OK (Enter)'
      Kind = bkOK
      NumGlyphs = 2
      TabOrder = 0
    end
    object btCancel: TBitBtn
      Left = 216
      Top = 8
      Width = 105
      Height = 25
      Caption = 'Cancel (ESC)'
      Kind = bkCancel
      NumGlyphs = 2
      TabOrder = 1
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 520
    Height = 49
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    object Label1: TLabel
      Left = 17
      Top = 19
      Width = 24
      Height = 13
      Alignment = taRightJustify
      Caption = 'From'
    end
    object Label2: TLabel
      Left = 179
      Top = 20
      Width = 12
      Height = 13
      Alignment = taRightJustify
      Caption = 'Till'
    end
    object dtFrom: TDateTimePicker
      Left = 48
      Top = 16
      Width = 89
      Height = 21
      Date = 41915.920413495400000000
      Time = 41915.920413495400000000
      TabOrder = 0
      OnChange = dtFromChange
    end
    object dtTill: TDateTimePicker
      Left = 200
      Top = 16
      Width = 89
      Height = 21
      Date = 41915.920413495400000000
      Time = 41915.920413495400000000
      TabOrder = 1
      OnChange = dtTillChange
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 49
    Width = 520
    Height = 107
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 3
    object GroupBox2: TGroupBox
      Left = 0
      Top = 0
      Width = 520
      Height = 107
      Align = alClient
      Caption = 'Subagent'
      TabOrder = 0
      object UnDBGrid2: TUnDBGrid
        Left = 2
        Top = 15
        Width = 516
        Height = 90
        Align = alClient
        Color = clInfoBk
        Ctl3D = True
        DataSource = dsUsers
        ParentCtl3D = False
        ReadOnly = True
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'Tahoma'
        TitleFont.Style = []
        XTitleHeight = 17
        SagiKeybMode = 1
        Columns = <
          item
            Color = clInfoBk
            Expanded = False
            FieldName = 'USER_ID'
            ReadOnly = False
            Width = 47
            Visible = True
          end
          item
            Color = clInfoBk
            Expanded = False
            FieldName = 'USER_NAME'
            ReadOnly = False
            Width = 180
            Visible = True
          end>
      end
    end
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 166
    Width = 520
    Height = 105
    Align = alTop
    TabOrder = 2
    object UnDBGrid: TUnDBGrid
      Left = 2
      Top = 15
      Width = 516
      Height = 88
      Align = alClient
      Color = clInfoBk
      Ctl3D = True
      DataSource = dsCasalenta
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
      XTitleHeight = 17
      SagiKeybMode = 1
      Columns = <
        item
          Alignment = taLeftJustify
          Color = clInfoBk
          Expanded = False
          FieldName = 'ID'
          ReadOnly = False
          Width = 47
          Visible = True
        end
        item
          Color = clInfoBk
          Expanded = False
          FieldName = 'CASA'
          ReadOnly = False
          Width = 23
          Visible = True
        end
        item
          Color = clInfoBk
          Expanded = False
          FieldName = 'SUMA_PACH'
          ReadOnly = False
          Width = 47
          Visible = True
        end
        item
          Color = clInfoBk
          Expanded = False
          FieldName = 'DATA'
          ReadOnly = False
          Width = 86
          Visible = True
        end>
    end
  end
  object s: TUnDBGrid
    Left = 0
    Top = 281
    Width = 520
    Height = 275
    Align = alClient
    BorderStyle = bsNone
    Ctl3D = True
    DataSource = dsBilets
    Options = [dgEditing, dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit, dgMultiSelect]
    ParentCtl3D = False
    TabOrder = 4
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    XTitleHeight = 17
    SaveProperties = True
    UnLanguage = lnRus
    Columns = <
      item
        Color = clWindow
        Expanded = False
        FieldName = 'DATA'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        Title.Alignment = taCenter
        Title.Caption = #1044#1072#1090#1072
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -13
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = []
        Width = 75
        Visible = True
      end
      item
        Color = clWindow
        Expanded = False
        FieldName = 'DENUMIREA'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        Title.Alignment = taCenter
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -13
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = []
        Width = 236
        Visible = True
      end
      item
        Color = clWindow
        Expanded = False
        FieldName = 'COD'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        Title.Alignment = taCenter
        Title.Caption = 'Nr bilet'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -13
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = []
        Width = 60
        Visible = True
      end
      item
        ButtonStyle = cbsEllipsis
        Color = clWindow
        Expanded = False
        FieldName = 'INLESN'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        Title.Alignment = taCenter
        Title.Caption = 'Inlesn.'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -13
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = []
        Width = 43
        Visible = True
      end
      item
        ButtonStyle = cbsEllipsis
        Color = clWindow
        Expanded = False
        FieldName = 'DEPART'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        Title.Alignment = taCenter
        Title.Caption = 'Depart.'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -13
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = []
        Width = 48
        Visible = True
      end
      item
        Color = clWindow
        Expanded = False
        FieldName = 'PERS_NUMELE'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        Title.Alignment = taCenter
        Title.Caption = 'Numele, pren.'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -13
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = []
        Width = 90
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'PASAPORT'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        Title.Alignment = taCenter
        Title.Caption = 'Pasaport'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -13
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = []
        Width = 70
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'SUMAT'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        Title.Alignment = taCenter
        Title.Caption = #1050' '#1086#1087#1083'.'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -13
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = []
        Width = 58
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'RIND_LOC_STRING'
        ReadOnly = True
        Title.Caption = 'Rindul si Locul'
        Width = 150
        Visible = True
      end>
    Captions = (
      'DATA=Date,Data,'#1044#1072#1090#1072
      'S_TIME=Time,Ora,'#1042#1088#1077#1084#1103
      'COD="Nr bilet","Nr bilet","Nr bilet"'
      'SUMAT="To pay","Spre plt.","'#1050' '#1086#1087#1083'."'
      'LOC=Loc,Loc,Loc'
      'INLESN=Inlesn.,Inlesn.,Inlesn.'
      'DEPART=Depart.,Depart.,Depart.'
      'PERS_NUMELE="Numele, pren.","Numele, pren.","Numele, pren."'
      'PASAPORT=Pasaport,Pasaport,Pasaport'
      
        'PRET_BRONARE_ESTIMAT="Pret estimat Bronare","Pret estimat Bronar' +
        'e","Pret estimat Bronare"'
      
        'RIND_LOC_STRING="Rindul si Locul","Rindul si Locul","Rindul si L' +
        'ocul"')
  end
  object dsCasalenta: TDataSource
    DataSet = qsCasalenta
    Left = 136
    Top = 376
  end
  object qsCasalenta: TSagiODACSmartQuery
    SQL.Strings = (
      'select * from v1_subagent_casalenta v'
      'where v.casir = :user_id'
      
        '  and trunc(v.data) between trunc(:date_from) and trunc(:date_ti' +
        'll)'
      'order by data desc')
    MasterSource = dsUsers
    AutoCommit = False
    LockMode = lmNone
    SagiMode = True
    SagiSimpleRefresh = True
    SagiEditRefreshNotNeed = True
    Left = 144
    Top = 320
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'user_id'
        Value = nil
      end
      item
        DataType = ftUnknown
        Name = 'date_from'
        Value = nil
      end
      item
        DataType = ftUnknown
        Name = 'date_till'
        Value = nil
      end>
    object qsCasalentaID: TIntegerField
      FieldName = 'ID'
      Required = True
    end
    object qsCasalentaCASA: TStringField
      FieldName = 'CASA'
      Size = 5
    end
    object qsCasalentaSUMA_PACH: TFloatField
      FieldName = 'SUMA_PACH'
    end
    object qsCasalentaSUMA_PRIM: TFloatField
      FieldName = 'SUMA_PRIM'
    end
    object qsCasalentaDATA: TDateTimeField
      FieldName = 'DATA'
    end
    object qsCasalentaDESCR: TStringField
      FieldName = 'DESCR'
      Size = 50
    end
    object qsCasalentaISRET: TStringField
      FieldName = 'ISRET'
      FixedChar = True
      Size = 1
    end
    object qsCasalentaACCEPT: TIntegerField
      FieldName = 'ACCEPT'
    end
    object qsCasalentaCASIR: TIntegerField
      FieldName = 'CASIR'
    end
  end
  object LS: TUnLangSelector
    UnSections = <>
    Left = 40
    Top = 288
    CompList = (
      'fBookedTickets'
      'btOk'
      'btCancel'
      'UnDBGrid')
    CompStrEng = (
      '[fUsers]'
      'Caption=Personnel'
      '[btOk]'
      'Caption=OK (Enter)'
      '[btCancel]'
      'Caption=Cancel (ESC)'
      '[fBookedTickets]'
      'Caption=Subagent tickets')
    CompStrRom = (
      '[fUsers]'
      'Caption=Lista personalului'
      '[btOk]'
      'Caption=OK (Enter)'
      '[btCancel]'
      'Caption=Anulare (ESC)'
      '[fBookedTickets]'
      'Caption=Biletele subagentilor')
    CompStrRus = (
      '[btOk]'
      'Caption=OK (Enter)'
      '[btCancel]'
      'Caption='#1054#1090#1084#1077#1085#1072' (ESC)'
      '[fBookedTickets]'
      'Caption='#1041#1080#1083#1077#1090#1099' '#1089#1091#1073#1072#1075#1077#1085#1090#1086#1074)
  end
  object dsUsers: TDataSource
    DataSet = qsUsers
    Left = 224
    Top = 376
  end
  object qsUsers: TSagiODACSmartQuery
    KeyFields = 'user_id'
    Session = dmCassa.db
    SQL.Strings = (
      'select id user_id, name user_name from v0subagents v')
    Left = 225
    Top = 320
    object qsUsersUSER_ID: TIntegerField
      FieldName = 'USER_ID'
      Required = True
    end
    object qsUsersUSER_NAME: TStringField
      FieldName = 'USER_NAME'
      Size = 80
    end
  end
  object dsBilets: TDataSource
    DataSet = qsBilets
    Left = 312
    Top = 376
  end
  object qsBilets: TSagiODACSmartQuery
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
    Session = dmCassa.db
    SQL.Strings = (
      'select  b.cod, data,  b.loc, b.idcaslenta'
      '  , b.inlesn, b.depart, b.pers_numele, b.pasaport, b.prints'
      
        '  , decode(nvl(sys_context('#39'GRACONTEXT'#39','#39'SESS_ValCURS_D'#39'),1.0),1' +
        '.0, b.sumat,b.sumavalt) sumat'
      '  , b.pret_bronare_estimat'
      '  , b.rind_loc_string'
      '  , t.denumirea||'#39' '#39'||to_char(time_in ,'#39'hh24:mi'#39') denumirea '
      'from v0_bilets b, t0ruta t'
      'WHERE'
      '(idcaslenta = :id and b.ruta = t.codu)')
    MasterSource = dsCasalenta
    FetchAll = True
    Active = True
    SagiKeyFields = 'COD'
    SagiMode = True
    SagiFilterSYS = 'idcaslenta = :id and b.ruta = t.codu'
    SagiSQL1.Strings = (
      'select  b.cod, data,  b.loc, b.idcaslenta'
      '  , b.inlesn, b.depart, b.pers_numele, b.pasaport, b.prints'
      
        '  , decode(nvl(sys_context('#39'GRACONTEXT'#39','#39'SESS_ValCURS_D'#39'),1.0),1' +
        '.0, b.sumat,b.sumavalt) sumat'
      '  , b.pret_bronare_estimat'
      '  , b.rind_loc_string'
      '  , t.denumirea||'#39' '#39'||to_char(time_in ,'#39'hh24:mi'#39') denumirea '
      'from v0_bilets b, t0ruta t')
    SagiSimpleRefresh = True
    SagiEditRefreshNotNeed = True
    SagiSQLServer = True
    Left = 312
    Top = 320
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'id'
        Value = Null
      end>
    object qsBiletsCOD: TStringField
      FieldName = 'COD'
      Required = True
      Size = 15
    end
    object qsBiletsDATA: TDateTimeField
      FieldName = 'DATA'
    end
    object qsBiletsLOC: TIntegerField
      FieldName = 'LOC'
    end
    object qsBiletsIDCASLENTA: TIntegerField
      FieldName = 'IDCASLENTA'
    end
    object qsBiletsINLESN: TStringField
      FieldName = 'INLESN'
      Size = 2
    end
    object qsBiletsDEPART: TFloatField
      FieldName = 'DEPART'
    end
    object qsBiletsPERS_NUMELE: TStringField
      FieldName = 'PERS_NUMELE'
      Size = 50
    end
    object qsBiletsPASAPORT: TStringField
      FieldName = 'PASAPORT'
      Size = 255
    end
    object qsBiletsPRINTS: TIntegerField
      FieldName = 'PRINTS'
    end
    object qsBiletsSUMAT: TFloatField
      FieldName = 'SUMAT'
    end
    object qsBiletsPRET_BRONARE_ESTIMAT: TFloatField
      FieldName = 'PRET_BRONARE_ESTIMAT'
    end
    object qsBiletsRIND_LOC_STRING: TStringField
      FieldName = 'RIND_LOC_STRING'
      Size = 4000
    end
    object qsBiletsDENUMIREA: TStringField
      FieldName = 'DENUMIREA'
      Size = 70
    end
  end
end
