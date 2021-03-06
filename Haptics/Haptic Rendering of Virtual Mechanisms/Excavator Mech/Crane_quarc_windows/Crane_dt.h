/*
 * Crane_dt.h
 *
 * Real-Time Workshop code generation for Simulink model "Crane.mdl".
 *
 * Model Version              : 1.65
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Tue Jan 12 17:09:02 2010
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
  { (char_T *)(&Crane_B.Block1_o1[0]), 0, 0, 49 }
  ,

  { (char_T *)(&Crane_DWork.Memory_PreviousInput[0]), 0, 0, 4 },

  { (char_T *)(&Crane_DWork.Block1_PWORK), 11, 0, 4 },

  { (char_T *)(&Crane_DWork.Falcon_Falcon), 14, 0, 1 },

  { (char_T *)(&Crane_DWork.Block1_IWORK), 10, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  5U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Crane_P.Constant2_Value), 0, 0, 416 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  1U,
  rtPTransitions
};

/* [EOF] Crane_dt.h */
