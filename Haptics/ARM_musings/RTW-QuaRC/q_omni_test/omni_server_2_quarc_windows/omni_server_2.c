/*
 * omni_server_2.c
 *
 * Real-Time Workshop code generation for Simulink model "omni_server_2.mdl".
 *
 * Model Version              : 1.9
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Mon Jun 15 11:30:14 2009
 */

#include "omni_server_2.h"
#include "omni_server_2_private.h"
#include <stdio.h>
#include "omni_server_2_dt.h"

t_stream omni_server_2_rtZt_stream = NULL;

/* Block signals (auto storage) */
BlockIO_omni_server_2 omni_server_2_B;

/* Block states (auto storage) */
D_Work_omni_server_2 omni_server_2_DWork;

/* Real-time model */
RT_MODEL_omni_server_2 omni_server_2_M_;
RT_MODEL_omni_server_2 *omni_server_2_M = &omni_server_2_M_;

/* Model output function */
void omni_server_2_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_SwitchControl;
  t_stream_ptr rtb_StreamCall_o1;
  t_stream_ptr rtb_StreamWrite_o1;

  /* S-Function Block: omni_server_2/Stream Call (stream_call_block) */
  {
    static const t_short endian_test = 0x0201;
    t_error result = 0;
    t_boolean close_flag = (FALSE != 0);
    rtb_StreamCall_o1 = NULL;
    switch (omni_server_2_DWork.StreamCall_State) {
     case STREAM_CALL_STATE_NOT_CONNECTED:
      {
        if (!close_flag) {
          result = stream_connect("tcpip://localhost:18002", true,
            omni_server_2_P.StreamCall_SendBufferSize,
            omni_server_2_P.StreamCall_ReceiveBufferSize,
            &omni_server_2_DWork.StreamCall_Stream);
          if (result == 0) {
            omni_server_2_DWork.StreamCall_State = STREAM_CALL_STATE_CONNECTED;
            stream_set_swap_bytes(omni_server_2_DWork.StreamCall_Stream,
                                  *(t_byte *) &endian_test !=
                                  omni_server_2_P.StreamCall_Endian);
            rtb_StreamCall_o1 = &omni_server_2_DWork.StreamCall_Stream;
          } else if (result == -QERR_WOULD_BLOCK) {
            omni_server_2_DWork.StreamCall_State = STREAM_CALL_STATE_CONNECTING;
            result = 0;
          }
        }
        break;
      }

     case STREAM_CALL_STATE_CONNECTING:
      {
        if (!close_flag) {
          const t_timeout timeout = { 0, 0, false };/* zero seconds */

          result = stream_poll(omni_server_2_DWork.StreamCall_Stream, &timeout,
                               STREAM_POLL_CONNECT);
          if (result > 0) {
            omni_server_2_DWork.StreamCall_State = STREAM_CALL_STATE_CONNECTED;
            stream_set_swap_bytes(omni_server_2_DWork.StreamCall_Stream,
                                  *(t_byte *) &endian_test !=
                                  omni_server_2_P.StreamCall_Endian);
            rtb_StreamCall_o1 = &omni_server_2_DWork.StreamCall_Stream;
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
        rtb_StreamCall_o1 = &omni_server_2_DWork.StreamCall_Stream;
        if (!close_flag) {
          break;
        }

        /* Fall through deliberately */
      }

     default:
      {
        t_error close_result = stream_close
          (omni_server_2_DWork.StreamCall_Stream);
        if (close_result == 0) {
          omni_server_2_DWork.StreamCall_State = STREAM_CALL_STATE_NOT_CONNECTED;
          omni_server_2_DWork.StreamCall_Stream = NULL;
          rtb_StreamCall_o1 = NULL;
        } else if (result == 0) {
          result = close_result;
        }
        break;
      }
    }

    omni_server_2_B.StreamCall_o2 = omni_server_2_DWork.StreamCall_State;
    omni_server_2_B.StreamCall_o3 = (int32_T) result;
  }

  /* Switch: '<S1>/SwitchControl' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<S1>/Constant'
   */
  if (omni_server_2_P.Constant_Value_k > omni_server_2_P.SwitchControl_Threshold)
  {
    rtb_SwitchControl = omni_server_2_P.Constant_Value;
  } else {
    rtb_SwitchControl = omni_server_2_P.Constant1_Value;
  }

  /* S-Function (stream_write_block): '<Root>/Stream Write' */
  {
    t_error result;
    if (rtb_StreamCall_o1 != NULL) {
      result = stream_send_unit_array(*rtb_StreamCall_o1, &rtb_SwitchControl,
        sizeof(real_T), 1);
      if (result == 1) {
        t_error flush_result = stream_flush(*rtb_StreamCall_o1);
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

    rtb_StreamWrite_o1 = rtb_StreamCall_o1;
    omni_server_2_B.StreamWrite_o2 = (int32_T) result;
  }

  UNUSED_PARAMETER(tid);
}

/* Model update function */
void omni_server_2_update(int_T tid)
{
  /* Update absolute time for base rate */
  if (!(++omni_server_2_M->Timing.clockTick0))
    ++omni_server_2_M->Timing.clockTickH0;
  omni_server_2_M->Timing.t[0] = omni_server_2_M->Timing.clockTick0 *
    omni_server_2_M->Timing.stepSize0 + omni_server_2_M->Timing.clockTickH0 *
    omni_server_2_M->Timing.stepSize0 * 4294967296.0;
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void omni_server_2_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));    /* initialize real-time model */
  (void) memset((char_T *)omni_server_2_M,0,
                sizeof(RT_MODEL_omni_server_2));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = omni_server_2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    omni_server_2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    omni_server_2_M->Timing.sampleTimes =
      (&omni_server_2_M->Timing.sampleTimesArray[0]);
    omni_server_2_M->Timing.offsetTimes =
      (&omni_server_2_M->Timing.offsetTimesArray[0]);

    /* task periods */
    omni_server_2_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    omni_server_2_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(omni_server_2_M, &omni_server_2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = omni_server_2_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    omni_server_2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(omni_server_2_M, -1);
  omni_server_2_M->Timing.stepSize0 = 0.001;

  /* external mode info */
  omni_server_2_M->Sizes.checksums[0] = (1614293473U);
  omni_server_2_M->Sizes.checksums[1] = (1408155260U);
  omni_server_2_M->Sizes.checksums[2] = (3692798696U);
  omni_server_2_M->Sizes.checksums[3] = (1809353806U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    omni_server_2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &omni_server_2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, omni_server_2_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(omni_server_2_M));
  }

  omni_server_2_M->solverInfoPtr = (&omni_server_2_M->solverInfo);
  omni_server_2_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&omni_server_2_M->solverInfo, 0.001);
  rtsiSetSolverMode(&omni_server_2_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  omni_server_2_M->ModelData.blockIO = ((void *) &omni_server_2_B);
  (void) memset(((void *) &omni_server_2_B),0,
                sizeof(BlockIO_omni_server_2));

  /* parameters */
  omni_server_2_M->ModelData.defaultParam = ((real_T *) &omni_server_2_P);

  /* states (dwork) */
  omni_server_2_M->Work.dwork = ((void *) &omni_server_2_DWork);
  (void) memset((char_T *) &omni_server_2_DWork,0,
                sizeof(D_Work_omni_server_2));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    omni_server_2_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void omni_server_2_terminate(void)
{
  /* S-Function Block: omni_server_2/Stream Call (stream_call_block) */
  {
    if (omni_server_2_DWork.StreamCall_Stream != NULL) {
      stream_close(omni_server_2_DWork.StreamCall_Stream);
      omni_server_2_DWork.StreamCall_Stream = NULL;
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
  omni_server_2_output(tid);
}

void MdlUpdate(int_T tid)
{
  omni_server_2_update(tid);
}

void MdlInitializeSizes(void)
{
  omni_server_2_M->Sizes.numContStates = (0);/* Number of continuous states */
  omni_server_2_M->Sizes.numY = (0);   /* Number of model outputs */
  omni_server_2_M->Sizes.numU = (0);   /* Number of model inputs */
  omni_server_2_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  omni_server_2_M->Sizes.numSampTimes = (1);/* Number of sample times */
  omni_server_2_M->Sizes.numBlocks = (11);/* Number of blocks */
  omni_server_2_M->Sizes.numBlockIO = (3);/* Number of block outputs */
  omni_server_2_M->Sizes.numBlockPrms = (8);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  /* S-Function Block: omni_server_2/Stream Call (stream_call_block) */
  {
    omni_server_2_DWork.StreamCall_State = STREAM_CALL_STATE_NOT_CONNECTED;
    omni_server_2_DWork.StreamCall_Stream = NULL;
  }

  MdlInitialize();
}

RT_MODEL_omni_server_2 *omni_server_2(void)
{
  omni_server_2_initialize(1);
  return omni_server_2_M;
}

void MdlTerminate(void)
{
  omni_server_2_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
