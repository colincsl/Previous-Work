/*
 * Gravity_Well.c
 *
 * Real-Time Workshop code generation for Simulink model "Gravity_Well.mdl".
 *
 * Model Version              : 1.201
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Tue Jul 21 14:08:06 2009
 */

#include "Gravity_Well.h"
#include "Gravity_Well_private.h"
#include <stdio.h>
#include "Gravity_Well_dt.h"

/* Block signals (auto storage) */
BlockIO_Gravity_Well Gravity_Well_B;

/* Continuous states */
ContinuousStates_Gravity_Well Gravity_Well_X;

/* Block states (auto storage) */
D_Work_Gravity_Well Gravity_Well_DWork;

/* Real-time model */
RT_MODEL_Gravity_Well Gravity_Well_M_;
RT_MODEL_Gravity_Well *Gravity_Well_M = &Gravity_Well_M_;
static void rate_monotonic_scheduler(void);

/* Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Gravity_Well_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Gravity_Well_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(Gravity_Well_M, 2));
}

time_T rt_SimUpdateDiscreteEvents(int_T rtmNumSampTimes,
  void *rtmTimingData,
  int_T *rtmSampleHitPtr,
  int_T *rtmPerTaskSampleHits)
{
  rtmSampleHitPtr[1] = rtmStepTask(Gravity_Well_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(Gravity_Well_M, 2);
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

  /* tid 1 shares data with slower tid rate: 2 */
  if (Gravity_Well_M->Timing.TaskCounters.TID[1] == 0) {
    Gravity_Well_M->Timing.RateInteraction.TID1_2 =
      (Gravity_Well_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    Gravity_Well_M->Timing.perTaskSampleHits[5] =
      Gravity_Well_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  if (++Gravity_Well_M->Timing.TaskCounters.TID[2] == 100) {/* Sample time: [0.1s, 0.0s] */
    Gravity_Well_M->Timing.TaskCounters.TID[2] = 0;
  }

  Gravity_Well_M->Timing.sampleHits[2] =
    (Gravity_Well_M->Timing.TaskCounters.TID[2] == 0);
}

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
  int_T nXc = 12;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Gravity_Well_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Initial conditions for atomic system:
 *   '<S3>/Euclidean Distance'
 *   '<S4>/Euclidean Distance'
 */
void Gravity__EuclideanDistance_Init(rtDW_EuclideanDistance_Gravity_ *localDW)
{
  /* Initialize code for chart: '<S3>/Euclidean Distance' */
  localDW->is_active_c7_Gravity_Well = 0U;
}

/* Output and update for atomic system:
 *   '<S3>/Euclidean Distance'
 *   '<S4>/Euclidean Distance'
 */
void Gravity_Well_EuclideanDistance(const real_T rtu_diff[3],
  rtB_EuclideanDistance_Gravity_W *localB)
{
  /* Embedded MATLAB: '<S3>/Euclidean Distance' */
  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  localB->mag = sqrt((pow(rtu_diff[0], 2.0) + pow(rtu_diff[1], 2.0)) + pow
                     (rtu_diff[2], 2.0));
}

/* Model output function for TID0 */
void Gravity_Well_output0(int_T tid)   /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_TmpHiddenBufferAtProductInp[6];
  real_T rtb_HILReadAnalog[3];
  real_T rtb_Integrator1[3];
  if (rtmIsMajorTimeStep(Gravity_Well_M)) {
    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Gravity_Well_M)) {
    Gravity_Well_M->Timing.t[0] = rtsiGetT(&Gravity_Well_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Gravity_Well_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&Gravity_Well_M->solverInfo,
                          ((Gravity_Well_M->Timing.clockTick0+1)*
      Gravity_Well_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  {
    int32_T i;
    real_T tmp[18];
    real_T rtb_Integrator_idx;
    real_T rtb_Integrator_idx_0;
    real_T rtb_Integrator_idx_1;
    real_T rtb_Add_idx;
    real_T rtb_Add_idx_0;
    real_T rtb_Add_idx_1;
    real_T rtb_Integrator_o_idx;
    real_T rtb_Integrator_o_idx_0;
    real_T rtb_Integrator_o_idx_1;
    if (rtmIsMajorTimeStep(Gravity_Well_M)) {
      /* S-Function Block: Gravity_Well/Omni/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
      {
        t_error result = hil_task_read_encoder
          (Gravity_Well_DWork.HILReadEncoderTimebase_Task, 1,
           &Gravity_Well_DWork.HILReadEncoderTimebase_Buffer[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Gravity_Well_M, _rt_error_message);
        } else {
          rtb_HILReadAnalog[0] =
            Gravity_Well_DWork.HILReadEncoderTimebase_Buffer[0];
          rtb_HILReadAnalog[1] =
            Gravity_Well_DWork.HILReadEncoderTimebase_Buffer[1];
          rtb_HILReadAnalog[2] =
            Gravity_Well_DWork.HILReadEncoderTimebase_Buffer[2];
        }
      }

      /* Gain: '<S5>/Gear Ratio' incorporates:
       *  Bias: '<S5>/Bias1'
       *  Gain: '<S5>/Encoder'
       */
      Gravity_Well_B.GearRatio[0] = (rtb_HILReadAnalog[0] +
        Gravity_Well_P.Bias1_Bias[0]) * Gravity_Well_P.Encoder_Gain *
        Gravity_Well_P.GearRatio_Gain[0];
      Gravity_Well_B.GearRatio[1] = (rtb_HILReadAnalog[1] +
        Gravity_Well_P.Bias1_Bias[1]) * Gravity_Well_P.Encoder_Gain *
        Gravity_Well_P.GearRatio_Gain[1];
      Gravity_Well_B.GearRatio[2] = (rtb_HILReadAnalog[2] +
        Gravity_Well_P.Bias1_Bias[2]) * Gravity_Well_P.Encoder_Gain *
        Gravity_Well_P.GearRatio_Gain[2];

      /* Embedded MATLAB: '<S5>/Embedded MATLAB Function' */
      {
        int32_T eml_i0;
        for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
          Gravity_Well_B.q[eml_i0] = Gravity_Well_B.GearRatio[eml_i0];
        }

        Gravity_Well_B.q[0] = Gravity_Well_B.GearRatio[0];
        Gravity_Well_B.q[1] = Gravity_Well_B.GearRatio[1];
        Gravity_Well_B.q[2] = (Gravity_Well_B.GearRatio[2] -
          Gravity_Well_B.GearRatio[1]) - 1.5707963267948966E+000;
      }

      /* Bias: '<S2>/Joint Offsets' incorporates:
       *  Gain: '<S2>/Convert to Positive Rotation Convension Used in Kinematics'
       */
      Gravity_Well_B.JointOffsets[0] =
        Gravity_Well_P.ConverttoPositiveRotationConven[0] * Gravity_Well_B.q[0]
        + Gravity_Well_P.JointOffsets_Bias[0];
      Gravity_Well_B.JointOffsets[1] =
        Gravity_Well_P.ConverttoPositiveRotationConven[1] * Gravity_Well_B.q[1]
        + Gravity_Well_P.JointOffsets_Bias[1];
      Gravity_Well_B.JointOffsets[2] =
        Gravity_Well_P.ConverttoPositiveRotationConven[2] * Gravity_Well_B.q[2]
        + Gravity_Well_P.JointOffsets_Bias[2];
      for (i = 0; i < 16; i++) {
        /* Constant: '<S2>/Tool Offset2' */
        Gravity_Well_B.ToolOffset2[i] = Gravity_Well_P.ToolOffset2_Value[i];
      }

      /* Embedded MATLAB: '<S2>/Forward Kinematics ' */
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
        eml_theta_z = Gravity_Well_B.JointOffsets[0];
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

        eml_theta_z = Gravity_Well_B.JointOffsets[1];
        eml_theta_z_0 = Gravity_Well_B.JointOffsets[2] - 1.5707963267948966E+000;

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
            Gravity_Well_B.Rot[eml_i2 + 3 * eml_i0] = eml_T03[eml_i2 + (eml_i0 <<
              2)];
          }
        }

        for (eml_i0 = 0; eml_i0 < 4; eml_i0++) {
          for (eml_i2 = 0; eml_i2 < 4; eml_i2++) {
            eml_dv11[eml_i0 + (eml_i2 << 2)] = 0.0;
            for (eml_i1 = 0; eml_i1 < 4; eml_i1++) {
              eml_dv11[eml_i0 + (eml_i2 << 2)] += eml_T03[eml_i0 + (eml_i1 << 2)]
                * Gravity_Well_B.ToolOffset2[eml_i1 + (eml_i2 << 2)];
            }
          }
        }

        for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
          Gravity_Well_B.pos[eml_i0] = eml_dv11[eml_i0 + 12];

          /* Formulation of the Jacobian */
          /* %%%%%%%%%%%%%%%%%%%%%%%%%%%JACOBIAN%%%%%%%%%%%%%%%%%%%%%%%% */
          eml_b[eml_i0] = Gravity_Well_B.pos[eml_i0] - eml_T02[eml_i0 + 12];
          eml_b_0[eml_i0] = Gravity_Well_B.pos[eml_i0] - eml_A1[eml_i0 + 12];
          eml_b_1[eml_i0] = Gravity_Well_B.pos[eml_i0];
        }

        Gravity_Well_B.Jac[0] = 0.0 * eml_b_1[2] - eml_b_1[1];
        Gravity_Well_B.Jac[1] = eml_b_1[0] - 0.0 * eml_b_1[2];
        Gravity_Well_B.Jac[2] = 0.0 * eml_b_1[1] - 0.0 * eml_b_1[0];
        Gravity_Well_B.Jac[6] = eml_z1[1] * eml_b_0[2] - eml_z1[2] * eml_b_0[1];
        Gravity_Well_B.Jac[7] = eml_z1[2] * eml_b_0[0] - eml_z1[0] * eml_b_0[2];
        Gravity_Well_B.Jac[8] = eml_z1[0] * eml_b_0[1] - eml_z1[1] * eml_b_0[0];
        Gravity_Well_B.Jac[12] = eml_z2[1] * eml_b[2] - eml_z2[2] * eml_b[1];
        Gravity_Well_B.Jac[13] = eml_z2[2] * eml_b[0] - eml_z2[0] * eml_b[2];
        Gravity_Well_B.Jac[14] = eml_z2[0] * eml_b[1] - eml_z2[1] * eml_b[0];
        for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
          Gravity_Well_B.Jac[eml_i0 + 3] = (real_T)eml_bv3[eml_i0];
        }

        for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
          Gravity_Well_B.Jac[eml_i0 + 9] = eml_z1[eml_i0];
        }

        for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
          Gravity_Well_B.Jac[eml_i0 + 15] = eml_z2[eml_i0];
        }
      }

      /* Math: '<S2>/Math Function' */
      for (i = 0; i < 6; i++) {
        tmp[3 * i] = Gravity_Well_B.Jac[i];
        tmp[1 + 3 * i] = Gravity_Well_B.Jac[i + 6];
        tmp[2 + 3 * i] = Gravity_Well_B.Jac[i + 12];
      }

      for (i = 0; i < 18; i++) {
        Gravity_Well_B.MathFunction[i] = tmp[i];
      }

      /* Sum: '<S3>/Subtract' incorporates:
       *  Constant: '<S3>/Posx'
       *  Constant: '<S3>/Posy'
       *  Constant: '<S3>/Posz'
       */
      Gravity_Well_B.Subtract[0] = Gravity_Well_P.Posz_Value -
        Gravity_Well_B.pos[0];
      Gravity_Well_B.Subtract[1] = Gravity_Well_P.Posx_Value -
        Gravity_Well_B.pos[1];
      Gravity_Well_B.Subtract[2] = Gravity_Well_P.Posy_Value -
        Gravity_Well_B.pos[2];
      Gravity_Well_EuclideanDistance(Gravity_Well_B.Subtract,
        &Gravity_Well_B.sf_EuclideanDistance);

      /* Gain: '<S3>/Stiffness' */
      Gravity_Well_B.Stiffness[0] = Gravity_Well_P.Stiffness_Gain *
        Gravity_Well_B.Subtract[0];
      Gravity_Well_B.Stiffness[1] = Gravity_Well_P.Stiffness_Gain *
        Gravity_Well_B.Subtract[1];
      Gravity_Well_B.Stiffness[2] = Gravity_Well_P.Stiffness_Gain *
        Gravity_Well_B.Subtract[2];
    }

    /* Integrator: '<S12>/Integrator' */
    rtb_Integrator_idx = Gravity_Well_X.Integrator_CSTATE[0];
    rtb_Integrator_idx_0 = Gravity_Well_X.Integrator_CSTATE[1];
    rtb_Integrator_idx_1 = Gravity_Well_X.Integrator_CSTATE[2];

    /* Product: '<S12>/Product1' incorporates:
     *  Constant: '<S3>/Constant2'
     *  Integrator: '<S12>/Integrator'
     */
    Gravity_Well_B.Product1[0] = Gravity_Well_P.Constant2_Value *
      Gravity_Well_X.Integrator_CSTATE[0];
    Gravity_Well_B.Product1[1] = Gravity_Well_P.Constant2_Value *
      Gravity_Well_X.Integrator_CSTATE[1];
    Gravity_Well_B.Product1[2] = Gravity_Well_P.Constant2_Value *
      Gravity_Well_X.Integrator_CSTATE[2];

    /* Switch: '<S3>/Compare' incorporates:
     *  Constant: '<S3>/Constant1'
     *  Constant: '<S3>/Damping'
     *  Product: '<S3>/Product1'
     *  Sum: '<S3>/Sum1'
     */
    if (Gravity_Well_B.sf_EuclideanDistance.mag >=
        Gravity_Well_P.Compare_Threshold) {
      rtb_Add_idx = Gravity_Well_P.Constant1_Value[0];
      rtb_Add_idx_0 = Gravity_Well_P.Constant1_Value[1];
      rtb_Add_idx_1 = Gravity_Well_P.Constant1_Value[2];
    } else {
      rtb_Add_idx = Gravity_Well_B.Stiffness[0] - Gravity_Well_B.Product1[0] *
        Gravity_Well_P.Damping_Value;
      rtb_Add_idx_0 = Gravity_Well_B.Stiffness[1] - Gravity_Well_B.Product1[1] *
        Gravity_Well_P.Damping_Value;
      rtb_Add_idx_1 = Gravity_Well_B.Stiffness[2] - Gravity_Well_B.Product1[2] *
        Gravity_Well_P.Damping_Value;
    }

    if (rtmIsMajorTimeStep(Gravity_Well_M)) {
      /* Sum: '<S4>/Subtract' incorporates:
       *  Constant: '<S4>/Posx'
       *  Constant: '<S4>/Posy'
       *  Constant: '<S4>/Posz'
       */
      Gravity_Well_B.Subtract_o[0] = Gravity_Well_P.Posz_Value_i -
        Gravity_Well_B.pos[0];
      Gravity_Well_B.Subtract_o[1] = Gravity_Well_P.Posx_Value_p -
        Gravity_Well_B.pos[1];
      Gravity_Well_B.Subtract_o[2] = Gravity_Well_P.Posy_Value_o -
        Gravity_Well_B.pos[2];
      Gravity_Well_EuclideanDistance(Gravity_Well_B.Subtract_o,
        &Gravity_Well_B.sf_EuclideanDistance_j);

      /* Gain: '<S4>/Stiffness' */
      Gravity_Well_B.Stiffness_e[0] = Gravity_Well_P.Stiffness_Gain_h *
        Gravity_Well_B.Subtract_o[0];
      Gravity_Well_B.Stiffness_e[1] = Gravity_Well_P.Stiffness_Gain_h *
        Gravity_Well_B.Subtract_o[1];
      Gravity_Well_B.Stiffness_e[2] = Gravity_Well_P.Stiffness_Gain_h *
        Gravity_Well_B.Subtract_o[2];
    }

    /* Integrator: '<S15>/Integrator' */
    rtb_Integrator_o_idx = Gravity_Well_X.Integrator_CSTATE_o[0];
    rtb_Integrator_o_idx_0 = Gravity_Well_X.Integrator_CSTATE_o[1];
    rtb_Integrator_o_idx_1 = Gravity_Well_X.Integrator_CSTATE_o[2];

    /* Product: '<S15>/Product1' incorporates:
     *  Constant: '<S4>/Constant2'
     *  Integrator: '<S15>/Integrator'
     */
    Gravity_Well_B.Product1_e[0] = Gravity_Well_P.Constant2_Value_l *
      Gravity_Well_X.Integrator_CSTATE_o[0];
    Gravity_Well_B.Product1_e[1] = Gravity_Well_P.Constant2_Value_l *
      Gravity_Well_X.Integrator_CSTATE_o[1];
    Gravity_Well_B.Product1_e[2] = Gravity_Well_P.Constant2_Value_l *
      Gravity_Well_X.Integrator_CSTATE_o[2];

    /* Switch: '<S4>/Compare' incorporates:
     *  Constant: '<S4>/Constant1'
     *  Constant: '<S4>/Damping'
     *  Product: '<S4>/Product1'
     *  Sum: '<S4>/Sum1'
     */
    if (Gravity_Well_B.sf_EuclideanDistance_j.mag >=
        Gravity_Well_P.Compare_Threshold_c) {
      rtb_Integrator1[0] = Gravity_Well_P.Constant1_Value_p[0];
      rtb_Integrator1[1] = Gravity_Well_P.Constant1_Value_p[1];
      rtb_Integrator1[2] = Gravity_Well_P.Constant1_Value_p[2];
    } else {
      rtb_Integrator1[0] = Gravity_Well_B.Stiffness_e[0] -
        Gravity_Well_B.Product1_e[0] * Gravity_Well_P.Damping_Value_k;
      rtb_Integrator1[1] = Gravity_Well_B.Stiffness_e[1] -
        Gravity_Well_B.Product1_e[1] * Gravity_Well_P.Damping_Value_k;
      rtb_Integrator1[2] = Gravity_Well_B.Stiffness_e[2] -
        Gravity_Well_B.Product1_e[2] * Gravity_Well_P.Damping_Value_k;
    }

    /* Sum: '<Root>/Add' */
    rtb_Add_idx += rtb_Integrator1[0];
    rtb_Add_idx_0 += rtb_Integrator1[1];
    rtb_Add_idx_1 += rtb_Integrator1[2];

    /* SignalConversion: '<S2>/TmpHiddenBufferAtProductInport2' incorporates:
     *  Constant: '<S2>/Constant'
     */
    rtb_TmpHiddenBufferAtProductInp[0] = rtb_Add_idx;
    rtb_TmpHiddenBufferAtProductInp[1] = rtb_Add_idx_0;
    rtb_TmpHiddenBufferAtProductInp[2] = rtb_Add_idx_1;
    rtb_TmpHiddenBufferAtProductInp[3] = Gravity_Well_P.Constant_Value[0];
    rtb_TmpHiddenBufferAtProductInp[4] = Gravity_Well_P.Constant_Value[1];
    rtb_TmpHiddenBufferAtProductInp[5] = Gravity_Well_P.Constant_Value[2];

    {
      static const int_T dims[3] = { 3, 6, 1 };

      rt_MatMultRR_Dbl(rtb_Integrator1, Gravity_Well_B.MathFunction,
                       rtb_TmpHiddenBufferAtProductInp, &dims[0]);
    }

    /* Gain: '<S2>/Convert to Positive Rotation Convension Used in Kinematics1' */
    Gravity_Well_B.ConverttoPositiveRotationConven[0] =
      Gravity_Well_P.ConverttoPositiveRotationConv_k[0] * rtb_Integrator1[0];
    Gravity_Well_B.ConverttoPositiveRotationConven[1] =
      Gravity_Well_P.ConverttoPositiveRotationConv_k[1] * rtb_Integrator1[1];
    Gravity_Well_B.ConverttoPositiveRotationConven[2] =
      Gravity_Well_P.ConverttoPositiveRotationConv_k[2] * rtb_Integrator1[2];

    /* Embedded MATLAB: '<S8>/Joint Torque to Motor Torque' */
    {
      int32_T eml_i0;

      /*  Smart Saturation: allows channels to go up to 1.6A  */
      /*  unless the total exceeds 2.2A in which case all channels */
      /*  are scaled so that the cumulative current is equal to 2.2A. */
      for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
        Gravity_Well_B.y_a[eml_i0] = 0.0;
      }

      Gravity_Well_B.y_a[0] = Gravity_Well_B.ConverttoPositiveRotationConven[0];
      Gravity_Well_B.y_a[2] = Gravity_Well_B.ConverttoPositiveRotationConven[2];
      Gravity_Well_B.y_a[1] = Gravity_Well_B.ConverttoPositiveRotationConven[1]
        - Gravity_Well_B.ConverttoPositiveRotationConven[2];
    }

    /* Gain: '<S8>/Kt' incorporates:
     *  Gain: '<S8>/Gear Ratio1'
     */
    rtb_Integrator1[0] = Gravity_Well_P.GearRatio1_Gain[0] * Gravity_Well_B.y_a
      [0] * Gravity_Well_P.Kt_Gain;
    rtb_Integrator1[1] = Gravity_Well_P.GearRatio1_Gain[1] * Gravity_Well_B.y_a
      [1] * Gravity_Well_P.Kt_Gain;
    rtb_Integrator1[2] = Gravity_Well_P.GearRatio1_Gain[2] * Gravity_Well_B.y_a
      [2] * Gravity_Well_P.Kt_Gain;

    /* Saturate: '<S8>/Saturation' */
    Gravity_Well_B.Saturation[0] = rt_SATURATE(rtb_Integrator1[0],
      Gravity_Well_P.Saturation_LowerSat, Gravity_Well_P.Saturation_UpperSat);
    Gravity_Well_B.Saturation[1] = rt_SATURATE(rtb_Integrator1[1],
      Gravity_Well_P.Saturation_LowerSat, Gravity_Well_P.Saturation_UpperSat);
    Gravity_Well_B.Saturation[2] = rt_SATURATE(rtb_Integrator1[2],
      Gravity_Well_P.Saturation_LowerSat, Gravity_Well_P.Saturation_UpperSat);

    /* Embedded MATLAB: '<S8>/Smart Saturation' */
    {
      int32_T eml_k;
      real_T eml_x[3];
      real_T eml_total;

      /*  Smart Saturation: allows channels to go up to 1.6A  */
      /*  unless the total exceeds 2.2A in which case all channels */
      /*  are scaled so that the cumulative current is equal to 2.2A. */
      /*  Define the maximum cumulative current here */
      for (eml_k = 0; eml_k < 3; eml_k++) {
        eml_x[eml_k] = fabs(Gravity_Well_B.Saturation[eml_k]);
      }

      eml_total = eml_x[0];
      for (eml_k = 2; eml_k < 4; eml_k++) {
        eml_total += eml_x[eml_k - 1];
      }

      if (eml_total > 2.2) {
        eml_total = 2.2 / eml_total;
        for (eml_k = 0; eml_k < 3; eml_k++) {
          Gravity_Well_B.y[eml_k] = eml_total * Gravity_Well_B.Saturation[eml_k];
        }
      } else {
        for (eml_k = 0; eml_k < 3; eml_k++) {
          Gravity_Well_B.y[eml_k] = Gravity_Well_B.Saturation[eml_k];
        }
      }
    }

    if (rtmIsMajorTimeStep(Gravity_Well_M)) {
      /* S-Function Block: Gravity_Well/Omni/HIL Write PWM (hil_write_pwm_block) */
      {
        t_error result;
        result = hil_write_pwm(Gravity_Well_DWork.HILInitialize_Card,
          Gravity_Well_P.HILWritePWM_Channels, 3, Gravity_Well_B.y);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Gravity_Well_M, _rt_error_message);
        }
      }

      /* S-Function Block: Gravity_Well/Omni/HIL Read Analog (hil_read_analog_block) */
      {
        t_error result = hil_read_analog(Gravity_Well_DWork.HILInitialize_Card,
          Gravity_Well_P.HILReadAnalog_Channels, 3, rtb_HILReadAnalog);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Gravity_Well_M, _rt_error_message);
        }
      }
    }

    /* RateTransition: '<Root>/Rate Transition1' */
    if (rtmIsMajorTimeStep(Gravity_Well_M) &&
        Gravity_Well_M->Timing.RateInteraction.TID1_2) {
      Gravity_Well_B.RateTransition1[0] = Gravity_Well_B.pos[1];
      Gravity_Well_B.RateTransition1[1] = Gravity_Well_B.pos[2];
      Gravity_Well_B.RateTransition1[2] = Gravity_Well_B.pos[0];
    }

    /* Integrator: '<S12>/Integrator1' */
    if (Gravity_Well_DWork.Integrator1_IWORK.IcNeedsLoading) {
      Gravity_Well_X.Integrator1_CSTATE[0] = Gravity_Well_B.Subtract[0];
      Gravity_Well_X.Integrator1_CSTATE[1] = Gravity_Well_B.Subtract[1];
      Gravity_Well_X.Integrator1_CSTATE[2] = Gravity_Well_B.Subtract[2];
      Gravity_Well_DWork.Integrator1_IWORK.IcNeedsLoading = 0;
    }

    rtb_Integrator1[0] = Gravity_Well_X.Integrator1_CSTATE[0];
    rtb_Integrator1[1] = Gravity_Well_X.Integrator1_CSTATE[1];
    rtb_Integrator1[2] = Gravity_Well_X.Integrator1_CSTATE[2];

    /* Product: '<S12>/Product' incorporates:
     *  Constant: '<S12>/Constant'
     *  Constant: '<S3>/Constant2'
     *  Constant: '<S3>/z1'
     *  Product: '<S12>/Product2'
     *  Sum: '<S12>/Sum'
     *  Sum: '<S12>/Sum1'
     */
    Gravity_Well_B.Product[0] = ((Gravity_Well_B.Subtract[0] - rtb_Integrator1[0])
      - rtb_Integrator_idx * Gravity_Well_P.Constant_Value_c *
      Gravity_Well_P.z1_Value) * Gravity_Well_P.Constant2_Value;
    Gravity_Well_B.Product[1] = ((Gravity_Well_B.Subtract[1] - rtb_Integrator1[1])
      - rtb_Integrator_idx_0 * Gravity_Well_P.Constant_Value_c *
      Gravity_Well_P.z1_Value) * Gravity_Well_P.Constant2_Value;
    Gravity_Well_B.Product[2] = ((Gravity_Well_B.Subtract[2] - rtb_Integrator1[2])
      - rtb_Integrator_idx_1 * Gravity_Well_P.Constant_Value_c *
      Gravity_Well_P.z1_Value) * Gravity_Well_P.Constant2_Value;

    /* Integrator: '<S15>/Integrator1' */
    if (Gravity_Well_DWork.Integrator1_IWORK_d.IcNeedsLoading) {
      Gravity_Well_X.Integrator1_CSTATE_p[0] = Gravity_Well_B.Subtract_o[0];
      Gravity_Well_X.Integrator1_CSTATE_p[1] = Gravity_Well_B.Subtract_o[1];
      Gravity_Well_X.Integrator1_CSTATE_p[2] = Gravity_Well_B.Subtract_o[2];
      Gravity_Well_DWork.Integrator1_IWORK_d.IcNeedsLoading = 0;
    }

    rtb_Integrator1[0] = Gravity_Well_X.Integrator1_CSTATE_p[0];
    rtb_Integrator1[1] = Gravity_Well_X.Integrator1_CSTATE_p[1];
    rtb_Integrator1[2] = Gravity_Well_X.Integrator1_CSTATE_p[2];

    /* Product: '<S15>/Product' incorporates:
     *  Constant: '<S15>/Constant'
     *  Constant: '<S4>/Constant2'
     *  Constant: '<S4>/z1'
     *  Product: '<S15>/Product2'
     *  Sum: '<S15>/Sum'
     *  Sum: '<S15>/Sum1'
     */
    Gravity_Well_B.Product_h[0] = ((Gravity_Well_B.Subtract_o[0] -
      rtb_Integrator1[0]) - rtb_Integrator_o_idx *
      Gravity_Well_P.Constant_Value_n * Gravity_Well_P.z1_Value_h) *
      Gravity_Well_P.Constant2_Value_l;
    Gravity_Well_B.Product_h[1] = ((Gravity_Well_B.Subtract_o[1] -
      rtb_Integrator1[1]) - rtb_Integrator_o_idx_0 *
      Gravity_Well_P.Constant_Value_n * Gravity_Well_P.z1_Value_h) *
      Gravity_Well_P.Constant2_Value_l;
    Gravity_Well_B.Product_h[2] = ((Gravity_Well_B.Subtract_o[2] -
      rtb_Integrator1[2]) - rtb_Integrator_o_idx_1 *
      Gravity_Well_P.Constant_Value_n * Gravity_Well_P.z1_Value_h) *
      Gravity_Well_P.Constant2_Value_l;
  }

  UNUSED_PARAMETER(tid);
}

