/*
 * omni_interface_data.c
 *
 * Real-Time Workshop code generation for Simulink model "omni_interface.mdl".
 *
 * Model Version              : 1.22
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Mon Jun 15 11:31:32 2009
 */

#include "omni_interface.h"
#include "omni_interface_private.h"

/* Block parameters (auto storage) */
Parameters_omni_interface omni_interface_P = {
  0.0,                                 /* HILInitialize_OOStart : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOEnter : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOTerminate : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOExit : '<Root>/HIL Initialize'
                                        */
  10.0,                                /* HILInitialize_AIHigh : '<Root>/HIL Initialize'
                                        */
  -10.0,                               /* HILInitialize_AILow : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POInitial : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POFinal : '<Root>/HIL Initialize'
                                        */

  /*  Bias3_Bias : '<Root>/Bias3'
   */
  { -36.0, 1591.0, -2731.0 },
  3.0679615757712823E-003,             /* Gain1_Gain : '<Root>/Gain1'
                                        */

  /*  GearRatio_Gain : '<Root>/Gear Ratio'
   */
  { 1.3403029084573112E-001, -1.3299640909695437E-001, 1.3281976358082082E-001 },
  5.7295779513082323E+001,             /* Gain2_Gain : '<Root>/Gain2'
                                        */
  0.0,                                 /* FixPtUnitDelay1_X0 : '<S8>/FixPt Unit Delay1'
                                        */
  0.0,                                 /* FixPtUnitDelay1_X0_d : '<S9>/FixPt Unit Delay1'
                                        */
  0.0,                                 /* FixPtUnitDelay1_X0_p : '<S10>/FixPt Unit Delay1'
                                        */
  0.0,                                 /* FixPtUnitDelay1_X0_j : '<S11>/FixPt Unit Delay1'
                                        */
  0.0,                                 /* FixPtUnitDelay1_X0_j0 : '<S12>/FixPt Unit Delay1'
                                        */
  0.0,                                 /* FixPtUnitDelay1_X0_d1 : '<S13>/FixPt Unit Delay1'
                                        */

  /*  Gain_Gain : '<Root>/Gain'
   */
  { 1.0, 1.0, 1.0 },
  1.0,                                 /* Saturation_UpperSat : '<Root>/Saturation'
                                        */
  -1.0,                                /* Saturation_LowerSat : '<Root>/Saturation'
                                        */
  0.0,                                 /* InitialCondition_Value : '<S8>/Initial Condition'
                                        */
  0.0,                                 /* InitialCondition_Value_d : '<S9>/Initial Condition'
                                        */
  0.0,                                 /* InitialCondition_Value_g : '<S10>/Initial Condition'
                                        */
  0.0,                                 /* InitialCondition_Value_gd : '<S11>/Initial Condition'
                                        */
  0.0,                                 /* InitialCondition_Value_m : '<S12>/Initial Condition'
                                        */
  0.0,                                 /* InitialCondition_Value_f : '<S13>/Initial Condition'
                                        */
  0,                                   /* HILInitialize_EIInitial : '<Root>/HIL Initialize'
                                        */
  8000,                                /* StreamAnswer_SendBufferSize : '<Root>/Stream Answer'
                                        */
  8000,                                /* StreamAnswer_ReceiveBufferSize : '<Root>/Stream Answer'
                                        */
  8000,                                /* StreamAnswer1_SendBufferSize : '<Root>/Stream Answer1'
                                        */
  8000,                                /* StreamAnswer1_ReceiveBufferSize : '<Root>/Stream Answer1'
                                        */

  /*  HILInitialize_AIChannels : '<Root>/HIL Initialize'
   */
  { 0U, 1U },

  /*  HILInitialize_EIChannels : '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U },

  /*  HILInitialize_POChannels : '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U },

  /*  HILRead_AnalogChannels : '<Root>/HIL Read'
   */
  { 0U, 1U, 2U },

  /*  HILRead_EncoderChannels : '<Root>/HIL Read'
   */
  { 0U, 1U, 2U },

  /*  HILRead_DigitalChannels : '<Root>/HIL Read'
   */
  { 0U, 1U },

  /*  HILWrite_PWMChannels : '<Root>/HIL Write'
   */
  { 0U, 1U, 2U },
  1,                                   /* StreamAnswer_Endian : '<Root>/Stream Answer'
                                        */
  1,                                   /* StreamAnswer1_Endian : '<Root>/Stream Answer1'
                                        */
  1,                                   /* HILInitialize_Active : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_CKPStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_CKPEnter : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AIPStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AIPEnter : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOPStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOPEnter : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOEnter : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOTerminate : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOExit : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOReset : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOEnter : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOTerminate : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOExit : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOReset : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIPStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIPEnter : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIEnter : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POPStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POPEnter : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POEnter : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POTerminate : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POExit : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POReset : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_OOReset : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILRead_Active : '<Root>/HIL Read'
                                        */
  0,                                   /* StreamAnswer_Active : '<Root>/Stream Answer'
                                        */
  0,                                   /* StreamAnswer1_Active : '<Root>/Stream Answer1'
                                        */
  0                                    /* HILWrite_Active : '<Root>/HIL Write'
                                        */
};
