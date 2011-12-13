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
    ;% Auto data (Force_Rendering_P)
    ;%
      section.nData     = 32;
      section.data(32)  = dumData; %prealloc
      
	  ;% Force_Rendering_P.HILInitialize_OOStart
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Force_Rendering_P.HILInitialize_OOEnter
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Force_Rendering_P.HILInitialize_OOTerminate
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Force_Rendering_P.HILInitialize_OOExit
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Force_Rendering_P.HILInitialize_AIHigh
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Force_Rendering_P.HILInitialize_AILow
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Force_Rendering_P.HILInitialize_AOWatchdog
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Force_Rendering_P.HILInitialize_POInitial
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Force_Rendering_P.HILInitialize_POFinal
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Force_Rendering_P.HILInitialize_POWatchdog
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Force_Rendering_P.HILInitialize_OOWatchdog
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Force_Rendering_P.Bias1_Bias
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Force_Rendering_P.Encoder_Gain
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 14;
	
	  ;% Force_Rendering_P.GearRatio_Gain
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 15;
	
	  ;% Force_Rendering_P.ConverttoPositiveRotationConven
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 18;
	
	  ;% Force_Rendering_P.JointOffsets_Bias
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 21;
	
	  ;% Force_Rendering_P.ToolOffset2_Value
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 24;
	
	  ;% Force_Rendering_P.Force_Value
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 40;
	
	  ;% Force_Rendering_P.SliderGain_Gain
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 43;
	
	  ;% Force_Rendering_P.Constant_Value
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 44;
	
	  ;% Force_Rendering_P.ConverttoPositiveRotationConv_e
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 47;
	
	  ;% Force_Rendering_P.GearRatio1_Gain
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 50;
	
	  ;% Force_Rendering_P.Kt_Gain
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 53;
	
	  ;% Force_Rendering_P.Saturation_UpperSat
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 54;
	
	  ;% Force_Rendering_P.Saturation_LowerSat
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 55;
	
	  ;% Force_Rendering_P.Bias1_Bias_k
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 56;
	
	  ;% Force_Rendering_P.Gain2_Gain
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 59;
	
	  ;% Force_Rendering_P.ConverttoPositiveRotationConv_c
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 62;
	
	  ;% Force_Rendering_P.JointOffsets1_Bias
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 65;
	
	  ;% Force_Rendering_P.metertomilimeter_Gain
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 68;
	
	  ;% Force_Rendering_P.radiantodegree1_Gain
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 69;
	
	  ;% Force_Rendering_P.radiantodegree_Gain
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 70;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Force_Rendering_P.HILInitialize_DOWatchdog
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Force_Rendering_P.HILInitialize_EIInitial
	  section.data(2).logicalSrcIdx = 33;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Force_Rendering_P.HILReadEncoderTimebase_Clock
	  section.data(3).logicalSrcIdx = 34;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Force_Rendering_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Force_Rendering_P.HILInitialize_EIChannels
	  section.data(2).logicalSrcIdx = 36;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Force_Rendering_P.HILInitialize_POChannels
	  section.data(3).logicalSrcIdx = 37;
	  section.data(3).dtTransOffset = 5;
	
	  ;% Force_Rendering_P.HILReadEncoderTimebase_Channels
	  section.data(4).logicalSrcIdx = 38;
	  section.data(4).dtTransOffset = 8;
	
	  ;% Force_Rendering_P.HILReadEncoderTimebase_SamplesI
	  section.data(5).logicalSrcIdx = 39;
	  section.data(5).dtTransOffset = 11;
	
	  ;% Force_Rendering_P.HILWritePWM_Channels
	  section.data(6).logicalSrcIdx = 40;
	  section.data(6).dtTransOffset = 12;
	
	  ;% Force_Rendering_P.HILReadAnalog_Channels
	  section.data(7).logicalSrcIdx = 41;
	  section.data(7).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 32;
      section.data(32)  = dumData; %prealloc
      
	  ;% Force_Rendering_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Force_Rendering_P.HILInitialize_CKPStart
	  section.data(2).logicalSrcIdx = 43;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Force_Rendering_P.HILInitialize_CKPEnter
	  section.data(3).logicalSrcIdx = 44;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Force_Rendering_P.HILInitialize_AIPStart
	  section.data(4).logicalSrcIdx = 45;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Force_Rendering_P.HILInitialize_AIPEnter
	  section.data(5).logicalSrcIdx = 46;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Force_Rendering_P.HILInitialize_AOPStart
	  section.data(6).logicalSrcIdx = 47;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Force_Rendering_P.HILInitialize_AOPEnter
	  section.data(7).logicalSrcIdx = 48;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Force_Rendering_P.HILInitialize_AOStart
	  section.data(8).logicalSrcIdx = 49;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Force_Rendering_P.HILInitialize_AOEnter
	  section.data(9).logicalSrcIdx = 50;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Force_Rendering_P.HILInitialize_AOTerminate
	  section.data(10).logicalSrcIdx = 51;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Force_Rendering_P.HILInitialize_AOExit
	  section.data(11).logicalSrcIdx = 52;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Force_Rendering_P.HILInitialize_AOReset
	  section.data(12).logicalSrcIdx = 53;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Force_Rendering_P.HILInitialize_DOStart
	  section.data(13).logicalSrcIdx = 54;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Force_Rendering_P.HILInitialize_DOEnter
	  section.data(14).logicalSrcIdx = 55;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Force_Rendering_P.HILInitialize_DOTerminate
	  section.data(15).logicalSrcIdx = 56;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Force_Rendering_P.HILInitialize_DOExit
	  section.data(16).logicalSrcIdx = 57;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Force_Rendering_P.HILInitialize_DOReset
	  section.data(17).logicalSrcIdx = 58;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Force_Rendering_P.HILInitialize_EIPStart
	  section.data(18).logicalSrcIdx = 59;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Force_Rendering_P.HILInitialize_EIPEnter
	  section.data(19).logicalSrcIdx = 60;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Force_Rendering_P.HILInitialize_EIStart
	  section.data(20).logicalSrcIdx = 61;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Force_Rendering_P.HILInitialize_EIEnter
	  section.data(21).logicalSrcIdx = 62;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Force_Rendering_P.HILInitialize_POPStart
	  section.data(22).logicalSrcIdx = 63;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Force_Rendering_P.HILInitialize_POPEnter
	  section.data(23).logicalSrcIdx = 64;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Force_Rendering_P.HILInitialize_POStart
	  section.data(24).logicalSrcIdx = 65;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Force_Rendering_P.HILInitialize_POEnter
	  section.data(25).logicalSrcIdx = 66;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Force_Rendering_P.HILInitialize_POTerminate
	  section.data(26).logicalSrcIdx = 67;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Force_Rendering_P.HILInitialize_POExit
	  section.data(27).logicalSrcIdx = 68;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Force_Rendering_P.HILInitialize_POReset
	  section.data(28).logicalSrcIdx = 69;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Force_Rendering_P.HILInitialize_OOReset
	  section.data(29).logicalSrcIdx = 70;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Force_Rendering_P.HILReadEncoderTimebase_Active
	  section.data(30).logicalSrcIdx = 71;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Force_Rendering_P.HILWritePWM_Active
	  section.data(31).logicalSrcIdx = 72;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Force_Rendering_P.HILReadAnalog_Active
	  section.data(32).logicalSrcIdx = 73;
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
    nTotSects     = 2;
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
    ;% Auto data (Force_Rendering_B)
    ;%
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% Force_Rendering_B.GearRatio
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Force_Rendering_B.JointOffsets
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Force_Rendering_B.ToolOffset2
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Force_Rendering_B.ConverttoPositiveRotationConven
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 22;
	
	  ;% Force_Rendering_B.Saturation
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 25;
	
	  ;% Force_Rendering_B.y
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 28;
	
	  ;% Force_Rendering_B.y_f
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 31;
	
	  ;% Force_Rendering_B.pos
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 34;
	
	  ;% Force_Rendering_B.Rot
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 37;
	
	  ;% Force_Rendering_B.Jac
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 46;
	
	  ;% Force_Rendering_B.q
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 64;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Force_Rendering_B.Rounding
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Force_Rendering_B.Rounding2
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Force_Rendering_B.Rounding1
	  section.data(3).logicalSrcIdx = 13;
	  section.data(3).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
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
    sectIdxOffset = 2;
    
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
    ;% Auto data (Force_Rendering_DWork)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Force_Rendering_DWork.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Force_Rendering_DWork.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Force_Rendering_DWork.HILInitialize_FilterFrequency
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% Force_Rendering_DWork.HILInitialize_POSortedFreqs
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
	  ;% Force_Rendering_DWork.HILInitialize_POValues
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Force_Rendering_DWork.HILWritePWM_PWORK
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Force_Rendering_DWork.HILReadAnalog_PWORK
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Force_Rendering_DWork.HILInitialize_QuadratureModes
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Force_Rendering_DWork.HILInitialize_InitialEICounts
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Force_Rendering_DWork.HILInitialize_POModeValues
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Force_Rendering_DWork.HILReadEncoderTimebase_Buffer
	  section.data(4).logicalSrcIdx = 10;
	  section.data(4).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Force_Rendering_DWork.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Force_Rendering_DWork.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Force_Rendering_DWork.HILReadEncoderTimebase_Task
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Force_Rendering_DWork.is_active_c3_Force_Rendering
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Force_Rendering_DWork.is_active_c4_Force_Rendering
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Force_Rendering_DWork.is_active_c5_Force_Rendering
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Force_Rendering_DWork.is_active_c8_Force_Rendering
	  section.data(4).logicalSrcIdx = 17;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Force_Rendering_DWork.doneDoubleBufferReInit
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Force_Rendering_DWork.doneDoubleBufferReInit_f
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Force_Rendering_DWork.doneDoubleBufferReInit_fr
	  section.data(3).logicalSrcIdx = 20;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Force_Rendering_DWork.doneDoubleBufferReInit_ft
	  section.data(4).logicalSrcIdx = 21;
	  section.data(4).dtTransOffset = 3;
	
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


  targMap.checksum0 = 4227541037;
  targMap.checksum1 = 3154054101;
  targMap.checksum2 = 2402257829;
  targMap.checksum3 = 3343334248;

