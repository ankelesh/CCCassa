object fRest: TfRest
  Left = 215
  Top = 0
  Caption = #1042#1086#1079#1074#1088#1072#1090
  ClientHeight = 576
  ClientWidth = 718
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDesktopCenter
  Visible = True
  OnCloseQuery = FormCloseQuery
  OnDeactivate = FormDeactivate
  PixelsPerInch = 96
  TextHeight = 13
  object pnlFind: TPanel
    Left = 0
    Top = 0
    Width = 718
    Height = 57
    Align = alTop
    TabOrder = 0
    object Label1: TLabel
      Left = 13
      Top = 16
      Width = 74
      Height = 19
      Alignment = taRightJustify
      Caption = #8470' '#1073#1080#1083#1077#1090#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object btFindBil: TSpeedButton
      Left = 263
      Top = 16
      Width = 23
      Height = 22
      Caption = '?'
      OnClick = btFindBilClick
    end
    object meNrBilet: TMaskEdit
      Left = 96
      Top = 16
      Width = 161
      Height = 26
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      Text = ''
      OnChange = meNrBiletChange
      OnKeyDown = meNrBiletKeyDown
    end
  end
  object pnlRest: TPanel
    Left = 0
    Top = 57
    Width = 718
    Height = 519
    Align = alClient
    AutoSize = True
    BevelInner = bvRaised
    BevelOuter = bvNone
    TabOrder = 1
    object Label6: TLabel
      Left = 32
      Top = 192
      Width = 130
      Height = 19
      Alignment = taRightJustify
      Caption = #1057#1091#1084#1084#1072' '#1082' '#1074#1086#1079#1074#1088#1072#1090#1091
      FocusControl = dbePrim
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 296
      Top = 192
      Width = 67
      Height = 19
      Caption = ' '#1085#1072' '#1073#1080#1083#1077#1090
      FocusControl = dbePrim
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 365
      Top = 48
      Width = 41
      Height = 13
      Alignment = taRightJustify
      Caption = #1052#1040#1056#1064#1056'.'
      FocusControl = DBEdit2
    end
    object Label2: TLabel
      Left = 377
      Top = 16
      Width = 28
      Height = 13
      Alignment = taRightJustify
      Caption = #1044#1040#1058#1040
      FocusControl = DBEdit1
    end
    object DBGridMy11: TUnDBGrid
      Left = 9
      Top = 80
      Width = 512
      Height = 105
      Color = clInfoBk
      Ctl3D = True
      DataSource = dsRest
      Enabled = False
      ParentCtl3D = False
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
      XTitleHeight = 17
      UnLanguage = lnRus
      Columns = <
        item
          Color = clInfoBk
          Expanded = False
          FieldName = 'SC'
          Title.Alignment = taCenter
          Title.Caption = #8470
          Width = 26
          Visible = True
        end
        item
          Color = clInfoBk
          Expanded = False
          FieldName = 'DESCR'
          Title.Alignment = taCenter
          Title.Caption = #1059#1089#1083#1091#1075#1072
          Width = 96
          Visible = True
        end
        item
          Color = clInfoBk
          Expanded = False
          FieldName = 'UPL'
          Title.Alignment = taCenter
          Title.Caption = #1054#1087#1083#1072#1095#1077#1085#1086
          Visible = True
        end
        item
          Color = clInfoBk
          Expanded = False
          FieldName = 'RESTREAL'
          Title.Alignment = taCenter
          Title.Caption = #1042#1086#1079#1074#1088#1072#1090
          Visible = True
        end
        item
          Color = clInfoBk
          Expanded = False
          FieldName = 'R5161'
          Title.Alignment = taCenter
          Title.Caption = #1048#1085#1080#1094'. '#1087#1072#1089#1089'.'
          Visible = True
        end
        item
          Color = clInfoBk
          Expanded = False
          FieldName = 'PROCENTRET'
          Title.Alignment = taCenter
          Title.Caption = '% '#1048#1085#1080#1094'. '#1087#1072#1089#1089'.'
          Visible = True
        end
        item
          Color = clInfoBk
          Expanded = False
          FieldName = 'R5162'
          Title.Alignment = taCenter
          Title.Caption = #1048#1079'-'#1079#1072' '#1089#1088#1099#1074#1086#1074' '#1080' '#1090'.'#1076'.'
          Visible = True
        end>
      Captions = (
        'SC=Nr,Nr,'#8470
        'DESCR=Costuri,Costuri,'#1059#1089#1083#1091#1075#1072
        'UPL=Achitat,Achitat,'#1054#1087#1083#1072#1095#1077#1085#1086
        'RESTREAL=Restituit,Restituit,'#1042#1086#1079#1074#1088#1072#1090
        'R5161="prin init.pas.","prin init.pas.","'#1048#1085#1080#1094'. '#1087#1072#1089#1089'."'
        'PROCENTRET="% din init.pas.","% din init.pas.","% '#1048#1085#1080#1094'. '#1087#1072#1089#1089'."'
        'R5162="prin rebut,etc.","prin rebut,etc.","'#1048#1079'-'#1079#1072' '#1089#1088#1099#1074#1086#1074' '#1080' '#1090'.'#1076'."')
    end
    object dbedIP: TDBEdit
      Left = 236
      Top = 16
      Width = 121
      Height = 26
      Color = clMenu
      DataField = 'IP'
      DataSource = dsRestT
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
    end
    object dbedRB: TDBEdit
      Left = 236
      Top = 48
      Width = 121
      Height = 26
      Color = clMenu
      DataField = 'RB'
      DataSource = dsRestT
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
    end
    object rgpCauza: TGroupBox
      Left = 8
      Top = 1
      Width = 214
      Height = 73
      Caption = ' '#1055#1088#1080#1095#1080#1085#1072
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 3
      object rbIP1: TRadioButton
        Left = 16
        Top = 20
        Width = 186
        Height = 25
        Action = rbIP
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object rbRB1: TRadioButton
        Left = 16
        Top = 48
        Width = 193
        Height = 17
        Action = rbRB
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
    end
    object dbePrim: TDBEdit
      Left = 176
      Top = 192
      Width = 121
      Height = 26
      Color = clInfoBk
      DataField = 'clcSumaRest'
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
      OnChange = dbePrimChange
    end
    object btnLaTipar: TBitBtn
      Left = 392
      Top = 192
      Width = 145
      Height = 41
      Caption = #1055#1077#1095#1072#1090#1100' (Alt+P)'
      Glyph.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000010000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
        888F8800000000000888808888888880808800000000000008080888888BBB88
        0008088888877788080800000000000008800888888888808080800000000008
        0800880FFFFFFFF080808880F00000F000088880FFFFFFFF088888880F00000F
        088888880FFFFFFFF08888888000000000888888888888888888}
      TabOrder = 5
      OnClick = btnLaTiparClick
    end
    object btAnul: TBitBtn
      Left = 392
      Top = 240
      Width = 145
      Height = 41
      Caption = #1054#1090#1084#1077#1085#1072' (Alt+A)'
      Glyph.Data = {
        DE010000424DDE01000000000000760000002800000024000000120000000100
        0400000000006801000000000000000000001000000010000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        333333333333333333333333000033338833333333333333333F333333333333
        0000333911833333983333333388F333333F3333000033391118333911833333
        38F38F333F88F33300003339111183911118333338F338F3F8338F3300003333
        911118111118333338F3338F833338F3000033333911111111833333338F3338
        3333F8330000333333911111183333333338F333333F83330000333333311111
        8333333333338F3333383333000033333339111183333333333338F333833333
        00003333339111118333333333333833338F3333000033333911181118333333
        33338333338F333300003333911183911183333333383338F338F33300003333
        9118333911183333338F33838F338F33000033333913333391113333338FF833
        38F338F300003333333333333919333333388333338FFF830000333333333333
        3333333333333333333888330000333333333333333333333333333333333333
        0000}
      NumGlyphs = 2
      TabOrder = 6
      OnClick = btAnulClick
    end
    object DBEdit2: TDBEdit
      Left = 416
      Top = 48
      Width = 113
      Height = 21
      Color = clMenu
      DataField = 'RUTA'
      DataSource = dsRestT
      Enabled = False
      TabOrder = 7
    end
    object DBEdit1: TDBEdit
      Left = 416
      Top = 16
      Width = 113
      Height = 21
      Color = clMenu
      DataField = 'DATA'
      DataSource = dsRestT
      Enabled = False
      TabOrder = 8
    end
    object pgcRestInfo: TPageControl
      Left = 8
      Top = 232
      Width = 377
      Height = 225
      ActivePage = tsInpRest
      TabOrder = 9
      object tsBilet: TTabSheet
        Caption = #1041#1080#1083#1077#1090
        object dbmemoBilet: TDBRichEdit
          Left = 0
          Top = 0
          Width = 369
          Height = 197
          Align = alClient
          BorderStyle = bsNone
          DataField = 'CECU'
          DataSource = dsRestBilet
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Courier New'
          Font.Style = []
          ReadOnly = True
          ScrollBars = ssVertical
          TabOrder = 0
          Zoom = 100
        end
      end
      object tsInpRest: TTabSheet
        Caption = #1053#1077#1089#1090#1072#1085#1076#1072#1088#1090#1085'. '#1074#1086#1079#1074#1088#1072#1090
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = []
        ImageIndex = 1
        ParentFont = False
        object Label5: TLabel
          Left = 93
          Top = 97
          Width = 79
          Height = 13
          Alignment = taRightJustify
          Caption = #1053#1077#1089#1090#1072#1085#1076'. '#1089#1091#1084#1084#1072
          FocusControl = DBEdit3
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          Transparent = True
        end
        object Label7: TLabel
          Left = 57
          Top = 25
          Width = 122
          Height = 13
          Alignment = taRightJustify
          Caption = #1055#1088#1086#1094'. '#1080#1079' '#1089#1091#1084#1084#1099' '#1087#1086#1077#1079#1076#1082#1080
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          Transparent = True
        end
        object DBEdit3: TDBEdit
          Left = 184
          Top = 97
          Width = 121
          Height = 27
          DataField = 'REST_SUMA'
          DataSource = dsmT1LISTIMB_VPRON_RESTIT
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
          OnChange = rzdbProcEditChange
        end
        object rzBiletRecalc: TRzButton
          Left = 184
          Top = 136
          Width = 121
          Height = 41
          Action = actCalcRest
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
        end
        object rzdbProcEdit: TRzDBComboBox
          Left = 184
          Top = 24
          Width = 121
          Height = 26
          DataField = 'REST_PROCENT'
          DataSource = dsmT1LISTIMB_VPRON_RESTIT
          Style = csDropDownList
          Sorted = True
          TabOrder = 0
          OnChange = rzdbProcEditChange
          Items.Strings = (
            '100'
            '50'
            '75'
            '85')
        end
        object DBCheckBox1: TDBCheckBox
          Left = 184
          Top = 64
          Width = 129
          Height = 17
          Caption = #1042#1089#1077' '#1079#1072#1090#1088#1072#1090#1099
          DataField = 'REST_FULLSUMS'
          DataSource = dsmT1LISTIMB_VPRON_RESTIT
          TabOrder = 3
          ValueChecked = '1'
          ValueUnchecked = '0'
        end
      end
      object tsDescSpec: TTabSheet
        Caption = #1057#1087#1077#1094'. '#1088#1072#1089#1096#1080#1092#1088#1086#1074#1082#1072
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = []
        ImageIndex = 2
        ParentFont = False
        object Label39: TLabel
          Left = 208
          Top = 21
          Width = 30
          Height = 18
          Caption = 'C31'
          FocusControl = DBEdit23
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          Transparent = True
        end
        object Label40: TLabel
          Left = 208
          Top = 47
          Width = 30
          Height = 18
          Caption = 'C32'
          FocusControl = DBEdit24
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          Transparent = True
        end
        object Label41: TLabel
          Left = 208
          Top = 72
          Width = 30
          Height = 18
          Caption = 'C33'
          FocusControl = DBEdit25
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          Transparent = True
        end
        object Label42: TLabel
          Left = 208
          Top = 97
          Width = 30
          Height = 18
          Caption = 'C34'
          FocusControl = DBEdit26
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          Transparent = True
        end
        object Label43: TLabel
          Left = 208
          Top = 122
          Width = 30
          Height = 18
          Caption = 'C35'
          FocusControl = DBEdit27
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          Transparent = True
        end
        object Label44: TLabel
          Left = 208
          Top = 147
          Width = 30
          Height = 18
          Caption = 'C36'
          FocusControl = DBEdit28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          Transparent = True
        end
        object Label55: TLabel
          Left = 99
          Top = 17
          Width = 102
          Height = 19
          Alignment = taRightJustify
          Caption = #1080#1085#1080#1094#1080#1072#1090'.'#1087#1072#1089#1089'.'
          FocusControl = DBEdit23
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          Transparent = True
        end
        object Label56: TLabel
          Left = 96
          Top = 43
          Width = 106
          Height = 19
          Alignment = taRightJustify
          Caption = #1089#1088#1099#1074#1099'  '#1088#1077#1081#1089#1086#1074
          FocusControl = DBEdit24
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          Transparent = True
        end
        object Label57: TLabel
          Left = 80
          Top = 68
          Width = 122
          Height = 19
          Alignment = taRightJustify
          Caption = #1082#1086#1084#1085'.'#1084#1072#1090'. '#1080' '#1088#1077#1073'.'
          FocusControl = DBEdit25
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          Transparent = True
        end
        object Label58: TLabel
          Left = 137
          Top = 93
          Width = 66
          Height = 19
          Alignment = taRightJustify
          Caption = #1082#1086#1084'.'#1089#1073#1086#1088
          FocusControl = DBEdit26
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          Transparent = True
        end
        object Label59: TLabel
          Left = 159
          Top = 118
          Width = 44
          Height = 19
          Alignment = taRightJustify
          Caption = #1073#1072#1075#1072#1078
          FocusControl = DBEdit27
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          Transparent = True
        end
        object Label60: TLabel
          Left = 159
          Top = 143
          Width = 44
          Height = 19
          Alignment = taRightJustify
          Caption = #1073#1088#1086#1085#1100
          FocusControl = DBEdit28
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          Transparent = True
        end
        object DBEdit23: TDBEdit
          Left = 240
          Top = 17
          Width = 105
          Height = 26
          DataField = 'REST_SUMA_C31'
          DataSource = dsmT1LISTIMB_VPRON_RESTIT
          TabOrder = 0
        end
        object DBEdit24: TDBEdit
          Left = 240
          Top = 43
          Width = 105
          Height = 26
          DataField = 'REST_SUMA_C32'
          DataSource = dsmT1LISTIMB_VPRON_RESTIT
          TabOrder = 1
        end
        object DBEdit25: TDBEdit
          Left = 240
          Top = 68
          Width = 105
          Height = 26
          DataField = 'REST_SUMA_C33'
          DataSource = dsmT1LISTIMB_VPRON_RESTIT
          TabOrder = 2
        end
        object DBEdit26: TDBEdit
          Left = 240
          Top = 93
          Width = 105
          Height = 26
          DataField = 'REST_SUMA_C34'
          DataSource = dsmT1LISTIMB_VPRON_RESTIT
          TabOrder = 3
        end
        object DBEdit27: TDBEdit
          Left = 240
          Top = 118
          Width = 105
          Height = 26
          DataField = 'REST_SUMA_C35'
          DataSource = dsmT1LISTIMB_VPRON_RESTIT
          TabOrder = 4
        end
        object DBEdit28: TDBEdit
          Left = 240
          Top = 143
          Width = 105
          Height = 26
          DataField = 'REST_SUMA_C36'
          DataSource = dsmT1LISTIMB_VPRON_RESTIT
          TabOrder = 5
        end
      end
    end
    object BtnBezPrint: TBitBtn
      Left = 392
      Top = 288
      Width = 145
      Height = 41
      Caption = #1041#1077#1079' '#1087#1077#1095#1072#1090#1080
      Enabled = False
      Glyph.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        0400000000008000000000000000000000001000000010000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
        888F8800000000000888808888888880808800000000000008080888888BBB88
        0008088888877788080800000000000008800888888888808080800000000008
        0800880FFFFFFFF080808880F00000F000088880FFFFFFFF088888880F00000F
        088888880FFFFFFFF08888888000000000888888888888888888}
      TabOrder = 10
      OnClick = BtnBezPrintClick
    end
  end
  object btnIesir1: TBitBtn
    Left = 376
    Top = 7
    Width = 145
    Height = 41
    Action = btnIesir
    Caption = #1042#1099#1093#1086#1076' (ESC)'
    Glyph.Data = {
      DE010000424DDE01000000000000760000002800000024000000120000000100
      0400000000006801000000000000000000001000000010000000000000000000
      80000080000000808000800000008000800080800000C0C0C000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00388888888877
      F7F787F8888888888333333F00004444400888FFF444448888888888F333FF8F
      000033334D5007FFF4333388888888883338888F0000333345D50FFFF4333333
      338F888F3338F33F000033334D5D0FFFF43333333388788F3338F33F00003333
      45D50FEFE4333333338F878F3338F33F000033334D5D0FFFF43333333388788F
      3338F33F0000333345D50FEFE4333333338F878F3338F33F000033334D5D0FFF
      F43333333388788F3338F33F0000333345D50FEFE4333333338F878F3338F33F
      000033334D5D0EFEF43333333388788F3338F33F0000333345D50FEFE4333333
      338F878F3338F33F000033334D5D0EFEF43333333388788F3338F33F00003333
      4444444444333333338F8F8FFFF8F33F00003333333333333333333333888888
      8888333F00003333330000003333333333333FFFFFF3333F00003333330AAAA0
      333333333333888888F3333F00003333330000003333333333338FFFF8F3333F
      0000}
    NumGlyphs = 2
    TabOrder = 2
  end
  object dsRest: TDataSource
    DataSet = qsRest
    Left = 440
    Top = 201
  end
  object dsRestT: TDataSource
    DataSet = qsRestT
    Left = 440
    Top = 161
  end
  object ActionList1: TActionList
    Left = 248
    Top = 185
    object rbIP: TAction
      Caption = #1054#1090#1082#1072#1079' '#1087#1072#1089#1089#1072#1078#1080#1088#1072
      ShortCut = 32846
      OnExecute = rbIPClick
    end
    object rbRB: TAction
      Caption = #1055#1077#1088#1077#1086#1092#1086#1088#1084'., '#1087#1086#1083#1086#1084'.'
      ShortCut = 32837
      OnExecute = rbRBClick
    end
    object btnIesir: TAction
      Caption = #1042#1099#1093#1086#1076' (ESC)'
      ShortCut = 27
      OnExecute = btnIesir1Click
    end
    object actCalcRest: TAction
      Caption = #1056#1072#1089#1095#1077#1090' (Alt+C)'
      ShortCut = 32835
      OnExecute = actCalcRestExecute
    end
  end
  object qsRestT: TSagiODACSmartQuery
    SQLRefresh.Strings = (
      'where COD=:CC')
    Session = dmCassa.db
    SQL.Strings = (
      'SELECT V1_TRESTIT.*  FROM V1_TRESTIT'
      'where COD=:CC')
    SagiKeyFields = 'COD'
    Left = 368
    Top = 161
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CC'
        Value = nil
      end>
    object qsRestTCOD: TStringField
      FieldName = 'COD'
      Required = True
      Size = 15
    end
    object qsRestTIP: TFloatField
      FieldName = 'IP'
    end
    object qsRestTRB: TFloatField
      FieldName = 'RB'
    end
    object qsRestTDATA: TDateTimeField
      FieldName = 'DATA'
      Required = True
    end
    object qsRestTRUTA: TStringField
      FieldName = 'RUTA'
      Required = True
      Size = 10
    end
    object qsRestTCECU: TStringField
      FieldName = 'CECU'
      Size = 4000
    end
    object qsRestTNRORD: TIntegerField
      FieldName = 'NRORD'
      Required = True
    end
  end
  object qsRest: TSagiODACSmartQuery
    Session = dmCassa.db
    SQL.Strings = (
      'SELECT V1_RESTIT.*  FROM V1_RESTIT'
      'where COD=:COD'
      'order by SC')
    MasterSource = dsRestT
    Left = 368
    Top = 209
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'COD'
        Value = nil
      end>
    object qsRestCOD: TStringField
      FieldName = 'COD'
      Required = True
      Size = 15
    end
    object qsRestSC: TFloatField
      FieldName = 'SC'
    end
    object qsRestDESCR: TStringField
      FieldName = 'DESCR'
      Size = 50
    end
    object qsRestUPL: TFloatField
      FieldName = 'UPL'
      Required = True
    end
    object qsRestRESTREAL: TFloatField
      FieldName = 'RESTREAL'
    end
    object qsRestR5161: TFloatField
      FieldName = 'R5161'
    end
    object qsRestR5162: TFloatField
      FieldName = 'R5162'
    end
    object qsRestPROCENTRET: TFloatField
      FieldName = 'PROCENTRET'
    end
  end
  object osmT1LISTIMB_VPRON_RESTIT: TSagiODACSmartQuery
    FullRefresh = True
    DMLRefresh = True
    SQLInsert.Strings = (
      'INSERT INTO T1LISTIMB_VPRON_RESTIT'
      
        '  (IDCASLENTA, COD_REST_BILET, REST_PROCENT, REST_MODE, REST_SUM' +
        'A, REST_SUMA_C31, REST_SUMA_C32, REST_SUMA_C33, REST_SUMA_C34, R' +
        'EST_SUMA_C35, REST_SUMA_C36, REST_FULLSUMS)'
      'VALUES'
      
        '  (:IDCASLENTA, :COD_REST_BILET, :REST_PROCENT, :REST_MODE, :RES' +
        'T_SUMA, :REST_SUMA_C31, :REST_SUMA_C32, :REST_SUMA_C33, :REST_SU' +
        'MA_C34, :REST_SUMA_C35, :REST_SUMA_C36, :REST_FULLSUMS)'
      'RETURNING'
      
        '  IDCASLENTA, COD_REST_BILET, REST_PROCENT, REST_MODE, REST_SUMA' +
        ', REST_SUMA_C31, REST_SUMA_C32, REST_SUMA_C33, REST_SUMA_C34, RE' +
        'ST_SUMA_C35, REST_SUMA_C36, REST_FULLSUMS'
      'INTO'
      
        '  :IDCASLENTA, :COD_REST_BILET, :REST_PROCENT, :REST_MODE, :REST' +
        '_SUMA, :REST_SUMA_C31, :REST_SUMA_C32, :REST_SUMA_C33, :REST_SUM' +
        'A_C34, :REST_SUMA_C35, :REST_SUMA_C36, :REST_FULLSUMS')
    SQLDelete.Strings = (
      'DELETE FROM T1LISTIMB_VPRON_RESTIT'
      'WHERE'
      '  IDCASLENTA = :IDCASLENTA')
    SQLUpdate.Strings = (
      'UPDATE T1LISTIMB_VPRON_RESTIT'
      'SET'
      '  IDCASLENTA = :IDCASLENTA,'
      '  COD_REST_BILET = :COD_REST_BILET,'
      '  REST_PROCENT = :REST_PROCENT,'
      '  REST_MODE = :REST_MODE,'
      '  REST_SUMA = :REST_SUMA,'
      '  REST_SUMA_C31 = :REST_SUMA_C31,'
      '  REST_SUMA_C32 = :REST_SUMA_C32,'
      '  REST_SUMA_C33 = :REST_SUMA_C33,'
      '  REST_SUMA_C34 = :REST_SUMA_C34,'
      '  REST_SUMA_C35 = :REST_SUMA_C35,'
      '  REST_SUMA_C36 = :REST_SUMA_C36,'
      '  REST_FULLSUMS = :REST_FULLSUMS'
      'WHERE'
      '  IDCASLENTA = :OLD_IDCASLENTA'
      'RETURNING'
      
        '  IDCASLENTA, COD_REST_BILET, REST_PROCENT, REST_MODE, REST_SUMA' +
        ', REST_SUMA_C31, REST_SUMA_C32, REST_SUMA_C33, REST_SUMA_C34, RE' +
        'ST_SUMA_C35, REST_SUMA_C36, REST_FULLSUMS'
      'INTO'
      
        '  :IDCASLENTA, :COD_REST_BILET, :REST_PROCENT, :REST_MODE, :REST' +
        '_SUMA, :REST_SUMA_C31, :REST_SUMA_C32, :REST_SUMA_C33, :REST_SUM' +
        'A_C34, :REST_SUMA_C35, :REST_SUMA_C36, :REST_FULLSUMS')
    SQLRefresh.Strings = (
      'WHERE'
      '  IDCASLENTA = :IDCASLENTA')
    Session = dmCassa.db
    SQL.Strings = (
      'SELECT T1LISTIMB_VPRON_RESTIT.*  FROM T1LISTIMB_VPRON_RESTIT'
      ' WHERE'
      '(IDCASLENTA=:ID)')
    LockMode = lmNone
    RefreshOptions = [roAfterInsert, roAfterUpdate, roBeforeEdit]
    Options.FullRefresh = True
    AfterInsert = osmT1LISTIMB_VPRON_RESTITAfterInsert
    OnPostError = osmT1LISTIMB_VPRON_RESTITPostError
    SagiModeNotAbort = True
    SagiTableLive = 'T1LISTIMB_VPRON_RESTIT'
    SagiFilterSYS = 'IDCASLENTA=:ID'
    SagiSimpleRefresh = True
    SagiEditRefreshNotNeed = True
    SagiSQLServer = True
    Left = 64
    Top = 177
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'ID'
        Value = nil
      end>
    object osmT1LISTIMB_VPRON_RESTITIDCASLENTA: TIntegerField
      FieldName = 'IDCASLENTA'
      Required = True
    end
    object osmT1LISTIMB_VPRON_RESTITCOD_REST_BILET: TStringField
      FieldName = 'COD_REST_BILET'
      Required = True
      Size = 15
    end
    object osmT1LISTIMB_VPRON_RESTITREST_PROCENT: TFloatField
      FieldName = 'REST_PROCENT'
      OnChange = osmT1LISTIMB_VPRON_RESTITREST_PROCENTChange
    end
    object osmT1LISTIMB_VPRON_RESTITREST_MODE: TIntegerField
      FieldName = 'REST_MODE'
    end
    object osmT1LISTIMB_VPRON_RESTITREST_SUMA: TFloatField
      FieldName = 'REST_SUMA'
    end
    object osmT1LISTIMB_VPRON_RESTITREST_SUMA_C31: TFloatField
      FieldName = 'REST_SUMA_C31'
    end
    object osmT1LISTIMB_VPRON_RESTITREST_SUMA_C32: TFloatField
      FieldName = 'REST_SUMA_C32'
    end
    object osmT1LISTIMB_VPRON_RESTITREST_SUMA_C33: TFloatField
      FieldName = 'REST_SUMA_C33'
    end
    object osmT1LISTIMB_VPRON_RESTITREST_SUMA_C34: TFloatField
      FieldName = 'REST_SUMA_C34'
    end
    object osmT1LISTIMB_VPRON_RESTITREST_SUMA_C35: TFloatField
      FieldName = 'REST_SUMA_C35'
    end
    object osmT1LISTIMB_VPRON_RESTITREST_SUMA_C36: TFloatField
      FieldName = 'REST_SUMA_C36'
    end
    object osmT1LISTIMB_VPRON_RESTITREST_FULLSUMS: TIntegerField
      FieldName = 'REST_FULLSUMS'
    end
  end
  object dsmT1LISTIMB_VPRON_RESTIT: TDataSource
    DataSet = osmT1LISTIMB_VPRON_RESTIT
    Left = 160
    Top = 193
  end
  object LS: TUnLangSelector
    UnLanguage = lnRus
    UnSections = <>
    Left = 520
    Top = 473
    CompList = (
      'fRest'
      'Label1'
      'Label6'
      'Label4'
      'Label3'
      'Label2'
      'DBGridMy11'
      'rgpCauza'
      'rbIP1'
      'rbRB1'
      'btnLaTipar'
      'btAnul'
      'tsBilet'
      'tsInpRest'
      'Label5'
      'Label7'
      'rzBiletRecalc'
      'DBCheckBox1'
      'tsDescSpec'
      'Label39'
      'Label40'
      'Label41'
      'Label42'
      'Label43'
      'Label44'
      'Label55'
      'Label56'
      'Label57'
      'Label58'
      'Label59'
      'Label60'
      'btnIesir1'
      'rbIP'
      'rbRB'
      'btnIesir'
      'actCalcRest'
      'BtnBezPrint')
    CompStrEng = (
      '[fRest]'
      'Caption=Returning'
      '[Label1]'
      'Caption=Ticket #'
      '[Label6]'
      'Caption=Returning sum'
      '[Label4]'
      'Caption= on ticket'
      '[Label3]'
      'Caption=ROUTE'
      '[Label2]'
      'Caption=DATE'
      '[rgpCauza]'
      'Caption= Cause'
      '[rbIP1]'
      'Caption=Passengers refusal'
      '[rbRB1]'
      'Caption=Rebilling, breakage'
      '[btnLaTipar]'
      'Caption=Print (Alt+P)'
      '[btAnul]'
      'Caption=Cancel (Alt+A)'
      '[btnIesir1]'
      'Caption=Exit (ESC)'
      '[rbIP]'
      'Caption=Passengers refusal'
      '[rbRB]'
      'Caption=Rebilling, breakage'
      '[btnIesir]'
      'Caption=Exit (ESC)'
      '[tsBilet]'
      'Caption=Ticket'
      '[tsInpRest]'
      'Caption=Nonstandart returning'
      '[Label5]'
      'Caption=Nonstandart sum'
      '[Label7]'
      'Caption=Percent from sum of trip'
      '[rzBiletRecalc]'
      'Caption=Calculation (Alt+C)'
      '[DBCheckBox1]'
      'Caption=Expense total'
      '[tsDescSpec]'
      'Caption=Special decoding'
      '[Label39]'
      'Caption=C31'
      '[Label40]'
      'Caption=C32'
      '[Label41]'
      'Caption=C33'
      '[Label42]'
      'Caption=C34'
      '[Label43]'
      'Caption=C35'
      '[Label44]'
      'Caption=C36'
      '[Label55]'
      'Caption=passen. initiative'
      '[Label56]'
      'Caption=route derangement'
      '[Label57]'
      'Caption=room for moth. w/ children'
      '[Label58]'
      'Caption=commission tax'
      '[Label59]'
      'Caption=bagage'
      '[Label60]'
      'Caption=reservation'
      '[actCalcRest]'
      'Caption=Calculation (Alt+C)'
      '[BtnBezPrint]'
      'Caption=Fara tipar')
    CompStrRom = (
      '[fRest]'
      'Caption=Restituirea'
      '[Label1]'
      'Caption=Nr biletului'
      '[Label6]'
      'Caption=Suma pentru restituirea'
      '[Label4]'
      'Caption= pe bilet'
      '[Label3]'
      'Caption=RUTA'
      '[Label2]'
      'Caption=DATA'
      '[rgpCauza]'
      'Caption= Cauza '
      '[rbIP1]'
      'Caption=Initiativa pasajerului'
      '[rbRB1]'
      'Caption=Rebut, reperfectare'
      '[btnLaTipar]'
      'Caption=La tipar (Alt+P)'
      '[btAnul]'
      'Caption=Anulare (Alt+A)'
      '[btnIesir1]'
      'Caption=Iesire (ESC)'
      '[rbIP]'
      'Caption=Initiativa pasajerului'
      '[rbRB]'
      'Caption=Rebut, reperfectare'
      '[btnIesir]'
      'Caption=Iesire (ESC)'
      '[tsBilet]'
      'Caption=Bilet'
      '[tsInpRest]'
      'Caption=Restituirea nestandarda'
      '[Label5]'
      'Caption=Suma nestandarda'
      '[Label7]'
      'Caption=Procent din suma calatoriei'
      '[rzBiletRecalc]'
      'Caption=Calcul (Alt+C)'
      '[DBCheckBox1]'
      'Caption=Toate cheltueili'
      '[tsDescSpec]'
      'Caption=Descifrarea speciala'
      '[Label39]'
      'Caption=C31'
      '[Label40]'
      'Caption=C32'
      '[Label41]'
      'Caption=C33'
      '[Label42]'
      'Caption=C34'
      '[Label43]'
      'Caption=C35'
      '[Label44]'
      'Caption=C36'
      '[Label55]'
      'Caption=pasag. initiat.'
      '[Label56]'
      'Caption=compromiteri pe ruta'
      '[Label57]'
      'Caption=cam. mamei si cop.'
      '[Label58]'
      'Caption=comisie'
      '[Label59]'
      'Caption=bagaj'
      '[Label60]'
      'Caption=bronare'
      '[actCalcRest]'
      'Caption=Calcul (Alt+C)'
      '[BtnBezPrint]'
      'Caption=Fara tipar')
    CompStrRus = (
      '[fRest]'
      'Caption='#1042#1086#1079#1074#1088#1072#1090
      '[Label1]'
      'Caption='#8470' '#1073#1080#1083#1077#1090#1072
      '[Label6]'
      'Caption='#1057#1091#1084#1084#1072' '#1082' '#1074#1086#1079#1074#1088#1072#1090#1091
      '[Label4]'
      'Caption= '#1085#1072' '#1073#1080#1083#1077#1090
      '[Label3]'
      'Caption='#1052#1040#1056#1064#1056'.'
      '[Label2]'
      'Caption='#1044#1040#1058#1040
      '[rgpCauza]'
      'Caption= '#1055#1088#1080#1095#1080#1085#1072
      '[rbIP1]'
      'Caption='#1054#1090#1082#1072#1079' '#1087#1072#1089#1089#1072#1078#1080#1088#1072
      '[rbRB1]'
      'Caption='#1055#1077#1088#1077#1086#1092#1086#1088#1084'., '#1087#1086#1083#1086#1084'.'
      '[btnLaTipar]'
      'Caption='#1055#1077#1095#1072#1090#1100' (Alt+P)'
      '[btAnul]'
      'Caption='#1054#1090#1084#1077#1085#1072' (Alt+A)'
      '[btnIesir1]'
      'Caption='#1042#1099#1093#1086#1076' (ESC)'
      '[rbIP]'
      'Caption='#1054#1090#1082#1072#1079' '#1087#1072#1089#1089#1072#1078#1080#1088#1072
      '[rbRB]'
      'Caption='#1055#1077#1088#1077#1086#1092#1086#1088#1084'., '#1087#1086#1083#1086#1084'.'
      '[btnIesir]'
      'Caption='#1042#1099#1093#1086#1076' (ESC)'
      '[tsBilet]'
      'Caption='#1041#1080#1083#1077#1090
      '[tsInpRest]'
      'Caption='#1053#1077#1089#1090#1072#1085#1076#1072#1088#1090#1085'. '#1074#1086#1079#1074#1088#1072#1090
      '[Label5]'
      'Caption='#1053#1077#1089#1090#1072#1085#1076'. '#1089#1091#1084#1084#1072
      '[Label7]'
      'Caption='#1055#1088#1086#1094'. '#1080#1079' '#1089#1091#1084#1084#1099' '#1087#1086#1077#1079#1076#1082#1080
      '[rzBiletRecalc]'
      'Caption='#1056#1072#1089#1095#1077#1090' (Alt+C)'
      '[DBCheckBox1]'
      'Caption='#1042#1089#1077' '#1079#1072#1090#1088#1072#1090#1099
      '[tsDescSpec]'
      'Caption='#1057#1087#1077#1094'. '#1088#1072#1089#1096#1080#1092#1088#1086#1074#1082#1072
      '[Label39]'
      'Caption=C31'
      '[Label40]'
      'Caption=C32'
      '[Label41]'
      'Caption=C33'
      '[Label42]'
      'Caption=C34'
      '[Label43]'
      'Caption=C35'
      '[Label44]'
      'Caption=C36'
      '[Label55]'
      'Caption='#1080#1085#1080#1094#1080#1072#1090'.'#1087#1072#1089#1089'.'
      '[Label56]'
      'Caption='#1089#1088#1099#1074#1099'  '#1088#1077#1081#1089#1086#1074
      '[Label57]'
      'Caption='#1082#1086#1084#1085'.'#1084#1072#1090'. '#1080' '#1088#1077#1073'.'
      '[Label58]'
      'Caption='#1082#1086#1084'.'#1089#1073#1086#1088
      '[Label59]'
      'Caption='#1073#1072#1075#1072#1078
      '[Label60]'
      'Caption='#1073#1088#1086#1085#1100
      '[actCalcRest]'
      'Caption='#1056#1072#1089#1095#1077#1090' (Alt+C)'
      '[BtnBezPrint]'
      'Caption='#1041#1077#1079' '#1087#1077#1095#1072#1090#1080)
  end
  object dsRestBilet: TDataSource
    DataSet = qsRestBilet
    Left = 593
    Top = 167
  end
  object qsRestBilet: TSagiODACSmartQuery
    Session = dmCassa.db
    SQL.Strings = (
      'SELECT Mink.GETBILET(:pcod, :prest) CECU FROM dual')
    Left = 536
    Top = 168
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'pcod'
        Value = nil
      end
      item
        DataType = ftUnknown
        Name = 'prest'
        Value = nil
      end>
    object qsRestBiletCECU: TStringField
      FieldName = 'CECU'
      Size = 4000
    end
  end
end
