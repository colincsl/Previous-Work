/*
 * Force_Rendering.c
 *
 * Real-Time Workshop code generation for Simulink model "Force_Rendering.mdl".
 *
 * Model Version              : 1.35
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Tue Jul 21 13:58:05 2009
 */

#include "Force_Rendering.h"
#include "Force_Rendering_private.h"
#include <stdio.h>
#include "Force_Rendering_dt.h"

/* Block signals (auto storage) */
BlockIO_Force_Rendering Force_Rendering_B;

/* Block states (auto storage) */
D_Work_Force_Rendering Force_Rendering_DWork;

/* Real-time model */
RT_MODEL_Force_Rendering Force_Rendering_M_;
RT_MODEL_Force_Rendering *Force_Rendering_M = &Force_Rendering_M_;

/* Model output function */
void Force_Rendering_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_MathFunction[18];
  real_T rtb_TmpHiddenBufferAtProductInp[6];
  real_T rtb_radiantodegree[3];

  {
    int32_T i;
    real_T tmp[18];
    real_T rtb_Bias1_e_idx;
    real_T rtb_Bias1_e_idx_0;
    real_T rtb_Bias1_e_idx_1;
    real_T tmp_0;

    /* S-Function Block: Force_Rendering/Omni/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result = hil_task_read_encoder
        (Force_Rendering_DWork.HILReadEncoderTimebase_Task, 1,
         &Force_Rendering_DWork.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Force_Rendering_M, _rt_error_message);
      } else {
        rtb_radiantodegree[0] =
          Force_Rendering_DWork.HILReadEncoderTimebase_Buffer[0];
        rtb_radiantodegree[1] =
          Force_Rendering_DWork.HILReadEncoderTimebase_Buffer[1];
        rtb_radiantodegree[2] =
          Force_Rendering_DWork.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* Gain: '<S3>/Gear Ratio' incorporates:
     *  Bias: '<S3>/Bias1'
     *  Gain: '<S3>/Encoder'
     */
    Force_Rendering_B.GearRatio[0] = (rtb_radiantodegree[0] +
      Force_Rendering_P.Bias1_Bias[0]) * Force_Rendering_P.Encoder_Gain *
      Force_Rendering_P.GearRatio_Gain[0];
    Force_Rendering_B.GearRatio[1] = (rtb_radiantodegree[1] +
      Force_Rendering_P.Bias1_Bias[1]) * Force_Rendering_P.Encoder_Gain *
      Force_Rendering_P.GearRatio_Gain[1];
    Force_Rendering_B.GearRatio[2] = (rtb_radiantodegree[2] +
      Force_Rendering_P.Bias1_Bias[2]) * Force_Rendering_P.Encoder_Gain *
      Force_Rendering_P.GearRatio_Gain[2];

    /* Embedded MATLAB: '<S3>/Embedded MATLAB Function' */
    {
      int32_T eml_i0;
      for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
        Force_Rendering_B.q[eml_i0] = Force_Rendering_B.GearRatio[eml_i0];
      }

      Force_Rendering_B.q[0] = Force_Rendering_B.GearRatio[0];
      Force_Rendering_B.q[1] = Force_Rendering_B.GearRatio[1];
      Force_Rendering_B.q[2] = (Force_Rendering_B.GearRatio[2] -
        Force_Rendering_B.GearRatio[1]) - 1.5707963267948966E+000;
    }

    /* Bias: '<S1>/Joint Offsets' incorporates:
     *  Gain: '<S1>/Convert to Positive Rotation Convension Used in Kinematics'
     */
    Force_Rendering_B.JointOffsets[0] =
      Force_Rendering_P.ConverttoPositiveRotationConven[0] *
      Force_Rendering_B.q[0] + Force_Rendering_P.JointOffsets_Bias[0];
    Force_Rendering_B.JointOffsets[1] =
      Force_Rendering_P.ConverttoPositiveRotationConven[1] *
      Force_Rendering_B.q[1] + Force_Rendering_P.JointOffsets_Bias[1];
    Force_Rendering_B.JointOffsets[2] =
      Force_Rendering_P.ConverttoPositiveRotationConven[2] *
      Force_Rendering_B.q[2] + Force_Rendering_P.JointOffsets_Bias[2];
    for (i = 0; i < 16; i++) {
      /* Constant: '<S1>/Tool Offset2' */
      Force_Rendering_B.ToolOffset2[i] = Force_Rendering_P.ToolOffset2_Value[i];
    }

    /* Embedded MATLAB: '<S1>/Forward Kinematics ' */
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
      eml_theta_z = Force_Rendering_B.JointOffsets[0];
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

      eml_theta_z = Force_Rendering_B.JointOffsets[1];
      eml_theta_z_0 = Force_Rendering_B.JointOffsets[2] -
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
          Force_Rendering_B.Rot[eml_i2 + 3 * eml_i0] = eml_T03[eml_i2 + (eml_i0 <<
            2)];
        }
      }

      for (eml_i0 = 0; eml_i0 < 4; eml_i0++) {
        for (eml_i2 = 0; eml_i2 < 4; eml_i2++) {
          eml_dv11[eml_i0 + (eml_i2 << 2)] = 0.0;
          for (eml_i1 = 0; eml_i1 < 4; eml_i1++) {
            eml_dv11[eml_i0 + (eml_i2 << 2)] += eml_T03[eml_i0 + (eml_i1 << 2)] *
              Force_Rendering_B.ToolOffset2[eml_i1 + (eml_i2 << 2)];
          }
        }
      }

      for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
        Force_Rendering_B.pos[eml_i0] = eml_dv11[eml_i0 + 12];

        /* Formulation of the Jacobian */
        /* %%%%%%%%%%%%%%%%%%%%%%%%%%%JACOBIAN%%%%%%%%%%%%%%%%%%%%%%%% */
        eml_b[eml_i0] = Force_Rendering_B.pos[eml_i0] - eml_T02[eml_i0 + 12];
        eml_b_0[eml_i0] = Force_Rendering_B.pos[eml_i0] - eml_A1[eml_i0 + 12];
        eml_b_1[eml_i0] = Force_Rendering_B.pos[eml_i0];
      }

      Force_Rendering_B.Jac[0] = 0.0 * eml_b_1[2] - eml_b_1[1];
      Force_Rendering_B.Jac[1] = eml_b_1[0] - 0.0 * eml_b_1[2];
      Force_Rendering_B.Jac[2] = 0.0 * eml_b_1[1] - 0.0 * eml_b_1[0];
      Force_Rendering_B.Jac[6] = eml_z1[1] * eml_b_0[2] - eml_z1[2] * eml_b_0[1];
      Force_Rendering_B.Jac[7] = eml_z1[2] * eml_b_0[0] - eml_z1[0] * eml_b_0[2];
      Force_Rendering_B.Jac[8] = eml_z1[0] * eml_b_0[1] - eml_z1[1] * eml_b_0[0];
      Force_Rendering_B.Jac[12] = eml_z2[1] * eml_b[2] - eml_z2[2] * eml_b[1];
      Force_Rendering_B.Jac[13] = eml_z2[2] * eml_b[0] - eml_z2[0] * eml_b[2];
      Force_Rendering_B.Jac[14] = eml_z2[0] * eml_b[1] - eml_z2[1] * eml_b[0];
      for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
        Force_Rendering_B.Jac[eml_i0 + 3] = (real_T)eml_bv3[eml_i0];
      }

      for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
        Force_Rendering_B.Jac[eml_i0 + 9] = eml_z1[eml_i0];
      }

      for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
        Force_Rendering_B.Jac[eml_i0 + 15] = eml_z2[eml_i0];
      }
    }

    /* Math: '<S1>/Math Function' */
    for (i = 0; i < 6; i++) {
      tmp[3 * i] = Force_Rendering_B.Jac[i];
      tmp[1 + 3 * i] = Force_Rendering_B.Jac[i + 6];
      tmp[2 + 3 * i] = Force_Rendering_B.Jac[i + 12];
    }

    for (i = 0; i < 18; i++) {
      rtb_MathFunction[i] = tmp[i];
    }

    /* Gain: '<S2>/Slider Gain' incorporates:
     *  Constant: '<Root>/Force'
     */
    rtb_radiantodegree[0] = Force_Rendering_P.SliderGain_Gain *
      Force_Rendering_P.Force_Value[0];
    rtb_radiantodegree[1] = Force_Rendering_P.SliderGain_Gain *
      Force_Rendering_P.Force_Value[1];
    rtb_radiantodegree[2] = Force_Rendering_P.SliderGain_Gain *
      Force_Rendering_P.Force_Value[2];

    /* SignalConversion: '<S1>/TmpHiddenBufferAtProductInport2' incorporates:
     *  Constant: '<S1>/Constant'
     */
    rtb_TmpHiddenBufferAtProductInp[0] = rtb_radiantodegree[0];
    rtb_TmpHiddenBufferAtProductInp[1] = rtb_radiantodegree[1];
    rtb_TmpHiddenBufferAtProductInp[2] = rtb_radiantodegree[2];
    rtb_TmpHiddenBufferAtProductInp[3] = Force_Rendering_P.Constant_Value[0];
    rtb_TmpHiddenBufferAtProductInp[4] = Force_Rendering_P.Constant_Value[1];
    rtb_TmpHiddenBufferAtProductInp[5] = Force_Rendering_P.Constant_Value[2];

    {
      static const int_T dims[3] = { 3, 6, 1 };

      rt_MatMultRR_Dbl(rtb_radiantodegree, rtb_MathFunction,
                       rtb_TmpHiddenBufferAtProductInp, &dims[0]);
    }

    /* Gain: '<S1>/Convert to Positive Rotation Convension Used in Kinematics1' */
    Force_Rendering_B.ConverttoPositiveRotationConven[0] =
      Force_Rendering_P.ConverttoPositiveRotationConv_e[0] * rtb_radiantodegree
      [0];
    Force_Rendering_B.ConverttoPositiveRotationConven[1] =
      Force_Rendering_P.ConverttoPositiveRotationConv_e[1] * rtb_radiantodegree
      [1];
    Force_Rendering_B.ConverttoPositiveRotationConven[2] =
      Force_Rendering_P.ConverttoPositiveRotationConv_e[2] * rtb_radiantodegree
      [2];

    /* Embedded MATLAB: '<S6>/Joint Torque to Motor Torque' */
    {
      int32_T eml_i0;

      /*  Smart Saturation: allows channels to go up to 1.6A  */
      /*  unless the total exceeds 2.2A in which case all channels */
      /*  are scaled so that the cumulative current is equal to 2.2A. */
      for (eml_i0 = 0; eml_i0 < 3; eml_i0++) {
        Force_Rendering_B.y_f[eml_i0] = 0.0;
      }

      Force_Rendering_B.y_f[0] =
        Force_Rendering_B.ConverttoPositiveRotationConven[0];
      Force_Rendering_B.y_f[2] =
        Force_Rendering_B.ConverttoPositiveRotationConven[2];
      Force_Rendering_B.y_f[1] =
        Force_Rendering_B.ConverttoPositiveRotationConven[1] -
        Force_Rendering_B.ConverttoPositiveRotationConven[2];
    }

    /* Gain: '<S6>/Kt' incorporates:
     *  Gain: '<S6>/Gear Ratio1'
     */
    rtb_radiantodegree[0] = Force_Rendering_P.GearRatio1_Gain[0] *
      Force_Rendering_B.y_f[0] * Force_Rendering_P.Kt_Gain;
    rtb_radiantodegree[1] = Force_Rendering_P.GearRatio1_Gain[1] *
      Force_Rendering_B.y_f[1] * Force_Rendering_P.Kt_Gain;
    rtb_radiantodegree[2] = Force_Rendering_P.GearRatio1_Gain[2] *
      Force_Rendering_B.y_f[2] * Force_Rendering_P.Kt_Gain;

    /* Saturate: '<S6>/Saturation' */
    Force_Rendering_B.Saturation[0] = rt_SATURATE(rtb_radiantodegree[0],
      Force_Rendering_P.Saturation_LowerSat,
      Force_Rendering_P.Saturation_UpperSat);
    Force_Rendering_B.Saturation[1] = rt_SATURATE(rtb_radiantodegree[1],
      Force_Rendering_P.Saturation_LowerSat,
      Force_Rendering_P.Saturation_UpperSat);
    Force_Rendering_B.Saturation[2] = rt_SATURATE(rtb_radiantodegree[2],
      Force_Rendering_P.Saturation_LowerSat,
      Force_Rendering_P.Saturation_UpperSat);

    /* Embedded MATLAB: '<S6>/Smart Saturation' */
    {
      int32_T eml_k;
      real_T eml_x[3];
      real_T eml_total;

      /*  Smart Saturation: allows channels to go up to 1.6A  */
      /*  unless the total exceeds 2.2A in which case all channels */
      /*  are scaled so that the cumulative current is equal to 2.2A. */
      /*  Define the maximum cumulative current here */
      for (eml_k = 0; eml_k < 3; eml_k++) {
        eml_x[eml_k] = fabs(Force_Rendering_B.Saturation[eml_k]);
      }

      eml_total = eml_x[0];
      for (eml_k = 2; eml_k < 4; eml_k++) {
        eml_total += eml_x[eml_k - 1];
      }

      if (eml_total > 2.2) {
        eml_total = 2.2 / eml_total;
        for (eml_k = 0; eml_k < 3; eml_k++) {
          Force_Rendering_B.y[eml_k] = eml_total *
            Force_Rendering_B.Saturation[eml_k];
        }
      } else {
        for (eml_k = 0; eml_k < 3; eml_k++) {
          Force_Rendering_B.y[eml_k] = Force_Rendering_B.Saturation[eml_k];
        }
      }
    }

    /* S-Function Block: Force_Rendering/Omni/HIL Write PWM (hil_write_pwm_block) */
    {
      t_error result;
      result = hil_write_pwm(Force_Rendering_DWork.HILInitialize_Card,
        Force_Rendering_P.HILWritePWM_Channels, 3, Force_Rendering_B.y);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Force_Rendering_M, _rt_error_message);
      }
    }

    /* S-Function Block: Force_Rendering/Omni/HIL Read Analog (hil_read_analog_block) */
    {
      t_error result = hil_read_analog(Force_Rendering_DWork.HILInitialize_Card,
        Force_Rendering_P.HILReadAnalog_Channels, 3, rtb_radiantodegree);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Force_Rendering_M, _rt_error_message);
      }
    }

    /* Bias: '<S5>/Bias1' */
    rtb_Bias1_e_idx = rtb_radiantodegree[0] + Force_Rendering_P.Bias1_Bias_k[0];
    rtb_Bias1_e_idx_0 = rtb_radiantodegree[1] + Force_Rendering_P.Bias1_Bias_k[1];
    rtb_Bias1_e_idx_1 = rtb_radiantodegree[2] + Force_Rendering_P.Bias1_Bias_k[2];

    /* Gain: '<Root>/meter to milimeter' */
    rtb_radiantodegree[0] = Force_Rendering_P.metertomilimeter_Gain *
      Force_Rendering_B.pos[0];
    rtb_radiantodegree[1] = Force_Rendering_P.metertomilimeter_Gain *
      Force_Rendering_B.pos[1];
    rtb_radiantodegree[2] = Force_Rendering_P.metertomilimeter_Gain *
      Force_Rendering_B.pos[2];

    /* DataTypeConversion: '<Root>/Rounding' */
    tmp_0 = fmod(floor(rtb_radiantodegree[0]), 4.294967296E+009);
    if (tmp_0 < -2.147483648E+009) {
      tmp_0 += 4.294967296E+009;
    } else if (tmp_0 >= 2.147483648E+009) {
      tmp_0 -= 4.294967296E+009;
    }

    Force_Rendering_B.Rounding[0] = (int32_T)tmp_0;
    tmp_0 = fmod(floor(rtb_radiantodegree[1]), 4.294967296E+009);
    if (tmp_0 < -2.147483648E+009) {
      tmp_0 += 4.294967296E+009;
    } else if (tmp_0 >= 2.147483648E+009) {
      tmp_0 -= 4.294967296E+009;
    }

    Force_Rendering_B.Rounding[1] = (int32_T)tmp_0;
    tmp_0 = fmod(floor(rtb_radiantodegree[2]), 4.294967296E+009);
    if (tmp_0 < -2.147483648E+009) {
      tmp_0 += 4.294967296E+009;
    } else if (tmp_0 >= 2.147483648E+009) {
      tmp_0 -= 4.294967296E+009;
    }

    Force_Rendering_B.Rounding[2] = (int32_T)tmp_0;

    /* Gain: '<Root>/radian to degree1' incorporates:
     *  Bias: '<S1>/Joint Offsets1'
     *  Gain: '<S1>/Convert to Positive Rotation Convension Used in Kinematics2'
     *  Gain: '<S5>/Gain2'
     */
    rtb_radiantodegree[0] = (Force_Rendering_P.Gain2_Gain[0] * rtb_Bias1_e_idx *
      Force_Rendering_P.ConverttoPositiveRotationConv_c[0] +
      Force_Rendering_P.JointOffsets1_Bias[0]) *
      Force_Rendering_P.radiantodegree1_Gain;
    rtb_radiantodegree[1] = (Force_Rendering_P.Gain2_Gain[1] * rtb_Bias1_e_idx_0
      * Force_Rendering_P.ConverttoPositiveRotationConv_c[1] +
      Force_Rendering_P.JointOffsets1_Bias[1]) *
      Force_Rendering_P.radiantodegree1_Gain;
    rtb_radiantodegree[2] = (Force_Rendering_P.Gain2_Gain[2] * rtb_Bias1_e_idx_1
      * Force_Rendering_P.ConverttoPositiveRotationConv_c[2] +
      Force_Rendering_P.JointOffsets1_Bias[2]) *
      Force_Rendering_P.radiantodegree1_Gain;

    /* DataTypeConversion: '<Root>/Rounding2' */
    tmp_0 = fmod(floor(rtb_radiantodegree[0]), 4.294967296E+009);
    if (tmp_0 < -2.147483648E+009) {
      tmp_0 += 4.294967296E+009;
    } else if (tmp_0 >= 2.147483648E+009) {
      tmp_0 -= 4.294967296E+009;
    }

    Force_Rendering_B.Rounding2[0] = (int32_T)tmp_0;
    tmp_0 = fmod(floor(rtb_radiantodegree[1]), 4.294967296E+009);
    if (tmp_0 < -2.147483648E+009) {
      tmp_0 += 4.294967296E+009;
    } else if (tmp_0 >= 2.147483648E+009) {
      tmp_0 -= 4.294967296E+009;
    }

    Force_Rendering_B.Rounding2[1] = (int32_T)tmp_0;
    tmp_0 = fmod(floor(rtb_radiantodegree[2]), 4.294967296E+009);
    if (tmp_0 < -2.147483648E+009) {
      tmp_0 += 4.294967296E+009;
    } else if (tmp_0 >= 2.147483648E+009) {
      tmp_0 -= 4.294967296E+009;
    }

    Force_Rendering_B.Rounding2[2] = (int32_T)tmp_0;

    /* Gain: '<Root>/radian to degree' */
    rtb_radiantodegree[0] = Force_Rendering_P.radiantodegree_Gain *
      Force_Rendering_B.JointOffsets[0];
    rtb_radiantodegree[1] = Force_Rendering_P.radiantodegree_Gain *
      Force_Rendering_B.JointOffsets[1];
    rtb_radiantodegree[2] = Force_Rendering_P.radiantodegree_Gain *
      Force_Rendering_B.JointOffsets[2];

    /* DataTypeConversion: '<Root>/Rounding1' */
    tmp_0 = fmod(floor(rtb_radiantodegree[0]), 4.294967296E+009);
    if (tmp_0 < -2.147483648E+009) {
      tmp_0 += 4.294967296E+009;
    } else if (tmp_0 >= 2.147483648E+009) {
      tmp_0 -= 4.294967296E+009;
    }

    Force_Rendering_B.Rounding1[0] = (int32_T)tmp_0;
    tmp_0 = fmod(floor(rtb_radiantodegree[1]), 4.294967296E+009);
    if (tmp_0 < -2.147483648E+009) {
      tmp_0 += 4.294967296E+009;
    } else if (tmp_0 >= 2.147483648E+009) {
      tmp_0 -= 4.294967296E+009;
    }

    Force_Rendering_B.Rounding1[1] = (int32_T)tmp_0;
    tmp_0 = fmod(floor(rtb_radiantodegree[2]), 4.294967296E+009);
    if (tmp_0 < -2.147483648E+009) {
      tmp_0 += 4.294967296E+009;
    } else if (tmp_0 >= 2.147483648E+009) {
      tmp_0 -= 4.294967296E+009;
    }

    Force_Rendering_B.Rounding1[2] = (int32_T)tmp_0;
  }

  UNUSED_PARAMETER(tid);
}

