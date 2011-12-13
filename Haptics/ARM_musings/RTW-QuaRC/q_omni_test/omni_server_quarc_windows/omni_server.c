/*
 * omni_server.c
 *
 * Real-Time Workshop code generation for Simulink model "omni_server.mdl".
 *
 * Model Version              : 1.8
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Wed Jun 17 13:11:59 2009
 */

#include "omni_server.h"
#include "omni_server_private.h"
#include <stdio.h>
#include "omni_server_dt.h"

t_stream omni_server_rtZt_stream = NULL;

/* Block signals (auto storage) */
BlockIO_omni_server omni_server_B;

/* Block states (auto storage) */
D_Work_omni_server omni_server_DWork;

/* Real-time model */
RT_MODEL_omni_server omni_server_M_;
RT_MODEL_omni_server *omni_server_M = &omni_server_M_;

/* Model output function */
void omni_server_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_TmpHiddenBufferAtStreamWrit[3];
  t_stream_ptr rtb_StreamCall_o1;
  t_stream_ptr rtb_StreamWrite_o1;
  boolean_T rtb_StreamRead_o3;
  boolean_T rtb_StreamRead_o4;

  /* S-Function Block: omni_server/Stream Call (stream_call_block) */
  {
    static const t_short endian_test = 0x0201;
    t_error result = 0;
    t_boolean close_flag = (FALSE != 0);
    rtb_StreamCall_o1 = NULL;
    switch (omni_server_DWork.StreamCall_State) {
     case STREAM_CALL_STATE_NOT_CONNECTED:
      {
        if (!close_flag) {
          result = stream_connect("tcpip://localhost:18000", true,
            omni_server_P.StreamCall_SendBufferSize,
            omni_server_P.StreamCall_ReceiveBufferSize,
            &omni_server_DWork.StreamCall_Stream);
          if (result == 0) {
            omni_server_DWork.StreamCall_State = STREAM_CALL_STATE_CONNECTED;
            stream_set_swap_bytes(omni_server_DWork.StreamCall_Stream, *(t_byte *)
                                  &endian_test !=
                                  omni_server_P.StreamCall_Endian);
            rtb_StreamCall_o1 = &omni_server_DWork.StreamCall_Stream;
          } else if (result == -QERR_WOULD_BLOCK) {
            omni_server_DWork.StreamCall_State = STREAM_CALL_STATE_CONNECTING;
            result = 0;
          }
        }
        break;
      }

     case STREAM_CALL_STATE_CONNECTING:
      {
        if (!close_flag) {
          const t_timeout timeout = { 0, 0, false };/* zero seconds */

          result = stream_poll(omni_server_DWork.StreamCall_Stream, &timeout,
                               STREAM_POLL_CONNECT);
          if (result > 0) {
            omni_server_DWork.StreamCall_State = STREAM_CALL_STATE_CONNECTED;
            stream_set_swap_bytes(omni_server_DWork.StreamCall_Stream, *(t_byte *)
                                  &endian_test !=
                                  omni_server_P.StreamCall_Endian);
            rtb_StreamCall_o1 = &omni_server_DWork.StreamCall_Stream;
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
        rtb_StreamCall_o1 = &omni_server_DWork.StreamCall_Stream;
        if (!close_flag) {
          break;
        }

        /* Fall through deliberately */
      }

     default:
      {
        t_error close_result = stream_close(omni_server_DWork.StreamCall_Stream);
        if (close_result == 0) {
          omni_server_DWork.StreamCall_State = STREAM_CALL_STATE_NOT_CONNECTED;
          omni_server_DWork.StreamCall_Stream = NULL;
          rtb_StreamCall_o1 = NULL;
        } else if (result == 0) {
          result = close_result;
        }
        break;
      }
    }

    omni_server_B.StreamCall_o2 = omni_server_DWork.StreamCall_State;
    omni_server_B.StreamCall_o3 = (int32_T) result;
  }

  /* S-Function (stream_read_block): '<Root>/Stream Read' */
  /* S-Function Block: omni_server/Stream Read (stream_read_block) */
  {
    t_error result;
    if (rtb_StreamCall_o1 != NULL) {
      result = stream_receive_unit_array(*rtb_StreamCall_o1,
        omni_server_B.StreamRead_o2, sizeof(real_T), 3);
      if (result == -QERR_WOULD_BLOCK) {
        result = 0;
      }

      /*
         if (result <= 0 && result != -QERR_WOULD_BLOCK) {
         memset(omni_server_B.StreamRead_o2, 0, 3 * sizeof(real_T));
         }
       */
    } else {
      memset(omni_server_B.StreamRead_o2, 0, 3 * sizeof(real_T));
      result = 0;
    }
  }

  /* Sin: '<Root>/Sine Wave' */
  omni_server_B.SineWave = sin(omni_server_P.SineWave_Freq *
    omni_server_M->Timing.t[0] + omni_server_P.SineWave_Phase) *
    omni_server_P.SineWave_Amp + omni_server_P.SineWave_Bias;

  /* SignalConversion: '<Root>/TmpHiddenBufferAtStream WriteInport2' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_TmpHiddenBufferAtStreamWrit[0] = omni_server_B.SineWave;
  rtb_TmpHiddenBufferAtStreamWrit[1] = omni_server_P.Constant_Value;
  rtb_TmpHiddenBufferAtStreamWrit[2] = omni_server_P.Constant_Value;

  /* S-Function (stream_write_block): '<Root>/Stream Write' incorporates:
   *  S-Function (stream_read_block): '<Root>/Stream Read'
   */
  {
    t_error result;
    if (((t_stream_ptr)rtb_StreamCall_o1) != NULL) {
      result = stream_send_unit_array(*((t_stream_ptr)rtb_StreamCall_o1),
        rtb_TmpHiddenBufferAtStreamWrit, sizeof(real_T), 3);
      if (result == 1) {
        t_error flush_result = stream_flush(*((t_stream_ptr)rtb_StreamCall_o1));
        if (flush_result < 0) {
          result = flush_result;
        }
      }

      if (result == -QERR_WOULD_BLOCK) {
        result = 0;
      }
    } else {
      result = 0;
    }

    rtb_StreamWrite_o1 = ((t_stream_ptr)rtb_StreamCall_o1);
    omni_server_B.StreamWrite_o2 = (int32_T) result;
  }

  UNUSED_PARAMETER(tid);
}

/* Model update function */
void omni_server_update(int_T tid)
{
  /* Update absolute time for base rate */
  if (!(++omni_server_M->Timing.clockTick0))
    ++omni_server_M->Timing.clockTickH0;
  omni_server_M->Timing.t[0] = omni_server_M->Timing.clockTick0 *
    omni_server_M->Timing.stepSize0 + omni_server_M->Timing.clockTickH0 *
    omni_server_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    if (!(++omni_server_M->Timing.clockTick1))
      ++omni_server_M->Timing.clockTickH1;
    omni_server_M->Timing.t[1] = omni_server_M->Timing.clockTick1 *
      omni_server_M->Timing.stepSize1 + omni_server_M->Timing.clockTickH1 *
      omni_server_M->Timing.stepSize1 * 4294967296.0;
  }

  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void omni_server_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));    /* initialize real-time model */
  (void) memset((char_T *)omni_server_M,0,
                sizeof(RT_MODEL_omni_server));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&omni_server_M->solverInfo,
                          &omni_server_M->Timing.simTimeStep);
    rtsiSetTPtr(&omni_server_M->solverInfo, &rtmGetTPtr(omni_server_M));
    rtsiSetStepSizePtr(&omni_server_M->solverInfo,
                       &omni_server_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&omni_server_M->solverInfo, (&rtmGetErrorStatus
      (omni_server_M)));
    rtsiSetRTModelPtr(&omni_server_M->solverInfo, omni_server_M);
  }

  rtsiSetSimTimeStep(&omni_server_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&omni_server_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = omni_server_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    omni_server_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    omni_server_M->Timing.sampleTimes = (&omni_server_M->
      Timing.sampleTimesArray[0]);
    omni_server_M->Timing.offsetTimes = (&omni_server_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    omni_server_M->Timing.sampleTimes[0] = (0.0);
    omni_server_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    omni_server_M->Timing.offsetTimes[0] = (0.0);
    omni_server_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(omni_server_M, &omni_server_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = omni_server_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    omni_server_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(omni_server_M, -1);
  omni_server_M->Timing.stepSize0 = 0.001;
  omni_server_M->Timing.stepSize1 = 0.001;

  /* external mode info */
  omni_server_M->Sizes.checksums[0] = (97270180U);
  omni_server_M->Sizes.checksums[1] = (442273077U);
  omni_server_M->Sizes.checksums[2] = (1472430018U);
  omni_server_M->Sizes.checksums[3] = (1895188483U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    omni_server_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &omni_server_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, omni_server_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(omni_server_M));
  }

  omni_server_M->solverInfoPtr = (&omni_server_M->solverInfo);
  omni_server_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&omni_server_M->solverInfo, 0.001);
  rtsiSetSolverMode(&omni_server_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  omni_server_M->ModelData.blockIO = ((void *) &omni_server_B);
  (void) memset(((void *) &omni_server_B),0,
                sizeof(BlockIO_omni_server));

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&omni_server_B.StreamRead_o2[0]);
    for (i = 0; i < 4; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }
  }

  /* parameters */
  omni_server_M->ModelData.defaultParam = ((real_T *) &omni_server_P);

  /* states (dwork) */
  omni_server_M->Work.dwork = ((void *) &omni_server_DWork);
  (void) memset((char_T *) &omni_server_DWork,0,
                sizeof(D_Work_omni_server));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    omni_server_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void omni_server_terminate(void)
{
  /* S-Function Block: omni_server/Stream Call (stream_call_block) */
  {
    if (omni_server_DWork.StreamCall_Stream != NULL) {
      stream_close(omni_server_DWork.StreamCall_Stream);
      omni_server_DWork.StreamCall_Stream = NULL;
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
  omni_server_output(tid);
}

void MdlUpdate(int_T tid)
{
  omni_server_update(tid);
}

void MdlInitializeSizes(void)
{
  omni_server_M->Sizes.numContStates = (0);/* Number of continuous states */
  omni_server_M->Sizes.numY = (0);     /* Number of model outputs */
  omni_server_M->Sizes.numU = (0);     /* Number of model inputs */
  omni_server_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  omni_server_M->Sizes.numSampTimes = (2);/* Number of sample times */
  omni_server_M->Sizes.numBlocks = (11);/* Number of blocks */
  omni_server_M->Sizes.numBlockIO = (5);/* Number of block outputs */
  omni_server_M->Sizes.numBlockPrms = (9);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  /* S-Function Block: omni_server/Stream Call (stream_call_block) */
  {
    omni_server_DWork.StreamCall_State = STREAM_CALL_STATE_NOT_CONNECTED;
    omni_server_DWork.StreamCall_Stream = NULL;
  }

  MdlInitialize();
}

RT_MODEL_omni_server *omni_server(void)
{
  omni_server_initialize(1);
  return omni_server_M;
}

void MdlTerminate(void)
{
  omni_server_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
