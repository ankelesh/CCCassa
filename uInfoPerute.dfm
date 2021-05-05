object fInfoPeRute: TfInfoPeRute
  Left = 241
  Top = 214
  Caption = 'Informatia pe rute'
  ClientHeight = 315
  ClientWidth = 615
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 201
    Top = 0
    Height = 274
    ExplicitHeight = 286
  end
  object DBGridMy11: TDBGridMy1
    Left = 0
    Top = 0
    Width = 201
    Height = 274
    Align = alLeft
    Ctl3D = True
    DataSource = dsVRutes
    ParentCtl3D = False
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    XTitleHeight = 17
    Columns = <
      item
        Expanded = False
        FieldName = 'DENUMIREA'
        Title.Caption = 'Ruta'
        Width = 108
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'TIME_OUT'
        Title.Caption = 'Plecare'
        Width = 48
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'CODU'
        Visible = True
      end>
  end
  object DBGridMy12: TDBGridMy1
    Left = 204
    Top = 0
    Width = 411
    Height = 274
    Align = alClient
    Ctl3D = True
    DataSource = dsVRutesD
    ParentCtl3D = False
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    XTitleHeight = 17
    Columns = <
      item
        Expanded = False
        FieldName = 'DATA'
        Width = 67
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'LOC_LIBER'
        Title.Caption = 'liber'
        Width = 37
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'LOC_TOTAL'
        Title.Caption = 'total'
        Width = 30
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'AUTABUS'
        Title.Caption = 'autobus'
        Width = 110
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'TIP'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'CODU'
        Visible = True
      end>
  end
  object Panel1: TPanel
    Left = 0
    Top = 274
    Width = 615
    Height = 41
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    object BitBtn1: TBitBtn
      Left = 272
      Top = 8
      Width = 75
      Height = 25
      Kind = bkOK
      NumGlyphs = 2
      TabOrder = 0
    end
  end
  object dsVRutes: TDataSource
    DataSet = qsVRutes
    Left = 88
    Top = 104
  end
  object dsVRutesD: TDataSource
    DataSet = qsVRutesD
    Left = 248
    Top = 104
  end
  object qsVRutes: TSagiODACSmartQuery
    Session = dmCassa.db
    SQL.Strings = (
      'select  codu, to_char(TIME_OUT,'#39'HH24:MM'#39') TIME_OUT,denumirea '
      'from t0ruta'
      
        'where transit=0 and ZILEVINZPREALAB>0 and codu in (select rutade' +
        'baza from t1ruta_m where trunc(data)>=trunc(sysdate)) '
      ' order by denumirea')
    SagiKeyFields = 'CODU;TIME_OUT;DENUMIREA'
    SagiMode = True
    SagiSQLServer = True
    Left = 88
    Top = 160
  end
  object qsVRutesD: TSagiODACSmartQuery
    Session = dmCassa.db
    SQL.Strings = (
      'select '
      
        ' codu, trunc(data) data,LOC_TOTAL,LOC_LIBER,AUTABUS,TIP,PRETC,PR' +
        'ETN'
      ' from v1_rutam'
      'where codu=:codu and to_char(TIME_OUT,'#39'HH24:MM'#39')=:TIME_OUT')
    MasterSource = dsVRutes
    Left = 248
    Top = 160
    ParamData = <
      item
        DataType = ftString
        Name = 'CODU'
        ParamType = ptInput
        Value = '200098'
      end
      item
        DataType = ftString
        Name = 'TIME_OUT'
        ParamType = ptInput
        Value = '18:01'
      end>
  end
end
