object fControlDePerron: TfControlDePerron
  Left = 306
  Top = 261
  BorderStyle = bsDialog
  Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1087#1077#1088#1088#1086#1085#1085#1086#1075#1086' '#1082#1086#1085#1090#1088#1086#1083#1077#1088#1072
  ClientHeight = 143
  ClientWidth = 308
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCloseQuery = FormCloseQuery
  OnKeyPress = FormKeyPress
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 9
    Top = 16
    Width = 113
    Height = 13
    Caption = #1055#1077#1088#1088#1086#1085'. '#1082#1086#1085#1090#1088#1086#1083#1077#1088' #1'
  end
  object Label2: TLabel
    Left = 9
    Top = 41
    Width = 113
    Height = 13
    Caption = #1055#1077#1088#1088#1086#1085'. '#1082#1086#1085#1090#1088#1086#1083#1077#1088' #2'
  end
  object Label3: TLabel
    Left = 9
    Top = 66
    Width = 113
    Height = 13
    Caption = #1055#1077#1088#1088#1086#1085'. '#1082#1086#1085#1090#1088#1086#1083#1077#1088' #3'
  end
  object RzDialogButtons1: TRzDialogButtons
    Left = 0
    Top = 107
    Width = 308
    ShowGlyphs = True
    TabOrder = 0
  end
  object SagiEdit1: TRzDBButtonEdit
    Left = 126
    Top = 16
    Width = 169
    Height = 21
    DataField = 'CODCONTROLER_T'
    TabOrder = 1
    OnKeyPress = SagiEdit1KeyPress
    AllowKeyEdit = False
    ButtonKind = bkFind
    ButtonShortCut = 32808
    AltBtnWidth = 15
    ButtonWidth = 15
    OnButtonClick = SagiEdit1ButtonClick
    FlatButtons = True
  end
  object SagiEdit2: TRzDBButtonEdit
    Left = 126
    Top = 41
    Width = 169
    Height = 21
    DataField = 'CODCONTROLER2_T'
    TabOrder = 2
    OnKeyPress = SagiEdit2KeyPress
    AllowKeyEdit = False
    ButtonKind = bkFind
    ButtonShortCut = 32808
    AltBtnWidth = 15
    ButtonWidth = 15
    OnButtonClick = SagiEdit2ButtonClick
    FlatButtons = True
  end
  object SagiEdit3: TRzDBButtonEdit
    Left = 126
    Top = 65
    Width = 169
    Height = 21
    DataField = 'CODCONTROLER3_T'
    TabOrder = 3
    OnKeyPress = SagiEdit3KeyPress
    AllowKeyEdit = False
    ButtonKind = bkFind
    ButtonShortCut = 32808
    AltBtnWidth = 15
    ButtonWidth = 15
    OnButtonClick = SagiEdit3ButtonClick
    FlatButtons = True
  end
  object V1LISTIMB_VPRONM: TSagiODACSmartQuery
    SQLUpdate.Strings = (
      'UPDATE V1_DISP'
      'SET'
      '  CODCONTROLER = :CODCONTROLER,'
      '  CODCONTROLER2 = :CODCONTROLER2,'
      '  CODCONTROLER3 = :CODCONTROLER3,'
      '  CODCONTROLER_T = :CODCONTROLER_T,'
      '  CODCONTROLER2_T = :CODCONTROLER2_T,'
      '  CODCONTROLER3_T = :CODCONTROLER3_T'
      'WHERE'
      '  CODU = :OLD_CODU and'
      '  trunc(DATA) = trunc(:OLD_DATA)')
    SQLRefresh.Strings = (
      'SELECT * FROM V1_DISP'
      'WHERE'
      '  CODU = :CODU and'
      '  DATA = :DATA')
    SQL.Strings = (
      'SELECT'
      'CODCONTROLER,CODCONTROLER2,CODCONTROLER3,'
      'CODCONTROLER_t,CODCONTROLER2_t,CODCONTROLER3_t'
      ' FROM  V1_DISP M'
      'WHERE TRUNC(m.data)=:data AND m.codu=:ruta')
    Left = 16
    Top = 104
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'data'
        Value = nil
      end
      item
        DataType = ftUnknown
        Name = 'ruta'
        Value = nil
      end>
    object V1LISTIMB_VPRONMCODCONTROLER: TIntegerField
      FieldName = 'CODCONTROLER'
    end
    object V1LISTIMB_VPRONMCODCONTROLER2: TIntegerField
      FieldName = 'CODCONTROLER2'
    end
    object V1LISTIMB_VPRONMCODCONTROLER3: TIntegerField
      FieldName = 'CODCONTROLER3'
    end
    object V1LISTIMB_VPRONMCODCONTROLER_T: TStringField
      FieldName = 'CODCONTROLER_T'
      Size = 80
    end
    object V1LISTIMB_VPRONMCODCONTROLER2_T: TStringField
      FieldName = 'CODCONTROLER2_T'
      Size = 80
    end
    object V1LISTIMB_VPRONMCODCONTROLER3_T: TStringField
      FieldName = 'CODCONTROLER3_T'
      Size = 80
    end
  end
  object dsV1LISTIMB_VPRONM: TDataSource
    DataSet = V1LISTIMB_VPRONM
    Left = 56
    Top = 112
  end
  object LS: TUnLangSelector
    UnLanguage = lnRus
    UnSections = <>
    Left = 88
    Top = 88
    CompList = (
      'fControlDePerron'
      'Label1'
      'Label2'
      'Label3')
    CompStrEng = (
      '[Label3]'
      'Caption=Platform controller #3'
      '[Label2]'
      'Caption=Platform controller #2'
      '[Label1]'
      'Caption=Platform controller #1'
      '[fControlDePerron]'
      'Caption=Choose platform controller')
    CompStrRom = (
      '[Label3]'
      'Caption=Controler de perron #3'
      '[Label2]'
      'Caption=Controler de perron #2'
      '[Label1]'
      'Caption=Controler de perron #1'
      '[fControlDePerron]'
      'Caption=Selectati controlori de perron')
    CompStrRus = (
      '[Label3]'
      'Caption='#1055#1077#1088#1088#1086#1085'. '#1082#1086#1085#1090#1088#1086#1083#1077#1088' #3'
      '[Label2]'
      'Caption='#1055#1077#1088#1088#1086#1085'. '#1082#1086#1085#1090#1088#1086#1083#1077#1088' #2'
      '[Label1]'
      'Caption='#1055#1077#1088#1088#1086#1085'. '#1082#1086#1085#1090#1088#1086#1083#1077#1088' #1'
      '[fControlDePerron]'
      'Caption='#1042#1099#1073#1077#1088#1080#1090#1077' '#1087#1077#1088#1088#1086#1085#1085#1086#1075#1086' '#1082#1086#1085#1090#1088#1086#1083#1077#1088#1072)
  end
end
