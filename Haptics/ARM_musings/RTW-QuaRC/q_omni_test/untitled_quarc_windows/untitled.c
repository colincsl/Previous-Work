/*
 * untitled.c
 *
 * Real-Time Workshop code generation for Simulink model "untitled.mdl".
 *
 * Model Version              : 1.0
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Mon Jun 15 11:44:38 2009
 */

#include "untitled.h"
#include "untitled_private.h"
#include <stdio.h>
#include "untitled_dt.h"

/* Block states (auto storage) */
D_Work_untitled untitled_DWork;

/* Real-time model */
RT_MODEL_untitled untitled_M_;
RT_MODEL_untitled *untitled_M = &untitled_M_;

/* Model output function */
void untitled_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_Falcon_o1[3];
  boolean_T rtb_Falcon_o2[4];

  /* S-Function Block: untitled/Falcon (falcon_block) */
  {
    t_error result;
    double force_vector[3];
    double position[3];
    t_int read_buttons;
    force_vector[0] = 0.0;
    force_vector[1] = 0.0;
    force_vector[2] = 0.0;

    /* read the position and buttons, and output the requested force to the falcon */
    result = falcon_read_write(untitled_DWork.Falcon_Falcon, position,
      &read_buttons, force_vector);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(untitled_M, _rt_error_message);
      return;
    }

    rtb_Falcon_o1[0] = position[0];
    rtb_Falcon_o1[1] = position[1];
    rtb_Falcon_o1[2] = position[2];
    rtb_Falcon_o2[0] = ((read_buttons & 0x01) != 0);
    rtb_Falcon_o2[1] = ((read_buttons & 0x02) != 0);
    rtb_Falcon_o2[2] = ((read_buttons & 0x04) != 0);
    rtb_Falcon_o2[3] = ((read_buttons & 0x08) != 0);
  }

  UNUSED_PARAMETER(tid);
}

