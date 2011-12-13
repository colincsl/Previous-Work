/*
 * Demo_vehicle_dt.h
 *
 * Real-Time Workshop code generation for Simulink model "Demo_vehicle.mdl".
 *
 * Model Version              : 1.35
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Tue Jun 16 13:46:58 2009
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
  { (char_T *)(&Demo_vehicle_B.Memory1[0]), 0, 0, 27 }
  ,

  { (char_T *)(&Demo_vehicle_DWork.Memory1_PreviousInput[0]), 0, 0, 2006 },

  { (char_T *)(&Demo_vehicle_DWork.VRSink_PWORK[0]), 11, 0, 7 },

  { (char_T *)(&Demo_vehicle_DWork.Falcon_Falcon), 14, 0, 1 },

  { (char_T *)(&Demo_vehicle_DWork.XYFigure_IWORK[0]), 10, 0, 2 },

  { (char_T *)(&Demo_vehicle_DWork.is_active_c2_Demo_vehicle), 3, 0, 1 },

  { (char_T *)(&Demo_vehicle_DWork.XYFigure_IsFull), 8, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  7U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Demo_vehicle_P.Memory1_X0), 0, 0, 10216 },

  { (char_T *)(&Demo_vehicle_P.XYFigure_UpdateRate), 6, 0, 1 },

  { (char_T *)(&Demo_vehicle_P.XYFigure_EraseMode), 2, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] Demo_vehicle_dt.h */
