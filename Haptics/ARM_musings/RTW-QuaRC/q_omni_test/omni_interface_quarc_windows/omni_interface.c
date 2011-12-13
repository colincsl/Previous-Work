/*
 * omni_interface.c
 *
 * Real-Time Workshop code generation for Simulink model "omni_interface.mdl".
 *
 * Model Version              : 1.22
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Mon Jun 15 11:31:32 2009
 */

#include "omni_interface.h"
#include "omni_interface_private.h"
#include <stdio.h>
#include "omni_interface_dt.h"

t_stream omni_interface_rtZt_stream = NULL;

/* Block signals (auto storage) */
BlockIO_omni_interface omni_interface_B;

/* Block states (auto storage) */
D_Work_omni_interface omni_interface_DWork;

/* Real-time model */
RT_MODEL_omni_interface omni_interface_M_;
RT_MODEL_omni_interface *omni_interface_M = &omni_interface_M_;

/* Model output function */
void omni_interface_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_HILRead_o3[2];
  real_T rtb_Saturation[3];
  real_T rtb_StreamRead1_o2[3];
  t_stream_ptr rtb_StreamAnswer_o1;
  t_stream_ptr rtb_StreamWrite_o1;
  t_stream_ptr rtb_StreamAnswer1_o1;
  t_stream_ptr rtb_StreamRead1_o1;
  uint8_T rtb_StreamAnswer1_o2;
  boolean_T rtb_LogicalOperator2[2];
  boolean_T rtb_StreamRead1_o4;
  boolean_T rtb_StreamRead1_o3;

  /* S-Function Block: omni_interface/HIL Read (hil_read_block) */
  {
    t_error result = hil_read(omni_interface_DWork.HILInitialize_Card,
      omni_interface_P.HILRead_AnalogChannels, 3U,
      omni_interface_P.HILRead_EncoderChannels, 3U,
      omni_interface_P.HILRead_DigitalChannels, 2U,
      NULL, 0U,
      rtb_Saturation,
      &omni_interface_DWork.HILRead_EncoderBuffer[0],
      &omni_interface_DWork.HILRead_DigitalBuffer[0],
      NULL
      );
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(omni_interface_M, _rt_error_message);
    } else {
      rtb_StreamRead1_o2[0] = omni_interface_DWork.HILRead_EncoderBuffer[0];
      rtb_StreamRead1_o2[1] = omni_interface_DWork.HILRead_EncoderBuffer[1];
      rtb_StreamRead1_o2[2] = omni_interface_DWork.HILRead_EncoderBuffer[2];
      rtb_HILRead_o3[0] = omni_interface_DWork.HILRead_DigitalBuffer[0];
      rtb_HILRead_o3[1] = omni_interface_DWork.HILRead_DigitalBuffer[1];
    }
  }

  /* Gain: '<Root>/Gain2' incorporates:
   *  Bias: '<Root>/Bias3'
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gear Ratio'
   */
  omni_interface_B.Gain2[0] = (rtb_StreamRead1_o2[0] +
    omni_interface_P.Bias3_Bias[0]) * omni_interface_P.Gain1_Gain *
    omni_interface_P.GearRatio_Gain[0] * omni_interface_P.Gain2_Gain;
  omni_interface_B.Gain2[1] = (rtb_StreamRead1_o2[1] +
    omni_interface_P.Bias3_Bias[1]) * omni_interface_P.Gain1_Gain *
    omni_interface_P.GearRatio_Gain[1] * omni_interface_P.Gain2_Gain;
  omni_interface_B.Gain2[2] = (rtb_StreamRead1_o2[2] +
    omni_interface_P.Bias3_Bias[2]) * omni_interface_P.Gain1_Gain *
    omni_interface_P.GearRatio_Gain[2] * omni_interface_P.Gain2_Gain;

  /* Switch: '<S8>/Reset' incorporates:
   *  Constant: '<S8>/Initial Condition'
   *  MinMax: '<S2>/MinMax'
   *  UnitDelay: '<S8>/FixPt Unit Delay1'
   */
  if (0.0 != 0.0) {
    omni_interface_B.Reset = omni_interface_P.InitialCondition_Value;
  } else {
    omni_interface_B.Reset = rt_MIN(omni_interface_B.Gain2[0],
      omni_interface_DWork.FixPtUnitDelay1_DSTATE);
  }

  /* Switch: '<S9>/Reset' incorporates:
   *  Constant: '<S9>/Initial Condition'
   *  MinMax: '<S3>/MinMax'
   *  UnitDelay: '<S9>/FixPt Unit Delay1'
   */
  if (0.0 != 0.0) {
    omni_interface_B.Reset_c = omni_interface_P.InitialCondition_Value_d;
  } else {
    omni_interface_B.Reset_c = rt_MIN(omni_interface_B.Gain2[1],
      omni_interface_DWork.FixPtUnitDelay1_DSTATE_i);
  }

  /* Switch: '<S10>/Reset' incorporates:
   *  Constant: '<S10>/Initial Condition'
   *  MinMax: '<S4>/MinMax'
   *  UnitDelay: '<S10>/FixPt Unit Delay1'
   */
  if (0.0 != 0.0) {
    omni_interface_B.Reset_n = omni_interface_P.InitialCondition_Value_g;
  } else {
    omni_interface_B.Reset_n = rt_MIN(omni_interface_B.Gain2[2],
      omni_interface_DWork.FixPtUnitDelay1_DSTATE_a);
  }

  /* Switch: '<S11>/Reset' incorporates:
   *  Constant: '<S11>/Initial Condition'
   *  MinMax: '<S5>/MinMax'
   *  UnitDelay: '<S11>/FixPt Unit Delay1'
   */
  if (0.0 != 0.0) {
    omni_interface_B.Reset_c3 = omni_interface_P.InitialCondition_Value_gd;
  } else {
    omni_interface_B.Reset_c3 = rt_MAX(omni_interface_B.Gain2[0],
      omni_interface_DWork.FixPtUnitDelay1_DSTATE_e);
  }

  /* Switch: '<S12>/Reset' incorporates:
   *  Constant: '<S12>/Initial Condition'
   *  MinMax: '<S6>/MinMax'
   *  UnitDelay: '<S12>/FixPt Unit Delay1'
   */
  if (0.0 != 0.0) {
    omni_interface_B.Reset_l = omni_interface_P.InitialCondition_Value_m;
  } else {
    omni_interface_B.Reset_l = rt_MAX(omni_interface_B.Gain2[1],
      omni_interface_DWork.FixPtUnitDelay1_DSTATE_eh);
  }

  /* Switch: '<S13>/Reset' incorporates:
   *  Constant: '<S13>/Initial Condition'
   *  MinMax: '<S7>/MinMax'
   *  UnitDelay: '<S13>/FixPt Unit Delay1'
   */
  if (0.0 != 0.0) {
    omni_interface_B.Reset_i = omni_interface_P.InitialCondition_Value_f;
  } else {
    omni_interface_B.Reset_i = rt_MAX(omni_interface_B.Gain2[2],
      omni_interface_DWork.FixPtUnitDelay1_DSTATE_d);
  }

  /* S-Function Block: omni_interface/Stream Answer (stream_answer_block) */
  {
    static const t_short endian_test = 0x0201;
    t_error result = 0;
    t_boolean close_listener = (FALSE != 0);
    t_boolean close_client = (FALSE != 0);
    rtb_StreamAnswer_o1 = NULL;
    switch (omni_interface_DWork.StreamAnswer_State) {
     case STREAM_ANSWER_STATE_NOT_LISTENING:
      {
        if (!close_listener) {
          result = stream_listen("tcpip://localhost:18000", true,
            &omni_interface_DWork.StreamAnswer_Listener);
          if (result == 0) {
            omni_interface_DWork.StreamAnswer_State =
              STREAM_ANSWER_STATE_NOT_CONNECTED;
          }
        }
        break;
      }

     case STREAM_ANSWER_STATE_NOT_CONNECTED:
      {
        if (!close_client) {
          result = stream_accept(omni_interface_DWork.StreamAnswer_Listener,
            omni_interface_P.StreamAnswer_SendBufferSize,
            omni_interface_P.StreamAnswer_ReceiveBufferSize,
            &omni_interface_DWork.StreamAnswer_Client);
          if (result == 0) {
            omni_interface_DWork.StreamAnswer_State =
              STREAM_ANSWER_STATE_CONNECTED;
            stream_set_swap_bytes(omni_interface_DWork.StreamAnswer_Client,
                                  *(t_byte *) &endian_test !=
                                  omni_interface_P.StreamAnswer_Endian);
            rtb_StreamAnswer_o1 = &omni_interface_DWork.StreamAnswer_Client;
          }
        }
        break;
      }

     case STREAM_ANSWER_STATE_CONNECTED:
      {
        rtb_StreamAnswer_o1 = &omni_interface_DWork.StreamAnswer_Client;
        if (!close_client) {
          break;
        }

        /* Fall through deliberately */
      }

     default:
      {
        t_error close_result = stream_close
          (omni_interface_DWork.StreamAnswer_Client);
        if (close_result == 0) {
          omni_interface_DWork.StreamAnswer_Client = NULL;
          omni_interface_DWork.StreamAnswer_State =
            STREAM_ANSWER_STATE_NOT_CONNECTED;
          rtb_StreamAnswer_o1 = NULL;
          if (close_listener) {
            close_result = stream_close
              (omni_interface_DWork.StreamAnswer_Listener);
            if (close_result == 0) {
              omni_interface_DWork.StreamAnswer_Listener = NULL;
              omni_interface_DWork.StreamAnswer_State =
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

    rtb_StreamAnswer1_o2 = omni_interface_DWork.StreamAnswer_State;
    omni_interface_B.StreamAnswer_o3 = (int32_T) result;
  }

  /* Logic: '<Root>/Logical Operator' incorporates:
   *  Logic: '<Root>/Logical Operator1'
   *  RelationalOperator: '<S1>/Compare'
   */
  omni_interface_B.LogicalOperator = ((rtb_StreamAnswer1_o2 != 0U) &&
    (!((omni_interface_B.StreamAnswer_o3 != 0) != 0U)));

  /* S-Function (stream_write_block): '<Root>/Stream Write' */
  {
    t_error result;
    if (rtb_StreamAnswer_o1 != NULL) {
      result = stream_send_unit_array(*rtb_StreamAnswer_o1,
        omni_interface_B.Gain2, sizeof(real_T), 3);
      if (result == 1) {
        stream_flush(*rtb_StreamAnswer_o1);
      }

      if (result == -QERR_WOULD_BLOCK) {
        result = 0;
      }
    }

    rtb_StreamWrite_o1 = rtb_StreamAnswer_o1;
  }

  /* S-Function (stream_read_block): '<Root>/Stream Read' */
  /* S-Function Block: omni_interface/Stream Read (stream_read_block) */
  {
    t_error result;
    if (rtb_StreamWrite_o1 != NULL) {
      result = stream_receive_unit_array(*rtb_StreamWrite_o1,
        omni_interface_B.StreamRead_o2, sizeof(real_T), 3);
      omni_interface_B.StreamRead_o3 = (result > 0);
      if (result == -QERR_WOULD_BLOCK) {
        result = 0;
      }

      /*
         if (result <= 0 && result != -QERR_WOULD_BLOCK) {
         memset(omni_interface_B.StreamRead_o2, 0, 3 * sizeof(real_T));
         }
       */
    } else {
      memset(omni_interface_B.StreamRead_o2, 0, 3 * sizeof(real_T));
      omni_interface_B.StreamRead_o3 = false;
      result = 0;
    }

    rtb_StreamRead1_o1 = rtb_StreamWrite_o1;
  }

  /* S-Function Block: omni_interface/Stream Answer1 (stream_answer_block) */
  {
    static const t_short endian_test = 0x0201;
    t_error result = 0;
    t_boolean close_listener = (FALSE != 0);
    t_boolean close_client = (FALSE != 0);
    rtb_StreamAnswer1_o1 = NULL;
    switch (omni_interface_DWork.StreamAnswer1_State) {
     case STREAM_ANSWER_STATE_NOT_LISTENING:
      {
        if (!close_listener) {
          result = stream_listen("tcpip://localhost:18002", true,
            &omni_interface_DWork.StreamAnswer1_Listener);
          if (result == 0) {
            omni_interface_DWork.StreamAnswer1_State =
              STREAM_ANSWER_STATE_NOT_CONNECTED;
          }
        }
        break;
      }

     case STREAM_ANSWER_STATE_NOT_CONNECTED:
      {
        if (!close_client) {
          result = stream_accept(omni_interface_DWork.StreamAnswer1_Listener,
            omni_interface_P.StreamAnswer1_SendBufferSize,
            omni_interface_P.StreamAnswer1_ReceiveBufferSize,
            &omni_interface_DWork.StreamAnswer1_Client);
          if (result == 0) {
            omni_interface_DWork.StreamAnswer1_State =
              STREAM_ANSWER_STATE_CONNECTED;
            stream_set_swap_bytes(omni_interface_DWork.StreamAnswer1_Client,
                                  *(t_byte *) &endian_test !=
                                  omni_interface_P.StreamAnswer1_Endian);
            rtb_StreamAnswer1_o1 = &omni_interface_DWork.StreamAnswer1_Client;
          }
        }
        break;
      }

     case STREAM_ANSWER_STATE_CONNECTED:
      {
        rtb_StreamAnswer1_o1 = &omni_interface_DWork.StreamAnswer1_Client;
        if (!close_client) {
          break;
        }

        /* Fall through deliberately */
      }

     default:
      {
        t_error close_result = stream_close
          (omni_interface_DWork.StreamAnswer1_Client);
        if (close_result == 0) {
          omni_interface_DWork.StreamAnswer1_Client = NULL;
          omni_interface_DWork.StreamAnswer1_State =
            STREAM_ANSWER_STATE_NOT_CONNECTED;
          rtb_StreamAnswer1_o1 = NULL;
          if (close_listener) {
            close_result = stream_close
              (omni_interface_DWork.StreamAnswer1_Listener);
            if (close_result == 0) {
              omni_interface_DWork.StreamAnswer1_Listener = NULL;
              omni_interface_DWork.StreamAnswer1_State =
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

    omni_interface_B.StreamAnswer1_o3 = (int32_T) result;
  }

  /* Gain: '<Root>/Gain' */
  rtb_StreamRead1_o2[0] = omni_interface_P.Gain_Gain[0] *
    omni_interface_B.StreamRead_o2[0];
  rtb_StreamRead1_o2[1] = omni_interface_P.Gain_Gain[1] *
    omni_interface_B.StreamRead_o2[1];
  rtb_StreamRead1_o2[2] = omni_interface_P.Gain_Gain[2] *
    omni_interface_B.StreamRead_o2[2];

  /* Product: '<Root>/Product' */
  rtb_Saturation[0] = (int32_T)omni_interface_B.LogicalOperator ?
    rtb_StreamRead1_o2[0] : 0.0;
  rtb_Saturation[1] = (int32_T)omni_interface_B.LogicalOperator ?
    rtb_StreamRead1_o2[1] : 0.0;
  rtb_Saturation[2] = (int32_T)omni_interface_B.LogicalOperator ?
    rtb_StreamRead1_o2[2] : 0.0;

  /* Saturate: '<Root>/Saturation' */
  rtb_Saturation[0] = rt_SATURATE(rtb_Saturation[0],
    omni_interface_P.Saturation_LowerSat, omni_interface_P.Saturation_UpperSat);
  rtb_Saturation[1] = rt_SATURATE(rtb_Saturation[1],
    omni_interface_P.Saturation_LowerSat, omni_interface_P.Saturation_UpperSat);
  rtb_Saturation[2] = rt_SATURATE(rtb_Saturation[2],
    omni_interface_P.Saturation_LowerSat, omni_interface_P.Saturation_UpperSat);

  /* S-Function Block: omni_interface/HIL Write (hil_write_block) */
  {
    t_error result;
    result = hil_write(omni_interface_DWork.HILInitialize_Card,
                       NULL, 0U,
                       omni_interface_P.HILWrite_PWMChannels, 3U,
                       NULL, 0U,
                       NULL, 0U,
                       NULL,
                       rtb_Saturation,
                       NULL,
                       NULL
                       );
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(omni_interface_M, _rt_error_message);
    }
  }

  /* S-Function (stream_read_block): '<Root>/Stream Read1' */
  /* S-Function Block: omni_interface/Stream Read1 (stream_read_block) */
  {
    t_error result;
    if (rtb_StreamAnswer1_o1 != NULL) {
      result = stream_receive_unit_array(*rtb_StreamAnswer1_o1,
        rtb_StreamRead1_o2, sizeof(real_T), 3);
      if (result == -QERR_WOULD_BLOCK) {
        result = 0;
      }

      /*
         if (result <= 0 && result != -QERR_WOULD_BLOCK) {
         memset(rtb_StreamRead1_o2, 0, 3 * sizeof(real_T));
         }
       */
    } else {
      memset(rtb_StreamRead1_o2, 0, 3 * sizeof(real_T));
      result = 0;
    }

    rtb_StreamRead1_o1 = rtb_StreamAnswer1_o1;
  }

  /* Logic: '<Root>/Logical Operator2' */
  rtb_LogicalOperator2[0] = ((rtb_HILRead_o3[0] != 0.0) || (0.0 != 0.0) ||
    (rtb_StreamRead1_o2[1] != 0.0));
  rtb_LogicalOperator2[1] = ((rtb_HILRead_o3[1] != 0.0) || (0.0 != 0.0) ||
    (rtb_StreamRead1_o2[1] != 0.0));

  /* Stop: '<Root>/Stop Simulation' */
  if (rtb_LogicalOperator2[0] || rtb_LogicalOperator2[1]) {
    rtmSetStopRequested(omni_interface_M, 1);
  }

  UNUSED_PARAMETER(tid);
}

/* Model update function */
void omni_interface_update(int_T tid)
{
  /* Update for UnitDelay: '<S8>/FixPt Unit Delay1' */
  omni_interface_DWork.FixPtUnitDelay1_DSTATE = omni_interface_B.Reset;

  /* Update for UnitDelay: '<S9>/FixPt Unit Delay1' */
  omni_interface_DWork.FixPtUnitDelay1_DSTATE_i = omni_interface_B.Reset_c;

  /* Update for UnitDelay: '<S10>/FixPt Unit Delay1' */
  omni_interface_DWork.FixPtUnitDelay1_DSTATE_a = omni_interface_B.Reset_n;

  /* Update for UnitDelay: '<S11>/FixPt Unit Delay1' */
  omni_interface_DWork.FixPtUnitDelay1_DSTATE_e = omni_interface_B.Reset_c3;

  /* Update for UnitDelay: '<S12>/FixPt Unit Delay1' */
  omni_interface_DWork.FixPtUnitDelay1_DSTATE_eh = omni_interface_B.Reset_l;

  /* Update for UnitDelay: '<S13>/FixPt Unit Delay1' */
  omni_interface_DWork.FixPtUnitDelay1_DSTATE_d = omni_interface_B.Reset_i;

  /* Update absolute time for base rate */
  if (!(++omni_interface_M->Timing.clockTick0))
    ++omni_interface_M->Timing.clockTickH0;
  omni_interface_M->Timing.t[0] = omni_interface_M->Timing.clockTick0 *
    omni_interface_M->Timing.stepSize0 + omni_interface_M->Timing.clockTickH0 *
    omni_interface_M->Timing.stepSize0 * 4294967296.0;
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void omni_interface_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));    /* initialize real-time model */
  (void) memset((char_T *)omni_interface_M,0,
                sizeof(RT_MODEL_omni_interface));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = omni_interface_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    omni_interface_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    omni_interface_M->Timing.sampleTimes =
      (&omni_interface_M->Timing.sampleTimesArray[0]);
    omni_interface_M->Timing.offsetTimes =
      (&omni_interface_M->Timing.offsetTimesArray[0]);

    /* task periods */
    omni_interface_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    omni_interface_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(omni_interface_M, &omni_interface_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = omni_interface_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    omni_interface_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(omni_interface_M, -1);
  omni_interface_M->Timing.stepSize0 = 0.001;

  /* external mode info */
  omni_interface_M->Sizes.checksums[0] = (3515672156U);
  omni_interface_M->Sizes.checksums[1] = (4130000490U);
  omni_interface_M->Sizes.checksums[2] = (2703472843U);
  omni_interface_M->Sizes.checksums[3] = (3284165155U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
    omni_interface_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &omni_interface_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, omni_interface_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(omni_interface_M));
  }

  omni_interface_M->solverInfoPtr = (&omni_interface_M->solverInfo);
  omni_interface_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&omni_interface_M->solverInfo, 0.001);
  rtsiSetSolverMode(&omni_interface_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  omni_interface_M->ModelData.blockIO = ((void *) &omni_interface_B);
  (void) memset(((void *) &omni_interface_B),0,
                sizeof(BlockIO_omni_interface));

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&omni_interface_B.Gain2[0]);
    for (i = 0; i < 12; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }
  }

  /* parameters */
  omni_interface_M->ModelData.defaultParam = ((real_T *) &omni_interface_P);

  /* states (dwork) */
  omni_interface_M->Work.dwork = ((void *) &omni_interface_DWork);
  (void) memset((char_T *) &omni_interface_DWork,0,
                sizeof(D_Work_omni_interface));

  {
    int_T i;
    real_T *dwork_ptr = (real_T *) &omni_interface_DWork.FixPtUnitDelay1_DSTATE;
    for (i = 0; i < 19; i++) {
      dwork_ptr[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    omni_interface_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }
}

/* Model terminate function */
void omni_interface_terminate(void)
{
  /* S-Function Block: omni_interface/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    hil_task_stop_all(omni_interface_DWork.HILInitialize_Card);
    hil_task_delete_all(omni_interface_DWork.HILInitialize_Card);
    is_switching = false;
    if ((omni_interface_P.HILInitialize_POTerminate && !is_switching) ||
        (omni_interface_P.HILInitialize_POExit && is_switching)) {
      omni_interface_DWork.HILInitialize_POValues[0] =
        omni_interface_P.HILInitialize_POFinal;
      omni_interface_DWork.HILInitialize_POValues[1] =
        omni_interface_P.HILInitialize_POFinal;
      omni_interface_DWork.HILInitialize_POValues[2] =
        omni_interface_P.HILInitialize_POFinal;
      result = hil_write_pwm(omni_interface_DWork.HILInitialize_Card,
        &omni_interface_P.HILInitialize_POChannels[0], 3U,
        &omni_interface_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(omni_interface_M, _rt_error_message);
      }
    }

    hil_close(omni_interface_DWork.HILInitialize_Card);
    omni_interface_DWork.HILInitialize_Card = NULL;
  }

  /* S-Function Block: omni_interface/Stream Answer (stream_answer_block) */
  {
    if (omni_interface_DWork.StreamAnswer_Client != NULL) {
      stream_close(omni_interface_DWork.StreamAnswer_Client);
      omni_interface_DWork.StreamAnswer_Client = NULL;
    }

    if (omni_interface_DWork.StreamAnswer_Listener != NULL) {
      stream_close(omni_interface_DWork.StreamAnswer_Listener);
      omni_interface_DWork.StreamAnswer_Listener = NULL;
    }
  }

  /* S-Function Block: omni_interface/Stream Answer1 (stream_answer_block) */
  {
    if (omni_interface_DWork.StreamAnswer1_Client != NULL) {
      stream_close(omni_interface_DWork.StreamAnswer1_Client);
      omni_interface_DWork.StreamAnswer1_Client = NULL;
    }

    if (omni_interface_DWork.StreamAnswer1_Listener != NULL) {
      stream_close(omni_interface_DWork.StreamAnswer1_Listener);
      omni_interface_DWork.StreamAnswer1_Listener = NULL;
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
  omni_interface_output(tid);
}

void MdlUpdate(int_T tid)
{
  omni_interface_update(tid);
}

void MdlInitializeSizes(void)
{
  omni_interface_M->Sizes.numContStates = (0);/* Number of continuous states */
  omni_interface_M->Sizes.numY = (0);  /* Number of model outputs */
  omni_interface_M->Sizes.numU = (0);  /* Number of model inputs */
  omni_interface_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  omni_interface_M->Sizes.numSampTimes = (1);/* Number of sample times */
  omni_interface_M->Sizes.numBlocks = (68);/* Number of blocks */
  omni_interface_M->Sizes.numBlockIO = (12);/* Number of block outputs */
  omni_interface_M->Sizes.numBlockPrms = (92);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for UnitDelay: '<S8>/FixPt Unit Delay1' */
  omni_interface_DWork.FixPtUnitDelay1_DSTATE =
    omni_interface_P.FixPtUnitDelay1_X0;

  /* InitializeConditions for UnitDelay: '<S9>/FixPt Unit Delay1' */
  omni_interface_DWork.FixPtUnitDelay1_DSTATE_i =
    omni_interface_P.FixPtUnitDelay1_X0_d;

  /* InitializeConditions for UnitDelay: '<S10>/FixPt Unit Delay1' */
  omni_interface_DWork.FixPtUnitDelay1_DSTATE_a =
    omni_interface_P.FixPtUnitDelay1_X0_p;

  /* InitializeConditions for UnitDelay: '<S11>/FixPt Unit Delay1' */
  omni_interface_DWork.FixPtUnitDelay1_DSTATE_e =
    omni_interface_P.FixPtUnitDelay1_X0_j;

  /* InitializeConditions for UnitDelay: '<S12>/FixPt Unit Delay1' */
  omni_interface_DWork.FixPtUnitDelay1_DSTATE_eh =
    omni_interface_P.FixPtUnitDelay1_X0_j0;

  /* InitializeConditions for UnitDelay: '<S13>/FixPt Unit Delay1' */
  omni_interface_DWork.FixPtUnitDelay1_DSTATE_d =
    omni_interface_P.FixPtUnitDelay1_X0_d1;
}

void MdlStart(void)
{
  /* S-Function Block: omni_interface/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("phantom_omni", "0",
                      &omni_interface_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(omni_interface_M, _rt_error_message);
      return;
    }

    is_switching = false;
    if ((omni_interface_P.HILInitialize_AIPStart && !is_switching) ||
        (omni_interface_P.HILInitialize_AIPEnter && is_switching)) {
      omni_interface_DWork.HILInitialize_AIMinimums[0] =
        omni_interface_P.HILInitialize_AILow;
      omni_interface_DWork.HILInitialize_AIMinimums[1] =
        omni_interface_P.HILInitialize_AILow;
      omni_interface_DWork.HILInitialize_AIMaximums[0] =
        omni_interface_P.HILInitialize_AIHigh;
      omni_interface_DWork.HILInitialize_AIMaximums[1] =
        omni_interface_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges
        (omni_interface_DWork.HILInitialize_Card,
         &omni_interface_P.HILInitialize_AIChannels[0], 2U,
         &omni_interface_DWork.HILInitialize_AIMinimums[0],
         &omni_interface_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(omni_interface_M, _rt_error_message);
        return;
      }
    }

    if ((omni_interface_P.HILInitialize_EIStart && !is_switching) ||
        (omni_interface_P.HILInitialize_EIEnter && is_switching)) {
      omni_interface_DWork.HILInitialize_InitialEICounts[0] =
        omni_interface_P.HILInitialize_EIInitial;
      omni_interface_DWork.HILInitialize_InitialEICounts[1] =
        omni_interface_P.HILInitialize_EIInitial;
      omni_interface_DWork.HILInitialize_InitialEICounts[2] =
        omni_interface_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(omni_interface_DWork.HILInitialize_Card,
        &omni_interface_P.HILInitialize_EIChannels[0], 3U,
        &omni_interface_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(omni_interface_M, _rt_error_message);
        return;
      }
    }

    if ((omni_interface_P.HILInitialize_POStart && !is_switching) ||
        (omni_interface_P.HILInitialize_POEnter && is_switching)) {
      omni_interface_DWork.HILInitialize_POValues[0] =
        omni_interface_P.HILInitialize_POInitial;
      omni_interface_DWork.HILInitialize_POValues[1] =
        omni_interface_P.HILInitialize_POInitial;
      omni_interface_DWork.HILInitialize_POValues[2] =
        omni_interface_P.HILInitialize_POInitial;
      result = hil_write_pwm(omni_interface_DWork.HILInitialize_Card,
        &omni_interface_P.HILInitialize_POChannels[0], 3U,
        &omni_interface_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(omni_interface_M, _rt_error_message);
        return;
      }
    }
  }

  /* S-Function Block: omni_interface/Stream Answer (stream_answer_block) */
  {
    omni_interface_DWork.StreamAnswer_State = STREAM_ANSWER_STATE_NOT_LISTENING;
    omni_interface_DWork.StreamAnswer_Listener = NULL;
    omni_interface_DWork.StreamAnswer_Client = NULL;
  }

  /* S-Function Block: omni_interface/Stream Answer1 (stream_answer_block) */
  {
    omni_interface_DWork.StreamAnswer1_State = STREAM_ANSWER_STATE_NOT_LISTENING;
    omni_interface_DWork.StreamAnswer1_Listener = NULL;
    omni_interface_DWork.StreamAnswer1_Client = NULL;
  }

  MdlInitialize();
}

RT_MODEL_omni_interface *omni_interface(void)
{
  omni_interface_initialize(1);
  return omni_interface_M;
}

void MdlTerminate(void)
{
  omni_interface_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