/* Model update function for TID0 */
void Gravity_Well_update0(int_T tid)   /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(Gravity_Well_M)) {
    rt_ertODEUpdateContinuousStates(&Gravity_Well_M->solverInfo);
  }

  /* Update absolute time */
  if (!(++Gravity_Well_M->Timing.clockTick0))
    ++Gravity_Well_M->Timing.clockTickH0;
  Gravity_Well_M->Timing.t[0] = Gravity_Well_M->Timing.clockTick0 *
    Gravity_Well_M->Timing.stepSize0 + Gravity_Well_M->Timing.clockTickH0 *
    Gravity_Well_M->Timing.stepSize0 * 4294967296.0;

  /* Update absolute time */
  if (!(++Gravity_Well_M->Timing.clockTick1))
    ++Gravity_Well_M->Timing.clockTickH1;
  Gravity_Well_M->Timing.t[1] = Gravity_Well_M->Timing.clockTick1 *
    Gravity_Well_M->Timing.stepSize1 + Gravity_Well_M->Timing.clockTickH1 *
    Gravity_Well_M->Timing.stepSize1 * 4294967296.0;
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void Gravity_Well_derivatives(void)
{
  /* Derivatives for Integrator: '<S12>/Integrator' */
  ((StateDerivatives_Gravity_Well *) Gravity_Well_M->ModelData.derivs)
    ->Integrator_CSTATE[0] = Gravity_Well_B.Product[0];
  ((StateDerivatives_Gravity_Well *) Gravity_Well_M->ModelData.derivs)
    ->Integrator_CSTATE[1] = Gravity_Well_B.Product[1];
  ((StateDerivatives_Gravity_Well *) Gravity_Well_M->ModelData.derivs)
    ->Integrator_CSTATE[2] = Gravity_Well_B.Product[2];

  /* Derivatives for Integrator: '<S15>/Integrator' */
  ((StateDerivatives_Gravity_Well *) Gravity_Well_M->ModelData.derivs)
    ->Integrator_CSTATE_o[0] = Gravity_Well_B.Product_h[0];
  ((StateDerivatives_Gravity_Well *) Gravity_Well_M->ModelData.derivs)
    ->Integrator_CSTATE_o[1] = Gravity_Well_B.Product_h[1];
  ((StateDerivatives_Gravity_Well *) Gravity_Well_M->ModelData.derivs)
    ->Integrator_CSTATE_o[2] = Gravity_Well_B.Product_h[2];

  /* Integrator Block: '<S12>/Integrator1' */
  {
    ((StateDerivatives_Gravity_Well *) Gravity_Well_M->ModelData.derivs)
      ->Integrator1_CSTATE[0] = Gravity_Well_B.Product1[0];
    ((StateDerivatives_Gravity_Well *) Gravity_Well_M->ModelData.derivs)
      ->Integrator1_CSTATE[1] = Gravity_Well_B.Product1[1];
    ((StateDerivatives_Gravity_Well *) Gravity_Well_M->ModelData.derivs)
      ->Integrator1_CSTATE[2] = Gravity_Well_B.Product1[2];
  }

  /* Integrator Block: '<S15>/Integrator1' */
  {
    ((StateDerivatives_Gravity_Well *) Gravity_Well_M->ModelData.derivs)
      ->Integrator1_CSTATE_p[0] = Gravity_Well_B.Product1_e[0];
    ((StateDerivatives_Gravity_Well *) Gravity_Well_M->ModelData.derivs)
      ->Integrator1_CSTATE_p[1] = Gravity_Well_B.Product1_e[1];
    ((StateDerivatives_Gravity_Well *) Gravity_Well_M->ModelData.derivs)
      ->Integrator1_CSTATE_p[2] = Gravity_Well_B.Product1_e[2];
  }
}

