/*
 * untitled_dt.h
 *
 * Real-Time Workshop code generation for Simulink model "untitled.mdl".
 *
 * Model Version              : 1.0
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Mon Jun 15 11:44:38 2009
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
  sizeof(t_falcon_properties),
  sizeof(t_card)
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
  "t_falcon_properties",
  "t_card"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&untitled_DWork.HILInitialize_AIMinimums[0]), 0, 0, 13 },

  { (char_T *)(&untitled_DWork.HILInitialize_QuadratureModes[0]), 6, 0, 9 },

  { (char_T *)(&untitled_DWork.HILInitialize_POSortedChans[0]), 7, 0, 3 },

  { (char_T *)(&untitled_DWork.Falcon_Falcon), 14, 0, 1 },

  { (char_T *)(&untitled_DWork.HILInitialize_Card), 15, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  5U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&untitled_P.HILInitialize_OOStart), 0, 0, 8 },

  { (char_T *)(&untitled_P.HILInitialize_EIInitial), 6, 0, 1 },

  { (char_T *)(&untitled_P.HILInitialize_AIChannels[0]), 7, 0, 8 },

  { (char_T *)(&untitled_P.HILInitialize_Active), 8, 0, 29 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  4U,
  rtPTransitions
};

/* [EOF] untitled_dt.h */
