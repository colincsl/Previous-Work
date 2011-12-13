/*
 * Force_Rendering_data.c
 *
 * Real-Time Workshop code generation for Simulink model "Force_Rendering.mdl".
 *
 * Model Version              : 1.35
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Tue Jul 21 13:58:05 2009
 */

#include "Force_Rendering.h"
#include "Force_Rendering_private.h"

/* Block parameters (auto storage) */
Parameters_Force_Rendering Force_Rendering_P = {
  0.0,                                 /* HILInitialize_OOStart : '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOEnter : '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOTerminate : '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOExit : '<S1>/HIL Initialize'
                                        */
  10.0,                                /* HILInitialize_AIHigh : '<S1>/HIL Initialize'
                                        */
  -10.0,                               /* HILInitialize_AILow : '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_AOWatchdog : '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POInitial : '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POFinal : '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POWatchdog : '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOWatchdog : '<S1>/HIL Initialize'
                                        */

  /*  Bias1_Bias : '<S3>/Bias1'
   */
  { 0.0, -659.0, -910.0 },
  3.0679615757712823E-003,             /* Encoder_Gain : '<S3>/Encoder'
                                        */

  /*  GearRatio_Gain : '<S3>/Gear Ratio'
   */
  { 1.3403029084573112E-001, -1.3299640909695437E-001, 1.3281976358082082E-001 },

  /*  ConverttoPositiveRotationConven : '<S1>/Convert to Positive Rotation Convension Used in Kinematics'
   */
  { 1.0, -1.0, -1.0 },

  /*  JointOffsets_Bias : '<S1>/Joint Offsets'
   */
  { 0.0, 0.0, 1.5707963267948966E+000 },

  /*  ToolOffset2_Value : '<S1>/Tool Offset2'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.039,
    1.0 },

  /*  Force_Value : '<Root>/Force'
   */
  { 1.0, 0.0, 0.0 },
  1.8,                                 /* SliderGain_Gain : '<S2>/Slider Gain'
                                        */

  /*  Constant_Value : '<S1>/Constant'
   */
  { 0.0, 0.0, 0.0 },

  /*  ConverttoPositiveRotationConv_e : '<S1>/Convert to Positive Rotation Convension Used in Kinematics1'
   */
  { 1.0, -1.0, -1.0 },

  /*  GearRatio1_Gain : '<S6>/Gear Ratio1'
   */
  { 1.3403029084573112E-001, -1.3299640909695437E-001, 1.3281976358082082E-001 },
  2.5956496911176870E+001,             /* Kt_Gain : '<S6>/Kt'
                                        */
  1.6,                                 /* Saturation_UpperSat : '<S6>/Saturation'
                                        */
  -1.6,                                /* Saturation_LowerSat : '<S6>/Saturation'
                                        */

  /*  Bias1_Bias_k : '<S5>/Bias1'
   */
  { -2048.0, -2654.0, -2048.0 },

  /*  Gain2_Gain : '<S5>/Gain2'
   */
  { 1.2783693402196514E-003, 1.5339807878856412E-003, 1.2783693402196514E-003 },

  /*  ConverttoPositiveRotationConv_c : '<S1>/Convert to Positive Rotation Convension Used in Kinematics2'
   */
  { -1.0, 1.0, 1.0 },

  /*  JointOffsets1_Bias : '<S1>/Joint Offsets1'
   */
  { 0.0, 2.4434609527920612E+000, 0.0 },
  1000.0,                              /* metertomilimeter_Gain : '<Root>/meter to milimeter'
                                        */
  5.7295779513082323E+001,             /* radiantodegree1_Gain : '<Root>/radian to degree1'
                                        */
  5.7295779513082323E+001,             /* radiantodegree_Gain : '<Root>/radian to degree'
                                        */
  0,                                   /* HILInitialize_DOWatchdog : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIInitial : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILReadEncoderTimebase_Clock : '<S1>/HIL Read Encoder Timebase'
                                        */

  /*  HILInitialize_AIChannels : '<S1>/HIL Initialize'
   */
  { 0U, 1U },

  /*  HILInitialize_EIChannels : '<S1>/HIL Initialize'
   */
  { 0U, 1U, 2U },

  /*  HILInitialize_POChannels : '<S1>/HIL Initialize'
   */
  { 0U, 1U, 2U },

  /*  HILReadEncoderTimebase_Channels : '<S1>/HIL Read Encoder Timebase'
   */
  { 0U, 1U, 2U },
  1000U,                               /* HILReadEncoderTimebase_SamplesI : '<S1>/HIL Read Encoder Timebase'
                                        */

  /*  HILWritePWM_Channels : '<S1>/HIL Write PWM'
   */
  { 0U, 1U, 2U },

  /*  HILReadAnalog_Channels : '<S1>/HIL Read Analog'
   */
  { 0U, 1U, 2U },
  1,                                   /* HILInitialize_Active : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_CKPStart : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_CKPEnter : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AIPStart : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AIPEnter : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOPStart : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOPEnter : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOStart : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOEnter : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOTerminate : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOExit : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOReset : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOStart : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOEnter : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOTerminate : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOExit : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOReset : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIPStart : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIPEnter : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIStart : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIEnter : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POPStart : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POPEnter : '<S1>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POStart : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POEnter : '<S1>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POTerminate : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POExit : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POReset : '<S1>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_OOReset : '<S1>/HIL Initialize'
                                        */
  1,                                   /* HILReadEncoderTimebase_Active : '<S1>/HIL Read Encoder Timebase'
                                        */
  0,                                   /* HILWritePWM_Active : '<S1>/HIL Write PWM'
                                        */
  1                                    /* HILReadAnalog_Active : '<S1>/HIL Read Analog'
                                        */
};
