object fRetiparBil: TfRetiparBil
  Left = 573
  Top = 409
  BorderStyle = bsDialog
  Caption = #1055#1077#1088#1077#1087#1077#1095#1072#1090#1072#1090#1100' '#1073#1080#1083#1077#1090#1099
  ClientHeight = 239
  ClientWidth = 430
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
  object rgRezult: TRadioGroup
    Left = 8
    Top = 8
    Width = 409
    Height = 137
    Items.Strings = (
      #1056#1072#1089#1087#1077#1095#1072#1090#1072#1090#1100' '#1074#1089#1077' '#1073#1080#1083#1077#1090#1099
      #1056#1072#1089#1087#1077#1095#1072#1090#1072#1090#1100' '#1074#1089#1077' '#1073#1080#1083#1077#1090#1099' '#1089' '#1090#1077#1082#1091#1097#1077#1075#1086
      #1056#1072#1089#1087#1077#1095#1072#1090#1072#1090#1100' '#1090#1086#1083#1100#1082#1086' '#1090#1077#1082#1091#1097#1080#1081' '#1073#1080#1083#1077#1090
      #1056#1072#1089#1087#1077#1095#1072#1090#1072#1090#1100' '#1085#1080' '#1086#1076#1085#1086#1075#1086' '#1073#1080#1083#1077#1090#1072)
    TabOrder = 0
  end
  object RzDialogButtons1: TRzDialogButtons
    Left = 0
    Top = 203
    Width = 430
    CaptionOk = 'OK (Enter)'
    CaptionCancel = 'Cancel (ESC)'
    ShowDivider = True
    ShowGlyphs = True
    WidthOk = 100
    WidthCancel = 100
    TabOrder = 2
  end
  object cbBiletZero: TCheckBox
    Left = 21
    Top = 156
    Width = 401
    Height = 17
    Caption = #1055#1088#1086#1074#1077#1089#1090#1080' '#1074' '#1082#1072#1089#1089#1086#1074#1099#1081' '#1072#1087#1087#1072#1088#1072#1090' '#1089' '#1085#1091#1083#1077#1074#1086#1081' '#1089#1091#1084#1086#1081' '#1073#1080#1083#1077#1090#1072' '
    TabOrder = 1
  end
  object cbRePrint: TCheckBox
    Left = 21
    Top = 179
    Width = 401
    Height = 17
    Caption = #1056#1072#1089#1087#1077#1095#1072#1090#1072#1090#1100' '#1087#1086#1074#1090#1086#1088#1085#1086' '#1095#1077#1082' '
    Checked = True
    State = cbChecked
    TabOrder = 3
  end
  object LS: TUnLangSelector
    UnLanguage = lnRus
    UnSections = <>
    Left = 336
    Top = 72
    CompList = (
      'fRetiparBil'
      'rgRezult'
      'RzDialogButtons1'
      'cbBiletZero')
    CompStrEng = (
      '[fRetiparBil]'
      'Caption=Reprint tickets'
      '[cbBiletZero]'
      'Caption=Send to cash machine ticket with zero sum')
    CompStrRom = (
      '[fRetiparBil]'
      'Caption=Retiparirea biletelor'
      '[cbBiletZero]'
      'Caption='#1055#1088#1086#1074#1077#1089#1090#1080' '#1074' '#1082#1072#1089#1089#1086#1074#1099#1081' '#1072#1087#1087#1072#1088#1072#1090' '#1089' '#1085#1091#1083#1077#1074#1086#1081' '#1089#1091#1084#1086#1081' '#1073#1080#1083#1077#1090#1072' ')
    CompStrRus = (
      '[fRetiparBil]'
      'Caption='#1055#1077#1088#1077#1087#1077#1095#1072#1090#1072#1090#1100' '#1073#1080#1083#1077#1090#1099
      '[cbBiletZero]'
      'Caption='#1055#1088#1086#1074#1077#1089#1090#1080' '#1074' '#1082#1072#1089#1089#1086#1074#1099#1081' '#1072#1087#1087#1072#1088#1072#1090' '#1089' '#1085#1091#1083#1077#1074#1086#1081' '#1089#1091#1084#1086#1081' '#1073#1080#1083#1077#1090#1072' ')
  end
end
