/*
 * Server.c
 *
 * Real-Time Workshop code generation for Simulink model "Server.mdl".
 *
 * Model Version              : 1.3
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Fri Jun 12 16:15:41 2009
 */

#include "Server.h"
#include "Server_private.h"
#include <stdio.h>
#include "Server_dt.h"

t_stream Server_rtZt_stream = NULL;

/* Block signals (auto storage) */
BlockIO_Server Server_B;

/* Block states (auto storage) */
D_Work_Server Server_DWork;

/* Real-time model */
RT_MODEL_Server Server_M_;
RT_MODEL_Server *Server_M = &Server_M_;

/* Model output function */
void Server_output(int_T tid)
{
  /* local block i/o variables */
  t_stream_ptr rtb_StreamAnswer_o1;
  t_stream_ptr rtb_StreamWrite_o1;

  /* S-Function Block: Server/Stream Answer (stream_answer_block) */
  {
    static const t_short endian_test = 0x0201;
    t_error result = 0;
    t_boolean close_listener = (FALSE != 0);
    t_boolean close_client = (FALSE != 0);
    rtb_StreamAnswer_o1 = NULL;
    switch (Server_DWork.StreamAnswer_State) {
     case STREAM_ANSWER_STATE_NOT_LISTENING:
      {
        if (!close_listener) {
          result = stream_listen("tcpip://localhost:18000", true,
            &Server_DWork.StreamAnswer_Listener);
          if (result == 0) {
            Server_DWork.StreamAnswer_State = STREAM_ANSWER_STATE_NOT_CONNECTED;
          }
        }
        break;
      }

     case STREAM_ANSWER_STATE_NOT_CONNECTED:
      {
        if (!close_client) {
          result = stream_accept(Server_DWork.StreamAnswer_Listener,
            Server_P.StreamAnswer_SendBufferSize,
            Server_P.StreamAnswer_ReceiveBufferSize,
            &Server_DWork.StreamAnswer_Client);
          if (result == 0) {
            Server_DWork.StreamAnswer_State = STREAM_ANSWER_STATE_CONNECTED;
            stream_set_swap_bytes(Server_DWork.StreamAnswer_Client, *(t_byte *)
                                  &endian_test != Server_P.StreamAnswer_Endian);
            rtb_StreamAnswer_o1 = &Server_DWork.StreamAnswer_Client;
          }
        }
        break;
      }

     case STREAM_ANSWER_STATE_CONNECTED:
      {
        rtb_StreamAnswer_o1 = &Server_DWork.StreamAnswer_Client;
        if (!close_client) {
          break;
        }

        /* Fall through deliberately */
      }

     default:
      {
        t_error close_result = stream_close(Server_DWork.StreamAnswer_Client);
        if (close_result == 0) {
          Server_DWork.StreamAnswer_Client = NULL;
          Server_DWork.StreamAnswer_State = STREAM_ANSWER_STATE_NOT_CONNECTED;
          rtb_StreamAnswer_o1 = NULL;
          if (close_listener) {
            close_result = stream_close(Server_DWork.StreamAnswer_Listener);
            if (close_result == 0) {
              Server_DWork.StreamAnswer_Listener = NULL;
              Server_DWork.StreamAnswer_State =
                STREAM_ANSWER_STATE_NOT_LISTENING;
            } else if (result == 0) {
              result = close_result;
            }
          }
        } else if (result == 0) {
          result = close_result;
        }
        break;
      }
    }

    Server_B.StreamAnswer_o2 = Server_DWork.StreamAnswer_State;
  }

  /* Sin: '<Root>/Sine Wave' */
  Server_B.SineWave = sin(Server_P.SineWave_Freq * Server_M->Timing.t[0] +
    Server_P.SineWave_Phase) * Server_P.SineWave_Amp + Server_P.SineWave_Bias;

  /* S-Function (stream_write_block): '<Root>/Stream Write' */
  {
    t_error result;
    if (rtb_StreamAnswer_o1 != NULL) {
      result = stream_send_unit_array(*rtb_StreamAnswer_o1, &Server_B.SineWave,
        sizeof(real_T), 1);
      if (result == 1) {
        stream_flush(*rtb_StreamAnswer_o1);
      }

      if (result == -QERR_WOULD_BLOCK) {
        result = 0;
      }
    }

    rtb_StreamWrite_o1 = rtb_StreamAnswer_o1;
  }

  UNUSED_PARAMETER(tid);
}

