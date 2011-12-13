/*
 * Pong.c
 *
 * Real-Time Workshop code generation for Simulink model "Pong.mdl".
 *
 * Model Version              : 1.299
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Tue Jul 21 14:15:33 2009
 */

#include "Pong.h"
#include "Pong_private.h"
#include <stdio.h>
#include "Pong_dt.h"

/* Block signals (auto storage) */
BlockIO_Pong Pong_B;

/* Continuous states */
ContinuousStates_Pong Pong_X;

/* Block states (auto storage) */
D_Work_Pong Pong_DWork;

/* Real-time model */
RT_MODEL_Pong Pong_M_;
RT_MODEL_Pong *Pong_M = &Pong_M_;
static void rate_monotonic_scheduler(void);

/* Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Pong_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Pong_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(Pong_M, 2));
}

time_T rt_SimUpdateDiscreteEvents(int_T rtmNumSampTimes,
  void *rtmTimingData,
  int_T *rtmSampleHitPtr,
  int_T *rtmPerTaskSampleHits)
{
  rtmSampleHitPtr[1] = rtmStepTask(Pong_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(Pong_M, 2);
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

  /* tid 0 shares data with slower tid rate: 2 */
  Pong_M->Timing.RateInteraction.TID0_2 = (Pong_M->Timing.TaskCounters.TID[2] ==
    0);

  /* update PerTaskSampleHits matrix for non-inline sfcn */
  Pong_M->Timing.perTaskSampleHits[2] = Pong_M->Timing.RateInteraction.TID0_2;

  /* tid 1 shares data with slower tid rate: 2 */
  if (Pong_M->Timing.TaskCounters.TID[1] == 0) {
    Pong_M->Timing.RateInteraction.TID1_2 = (Pong_M->Timing.TaskCounters.TID[2] ==
      0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    Pong_M->Timing.perTaskSampleHits[5] = Pong_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  if (++Pong_M->Timing.TaskCounters.TID[2] == 100) {/* Sample time: [0.1s, 0.0s] */
    Pong_M->Timing.TaskCounters.TID[2] = 0;
  }

  Pong_M->Timing.sampleHits[2] = (Pong_M->Timing.TaskCounters.TID[2] == 0);
}

/* This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 14;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y,x,
                nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Pong_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++)
    x[i] = y[i] + (temp*f0[i]);
  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  Pong_output0(0);
  Pong_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++)
    x[i] = y[i] + (temp*f1[i]);
  rtsiSetdX(si, f2);
  Pong_output0(0);
  Pong_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++)
    x[i] = y[i] + (h*f2[i]);
  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  Pong_output0(0);
  Pong_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void Pong_output0(int_T tid)           /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_Integrator3;
  real_T rtb_Integrator1;
  real_T rtb_Switch;
  real_T rtb_Gain3;
  real_T rtb_TmpHiddenBufferAtProductInp[6];
  real_T rtb_HILReadAnalog[3];
  real_T rtb_Integrator1_l;
  real_T rtb_Switch2;
  real_T rtb_Kt[3];
  real_T rtb_Switch3;
  real_T rtb_Switch2_k;
  boolean_T rtb_LogicalOperator;
  if (rtmIsMajorTimeStep(Pong_M)) {
    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Pong_M)) {
    Pong_M->Timing.t[0] = rtsiGetT(&Pong_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Pong_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&Pong_M->solverInfo,
                          ((Pong_M->Timing.clockTick0+1)*
      Pong_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  {
    int32_T i;
    real_T tmp[18];
    if (rtmIsMajorTimeStep(Pong_M)) {
      /* S-Function Block: Pong/Omni/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
      {
        t_error result = hil_task_read_encoder
          (Pong_DWork.HILReadEncoderTimebase_Task, 1,
           &Pong_DWork.HILReadEncoderTimebase_Buffer[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Pong_M, _rt_error_message);
        } else {
          rtb_HILReadAnalog[0] = Pong_DWork.HILReadEncoderTimebase_Buffer[0];
          rtb_HILReadAnalog[1] = Pong_DWork.HILReadEncoderTimebase_Buffer[1];
          rtb_HILReadAnalog[2] = Pong_DWork.HILReadEncoderTimebase_Buffer[2];
        }
      }

      /* Gain: '<S25>/Gear Ratio' incorporates:
       *  Bias: '<S25>/Bias1'
       *  Gain: '<S25>/Encoder'
       */
      Pong_B.GearRatio[0] = (rtb_HILReadAnalog[0] + Pong_P.Bias1_Bias[0]) *
        Pong_P.Encoder_Gain * Pong_P.GearRatio_Gain[0];
      Pong_B.GearRatio[1] = (rtb_HILReadAnalog[1] + Pong_P.Bias1_Bias[1]) *
        Pong_P.Encoder_Gain * Pong_P.GearRatio_Gain[1];
      Pong_B.GearRatio[2] = (rtb_HILReadAnalog[2] + Pong_P.Bias1_Bias[2]) *
        Pong_P.Encoder_Gain * Pong_P.GearRatio_Gain[2];

      /* Embedded MATLAB: '<S25>/Embedded MATLAB Function' */
      {
        int32_T eml_i0;
        for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
          Pong_B.q[eml_i0] = Pong_B.GearRatio[eml_i0];
        }

        Pong_B.q[0] = Pong_B.GearRatio[0];
        Pong_B.q[1] = Pong_B.GearRatio[1];
        Pong_B.q[2] = (Pong_B.GearRatio[2] - Pong_B.GearRatio[1]) -
          1.5707963267948966E+000;
      }

      /* Bias: '<S4>/Joint Offsets' incorporates:
       *  Gain: '<S4>/Convert to Positive Rotation Convension Used in Kinematics'
       */
      Pong_B.JointOffsets[0] = Pong_P.ConverttoPositiveRotationConven[0] *
        Pong_B.q[0] + Pong_P.JointOffsets_Bias[0];
      Pong_B.JointOffsets[1] = Pong_P.ConverttoPositiveRotationConven[1] *
        Pong_B.q[1] + Pong_P.JointOffsets_Bias[1];
      Pong_B.JointOffsets[2] = Pong_P.ConverttoPositiveRotationConven[2] *
        Pong_B.q[2] + Pong_P.JointOffsets_Bias[2];
      for (i = 0; i < 16; i++) {
        /* Constant: '<S4>/Tool Offset2' */
        Pong_B.ToolOffset2[i] = Pong_P.ToolOffset2_Value[i];
      }

      /* Embedded MATLAB: '<S4>/Forward Kinematics ' */
      {
        real_T eml_theta_z;
        real_T eml_dv0[16];
        int32_T eml_i0;
        static boolean_T eml_bv0[4] = { false, false, true, false };

        static boolean_T eml_bv1[4] = { false, false, false, true };

        real_T eml_theta_z_0;
        real_T eml_dv1[16];
        int32_T eml_i1;
        real_T eml_dv2[16];
        int32_T eml_i2;
        static boolean_T eml_bv2[16] = { true, false, false, false, false, true,
          false, false, false, false, true, false, false, false, false, true };

        real_T eml_dv3[16];
        real_T eml_A1[16];
        static real_T eml_A_R_x[16] = { 1.0, 0.0, 0.0, 0.0, 0.0,
          6.1232339957367660E-017, -1.0, 0.0, 0.0, 1.0, 6.1232339957367660E-017,
          0.0, 0.0, 0.0, 0.0, 1.0 };

        real_T eml_dv4[16];
        real_T eml_dv5[16];
        static real_T eml_A_T_x[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
          0.0, 0.0, 1.0, 0.0, 0.132, 0.0, 0.0, 1.0 };

        real_T eml_dv6[16];
        real_T eml_dv7[16];
        real_T eml_T02[16];
        real_T eml_dv8[16];
        real_T eml_dv9[16];
        real_T eml_dv10[16];
        real_T eml_T03[16];
        real_T eml_z1[3];
        real_T eml_z2[3];
        real_T eml_dv11[16];
        real_T eml_b[3];
        real_T eml_b_0[3];
        real_T eml_b_1[3];
        static boolean_T eml_bv3[3] = { false, false, true };

        /*  This block supports the Embedded MATLAB subset. */
        /*  See the help menu for details.  */
        /*  Link lengths */
        /* Define A-matrices */
        /* A1= DH(a_i ,alpha_i    ,d_i    ,theta_i) */
        eml_theta_z = Pong_B.JointOffsets[0];
        eml_dv0[0] = cos(eml_theta_z);
        eml_dv0[4] = -sin(eml_theta_z);
        eml_dv0[8] = 0.0;
        eml_dv0[12] = 0.0;
        eml_dv0[1] = sin(eml_theta_z);
        eml_dv0[5] = cos(eml_theta_z);
        eml_dv0[9] = 0.0;
        eml_dv0[13] = 0.0;
        for (eml_i0 = 0; eml_i0 < 4; eml_i0++) {
          eml_dv0[2 + (eml_i0 << 2)] = (real_T)eml_bv0[eml_i0];
          eml_dv0[3 + (eml_i0 << 2)] = (real_T)eml_bv1[eml_i0];
        }

        eml_theta_z = Pong_B.JointOffsets[1];
        eml_theta_z_0 = Pong_B.JointOffsets[2] - 1.5707963267948966E+000;

        /* Define T Matrices */
        eml_dv1[0] = cos(eml_theta_z);
        eml_dv1[4] = -sin(eml_theta_z);
        eml_dv1[8] = 0.0;
        eml_dv1[12] = 0.0;
        eml_dv1[1] = sin(eml_theta_z);
        eml_dv1[5] = cos(eml_theta_z);
        eml_dv1[9] = 0.0;
        eml_dv1[13] = 0.0;
        for (eml_i1 = 0; eml_i1 < 4; eml_i1++) {
          for (eml_i0 = 0; eml_i0 < 4; eml_i0++) {
            eml_dv2[eml_i1 + (eml_i0 << 2)] = 0.0;
            for (eml_i2 = 0; eml_i2 < 4; eml_i2++) {
              eml_dv2[eml_i1 + (eml_i0 << 2)] += eml_dv0[eml_i1 + (eml_i2 << 2)]
                * (real_T)eml_bv2[eml_i2 + (eml_i0 << 2)];
            }
          }

          for (eml_i0 = 0; eml_i0 < 4; eml_i0++) {
            eml_dv3[eml_i1 + (eml_i0 << 2)] = 0.0;
            for (eml_i2 = 0; eml_i2 < 4; eml_i2++) {
              eml_dv3[eml_i1 + (eml_i0 << 2)] += eml_dv2[eml_i1 + (eml_i2 << 2)]
                * (real_T)eml_bv2[eml_i2 + (eml_i0 << 2)];
            }
          }

          for (eml_i0 = 0; eml_i0 < 4; eml_i0++) {
            eml_A1[eml_i1 + (eml_i0 << 2)] = 0.0;
            for (eml_i2 = 0; eml_i2 < 4; eml_i2++) {
              eml_A1[eml_i1 + (eml_i0 << 2)] += eml_dv3[eml_i1 + (eml_i2 << 2)] *
                eml_A_R_x[eml_i2 + (eml_i0 << 2)];
            }
          }

          eml_dv1[2 + (eml_i1 << 2)] = (real_T)eml_bv0[eml_i1];
          eml_dv1[3 + (eml_i1 << 2)] = (real_T)eml_bv1[eml_i1];
        }

        for (eml_i1 = 0; eml_i1 < 4; eml_i1++) {
          for (eml_i0 = 0; eml_i0 < 4; eml_i0++) {
            eml_dv4[eml_i1 + (eml_i0 << 2)] = 0.0;
            for (eml_i2 = 0; eml_i2 < 4; eml_i2++) {
              eml_dv4[eml_i1 + (eml_i0 << 2)] += eml_dv1[eml_i1 + (eml_i2 << 2)]
                * (real_T)eml_bv2[eml_i2 + (eml_i0 << 2)];
            }
          }

          for (eml_i0 = 0; eml_i0 < 4; eml_i0++) {
            eml_dv5[eml_i1 + (eml_i0 << 2)] = 0.0;
            for (eml_i2 = 0; eml_i2 < 4; eml_i2++) {
              eml_dv5[eml_i1 + (eml_i0 << 2)] += eml_dv4[eml_i1 + (eml_i2 << 2)]
                * eml_A_T_x[eml_i2 + (eml_i0 << 2)];
            }
          }

          for (eml_i0 = 0; eml_i0 < 4; eml_i0++) {
            eml_dv6[eml_i1 + (eml_i0 << 2)] = 0.0;
            for (eml_i2 = 0; eml_i2 < 4; eml_i2++) {
              eml_dv6[eml_i1 + (eml_i0 << 2)] += eml_dv5[eml_i1 + (eml_i2 << 2)]
                * (real_T)eml_bv2[eml_i2 + (eml_i0 << 2)];
            }
          }
        }

        eml_dv7[0] = cos(eml_theta_z_0);
        eml_dv7[4] = -sin(eml_theta_z_0);
        eml_dv7[8] = 0.0;
        eml_dv7[12] = 0.0;
        eml_dv7[1] = sin(eml_theta_z_0);
        eml_dv7[5] = cos(eml_theta_z_0);
        eml_dv7[9] = 0.0;
        eml_dv7[13] = 0.0;
        for (eml_i0 = 0; eml_i0 < 4; eml_i0++) {
          for (eml_i2 = 0; eml_i2 < 4; eml_i2++) {
            eml_T02[eml_i0 + (eml_i2 << 2)] = 0.0;
            for (eml_i1 = 0; eml_i1 < 4; eml_i1++) {
              eml_T02[eml_i0 + (eml_i2 << 2)] += eml_A1[eml_i0 + (eml_i1 << 2)] *
                eml_dv6[eml_i1 + (eml_i2 << 2)];
            }
          }

          eml_dv7[2 + (eml_i0 << 2)] = (real_T)eml_bv0[eml_i0];
          eml_dv7[3 + (eml_i0 << 2)] = (real_T)eml_bv1[eml_i0];
        }

        for (eml_i1 = 0; eml_i1 < 4; eml_i1++) {
          for (eml_i0 = 0; eml_i0 < 4; eml_i0++) {
            eml_dv8[eml_i1 + (eml_i0 << 2)] = 0.0;
            for (eml_i2 = 0; eml_i2 < 4; eml_i2++) {
              eml_dv8[eml_i1 + (eml_i0 << 2)] += eml_dv7[eml_i1 + (eml_i2 << 2)]
                * (real_T)eml_bv2[eml_i2 + (eml_i0 << 2)];
            }
          }

          for (eml_i0 = 0; eml_i0 < 4; eml_i0++) {
            eml_dv9[eml_i1 + (eml_i0 << 2)] = 0.0;
            for (eml_i2 = 0; eml_i2 < 4; eml_i2++) {
              eml_dv9[eml_i1 + (eml_i0 << 2)] += eml_dv8[eml_i1 + (eml_i2 << 2)]
                * eml_A_T_x[eml_i2 + (eml_i0 << 2)];
            }
          }

          for (eml_i0 = 0; eml_i0 < 4; eml_i0++) {
            eml_dv10[eml_i1 + (eml_i0 << 2)] = 0.0;
            for (eml_i2 = 0; eml_i2 < 4; eml_i2++) {
              eml_dv10[eml_i1 + (eml_i0 << 2)] += eml_dv9[eml_i1 + (eml_i2 << 2)]
                * (real_T)eml_bv2[eml_i2 + (eml_i0 << 2)];
            }
          }
        }

        for (eml_i0 = 0; eml_i0 < 4; eml_i0++) {
          for (eml_i2 = 0; eml_i2 < 4; eml_i2++) {
            eml_T03[eml_i0 + (eml_i2 << 2)] = 0.0;
            for (eml_i1 = 0; eml_i1 < 4; eml_i1++) {
              eml_T03[eml_i0 + (eml_i2 << 2)] += eml_T02[eml_i0 + (eml_i1 << 2)]
                * eml_dv10[eml_i1 + (eml_i2 << 2)];
            }
          }
        }

        /* Axes of rotation in base coordinates.  */
        for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
          eml_z1[eml_i0] = eml_A1[eml_i0 + 8];
          eml_z2[eml_i0] = eml_T02[eml_i0 + 8];

          /* Coordinate Frame origins in Base frame coordinates */
          /* tool_offset given with respect to frame 3. */
          for (eml_i2 = 0; eml_i2 < 3; eml_i2++) {
            Pong_B.Rot[eml_i2 + 3 * eml_i0] = eml_T03[eml_i2 + (eml_i0 << 2)];
          }
        }

        for (eml_i0 = 0; eml_i0 < 4; eml_i0++) {
          for (eml_i2 = 0; eml_i2 < 4; eml_i2++) {
            eml_dv11[eml_i0 + (eml_i2 << 2)] = 0.0;
            for (eml_i1 = 0; eml_i1 < 4; eml_i1++) {
              eml_dv11[eml_i0 + (eml_i2 << 2)] += eml_T03[eml_i0 + (eml_i1 << 2)]
                * Pong_B.ToolOffset2[eml_i1 + (eml_i2 << 2)];
            }
          }
        }

        for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
          Pong_B.pos[eml_i0] = eml_dv11[eml_i0 + 12];

          /* Formulation of the Jacobian */
          /* %%%%%%%%%%%%%%%%%%%%%%%%%%%JACOBIAN%%%%%%%%%%%%%%%%%%%%%%%% */
          eml_b[eml_i0] = Pong_B.pos[eml_i0] - eml_T02[eml_i0 + 12];
          eml_b_0[eml_i0] = Pong_B.pos[eml_i0] - eml_A1[eml_i0 + 12];
          eml_b_1[eml_i0] = Pong_B.pos[eml_i0];
        }

        Pong_B.Jac[0] = 0.0 * eml_b_1[2] - eml_b_1[1];
        Pong_B.Jac[1] = eml_b_1[0] - 0.0 * eml_b_1[2];
        Pong_B.Jac[2] = 0.0 * eml_b_1[1] - 0.0 * eml_b_1[0];
        Pong_B.Jac[6] = eml_z1[1] * eml_b_0[2] - eml_z1[2] * eml_b_0[1];
        Pong_B.Jac[7] = eml_z1[2] * eml_b_0[0] - eml_z1[0] * eml_b_0[2];
        Pong_B.Jac[8] = eml_z1[0] * eml_b_0[1] - eml_z1[1] * eml_b_0[0];
        Pong_B.Jac[12] = eml_z2[1] * eml_b[2] - eml_z2[2] * eml_b[1];
        Pong_B.Jac[13] = eml_z2[2] * eml_b[0] - eml_z2[0] * eml_b[2];
        Pong_B.Jac[14] = eml_z2[0] * eml_b[1] - eml_z2[1] * eml_b[0];
        for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
          Pong_B.Jac[eml_i0 + 3] = (real_T)eml_bv3[eml_i0];
        }

        for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
          Pong_B.Jac[eml_i0 + 9] = eml_z1[eml_i0];
        }

        for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
          Pong_B.Jac[eml_i0 + 15] = eml_z2[eml_i0];
        }
      }

      /* Math: '<S4>/Math Function' */
      for (i = 0; i < 6; i++) {
        tmp[3 * i] = Pong_B.Jac[i];
        tmp[1 + 3 * i] = Pong_B.Jac[i + 6];
        tmp[2 + 3 * i] = Pong_B.Jac[i + 12];
      }

      for (i = 0; i < 18; i++) {
        Pong_B.MathFunction[i] = tmp[i];
      }
    }

    /* Integrator: '<S1>/Integrator3' */
    rtb_Integrator3 = Pong_X.Integrator3_CSTATE;

    /* Sum: '<S7>/Sum10' incorporates:
     *  Integrator: '<S1>/Integrator3'
     */
    Pong_B.Sum10 = Pong_B.pos[1] - Pong_X.Integrator3_CSTATE;

    /* Integrator: '<S15>/Integrator' */
    rtb_Integrator1_l = Pong_X.Integrator_CSTATE;

    /* Product: '<S15>/Product1' incorporates:
     *  Constant: '<S14>/Wn'
     */
    Pong_B.Product1 = Pong_P.Wn_Value * rtb_Integrator1_l;

    /* Integrator: '<S1>/Integrator1' */
    rtb_Integrator1 = Pong_X.Integrator1_CSTATE;

    /* Sum: '<S8>/Sum1' incorporates:
     *  Constant: '<S6>/Constant2'
     *  Constant: '<S6>/Constant6'
     *  Integrator: '<S1>/Integrator1'
     */
    Pong_B.Sum1 = ((Pong_B.pos[2] - Pong_X.Integrator1_CSTATE) +
                   Pong_P.Constant2_Value) + Pong_P.Constant6_Value;
    if (rtmIsMajorTimeStep(Pong_M)) {
      /* Sum: '<S12>/Sum8' incorporates:
       *  Constant: '<S6>/Constant4'
       */
      Pong_B.Sum8 = Pong_B.pos[1] + Pong_P.Constant4_Value;
    }

    if (rtmIsMajorTimeStep(Pong_M)) {
      /* Sum: '<S12>/Sum9' incorporates:
       *  Constant: '<S6>/Constant4'
       */
      Pong_B.Sum9 = Pong_B.pos[1] - Pong_P.Constant4_Value;
    }

    /* Logic: '<S8>/Logical Operator' incorporates:
     *  Constant: '<S16>/Constant'
     *  Integrator: '<S1>/Integrator3'
     *  Logic: '<S12>/Logical Operator1'
     *  RelationalOperator: '<S12>/Relational Operator'
     *  RelationalOperator: '<S12>/Relational Operator1'
     *  RelationalOperator: '<S16>/Compare'
     */
    rtb_LogicalOperator = (((Pong_B.Sum1 >= Pong_P.Constant_Value_n) != 0U) &&
                           ((Pong_X.Integrator3_CSTATE <= Pong_B.Sum8) &&
      (Pong_X.Integrator3_CSTATE >= Pong_B.Sum9)));

    /* Switch: '<S7>/Switch4' incorporates:
     *  Constant: '<S13>/Constant'
     *  Constant: '<S7>/non contact Force4'
     *  Gain: '<S14>/Gain1'
     *  Gain: '<S14>/Gain3'
     *  Logic: '<S7>/Logical Operator2'
     *  RelationalOperator: '<S13>/Compare'
     *  Sum: '<S14>/Subtract'
     */
    if (((Pong_B.Sum10 != Pong_P.Constant_Value) != 0U) && rtb_LogicalOperator)
    {
      rtb_Switch3 = Pong_P.Gain3_Gain_i * Pong_B.Sum10 - Pong_P.Gain1_Gain *
        Pong_B.Product1;
    } else {
      rtb_Switch3 = Pong_P.noncontactForce4_Value;
    }

    /* Integrator: '<S18>/Integrator' */
    rtb_Switch2 = Pong_X.Integrator_CSTATE_c;

    /* Product: '<S18>/Product1' incorporates:
     *  Constant: '<S17>/Wn'
     */
    Pong_B.Product1_n = Pong_P.Wn_Value_j * rtb_Switch2;

    /* Switch: '<S8>/Switch' incorporates:
     *  Constant: '<S8>/non contact Force'
     *  Gain: '<S17>/Gain1'
     *  Gain: '<S17>/Gain3'
     *  Sum: '<S17>/Subtract'
     */
    if (rtb_LogicalOperator) {
      rtb_Switch = Pong_P.Gain3_Gain_ij * Pong_B.Sum1 - Pong_P.Gain1_Gain_a *
        Pong_B.Product1_n;
    } else {
      rtb_Switch = Pong_P.noncontactForce_Value;
    }

    /* Switch: '<S3>/SwitchControl' incorporates:
     *  Constant: '<Root>/Constant10'
     *  Constant: '<Root>/Constant12'
     *  Constant: '<S3>/Constant'
     *  Gain: '<S1>/Gain1'
     */
    if (Pong_P.Constant_Value_k > Pong_P.SwitchControl_Threshold) {
      rtb_Kt[0] = Pong_P.Constant12_Value;
      rtb_Kt[1] = rtb_Switch3;
      rtb_Kt[2] = Pong_P.Gain1_Gain_l * rtb_Switch;
    } else {
      rtb_Kt[0] = Pong_P.Constant10_Value[0];
      rtb_Kt[1] = Pong_P.Constant10_Value[1];
      rtb_Kt[2] = Pong_P.Constant10_Value[2];
    }

    /* SignalConversion: '<S4>/TmpHiddenBufferAtProductInport2' incorporates:
     *  Constant: '<S4>/Constant'
     */
    rtb_TmpHiddenBufferAtProductInp[0] = rtb_Kt[0];
    rtb_TmpHiddenBufferAtProductInp[1] = rtb_Kt[1];
    rtb_TmpHiddenBufferAtProductInp[2] = rtb_Kt[2];
    rtb_TmpHiddenBufferAtProductInp[3] = Pong_P.Constant_Value_g[0];
    rtb_TmpHiddenBufferAtProductInp[4] = Pong_P.Constant_Value_g[1];
    rtb_TmpHiddenBufferAtProductInp[5] = Pong_P.Constant_Value_g[2];

    {
      static const int_T dims[3] = { 3, 6, 1 };

      rt_MatMultRR_Dbl(rtb_Kt, Pong_B.MathFunction,
                       rtb_TmpHiddenBufferAtProductInp, &dims[0]);
    }

    /* Gain: '<S4>/Convert to Positive Rotation Convension Used in Kinematics1' */
    Pong_B.ConverttoPositiveRotationConven[0] =
      Pong_P.ConverttoPositiveRotationConv_d[0] * rtb_Kt[0];
    Pong_B.ConverttoPositiveRotationConven[1] =
      Pong_P.ConverttoPositiveRotationConv_d[1] * rtb_Kt[1];
    Pong_B.ConverttoPositiveRotationConven[2] =
      Pong_P.ConverttoPositiveRotationConv_d[2] * rtb_Kt[2];

    /* Embedded MATLAB: '<S28>/Joint Torque to Motor Torque' */
    {
      int32_T eml_i0;

      /*  Smart Saturation: allows channels to go up to 1.6A  */
      /*  unless the total exceeds 2.2A in which case all channels */
      /*  are scaled so that the cumulative current is equal to 2.2A. */
      for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
        Pong_B.y_d[eml_i0] = 0.0;
      }

      Pong_B.y_d[0] = Pong_B.ConverttoPositiveRotationConven[0];
      Pong_B.y_d[2] = Pong_B.ConverttoPositiveRotationConven[2];
      Pong_B.y_d[1] = Pong_B.ConverttoPositiveRotationConven[1] -
        Pong_B.ConverttoPositiveRotationConven[2];
    }

    /* Gain: '<S28>/Kt' incorporates:
     *  Gain: '<S28>/Gear Ratio1'
     */
    rtb_Kt[0] = Pong_P.GearRatio1_Gain[0] * Pong_B.y_d[0] * Pong_P.Kt_Gain;
    rtb_Kt[1] = Pong_P.GearRatio1_Gain[1] * Pong_B.y_d[1] * Pong_P.Kt_Gain;
    rtb_Kt[2] = Pong_P.GearRatio1_Gain[2] * Pong_B.y_d[2] * Pong_P.Kt_Gain;

    /* Saturate: '<S28>/Saturation' */
    Pong_B.Saturation[0] = rt_SATURATE(rtb_Kt[0], Pong_P.Saturation_LowerSat,
      Pong_P.Saturation_UpperSat);
    Pong_B.Saturation[1] = rt_SATURATE(rtb_Kt[1], Pong_P.Saturation_LowerSat,
      Pong_P.Saturation_UpperSat);
    Pong_B.Saturation[2] = rt_SATURATE(rtb_Kt[2], Pong_P.Saturation_LowerSat,
      Pong_P.Saturation_UpperSat);

    /* Embedded MATLAB: '<S28>/Smart Saturation' */
    {
      int32_T eml_k;
      real_T eml_x[3];
      real_T eml_total;

      /*  Smart Saturation: allows channels to go up to 1.6A  */
      /*  unless the total exceeds 2.2A in which case all channels */
      /*  are scaled so that the cumulative current is equal to 2.2A. */
      /*  Define the maximum cumulative current here */
      for (eml_k = 0; eml_k < 3; eml_k++) {
        eml_x[eml_k] = fabs(Pong_B.Saturation[eml_k]);
      }

      eml_total = eml_x[0];
      for (eml_k = 2; eml_k < 4; eml_k++) {
        eml_total += eml_x[eml_k - 1];
      }

      if (eml_total > 2.2) {
        eml_total = 2.2 / eml_total;
        for (eml_k = 0; eml_k < 3; eml_k++) {
          Pong_B.y[eml_k] = eml_total * Pong_B.Saturation[eml_k];
        }
      } else {
        for (eml_k = 0; eml_k < 3; eml_k++) {
          Pong_B.y[eml_k] = Pong_B.Saturation[eml_k];
        }
      }
    }

    if (rtmIsMajorTimeStep(Pong_M)) {
      /* S-Function Block: Pong/Omni/HIL Write PWM (hil_write_pwm_block) */
      {
        t_error result;
        result = hil_write_pwm(Pong_DWork.HILInitialize_Card,
          Pong_P.HILWritePWM_Channels, 3, Pong_B.y);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Pong_M, _rt_error_message);
        }
      }

      /* S-Function Block: Pong/Omni/HIL Read Analog (hil_read_analog_block) */
      {
        t_error result = hil_read_analog(Pong_DWork.HILInitialize_Card,
          Pong_P.HILReadAnalog_Channels, 3, rtb_HILReadAnalog);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Pong_M, _rt_error_message);
        }
      }
    }

    /* Integrator: '<S15>/Integrator1' */
    if (Pong_DWork.Integrator1_IWORK.IcNeedsLoading) {
      Pong_X.Integrator1_CSTATE_i = Pong_B.Sum10;
      Pong_DWork.Integrator1_IWORK.IcNeedsLoading = 0;
    }

    rtb_Switch2_k = Pong_X.Integrator1_CSTATE_i;

    /* Product: '<S15>/Product' incorporates:
     *  Constant: '<S14>/Wn'
     *  Constant: '<S14>/z'
     *  Constant: '<S15>/Constant'
     *  Product: '<S15>/Product2'
     *  Sum: '<S15>/Sum'
     *  Sum: '<S15>/Sum1'
     */
    Pong_B.Product = ((Pong_B.Sum10 - rtb_Switch2_k) - rtb_Integrator1_l *
                      Pong_P.Constant_Value_nt * Pong_P.z_Value) *
      Pong_P.Wn_Value;

    /* Gain: '<S1>/Gain3' */
    rtb_Gain3 = Pong_P.Gain3_Gain * rtb_Switch3;
    if (rtmIsMajorTimeStep(Pong_M)) {
      /* Gain: '<S1>/Gain4' incorporates:
       *  Constant: '<S6>/Constant3'
       */
      Pong_B.Gain4 = Pong_P.Gain4_Gain * Pong_P.Constant3_Value;
    }

    /* Integrator: '<S1>/Integrator2' */
    Pong_B.Integrator2 = Pong_X.Integrator2_CSTATE;

    /* Integrator: '<S20>/Integrator' */
    rtb_Switch2_k = Pong_X.Integrator_CSTATE_cz;

    /* Sum: '<S9>/Sum5' incorporates:
     *  Constant: '<S6>/Constant2'
     */
    Pong_B.Sum5 = (Pong_B.Gain4 + Pong_P.Constant2_Value) - rtb_Integrator3;

    /* Integrator: '<S20>/Integrator1' */
    if (Pong_DWork.Integrator1_IWORK_k.IcNeedsLoading) {
      Pong_X.Integrator1_CSTATE_p = Pong_B.Sum5;
      Pong_DWork.Integrator1_IWORK_k.IcNeedsLoading = 0;
    }

    rtb_Switch3 = Pong_X.Integrator1_CSTATE_p;

    /* Product: '<S20>/Product' incorporates:
     *  Constant: '<S19>/Wn'
     *  Constant: '<S19>/z'
     *  Constant: '<S20>/Constant'
     *  Product: '<S20>/Product2'
     *  Sum: '<S20>/Sum'
     *  Sum: '<S20>/Sum1'
     */
    Pong_B.Product_b = ((Pong_B.Sum5 - rtb_Switch3) - rtb_Switch2_k *
                        Pong_P.Constant_Value_p * Pong_P.z_Value_a) *
      Pong_P.Wn_Value_ju;

    /* Product: '<S20>/Product1' incorporates:
     *  Constant: '<S19>/Wn'
     */
    Pong_B.Product1_m = Pong_P.Wn_Value_ju * rtb_Switch2_k;

    /* Switch: '<S9>/Switch2' incorporates:
     *  Constant: '<S9>/non contact Force2'
     *  Gain: '<S19>/Gain1'
     *  Gain: '<S19>/Gain3'
     *  Sum: '<S19>/Subtract'
     */
    if (Pong_B.Sum5 >= Pong_P.Switch2_Threshold) {
      rtb_Switch2_k = Pong_P.Gain3_Gain_c * Pong_B.Sum5 - Pong_P.Gain1_Gain_g *
        Pong_B.Product1_m;
    } else {
      rtb_Switch2_k = Pong_P.noncontactForce2_Value;
    }

    /* Integrator: '<S22>/Integrator' */
    rtb_Switch3 = Pong_X.Integrator_CSTATE_p;

    /* Sum: '<S10>/Sum6' incorporates:
     *  Constant: '<S6>/Constant2'
     *  Constant: '<S6>/Constant3'
     */
    Pong_B.Sum6 = (Pong_P.Constant3_Value - Pong_P.Constant2_Value) -
      rtb_Integrator3;

    /* Integrator: '<S22>/Integrator1' */
    if (Pong_DWork.Integrator1_IWORK_h.IcNeedsLoading) {
      Pong_X.Integrator1_CSTATE_d = Pong_B.Sum6;
      Pong_DWork.Integrator1_IWORK_h.IcNeedsLoading = 0;
    }

    rtb_Integrator1_l = Pong_X.Integrator1_CSTATE_d;

    /* Product: '<S22>/Product' incorporates:
     *  Constant: '<S21>/Wn'
     *  Constant: '<S21>/z'
     *  Constant: '<S22>/Constant'
     *  Product: '<S22>/Product2'
     *  Sum: '<S22>/Sum'
     *  Sum: '<S22>/Sum1'
     */
    Pong_B.Product_h = ((Pong_B.Sum6 - rtb_Integrator1_l) - rtb_Switch3 *
                        Pong_P.Constant_Value_n2 * Pong_P.z_Value_f) *
      Pong_P.Wn_Value_e;

    /* Product: '<S22>/Product1' incorporates:
     *  Constant: '<S21>/Wn'
     */
    Pong_B.Product1_g = Pong_P.Wn_Value_e * rtb_Switch3;

    /* Switch: '<S10>/Switch3' incorporates:
     *  Constant: '<S10>/non contact Force3'
     *  Gain: '<S21>/Gain1'
     *  Gain: '<S21>/Gain3'
     *  Sum: '<S21>/Subtract'
     */
    if (Pong_B.Sum6 >= Pong_P.Switch3_Threshold) {
      rtb_Switch3 = Pong_P.noncontactForce3_Value;
    } else {
      rtb_Switch3 = Pong_P.Gain3_Gain_cs * Pong_B.Sum6 - Pong_P.Gain1_Gain_h *
        Pong_B.Product1_g;
    }

    /* Sum: '<S1>/Sum7' */
    Pong_B.Sum7 = (rtb_Switch3 + rtb_Switch2_k) + rtb_Gain3;

    /* TransferFcn Block: '<S1>/Transfer Fcn1' */
    Pong_B.TransferFcn1 = Pong_P.TransferFcn1_D*Pong_B.Sum7;

    /* Integrator: '<S1>/Integrator' */
    Pong_B.Integrator = Pong_X.Integrator_CSTATE_o;

    /* Integrator: '<S18>/Integrator1' */
    if (Pong_DWork.Integrator1_IWORK_e.IcNeedsLoading) {
      Pong_X.Integrator1_CSTATE_h = Pong_B.Sum1;
      Pong_DWork.Integrator1_IWORK_e.IcNeedsLoading = 0;
    }

    rtb_Switch2_k = Pong_X.Integrator1_CSTATE_h;

    /* Product: '<S18>/Product' incorporates:
     *  Constant: '<S17>/Wn'
     *  Constant: '<S17>/z'
     *  Constant: '<S18>/Constant'
     *  Product: '<S18>/Product2'
     *  Sum: '<S18>/Sum'
     *  Sum: '<S18>/Sum1'
     */
    Pong_B.Product_he = ((Pong_B.Sum1 - rtb_Switch2_k) - rtb_Switch2 *
                         Pong_P.Constant_Value_o * Pong_P.z_Value_j) *
      Pong_P.Wn_Value_j;

    /* Integrator: '<S24>/Integrator' */
    rtb_Switch2_k = Pong_X.Integrator_CSTATE_f;
    if (rtmIsMajorTimeStep(Pong_M)) {
      /* Sum: '<S1>/Sum4' incorporates:
       *  Constant: '<S6>/Constant3'
       *  Constant: '<S6>/Constant9'
       */
      Pong_B.Sum4 = Pong_P.Constant3_Value + Pong_P.Constant9_Value[1];
    }

    /* Sum: '<S11>/Sum2' incorporates:
     *  Constant: '<S6>/Constant2'
     */
    Pong_B.Sum2 = (Pong_B.Sum4 - Pong_P.Constant2_Value) - rtb_Integrator1;

    /* Integrator: '<S24>/Integrator1' */
    if (Pong_DWork.Integrator1_IWORK_hb.IcNeedsLoading) {
      Pong_X.Integrator1_CSTATE_e = Pong_B.Sum2;
      Pong_DWork.Integrator1_IWORK_hb.IcNeedsLoading = 0;
    }

    rtb_Switch2 = Pong_X.Integrator1_CSTATE_e;

    /* Product: '<S24>/Product' incorporates:
     *  Constant: '<S23>/Wn'
     *  Constant: '<S23>/z'
     *  Constant: '<S24>/Constant'
     *  Product: '<S24>/Product2'
     *  Sum: '<S24>/Sum'
     *  Sum: '<S24>/Sum1'
     */
    Pong_B.Product_m = ((Pong_B.Sum2 - rtb_Switch2) - rtb_Switch2_k *
                        Pong_P.Constant_Value_o1 * Pong_P.z_Value_h) *
      Pong_P.Wn_Value_h;

    /* Product: '<S24>/Product1' incorporates:
     *  Constant: '<S23>/Wn'
     */
    Pong_B.Product1_h = Pong_P.Wn_Value_h * rtb_Switch2_k;

    /* Switch: '<S11>/Switch1' incorporates:
     *  Constant: '<S11>/non contact Force1'
     *  Gain: '<S23>/Gain1'
     *  Gain: '<S23>/Gain3'
     *  Sum: '<S23>/Subtract'
     */
    if (Pong_B.Sum2 >= Pong_P.Switch1_Threshold) {
      rtb_Switch2_k = Pong_P.noncontactForce1_Value;
    } else {
      rtb_Switch2_k = Pong_P.Gain3_Gain_d * Pong_B.Sum2 - Pong_P.Gain1_Gain_a1 *
        Pong_B.Product1_h;
    }

    /* Sum: '<S1>/Sum' incorporates:
     *  Constant: '<S1>/Gravity'
     *  Sum: '<S1>/Sum3'
     */
    Pong_B.Sum = (rtb_Switch2_k + rtb_Switch) + Pong_P.Gravity_Value;

    /* TransferFcn Block: '<S1>/Transfer Fcn' */
    Pong_B.TransferFcn = Pong_P.TransferFcn_D*Pong_B.Sum;

    /* RateTransition: '<S5>/Rate Transition6' incorporates:
     *  Constant: '<S6>/Constant2'
     */
    if (rtmIsMajorTimeStep(Pong_M) && Pong_M->Timing.RateInteraction.TID1_2) {
      Pong_B.RateTransition6[0] = Pong_P.Constant2_Value;
      Pong_B.RateTransition6[1] = Pong_P.Constant2_Value;
      Pong_B.RateTransition6[2] = Pong_P.Constant2_Value;
    }

    if (rtmIsMajorTimeStep(Pong_M)) {
      /* Sum: '<S5>/Sum5' incorporates:
       *  Constant: '<S6>/Constant2'
       *  Constant: '<S6>/Constant3'
       */
      Pong_B.Sum5_k = Pong_P.Constant3_Value - Pong_P.Constant2_Value;
    }

    if (rtmIsMajorTimeStep(Pong_M)) {
      /* Sum: '<S5>/Sum6' incorporates:
       *  Constant: '<S6>/Constant2'
       *  Constant: '<S6>/Constant3'
       */
      Pong_B.Sum6_b = Pong_P.Constant2_Value - Pong_P.Constant3_Value;
    }

    /* Switch: '<S32>/Switch2' incorporates:
     *  RelationalOperator: '<S32>/LowerRelop1'
     */
    if (rtb_Integrator3 > Pong_B.Sum5_k) {
      rtb_Switch2_k = Pong_B.Sum5_k;
    } else {
      /* Switch: '<S32>/Switch' incorporates:
       *  RelationalOperator: '<S32>/UpperRelop'
       */
      if (rtb_Integrator3 < Pong_B.Sum6_b) {
        rtb_Integrator3 = Pong_B.Sum6_b;
      }

      rtb_Switch2_k = rtb_Integrator3;
    }

    if (rtmIsMajorTimeStep(Pong_M)) {
      /* Sum: '<S5>/Sum3' incorporates:
       *  Constant: '<S6>/Constant2'
       *  Constant: '<S6>/Constant3'
       *  Constant: '<S6>/Constant9'
       */
      Pong_B.Sum3 = (Pong_P.Constant3_Value + Pong_P.Constant9_Value[1]) -
        Pong_P.Constant2_Value;
    }

    if (rtmIsMajorTimeStep(Pong_M)) {
      /* Sum: '<S5>/Sum4' incorporates:
       *  Constant: '<S6>/Constant2'
       *  Constant: '<S6>/Constant6'
       */
      Pong_B.Sum4_b = (Pong_B.pos[2] + Pong_P.Constant6_Value) +
        Pong_P.Constant2_Value;
    }

    /* Switch: '<S33>/Switch2' incorporates:
     *  RelationalOperator: '<S33>/LowerRelop1'
     */
    if (rtb_Integrator1 > Pong_B.Sum3) {
      rtb_Switch2 = Pong_B.Sum3;
    } else {
      /* Switch: '<S5>/Switch' incorporates:
       *  Constant: '<S5>/Constant1'
       */
      if (rtb_LogicalOperator) {
        rtb_Integrator3 = Pong_B.Sum4_b;
      } else {
        rtb_Integrator3 = Pong_P.Constant1_Value;
      }

      /* Switch: '<S33>/Switch' incorporates:
       *  RelationalOperator: '<S33>/UpperRelop'
       */
      if (!(rtb_Integrator1 < rtb_Integrator3)) {
        rtb_Integrator3 = rtb_Integrator1;
      }

      rtb_Switch2 = rtb_Integrator3;
    }

    /* RateTransition: '<S5>/Rate Transition7' incorporates:
     *  Constant: '<Root>/z position of ball'
     */
    if (rtmIsMajorTimeStep(Pong_M) && Pong_M->Timing.RateInteraction.TID0_2) {
      Pong_B.RateTransition7[0] = rtb_Switch2_k;
      Pong_B.RateTransition7[1] = rtb_Switch2;
      Pong_B.RateTransition7[2] = Pong_P.zpositionofball_Value;
    }

    /* RateTransition: '<S5>/Rate Transition1' incorporates:
     *  Constant: '<S6>/Constant4'
     *  Constant: '<S6>/Constant6'
     */
    if (rtmIsMajorTimeStep(Pong_M) && Pong_M->Timing.RateInteraction.TID1_2) {
      Pong_B.RateTransition1[0] = Pong_P.Constant4_Value;
      Pong_B.RateTransition1[1] = Pong_P.Constant6_Value;
      Pong_B.RateTransition1[2] = Pong_P.Constant6_Value;
    }

    /* RateTransition: '<S5>/Rate Transition5' incorporates:
     *  Constant: '<Root>/Constant7'
     */
    if (rtmIsMajorTimeStep(Pong_M) && Pong_M->Timing.RateInteraction.TID1_2) {
      Pong_B.RateTransition5[0] = Pong_B.pos[1];
      Pong_B.RateTransition5[1] = Pong_B.pos[2];
      Pong_B.RateTransition5[2] = Pong_P.Constant7_Value;
    }

    /* RateTransition: '<S5>/Rate Transition4' incorporates:
     *  Constant: '<S5>/Constant5'
     *  Constant: '<S6>/Constant3'
     */
    if (rtmIsMajorTimeStep(Pong_M) && Pong_M->Timing.RateInteraction.TID1_2) {
      Pong_B.RateTransition4[0] = Pong_P.Constant3_Value;
      Pong_B.RateTransition4[1] = Pong_P.Constant3_Value;
      Pong_B.RateTransition4[2] = Pong_P.Constant5_Value;
    }

    /* RateTransition: '<S5>/Rate Transition3' incorporates:
     *  Constant: '<S6>/Constant9'
     */
    if (rtmIsMajorTimeStep(Pong_M) && Pong_M->Timing.RateInteraction.TID1_2) {
      Pong_B.RateTransition3[0] = Pong_P.Constant9_Value[0];
      Pong_B.RateTransition3[1] = Pong_P.Constant9_Value[1];
      Pong_B.RateTransition3[2] = Pong_P.Constant9_Value[2];
    }

    if (rtmIsMajorTimeStep(Pong_M)) {
      /* Sum: '<S35>/Add' incorporates:
       *  Constant: '<S35>/Constant1'
       *  Constant: '<S6>/Constant3'
       *  Constant: '<S6>/Constant9'
       */
      Pong_B.Add = (Pong_P.Constant9_Value[1] - Pong_P.Constant3_Value) -
        Pong_P.Constant1_Value_f;
    }

    /* Switch: '<S34>/SwitchControl' */
    if (Pong_P.Constant_Value_i > Pong_P.SwitchControl_Threshold_k) {
      /* Switch: '<S35>/Switch1' incorporates:
       *  Constant: '<S34>/Constant'
       *  Constant: '<S35>/Constant10'
       *  Constant: '<S35>/Constant2'
       *  Constant: '<S6>/Constant11'
       *  RelationalOperator: '<S35>/Relational Operator'
       *  Switch: '<S34>/SwitchControl'
       */
      if (Pong_B.Add >= rtb_Integrator1) {
        Pong_B.SwitchControl = Pong_P.Constant2_Value_f;
      } else {
        Pong_B.SwitchControl = Pong_P.Constant10_Value_k;
      }
    } else {
      Pong_B.SwitchControl = Pong_P.Constant11_Value;
    }

    if (rtmIsMajorTimeStep(Pong_M)) {
      /* Stop: '<S6>/Stop Simulation' */
      if (Pong_B.SwitchControl != 0.0) {
        rtmSetStopRequested(Pong_M, 1);
      }
    }
  }

  UNUSED_PARAMETER(tid);
}

