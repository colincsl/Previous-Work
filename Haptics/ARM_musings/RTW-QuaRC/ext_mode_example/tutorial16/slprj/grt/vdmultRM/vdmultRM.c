/*
 * Real-Time Workshop code generation for Simulink model 'vdmultRM'
 *
 * Model                      : vdmultRM
 * Model Version              : 1.7
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Wed Jun 10 17:28:43 2009
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "vdmultRM.h"
#include "vdmultRM_private.h"

int_T vdmultRM_GlobalTID[1];

/* Output and update for referenced model: 'vdmultRM'*/
void mr_vdmultRM(const real_T *rtu_0, const real_T *rtu_1, real_T *rty_0)
{
  /* Gain: '<Root>/Mu' incorporates:
   *  Fcn: '<Root>/Fcn'
   *  Product: '<Root>/Product'
   */
  (*rty_0) = (1.0 - (*rtu_0) * (*rtu_0)) * (*rtu_1) * 1.0;
}

/* Model initialize function */
void mr_vdmultRM_initialize(boolean_T firstTime, const char **rt_errorStatus,
  RTWSolverInfo *rt_solverInfo, int_T mdlref_TID0, RT_MODEL_vdmultRM *vdmultRM_M)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));    /* initialize real-time model */
  (void) memset((char_T *)vdmultRM_M,0,
                sizeof(RT_MODEL_vdmultRM));

  /* setup the global timing engine */
  vdmultRM_GlobalTID[0] = mdlref_TID0;

  /* initialize error status */
  rtmSetErrorStatusPointer(vdmultRM_M, rt_errorStatus);

  /* initialize RTWSolverInfo */
  vdmultRM_M->solverInfo = (rt_solverInfo);

  /* Set the Timing fields to the appropriate data in the RTWSolverInfo */
  rtmSetSimTimeStepPointer(vdmultRM_M, rtsiGetSimTimeStepPtr
    (vdmultRM_M->solverInfo));
  vdmultRM_M->Timing.stepSize0 = (rtsiGetStepSize(vdmultRM_M->solverInfo));
}
