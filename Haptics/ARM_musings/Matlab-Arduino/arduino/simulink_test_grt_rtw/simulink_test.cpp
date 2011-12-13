/*
 * simulink_test.cpp
 *
 * Real-Time Workshop code generation for Simulink model "simulink_test.mdl".
 *
 * Model Version              : 1.7
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C++ source code generated on : Mon Aug 31 14:12:33 2009
 */

#include "simulink_test.h"
#include "simulink_test_private.h"

/* Block states (auto storage) */
D_Work_simulink_test simulink_test_DWork;

/* Real-time model */
RT_MODEL_simulink_test simulink_test_M_;
RT_MODEL_simulink_test *simulink_test_M = &simulink_test_M_;

/* Model output function */
static void simulink_test_output(int_T tid)
{
  /* (no output code required) */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
static void simulink_test_update(int_T tid)
{
  /* Update absolute time for base rate */
  if (!(++simulink_test_M->Timing.clockTick0))
    ++simulink_test_M->Timing.clockTickH0;
  simulink_test_M->Timing.t[0] = simulink_test_M->Timing.clockTick0 *
    simulink_test_M->Timing.stepSize0 + simulink_test_M->Timing.clockTickH0 *
    simulink_test_M->Timing.stepSize0 * 4294967296.0;
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
extern "C" void simulink_test_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));    /* initialize real-time model */
  (void) memset((char_T *)simulink_test_M,0,
                sizeof(RT_MODEL_simulink_test));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = simulink_test_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    simulink_test_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    simulink_test_M->Timing.sampleTimes =
      (&simulink_test_M->Timing.sampleTimesArray[0]);
    simulink_test_M->Timing.offsetTimes =
      (&simulink_test_M->Timing.offsetTimesArray[0]);

    /* task periods */
    simulink_test_M->Timing.sampleTimes[0] = (0.2);

    /* task offsets */
    simulink_test_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(simulink_test_M, &simulink_test_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = simulink_test_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    simulink_test_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(simulink_test_M, -1);
  simulink_test_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    simulink_test_M->rtwLogInfo = &rt_DataLoggingInfo;
    rtliSetLogFormat(simulink_test_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(simulink_test_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(simulink_test_M->rtwLogInfo, 1);
    rtliSetLogVarNameModifier(simulink_test_M->rtwLogInfo, "rt_");
    rtliSetLogT(simulink_test_M->rtwLogInfo, "tout");
    rtliSetLogX(simulink_test_M->rtwLogInfo, "");
    rtliSetLogXFinal(simulink_test_M->rtwLogInfo, "");
    rtliSetSigLog(simulink_test_M->rtwLogInfo, "");
    rtliSetLogXSignalInfo(simulink_test_M->rtwLogInfo, NULL);
    rtliSetLogXSignalPtrs(simulink_test_M->rtwLogInfo, NULL);
    rtliSetLogY(simulink_test_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(simulink_test_M->rtwLogInfo, NULL);
    rtliSetLogYSignalPtrs(simulink_test_M->rtwLogInfo, NULL);
  }

  simulink_test_M->solverInfoPtr = (&simulink_test_M->solverInfo);
  simulink_test_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&simulink_test_M->solverInfo, 0.2);
  rtsiSetSolverMode(&simulink_test_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* parameters */
  simulink_test_M->ModelData.defaultParam = ((real_T *) &simulink_test_P);

  /* states (dwork) */
  simulink_test_M->Work.dwork = ((void *) &simulink_test_DWork);
  (void) memset((char_T *) &simulink_test_DWork,0,
                sizeof(D_Work_simulink_test));
}

/* Model terminate function */
extern "C" void simulink_test_terminate(void)
{
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
extern "C" void MdlOutputs(int_T tid)
{
  simulink_test_output(tid);
}

extern "C" void MdlUpdate(int_T tid)
{
  simulink_test_update(tid);
}

extern "C" void MdlInitializeSizes(void)
{
  simulink_test_M->Sizes.numContStates = (0);/* Number of continuous states */
  simulink_test_M->Sizes.numY = (0);   /* Number of model outputs */
  simulink_test_M->Sizes.numU = (0);   /* Number of model inputs */
  simulink_test_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  simulink_test_M->Sizes.numSampTimes = (1);/* Number of sample times */
  simulink_test_M->Sizes.numBlocks = (4);/* Number of blocks */
  simulink_test_M->Sizes.numBlockIO = (0);/* Number of block outputs */
  simulink_test_M->Sizes.numBlockPrms = (1);/* Sum of parameter "widths" */
}

extern "C" void MdlInitializeSampleTimes(void)
{
}

extern "C" void MdlInitialize(void)
{
}

extern "C" void MdlStart(void)
{
  MdlInitialize();
}

extern "C" RT_MODEL_simulink_test *simulink_test(void)
{
  simulink_test_initialize(1);
  return simulink_test_M;
}

extern "C" void MdlTerminate(void)
{
  simulink_test_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
