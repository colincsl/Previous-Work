/*
 * Puncture_Through_Wall.c
 *
 * Real-Time Workshop code generation for Simulink model "Puncture_Through_Wall.mdl".
 *
 * Model Version              : 1.177
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Tue Jul 21 14:20:03 2009
 */

#include "Puncture_Through_Wall.h"
#include "Puncture_Through_Wall_private.h"
#include <stdio.h>
#include "Puncture_Through_Wall_dt.h"

/* Block signals (auto storage) */
BlockIO_Puncture_Through_Wall Puncture_Through_Wall_B;

/* Block states (auto storage) */
D_Work_Puncture_Through_Wall Puncture_Through_Wall_DWork;

/* Real-time model */
RT_MODEL_Puncture_Through_Wall Puncture_Through_Wall_M_;
RT_MODEL_Puncture_Through_Wall *Puncture_Through_Wall_M =
  &Puncture_Through_Wall_M_;
static void rate_monotonic_scheduler(void);

/* Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Puncture_Through_Wall_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Puncture_Through_Wall_M, 1));
}

time_T rt_SimUpdateDiscreteEvents(int_T rtmNumSampTimes,
  void *rtmTimingData,
  int_T *rtmSampleHitPtr,
  int_T *rtmPerTaskSampleHits)
{
  rtmSampleHitPtr[1] = rtmStepTask(Puncture_Through_Wall_M, 1);
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

  /* tid 0 shares data with slower tid rate: 1 */
  Puncture_Through_Wall_M->Timing.RateInteraction.TID0_1 =
    (Puncture_Through_Wall_M->Timing.TaskCounters.TID[1] == 0);

  /* update PerTaskSampleHits matrix for non-inline sfcn */
  Puncture_Through_Wall_M->Timing.perTaskSampleHits[1] =
    Puncture_Through_Wall_M->Timing.RateInteraction.TID0_1;

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  if (++Puncture_Through_Wall_M->Timing.TaskCounters.TID[1] == 100) {/* Sample time: [0.1s, 0.0s] */
    Puncture_Through_Wall_M->Timing.TaskCounters.TID[1] = 0;
  }

  Puncture_Through_Wall_M->Timing.sampleHits[1] =
    (Puncture_Through_Wall_M->Timing.TaskCounters.TID[1] == 0);
}

