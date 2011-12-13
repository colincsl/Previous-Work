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
    ;% Auto data (Puncture_Through_Wall_P)
    ;%
      section.nData     = 45;
      section.data(45)  = dumData; %prealloc
      
	  ;% Puncture_Through_Wall_P.HILInitialize_OOStart
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_OOEnter
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_OOTerminate
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_OOExit
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_AIHigh
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_AILow
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_AOWatchdog
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_POInitial
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_POFinal
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_POWatchdog
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_OOWatchdog
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Puncture_Through_Wall_P.Bias1_Bias
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Puncture_Through_Wall_P.Encoder_Gain
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 14;
	
	  ;% Puncture_Through_Wall_P.GearRatio_Gain
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 15;
	
	  ;% Puncture_Through_Wall_P.ConverttoPositiveRotationConven
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 18;
	
	  ;% Puncture_Through_Wall_P.JointOffsets_Bias
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 21;
	
	  ;% Puncture_Through_Wall_P.ToolOffset2_Value
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 24;
	
	  ;% Puncture_Through_Wall_P.UnitDelay1_X0
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 40;
	
	  ;% Puncture_Through_Wall_P.Stiffness_Value
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 43;
	
	  ;% Puncture_Through_Wall_P.BreakForce_Value
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 44;
	
	  ;% Puncture_Through_Wall_P.UnitDelay3_X0
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 45;
	
	  ;% Puncture_Through_Wall_P.UnitDelay2_X0
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 46;
	
	  ;% Puncture_Through_Wall_P.Constant_Value
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 47;
	
	  ;% Puncture_Through_Wall_P.ConverttoPositiveRotationConv_p
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 50;
	
	  ;% Puncture_Through_Wall_P.GearRatio1_Gain
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 53;
	
	  ;% Puncture_Through_Wall_P.Kt_Gain
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 56;
	
	  ;% Puncture_Through_Wall_P.Saturation_UpperSat
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 57;
	
	  ;% Puncture_Through_Wall_P.Saturation_LowerSat
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 58;
	
	  ;% Puncture_Through_Wall_P.Constant1_Value
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 59;
	
	  ;% Puncture_Through_Wall_P.SliderGain_Gain
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 60;
	
	  ;% Puncture_Through_Wall_P.Constant4_Value
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 61;
	
	  ;% Puncture_Through_Wall_P.Switch_Threshold
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 64;
	
	  ;% Puncture_Through_Wall_P.Constant1_Value_e
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 65;
	
	  ;% Puncture_Through_Wall_P.Constant3_Value
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 68;
	
	  ;% Puncture_Through_Wall_P.Switch1_Threshold
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 69;
	
	  ;% Puncture_Through_Wall_P.Gain_Gain
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 70;
	
	  ;% Puncture_Through_Wall_P.Constant3_Value_p
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 73;
	
	  ;% Puncture_Through_Wall_P.Constant3_Value_c
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 76;
	
	  ;% Puncture_Through_Wall_P.SliderGain_Gain_i
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 77;
	
	  ;% Puncture_Through_Wall_P.Constant5_Value
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 78;
	
	  ;% Puncture_Through_Wall_P.Constant1_Value_j
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 80;
	
	  ;% Puncture_Through_Wall_P.SliderGain_Gain_e
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 81;
	
	  ;% Puncture_Through_Wall_P.Constant2_Value
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 82;
	
	  ;% Puncture_Through_Wall_P.Constant4_Value_i
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 84;
	
	  ;% Puncture_Through_Wall_P.Constant2_Value_m
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 85;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Puncture_Through_Wall_P.HILInitialize_DOWatchdog
	  section.data(1).logicalSrcIdx = 45;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_EIInitial
	  section.data(2).logicalSrcIdx = 46;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Puncture_Through_Wall_P.HILReadEncoderTimebase_Clock
	  section.data(3).logicalSrcIdx = 47;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Puncture_Through_Wall_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_EIChannels
	  section.data(2).logicalSrcIdx = 49;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_POChannels
	  section.data(3).logicalSrcIdx = 50;
	  section.data(3).dtTransOffset = 5;
	
	  ;% Puncture_Through_Wall_P.HILReadEncoderTimebase_Channels
	  section.data(4).logicalSrcIdx = 51;
	  section.data(4).dtTransOffset = 8;
	
	  ;% Puncture_Through_Wall_P.HILReadEncoderTimebase_SamplesI
	  section.data(5).logicalSrcIdx = 52;
	  section.data(5).dtTransOffset = 11;
	
	  ;% Puncture_Through_Wall_P.HILWritePWM_Channels
	  section.data(6).logicalSrcIdx = 53;
	  section.data(6).dtTransOffset = 12;
	
	  ;% Puncture_Through_Wall_P.HILReadAnalog_Channels
	  section.data(7).logicalSrcIdx = 54;
	  section.data(7).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 32;
      section.data(32)  = dumData; %prealloc
      
	  ;% Puncture_Through_Wall_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 55;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_CKPStart
	  section.data(2).logicalSrcIdx = 56;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_CKPEnter
	  section.data(3).logicalSrcIdx = 57;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_AIPStart
	  section.data(4).logicalSrcIdx = 58;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_AIPEnter
	  section.data(5).logicalSrcIdx = 59;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_AOPStart
	  section.data(6).logicalSrcIdx = 60;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_AOPEnter
	  section.data(7).logicalSrcIdx = 61;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_AOStart
	  section.data(8).logicalSrcIdx = 62;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_AOEnter
	  section.data(9).logicalSrcIdx = 63;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_AOTerminate
	  section.data(10).logicalSrcIdx = 64;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_AOExit
	  section.data(11).logicalSrcIdx = 65;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_AOReset
	  section.data(12).logicalSrcIdx = 66;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_DOStart
	  section.data(13).logicalSrcIdx = 67;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_DOEnter
	  section.data(14).logicalSrcIdx = 68;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_DOTerminate
	  section.data(15).logicalSrcIdx = 69;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_DOExit
	  section.data(16).logicalSrcIdx = 70;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_DOReset
	  section.data(17).logicalSrcIdx = 71;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_EIPStart
	  section.data(18).logicalSrcIdx = 72;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_EIPEnter
	  section.data(19).logicalSrcIdx = 73;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_EIStart
	  section.data(20).logicalSrcIdx = 74;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_EIEnter
	  section.data(21).logicalSrcIdx = 75;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_POPStart
	  section.data(22).logicalSrcIdx = 76;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_POPEnter
	  section.data(23).logicalSrcIdx = 77;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_POStart
	  section.data(24).logicalSrcIdx = 78;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_POEnter
	  section.data(25).logicalSrcIdx = 79;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_POTerminate
	  section.data(26).logicalSrcIdx = 80;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_POExit
	  section.data(27).logicalSrcIdx = 81;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_POReset
	  section.data(28).logicalSrcIdx = 82;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Puncture_Through_Wall_P.HILInitialize_OOReset
	  section.data(29).logicalSrcIdx = 83;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Puncture_Through_Wall_P.HILReadEncoderTimebase_Active
	  section.data(30).logicalSrcIdx = 84;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Puncture_Through_Wall_P.HILWritePWM_Active
	  section.data(31).logicalSrcIdx = 85;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Puncture_Through_Wall_P.HILReadAnalog_Active
	  section.data(32).logicalSrcIdx = 86;
	  section.data(32).dtTransOffset = 31;
	
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
    ;% Auto data (Puncture_Through_Wall_B)
    ;%
      section.nData     = 25;
      section.data(25)  = dumData; %prealloc
      
	  ;% Puncture_Through_Wall_B.GearRatio
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Puncture_Through_Wall_B.JointOffsets
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Puncture_Through_Wall_B.ToolOffset2
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Puncture_Through_Wall_B.UnitDelay1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 22;
	
	  ;% Puncture_Through_Wall_B.Stiffness
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 25;
	
	  ;% Puncture_Through_Wall_B.BreakForce
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 26;
	
	  ;% Puncture_Through_Wall_B.UnitDelay3
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 27;
	
	  ;% Puncture_Through_Wall_B.UnitDelay2
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 28;
	
	  ;% Puncture_Through_Wall_B.ConverttoPositiveRotationConven
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 29;
	
	  ;% Puncture_Through_Wall_B.Saturation
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 32;
	
	  ;% Puncture_Through_Wall_B.SliderGain
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 35;
	
	  ;% Puncture_Through_Wall_B.RateTransition1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 36;
	
	  ;% Puncture_Through_Wall_B.Switch1
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 39;
	
	  ;% Puncture_Through_Wall_B.RateTransition
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 40;
	
	  ;% Puncture_Through_Wall_B.Gain
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 43;
	
	  ;% Puncture_Through_Wall_B.Constant3
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 46;
	
	  ;% Puncture_Through_Wall_B.y
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 49;
	
	  ;% Puncture_Through_Wall_B.y_i
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 52;
	
	  ;% Puncture_Through_Wall_B.pos
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 55;
	
	  ;% Puncture_Through_Wall_B.Rot
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 58;
	
	  ;% Puncture_Through_Wall_B.Jac
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 67;
	
	  ;% Puncture_Through_Wall_B.q
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 85;
	
	  ;% Puncture_Through_Wall_B.Force
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 88;
	
	  ;% Puncture_Through_Wall_B.dir
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 91;
	
	  ;% Puncture_Through_Wall_B.flag
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 92;
	
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
    nTotSects     = 8;
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
    ;% Auto data (Puncture_Through_Wall_DWork)
    ;%
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% Puncture_Through_Wall_DWork.UnitDelay1_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Puncture_Through_Wall_DWork.UnitDelay3_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Puncture_Through_Wall_DWork.UnitDelay2_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% Puncture_Through_Wall_DWork.HILInitialize_AIMinimums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% Puncture_Through_Wall_DWork.HILInitialize_AIMaximums
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 7;
	
	  ;% Puncture_Through_Wall_DWork.HILInitialize_FilterFrequency
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 9;
	
	  ;% Puncture_Through_Wall_DWork.HILInitialize_POSortedFreqs
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 12;
	
	  ;% Puncture_Through_Wall_DWork.HILInitialize_POValues
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Puncture_Through_Wall_DWork.HILWritePWM_PWORK
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Puncture_Through_Wall_DWork.HILReadAnalog_PWORK
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Puncture_Through_Wall_DWork.VRSink_PWORK
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Puncture_Through_Wall_DWork.HILInitialize_QuadratureModes
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Puncture_Through_Wall_DWork.HILInitialize_InitialEICounts
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Puncture_Through_Wall_DWork.HILInitialize_POModeValues
	  section.data(3).logicalSrcIdx = 13;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Puncture_Through_Wall_DWork.HILReadEncoderTimebase_Buffer
	  section.data(4).logicalSrcIdx = 14;
	  section.data(4).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Puncture_Through_Wall_DWork.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Puncture_Through_Wall_DWork.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Puncture_Through_Wall_DWork.HILReadEncoderTimebase_Task
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Puncture_Through_Wall_DWork.is_active_c3_Puncture_Through_W
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Puncture_Through_Wall_DWork.is_active_c4_Puncture_Through_W
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Puncture_Through_Wall_DWork.is_active_c5_Puncture_Through_W
	  section.data(3).logicalSrcIdx = 20;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Puncture_Through_Wall_DWork.is_active_c8_Puncture_Through_W
	  section.data(4).logicalSrcIdx = 21;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Puncture_Through_Wall_DWork.is_active_c2_Puncture_Through_W
	  section.data(5).logicalSrcIdx = 22;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Puncture_Through_Wall_DWork.doneDoubleBufferReInit
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Puncture_Through_Wall_DWork.doneDoubleBufferReInit_c
	  section.data(2).logicalSrcIdx = 24;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Puncture_Through_Wall_DWork.doneDoubleBufferReInit_a
	  section.data(3).logicalSrcIdx = 25;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Puncture_Through_Wall_DWork.doneDoubleBufferReInit_n
	  section.data(4).logicalSrcIdx = 26;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Puncture_Through_Wall_DWork.doneDoubleBufferReInit_i
	  section.data(5).logicalSrcIdx = 27;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
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


  targMap.checksum0 = 229532757;
  targMap.checksum1 = 4184693949;
  targMap.checksum2 = 841558308;
  targMap.checksum3 = 3478176748;