/* Model update function */
void Force_Rendering_update(int_T tid)
{
  /* Update absolute time for base rate */
  if (!(++Force_Rendering_M->Timing.clockTick0))
    ++Force_Rendering_M->Timing.clockTickH0;
  Force_Rendering_M->Timing.t[0] = Force_Rendering_M->Timing.clockTick0 *
    Force_Rendering_M->Timing.stepSize0 + Force_Rendering_M->Timing.clockTickH0 *
    Force_Rendering_M->Timing.stepSize0 * 4294967296.0;
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void Force_Rendering_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));    /* initialize real-time model */
  (void) memset((char_T *)Force_Rendering_M,0,
                sizeof(RT_MODEL_Force_Rendering));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Force_Rendering_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    Force_Rendering_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Force_Rendering_M->Timing.sampleTimes =
      (&Force_Rendering_M->Timing.sampleTimesArray[0]);
    Force_Rendering_M->Timing.offsetTimes =
      (&Force_Rendering_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Force_Rendering_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    Force_Rendering_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Force_Rendering_M, &Force_Rendering_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Force_Rendering_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Force_Rendering_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Force_Rendering_M, -1);
  Force_Rendering_M->Timing.stepSize0 = 0.001;

  /* external mode info */
  Force_Rendering_M->Sizes.checksums[0] = (4227541037U);
  Force_Rendering_M->Sizes.checksums[1] = (3154054101U);
  Force_Rendering_M->Sizes.checksums[2] = (2402257829U);
  Force_Rendering_M->Sizes.checksums[3] = (3343334248U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    Force_Rendering_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &Force_Rendering_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, Force_Rendering_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(Force_Rendering_M));
  }

  Force_Rendering_M->solverInfoPtr = (&Force_Rendering_M->solverInfo);
  Force_Rendering_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Force_Rendering_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Force_Rendering_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Force_Rendering_M->ModelData.blockIO = ((void *) &Force_Rendering_B);
  (void) memset(((void *) &Force_Rendering_B),0,
                sizeof(BlockIO_Force_Rendering));

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&Force_Rendering_B.GearRatio[0]);
    for (i = 0; i < 28; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    pVoidBlockIORegion = (void *)(&Force_Rendering_B.y[0]);
    for (i = 0; i < 39; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }
  }

  /* parameters */
  Force_Rendering_M->ModelData.defaultParam = ((real_T *) &Force_Rendering_P);

  /* states (dwork) */
  Force_Rendering_M->Work.dwork = ((void *) &Force_Rendering_DWork);
  (void) memset((char_T *) &Force_Rendering_DWork,0,
                sizeof(D_Work_Force_Rendering));

  {
    int_T i;
    real_T *dwork_ptr = (real_T *)
      &Force_Rendering_DWork.HILInitialize_AIMinimums[0];
    for (i = 0; i < 13; i++) {
      dwork_ptr[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    Force_Rendering_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void Force_Rendering_terminate(void)
{
  /* S-Function Block: Force_Rendering/Omni/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    hil_task_stop_all(Force_Rendering_DWork.HILInitialize_Card);
    hil_task_delete_all(Force_Rendering_DWork.HILInitialize_Card);
    is_switching = false;
    if ((Force_Rendering_P.HILInitialize_POTerminate && !is_switching) ||
        (Force_Rendering_P.HILInitialize_POExit && is_switching)) {
      Force_Rendering_DWork.HILInitialize_POValues[0] =
        Force_Rendering_P.HILInitialize_POFinal;
      Force_Rendering_DWork.HILInitialize_POValues[1] =
        Force_Rendering_P.HILInitialize_POFinal;
      Force_Rendering_DWork.HILInitialize_POValues[2] =
        Force_Rendering_P.HILInitialize_POFinal;
      result = hil_write_pwm(Force_Rendering_DWork.HILInitialize_Card,
        &Force_Rendering_P.HILInitialize_POChannels[0], 3U,
        &Force_Rendering_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Force_Rendering_M, _rt_error_message);
      }
    }

    hil_close(Force_Rendering_DWork.HILInitialize_Card);
    Force_Rendering_DWork.HILInitialize_Card = NULL;
  }

  /* External mode */
  rtExtModeShutdown(1);
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Force_Rendering_output(tid);
}

void MdlUpdate(int_T tid)
{
  Force_Rendering_update(tid);
}

void MdlInitializeSizes(void)
{
  Force_Rendering_M->Sizes.numContStates = (0);/* Number of continuous states */
  Force_Rendering_M->Sizes.numY = (0); /* Number of model outputs */
  Force_Rendering_M->Sizes.numU = (0); /* Number of model inputs */
  Force_Rendering_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Force_Rendering_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Force_Rendering_M->Sizes.numBlocks = (41);/* Number of blocks */
  Force_Rendering_M->Sizes.numBlockIO = (14);/* Number of block outputs */
  Force_Rendering_M->Sizes.numBlockPrms = (124);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* Initialize code for chart: '<S3>/Embedded MATLAB Function' */
  Force_Rendering_DWork.is_active_c8_Force_Rendering = 0U;

  /* Initialize code for chart: '<S1>/Forward Kinematics ' */
  Force_Rendering_DWork.is_active_c5_Force_Rendering = 0U;

  /* Initialize code for chart: '<S6>/Joint Torque to Motor Torque' */
  Force_Rendering_DWork.is_active_c4_Force_Rendering = 0U;

  /* Initialize code for chart: '<S6>/Smart Saturation' */
  Force_Rendering_DWork.is_active_c3_Force_Rendering = 0U;
}

void MdlStart(void)
{
  {
    int32_T i;

    /* S-Function Block: Force_Rendering/Omni/HIL Initialize (hil_initialize_block) */
    {
      t_int result;
      t_boolean is_switching;
      result = hil_open("phantom_omni", "0",
                        &Force_Rendering_DWork.HILInitialize_Card);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Force_Rendering_M, _rt_error_message);
        return;
      }

      is_switching = false;
      if ((Force_Rendering_P.HILInitialize_AIPStart && !is_switching) ||
          (Force_Rendering_P.HILInitialize_AIPEnter && is_switching)) {
        Force_Rendering_DWork.HILInitialize_AIMinimums[0] =
          Force_Rendering_P.HILInitialize_AILow;
        Force_Rendering_DWork.HILInitialize_AIMinimums[1] =
          Force_Rendering_P.HILInitialize_AILow;
        Force_Rendering_DWork.HILInitialize_AIMaximums[0] =
          Force_Rendering_P.HILInitialize_AIHigh;
        Force_Rendering_DWork.HILInitialize_AIMaximums[1] =
          Force_Rendering_P.HILInitialize_AIHigh;
        result = hil_set_analog_input_ranges
          (Force_Rendering_DWork.HILInitialize_Card,
           &Force_Rendering_P.HILInitialize_AIChannels[0], 2U,
           &Force_Rendering_DWork.HILInitialize_AIMinimums[0],
           &Force_Rendering_DWork.HILInitialize_AIMaximums[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Force_Rendering_M, _rt_error_message);
          return;
        }
      }

      if ((Force_Rendering_P.HILInitialize_EIStart && !is_switching) ||
          (Force_Rendering_P.HILInitialize_EIEnter && is_switching)) {
        Force_Rendering_DWork.HILInitialize_InitialEICounts[0] =
          Force_Rendering_P.HILInitialize_EIInitial;
        Force_Rendering_DWork.HILInitialize_InitialEICounts[1] =
          Force_Rendering_P.HILInitialize_EIInitial;
        Force_Rendering_DWork.HILInitialize_InitialEICounts[2] =
          Force_Rendering_P.HILInitialize_EIInitial;
        result = hil_set_encoder_counts(Force_Rendering_DWork.HILInitialize_Card,
          &Force_Rendering_P.HILInitialize_EIChannels[0], 3U,
          &Force_Rendering_DWork.HILInitialize_InitialEICounts[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Force_Rendering_M, _rt_error_message);
          return;
        }
      }

      if ((Force_Rendering_P.HILInitialize_POStart && !is_switching) ||
          (Force_Rendering_P.HILInitialize_POEnter && is_switching)) {
        Force_Rendering_DWork.HILInitialize_POValues[0] =
          Force_Rendering_P.HILInitialize_POInitial;
        Force_Rendering_DWork.HILInitialize_POValues[1] =
          Force_Rendering_P.HILInitialize_POInitial;
        Force_Rendering_DWork.HILInitialize_POValues[2] =
          Force_Rendering_P.HILInitialize_POInitial;
        result = hil_write_pwm(Force_Rendering_DWork.HILInitialize_Card,
          &Force_Rendering_P.HILInitialize_POChannels[0], 3U,
          &Force_Rendering_DWork.HILInitialize_POValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Force_Rendering_M, _rt_error_message);
          return;
        }
      }

      if (Force_Rendering_P.HILInitialize_POReset) {
        Force_Rendering_DWork.HILInitialize_POValues[0] =
          Force_Rendering_P.HILInitialize_POWatchdog;
        Force_Rendering_DWork.HILInitialize_POValues[1] =
          Force_Rendering_P.HILInitialize_POWatchdog;
        Force_Rendering_DWork.HILInitialize_POValues[2] =
          Force_Rendering_P.HILInitialize_POWatchdog;
        result = hil_watchdog_set_pwm_expiration_state
          (Force_Rendering_DWork.HILInitialize_Card,
           &Force_Rendering_P.HILInitialize_POChannels[0], 3U,
           &Force_Rendering_DWork.HILInitialize_POValues[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Force_Rendering_M, _rt_error_message);
          return;
        }
      }
    }

    /* S-Function Block: Force_Rendering/Omni/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_create_encoder_reader
        (Force_Rendering_DWork.HILInitialize_Card,
         Force_Rendering_P.HILReadEncoderTimebase_SamplesI,
         Force_Rendering_P.HILReadEncoderTimebase_Channels, 3,
         &Force_Rendering_DWork.HILReadEncoderTimebase_Task);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Force_Rendering_M, _rt_error_message);
      }
    }

    for (i = 0; i < 16; i++) {
      /* Start for Constant: '<S1>/Tool Offset2' */
      Force_Rendering_B.ToolOffset2[i] = Force_Rendering_P.ToolOffset2_Value[i];
    }
  }

  MdlInitialize();
}

RT_MODEL_Force_Rendering *Force_Rendering(void)
{
  Force_Rendering_initialize(1);
  return Force_Rendering_M;
}

void MdlTerminate(void)
{
  Force_Rendering_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