/* Model output function for TID0 */
void Puncture_Through_Wall_output0(int_T tid) /* Sample time: [0.001s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_MathFunction[18];
  real_T rtb_TmpHiddenBufferAtProductInp[6];
  real_T rtb_Add_k;
  real_T rtb_Switch_n[3];

  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  {
    int32_T i;
    real_T tmp[18];

    /* S-Function Block: Puncture_Through_Wall/Omni/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result = hil_task_read_encoder
        (Puncture_Through_Wall_DWork.HILReadEncoderTimebase_Task, 1,
         &Puncture_Through_Wall_DWork.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Puncture_Through_Wall_M, _rt_error_message);
      } else {
        rtb_Switch_n[0] =
          Puncture_Through_Wall_DWork.HILReadEncoderTimebase_Buffer[0];
        rtb_Switch_n[1] =
          Puncture_Through_Wall_DWork.HILReadEncoderTimebase_Buffer[1];
        rtb_Switch_n[2] =
          Puncture_Through_Wall_DWork.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* Gain: '<S9>/Gear Ratio' incorporates:
     *  Bias: '<S9>/Bias1'
     *  Gain: '<S9>/Encoder'
     */
    Puncture_Through_Wall_B.GearRatio[0] = (rtb_Switch_n[0] +
      Puncture_Through_Wall_P.Bias1_Bias[0]) *
      Puncture_Through_Wall_P.Encoder_Gain *
      Puncture_Through_Wall_P.GearRatio_Gain[0];
    Puncture_Through_Wall_B.GearRatio[1] = (rtb_Switch_n[1] +
      Puncture_Through_Wall_P.Bias1_Bias[1]) *
      Puncture_Through_Wall_P.Encoder_Gain *
      Puncture_Through_Wall_P.GearRatio_Gain[1];
    Puncture_Through_Wall_B.GearRatio[2] = (rtb_Switch_n[2] +
      Puncture_Through_Wall_P.Bias1_Bias[2]) *
      Puncture_Through_Wall_P.Encoder_Gain *
      Puncture_Through_Wall_P.GearRatio_Gain[2];

    /* Embedded MATLAB: '<S9>/Embedded MATLAB Function' */
    {
      int32_T eml_i0;
      for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
        Puncture_Through_Wall_B.q[eml_i0] =
          Puncture_Through_Wall_B.GearRatio[eml_i0];
      }

      Puncture_Through_Wall_B.q[0] = Puncture_Through_Wall_B.GearRatio[0];
      Puncture_Through_Wall_B.q[1] = Puncture_Through_Wall_B.GearRatio[1];
      Puncture_Through_Wall_B.q[2] = (Puncture_Through_Wall_B.GearRatio[2] -
        Puncture_Through_Wall_B.GearRatio[1]) - 1.5707963267948966E+000;
    }

    /* Bias: '<S4>/Joint Offsets' incorporates:
     *  Gain: '<S4>/Convert to Positive Rotation Convension Used in Kinematics'
     */
    Puncture_Through_Wall_B.JointOffsets[0] =
      Puncture_Through_Wall_P.ConverttoPositiveRotationConven[0] *
      Puncture_Through_Wall_B.q[0] + Puncture_Through_Wall_P.JointOffsets_Bias[0];
    Puncture_Through_Wall_B.JointOffsets[1] =
      Puncture_Through_Wall_P.ConverttoPositiveRotationConven[1] *
      Puncture_Through_Wall_B.q[1] + Puncture_Through_Wall_P.JointOffsets_Bias[1];
    Puncture_Through_Wall_B.JointOffsets[2] =
      Puncture_Through_Wall_P.ConverttoPositiveRotationConven[2] *
      Puncture_Through_Wall_B.q[2] + Puncture_Through_Wall_P.JointOffsets_Bias[2];
    for (i = 0; i < 16; i++) {
      /* Constant: '<S4>/Tool Offset2' */
      Puncture_Through_Wall_B.ToolOffset2[i] =
        Puncture_Through_Wall_P.ToolOffset2_Value[i];
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
      eml_theta_z = Puncture_Through_Wall_B.JointOffsets[0];
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

      eml_theta_z = Puncture_Through_Wall_B.JointOffsets[1];
      eml_theta_z_0 = Puncture_Through_Wall_B.JointOffsets[2] -
        1.5707963267948966E+000;

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
            eml_dv2[eml_i1 + (eml_i0 << 2)] += eml_dv0[eml_i1 + (eml_i2 << 2)] *
              (real_T)eml_bv2[eml_i2 + (eml_i0 << 2)];
          }
        }

        for (eml_i0 = 0; eml_i0 < 4; eml_i0++) {
          eml_dv3[eml_i1 + (eml_i0 << 2)] = 0.0;
          for (eml_i2 = 0; eml_i2 < 4; eml_i2++) {
            eml_dv3[eml_i1 + (eml_i0 << 2)] += eml_dv2[eml_i1 + (eml_i2 << 2)] *
              (real_T)eml_bv2[eml_i2 + (eml_i0 << 2)];
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
            eml_dv4[eml_i1 + (eml_i0 << 2)] += eml_dv1[eml_i1 + (eml_i2 << 2)] *
              (real_T)eml_bv2[eml_i2 + (eml_i0 << 2)];
          }
        }

        for (eml_i0 = 0; eml_i0 < 4; eml_i0++) {
          eml_dv5[eml_i1 + (eml_i0 << 2)] = 0.0;
          for (eml_i2 = 0; eml_i2 < 4; eml_i2++) {
            eml_dv5[eml_i1 + (eml_i0 << 2)] += eml_dv4[eml_i1 + (eml_i2 << 2)] *
              eml_A_T_x[eml_i2 + (eml_i0 << 2)];
          }
        }

        for (eml_i0 = 0; eml_i0 < 4; eml_i0++) {
          eml_dv6[eml_i1 + (eml_i0 << 2)] = 0.0;
          for (eml_i2 = 0; eml_i2 < 4; eml_i2++) {
            eml_dv6[eml_i1 + (eml_i0 << 2)] += eml_dv5[eml_i1 + (eml_i2 << 2)] *
              (real_T)eml_bv2[eml_i2 + (eml_i0 << 2)];
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
            eml_dv8[eml_i1 + (eml_i0 << 2)] += eml_dv7[eml_i1 + (eml_i2 << 2)] *
              (real_T)eml_bv2[eml_i2 + (eml_i0 << 2)];
          }
        }

        for (eml_i0 = 0; eml_i0 < 4; eml_i0++) {
          eml_dv9[eml_i1 + (eml_i0 << 2)] = 0.0;
          for (eml_i2 = 0; eml_i2 < 4; eml_i2++) {
            eml_dv9[eml_i1 + (eml_i0 << 2)] += eml_dv8[eml_i1 + (eml_i2 << 2)] *
              eml_A_T_x[eml_i2 + (eml_i0 << 2)];
          }
        }

        for (eml_i0 = 0; eml_i0 < 4; eml_i0++) {
          eml_dv10[eml_i1 + (eml_i0 << 2)] = 0.0;
          for (eml_i2 = 0; eml_i2 < 4; eml_i2++) {
            eml_dv10[eml_i1 + (eml_i0 << 2)] += eml_dv9[eml_i1 + (eml_i2 << 2)] *
              (real_T)eml_bv2[eml_i2 + (eml_i0 << 2)];
          }
        }
      }

      for (eml_i0 = 0; eml_i0 < 4; eml_i0++) {
        for (eml_i2 = 0; eml_i2 < 4; eml_i2++) {
          eml_T03[eml_i0 + (eml_i2 << 2)] = 0.0;
          for (eml_i1 = 0; eml_i1 < 4; eml_i1++) {
            eml_T03[eml_i0 + (eml_i2 << 2)] += eml_T02[eml_i0 + (eml_i1 << 2)] *
              eml_dv10[eml_i1 + (eml_i2 << 2)];
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
          Puncture_Through_Wall_B.Rot[eml_i2 + 3 * eml_i0] = eml_T03[eml_i2 +
            (eml_i0 << 2)];
        }
      }

      for (eml_i0 = 0; eml_i0 < 4; eml_i0++) {
        for (eml_i2 = 0; eml_i2 < 4; eml_i2++) {
          eml_dv11[eml_i0 + (eml_i2 << 2)] = 0.0;
          for (eml_i1 = 0; eml_i1 < 4; eml_i1++) {
            eml_dv11[eml_i0 + (eml_i2 << 2)] += eml_T03[eml_i0 + (eml_i1 << 2)] *
              Puncture_Through_Wall_B.ToolOffset2[eml_i1 + (eml_i2 << 2)];
          }
        }
      }

      for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
        Puncture_Through_Wall_B.pos[eml_i0] = eml_dv11[eml_i0 + 12];

        /* Formulation of the Jacobian */
        /* %%%%%%%%%%%%%%%%%%%%%%%%%%%JACOBIAN%%%%%%%%%%%%%%%%%%%%%%%% */
        eml_b[eml_i0] = Puncture_Through_Wall_B.pos[eml_i0] - eml_T02[eml_i0 +
          12];
        eml_b_0[eml_i0] = Puncture_Through_Wall_B.pos[eml_i0] - eml_A1[eml_i0 +
          12];
        eml_b_1[eml_i0] = Puncture_Through_Wall_B.pos[eml_i0];
      }

      Puncture_Through_Wall_B.Jac[0] = 0.0 * eml_b_1[2] - eml_b_1[1];
      Puncture_Through_Wall_B.Jac[1] = eml_b_1[0] - 0.0 * eml_b_1[2];
      Puncture_Through_Wall_B.Jac[2] = 0.0 * eml_b_1[1] - 0.0 * eml_b_1[0];
      Puncture_Through_Wall_B.Jac[6] = eml_z1[1] * eml_b_0[2] - eml_z1[2] *
        eml_b_0[1];
      Puncture_Through_Wall_B.Jac[7] = eml_z1[2] * eml_b_0[0] - eml_z1[0] *
        eml_b_0[2];
      Puncture_Through_Wall_B.Jac[8] = eml_z1[0] * eml_b_0[1] - eml_z1[1] *
        eml_b_0[0];
      Puncture_Through_Wall_B.Jac[12] = eml_z2[1] * eml_b[2] - eml_z2[2] *
        eml_b[1];
      Puncture_Through_Wall_B.Jac[13] = eml_z2[2] * eml_b[0] - eml_z2[0] *
        eml_b[2];
      Puncture_Through_Wall_B.Jac[14] = eml_z2[0] * eml_b[1] - eml_z2[1] *
        eml_b[0];
      for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
        Puncture_Through_Wall_B.Jac[eml_i0 + 3] = (real_T)eml_bv3[eml_i0];
      }

      for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
        Puncture_Through_Wall_B.Jac[eml_i0 + 9] = eml_z1[eml_i0];
      }

      for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
        Puncture_Through_Wall_B.Jac[eml_i0 + 15] = eml_z2[eml_i0];
      }
    }

    /* Math: '<S4>/Math Function' */
    for (i = 0; i < 6; i++) {
      tmp[3 * i] = Puncture_Through_Wall_B.Jac[i];
      tmp[1 + 3 * i] = Puncture_Through_Wall_B.Jac[i + 6];
      tmp[2 + 3 * i] = Puncture_Through_Wall_B.Jac[i + 12];
    }

    for (i = 0; i < 18; i++) {
      rtb_MathFunction[i] = tmp[i];
    }

    /* UnitDelay: '<Root>/Unit Delay1' */
    Puncture_Through_Wall_B.UnitDelay1[0] =
      Puncture_Through_Wall_DWork.UnitDelay1_DSTATE[0];
    Puncture_Through_Wall_B.UnitDelay1[1] =
      Puncture_Through_Wall_DWork.UnitDelay1_DSTATE[1];
    Puncture_Through_Wall_B.UnitDelay1[2] =
      Puncture_Through_Wall_DWork.UnitDelay1_DSTATE[2];

    /* Constant: '<Root>/Stiffness' */
    Puncture_Through_Wall_B.Stiffness = Puncture_Through_Wall_P.Stiffness_Value;

    /* Constant: '<Root>/Break Force' */
    Puncture_Through_Wall_B.BreakForce =
      Puncture_Through_Wall_P.BreakForce_Value;

    /* UnitDelay: '<Root>/Unit Delay3' */
    Puncture_Through_Wall_B.UnitDelay3 =
      Puncture_Through_Wall_DWork.UnitDelay3_DSTATE;

    /* UnitDelay: '<Root>/Unit Delay2' */
    Puncture_Through_Wall_B.UnitDelay2 =
      Puncture_Through_Wall_DWork.UnitDelay2_DSTATE;

    /* Embedded MATLAB: '<Root>/Calculate Force' */
    {
      real_T eml_av;
      int32_T eml_touching;
      boolean_T eml_guard1 = false;
      real_T eml_x;
      real_T eml_dv0[3];

      /* DESCRIPTION--------------------------------------------------------------- */
      /* Determine the force. The magnitude of the force is penetration into the wall */
      /* The direction of force depends on the which of the wall the avatar is on.  */
      /* The wall is implemented in the x-z */
      /* INPUTS-------------------------------------------------------------------- */
      /* Force_prev - force in the previous sample time */
      /* x - position of the avatar */
      /* stiffness - stiffness of wall */
      /* Fbreak - force required to break the wall */
      /* dir_prev - the side of the wall where the avatar was in the previous sample time */
      /* dir_flag - the value of flag in the previous sample time. flag is 1 when  */
      /* the wall is broken, flag is 0 when the wall is solid. */
      /* OUTPUTS------------------------------------------------------------------- */
      /* Force - magnitude and direction of force to be applied */
      /* dir - the side of the wall where the avatar is. If the avatar is strictly */
      /* on the left dir = -1, if avatar is strictly on the right, dir = 1, else the */
      /* avatar is touching or penetrating the wall and keep the previous direction */
      /*  flag - flag is 1 when the wall is broken , flag is 0 when wall is solid */
      /* The y coordinate of the left side of the wall */
      /* The y coordinate of teh right side of the wall */
      /* The y coordinate of the avatar */
      eml_av = Puncture_Through_Wall_B.pos[1];

      /* declare variables */
      Puncture_Through_Wall_B.dir = Puncture_Through_Wall_B.UnitDelay3;
      for (eml_touching = 0; eml_touching < 3; eml_touching++) {
        Puncture_Through_Wall_B.Force[eml_touching] = 0.0;
      }

      Puncture_Through_Wall_B.flag = Puncture_Through_Wall_B.UnitDelay2;
      eml_guard1 = false;
      if ((!(eml_av >= -0.01)) || (!(eml_av <= 0.01))) {
        eml_x = Puncture_Through_Wall_B.UnitDelay1[1];
        if ((boolean_T)rtIsNaN(eml_x)) {
          eml_x = rtNaN;
        } else if (eml_x > 0.0) {
          eml_x = 1.0;
        } else if (eml_x < 0.0) {
          eml_x = -1.0;
        }

        if (eml_x == Puncture_Through_Wall_B.UnitDelay3) {
          eml_guard1 = true;
        } else {
          eml_touching = 0;
        }
      } else {
        eml_guard1 = true;
      }

      if (eml_guard1 == true) {
        /* If inside the wall or pushing agains the wall, touching = 1, else 0. touching */
        /* indicates when the wall is being touched. */
        eml_touching = 1;
      }

      if (Puncture_Through_Wall_B.UnitDelay2 == 1.0) {
        /* if the wall is broken, keep its state as broken, until the avatar is completly */
        /* on one side of teh wall and not inside it. */
        Puncture_Through_Wall_B.flag = 1.0;
        if ((eml_av < -0.01) || (eml_av > 0.01)) {
          Puncture_Through_Wall_B.flag = 0.0;
        }
      }

      if ((Puncture_Through_Wall_B.UnitDelay3 == -1.0) && (eml_touching != 0) &&
          (eml_av > -0.01) && (Puncture_Through_Wall_B.flag == 0.0)) {
        /*  If the wall is solid and the avatar is touchign the wall */
        /* Calcualte the force based on the side of the wall the avatar is. */
        eml_x = Puncture_Through_Wall_B.UnitDelay3 *
          Puncture_Through_Wall_B.Stiffness;
        eml_dv0[0] = 0.0;
        eml_dv0[1] = eml_av - -0.01;
        eml_dv0[2] = 0.0;
        for (eml_touching = 0; eml_touching < 3; eml_touching++) {
          Puncture_Through_Wall_B.Force[eml_touching] = eml_x *
            eml_dv0[eml_touching];
        }
      } else if ((Puncture_Through_Wall_B.UnitDelay3 == 1.0) && (eml_touching !=
                  0) && (eml_av < 0.01) && (Puncture_Through_Wall_B.flag == 0.0))
      {
        eml_x = Puncture_Through_Wall_B.UnitDelay3 *
          Puncture_Through_Wall_B.Stiffness;
        eml_dv0[0] = 0.0;
        eml_dv0[1] = fabs(eml_av - 0.01);
        eml_dv0[2] = 0.0;
        for (eml_touching = 0; eml_touching < 3; eml_touching++) {
          Puncture_Through_Wall_B.Force[eml_touching] = eml_x *
            eml_dv0[eml_touching];
        }
      }

      if (fabs(Puncture_Through_Wall_B.Force[1]) >=
          Puncture_Through_Wall_B.BreakForce) {
        /* If force is above break force, change the status of the wall to broken */
        Puncture_Through_Wall_B.flag = 1.0;
      }

      if (eml_av < -0.01) {
        /*  if avatar is on the left, dir = -1, elseif avatar is on theright dir = 1 */
        Puncture_Through_Wall_B.dir = -1.0;
      } else if (eml_av > 0.01) {
        Puncture_Through_Wall_B.dir = 1.0;
      }
    }

    /* SignalConversion: '<S4>/TmpHiddenBufferAtProductInport2' incorporates:
     *  Constant: '<S4>/Constant'
     */
    rtb_TmpHiddenBufferAtProductInp[0] = Puncture_Through_Wall_B.Force[0];
    rtb_TmpHiddenBufferAtProductInp[1] = Puncture_Through_Wall_B.Force[1];
    rtb_TmpHiddenBufferAtProductInp[2] = Puncture_Through_Wall_B.Force[2];
    rtb_TmpHiddenBufferAtProductInp[3] = Puncture_Through_Wall_P.Constant_Value
      [0];
    rtb_TmpHiddenBufferAtProductInp[4] = Puncture_Through_Wall_P.Constant_Value
      [1];
    rtb_TmpHiddenBufferAtProductInp[5] = Puncture_Through_Wall_P.Constant_Value
      [2];

    {
      static const int_T dims[3] = { 3, 6, 1 };

      rt_MatMultRR_Dbl(rtb_Switch_n, rtb_MathFunction,
                       rtb_TmpHiddenBufferAtProductInp, &dims[0]);
    }

    /* Gain: '<S4>/Convert to Positive Rotation Convension Used in Kinematics1' */
    Puncture_Through_Wall_B.ConverttoPositiveRotationConven[0] =
      Puncture_Through_Wall_P.ConverttoPositiveRotationConv_p[0] * rtb_Switch_n
      [0];
    Puncture_Through_Wall_B.ConverttoPositiveRotationConven[1] =
      Puncture_Through_Wall_P.ConverttoPositiveRotationConv_p[1] * rtb_Switch_n
      [1];
    Puncture_Through_Wall_B.ConverttoPositiveRotationConven[2] =
      Puncture_Through_Wall_P.ConverttoPositiveRotationConv_p[2] * rtb_Switch_n
      [2];

    /* Embedded MATLAB: '<S12>/Joint Torque to Motor Torque' */
    {
      int32_T eml_i0;

      /*  Smart Saturation: allows channels to go up to 1.6A  */
      /*  unless the total exceeds 2.2A in which case all channels */
      /*  are scaled so that the cumulative current is equal to 2.2A. */
      for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
        Puncture_Through_Wall_B.y_i[eml_i0] = 0.0;
      }

      Puncture_Through_Wall_B.y_i[0] =
        Puncture_Through_Wall_B.ConverttoPositiveRotationConven[0];
      Puncture_Through_Wall_B.y_i[2] =
        Puncture_Through_Wall_B.ConverttoPositiveRotationConven[2];
      Puncture_Through_Wall_B.y_i[1] =
        Puncture_Through_Wall_B.ConverttoPositiveRotationConven[1] -
        Puncture_Through_Wall_B.ConverttoPositiveRotationConven[2];
    }

    /* Gain: '<S12>/Kt' incorporates:
     *  Gain: '<S12>/Gear Ratio1'
     */
    rtb_Switch_n[0] = Puncture_Through_Wall_P.GearRatio1_Gain[0] *
      Puncture_Through_Wall_B.y_i[0] * Puncture_Through_Wall_P.Kt_Gain;
    rtb_Switch_n[1] = Puncture_Through_Wall_P.GearRatio1_Gain[1] *
      Puncture_Through_Wall_B.y_i[1] * Puncture_Through_Wall_P.Kt_Gain;
    rtb_Switch_n[2] = Puncture_Through_Wall_P.GearRatio1_Gain[2] *
      Puncture_Through_Wall_B.y_i[2] * Puncture_Through_Wall_P.Kt_Gain;

    /* Saturate: '<S12>/Saturation' */
    Puncture_Through_Wall_B.Saturation[0] = rt_SATURATE(rtb_Switch_n[0],
      Puncture_Through_Wall_P.Saturation_LowerSat,
      Puncture_Through_Wall_P.Saturation_UpperSat);
    Puncture_Through_Wall_B.Saturation[1] = rt_SATURATE(rtb_Switch_n[1],
      Puncture_Through_Wall_P.Saturation_LowerSat,
      Puncture_Through_Wall_P.Saturation_UpperSat);
    Puncture_Through_Wall_B.Saturation[2] = rt_SATURATE(rtb_Switch_n[2],
      Puncture_Through_Wall_P.Saturation_LowerSat,
      Puncture_Through_Wall_P.Saturation_UpperSat);

    /* Embedded MATLAB: '<S12>/Smart Saturation' */
    {
      int32_T eml_k;
      real_T eml_x[3];
      real_T eml_total;

      /*  Smart Saturation: allows channels to go up to 1.6A  */
      /*  unless the total exceeds 2.2A in which case all channels */
      /*  are scaled so that the cumulative current is equal to 2.2A. */
      /*  Define the maximum cumulative current here */
      for (eml_k = 0; eml_k < 3; eml_k++) {
        eml_x[eml_k] = fabs(Puncture_Through_Wall_B.Saturation[eml_k]);
      }

      eml_total = eml_x[0];
      for (eml_k = 2; eml_k < 4; eml_k++) {
        eml_total += eml_x[eml_k - 1];
      }

      if (eml_total > 2.2) {
        eml_total = 2.2 / eml_total;
        for (eml_k = 0; eml_k < 3; eml_k++) {
          Puncture_Through_Wall_B.y[eml_k] = eml_total *
            Puncture_Through_Wall_B.Saturation[eml_k];
        }
      } else {
        for (eml_k = 0; eml_k < 3; eml_k++) {
          Puncture_Through_Wall_B.y[eml_k] =
            Puncture_Through_Wall_B.Saturation[eml_k];
        }
      }
    }

    /* S-Function Block: Puncture_Through_Wall/Omni/HIL Write PWM (hil_write_pwm_block) */
    {
      t_error result;
      result = hil_write_pwm(Puncture_Through_Wall_DWork.HILInitialize_Card,
        Puncture_Through_Wall_P.HILWritePWM_Channels, 3,
        Puncture_Through_Wall_B.y);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Puncture_Through_Wall_M, _rt_error_message);
      }
    }

    /* S-Function Block: Puncture_Through_Wall/Omni/HIL Read Analog (hil_read_analog_block) */
    {
      t_error result = hil_read_analog
        (Puncture_Through_Wall_DWork.HILInitialize_Card,
         Puncture_Through_Wall_P.HILReadAnalog_Channels, 3, rtb_Switch_n);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Puncture_Through_Wall_M, _rt_error_message);
      }
    }

    /* Switch: '<S2>/Switch' incorporates:
     *  Constant: '<S2>/Constant1'
     *  Constant: '<S2>/Constant2'
     *  Constant: '<S2>/Constant3'
     *  Constant: '<S2>/Constant4'
     *  Constant: '<S2>/Constant5'
     *  Gain: '<S7>/Slider Gain'
     *  Gain: '<S8>/Slider Gain'
     *  Sum: '<S2>/Add'
     *  Sum: '<S2>/Add1'
     */
    if (Puncture_Through_Wall_B.dir >= Puncture_Through_Wall_P.Switch_Threshold)
    {
      rtb_Switch_n[0] = Puncture_Through_Wall_P.SliderGain_Gain_e *
        Puncture_Through_Wall_P.Constant1_Value_j +
        Puncture_Through_Wall_P.Constant4_Value[1];
      rtb_Switch_n[1] = Puncture_Through_Wall_P.Constant2_Value[0];
      rtb_Switch_n[2] = Puncture_Through_Wall_P.Constant2_Value[1];
    } else {
      rtb_Switch_n[0] = Puncture_Through_Wall_P.Constant4_Value[1] -
        Puncture_Through_Wall_P.SliderGain_Gain_i *
        Puncture_Through_Wall_P.Constant3_Value_c;
      rtb_Switch_n[1] = Puncture_Through_Wall_P.Constant5_Value[0];
      rtb_Switch_n[2] = Puncture_Through_Wall_P.Constant5_Value[1];
    }

    /* RateTransition: '<Root>/Rate Transition1' */
    if (Puncture_Through_Wall_M->Timing.RateInteraction.TID0_1) {
      Puncture_Through_Wall_B.RateTransition1[0] = rtb_Switch_n[0];
      Puncture_Through_Wall_B.RateTransition1[1] = rtb_Switch_n[1];
      Puncture_Through_Wall_B.RateTransition1[2] = rtb_Switch_n[2];
    }

    /* Switch: '<S5>/Switch1' */
    if (Puncture_Through_Wall_B.dir >= Puncture_Through_Wall_P.Switch1_Threshold)
    {
      /* Switch: '<S16>/Switch2' incorporates:
       *  Constant: '<S5>/Constant2'
       *  RelationalOperator: '<S16>/LowerRelop1'
       */
      if (Puncture_Through_Wall_B.pos[1] >
          Puncture_Through_Wall_P.Constant2_Value_m) {
        rtb_Add_k = Puncture_Through_Wall_P.Constant2_Value_m;
      } else {
        /* Sum: '<S5>/Add' incorporates:
         *  Constant: '<S5>/Constant1'
         *  Constant: '<S5>/Constant3'
         */
        rtb_Add_k = Puncture_Through_Wall_P.Constant1_Value_e[1] +
          Puncture_Through_Wall_P.Constant3_Value;

        /* Switch: '<S16>/Switch' incorporates:
         *  RelationalOperator: '<S16>/UpperRelop'
         */
        if (!(Puncture_Through_Wall_B.pos[1] < rtb_Add_k)) {
          rtb_Add_k = Puncture_Through_Wall_B.pos[1];
        }
      }

      Puncture_Through_Wall_B.Switch1 = rtb_Add_k;
    } else {
      /* Sum: '<S5>/Subtract' incorporates:
       *  Constant: '<S5>/Constant1'
       *  Constant: '<S5>/Constant3'
       */
      rtb_Add_k = Puncture_Through_Wall_P.Constant1_Value_e[1] -
        Puncture_Through_Wall_P.Constant3_Value;

      /* Switch: '<S17>/Switch2' incorporates:
       *  RelationalOperator: '<S17>/LowerRelop1'
       */
      if (!(Puncture_Through_Wall_B.pos[1] > rtb_Add_k)) {
        /* Switch: '<S17>/Switch' incorporates:
         *  Constant: '<S5>/Constant4'
         *  RelationalOperator: '<S17>/UpperRelop'
         */
        if (Puncture_Through_Wall_B.pos[1] <
            Puncture_Through_Wall_P.Constant4_Value_i) {
          rtb_Add_k = Puncture_Through_Wall_P.Constant4_Value_i;
        } else {
          rtb_Add_k = Puncture_Through_Wall_B.pos[1];
        }
      }

      Puncture_Through_Wall_B.Switch1 = rtb_Add_k;
    }

    /* RateTransition: '<Root>/Rate Transition' */
    if (Puncture_Through_Wall_M->Timing.RateInteraction.TID0_1) {
      Puncture_Through_Wall_B.RateTransition[0] =
        Puncture_Through_Wall_B.Switch1;
      Puncture_Through_Wall_B.RateTransition[1] = Puncture_Through_Wall_B.pos[2];
      Puncture_Through_Wall_B.RateTransition[2] = Puncture_Through_Wall_B.pos[0];
    }
  }

  UNUSED_PARAMETER(tid);
}

