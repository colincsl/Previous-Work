/*
 * vmrl_test_fourbar.c
 *
 * Real-Time Workshop code generation for Simulink model "vmrl_test_fourbar.mdl".
 *
 * Model Version              : 1.21
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Tue Jan 12 17:03:46 2010
 */

#include "vmrl_test_fourbar.h"
#include "vmrl_test_fourbar_private.h"
#include <stdio.h>
#include "vmrl_test_fourbar_dt.h"

/* Block signals (auto storage) */
BlockIO_vmrl_test_fourbar vmrl_test_fourbar_B;

/* Continuous states */
ContinuousStates_vmrl_test_fourbar vmrl_test_fourbar_X;

/* Block states (auto storage) */
D_Work_vmrl_test_fourbar vmrl_test_fourbar_DWork;

/* Real-time model */
RT_MODEL_vmrl_test_fourbar vmrl_test_fourbar_M_;
RT_MODEL_vmrl_test_fourbar *vmrl_test_fourbar_M = &vmrl_test_fourbar_M_;

/* Projection for root system: '<Root>' */
void vmrl_test_fourbar_projection(void)
{
  /* S-Function Block: <S15>/Block#1 */
  {
    _rtMech_PWORK *mechWork = (_rtMech_PWORK *)
      vmrl_test_fourbar_DWork.Block1_PWORK;
    mechWork->genSimData.time = vmrl_test_fourbar_M->Timing.t[0];
    if (sFcnProjectionMethod(mechWork->mechanism,&(mechWork->genSimData))) {
      {
        const ErrorRecord *err = getErrorMsg();
        static char_T errorMsg[1024];
        sprintf(errorMsg,
                err->errorMsg,
                err->blocks[0],
                err->blocks[1],
                err->blocks[2],
                err->blocks[3],
                err->blocks[4]);
        rtmSetErrorStatus(vmrl_test_fourbar_M, errorMsg);
        return;
      }
    }
  }
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
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  vmrl_test_fourbar_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  vmrl_test_fourbar_output(0);
  vmrl_test_fourbar_projection();
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Start for action system:
 *   '<S9>/Phi == pi'
 *   '<S10>/Phi == pi'
 *   '<S11>/Phi == pi'
 *   '<S12>/Phi == pi'
 *   '<S13>/Phi == pi'
 *   '<S14>/Phi == pi'
 */
void vmrl_test_fourbar_Phipi_Start(real_T *rty_0, real_T rty_1[3],
  rtP_Phipi_vmrl_test_fourbar *localP)
{
  /* VirtualOutportStart for Outport: '<S22>/VRRot_Pi' */
  rty_1[0] = localP->VRRot_Pi_Y0[0];
  rty_1[1] = localP->VRRot_Pi_Y0[1];
  rty_1[2] = localP->VRRot_Pi_Y0[2];
  (*rty_0) = localP->VRRot_Pi_Y0[3];
}

/* Output and update for action system:
 *   '<S9>/Phi == pi'
 *   '<S10>/Phi == pi'
 *   '<S11>/Phi == pi'
 *   '<S12>/Phi == pi'
 *   '<S13>/Phi == pi'
 *   '<S14>/Phi == pi'
 */
void vmrl_test_fourbar_Phipi(real_T rtu_0, real_T rtu_1, real_T rtu_2, real_T
  rtu_3, real_T rtu_4, real_T rtu_5, real_T *rty_0, real_T rty_1[3],
  RT_MODEL_vmrl_test_fourbar *vmrl_test_fourbar_M, rtDW_Phipi_vmrl_test_fourbar *
  localDW, rtP_Phipi_vmrl_test_fourbar *localP)
{
  /* local block i/o variables */
  real_T rtb_Shiftright[3];
  real_T rtb_Switch[3];
  boolean_T rtb_Compare[3];

  {
    real_T rtb_Switch_n_idx;
    real_T rtb_Switch_n_idx_0;
    real_T rtb_Switch_n_idx_1;
    real_T rtb_Sign1_idx;
    real_T rtb_Sign1_idx_0;
    real_T rtb_Sign1_idx_1;

    /* Gain: '<S22>/Gain' incorporates:
     *  Constant: '<S22>/Constant'
     *  Sum: '<S22>/Sum'
     */
    rtb_Switch_n_idx = (localP->Constant_Value + rtu_0) * localP->Gain_Gain;
    rtb_Switch_n_idx_0 = (localP->Constant_Value + rtu_1) * localP->Gain_Gain;
    rtb_Switch_n_idx_1 = (localP->Constant_Value + rtu_2) * localP->Gain_Gain;

    /* DeadZone: '<S23>/Dead Zone' */
    if (rtu_3 >= localP->DeadZone_End) {
      rtb_Switch[0] = rtu_3 - localP->DeadZone_End;
    } else if (rtu_3 > localP->DeadZone_Start) {
      rtb_Switch[0] = 0.0;
    } else {
      rtb_Switch[0] = rtu_3 - localP->DeadZone_Start;
    }

    if (rtu_4 >= localP->DeadZone_End) {
      rtb_Switch[1] = rtu_4 - localP->DeadZone_End;
    } else if (rtu_4 > localP->DeadZone_Start) {
      rtb_Switch[1] = 0.0;
    } else {
      rtb_Switch[1] = rtu_4 - localP->DeadZone_Start;
    }

    if (rtu_5 >= localP->DeadZone_End) {
      rtb_Switch[2] = rtu_5 - localP->DeadZone_End;
    } else if (rtu_5 > localP->DeadZone_Start) {
      rtb_Switch[2] = 0.0;
    } else {
      rtb_Switch[2] = rtu_5 - localP->DeadZone_Start;
    }

    /* Signum: '<S23>/Sign1' */
    rtb_Sign1_idx = rt_SGN(rtb_Switch[0]);
    rtb_Sign1_idx_0 = rt_SGN(rtb_Switch[1]);
    rtb_Sign1_idx_1 = rt_SGN(rtb_Switch[2]);

    /* Switch: '<S23>/Switch' incorporates:
     *  Constant: '<S23>/Pi1'
     *  Sum: '<S23>/Sum of Elements3'
     */
    if ((rtb_Sign1_idx + rtb_Sign1_idx_0) + rtb_Sign1_idx_1 >=
        localP->Switch_Threshold) {
      rtb_Switch[0] = localP->Pi1_Value[0];
      rtb_Switch[1] = localP->Pi1_Value[1];
      rtb_Switch[2] = localP->Pi1_Value[2];
    } else {
      /* Switch: '<S23>/Switch1' incorporates:
       *  Gain: '<S23>/Gain1'
       *  Product: '<S23>/Product of Elements'
       */
      if (rtb_Sign1_idx * rtb_Sign1_idx_0 * rtb_Sign1_idx_1 != 0.0) {
        rtb_Sign1_idx *= localP->Gain1_Gain;
        rtb_Sign1_idx_0 *= localP->Gain1_Gain;
        rtb_Sign1_idx_1 *= localP->Gain1_Gain;
      } else {
        /* RelationalOperator: '<S24>/Compare' */
        rtb_Compare[0] = (rtb_Sign1_idx != 0.0);
        rtb_Compare[1] = (rtb_Sign1_idx_0 != 0.0);
        rtb_Compare[2] = (rtb_Sign1_idx_1 != 0.0);

        /* CombinatorialLogic: '<S23>/Shift right' */
        {
          int_T rowidx= 0;

          /* Compute the truth table row index corresponding to the input */
          rowidx = (rowidx << 1) + (int_T)(rtb_Compare[0] != 0);
          rowidx = (rowidx << 1) + (int_T)(rtb_Compare[1] != 0);
          rowidx = (rowidx << 1) + (int_T)(rtb_Compare[2] != 0);

          /* Copy the appropriate row of the table into the block output vector */
          rtb_Shiftright[0] = localP->Shiftright_table[rowidx];
          rtb_Shiftright[1] = localP->Shiftright_table[rowidx + 8];
          rtb_Shiftright[2] = localP->Shiftright_table[rowidx + 16];
        }

        rtb_Sign1_idx = rtb_Shiftright[0];
        rtb_Sign1_idx_0 = rtb_Shiftright[1];
        rtb_Sign1_idx_1 = rtb_Shiftright[2];
      }

      rtb_Switch[0] = rtb_Sign1_idx;
      rtb_Switch[1] = rtb_Sign1_idx_0;
      rtb_Switch[2] = rtb_Sign1_idx_1;
    }

    /* MinMax: '<S22>/MinMax' */
    rtb_Sign1_idx = rt_MAX(rtb_Switch_n_idx, 0.0);
    rtb_Sign1_idx_0 = rt_MAX(rtb_Switch_n_idx_0, 0.0);
    rtb_Sign1_idx_1 = rt_MAX(rtb_Switch_n_idx_1, 0.0);

    /* Math: '<S22>/Math Function' */
    if (rtb_Sign1_idx < 0.0) {
      rtb_Switch_n_idx = -sqrt(-rtb_Sign1_idx);
    } else {
      rtb_Switch_n_idx = sqrt(rtb_Sign1_idx);
    }

    if (rtb_Sign1_idx_0 < 0.0) {
      rtb_Switch_n_idx_0 = -sqrt(-rtb_Sign1_idx_0);
    } else {
      rtb_Switch_n_idx_0 = sqrt(rtb_Sign1_idx_0);
    }

    if (rtb_Sign1_idx_1 < 0.0) {
      rtb_Switch_n_idx_1 = -sqrt(-rtb_Sign1_idx_1);
    } else {
      rtb_Switch_n_idx_1 = sqrt(rtb_Sign1_idx_1);
    }

    if (rtmIsMajorTimeStep(vmrl_test_fourbar_M) &&
        vmrl_test_fourbar_M->Timing.TaskCounters.TID[1] == 0) {
      /* Constant: '<S22>/Pi' */
      (*rty_0) = localP->Pi_Value;
    }

    /* Switch: '<S22>/Switch' */
    if (!(rtb_Switch_n_idx > localP->Switch_Threshold_h)) {
      rtb_Switch_n_idx = 0.0;
    }

    if (!(rtb_Switch_n_idx_0 > localP->Switch_Threshold_h)) {
      rtb_Switch_n_idx_0 = 0.0;
    }

    if (!(rtb_Switch_n_idx_1 > localP->Switch_Threshold_h)) {
      rtb_Switch_n_idx_1 = 0.0;
    }

    /* Product: '<S22>/Product' */
    rty_1[0] = rtb_Switch_n_idx * rtb_Switch[0];
    rty_1[1] = rtb_Switch_n_idx_0 * rtb_Switch[1];
    rty_1[2] = rtb_Switch_n_idx_1 * rtb_Switch[2];
  }

  if (rtmIsMajorTimeStep(vmrl_test_fourbar_M)) {
    srUpdateBC(localDW->Phipi_SubsysRanBC);
  }
}

/* Output and update for action system:
 *   '<S9>/General case'
 *   '<S10>/General case'
 *   '<S11>/General case'
 *   '<S12>/General case'
 *   '<S13>/General case'
 *   '<S14>/General case'
 */
void vmrl_test_fourbar_Generalcase(real_T rtu_Traceu, const real_T rtu_1[2],
  real_T rtu_2, real_T rtu_3, const real_T rtu_4[2], real_T *rty_0, real_T
  rty_1[3], RT_MODEL_vmrl_test_fourbar *vmrl_test_fourbar_M,
  rtDW_Generalcase_vmrl_test_four *localDW, rtP_Generalcase_vmrl_test_fourb
  *localP)
{
  /* local block i/o variables */
  real_T rtb_Gain1_j;

  /* Gain: '<S20>/Gain1' incorporates:
   *  Constant: '<S20>/Constant'
   *  Sum: '<S20>/Subtract'
   */
  rtb_Gain1_j = (rtu_Traceu - localP->Constant_Value) * localP->Gain1_Gain;

  /* Trigonometry: '<S20>/Trigonometric Function1' */
  rtb_Gain1_j = acos(rt_SATURATE(rtb_Gain1_j, -1.0, 1.0));

  /* DataTypeConversion: '<S20>/Data Type Conversion' */
  (*rty_0) = rtb_Gain1_j;

  /* Gain: '<S20>/Gain' incorporates:
   *  Trigonometry: '<S20>/Trigonometric Function'
   */
  rtb_Gain1_j = localP->Gain_Gain * sin(rtb_Gain1_j);

  /* Product: '<S20>/Divide' incorporates:
   *  Sum: '<S20>/Sum'
   */
  rty_1[0] = (rtu_1[0] - rtu_3) / rtb_Gain1_j;
  rty_1[1] = (rtu_1[1] - rtu_4[0]) / rtb_Gain1_j;
  rty_1[2] = (rtu_2 - rtu_4[1]) / rtb_Gain1_j;
  if (rtmIsMajorTimeStep(vmrl_test_fourbar_M)) {
    srUpdateBC(localDW->Generalcase_SubsysRanBC);
  }
}

/* Model output function */
void vmrl_test_fourbar_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_gain_2[9];
  real_T rtb_SumofElements3;
  real_T rtb_gain_2_d[9];
  real_T rtb_SumofElements3_k;
  real_T rtb_gain_2_g[9];
  real_T rtb_SumofElements3_e;
  real_T rtb_gain_2_e[9];
  real_T rtb_SumofElements3_a;
  real_T rtb_SumofElements3_m;
  real_T rtb_gain_2_n[9];
  real_T rtb_SumofElements3_i;

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(vmrl_test_fourbar_M)) {
    vmrl_test_fourbar_M->Timing.t[0] = rtsiGetT(&vmrl_test_fourbar_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(vmrl_test_fourbar_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&vmrl_test_fourbar_M->solverInfo,
                          ((vmrl_test_fourbar_M->Timing.clockTick0+1)*
      vmrl_test_fourbar_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Reset subsysRan breadcrumbs */
  srClearBC(vmrl_test_fourbar_DWork.Generalcase.Generalcase_SubsysRanBC);
  srClearBC(vmrl_test_fourbar_DWork.Phi0_SubsysRanBC);
  srClearBC(vmrl_test_fourbar_DWork.Phipi.Phipi_SubsysRanBC);
  srClearBC(vmrl_test_fourbar_DWork.Generalcase_c.Generalcase_SubsysRanBC);
  srClearBC(vmrl_test_fourbar_DWork.Phi0_SubsysRanBC_b);
  srClearBC(vmrl_test_fourbar_DWork.Phipi_m.Phipi_SubsysRanBC);
  srClearBC(vmrl_test_fourbar_DWork.Generalcase_g.Generalcase_SubsysRanBC);
  srClearBC(vmrl_test_fourbar_DWork.Phi0_SubsysRanBC_n);
  srClearBC(vmrl_test_fourbar_DWork.Phipi_e.Phipi_SubsysRanBC);
  srClearBC(vmrl_test_fourbar_DWork.Generalcase_k.Generalcase_SubsysRanBC);
  srClearBC(vmrl_test_fourbar_DWork.Phi0_SubsysRanBC_g);
  srClearBC(vmrl_test_fourbar_DWork.Phipi_g.Phipi_SubsysRanBC);
  srClearBC(vmrl_test_fourbar_DWork.Generalcase_l.Generalcase_SubsysRanBC);
  srClearBC(vmrl_test_fourbar_DWork.Phi0_SubsysRanBC_l);
  srClearBC(vmrl_test_fourbar_DWork.Phipi_j.Phipi_SubsysRanBC);
  srClearBC(vmrl_test_fourbar_DWork.Generalcase_b.Generalcase_SubsysRanBC);
  srClearBC(vmrl_test_fourbar_DWork.Phi0_SubsysRanBC_d);
  srClearBC(vmrl_test_fourbar_DWork.Phipi_n.Phipi_SubsysRanBC);

  {
    int8_T rtAction;
    int32_T i;

    /* S-Function Block: <S15>/Block#1 */
    {
      _rtMech_PWORK *mechWork = (_rtMech_PWORK *)
        vmrl_test_fourbar_DWork.Block1_PWORK;
      mechWork->genSimData.time = vmrl_test_fourbar_M->Timing.t[0];
      mechWork->outSimData.majorTimestep = rtmIsMajorTimeStep
        (vmrl_test_fourbar_M);
      if (kinematicSfcnOutputMethod(mechWork->mechanism, &(mechWork->genSimData),
           &(mechWork->outSimData))) {
        {
          const ErrorRecord *err = getErrorMsg();
          static char_T errorMsg[1024];
          sprintf(errorMsg,
                  err->errorMsg,
                  err->blocks[0],
                  err->blocks[1],
                  err->blocks[2],
                  err->blocks[3],
                  err->blocks[4]);
          rtmSetErrorStatus(vmrl_test_fourbar_M, errorMsg);
          return;
        }
      }
    }

    for (i = 0; i < 9; i++) {
      /* Gain: '<S1>/gain_2' */
      rtb_gain_2[i] = vmrl_test_fourbar_B.Block1_o1[i + 27] *
        vmrl_test_fourbar_P.gain_2_Gain;
    }

    /* Sum: '<S9>/Sum of Elements3' */
    rtb_SumofElements3 = (rtb_gain_2[0] + rtb_gain_2[4]) + rtb_gain_2[8];

    /* If: '<S9>/If' incorporates:
     *  Abs: '<S9>/Abs'
     *  Constant: '<S9>/Constant'
     *  Sum: '<S9>/Sum'
     */
    if (rtmIsMajorTimeStep(vmrl_test_fourbar_M) != 0) {
      if (rtb_SumofElements3 == 3.0) {
        rtAction = 0;
      } else if (fabs(rtb_SumofElements3 + vmrl_test_fourbar_P.Constant_Value) <=
                 1.0E-012) {
        rtAction = 1;
      } else {
        rtAction = 2;
      }

      vmrl_test_fourbar_DWork.If_ActiveSubsystem = rtAction;
    } else {
      rtAction = vmrl_test_fourbar_DWork.If_ActiveSubsystem;
    }

    switch (rtAction) {
     case 0:
      if (rtmIsMajorTimeStep(vmrl_test_fourbar_M) &&
          vmrl_test_fourbar_M->Timing.TaskCounters.TID[1] == 0) {
        /* Constant: '<S21>/Trace=3=>Phi=0' */
        vmrl_test_fourbar_B.Merge[0] = vmrl_test_fourbar_P.Trace3Phi0_Value[0];
        vmrl_test_fourbar_B.Merge[1] = vmrl_test_fourbar_P.Trace3Phi0_Value[1];
        vmrl_test_fourbar_B.Merge[2] = vmrl_test_fourbar_P.Trace3Phi0_Value[2];
        vmrl_test_fourbar_B.Merge[3] = vmrl_test_fourbar_P.Trace3Phi0_Value[3];
      }

      if (rtmIsMajorTimeStep(vmrl_test_fourbar_M)) {
        srUpdateBC(vmrl_test_fourbar_DWork.Phi0_SubsysRanBC);
      }
      break;

     case 1:
      vmrl_test_fourbar_Phipi(rtb_gain_2[0], rtb_gain_2[4], rtb_gain_2[8],
        rtb_gain_2[7], rtb_gain_2[6], rtb_gain_2[3], &vmrl_test_fourbar_B.Merge
        [3], vmrl_test_fourbar_B.Merge, vmrl_test_fourbar_M,
        &vmrl_test_fourbar_DWork.Phipi, (rtP_Phipi_vmrl_test_fourbar *)
        &vmrl_test_fourbar_P.Phipi);
      if (rtmIsMajorTimeStep(vmrl_test_fourbar_M)) {
        srUpdateBC(vmrl_test_fourbar_DWork.Phipi.Phipi_SubsysRanBC);
      }
      break;

     case 2:
      vmrl_test_fourbar_Generalcase(rtb_SumofElements3, &rtb_gain_2[5],
        rtb_gain_2[1], rtb_gain_2[7], &rtb_gain_2[2],
        &vmrl_test_fourbar_B.Merge[3], vmrl_test_fourbar_B.Merge,
        vmrl_test_fourbar_M, &vmrl_test_fourbar_DWork.Generalcase,
        (rtP_Generalcase_vmrl_test_fourb *) &vmrl_test_fourbar_P.Generalcase);
      if (rtmIsMajorTimeStep(vmrl_test_fourbar_M)) {
        srUpdateBC(vmrl_test_fourbar_DWork.Generalcase.Generalcase_SubsysRanBC);
      }
      break;
    }

    /* Gain: '<S1>/gain_1' */
    vmrl_test_fourbar_B.gain_1[0] = vmrl_test_fourbar_P.gain_1_Gain *
      vmrl_test_fourbar_B.Block1_o1[24];
    vmrl_test_fourbar_B.gain_1[1] = vmrl_test_fourbar_P.gain_1_Gain *
      vmrl_test_fourbar_B.Block1_o1[25];
    vmrl_test_fourbar_B.gain_1[2] = vmrl_test_fourbar_P.gain_1_Gain *
      vmrl_test_fourbar_B.Block1_o1[26];
    for (i = 0; i < 9; i++) {
      /* Gain: '<S5>/gain_2' */
      rtb_gain_2_d[i] = vmrl_test_fourbar_B.Block1_o1[i + 51] *
        vmrl_test_fourbar_P.gain_2_Gain_n;
    }

    /* Sum: '<S10>/Sum of Elements3' */
    rtb_SumofElements3_k = (rtb_gain_2_d[0] + rtb_gain_2_d[4]) + rtb_gain_2_d[8];

    /* If: '<S10>/If' incorporates:
     *  Abs: '<S10>/Abs'
     *  Constant: '<S10>/Constant'
     *  Sum: '<S10>/Sum'
     */
    if (rtmIsMajorTimeStep(vmrl_test_fourbar_M) != 0) {
      if (rtb_SumofElements3_k == 3.0) {
        rtAction = 0;
      } else if (fabs(rtb_SumofElements3_k +
                      vmrl_test_fourbar_P.Constant_Value_l) <= 1.0E-012) {
        rtAction = 1;
      } else {
        rtAction = 2;
      }

      vmrl_test_fourbar_DWork.If_ActiveSubsystem_l = rtAction;
    } else {
      rtAction = vmrl_test_fourbar_DWork.If_ActiveSubsystem_l;
    }

    switch (rtAction) {
     case 0:
      if (rtmIsMajorTimeStep(vmrl_test_fourbar_M) &&
          vmrl_test_fourbar_M->Timing.TaskCounters.TID[1] == 0) {
        /* Constant: '<S26>/Trace=3=>Phi=0' */
        vmrl_test_fourbar_B.Merge_d[0] = vmrl_test_fourbar_P.Trace3Phi0_Value_h
          [0];
        vmrl_test_fourbar_B.Merge_d[1] = vmrl_test_fourbar_P.Trace3Phi0_Value_h
          [1];
        vmrl_test_fourbar_B.Merge_d[2] = vmrl_test_fourbar_P.Trace3Phi0_Value_h
          [2];
        vmrl_test_fourbar_B.Merge_d[3] = vmrl_test_fourbar_P.Trace3Phi0_Value_h
          [3];
      }

      if (rtmIsMajorTimeStep(vmrl_test_fourbar_M)) {
        srUpdateBC(vmrl_test_fourbar_DWork.Phi0_SubsysRanBC_b);
      }
      break;

     case 1:
      vmrl_test_fourbar_Phipi(rtb_gain_2_d[0], rtb_gain_2_d[4], rtb_gain_2_d[8],
        rtb_gain_2_d[7], rtb_gain_2_d[6], rtb_gain_2_d[3],
        &vmrl_test_fourbar_B.Merge_d[3], vmrl_test_fourbar_B.Merge_d,
        vmrl_test_fourbar_M, &vmrl_test_fourbar_DWork.Phipi_m,
        (rtP_Phipi_vmrl_test_fourbar *) &vmrl_test_fourbar_P.Phipi_m);
      if (rtmIsMajorTimeStep(vmrl_test_fourbar_M)) {
        srUpdateBC(vmrl_test_fourbar_DWork.Phipi_m.Phipi_SubsysRanBC);
      }
      break;

     case 2:
      vmrl_test_fourbar_Generalcase(rtb_SumofElements3_k, &rtb_gain_2_d[5],
        rtb_gain_2_d[1], rtb_gain_2_d[7], &rtb_gain_2_d[2],
        &vmrl_test_fourbar_B.Merge_d[3], vmrl_test_fourbar_B.Merge_d,
        vmrl_test_fourbar_M, &vmrl_test_fourbar_DWork.Generalcase_c,
        (rtP_Generalcase_vmrl_test_fourb *) &vmrl_test_fourbar_P.Generalcase_c);
      if (rtmIsMajorTimeStep(vmrl_test_fourbar_M)) {
        srUpdateBC(vmrl_test_fourbar_DWork.Generalcase_c.Generalcase_SubsysRanBC);
      }
      break;
    }

    /* Gain: '<S5>/gain_1' */
    vmrl_test_fourbar_B.gain_1_i[0] = vmrl_test_fourbar_P.gain_1_Gain_m *
      vmrl_test_fourbar_B.Block1_o1[48];
    vmrl_test_fourbar_B.gain_1_i[1] = vmrl_test_fourbar_P.gain_1_Gain_m *
      vmrl_test_fourbar_B.Block1_o1[49];
    vmrl_test_fourbar_B.gain_1_i[2] = vmrl_test_fourbar_P.gain_1_Gain_m *
      vmrl_test_fourbar_B.Block1_o1[50];
    for (i = 0; i < 9; i++) {
      /* Gain: '<S3>/gain_2' */
      rtb_gain_2_g[i] = vmrl_test_fourbar_B.Block1_o1[i + 3] *
        vmrl_test_fourbar_P.gain_2_Gain_n0;
    }

    /* Sum: '<S11>/Sum of Elements3' */
    rtb_SumofElements3_e = (rtb_gain_2_g[0] + rtb_gain_2_g[4]) + rtb_gain_2_g[8];

    /* If: '<S11>/If' incorporates:
     *  Abs: '<S11>/Abs'
     *  Constant: '<S11>/Constant'
     *  Sum: '<S11>/Sum'
     */
    if (rtmIsMajorTimeStep(vmrl_test_fourbar_M) != 0) {
      if (rtb_SumofElements3_e == 3.0) {
        rtAction = 0;
      } else if (fabs(rtb_SumofElements3_e +
                      vmrl_test_fourbar_P.Constant_Value_e) <= 1.0E-012) {
        rtAction = 1;
      } else {
        rtAction = 2;
      }

      vmrl_test_fourbar_DWork.If_ActiveSubsystem_i = rtAction;
    } else {
      rtAction = vmrl_test_fourbar_DWork.If_ActiveSubsystem_i;
    }

    switch (rtAction) {
     case 0:
      if (rtmIsMajorTimeStep(vmrl_test_fourbar_M) &&
          vmrl_test_fourbar_M->Timing.TaskCounters.TID[1] == 0) {
        /* Constant: '<S31>/Trace=3=>Phi=0' */
        vmrl_test_fourbar_B.Merge_m[0] = vmrl_test_fourbar_P.Trace3Phi0_Value_i
          [0];
        vmrl_test_fourbar_B.Merge_m[1] = vmrl_test_fourbar_P.Trace3Phi0_Value_i
          [1];
        vmrl_test_fourbar_B.Merge_m[2] = vmrl_test_fourbar_P.Trace3Phi0_Value_i
          [2];
        vmrl_test_fourbar_B.Merge_m[3] = vmrl_test_fourbar_P.Trace3Phi0_Value_i
          [3];
      }

      if (rtmIsMajorTimeStep(vmrl_test_fourbar_M)) {
        srUpdateBC(vmrl_test_fourbar_DWork.Phi0_SubsysRanBC_n);
      }
      break;

     case 1:
      vmrl_test_fourbar_Phipi(rtb_gain_2_g[0], rtb_gain_2_g[4], rtb_gain_2_g[8],
        rtb_gain_2_g[7], rtb_gain_2_g[6], rtb_gain_2_g[3],
        &vmrl_test_fourbar_B.Merge_m[3], vmrl_test_fourbar_B.Merge_m,
        vmrl_test_fourbar_M, &vmrl_test_fourbar_DWork.Phipi_e,
        (rtP_Phipi_vmrl_test_fourbar *) &vmrl_test_fourbar_P.Phipi_e);
      if (rtmIsMajorTimeStep(vmrl_test_fourbar_M)) {
        srUpdateBC(vmrl_test_fourbar_DWork.Phipi_e.Phipi_SubsysRanBC);
      }
      break;

     case 2:
      vmrl_test_fourbar_Generalcase(rtb_SumofElements3_e, &rtb_gain_2_g[5],
        rtb_gain_2_g[1], rtb_gain_2_g[7], &rtb_gain_2_g[2],
        &vmrl_test_fourbar_B.Merge_m[3], vmrl_test_fourbar_B.Merge_m,
        vmrl_test_fourbar_M, &vmrl_test_fourbar_DWork.Generalcase_g,
        (rtP_Generalcase_vmrl_test_fourb *) &vmrl_test_fourbar_P.Generalcase_g);
      if (rtmIsMajorTimeStep(vmrl_test_fourbar_M)) {
        srUpdateBC(vmrl_test_fourbar_DWork.Generalcase_g.Generalcase_SubsysRanBC);
      }
      break;
    }

    /* Gain: '<S3>/gain_1' */
    vmrl_test_fourbar_B.gain_1_b[0] = vmrl_test_fourbar_P.gain_1_Gain_p *
      vmrl_test_fourbar_B.Block1_o1[0];
    vmrl_test_fourbar_B.gain_1_b[1] = vmrl_test_fourbar_P.gain_1_Gain_p *
      vmrl_test_fourbar_B.Block1_o1[1];
    vmrl_test_fourbar_B.gain_1_b[2] = vmrl_test_fourbar_P.gain_1_Gain_p *
      vmrl_test_fourbar_B.Block1_o1[2];
    for (i = 0; i < 9; i++) {
      /* Gain: '<S4>/gain_2' */
      rtb_gain_2_e[i] = vmrl_test_fourbar_B.Block1_o1[i + 39] *
        vmrl_test_fourbar_P.gain_2_Gain_o;
    }

    /* Sum: '<S12>/Sum of Elements3' */
    rtb_SumofElements3_a = (rtb_gain_2_e[0] + rtb_gain_2_e[4]) + rtb_gain_2_e[8];

    /* If: '<S12>/If' incorporates:
     *  Abs: '<S12>/Abs'
     *  Constant: '<S12>/Constant'
     *  Sum: '<S12>/Sum'
     */
    if (rtmIsMajorTimeStep(vmrl_test_fourbar_M) != 0) {
      if (rtb_SumofElements3_a == 3.0) {
        rtAction = 0;
      } else if (fabs(rtb_SumofElements3_a +
                      vmrl_test_fourbar_P.Constant_Value_a) <= 1.0E-012) {
        rtAction = 1;
      } else {
        rtAction = 2;
      }

      vmrl_test_fourbar_DWork.If_ActiveSubsystem_c = rtAction;
    } else {
      rtAction = vmrl_test_fourbar_DWork.If_ActiveSubsystem_c;
    }

    switch (rtAction) {
     case 0:
      if (rtmIsMajorTimeStep(vmrl_test_fourbar_M) &&
          vmrl_test_fourbar_M->Timing.TaskCounters.TID[1] == 0) {
        /* Constant: '<S36>/Trace=3=>Phi=0' */
        vmrl_test_fourbar_B.Merge_g[0] = vmrl_test_fourbar_P.Trace3Phi0_Value_b
          [0];
        vmrl_test_fourbar_B.Merge_g[1] = vmrl_test_fourbar_P.Trace3Phi0_Value_b
          [1];
        vmrl_test_fourbar_B.Merge_g[2] = vmrl_test_fourbar_P.Trace3Phi0_Value_b
          [2];
        vmrl_test_fourbar_B.Merge_g[3] = vmrl_test_fourbar_P.Trace3Phi0_Value_b
          [3];
      }

      if (rtmIsMajorTimeStep(vmrl_test_fourbar_M)) {
        srUpdateBC(vmrl_test_fourbar_DWork.Phi0_SubsysRanBC_g);
      }
      break;

     case 1:
      vmrl_test_fourbar_Phipi(rtb_gain_2_e[0], rtb_gain_2_e[4], rtb_gain_2_e[8],
        rtb_gain_2_e[7], rtb_gain_2_e[6], rtb_gain_2_e[3],
        &vmrl_test_fourbar_B.Merge_g[3], vmrl_test_fourbar_B.Merge_g,
        vmrl_test_fourbar_M, &vmrl_test_fourbar_DWork.Phipi_g,
        (rtP_Phipi_vmrl_test_fourbar *) &vmrl_test_fourbar_P.Phipi_g);
      if (rtmIsMajorTimeStep(vmrl_test_fourbar_M)) {
        srUpdateBC(vmrl_test_fourbar_DWork.Phipi_g.Phipi_SubsysRanBC);
      }
      break;

     case 2:
      vmrl_test_fourbar_Generalcase(rtb_SumofElements3_a, &rtb_gain_2_e[5],
        rtb_gain_2_e[1], rtb_gain_2_e[7], &rtb_gain_2_e[2],
        &vmrl_test_fourbar_B.Merge_g[3], vmrl_test_fourbar_B.Merge_g,
        vmrl_test_fourbar_M, &vmrl_test_fourbar_DWork.Generalcase_k,
        (rtP_Generalcase_vmrl_test_fourb *) &vmrl_test_fourbar_P.Generalcase_k);
      if (rtmIsMajorTimeStep(vmrl_test_fourbar_M)) {
        srUpdateBC(vmrl_test_fourbar_DWork.Generalcase_k.Generalcase_SubsysRanBC);
      }
      break;
    }

    /* Gain: '<S4>/gain_1' */
    vmrl_test_fourbar_B.gain_1_i3[0] = vmrl_test_fourbar_P.gain_1_Gain_k *
      vmrl_test_fourbar_B.Block1_o1[36];
    vmrl_test_fourbar_B.gain_1_i3[1] = vmrl_test_fourbar_P.gain_1_Gain_k *
      vmrl_test_fourbar_B.Block1_o1[37];
    vmrl_test_fourbar_B.gain_1_i3[2] = vmrl_test_fourbar_P.gain_1_Gain_k *
      vmrl_test_fourbar_B.Block1_o1[38];

    /* Sum: '<S13>/Sum of Elements3' */
    rtb_SumofElements3_m = (rtb_gain_2[0] + rtb_gain_2[4]) + rtb_gain_2[8];

    /* If: '<S13>/If' incorporates:
     *  Abs: '<S13>/Abs'
     *  Constant: '<S13>/Constant'
     *  Sum: '<S13>/Sum'
     */
    if (rtmIsMajorTimeStep(vmrl_test_fourbar_M) != 0) {
      if (rtb_SumofElements3_m == 3.0) {
        rtAction = 0;
      } else if (fabs(rtb_SumofElements3_m +
                      vmrl_test_fourbar_P.Constant_Value_ej) <= 1.0E-012) {
        rtAction = 1;
      } else {
        rtAction = 2;
      }

      vmrl_test_fourbar_DWork.If_ActiveSubsystem_b = rtAction;
    } else {
      rtAction = vmrl_test_fourbar_DWork.If_ActiveSubsystem_b;
    }

    switch (rtAction) {
     case 0:
      if (rtmIsMajorTimeStep(vmrl_test_fourbar_M) &&
          vmrl_test_fourbar_M->Timing.TaskCounters.TID[1] == 0) {
        /* Constant: '<S41>/Trace=3=>Phi=0' */
        vmrl_test_fourbar_B.Merge_n[0] = vmrl_test_fourbar_P.Trace3Phi0_Value_o
          [0];
        vmrl_test_fourbar_B.Merge_n[1] = vmrl_test_fourbar_P.Trace3Phi0_Value_o
          [1];
        vmrl_test_fourbar_B.Merge_n[2] = vmrl_test_fourbar_P.Trace3Phi0_Value_o
          [2];
        vmrl_test_fourbar_B.Merge_n[3] = vmrl_test_fourbar_P.Trace3Phi0_Value_o
          [3];
      }

      if (rtmIsMajorTimeStep(vmrl_test_fourbar_M)) {
        srUpdateBC(vmrl_test_fourbar_DWork.Phi0_SubsysRanBC_l);
      }
      break;

     case 1:
      vmrl_test_fourbar_Phipi(rtb_gain_2[0], rtb_gain_2[4], rtb_gain_2[8],
        rtb_gain_2[7], rtb_gain_2[6], rtb_gain_2[3],
        &vmrl_test_fourbar_B.Merge_n[3], vmrl_test_fourbar_B.Merge_n,
        vmrl_test_fourbar_M, &vmrl_test_fourbar_DWork.Phipi_j,
        (rtP_Phipi_vmrl_test_fourbar *) &vmrl_test_fourbar_P.Phipi_j);
      if (rtmIsMajorTimeStep(vmrl_test_fourbar_M)) {
        srUpdateBC(vmrl_test_fourbar_DWork.Phipi_j.Phipi_SubsysRanBC);
      }
      break;

     case 2:
      vmrl_test_fourbar_Generalcase(rtb_SumofElements3_m, &rtb_gain_2[5],
        rtb_gain_2[1], rtb_gain_2[7], &rtb_gain_2[2],
        &vmrl_test_fourbar_B.Merge_n[3], vmrl_test_fourbar_B.Merge_n,
        vmrl_test_fourbar_M, &vmrl_test_fourbar_DWork.Generalcase_l,
        (rtP_Generalcase_vmrl_test_fourb *) &vmrl_test_fourbar_P.Generalcase_l);
      if (rtmIsMajorTimeStep(vmrl_test_fourbar_M)) {
        srUpdateBC(vmrl_test_fourbar_DWork.Generalcase_l.Generalcase_SubsysRanBC);
      }
      break;
    }

    for (i = 0; i < 9; i++) {
      /* Gain: '<S2>/gain_2' */
      rtb_gain_2_n[i] = vmrl_test_fourbar_B.Block1_o1[i + 15] *
        vmrl_test_fourbar_P.gain_2_Gain_d;
    }

    /* Sum: '<S14>/Sum of Elements3' */
    rtb_SumofElements3_i = (rtb_gain_2_n[0] + rtb_gain_2_n[4]) + rtb_gain_2_n[8];

    /* If: '<S14>/If' incorporates:
     *  Abs: '<S14>/Abs'
     *  Constant: '<S14>/Constant'
     *  Sum: '<S14>/Sum'
     */
    if (rtmIsMajorTimeStep(vmrl_test_fourbar_M) != 0) {
      if (rtb_SumofElements3_i == 3.0) {
        rtAction = 0;
      } else if (fabs(rtb_SumofElements3_i +
                      vmrl_test_fourbar_P.Constant_Value_b) <= 1.0E-012) {
        rtAction = 1;
      } else {
        rtAction = 2;
      }

      vmrl_test_fourbar_DWork.If_ActiveSubsystem_m = rtAction;
    } else {
      rtAction = vmrl_test_fourbar_DWork.If_ActiveSubsystem_m;
    }

    switch (rtAction) {
     case 0:
      if (rtmIsMajorTimeStep(vmrl_test_fourbar_M) &&
          vmrl_test_fourbar_M->Timing.TaskCounters.TID[1] == 0) {
        /* Constant: '<S46>/Trace=3=>Phi=0' */
        vmrl_test_fourbar_B.Merge_no[0] =
          vmrl_test_fourbar_P.Trace3Phi0_Value_e[0];
        vmrl_test_fourbar_B.Merge_no[1] =
          vmrl_test_fourbar_P.Trace3Phi0_Value_e[1];
        vmrl_test_fourbar_B.Merge_no[2] =
          vmrl_test_fourbar_P.Trace3Phi0_Value_e[2];
        vmrl_test_fourbar_B.Merge_no[3] =
          vmrl_test_fourbar_P.Trace3Phi0_Value_e[3];
      }

      if (rtmIsMajorTimeStep(vmrl_test_fourbar_M)) {
        srUpdateBC(vmrl_test_fourbar_DWork.Phi0_SubsysRanBC_d);
      }
      break;

     case 1:
      vmrl_test_fourbar_Phipi(rtb_gain_2_n[0], rtb_gain_2_n[4], rtb_gain_2_n[8],
        rtb_gain_2_n[7], rtb_gain_2_n[6], rtb_gain_2_n[3],
        &vmrl_test_fourbar_B.Merge_no[3], vmrl_test_fourbar_B.Merge_no,
        vmrl_test_fourbar_M, &vmrl_test_fourbar_DWork.Phipi_n,
        (rtP_Phipi_vmrl_test_fourbar *) &vmrl_test_fourbar_P.Phipi_n);
      if (rtmIsMajorTimeStep(vmrl_test_fourbar_M)) {
        srUpdateBC(vmrl_test_fourbar_DWork.Phipi_n.Phipi_SubsysRanBC);
      }
      break;

     case 2:
      vmrl_test_fourbar_Generalcase(rtb_SumofElements3_i, &rtb_gain_2_n[5],
        rtb_gain_2_n[1], rtb_gain_2_n[7], &rtb_gain_2_n[2],
        &vmrl_test_fourbar_B.Merge_no[3], vmrl_test_fourbar_B.Merge_no,
        vmrl_test_fourbar_M, &vmrl_test_fourbar_DWork.Generalcase_b,
        (rtP_Generalcase_vmrl_test_fourb *) &vmrl_test_fourbar_P.Generalcase_b);
      if (rtmIsMajorTimeStep(vmrl_test_fourbar_M)) {
        srUpdateBC(vmrl_test_fourbar_DWork.Generalcase_b.Generalcase_SubsysRanBC);
      }
      break;
    }

    /* Gain: '<S2>/gain_1' */
    vmrl_test_fourbar_B.gain_1_j[0] = vmrl_test_fourbar_P.gain_1_Gain_h *
      vmrl_test_fourbar_B.Block1_o1[12];
    vmrl_test_fourbar_B.gain_1_j[1] = vmrl_test_fourbar_P.gain_1_Gain_h *
      vmrl_test_fourbar_B.Block1_o1[13];
    vmrl_test_fourbar_B.gain_1_j[2] = vmrl_test_fourbar_P.gain_1_Gain_h *
      vmrl_test_fourbar_B.Block1_o1[14];
    if (rtmIsMajorTimeStep(vmrl_test_fourbar_M) &&
        vmrl_test_fourbar_M->Timing.TaskCounters.TID[1] == 0) {
      /* Gain: '<S15>/_gravity_conversion' incorporates:
       *  Constant: '<S8>/SOURCE_BLOCK'
       */
      vmrl_test_fourbar_B._gravity_conversion[0] =
        vmrl_test_fourbar_P._gravity_conversion_Gain *
        vmrl_test_fourbar_P.SOURCE_BLOCK_Value[0];
      vmrl_test_fourbar_B._gravity_conversion[1] =
        vmrl_test_fourbar_P._gravity_conversion_Gain *
        vmrl_test_fourbar_P.SOURCE_BLOCK_Value[1];
      vmrl_test_fourbar_B._gravity_conversion[2] =
        vmrl_test_fourbar_P._gravity_conversion_Gain *
        vmrl_test_fourbar_P.SOURCE_BLOCK_Value[2];
    }

    /* S-Function Block: <S15>/Block#2 */
    {
      _rtMech_PWORK *mechWork = (_rtMech_PWORK *)
        vmrl_test_fourbar_DWork.Block2_PWORK;
      mechWork->genSimData.time = vmrl_test_fourbar_M->Timing.t[0];
      mechWork->outSimData.majorTimestep = rtmIsMajorTimeStep
        (vmrl_test_fourbar_M);
      if (dynamicSfcnOutputMethod(mechWork->mechanism, &(mechWork->genSimData),
           &(mechWork->outSimData))) {
        {
          const ErrorRecord *err = getErrorMsg();
          static char_T errorMsg[1024];
          sprintf(errorMsg,
                  err->errorMsg,
                  err->blocks[0],
                  err->blocks[1],
                  err->blocks[2],
                  err->blocks[3],
                  err->blocks[4]);
          rtmSetErrorStatus(vmrl_test_fourbar_M, errorMsg);
          return;
        }
      }
    }

    /* S-Function Block: <S15>/Block#3 */
    {
      _rtMech_PWORK *mechWork = (_rtMech_PWORK *)
        vmrl_test_fourbar_DWork.Block3_PWORK;
      mechWork->genSimData.time = vmrl_test_fourbar_M->Timing.t[0];
      mechWork->outSimData.majorTimestep = rtmIsMajorTimeStep
        (vmrl_test_fourbar_M);
      if (eventSfcnOutputMethod(mechWork->mechanism, &(mechWork->genSimData),
           &(mechWork->outSimData))) {
        {
          const ErrorRecord *err = getErrorMsg();
          static char_T errorMsg[1024];
          sprintf(errorMsg,
                  err->errorMsg,
                  err->blocks[0],
                  err->blocks[1],
                  err->blocks[2],
                  err->blocks[3],
                  err->blocks[4]);
          rtmSetErrorStatus(vmrl_test_fourbar_M, errorMsg);
          return;
        }
      }
    }
  }

  UNUSED_PARAMETER(tid);
}

/* Model update function */
void vmrl_test_fourbar_update(int_T tid)
{
  if (rtmIsMajorTimeStep(vmrl_test_fourbar_M)) {
    rt_ertODEUpdateContinuousStates(&vmrl_test_fourbar_M->solverInfo);
  }

  /* Update absolute time for base rate */
  if (!(++vmrl_test_fourbar_M->Timing.clockTick0))
    ++vmrl_test_fourbar_M->Timing.clockTickH0;
  vmrl_test_fourbar_M->Timing.t[0] = vmrl_test_fourbar_M->Timing.clockTick0 *
    vmrl_test_fourbar_M->Timing.stepSize0 +
    vmrl_test_fourbar_M->Timing.clockTickH0 *
    vmrl_test_fourbar_M->Timing.stepSize0 * 4294967296.0;
  if (rtmIsMajorTimeStep(vmrl_test_fourbar_M) &&
      vmrl_test_fourbar_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    if (!(++vmrl_test_fourbar_M->Timing.clockTick1))
      ++vmrl_test_fourbar_M->Timing.clockTickH1;
    vmrl_test_fourbar_M->Timing.t[1] = vmrl_test_fourbar_M->Timing.clockTick1 *
      vmrl_test_fourbar_M->Timing.stepSize1 +
      vmrl_test_fourbar_M->Timing.clockTickH1 *
      vmrl_test_fourbar_M->Timing.stepSize1 * 4294967296.0;
  }

  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void vmrl_test_fourbar_derivatives(void)
{
  /* S-Function Block: <S15>/Block#1 */
  {
    _rtMech_PWORK *mechWork = (_rtMech_PWORK *)
      vmrl_test_fourbar_DWork.Block1_PWORK;
    if (sFcnDerivativesMethod(mechWork->mechanism,
         &((StateDerivatives_vmrl_test_fourbar *)
           vmrl_test_fourbar_M->ModelData.derivs)->Block1_CSTATE[0])) {
      {
        const ErrorRecord *err = getErrorMsg();
        static char_T errorMsg[1024];
        sprintf(errorMsg,
                err->errorMsg,
                err->blocks[0],
                err->blocks[1],
                err->blocks[2],
                err->blocks[3],
                err->blocks[4]);
        rtmSetErrorStatus(vmrl_test_fourbar_M, errorMsg);
        return;
      }
    }
  }

  /* Derivatives for If: '<S9>/If' */

  /* Derivatives for If: '<S10>/If' */

  /* Derivatives for If: '<S11>/If' */

  /* Derivatives for If: '<S12>/If' */

  /* Derivatives for If: '<S13>/If' */

  /* Derivatives for If: '<S14>/If' */
}

/* Model initialize function */
void vmrl_test_fourbar_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));    /* initialize real-time model */
  (void) memset((char_T *)vmrl_test_fourbar_M,0,
                sizeof(RT_MODEL_vmrl_test_fourbar));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&vmrl_test_fourbar_M->solverInfo,
                          &vmrl_test_fourbar_M->Timing.simTimeStep);
    rtsiSetTPtr(&vmrl_test_fourbar_M->solverInfo, &rtmGetTPtr
                (vmrl_test_fourbar_M));
    rtsiSetStepSizePtr(&vmrl_test_fourbar_M->solverInfo,
                       &vmrl_test_fourbar_M->Timing.stepSize0);
    rtsiSetdXPtr(&vmrl_test_fourbar_M->solverInfo,
                 &vmrl_test_fourbar_M->ModelData.derivs);
    rtsiSetContStatesPtr(&vmrl_test_fourbar_M->solverInfo,
                         &vmrl_test_fourbar_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&vmrl_test_fourbar_M->solverInfo,
      &vmrl_test_fourbar_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&vmrl_test_fourbar_M->solverInfo, (&rtmGetErrorStatus
      (vmrl_test_fourbar_M)));
    rtsiSetRTModelPtr(&vmrl_test_fourbar_M->solverInfo, vmrl_test_fourbar_M);
  }

  rtsiSetSimTimeStep(&vmrl_test_fourbar_M->solverInfo, MAJOR_TIME_STEP);
  vmrl_test_fourbar_M->ModelData.intgData.f[0] =
    vmrl_test_fourbar_M->ModelData.odeF[0];
  vmrl_test_fourbar_M->ModelData.contStates = ((real_T *) &vmrl_test_fourbar_X);
  rtsiSetSolverData(&vmrl_test_fourbar_M->solverInfo, (void *)
                    &vmrl_test_fourbar_M->ModelData.intgData);
  rtsiSetSolverName(&vmrl_test_fourbar_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = vmrl_test_fourbar_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    vmrl_test_fourbar_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    vmrl_test_fourbar_M->Timing.sampleTimes =
      (&vmrl_test_fourbar_M->Timing.sampleTimesArray[0]);
    vmrl_test_fourbar_M->Timing.offsetTimes =
      (&vmrl_test_fourbar_M->Timing.offsetTimesArray[0]);

    /* task periods */
    vmrl_test_fourbar_M->Timing.sampleTimes[0] = (0.0);
    vmrl_test_fourbar_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    vmrl_test_fourbar_M->Timing.offsetTimes[0] = (0.0);
    vmrl_test_fourbar_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(vmrl_test_fourbar_M, &vmrl_test_fourbar_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = vmrl_test_fourbar_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    vmrl_test_fourbar_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(vmrl_test_fourbar_M, -1);
  vmrl_test_fourbar_M->Timing.stepSize0 = 0.001;
  vmrl_test_fourbar_M->Timing.stepSize1 = 0.001;

  /* external mode info */
  vmrl_test_fourbar_M->Sizes.checksums[0] = (1116831554U);
  vmrl_test_fourbar_M->Sizes.checksums[1] = (2304746241U);
  vmrl_test_fourbar_M->Sizes.checksums[2] = (2941337149U);
  vmrl_test_fourbar_M->Sizes.checksums[3] = (620976095U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[37];
    vmrl_test_fourbar_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Generalcase.Generalcase_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&vmrl_test_fourbar_DWork.Phi0_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Phipi.Phipi_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Phipi.Phipi_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Phipi.Phipi_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Phipi.Phipi_SubsysRanBC;
    systemRan[7] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Generalcase_c.Generalcase_SubsysRanBC;
    systemRan[8] = (sysRanDType *)&vmrl_test_fourbar_DWork.Phi0_SubsysRanBC_b;
    systemRan[9] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Phipi_m.Phipi_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Phipi_m.Phipi_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Phipi_m.Phipi_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Phipi_m.Phipi_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Generalcase_g.Generalcase_SubsysRanBC;
    systemRan[14] = (sysRanDType *)&vmrl_test_fourbar_DWork.Phi0_SubsysRanBC_n;
    systemRan[15] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Phipi_e.Phipi_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Phipi_e.Phipi_SubsysRanBC;
    systemRan[17] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Phipi_e.Phipi_SubsysRanBC;
    systemRan[18] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Phipi_e.Phipi_SubsysRanBC;
    systemRan[19] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Generalcase_k.Generalcase_SubsysRanBC;
    systemRan[20] = (sysRanDType *)&vmrl_test_fourbar_DWork.Phi0_SubsysRanBC_g;
    systemRan[21] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Phipi_g.Phipi_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Phipi_g.Phipi_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Phipi_g.Phipi_SubsysRanBC;
    systemRan[24] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Phipi_g.Phipi_SubsysRanBC;
    systemRan[25] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Generalcase_l.Generalcase_SubsysRanBC;
    systemRan[26] = (sysRanDType *)&vmrl_test_fourbar_DWork.Phi0_SubsysRanBC_l;
    systemRan[27] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Phipi_j.Phipi_SubsysRanBC;
    systemRan[28] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Phipi_j.Phipi_SubsysRanBC;
    systemRan[29] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Phipi_j.Phipi_SubsysRanBC;
    systemRan[30] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Phipi_j.Phipi_SubsysRanBC;
    systemRan[31] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Generalcase_b.Generalcase_SubsysRanBC;
    systemRan[32] = (sysRanDType *)&vmrl_test_fourbar_DWork.Phi0_SubsysRanBC_d;
    systemRan[33] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Phipi_n.Phipi_SubsysRanBC;
    systemRan[34] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Phipi_n.Phipi_SubsysRanBC;
    systemRan[35] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Phipi_n.Phipi_SubsysRanBC;
    systemRan[36] = (sysRanDType *)
      &vmrl_test_fourbar_DWork.Phipi_n.Phipi_SubsysRanBC;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &vmrl_test_fourbar_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, vmrl_test_fourbar_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(vmrl_test_fourbar_M));
  }

  vmrl_test_fourbar_M->solverInfoPtr = (&vmrl_test_fourbar_M->solverInfo);
  vmrl_test_fourbar_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&vmrl_test_fourbar_M->solverInfo, 0.001);
  rtsiSetSolverMode(&vmrl_test_fourbar_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  vmrl_test_fourbar_M->ModelData.blockIO = ((void *) &vmrl_test_fourbar_B);

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&vmrl_test_fourbar_B.Block1_o1[0]);
    for (i = 0; i < 111; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }
  }

  /* parameters */
  vmrl_test_fourbar_M->ModelData.defaultParam = ((real_T *) &vmrl_test_fourbar_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &vmrl_test_fourbar_X;
    vmrl_test_fourbar_M->ModelData.contStates = (x);
    (void) memset((char_T *)x,0,
                  sizeof(ContinuousStates_vmrl_test_fourbar));
  }

  /* states (dwork) */
  vmrl_test_fourbar_M->Work.dwork = ((void *) &vmrl_test_fourbar_DWork);
  (void) memset((char_T *) &vmrl_test_fourbar_DWork,0,
                sizeof(D_Work_vmrl_test_fourbar));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    vmrl_test_fourbar_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }
}

