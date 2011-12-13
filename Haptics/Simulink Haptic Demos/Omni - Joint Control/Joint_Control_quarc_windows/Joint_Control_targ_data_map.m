  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Joint_Control_P)
    ;%
      section.nData     = 43;
      section.data(43)  = dumData; %prealloc
      
	  ;% Joint_Control_P.HILInitialize_OOStart
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Joint_Control_P.HILInitialize_OOEnter
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Joint_Control_P.HILInitialize_OOTerminate
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Joint_Control_P.HILInitialize_OOExit
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Joint_Control_P.HILInitialize_AIHigh
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Joint_Control_P.HILInitialize_AILow
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Joint_Control_P.HILInitialize_AOWatchdog
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Joint_Control_P.HILInitialize_POInitial
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Joint_Control_P.HILInitialize_POFinal
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Joint_Control_P.HILInitialize_POWatchdog
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Joint_Control_P.HILInitialize_OOWatchdog
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Joint_Control_P.Kpq1_Value
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Joint_Control_P.SliderGain_Gain
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Joint_Control_P.Kpq2_Value
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Joint_Control_P.SliderGain_Gain_f
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Joint_Control_P.Kpq3_Value
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Joint_Control_P.SliderGain_Gain_ff
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Joint_Control_P.Saturation_UpperSat
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Joint_Control_P.Saturation_LowerSat
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 20;
	
	  ;% Joint_Control_P.SignalGenerator_Amplitude
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 23;
	
	  ;% Joint_Control_P.SignalGenerator_Frequency
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 26;
	
	  ;% Joint_Control_P.Bias1_Bias
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 27;
	
	  ;% Joint_Control_P.Encoder_Gain
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 30;
	
	  ;% Joint_Control_P.GearRatio_Gain
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 31;
	
	  ;% Joint_Control_P.ConverttoPositiveRotationConven
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 34;
	
	  ;% Joint_Control_P.JointOffsets_Bias
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 37;
	
	  ;% Joint_Control_P.Wn_Value
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 40;
	
	  ;% Joint_Control_P.Integrator_IC
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 41;
	
	  ;% Joint_Control_P.Kvq1_Value
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 42;
	
	  ;% Joint_Control_P.SliderGain_Gain_g
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 43;
	
	  ;% Joint_Control_P.Kvq2_Value
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 44;
	
	  ;% Joint_Control_P.SliderGain_Gain_i
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 45;
	
	  ;% Joint_Control_P.Kvq3_Value
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 46;
	
	  ;% Joint_Control_P.SliderGain_Gain_h
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 47;
	
	  ;% Joint_Control_P.Saturation1_UpperSat
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 48;
	
	  ;% Joint_Control_P.Saturation1_LowerSat
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 51;
	
	  ;% Joint_Control_P.ConverttoPositiveRotationConv_k
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 54;
	
	  ;% Joint_Control_P.GearRatio1_Gain
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 57;
	
	  ;% Joint_Control_P.Kt_Gain
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 60;
	
	  ;% Joint_Control_P.Saturation_UpperSat_a
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 61;
	
	  ;% Joint_Control_P.Saturation_LowerSat_l
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 62;
	
	  ;% Joint_Control_P.Constant_Value
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 63;
	
	  ;% Joint_Control_P.z_Value
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 64;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Joint_Control_P.HILInitialize_DOWatchdog
	  section.data(1).logicalSrcIdx = 43;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Joint_Control_P.HILInitialize_EIInitial
	  section.data(2).logicalSrcIdx = 44;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Joint_Control_P.HILReadEncoderTimebase_Clock
	  section.data(3).logicalSrcIdx = 45;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Joint_Control_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 46;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Joint_Control_P.HILInitialize_EIChannels
	  section.data(2).logicalSrcIdx = 47;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Joint_Control_P.HILInitialize_POChannels
	  section.data(3).logicalSrcIdx = 48;
	  section.data(3).dtTransOffset = 5;
	
	  ;% Joint_Control_P.HILReadEncoderTimebase_Channels
	  section.data(4).logicalSrcIdx = 49;
	  section.data(4).dtTransOffset = 8;
	
	  ;% Joint_Control_P.HILReadEncoderTimebase_SamplesI
	  section.data(5).logicalSrcIdx = 50;
	  section.data(5).dtTransOffset = 11;
	
	  ;% Joint_Control_P.HILWritePWM_Channels
	  section.data(6).logicalSrcIdx = 51;
	  section.data(6).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 31;
      section.data(31)  = dumData; %prealloc
      
	  ;% Joint_Control_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Joint_Control_P.HILInitialize_CKPStart
	  section.data(2).logicalSrcIdx = 53;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Joint_Control_P.HILInitialize_CKPEnter
	  section.data(3).logicalSrcIdx = 54;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Joint_Control_P.HILInitialize_AIPStart
	  section.data(4).logicalSrcIdx = 55;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Joint_Control_P.HILInitialize_AIPEnter
	  section.data(5).logicalSrcIdx = 56;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Joint_Control_P.HILInitialize_AOPStart
	  section.data(6).logicalSrcIdx = 57;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Joint_Control_P.HILInitialize_AOPEnter
	  section.data(7).logicalSrcIdx = 58;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Joint_Control_P.HILInitialize_AOStart
	  section.data(8).logicalSrcIdx = 59;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Joint_Control_P.HILInitialize_AOEnter
	  section.data(9).logicalSrcIdx = 60;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Joint_Control_P.HILInitialize_AOTerminate
	  section.data(10).logicalSrcIdx = 61;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Joint_Control_P.HILInitialize_AOExit
	  section.data(11).logicalSrcIdx = 62;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Joint_Control_P.HILInitialize_AOReset
	  section.data(12).logicalSrcIdx = 63;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Joint_Control_P.HILInitialize_DOStart
	  section.data(13).logicalSrcIdx = 64;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Joint_Control_P.HILInitialize_DOEnter
	  section.data(14).logicalSrcIdx = 65;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Joint_Control_P.HILInitialize_DOTerminate
	  section.data(15).logicalSrcIdx = 66;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Joint_Control_P.HILInitialize_DOExit
	  section.data(16).logicalSrcIdx = 67;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Joint_Control_P.HILInitialize_DOReset
	  section.data(17).logicalSrcIdx = 68;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Joint_Control_P.HILInitialize_EIPStart
	  section.data(18).logicalSrcIdx = 69;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Joint_Control_P.HILInitialize_EIPEnter
	  section.data(19).logicalSrcIdx = 70;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Joint_Control_P.HILInitialize_EIStart
	  section.data(20).logicalSrcIdx = 71;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Joint_Control_P.HILInitialize_EIEnter
	  section.data(21).logicalSrcIdx = 72;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Joint_Control_P.HILInitialize_POPStart
	  section.data(22).logicalSrcIdx = 73;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Joint_Control_P.HILInitialize_POPEnter
	  section.data(23).logicalSrcIdx = 74;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Joint_Control_P.HILInitialize_POStart
	  section.data(24).logicalSrcIdx = 75;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Joint_Control_P.HILInitialize_POEnter
	  section.data(25).logicalSrcIdx = 76;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Joint_Control_P.HILInitialize_POTerminate
	  section.data(26).logicalSrcIdx = 77;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Joint_Control_P.HILInitialize_POExit
	  section.data(27).logicalSrcIdx = 78;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Joint_Control_P.HILInitialize_POReset
	  section.data(28).logicalSrcIdx = 79;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Joint_Control_P.HILInitialize_OOReset
	  section.data(29).logicalSrcIdx = 80;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Joint_Control_P.HILReadEncoderTimebase_Active
	  section.data(30).logicalSrcIdx = 81;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Joint_Control_P.HILWritePWM_Active
	  section.data(31).logicalSrcIdx = 82;
	  section.data(31).dtTransOffset = 30;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Joint_Control_B)
    ;%
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% Joint_Control_B.Saturation
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Joint_Control_B.GearRatio
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Joint_Control_B.JointOffsets
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Joint_Control_B.TmpHiddenBufferAtSFunctionInpor
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 9;
	
	  ;% Joint_Control_B.SFunction
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 15;
	
	  ;% Joint_Control_B.Sum
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 21;
	
	  ;% Joint_Control_B.Product1
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 24;
	
	  ;% Joint_Control_B.Saturation1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 27;
	
	  ;% Joint_Control_B.ConverttoPositiveRotationConven
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 30;
	
	  ;% Joint_Control_B.Saturation_n
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 33;
	
	  ;% Joint_Control_B.Product
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 36;
	
	  ;% Joint_Control_B.y
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 39;
	
	  ;% Joint_Control_B.y_f
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 42;
	
	  ;% Joint_Control_B.q
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 45;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 9;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Joint_Control_DWork)
    ;%
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Joint_Control_DWork.SFunction_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Joint_Control_DWork.HILInitialize_AIMinimums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Joint_Control_DWork.HILInitialize_AIMaximums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Joint_Control_DWork.HILInitialize_FilterFrequency
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% Joint_Control_DWork.HILInitialize_POSortedFreqs
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% Joint_Control_DWork.HILInitialize_POValues
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Joint_Control_DWork.HILWritePWM_PWORK
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Joint_Control_DWork.Response_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Joint_Control_DWork.HILInitialize_QuadratureModes
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Joint_Control_DWork.HILInitialize_InitialEICounts
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Joint_Control_DWork.HILInitialize_POModeValues
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Joint_Control_DWork.HILReadEncoderTimebase_Buffer
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Joint_Control_DWork.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Joint_Control_DWork.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Joint_Control_DWork.HILReadEncoderTimebase_Task
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Joint_Control_DWork.Integrator1_IWORK.IcNeedsLoading
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Joint_Control_DWork.is_active_c3_Joint_Control
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Joint_Control_DWork.is_active_c4_Joint_Control
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Joint_Control_DWork.is_active_c8_Joint_Control
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Joint_Control_DWork.doneDoubleBufferReInit
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Joint_Control_DWork.doneDoubleBufferReInit_j
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Joint_Control_DWork.doneDoubleBufferReInit_b
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 3785709360;
  targMap.checksum1 = 3261669109;
  targMap.checksum2 = 1122963643;
  targMap.checksum3 = 3821694672;

