/*
 * Demo_vehicle.c
 *
 * Real-Time Workshop code generation for Simulink model "Demo_vehicle.mdl".
 *
 * Model Version              : 1.35
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Tue Jun 16 13:46:58 2009
 */

#include "Demo_vehicle.h"
#include "Demo_vehicle_private.h"
#include <stdio.h>
#include "Demo_vehicle_dt.h"

/* Block signals (auto storage) */
BlockIO_Demo_vehicle Demo_vehicle_B;

/* Block states (auto storage) */
D_Work_Demo_vehicle Demo_vehicle_DWork;

/* Real-time model */
RT_MODEL_Demo_vehicle Demo_vehicle_M_;
RT_MODEL_Demo_vehicle *Demo_vehicle_M = &Demo_vehicle_M_;
static void rate_monotonic_scheduler(void);

/* Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Demo_vehicle_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Demo_vehicle_M, 1));
}

time_T rt_SimUpdateDiscreteEvents(int_T rtmNumSampTimes,
  void *rtmTimingData,
  int_T *rtmSampleHitPtr,
  int_T *rtmPerTaskSampleHits)
{
  rtmSampleHitPtr[1] = rtmStepTask(Demo_vehicle_M, 1);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/* This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchagne data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a safe and deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  Demo_vehicle_M->Timing.RateInteraction.TID0_1 =
    (Demo_vehicle_M->Timing.TaskCounters.TID[1] == 0);

  /* update PerTaskSampleHits matrix for non-inline sfcn */
  Demo_vehicle_M->Timing.perTaskSampleHits[1] =
    Demo_vehicle_M->Timing.RateInteraction.TID0_1;

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  if (++Demo_vehicle_M->Timing.TaskCounters.TID[1] == 100) {/* Sample time: [0.1s, 0.0s] */
    Demo_vehicle_M->Timing.TaskCounters.TID[1] = 0;
  }

  Demo_vehicle_M->Timing.sampleHits[1] =
    (Demo_vehicle_M->Timing.TaskCounters.TID[1] == 0);
}