/* Model terminate function */
void vmrl_test_fourbar_terminate(void)
{
  /* S-Function Block: <S15>/Block#1 */
  {
    if (rt_mech_visited_vmrl_test_fourbar_1d6fdf5b == 1) {
      _rtMech_PWORK *mechWork = (_rtMech_PWORK *)
        vmrl_test_fourbar_DWork.Block1_PWORK;
      if (mechWork->mechanism->destroyEngine != NULL) {
        (mechWork->mechanism->destroyEngine)(mechWork->mechanism);
      }
    }

    if ((--rt_mech_visited_vmrl_test_fourbar_1d6fdf5b) == 0 ) {
      rt_mech_visited_loc_vmrl_test_fourbar_1d6fdf5b = 0;
    }
  }

  /* Terminate for ifaction SubSystem: '<S9>/Phi == pi' */

  /* end of Terminate for SubSystem: '<S9>/Phi == pi' */

  /* Terminate for ifaction SubSystem: '<S10>/Phi == pi' */

  /* end of Terminate for SubSystem: '<S10>/Phi == pi' */

  /* Terminate for ifaction SubSystem: '<S11>/Phi == pi' */

  /* end of Terminate for SubSystem: '<S11>/Phi == pi' */

  /* Terminate for ifaction SubSystem: '<S12>/Phi == pi' */

  /* end of Terminate for SubSystem: '<S12>/Phi == pi' */

  /* Terminate for ifaction SubSystem: '<S13>/Phi == pi' */

  /* end of Terminate for SubSystem: '<S13>/Phi == pi' */

  /* Terminate for ifaction SubSystem: '<S14>/Phi == pi' */

  /* end of Terminate for SubSystem: '<S14>/Phi == pi' */

  /* External mode */
  rtExtModeShutdown(2);
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  vmrl_test_fourbar_output(tid);
}

