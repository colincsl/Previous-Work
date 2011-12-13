/*
 * Pong_data.c
 *
 * Real-Time Workshop code generation for Simulink model "Pong.mdl".
 *
 * Model Version              : 1.299
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Tue Jul 21 14:15:33 2009
 */

#include "Pong.h"
#include "Pong_private.h"

/* Block parameters (auto storage) */
Parameters_Pong Pong_P = {
  0.0,                                 /* HILInitialize_OOStart : '<S4>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOEnter : '<S4>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOTerminate : '<S4>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOExit : '<S4>/HIL Initialize'
                                        */
  10.0,                                /* HILInitialize_AIHigh : '<S4>/HIL Initialize'
                                        */
  -10.0,                               /* HILInitialize_AILow : '<S4>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_AOWatchdog : '<S4>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POInitial : '<S4>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POFinal : '<S4>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POWatchdog : '<S4>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOWatchdog : '<S4>/HIL Initialize'
                                        */

  /*  Bias1_Bias : '<S25>/Bias1'
   */
  { 0.0, -659.0, -910.0 },
  3.0679615757712823E-003,             /* Encoder_Gain : '<S25>/Encoder'
                                        */

  /*  GearRatio_Gain : '<S25>/Gear Ratio'
   */
  { 1.3403029084573112E-001, -1.3299640909695437E-001, 1.3281976358082082E-001 },

  /*  ConverttoPositiveRotationConven : '<S4>/Convert to Positive Rotation Convension Used in Kinematics'
   */
  { 1.0, -1.0, -1.0 },

  /*  JointOffsets_Bias : '<S4>/Joint Offsets'
   */
  { 0.0, 0.0, 1.5707963267948966E+000 },

  /*  ToolOffset2_Value : '<S4>/Tool Offset2'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.039,
    1.0 },
  0.0,                                 /* Constant12_Value : '<Root>/Constant12'
                                        */
  0.0,                                 /* Integrator3_IC : '<S1>/Integrator3'
                                        */
  200.0,                               /* Wn_Value : '<S14>/Wn'
                                        */
  0.0,                                 /* Integrator_IC : '<S15>/Integrator'
                                        */
  0.0,                                 /* Constant_Value : '<S13>/Constant'
                                        */
  0.0,                                 /* Integrator1_IC : '<S1>/Integrator1'
                                        */
  0.02,                                /* Constant2_Value : '<S6>/Constant2'
                                        */
  0.005,                               /* Constant6_Value : '<S6>/Constant6'
                                        */
  0.0,                                 /* Constant_Value_n : '<S16>/Constant'
                                        */
  0.1,                                 /* Constant4_Value : '<S6>/Constant4'
                                        */
  0.0,                                 /* noncontactForce4_Value : '<S7>/non contact Force4'
                                        */
  200.0,                               /* Wn_Value_j : '<S17>/Wn'
                                        */
  0.0,                                 /* Integrator_IC_i : '<S18>/Integrator'
                                        */
  0.0,                                 /* noncontactForce_Value : '<S8>/non contact Force'
                                        */

  /*  Constant10_Value : '<Root>/Constant10'
   */
  { 0.0, 0.0, 0.0 },

  /*  Constant_Value_g : '<S4>/Constant'
   */
  { 0.0, 0.0, 0.0 },

  /*  ConverttoPositiveRotationConv_d : '<S4>/Convert to Positive Rotation Convension Used in Kinematics1'
   */
  { 1.0, -1.0, -1.0 },

  /*  GearRatio1_Gain : '<S28>/Gear Ratio1'
   */
  { 1.3403029084573112E-001, -1.3299640909695437E-001, 1.3281976358082082E-001 },
  2.5956496911176870E+001,             /* Kt_Gain : '<S28>/Kt'
                                        */
  1.6,                                 /* Saturation_UpperSat : '<S28>/Saturation'
                                        */
  -1.6,                                /* Saturation_LowerSat : '<S28>/Saturation'
                                        */
  2.0,                                 /* Constant_Value_nt : '<S15>/Constant'
                                        */
  1.0,                                 /* z_Value : '<S14>/z'
                                        */
  -1.0,                                /* Gain3_Gain : '<S1>/Gain3'
                                        */
  0.2,                                 /* Constant3_Value : '<S6>/Constant3'
                                        */
  -1.0,                                /* Gain4_Gain : '<S1>/Gain4'
                                        */
  0.0,                                 /* Integrator2_IC : '<S1>/Integrator2'
                                        */
  2.0,                                 /* Constant_Value_p : '<S20>/Constant'
                                        */
  0.0,                                 /* Integrator_IC_n : '<S20>/Integrator'
                                        */
  200.0,                               /* Wn_Value_ju : '<S19>/Wn'
                                        */
  1.0,                                 /* z_Value_a : '<S19>/z'
                                        */
  0.0,                                 /* noncontactForce2_Value : '<S9>/non contact Force2'
                                        */
  0.0,                                 /* Switch2_Threshold : '<S9>/Switch2'
                                        */
  2.0,                                 /* Constant_Value_n2 : '<S22>/Constant'
                                        */
  0.0,                                 /* Integrator_IC_o : '<S22>/Integrator'
                                        */
  200.0,                               /* Wn_Value_e : '<S21>/Wn'
                                        */
  1.0,                                 /* z_Value_f : '<S21>/z'
                                        */
  0.0,                                 /* noncontactForce3_Value : '<S10>/non contact Force3'
                                        */
  0.0,                                 /* Switch3_Threshold : '<S10>/Switch3'
                                        */
  2.0,                                 /* TransferFcn1_D : '<S1>/Transfer Fcn1'
                                        */
  -0.25,                               /* Gravity_Value : '<S1>/Gravity'
                                        */
  0.0,                                 /* Integrator_IC_c : '<S1>/Integrator'
                                        */
  2.0,                                 /* Constant_Value_o : '<S18>/Constant'
                                        */
  1.0,                                 /* z_Value_j : '<S17>/z'
                                        */
  2.0,                                 /* Constant_Value_o1 : '<S24>/Constant'
                                        */
  0.0,                                 /* Integrator_IC_h : '<S24>/Integrator'
                                        */

  /*  Constant9_Value : '<S6>/Constant9'
   */
  { 0.0, 0.11, 0.0 },
  200.0,                               /* Wn_Value_h : '<S23>/Wn'
                                        */
  1.0,                                 /* z_Value_h : '<S23>/z'
                                        */
  0.0,                                 /* noncontactForce1_Value : '<S11>/non contact Force1'
                                        */
  0.0,                                 /* Switch1_Threshold : '<S11>/Switch1'
                                        */
  2.0,                                 /* TransferFcn_D : '<S1>/Transfer Fcn'
                                        */
  0.0,                                 /* Constant7_Value : '<Root>/Constant7'
                                        */
  0.0,                                 /* zpositionofball_Value : '<Root>/z position of ball'
                                        */
  -1.0,                                /* Constant1_Value : '<S5>/Constant1'
                                        */
  0.02,                                /* Constant5_Value : '<S5>/Constant5'
                                        */
  1.0,                                 /* Constant2_Value_f : '<S35>/Constant2'
                                        */
  0.03,                                /* Constant1_Value_f : '<S35>/Constant1'
                                        */
  0.0,                                 /* Constant10_Value_k : '<S35>/Constant10'
                                        */
  0.0,                                 /* Constant11_Value : '<S6>/Constant11'
                                        */
  2.0,                                 /* Gain1_Gain : '<S14>/Gain1'
                                        */
  0.0,                                 /* Gain3_Gain_i : '<S14>/Gain3'
                                        */
  0.01,                                /* Gain1_Gain_a : '<S17>/Gain1'
                                        */
  500.0,                               /* Gain3_Gain_ij : '<S17>/Gain3'
                                        */
  500.0,                               /* Gain3_Gain_c : '<S19>/Gain3'
                                        */
  0.01,                                /* Gain1_Gain_g : '<S19>/Gain1'
                                        */
  500.0,                               /* Gain3_Gain_cs : '<S21>/Gain3'
                                        */
  0.01,                                /* Gain1_Gain_h : '<S21>/Gain1'
                                        */
  500.0,                               /* Gain3_Gain_d : '<S23>/Gain3'
                                        */
  0.01,                                /* Gain1_Gain_a1 : '<S23>/Gain1'
                                        */
  -1.0,                                /* Gain1_Gain_l : '<S1>/Gain1'
                                        */
  0,                                   /* HILInitialize_DOWatchdog : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIInitial : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILReadEncoderTimebase_Clock : '<S4>/HIL Read Encoder Timebase'
                                        */

  /*  HILInitialize_AIChannels : '<S4>/HIL Initialize'
   */
  { 0U, 1U },

  /*  HILInitialize_EIChannels : '<S4>/HIL Initialize'
   */
  { 0U, 1U, 2U },

  /*  HILInitialize_POChannels : '<S4>/HIL Initialize'
   */
  { 0U, 1U, 2U },

  /*  HILReadEncoderTimebase_Channels : '<S4>/HIL Read Encoder Timebase'
   */
  { 0U, 1U, 2U },
  1000U,                               /* HILReadEncoderTimebase_SamplesI : '<S4>/HIL Read Encoder Timebase'
                                        */

  /*  HILWritePWM_Channels : '<S4>/HIL Write PWM'
   */
  { 0U, 1U, 2U },

  /*  HILReadAnalog_Channels : '<S4>/HIL Read Analog'
   */
  { 0U, 1U, 2U },
  1U,                                  /* Constant_Value_k : '<S3>/Constant'
                                        */
  0U,                                  /* SwitchControl_Threshold : '<S3>/SwitchControl'
                                        */
  1U,                                  /* Constant_Value_i : '<S34>/Constant'
                                        */
  0U,                                  /* SwitchControl_Threshold_k : '<S34>/SwitchControl'
                                        */
  1,                                   /* HILInitialize_Active : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_CKPStart : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_CKPEnter : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AIPStart : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AIPEnter : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOPStart : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOPEnter : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOStart : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOEnter : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOTerminate : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOExit : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOReset : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOStart : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOEnter : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOTerminate : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOExit : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOReset : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIPStart : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIPEnter : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIStart : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIEnter : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POPStart : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POPEnter : '<S4>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POStart : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POEnter : '<S4>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POTerminate : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POExit : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POReset : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_OOReset : '<S4>/HIL Initialize'
                                        */
  1,                                   /* HILReadEncoderTimebase_Active : '<S4>/HIL Read Encoder Timebase'
                                        */
  0,                                   /* HILWritePWM_Active : '<S4>/HIL Write PWM'
                                        */
  1                                    /* HILReadAnalog_Active : '<S4>/HIL Read Analog'
                                        */
};
