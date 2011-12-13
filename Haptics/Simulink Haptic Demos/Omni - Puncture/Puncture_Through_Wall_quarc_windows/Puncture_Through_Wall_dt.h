/*
 * Puncture_Through_Wall_dt.h
 *
 * Real-Time Workshop code generation for Simulink model "Puncture_Through_Wall.mdl".
 *
 * Model Version              : 1.177
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Tue Jul 21 14:20:03 2009
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_card),
  sizeof(t_task)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_card",
  "t_task"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Puncture_Through_Wall_B.GearRatio[0]), 0, 0, 93 }
  ,

  { (char_T *)(&Puncture_Through_Wall_DWork.UnitDelay1_DSTATE[0]), 0, 0, 18 },

  { (char_T *)(&Puncture_Through_Wall_DWork.HILWritePWM_PWORK), 11, 0, 13 },

  { (char_T *)(&Puncture_Through_Wall_DWork.HILInitialize_QuadratureModes[0]), 6,
    0, 12 },

  { (char_T *)(&Puncture_Through_Wall_DWork.HILInitialize_POSortedChans[0]), 7,
    0, 3 },

  { (char_T *)(&Puncture_Through_Wall_DWork.HILInitialize_Card), 14, 0, 1 },

  { (char_T *)(&Puncture_Through_Wall_DWork.HILReadEncoderTimebase_Task), 15, 0,
    1 },

  { (char_T *)(&Puncture_Through_Wall_DWork.is_active_c3_Puncture_Through_W), 3,
    0, 5 },

  { (char_T *)(&Puncture_Through_Wall_DWork.doneDoubleBufferReInit), 8, 0, 5 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  9U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Puncture_Through_Wall_P.HILInitialize_OOStart), 0, 0, 86 },

  { (char_T *)(&Puncture_Through_Wall_P.HILInitialize_DOWatchdog), 6, 0, 3 },

  { (char_T *)(&Puncture_Through_Wall_P.HILInitialize_AIChannels[0]), 7, 0, 18 },

  { (char_T *)(&Puncture_Through_Wall_P.HILInitialize_Active), 8, 0, 32 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  4U,
  rtPTransitions
};

/* [EOF] Puncture_Through_Wall_dt.h */
