object fSubscription: TfSubscription
  Left = 0
  Top = 0
  Caption = #1040#1073#1086#1085#1077#1084#1077#1085#1090#1099
  ClientHeight = 530
  ClientWidth = 1005
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Visible = True
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 0
    Top = 203
    Width = 1005
    Height = 3
    Cursor = crVSplit
    Align = alTop
    ExplicitTop = 161
    ExplicitWidth = 369
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 236
    Width = 1005
    Height = 294
    Align = alClient
    Caption = #1044#1086#1089#1090#1091#1087#1085#1099#1077' '#1089#1077#1072#1085#1089#1099
    TabOrder = 0
    ExplicitTop = 194
    ExplicitHeight = 336
    object Splitter2: TSplitter
      Left = 2
      Top = 15
      Height = 277
      ExplicitLeft = 544
      ExplicitTop = 328
      ExplicitHeight = 100
    end
    object grRoutes: TUnDBGrid
      Left = 5
      Top = 15
      Width = 998
      Height = 277
      Align = alClient
      Ctl3D = True
      DataSource = dsRoutes
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
          Color = clWindow
          Expanded = False
          FieldName = 'CODU'
          Title.Caption = #1050#1086#1076' '#1089#1077#1072#1085#1089#1072
          Visible = True
        end
        item
          Color = clWindow
          Expanded = False
          FieldName = 'DATA'
          Title.Caption = #1044#1072#1090#1072
          Visible = True
        end
        item
          Color = clWindow
          Expanded = False
          FieldName = 'DENUMIREA'
          Title.Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
          Visible = True
        end>
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1005
    Height = 41
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    object Label1: TLabel
      Left = 16
      Top = 14
      Width = 57
      Height = 13
      Caption = #1064#1090#1088#1080#1093#1082#1086#1076':'
    end
    object edBarcode: TEdit
      Left = 79
      Top = 11
      Width = 218
      Height = 21
      TabOrder = 0
      OnKeyPress = edBarcodeKeyPress
    end
    object btnFind: TButton
      Left = 302
      Top = 9
      Width = 75
      Height = 25
      Caption = #1053#1072#1081#1090#1080
      TabOrder = 1
      OnClick = btnFindClick
    end
    object lbBarcode: TcxLabel
      Left = 383
      Top = 4
      Caption = 'Barcode 022565645'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clWindowText
      Style.Font.Height = -19
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = [fsBold]
      Style.TextColor = clMaroon
      Style.TextStyle = [fsBold]
      Style.IsFontAssigned = True
      Properties.LabelStyle = cxlsRaised
    end
  end
  object GroupBox2: TGroupBox
    Left = 0
    Top = 41
    Width = 1005
    Height = 162
    Align = alTop
    Caption = #1040#1073#1086#1085#1077#1084#1077#1085#1090#1099
    TabOrder = 2
    object Splitter3: TSplitter
      Left = 821
      Top = 15
      Height = 145
      Align = alRight
      ExplicitLeft = 776
      ExplicitTop = 48
      ExplicitHeight = 100
    end
    object grSubscriptions: TUnDBGrid
      Left = 2
      Top = 15
      Width = 819
      Height = 145
      Align = alClient
      Ctl3D = True
      DataSource = dsContracts
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
          Color = clWindow
          Expanded = False
          FieldName = 'ID_TIP_CONTRACT'
          Title.Caption = #1050#1086#1076
          Width = 55
          Visible = True
        end
        item
          Color = clWindow
          Expanded = False
          FieldName = 'SUBSCRIPTION_TYPE_STR'
          Title.Caption = #1058#1080#1087' '#1072#1073#1086#1085#1077#1084#1077#1085#1090#1072
          Width = 150
          Visible = True
        end
        item
          Color = clWindow
          Expanded = False
          FieldName = 'CLIENT_STR'
          Title.Caption = #1050#1083#1080#1077#1085#1090
          Width = 183
          Visible = True
        end
        item
          Color = clWindow
          Expanded = False
          FieldName = 'SERIA'
          Title.Caption = #1057#1077#1088#1080#1103
          Width = 34
          Visible = True
        end
        item
          Color = clWindow
          Expanded = False
          FieldName = 'BARCODE'
          Title.Caption = #1064#1090#1088#1080#1093#1082#1086#1076
          Width = 128
          Visible = True
        end
        item
          Color = clWindow
          Expanded = False
          FieldName = 'SECTOR_STR'
          Title.Caption = #1057#1077#1082#1090#1086#1088
          Width = 90
          Visible = True
        end
        item
          Color = clWindow
          Expanded = False
          FieldName = 'TRIBUNE_STR'
          Title.Caption = #1058#1088#1080#1073#1091#1085#1072
          Width = 52
          Visible = True
        end
        item
          Color = clWindow
          Expanded = False
          FieldName = 'ROW_STR'
          Title.Caption = #1056#1103#1076
          Width = 34
          Visible = True
        end
        item
          Color = clWindow
          Expanded = False
          FieldName = 'PLACE_STR'
          Title.Caption = #1052#1077#1089#1090#1086
          Width = 40
          Visible = True
        end
        item
          Color = clWindow
          Expanded = False
          FieldName = 'VALID_FROM'
          Title.Caption = #1044#1077#1081#1089#1090#1074#1080#1090#1077#1083#1077#1085' '#1089
          Visible = True
        end
        item
          Color = clWindow
          Expanded = False
          FieldName = 'VALID_TILL'
          Title.Caption = #1044#1077#1081#1089#1090#1074#1080#1090#1077#1083#1077#1085' '#1076#1086
          Visible = True
        end
        item
          Color = clWindow
          Expanded = False
          FieldName = 'FINAL_PRICE'
          ReadOnly = False
          Title.Caption = #1057#1090#1086#1080#1084#1086#1089#1090#1100
          Visible = True
        end
        item
          Color = clWindow
          Expanded = False
          FieldName = 'DISCOUNT_STR'
          ReadOnly = False
          Title.Caption = #1057#1082#1080#1076#1082#1072
          Width = 90
          Visible = True
        end
        item
          Color = clWindow
          Expanded = False
          FieldName = 'ACTIVE_STR'
          ReadOnly = False
          Title.Caption = #1057#1090#1072#1090#1091#1089
          Width = 78
          Visible = True
        end>
    end
    object imgClient: TcxDBImage
      Left = 824
      Top = 15
      Align = alRight
      DataBinding.DataField = 'PHOTO'
      DataBinding.DataSource = dsContracts
      Properties.GraphicClassName = 'TdxSmartImage'
      Properties.ReadOnly = True
      TabOrder = 1
      ExplicitHeight = 103
      Height = 145
      Width = 179
    end
  end
  object pnlActions: TPanel
    Left = 0
    Top = 206
    Width = 1005
    Height = 30
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 3
    Visible = False
    ExplicitTop = 200
    object btnCheckIn: TButton
      Left = 2
      Top = 2
      Width = 75
      Height = 25
      Caption = 'Check In'
      TabOrder = 0
      OnClick = btnCheckInClick
    end
  end
  object qsContracts: TSagiODACSmartQuery
    Session = dmCassa.db
    SQL.Strings = (
      'select * from v1contracts'
      'where barcode = :barcode')
    AfterScroll = qsContractsAfterScroll
    Left = 624
    Top = 401
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'barcode'
        Value = Null
      end>
  end
  object qsRoutes: TSagiODACSmartQuery
    Session = dmCassa.db
    SQL.Strings = (
      'select * from v1contracts_ruta r'
      'where subscription_type_id = :subscription_type_id'
      '  and id_tip_contract = :id_tip_contract'
      '  and data between :valid_from and :valid_till'
      'order by data')
    MasterSource = dsContracts
    Left = 688
    Top = 401
    ParamData = <
      item
        DataType = ftFloat
        Name = 'subscription_type_id'
        ParamType = ptInput
        Value = nil
      end
      item
        DataType = ftFloat
        Name = 'id_tip_contract'
        ParamType = ptInput
        Value = nil
      end
      item
        DataType = ftDateTime
        Name = 'valid_from'
        ParamType = ptInput
        Value = nil
      end
      item
        DataType = ftDateTime
        Name = 'valid_till'
        ParamType = ptInput
        Value = nil
      end>
  end
  object dsContracts: TDataSource
    DataSet = qsContracts
    Left = 624
    Top = 449
  end
  object dsRoutes: TDataSource
    DataSet = qsRoutes
    Left = 688
    Top = 449
  end
  object spCheckIn: TOraStoredProc
    StoredProcName = 'PKG_SUBSCRIPTION.CHECKIN'
    SQL.Strings = (
      'begin'
      
        '  PKG_SUBSCRIPTION.CHECKIN(:P_SUBSCRIPTION_ID, :P_EVENT_ID, :P_E' +
        'VENT_DATE);'
      'end;')
    Left = 432
    Top = 410
    ParamData = <
      item
        DataType = ftFloat
        Name = 'P_SUBSCRIPTION_ID'
        ParamType = ptInput
        Value = nil
      end
      item
        DataType = ftFloat
        Name = 'P_EVENT_ID'
        ParamType = ptInput
        Value = nil
      end
      item
        DataType = ftDateTime
        Name = 'P_EVENT_DATE'
        ParamType = ptInput
        Value = nil
      end>
    CommandStoredProcName = 'PKG_SUBSCRIPTION.CHECKIN'
  end
end
