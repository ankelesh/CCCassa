object fVinz: TfVinz
  Left = 234
  Top = 214
  Caption = #1055#1088#1086#1076#1072#1078#1072
  ClientHeight = 515
  ClientWidth = 1026
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  KeyPreview = True
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  WindowState = wsMaximized
  OnActivate = FormActivate
  OnCloseQuery = FormCloseQuery
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label16: TLabel
    Left = 408
    Top = 240
    Width = 37
    Height = 13
    Caption = 'Label16'
  end
  object Panel2: TPanel
    Left = 0
    Top = 73
    Width = 1026
    Height = 261
    Align = alClient
    TabOrder = 1
    ExplicitWidth = 1020
    object pnlgrV: TPanel
      Left = 264
      Top = 1
      Width = 761
      Height = 259
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 1
      ExplicitWidth = 755
      object dbgrV: TUnDBGrid
        Left = 0
        Top = 81
        Width = 761
        Height = 178
        Align = alClient
        BorderStyle = bsNone
        Ctl3D = True
        DataSource = dmCassa.dsBiltets
        Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgMultiSelect]
        ParentCtl3D = False
        ReadOnly = True
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'Tahoma'
        TitleFont.Style = []
        OnColEnter = dbgrVColEnter
        OnEditButtonClick = dbgrVEditButtonClick
        OnKeyDown = dbgrVKeyDown
        XTitleHeight = 17
        SaveProperties = True
        UnLanguage = lnRus
        Columns = <
          item
            Color = clBtnFace
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
            Color = clBtnFace
            Expanded = False
            FieldName = 'S_TIME'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Tahoma'
            Font.Style = []
            Title.Alignment = taCenter
            Title.Caption = #1042#1088#1077#1084#1103
            Title.Font.Charset = DEFAULT_CHARSET
            Title.Font.Color = clWindowText
            Title.Font.Height = -13
            Title.Font.Name = 'Tahoma'
            Title.Font.Style = []
            Width = 48
            Visible = True
          end
          item
            Color = clBtnFace
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
            Color = clBtnFace
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
            Color = clBtnFace
            Expanded = False
            FieldName = 'LOC'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Tahoma'
            Font.Style = []
            Title.Alignment = taCenter
            Title.Caption = 'Loc'
            Title.Font.Charset = DEFAULT_CHARSET
            Title.Font.Color = clWindowText
            Title.Font.Height = -13
            Title.Font.Name = 'Tahoma'
            Title.Font.Style = []
            Width = 29
            Visible = True
          end
          item
            ButtonStyle = cbsEllipsis
            Color = clBtnFace
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
            Color = clBtnFace
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
            Color = clBtnFace
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
            Color = clBtnFace
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
            Color = clBtnFace
            Expanded = False
            FieldName = 'PRET_BRONARE_ESTIMAT'
            Title.Caption = 'Pret estimat Bronare'
            Width = 38
            Visible = True
          end
          item
            Color = clBtnFace
            Expanded = False
            FieldName = 'RIND_LOC_STRING'
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
      object pnlBroni: TPanel
        Left = 0
        Top = 0
        Width = 761
        Height = 81
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 1
        ExplicitWidth = 755
        object Label10: TLabel
          Left = 682
          Top = 1
          Width = 18
          Height = 13
          Caption = #1058#1080#1087
          FocusControl = DBEdit1
        end
        object Label12: TLabel
          Left = 72
          Top = 1
          Width = 57
          Height = 13
          Caption = #1044#1054#1050#1059#1052#1045#1053#1058
          FocusControl = edBookingDoc
        end
        object Label13: TLabel
          Left = 335
          Top = 1
          Width = 56
          Height = 13
          Caption = #1044#1054#1055'. '#1048#1053#1060'.'
        end
        object Label14: TLabel
          Left = 641
          Top = 1
          Width = 23
          Height = 13
          Caption = #1050#1086#1083'.'
          FocusControl = DBEdit4
        end
        object Label15: TLabel
          Left = 3
          Top = 1
          Width = 53
          Height = 13
          Caption = #1050#1086#1076' '#1073#1088#1086#1085#1080
          FocusControl = DBEdit5
        end
        object ReservationNameInfo: TLabel
          Left = 72
          Top = 40
          Width = 19
          Height = 13
          Caption = #1048#1084#1103
        end
        object ReservationSurnameInfo: TLabel
          Left = 336
          Top = 40
          Width = 44
          Height = 13
          Caption = #1060#1072#1084#1080#1083#1080#1103
        end
        object DBEdit1: TDBEdit
          Left = 681
          Top = 17
          Width = 49
          Height = 21
          DataField = 'TIPBRONI'
          DataSource = dsT1RUTABRONI
          TabOrder = 0
        end
        object edBookingDoc: TDBEdit
          Left = 72
          Top = 20
          Width = 257
          Height = 21
          DataField = 'DOCUMENT'
          DataSource = dsT1RUTABRONI
          TabOrder = 1
        end
        object DBEdit4: TDBEdit
          Left = 641
          Top = 17
          Width = 41
          Height = 21
          DataField = 'BILETCOUNT'
          DataSource = dsT1RUTABRONI
          TabOrder = 2
        end
        object DBEdit5: TDBEdit
          Left = 3
          Top = 17
          Width = 68
          Height = 22
          Color = clInfoBk
          DataField = 'IDCASALENTA'
          DataSource = dsT1RUTABRONI
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 3
        end
        object ReservationNameBox: TDBEdit
          Left = 72
          Top = 54
          Width = 257
          Height = 21
          DataField = 'FIRST_NAME'
          DataSource = dmCassa.dsT1RUTABRONIDETAILS1
          TabOrder = 4
        end
        object ReservationSurnameBox: TDBEdit
          Left = 335
          Top = 54
          Width = 290
          Height = 21
          DataField = 'LAST_NAME'
          DataSource = dmCassa.dsT1RUTABRONIDETAILS1
          TabOrder = 5
        end
        object AddInfoAndTypeBox: TComboBoxEx
          Left = 335
          Top = 20
          Width = 290
          Height = 22
          ItemsEx = <>
          StyleEx = [csExNoSizeLimit]
          TabOrder = 6
          OnSelect = AddInfoAndTypeBoxSelect
        end
      end
    end
    object pnlTimerCal: TPanel
      Left = 1
      Top = 1
      Width = 263
      Height = 259
      Align = alLeft
      Color = clWindow
      TabOrder = 0
      object lblTimp: TLabel
        Left = 1
        Top = 1
        Width = 261
        Height = 16
        Align = alTop
        Alignment = taCenter
        Caption = 'lblTimp'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clMaroon
        Font.Height = -16
        Font.Name = 'Courier'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
        ExplicitWidth = 71
      end
      object mmc: TGaraMonthCalendar
        Left = 1
        Top = 17
        Width = 261
        Height = 241
        Align = alClient
        AutoSize = True
        BiDiMode = bdLeftToRight
        CalColors.TitleBackColor = clBackground
        Constraints.MinWidth = 220
        Date = 1.481197858796804000
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Courier'
        Font.Pitch = fpFixed
        Font.Style = [fsBold]
        ParentBiDiMode = False
        ParentFont = False
        TabOrder = 0
        OnChange = mmcChange
      end
    end
  end
  object pnlSel: TPanel
    Left = 0
    Top = 0
    Width = 1026
    Height = 73
    Align = alTop
    TabOrder = 0
    ExplicitWidth = 1020
    DesignSize = (
      1026
      73)
    object Label1: TLabel
      Left = 365
      Top = 2
      Width = 54
      Height = 13
      Alignment = taRightJustify
      Caption = #1050#1091#1076#1072' '#1077#1076#1077#1084
    end
    object Label2: TLabel
      Left = 6
      Top = 2
      Width = 26
      Height = 13
      Alignment = taRightJustify
      Caption = #1044#1072#1090#1072
    end
    object Label3: TLabel
      Left = 16
      Top = 25
      Width = 48
      Height = 13
      Alignment = taRightJustify
      Caption = #1050#1086#1083'. '#1073#1080#1083'.'
      Visible = False
    end
    object Label4: TLabel
      Left = 381
      Top = 25
      Width = 38
      Height = 13
      Alignment = taRightJustify
      Caption = #1052#1072#1088#1096#1088'.'
    end
    object Label8: TLabel
      Left = 116
      Top = 2
      Width = 30
      Height = 13
      Alignment = taRightJustify
      Caption = #1060#1080#1083#1090'.'
    end
    object lblGrupaCasei: TLabel
      Left = 106
      Top = 25
      Width = 41
      Height = 13
      Alignment = taRightJustify
      Caption = #1042#1054#1050#1047#1040#1051
    end
    object lblValuta: TLabel
      Left = 102
      Top = 52
      Width = 43
      Height = 13
      Alignment = taRightJustify
      Caption = #1042#1040#1051#1070#1058#1040
    end
    object LbTickCounter: TLabel
      Left = 340
      Top = 50
      Width = 79
      Height = 13
      Alignment = taRightJustify
      Caption = #1050#1086#1083'-'#1074#1086' '#1087#1088'. '#1073#1080#1083'.'
    end
    object SBtnResetTickCounter: TSpeedButton
      Left = 546
      Top = 48
      Width = 111
      Height = 21
      Caption = #1057#1073#1088#1086#1089#1080#1090#1100' '#1089#1095#1077#1090#1095#1080#1082
      OnClick = SBtnResetTickCounterClick
    end
    object LbWarningTickCount: TLabel
      Left = 671
      Top = 3
      Width = 198
      Height = 72
      Alignment = taCenter
      Caption = 
        #1044#1086#1089#1090#1080#1075#1085#1091#1090#1086' '#1084#1072#1082#1080#1084#1072#1083#1100#1085#1086#1077' '#1082#1086#1083'-'#1074#1086' '#1073#1080#1083#1077#1090#1086#1074' '#1074' '#1082#1072#1089#1089#1086#1074#1086#1084' '#1072#1087#1087#1072#1088#1072#1090#1077'!!! '#1057#1085#1080 +
        #1084#1080#1090#1077' Z-'#1086#1090#1095#1077#1090' '#1080' '#1089#1073#1088#1086#1089#1100#1090#1077' '#1089#1095#1077#1090#1095#1080#1082'.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      Visible = False
      WordWrap = True
    end
    object meData: TMaskEdit
      Left = 34
      Top = 2
      Width = 65
      Height = 21
      AutoSelect = False
      EditMask = '00.00.2\0\0\0'
      MaxLength = 10
      TabOrder = 0
      Text = '  .  .2000'
      OnChange = meDataChange
      OnEnter = meDataEnter
      OnKeyDown = meDataKeyDown
    end
    object meSelDest: TMaskEdit
      Left = 420
      Top = 2
      Width = 121
      Height = 21
      Color = clInfoBk
      Enabled = False
      TabOrder = 4
      Text = ''
    end
    object meCntBlt: TMaskEdit
      Left = 65
      Top = 25
      Width = 33
      Height = 21
      EditMask = '99;1; '
      MaxLength = 2
      TabOrder = 1
      Text = '1 '
      Visible = False
      OnKeyDown = meCntBltKeyDown
    end
    object meRuta: TMaskEdit
      Left = 420
      Top = 25
      Width = 121
      Height = 21
      Color = clInfoBk
      Enabled = False
      TabOrder = 5
      Text = ''
    end
    object btSelect: TBitBtn
      Left = 271
      Top = 2
      Width = 89
      Height = 41
      Caption = #1042#1099#1073#1086#1088' (Enter)'
      TabOrder = 2
      OnClick = SpeedButton1Click
    end
    object cmbAuto: TComboBox
      Left = 149
      Top = 25
      Width = 121
      Height = 21
      Style = csDropDownList
      TabOrder = 3
      OnKeyDown = meFilter_oldKeyDown
      Items.Strings = (
        'Gara CHISINAU'
        'Gara de SUD, Chisinau'
        'Straseni'
        'Gara de SUBURBIE, Chisinau')
    end
    object cbxPerron: TCheckBox
      Left = 545
      Top = 2
      Width = 125
      Height = 16
      Caption = #1055#1088#1086#1076' '#1085#1072' '#1087#1077#1088'. (Alt+E)'
      TabOrder = 6
      OnClick = cbxPerronClick
    end
    object cbxBroni: TCheckBox
      Left = 545
      Top = 25
      Width = 100
      Height = 18
      Caption = #1041#1088#1086#1085#1100' (Alt+B)'
      TabOrder = 7
      OnClick = cbxBroniClick
    end
    object cmbValuta: TComboBox
      Left = 149
      Top = 48
      Width = 121
      Height = 21
      Style = csDropDownList
      TabOrder = 8
      OnChange = cmbValutaChange
      Items.Strings = (
        'RUP'
        'LEI'
        'EUR'
        'USD')
    end
    object stCursVal: TStaticText
      Left = 275
      Top = 50
      Width = 54
      Height = 16
      AutoSize = False
      Caption = '0.00'
      TabOrder = 9
    end
    object EdTickCount: TMaskEdit
      Left = 420
      Top = 48
      Width = 121
      Height = 21
      Color = clInfoBk
      Enabled = False
      ReadOnly = True
      TabOrder = 10
      Text = ''
      OnChange = EdTickCountChange
    end
    object meFilter: TDBLookupComboBox
      Left = 149
      Top = 2
      Width = 121
      Height = 21
      KeyField = 'ID'
      ListField = 'DENUMIREA'
      ListSource = dmCassa.dsComplexFilt
      TabOrder = 11
    end
    object btnBroni: TButton
      Left = 950
      Top = 8
      Width = 75
      Height = 25
      Anchors = [akTop, akRight]
      Caption = #1041#1088#1086#1085#1080
      TabOrder = 12
      OnClick = btnBroniClick
      ExplicitLeft = 944
    end
  end
  object pnlTipar: TPanel
    Left = 0
    Top = 334
    Width = 1026
    Height = 181
    Align = alBottom
    BevelOuter = bvNone
    Color = clWindow
    TabOrder = 2
    ExplicitWidth = 1020
    object Panel1: TPanel
      Left = 0
      Top = 0
      Width = 264
      Height = 181
      Align = alLeft
      Color = clInfoBk
      ParentBackground = False
      TabOrder = 0
      object Label7: TLabel
        Left = 105
        Top = 56
        Width = 41
        Height = 16
        Alignment = taRightJustify
        Caption = #1057#1076#1072#1095#1072
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clHighlight
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label6: TLabel
        Left = 91
        Top = 30
        Width = 56
        Height = 16
        Alignment = taRightJustify
        Caption = #1055#1088#1080#1085#1103#1090#1086
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clHighlight
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label5: TLabel
        Left = 38
        Top = 4
        Width = 108
        Height = 16
        Alignment = taRightJustify
        Caption = #1057#1091#1084#1084#1072' '#1082' '#1086#1087#1083#1072#1090#1077
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clHighlight
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object btnLaTipar: TBitBtn
        Left = 2
        Top = 83
        Width = 137
        Height = 33
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
        TabOrder = 3
        OnClick = btnLaTiparClick
      end
      object btAnul: TBitBtn
        Left = 138
        Top = 83
        Width = 123
        Height = 33
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
        TabOrder = 4
        OnClick = btAnulClick
      end
      object btFullOk: TBitBtn
        Left = 2
        Top = 115
        Width = 137
        Height = 33
        Caption = #1041#1080#1083#1077#1090' '#1085#1072#1087#1077#1095'-'#1085' (Alt+T)'
        Glyph.Data = {
          EE000000424DEE000000000000007600000028000000100000000F0000000100
          0400000000007800000000000000000000001000000010000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
          88888888888888888888888888800000000088088880FFFFFFF088008880F00F
          00F000000880FFFFFFF000000080F00F00F000000880FFFFFFF088008884C4C4
          C4C48808888CF4CF4CFC88888884C4C4C44C8888888888888888888888888888
          888888888888888888888888888888888888}
        TabOrder = 5
        OnClick = btFullOkClick
      end
      object btnLaTiparLISTADEIMB: TBitBtn
        Left = 138
        Top = 115
        Width = 123
        Height = 33
        Caption = #1057#1087#1080#1089'. '#1087#1072#1089#1089'.(Alt+L)'
        Glyph.Data = {
          F6000000424DF600000000000000760000002800000010000000100000000100
          0400000000008000000000000000000000001000000010000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
          888F8800000000000888808888888880808800000000000008080888888BBB88
          0008088888877788080800000000000008800888888888808080800000000008
          0800880FFFFFFFF080808880F00000F000088880FFFFFFFF088888880F00000F
          088888880FFFFFFFF08888888000000000888888888888888888}
        TabOrder = 6
        OnClick = btnLaTiparLISTADEIMBClick
      end
      object dbePlata: TRzDBNumericEdit
        Left = 152
        Top = 4
        Width = 104
        Height = 25
        TabStop = False
        DataField = 'SUMA_PACH'
        ReadOnly = True
        Alignment = taLeftJustify
        Color = clInfoBk
        Ctl3D = True
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Courier New'
        Font.Style = [fsBold]
        ParentColor = True
        ParentCtl3D = False
        ParentFont = False
        TabOrder = 0
        IntegersOnly = False
        DisplayFormat = ',0;(,0)'
      end
      object dbBaniiPrim: TRzDBNumericEdit
        Left = 152
        Top = 30
        Width = 104
        Height = 25
        DataField = 'SUMA_PRIM'
        Alignment = taLeftJustify
        Ctl3D = True
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Courier New'
        Font.Style = [fsBold]
        ParentCtl3D = False
        ParentFont = False
        TabOrder = 1
        OnChange = dbBaniiPrimChange
        OnKeyDown = dbBaniiPrimKeyDown
        IntegersOnly = False
        DisplayFormat = ',0;(,0)'
      end
      object dbRest: TRzDBNumericEdit
        Left = 152
        Top = 56
        Width = 104
        Height = 25
        TabStop = False
        DataField = 'clcSumaRest'
        ReadOnly = True
        Alignment = taLeftJustify
        Color = clInfoBk
        Ctl3D = True
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Courier New'
        Font.Style = [fsBold]
        ParentColor = True
        ParentCtl3D = False
        ParentFont = False
        TabOrder = 2
        IntegersOnly = False
        DisplayFormat = ',0;(,0)'
      end
      object cbxStopRuta: TRzCheckBox
        Left = 6
        Top = 56
        Width = 78
        Height = 16
        Caption = #1040#1074#1090'. '#1086#1090#1087#1088'.'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clPurple
        Font.Height = -12
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        State = cbUnchecked
        TabOrder = 7
      end
      object btLaTiparBon: TBitBtn
        Left = 2
        Top = 147
        Width = 137
        Height = 33
        Caption = #1055#1077#1095'. '#1095#1077#1082
        TabOrder = 8
        OnClick = btLaTiparBonClick
      end
      object BtPterminal: TBitBtn
        Left = 138
        Top = 147
        Width = 123
        Height = 33
        Caption = #1055#1083#1072#1090#1072' '#1090#1077#1088#1084#1080#1085#1072#1083
        TabOrder = 9
        OnClick = BtPterminalClick
      end
    end
    object Panel3: TPanel
      Left = 449
      Top = 0
      Width = 577
      Height = 181
      Align = alClient
      BevelOuter = bvNone
      Color = clWindow
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Courier New'
      Font.Style = []
      ParentBackground = False
      ParentFont = False
      TabOrder = 1
      ExplicitWidth = 571
      object RzDBStatusPane1: TRzDBStatusPane
        Left = 0
        Top = 0
        Width = 577
        FillColor = clHighlightText
        FrameStyle = fsNone
        ParentFillColor = False
        Transparent = False
        Align = alTop
        ParentColor = False
        ParentShowHint = False
        FieldLabel = 'Lenta '
        DataField = 'ID'
        ExplicitWidth = 581
      end
      object mmInfo: TMemo
        Left = 0
        Top = 20
        Width = 577
        Height = 161
        Align = alClient
        BorderStyle = bsNone
        TabOrder = 0
        ExplicitWidth = 571
        ExplicitHeight = 131
      end
      object ToInlCallButton: TButton
        Left = 0
        Top = 121
        Width = 145
        Height = 30
        Align = alCustom
        Caption = 'F9 - '#1041#1080#1083#1077#1090' '#1086#1090'.'
        TabOrder = 1
        OnClick = toInlExecute
      end
      object F12ToInlButton: TButton
        Left = 0
        Top = 152
        Width = 145
        Height = 29
        Align = alCustom
        Anchors = [akLeft, akBottom]
        Caption = 'F12 - '#1041#1080#1083#1077#1090' <-> '#1054#1090#1076'.'
        TabOrder = 2
        OnClick = toInlExecute
      end
    end
    object pnlBilet: TPanel
      Left = 264
      Top = 0
      Width = 185
      Height = 181
      Align = alLeft
      TabOrder = 2
      object dbmemoBilet: TRzDBRichEdit
        Left = 1
        Top = 1
        Width = 183
        Height = 159
        TabStop = False
        Align = alTop
        BorderStyle = bsNone
        Color = clInfoBk
        DataField = 'CECU'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Courier New'
        Font.Style = []
        ReadOnly = True
        ScrollBars = ssVertical
        TabOrder = 0
        WordWrap = False
        Zoom = 100
        OnClick = dbmemoBiletExit
        OnExit = dbmemoBiletExit
      end
      object btnBiletToClipboard: TButton
        Left = 1
        Top = 157
        Width = 184
        Height = 23
        Caption = 'Copy to clipboard'
        TabOrder = 1
        OnClick = btnBiletToClipboardClick
      end
    end
  end
  object ActionList1: TActionList
    Left = 768
    Top = 369
    object toInl: TAction
      Caption = #1051#1100#1075#1086#1090#1099' '#1080' '#1073#1072#1075#1072#1078
      ShortCut = 123
      OnExecute = toInlExecute
    end
    object ToInlQuick: TAction
      Caption = #1051#1100#1075#1086#1090#1099' '#1080' '#1073#1072#1075#1072#1078
      ShortCut = 120
      OnExecute = toInlExecute
    end
    object ToAn: TAction
      Caption = 'ToAn'
      ShortCut = 32833
      OnExecute = btAnulClick
    end
    object ToTipar: TAction
      Caption = 'ToTipar'
      ShortCut = 32848
      OnExecute = btnLaTiparClick
    end
    object ToFullOk: TAction
      Caption = 'ToFullOk'
      ShortCut = 32852
      OnExecute = btFullOkClick
    end
    object toBagaj: TAction
      Caption = 'toBagaj'
      ShortCut = 121
      OnExecute = toBagajExecute
    end
    object toPasaport: TAction
      Caption = 'toPasaport'
      ShortCut = 122
      OnExecute = toInlExecute
    end
    object actVinzPeeron: TAction
      Caption = 'Vizarea peron (Alt+E)'
      ShortCut = 32837
      OnExecute = actVinzPeeronExecute
    end
    object actRutaPlecat: TAction
      Caption = 'Ruta a plecat'
      ShortCut = 32853
      OnExecute = actRutaPlecatExecute
    end
    object actListImb: TAction
      Caption = 'actListImb'
      ShortCut = 32844
      OnExecute = btnLaTiparLISTADEIMBClick
    end
    object actBroni: TAction
      Caption = 'actBroni'
      ShortCut = 32834
      OnExecute = actBroniExecute
    end
    object actCustom: TAction
      Caption = 'actCustom'
      ShortCut = 117
      OnExecute = actCustomExecute
    end
    object actSel: TAction
      Caption = 'Selection'
      ShortCut = 13
    end
  end
  object srvTimer: TTimer
    OnTimer = srvTimerTimer
    Left = 840
    Top = 368
  end
  object Timer1: TTimer
    Interval = 300
    OnTimer = Timer1Timer
    Left = 912
    Top = 369
  end
  object dsT1RUTABRONI: TOraDataSource
    Left = 792
    Top = 432
  end
  object LS: TUnLangSelector
    UnLanguage = lnRus
    UnSections = <>
    Left = 400
    Top = 200
    CompList = (
      'fVinz'
      'dbgrV'
      'Label10'
      'Label12'
      'Label13'
      'Label14'
      'Label15'
      'lblTimp'
      'Label1'
      'Label2'
      'Label3'
      'Label4'
      'Label8'
      'lblGrupaCasei'
      'lblValuta'
      'btSelect'
      'cbxPerron'
      'cbxBroni'
      'Label7'
      'Label6'
      'Label5'
      'btnLaTipar'
      'btAnul'
      'btFullOk'
      'btnLaTiparLISTADEIMB'
      'cbxStopRuta'
      'dbmemoBilet'
      'Label11'
      'Label9'
      'toInl'
      'ToInlQuick'
      'ToAn'
      'ToTipar'
      'ToFullOk'
      'toBagaj'
      'toPasaport'
      'actVinzPeeron'
      'actRutaPlecat'
      'actListImb'
      'actBroni')
    CompStrEng = (
      '[fVinz]'
      'Caption=Sale'
      '[Label10]'
      'Caption=Type'
      '[Label12]'
      'Caption=DOCUMENT'
      '[Label13]'
      'Caption=ADD INFO'
      '[Label14]'
      'Caption=cant.bil.'
      '[Label15]'
      'Caption=Cod reserv.'
      '[lblTimp]'
      'Caption=lblTimp'
      '[Label1]'
      'Caption=Destination'
      '[Label2]'
      'Caption=Date'
      '[Label3]'
      'Caption=Tick. quant.'
      '[Label4]'
      'Caption=Route'
      '[Label8]'
      'Caption=Filtr'
      '[lblGrupaCasei]'
      'Caption=STATION'
      '[lblValuta]'
      'Caption=CURRENCY'
      '[btSelect]'
      'Caption=Select (Enter)'
      '[cbxPerron]'
      'Caption=Platf. sale (Alt+E)'
      '[cbxBroni]'
      'Caption=Reserv. (Alt+B)'
      '[Label7]'
      'Caption='#1057'hange'
      '[Label6]'
      'Caption=Received'
      '[Label5]'
      'Caption=Sum for pay'
      '[btnLaTipar]'
      'Caption=Print (Alt+P)'
      '[btAnul]'
      'Caption=Cancel (Alt+A)'
      '[btFullOk]'
      'Caption=Ticket printed (Alt+T)'
      '[btnLaTiparLISTADEIMB]'
      'Caption=Passeng. list(Alt+L)'
      '[cbxStopRuta]'
      'Caption=Bus has gone'
      '[Label11]'
      'Caption=F12 - Ticket <-> Returned'
      '[Label9]'
      'Caption=F9 - Ticket ext'
      '[toInl]'
      'Caption=Benef. and bagage'
      '[ToInlQuick]'
      'Caption=Benef. and bagage'
      '[ToAn]'
      'Caption=ToAn'
      '[ToTipar]'
      'Caption=ToTipar'
      '[ToFullOk]'
      'Caption=ToFullOk'
      '[toBagaj]'
      'Caption=toBagaj'
      '[toPasaport]'
      'Caption=toPasaport'
      '[actVinzPeeron]'
      'Caption=Vizarea peron (Alt+E)'
      '[actRutaPlecat]'
      'Caption=Ruta a plecat'
      '[actListImb]'
      'Caption=actListImb'
      '[actBroni]'
      'Caption=actBroni')
    CompStrRom = (
      '[fVinz]'
      'Caption=Vinzare'
      '[Label10]'
      'Caption=Tip'
      '[Label12]'
      'Caption=DOCUMENT'
      '[Label13]'
      'Caption=ADD INFO'
      '[Label14]'
      'Caption=cant.bil.'
      '[Label15]'
      'Caption=Cod bronare'
      '[lblTimp]'
      'Caption=lblTimp'
      '[Label1]'
      'Caption=Destinatia'
      '[Label2]'
      'Caption=Data'
      '[Label3]'
      'Caption=Cite bilete'
      '[Label4]'
      'Caption=Ruta'
      '[Label8]'
      'Caption=Filtru'
      '[lblGrupaCasei]'
      'Caption=GARA'
      '[lblValuta]'
      'Caption=VALUTA'
      '[btSelect]'
      'Caption=Selectare (Enter)'
      '[cbxPerron]'
      'Caption=Vinz. peron (Alt+E)'
      '[cbxBroni]'
      'Caption=Bronarea (Alt+B)'
      '[Label7]'
      'Caption=Restul'
      '[Label6]'
      'Caption=Primit'
      '[Label5]'
      'Caption=Suma pentru plata'
      '[btnLaTipar]'
      'Caption=La tipar (Alt+P)'
      '[btAnul]'
      'Caption=Anulare (Alt+A)'
      '[btFullOk]'
      'Caption=Bilet s-a tiparit (Alt+T)'
      '[btnLaTiparLISTADEIMB]'
      'Caption=Lista de imb.(Alt+L)'
      '[cbxStopRuta]'
      'Caption=Ruta a plecat'
      '[Label11]'
      'Caption=F12 - Bilet <-> Predat'
      '[Label9]'
      'Caption=F9 - Bilet ext'
      '[toInl]'
      'Caption=Inlesniri si bagaj'
      '[ToInlQuick]'
      'Caption=Inlesniri si bagaj'
      '[ToAn]'
      'Caption=ToAn'
      '[ToTipar]'
      'Caption=ToTipar'
      '[toBagaj]'
      'Caption=toBagaj'
      '[toPasaport]'
      'Caption=toPasaport'
      '[actVinzPeeron]'
      'Caption=Vizarea peron (Alt+E)'
      '[actRutaPlecat]'
      'Caption=Ruta a plecat'
      '[actListImb]'
      'Caption=actListImb'
      '[actBroni]'
      'Caption=actBroni'
      '[ToFullOk]'
      'Caption=')
    CompStrRus = (
      '[fVinz]'
      'Caption='#1055#1088#1086#1076#1072#1078#1072
      '[Label10]'
      'Caption='#1058#1080#1087
      '[Label12]'
      'Caption='#1044#1054#1050#1059#1052#1045#1053#1058
      '[Label13]'
      'Caption='#1044#1054#1055'. '#1048#1053#1060'.'
      '[Label14]'
      'Caption='#1050#1086#1083'.'
      '[Label15]'
      'Caption='#1050#1086#1076' '#1073#1088#1086#1085#1080
      '[lblTimp]'
      'Caption=lblTimp'
      '[Label1]'
      'Caption='#1050#1091#1076#1072' '#1077#1076#1077#1084
      '[Label2]'
      'Caption='#1044#1072#1090#1072
      '[Label3]'
      'Caption='#1050#1086#1083'. '#1073#1080#1083'.'
      '[Label4]'
      'Caption='#1052#1072#1088#1096#1088'.'
      '[Label8]'
      'Caption='#1060#1080#1083#1090'.'
      '[lblGrupaCasei]'
      'Caption='#1042#1054#1050#1047#1040#1051
      '[lblValuta]'
      'Caption='#1042#1040#1051#1070#1058#1040
      '[btSelect]'
      'Caption='#1042#1099#1073#1086#1088' (Enter)'
      '[cbxPerron]'
      'Caption='#1055#1088#1086#1076' '#1085#1072' '#1087#1077#1088'. (Alt+E)'
      '[cbxBroni]'
      'Caption='#1041#1088#1086#1085#1100' (Alt+B)'
      '[Label7]'
      'Caption='#1057#1076#1072#1095#1072
      '[Label6]'
      'Caption='#1055#1088#1080#1085#1103#1090#1086
      '[Label5]'
      'Caption='#1057#1091#1084#1084#1072' '#1082' '#1086#1087#1083#1072#1090#1077
      '[btnLaTipar]'
      'Caption='#1055#1077#1095#1072#1090#1100' (Alt+P)'
      '[btAnul]'
      'Caption='#1054#1090#1084#1077#1085#1072' (Alt+A)'
      '[btFullOk]'
      'Caption='#1041#1080#1083#1077#1090' '#1085#1072#1087#1077#1095'-'#1085' (Alt+T)'
      '[btnLaTiparLISTADEIMB]'
      'Caption='#1057#1087#1080#1089'. '#1087#1072#1089#1089'.(Alt+L)'
      '[cbxStopRuta]'
      'Caption='#1040#1074#1090'. '#1086#1090#1087#1088'.'
      '[Label11]'
      'Caption=F12 - '#1041#1080#1083#1077#1090' <-> '#1054#1090#1076'.'
      '[Label9]'
      'Caption=F9 - '#1041#1080#1083#1077#1090' '#1086#1090'.'
      '[toInl]'
      'Caption='#1051#1100#1075#1086#1090#1099' '#1080' '#1073#1072#1075#1072#1078
      '[ToInlQuick]'
      'Caption='#1051#1100#1075#1086#1090#1099' '#1080' '#1073#1072#1075#1072#1078
      '[ToAn]'
      'Caption=ToAn'
      '[ToTipar]'
      'Caption=ToTipar'
      '[ToFullOk]'
      'Caption=ToFullOk'
      '[toBagaj]'
      'Caption=toBagaj'
      '[toPasaport]'
      'Caption=toPasaport'
      '[actVinzPeeron]'
      'Caption=Vizarea peron (Alt+E)'
      '[actRutaPlecat]'
      'Caption=Ruta a plecat'
      '[actListImb]'
      'Caption=actListImb'
      '[actBroni]'
      'Caption=actBroni')
  end
  object spSetCustomPrice: TOraStoredProc
    StoredProcName = 'circus.set_custom_ticket_price'
    Session = dmCassa.db
    SQL.Strings = (
      'begin'
      
        '  circus.set_custom_ticket_price(:P_ID_CASALENTA, :P_SUMM, :P_CO' +
        'MMENT);'
      'end;')
    Left = 608
    Top = 210
    ParamData = <
      item
        DataType = ftFloat
        Name = 'P_ID_CASALENTA'
        ParamType = ptInput
        Value = nil
      end
      item
        DataType = ftFloat
        Name = 'P_SUMM'
        ParamType = ptInput
        Value = nil
      end
      item
        DataType = ftString
        Name = 'P_COMMENT'
        ParamType = ptInput
        Value = nil
      end>
  end
  object TimerCheckBroni: TTimer
    Interval = 600000
    OnTimer = TimerCheckBroniTimer
    Left = 896
    Top = 186
  end
  object CheckBroniFlick: TTimer
    Enabled = False
    Interval = 1500
    OnTimer = CheckBroniFlickTimer
    Left = 816
    Top = 186
  end
end
