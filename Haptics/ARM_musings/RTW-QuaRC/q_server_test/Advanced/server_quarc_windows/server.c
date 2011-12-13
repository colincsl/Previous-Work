/*
 * server.c
 *
 * Real-Time Workshop code generation for Simulink model "server.mdl".
 *
 * Model Version              : 1.7
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Thu Jun 18 10:54:34 2009
 */

#include "server.h"
#include "server_private.h"
#include <stdio.h>
#include "server_dt.h"

t_stream server_rtZt_stream = NULL;

/* Block signals (auto storage) */
BlockIO_server server_B;

/* Block states (auto storage) */
D_Work_server server_DWork;

/* Real-time model */
RT_MODEL_server server_M_;
RT_MODEL_server *server_M = &server_M_;

/* Model output function */
void server_output(int_T tid)
{
  /* local block i/o variables */
  t_stream_ptr rtb_StreamPoll_o1;

  /* S-Function (stream_listen_block): '<Root>/Stream Listen' */
  /* S-Function Block: server/Stream Listen (stream_listen_block) */
  {
    stream_listen("tcpip://localhost:18000", true,
                  &server_DWork.StreamListen_Stream);
  }

  /* S-Function (stream_poll_block): '<Root>/Stream Poll' incorporates:
   *  S-Function (stream_listen_block): '<Root>/Stream Listen'
   */
  {
    t_int result = 0;
    t_timeout relative_timeout;
    t_timeout * timeout_pointer;
    timeout_pointer = timeout_get_timeout(&relative_timeout,
      server_P.StreamPoll_Timeout);
    result = stream_poll(*((t_stream_ptr)&server_DWork.StreamListen_Stream),
                         timeout_pointer, STREAM_POLL_RECEIVE);
    if (result > 0) {
      server_B.StreamPoll_o2 = ((result & STREAM_POLL_RECEIVE) != 0);
    } else {
      server_B.StreamPoll_o2 = false;
    }

    rtb_StreamPoll_o1 = ((t_stream_ptr)&server_DWork.StreamListen_Stream);
    server_B.StreamPoll_o3 = (int32_T) result;
  }

  UNUSED_PARAMETER(tid);
}

/* Model update function */
void server_update(int_T tid)
{
  /* Update absolute time for base rate */
  if (!(++server_M->Timing.clockTick0))
    ++server_M->Timing.clockTickH0;
  server_M->Timing.t[0] = server_M->Timing.clockTick0 *
    server_M->Timing.stepSize0 + server_M->Timing.clockTickH0 *
    server_M->Timing.stepSize0 * 4294967296.0;
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void server_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));    /* initialize real-time model */
  (void) memset((char_T *)server_M,0,
                sizeof(RT_MODEL_server));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = server_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    server_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    server_M->Timing.sampleTimes = (&server_M->Timing.sampleTimesArray[0]);
    server_M->Timing.offsetTimes = (&server_M->Timing.offsetTimesArray[0]);

    /* task periods */
    server_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    server_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(server_M, &server_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = server_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    server_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(server_M, -1);
  server_M->Timing.stepSize0 = 0.001;

  /* external mode info */
  server_M->Sizes.checksums[0] = (1223382796U);
  server_M->Sizes.checksums[1] = (215582823U);
  server_M->Sizes.checksums[2] = (3428488728U);
  server_M->Sizes.checksums[3] = (3237863954U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    server_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &server_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, server_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(server_M));
  }

  server_M->solverInfoPtr = (&server_M->solverInfo);
  server_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&server_M->solverInfo, 0.001);
  rtsiSetSolverMode(&server_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  server_M->ModelData.blockIO = ((void *) &server_B);
  (void) memset(((void *) &server_B),0,
                sizeof(BlockIO_server));

  /* parameters */
  server_M->ModelData.defaultParam = ((real_T *) &server_P);

  /* states (dwork) */
  server_M->Work.dwork = ((void *) &server_DWork);
  (void) memset((char_T *) &server_DWork,0,
                sizeof(D_Work_server));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    server_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void server_terminate(void)
{
  /* S-Function Block: server/Stream Listen (stream_listen_block) */
  {
    if (server_DWork.StreamListen_Stream != NULL) {
      stream_close(server_DWork.StreamListen_Stream);
      server_DWork.StreamListen_Stream = NULL;
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
  server_output(tid);
}

void MdlUpdate(int_T tid)
{
  server_update(tid);
}

void MdlInitializeSizes(void)
{
  server_M->Sizes.numContStates = (0); /* Number of continuous states */
  server_M->Sizes.numY = (0);          /* Number of model outputs */
  server_M->Sizes.numU = (0);          /* Number of model inputs */
  server_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  server_M->Sizes.numSampTimes = (1);  /* Number of sample times */
  server_M->Sizes.numBlocks = (4);     /* Number of blocks */
  server_M->Sizes.numBlockIO = (2);    /* Number of block outputs */
  server_M->Sizes.numBlockPrms = (2);  /* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  /* S-Function Block: server/Stream Listen (stream_listen_block) */
  {
    server_DWork.StreamListen_Stream = NULL;
  }

  MdlInitialize();
}

RT_MODEL_server *server(void)
{
  server_initialize(1);
  return server_M;
}

void MdlTerminate(void)
{
  server_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