/* Model output function for TID0 */
void Demo_vehicle_output0(int_T tid)   /* Sample time: [0.001s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_Gain1;
  boolean_T rtb_Falcon_o2[4];

  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Memory: '<Root>/Memory1' */
  Demo_vehicle_B.Memory1[0] = Demo_vehicle_DWork.Memory1_PreviousInput[0];
  Demo_vehicle_B.Memory1[1] = Demo_vehicle_DWork.Memory1_PreviousInput[1];
  Demo_vehicle_B.Memory1[2] = Demo_vehicle_DWork.Memory1_PreviousInput[2];

  /* Gain: '<Root>/Gain1' incorporates:
   *  Lookup2D: '<Root>/Lookup Table (2-D)'
   */
  rtb_Gain1 = Demo_vehicle_P.Gain1_Gain * rt_Lookup2D_Normal
    (&Demo_vehicle_P.LookupTable2D_RowIdx[0], 100,
     &Demo_vehicle_P.LookupTable2D_ColIdx[0], 100,
     &Demo_vehicle_P.LookupTable2D_Table[0], Demo_vehicle_B.Memory1[0],
     Demo_vehicle_B.Memory1[1]);

  /* Saturate: '<Root>/Saturation' */
  Demo_vehicle_B.Saturation = rt_SATURATE(rtb_Gain1,
    Demo_vehicle_P.Saturation_LowerSat, Demo_vehicle_P.Saturation_UpperSat);

  /* S-Function Block: Demo_vehicle/Falcon (falcon_block) */
  {
    t_error result;
    double force_vector[3];
    double position[3];
    t_int read_buttons;
    force_vector[0] = Demo_vehicle_B.Saturation;
    force_vector[1] = Demo_vehicle_P.Constant1_Value;
    force_vector[2] = Demo_vehicle_P.Constant1_Value;

    /* read the position and buttons, and output the requested force to the falcon */
    result = falcon_read_write(Demo_vehicle_DWork.Falcon_Falcon, position,
      &read_buttons, force_vector);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Demo_vehicle_M, _rt_error_message);
      return;
    }

    Demo_vehicle_B.Falcon_o1[0] = position[0];
    Demo_vehicle_B.Falcon_o1[1] = position[1];
    Demo_vehicle_B.Falcon_o1[2] = position[2];
    rtb_Falcon_o2[0] = ((read_buttons & 0x01) != 0);
    rtb_Falcon_o2[1] = ((read_buttons & 0x02) != 0);
    rtb_Falcon_o2[2] = ((read_buttons & 0x04) != 0);
    rtb_Falcon_o2[3] = ((read_buttons & 0x08) != 0);
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   *  Memory: '<Root>/Memory'
   */
  Demo_vehicle_B.Sum[0] = Demo_vehicle_P.Constant_Value[0] +
    Demo_vehicle_DWork.Memory_PreviousInput[0];
  Demo_vehicle_B.Sum[1] = Demo_vehicle_P.Constant_Value[1] +
    Demo_vehicle_DWork.Memory_PreviousInput[1];
  Demo_vehicle_B.Sum[2] = Demo_vehicle_P.Constant_Value[2] +
    Demo_vehicle_DWork.Memory_PreviousInput[2];

  /* Embedded MATLAB: '<Root>/Embedded MATLAB Function' */

  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  Demo_vehicle_B.v[0] = Demo_vehicle_B.Sum[0] + Demo_vehicle_B.Falcon_o1[0] *
    cos(Demo_vehicle_B.Sum[2]) * 0.01;
  Demo_vehicle_B.v[1] = Demo_vehicle_B.Sum[1] + Demo_vehicle_B.Falcon_o1[0] *
    sin(Demo_vehicle_B.Sum[2]) * 0.01;
  Demo_vehicle_B.v[2] = Demo_vehicle_B.Sum[2] - 0.1 * 0.0;

  /* Stop: '<Root>/Stop Simulation' */
  if (rtb_Falcon_o2[0] || rtb_Falcon_o2[1] || rtb_Falcon_o2[2] || rtb_Falcon_o2
      [3]) {
    rtmSetStopRequested(Demo_vehicle_M, 1);
  }

  /* RateTransition: '<Root>/Rate Transition' */
  if (Demo_vehicle_M->Timing.RateInteraction.TID0_1) {
    Demo_vehicle_B.RateTransition[0] = Demo_vehicle_B.Memory1[0];
    Demo_vehicle_B.RateTransition[1] = Demo_vehicle_B.Memory1[1];
    Demo_vehicle_B.RateTransition[2] = Demo_vehicle_B.Memory1[2];
  }

  /* Gain: '<Root>/Gain' */
  Demo_vehicle_B.Gain[0] = Demo_vehicle_P.Gain_Gain * Demo_vehicle_B.v[0];
  Demo_vehicle_B.Gain[1] = Demo_vehicle_P.Gain_Gain * Demo_vehicle_B.v[1];
  Demo_vehicle_B.Gain[2] = Demo_vehicle_P.Gain_Gain * Demo_vehicle_B.v[2];
  UNUSED_PARAMETER(tid);
}

/* Model update function for TID0 */
void Demo_vehicle_update0(int_T tid)   /* Sample time: [0.001s, 0.0s] */
{
  /* Update for Memory: '<Root>/Memory1' */
  Demo_vehicle_DWork.Memory1_PreviousInput[0] = Demo_vehicle_B.Gain[0];
  Demo_vehicle_DWork.Memory1_PreviousInput[1] = Demo_vehicle_B.Gain[1];
  Demo_vehicle_DWork.Memory1_PreviousInput[2] = Demo_vehicle_B.Gain[2];

  /* Update for Memory: '<Root>/Memory' */
  Demo_vehicle_DWork.Memory_PreviousInput[0] = Demo_vehicle_B.v[0];
  Demo_vehicle_DWork.Memory_PreviousInput[1] = Demo_vehicle_B.v[1];
  Demo_vehicle_DWork.Memory_PreviousInput[2] = Demo_vehicle_B.v[2];

  /* Update absolute time */
  if (!(++Demo_vehicle_M->Timing.clockTick0))
    ++Demo_vehicle_M->Timing.clockTickH0;
  Demo_vehicle_M->Timing.t[0] = Demo_vehicle_M->Timing.clockTick0 *
    Demo_vehicle_M->Timing.stepSize0 + Demo_vehicle_M->Timing.clockTickH0 *
    Demo_vehicle_M->Timing.stepSize0 * 4294967296.0;
  UNUSED_PARAMETER(tid);
}

