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
    ;% Auto data (Gravity_Well_P)
    ;%
      section.nData     = 45;
      section.data(45)  = dumData; %prealloc
      
	  ;% Gravity_Well_P.HILInitialize_OOStart
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Gravity_Well_P.HILInitialize_OOEnter
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Gravity_Well_P.HILInitialize_OOTerminate
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Gravity_Well_P.HILInitialize_OOExit
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Gravity_Well_P.HILInitialize_AIHigh
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Gravity_Well_P.HILInitialize_AILow
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Gravity_Well_P.HILInitialize_AOWatchdog
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Gravity_Well_P.HILInitialize_POInitial
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Gravity_Well_P.HILInitialize_POFinal
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Gravity_Well_P.HILInitialize_POWatchdog
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Gravity_Well_P.HILInitialize_OOWatchdog
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Gravity_Well_P.Bias1_Bias
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Gravity_Well_P.Encoder_Gain
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 14;
	
	  ;% Gravity_Well_P.GearRatio_Gain
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 15;
	
	  ;% Gravity_Well_P.ConverttoPositiveRotationConven
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 18;
	
	  ;% Gravity_Well_P.JointOffsets_Bias
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 21;
	
	  ;% Gravity_Well_P.ToolOffset2_Value
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 24;
	
	  ;% Gravity_Well_P.Constant1_Value
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 40;
	
	  ;% Gravity_Well_P.Posz_Value
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 43;
	
	  ;% Gravity_Well_P.Posx_Value
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 44;
	
	  ;% Gravity_Well_P.Posy_Value
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 45;
	
	  ;% Gravity_Well_P.Stiffness_Gain
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 46;
	
	  ;% Gravity_Well_P.Constant2_Value
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 47;
	
	  ;% Gravity_Well_P.Integrator_IC
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 48;
	
	  ;% Gravity_Well_P.Damping_Value
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 49;
	
	  ;% Gravity_Well_P.Compare_Threshold
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 50;
	
	  ;% Gravity_Well_P.Constant1_Value_p
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 51;
	
	  ;% Gravity_Well_P.Posz_Value_i
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 54;
	
	  ;% Gravity_Well_P.Posx_Value_p
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 55;
	
	  ;% Gravity_Well_P.Posy_Value_o
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 56;
	
	  ;% Gravity_Well_P.Stiffness_Gain_h
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 57;
	
	  ;% Gravity_Well_P.Constant2_Value_l
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 58;
	
	  ;% Gravity_Well_P.Integrator_IC_i
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 59;
	
	  ;% Gravity_Well_P.Damping_Value_k
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 60;
	
	  ;% Gravity_Well_P.Compare_Threshold_c
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 61;
	
	  ;% Gravity_Well_P.Constant_Value
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 62;
	
	  ;% Gravity_Well_P.ConverttoPositiveRotationConv_k
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 65;
	
	  ;% Gravity_Well_P.GearRatio1_Gain
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 68;
	
	  ;% Gravity_Well_P.Kt_Gain
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 71;
	
	  ;% Gravity_Well_P.Saturation_UpperSat
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 72;
	
	  ;% Gravity_Well_P.Saturation_LowerSat
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 73;
	
	  ;% Gravity_Well_P.Constant_Value_c
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 74;
	
	  ;% Gravity_Well_P.z1_Value
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 75;
	
	  ;% Gravity_Well_P.Constant_Value_n
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 76;
	
	  ;% Gravity_Well_P.z1_Value_h
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 77;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Gravity_Well_P.HILInitialize_DOWatchdog
	  section.data(1).logicalSrcIdx = 45;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Gravity_Well_P.HILInitialize_EIInitial
	  section.data(2).logicalSrcIdx = 46;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Gravity_Well_P.HILReadEncoderTimebase_Clock
	  section.data(3).logicalSrcIdx = 47;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Gravity_Well_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Gravity_Well_P.HILInitialize_EIChannels
	  section.data(2).logicalSrcIdx = 49;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Gravity_Well_P.HILInitialize_POChannels
	  section.data(3).logicalSrcIdx = 50;
	  section.data(3).dtTransOffset = 5;
	
	  ;% Gravity_Well_P.HILReadEncoderTimebase_Channels
	  section.data(4).logicalSrcIdx = 51;
	  section.data(4).dtTransOffset = 8;
	
	  ;% Gravity_Well_P.HILReadEncoderTimebase_SamplesI
	  section.data(5).logicalSrcIdx = 52;
	  section.data(5).dtTransOffset = 11;
	
	  ;% Gravity_Well_P.HILWritePWM_Channels
	  section.data(6).logicalSrcIdx = 53;
	  section.data(6).dtTransOffset = 12;
	
	  ;% Gravity_Well_P.HILReadAnalog_Channels
	  section.data(7).logicalSrcIdx = 54;
	  section.data(7).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 32;
      section.data(32)  = dumData; %prealloc
      
	  ;% Gravity_Well_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 55;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Gravity_Well_P.HILInitialize_CKPStart
	  section.data(2).logicalSrcIdx = 56;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Gravity_Well_P.HILInitialize_CKPEnter
	  section.data(3).logicalSrcIdx = 57;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Gravity_Well_P.HILInitialize_AIPStart
	  section.data(4).logicalSrcIdx = 58;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Gravity_Well_P.HILInitialize_AIPEnter
	  section.data(5).logicalSrcIdx = 59;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Gravity_Well_P.HILInitialize_AOPStart
	  section.data(6).logicalSrcIdx = 60;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Gravity_Well_P.HILInitialize_AOPEnter
	  section.data(7).logicalSrcIdx = 61;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Gravity_Well_P.HILInitialize_AOStart
	  section.data(8).logicalSrcIdx = 62;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Gravity_Well_P.HILInitialize_AOEnter
	  section.data(9).logicalSrcIdx = 63;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Gravity_Well_P.HILInitialize_AOTerminate
	  section.data(10).logicalSrcIdx = 64;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Gravity_Well_P.HILInitialize_AOExit
	  section.data(11).logicalSrcIdx = 65;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Gravity_Well_P.HILInitialize_AOReset
	  section.data(12).logicalSrcIdx = 66;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Gravity_Well_P.HILInitialize_DOStart
	  section.data(13).logicalSrcIdx = 67;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Gravity_Well_P.HILInitialize_DOEnter
	  section.data(14).logicalSrcIdx = 68;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Gravity_Well_P.HILInitialize_DOTerminate
	  section.data(15).logicalSrcIdx = 69;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Gravity_Well_P.HILInitialize_DOExit
	  section.data(16).logicalSrcIdx = 70;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Gravity_Well_P.HILInitialize_DOReset
	  section.data(17).logicalSrcIdx = 71;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Gravity_Well_P.HILInitialize_EIPStart
	  section.data(18).logicalSrcIdx = 72;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Gravity_Well_P.HILInitialize_EIPEnter
	  section.data(19).logicalSrcIdx = 73;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Gravity_Well_P.HILInitialize_EIStart
	  section.data(20).logicalSrcIdx = 74;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Gravity_Well_P.HILInitialize_EIEnter
	  section.data(21).logicalSrcIdx = 75;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Gravity_Well_P.HILInitialize_POPStart
	  section.data(22).logicalSrcIdx = 76;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Gravity_Well_P.HILInitialize_POPEnter
	  section.data(23).logicalSrcIdx = 77;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Gravity_Well_P.HILInitialize_POStart
	  section.data(24).logicalSrcIdx = 78;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Gravity_Well_P.HILInitialize_POEnter
	  section.data(25).logicalSrcIdx = 79;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Gravity_Well_P.HILInitialize_POTerminate
	  section.data(26).logicalSrcIdx = 80;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Gravity_Well_P.HILInitialize_POExit
	  section.data(27).logicalSrcIdx = 81;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Gravity_Well_P.HILInitialize_POReset
	  section.data(28).logicalSrcIdx = 82;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Gravity_Well_P.HILInitialize_OOReset
	  section.data(29).logicalSrcIdx = 83;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Gravity_Well_P.HILReadEncoderTimebase_Active
	  section.data(30).logicalSrcIdx = 84;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Gravity_Well_P.HILWritePWM_Active
	  section.data(31).logicalSrcIdx = 85;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Gravity_Well_P.HILReadAnalog_Active
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
    nTotSects     = 3;
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
    ;% Auto data (Gravity_Well_B)
    ;%
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% Gravity_Well_B.GearRatio
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Gravity_Well_B.JointOffsets
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Gravity_Well_B.ToolOffset2
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Gravity_Well_B.MathFunction
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 22;
	
	  ;% Gravity_Well_B.Subtract
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 40;
	
	  ;% Gravity_Well_B.Stiffness
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 43;
	
	  ;% Gravity_Well_B.Product1
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 46;
	
	  ;% Gravity_Well_B.Subtract_o
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 49;
	
	  ;% Gravity_Well_B.Stiffness_e
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 52;
	
	  ;% Gravity_Well_B.Product1_e
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 55;
	
	  ;% Gravity_Well_B.ConverttoPositiveRotationConven
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 58;
	
	  ;% Gravity_Well_B.Saturation
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 61;
	
	  ;% Gravity_Well_B.RateTransition1
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 64;
	
	  ;% Gravity_Well_B.Product
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 67;
	
	  ;% Gravity_Well_B.Product_h
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 70;
	
	  ;% Gravity_Well_B.y
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 73;
	
	  ;% Gravity_Well_B.y_a
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 76;
	
	  ;% Gravity_Well_B.pos
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 79;
	
	  ;% Gravity_Well_B.Rot
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 82;
	
	  ;% Gravity_Well_B.Jac
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 91;
	
	  ;% Gravity_Well_B.q
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 109;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Gravity_Well_B.sf_EuclideanDistance_j.mag
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Gravity_Well_B.sf_EuclideanDistance.mag
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
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
    nTotSects     = 13;
    sectIdxOffset = 3;
    
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
    ;% Auto data (Gravity_Well_DWork)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Gravity_Well_DWork.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Gravity_Well_DWork.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Gravity_Well_DWork.HILInitialize_FilterFrequency
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% Gravity_Well_DWork.HILInitialize_POSortedFreqs
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
	  ;% Gravity_Well_DWork.HILInitialize_POValues
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Gravity_Well_DWork.HILWritePWM_PWORK
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Gravity_Well_DWork.HILReadAnalog_PWORK
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Gravity_Well_DWork.VRSink1_PWORK
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Gravity_Well_DWork.HILInitialize_QuadratureModes
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Gravity_Well_DWork.HILInitialize_InitialEICounts
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Gravity_Well_DWork.HILInitialize_POModeValues
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Gravity_Well_DWork.HILReadEncoderTimebase_Buffer
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Gravity_Well_DWork.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Gravity_Well_DWork.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Gravity_Well_DWork.HILReadEncoderTimebase_Task
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Gravity_Well_DWork.Integrator1_IWORK.IcNeedsLoading
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Gravity_Well_DWork.Integrator1_IWORK_d.IcNeedsLoading
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Gravity_Well_DWork.is_active_c3_Gravity_Well
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Gravity_Well_DWork.is_active_c4_Gravity_Well
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Gravity_Well_DWork.is_active_c5_Gravity_Well
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Gravity_Well_DWork.is_active_c8_Gravity_Well
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Gravity_Well_DWork.doneDoubleBufferReInit
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Gravity_Well_DWork.doneDoubleBufferReInit_a
	  section.data(2).logicalSrcIdx = 22;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Gravity_Well_DWork.doneDoubleBufferReInit_f
	  section.data(3).logicalSrcIdx = 23;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Gravity_Well_DWork.doneDoubleBufferReInit_l
	  section.data(4).logicalSrcIdx = 24;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Gravity_Well_DWork.sf_EuclideanDistance_j.is_active_c7_Gravity_Well
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Gravity_Well_DWork.sf_EuclideanDistance_j.doneDoubleBufferReInit
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Gravity_Well_DWork.sf_EuclideanDistance.is_active_c7_Gravity_Well
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Gravity_Well_DWork.sf_EuclideanDistance.doneDoubleBufferReInit
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
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


  targMap.checksum0 = 3887136759;
  targMap.checksum1 = 3479414719;
  targMap.checksum2 = 4187217815;
  targMap.checksum3 = 54494498;

