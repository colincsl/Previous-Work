/*
 * Real-Time Workshop code generation for Simulink model 'vdmultRM'
 * For more details, see corresponding source file vdmultRM.c
 *
 */
#ifndef RTW_HEADER_vdmultRM_h_
#define RTW_HEADER_vdmultRM_h_
#ifndef vdmultRM_COMMON_INCLUDES_
# define vdmultRM_COMMON_INCLUDES_
#include <math.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_nonfinite.h"
#endif                                 /* vdmultRM_COMMON_INCLUDES_ */

#include "vdmultRM_types.h"

/* Real-time Model Data Structure */
struct RT_MODEL_vdmultRM {
  const char_T **errorStatus;
  RTWSolverInfo *solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize0;
    SimTimeStep *simTimeStep;
  } Timing;
};

typedef struct {
  RT_MODEL_vdmultRM rtm;
} rtMdlrefDWork_mr_vdmultRM;

/* Model reference registration function */
extern void mr_vdmultRM_initialize(boolean_T firstTime, const char
  **rt_errorStatus, RTWSolverInfo *rt_solverInfo, int_T mdlref_TID0,
  RT_MODEL_vdmultRM *vdmultRM_M);
extern void mr_vdmultRM(const real_T *rtu_0, const real_T *rtu_1, real_T *rty_0);

#endif                                 /* RTW_HEADER_vdmultRM_h_ */