/* Model update function for TID0 */
void Puncture_Through_Wall_update0(int_T tid)/* Sample time: [0.001s, 0.0s] */
{
  /* Update for UnitDelay: '<Root>/Unit Delay1' */
  Puncture_Through_Wall_DWork.UnitDelay1_DSTATE[0] =
    Puncture_Through_Wall_B.Force[0];
  Puncture_Through_Wall_DWork.UnitDelay1_DSTATE[1] =
    Puncture_Through_Wall_B.Force[1];
  Puncture_Through_Wall_DWork.UnitDelay1_DSTATE[2] =
    Puncture_Through_Wall_B.Force[2];

  /* Update for UnitDelay: '<Root>/Unit Delay3' */
  Puncture_Through_Wall_DWork.UnitDelay3_DSTATE = Puncture_Through_Wall_B.dir;

  /* Update for UnitDelay: '<Root>/Unit Delay2' */
  Puncture_Through_Wall_DWork.UnitDelay2_DSTATE = Puncture_Through_Wall_B.flag;

  /* Update absolute time */
  if (!(++Puncture_Through_Wall_M->Timing.clockTick0))
    ++Puncture_Through_Wall_M->Timing.clockTickH0;
  Puncture_Through_Wall_M->Timing.t[0] =
    Puncture_Through_Wall_M->Timing.clockTick0 *
    Puncture_Through_Wall_M->Timing.stepSize0 +
    Puncture_Through_Wall_M->Timing.clockTickH0 *
    Puncture_Through_Wall_M->Timing.stepSize0 * 4294967296.0;
  UNUSED_PARAMETER(tid);
}

