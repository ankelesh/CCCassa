object TiparBonForm: TTiparBonForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1055#1077#1095#1072#1090#1100' '#1095#1077#1082#1086#1074
  ClientHeight = 263
  ClientWidth = 491
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
  object pnlUp: TPanel
    Left = 0
    Top = 0
    Width = 491
    Height = 263
    Align = alClient
    TabOrder = 0
    object rgroup: TRadioGroup
      Left = 16
      Top = 0
      Width = 409
      Height = 81
      ItemIndex = 0
      Items.Strings = (
        #1056#1072#1089#1087#1077#1095#1072#1090#1072#1090#1100' '#1092#1080#1089#1082#1072#1083#1100#1085#1099#1081' '#1095#1077#1082
        #1056#1072#1089#1087#1077#1095#1072#1090#1072#1090#1100' '#1076#1091#1087#1083#1080#1082#1072#1090'('#1082#1086#1087#1080#1103') '#1087#1086#1089#1076#1077#1085#1077#1075#1086' '#1095#1077#1082#1072' '#1089' '#1087#1088#1080#1085#1090#1077#1088#1072)
      TabOrder = 0
    end
    object RichEdit: TRichEdit
      Left = 16
      Top = 103
      Width = 409
      Height = 51
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      Zoom = 100
    end
    object BitBtn1: TBitBtn
      Left = 312
      Top = 160
      Width = 115
      Height = 25
      Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077' '#1087#1088#1080#1085#1090#1077#1088#1072
      TabOrder = 2
      OnClick = BitBtn1Click
    end
    object BtnPrint: TBitBtn
      Left = 16
      Top = 216
      Width = 75
      Height = 25
      Caption = #1055#1077#1095#1072#1090#1100
      TabOrder = 3
      OnClick = BtnPrintClick
    end
    object BtnOk: TBitBtn
      Left = 256
      Top = 216
      Width = 75
      Height = 25
      Caption = 'Ok'
      TabOrder = 4
      OnClick = BtnOkClick
    end
    object Inchide: TBitBtn
      Left = 352
      Top = 216
      Width = 75
      Height = 25
      Caption = #1054#1090#1084#1077#1085#1072
      TabOrder = 5
      OnClick = InchideClick
    end
  end
  object LS: TUnLangSelector
    UnSections = <>
    Left = 440
    Top = 32
  end
end
