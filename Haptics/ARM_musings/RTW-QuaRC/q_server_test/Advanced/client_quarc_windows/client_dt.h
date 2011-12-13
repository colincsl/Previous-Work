/*
 * client_dt.h
 *
 * Real-Time Workshop code generation for Simulink model "client.mdl".
 *
 * Model Version              : 1.4
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Thu Jun 18 10:49:53 2009
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
  sizeof(t_stream_ptr)
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
  "t_stream_ptr"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&client_B.SineWave), 0, 0, 1 },

  { (char_T *)(&client_B.StreamFlush_o2), 6, 0, 1 }
  ,

  { (char_T *)(&client_DWork.Scope1_PWORK.LoggedData), 11, 0, 1 },

  { (char_T *)(&client_DWork.StreamConnect_Stream), 14, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  4U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&client_P.SineWave_Amp), 0, 0, 4 },

  { (char_T *)(&client_P.StreamConnect_SendBufferSize), 6, 0, 2 },

  { (char_T *)(&client_P.StreamConnect_Endian), 2, 0, 1 },

  { (char_T *)(&client_P.StreamConnect_Active), 8, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  4U,
  rtPTransitions
};

/* [EOF] client_dt.h */
