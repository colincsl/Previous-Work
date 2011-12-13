/*
 * Gravity_Well_data.c
 *
 * Real-Time Workshop code generation for Simulink model "Gravity_Well.mdl".
 *
 * Model Version              : 1.201
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Tue Jul 21 14:08:06 2009
 */

#include "Gravity_Well.h"
#include "Gravity_Well_private.h"

/* Block parameters (auto storage) */
Parameters_Gravity_Well Gravity_Well_P = {
  0.0,                                 /* HILInitialize_OOStart : '<S2>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOEnter : '<S2>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOTerminate : '<S2>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOExit : '<S2>/HIL Initialize'
                                        */
  10.0,                                /* HILInitialize_AIHigh : '<S2>/HIL Initialize'
                                        */
  -10.0,                               /* HILInitialize_AILow : '<S2>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_AOWatchdog : '<S2>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POInitial : '<S2>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POFinal : '<S2>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POWatchdog : '<S2>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOWatchdog : '<S2>/HIL Initialize'
                                        */

  /*  Bias1_Bias : '<S5>/Bias1'
   */
  { 0.0, -659.0, -910.0 },
  3.0679615757712823E-003,             /* Encoder_Gain : '<S5>/Encoder'
                                        */

  /*  GearRatio_Gain : '<S5>/Gear Ratio'
   */
  { 1.3403029084573112E-001, -1.3299640909695437E-001, 1.3281976358082082E-001 },

  /*  ConverttoPositiveRotationConven : '<S2>/Convert to Positive Rotation Convension Used in Kinematics'
   */
  { 1.0, -1.0, -1.0 },

  /*  JointOffsets_Bias : '<S2>/Joint Offsets'
   */
  { 0.0, 0.0, 1.5707963267948966E+000 },

  /*  ToolOffset2_Value : '<S2>/Tool Offset2'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.039,
    1.0 },

  /*  Constant1_Value : '<S3>/Constant1'
   */
  { 0.0, 0.0, 0.0 },
  0.15,                                /* Posz_Value : '<S3>/Posz'
                                        */
  -0.08,                               /* Posx_Value : '<S3>/Posx'
                                        */
  0.0,                                 /* Posy_Value : '<S3>/Posy'
                                        */
  150.0,                               /* Stiffness_Gain : '<S3>/Stiffness'
                                        */
  200.0,                               /* Constant2_Value : '<S3>/Constant2'
                                        */
  0.0,                                 /* Integrator_IC : '<S12>/Integrator'
                                        */
  0.01,                                /* Damping_Value : '<S3>/Damping'
                                        */
  0.03,                                /* Compare_Threshold : '<S3>/Compare'
                                        */

  /*  Constant1_Value_p : '<S4>/Constant1'
   */
  { 0.0, 0.0, 0.0 },
  0.1,                                 /* Posz_Value_i : '<S4>/Posz'
                                        */
  0.05,                                /* Posx_Value_p : '<S4>/Posx'
                                        */
  0.0,                                 /* Posy_Value_o : '<S4>/Posy'
                                        */
  100.0,                               /* Stiffness_Gain_h : '<S4>/Stiffness'
                                        */
  200.0,                               /* Constant2_Value_l : '<S4>/Constant2'
                                        */
  0.0,                                 /* Integrator_IC_i : '<S15>/Integrator'
                                        */
  0.01,                                /* Damping_Value_k : '<S4>/Damping'
                                        */
  0.02,                                /* Compare_Threshold_c : '<S4>/Compare'
                                        */

  /*  Constant_Value : '<S2>/Constant'
   */
  { 0.0, 0.0, 0.0 },

  /*  ConverttoPositiveRotationConv_k : '<S2>/Convert to Positive Rotation Convension Used in Kinematics1'
   */
  { 1.0, -1.0, -1.0 },

  /*  GearRatio1_Gain : '<S8>/Gear Ratio1'
   */
  { 1.3403029084573112E-001, -1.3299640909695437E-001, 1.3281976358082082E-001 },
  2.5956496911176870E+001,             /* Kt_Gain : '<S8>/Kt'
                                        */
  1.6,                                 /* Saturation_UpperSat : '<S8>/Saturation'
                                        */
  -1.6,                                /* Saturation_LowerSat : '<S8>/Saturation'
                                        */
  2.0,                                 /* Constant_Value_c : '<S12>/Constant'
                                        */
  1.0,                                 /* z1_Value : '<S3>/z1'
                                        */
  2.0,                                 /* Constant_Value_n : '<S15>/Constant'
                                        */
  1.0,                                 /* z1_Value_h : '<S4>/z1'
                                        */
  0,                                   /* HILInitialize_DOWatchdog : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIInitial : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILReadEncoderTimebase_Clock : '<S2>/HIL Read Encoder Timebase'
                                        */

  /*  HILInitialize_AIChannels : '<S2>/HIL Initialize'
   */
  { 0U, 1U },

  /*  HILInitialize_EIChannels : '<S2>/HIL Initialize'
   */
  { 0U, 1U, 2U },

  /*  HILInitialize_POChannels : '<S2>/HIL Initialize'
   */
  { 0U, 1U, 2U },

  /*  HILReadEncoderTimebase_Channels : '<S2>/HIL Read Encoder Timebase'
   */
  { 0U, 1U, 2U },
  1000U,                               /* HILReadEncoderTimebase_SamplesI : '<S2>/HIL Read Encoder Timebase'
                                        */

  /*  HILWritePWM_Channels : '<S2>/HIL Write PWM'
   */
  { 0U, 1U, 2U },

  /*  HILReadAnalog_Channels : '<S2>/HIL Read Analog'
   */
  { 0U, 1U, 2U },
  1,                                   /* HILInitialize_Active : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_CKPStart : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_CKPEnter : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AIPStart : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AIPEnter : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOPStart : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOPEnter : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOStart : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOEnter : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOTerminate : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOExit : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOReset : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOStart : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOEnter : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOTerminate : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOExit : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOReset : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIPStart : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIPEnter : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIStart : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIEnter : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POPStart : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POPEnter : '<S2>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POStart : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POEnter : '<S2>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POTerminate : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POExit : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POReset : '<S2>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_OOReset : '<S2>/HIL Initialize'
                                        */
  1,                                   /* HILReadEncoderTimebase_Active : '<S2>/HIL Read Encoder Timebase'
                                        */
  0,                                   /* HILWritePWM_Active : '<S2>/HIL Write PWM'
                                        */
  1                                    /* HILReadAnalog_Active : '<S2>/HIL Read Analog'
                                        */
};
