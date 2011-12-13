/*
 * Joint_Control_data.c
 *
 * Real-Time Workshop code generation for Simulink model "Joint_Control.mdl".
 *
 * Model Version              : 1.29
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Tue Jul 21 14:12:36 2009
 */

#include "Joint_Control.h"
#include "Joint_Control_private.h"

/* Block parameters (auto storage) */
Parameters_Joint_Control Joint_Control_P = {
  0.0,                                 /* HILInitialize_OOStart : '<S7>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOEnter : '<S7>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOTerminate : '<S7>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOExit : '<S7>/HIL Initialize'
                                        */
  10.0,                                /* HILInitialize_AIHigh : '<S7>/HIL Initialize'
                                        */
  -10.0,                               /* HILInitialize_AILow : '<S7>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_AOWatchdog : '<S7>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POInitial : '<S7>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POFinal : '<S7>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POWatchdog : '<S7>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOWatchdog : '<S7>/HIL Initialize'
                                        */
  1.0,                                 /* Kpq1_Value : '<Root>/Kp q1'
                                        */
  1.79,                                /* SliderGain_Gain : '<S1>/Slider Gain'
                                        */
  1.0,                                 /* Kpq2_Value : '<Root>/Kp q2'
                                        */
  2.25,                                /* SliderGain_Gain_f : '<S2>/Slider Gain'
                                        */
  1.0,                                 /* Kpq3_Value : '<Root>/Kp q3'
                                        */
  0.647,                               /* SliderGain_Gain_ff : '<S3>/Slider Gain'
                                        */

  /*  Saturation_UpperSat : '<S7>/Saturation'
   */
  { 2.0, 2.0, 1.0 },

  /*  Saturation_LowerSat : '<S7>/Saturation'
   */
  { 0.0, 0.0, 0.0 },

  /*  SignalGenerator_Amplitude : '<Root>/Signal Generator'
   */
  { 1.7453292519943295E-001, 0.0, 0.0 },
  0.5,                                 /* SignalGenerator_Frequency : '<Root>/Signal Generator'
                                        */

  /*  Bias1_Bias : '<S8>/Bias1'
   */
  { 0.0, -659.0, -910.0 },
  3.0679615757712823E-003,             /* Encoder_Gain : '<S8>/Encoder'
                                        */

  /*  GearRatio_Gain : '<S8>/Gear Ratio'
   */
  { 1.3403029084573112E-001, -1.3299640909695437E-001, 1.3281976358082082E-001 },

  /*  ConverttoPositiveRotationConven : '<S7>/Convert to Positive Rotation Convension Used in Kinematics1'
   */
  { 1.0, -1.0, -1.0 },

  /*  JointOffsets_Bias : '<S7>/Joint Offsets'
   */
  { 0.0, 0.0, 1.5707963267948966E+000 },
  200.0,                               /* Wn_Value : '<S7>/Wn'
                                        */
  0.0,                                 /* Integrator_IC : '<S13>/Integrator'
                                        */
  1.0,                                 /* Kvq1_Value : '<Root>/Kv q1'
                                        */
  0.06,                                /* SliderGain_Gain_g : '<S4>/Slider Gain'
                                        */
  1.0,                                 /* Kvq2_Value : '<Root>/Kv q2'
                                        */
  0.021,                               /* SliderGain_Gain_i : '<S5>/Slider Gain'
                                        */
  1.0,                                 /* Kvq3_Value : '<Root>/Kv q3'
                                        */
  0.0105,                              /* SliderGain_Gain_h : '<S6>/Slider Gain'
                                        */

  /*  Saturation1_UpperSat : '<S7>/Saturation1'
   */
  { 0.1, 0.1, 0.025 },

  /*  Saturation1_LowerSat : '<S7>/Saturation1'
   */
  { 0.02, 0.02, 0.0 },

  /*  ConverttoPositiveRotationConv_k : '<S7>/Convert to Positive Rotation Convension Used in Kinematics2'
   */
  { 1.0, -1.0, -1.0 },

  /*  GearRatio1_Gain : '<S10>/Gear Ratio1'
   */
  { 1.3403029084573112E-001, -1.3299640909695437E-001, 1.3281976358082082E-001 },
  2.5956496911176870E+001,             /* Kt_Gain : '<S10>/Kt'
                                        */
  1.6,                                 /* Saturation_UpperSat_a : '<S10>/Saturation'
                                        */
  -1.6,                                /* Saturation_LowerSat_l : '<S10>/Saturation'
                                        */
  2.0,                                 /* Constant_Value : '<S13>/Constant'
                                        */
  1.0,                                 /* z_Value : '<S9>/z'
                                        */
  0,                                   /* HILInitialize_DOWatchdog : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIInitial : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILReadEncoderTimebase_Clock : '<S7>/HIL Read Encoder Timebase'
                                        */

  /*  HILInitialize_AIChannels : '<S7>/HIL Initialize'
   */
  { 0U, 1U },

  /*  HILInitialize_EIChannels : '<S7>/HIL Initialize'
   */
  { 0U, 1U, 2U },

  /*  HILInitialize_POChannels : '<S7>/HIL Initialize'
   */
  { 0U, 1U, 2U },

  /*  HILReadEncoderTimebase_Channels : '<S7>/HIL Read Encoder Timebase'
   */
  { 0U, 1U, 2U },
  1000U,                               /* HILReadEncoderTimebase_SamplesI : '<S7>/HIL Read Encoder Timebase'
                                        */

  /*  HILWritePWM_Channels : '<S7>/HIL Write PWM'
   */
  { 0U, 1U, 2U },
  1,                                   /* HILInitialize_Active : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_CKPStart : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_CKPEnter : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AIPStart : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AIPEnter : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOPStart : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOPEnter : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOStart : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOEnter : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOTerminate : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOExit : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOReset : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOStart : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOEnter : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOTerminate : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOExit : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOReset : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIPStart : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIPEnter : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIStart : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIEnter : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POPStart : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POPEnter : '<S7>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POStart : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POEnter : '<S7>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POTerminate : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POExit : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POReset : '<S7>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_OOReset : '<S7>/HIL Initialize'
                                        */
  1,                                   /* HILReadEncoderTimebase_Active : '<S7>/HIL Read Encoder Timebase'
                                        */
  0                                    /* HILWritePWM_Active : '<S7>/HIL Write PWM'
                                        */
};