/* Model update function */
void Server_update(int_T tid)
{
  /* Update absolute time for base rate */
  if (!(++Server_M->Timing.clockTick0))
    ++Server_M->Timing.clockTickH0;
  Server_M->Timing.t[0] = Server_M->Timing.clockTick0 *
    Server_M->Timing.stepSize0 + Server_M->Timing.clockTickH0 *
    Server_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    if (!(++Server_M->Timing.clockTick1))
      ++Server_M->Timing.clockTickH1;
    Server_M->Timing.t[1] = Server_M->Timing.clockTick1 *
      Server_M->Timing.stepSize1 + Server_M->Timing.clockTickH1 *
      Server_M->Timing.stepSize1 * 4294967296.0;
  }

  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void Server_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));    /* initialize real-time model */
  (void) memset((char_T *)Server_M,0,
                sizeof(RT_MODEL_Server));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Server_M->solverInfo, &Server_M->Timing.simTimeStep);
    rtsiSetTPtr(&Server_M->solverInfo, &rtmGetTPtr(Server_M));
    rtsiSetStepSizePtr(&Server_M->solverInfo, &Server_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Server_M->solverInfo, (&rtmGetErrorStatus(Server_M)));
    rtsiSetRTModelPtr(&Server_M->solverInfo, Server_M);
  }

  rtsiSetSimTimeStep(&Server_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Server_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Server_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Server_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Server_M->Timing.sampleTimes = (&Server_M->Timing.sampleTimesArray[0]);
    Server_M->Timing.offsetTimes = (&Server_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Server_M->Timing.sampleTimes[0] = (0.0);
    Server_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    Server_M->Timing.offsetTimes[0] = (0.0);
    Server_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Server_M, &Server_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Server_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Server_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Server_M, -1);
  Server_M->Timing.stepSize0 = 0.001;
  Server_M->Timing.stepSize1 = 0.001;

  /* external mode info */
  Server_M->Sizes.checksums[0] = (3791027284U);
  Server_M->Sizes.checksums[1] = (1928235140U);
  Server_M->Sizes.checksums[2] = (386570905U);
  Server_M->Sizes.checksums[3] = (3697957716U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Server_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &Server_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, Server_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(Server_M));
  }

  Server_M->solverInfoPtr = (&Server_M->solverInfo);
  Server_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Server_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Server_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Server_M->ModelData.blockIO = ((void *) &Server_B);
  (void) memset(((void *) &Server_B),0,
                sizeof(BlockIO_Server));

  {
    ((real_T*)&Server_B.SineWave)[0] = 0.0;
  }

  /* parameters */
  Server_M->ModelData.defaultParam = ((real_T *) &Server_P);

  /* states (dwork) */
  Server_M->Work.dwork = ((void *) &Server_DWork);
  (void) memset((char_T *) &Server_DWork,0,
                sizeof(D_Work_Server));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    Server_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void Server_terminate(void)
{
  /* S-Function Block: Server/Stream Answer (stream_answer_block) */
  {
    if (Server_DWork.StreamAnswer_Client != NULL) {
      stream_close(Server_DWork.StreamAnswer_Client);
      Server_DWork.StreamAnswer_Client = NULL;
    }

    if (Server_DWork.StreamAnswer_Listener != NULL) {
      stream_close(Server_DWork.StreamAnswer_Listener);
      Server_DWork.StreamAnswer_Listener = NULL;
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
  Server_output(tid);
}

void MdlUpdate(int_T tid)
{
  Server_update(tid);
}

void MdlInitializeSizes(void)
{
  Server_M->Sizes.numContStates = (0); /* Number of continuous states */
  Server_M->Sizes.numY = (0);          /* Number of model outputs */
  Server_M->Sizes.numU = (0);          /* Number of model inputs */
  Server_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Server_M->Sizes.numSampTimes = (2);  /* Number of sample times */
  Server_M->Sizes.numBlocks = (4);     /* Number of blocks */
  Server_M->Sizes.numBlockIO = (2);    /* Number of block outputs */
  Server_M->Sizes.numBlockPrms = (8);  /* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  /* S-Function Block: Server/Stream Answer (stream_answer_block) */
  {
    Server_DWork.StreamAnswer_State = STREAM_ANSWER_STATE_NOT_LISTENING;
    Server_DWork.StreamAnswer_Listener = NULL;
    Server_DWork.StreamAnswer_Client = NULL;
  }

  MdlInitialize();
}

RT_MODEL_Server *Server(void)
{
  Server_initialize(1);
  return Server_M;
}

void MdlTerminate(void)
{
  Server_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