/* Model update function */
void untitled_update(int_T tid)
{
  /* Update absolute time for base rate */
  if (!(++untitled_M->Timing.clockTick0))
    ++untitled_M->Timing.clockTickH0;
  untitled_M->Timing.t[0] = untitled_M->Timing.clockTick0 *
    untitled_M->Timing.stepSize0 + untitled_M->Timing.clockTickH0 *
    untitled_M->Timing.stepSize0 * 4294967296.0;
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void untitled_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));    /* initialize real-time model */
  (void) memset((char_T *)untitled_M,0,
                sizeof(RT_MODEL_untitled));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = untitled_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    untitled_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    untitled_M->Timing.sampleTimes = (&untitled_M->Timing.sampleTimesArray[0]);
    untitled_M->Timing.offsetTimes = (&untitled_M->Timing.offsetTimesArray[0]);

    /* task periods */
    untitled_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    untitled_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(untitled_M, &untitled_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = untitled_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    untitled_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(untitled_M, -1);
  untitled_M->Timing.stepSize0 = 0.001;

  /* external mode info */
  untitled_M->Sizes.checksums[0] = (2958107259U);
  untitled_M->Sizes.checksums[1] = (2808822036U);
  untitled_M->Sizes.checksums[2] = (3537992539U);
  untitled_M->Sizes.checksums[3] = (3399565125U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(untitled_M));
  }

  untitled_M->solverInfoPtr = (&untitled_M->solverInfo);
  untitled_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&untitled_M->solverInfo, 0.001);
  rtsiSetSolverMode(&untitled_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* parameters */
  untitled_M->ModelData.defaultParam = ((real_T *) &untitled_P);

  /* states (dwork) */
  untitled_M->Work.dwork = ((void *) &untitled_DWork);
  (void) memset((char_T *) &untitled_DWork,0,
                sizeof(D_Work_untitled));

  {
    int_T i;
    real_T *dwork_ptr = (real_T *) &untitled_DWork.HILInitialize_AIMinimums[0];
    for (i = 0; i < 13; i++) {
      dwork_ptr[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    untitled_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* S-Function Block: untitled/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    hil_task_stop_all(untitled_DWork.HILInitialize_Card);
    hil_task_delete_all(untitled_DWork.HILInitialize_Card);
    is_switching = false;
    if ((untitled_P.HILInitialize_POTerminate && !is_switching) ||
        (untitled_P.HILInitialize_POExit && is_switching)) {
      untitled_DWork.HILInitialize_POValues[0] =
        untitled_P.HILInitialize_POFinal;
      untitled_DWork.HILInitialize_POValues[1] =
        untitled_P.HILInitialize_POFinal;
      untitled_DWork.HILInitialize_POValues[2] =
        untitled_P.HILInitialize_POFinal;
      result = hil_write_pwm(untitled_DWork.HILInitialize_Card,
        &untitled_P.HILInitialize_POChannels[0], 3U,
        &untitled_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
      }
    }

    hil_close(untitled_DWork.HILInitialize_Card);
    untitled_DWork.HILInitialize_Card = NULL;
  }

  /* S-Function Block: untitled/Falcon (falcon_block) */
  {
    t_error result;
    result = falcon_close(untitled_DWork.Falcon_Falcon);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(untitled_M, _rt_error_message);
      return;
    }
  }

  /* External mode */
  rtExtModeShutdown(1);
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  untitled_output(tid);
}

void MdlUpdate(int_T tid)
{
  untitled_update(tid);
}

void MdlInitializeSizes(void)
{
  untitled_M->Sizes.numContStates = (0);/* Number of continuous states */
  untitled_M->Sizes.numY = (0);        /* Number of model outputs */
  untitled_M->Sizes.numU = (0);        /* Number of model inputs */
  untitled_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  untitled_M->Sizes.numSampTimes = (1);/* Number of sample times */
  untitled_M->Sizes.numBlocks = (2);   /* Number of blocks */
  untitled_M->Sizes.numBlockIO = (0);  /* Number of block outputs */
  untitled_M->Sizes.numBlockPrms = (46);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  /* S-Function Block: untitled/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("phantom_omni", "0", &untitled_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(untitled_M, _rt_error_message);
      return;
    }

    is_switching = false;
    if ((untitled_P.HILInitialize_AIPStart && !is_switching) ||
        (untitled_P.HILInitialize_AIPEnter && is_switching)) {
      untitled_DWork.HILInitialize_AIMinimums[0] =
        untitled_P.HILInitialize_AILow;
      untitled_DWork.HILInitialize_AIMinimums[1] =
        untitled_P.HILInitialize_AILow;
      untitled_DWork.HILInitialize_AIMaximums[0] =
        untitled_P.HILInitialize_AIHigh;
      untitled_DWork.HILInitialize_AIMaximums[1] =
        untitled_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges(untitled_DWork.HILInitialize_Card,
        &untitled_P.HILInitialize_AIChannels[0], 2U,
        &untitled_DWork.HILInitialize_AIMinimums[0],
        &untitled_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }

    if ((untitled_P.HILInitialize_EIStart && !is_switching) ||
        (untitled_P.HILInitialize_EIEnter && is_switching)) {
      untitled_DWork.HILInitialize_InitialEICounts[0] =
        untitled_P.HILInitialize_EIInitial;
      untitled_DWork.HILInitialize_InitialEICounts[1] =
        untitled_P.HILInitialize_EIInitial;
      untitled_DWork.HILInitialize_InitialEICounts[2] =
        untitled_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(untitled_DWork.HILInitialize_Card,
        &untitled_P.HILInitialize_EIChannels[0], 3U,
        &untitled_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }

    if ((untitled_P.HILInitialize_POStart && !is_switching) ||
        (untitled_P.HILInitialize_POEnter && is_switching)) {
      untitled_DWork.HILInitialize_POValues[0] =
        untitled_P.HILInitialize_POInitial;
      untitled_DWork.HILInitialize_POValues[1] =
        untitled_P.HILInitialize_POInitial;
      untitled_DWork.HILInitialize_POValues[2] =
        untitled_P.HILInitialize_POInitial;
      result = hil_write_pwm(untitled_DWork.HILInitialize_Card,
        &untitled_P.HILInitialize_POChannels[0], 3U,
        &untitled_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(untitled_M, _rt_error_message);
        return;
      }
    }
  }

  /* S-Function Block: untitled/Falcon (falcon_block) */
  {
    t_error result;
    result = falcon_open(&untitled_DWork.Falcon_Falcon);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(untitled_M, _rt_error_message);
      return;
    }
  }

  MdlInitialize();
}

RT_MODEL_untitled *untitled(void)
{
  untitled_initialize(1);
  return untitled_M;
}

void MdlTerminate(void)
{
  untitled_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
