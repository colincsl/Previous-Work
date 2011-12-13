/*
 * Joint_Control.c
 *
 * Real-Time Workshop code generation for Simulink model "Joint_Control.mdl".
 *
 * Model Version              : 1.29
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Tue Jul 21 14:12:36 2009
 */

#include "Joint_Control.h"
#include "Joint_Control_private.h"
#include <stdio.h>
#include "Joint_Control_dt.h"

/* Block signals (auto storage) */
BlockIO_Joint_Control Joint_Control_B;

/* Continuous states */
ContinuousStates_Joint_Control Joint_Control_X;

/* Block states (auto storage) */
D_Work_Joint_Control Joint_Control_DWork;

/* Real-time model */
RT_MODEL_Joint_Control Joint_Control_M_;
RT_MODEL_Joint_Control *Joint_Control_M = &Joint_Control_M_;

/* This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Joint_Control_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Joint_Control_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase[3];
  real_T rtb_Integrator[3];
  real_T rtb_Integrator1[3];

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Joint_Control_M)) {
    Joint_Control_M->Timing.t[0] = rtsiGetT(&Joint_Control_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Joint_Control_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&Joint_Control_M->solverInfo,
                          ((Joint_Control_M->Timing.clockTick0+1)*
      Joint_Control_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  {
    real_T tmp;
    real_T tmp_0;
    real_T tmp_1;
    if (rtmIsMajorTimeStep(Joint_Control_M) &&
        Joint_Control_M->Timing.TaskCounters.TID[1] == 0) {
      /* S-Function Block: Joint_Control/PD Control/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
      {
        t_error result = hil_task_read_encoder
          (Joint_Control_DWork.HILReadEncoderTimebase_Task, 1,
           &Joint_Control_DWork.HILReadEncoderTimebase_Buffer[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Joint_Control_M, _rt_error_message);
        } else {
          rtb_HILReadEncoderTimebase[0] =
            Joint_Control_DWork.HILReadEncoderTimebase_Buffer[0];
          rtb_HILReadEncoderTimebase[1] =
            Joint_Control_DWork.HILReadEncoderTimebase_Buffer[1];
          rtb_HILReadEncoderTimebase[2] =
            Joint_Control_DWork.HILReadEncoderTimebase_Buffer[2];
        }
      }

      /* Saturate: '<S7>/Saturation' incorporates:
       *  Constant: '<Root>/Kp q1'
       *  Constant: '<Root>/Kp q2'
       *  Constant: '<Root>/Kp q3'
       *  Gain: '<S1>/Slider Gain'
       *  Gain: '<S2>/Slider Gain'
       *  Gain: '<S3>/Slider Gain'
       */
      tmp = Joint_Control_P.SliderGain_Gain * Joint_Control_P.Kpq1_Value;
      tmp_0 = Joint_Control_P.SliderGain_Gain_f * Joint_Control_P.Kpq2_Value;
      tmp_1 = Joint_Control_P.SliderGain_Gain_ff * Joint_Control_P.Kpq3_Value;
      Joint_Control_B.Saturation[0] = rt_SATURATE(tmp,
        Joint_Control_P.Saturation_LowerSat[0],
        Joint_Control_P.Saturation_UpperSat[0]);
      Joint_Control_B.Saturation[1] = rt_SATURATE(tmp_0,
        Joint_Control_P.Saturation_LowerSat[1],
        Joint_Control_P.Saturation_UpperSat[1]);
      Joint_Control_B.Saturation[2] = rt_SATURATE(tmp_1,
        Joint_Control_P.Saturation_LowerSat[2],
        Joint_Control_P.Saturation_UpperSat[2]);
    }

    /* SignalGenerator: '<Root>/Signal Generator' */
    {
      real_T phase = Joint_Control_P.SignalGenerator_Frequency*
        Joint_Control_M->Timing.t[0];
      phase = phase-floor(phase);
      rtb_Integrator[0] = ( phase >= 0.5 ) ?
        Joint_Control_P.SignalGenerator_Amplitude[0] :
        -Joint_Control_P.SignalGenerator_Amplitude[0];
      rtb_Integrator[1] = ( phase >= 0.5 ) ?
        Joint_Control_P.SignalGenerator_Amplitude[1] :
        -Joint_Control_P.SignalGenerator_Amplitude[1];
      rtb_Integrator[2] = ( phase >= 0.5 ) ?
        Joint_Control_P.SignalGenerator_Amplitude[2] :
        -Joint_Control_P.SignalGenerator_Amplitude[2];
    }

    if (rtmIsMajorTimeStep(Joint_Control_M) &&
        Joint_Control_M->Timing.TaskCounters.TID[1] == 0) {
      /* Gain: '<S8>/Gear Ratio' incorporates:
       *  Bias: '<S8>/Bias1'
       *  Gain: '<S8>/Encoder'
       */
      Joint_Control_B.GearRatio[0] = (rtb_HILReadEncoderTimebase[0] +
        Joint_Control_P.Bias1_Bias[0]) * Joint_Control_P.Encoder_Gain *
        Joint_Control_P.GearRatio_Gain[0];
      Joint_Control_B.GearRatio[1] = (rtb_HILReadEncoderTimebase[1] +
        Joint_Control_P.Bias1_Bias[1]) * Joint_Control_P.Encoder_Gain *
        Joint_Control_P.GearRatio_Gain[1];
      Joint_Control_B.GearRatio[2] = (rtb_HILReadEncoderTimebase[2] +
        Joint_Control_P.Bias1_Bias[2]) * Joint_Control_P.Encoder_Gain *
        Joint_Control_P.GearRatio_Gain[2];

      /* Embedded MATLAB: '<S8>/Embedded MATLAB Function' */
      {
        int32_T eml_i0;
        for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
          Joint_Control_B.q[eml_i0] = Joint_Control_B.GearRatio[eml_i0];
        }

        Joint_Control_B.q[0] = Joint_Control_B.GearRatio[0];
        Joint_Control_B.q[1] = Joint_Control_B.GearRatio[1];
        Joint_Control_B.q[2] = (Joint_Control_B.GearRatio[2] -
          Joint_Control_B.GearRatio[1]) - 1.5707963267948966E+000;
      }

      /* Bias: '<S7>/Joint Offsets' incorporates:
       *  Gain: '<S7>/Convert to Positive Rotation Convension Used in Kinematics1'
       */
      Joint_Control_B.JointOffsets[0] =
        Joint_Control_P.ConverttoPositiveRotationConven[0] * Joint_Control_B.q[0]
        + Joint_Control_P.JointOffsets_Bias[0];
      Joint_Control_B.JointOffsets[1] =
        Joint_Control_P.ConverttoPositiveRotationConven[1] * Joint_Control_B.q[1]
        + Joint_Control_P.JointOffsets_Bias[1];
      Joint_Control_B.JointOffsets[2] =
        Joint_Control_P.ConverttoPositiveRotationConven[2] * Joint_Control_B.q[2]
        + Joint_Control_P.JointOffsets_Bias[2];

      /* SignalConversion: '<S11>/TmpHiddenBufferAtS-FunctionInport1' */
      Joint_Control_B.TmpHiddenBufferAtSFunctionInpor[0] =
        Joint_Control_B.JointOffsets[0];
      Joint_Control_B.TmpHiddenBufferAtSFunctionInpor[1] =
        Joint_Control_B.JointOffsets[1];
      Joint_Control_B.TmpHiddenBufferAtSFunctionInpor[2] =
        Joint_Control_B.JointOffsets[2];
      Joint_Control_B.TmpHiddenBufferAtSFunctionInpor[3] = 0.0;
      Joint_Control_B.TmpHiddenBufferAtSFunctionInpor[4] = 0.0;
      Joint_Control_B.TmpHiddenBufferAtSFunctionInpor[5] = 0.0;

      /* S-Function "q_first_sample_latch_wrapper" Block: <S11>/S-Function */
      q_first_sample_latch_Outputs_wrapper
        (Joint_Control_B.TmpHiddenBufferAtSFunctionInpor,
         Joint_Control_B.SFunction, &Joint_Control_DWork.SFunction_DSTATE);
    }

    /* Sum: '<Root>/Sum' */
    Joint_Control_B.Sum[0] = rtb_Integrator[0] + Joint_Control_B.SFunction[0];
    Joint_Control_B.Sum[1] = rtb_Integrator[1] + Joint_Control_B.SFunction[1];
    Joint_Control_B.Sum[2] = rtb_Integrator[2] + Joint_Control_B.SFunction[2];

    /* Integrator: '<S13>/Integrator' */
    rtb_Integrator[0] = Joint_Control_X.Integrator_CSTATE[0];
    rtb_Integrator[1] = Joint_Control_X.Integrator_CSTATE[1];
    rtb_Integrator[2] = Joint_Control_X.Integrator_CSTATE[2];

    /* Product: '<S13>/Product1' incorporates:
     *  Constant: '<S7>/Wn'
     */
    Joint_Control_B.Product1[0] = Joint_Control_P.Wn_Value * rtb_Integrator[0];
    Joint_Control_B.Product1[1] = Joint_Control_P.Wn_Value * rtb_Integrator[1];
    Joint_Control_B.Product1[2] = Joint_Control_P.Wn_Value * rtb_Integrator[2];
    if (rtmIsMajorTimeStep(Joint_Control_M) &&
        Joint_Control_M->Timing.TaskCounters.TID[1] == 0) {
      /* Saturate: '<S7>/Saturation1' incorporates:
       *  Constant: '<Root>/Kv q1'
       *  Constant: '<Root>/Kv q2'
       *  Constant: '<Root>/Kv q3'
       *  Gain: '<S4>/Slider Gain'
       *  Gain: '<S5>/Slider Gain'
       *  Gain: '<S6>/Slider Gain'
       */
      tmp = Joint_Control_P.SliderGain_Gain_g * Joint_Control_P.Kvq1_Value;
      tmp_0 = Joint_Control_P.SliderGain_Gain_i * Joint_Control_P.Kvq2_Value;
      tmp_1 = Joint_Control_P.SliderGain_Gain_h * Joint_Control_P.Kvq3_Value;
      Joint_Control_B.Saturation1[0] = rt_SATURATE(tmp,
        Joint_Control_P.Saturation1_LowerSat[0],
        Joint_Control_P.Saturation1_UpperSat[0]);
      Joint_Control_B.Saturation1[1] = rt_SATURATE(tmp_0,
        Joint_Control_P.Saturation1_LowerSat[1],
        Joint_Control_P.Saturation1_UpperSat[1]);
      Joint_Control_B.Saturation1[2] = rt_SATURATE(tmp_1,
        Joint_Control_P.Saturation1_LowerSat[2],
        Joint_Control_P.Saturation1_UpperSat[2]);
    }

    /* Gain: '<S7>/Convert to Positive Rotation Convension Used in Kinematics2' incorporates:
     *  Product: '<S9>/Product'
     *  Product: '<S9>/Product1'
     *  Sum: '<S9>/Sum'
     *  Sum: '<S9>/Sum1'
     */
    Joint_Control_B.ConverttoPositiveRotationConven[0] = ((Joint_Control_B.Sum[0]
      - Joint_Control_B.JointOffsets[0]) * Joint_Control_B.Saturation[0] -
      Joint_Control_B.Product1[0] * Joint_Control_B.Saturation1[0]) *
      Joint_Control_P.ConverttoPositiveRotationConv_k[0];
    Joint_Control_B.ConverttoPositiveRotationConven[1] = ((Joint_Control_B.Sum[1]
      - Joint_Control_B.JointOffsets[1]) * Joint_Control_B.Saturation[1] -
      Joint_Control_B.Product1[1] * Joint_Control_B.Saturation1[1]) *
      Joint_Control_P.ConverttoPositiveRotationConv_k[1];
    Joint_Control_B.ConverttoPositiveRotationConven[2] = ((Joint_Control_B.Sum[2]
      - Joint_Control_B.JointOffsets[2]) * Joint_Control_B.Saturation[2] -
      Joint_Control_B.Product1[2] * Joint_Control_B.Saturation1[2]) *
      Joint_Control_P.ConverttoPositiveRotationConv_k[2];

    /* Embedded MATLAB: '<S10>/Joint Torque to Motor Torque' */
    {
      int32_T eml_i0;

      /*  Smart Saturation: allows channels to go up to 1.6A  */
      /*  unless the total exceeds 2.2A in which case all channels */
      /*  are scaled so that the cumulative current is equal to 2.2A. */
      for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
        Joint_Control_B.y_f[eml_i0] = 0.0;
      }

      Joint_Control_B.y_f[0] = Joint_Control_B.ConverttoPositiveRotationConven[0];
      Joint_Control_B.y_f[2] = Joint_Control_B.ConverttoPositiveRotationConven[2];
      Joint_Control_B.y_f[1] = Joint_Control_B.ConverttoPositiveRotationConven[1]
        - Joint_Control_B.ConverttoPositiveRotationConven[2];
    }

    /* Gain: '<S10>/Kt' incorporates:
     *  Gain: '<S10>/Gear Ratio1'
     */
    rtb_Integrator1[0] = Joint_Control_P.GearRatio1_Gain[0] *
      Joint_Control_B.y_f[0] * Joint_Control_P.Kt_Gain;
    rtb_Integrator1[1] = Joint_Control_P.GearRatio1_Gain[1] *
      Joint_Control_B.y_f[1] * Joint_Control_P.Kt_Gain;
    rtb_Integrator1[2] = Joint_Control_P.GearRatio1_Gain[2] *
      Joint_Control_B.y_f[2] * Joint_Control_P.Kt_Gain;

    /* Saturate: '<S10>/Saturation' */
    Joint_Control_B.Saturation_n[0] = rt_SATURATE(rtb_Integrator1[0],
      Joint_Control_P.Saturation_LowerSat_l,
      Joint_Control_P.Saturation_UpperSat_a);
    Joint_Control_B.Saturation_n[1] = rt_SATURATE(rtb_Integrator1[1],
      Joint_Control_P.Saturation_LowerSat_l,
      Joint_Control_P.Saturation_UpperSat_a);
    Joint_Control_B.Saturation_n[2] = rt_SATURATE(rtb_Integrator1[2],
      Joint_Control_P.Saturation_LowerSat_l,
      Joint_Control_P.Saturation_UpperSat_a);

    /* Embedded MATLAB: '<S10>/Smart Saturation' */
    {
      int32_T eml_k;
      real_T eml_x[3];
      real_T eml_total;

      /*  Smart Saturation: allows channels to go up to 1.6A  */
      /*  unless the total exceeds 2.2A in which case all channels */
      /*  are scaled so that the cumulative current is equal to 2.2A. */
      /*  Define the maximum cumulative current here */
      for (eml_k = 0; eml_k < 3; eml_k++) {
        eml_x[eml_k] = fabs(Joint_Control_B.Saturation_n[eml_k]);
      }

      eml_total = eml_x[0];
      for (eml_k = 2; eml_k < 4; eml_k++) {
        eml_total += eml_x[eml_k - 1];
      }

      if (eml_total > 2.2) {
        eml_total = 2.2 / eml_total;
        for (eml_k = 0; eml_k < 3; eml_k++) {
          Joint_Control_B.y[eml_k] = eml_total *
            Joint_Control_B.Saturation_n[eml_k];
        }
      } else {
        for (eml_k = 0; eml_k < 3; eml_k++) {
          Joint_Control_B.y[eml_k] = Joint_Control_B.Saturation_n[eml_k];
        }
      }
    }

    if (rtmIsMajorTimeStep(Joint_Control_M) &&
        Joint_Control_M->Timing.TaskCounters.TID[1] == 0) {
      /* S-Function Block: Joint_Control/PD Control/HIL Write PWM (hil_write_pwm_block) */
      {
        t_error result;
        result = hil_write_pwm(Joint_Control_DWork.HILInitialize_Card,
          Joint_Control_P.HILWritePWM_Channels, 3, Joint_Control_B.y);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Joint_Control_M, _rt_error_message);
        }
      }
    }

    /* Integrator: '<S13>/Integrator1' */
    if (Joint_Control_DWork.Integrator1_IWORK.IcNeedsLoading) {
      Joint_Control_X.Integrator1_CSTATE[0] = Joint_Control_B.JointOffsets[0];
      Joint_Control_X.Integrator1_CSTATE[1] = Joint_Control_B.JointOffsets[1];
      Joint_Control_X.Integrator1_CSTATE[2] = Joint_Control_B.JointOffsets[2];
      Joint_Control_DWork.Integrator1_IWORK.IcNeedsLoading = 0;
    }

    rtb_Integrator1[0] = Joint_Control_X.Integrator1_CSTATE[0];
    rtb_Integrator1[1] = Joint_Control_X.Integrator1_CSTATE[1];
    rtb_Integrator1[2] = Joint_Control_X.Integrator1_CSTATE[2];

    /* Product: '<S13>/Product' incorporates:
     *  Constant: '<S13>/Constant'
     *  Constant: '<S7>/Wn'
     *  Constant: '<S9>/z'
     *  Product: '<S13>/Product2'
     *  Sum: '<S13>/Sum'
     *  Sum: '<S13>/Sum1'
     */
    Joint_Control_B.Product[0] = ((Joint_Control_B.JointOffsets[0] -
      rtb_Integrator1[0]) - rtb_Integrator[0] * Joint_Control_P.Constant_Value *
      Joint_Control_P.z_Value) * Joint_Control_P.Wn_Value;
    Joint_Control_B.Product[1] = ((Joint_Control_B.JointOffsets[1] -
      rtb_Integrator1[1]) - rtb_Integrator[1] * Joint_Control_P.Constant_Value *
      Joint_Control_P.z_Value) * Joint_Control_P.Wn_Value;
    Joint_Control_B.Product[2] = ((Joint_Control_B.JointOffsets[2] -
      rtb_Integrator1[2]) - rtb_Integrator[2] * Joint_Control_P.Constant_Value *
      Joint_Control_P.z_Value) * Joint_Control_P.Wn_Value;
    if (rtmIsMajorTimeStep(Joint_Control_M) &&
        Joint_Control_M->Timing.TaskCounters.TID[1] == 0) {
    }
  }

  UNUSED_PARAMETER(tid);
}

