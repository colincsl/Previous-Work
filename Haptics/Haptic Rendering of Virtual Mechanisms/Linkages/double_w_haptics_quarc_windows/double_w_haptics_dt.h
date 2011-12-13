/*
 * double_w_haptics_dt.h
 *
 * Real-Time Workshop code generation for Simulink model "double_w_haptics.mdl".
 *
 * Model Version              : 1.132
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Tue Jul 21 16:32:36 2009
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
  sizeof(t_falcon_properties)
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
  "t_falcon_properties"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&double_w_haptics_B.Sum[0]), 0, 0, 40 }
  ,

  { (char_T *)(&double_w_haptics_DWork.Memory_PreviousInput[0]), 0, 0, 10 },

  { (char_T *)(&double_w_haptics_DWork.Block1_PWORK), 11, 0, 7 },

  { (char_T *)(&double_w_haptics_DWork.Falcon_Falcon), 14, 0, 1 },

  { (char_T *)(&double_w_haptics_DWork.Block1_IWORK), 10, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  5U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&double_w_haptics_P.Memory_X0), 0, 0, 95 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  1U,
  rtPTransitions
};

/* [EOF] double_w_haptics_dt.h */
