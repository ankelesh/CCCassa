object fCustomPrice: TfCustomPrice
  Left = 456
  Top = 273
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #1057#1090#1086#1080#1084#1086#1089#1090#1100' '#1086#1076#1085#1086#1075#1086' '#1073#1080#1083#1077#1090#1072
  ClientHeight = 167
  ClientWidth = 351
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 16
    Width = 55
    Height = 13
    Alignment = taRightJustify
    Caption = #1057#1090#1086#1080#1084#1086#1089#1090#1100
  end
  object Label2: TLabel
    Left = 8
    Top = 48
    Width = 70
    Height = 13
    Alignment = taRightJustify
    Caption = #1050#1086#1084#1084#1077#1085#1090#1072#1088#1080#1081
  end
  object Button1: TButton
    Left = 56
    Top = 128
    Width = 75
    Height = 25
    Caption = #1054#1050
    Default = True
    ModalResult = 1
    TabOrder = 2
  end
  object Button2: TButton
    Left = 216
    Top = 128
    Width = 75
    Height = 25
    Cancel = True
    Caption = #1054#1090#1084#1077#1085#1072
    ModalResult = 2
    TabOrder = 3
  end
  object edPrice: TEdit
    Left = 89
    Top = 12
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object mComment: TMemo
    Left = 88
    Top = 40
    Width = 249
    Height = 73
    TabOrder = 1
  end
  object LS: TUnLangSelector
    UnLanguage = lnRus
    UnSections = <>
    Left = 17
    Top = 72
    CompList = (
      'fCustomPrice'
      'Label1'
      'Label2'
      'Button1'
      'Button2')
    CompStrEng = (
      '[fCustomPrice]'
      'Caption=One ticket cost'
      '[Label1]'
      'Caption=Price'
      '[Label2]'
      'Caption=Comment'
      '[Button1]'
      'Caption=OK'
      '[Button2]'
      'Caption=Cancel')
    CompStrRom = (
      '[fCustomPrice]'
      'Caption=Costul unui bilet'
      '[Label2]'
      'Caption=Comentariu'
      '[Label1]'
      'Caption=Costul'
      '[Button1]'
      'Caption=OK'
      '[Button2]'
      'Caption=Anularea')
    CompStrRus = (
      '[fCustomPrice]'
      'Caption='#1057#1090#1086#1080#1084#1086#1089#1090#1100' '#1086#1076#1085#1086#1075#1086' '#1073#1080#1083#1077#1090#1072
      '[Label2]'
      'Caption='#1050#1086#1084#1084#1077#1085#1090#1072#1088#1080#1081
      '[Label1]'
      'Caption='#1057#1090#1086#1080#1084#1086#1089#1090#1100
      '[Button1]'
      'Caption='#1054#1050
      '[Button2]'
      'Caption='#1054#1090#1084#1077#1085#1072)
  end
end