/* Model update function */
void Joint_Control_update(int_T tid)
{
  if (rtmIsMajorTimeStep(Joint_Control_M) &&
      Joint_Control_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function "q_first_sample_latch_wrapper" Block: <S11>/S-Function */
    q_first_sample_latch_Update_wrapper
      (Joint_Control_B.TmpHiddenBufferAtSFunctionInpor,
       Joint_Control_B.SFunction, &Joint_Control_DWork.SFunction_DSTATE);
  }

  if (rtmIsMajorTimeStep(Joint_Control_M)) {
    rt_ertODEUpdateContinuousStates(&Joint_Control_M->solverInfo);
  }

  /* Update absolute time for base rate */
  if (!(++Joint_Control_M->Timing.clockTick0))
    ++Joint_Control_M->Timing.clockTickH0;
  Joint_Control_M->Timing.t[0] = Joint_Control_M->Timing.clockTick0 *
    Joint_Control_M->Timing.stepSize0 + Joint_Control_M->Timing.clockTickH0 *
    Joint_Control_M->Timing.stepSize0 * 4294967296.0;
  if (rtmIsMajorTimeStep(Joint_Control_M) &&
      Joint_Control_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    if (!(++Joint_Control_M->Timing.clockTick1))
      ++Joint_Control_M->Timing.clockTickH1;
    Joint_Control_M->Timing.t[1] = Joint_Control_M->Timing.clockTick1 *
      Joint_Control_M->Timing.stepSize1 + Joint_Control_M->Timing.clockTickH1 *
      Joint_Control_M->Timing.stepSize1 * 4294967296.0;
  }

  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void Joint_Control_derivatives(void)
{
  /* Derivatives for Integrator: '<S13>/Integrator' */
  ((StateDerivatives_Joint_Control *) Joint_Control_M->ModelData.derivs)
    ->Integrator_CSTATE[0] = Joint_Control_B.Product[0];
  ((StateDerivatives_Joint_Control *) Joint_Control_M->ModelData.derivs)
    ->Integrator_CSTATE[1] = Joint_Control_B.Product[1];
  ((StateDerivatives_Joint_Control *) Joint_Control_M->ModelData.derivs)
    ->Integrator_CSTATE[2] = Joint_Control_B.Product[2];

  /* Integrator Block: '<S13>/Integrator1' */
  {
    ((StateDerivatives_Joint_Control *) Joint_Control_M->ModelData.derivs)
      ->Integrator1_CSTATE[0] = Joint_Control_B.Product1[0];
    ((StateDerivatives_Joint_Control *) Joint_Control_M->ModelData.derivs)
      ->Integrator1_CSTATE[1] = Joint_Control_B.Product1[1];
    ((StateDerivatives_Joint_Control *) Joint_Control_M->ModelData.derivs)
      ->Integrator1_CSTATE[2] = Joint_Control_B.Product1[2];
  }
}

/* Model initialize function */
void Joint_Control_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));    /* initialize real-time model */
  (void) memset((char_T *)Joint_Control_M,0,
                sizeof(RT_MODEL_Joint_Control));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Joint_Control_M->solverInfo,
                          &Joint_Control_M->Timing.simTimeStep);
    rtsiSetTPtr(&Joint_Control_M->solverInfo, &rtmGetTPtr(Joint_Control_M));
    rtsiSetStepSizePtr(&Joint_Control_M->solverInfo,
                       &Joint_Control_M->Timing.stepSize0);
    rtsiSetdXPtr(&Joint_Control_M->solverInfo,
                 &Joint_Control_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Joint_Control_M->solverInfo,
                         &Joint_Control_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Joint_Control_M->solverInfo,
      &Joint_Control_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Joint_Control_M->solverInfo, (&rtmGetErrorStatus
      (Joint_Control_M)));
    rtsiSetRTModelPtr(&Joint_Control_M->solverInfo, Joint_Control_M);
  }

  rtsiSetSimTimeStep(&Joint_Control_M->solverInfo, MAJOR_TIME_STEP);
  Joint_Control_M->ModelData.intgData.f[0] = Joint_Control_M->ModelData.odeF[0];
  Joint_Control_M->ModelData.contStates = ((real_T *) &Joint_Control_X);
  rtsiSetSolverData(&Joint_Control_M->solverInfo, (void *)
                    &Joint_Control_M->ModelData.intgData);
  rtsiSetSolverName(&Joint_Control_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Joint_Control_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Joint_Control_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Joint_Control_M->Timing.sampleTimes =
      (&Joint_Control_M->Timing.sampleTimesArray[0]);
    Joint_Control_M->Timing.offsetTimes =
      (&Joint_Control_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Joint_Control_M->Timing.sampleTimes[0] = (0.0);
    Joint_Control_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    Joint_Control_M->Timing.offsetTimes[0] = (0.0);
    Joint_Control_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Joint_Control_M, &Joint_Control_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Joint_Control_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Joint_Control_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Joint_Control_M, -1);
  Joint_Control_M->Timing.stepSize0 = 0.001;
  Joint_Control_M->Timing.stepSize1 = 0.001;

  /* external mode info */
  Joint_Control_M->Sizes.checksums[0] = (3785709360U);
  Joint_Control_M->Sizes.checksums[1] = (3261669109U);
  Joint_Control_M->Sizes.checksums[2] = (1122963643U);
  Joint_Control_M->Sizes.checksums[3] = (3821694672U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    Joint_Control_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &Joint_Control_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, Joint_Control_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(Joint_Control_M));
  }

  Joint_Control_M->solverInfoPtr = (&Joint_Control_M->solverInfo);
  Joint_Control_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Joint_Control_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Joint_Control_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Joint_Control_M->ModelData.blockIO = ((void *) &Joint_Control_B);

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&Joint_Control_B.Saturation[0]);
    for (i = 0; i < 39; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    pVoidBlockIORegion = (void *)(&Joint_Control_B.y[0]);
    for (i = 0; i < 9; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }
  }

  /* parameters */
  Joint_Control_M->ModelData.defaultParam = ((real_T *) &Joint_Control_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Joint_Control_X;
    Joint_Control_M->ModelData.contStates = (x);
    (void) memset((char_T *)x,0,
                  sizeof(ContinuousStates_Joint_Control));
  }

  /* states (dwork) */
  Joint_Control_M->Work.dwork = ((void *) &Joint_Control_DWork);
  (void) memset((char_T *) &Joint_Control_DWork,0,
                sizeof(D_Work_Joint_Control));

  {
    int_T i;
    real_T *dwork_ptr = (real_T *) &Joint_Control_DWork.SFunction_DSTATE;
    for (i = 0; i < 14; i++) {
      dwork_ptr[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    Joint_Control_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void Joint_Control_terminate(void)
{
  /* S-Function Block: Joint_Control/PD Control/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    hil_task_stop_all(Joint_Control_DWork.HILInitialize_Card);
    hil_task_delete_all(Joint_Control_DWork.HILInitialize_Card);
    is_switching = false;
    if ((Joint_Control_P.HILInitialize_POTerminate && !is_switching) ||
        (Joint_Control_P.HILInitialize_POExit && is_switching)) {
      Joint_Control_DWork.HILInitialize_POValues[0] =
        Joint_Control_P.HILInitialize_POFinal;
      Joint_Control_DWork.HILInitialize_POValues[1] =
        Joint_Control_P.HILInitialize_POFinal;
      Joint_Control_DWork.HILInitialize_POValues[2] =
        Joint_Control_P.HILInitialize_POFinal;
      result = hil_write_pwm(Joint_Control_DWork.HILInitialize_Card,
        &Joint_Control_P.HILInitialize_POChannels[0], 3U,
        &Joint_Control_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Joint_Control_M, _rt_error_message);
      }
    }

    hil_close(Joint_Control_DWork.HILInitialize_Card);
    Joint_Control_DWork.HILInitialize_Card = NULL;
  }

  /* External mode */
  rtExtModeShutdown(2);
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Joint_Control_output(tid);
}

void MdlUpdate(int_T tid)
{
  Joint_Control_update(tid);
}

void MdlInitializeSizes(void)
{
  Joint_Control_M->Sizes.numContStates = (6);/* Number of continuous states */
  Joint_Control_M->Sizes.numY = (0);   /* Number of model outputs */
  Joint_Control_M->Sizes.numU = (0);   /* Number of model inputs */
  Joint_Control_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Joint_Control_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Joint_Control_M->Sizes.numBlocks = (53);/* Number of blocks */
  Joint_Control_M->Sizes.numBlockIO = (14);/* Number of block outputs */
  Joint_Control_M->Sizes.numBlockPrms = (114);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* Initialize code for chart: '<S8>/Embedded MATLAB Function' */
  Joint_Control_DWork.is_active_c8_Joint_Control = 0U;

  /* S-Function Block: <S11>/S-Function */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        Joint_Control_DWork.SFunction_DSTATE = initVector[0];
      }
    }
  }

  /* InitializeConditions for Integrator: '<S13>/Integrator' */
  Joint_Control_X.Integrator_CSTATE[0] = Joint_Control_P.Integrator_IC;
  Joint_Control_X.Integrator_CSTATE[1] = Joint_Control_P.Integrator_IC;
  Joint_Control_X.Integrator_CSTATE[2] = Joint_Control_P.Integrator_IC;

  /* Initialize code for chart: '<S10>/Joint Torque to Motor Torque' */
  Joint_Control_DWork.is_active_c4_Joint_Control = 0U;

  /* Initialize code for chart: '<S10>/Smart Saturation' */
  Joint_Control_DWork.is_active_c3_Joint_Control = 0U;

  /* Integrator Block: '<S13>/Integrator1' */
  if (rtmIsFirstInitCond(Joint_Control_M)) {
    Joint_Control_X.Integrator1_CSTATE[0] = 0.0;
    Joint_Control_X.Integrator1_CSTATE[1] = 0.0;
    Joint_Control_X.Integrator1_CSTATE[2] = 0.0;
  }

  Joint_Control_DWork.Integrator1_IWORK.IcNeedsLoading = 1;
}