/* Model output function for TID2 */
void Gravity_Well_output2(int_T tid)   /* Sample time: [0.1s, 0.0s] */
{
  /* (no output code required) */
  UNUSED_PARAMETER(tid);
}

/* Model update function for TID2 */
void Gravity_Well_update2(int_T tid)   /* Sample time: [0.1s, 0.0s] */
{
  /* Update absolute time */
  if (!(++Gravity_Well_M->Timing.clockTick2))
    ++Gravity_Well_M->Timing.clockTickH2;
  Gravity_Well_M->Timing.t[2] = Gravity_Well_M->Timing.clockTick2 *
    Gravity_Well_M->Timing.stepSize2 + Gravity_Well_M->Timing.clockTickH2 *
    Gravity_Well_M->Timing.stepSize2 * 4294967296.0;
  UNUSED_PARAMETER(tid);
}

void Gravity_Well_output(int_T tid)
{
  switch (tid) {
   case 0 :
    Gravity_Well_output0(0);
    break;

   case 2 :
    Gravity_Well_output2(2);
    break;

   default :
    break;
  }
}

void Gravity_Well_update(int_T tid)
{
  switch (tid) {
   case 0 :
    Gravity_Well_update0(0);
    break;

   case 2 :
    Gravity_Well_update2(2);
    break;

   default :
    break;
  }
}