/* Model output function for TID1 */
void Puncture_Through_Wall_output1(int_T tid) /* Sample time: [0.1s, 0.0s] */
{
  /* Gain: '<S6>/Slider Gain' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  Puncture_Through_Wall_B.SliderGain = Puncture_Through_Wall_P.SliderGain_Gain *
    Puncture_Through_Wall_P.Constant1_Value;

  /* Gain: '<Root>/Gain' */
  Puncture_Through_Wall_B.Gain[0] = Puncture_Through_Wall_P.Gain_Gain[0] *
    Puncture_Through_Wall_B.RateTransition[0];
  Puncture_Through_Wall_B.Gain[1] = Puncture_Through_Wall_P.Gain_Gain[1] *
    Puncture_Through_Wall_B.RateTransition[1];
  Puncture_Through_Wall_B.Gain[2] = Puncture_Through_Wall_P.Gain_Gain[2] *
    Puncture_Through_Wall_B.RateTransition[2];

  /* Constant: '<Root>/Constant3' */
  Puncture_Through_Wall_B.Constant3[0] =
    Puncture_Through_Wall_P.Constant3_Value_p[0];
  Puncture_Through_Wall_B.Constant3[1] =
    Puncture_Through_Wall_P.Constant3_Value_p[1];
  Puncture_Through_Wall_B.Constant3[2] =
    Puncture_Through_Wall_P.Constant3_Value_p[2];
  UNUSED_PARAMETER(tid);
}

