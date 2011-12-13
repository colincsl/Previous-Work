/*
 * This file is not available for use in any application other than as a
 * MATLAB(R) MEX file for use with the Simulink(R) Accelerator product.
 */

/*
 * Crane_acc.c
 *
 * Real-Time Workshop code generation for Simulink model "Crane_acc.mdl".
 *
 * Model Version              : 1.32
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Tue Jun 02 13:39:54 2009
 */
#include <math.h>
#include "Crane_acc.h"
#include "Crane_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat                     S-Function
#define AccDefine1                     Accelerator_S-Function

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  if (ssIsSampleHit(S, 1, 0)) {
  }

  ((BlockIO *) _ssGetBlockIO(S))->B_0_3_0 = (muDoubleScalarSin(((Parameters *)
    ssGetDefaultParam(S))->P_2 * ssGetTaskTime(S,0) + ((Parameters *)
    ssGetDefaultParam(S))->P_3) * ((Parameters *) ssGetDefaultParam(S))->P_0 +
    ((Parameters *) ssGetDefaultParam(S))->P_1) * ((Parameters *)
    ssGetDefaultParam(S))->P_4;

  /* Level2 S-Function Block: '<S5>/B_0_2' (mech_engine) */
  /* Call into Simulink for MEX-version of S-function */
  ssCallAccelRunBlock(S, 0, 4, SS_CALL_MDL_OUTPUTS);
  if (ssIsSampleHit(S, 1, 0)) {
    ((BlockIO *) _ssGetBlockIO(S))->B_0_6_0[0] = ((Parameters *)
      ssGetDefaultParam(S))->P_8 * ((Parameters *) ssGetDefaultParam(S))->P_7[0];
    ((BlockIO *) _ssGetBlockIO(S))->B_0_6_0[1] = ((Parameters *)
      ssGetDefaultParam(S))->P_8 * ((Parameters *) ssGetDefaultParam(S))->P_7[1];
    ((BlockIO *) _ssGetBlockIO(S))->B_0_6_0[2] = ((Parameters *)
      ssGetDefaultParam(S))->P_8 * ((Parameters *) ssGetDefaultParam(S))->P_7[2];
  }

  /* Level2 S-Function Block: '<S5>/B_0_3' (mech_engine) */
  /* Call into Simulink for MEX-version of S-function */
  ssCallAccelRunBlock(S, 0, 7, SS_CALL_MDL_OUTPUTS);

  /* Level2 S-Function Block: '<S5>/B_0_4' (mech_engine) */
  /* Call into Simulink for MEX-version of S-function */
  ssCallAccelRunBlock(S, 0, 8, SS_CALL_MDL_OUTPUTS);
  if (ssIsSampleHit(S, 1, 0)) {
  }

  /* tid is required for a uniform function interface. This system
   * is single rate, and in this case, tid is not accessed. */
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  if (ssIsSampleHit(S, 1, 0)) {
  }

  /* Level2 S-Function Block: '<S5>/B_0_2' (mech_engine) */
  /* Call into Simulink for MEX-version of S-function */
  ssCallAccelRunBlock(S, 0, 4, SS_CALL_MDL_UPDATE);
  if (ssIsSampleHit(S, 1, 0)) {
  }

  /* Level2 S-Function Block: '<S5>/B_0_3' (mech_engine) */
  /* Call into Simulink for MEX-version of S-function */
  ssCallAccelRunBlock(S, 0, 7, SS_CALL_MDL_UPDATE);

  /* Level2 S-Function Block: '<S5>/B_0_4' (mech_engine) */
  /* Call into Simulink for MEX-version of S-function */
  ssCallAccelRunBlock(S, 0, 8, SS_CALL_MDL_UPDATE);
  if (ssIsSampleHit(S, 1, 0)) {
  }

  /* tid is required for a uniform function interface. This system
   * is single rate, and in this case, tid is not accessed. */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
#define MDL_DERIVATIVES

static void mdlDerivatives(SimStruct *S)
{
  /* Level2 S-Function Block: '<S5>/B_0_2' (mech_engine) */
  /* Call into Simulink for MEX-version of S-function */
  ssCallAccelRunBlock(S, 0, 4, SS_CALL_MDL_DERIVATIVES);
}

/* Projection for root system: '<Root>' */
#define MDL_PROJECTION

static void mdlProjection(SimStruct *S)
{
  /* Level2 S-Function Block: '<S5>/B_0_2' (mech_engine) */
  /* Call into Simulink for MEX-version of S-function */
  ssCallAccelRunBlock(S, 0, 4, SS_CALL_MDL_PROJECTION);
}

/* Function to initialize sizes */
static void mdlInitializeSizes(SimStruct *S)
{
  /* checksum */
  ssSetChecksumVal(S, 0, 71594385U);
  ssSetChecksumVal(S, 1, 1091377313U);
  ssSetChecksumVal(S, 2, 128779518U);
  ssSetChecksumVal(S, 3, 4288181503U);

  /* options */
  ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);

  /* Accelerator check memory map size match for DWork */
  if (ssGetSizeofDWork(S) != sizeof(D_Work)) {
    ssSetErrorStatus(S,"Unexpected error: Internal DWork sizes do "
                     "not match for accelerator mex file.");
  }

  /* Accelerator check memory map size match for BlockIO */
  if (ssGetSizeofGlobalBlockIO(S) != sizeof(BlockIO)) {
    ssSetErrorStatus(S,"Unexpected error: Internal BlockIO sizes do "
                     "not match for accelerator mex file.");
  }

  /* model parameters */
  _ssSetDefaultParam(S, (real_T *) &rtDefaultParameters);

  /* non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* Empty mdlInitializeSampleTimes function (never called) */
static void mdlInitializeSampleTimes(SimStruct *S)
{
}

/* Empty mdlTerminate function (never called) */
static void mdlTerminate(SimStruct *S)
{
}

/* MATLAB MEX Glue */
#include "simulink.c"