/* Model output function for TID1 */
void Demo_vehicle_output1(int_T tid)   /* Sample time: [0.1s, 0.0s] */
{
  /* Gain: '<Root>/Gain2' */
  Demo_vehicle_B.Gain2 = Demo_vehicle_P.Gain2_Gain *
    Demo_vehicle_B.RateTransition[2];

  /* SignalConversion: '<Root>/TmpHiddenBufferAtVR SinkInport1' */
  Demo_vehicle_B.TmpHiddenBufferAtVRSinkInport1[0] = 0.0;
  Demo_vehicle_B.TmpHiddenBufferAtVRSinkInport1[1] = Demo_vehicle_B.Gain2;
  Demo_vehicle_B.TmpHiddenBufferAtVRSinkInport1[2] = 0.0;
  Demo_vehicle_B.TmpHiddenBufferAtVRSinkInport1[3] = Demo_vehicle_B.Gain2;

  /* SignalConversion: '<Root>/TmpHiddenBufferAtVR SinkInport2' */
  Demo_vehicle_B.TmpHiddenBufferAtVRSinkInport2[0] =
    Demo_vehicle_B.RateTransition[0];
  Demo_vehicle_B.TmpHiddenBufferAtVRSinkInport2[1] = 0.0;
  Demo_vehicle_B.TmpHiddenBufferAtVRSinkInport2[2] =
    Demo_vehicle_B.RateTransition[1];
  UNUSED_PARAMETER(tid);
}

/* Model update function for TID1 */
void Demo_vehicle_update1(int_T tid)   /* Sample time: [0.1s, 0.0s] */
{
  /* Update absolute time */
  if (!(++Demo_vehicle_M->Timing.clockTick1))
    ++Demo_vehicle_M->Timing.clockTickH1;
  Demo_vehicle_M->Timing.t[1] = Demo_vehicle_M->Timing.clockTick1 *
    Demo_vehicle_M->Timing.stepSize1 + Demo_vehicle_M->Timing.clockTickH1 *
    Demo_vehicle_M->Timing.stepSize1 * 4294967296.0;
  UNUSED_PARAMETER(tid);
}

void Demo_vehicle_output(int_T tid)
{
  switch (tid) {
   case 0 :
    Demo_vehicle_output0(0);
    break;

   case 1 :
    Demo_vehicle_output1(1);
    break;

   default :
    break;
  }
}

void Demo_vehicle_update(int_T tid)
{
  switch (tid) {
   case 0 :
    Demo_vehicle_update0(0);
    break;

   case 1 :
    Demo_vehicle_update1(1);
    break;

   default :
    break;
  }
}