/* Model initialize function */
void Gravity_Well_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));    /* initialize real-time model */
  (void) memset((char_T *)Gravity_Well_M,0,
                sizeof(RT_MODEL_Gravity_Well));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Gravity_Well_M->solverInfo,
                          &Gravity_Well_M->Timing.simTimeStep);
    rtsiSetTPtr(&Gravity_Well_M->solverInfo, &rtmGetTPtr(Gravity_Well_M));
    rtsiSetStepSizePtr(&Gravity_Well_M->solverInfo,
                       &Gravity_Well_M->Timing.stepSize0);
    rtsiSetdXPtr(&Gravity_Well_M->solverInfo, &Gravity_Well_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Gravity_Well_M->solverInfo,
                         &Gravity_Well_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Gravity_Well_M->solverInfo,
      &Gravity_Well_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Gravity_Well_M->solverInfo, (&rtmGetErrorStatus
      (Gravity_Well_M)));
    rtsiSetRTModelPtr(&Gravity_Well_M->solverInfo, Gravity_Well_M);
  }

  rtsiSetSimTimeStep(&Gravity_Well_M->solverInfo, MAJOR_TIME_STEP);
  Gravity_Well_M->ModelData.intgData.f[0] = Gravity_Well_M->ModelData.odeF[0];
  Gravity_Well_M->ModelData.contStates = ((real_T *) &Gravity_Well_X);
  rtsiSetSolverData(&Gravity_Well_M->solverInfo, (void *)
                    &Gravity_Well_M->ModelData.intgData);
  rtsiSetSolverName(&Gravity_Well_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Gravity_Well_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    Gravity_Well_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Gravity_Well_M->Timing.sampleTimes =
      (&Gravity_Well_M->Timing.sampleTimesArray[0]);
    Gravity_Well_M->Timing.offsetTimes =
      (&Gravity_Well_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Gravity_Well_M->Timing.sampleTimes[0] = (0.0);
    Gravity_Well_M->Timing.sampleTimes[1] = (0.001);
    Gravity_Well_M->Timing.sampleTimes[2] = (0.1);

    /* task offsets */
    Gravity_Well_M->Timing.offsetTimes[0] = (0.0);
    Gravity_Well_M->Timing.offsetTimes[1] = (0.0);
    Gravity_Well_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(Gravity_Well_M, &Gravity_Well_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Gravity_Well_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = Gravity_Well_M->Timing.perTaskSampleHitsArray;
    Gravity_Well_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    Gravity_Well_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Gravity_Well_M, -1);
  Gravity_Well_M->Timing.stepSize0 = 0.001;
  Gravity_Well_M->Timing.stepSize1 = 0.001;
  Gravity_Well_M->Timing.stepSize2 = 0.1;

  /* external mode info */
  Gravity_Well_M->Sizes.checksums[0] = (3887136759U);
  Gravity_Well_M->Sizes.checksums[1] = (3479414719U);
  Gravity_Well_M->Sizes.checksums[2] = (4187217815U);
  Gravity_Well_M->Sizes.checksums[3] = (54494498U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    Gravity_Well_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &Gravity_Well_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, Gravity_Well_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(Gravity_Well_M));
  }

  Gravity_Well_M->solverInfoPtr = (&Gravity_Well_M->solverInfo);
  Gravity_Well_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Gravity_Well_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Gravity_Well_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  Gravity_Well_M->ModelData.blockIO = ((void *) &Gravity_Well_B);

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&Gravity_Well_B.GearRatio[0]);
    for (i = 0; i < 73; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    pVoidBlockIORegion = (void *)(&Gravity_Well_B.y[0]);
    for (i = 0; i < 39; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    ((real_T*)&Gravity_Well_B.sf_EuclideanDistance_j.mag)[0] = 0.0;
    ((real_T*)&Gravity_Well_B.sf_EuclideanDistance.mag)[0] = 0.0;
  }

  /* parameters */
  Gravity_Well_M->ModelData.defaultParam = ((real_T *) &Gravity_Well_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Gravity_Well_X;
    Gravity_Well_M->ModelData.contStates = (x);
    (void) memset((char_T *)x,0,
                  sizeof(ContinuousStates_Gravity_Well));
  }

  /* states (dwork) */
  Gravity_Well_M->Work.dwork = ((void *) &Gravity_Well_DWork);
  (void) memset((char_T *) &Gravity_Well_DWork,0,
                sizeof(D_Work_Gravity_Well));

  {
    int_T i;
    real_T *dwork_ptr = (real_T *) &Gravity_Well_DWork.HILInitialize_AIMinimums
      [0];
    for (i = 0; i < 13; i++) {
      dwork_ptr[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    Gravity_Well_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void Gravity_Well_terminate(void)
{
  /* S-Function Block: Gravity_Well/Omni/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    hil_task_stop_all(Gravity_Well_DWork.HILInitialize_Card);
    hil_task_delete_all(Gravity_Well_DWork.HILInitialize_Card);
    is_switching = false;
    if ((Gravity_Well_P.HILInitialize_POTerminate && !is_switching) ||
        (Gravity_Well_P.HILInitialize_POExit && is_switching)) {
      Gravity_Well_DWork.HILInitialize_POValues[0] =
        Gravity_Well_P.HILInitialize_POFinal;
      Gravity_Well_DWork.HILInitialize_POValues[1] =
        Gravity_Well_P.HILInitialize_POFinal;
      Gravity_Well_DWork.HILInitialize_POValues[2] =
        Gravity_Well_P.HILInitialize_POFinal;
      result = hil_write_pwm(Gravity_Well_DWork.HILInitialize_Card,
        &Gravity_Well_P.HILInitialize_POChannels[0], 3U,
        &Gravity_Well_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Gravity_Well_M, _rt_error_message);
      }
    }

    hil_close(Gravity_Well_DWork.HILInitialize_Card);
    Gravity_Well_DWork.HILInitialize_Card = NULL;
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
  Gravity_Well_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  Gravity_Well_update(tid);
}

void MdlInitializeSizes(void)
{
  Gravity_Well_M->Sizes.numContStates = (12);/* Number of continuous states */
  Gravity_Well_M->Sizes.numY = (0);    /* Number of model outputs */
  Gravity_Well_M->Sizes.numU = (0);    /* Number of model inputs */
  Gravity_Well_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Gravity_Well_M->Sizes.numSampTimes = (3);/* Number of sample times */
  Gravity_Well_M->Sizes.numBlocks = (74);/* Number of blocks */
  Gravity_Well_M->Sizes.numBlockIO = (23);/* Number of block outputs */
  Gravity_Well_M->Sizes.numBlockPrms = (131);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* Initialize code for chart: '<S5>/Embedded MATLAB Function' */
  Gravity_Well_DWork.is_active_c8_Gravity_Well = 0U;

  /* Initialize code for chart: '<S2>/Forward Kinematics ' */
  Gravity_Well_DWork.is_active_c5_Gravity_Well = 0U;
  Gravity__EuclideanDistance_Init(&Gravity_Well_DWork.sf_EuclideanDistance);

  /* InitializeConditions for Integrator: '<S12>/Integrator' */
  Gravity_Well_X.Integrator_CSTATE[0] = Gravity_Well_P.Integrator_IC;
  Gravity_Well_X.Integrator_CSTATE[1] = Gravity_Well_P.Integrator_IC;
  Gravity_Well_X.Integrator_CSTATE[2] = Gravity_Well_P.Integrator_IC;
  Gravity__EuclideanDistance_Init(&Gravity_Well_DWork.sf_EuclideanDistance_j);

  /* InitializeConditions for Integrator: '<S15>/Integrator' */
  Gravity_Well_X.Integrator_CSTATE_o[0] = Gravity_Well_P.Integrator_IC_i;
  Gravity_Well_X.Integrator_CSTATE_o[1] = Gravity_Well_P.Integrator_IC_i;
  Gravity_Well_X.Integrator_CSTATE_o[2] = Gravity_Well_P.Integrator_IC_i;

  /* Initialize code for chart: '<S8>/Joint Torque to Motor Torque' */
  Gravity_Well_DWork.is_active_c4_Gravity_Well = 0U;

  /* Initialize code for chart: '<S8>/Smart Saturation' */
  Gravity_Well_DWork.is_active_c3_Gravity_Well = 0U;

  /* Integrator Block: '<S12>/Integrator1' */
  if (rtmIsFirstInitCond(Gravity_Well_M)) {
    Gravity_Well_X.Integrator1_CSTATE[0] = 0.0;
    Gravity_Well_X.Integrator1_CSTATE[1] = 0.0;
    Gravity_Well_X.Integrator1_CSTATE[2] = 0.0;
  }

  Gravity_Well_DWork.Integrator1_IWORK.IcNeedsLoading = 1;

  /* Integrator Block: '<S15>/Integrator1' */
  if (rtmIsFirstInitCond(Gravity_Well_M)) {
    Gravity_Well_X.Integrator1_CSTATE_p[0] = 0.0;
    Gravity_Well_X.Integrator1_CSTATE_p[1] = 0.0;
    Gravity_Well_X.Integrator1_CSTATE_p[2] = 0.0;
  }

  Gravity_Well_DWork.Integrator1_IWORK_d.IcNeedsLoading = 1;
}

void MdlStart(void)
{
  {
    int32_T i;

    /* S-Function Block: Gravity_Well/Omni/HIL Initialize (hil_initialize_block) */
    {
      t_int result;
      t_boolean is_switching;
      result = hil_open("phantom_omni", "0",
                        &Gravity_Well_DWork.HILInitialize_Card);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Gravity_Well_M, _rt_error_message);
        return;
      }

      is_switching = false;
      if ((Gravity_Well_P.HILInitialize_AIPStart && !is_switching) ||
          (Gravity_Well_P.HILInitialize_AIPEnter && is_switching)) {
        Gravity_Well_DWork.HILInitialize_AIMinimums[0] =
          Gravity_Well_P.HILInitialize_AILow;
        Gravity_Well_DWork.HILInitialize_AIMinimums[1] =
          Gravity_Well_P.HILInitialize_AILow;
        Gravity_Well_DWork.HILInitialize_AIMaximums[0] =
          Gravity_Well_P.HILInitialize_AIHigh;
        Gravity_Well_DWork.HILInitialize_AIMaximums[1] =
          Gravity_Well_P.HILInitialize_AIHigh;
        result = hil_set_analog_input_ranges
          (Gravity_Well_DWork.HILInitialize_Card,
           &Gravity_Well_P.HILInitialize_AIChannels[0], 2U,
           &Gravity_Well_DWork.HILInitialize_AIMinimums[0],
           &Gravity_Well_DWork.HILInitialize_AIMaximums[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Gravity_Well_M, _rt_error_message);
          return;
        }
      }

      if ((Gravity_Well_P.HILInitialize_EIStart && !is_switching) ||
          (Gravity_Well_P.HILInitialize_EIEnter && is_switching)) {
        Gravity_Well_DWork.HILInitialize_InitialEICounts[0] =
          Gravity_Well_P.HILInitialize_EIInitial;
        Gravity_Well_DWork.HILInitialize_InitialEICounts[1] =
          Gravity_Well_P.HILInitialize_EIInitial;
        Gravity_Well_DWork.HILInitialize_InitialEICounts[2] =
          Gravity_Well_P.HILInitialize_EIInitial;
        result = hil_set_encoder_counts(Gravity_Well_DWork.HILInitialize_Card,
          &Gravity_Well_P.HILInitialize_EIChannels[0], 3U,
          &Gravity_Well_DWork.HILInitialize_InitialEICounts[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Gravity_Well_M, _rt_error_message);
          return;
        }
      }

      if ((Gravity_Well_P.HILInitialize_POStart && !is_switching) ||
          (Gravity_Well_P.HILInitialize_POEnter && is_switching)) {
        Gravity_Well_DWork.HILInitialize_POValues[0] =
          Gravity_Well_P.HILInitialize_POInitial;
        Gravity_Well_DWork.HILInitialize_POValues[1] =
          Gravity_Well_P.HILInitialize_POInitial;
        Gravity_Well_DWork.HILInitialize_POValues[2] =
          Gravity_Well_P.HILInitialize_POInitial;
        result = hil_write_pwm(Gravity_Well_DWork.HILInitialize_Card,
          &Gravity_Well_P.HILInitialize_POChannels[0], 3U,
          &Gravity_Well_DWork.HILInitialize_POValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Gravity_Well_M, _rt_error_message);
          return;
        }
      }

      if (Gravity_Well_P.HILInitialize_POReset) {
        Gravity_Well_DWork.HILInitialize_POValues[0] =
          Gravity_Well_P.HILInitialize_POWatchdog;
        Gravity_Well_DWork.HILInitialize_POValues[1] =
          Gravity_Well_P.HILInitialize_POWatchdog;
        Gravity_Well_DWork.HILInitialize_POValues[2] =
          Gravity_Well_P.HILInitialize_POWatchdog;
        result = hil_watchdog_set_pwm_expiration_state
          (Gravity_Well_DWork.HILInitialize_Card,
           &Gravity_Well_P.HILInitialize_POChannels[0], 3U,
           &Gravity_Well_DWork.HILInitialize_POValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Gravity_Well_M, _rt_error_message);
          return;
        }
      }
    }

    /* S-Function Block: Gravity_Well/Omni/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_create_encoder_reader
        (Gravity_Well_DWork.HILInitialize_Card,
         Gravity_Well_P.HILReadEncoderTimebase_SamplesI,
         Gravity_Well_P.HILReadEncoderTimebase_Channels, 3,
         &Gravity_Well_DWork.HILReadEncoderTimebase_Task);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Gravity_Well_M, _rt_error_message);
      }
    }

    for (i = 0; i < 16; i++) {
      /* Start for Constant: '<S2>/Tool Offset2' */
      Gravity_Well_B.ToolOffset2[i] = Gravity_Well_P.ToolOffset2_Value[i];
    }
  }

  MdlInitialize();
}

RT_MODEL_Gravity_Well *Gravity_Well(void)
{
  Gravity_Well_initialize(1);
  return Gravity_Well_M;
}

void MdlTerminate(void)
{
  Gravity_Well_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
