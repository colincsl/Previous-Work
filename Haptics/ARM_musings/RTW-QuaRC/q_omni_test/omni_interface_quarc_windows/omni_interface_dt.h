/*
 * omni_interface_dt.h
 *
 * Real-Time Workshop code generation for Simulink model "omni_interface.mdl".
 *
 * Model Version              : 1.22
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Mon Jun 15 11:31:32 2009
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
  sizeof(t_stream),
  sizeof(t_stream_ptr),
  sizeof(t_card),
  sizeof(t_boolean)
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
  "t_stream",
  "t_stream_ptr",
  "t_card",
  "t_boolean"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&omni_interface_B.Gain2[0]), 0, 0, 12 },

  { (char_T *)(&omni_interface_B.StreamAnswer_o3), 6, 0, 2 },

  { (char_T *)(&omni_interface_B.LogicalOperator), 8, 0, 2 }
  ,

  { (char_T *)(&omni_interface_DWork.FixPtUnitDelay1_DSTATE), 0, 0, 19 },

  { (char_T *)(&omni_interface_DWork.HILRead_PWORK), 11, 0, 2 },

  { (char_T *)(&omni_interface_DWork.HILInitialize_QuadratureModes[0]), 6, 0, 12
  },

  { (char_T *)(&omni_interface_DWork.HILInitialize_POSortedChans[0]), 7, 0, 3 },

  { (char_T *)(&omni_interface_DWork.StreamAnswer_Listener), 14, 0, 4 },

  { (char_T *)(&omni_interface_DWork.HILInitialize_Card), 16, 0, 1 },

  { (char_T *)(&omni_interface_DWork.StreamAnswer_State), 3, 0, 2 },

  { (char_T *)(&omni_interface_DWork.HILRead_DigitalBuffer[0]), 17, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  11U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&omni_interface_P.HILInitialize_OOStart), 0, 0, 33 },

  { (char_T *)(&omni_interface_P.HILInitialize_EIInitial), 6, 0, 5 },

  { (char_T *)(&omni_interface_P.HILInitialize_AIChannels[0]), 7, 0, 19 },

  { (char_T *)(&omni_interface_P.StreamAnswer_Endian), 2, 0, 2 },

  { (char_T *)(&omni_interface_P.HILInitialize_Active), 8, 0, 33 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] omni_interface_dt.h */
