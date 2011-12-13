  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 13;
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
    ;% Auto data (vmrl_test_fourbar_P)
    ;%
      section.nData     = 31;
      section.data(31)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_P.Block1_SimMechanicsRuntimeParam
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vmrl_test_fourbar_P.gain_2_Gain
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 200;
	
	  ;% vmrl_test_fourbar_P.Constant_Value
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 201;
	
	  ;% vmrl_test_fourbar_P.gain_1_Gain
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 202;
	
	  ;% vmrl_test_fourbar_P.gain_2_Gain_n
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 203;
	
	  ;% vmrl_test_fourbar_P.Constant_Value_l
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 204;
	
	  ;% vmrl_test_fourbar_P.gain_1_Gain_m
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 205;
	
	  ;% vmrl_test_fourbar_P.gain_2_Gain_n0
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 206;
	
	  ;% vmrl_test_fourbar_P.Constant_Value_e
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 207;
	
	  ;% vmrl_test_fourbar_P.gain_1_Gain_p
	  section.data(10).logicalSrcIdx = 12;
	  section.data(10).dtTransOffset = 208;
	
	  ;% vmrl_test_fourbar_P.gain_2_Gain_o
	  section.data(11).logicalSrcIdx = 13;
	  section.data(11).dtTransOffset = 209;
	
	  ;% vmrl_test_fourbar_P.Constant_Value_a
	  section.data(12).logicalSrcIdx = 14;
	  section.data(12).dtTransOffset = 210;
	
	  ;% vmrl_test_fourbar_P.gain_1_Gain_k
	  section.data(13).logicalSrcIdx = 16;
	  section.data(13).dtTransOffset = 211;
	
	  ;% vmrl_test_fourbar_P.Constant_Value_ej
	  section.data(14).logicalSrcIdx = 17;
	  section.data(14).dtTransOffset = 212;
	
	  ;% vmrl_test_fourbar_P.gain_2_Gain_d
	  section.data(15).logicalSrcIdx = 19;
	  section.data(15).dtTransOffset = 213;
	
	  ;% vmrl_test_fourbar_P.Constant_Value_b
	  section.data(16).logicalSrcIdx = 20;
	  section.data(16).dtTransOffset = 214;
	
	  ;% vmrl_test_fourbar_P.gain_1_Gain_h
	  section.data(17).logicalSrcIdx = 22;
	  section.data(17).dtTransOffset = 215;
	
	  ;% vmrl_test_fourbar_P.SOURCE_BLOCK_Value
	  section.data(18).logicalSrcIdx = 23;
	  section.data(18).dtTransOffset = 216;
	
	  ;% vmrl_test_fourbar_P._gravity_conversion_Gain
	  section.data(19).logicalSrcIdx = 24;
	  section.data(19).dtTransOffset = 219;
	
	  ;% vmrl_test_fourbar_P.VRRot_0_Y0
	  section.data(20).logicalSrcIdx = 25;
	  section.data(20).dtTransOffset = 220;
	
	  ;% vmrl_test_fourbar_P.Trace3Phi0_Value
	  section.data(21).logicalSrcIdx = 26;
	  section.data(21).dtTransOffset = 224;
	
	  ;% vmrl_test_fourbar_P.VRRot_0_Y0_i
	  section.data(22).logicalSrcIdx = 27;
	  section.data(22).dtTransOffset = 228;
	
	  ;% vmrl_test_fourbar_P.Trace3Phi0_Value_h
	  section.data(23).logicalSrcIdx = 28;
	  section.data(23).dtTransOffset = 232;
	
	  ;% vmrl_test_fourbar_P.VRRot_0_Y0_d
	  section.data(24).logicalSrcIdx = 29;
	  section.data(24).dtTransOffset = 236;
	
	  ;% vmrl_test_fourbar_P.Trace3Phi0_Value_i
	  section.data(25).logicalSrcIdx = 30;
	  section.data(25).dtTransOffset = 240;
	
	  ;% vmrl_test_fourbar_P.VRRot_0_Y0_b
	  section.data(26).logicalSrcIdx = 31;
	  section.data(26).dtTransOffset = 244;
	
	  ;% vmrl_test_fourbar_P.Trace3Phi0_Value_b
	  section.data(27).logicalSrcIdx = 32;
	  section.data(27).dtTransOffset = 248;
	
	  ;% vmrl_test_fourbar_P.VRRot_0_Y0_e
	  section.data(28).logicalSrcIdx = 33;
	  section.data(28).dtTransOffset = 252;
	
	  ;% vmrl_test_fourbar_P.Trace3Phi0_Value_o
	  section.data(29).logicalSrcIdx = 34;
	  section.data(29).dtTransOffset = 256;
	
	  ;% vmrl_test_fourbar_P.VRRot_0_Y0_l
	  section.data(30).logicalSrcIdx = 35;
	  section.data(30).dtTransOffset = 260;
	
	  ;% vmrl_test_fourbar_P.Trace3Phi0_Value_e
	  section.data(31).logicalSrcIdx = 36;
	  section.data(31).dtTransOffset = 264;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_P.Generalcase_b.Constant_Value
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vmrl_test_fourbar_P.Generalcase_b.Gain1_Gain
	  section.data(2).logicalSrcIdx = 38;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vmrl_test_fourbar_P.Generalcase_b.Gain_Gain
	  section.data(3).logicalSrcIdx = 39;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_P.Phipi_n.Shiftright_table
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vmrl_test_fourbar_P.Phipi_n.Gain1_Gain
	  section.data(2).logicalSrcIdx = 41;
	  section.data(2).dtTransOffset = 24;
	
	  ;% vmrl_test_fourbar_P.Phipi_n.VRRot_Pi_Y0
	  section.data(3).logicalSrcIdx = 42;
	  section.data(3).dtTransOffset = 25;
	
	  ;% vmrl_test_fourbar_P.Phipi_n.Constant_Value
	  section.data(4).logicalSrcIdx = 43;
	  section.data(4).dtTransOffset = 29;
	
	  ;% vmrl_test_fourbar_P.Phipi_n.Gain_Gain
	  section.data(5).logicalSrcIdx = 44;
	  section.data(5).dtTransOffset = 30;
	
	  ;% vmrl_test_fourbar_P.Phipi_n.DeadZone_Start
	  section.data(6).logicalSrcIdx = 45;
	  section.data(6).dtTransOffset = 31;
	
	  ;% vmrl_test_fourbar_P.Phipi_n.DeadZone_End
	  section.data(7).logicalSrcIdx = 46;
	  section.data(7).dtTransOffset = 32;
	
	  ;% vmrl_test_fourbar_P.Phipi_n.Pi1_Value
	  section.data(8).logicalSrcIdx = 47;
	  section.data(8).dtTransOffset = 33;
	
	  ;% vmrl_test_fourbar_P.Phipi_n.Switch_Threshold
	  section.data(9).logicalSrcIdx = 48;
	  section.data(9).dtTransOffset = 36;
	
	  ;% vmrl_test_fourbar_P.Phipi_n.Pi_Value
	  section.data(10).logicalSrcIdx = 49;
	  section.data(10).dtTransOffset = 37;
	
	  ;% vmrl_test_fourbar_P.Phipi_n.Switch_Threshold_h
	  section.data(11).logicalSrcIdx = 50;
	  section.data(11).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_P.Generalcase_l.Constant_Value
	  section.data(1).logicalSrcIdx = 51;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vmrl_test_fourbar_P.Generalcase_l.Gain1_Gain
	  section.data(2).logicalSrcIdx = 52;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vmrl_test_fourbar_P.Generalcase_l.Gain_Gain
	  section.data(3).logicalSrcIdx = 53;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_P.Phipi_j.Shiftright_table
	  section.data(1).logicalSrcIdx = 54;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vmrl_test_fourbar_P.Phipi_j.Gain1_Gain
	  section.data(2).logicalSrcIdx = 55;
	  section.data(2).dtTransOffset = 24;
	
	  ;% vmrl_test_fourbar_P.Phipi_j.VRRot_Pi_Y0
	  section.data(3).logicalSrcIdx = 56;
	  section.data(3).dtTransOffset = 25;
	
	  ;% vmrl_test_fourbar_P.Phipi_j.Constant_Value
	  section.data(4).logicalSrcIdx = 57;
	  section.data(4).dtTransOffset = 29;
	
	  ;% vmrl_test_fourbar_P.Phipi_j.Gain_Gain
	  section.data(5).logicalSrcIdx = 58;
	  section.data(5).dtTransOffset = 30;
	
	  ;% vmrl_test_fourbar_P.Phipi_j.DeadZone_Start
	  section.data(6).logicalSrcIdx = 59;
	  section.data(6).dtTransOffset = 31;
	
	  ;% vmrl_test_fourbar_P.Phipi_j.DeadZone_End
	  section.data(7).logicalSrcIdx = 60;
	  section.data(7).dtTransOffset = 32;
	
	  ;% vmrl_test_fourbar_P.Phipi_j.Pi1_Value
	  section.data(8).logicalSrcIdx = 61;
	  section.data(8).dtTransOffset = 33;
	
	  ;% vmrl_test_fourbar_P.Phipi_j.Switch_Threshold
	  section.data(9).logicalSrcIdx = 62;
	  section.data(9).dtTransOffset = 36;
	
	  ;% vmrl_test_fourbar_P.Phipi_j.Pi_Value
	  section.data(10).logicalSrcIdx = 63;
	  section.data(10).dtTransOffset = 37;
	
	  ;% vmrl_test_fourbar_P.Phipi_j.Switch_Threshold_h
	  section.data(11).logicalSrcIdx = 64;
	  section.data(11).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_P.Generalcase_k.Constant_Value
	  section.data(1).logicalSrcIdx = 65;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vmrl_test_fourbar_P.Generalcase_k.Gain1_Gain
	  section.data(2).logicalSrcIdx = 66;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vmrl_test_fourbar_P.Generalcase_k.Gain_Gain
	  section.data(3).logicalSrcIdx = 67;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_P.Phipi_g.Shiftright_table
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vmrl_test_fourbar_P.Phipi_g.Gain1_Gain
	  section.data(2).logicalSrcIdx = 69;
	  section.data(2).dtTransOffset = 24;
	
	  ;% vmrl_test_fourbar_P.Phipi_g.VRRot_Pi_Y0
	  section.data(3).logicalSrcIdx = 70;
	  section.data(3).dtTransOffset = 25;
	
	  ;% vmrl_test_fourbar_P.Phipi_g.Constant_Value
	  section.data(4).logicalSrcIdx = 71;
	  section.data(4).dtTransOffset = 29;
	
	  ;% vmrl_test_fourbar_P.Phipi_g.Gain_Gain
	  section.data(5).logicalSrcIdx = 72;
	  section.data(5).dtTransOffset = 30;
	
	  ;% vmrl_test_fourbar_P.Phipi_g.DeadZone_Start
	  section.data(6).logicalSrcIdx = 73;
	  section.data(6).dtTransOffset = 31;
	
	  ;% vmrl_test_fourbar_P.Phipi_g.DeadZone_End
	  section.data(7).logicalSrcIdx = 74;
	  section.data(7).dtTransOffset = 32;
	
	  ;% vmrl_test_fourbar_P.Phipi_g.Pi1_Value
	  section.data(8).logicalSrcIdx = 75;
	  section.data(8).dtTransOffset = 33;
	
	  ;% vmrl_test_fourbar_P.Phipi_g.Switch_Threshold
	  section.data(9).logicalSrcIdx = 76;
	  section.data(9).dtTransOffset = 36;
	
	  ;% vmrl_test_fourbar_P.Phipi_g.Pi_Value
	  section.data(10).logicalSrcIdx = 77;
	  section.data(10).dtTransOffset = 37;
	
	  ;% vmrl_test_fourbar_P.Phipi_g.Switch_Threshold_h
	  section.data(11).logicalSrcIdx = 78;
	  section.data(11).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_P.Generalcase_g.Constant_Value
	  section.data(1).logicalSrcIdx = 79;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vmrl_test_fourbar_P.Generalcase_g.Gain1_Gain
	  section.data(2).logicalSrcIdx = 80;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vmrl_test_fourbar_P.Generalcase_g.Gain_Gain
	  section.data(3).logicalSrcIdx = 81;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_P.Phipi_e.Shiftright_table
	  section.data(1).logicalSrcIdx = 82;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vmrl_test_fourbar_P.Phipi_e.Gain1_Gain
	  section.data(2).logicalSrcIdx = 83;
	  section.data(2).dtTransOffset = 24;
	
	  ;% vmrl_test_fourbar_P.Phipi_e.VRRot_Pi_Y0
	  section.data(3).logicalSrcIdx = 84;
	  section.data(3).dtTransOffset = 25;
	
	  ;% vmrl_test_fourbar_P.Phipi_e.Constant_Value
	  section.data(4).logicalSrcIdx = 85;
	  section.data(4).dtTransOffset = 29;
	
	  ;% vmrl_test_fourbar_P.Phipi_e.Gain_Gain
	  section.data(5).logicalSrcIdx = 86;
	  section.data(5).dtTransOffset = 30;
	
	  ;% vmrl_test_fourbar_P.Phipi_e.DeadZone_Start
	  section.data(6).logicalSrcIdx = 87;
	  section.data(6).dtTransOffset = 31;
	
	  ;% vmrl_test_fourbar_P.Phipi_e.DeadZone_End
	  section.data(7).logicalSrcIdx = 88;
	  section.data(7).dtTransOffset = 32;
	
	  ;% vmrl_test_fourbar_P.Phipi_e.Pi1_Value
	  section.data(8).logicalSrcIdx = 89;
	  section.data(8).dtTransOffset = 33;
	
	  ;% vmrl_test_fourbar_P.Phipi_e.Switch_Threshold
	  section.data(9).logicalSrcIdx = 90;
	  section.data(9).dtTransOffset = 36;
	
	  ;% vmrl_test_fourbar_P.Phipi_e.Pi_Value
	  section.data(10).logicalSrcIdx = 91;
	  section.data(10).dtTransOffset = 37;
	
	  ;% vmrl_test_fourbar_P.Phipi_e.Switch_Threshold_h
	  section.data(11).logicalSrcIdx = 92;
	  section.data(11).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_P.Generalcase_c.Constant_Value
	  section.data(1).logicalSrcIdx = 93;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vmrl_test_fourbar_P.Generalcase_c.Gain1_Gain
	  section.data(2).logicalSrcIdx = 94;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vmrl_test_fourbar_P.Generalcase_c.Gain_Gain
	  section.data(3).logicalSrcIdx = 95;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_P.Phipi_m.Shiftright_table
	  section.data(1).logicalSrcIdx = 96;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vmrl_test_fourbar_P.Phipi_m.Gain1_Gain
	  section.data(2).logicalSrcIdx = 97;
	  section.data(2).dtTransOffset = 24;
	
	  ;% vmrl_test_fourbar_P.Phipi_m.VRRot_Pi_Y0
	  section.data(3).logicalSrcIdx = 98;
	  section.data(3).dtTransOffset = 25;
	
	  ;% vmrl_test_fourbar_P.Phipi_m.Constant_Value
	  section.data(4).logicalSrcIdx = 99;
	  section.data(4).dtTransOffset = 29;
	
	  ;% vmrl_test_fourbar_P.Phipi_m.Gain_Gain
	  section.data(5).logicalSrcIdx = 100;
	  section.data(5).dtTransOffset = 30;
	
	  ;% vmrl_test_fourbar_P.Phipi_m.DeadZone_Start
	  section.data(6).logicalSrcIdx = 101;
	  section.data(6).dtTransOffset = 31;
	
	  ;% vmrl_test_fourbar_P.Phipi_m.DeadZone_End
	  section.data(7).logicalSrcIdx = 102;
	  section.data(7).dtTransOffset = 32;
	
	  ;% vmrl_test_fourbar_P.Phipi_m.Pi1_Value
	  section.data(8).logicalSrcIdx = 103;
	  section.data(8).dtTransOffset = 33;
	
	  ;% vmrl_test_fourbar_P.Phipi_m.Switch_Threshold
	  section.data(9).logicalSrcIdx = 104;
	  section.data(9).dtTransOffset = 36;
	
	  ;% vmrl_test_fourbar_P.Phipi_m.Pi_Value
	  section.data(10).logicalSrcIdx = 105;
	  section.data(10).dtTransOffset = 37;
	
	  ;% vmrl_test_fourbar_P.Phipi_m.Switch_Threshold_h
	  section.data(11).logicalSrcIdx = 106;
	  section.data(11).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_P.Generalcase.Constant_Value
	  section.data(1).logicalSrcIdx = 107;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vmrl_test_fourbar_P.Generalcase.Gain1_Gain
	  section.data(2).logicalSrcIdx = 108;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vmrl_test_fourbar_P.Generalcase.Gain_Gain
	  section.data(3).logicalSrcIdx = 109;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_P.Phipi.Shiftright_table
	  section.data(1).logicalSrcIdx = 110;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vmrl_test_fourbar_P.Phipi.Gain1_Gain
	  section.data(2).logicalSrcIdx = 111;
	  section.data(2).dtTransOffset = 24;
	
	  ;% vmrl_test_fourbar_P.Phipi.VRRot_Pi_Y0
	  section.data(3).logicalSrcIdx = 112;
	  section.data(3).dtTransOffset = 25;
	
	  ;% vmrl_test_fourbar_P.Phipi.Constant_Value
	  section.data(4).logicalSrcIdx = 113;
	  section.data(4).dtTransOffset = 29;
	
	  ;% vmrl_test_fourbar_P.Phipi.Gain_Gain
	  section.data(5).logicalSrcIdx = 114;
	  section.data(5).dtTransOffset = 30;
	
	  ;% vmrl_test_fourbar_P.Phipi.DeadZone_Start
	  section.data(6).logicalSrcIdx = 115;
	  section.data(6).dtTransOffset = 31;
	
	  ;% vmrl_test_fourbar_P.Phipi.DeadZone_End
	  section.data(7).logicalSrcIdx = 116;
	  section.data(7).dtTransOffset = 32;
	
	  ;% vmrl_test_fourbar_P.Phipi.Pi1_Value
	  section.data(8).logicalSrcIdx = 117;
	  section.data(8).dtTransOffset = 33;
	
	  ;% vmrl_test_fourbar_P.Phipi.Switch_Threshold
	  section.data(9).logicalSrcIdx = 118;
	  section.data(9).dtTransOffset = 36;
	
	  ;% vmrl_test_fourbar_P.Phipi.Pi_Value
	  section.data(10).logicalSrcIdx = 119;
	  section.data(10).dtTransOffset = 37;
	
	  ;% vmrl_test_fourbar_P.Phipi.Switch_Threshold_h
	  section.data(11).logicalSrcIdx = 120;
	  section.data(11).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
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
    ;% Auto data (vmrl_test_fourbar_B)
    ;%
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_B.Block1_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vmrl_test_fourbar_B.Block1_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 60;
	
	  ;% vmrl_test_fourbar_B.Block1_o3
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 66;
	
	  ;% vmrl_test_fourbar_B.Merge
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 67;
	
	  ;% vmrl_test_fourbar_B.gain_1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 71;
	
	  ;% vmrl_test_fourbar_B.Merge_d
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 74;
	
	  ;% vmrl_test_fourbar_B.gain_1_i
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 78;
	
	  ;% vmrl_test_fourbar_B.Merge_m
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 81;
	
	  ;% vmrl_test_fourbar_B.gain_1_b
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 85;
	
	  ;% vmrl_test_fourbar_B.Merge_g
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 88;
	
	  ;% vmrl_test_fourbar_B.gain_1_i3
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 92;
	
	  ;% vmrl_test_fourbar_B.Merge_n
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 95;
	
	  ;% vmrl_test_fourbar_B.Merge_no
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 99;
	
	  ;% vmrl_test_fourbar_B.gain_1_j
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 103;
	
	  ;% vmrl_test_fourbar_B._gravity_conversion
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 106;
	
	  ;% vmrl_test_fourbar_B.Block2
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 109;
	
	  ;% vmrl_test_fourbar_B.Block3
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 110;
	
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
    nTotSects     = 15;
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
    ;% Auto data (vmrl_test_fourbar_DWork)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_DWork.Block1_PWORK
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vmrl_test_fourbar_DWork.VRSink_PWORK
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vmrl_test_fourbar_DWork.Block2_PWORK
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 28;
	
	  ;% vmrl_test_fourbar_DWork.Block3_PWORK
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 29;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_DWork.Block1_IWORK
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vmrl_test_fourbar_DWork.Block3_IWORK
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_DWork.If_ActiveSubsystem
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% vmrl_test_fourbar_DWork.Phi0_SubsysRanBC
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
	  ;% vmrl_test_fourbar_DWork.If_ActiveSubsystem_l
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 2;
	
	  ;% vmrl_test_fourbar_DWork.Phi0_SubsysRanBC_b
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 3;
	
	  ;% vmrl_test_fourbar_DWork.If_ActiveSubsystem_i
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 4;
	
	  ;% vmrl_test_fourbar_DWork.Phi0_SubsysRanBC_n
	  section.data(6).logicalSrcIdx = 11;
	  section.data(6).dtTransOffset = 5;
	
	  ;% vmrl_test_fourbar_DWork.If_ActiveSubsystem_c
	  section.data(7).logicalSrcIdx = 12;
	  section.data(7).dtTransOffset = 6;
	
	  ;% vmrl_test_fourbar_DWork.Phi0_SubsysRanBC_g
	  section.data(8).logicalSrcIdx = 13;
	  section.data(8).dtTransOffset = 7;
	
	  ;% vmrl_test_fourbar_DWork.If_ActiveSubsystem_b
	  section.data(9).logicalSrcIdx = 14;
	  section.data(9).dtTransOffset = 8;
	
	  ;% vmrl_test_fourbar_DWork.Phi0_SubsysRanBC_l
	  section.data(10).logicalSrcIdx = 15;
	  section.data(10).dtTransOffset = 9;
	
	  ;% vmrl_test_fourbar_DWork.If_ActiveSubsystem_m
	  section.data(11).logicalSrcIdx = 16;
	  section.data(11).dtTransOffset = 10;
	
	  ;% vmrl_test_fourbar_DWork.Phi0_SubsysRanBC_d
	  section.data(12).logicalSrcIdx = 17;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_DWork.Generalcase_b.Generalcase_SubsysRanBC
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_DWork.Phipi_n.Phipi_SubsysRanBC
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_DWork.Generalcase_l.Generalcase_SubsysRanBC
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_DWork.Phipi_j.Phipi_SubsysRanBC
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_DWork.Generalcase_k.Generalcase_SubsysRanBC
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_DWork.Phipi_g.Phipi_SubsysRanBC
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_DWork.Generalcase_g.Generalcase_SubsysRanBC
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_DWork.Phipi_e.Phipi_SubsysRanBC
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_DWork.Generalcase_c.Generalcase_SubsysRanBC
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_DWork.Phipi_m.Phipi_SubsysRanBC
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_DWork.Generalcase.Generalcase_SubsysRanBC
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% vmrl_test_fourbar_DWork.Phipi.Phipi_SubsysRanBC
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
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


  targMap.checksum0 = 1116831554;
  targMap.checksum1 = 2304746241;
  targMap.checksum2 = 2941337149;
  targMap.checksum3 = 620976095;

