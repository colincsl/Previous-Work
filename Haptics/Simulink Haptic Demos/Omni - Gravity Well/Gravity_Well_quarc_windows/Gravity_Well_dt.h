/*
 * Gravity_Well_dt.h
 *
 * Real-Time Workshop code generation for Simulink model "Gravity_Well.mdl".
 *
 * Model Version              : 1.201
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Tue Jul 21 14:08:06 2009
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
  { (char_T *)(&Gravity_Well_B.GearRatio[0]), 0, 0, 112 },

  { (char_T *)(&Gravity_Well_B.sf_EuclideanDistance_j.mag), 0, 0, 1 },

  { (char_T *)(&Gravity_Well_B.sf_EuclideanDistance.mag), 0, 0, 1 }
  ,

  { (char_T *)(&Gravity_Well_DWork.HILInitialize_AIMinimums[0]), 0, 0, 13 },

  { (char_T *)(&Gravity_Well_DWork.HILWritePWM_PWORK), 11, 0, 7 },

  { (char_T *)(&Gravity_Well_DWork.HILInitialize_QuadratureModes[0]), 6, 0, 12 },

  { (char_T *)(&Gravity_Well_DWork.HILInitialize_POSortedChans[0]), 7, 0, 3 },

  { (char_T *)(&Gravity_Well_DWork.HILInitialize_Card), 14, 0, 1 },

  { (char_T *)(&Gravity_Well_DWork.HILReadEncoderTimebase_Task), 15, 0, 1 },

  { (char_T *)(&Gravity_Well_DWork.Integrator1_IWORK.IcNeedsLoading), 10, 0, 2 },

  { (char_T *)(&Gravity_Well_DWork.is_active_c3_Gravity_Well), 3, 0, 4 },

  { (char_T *)(&Gravity_Well_DWork.doneDoubleBufferReInit), 8, 0, 4 },

  { (char_T *)
    (&Gravity_Well_DWork.sf_EuclideanDistance_j.is_active_c7_Gravity_Well), 3, 0,
    1 },

  { (char_T *)(&Gravity_Well_DWork.sf_EuclideanDistance_j.doneDoubleBufferReInit),
    8, 0, 1 },

  { (char_T *)
    (&Gravity_Well_DWork.sf_EuclideanDistance.is_active_c7_Gravity_Well), 3, 0,
    1 },

  { (char_T *)(&Gravity_Well_DWork.sf_EuclideanDistance.doneDoubleBufferReInit),
    8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  16U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Gravity_Well_P.HILInitialize_OOStart), 0, 0, 78 },

  { (char_T *)(&Gravity_Well_P.HILInitialize_DOWatchdog), 6, 0, 3 },

  { (char_T *)(&Gravity_Well_P.HILInitialize_AIChannels[0]), 7, 0, 18 },

  { (char_T *)(&Gravity_Well_P.HILInitialize_Active), 8, 0, 32 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  4U,
  rtPTransitions
};

/* [EOF] Gravity_Well_dt.h */