void MdlStart(void)
{
  /* S-Function Block: Joint_Control/PD Control/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("phantom_omni", "0",
                      &Joint_Control_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Joint_Control_M, _rt_error_message);
      return;
    }

    is_switching = false;
    if ((Joint_Control_P.HILInitialize_AIPStart && !is_switching) ||
        (Joint_Control_P.HILInitialize_AIPEnter && is_switching)) {
      Joint_Control_DWork.HILInitialize_AIMinimums[0] =
        Joint_Control_P.HILInitialize_AILow;
      Joint_Control_DWork.HILInitialize_AIMinimums[1] =
        Joint_Control_P.HILInitialize_AILow;
      Joint_Control_DWork.HILInitialize_AIMaximums[0] =
        Joint_Control_P.HILInitialize_AIHigh;
      Joint_Control_DWork.HILInitialize_AIMaximums[1] =
        Joint_Control_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges
        (Joint_Control_DWork.HILInitialize_Card,
         &Joint_Control_P.HILInitialize_AIChannels[0], 2U,
         &Joint_Control_DWork.HILInitialize_AIMinimums[0],
         &Joint_Control_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Joint_Control_M, _rt_error_message);
        return;
      }
    }

    if ((Joint_Control_P.HILInitialize_EIStart && !is_switching) ||
        (Joint_Control_P.HILInitialize_EIEnter && is_switching)) {
      Joint_Control_DWork.HILInitialize_InitialEICounts[0] =
        Joint_Control_P.HILInitialize_EIInitial;
      Joint_Control_DWork.HILInitialize_InitialEICounts[1] =
        Joint_Control_P.HILInitialize_EIInitial;
      Joint_Control_DWork.HILInitialize_InitialEICounts[2] =
        Joint_Control_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(Joint_Control_DWork.HILInitialize_Card,
        &Joint_Control_P.HILInitialize_EIChannels[0], 3U,
        &Joint_Control_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Joint_Control_M, _rt_error_message);
        return;
      }
    }

    if ((Joint_Control_P.HILInitialize_POStart && !is_switching) ||
        (Joint_Control_P.HILInitialize_POEnter && is_switching)) {
      Joint_Control_DWork.HILInitialize_POValues[0] =
        Joint_Control_P.HILInitialize_POInitial;
      Joint_Control_DWork.HILInitialize_POValues[1] =
        Joint_Control_P.HILInitialize_POInitial;
      Joint_Control_DWork.HILInitialize_POValues[2] =
        Joint_Control_P.HILInitialize_POInitial;
      result = hil_write_pwm(Joint_Control_DWork.HILInitialize_Card,
        &Joint_Control_P.HILInitialize_POChannels[0], 3U,
        &Joint_Control_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Joint_Control_M, _rt_error_message);
        return;
      }
    }

    if (Joint_Control_P.HILInitialize_POReset) {
      Joint_Control_DWork.HILInitialize_POValues[0] =
        Joint_Control_P.HILInitialize_POWatchdog;
      Joint_Control_DWork.HILInitialize_POValues[1] =
        Joint_Control_P.HILInitialize_POWatchdog;
      Joint_Control_DWork.HILInitialize_POValues[2] =
        Joint_Control_P.HILInitialize_POWatchdog;
      result = hil_watchdog_set_pwm_expiration_state
        (Joint_Control_DWork.HILInitialize_Card,
         &Joint_Control_P.HILInitialize_POChannels[0], 3U,
         &Joint_Control_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Joint_Control_M, _rt_error_message);
        return;
      }
    }
  }

  /* S-Function Block: Joint_Control/PD Control/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (Joint_Control_DWork.HILInitialize_Card,
       Joint_Control_P.HILReadEncoderTimebase_SamplesI,
       Joint_Control_P.HILReadEncoderTimebase_Channels, 3,
       &Joint_Control_DWork.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Joint_Control_M, _rt_error_message);
    }
  }

  MdlInitialize();
}

RT_MODEL_Joint_Control *Joint_Control(void)
{
  Joint_Control_initialize(1);
  return Joint_Control_M;
}

void MdlTerminate(void)
{
  Joint_Control_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
