object fCheckBroni: TfCheckBroni
  Left = 245
  Top = 239
  Width = 979
  Height = 566
  Caption = 'Проверка броней'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 963
    Height = 486
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    object grCheckBroni: TUnDBGrid
      Left = 0
      Top = 0
      Width = 963
      Height = 486
      Align = alClient
      Ctl3D = True
      DataSource = dmCassa.dsCheckBroni
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgMultiSelect]
      ParentCtl3D = False
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
      XTitleHeight = 17
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 486
    Width = 963
    Height = 41
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object btnAnull: TButton
      Left = 160
      Top = 8
      Width = 121
      Height = 25
      Caption = 'Аннулировать'
      TabOrder = 0
      OnClick = btnAnullClick
    end
    object Button1: TButton
      Left = 600
      Top = 8
      Width = 121
      Height = 25
      Cancel = True
      Caption = 'Закрыть окно'
      ModalResult = 2
      TabOrder = 1
    end
  end
end
