/*
 * vmrl_test_fourbar_dt.h
 *
 * Real-Time Workshop code generation for Simulink model "vmrl_test_fourbar.mdl".
 *
 * Model Version              : 1.21
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Tue Jan 12 17:03:46 2010
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
  2*sizeof(uint32_T)
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
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&vmrl_test_fourbar_B.Block1_o1[0]), 0, 0, 111 }
  ,

  { (char_T *)(&vmrl_test_fourbar_DWork.Block1_PWORK), 11, 0, 30 },

  { (char_T *)(&vmrl_test_fourbar_DWork.Block1_IWORK), 10, 0, 2 },

  { (char_T *)(&vmrl_test_fourbar_DWork.If_ActiveSubsystem), 2, 0, 12 },

  { (char_T *)(&vmrl_test_fourbar_DWork.Generalcase_b.Generalcase_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&vmrl_test_fourbar_DWork.Phipi_n.Phipi_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&vmrl_test_fourbar_DWork.Generalcase_l.Generalcase_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&vmrl_test_fourbar_DWork.Phipi_j.Phipi_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&vmrl_test_fourbar_DWork.Generalcase_k.Generalcase_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&vmrl_test_fourbar_DWork.Phipi_g.Phipi_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&vmrl_test_fourbar_DWork.Generalcase_g.Generalcase_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&vmrl_test_fourbar_DWork.Phipi_e.Phipi_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&vmrl_test_fourbar_DWork.Generalcase_c.Generalcase_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&vmrl_test_fourbar_DWork.Phipi_m.Phipi_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&vmrl_test_fourbar_DWork.Generalcase.Generalcase_SubsysRanBC), 2,
    0, 1 },

  { (char_T *)(&vmrl_test_fourbar_DWork.Phipi.Phipi_SubsysRanBC), 2, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  16U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&vmrl_test_fourbar_P.Block1_SimMechanicsRuntimeParam[0]), 0, 0,
    268 },

  { (char_T *)(&vmrl_test_fourbar_P.Generalcase_b.Constant_Value), 0, 0, 3 },

  { (char_T *)(&vmrl_test_fourbar_P.Phipi_n.Shiftright_table[0]), 0, 0, 39 },

  { (char_T *)(&vmrl_test_fourbar_P.Generalcase_l.Constant_Value), 0, 0, 3 },

  { (char_T *)(&vmrl_test_fourbar_P.Phipi_j.Shiftright_table[0]), 0, 0, 39 },

  { (char_T *)(&vmrl_test_fourbar_P.Generalcase_k.Constant_Value), 0, 0, 3 },

  { (char_T *)(&vmrl_test_fourbar_P.Phipi_g.Shiftright_table[0]), 0, 0, 39 },

  { (char_T *)(&vmrl_test_fourbar_P.Generalcase_g.Constant_Value), 0, 0, 3 },

  { (char_T *)(&vmrl_test_fourbar_P.Phipi_e.Shiftright_table[0]), 0, 0, 39 },

  { (char_T *)(&vmrl_test_fourbar_P.Generalcase_c.Constant_Value), 0, 0, 3 },

  { (char_T *)(&vmrl_test_fourbar_P.Phipi_m.Shiftright_table[0]), 0, 0, 39 },

  { (char_T *)(&vmrl_test_fourbar_P.Generalcase.Constant_Value), 0, 0, 3 },

  { (char_T *)(&vmrl_test_fourbar_P.Phipi.Shiftright_table[0]), 0, 0, 39 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  13U,
  rtPTransitions
};

/* [EOF] vmrl_test_fourbar_dt.h */