/* Model update function for TID0 */
void Pong_update0(int_T tid)           /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(Pong_M)) {
    rt_ertODEUpdateContinuousStates(&Pong_M->solverInfo);
  }

  /* Update absolute time */
  if (!(++Pong_M->Timing.clockTick0))
    ++Pong_M->Timing.clockTickH0;
  Pong_M->Timing.t[0] = Pong_M->Timing.clockTick0 * Pong_M->Timing.stepSize0 +
    Pong_M->Timing.clockTickH0 * Pong_M->Timing.stepSize0 * 4294967296.0;

  /* Update absolute time */
  if (!(++Pong_M->Timing.clockTick1))
    ++Pong_M->Timing.clockTickH1;
  Pong_M->Timing.t[1] = Pong_M->Timing.clockTick1 * Pong_M->Timing.stepSize1 +
    Pong_M->Timing.clockTickH1 * Pong_M->Timing.stepSize1 * 4294967296.0;
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void Pong_derivatives(void)
{
  /* Derivatives for Integrator: '<S1>/Integrator3' */
  ((StateDerivatives_Pong *) Pong_M->ModelData.derivs)->Integrator3_CSTATE =
    Pong_B.Integrator2;

  /* Derivatives for Integrator: '<S15>/Integrator' */
  ((StateDerivatives_Pong *) Pong_M->ModelData.derivs)->Integrator_CSTATE =
    Pong_B.Product;

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  ((StateDerivatives_Pong *) Pong_M->ModelData.derivs)->Integrator1_CSTATE =
    Pong_B.Integrator;

  /* Derivatives for Integrator: '<S18>/Integrator' */
  ((StateDerivatives_Pong *) Pong_M->ModelData.derivs)->Integrator_CSTATE_c =
    Pong_B.Product_he;

  /* Integrator Block: '<S15>/Integrator1' */
  {
    ((StateDerivatives_Pong *) Pong_M->ModelData.derivs)->Integrator1_CSTATE_i =
      Pong_B.Product1;
  }

  /* Derivatives for Integrator: '<S1>/Integrator2' */
  ((StateDerivatives_Pong *) Pong_M->ModelData.derivs)->Integrator2_CSTATE =
    Pong_B.TransferFcn1;

  /* Derivatives for Integrator: '<S20>/Integrator' */
  ((StateDerivatives_Pong *) Pong_M->ModelData.derivs)->Integrator_CSTATE_cz =
    Pong_B.Product_b;

  /* Integrator Block: '<S20>/Integrator1' */
  {
    ((StateDerivatives_Pong *) Pong_M->ModelData.derivs)->Integrator1_CSTATE_p =
      Pong_B.Product1_m;
  }

  /* Derivatives for Integrator: '<S22>/Integrator' */
  ((StateDerivatives_Pong *) Pong_M->ModelData.derivs)->Integrator_CSTATE_p =
    Pong_B.Product_h;

  /* Integrator Block: '<S22>/Integrator1' */
  {
    ((StateDerivatives_Pong *) Pong_M->ModelData.derivs)->Integrator1_CSTATE_d =
      Pong_B.Product1_g;
  }

  /* Derivatives for Integrator: '<S1>/Integrator' */
  ((StateDerivatives_Pong *) Pong_M->ModelData.derivs)->Integrator_CSTATE_o =
    Pong_B.TransferFcn;

  /* Integrator Block: '<S18>/Integrator1' */
  {
    ((StateDerivatives_Pong *) Pong_M->ModelData.derivs)->Integrator1_CSTATE_h =
      Pong_B.Product1_n;
  }

  /* Derivatives for Integrator: '<S24>/Integrator' */
  ((StateDerivatives_Pong *) Pong_M->ModelData.derivs)->Integrator_CSTATE_f =
    Pong_B.Product_m;

  /* Integrator Block: '<S24>/Integrator1' */
  {
    ((StateDerivatives_Pong *) Pong_M->ModelData.derivs)->Integrator1_CSTATE_e =
      Pong_B.Product1_h;
  }
}

