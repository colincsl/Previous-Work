/*
 * Client.c
 *
 * Real-Time Workshop code generation for Simulink model "Client.mdl".
 *
 * Model Version              : 1.3
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Fri Jun 12 16:16:16 2009
 */

#include "Client.h"
#include "Client_private.h"
#include <stdio.h>
#include "Client_dt.h"

t_stream Client_rtZt_stream = NULL;

/* Block signals (auto storage) */
BlockIO_Client Client_B;

/* Block states (auto storage) */
D_Work_Client Client_DWork;

/* Real-time model */
RT_MODEL_Client Client_M_;
RT_MODEL_Client *Client_M = &Client_M_;

/* Model output function */
void Client_output(int_T tid)
{
  /* local block i/o variables */
  t_stream_ptr rtb_StreamCall_o1;
  t_stream_ptr rtb_StreamRead_o1;
  boolean_T rtb_StreamRead_o3;
  boolean_T rtb_StreamRead_o4;

  /* S-Function Block: Client/Stream Call (stream_call_block) */
  {
    static const t_short endian_test = 0x0201;
    t_error result = 0;
    t_boolean close_flag = (FALSE != 0);
    rtb_StreamCall_o1 = NULL;
    switch (Client_DWork.StreamCall_State) {
     case STREAM_CALL_STATE_NOT_CONNECTED:
      {
        if (!close_flag) {
          result = stream_connect("tcpip://localhost:18000", true,
            Client_P.StreamCall_SendBufferSize,
            Client_P.StreamCall_ReceiveBufferSize,
            &Client_DWork.StreamCall_Stream);
          if (result == 0) {
            Client_DWork.StreamCall_State = STREAM_CALL_STATE_CONNECTED;
            stream_set_swap_bytes(Client_DWork.StreamCall_Stream, *(t_byte *)
                                  &endian_test != Client_P.StreamCall_Endian);
            rtb_StreamCall_o1 = &Client_DWork.StreamCall_Stream;
          } else if (result == -QERR_WOULD_BLOCK) {
            Client_DWork.StreamCall_State = STREAM_CALL_STATE_CONNECTING;
            result = 0;
          }
        }
        break;
      }

     case STREAM_CALL_STATE_CONNECTING:
      {
        if (!close_flag) {
          const t_timeout timeout = { 0, 0, false };/* zero seconds */

          result = stream_poll(Client_DWork.StreamCall_Stream, &timeout,
                               STREAM_POLL_CONNECT);
          if (result > 0) {
            Client_DWork.StreamCall_State = STREAM_CALL_STATE_CONNECTED;
            stream_set_swap_bytes(Client_DWork.StreamCall_Stream, *(t_byte *)
                                  &endian_test != Client_P.StreamCall_Endian);
            rtb_StreamCall_o1 = &Client_DWork.StreamCall_Stream;
            result = 0;
            break;
          } else if (result == 0) {
            break;
          }
        }

        /* Fall through deliberately */
      }

     case STREAM_CALL_STATE_CONNECTED:
      {
        rtb_StreamCall_o1 = &Client_DWork.StreamCall_Stream;
        if (!close_flag) {
          break;
        }

        /* Fall through deliberately */
      }

     default:
      {
        t_error close_result = stream_close(Client_DWork.StreamCall_Stream);
        if (close_result == 0) {
          Client_DWork.StreamCall_State = STREAM_CALL_STATE_NOT_CONNECTED;
          Client_DWork.StreamCall_Stream = NULL;
          rtb_StreamCall_o1 = NULL;
        } else if (result == 0) {
          result = close_result;
        }
        break;
      }
    }

    Client_B.StreamCall_o2 = Client_DWork.StreamCall_State;
  }

  /* S-Function (stream_read_block): '<Root>/Stream Read' */
  /* S-Function Block: Client/Stream Read (stream_read_block) */
  {
    t_error result;
    if (rtb_StreamCall_o1 != NULL) {
      result = stream_receive_unit_array(*rtb_StreamCall_o1,
        &Client_B.StreamRead_o2, sizeof(real_T), 1);
      if (result == -QERR_WOULD_BLOCK) {
        result = 0;
      }

      /*
         if (result <= 0 && result != -QERR_WOULD_BLOCK) {
         memset(&Client_B.StreamRead_o2, 0, 1 * sizeof(real_T));
         }
       */
    } else {
      memset(&Client_B.StreamRead_o2, 0, 1 * sizeof(real_T));
      result = 0;
    }

    rtb_StreamRead_o1 = rtb_StreamCall_o1;
  }

  UNUSED_PARAMETER(tid);
}

