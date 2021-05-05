object fTOAD: TfTOAD
  Left = 629
  Top = 138
  Caption = 'Vizionare registrelor si tabelelor'
  ClientHeight = 531
  ClientWidth = 680
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = True
  Scaled = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object pcTOAD: TcxPageControl
    Left = 0
    Top = 0
    Width = 680
    Height = 531
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    Properties.ActivePage = tsQueries
    Properties.CustomButtons.Buttons = <>
    Properties.HotTrack = True
    Properties.Style = 9
    Properties.TabPosition = tpBottom
    ClientRectBottom = 511
    ClientRectRight = 680
    ClientRectTop = 0
    object tsTables: TcxTabSheet
      Caption = 'Tabele'
      ExplicitWidth = 0
      ExplicitHeight = 0
      object splObjects: TcxSplitter
        Left = 201
        Top = 0
        Width = 8
        Height = 511
        Cursor = crHSplit
        HotZoneClassName = 'TcxMediaPlayer9Style'
        Control = panLeft
      end
      object panLeft: TPanel
        Left = 0
        Top = 0
        Width = 201
        Height = 511
        Align = alLeft
        BevelOuter = bvNone
        TabOrder = 0
        object grObjects: TUnDBGrid
          Left = 0
          Top = 33
          Width = 201
          Height = 478
          Align = alClient
          Ctl3D = True
          DataSource = dsObjects
          ParentCtl3D = False
          TabOrder = 0
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
          XTitleHeight = 17
          UnLanguage = lnRom
          Columns = <
            item
              Color = clWindow
              Expanded = False
              FieldName = 'NAME'
              Width = 168
              Visible = True
            end>
        end
        object panTop: TPanel
          Left = 0
          Top = 0
          Width = 201
          Height = 33
          Align = alTop
          BevelOuter = bvNone
          TabOrder = 1
          object rgObject: TRadioGroup
            Left = 0
            Top = 0
            Width = 144
            Height = 33
            Align = alClient
            Caption = 'Selectati objectul:'
            Columns = 2
            ItemIndex = 0
            Items.Strings = (
              'Tabele'
              'Vision.')
            TabOrder = 0
            OnClick = rgObjectClick
          end
          object panRefresh: TPanel
            Left = 144
            Top = 0
            Width = 57
            Height = 33
            Align = alRight
            BevelInner = bvRaised
            BevelOuter = bvLowered
            TabOrder = 1
            object sbRefObjects: TSpeedButton
              Left = 3
              Top = 8
              Width = 23
              Height = 22
              OnClick = sbRefObjectsClick
            end
            object sbRefCustom: TSpeedButton
              Left = 31
              Top = 3
              Width = 23
              Height = 22
              OnClick = sbRefCustomClick
            end
          end
        end
      end
      object grCustom: TUnDBGrid
        Left = 209
        Top = 0
        Width = 471
        Height = 511
        Align = alClient
        Ctl3D = True
        DataSource = dsCustom
        ParentCtl3D = False
        TabOrder = 1
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'Tahoma'
        TitleFont.Style = []
        XTitleHeight = 17
        UnLanguage = lnRom
      end
    end
    object tsQueries: TcxTabSheet
      Caption = 'Query'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ExplicitWidth = 0
      ExplicitHeight = 0
      object splQuery: TcxSplitter
        Left = 0
        Top = 182
        Width = 8
        Height = 8
        Cursor = crVSplit
        HotZoneClassName = 'TcxMediaPlayer9Style'
        AlignSplitter = salBottom
        Control = panResult
      end
      object panQuery: TPanel
        Left = 0
        Top = 0
        Width = 680
        Height = 182
        Align = alClient
        BevelOuter = bvNone
        TabOrder = 0
        object dcmQuery: TUnSynEditPLSQL
          Left = 0
          Top = 0
          Width = 680
          Height = 163
          Align = alClient
          ActiveLineColor = clInfoBk
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Courier New'
          Font.Pitch = fpFixed
          Font.Style = []
          TabOrder = 0
          OnKeyDown = dcmQueryKeyDown
          BorderStyle = bsSingle
          Gutter.AutoSize = True
          Gutter.Font.Charset = DEFAULT_CHARSET
          Gutter.Font.Color = clWindowText
          Gutter.Font.Height = -11
          Gutter.Font.Name = 'Courier New'
          Gutter.Font.Style = []
          Gutter.LeftOffset = 6
          Gutter.RightOffset = 7
          Gutter.ShowLineNumbers = True
          Gutter.GradientEndColor = clMenu
          Options = [eoAutoIndent, eoDragDropEditing, eoEnhanceEndKey, eoGroupUndo, eoShowScrollHint, eoSmartTabDelete, eoSmartTabs, eoTabsToSpaces]
          RightEdge = 80
          TabWidth = 2
          WantTabs = True
          FontSmoothing = fsmClearType
        end
        object sbSQL: TStatusBar
          Left = 0
          Top = 163
          Width = 680
          Height = 19
          DoubleBuffered = True
          Panels = <
            item
              Width = 280
            end
            item
              Width = 50
            end>
          ParentDoubleBuffered = False
        end
      end
      object panResult: TPanel
        Left = 0
        Top = 190
        Width = 680
        Height = 321
        Align = alBottom
        BevelOuter = bvNone
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        object dbgrTVQ: TDBGridMy1
          Left = 0
          Top = 0
          Width = 680
          Height = 232
          Align = alClient
          Ctl3D = True
          DataSource = dsTVQ
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Options = [dgEditing, dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete]
          ParentCtl3D = False
          ParentFont = False
          TabOrder = 0
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -11
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
          OnColEnter = dbgrTVQColEnter
          XTitleHeight = 17
        end
        object splMemo: TcxSplitter
          Left = 0
          Top = 232
          Width = 8
          Height = 8
          Cursor = crVSplit
          HotZoneClassName = 'TcxMediaPlayer9Style'
          AlignSplitter = salBottom
          Control = dbmField
        end
        object dbmField: TDBMemo
          Left = 0
          Top = 240
          Width = 680
          Height = 81
          Align = alBottom
          DataSource = dsTVQ
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          ScrollBars = ssBoth
          TabOrder = 2
          WordWrap = False
          OnKeyDown = dbmFieldKeyDown
        end
      end
    end
    object tsSold: TcxTabSheet
      Caption = 'Sold'
      ImageIndex = 2
      object gbSoldOptions: TcxGroupBox
        Left = 0
        Top = 0
        Align = alTop
        Caption = 'Parametres'
        TabOrder = 0
        Height = 241
        Width = 680
        object edSoldDate: TcxDateEdit
          Left = 64
          Top = 16
          Properties.OnChange = SoldParametersChange
          TabOrder = 0
          Width = 81
        end
        object cbSoldMethodOLD: TcxCheckBox
          Left = 152
          Top = 16
          Caption = 'Metoda veche'
          Properties.OnChange = SoldParametersChange
          TabOrder = 1
          Width = 97
        end
        object cbSoldNoActual: TcxCheckBox
          Left = 256
          Top = 16
          Caption = 'Nu sold actual'
          Properties.OnChange = SoldParametersChange
          TabOrder = 2
          Width = 97
        end
        object lbSoldDate: TcxLabel
          Left = 8
          Top = 18
          Caption = 'Data:'
        end
        object cbSoldShowZero: TcxCheckBox
          Left = 360
          Top = 16
          Caption = 'Include zero'
          Properties.OnChange = SoldParametersChange
          TabOrder = 4
          Width = 97
        end
        object cbSoldSmart: TcxCheckBox
          Left = 464
          Top = 16
          Caption = 'Smart'
          Properties.OnChange = SoldParametersChange
          TabOrder = 5
          Width = 57
        end
        object cbSoldAP: TcxCheckBox
          Left = 528
          Top = 16
          Caption = 'A/P'
          Properties.OnChange = SoldParametersChange
          TabOrder = 6
          Width = 49
        end
        object cbSoldCont: TcxCheckBox
          Left = 8
          Top = 48
          Caption = 'Cont'
          Properties.OnChange = SoldParametersChange
          TabOrder = 7
          Width = 65
        end
        object cbSoldCont1: TcxCheckBox
          Left = 72
          Top = 48
          Caption = '.sc'
          Properties.OnChange = SoldParametersChange
          TabOrder = 8
          Width = 49
        end
        object cbSoldSC: TcxCheckBox
          Left = 8
          Top = 68
          Caption = 'Analitica'
          Properties.OnChange = SoldParametersChange
          TabOrder = 9
          Width = 121
        end
        object cbSoldDep: TcxCheckBox
          Left = 8
          Top = 88
          Caption = 'Centru de cost'
          Properties.OnChange = SoldParametersChange
          TabOrder = 10
          Width = 121
        end
        object cbSoldSC1: TcxCheckBox
          Left = 8
          Top = 108
          Caption = 'Subconto'
          Properties.OnChange = SoldParametersChange
          TabOrder = 11
          Width = 121
        end
        object edSoldCont: TcxTextEdit
          Left = 128
          Top = 48
          Properties.OnChange = SoldParametersChange
          TabOrder = 12
          Width = 121
        end
        object edSoldCont1: TcxTextEdit
          Left = 256
          Top = 48
          Properties.OnChange = SoldParametersChange
          TabOrder = 13
          Width = 57
        end
        object edSoldSC: TUnScList
          Left = 128
          Top = 69
          Width = 185
          Height = 21
          UnDontCacheParams = True
          OnChange = SoldParametersChange
          UseDockManager = True
          TabOrder = 14
          TabStop = True
          DesignSize = (
            185
            21)
        end
        object edSoldDep: TUnScList
          Left = 128
          Top = 88
          Width = 185
          Height = 21
          UnDontCacheParams = True
          OnChange = SoldParametersChange
          UseDockManager = True
          TabOrder = 15
          TabStop = True
          DesignSize = (
            185
            21)
        end
        object edSoldSC1: TUnScList
          Left = 128
          Top = 108
          Width = 185
          Height = 21
          UnDontCacheParams = True
          OnChange = SoldParametersChange
          UseDockManager = True
          TabOrder = 16
          TabStop = True
          DesignSize = (
            185
            21)
        end
        object cbSoldNrDoc: TcxCheckBox
          Left = 320
          Top = 48
          Caption = 'NrDoc'
          Properties.OnChange = SoldParametersChange
          TabOrder = 17
          Width = 65
        end
        object edSoldNrDoc: TcxTextEdit
          Left = 384
          Top = 48
          Properties.OnChange = SoldParametersChange
          TabOrder = 18
          Width = 137
        end
        object cbSoldStrSC: TcxCheckBox
          Left = 320
          Top = 68
          Caption = 'StrSC'
          Properties.OnChange = SoldParametersChange
          TabOrder = 19
          Width = 65
        end
        object edSoldStrSC: TcxTextEdit
          Left = 384
          Top = 68
          Properties.OnChange = SoldParametersChange
          TabOrder = 20
          Width = 137
        end
        object cbSoldNrCM: TcxCheckBox
          Left = 320
          Top = 88
          Caption = 'NrCM'
          Properties.OnChange = SoldParametersChange
          TabOrder = 21
          Width = 65
        end
        object edSoldNrCM: TcxTextEdit
          Left = 384
          Top = 88
          Properties.OnChange = SoldParametersChange
          TabOrder = 22
          Width = 137
        end
        object cbSoldData: TcxCheckBox
          Left = 320
          Top = 108
          Caption = 'Data'
          Properties.OnChange = SoldParametersChange
          TabOrder = 23
          Width = 65
        end
        object edSoldData: TcxTextEdit
          Left = 384
          Top = 108
          Properties.OnChange = SoldParametersChange
          TabOrder = 24
          Width = 137
        end
        object cbSoldCant: TcxCheckBox
          Left = 528
          Top = 48
          Caption = 'Cant'
          Properties.OnChange = SoldParametersChange
          TabOrder = 25
          Width = 49
        end
        object cbSoldPret: TcxCheckBox
          Left = 584
          Top = 48
          Caption = 'Pret'
          Properties.OnChange = SoldParametersChange
          TabOrder = 26
          Width = 49
        end
        object cbSoldSumaVal: TcxCheckBox
          Left = 528
          Top = 68
          Caption = 'Suma val.'
          Properties.OnChange = SoldParametersChange
          TabOrder = 27
          Width = 81
        end
        object cbSoldSumaGaap: TcxCheckBox
          Left = 528
          Top = 88
          Caption = 'Suma gaap'
          Properties.OnChange = SoldParametersChange
          TabOrder = 28
          Width = 81
        end
        object cbSoldCant1: TcxCheckBox
          Left = 528
          Top = 108
          Caption = 'Cant adaug.'
          Properties.OnChange = SoldParametersChange
          TabOrder = 29
          Width = 81
        end
        object edSoldCmd: TcxTextEdit
          Left = 8
          Top = 172
          Properties.ReadOnly = True
          TabOrder = 30
          Width = 641
        end
        object btMakeSold: TcxButton
          Left = 8
          Top = 208
          Width = 97
          Height = 25
          Caption = 'Calculare!'
          TabOrder = 31
        end
        object btSoldTestTXSLD: TcxButton
          Left = 112
          Top = 208
          Width = 97
          Height = 25
          Caption = 'Test TXSLD'
          TabOrder = 32
        end
        object btSoldRebuildTXSLD: TcxButton
          Left = 216
          Top = 208
          Width = 97
          Height = 25
          Caption = 'Rebuild TXSLD'
          TabOrder = 33
        end
        object btSoldRebuildTSLD: TcxButton
          Left = 320
          Top = 208
          Width = 97
          Height = 25
          Caption = 'Rebuild TSLD'
          TabOrder = 34
        end
        object btSoldClearZTEMP: TcxButton
          Left = 424
          Top = 208
          Width = 97
          Height = 25
          Caption = 'Clear ZTEMP'
          TabOrder = 35
        end
        object lbSoldID: TcxLabel
          Left = 8
          Top = 138
          Caption = 'ID/Table:'
        end
        object edSoldID: TcxTextEdit
          Left = 64
          Top = 136
          Properties.OnChange = SoldParametersChange
          TabOrder = 37
          Width = 121
        end
        object lbSoldFilter: TcxLabel
          Left = 208
          Top = 138
          Caption = 'Filtru:'
        end
        object edSoldFilter: TcxTextEdit
          Left = 248
          Top = 136
          Properties.OnChange = SoldParametersChange
          TabOrder = 39
          Width = 401
        end
      end
      object grSold: TUnDBGrid
        Left = 0
        Top = 241
        Width = 680
        Height = 270
        Align = alClient
        Ctl3D = True
        DataSource = dsSold
        ParentCtl3D = False
        ReadOnly = True
        TabOrder = 1
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'Tahoma'
        TitleFont.Style = []
        UnRememberDesign = True
        XTitleHeight = 17
        Columns = <
          item
            Color = clWindow
            Expanded = False
            FieldName = 'CONT'
            Title.Alignment = taCenter
            Title.Caption = 'Cont'
            Width = 40
            Visible = True
          end
          item
            Color = clWindow
            Expanded = False
            FieldName = 'CONT1'
            Title.Alignment = taCenter
            Title.Caption = '.sc'
            Width = 40
            Visible = True
          end
          item
            Color = clWindow
            Expanded = False
            FieldName = 'SC'
            Title.Alignment = taCenter
            Title.Caption = 'An.'
            Width = 40
            Visible = True
          end
          item
            Color = clWindow
            Expanded = False
            FieldName = 'CLCSCT'
            Title.Alignment = taCenter
            Title.Caption = 'Analitica'
            Width = 100
            Visible = True
          end
          item
            Color = clWindow
            Expanded = False
            FieldName = 'DEP'
            Title.Alignment = taCenter
            Title.Caption = 'C/C'
            Width = 40
            Visible = True
          end
          item
            Color = clWindow
            Expanded = False
            FieldName = 'CLCDEPT'
            Title.Alignment = taCenter
            Title.Caption = 'Centru de cost'
            Width = 100
            Visible = True
          end
          item
            Color = clWindow
            Expanded = False
            FieldName = 'SC1'
            Title.Alignment = taCenter
            Title.Caption = 'Sc'
            Width = 40
            Visible = True
          end
          item
            Color = clWindow
            Expanded = False
            FieldName = 'CLCSC1T'
            Title.Alignment = taCenter
            Title.Caption = 'Subconto'
            Width = 100
            Visible = True
          end
          item
            Color = clWindow
            Expanded = False
            FieldName = 'NRDOC'
            Title.Alignment = taCenter
            Title.Caption = 'Nr. doc'
            Width = 50
            Visible = True
          end
          item
            Color = clWindow
            Expanded = False
            FieldName = 'STRSC'
            Title.Alignment = taCenter
            Title.Caption = 'Str. Sc'
            Width = 50
            Visible = True
          end
          item
            Color = clWindow
            Expanded = False
            FieldName = 'SUMA'
            Title.Alignment = taCenter
            Title.Caption = 'Suma, LEI'
            Width = 80
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'CANT'
            Title.Alignment = taCenter
            Title.Caption = 'Cantitatea'
            Width = 80
            Visible = True
          end>
      end
    end
    object tsCheck: TcxTabSheet
      Caption = 'Testuri'
      ImageIndex = 3
      ExplicitWidth = 0
      ExplicitHeight = 0
      object dmCheckText: TcxDBMemo
        Left = 0
        Top = 390
        Align = alBottom
        DataBinding.DataField = 'ERROR_TEXT'
        DataBinding.DataSource = dsCheck
        Properties.ReadOnly = True
        TabOrder = 2
        Height = 121
        Width = 680
      end
      object panCheckTop: TPanel
        Left = 0
        Top = 0
        Width = 680
        Height = 65
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 0
        object cbCheckActiveDS: TcxCheckBox
          Left = 4
          Top = 6
          Caption = 'Arata lista de erori'
          TabOrder = 0
          OnClick = cbCheckActiveDSClick
          Width = 121
        end
        object btCheckRunAll: TcxButton
          Left = 128
          Top = 4
          Width = 121
          Height = 25
          Caption = 'Testare totului'
          TabOrder = 1
        end
        object btCheckRunOne: TcxButton
          Left = 248
          Top = 4
          Width = 121
          Height = 25
          Caption = 'Start test selectat'
          TabOrder = 2
        end
        object btCheckClearAll: TcxButton
          Left = 368
          Top = 4
          Width = 121
          Height = 25
          Caption = 'Elibera lista'
          TabOrder = 3
        end
        object btCheckRefreshList: TcxButton
          Left = 488
          Top = 4
          Width = 121
          Height = 25
          Caption = 'Actualizeaza butoane'
          TabOrder = 4
          OnClick = btCheckRefreshListClick
        end
        object rbCheckLostChars: TcxRadioButton
          Left = 8
          Top = 40
          Width = 121
          Height = 17
          Caption = 'Lost chararacters'
          TabOrder = 5
        end
        object rbCheckCMSPType: TcxRadioButton
          Left = 128
          Top = 40
          Width = 121
          Height = 17
          Caption = 'Invalid pairs in CM'
          TabOrder = 6
        end
        object rbCheckTXSLD: TcxRadioButton
          Left = 248
          Top = 40
          Width = 121
          Height = 17
          Caption = 'Actual balance'
          TabOrder = 7
        end
        object rbCheckSequences: TcxRadioButton
          Left = 368
          Top = 40
          Width = 121
          Height = 17
          Caption = 'Secvente'
          TabOrder = 8
        end
        object rbCheckTunigIssues: TcxRadioButton
          Left = 488
          Top = 40
          Width = 121
          Height = 17
          Caption = 'Tuning issues'
          TabOrder = 9
        end
      end
      object grCheck: TUnDBGrid
        Left = 0
        Top = 65
        Width = 680
        Height = 325
        Align = alClient
        Ctl3D = True
        DataSource = dsCheck
        ParentCtl3D = False
        ReadOnly = True
        TabOrder = 1
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'Tahoma'
        TitleFont.Style = []
        UnRememberDesign = True
        XTitleHeight = 17
        Columns = <
          item
            Color = clWindow
            Expanded = False
            FieldName = 'ID_TIME'
            Title.Caption = 'Time'
            Width = 100
            Visible = True
          end
          item
            Color = clWindow
            Expanded = False
            FieldName = 'OBJECT_NAME'
            Title.Caption = 'Name'
            Width = 160
            Visible = True
          end
          item
            Color = clWindow
            Expanded = False
            FieldName = 'OBJECT_TYPE'
            Title.Caption = 'Type'
            Width = 160
            Visible = True
          end
          item
            Color = clWindow
            Expanded = False
            FieldName = 'ERROR_CODE'
            Title.Caption = 'Error'
            Width = 160
            Visible = True
          end
          item
            Color = clWindow
            Expanded = False
            FieldName = 'ERROR_TEXT'
            Title.Caption = 'Text'
            Width = 100
            Visible = True
          end>
      end
    end
    object tsOptions: TcxTabSheet
      Caption = 'Optiuni'
      ImageIndex = 4
      ExplicitWidth = 0
      ExplicitHeight = 0
      object cbxSqlMonitor: TCheckBox
        Left = 8
        Top = 8
        Width = 129
        Height = 17
        Caption = 'SQL monitor activ'
        TabOrder = 0
        OnClick = cbxSqlMonitorClick
      end
    end
  end
  object dsObjects: TDataSource
    DataSet = sqObjects
    Left = 68
    Top = 350
  end
  object dsTVQ: TDataSource
    Left = 68
    Top = 454
  end
  object sqq: TSagiODACSmartQuery
    Session = dmCassa.db
    NonBlocking = True
    AfterExecute = sqqAfterExecute
    AfterOpen = sqqAfterOpen
    Left = 20
    Top = 454
  end
  object sqObjects: TSagiODACSmartQuery
    Session = dmCassa.db
    SQL.Strings = (
      
        'SELECT OBJECT_NAME NAME FROM USER_OBJECTS WHERE OBJECT_TYPE = UP' +
        'PER(:ObjType)')
    AfterScroll = sqObjectsAfterScroll
    Left = 20
    Top = 350
    ParamData = <
      item
        DataType = ftString
        Name = 'ObjType'
        ParamType = ptInput
        Size = 32
        Value = 'VIEW'
      end>
    object sqObjectsNAME: TStringField
      FieldName = 'NAME'
      Required = True
      Size = 30
    end
  end
  object sqCustom: TSagiODACSmartQuery
    Session = dmCassa.db
    Left = 20
    Top = 398
  end
  object dsCustom: TDataSource
    DataSet = sqCustom
    Left = 68
    Top = 398
  end
  object LS: TUnLangSelector
    UnLanguage = lnRom
    UnSections = <>
    Left = 68
    Top = 294
    CompList = (
      'fTOAD'
      'tsTables'
      'grObjects'
      'panTop'
      'rgObject'
      'grCustom'
      'tsQueries'
      'tsSold'
      'gbSoldOptions'
      'cbSoldMethodOLD'
      'cbSoldNoActual'
      'lbSoldDate'
      'cbSoldShowZero'
      'cbSoldSmart'
      'cbSoldAP'
      'cbSoldCont'
      'cbSoldCont1'
      'cbSoldSC'
      'cbSoldDep'
      'cbSoldSC1'
      'cbSoldNrDoc'
      'cbSoldStrSC'
      'cbSoldNrCM'
      'cbSoldData'
      'cbSoldCant'
      'cbSoldPret'
      'cbSoldSumaVal'
      'cbSoldSumaGaap'
      'cbSoldCant1'
      'btMakeSold'
      'btSoldTestTXSLD'
      'btSoldRebuildTXSLD'
      'btSoldRebuildTSLD'
      'btSoldClearZTEMP'
      'lbSoldID'
      'lbSoldFilter'
      'tsCheck'
      'cbCheckActiveDS'
      'tsOptions'
      'cbxSqlMonitor'
      'btCheckRefreshList'
      'btCheckRunAll'
      'btCheckRunOne'
      'btCheckClearAll'
      'rbCheckLostChars'
      'rbCheckCMSPType'
      'rbCheckTXSLD'
      'rbCheckSequences'
      'rbCheckTunigIssues')
    CompStrEng = (
      '[fTOAD]'
      'Caption=SQL (table and query) Explorer'
      '[TabSheet1]'
      'Caption=Tables'
      '[rgObject]'
      'Caption=Select object:'
      '.Items=2'
      '[cbxSqlMonitor]'
      'Caption=SQL monitor active'
      '[rgObject.Items]'
      'Item0=Tables'
      'Item1=Views'
      '[tsTables]'
      'Caption=Tables'
      '[tsQueries]'
      'Caption=Query'
      '[tsOptions]'
      'Caption=Options'
      '[tsSold]'
      'Caption=Balance'
      '[gbSoldOptions]'
      'Caption=Parameters'
      '[cbSoldMethodOLD]'
      'Caption=Old method'
      '[cbSoldNoActual]'
      'Caption=No quick balance'
      '[lbSoldDate]'
      'Caption=Date:'
      '[cbSoldShowZero]'
      'Caption=Include zero'
      '[cbSoldSmart]'
      'Caption=Smart'
      '[cbSoldAP]'
      'Caption=A/P'
      '[cbSoldCont]'
      'Caption=Acct'
      '[cbSoldCont1]'
      'Caption=.sc'
      '[cbSoldSC]'
      'Caption=Analitics'
      '[cbSoldDep]'
      'Caption=Centru de cost'
      '[cbSoldSC1]'
      'Caption=Subconto'
      '[cbSoldNrDoc]'
      'Caption=NrDoc'
      '[cbSoldStrSC]'
      'Caption=StrSC'
      '[cbSoldNrCM]'
      'Caption=NrCM'
      '[cbSoldData]'
      'Caption=Date'
      '[cbSoldCant]'
      'Caption=Qty'
      '[cbSoldPret]'
      'Caption=Price'
      '[cbSoldSumaVal]'
      'Caption=Sum in Cur.'
      '[cbSoldSumaGaap]'
      'Caption=Sum gaap'
      '[cbSoldCant1]'
      'Caption=Add. quantity'
      '[btMakeSold]'
      'Caption=Calculate now!'
      '[btSoldTestTXSLD]'
      'Caption=Test TXSLD'
      '[btSoldRebuildTXSLD]'
      'Caption=Rebuild TXSLD'
      '[btSoldRebuildTSLD]'
      'Caption=Rebuild TSLD'
      '[btSoldClearZTEMP]'
      'Caption=Clear ZTEMP'
      '[cbCheckActiveDS]'
      'Caption=Open error table'
      '[btCheckRunAll]'
      'Caption=Run all tests'
      '[btCheckClearAll]'
      'Caption=Clear error table'
      '[btCheckRunOne]'
      'Caption=Run selected test'
      '[rbCheckLostChars]'
      'Caption=Lost chararacters'
      '[rbCheckCMSPType]'
      'Caption=Invalid pairs in CM'
      '[rbCheckTXSLD]'
      'Caption=Actual balance'
      '[rbCheckTunigIssues]'
      'Caption=Tuning issues'
      '[tsCheck]'
      'Caption=Check'
      '[rbCheckSequences]'
      'Caption=Sequences'
      '[btCheckRefreshList]'
      'Caption=Refresh buttons')
    CompStrRom = (
      '[fTOAD]'
      'Caption=Vizionare registrelor si tabelelor'
      '[TabSheet1]'
      'Caption=Tabele'
      '[rgObject]'
      'Caption=Selectati objectul:'
      '.Items=2'
      '[cbxSqlMonitor]'
      'Caption=SQL monitor activ'
      '[rgObject.Items]'
      'Item0=Tabele'
      'Item1=Vision.'
      '[tsTables]'
      'Caption=Tabele'
      '[tsQueries]'
      'Caption=Query'
      '[tsOptions]'
      'Caption=Optiuni'
      '[tsSold]'
      'Caption=Sold'
      '[gbSoldOptions]'
      'Caption=Parametres'
      '[cbSoldMethodOLD]'
      'Caption=Metoda veche'
      '[cbSoldNoActual]'
      'Caption=Nu sold actual'
      '[lbSoldDate]'
      'Caption=Data:'
      '[cbSoldShowZero]'
      'Caption=Include zero'
      '[cbSoldSmart]'
      'Caption=Smart'
      '[cbSoldAP]'
      'Caption=A/P'
      '[cbSoldCont]'
      'Caption=Cont'
      '[cbSoldCont1]'
      'Caption=.sc'
      '[cbSoldSC]'
      'Caption=Analitica'
      '[cbSoldDep]'
      'Caption=Centru de cost'
      '[cbSoldSC1]'
      'Caption=Subconto'
      '[cbSoldNrDoc]'
      'Caption=NrDoc'
      '[cbSoldStrSC]'
      'Caption=StrSC'
      '[cbSoldNrCM]'
      'Caption=NrCM'
      '[cbSoldData]'
      'Caption=Data'
      '[cbSoldCant]'
      'Caption=Cant'
      '[cbSoldPret]'
      'Caption=Pret'
      '[cbSoldSumaVal]'
      'Caption=Suma val.'
      '[cbSoldSumaGaap]'
      'Caption=Suma gaap'
      '[cbSoldCant1]'
      'Caption=Cant adaug.'
      '[btMakeSold]'
      'Caption=Calculare!'
      '[btSoldTestTXSLD]'
      'Caption=Test TXSLD'
      '[btSoldRebuildTXSLD]'
      'Caption=Rebuild TXSLD'
      '[btSoldRebuildTSLD]'
      'Caption=Rebuild TSLD'
      '[btSoldClearZTEMP]'
      'Caption=Clear ZTEMP'
      '[cbCheckActiveDS]'
      'Caption=Arata lista de erori'
      '[btCheckRunAll]'
      'Caption=Testare totului'
      '[btCheckClearAll]'
      'Caption=Elibera lista'
      '[btCheckRunOne]'
      'Caption=Start test selectat'
      '[rbCheckTunigIssues]'
      'Caption=Tuning issues'
      '[rbCheckTXSLD]'
      'Caption=Actual balance'
      '[rbCheckCMSPType]'
      'Caption=Invalid pairs in CM'
      '[rbCheckLostChars]'
      'Caption=Lost chararacters'
      '[tsCheck]'
      'Caption=Testuri'
      '[rbCheckSequences]'
      'Caption=Secvente'
      '[btCheckRefreshList]'
      'Caption=Actualizeaza butoane')
    CompStrRus = (
      '[fTOAD]'
      'Caption='#1055#1088#1086#1089#1084#1086#1090#1088' '#1090#1072#1073#1083#1080#1094' '#1080' '#1079#1072#1087#1088#1086#1089#1086#1074
      '[TabSheet1]'
      'Caption='#1058#1072#1073#1083#1080#1094#1099
      '[rgObject]'
      'Caption='#1042#1099#1073#1077#1088#1080#1090#1077' '#1086#1073#1098#1077#1082#1090':'
      '.Items=2'
      '[cbxSqlMonitor]'
      'Caption=SQL monitor '#1072#1082#1090#1080#1074#1077#1085
      '[rgObject.Items]'
      'Item0='#1058#1072#1073#1083'.'
      'Item1='#1055#1088#1077#1076#1089'.'
      '[tsTables]'
      'Caption='#1058#1072#1073#1083#1080#1094#1099
      '[tsQueries]'
      'Caption='#1047#1072#1087#1088#1086#1089#1099
      '[tsOptions]'
      'Caption='#1054#1087#1094#1080#1080
      '[tsSold]'
      'Caption='#1057#1072#1083#1100#1076#1086
      '[gbSoldOptions]'
      'Caption='#1055#1072#1088#1072#1084#1077#1090#1088#1099
      '[cbSoldMethodOLD]'
      'Caption='#1057#1090#1072#1088#1099#1081' '#1084#1077#1090#1086#1076
      '[cbSoldNoActual]'
      'Caption='#1041#1077#1079' '#1072#1082#1090'. '#1089#1072#1083#1100#1076#1086
      '[lbSoldDate]'
      'Caption='#1044#1072#1090#1072':'
      '[cbSoldShowZero]'
      'Caption='#1042#1082#1083#1102#1095#1072#1103' '#1085#1091#1083#1080
      '[cbSoldSmart]'
      'Caption='#1059#1084#1085#1086#1077
      '[cbSoldAP]'
      'Caption='#1040'/'#1055
      '[cbSoldCont]'
      'Caption='#1057#1095#1077#1090
      '[cbSoldCont1]'
      'Caption=.'#1089#1082
      '[cbSoldSC]'
      'Caption='#1040#1085#1072#1083#1080#1090#1080#1082#1072
      '[cbSoldDep]'
      'Caption='#1062#1077#1085#1090#1088' '#1079#1072#1090#1088#1072#1090
      '[cbSoldSC1]'
      'Caption='#1057#1091#1073#1082#1086#1085#1090#1086
      '[cbSoldNrDoc]'
      'Caption=NrDoc'
      '[cbSoldStrSC]'
      'Caption=StrSC'
      '[cbSoldNrCM]'
      'Caption=NrCM'
      '[cbSoldData]'
      'Caption='#1044#1072#1090#1072
      '[cbSoldCant]'
      'Caption='#1050'-'#1074#1086
      '[cbSoldPret]'
      'Caption='#1062#1077#1085#1072
      '[cbSoldSumaVal]'
      'Caption='#1057#1091#1084#1084#1072' '#1074' '#1074#1072#1083'.'
      '[cbSoldSumaGaap]'
      'Caption='#1044#1086#1087'. '#1089#1091#1084#1084#1072
      '[cbSoldCant1]'
      'Caption='#1044#1086#1087'. '#1082'-'#1074#1086
      '[btMakeSold]'
      'Caption='#1056#1072#1089#1089#1095#1080#1090#1072#1090#1100'!'
      '[btSoldTestTXSLD]'
      'Caption='#1058#1077#1089#1090' TXSLD'
      '[btSoldRebuildTXSLD]'
      'Caption='#1056#1072#1089#1095#1077#1090' TXSLD'
      '[btSoldRebuildTSLD]'
      'Caption='#1056#1072#1089#1095#1077#1090' TSLD'
      '[btSoldClearZTEMP]'
      'Caption='#1063#1080#1089#1090#1080#1090#1100' ZTEMP'
      '[cbCheckActiveDS]'
      'Caption='#1054#1090#1082#1088#1099#1090#1100' '#1089#1087#1080#1089#1086#1082
      '[btCheckRunAll]'
      'Caption='#1055#1088#1086#1074#1077#1088#1080#1090#1100' '#1074#1089#1077
      '[btCheckClearAll]'
      'Caption='#1054#1095#1080#1089#1090#1080#1090#1100' '#1089#1087#1080#1089#1086#1082
      '[btCheckRunOne]'
      'Caption='#1042#1099#1073#1088#1072#1085#1085#1099#1081' '#1090#1077#1089#1090
      '[rbCheckLostChars]'
      'Caption='#1055#1086#1090#1077#1088#1103#1085#1085#1099#1077' '#1073#1091#1082#1074#1099
      '[rbCheckCMSPType]'
      'Caption='#1041#1080#1090#1099#1077' '#1087#1072#1088#1099' '#1074' CM'
      '[rbCheckTXSLD]'
      'Caption='#1041#1099#1089#1090#1088#1086#1077' '#1089#1072#1083#1100#1076#1086
      '[rbCheckTunigIssues]'
      'Caption='#1053#1072#1089#1090#1088#1086#1081#1082#1072
      '[tsCheck]'
      'Caption='#1058#1077#1089#1090#1099
      '[rbCheckSequences]'
      'Caption='#1057#1095#1077#1090#1095#1080#1082#1080
      '[btCheckRefreshList]'
      'Caption='#1054#1073#1085#1086#1074#1080#1090#1100' '#1082#1085#1086#1087#1082#1080)
  end
  object sqSold: TSmartQuery
    Session = dmCassa.db
    SQL.Strings = (
      'select a.*'
      ',(select denumirea from vms_univers where cod=a.sc)clcsct'
      ',(select denumirea from vms_univers where cod=a.dep)clcdept'
      ',(select denumirea from vms_univers where cod=a.sc1)clcsc1t'
      'from xsld a'
      'where id is null')
    AutoCommit = False
    Left = 120
    Top = 456
  end
  object dsSold: TDataSource
    DataSet = sqSold
    Left = 164
    Top = 456
  end
  object sqCheck: TSmartQuery
    Session = dmCassa.db
    SQL.Strings = (
      'select * from xschemastate'
      'order by 1,2,3,4')
    AutoCommit = False
    Left = 208
    Top = 456
  end
  object dsCheck: TDataSource
    DataSet = sqCheck
    Left = 252
    Top = 456
  end
end
