object fBiletInput: TfBiletInput
  Left = 881
  Top = 477
  Caption = #1042#1074#1077#1076#1080#1090#1077' '#1076#1072#1085#1085#1099#1077' '#1087#1086' '#1073#1080#1083#1077#1090#1091
  ClientHeight = 319
  ClientWidth = 677
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  ShowHint = True
  OnCloseQuery = FormCloseQuery
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 272
    Width = 677
    Height = 47
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
    object btOk: TBitBtn
      Left = 240
      Top = 6
      Width = 200
      Height = 33
      Caption = 'OK (Enter)'
      Kind = bkOK
      NumGlyphs = 2
      TabOrder = 0
      TabStop = False
      OnClick = btOkClick
    end
    object btCancel: TBitBtn
      Left = 467
      Top = 6
      Width = 200
      Height = 33
      Caption = #1054#1090#1084#1077#1085#1072' (ESC)'
      Kind = bkCancel
      NumGlyphs = 2
      TabOrder = 1
      TabStop = False
    end
    object cbApplyToAll: TCheckBox
      Left = 89
      Top = 16
      Width = 129
      Height = 17
      Caption = #1055#1088#1080#1084#1077#1085#1080#1090#1100' '#1082#1086' '#1074#1089#1077#1084
      TabOrder = 2
    end
  end
  object Panel2: TPanel
    Left = 221
    Top = 0
    Width = 456
    Height = 272
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    object lbInl: TLabel
      Left = 120
      Top = 59
      Width = 51
      Height = 16
      Alignment = taRightJustify
      Caption = #1051#1068#1043#1054#1058#1067
    end
    object lbDep: TLabel
      Left = 131
      Top = 93
      Width = 39
      Height = 16
      Alignment = taRightJustify
      Caption = #1054#1056#1043#1040#1053
    end
    object lbCert: TLabel
      Left = 85
      Top = 123
      Width = 82
      Height = 16
      Alignment = taRightJustify
      Caption = #8470' '#1044#1086#1082#1091#1084#1077#1085#1090#1072
      FocusControl = dbCert
    end
    object lbPN: TLabel
      Left = 141
      Top = 155
      Width = 27
      Height = 16
      Alignment = taRightJustify
      Caption = #1060#1048#1054
      FocusControl = dbPN
    end
    object lbPasp: TLabel
      Left = 89
      Top = 187
      Width = 82
      Height = 16
      Alignment = taRightJustify
      Caption = #8470' '#1044#1086#1082#1091#1084#1077#1085#1090#1072
    end
    object lbBag: TLabel
      Left = 128
      Top = 27
      Width = 43
      Height = 16
      Alignment = taRightJustify
      Caption = #1041#1040#1043#1040#1046
      FocusControl = dbBag
    end
    object Label7: TLabel
      Left = 258
      Top = 27
      Width = 42
      Height = 16
      Caption = #1052#1045#1057#1058#1054
      FocusControl = DBEdit7
    end
    object dbCert: TDBEdit
      Left = 177
      Top = 123
      Width = 200
      Height = 24
      DataField = 'CERTIFICAT'
      DataSource = dsBilets
      TabOrder = 3
    end
    object dbPN: TDBEdit
      Left = 177
      Top = 155
      Width = 200
      Height = 24
      DataField = 'PERS_NUMELE'
      DataSource = dsBilets
      TabOrder = 4
    end
    object dbBag: TDBEdit
      Left = 177
      Top = 24
      Width = 64
      Height = 24
      DataField = 'BAGAJ'
      DataSource = dsBilets
      TabOrder = 0
    end
    object DBEdit7: TDBEdit
      Left = 327
      Top = 24
      Width = 65
      Height = 25
      BorderStyle = bsNone
      Color = clMenu
      DataField = 'LOC'
      DataSource = dmCassa.dsBiltets
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
    end
    object seDep: TSagiEdit
      Left = 177
      Top = 91
      Width = 121
      Height = 24
      Hint = 
        #1045#1089#1083#1080' '#1074#1099' '#1085#1077' '#1085#1072#1096#1083#1080' '#1087#1086#1076#1093#1086#1076#1103#1097#1091#1102' '#1086#1088#1075#1072#1085#1080#1079#1072#1094#1080#1102' '#1074' '#1089#1087#1080#1089#1082#1077', '#1074#1074#1077#1076#1080#1090#1077' '#1077#1105' '#1074' '#1087 +
        #1086#1083#1077' "'#1041#1072#1079#1086#1074#1099#1081' '#1076#1086#1082#1091#1084#1077#1085#1090'"'
      Ctl3D = True
      DataField = 'DEPART'
      DataSource = dsBilets
      ParentCtl3D = False
      TabOrder = 2
      BtnPress = seDepBtnPress
      XBtnOnFocus = 1
    end
    object seInl: TSagiEdit
      Left = 177
      Top = 59
      Width = 65
      Height = 24
      Ctl3D = True
      DataField = 'INLESN'
      DataSource = dsBilets
      ParentCtl3D = False
      TabOrder = 1
      BtnPress = seInlBtnPress
      XBtnOnFocus = 1
    end
    object dbPasp: TDBMemo
      Left = 176
      Top = 184
      Width = 270
      Height = 85
      Hint = 
        #1047#1072#1087#1086#1083#1085#1080#1090#1077' '#1101#1090#1086' '#1087#1086#1083#1077', '#1089#1083#1091#1095#1072#1077' '#1077#1089#1083#1080' '#1085#1077' '#1085#1072#1096#1083#1080' '#1087#1086#1076#1093#1086#1076#1103#1097#1091#1102' '#1086#1088#1075#1072#1085#1080#1079#1072#1094#1080#1102' ' +
        #1074' '#1089#1087#1080#1089#1082#1077' '#1087#1086#1083#1103' "'#1054#1088#1075#1072#1085'"'
      DataField = 'PASAPORT'
      DataSource = dsBilets
      MaxLength = 255
      ScrollBars = ssVertical
      TabOrder = 6
    end
  end
  object rgTipBilet: TRadioGroup
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 215
    Height = 266
    Align = alLeft
    Caption = ' '#1058#1080#1087' '#1073#1080#1083#1077#1090#1072': '
    Items.Strings = (
      '1. '#1057' '#1073#1072#1075#1072#1078#1086#1084
      '2. M'#1077#1078#1091#1085#1072#1088#1086#1076#1085#1099#1081' '
      '3. '#1044#1077#1090#1089#1082#1080#1081
      '4. '#1055#1077#1085#1089#1080#1086#1085#1077#1088
      '5. '#1055#1086' '#1080#1085#1074#1072#1083#1080#1076#1085#1086#1089#1090#1080
      '6. '#1057#1090#1091#1076#1077#1085#1090
      '7. '#1042#1086#1077#1085#1085#1099#1081
      '8. '#1057#1080#1088#1086#1090#1099
      '9. '#1055#1088#1086#1095#1080#1081)
    TabOrder = 2
    OnClick = rgTipBiletClick
  end
  object qsBilAView: TSmartQuery
    Session = dmCassa.db
    SQL.Strings = (
      'select  '
      
        '(select count(i.COD_DEPART) from T0INLES_PE_DEPART i where i.COD' +
        '_INLESN=:INL) as INLDEP_NEED,'
      'n.CERTIFICATNOTNEED,'
      'n.NUMELENOTNEED,'
      'n.PASAPORTNOTNEED,'
      ' (select IPAS from t0ruta r '
      
        ' where r.codu=(select m.rutadebaza from t1ruta_m m,t0bilet b whe' +
        're trunc(m.data)=trunc(b.data) and m.codu= b.ruta and b.cod=:COD' +
        'B)) IPAS '
      'from T0INLESNIRI n'
      'where n.COD=:INL')
    Left = 273
    Top = 224
    ParamData = <
      item
        DataType = ftString
        Name = 'INL'
        ParamType = ptInput
        Size = 10
        Value = nil
      end
      item
        DataType = ftString
        Name = 'CODB'
        ParamType = ptInput
        Size = 30
        Value = nil
      end>
  end
  object dsBilets: TOraDataSource
    Left = 337
    Top = 224
  end
  object LS: TUnLangSelector
    UnLanguage = lnRus
    UnSections = <>
    OnSetLanguage = LSSetLanguage
    Left = 217
    Top = 128
    CompList = (
      'fBiletInput'
      'btOk'
      'btCancel'
      'lbInl'
      'lbDep'
      'lbCert'
      'lbPN'
      'lbPasp'
      'lbBag'
      'Label7'
      'seDep'
      'rgTipBilet'
      'dbPasp')
    CompStrEng = (
      '[fBiletInput]'
      'Caption=Enter the ticket data'
      '[btOk]'
      'Caption=OK (Enter)'
      '[btCancel]'
      'Caption=Cancel  (ESC)'
      '[rgTipBilet]'
      'Caption= Ticket type: '
      '[lbInl]'
      'Caption=BENEFITS'
      '[lbDep]'
      'Caption=DEPART'
      '[lbCert]'
      'Caption=CERTIFICAT'
      '[Label7]'
      'Caption=PLACE'
      '[lbPN]'
      'Caption=NAME'
      '[lbPasp]'
      'Caption=PASSPORT'
      '[lbBag]'
      'Caption=BAGGAGE'
      '[seDep]'
      
        'Hint=If you didn'#39't found suitable organization in the list, type' +
        ' it in "Baze document" field'
      '[dbPasp]'
      
        'Hint=Fill this field if you didn'#39't found a suitable organization' +
        ' in the "Depart" list')
    CompStrRom = (
      '[fBiletInput]'
      'Caption=Introducerea datelor in bilet'
      '[btOk]'
      'Caption=OK (Enter)'
      '[btCancel]'
      'Caption=Anulare (ESC)'
      '[rgTipBilet]'
      'Caption= Tipul biletului: '
      '[lbInl]'
      'Caption=INLESN'
      '[lbDep]'
      'Caption=DEPART'
      '[lbCert]'
      'Caption=CERTIFICAT'
      '[Label7]'
      'Caption=LOC'
      '[lbPN]'
      'Caption=NUMELE'
      '[lbPasp]'
      'Caption=PASAPORT'
      '[lbBag]'
      'Caption=BAGAJ'
      '[seDep]'
      
        'Hint=Daca nu ati gasit organizatia in lista, introduceti in camp' +
        'ul "Document de baza"'
      '[dbPasp]'
      
        'Hint=Introduceti organizatia in cimpul acesta, daca nu ati gasit' +
        '-o in lista "Depart"')
    CompStrRus = (
      '[fBiletInput]'
      'Caption='#1042#1074#1077#1076#1080#1090#1077' '#1076#1072#1085#1085#1099#1077' '#1087#1086' '#1073#1080#1083#1077#1090#1091
      '[btOk]'
      'Caption=OK (Enter)'
      '[btCancel]'
      'Caption='#1054#1090#1084#1077#1085#1072' (ESC)'
      '[rgTipBilet]'
      'Caption= '#1058#1080#1087' '#1073#1080#1083#1077#1090#1072': '
      '[lbInl]'
      'Caption='#1051#1068#1043#1054#1058#1067
      '[lbDep]'
      'Caption='#1054#1056#1043#1040#1053
      '[lbCert]'
      'Caption='#8470' '#1044#1086#1082#1091#1084#1077#1085#1090#1072
      '[Label7]'
      'Caption='#1052#1045#1057#1058#1054
      '[lbPN]'
      'Caption='#1060#1048#1054
      '[lbPasp]'
      'Caption='#8470' '#1044#1086#1082#1091#1084#1077#1085#1090#1072
      '[lbBag]'
      'Caption='#1041#1040#1043#1040#1046
      '[seDep]'
      
        'Hint='#1045#1089#1083#1080' '#1074#1099' '#1085#1077' '#1085#1072#1096#1083#1080' '#1087#1086#1076#1093#1086#1076#1103#1097#1091#1102' '#1086#1088#1075#1072#1085#1080#1079#1072#1094#1080#1102' '#1074' '#1089#1087#1080#1089#1082#1077', '#1074#1074#1077#1076#1080#1090#1077' '#1077 +
        #1105' '#1074' '#1087#1086#1083#1077' "'#1041#1072#1079#1086#1074#1099#1081' '#1076#1086#1082#1091#1084#1077#1085#1090'"'
      '[dbPasp]'
      
        'Hint='#1047#1072#1087#1086#1083#1085#1080#1090#1077' '#1101#1090#1086' '#1087#1086#1083#1077', '#1089#1083#1091#1095#1072#1077' '#1077#1089#1083#1080' '#1085#1077' '#1085#1072#1096#1083#1080' '#1087#1086#1076#1093#1086#1076#1103#1097#1091#1102' '#1086#1088#1075#1072#1085#1080#1079 +
        #1072#1094#1080#1102' '#1074' '#1089#1087#1080#1089#1082#1077' '#1087#1086#1083#1103' "'#1054#1088#1075#1072#1085'"')
    TextStrEng = (
      'ATTENTION=ATTENTIE !!!'
      '1=Bagaj'
      '2=International'
      '3=Copilaresc'
      '4=Pensionar'
      '5=Invalid'
      '6=Student'
      '7=Cashless payments'
      '8=Orfani'
      '9=Altul'
      'BazeDoc=Baze document'
      'Passport=PASSPORT')
    TextStrRom = (
      'ATTENTION=ATTENTION !!!'
      '1=Bagaj'
      '2=International'
      '3=Copilaresc'
      '4=Pensionar'
      '5=Invalid'
      '6=Student'
      '7=Plati fara numerar'
      '8=Orfani'
      '9=Altul'
      'BazeDoc=Document de baza'
      'Passport=PASAPORT')
    TextStrRus = (
      'ATTENTION='#1042#1053#1048#1052#1040#1053#1048#1045' !!!'
      '1=C '#1073#1072#1075#1072#1078#1086#1084
      '2='#1052#1077#1078#1091#1085#1072#1088#1086#1076#1085#1099#1081
      '3='#1044#1077#1090#1089#1082#1080#1081
      '4='#1055#1077#1085#1089#1080#1086#1085#1077#1088
      '5='#1055#1086' '#1080#1085#1074#1072#1083#1080#1076#1085#1086#1089#1090#1080
      '6='#1057#1090#1091#1076#1077#1085#1090
      '7='#1041#1077#1079#1085#1072#1083#1080#1095#1085#1099#1077' '#1088#1072#1089#1095#1077#1090#1099
      '8='#1057#1080#1088#1086#1090#1099
      '9='#1055#1088#1086#1095#1080#1081
      'BazeDoc='#1041#1072#1079#1086#1074#1099#1081' '#1076#1086#1082#1091#1084#1077#1085#1090
      'Passport='#1055#1040#1057#1055#1054#1056#1058)
  end
end
