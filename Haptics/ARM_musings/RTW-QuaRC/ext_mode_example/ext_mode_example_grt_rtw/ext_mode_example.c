/*
 * ext_mode_example.c
 *
 * Real-Time Workshop code generation for Simulink model "ext_mode_example.mdl".
 *
 * Model Version              : 1.2
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Wed Jun 10 16:40:14 2009
 */

#include "ext_mode_example.h"
#include "ext_mode_example_private.h"
#include <stdio.h>
#include "ext_mode_example_dt.h"

/* Block signals (auto storage) */
BlockIO_ext_mode_example ext_mode_example_B;

/* Block states (auto storage) */
D_Work_ext_mode_example ext_mode_example_DWork;

/* Real-time model */
RT_MODEL_ext_mode_example ext_mode_example_M_;
RT_MODEL_ext_mode_example *ext_mode_example_M = &ext_mode_example_M_;

/* Model output function */
void ext_mode_example_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_SineWave;

  /* Sin: '<Root>/Sine Wave' */
  rtb_SineWave = sin(ext_mode_example_P.SineWave_Freq *
                     ext_mode_example_M->Timing.t[0] +
                     ext_mode_example_P.SineWave_Phase) *
    ext_mode_example_P.SineWave_Amp + ext_mode_example_P.SineWave_Bias;

  /* Gain: '<Root>/Gain A' */
  ext_mode_example_B.GainA = ext_mode_example_P.GainA_Gain * rtb_SineWave;

  /* Gain: '<Root>/Gain1' */
  ext_mode_example_B.Gain1 = ext_mode_example_P.Gain1_Gain * rtb_SineWave;
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void ext_mode_example_update(int_T tid)
{
  /* Update absolute time for base rate */
  if (!(++ext_mode_example_M->Timing.clockTick0))
    ++ext_mode_example_M->Timing.clockTickH0;
  ext_mode_example_M->Timing.t[0] = ext_mode_example_M->Timing.clockTick0 *
    ext_mode_example_M->Timing.stepSize0 +
    ext_mode_example_M->Timing.clockTickH0 *
    ext_mode_example_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    if (!(++ext_mode_example_M->Timing.clockTick1))
      ++ext_mode_example_M->Timing.clockTickH1;
    ext_mode_example_M->Timing.t[1] = ext_mode_example_M->Timing.clockTick1 *
      ext_mode_example_M->Timing.stepSize1 +
      ext_mode_example_M->Timing.clockTickH1 *
      ext_mode_example_M->Timing.stepSize1 * 4294967296.0;
  }

  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void ext_mode_example_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));    /* initialize real-time model */
  (void) memset((char_T *)ext_mode_example_M,0,
                sizeof(RT_MODEL_ext_mode_example));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ext_mode_example_M->solverInfo,
                          &ext_mode_example_M->Timing.simTimeStep);
    rtsiSetTPtr(&ext_mode_example_M->solverInfo, &rtmGetTPtr(ext_mode_example_M));
    rtsiSetStepSizePtr(&ext_mode_example_M->solverInfo,
                       &ext_mode_example_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&ext_mode_example_M->solverInfo, (&rtmGetErrorStatus
      (ext_mode_example_M)));
    rtsiSetRTModelPtr(&ext_mode_example_M->solverInfo, ext_mode_example_M);
  }

  rtsiSetSimTimeStep(&ext_mode_example_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&ext_mode_example_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ext_mode_example_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ext_mode_example_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ext_mode_example_M->Timing.sampleTimes =
      (&ext_mode_example_M->Timing.sampleTimesArray[0]);
    ext_mode_example_M->Timing.offsetTimes =
      (&ext_mode_example_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ext_mode_example_M->Timing.sampleTimes[0] = (0.0);
    ext_mode_example_M->Timing.sampleTimes[1] = (0.1);

    /* task offsets */
    ext_mode_example_M->Timing.offsetTimes[0] = (0.0);
    ext_mode_example_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ext_mode_example_M, &ext_mode_example_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ext_mode_example_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ext_mode_example_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ext_mode_example_M, 60.0);
  ext_mode_example_M->Timing.stepSize0 = 0.1;
  ext_mode_example_M->Timing.stepSize1 = 0.1;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    ext_mode_example_M->rtwLogInfo = &rt_DataLoggingInfo;
    rtliSetLogFormat(ext_mode_example_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ext_mode_example_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ext_mode_example_M->rtwLogInfo, 1);
    rtliSetLogVarNameModifier(ext_mode_example_M->rtwLogInfo, "rt_");
    rtliSetLogT(ext_mode_example_M->rtwLogInfo, "");
    rtliSetLogX(ext_mode_example_M->rtwLogInfo, "");
    rtliSetLogXFinal(ext_mode_example_M->rtwLogInfo, "");
    rtliSetSigLog(ext_mode_example_M->rtwLogInfo, "");
    rtliSetLogXSignalInfo(ext_mode_example_M->rtwLogInfo, NULL);
    rtliSetLogXSignalPtrs(ext_mode_example_M->rtwLogInfo, NULL);
    rtliSetLogY(ext_mode_example_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ext_mode_example_M->rtwLogInfo, NULL);
    rtliSetLogYSignalPtrs(ext_mode_example_M->rtwLogInfo, NULL);
  }

  /* external mode info */
  ext_mode_example_M->Sizes.checksums[0] = (656513736U);
  ext_mode_example_M->Sizes.checksums[1] = (1171684220U);
  ext_mode_example_M->Sizes.checksums[2] = (173266702U);
  ext_mode_example_M->Sizes.checksums[3] = (1026049724U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    ext_mode_example_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &ext_mode_example_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, ext_mode_example_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(ext_mode_example_M));
  }

  ext_mode_example_M->solverInfoPtr = (&ext_mode_example_M->solverInfo);
  ext_mode_example_M->Timing.stepSize = (0.1);
  rtsiSetFixedStepSize(&ext_mode_example_M->solverInfo, 0.1);
  rtsiSetSolverMode(&ext_mode_example_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ext_mode_example_M->ModelData.blockIO = ((void *) &ext_mode_example_B);

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&ext_mode_example_B.GainA);
    for (i = 0; i < 2; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }
  }

  /* parameters */
  ext_mode_example_M->ModelData.defaultParam = ((real_T *) &ext_mode_example_P);

  /* states (dwork) */
  ext_mode_example_M->Work.dwork = ((void *) &ext_mode_example_DWork);
  (void) memset((char_T *) &ext_mode_example_DWork,0,
                sizeof(D_Work_ext_mode_example));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    ext_mode_example_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }
}

/* Model terminate function */
void ext_mode_example_terminate(void)
{
  /* External mode */
  rtExtModeShutdown(2);
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  ext_mode_example_output(tid);
}

void MdlUpdate(int_T tid)
{
  ext_mode_example_update(tid);
}

void MdlInitializeSizes(void)
{
  ext_mode_example_M->Sizes.numContStates = (0);/* Number of continuous states */
  ext_mode_example_M->Sizes.numY = (0);/* Number of model outputs */
  ext_mode_example_M->Sizes.numU = (0);/* Number of model inputs */
  ext_mode_example_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ext_mode_example_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ext_mode_example_M->Sizes.numBlocks = (5);/* Number of blocks */
  ext_mode_example_M->Sizes.numBlockIO = (2);/* Number of block outputs */
  ext_mode_example_M->Sizes.numBlockPrms = (6);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  MdlInitialize();
}

RT_MODEL_ext_mode_example *ext_mode_example(void)
{
  ext_mode_example_initialize(1);
  return ext_mode_example_M;
}

void MdlTerminate(void)
{
  ext_mode_example_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
