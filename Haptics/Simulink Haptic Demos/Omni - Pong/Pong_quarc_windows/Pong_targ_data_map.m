  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
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
    ;% Auto data (Pong_P)
    ;%
      section.nData     = 88;
      section.data(88)  = dumData; %prealloc
      
	  ;% Pong_P.HILInitialize_OOStart
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pong_P.HILInitialize_OOEnter
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pong_P.HILInitialize_OOTerminate
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Pong_P.HILInitialize_OOExit
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Pong_P.HILInitialize_AIHigh
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Pong_P.HILInitialize_AILow
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Pong_P.HILInitialize_AOWatchdog
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Pong_P.HILInitialize_POInitial
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Pong_P.HILInitialize_POFinal
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Pong_P.HILInitialize_POWatchdog
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Pong_P.HILInitialize_OOWatchdog
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Pong_P.Bias1_Bias
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Pong_P.Encoder_Gain
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 14;
	
	  ;% Pong_P.GearRatio_Gain
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 15;
	
	  ;% Pong_P.ConverttoPositiveRotationConven
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 18;
	
	  ;% Pong_P.JointOffsets_Bias
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 21;
	
	  ;% Pong_P.ToolOffset2_Value
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 24;
	
	  ;% Pong_P.Constant12_Value
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 40;
	
	  ;% Pong_P.Integrator3_IC
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 41;
	
	  ;% Pong_P.Wn_Value
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 42;
	
	  ;% Pong_P.Integrator_IC
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 43;
	
	  ;% Pong_P.Constant_Value
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 44;
	
	  ;% Pong_P.Integrator1_IC
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 45;
	
	  ;% Pong_P.Constant2_Value
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 46;
	
	  ;% Pong_P.Constant6_Value
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 47;
	
	  ;% Pong_P.Constant_Value_n
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 48;
	
	  ;% Pong_P.Constant4_Value
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 49;
	
	  ;% Pong_P.noncontactForce4_Value
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 50;
	
	  ;% Pong_P.Wn_Value_j
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 51;
	
	  ;% Pong_P.Integrator_IC_i
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 52;
	
	  ;% Pong_P.noncontactForce_Value
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 53;
	
	  ;% Pong_P.Constant10_Value
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 54;
	
	  ;% Pong_P.Constant_Value_g
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 57;
	
	  ;% Pong_P.ConverttoPositiveRotationConv_d
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 60;
	
	  ;% Pong_P.GearRatio1_Gain
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 63;
	
	  ;% Pong_P.Kt_Gain
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 66;
	
	  ;% Pong_P.Saturation_UpperSat
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 67;
	
	  ;% Pong_P.Saturation_LowerSat
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 68;
	
	  ;% Pong_P.Constant_Value_nt
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 69;
	
	  ;% Pong_P.z_Value
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 70;
	
	  ;% Pong_P.Gain3_Gain
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 71;
	
	  ;% Pong_P.Constant3_Value
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 72;
	
	  ;% Pong_P.Gain4_Gain
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 73;
	
	  ;% Pong_P.Integrator2_IC
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 74;
	
	  ;% Pong_P.Constant_Value_p
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 75;
	
	  ;% Pong_P.Integrator_IC_n
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 76;
	
	  ;% Pong_P.Wn_Value_ju
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 77;
	
	  ;% Pong_P.z_Value_a
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 78;
	
	  ;% Pong_P.noncontactForce2_Value
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 79;
	
	  ;% Pong_P.Switch2_Threshold
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 80;
	
	  ;% Pong_P.Constant_Value_n2
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 81;
	
	  ;% Pong_P.Integrator_IC_o
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 82;
	
	  ;% Pong_P.Wn_Value_e
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 83;
	
	  ;% Pong_P.z_Value_f
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 84;
	
	  ;% Pong_P.noncontactForce3_Value
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 85;
	
	  ;% Pong_P.Switch3_Threshold
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 86;
	
	  ;% Pong_P.TransferFcn1_D
	  section.data(57).logicalSrcIdx = 58;
	  section.data(57).dtTransOffset = 87;
	
	  ;% Pong_P.Gravity_Value
	  section.data(58).logicalSrcIdx = 60;
	  section.data(58).dtTransOffset = 88;
	
	  ;% Pong_P.Integrator_IC_c
	  section.data(59).logicalSrcIdx = 61;
	  section.data(59).dtTransOffset = 89;
	
	  ;% Pong_P.Constant_Value_o
	  section.data(60).logicalSrcIdx = 62;
	  section.data(60).dtTransOffset = 90;
	
	  ;% Pong_P.z_Value_j
	  section.data(61).logicalSrcIdx = 63;
	  section.data(61).dtTransOffset = 91;
	
	  ;% Pong_P.Constant_Value_o1
	  section.data(62).logicalSrcIdx = 64;
	  section.data(62).dtTransOffset = 92;
	
	  ;% Pong_P.Integrator_IC_h
	  section.data(63).logicalSrcIdx = 65;
	  section.data(63).dtTransOffset = 93;
	
	  ;% Pong_P.Constant9_Value
	  section.data(64).logicalSrcIdx = 66;
	  section.data(64).dtTransOffset = 94;
	
	  ;% Pong_P.Wn_Value_h
	  section.data(65).logicalSrcIdx = 67;
	  section.data(65).dtTransOffset = 97;
	
	  ;% Pong_P.z_Value_h
	  section.data(66).logicalSrcIdx = 68;
	  section.data(66).dtTransOffset = 98;
	
	  ;% Pong_P.noncontactForce1_Value
	  section.data(67).logicalSrcIdx = 69;
	  section.data(67).dtTransOffset = 99;
	
	  ;% Pong_P.Switch1_Threshold
	  section.data(68).logicalSrcIdx = 70;
	  section.data(68).dtTransOffset = 100;
	
	  ;% Pong_P.TransferFcn_D
	  section.data(69).logicalSrcIdx = 73;
	  section.data(69).dtTransOffset = 101;
	
	  ;% Pong_P.Constant7_Value
	  section.data(70).logicalSrcIdx = 75;
	  section.data(70).dtTransOffset = 102;
	
	  ;% Pong_P.zpositionofball_Value
	  section.data(71).logicalSrcIdx = 76;
	  section.data(71).dtTransOffset = 103;
	
	  ;% Pong_P.Constant1_Value
	  section.data(72).logicalSrcIdx = 77;
	  section.data(72).dtTransOffset = 104;
	
	  ;% Pong_P.Constant5_Value
	  section.data(73).logicalSrcIdx = 78;
	  section.data(73).dtTransOffset = 105;
	
	  ;% Pong_P.Constant2_Value_f
	  section.data(74).logicalSrcIdx = 79;
	  section.data(74).dtTransOffset = 106;
	
	  ;% Pong_P.Constant1_Value_f
	  section.data(75).logicalSrcIdx = 80;
	  section.data(75).dtTransOffset = 107;
	
	  ;% Pong_P.Constant10_Value_k
	  section.data(76).logicalSrcIdx = 81;
	  section.data(76).dtTransOffset = 108;
	
	  ;% Pong_P.Constant11_Value
	  section.data(77).logicalSrcIdx = 82;
	  section.data(77).dtTransOffset = 109;
	
	  ;% Pong_P.Gain1_Gain
	  section.data(78).logicalSrcIdx = 83;
	  section.data(78).dtTransOffset = 110;
	
	  ;% Pong_P.Gain3_Gain_i
	  section.data(79).logicalSrcIdx = 84;
	  section.data(79).dtTransOffset = 111;
	
	  ;% Pong_P.Gain1_Gain_a
	  section.data(80).logicalSrcIdx = 85;
	  section.data(80).dtTransOffset = 112;
	
	  ;% Pong_P.Gain3_Gain_ij
	  section.data(81).logicalSrcIdx = 86;
	  section.data(81).dtTransOffset = 113;
	
	  ;% Pong_P.Gain3_Gain_c
	  section.data(82).logicalSrcIdx = 87;
	  section.data(82).dtTransOffset = 114;
	
	  ;% Pong_P.Gain1_Gain_g
	  section.data(83).logicalSrcIdx = 88;
	  section.data(83).dtTransOffset = 115;
	
	  ;% Pong_P.Gain3_Gain_cs
	  section.data(84).logicalSrcIdx = 89;
	  section.data(84).dtTransOffset = 116;
	
	  ;% Pong_P.Gain1_Gain_h
	  section.data(85).logicalSrcIdx = 90;
	  section.data(85).dtTransOffset = 117;
	
	  ;% Pong_P.Gain3_Gain_d
	  section.data(86).logicalSrcIdx = 91;
	  section.data(86).dtTransOffset = 118;
	
	  ;% Pong_P.Gain1_Gain_a1
	  section.data(87).logicalSrcIdx = 92;
	  section.data(87).dtTransOffset = 119;
	
	  ;% Pong_P.Gain1_Gain_l
	  section.data(88).logicalSrcIdx = 93;
	  section.data(88).dtTransOffset = 120;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Pong_P.HILInitialize_DOWatchdog
	  section.data(1).logicalSrcIdx = 94;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pong_P.HILInitialize_EIInitial
	  section.data(2).logicalSrcIdx = 95;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pong_P.HILReadEncoderTimebase_Clock
	  section.data(3).logicalSrcIdx = 96;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Pong_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 97;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pong_P.HILInitialize_EIChannels
	  section.data(2).logicalSrcIdx = 98;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Pong_P.HILInitialize_POChannels
	  section.data(3).logicalSrcIdx = 99;
	  section.data(3).dtTransOffset = 5;
	
	  ;% Pong_P.HILReadEncoderTimebase_Channels
	  section.data(4).logicalSrcIdx = 100;
	  section.data(4).dtTransOffset = 8;
	
	  ;% Pong_P.HILReadEncoderTimebase_SamplesI
	  section.data(5).logicalSrcIdx = 101;
	  section.data(5).dtTransOffset = 11;
	
	  ;% Pong_P.HILWritePWM_Channels
	  section.data(6).logicalSrcIdx = 102;
	  section.data(6).dtTransOffset = 12;
	
	  ;% Pong_P.HILReadAnalog_Channels
	  section.data(7).logicalSrcIdx = 103;
	  section.data(7).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Pong_P.Constant_Value_k
	  section.data(1).logicalSrcIdx = 104;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pong_P.SwitchControl_Threshold
	  section.data(2).logicalSrcIdx = 105;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pong_P.Constant_Value_i
	  section.data(3).logicalSrcIdx = 106;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Pong_P.SwitchControl_Threshold_k
	  section.data(4).logicalSrcIdx = 107;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 32;
      section.data(32)  = dumData; %prealloc
      
	  ;% Pong_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 108;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pong_P.HILInitialize_CKPStart
	  section.data(2).logicalSrcIdx = 109;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pong_P.HILInitialize_CKPEnter
	  section.data(3).logicalSrcIdx = 110;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Pong_P.HILInitialize_AIPStart
	  section.data(4).logicalSrcIdx = 111;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Pong_P.HILInitialize_AIPEnter
	  section.data(5).logicalSrcIdx = 112;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Pong_P.HILInitialize_AOPStart
	  section.data(6).logicalSrcIdx = 113;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Pong_P.HILInitialize_AOPEnter
	  section.data(7).logicalSrcIdx = 114;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Pong_P.HILInitialize_AOStart
	  section.data(8).logicalSrcIdx = 115;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Pong_P.HILInitialize_AOEnter
	  section.data(9).logicalSrcIdx = 116;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Pong_P.HILInitialize_AOTerminate
	  section.data(10).logicalSrcIdx = 117;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Pong_P.HILInitialize_AOExit
	  section.data(11).logicalSrcIdx = 118;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Pong_P.HILInitialize_AOReset
	  section.data(12).logicalSrcIdx = 119;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Pong_P.HILInitialize_DOStart
	  section.data(13).logicalSrcIdx = 120;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Pong_P.HILInitialize_DOEnter
	  section.data(14).logicalSrcIdx = 121;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Pong_P.HILInitialize_DOTerminate
	  section.data(15).logicalSrcIdx = 122;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Pong_P.HILInitialize_DOExit
	  section.data(16).logicalSrcIdx = 123;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Pong_P.HILInitialize_DOReset
	  section.data(17).logicalSrcIdx = 124;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Pong_P.HILInitialize_EIPStart
	  section.data(18).logicalSrcIdx = 125;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Pong_P.HILInitialize_EIPEnter
	  section.data(19).logicalSrcIdx = 126;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Pong_P.HILInitialize_EIStart
	  section.data(20).logicalSrcIdx = 127;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Pong_P.HILInitialize_EIEnter
	  section.data(21).logicalSrcIdx = 128;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Pong_P.HILInitialize_POPStart
	  section.data(22).logicalSrcIdx = 129;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Pong_P.HILInitialize_POPEnter
	  section.data(23).logicalSrcIdx = 130;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Pong_P.HILInitialize_POStart
	  section.data(24).logicalSrcIdx = 131;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Pong_P.HILInitialize_POEnter
	  section.data(25).logicalSrcIdx = 132;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Pong_P.HILInitialize_POTerminate
	  section.data(26).logicalSrcIdx = 133;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Pong_P.HILInitialize_POExit
	  section.data(27).logicalSrcIdx = 134;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Pong_P.HILInitialize_POReset
	  section.data(28).logicalSrcIdx = 135;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Pong_P.HILInitialize_OOReset
	  section.data(29).logicalSrcIdx = 136;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Pong_P.HILReadEncoderTimebase_Active
	  section.data(30).logicalSrcIdx = 137;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Pong_P.HILWritePWM_Active
	  section.data(31).logicalSrcIdx = 138;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Pong_P.HILReadAnalog_Active
	  section.data(32).logicalSrcIdx = 139;
	  section.data(32).dtTransOffset = 31;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
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
    ;% Auto data (Pong_B)
    ;%
      section.nData     = 49;
      section.data(49)  = dumData; %prealloc
      
	  ;% Pong_B.GearRatio
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pong_B.JointOffsets
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Pong_B.ToolOffset2
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Pong_B.MathFunction
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 22;
	
	  ;% Pong_B.Sum10
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 40;
	
	  ;% Pong_B.Product1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 41;
	
	  ;% Pong_B.Sum1
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 42;
	
	  ;% Pong_B.Sum8
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 43;
	
	  ;% Pong_B.Sum9
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 44;
	
	  ;% Pong_B.Product1_n
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 45;
	
	  ;% Pong_B.ConverttoPositiveRotationConven
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 46;
	
	  ;% Pong_B.Saturation
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 49;
	
	  ;% Pong_B.Product
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 52;
	
	  ;% Pong_B.Gain4
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 53;
	
	  ;% Pong_B.Integrator2
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 54;
	
	  ;% Pong_B.Sum5
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 55;
	
	  ;% Pong_B.Product_b
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 56;
	
	  ;% Pong_B.Product1_m
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 57;
	
	  ;% Pong_B.Sum6
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 58;
	
	  ;% Pong_B.Product_h
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 59;
	
	  ;% Pong_B.Product1_g
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 60;
	
	  ;% Pong_B.Sum7
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 61;
	
	  ;% Pong_B.TransferFcn1
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 62;
	
	  ;% Pong_B.Integrator
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 63;
	
	  ;% Pong_B.Product_he
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 64;
	
	  ;% Pong_B.Sum4
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 65;
	
	  ;% Pong_B.Sum2
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 66;
	
	  ;% Pong_B.Product_m
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 67;
	
	  ;% Pong_B.Product1_h
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 68;
	
	  ;% Pong_B.Sum
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 69;
	
	  ;% Pong_B.TransferFcn
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 70;
	
	  ;% Pong_B.RateTransition6
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 71;
	
	  ;% Pong_B.Sum5_k
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 74;
	
	  ;% Pong_B.Sum6_b
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 75;
	
	  ;% Pong_B.Sum3
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 76;
	
	  ;% Pong_B.Sum4_b
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 77;
	
	  ;% Pong_B.RateTransition7
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 78;
	
	  ;% Pong_B.RateTransition1
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 81;
	
	  ;% Pong_B.RateTransition5
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 84;
	
	  ;% Pong_B.RateTransition4
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 87;
	
	  ;% Pong_B.RateTransition3
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 90;
	
	  ;% Pong_B.Add
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 93;
	
	  ;% Pong_B.SwitchControl
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 94;
	
	  ;% Pong_B.y
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 95;
	
	  ;% Pong_B.y_d
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 98;
	
	  ;% Pong_B.pos
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 101;
	
	  ;% Pong_B.Rot
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 104;
	
	  ;% Pong_B.Jac
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 113;
	
	  ;% Pong_B.q
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 131;
	
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
    ;% Auto data (Pong_DWork)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Pong_DWork.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pong_DWork.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Pong_DWork.HILInitialize_FilterFrequency
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% Pong_DWork.HILInitialize_POSortedFreqs
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
	  ;% Pong_DWork.HILInitialize_POValues
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Pong_DWork.HILWritePWM_PWORK
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pong_DWork.HILReadAnalog_PWORK
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pong_DWork.VRSink_PWORK
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Pong_DWork.HILInitialize_QuadratureModes
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pong_DWork.HILInitialize_InitialEICounts
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Pong_DWork.HILInitialize_POModeValues
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Pong_DWork.HILReadEncoderTimebase_Buffer
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pong_DWork.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pong_DWork.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pong_DWork.HILReadEncoderTimebase_Task
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Pong_DWork.Integrator1_IWORK.IcNeedsLoading
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pong_DWork.Integrator1_IWORK_k.IcNeedsLoading
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pong_DWork.Integrator1_IWORK_h.IcNeedsLoading
	  section.data(3).logicalSrcIdx = 17;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Pong_DWork.Integrator1_IWORK_e.IcNeedsLoading
	  section.data(4).logicalSrcIdx = 18;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Pong_DWork.Integrator1_IWORK_hb.IcNeedsLoading
	  section.data(5).logicalSrcIdx = 19;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Pong_DWork.is_active_c3_Pong
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pong_DWork.is_active_c4_Pong
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pong_DWork.is_active_c5_Pong
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Pong_DWork.is_active_c8_Pong
	  section.data(4).logicalSrcIdx = 23;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Pong_DWork.doneDoubleBufferReInit
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pong_DWork.doneDoubleBufferReInit_g
	  section.data(2).logicalSrcIdx = 25;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pong_DWork.doneDoubleBufferReInit_m
	  section.data(3).logicalSrcIdx = 26;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Pong_DWork.doneDoubleBufferReInit_e
	  section.data(4).logicalSrcIdx = 27;
	  section.data(4).dtTransOffset = 3;
	
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


  targMap.checksum0 = 2496160883;
  targMap.checksum1 = 1721223492;
  targMap.checksum2 = 2761988816;
  targMap.checksum3 = 1532070706;

