object fBaniiCassa: TfBaniiCassa
  Left = 428
  Top = 129
  Caption = #1044#1077#1085#1100#1075#1080' '#1074' '#1082#1072#1089#1089#1077
  ClientHeight = 411
  ClientWidth = 796
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Courier New'
  Font.Style = [fsBold]
  FormStyle = fsMDIChild
  KeyPreview = True
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnKeyDown = FormKeyDown
  OnKeyPress = FormKeyPress
  PixelsPerInch = 96
  TextHeight = 18
  object Splitter1: TSplitter
    Left = 0
    Top = 137
    Width = 796
    Height = 9
    Cursor = crVSplit
    Align = alTop
    ExplicitWidth = 804
  end
  object Splitter2: TSplitter
    Left = 0
    Top = 235
    Width = 796
    Height = 9
    Cursor = crVSplit
    Align = alBottom
    ExplicitTop = 247
    ExplicitWidth = 804
  end
  object dbgrCasa: TUnDBGrid
    Left = 0
    Top = 25
    Width = 796
    Height = 112
    Align = alTop
    Ctl3D = True
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Courier New'
    Font.Style = [fsBold]
    ParentCtl3D = False
    ParentFont = False
    TabOrder = 0
    TitleFont.Charset = RUSSIAN_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -13
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = [fsBold]
    OnEditButtonClick = dbgrCasaEditButtonClick
    XTitleHeight = 17
    UnLanguage = lnRus
    Columns = <
      item
        ButtonStyle = cbsEllipsis
        Color = clWindow
        Expanded = False
        FieldName = 'Casir'
        Width = 273
        Visible = True
      end
      item
        Color = clWindow
        Expanded = False
        FieldName = 'SUMA'
        Visible = True
      end
      item
        Color = clWindow
        Expanded = False
        FieldName = 'DATA'
        Width = 122
        Visible = True
      end
      item
        Color = clWindow
        Expanded = False
        FieldName = 'SUMAVAL'
        Width = 79
        Visible = True
      end
      item
        Color = clWindow
        Expanded = False
        FieldName = 'VALUTA'
        Width = 83
        Visible = True
      end>
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 796
    Height = 25
    Align = alTop
    Alignment = taLeftJustify
    BevelOuter = bvNone
    Caption = '    (+)'#1055#1086#1083#1091#1095#1077#1085#1086':'
    TabOrder = 1
  end
  object dbgrCasaP: TUnDBGrid
    Left = 0
    Top = 164
    Width = 796
    Height = 71
    Align = alClient
    Ctl3D = True
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Courier New'
    Font.Style = [fsBold]
    ParentCtl3D = False
    ParentFont = False
    TabOrder = 2
    TitleFont.Charset = RUSSIAN_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -13
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = [fsBold]
    OnEditButtonClick = dbgrCasaPEditButtonClick
    XTitleHeight = 17
    UnLanguage = lnRus
    Columns = <
      item
        ButtonStyle = cbsEllipsis
        Color = clWindow
        Expanded = False
        FieldName = 'Casir'
        Width = 274
        Visible = True
      end
      item
        Color = clWindow
        Expanded = False
        FieldName = 'SUMA'
        Visible = True
      end
      item
        Color = clWindow
        Expanded = False
        FieldName = 'DATA'
        Width = 121
        Visible = True
      end
      item
        Color = clWindow
        Expanded = False
        FieldName = 'SUMAVAL'
        Width = 77
        Visible = True
      end
      item
        Color = clWindow
        Expanded = False
        FieldName = 'VALUTA'
        Width = 81
        Visible = True
      end>
  end
  object Panel2: TPanel
    Left = 0
    Top = 146
    Width = 796
    Height = 18
    Align = alTop
    Alignment = taLeftJustify
    BevelOuter = bvNone
    Caption = '    (-)'#1057#1076#1072#1085#1086':'
    TabOrder = 3
  end
  object Panel3: TPanel
    Left = 0
    Top = 370
    Width = 796
    Height = 41
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 4
    object Label1: TLabel
      Left = 272
      Top = 8
      Width = 150
      Height = 18
      Caption = #1054#1089#1090#1072#1090#1086#1082' (Alt+S)'
    end
    object Label2: TLabel
      Left = 560
      Top = 8
      Width = 60
      Height = 18
      Caption = '>  (-)'
      Visible = False
    end
    object BitBtn1: TBitBtn
      Left = 32
      Top = 5
      Width = 193
      Height = 33
      Caption = 'OK (Enter)'
      Default = True
      Glyph.Data = {
        DE010000424DDE01000000000000760000002800000024000000120000000100
        0400000000006801000000000000000000001000000010000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333333333333333330000333333333333333333333333F33333333333
        00003333344333333333333333388F3333333333000033334224333333333333
        338338F3333333330000333422224333333333333833338F3333333300003342
        222224333333333383333338F3333333000034222A22224333333338F338F333
        8F33333300003222A3A2224333333338F3838F338F33333300003A2A333A2224
        33333338F83338F338F33333000033A33333A222433333338333338F338F3333
        0000333333333A222433333333333338F338F33300003333333333A222433333
        333333338F338F33000033333333333A222433333333333338F338F300003333
        33333333A222433333333333338F338F00003333333333333A22433333333333
        3338F38F000033333333333333A223333333333333338F830000333333333333
        333A333333333333333338330000333333333333333333333333333333333333
        0000}
      NumGlyphs = 2
      TabOrder = 0
      OnClick = BitBtn1Click
    end
    object meSold: TMaskEdit
      Left = 432
      Top = 8
      Width = 121
      Height = 26
      TabOrder = 1
      Text = ''
      Visible = False
      OnKeyDown = meSoldKeyDown
    end
  end
  object PanSold: TPanel
    Left = 0
    Top = 244
    Width = 796
    Height = 126
    Align = alBottom
    TabOrder = 5
    object Panel4: TPanel
      Left = 1
      Top = 1
      Width = 794
      Height = 32
      Align = alTop
      Alignment = taLeftJustify
      BevelOuter = bvNone
      Caption = '    '#1054#1089#1090#1072#1090#1086#1082':'
      TabOrder = 0
      object BtnRefresh: TBitBtn
        Left = 128
        Top = 2
        Width = 33
        Height = 24
        Glyph.Data = {
          DE010000424DDE01000000000000760000002800000024000000120000000100
          0400000000006801000000000000000000001000000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333444444
          33333333333F8888883F33330000324334222222443333388F3833333388F333
          000032244222222222433338F8833FFFFF338F3300003222222AAAAA22243338
          F333F88888F338F30000322222A33333A2224338F33F8333338F338F00003222
          223333333A224338F33833333338F38F00003222222333333A444338FFFF8F33
          3338888300003AAAAAAA33333333333888888833333333330000333333333333
          333333333333333333FFFFFF000033333333333344444433FFFF333333888888
          00003A444333333A22222438888F333338F3333800003A2243333333A2222438
          F38F333333833338000033A224333334422224338338FFFFF8833338000033A2
          22444442222224338F3388888333FF380000333A2222222222AA243338FF3333
          33FF88F800003333AA222222AA33A3333388FFFFFF8833830000333333AAAAAA
          3333333333338888883333330000333333333333333333333333333333333333
          0000}
        ModalResult = 6
        NumGlyphs = 2
        TabOrder = 0
        OnClick = BtnRefreshClick
      end
    end
    object grCassaSold: TUnDBGrid
      Left = 1
      Top = 33
      Width = 794
      Height = 92
      Align = alClient
      Ctl3D = True
      DataSource = dsSold
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentCtl3D = False
      ParentFont = False
      TabOrder = 1
      TitleFont.Charset = RUSSIAN_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -13
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = [fsBold]
      OnEditButtonClick = dbgrCasaPEditButtonClick
      XTitleHeight = 17
      UnLanguage = lnRus
      Columns = <
        item
          Color = clWindow
          Expanded = False
          FieldName = 'VALUTA'
          Visible = True
        end
        item
          Color = clWindow
          Expanded = False
          FieldName = 'SOLDINIT'
          Visible = True
        end
        item
          Color = clWindow
          Expanded = False
          FieldName = 'PRIM'
          Visible = True
        end
        item
          Color = clWindow
          Expanded = False
          FieldName = 'OTD'
          Visible = True
        end
        item
          Color = clWindow
          Expanded = False
          FieldName = 'soldfin'
          Visible = True
        end>
    end
  end
  object ActionList1: TActionList
    Left = 448
    Top = 144
    object Action1: TAction
      Caption = 'Action1'
      ShortCut = 32851
      OnExecute = Action1Execute
    end
  end
  object LS: TUnLangSelector
    UnLanguage = lnRus
    UnSections = <>
    Left = 512
    Top = 80
    CompList = (
      'fBaniiCassa'
      'dbgrCasa'
      'Panel1'
      'dbgrCasaP'
      'Panel2'
      'Label1'
      'BitBtn1'
      'Panel4'
      'grCassaSold'
      'Action1')
    CompStrEng = (
      '[fBaniiCassa]'
      'Caption=Cash'
      '[Panel1]'
      'Caption=    (+)Received:'
      '[Panel2]'
      'Caption=    (-)Returned:'
      '[Label1]'
      'Caption=Sold (Alt+S)'
      '[BitBtn1]'
      'Caption=OK (Enter)'
      '[Action1]'
      'Caption=Action1')
    CompStrRom = (
      '[fBaniiCassa]'
      'Caption=Banii in casa'
      '[Panel1]'
      'Caption=    (+)Primit:'
      '[Panel2]'
      'Caption=    (-)Predat:'
      '[Label1]'
      'Caption=In sold (Alt+S)'
      '[BitBtn1]'
      'Caption=OK (Enter)'
      '[Action1]'
      'Caption=Action1')
    CompStrRus = (
      '[fBaniiCassa]'
      'Caption='#1044#1077#1085#1100#1075#1080' '#1074' '#1082#1072#1089#1089#1077
      '[Panel1]'
      'Caption=    (+)'#1055#1086#1083#1091#1095#1077#1085#1086':'
      '[Panel2]'
      'Caption=    (-)'#1057#1076#1072#1085#1086':'
      '[Label1]'
      'Caption='#1054#1089#1090#1072#1090#1086#1082' (Alt+S)'
      '[BitBtn1]'
      'Caption=OK (Enter)'
      '[Action1]'
      'Caption=Action1')
  end
  object sqSold: TSagiODACSmartQuery
    Session = dmCassa.db
    SQL.Strings = (
      'SELECT q.valuta, SUM(sumaval) soldinit,'
      '(SELECT SUM(C3.sumaval_pach) FROM '
      
        ' (SELECT CASA, NVL(SUMAVAL_PACH, SUMA_PACH) SUMAVAL_PACH, NVL(SU' +
        'MAVAL_PRIM, SUMA_PRIM) SUMAVAL_PRIM, '
      '  DATA, DESCR, ISRET, ACCEPT, CASIR, valuta '
      '  FROM T1CASALENTA a, T1CASALENTA_VAL b WHERE b.ID(+)=a.ID) C3'
      '  WHERE isret IS NULL AND q.valuta=C3.valuta AND'
      
        ' C3.CASIR=:CASIR AND C3.CASA=:CASA AND TRUNC(C3.DATA)=TRUNC(TO_D' +
        'ATE(:DATA))'
      ' GROUP BY C3.casir,C3.casa) prim, '
      '(SELECT SUM(C2.sumaval_prim) FROM '
      
        ' (SELECT CASA, NVL(SUMAVAL_PACH, SUMA_PACH) SUMAVAL_PACH, NVL(SU' +
        'MAVAL_PRIM, SUMA_PRIM) SUMAVAL_PRIM, '
      '  DATA, DESCR, ISRET, ACCEPT, CASIR, valuta '
      '  FROM T1CASALENTA a, T1CASALENTA_VAL b WHERE b.ID(+)=a.ID) C2'
      '  WHERE isret IS NOT NULL AND q.valuta=C2.valuta AND'
      
        ' C2.CASIR=:CASIR AND C2.CASA=:CASA AND TRUNC(C2.DATA)=TRUNC(TO_D' +
        'ATE(:DATA))'
      ' GROUP BY C2.casir,C2.casa) otd '
      ' FROM'
      '('
      ' SELECT  valuta, sumaval FROM TMDB_CM t'
      
        ' WHERE  TRUNC(TO_DATE(:DATA))>=DATA AND dt = 2413 AND dtdep=:CAS' +
        'IR'
      ' UNION ALL'
      ' SELECT  valuta, sumaval FROM TMDB_CM'
      
        ' WHERE TRUNC(TO_DATE(:DATA))>=DATA AND ct = 2413 AND ctdep=:CASI' +
        'R'
      ')Q GROUP BY valuta')
    OnCalcFields = sqSoldCalcFields
    Left = 536
    Top = 216
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CASIR'
        Value = Null
      end
      item
        DataType = ftUnknown
        Name = 'CASA'
        Value = Null
      end
      item
        DataType = ftUnknown
        Name = 'DATA'
        Value = Null
      end>
    object sqSoldVALUTA: TStringField
      FieldName = 'VALUTA'
      Size = 3
    end
    object sqSoldSOLDINIT: TFloatField
      FieldName = 'SOLDINIT'
    end
    object sqSoldPRIM: TFloatField
      FieldName = 'PRIM'
    end
    object sqSoldOTD: TFloatField
      FieldName = 'OTD'
    end
    object sqSoldsoldfin: TFloatField
      FieldKind = fkCalculated
      FieldName = 'soldfin'
      Calculated = True
    end
  end
  object dsSold: TOraDataSource
    DataSet = sqSold
    Left = 576
    Top = 216
  end
end