/* Model initialize function */
void Demo_vehicle_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));    /* initialize real-time model */
  (void) memset((char_T *)Demo_vehicle_M,0,
                sizeof(RT_MODEL_Demo_vehicle));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Demo_vehicle_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Demo_vehicle_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Demo_vehicle_M->Timing.sampleTimes =
      (&Demo_vehicle_M->Timing.sampleTimesArray[0]);
    Demo_vehicle_M->Timing.offsetTimes =
      (&Demo_vehicle_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Demo_vehicle_M->Timing.sampleTimes[0] = (0.001);
    Demo_vehicle_M->Timing.sampleTimes[1] = (0.1);

    /* task offsets */
    Demo_vehicle_M->Timing.offsetTimes[0] = (0.0);
    Demo_vehicle_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Demo_vehicle_M, &Demo_vehicle_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Demo_vehicle_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = Demo_vehicle_M->Timing.perTaskSampleHitsArray;
    Demo_vehicle_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    Demo_vehicle_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Demo_vehicle_M, -1);
  Demo_vehicle_M->Timing.stepSize0 = 0.001;
  Demo_vehicle_M->Timing.stepSize1 = 0.1;

  /* external mode info */
  Demo_vehicle_M->Sizes.checksums[0] = (3569660184U);
  Demo_vehicle_M->Sizes.checksums[1] = (3777522294U);
  Demo_vehicle_M->Sizes.checksums[2] = (4208076019U);
  Demo_vehicle_M->Sizes.checksums[3] = (2501304379U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    Demo_vehicle_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &Demo_vehicle_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, Demo_vehicle_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(Demo_vehicle_M));
  }

  Demo_vehicle_M->solverInfoPtr = (&Demo_vehicle_M->solverInfo);
  Demo_vehicle_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Demo_vehicle_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Demo_vehicle_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  Demo_vehicle_M->ModelData.blockIO = ((void *) &Demo_vehicle_B);

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&Demo_vehicle_B.Memory1[0]);
    for (i = 0; i < 17; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    pVoidBlockIORegion = (void *)(&Demo_vehicle_B.v[0]);
    for (i = 0; i < 3; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    pVoidBlockIORegion = (void *)
      (&Demo_vehicle_B.TmpHiddenBufferAtVRSinkInport1[0]);
    for (i = 0; i < 7; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }
  }

  /* parameters */
  Demo_vehicle_M->ModelData.defaultParam = ((real_T *) &Demo_vehicle_P);

  /* states (dwork) */
  Demo_vehicle_M->Work.dwork = ((void *) &Demo_vehicle_DWork);
  (void) memset((char_T *) &Demo_vehicle_DWork,0,
                sizeof(D_Work_Demo_vehicle));

  {
    int_T i;
    real_T *dwork_ptr = (real_T *) &Demo_vehicle_DWork.Memory1_PreviousInput[0];
    for (i = 0; i < 2006; i++) {
      dwork_ptr[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    Demo_vehicle_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }
}

/* Model terminate function */
void Demo_vehicle_terminate(void)
{
  /* S-Function Block: Demo_vehicle/Falcon (falcon_block) */
  {
    t_error result;
    result = falcon_close(Demo_vehicle_DWork.Falcon_Falcon);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Demo_vehicle_M, _rt_error_message);
      return;
    }
  }

  /* External mode */
  rtExtModeShutdown(2);
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Demo_vehicle_output(tid);
}

void MdlUpdate(int_T tid)
{
  Demo_vehicle_update(tid);
}

void MdlInitializeSizes(void)
{
  Demo_vehicle_M->Sizes.numContStates = (0);/* Number of continuous states */
  Demo_vehicle_M->Sizes.numY = (0);    /* Number of model outputs */
  Demo_vehicle_M->Sizes.numU = (0);    /* Number of model inputs */
  Demo_vehicle_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Demo_vehicle_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Demo_vehicle_M->Sizes.numBlocks = (23);/* Number of blocks */
  Demo_vehicle_M->Sizes.numBlockIO = (10);/* Number of block outputs */
  Demo_vehicle_M->Sizes.numBlockPrms = (10218);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for Memory: '<Root>/Memory1' */
  Demo_vehicle_DWork.Memory1_PreviousInput[0] = Demo_vehicle_P.Memory1_X0;
  Demo_vehicle_DWork.Memory1_PreviousInput[1] = Demo_vehicle_P.Memory1_X0;
  Demo_vehicle_DWork.Memory1_PreviousInput[2] = Demo_vehicle_P.Memory1_X0;

  /* InitializeConditions for Memory: '<Root>/Memory' */
  Demo_vehicle_DWork.Memory_PreviousInput[0] = Demo_vehicle_P.Memory_X0;
  Demo_vehicle_DWork.Memory_PreviousInput[1] = Demo_vehicle_P.Memory_X0;
  Demo_vehicle_DWork.Memory_PreviousInput[2] = Demo_vehicle_P.Memory_X0;

  /* Initialize code for chart: '<Root>/Embedded MATLAB Function' */
  Demo_vehicle_DWork.is_active_c2_Demo_vehicle = 0U;
}

void MdlStart(void)
{
  /* S-Function Block: Demo_vehicle/Falcon (falcon_block) */
  {
    t_error result;
    result = falcon_open(&Demo_vehicle_DWork.Falcon_Falcon);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Demo_vehicle_M, _rt_error_message);
      return;
    }
  }

  MdlInitialize();
}

RT_MODEL_Demo_vehicle *Demo_vehicle(void)
{
  Demo_vehicle_initialize(1);
  return Demo_vehicle_M;
}

void MdlTerminate(void)
{
  Demo_vehicle_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
