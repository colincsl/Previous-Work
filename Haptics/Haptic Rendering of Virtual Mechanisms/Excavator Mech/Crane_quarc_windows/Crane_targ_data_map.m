  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
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
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Crane_P)
    ;%
      section.nData     = 23;
      section.data(23)  = dumData; %prealloc
      
	  ;% Crane_P.Constant2_Value
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Crane_P.Block1_SimMechanicsRuntimeParam
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Crane_P.gain_1_Gain
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 393;
	
	  ;% Crane_P.Memory_X0
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 394;
	
	  ;% Crane_P.Constant5_Value
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 395;
	
	  ;% Crane_P.Integrator_IC
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 396;
	
	  ;% Crane_P.Constant6_Value
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 397;
	
	  ;% Crane_P.Gain4_Gain
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 398;
	
	  ;% Crane_P.Saturation_UpperSat
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 399;
	
	  ;% Crane_P.Saturation_LowerSat
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 400;
	
	  ;% Crane_P.Gain3_Gain
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 401;
	
	  ;% Crane_P.Constant_Value
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 402;
	
	  ;% Crane_P.Constant1_Value
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 403;
	
	  ;% Crane_P.Gain2_Gain
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 404;
	
	  ;% Crane_P.Constant3_Value
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 405;
	
	  ;% Crane_P.Gain1_Gain
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 406;
	
	  ;% Crane_P.SineWave_Amp
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 407;
	
	  ;% Crane_P.SineWave_Bias
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 408;
	
	  ;% Crane_P.SineWave_Freq
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 409;
	
	  ;% Crane_P.SineWave_Phase
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 410;
	
	  ;% Crane_P.Gain_Gain
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 411;
	
	  ;% Crane_P.SOURCE_BLOCK_Value
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 412;
	
	  ;% Crane_P._gravity_conversion_Gain
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 415;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
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
    ;% Auto data (Crane_B)
    ;%
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% Crane_B.Block1_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Crane_B.Block1_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Crane_B.Block1_o3
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 21;
	
	  ;% Crane_B.gain_1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 22;
	
	  ;% Crane_B.Memory
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 25;
	
	  ;% Crane_B.Sum
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 28;
	
	  ;% Crane_B.Sum1
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 31;
	
	  ;% Crane_B.Saturation
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 34;
	
	  ;% Crane_B.Gain3
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 37;
	
	  ;% Crane_B.Constant
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 40;
	
	  ;% Crane_B.Gain2
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 41;
	
	  ;% Crane_B.Gain1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 42;
	
	  ;% Crane_B.Gain
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 43;
	
	  ;% Crane_B._gravity_conversion
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 44;
	
	  ;% Crane_B.Block2
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 47;
	
	  ;% Crane_B.Block3
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 48;
	
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
    nTotSects     = 4;
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
    ;% Auto data (Crane_DWork)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Crane_DWork.Memory_PreviousInput
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Crane_DWork.Derivative_RWORK.TimeStampA
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Crane_DWork.Block1_PWORK
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Crane_DWork.ToWorkspace_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Crane_DWork.Block2_PWORK
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Crane_DWork.Block3_PWORK
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Crane_DWork.Falcon_Falcon
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Crane_DWork.Block1_IWORK
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Crane_DWork.Block3_IWORK
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
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


  targMap.checksum0 = 2478158774;
  targMap.checksum1 = 3803381746;
  targMap.checksum2 = 277883647;
  targMap.checksum3 = 670793414;