void MdlUpdate(int_T tid)
{
  vmrl_test_fourbar_update(tid);
}

void MdlInitializeSizes(void)
{
  vmrl_test_fourbar_M->Sizes.numContStates = (6);/* Number of continuous states */
  vmrl_test_fourbar_M->Sizes.numY = (0);/* Number of model outputs */
  vmrl_test_fourbar_M->Sizes.numU = (0);/* Number of model inputs */
  vmrl_test_fourbar_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  vmrl_test_fourbar_M->Sizes.numSampTimes = (2);/* Number of sample times */
  vmrl_test_fourbar_M->Sizes.numBlocks = (131);/* Number of blocks */
  vmrl_test_fourbar_M->Sizes.numBlockIO = (17);/* Number of block outputs */
  vmrl_test_fourbar_M->Sizes.numBlockPrms = (520);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* S-Function Block: <S15>/Block#1 */
  {
    static _rtMech_PWORK mechWork;
    static ErrorRecord errorRec;
    if (rtmIsFirstInitCond(vmrl_test_fourbar_M)) {
      const int locationFlag = __LINE__;
      if (rt_mech_visited_loc_vmrl_test_fourbar_1d6fdf5b == 0 ) {
        rt_mech_visited_loc_vmrl_test_fourbar_1d6fdf5b = locationFlag;
      }

      if (rt_mech_visited_loc_vmrl_test_fourbar_1d6fdf5b == locationFlag ) {
        if ((++rt_mech_visited_vmrl_test_fourbar_1d6fdf5b) != 1) {
          static const char reentranterrormsg[] =
            "Attempting to use multiple instances of SimMechanics generated code";
          rtmSetErrorStatus(vmrl_test_fourbar_M, reentranterrormsg);
          return;
        }
      }

      mechWork.mechanism = rt_get_mechanism_vmrl_test_fourbar_1d6fdf5b();
      mechWork.mechanism->engineError = &errorRec;
      mechWork.mechanism->engineError->errorFlag = false;

      {
        static char errorMsg[1024];
        if ((mechWork.mechanism->mapRuntimeData)(mechWork.mechanism,
             vmrl_test_fourbar_P.Block1_SimMechanicsRuntimeParam, errorMsg,
             sizeof(errorMsg) - 1)) {
          rtmSetErrorStatus(vmrl_test_fourbar_M, errorMsg);
          return;
        }
      }

      {
        static mech_method_table_t _mech_method_table = {
          NULL
          , mech_I_xrvyx3Aq5bww_f7NHox2
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_lagoBpV2welCUbWExMd2g_
          , mech_xgVNf0uqACGJgr3riV2TW_
          , NULL
          , NULL
          , mech_lXjmQCmQ9KYdo3NotOWF50
          , NULL
          , mech_KRzkmSIGFh1nPlRnKYf5f_
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_J1VBUO2K8W2Ag4M8nqujC_
          , NULL
          , mech_UF3v8E1vqSvGWTzmehi3_1
          , NULL
          , mech__d0CIENIR3HfEF35QR9Ha1
          , NULL
          , NULL
          , NULL
          , mech_MGOfra5Zxw_DziA1lJ_Xv_
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_YyMp0EfJfPncA2TzJ_1fp1
          , NULL
          , mech_VM6ChnSTNT9whG7bzcrTp1
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_VPlni_ltm1YYtBkIrjvcq1
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_Cgu0lKThtzqrZoLtCnwjJ_
          , mech_7aIKRF_YGZdePwxsVRxfZ2
          , NULL
          , mech_NfxycZZniL4oyBcp6hoVv_
          , NULL
          , mech_RSWvKDmIsIxZ2TrwvUllG1
          , mech_uhcwxi7XwjGUubpSE__vs1
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_VOxXGjvB0g0cs7Y_LB0lR1
          , mech_ctiIyAJi1PeFIuG_wUvnk2
          , NULL
          , mech_a_17m3gydYlTeUU7HvysF0
          , mech__MLGR2zPV8GQNF039XoEV2
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_MliFRcEv5v_hyQWjFWj4a_
          , NULL
          , mech_2msDn_wV4WKxjlyA01gQj1
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_OHckGNNEJwON5eZqEeLzi0
          , mech_SkMDZ_VPJbRajQj2KcnZo0
          , mech__K9V_2xZBC8lWckjTxcwv2
          , mech_ISI2aDLTEeSoNduI2K46F1
          , mech_ZxSA6eM26nhj8ctjJJYeG_
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_EG6IMPocjVW_x9f9ZmlYz2
          , mech_yaseRorTHqgQ0h0Gr4MBx2
          , mech_3QZGEfrvTKXUDkwr2nava1
          , mech_RaJJemaGowYhkniKZX9hV0
          , NULL
          , NULL
          , NULL
          , NULL
          , mech__4bqWfNpOsb8u2HaHsF5l_
          , mech_UqNuwpQkQmhW4UcXaqzzc1
          , NULL
          , mech_doyXts1OIeDYQ4fyF5snA0
          , mech_tVk1xlecMmZl4t2t2Z4rJ0
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_gQwpAydKmPpdPDPznUyeu2
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_ZI9UhUM6Zzhg0B_NnP9no1
          , mech_c3JLv6NHRlcbYvbo3yUqR2
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_2Erdl7FY9HDft_6KKrAbi_
          , mech_AjYYhGS00PWFQve_0KKLk2
          , mech_pz1_pEZ6t6jTHWzCNq3HX1
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_H2CpDYCpvxvkzfBP3eSON1
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_b7vVw7rEJer8uyv4__kSE0
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_J61NtGQh_Nkg4Fv9d3UWy_
          , mech_haUnkmp_EtE6yFkU2FVfb1
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_GrHBsF3gQ0OlLLDe_fJL90
          , mech_lEYbC8DzcQHVYBt6kV_IN_
          , NULL
          , NULL
          , mech_3WSmgjHoFmbqWEdNHIA7R_
          , NULL
          , mech_zBX_KJTs7H_0gB_Ea_czh0
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_th7tzcG4WkxfeSEgprwRI2
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_Uu7joU8H9eUeastwolDVg0
          , NULL
          , NULL
          , NULL
          , mech_nfsiZqoPRlid5if8dLBIP_
          , NULL
          , NULL
          , NULL
          , mech_pm9lvWqM_0HTWE9n7V4cd_
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_KRJ4D_h3wCIKJUWPQ5El42
          , NULL
          , mech_0lIrQNN8BikpjmSlfvOpD2
          , NULL
          , mech_X_s55__MagWomhwU3uTBJ2
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_dR3yJSNJ2TdJ3zjUrmGvi_
          , NULL
          , mech_rbFdBLFHaXR2hE4eNt3M_2
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_c4fHdpqHIi08Ait7iCqsD0
          , NULL
          , mech_tvBgCn9kE7__7gd_dQRd32
          , mech_X43nq7_9OD9COWaArLGn72
          , mech_SFLi3RphwofdWH6oWJjav_
          , mech_UYo1_sYa9rbFhwYiTlhPe1
          , mech_I_TjZD9IA_EJQ5p3TqNg41
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_mVUuDxDYWY_wnk_u3tMJ52
          , NULL
          , mech_LnQ7yURGT5VnhZw7eJN_c1
          , mech_JEGLA8EGraNv1gsCDpdTi1
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_iZMzxIc7St_1CDhCr_ERu1
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_V9_Mz_LzNbR9VpzkOzpsQ_
          , NULL
          , mech_FZzsa9eVxUlRmX6dgrqba_
          , NULL
          , mech__REV7VpG04VPUsfMedjgL0
          , mech__KVOfJ_GF9rOM_LIXRUxG1
          , mech_IALCHMIMjiHkLz1jh1u2V1
          , mech_pTDkXJlN7oTiMSukGwz3M_
          , mech_Sc7uBbgOp5rMuP5VajcjW_
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_whurMJYuIQ0eFWTX2xlVq2
          , NULL
          , mech_zXy1Dl5ssQjKdPryZJ55s_
          , NULL
          , mech_EV0vUsoIE58aWnq3LGXr50
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_YLlDEY62bKu6q8tuZBo5x0
          , NULL
          , mech_8D74wPqnKsVbxa37aTmqw2
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_D4BauNoWsalkiYiv8mN1j0
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_Vtow2gQfjWqPxtWw2FRuj2
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_ANoHgRb4tp27Dm9QJ3CSQ1
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_eCAm5yLntfjR0nO0eiLu50
          , NULL
          , mech_O_0fmXHZlNRyWfOvQvLXt_
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_r0DHD16hK0BIQM3TZ7F1G_
          , mech_8iHff_rVIjjhbiiPfQqDA1
          , NULL
          , NULL
          , mech_5wQbk_zOuJGXAaiJyVzLQ1
          , mech_Ugf3ikEW46pYkHy18GDhF1
          , NULL
          , NULL
          , mech_HVnyXQ8p1Ft6jrmXYhQZC2
          , NULL
          , NULL
          , mech_KzAgwj55qtxfWczRliRB5_
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_9zUFhBEQOKyWs7xjscZfw2
          , mech_PfNmXDpxmYMkGo9X3cLBR1
          , mech_6qPdndNUGrxO5pKg3xXD3_
          , NULL
          , mech_eAYj60QmC3AeVM8z8M5VH0
          , NULL
          , mech_wn4jlCEwb7bynhe7vagGC_
          , NULL
          , NULL
          , mech_ZVdknpwSY_5rh59_L8Z_s0
          , NULL
          , NULL
          , NULL
          , mech_aqrbxHdKQezp3I_SDAzBn0
          , mech_cR0B84p7D4fGeJs1kDmO0_
          , NULL
          , NULL
          , NULL
          , mech_CEGucWxEmABHIRkypy11k1
          , NULL
          , mech_kO655f1w_6PM5ppviK7fX2
          , NULL
          , mech_Ef6SswH2FfLe6jo9haPdv_
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
        };

        mech_method_table_update(&_mech_method_table);
      }

      if (createEngineMechanism(mechWork.mechanism)) {
        {
          const ErrorRecord *err = getErrorMsg();
          static char_T errorMsg[1024];
          sprintf(errorMsg,
                  err->errorMsg,
                  err->blocks[0],
                  err->blocks[1],
                  err->blocks[2],
                  err->blocks[3],
                  err->blocks[4]);
          rtmSetErrorStatus(vmrl_test_fourbar_M, errorMsg);
          return;
        }
      }

      mechWork.mechanism->state = &vmrl_test_fourbar_X.Block1_CSTATE[0];
      vmrl_test_fourbar_DWork.Block1_IWORK = 0U;
      mechWork.genSimData.tStart = (0.0);
      mechWork.genSimData.iwork = &vmrl_test_fourbar_DWork.Block1_IWORK;
      mechWork.genSimData.numInputPorts = 1;

      {
        static real_T *mech_inputSignals[3];
        mech_inputSignals[0] = (real_T *)
          vmrl_test_fourbar_B._gravity_conversion;
        mech_inputSignals[1] = (real_T *)
          &vmrl_test_fourbar_B._gravity_conversion[1];
        mech_inputSignals[2] = (real_T *)
          &vmrl_test_fourbar_B._gravity_conversion[2];
        mechWork.genSimData.inputSignals[0] = mech_inputSignals;
      }

      mechWork.outSimData.numOutputPorts = 3;
      mechWork.outSimData.logOutput = false;
      mechWork.outSimData.outputSignals[0] = vmrl_test_fourbar_B.Block1_o1;
      mechWork.outSimData.outputSignals[1] = vmrl_test_fourbar_B.Block1_o2;
      mechWork.outSimData.outputSignals[2] = &vmrl_test_fourbar_B.Block1_o3;
      vmrl_test_fourbar_DWork.Block1_PWORK = &mechWork;
    }
  }

  /* S-Function Block: <S15>/Block#2 */
  {
    static _rtMech_PWORK mechWork;
    static ErrorRecord errorRec;
    if (rtmIsFirstInitCond(vmrl_test_fourbar_M)) {
      mechWork.mechanism = rt_get_mechanism_vmrl_test_fourbar_1d6fdf5b();
      mechWork.mechanism->engineError = &errorRec;
      mechWork.mechanism->engineError->errorFlag = false;
      mechWork.genSimData.tStart = (0.0);
      mechWork.genSimData.iwork = NULL;
      mechWork.genSimData.numInputPorts = 3;

      {
        static real_T *mech_inputSignals[6];
        mech_inputSignals[0] = (real_T *) vmrl_test_fourbar_B.Block1_o2;
        mech_inputSignals[1] = (real_T *) &vmrl_test_fourbar_B.Block1_o2[1];
        mech_inputSignals[2] = (real_T *) &vmrl_test_fourbar_B.Block1_o2[2];
        mech_inputSignals[3] = (real_T *) &vmrl_test_fourbar_B.Block1_o2[3];
        mech_inputSignals[4] = (real_T *) &vmrl_test_fourbar_B.Block1_o2[4];
        mech_inputSignals[5] = (real_T *) &vmrl_test_fourbar_B.Block1_o2[5];
        mechWork.genSimData.inputSignals[0] = mech_inputSignals;
      }

      {
        static real_T *mech_inputSignals[1];
        mech_inputSignals[0] = (real_T *) &vmrl_test_fourbar_B.Block1_o3;
        mechWork.genSimData.inputSignals[1] = mech_inputSignals;
      }

      {
        static real_T *mech_inputSignals[3];
        mech_inputSignals[0] = (real_T *)
          vmrl_test_fourbar_B._gravity_conversion;
        mech_inputSignals[1] = (real_T *)
          &vmrl_test_fourbar_B._gravity_conversion[1];
        mech_inputSignals[2] = (real_T *)
          &vmrl_test_fourbar_B._gravity_conversion[2];
        mechWork.genSimData.inputSignals[2] = mech_inputSignals;
      }

      mechWork.outSimData.numOutputPorts = 1;
      mechWork.outSimData.logOutput = false;
      mechWork.outSimData.outputSignals[0] = &vmrl_test_fourbar_B.Block2;
      vmrl_test_fourbar_DWork.Block2_PWORK = &mechWork;
    }
  }

  /* S-Function Block: <S15>/Block#3 */
  {
    static _rtMech_PWORK mechWork;
    static ErrorRecord errorRec;
    if (rtmIsFirstInitCond(vmrl_test_fourbar_M)) {
      mechWork.mechanism = rt_get_mechanism_vmrl_test_fourbar_1d6fdf5b();
      mechWork.mechanism->engineError = &errorRec;
      mechWork.mechanism->engineError->errorFlag = false;
      vmrl_test_fourbar_DWork.Block3_IWORK = 1U;
      mechWork.genSimData.tStart = (0.0);
      mechWork.genSimData.iwork = &vmrl_test_fourbar_DWork.Block3_IWORK;
      mechWork.genSimData.numInputPorts = 1;

      {
        static real_T *mech_inputSignals[1];
        mech_inputSignals[0] = (real_T *) &vmrl_test_fourbar_B.Block2;
        mechWork.genSimData.inputSignals[0] = mech_inputSignals;
      }

      mechWork.outSimData.numOutputPorts = 1;
      mechWork.outSimData.logOutput = false;
      mechWork.outSimData.outputSignals[0] = &vmrl_test_fourbar_B.Block3;
      vmrl_test_fourbar_DWork.Block3_PWORK = &mechWork;
    }
  }
}

