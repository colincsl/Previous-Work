/*
 * vmrl_test_fourbar_private.h
 *
 * Real-Time Workshop code generation for Simulink model "vmrl_test_fourbar.mdl".
 *
 * Model Version              : 1.21
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Tue Jan 12 17:03:46 2010
 */
#ifndef RTW_HEADER_vmrl_test_fourbar_private_h_
#define RTW_HEADER_vmrl_test_fourbar_private_h_
#include "rtwtypes.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   /* do nothing */
# else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

#include "mech_std.h"
#include "mtypes.h"
#include "simulation_data.h"
#include "mech_method_table.h"
#include "rt_mechanism.h"
#include "sim_mechanics_imports.h"

/*
 * simulation data structure for SimMechanics, one for each SFunction
 */
typedef struct {
  Mechanism *mechanism;
  SimulationDataGeneral genSimData;
  SimulationDataOutputs outSimData;
} _rtMech_PWORK;

/* private model entry point functions */
extern void vmrl_test_fourbar_derivatives(void);
void vmrl_test_fourbar_Phipi_Start(real_T *rty_0, real_T rty_1[3],
  rtP_Phipi_vmrl_test_fourbar *localP);
void vmrl_test_fourbar_Phipi(real_T rtu_0, real_T rtu_1, real_T rtu_2, real_T
  rtu_3, real_T rtu_4, real_T rtu_5, real_T *rty_0, real_T rty_1[3],
  RT_MODEL_vmrl_test_fourbar *rtm, rtDW_Phipi_vmrl_test_fourbar *localDW,
  rtP_Phipi_vmrl_test_fourbar *localP);
void vmrl_test_fourbar_Generalcase(real_T rtu_Traceu, const real_T rtu_1[2],
  real_T rtu_2, real_T rtu_3, const real_T rtu_4[2], real_T *rty_0, real_T
  rty_1[3], RT_MODEL_vmrl_test_fourbar *rtm, rtDW_Generalcase_vmrl_test_four
  *localDW, rtP_Generalcase_vmrl_test_fourb *localP);

#endif                                 /* RTW_HEADER_vmrl_test_fourbar_private_h_ */