/* Model output function for TID2 */
void Pong_output2(int_T tid)           /* Sample time: [0.1s, 0.0s] */
{
  /* (no output code required) */
  UNUSED_PARAMETER(tid);
}

/* Model update function for TID2 */
void Pong_update2(int_T tid)           /* Sample time: [0.1s, 0.0s] */
{
  /* Update absolute time */
  if (!(++Pong_M->Timing.clockTick2))
    ++Pong_M->Timing.clockTickH2;
  Pong_M->Timing.t[2] = Pong_M->Timing.clockTick2 * Pong_M->Timing.stepSize2 +
    Pong_M->Timing.clockTickH2 * Pong_M->Timing.stepSize2 * 4294967296.0;
  UNUSED_PARAMETER(tid);
}

void Pong_output(int_T tid)
{
  switch (tid) {
   case 0 :
    Pong_output0(0);
    break;

   case 2 :
    Pong_output2(2);
    break;

   default :
    break;
  }
}

void Pong_update(int_T tid)
{
  switch (tid) {
   case 0 :
    Pong_update0(0);
    break;

   case 2 :
    Pong_update2(2);
    break;

   default :
    break;
  }
}

/* Model initialize function */
void Pong_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));    /* initialize real-time model */
  (void) memset((char_T *)Pong_M,0,
                sizeof(RT_MODEL_Pong));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Pong_M->solverInfo, &Pong_M->Timing.simTimeStep);
    rtsiSetTPtr(&Pong_M->solverInfo, &rtmGetTPtr(Pong_M));
    rtsiSetStepSizePtr(&Pong_M->solverInfo, &Pong_M->Timing.stepSize0);
    rtsiSetdXPtr(&Pong_M->solverInfo, &Pong_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Pong_M->solverInfo, &Pong_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Pong_M->solverInfo, &Pong_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Pong_M->solverInfo, (&rtmGetErrorStatus(Pong_M)));
    rtsiSetRTModelPtr(&Pong_M->solverInfo, Pong_M);
  }

  rtsiSetSimTimeStep(&Pong_M->solverInfo, MAJOR_TIME_STEP);
  Pong_M->ModelData.intgData.y = Pong_M->ModelData.odeY;
  Pong_M->ModelData.intgData.f[0] = Pong_M->ModelData.odeF[0];
  Pong_M->ModelData.intgData.f[1] = Pong_M->ModelData.odeF[1];
  Pong_M->ModelData.intgData.f[2] = Pong_M->ModelData.odeF[2];
  Pong_M->ModelData.intgData.f[3] = Pong_M->ModelData.odeF[3];
  Pong_M->ModelData.contStates = ((real_T *) &Pong_X);
  rtsiSetSolverData(&Pong_M->solverInfo, (void *)&Pong_M->ModelData.intgData);
  rtsiSetSolverName(&Pong_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Pong_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    Pong_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Pong_M->Timing.sampleTimes = (&Pong_M->Timing.sampleTimesArray[0]);
    Pong_M->Timing.offsetTimes = (&Pong_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Pong_M->Timing.sampleTimes[0] = (0.0);
    Pong_M->Timing.sampleTimes[1] = (0.001);
    Pong_M->Timing.sampleTimes[2] = (0.1);

    /* task offsets */
    Pong_M->Timing.offsetTimes[0] = (0.0);
    Pong_M->Timing.offsetTimes[1] = (0.0);
    Pong_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(Pong_M, &Pong_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Pong_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = Pong_M->Timing.perTaskSampleHitsArray;
    Pong_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    Pong_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Pong_M, -1);
  Pong_M->Timing.stepSize0 = 0.001;
  Pong_M->Timing.stepSize1 = 0.001;
  Pong_M->Timing.stepSize2 = 0.1;

  /* external mode info */
  Pong_M->Sizes.checksums[0] = (2496160883U);
  Pong_M->Sizes.checksums[1] = (1721223492U);
  Pong_M->Sizes.checksums[2] = (2761988816U);
  Pong_M->Sizes.checksums[3] = (1532070706U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[14];
    Pong_M->extModeInfo = (&rt_ExtModeInfo);
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
    systemRan[13] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo, &Pong_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, Pong_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(Pong_M));
  }

  Pong_M->solverInfoPtr = (&Pong_M->solverInfo);
  Pong_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Pong_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Pong_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  Pong_M->ModelData.blockIO = ((void *) &Pong_B);

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&Pong_B.GearRatio[0]);
    for (i = 0; i < 95; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    pVoidBlockIORegion = (void *)(&Pong_B.y[0]);
    for (i = 0; i < 39; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }
  }

  /* parameters */
  Pong_M->ModelData.defaultParam = ((real_T *) &Pong_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Pong_X;
    Pong_M->ModelData.contStates = (x);
    (void) memset((char_T *)x,0,
                  sizeof(ContinuousStates_Pong));
  }

  /* states (dwork) */
  Pong_M->Work.dwork = ((void *) &Pong_DWork);
  (void) memset((char_T *) &Pong_DWork,0,
                sizeof(D_Work_Pong));

  {
    int_T i;
    real_T *dwork_ptr = (real_T *) &Pong_DWork.HILInitialize_AIMinimums[0];
    for (i = 0; i < 13; i++) {
      dwork_ptr[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    Pong_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void Pong_terminate(void)
{
  /* S-Function Block: Pong/Omni/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    hil_task_stop_all(Pong_DWork.HILInitialize_Card);
    hil_task_delete_all(Pong_DWork.HILInitialize_Card);
    is_switching = false;
    if ((Pong_P.HILInitialize_POTerminate && !is_switching) ||
        (Pong_P.HILInitialize_POExit && is_switching)) {
      Pong_DWork.HILInitialize_POValues[0] = Pong_P.HILInitialize_POFinal;
      Pong_DWork.HILInitialize_POValues[1] = Pong_P.HILInitialize_POFinal;
      Pong_DWork.HILInitialize_POValues[2] = Pong_P.HILInitialize_POFinal;
      result = hil_write_pwm(Pong_DWork.HILInitialize_Card,
        &Pong_P.HILInitialize_POChannels[0], 3U,
        &Pong_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Pong_M, _rt_error_message);
      }
    }

    hil_close(Pong_DWork.HILInitialize_Card);
    Pong_DWork.HILInitialize_Card = NULL;
  }

  /* External mode */
  rtExtModeShutdown(3);
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  Pong_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  Pong_update(tid);
}

void MdlInitializeSizes(void)
{
  Pong_M->Sizes.numContStates = (14);  /* Number of continuous states */
  Pong_M->Sizes.numY = (0);            /* Number of model outputs */
  Pong_M->Sizes.numU = (0);            /* Number of model inputs */
  Pong_M->Sizes.sysDirFeedThru = (0);  /* The model is not direct feedthrough */
  Pong_M->Sizes.numSampTimes = (3);    /* Number of sample times */
  Pong_M->Sizes.numBlocks = (183);     /* Number of blocks */
  Pong_M->Sizes.numBlockIO = (49);     /* Number of block outputs */
  Pong_M->Sizes.numBlockPrms = (178);  /* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* Initialize code for chart: '<S25>/Embedded MATLAB Function' */
  Pong_DWork.is_active_c8_Pong = 0U;

  /* Initialize code for chart: '<S4>/Forward Kinematics ' */
  Pong_DWork.is_active_c5_Pong = 0U;

  /* InitializeConditions for Integrator: '<S1>/Integrator3' */
  Pong_X.Integrator3_CSTATE = Pong_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<S15>/Integrator' */
  Pong_X.Integrator_CSTATE = Pong_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  Pong_X.Integrator1_CSTATE = Pong_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S18>/Integrator' */
  Pong_X.Integrator_CSTATE_c = Pong_P.Integrator_IC_i;

  /* Initialize code for chart: '<S28>/Joint Torque to Motor Torque' */
  Pong_DWork.is_active_c4_Pong = 0U;

  /* Initialize code for chart: '<S28>/Smart Saturation' */
  Pong_DWork.is_active_c3_Pong = 0U;

  /* Integrator Block: '<S15>/Integrator1' */
  if (rtmIsFirstInitCond(Pong_M)) {
    Pong_X.Integrator1_CSTATE_i = 0.0;
  }

  Pong_DWork.Integrator1_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S1>/Integrator2' */
  Pong_X.Integrator2_CSTATE = Pong_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S20>/Integrator' */
  Pong_X.Integrator_CSTATE_cz = Pong_P.Integrator_IC_n;

  /* Integrator Block: '<S20>/Integrator1' */
  if (rtmIsFirstInitCond(Pong_M)) {
    Pong_X.Integrator1_CSTATE_p = 0.0;
  }

  Pong_DWork.Integrator1_IWORK_k.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S22>/Integrator' */
  Pong_X.Integrator_CSTATE_p = Pong_P.Integrator_IC_o;

  /* Integrator Block: '<S22>/Integrator1' */
  if (rtmIsFirstInitCond(Pong_M)) {
    Pong_X.Integrator1_CSTATE_d = 0.0;
  }

  Pong_DWork.Integrator1_IWORK_h.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  Pong_X.Integrator_CSTATE_o = Pong_P.Integrator_IC_c;

  /* Integrator Block: '<S18>/Integrator1' */
  if (rtmIsFirstInitCond(Pong_M)) {
    Pong_X.Integrator1_CSTATE_h = 0.0;
  }

  Pong_DWork.Integrator1_IWORK_e.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S24>/Integrator' */
  Pong_X.Integrator_CSTATE_f = Pong_P.Integrator_IC_h;

  /* Integrator Block: '<S24>/Integrator1' */
  if (rtmIsFirstInitCond(Pong_M)) {
    Pong_X.Integrator1_CSTATE_e = 0.0;
  }

  Pong_DWork.Integrator1_IWORK_hb.IcNeedsLoading = 1;
}

void MdlStart(void)
{
  {
    int32_T i;

    /* S-Function Block: Pong/Omni/HIL Initialize (hil_initialize_block) */
    {
      t_int result;
      t_boolean is_switching;
      result = hil_open("phantom_omni", "0", &Pong_DWork.HILInitialize_Card);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Pong_M, _rt_error_message);
        return;
      }

      is_switching = false;
      if ((Pong_P.HILInitialize_AIPStart && !is_switching) ||
          (Pong_P.HILInitialize_AIPEnter && is_switching)) {
        Pong_DWork.HILInitialize_AIMinimums[0] = Pong_P.HILInitialize_AILow;
        Pong_DWork.HILInitialize_AIMinimums[1] = Pong_P.HILInitialize_AILow;
        Pong_DWork.HILInitialize_AIMaximums[0] = Pong_P.HILInitialize_AIHigh;
        Pong_DWork.HILInitialize_AIMaximums[1] = Pong_P.HILInitialize_AIHigh;
        result = hil_set_analog_input_ranges(Pong_DWork.HILInitialize_Card,
          &Pong_P.HILInitialize_AIChannels[0], 2U,
          &Pong_DWork.HILInitialize_AIMinimums[0],
          &Pong_DWork.HILInitialize_AIMaximums[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Pong_M, _rt_error_message);
          return;
        }
      }

      if ((Pong_P.HILInitialize_EIStart && !is_switching) ||
          (Pong_P.HILInitialize_EIEnter && is_switching)) {
        Pong_DWork.HILInitialize_InitialEICounts[0] =
          Pong_P.HILInitialize_EIInitial;
        Pong_DWork.HILInitialize_InitialEICounts[1] =
          Pong_P.HILInitialize_EIInitial;
        Pong_DWork.HILInitialize_InitialEICounts[2] =
          Pong_P.HILInitialize_EIInitial;
        result = hil_set_encoder_counts(Pong_DWork.HILInitialize_Card,
          &Pong_P.HILInitialize_EIChannels[0], 3U,
          &Pong_DWork.HILInitialize_InitialEICounts[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Pong_M, _rt_error_message);
          return;
        }
      }

      if ((Pong_P.HILInitialize_POStart && !is_switching) ||
          (Pong_P.HILInitialize_POEnter && is_switching)) {
        Pong_DWork.HILInitialize_POValues[0] = Pong_P.HILInitialize_POInitial;
        Pong_DWork.HILInitialize_POValues[1] = Pong_P.HILInitialize_POInitial;
        Pong_DWork.HILInitialize_POValues[2] = Pong_P.HILInitialize_POInitial;
        result = hil_write_pwm(Pong_DWork.HILInitialize_Card,
          &Pong_P.HILInitialize_POChannels[0], 3U,
          &Pong_DWork.HILInitialize_POValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Pong_M, _rt_error_message);
          return;
        }
      }

      if (Pong_P.HILInitialize_POReset) {
        Pong_DWork.HILInitialize_POValues[0] = Pong_P.HILInitialize_POWatchdog;
        Pong_DWork.HILInitialize_POValues[1] = Pong_P.HILInitialize_POWatchdog;
        Pong_DWork.HILInitialize_POValues[2] = Pong_P.HILInitialize_POWatchdog;
        result = hil_watchdog_set_pwm_expiration_state
          (Pong_DWork.HILInitialize_Card, &Pong_P.HILInitialize_POChannels[0],
           3U, &Pong_DWork.HILInitialize_POValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Pong_M, _rt_error_message);
          return;
        }
      }
    }

    /* S-Function Block: Pong/Omni/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_create_encoder_reader(Pong_DWork.HILInitialize_Card,
        Pong_P.HILReadEncoderTimebase_SamplesI,
        Pong_P.HILReadEncoderTimebase_Channels, 3,
        &Pong_DWork.HILReadEncoderTimebase_Task);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Pong_M, _rt_error_message);
      }
    }

    for (i = 0; i < 16; i++) {
      /* Start for Constant: '<S4>/Tool Offset2' */
      Pong_B.ToolOffset2[i] = Pong_P.ToolOffset2_Value[i];
    }
  }

  MdlInitialize();
}

RT_MODEL_Pong *Pong(void)
{
  Pong_initialize(1);
  return Pong_M;
}

void MdlTerminate(void)
{
  Pong_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