/* Model update function for TID1 */
void Puncture_Through_Wall_update1(int_T tid)/* Sample time: [0.1s, 0.0s] */
{
  /* Update absolute time */
  if (!(++Puncture_Through_Wall_M->Timing.clockTick1))
    ++Puncture_Through_Wall_M->Timing.clockTickH1;
  Puncture_Through_Wall_M->Timing.t[1] =
    Puncture_Through_Wall_M->Timing.clockTick1 *
    Puncture_Through_Wall_M->Timing.stepSize1 +
    Puncture_Through_Wall_M->Timing.clockTickH1 *
    Puncture_Through_Wall_M->Timing.stepSize1 * 4294967296.0;
  UNUSED_PARAMETER(tid);
}

void Puncture_Through_Wall_output(int_T tid)
{
  switch (tid) {
   case 0 :
    Puncture_Through_Wall_output0(0);
    break;

   case 1 :
    Puncture_Through_Wall_output1(1);
    break;

   default :
    break;
  }
}

void Puncture_Through_Wall_update(int_T tid)
{
  switch (tid) {
   case 0 :
    Puncture_Through_Wall_update0(0);
    break;

   case 1 :
    Puncture_Through_Wall_update1(1);
    break;

   default :
    break;
  }
}

/* Model initialize function */
void Puncture_Through_Wall_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));    /* initialize real-time model */
  (void) memset((char_T *)Puncture_Through_Wall_M,0,
                sizeof(RT_MODEL_Puncture_Through_Wall));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Puncture_Through_Wall_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Puncture_Through_Wall_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Puncture_Through_Wall_M->Timing.sampleTimes =
      (&Puncture_Through_Wall_M->Timing.sampleTimesArray[0]);
    Puncture_Through_Wall_M->Timing.offsetTimes =
      (&Puncture_Through_Wall_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Puncture_Through_Wall_M->Timing.sampleTimes[0] = (0.001);
    Puncture_Through_Wall_M->Timing.sampleTimes[1] = (0.1);

    /* task offsets */
    Puncture_Through_Wall_M->Timing.offsetTimes[0] = (0.0);
    Puncture_Through_Wall_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Puncture_Through_Wall_M, &Puncture_Through_Wall_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Puncture_Through_Wall_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      Puncture_Through_Wall_M->Timing.perTaskSampleHitsArray;
    Puncture_Through_Wall_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    Puncture_Through_Wall_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Puncture_Through_Wall_M, -1);
  Puncture_Through_Wall_M->Timing.stepSize0 = 0.001;
  Puncture_Through_Wall_M->Timing.stepSize1 = 0.1;

  /* external mode info */
  Puncture_Through_Wall_M->Sizes.checksums[0] = (229532757U);
  Puncture_Through_Wall_M->Sizes.checksums[1] = (4184693949U);
  Puncture_Through_Wall_M->Sizes.checksums[2] = (841558308U);
  Puncture_Through_Wall_M->Sizes.checksums[3] = (3478176748U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[12];
    Puncture_Through_Wall_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &Puncture_Through_Wall_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo,
                        Puncture_Through_Wall_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(Puncture_Through_Wall_M));
  }

  Puncture_Through_Wall_M->solverInfoPtr = (&Puncture_Through_Wall_M->solverInfo);
  Puncture_Through_Wall_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Puncture_Through_Wall_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Puncture_Through_Wall_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  Puncture_Through_Wall_M->ModelData.blockIO = ((void *)
    &Puncture_Through_Wall_B);

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&Puncture_Through_Wall_B.GearRatio[0]);
    for (i = 0; i < 49; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    pVoidBlockIORegion = (void *)(&Puncture_Through_Wall_B.y[0]);
    for (i = 0; i < 44; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }
  }

  /* parameters */
  Puncture_Through_Wall_M->ModelData.defaultParam = ((real_T *)
    &Puncture_Through_Wall_P);

  /* states (dwork) */
  Puncture_Through_Wall_M->Work.dwork = ((void *) &Puncture_Through_Wall_DWork);
  (void) memset((char_T *) &Puncture_Through_Wall_DWork,0,
                sizeof(D_Work_Puncture_Through_Wall));

  {
    int_T i;
    real_T *dwork_ptr = (real_T *)
      &Puncture_Through_Wall_DWork.UnitDelay1_DSTATE[0];
    for (i = 0; i < 18; i++) {
      dwork_ptr[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    Puncture_Through_Wall_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void Puncture_Through_Wall_terminate(void)
{
  /* S-Function Block: Puncture_Through_Wall/Omni/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    hil_task_stop_all(Puncture_Through_Wall_DWork.HILInitialize_Card);
    hil_task_delete_all(Puncture_Through_Wall_DWork.HILInitialize_Card);
    is_switching = false;
    if ((Puncture_Through_Wall_P.HILInitialize_POTerminate && !is_switching) ||
        (Puncture_Through_Wall_P.HILInitialize_POExit && is_switching)) {
      Puncture_Through_Wall_DWork.HILInitialize_POValues[0] =
        Puncture_Through_Wall_P.HILInitialize_POFinal;
      Puncture_Through_Wall_DWork.HILInitialize_POValues[1] =
        Puncture_Through_Wall_P.HILInitialize_POFinal;
      Puncture_Through_Wall_DWork.HILInitialize_POValues[2] =
        Puncture_Through_Wall_P.HILInitialize_POFinal;
      result = hil_write_pwm(Puncture_Through_Wall_DWork.HILInitialize_Card,
        &Puncture_Through_Wall_P.HILInitialize_POChannels[0], 3U,
        &Puncture_Through_Wall_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Puncture_Through_Wall_M, _rt_error_message);
      }
    }

    hil_close(Puncture_Through_Wall_DWork.HILInitialize_Card);
    Puncture_Through_Wall_DWork.HILInitialize_Card = NULL;
  }

  /* External mode */
  rtExtModeShutdown(2);
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Puncture_Through_Wall_output(tid);
}

void MdlUpdate(int_T tid)
{
  Puncture_Through_Wall_update(tid);
}

void MdlInitializeSizes(void)
{
  Puncture_Through_Wall_M->Sizes.numContStates = (0);/* Number of continuous states */
  Puncture_Through_Wall_M->Sizes.numY = (0);/* Number of model outputs */
  Puncture_Through_Wall_M->Sizes.numU = (0);/* Number of model inputs */
  Puncture_Through_Wall_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Puncture_Through_Wall_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Puncture_Through_Wall_M->Sizes.numBlocks = (72);/* Number of blocks */
  Puncture_Through_Wall_M->Sizes.numBlockIO = (25);/* Number of block outputs */
  Puncture_Through_Wall_M->Sizes.numBlockPrms = (139);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* Initialize code for chart: '<S9>/Embedded MATLAB Function' */
  Puncture_Through_Wall_DWork.is_active_c8_Puncture_Through_W = 0U;

  /* Initialize code for chart: '<S4>/Forward Kinematics ' */
  Puncture_Through_Wall_DWork.is_active_c5_Puncture_Through_W = 0U;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay1' */
  Puncture_Through_Wall_DWork.UnitDelay1_DSTATE[0] =
    Puncture_Through_Wall_P.UnitDelay1_X0[0];
  Puncture_Through_Wall_DWork.UnitDelay1_DSTATE[1] =
    Puncture_Through_Wall_P.UnitDelay1_X0[1];
  Puncture_Through_Wall_DWork.UnitDelay1_DSTATE[2] =
    Puncture_Through_Wall_P.UnitDelay1_X0[2];

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay3' */
  Puncture_Through_Wall_DWork.UnitDelay3_DSTATE =
    Puncture_Through_Wall_P.UnitDelay3_X0;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay2' */
  Puncture_Through_Wall_DWork.UnitDelay2_DSTATE =
    Puncture_Through_Wall_P.UnitDelay2_X0;

  /* Initialize code for chart: '<Root>/Calculate Force' */
  Puncture_Through_Wall_DWork.is_active_c2_Puncture_Through_W = 0U;

  /* Initialize code for chart: '<S12>/Joint Torque to Motor Torque' */
  Puncture_Through_Wall_DWork.is_active_c4_Puncture_Through_W = 0U;

  /* Initialize code for chart: '<S12>/Smart Saturation' */
  Puncture_Through_Wall_DWork.is_active_c3_Puncture_Through_W = 0U;
}

void MdlStart(void)
{
  {
    int32_T i;

    /* S-Function Block: Puncture_Through_Wall/Omni/HIL Initialize (hil_initialize_block) */
    {
      t_int result;
      t_boolean is_switching;
      result = hil_open("phantom_omni", "0",
                        &Puncture_Through_Wall_DWork.HILInitialize_Card);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Puncture_Through_Wall_M, _rt_error_message);
        return;
      }

      is_switching = false;
      if ((Puncture_Through_Wall_P.HILInitialize_AIPStart && !is_switching) ||
          (Puncture_Through_Wall_P.HILInitialize_AIPEnter && is_switching)) {
        Puncture_Through_Wall_DWork.HILInitialize_AIMinimums[0] =
          Puncture_Through_Wall_P.HILInitialize_AILow;
        Puncture_Through_Wall_DWork.HILInitialize_AIMinimums[1] =
          Puncture_Through_Wall_P.HILInitialize_AILow;
        Puncture_Through_Wall_DWork.HILInitialize_AIMaximums[0] =
          Puncture_Through_Wall_P.HILInitialize_AIHigh;
        Puncture_Through_Wall_DWork.HILInitialize_AIMaximums[1] =
          Puncture_Through_Wall_P.HILInitialize_AIHigh;
        result = hil_set_analog_input_ranges
          (Puncture_Through_Wall_DWork.HILInitialize_Card,
           &Puncture_Through_Wall_P.HILInitialize_AIChannels[0], 2U,
           &Puncture_Through_Wall_DWork.HILInitialize_AIMinimums[0],
           &Puncture_Through_Wall_DWork.HILInitialize_AIMaximums[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Puncture_Through_Wall_M, _rt_error_message);
          return;
        }
      }

      if ((Puncture_Through_Wall_P.HILInitialize_EIStart && !is_switching) ||
          (Puncture_Through_Wall_P.HILInitialize_EIEnter && is_switching)) {
        Puncture_Through_Wall_DWork.HILInitialize_InitialEICounts[0] =
          Puncture_Through_Wall_P.HILInitialize_EIInitial;
        Puncture_Through_Wall_DWork.HILInitialize_InitialEICounts[1] =
          Puncture_Through_Wall_P.HILInitialize_EIInitial;
        Puncture_Through_Wall_DWork.HILInitialize_InitialEICounts[2] =
          Puncture_Through_Wall_P.HILInitialize_EIInitial;
        result = hil_set_encoder_counts
          (Puncture_Through_Wall_DWork.HILInitialize_Card,
           &Puncture_Through_Wall_P.HILInitialize_EIChannels[0], 3U,
           &Puncture_Through_Wall_DWork.HILInitialize_InitialEICounts[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Puncture_Through_Wall_M, _rt_error_message);
          return;
        }
      }

      if ((Puncture_Through_Wall_P.HILInitialize_POStart && !is_switching) ||
          (Puncture_Through_Wall_P.HILInitialize_POEnter && is_switching)) {
        Puncture_Through_Wall_DWork.HILInitialize_POValues[0] =
          Puncture_Through_Wall_P.HILInitialize_POInitial;
        Puncture_Through_Wall_DWork.HILInitialize_POValues[1] =
          Puncture_Through_Wall_P.HILInitialize_POInitial;
        Puncture_Through_Wall_DWork.HILInitialize_POValues[2] =
          Puncture_Through_Wall_P.HILInitialize_POInitial;
        result = hil_write_pwm(Puncture_Through_Wall_DWork.HILInitialize_Card,
          &Puncture_Through_Wall_P.HILInitialize_POChannels[0], 3U,
          &Puncture_Through_Wall_DWork.HILInitialize_POValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Puncture_Through_Wall_M, _rt_error_message);
          return;
        }
      }

      if (Puncture_Through_Wall_P.HILInitialize_POReset) {
        Puncture_Through_Wall_DWork.HILInitialize_POValues[0] =
          Puncture_Through_Wall_P.HILInitialize_POWatchdog;
        Puncture_Through_Wall_DWork.HILInitialize_POValues[1] =
          Puncture_Through_Wall_P.HILInitialize_POWatchdog;
        Puncture_Through_Wall_DWork.HILInitialize_POValues[2] =
          Puncture_Through_Wall_P.HILInitialize_POWatchdog;
        result = hil_watchdog_set_pwm_expiration_state
          (Puncture_Through_Wall_DWork.HILInitialize_Card,
           &Puncture_Through_Wall_P.HILInitialize_POChannels[0], 3U,
           &Puncture_Through_Wall_DWork.HILInitialize_POValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Puncture_Through_Wall_M, _rt_error_message);
          return;
        }
      }
    }

    /* S-Function Block: Puncture_Through_Wall/Omni/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_create_encoder_reader
        (Puncture_Through_Wall_DWork.HILInitialize_Card,
         Puncture_Through_Wall_P.HILReadEncoderTimebase_SamplesI,
         Puncture_Through_Wall_P.HILReadEncoderTimebase_Channels, 3,
         &Puncture_Through_Wall_DWork.HILReadEncoderTimebase_Task);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Puncture_Through_Wall_M, _rt_error_message);
      }
    }

    for (i = 0; i < 16; i++) {
      /* Start for Constant: '<S4>/Tool Offset2' */
      Puncture_Through_Wall_B.ToolOffset2[i] =
        Puncture_Through_Wall_P.ToolOffset2_Value[i];
    }

    /* Start for Constant: '<Root>/Stiffness' */
    Puncture_Through_Wall_B.Stiffness = Puncture_Through_Wall_P.Stiffness_Value;

    /* Start for Constant: '<Root>/Break Force' */
    Puncture_Through_Wall_B.BreakForce =
      Puncture_Through_Wall_P.BreakForce_Value;

    /* Start for Constant: '<Root>/Constant3' */
    Puncture_Through_Wall_B.Constant3[0] =
      Puncture_Through_Wall_P.Constant3_Value_p[0];
    Puncture_Through_Wall_B.Constant3[1] =
      Puncture_Through_Wall_P.Constant3_Value_p[1];
    Puncture_Through_Wall_B.Constant3[2] =
      Puncture_Through_Wall_P.Constant3_Value_p[2];
  }

  MdlInitialize();
}

RT_MODEL_Puncture_Through_Wall *Puncture_Through_Wall(void)
{
  Puncture_Through_Wall_initialize(1);
  return Puncture_Through_Wall_M;
}

void MdlTerminate(void)
{
  Puncture_Through_Wall_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