/* Model update function */
void Client_update(int_T tid)
{
  /* Update absolute time for base rate */
  if (!(++Client_M->Timing.clockTick0))
    ++Client_M->Timing.clockTickH0;
  Client_M->Timing.t[0] = Client_M->Timing.clockTick0 *
    Client_M->Timing.stepSize0 + Client_M->Timing.clockTickH0 *
    Client_M->Timing.stepSize0 * 4294967296.0;
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void Client_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));    /* initialize real-time model */
  (void) memset((char_T *)Client_M,0,
                sizeof(RT_MODEL_Client));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Client_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    Client_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Client_M->Timing.sampleTimes = (&Client_M->Timing.sampleTimesArray[0]);
    Client_M->Timing.offsetTimes = (&Client_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Client_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    Client_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Client_M, &Client_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Client_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Client_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Client_M, -1);
  Client_M->Timing.stepSize0 = 0.001;

  /* external mode info */
  Client_M->Sizes.checksums[0] = (4276449988U);
  Client_M->Sizes.checksums[1] = (3803253132U);
  Client_M->Sizes.checksums[2] = (4182811404U);
  Client_M->Sizes.checksums[3] = (2165059169U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Client_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &Client_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, Client_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(Client_M));
  }

  Client_M->solverInfoPtr = (&Client_M->solverInfo);
  Client_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Client_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Client_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Client_M->ModelData.blockIO = ((void *) &Client_B);
  (void) memset(((void *) &Client_B),0,
                sizeof(BlockIO_Client));

  {
    ((real_T*)&Client_B.StreamRead_o2)[0] = 0.0;
  }

  /* parameters */
  Client_M->ModelData.defaultParam = ((real_T *) &Client_P);

  /* states (dwork) */
  Client_M->Work.dwork = ((void *) &Client_DWork);
  (void) memset((char_T *) &Client_DWork,0,
                sizeof(D_Work_Client));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    Client_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void Client_terminate(void)
{
  /* S-Function Block: Client/Stream Call (stream_call_block) */
  {
    if (Client_DWork.StreamCall_Stream != NULL) {
      stream_close(Client_DWork.StreamCall_Stream);
      Client_DWork.StreamCall_Stream = NULL;
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
  Client_output(tid);
}

void MdlUpdate(int_T tid)
{
  Client_update(tid);
}

void MdlInitializeSizes(void)
{
  Client_M->Sizes.numContStates = (0); /* Number of continuous states */
  Client_M->Sizes.numY = (0);          /* Number of model outputs */
  Client_M->Sizes.numU = (0);          /* Number of model inputs */
  Client_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Client_M->Sizes.numSampTimes = (1);  /* Number of sample times */
  Client_M->Sizes.numBlocks = (4);     /* Number of blocks */
  Client_M->Sizes.numBlockIO = (2);    /* Number of block outputs */
  Client_M->Sizes.numBlockPrms = (4);  /* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  /* S-Function Block: Client/Stream Call (stream_call_block) */
  {
    Client_DWork.StreamCall_State = STREAM_CALL_STATE_NOT_CONNECTED;
    Client_DWork.StreamCall_Stream = NULL;
  }

  MdlInitialize();
}

RT_MODEL_Client *Client(void)
{
  Client_initialize(1);
  return Client_M;
}

void MdlTerminate(void)
{
  Client_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
