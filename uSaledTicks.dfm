object fSaledTickets: TfSaledTickets
  Left = 20
  Top = 143
  Caption = 'Review of sold tickets'
  ClientHeight = 441
  ClientWidth = 680
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poScreenCenter
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 680
    Height = 441
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    object Splitter1: TSplitter
      Left = 0
      Top = 257
      Width = 680
      Height = 3
      Cursor = crVSplit
      Align = alBottom
      ExplicitTop = 269
      ExplicitWidth = 688
    end
    object grCasaLenta: TUnDBGrid
      Left = 0
      Top = 0
      Width = 680
      Height = 257
      Align = alClient
      Ctl3D = True
      DataSource = dmCassa.dsmFullCasaLentaPrev
      ParentCtl3D = False
      ReadOnly = True
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
          FieldName = 'RUTA'
          Width = 158
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'SUMA_PRIM'
          Title.Caption = 'Suma'
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'PRINTGR'
          Title.Caption = 'Tipar.'
          Width = 40
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'ID'
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'DATA'
          Width = 88
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'ISRET'
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'DESCR'
          Width = 77
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'CASIR'
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'CASA'
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'ACCEPT'
          Visible = True
        end>
      Captions = (
        'RUTA=RUTA,RUTA,RUTA'
        'SUMA_PRIM=Suma,Suma,Suma'
        'PRINTGR=Tipar.,Tipar.,Tipar.'
        'ID=ID,ID,ID'
        'DATA=DATA,DATA,DATA'
        'ISRET=ISRET,ISRET,ISRET'
        'DESCR=DESCR,DESCR,DESCR'
        'CASIR=CASIR,CASIR,CASIR'
        'CASA=CASA,CASA,CASA'
        'ACCEPT=ACCEPT,ACCEPT,ACCEPT')
    end
    object grBilets: TUnDBGrid
      Left = 0
      Top = 260
      Width = 680
      Height = 145
      Align = alBottom
      Ctl3D = True
      ParentCtl3D = False
      ReadOnly = True
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
          FieldName = 'COD'
          Width = 47
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'DATA'
          Width = 84
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'RUTA'
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'LOC'
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'PRET_BRONARE_ESTIMAT'
          Title.Caption = 'Pret bronare estimat'
          Width = 51
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'RIND_LOC_STRING'
          Title.Caption = 'Rindul/Locul'
          Width = 150
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'IDCASLENTA'
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'CODADD'
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'INLESN'
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'DEPART'
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'CERTIFICAT'
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'PERS_NUMELE'
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'PERS_PRUMELE'
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'PERS_PATRON'
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'PASAPORT'
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'BAGAJ'
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'INPIC'
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'PRINTS'
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'SUMAT'
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'CECU'
          Visible = True
        end>
    end
    object RzDialogButtons1: TRzDialogButtons
      Left = 0
      Top = 405
      Width = 680
      ShowGlyphs = True
      ShowCancelButton = False
      TabOrder = 2
      object cbxReTipar: TRzCheckBox
        Left = 168
        Top = 8
        Width = 220
        Height = 15
        Caption = 'Reprint tickets  or list of passengers (Alt+E)'
        State = cbUnchecked
        TabOrder = 3
      end
    end
  end
  object LS: TUnLangSelector
    UnSections = <>
    Left = 536
    Top = 96
    CompList = (
      'fSaledTickets'
      'grCasaLenta'
      'grBilets'
      'cbxReTipar')
    CompStrEng = (
      '[fSaledTickets]'
      'Caption=Review of sold tickets'
      '[cbxReTipar]'
      'Caption=Reprint tickets  or list of passengers (Alt+E)')
    CompStrRom = (
      '[fSaledTickets]'
      'Caption=Vizionarea biletelor vindute'
      '[cbxReTipar]'
      'Caption=Retiparirea biletelor sau listei de imbarcare (Alt+E)')
    CompStrRus = (
      '[fSaledTickets]'
      'Caption='#1055#1088#1086#1089#1084#1086#1090#1088' '#1087#1088#1086#1076#1072#1085#1099#1093' '#1073#1080#1083#1077#1090#1086#1074
      '[cbxReTipar]'
      'Caption='#1055#1086#1074#1090'. '#1087#1077#1095#1072#1090#1100' '#1073#1080#1083'. '#1080#1083#1080' '#1089#1087#1080#1089#1082#1072' '#1087#1072#1089#1089#1072#1078#1080#1088#1086#1074' (Alt+E)')
  end
end