void MdlStart(void)
{
  /* Start for If: '<S9>/If' */
  vmrl_test_fourbar_DWork.If_ActiveSubsystem = -1;

  /* Start for ifaction SubSystem: '<S9>/Phi == 0' */

  /* VirtualOutportStart for Outport: '<S21>/VRRot_0' */
  vmrl_test_fourbar_B.Merge[0] = vmrl_test_fourbar_P.VRRot_0_Y0[0];
  vmrl_test_fourbar_B.Merge[1] = vmrl_test_fourbar_P.VRRot_0_Y0[1];
  vmrl_test_fourbar_B.Merge[2] = vmrl_test_fourbar_P.VRRot_0_Y0[2];
  vmrl_test_fourbar_B.Merge[3] = vmrl_test_fourbar_P.VRRot_0_Y0[3];

  /* end of Start for SubSystem: '<S9>/Phi == 0' */

  /* Start for ifaction SubSystem: '<S9>/Phi == pi' */
  vmrl_test_fourbar_Phipi_Start(&vmrl_test_fourbar_B.Merge[3],
    vmrl_test_fourbar_B.Merge, (rtP_Phipi_vmrl_test_fourbar *)
    &vmrl_test_fourbar_P.Phipi);

  /* end of Start for SubSystem: '<S9>/Phi == pi' */

  /* Start for If: '<S10>/If' */
  vmrl_test_fourbar_DWork.If_ActiveSubsystem_l = -1;

  /* Start for ifaction SubSystem: '<S10>/Phi == 0' */

  /* VirtualOutportStart for Outport: '<S26>/VRRot_0' */
  vmrl_test_fourbar_B.Merge_d[0] = vmrl_test_fourbar_P.VRRot_0_Y0_i[0];
  vmrl_test_fourbar_B.Merge_d[1] = vmrl_test_fourbar_P.VRRot_0_Y0_i[1];
  vmrl_test_fourbar_B.Merge_d[2] = vmrl_test_fourbar_P.VRRot_0_Y0_i[2];
  vmrl_test_fourbar_B.Merge_d[3] = vmrl_test_fourbar_P.VRRot_0_Y0_i[3];

  /* end of Start for SubSystem: '<S10>/Phi == 0' */

  /* Start for ifaction SubSystem: '<S10>/Phi == pi' */
  vmrl_test_fourbar_Phipi_Start(&vmrl_test_fourbar_B.Merge_d[3],
    vmrl_test_fourbar_B.Merge_d, (rtP_Phipi_vmrl_test_fourbar *)
    &vmrl_test_fourbar_P.Phipi_m);

  /* end of Start for SubSystem: '<S10>/Phi == pi' */

  /* Start for If: '<S11>/If' */
  vmrl_test_fourbar_DWork.If_ActiveSubsystem_i = -1;

  /* Start for ifaction SubSystem: '<S11>/Phi == 0' */

  /* VirtualOutportStart for Outport: '<S31>/VRRot_0' */
  vmrl_test_fourbar_B.Merge_m[0] = vmrl_test_fourbar_P.VRRot_0_Y0_d[0];
  vmrl_test_fourbar_B.Merge_m[1] = vmrl_test_fourbar_P.VRRot_0_Y0_d[1];
  vmrl_test_fourbar_B.Merge_m[2] = vmrl_test_fourbar_P.VRRot_0_Y0_d[2];
  vmrl_test_fourbar_B.Merge_m[3] = vmrl_test_fourbar_P.VRRot_0_Y0_d[3];

  /* end of Start for SubSystem: '<S11>/Phi == 0' */

  /* Start for ifaction SubSystem: '<S11>/Phi == pi' */
  vmrl_test_fourbar_Phipi_Start(&vmrl_test_fourbar_B.Merge_m[3],
    vmrl_test_fourbar_B.Merge_m, (rtP_Phipi_vmrl_test_fourbar *)
    &vmrl_test_fourbar_P.Phipi_e);

  /* end of Start for SubSystem: '<S11>/Phi == pi' */

  /* Start for If: '<S12>/If' */
  vmrl_test_fourbar_DWork.If_ActiveSubsystem_c = -1;

  /* Start for ifaction SubSystem: '<S12>/Phi == 0' */

  /* VirtualOutportStart for Outport: '<S36>/VRRot_0' */
  vmrl_test_fourbar_B.Merge_g[0] = vmrl_test_fourbar_P.VRRot_0_Y0_b[0];
  vmrl_test_fourbar_B.Merge_g[1] = vmrl_test_fourbar_P.VRRot_0_Y0_b[1];
  vmrl_test_fourbar_B.Merge_g[2] = vmrl_test_fourbar_P.VRRot_0_Y0_b[2];
  vmrl_test_fourbar_B.Merge_g[3] = vmrl_test_fourbar_P.VRRot_0_Y0_b[3];

  /* end of Start for SubSystem: '<S12>/Phi == 0' */

  /* Start for ifaction SubSystem: '<S12>/Phi == pi' */
  vmrl_test_fourbar_Phipi_Start(&vmrl_test_fourbar_B.Merge_g[3],
    vmrl_test_fourbar_B.Merge_g, (rtP_Phipi_vmrl_test_fourbar *)
    &vmrl_test_fourbar_P.Phipi_g);

  /* end of Start for SubSystem: '<S12>/Phi == pi' */

  /* Start for If: '<S13>/If' */
  vmrl_test_fourbar_DWork.If_ActiveSubsystem_b = -1;

  /* Start for ifaction SubSystem: '<S13>/Phi == 0' */

  /* VirtualOutportStart for Outport: '<S41>/VRRot_0' */
  vmrl_test_fourbar_B.Merge_n[0] = vmrl_test_fourbar_P.VRRot_0_Y0_e[0];
  vmrl_test_fourbar_B.Merge_n[1] = vmrl_test_fourbar_P.VRRot_0_Y0_e[1];
  vmrl_test_fourbar_B.Merge_n[2] = vmrl_test_fourbar_P.VRRot_0_Y0_e[2];
  vmrl_test_fourbar_B.Merge_n[3] = vmrl_test_fourbar_P.VRRot_0_Y0_e[3];

  /* end of Start for SubSystem: '<S13>/Phi == 0' */

  /* Start for ifaction SubSystem: '<S13>/Phi == pi' */
  vmrl_test_fourbar_Phipi_Start(&vmrl_test_fourbar_B.Merge_n[3],
    vmrl_test_fourbar_B.Merge_n, (rtP_Phipi_vmrl_test_fourbar *)
    &vmrl_test_fourbar_P.Phipi_j);

  /* end of Start for SubSystem: '<S13>/Phi == pi' */

  /* Start for If: '<S14>/If' */
  vmrl_test_fourbar_DWork.If_ActiveSubsystem_m = -1;

  /* Start for ifaction SubSystem: '<S14>/Phi == 0' */

  /* VirtualOutportStart for Outport: '<S46>/VRRot_0' */
  vmrl_test_fourbar_B.Merge_no[0] = vmrl_test_fourbar_P.VRRot_0_Y0_l[0];
  vmrl_test_fourbar_B.Merge_no[1] = vmrl_test_fourbar_P.VRRot_0_Y0_l[1];
  vmrl_test_fourbar_B.Merge_no[2] = vmrl_test_fourbar_P.VRRot_0_Y0_l[2];
  vmrl_test_fourbar_B.Merge_no[3] = vmrl_test_fourbar_P.VRRot_0_Y0_l[3];

  /* end of Start for SubSystem: '<S14>/Phi == 0' */

  /* Start for ifaction SubSystem: '<S14>/Phi == pi' */
  vmrl_test_fourbar_Phipi_Start(&vmrl_test_fourbar_B.Merge_no[3],
    vmrl_test_fourbar_B.Merge_no, (rtP_Phipi_vmrl_test_fourbar *)
    &vmrl_test_fourbar_P.Phipi_n);

  /* end of Start for SubSystem: '<S14>/Phi == pi' */
  MdlInitialize();
}

RT_MODEL_vmrl_test_fourbar *vmrl_test_fourbar(void)
{
  vmrl_test_fourbar_initialize(1);
  return vmrl_test_fourbar_M;
}

void MdlTerminate(void)
{
  vmrl_test_fourbar_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
