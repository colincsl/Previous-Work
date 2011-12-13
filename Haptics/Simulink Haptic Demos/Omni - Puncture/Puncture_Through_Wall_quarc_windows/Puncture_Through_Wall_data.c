/*
 * Puncture_Through_Wall_data.c
 *
 * Real-Time Workshop code generation for Simulink model "Puncture_Through_Wall.mdl".
 *
 * Model Version              : 1.177
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Tue Jul 21 14:20:03 2009
 */

#include "Puncture_Through_Wall.h"
#include "Puncture_Through_Wall_private.h"

/* Block parameters (auto storage) */
Parameters_Puncture_Through_Wall Puncture_Through_Wall_P = {
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

  /*  Bias1_Bias : '<S9>/Bias1'
   */
  { 0.0, -659.0, -910.0 },
  3.0679615757712823E-003,             /* Encoder_Gain : '<S9>/Encoder'
                                        */

  /*  GearRatio_Gain : '<S9>/Gear Ratio'
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

  /*  UnitDelay1_X0 : '<Root>/Unit Delay1'
   */
  { 0.0, 0.0, 0.0 },
  100.0,                               /* Stiffness_Value : '<Root>/Stiffness'
                                        */
  2.0,                                 /* BreakForce_Value : '<Root>/Break Force'
                                        */
  1.0,                                 /* UnitDelay3_X0 : '<Root>/Unit Delay3'
                                        */
  0.0,                                 /* UnitDelay2_X0 : '<Root>/Unit Delay2'
                                        */

  /*  Constant_Value : '<S4>/Constant'
   */
  { 0.0, 0.0, 0.0 },

  /*  ConverttoPositiveRotationConv_p : '<S4>/Convert to Positive Rotation Convension Used in Kinematics1'
   */
  { 1.0, -1.0, -1.0 },

  /*  GearRatio1_Gain : '<S12>/Gear Ratio1'
   */
  { 1.3403029084573112E-001, -1.3299640909695437E-001, 1.3281976358082082E-001 },
  2.5956496911176870E+001,             /* Kt_Gain : '<S12>/Kt'
                                        */
  1.6,                                 /* Saturation_UpperSat : '<S12>/Saturation'
                                        */
  -1.6,                                /* Saturation_LowerSat : '<S12>/Saturation'
                                        */
  1.0,                                 /* Constant1_Value : '<Root>/Constant1'
                                        */
  0.64,                                /* SliderGain_Gain : '<S6>/Slider Gain'
                                        */

  /*  Constant4_Value : '<S2>/Constant4'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Switch_Threshold : '<S2>/Switch'
                                        */

  /*  Constant1_Value_e : '<S5>/Constant1'
   */
  { 0.0, 0.0, 0.0 },
  0.01,                                /* Constant3_Value : '<S5>/Constant3'
                                        */
  0.0,                                 /* Switch1_Threshold : '<S5>/Switch1'
                                        */

  /*  Gain_Gain : '<Root>/Gain'
   */
  { 3.0, 1.0, 1.0 },

  /*  Constant3_Value_p : '<Root>/Constant3'
   */
  { 0.005, 0.25, 0.2 },
  1.0,                                 /* Constant3_Value_c : '<S2>/Constant3'
                                        */
  0.1,                                 /* SliderGain_Gain_i : '<S7>/Slider Gain'
                                        */

  /*  Constant5_Value : '<S2>/Constant5'
   */
  { 0.04, 0.7 },
  1.0,                                 /* Constant1_Value_j : '<S2>/Constant1'
                                        */
  0.1,                                 /* SliderGain_Gain_e : '<S8>/Slider Gain'
                                        */

  /*  Constant2_Value : '<S2>/Constant2'
   */
  { 0.04, 0.7 },
  -1.0,                                /* Constant4_Value_i : '<S5>/Constant4'
                                        */
  1.0,                                 /* Constant2_Value_m : '<S5>/Constant2'
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
