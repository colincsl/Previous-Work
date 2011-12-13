/*
 * vdptop.c
 *
 * Real-Time Workshop code generation for Simulink model "vdptop.mdl".
 *
 * Model Version              : 1.6
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Wed Jun 10 17:28:57 2009
 */

#include "vdptop.h"
#include "vdptop_private.h"

/* Block signals (auto storage) */
BlockIO_vdptop vdptop_B;

/* Continuous states */
ContinuousStates_vdptop vdptop_X;

/* Solver Matrices */

/* A and B matrices used by ODE3 fixed-step solver */
static const real_T rt_ODE3_A[3] = {
  1.0/2.0, 3.0/4.0, 1.0
};

static const real_T rt_ODE3_B[3][3] = {
  { 1.0/2.0, 0.0, 0.0 },

  { 0.0, 3.0/4.0, 0.0 },

  { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
};

/* Block states (auto storage) */
D_Work_vdptop vdptop_DWork;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_vdptop vdptop_Y;

/* Real-time model */
RT_MODEL_vdptop vdptop_M_;
RT_MODEL_vdptop *vdptop_M = &vdptop_M_;

/* This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y,x,
                nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  vdptop_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  vdptop_output(0);
  vdptop_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++)
    hB[i] = h * rt_ODE3_B[1][i];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  vdptop_output(0);
  vdptop_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++)
    hB[i] = h * rt_ODE3_B[2][i];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void vdptop_output(int_T tid)
{
  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(vdptop_M)) {
    vdptop_M->Timing.t[0] = rtsiGetT(&vdptop_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(vdptop_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&vdptop_M->solverInfo,
                          ((vdptop_M->Timing.clockTick0+1)*
      vdptop_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Integrator: '<Root>/x1' */
  vdptop_B.x1 = vdptop_X.x1_CSTATE;

  /* Outport: '<Root>/Out1' */
  vdptop_Y.Out1 = vdptop_B.x1;

  /* Integrator: '<Root>/x2' */
  vdptop_B.x2 = vdptop_X.x2_CSTATE;

  /* Outport: '<Root>/Out2' */
  vdptop_Y.Out2 = vdptop_B.x2;
  if (rtmIsMajorTimeStep(vdptop_M) &&
      vdptop_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* OutputUpdate for ModelReference Block: '<Root>/vdpmult' */
  mr_vdmultRM(&vdptop_B.x1, &vdptop_B.x2, &vdptop_B.vdpmult);

  /* Sum: '<Root>/Sum' */
  vdptop_B.Sum = vdptop_B.vdpmult - vdptop_B.x1;
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void vdptop_update(int_T tid)
{
  if (rtmIsMajorTimeStep(vdptop_M)) {
    rt_ertODEUpdateContinuousStates(&vdptop_M->solverInfo);
  }

  /* Update absolute time for base rate */
  if (!(++vdptop_M->Timing.clockTick0))
    ++vdptop_M->Timing.clockTickH0;
  vdptop_M->Timing.t[0] = vdptop_M->Timing.clockTick0 *
    vdptop_M->Timing.stepSize0 + vdptop_M->Timing.clockTickH0 *
    vdptop_M->Timing.stepSize0 * 4294967296.0;
  if (rtmIsMajorTimeStep(vdptop_M) &&
      vdptop_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.4s, 0.0s] */
    if (!(++vdptop_M->Timing.clockTick1))
      ++vdptop_M->Timing.clockTickH1;
    vdptop_M->Timing.t[1] = vdptop_M->Timing.clockTick1 *
      vdptop_M->Timing.stepSize1 + vdptop_M->Timing.clockTickH1 *
      vdptop_M->Timing.stepSize1 * 4294967296.0;
  }

  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void vdptop_derivatives(void)
{
  /* Derivatives for Integrator: '<Root>/x1' */
  ((StateDerivatives_vdptop *) vdptop_M->ModelData.derivs)->x1_CSTATE =
    vdptop_B.x2;

  /* Derivatives for Integrator: '<Root>/x2' */
  ((StateDerivatives_vdptop *) vdptop_M->ModelData.derivs)->x2_CSTATE =
    vdptop_B.Sum;
}

/* Model initialize function */
void vdptop_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));    /* initialize real-time model */
  (void) memset((char_T *)vdptop_M,0,
                sizeof(RT_MODEL_vdptop));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&vdptop_M->solverInfo, &vdptop_M->Timing.simTimeStep);
    rtsiSetTPtr(&vdptop_M->solverInfo, &rtmGetTPtr(vdptop_M));
    rtsiSetStepSizePtr(&vdptop_M->solverInfo, &vdptop_M->Timing.stepSize0);
    rtsiSetdXPtr(&vdptop_M->solverInfo, &vdptop_M->ModelData.derivs);
    rtsiSetContStatesPtr(&vdptop_M->solverInfo, &vdptop_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&vdptop_M->solverInfo,
      &vdptop_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&vdptop_M->solverInfo, (&rtmGetErrorStatus(vdptop_M)));
    rtsiSetRTModelPtr(&vdptop_M->solverInfo, vdptop_M);
  }

  rtsiSetSimTimeStep(&vdptop_M->solverInfo, MAJOR_TIME_STEP);
  vdptop_M->ModelData.intgData.y = vdptop_M->ModelData.odeY;
  vdptop_M->ModelData.intgData.f[0] = vdptop_M->ModelData.odeF[0];
  vdptop_M->ModelData.intgData.f[1] = vdptop_M->ModelData.odeF[1];
  vdptop_M->ModelData.intgData.f[2] = vdptop_M->ModelData.odeF[2];
  vdptop_M->ModelData.contStates = ((real_T *) &vdptop_X);
  rtsiSetSolverData(&vdptop_M->solverInfo, (void *)&vdptop_M->ModelData.intgData);
  rtsiSetSolverName(&vdptop_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = vdptop_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    vdptop_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    vdptop_M->Timing.sampleTimes = (&vdptop_M->Timing.sampleTimesArray[0]);
    vdptop_M->Timing.offsetTimes = (&vdptop_M->Timing.offsetTimesArray[0]);

    /* task periods */
    vdptop_M->Timing.sampleTimes[0] = (0.0);
    vdptop_M->Timing.sampleTimes[1] = (0.4);

    /* task offsets */
    vdptop_M->Timing.offsetTimes[0] = (0.0);
    vdptop_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(vdptop_M, &vdptop_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = vdptop_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    vdptop_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(vdptop_M, 20.0);
  vdptop_M->Timing.stepSize0 = 0.4;
  vdptop_M->Timing.stepSize1 = 0.4;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    vdptop_M->rtwLogInfo = &rt_DataLoggingInfo;
    rtliSetLogFormat(vdptop_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(vdptop_M->rtwLogInfo, 0);
    rtliSetLogDecimation(vdptop_M->rtwLogInfo, 1);
    rtliSetLogVarNameModifier(vdptop_M->rtwLogInfo, "rt_");
    rtliSetLogT(vdptop_M->rtwLogInfo, "tout");
    rtliSetLogX(vdptop_M->rtwLogInfo, "");
    rtliSetLogXFinal(vdptop_M->rtwLogInfo, "");
    rtliSetSigLog(vdptop_M->rtwLogInfo, "");
    rtliSetLogXSignalInfo(vdptop_M->rtwLogInfo, NULL);
    rtliSetLogXSignalPtrs(vdptop_M->rtwLogInfo, NULL);
    rtliSetLogY(vdptop_M->rtwLogInfo, "yout");

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &vdptop_Y.Out1,
        &vdptop_Y.Out2
      };

      rtliSetLogYSignalPtrs(vdptop_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0
      };

      static int_T* rt_LoggedCurrentSignalDimensions[] = {
        NULL,
        NULL
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "x1",
        "x2" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "vdptop/Out1",
        "vdptop/Out2" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          2,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          NULL,

          { rt_LoggedOutputLabels },
          NULL,
          NULL,
          NULL,

          { rt_LoggedOutputBlockNames },

          { NULL },
          NULL,
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(vdptop_M->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
    }
  }

  vdptop_M->solverInfoPtr = (&vdptop_M->solverInfo);
  vdptop_M->Timing.stepSize = (0.4);
  rtsiSetFixedStepSize(&vdptop_M->solverInfo, 0.4);
  rtsiSetSolverMode(&vdptop_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  vdptop_M->ModelData.blockIO = ((void *) &vdptop_B);

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&vdptop_B.x1);
    for (i = 0; i < 4; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }
  }

  /* states (continuous) */
  {
    real_T *x = (real_T *) &vdptop_X;
    vdptop_M->ModelData.contStates = (x);
    (void) memset((char_T *)x,0,
                  sizeof(ContinuousStates_vdptop));
  }

  /* states (dwork) */
  vdptop_M->Work.dwork = ((void *) &vdptop_DWork);
  (void) memset((char_T *) &vdptop_DWork,0,
                sizeof(D_Work_vdptop));

  /* external outputs */
  vdptop_M->ModelData.outputs = (&vdptop_Y);
  vdptop_Y.Out1 = 0.0;
  vdptop_Y.Out2 = 0.0;

  /* Model Initialize fcn for ModelReference Block: '<Root>/vdpmult' */
  mr_vdmultRM_initialize(1, rtmGetErrorStatusPointer(vdptop_M),
    &(vdptop_M->solverInfo), 0, &(vdptop_DWork.vdpmult_DWORK1.rtm));
}

/* Model terminate function */
void vdptop_terminate(void)
{
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  vdptop_output(tid);
}

void MdlUpdate(int_T tid)
{
  vdptop_update(tid);
}

void MdlInitializeSizes(void)
{
  vdptop_M->Sizes.numContStates = (2); /* Number of continuous states */
  vdptop_M->Sizes.numY = (2);          /* Number of model outputs */
  vdptop_M->Sizes.numU = (0);          /* Number of model inputs */
  vdptop_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  vdptop_M->Sizes.numSampTimes = (2);  /* Number of sample times */
  vdptop_M->Sizes.numBlocks = (7);     /* Number of blocks */
  vdptop_M->Sizes.numBlockIO = (4);    /* Number of block outputs */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for Integrator: '<Root>/x1' */
  vdptop_X.x1_CSTATE = 2.0;

  /* InitializeConditions for Integrator: '<Root>/x2' */
  vdptop_X.x2_CSTATE = 0.0;
}

void MdlStart(void)
{
  MdlInitialize();
}

RT_MODEL_vdptop *vdptop(void)
{
  vdptop_initialize(1);
  return vdptop_M;
}

void MdlTerminate(void)
{
  vdptop_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
