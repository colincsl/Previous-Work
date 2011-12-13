/*
 * client.c
 *
 * Real-Time Workshop code generation for Simulink model "client.mdl".
 *
 * Model Version              : 1.4
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Thu Jun 18 10:49:53 2009
 */

#include "client.h"
#include "client_private.h"
#include <stdio.h>
#include "client_dt.h"

t_stream client_rtZt_stream = NULL;

/* Block signals (auto storage) */
BlockIO_client client_B;

/* Block states (auto storage) */
D_Work_client client_DWork;

/* Real-time model */
RT_MODEL_client client_M_;
RT_MODEL_client *client_M = &client_M_;

/* Model output function */
void client_output(int_T tid)
{
  /* local block i/o variables */
  t_stream_ptr rtb_StreamFlush_o1;

  /* S-Function (stream_connect_block): '<Root>/Stream Connect' */
  /* S-Function Block: client/Stream Connect (stream_connect_block) */
  {
    t_error result;
    result = stream_connect("tcpip://localhost:18000", true,
      client_P.StreamConnect_SendBufferSize,
      client_P.StreamConnect_ReceiveBufferSize,
      &client_DWork.StreamConnect_Stream);
    if (result == 0) {
      static const t_short endian_test = 0x0201;
      result = stream_set_swap_bytes(client_DWork.StreamConnect_Stream, *(t_byte
        *)&endian_test != client_P.StreamConnect_Endian);
    }
  }

  /* Sin: '<Root>/Sine Wave' */
  client_B.SineWave = sin(client_P.SineWave_Freq * client_M->Timing.t[0] +
    client_P.SineWave_Phase) * client_P.SineWave_Amp + client_P.SineWave_Bias;

  /* S-Function (stream_send_block): '<Root>/Stream Send' incorporates:
   *  S-Function (stream_connect_block): '<Root>/Stream Connect'
   */
  {
    stream_send_unit_array(*((t_stream_ptr)&client_DWork.StreamConnect_Stream),
      &client_B.SineWave, sizeof(real_T), 1);
  }

  /* S-Function (stream_flush_block): '<Root>/Stream Flush' incorporates:
   *  S-Function (stream_send_block): '<Root>/Stream Send'
   *  S-Function (stream_connect_block): '<Root>/Stream Connect'
   */
  /* S-Function Block: client/Stream Flush (stream_flush_block) */
  {
    t_error result;
    result = stream_flush(*((t_stream_ptr)((t_stream_ptr)&
      client_DWork.StreamConnect_Stream)));
    rtb_StreamFlush_o1 = ((t_stream_ptr)((t_stream_ptr)&
      client_DWork.StreamConnect_Stream));
    client_B.StreamFlush_o2 = (int32_T) result;
  }

  UNUSED_PARAMETER(tid);
}

/* Model update function */
void client_update(int_T tid)
{
  /* Update absolute time for base rate */
  if (!(++client_M->Timing.clockTick0))
    ++client_M->Timing.clockTickH0;
  client_M->Timing.t[0] = client_M->Timing.clockTick0 *
    client_M->Timing.stepSize0 + client_M->Timing.clockTickH0 *
    client_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    if (!(++client_M->Timing.clockTick1))
      ++client_M->Timing.clockTickH1;
    client_M->Timing.t[1] = client_M->Timing.clockTick1 *
      client_M->Timing.stepSize1 + client_M->Timing.clockTickH1 *
      client_M->Timing.stepSize1 * 4294967296.0;
  }

  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void client_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));    /* initialize real-time model */
  (void) memset((char_T *)client_M,0,
                sizeof(RT_MODEL_client));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&client_M->solverInfo, &client_M->Timing.simTimeStep);
    rtsiSetTPtr(&client_M->solverInfo, &rtmGetTPtr(client_M));
    rtsiSetStepSizePtr(&client_M->solverInfo, &client_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&client_M->solverInfo, (&rtmGetErrorStatus(client_M)));
    rtsiSetRTModelPtr(&client_M->solverInfo, client_M);
  }

  rtsiSetSimTimeStep(&client_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&client_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = client_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    client_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    client_M->Timing.sampleTimes = (&client_M->Timing.sampleTimesArray[0]);
    client_M->Timing.offsetTimes = (&client_M->Timing.offsetTimesArray[0]);

    /* task periods */
    client_M->Timing.sampleTimes[0] = (0.0);
    client_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    client_M->Timing.offsetTimes[0] = (0.0);
    client_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(client_M, &client_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = client_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    client_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(client_M, -1);
  client_M->Timing.stepSize0 = 0.001;
  client_M->Timing.stepSize1 = 0.001;

  /* external mode info */
  client_M->Sizes.checksums[0] = (1656169623U);
  client_M->Sizes.checksums[1] = (3324520885U);
  client_M->Sizes.checksums[2] = (852771084U);
  client_M->Sizes.checksums[3] = (3229346152U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    client_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &client_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, client_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(client_M));
  }

  client_M->solverInfoPtr = (&client_M->solverInfo);
  client_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&client_M->solverInfo, 0.001);
  rtsiSetSolverMode(&client_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  client_M->ModelData.blockIO = ((void *) &client_B);
  (void) memset(((void *) &client_B),0,
                sizeof(BlockIO_client));

  {
    ((real_T*)&client_B.SineWave)[0] = 0.0;
  }

  /* parameters */
  client_M->ModelData.defaultParam = ((real_T *) &client_P);

  /* states (dwork) */
  client_M->Work.dwork = ((void *) &client_DWork);
  (void) memset((char_T *) &client_DWork,0,
                sizeof(D_Work_client));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    client_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void client_terminate(void)
{
  /* S-Function Block: client/Stream Connect (stream_connect_block) */
  {
    if (client_DWork.StreamConnect_Stream != NULL) {
      stream_close(client_DWork.StreamConnect_Stream);
      client_DWork.StreamConnect_Stream = NULL;
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
  client_output(tid);
}

void MdlUpdate(int_T tid)
{
  client_update(tid);
}

void MdlInitializeSizes(void)
{
  client_M->Sizes.numContStates = (0); /* Number of continuous states */
  client_M->Sizes.numY = (0);          /* Number of model outputs */
  client_M->Sizes.numU = (0);          /* Number of model inputs */
  client_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  client_M->Sizes.numSampTimes = (2);  /* Number of sample times */
  client_M->Sizes.numBlocks = (6);     /* Number of blocks */
  client_M->Sizes.numBlockIO = (2);    /* Number of block outputs */
  client_M->Sizes.numBlockPrms = (8);  /* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  /* S-Function Block: client/Stream Connect (stream_connect_block) */
  {
    client_DWork.StreamConnect_Stream = NULL;
  }

  MdlInitialize();
}

RT_MODEL_client *client(void)
{
  client_initialize(1);
  return client_M;
}

void MdlTerminate(void)
{
  client_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
