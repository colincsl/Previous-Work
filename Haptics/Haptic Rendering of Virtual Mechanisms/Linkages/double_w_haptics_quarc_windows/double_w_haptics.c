/*
 * double_w_haptics.c
 *
 * Real-Time Workshop code generation for Simulink model "double_w_haptics.mdl".
 *
 * Model Version              : 1.132
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Tue Jul 21 16:32:36 2009
 */

#include "double_w_haptics.h"
#include "double_w_haptics_private.h"
#include <stdio.h>
#include "double_w_haptics_dt.h"

/* Block signals (auto storage) */
BlockIO_double_w_haptics double_w_haptics_B;

/* Continuous states */
ContinuousStates_double_w_hapti double_w_haptics_X;

/* Solver Matrices */

/* A and B matrices used by ODE3 fixed-step solver */
static const real_T rt_ODE3_A[3] = {
  1.0/2.0, 3.0/4.0, 1.0
};

static const real_T rt_ODE3_B[3][3] = {
  { 1.0/2.0, 0.0, 0.0 },

  { 0.0, 3.0/4.0, 0.0 },

  { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
};

/* Block states (auto storage) */
D_Work_double_w_haptics double_w_haptics_DWork;

/* Real-time model */
RT_MODEL_double_w_haptics double_w_haptics_M_;
RT_MODEL_double_w_haptics *double_w_haptics_M = &double_w_haptics_M_;

/* Projection for root system: '<Root>' */
void double_w_haptics_projection(void)
{
  /* S-Function Block: <S6>/Block#1 */
  {
    _rtMech_PWORK *mechWork = (_rtMech_PWORK *)
      double_w_haptics_DWork.Block1_PWORK;
    mechWork->genSimData.time = double_w_haptics_M->Timing.t[0];
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
        rtmSetErrorStatus(double_w_haptics_M, errorMsg);
        return;
      }
    }
  }
}

/* This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y,x,
                nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  double_w_haptics_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  double_w_haptics_output(0);
  double_w_haptics_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++)
    hB[i] = h * rt_ODE3_B[1][i];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  double_w_haptics_output(0);
  double_w_haptics_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++)
    hB[i] = h * rt_ODE3_B[2][i];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  double_w_haptics_output(0);
  double_w_haptics_projection();
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void double_w_haptics_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_Derivative[3];
  real_T rtb_Falcon_o1[3];
  boolean_T rtb_Falcon_o2[4];

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(double_w_haptics_M)) {
    double_w_haptics_M->Timing.t[0] = rtsiGetT(&double_w_haptics_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(double_w_haptics_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&double_w_haptics_M->solverInfo,
                          ((double_w_haptics_M->Timing.clockTick0+1)*
      double_w_haptics_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(double_w_haptics_M) &&
      double_w_haptics_M->Timing.TaskCounters.TID[1] == 0) {
    /* Memory: '<S5>/Memory1' */
    rtb_Falcon_o1[0] = double_w_haptics_DWork.Memory1_PreviousInput[0];
    rtb_Falcon_o1[1] = double_w_haptics_DWork.Memory1_PreviousInput[1];
    rtb_Falcon_o1[2] = double_w_haptics_DWork.Memory1_PreviousInput[2];

    /* Sum: '<S5>/Sum' incorporates:
     *  Memory: '<S5>/Memory'
     */
    double_w_haptics_B.Sum[0] = double_w_haptics_DWork.Memory_PreviousInput[0] -
      rtb_Falcon_o1[0];
    double_w_haptics_B.Sum[1] = double_w_haptics_DWork.Memory_PreviousInput[1] -
      rtb_Falcon_o1[1];
    double_w_haptics_B.Sum[2] = double_w_haptics_DWork.Memory_PreviousInput[2] -
      rtb_Falcon_o1[2];

    /* Gain: '<S5>/ks' */
    double_w_haptics_B.ks[0] = double_w_haptics_P.ks_Gain *
      double_w_haptics_B.Sum[0];
    double_w_haptics_B.ks[1] = double_w_haptics_P.ks_Gain *
      double_w_haptics_B.Sum[1];
    double_w_haptics_B.ks[2] = double_w_haptics_P.ks_Gain *
      double_w_haptics_B.Sum[2];
  }

  /* Derivative Block: '<S5>/Derivative' */
  {
    real_T t = double_w_haptics_M->Timing.t[0];
    real_T timeStampA = double_w_haptics_DWork.Derivative_RWORK.TimeStampA;
    real_T timeStampB = double_w_haptics_DWork.Derivative_RWORK.TimeStampB;
    if (timeStampA >= t && timeStampB >= t) {
      rtb_Derivative[0] = 0.0;
      rtb_Derivative[1] = 0.0;
      rtb_Derivative[2] = 0.0;
    } else {
      real_T deltaT;
      real_T *lastBank = &double_w_haptics_DWork.Derivative_RWORK.TimeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastBank += 4;
        }
      } else if (timeStampA >= t) {
        lastBank += 4;
      }

      deltaT = t - *lastBank++;
      rtb_Derivative[0] = (double_w_haptics_B.Sum[0] - *lastBank++) / deltaT;
      rtb_Derivative[1] = (double_w_haptics_B.Sum[1] - *lastBank++) / deltaT;
      rtb_Derivative[2] = (double_w_haptics_B.Sum[2] - *lastBank++) / deltaT;
    }
  }

  /* Gain: '<S5>/ks1' */
  double_w_haptics_B.ks1[0] = double_w_haptics_P.ks1_Gain * rtb_Derivative[0];
  double_w_haptics_B.ks1[1] = double_w_haptics_P.ks1_Gain * rtb_Derivative[1];
  double_w_haptics_B.ks1[2] = double_w_haptics_P.ks1_Gain * rtb_Derivative[2];

  /* Sum: '<S5>/Sum1' */
  double_w_haptics_B.Sum1[0] = double_w_haptics_B.ks[0] +
    double_w_haptics_B.ks1[0];
  double_w_haptics_B.Sum1[1] = double_w_haptics_B.ks[1] +
    double_w_haptics_B.ks1[1];
  double_w_haptics_B.Sum1[2] = double_w_haptics_B.ks[2] +
    double_w_haptics_B.ks1[2];
  if (rtmIsMajorTimeStep(double_w_haptics_M) &&
      double_w_haptics_M->Timing.TaskCounters.TID[1] == 0) {
    /* Memory: '<Root>/Memory' */
    rtb_Falcon_o1[0] = double_w_haptics_DWork.Memory_PreviousInput_c[0];
    rtb_Falcon_o1[1] = double_w_haptics_DWork.Memory_PreviousInput_c[1];
    rtb_Falcon_o1[2] = double_w_haptics_DWork.Memory_PreviousInput_c[2];

    /* Saturate: '<Root>/Saturation1' */
    double_w_haptics_B.Saturation1[0] = rt_SATURATE(rtb_Falcon_o1[0],
      double_w_haptics_P.Saturation1_LowerSat,
      double_w_haptics_P.Saturation1_UpperSat);
    double_w_haptics_B.Saturation1[1] = rt_SATURATE(rtb_Falcon_o1[1],
      double_w_haptics_P.Saturation1_LowerSat,
      double_w_haptics_P.Saturation1_UpperSat);
    double_w_haptics_B.Saturation1[2] = rt_SATURATE(rtb_Falcon_o1[2],
      double_w_haptics_P.Saturation1_LowerSat,
      double_w_haptics_P.Saturation1_UpperSat);

    /* S-Function Block: double_w_haptics/Falcon (falcon_block) */
    {
      t_error result;
      double force_vector[3];
      double position[3];
      t_int read_buttons;
      force_vector[0] = double_w_haptics_B.Saturation1[2];
      force_vector[1] = double_w_haptics_B.Saturation1[0];
      force_vector[2] = double_w_haptics_B.Saturation1[1];

      /* read the position and buttons, and output the requested force to the falcon */
      result = falcon_read_write(double_w_haptics_DWork.Falcon_Falcon, position,
        &read_buttons, force_vector);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(double_w_haptics_M, _rt_error_message);
        return;
      }

      rtb_Falcon_o1[0] = position[0];
      rtb_Falcon_o1[1] = position[1];
      rtb_Falcon_o1[2] = position[2];
      rtb_Falcon_o2[0] = ((read_buttons & 0x01) != 0);
      rtb_Falcon_o2[1] = ((read_buttons & 0x02) != 0);
      rtb_Falcon_o2[2] = ((read_buttons & 0x04) != 0);
      rtb_Falcon_o2[3] = ((read_buttons & 0x08) != 0);
    }

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/trans'
     *  Gain: '<Root>/Gain1'
     */
    double_w_haptics_B.Sum_k[0] = double_w_haptics_P.Gain1_Gain[0] *
      rtb_Falcon_o1[1] + double_w_haptics_P.trans_Value;
    double_w_haptics_B.Sum_k[1] = double_w_haptics_P.Gain1_Gain[1] *
      rtb_Falcon_o1[2] + double_w_haptics_P.trans_Value;
    double_w_haptics_B.Sum_k[2] = double_w_haptics_P.Gain1_Gain[2] *
      rtb_Falcon_o1[0] + double_w_haptics_P.trans_Value;
  }

  /* S-Function Block: <S6>/Block#1 */
  {
    _rtMech_PWORK *mechWork = (_rtMech_PWORK *)
      double_w_haptics_DWork.Block1_PWORK;
    mechWork->genSimData.time = double_w_haptics_M->Timing.t[0];
    mechWork->outSimData.majorTimestep = rtmIsMajorTimeStep(double_w_haptics_M);
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
        rtmSetErrorStatus(double_w_haptics_M, errorMsg);
        return;
      }
    }
  }

  /* Gain: '<S2>/gain_1' */
  double_w_haptics_B.gain_1[0] = double_w_haptics_P.gain_1_Gain *
    double_w_haptics_B.Block1_o1[0];
  double_w_haptics_B.gain_1[1] = double_w_haptics_P.gain_1_Gain *
    double_w_haptics_B.Block1_o1[1];
  double_w_haptics_B.gain_1[2] = double_w_haptics_P.gain_1_Gain *
    double_w_haptics_B.Block1_o1[2];
  if (rtmIsMajorTimeStep(double_w_haptics_M) &&
      double_w_haptics_M->Timing.TaskCounters.TID[1] == 0) {
    /* Stop: '<Root>/Stop Simulation' */
    if (rtb_Falcon_o2[0]) {
      rtmSetStopRequested(double_w_haptics_M, 1);
    }
  }

  /* Gain: '<Root>/Gain2' */
  double_w_haptics_B.Gain2[0] = double_w_haptics_P.Gain2_Gain *
    double_w_haptics_B.Sum1[0];
  double_w_haptics_B.Gain2[1] = double_w_haptics_P.Gain2_Gain *
    double_w_haptics_B.Sum1[1];
  double_w_haptics_B.Gain2[2] = double_w_haptics_P.Gain2_Gain *
    double_w_haptics_B.Sum1[2];

  /* Gain: '<Root>/Gain3' */
  double_w_haptics_B.Gain3[0] = double_w_haptics_P.Gain3_Gain *
    double_w_haptics_B.Sum1[0];
  double_w_haptics_B.Gain3[1] = double_w_haptics_P.Gain3_Gain *
    double_w_haptics_B.Sum1[1];
  double_w_haptics_B.Gain3[2] = double_w_haptics_P.Gain3_Gain *
    double_w_haptics_B.Sum1[2];
  if (rtmIsMajorTimeStep(double_w_haptics_M) &&
      double_w_haptics_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S6>/_gravity_conversion' incorporates:
     *  Constant: '<S4>/SOURCE_BLOCK'
     */
    double_w_haptics_B._gravity_conversion[0] =
      double_w_haptics_P._gravity_conversion_Gain *
      double_w_haptics_P.SOURCE_BLOCK_Value[0];
    double_w_haptics_B._gravity_conversion[1] =
      double_w_haptics_P._gravity_conversion_Gain *
      double_w_haptics_P.SOURCE_BLOCK_Value[1];
    double_w_haptics_B._gravity_conversion[2] =
      double_w_haptics_P._gravity_conversion_Gain *
      double_w_haptics_P.SOURCE_BLOCK_Value[2];
  }

  /* S-Function Block: <S6>/Block#2 */
  {
    _rtMech_PWORK *mechWork = (_rtMech_PWORK *)
      double_w_haptics_DWork.Block2_PWORK;
    mechWork->genSimData.time = double_w_haptics_M->Timing.t[0];
    mechWork->outSimData.majorTimestep = rtmIsMajorTimeStep(double_w_haptics_M);
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
        rtmSetErrorStatus(double_w_haptics_M, errorMsg);
        return;
      }
    }
  }

  /* S-Function Block: <S6>/Block#3 */
  {
    _rtMech_PWORK *mechWork = (_rtMech_PWORK *)
      double_w_haptics_DWork.Block3_PWORK;
    mechWork->genSimData.time = double_w_haptics_M->Timing.t[0];
    mechWork->outSimData.majorTimestep = rtmIsMajorTimeStep(double_w_haptics_M);
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
        rtmSetErrorStatus(double_w_haptics_M, errorMsg);
        return;
      }
    }
  }

  UNUSED_PARAMETER(tid);
}

/* Model update function */
void double_w_haptics_update(int_T tid)
{
  if (rtmIsMajorTimeStep(double_w_haptics_M) &&
      double_w_haptics_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory: '<S5>/Memory' */
    double_w_haptics_DWork.Memory_PreviousInput[0] = double_w_haptics_B.gain_1[0];
    double_w_haptics_DWork.Memory_PreviousInput[1] = double_w_haptics_B.gain_1[1];
    double_w_haptics_DWork.Memory_PreviousInput[2] = double_w_haptics_B.gain_1[2];

    /* Update for Memory: '<S5>/Memory1' */
    double_w_haptics_DWork.Memory1_PreviousInput[0] = double_w_haptics_B.Sum_k[0];
    double_w_haptics_DWork.Memory1_PreviousInput[1] = double_w_haptics_B.Sum_k[1];
    double_w_haptics_DWork.Memory1_PreviousInput[2] = double_w_haptics_B.Sum_k[2];
  }

  /* Derivative Block: '<S5>/Derivative' */
  {
    real_T timeStampA = double_w_haptics_DWork.Derivative_RWORK.TimeStampA;
    real_T timeStampB = double_w_haptics_DWork.Derivative_RWORK.TimeStampB;
    real_T *lastBank = &double_w_haptics_DWork.Derivative_RWORK.TimeStampA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastBank += 4;
      } else if (timeStampA >= timeStampB) {
        lastBank += 4;
      }
    }

    *lastBank++ = double_w_haptics_M->Timing.t[0];
    *lastBank++ = double_w_haptics_B.Sum[0];
    *lastBank++ = double_w_haptics_B.Sum[1];
    *lastBank++ = double_w_haptics_B.Sum[2];
  }

  if (rtmIsMajorTimeStep(double_w_haptics_M) &&
      double_w_haptics_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory: '<Root>/Memory' */
    double_w_haptics_DWork.Memory_PreviousInput_c[0] = double_w_haptics_B.Gain2
      [0];
    double_w_haptics_DWork.Memory_PreviousInput_c[1] = double_w_haptics_B.Gain2
      [1];
    double_w_haptics_DWork.Memory_PreviousInput_c[2] = double_w_haptics_B.Gain2
      [2];
  }

  if (rtmIsMajorTimeStep(double_w_haptics_M)) {
    rt_ertODEUpdateContinuousStates(&double_w_haptics_M->solverInfo);
  }

  /* Update absolute time for base rate */
  if (!(++double_w_haptics_M->Timing.clockTick0))
    ++double_w_haptics_M->Timing.clockTickH0;
  double_w_haptics_M->Timing.t[0] = double_w_haptics_M->Timing.clockTick0 *
    double_w_haptics_M->Timing.stepSize0 +
    double_w_haptics_M->Timing.clockTickH0 *
    double_w_haptics_M->Timing.stepSize0 * 4294967296.0;
  if (rtmIsMajorTimeStep(double_w_haptics_M) &&
      double_w_haptics_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    if (!(++double_w_haptics_M->Timing.clockTick1))
      ++double_w_haptics_M->Timing.clockTickH1;
    double_w_haptics_M->Timing.t[1] = double_w_haptics_M->Timing.clockTick1 *
      double_w_haptics_M->Timing.stepSize1 +
      double_w_haptics_M->Timing.clockTickH1 *
      double_w_haptics_M->Timing.stepSize1 * 4294967296.0;
  }

  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void double_w_haptics_derivatives(void)
{
  /* S-Function Block: <S6>/Block#1 */
  {
    _rtMech_PWORK *mechWork = (_rtMech_PWORK *)
      double_w_haptics_DWork.Block1_PWORK;
    if (sFcnDerivativesMethod(mechWork->mechanism,
         &((StateDerivatives_double_w_hapti *)
           double_w_haptics_M->ModelData.derivs)->Block1_CSTATE[0])) {
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
        rtmSetErrorStatus(double_w_haptics_M, errorMsg);
        return;
      }
    }
  }
}

/* Model initialize function */
void double_w_haptics_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));    /* initialize real-time model */
  (void) memset((char_T *)double_w_haptics_M,0,
                sizeof(RT_MODEL_double_w_haptics));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&double_w_haptics_M->solverInfo,
                          &double_w_haptics_M->Timing.simTimeStep);
    rtsiSetTPtr(&double_w_haptics_M->solverInfo, &rtmGetTPtr(double_w_haptics_M));
    rtsiSetStepSizePtr(&double_w_haptics_M->solverInfo,
                       &double_w_haptics_M->Timing.stepSize0);
    rtsiSetdXPtr(&double_w_haptics_M->solverInfo,
                 &double_w_haptics_M->ModelData.derivs);
    rtsiSetContStatesPtr(&double_w_haptics_M->solverInfo,
                         &double_w_haptics_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&double_w_haptics_M->solverInfo,
      &double_w_haptics_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&double_w_haptics_M->solverInfo, (&rtmGetErrorStatus
      (double_w_haptics_M)));
    rtsiSetRTModelPtr(&double_w_haptics_M->solverInfo, double_w_haptics_M);
  }

  rtsiSetSimTimeStep(&double_w_haptics_M->solverInfo, MAJOR_TIME_STEP);
  double_w_haptics_M->ModelData.intgData.y = double_w_haptics_M->ModelData.odeY;
  double_w_haptics_M->ModelData.intgData.f[0] =
    double_w_haptics_M->ModelData.odeF[0];
  double_w_haptics_M->ModelData.intgData.f[1] =
    double_w_haptics_M->ModelData.odeF[1];
  double_w_haptics_M->ModelData.intgData.f[2] =
    double_w_haptics_M->ModelData.odeF[2];
  double_w_haptics_M->ModelData.contStates = ((real_T *) &double_w_haptics_X);
  rtsiSetSolverData(&double_w_haptics_M->solverInfo, (void *)
                    &double_w_haptics_M->ModelData.intgData);
  rtsiSetSolverName(&double_w_haptics_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = double_w_haptics_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    double_w_haptics_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    double_w_haptics_M->Timing.sampleTimes =
      (&double_w_haptics_M->Timing.sampleTimesArray[0]);
    double_w_haptics_M->Timing.offsetTimes =
      (&double_w_haptics_M->Timing.offsetTimesArray[0]);

    /* task periods */
    double_w_haptics_M->Timing.sampleTimes[0] = (0.0);
    double_w_haptics_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    double_w_haptics_M->Timing.offsetTimes[0] = (0.0);
    double_w_haptics_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(double_w_haptics_M, &double_w_haptics_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = double_w_haptics_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    double_w_haptics_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(double_w_haptics_M, -1);
  double_w_haptics_M->Timing.stepSize0 = 0.01;
  double_w_haptics_M->Timing.stepSize1 = 0.01;

  /* external mode info */
  double_w_haptics_M->Sizes.checksums[0] = (1599923205U);
  double_w_haptics_M->Sizes.checksums[1] = (3579604898U);
  double_w_haptics_M->Sizes.checksums[2] = (3779150750U);
  double_w_haptics_M->Sizes.checksums[3] = (2205369005U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    double_w_haptics_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &double_w_haptics_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, double_w_haptics_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(double_w_haptics_M));
  }

  double_w_haptics_M->solverInfoPtr = (&double_w_haptics_M->solverInfo);
  double_w_haptics_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&double_w_haptics_M->solverInfo, 0.01);
  rtsiSetSolverMode(&double_w_haptics_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  double_w_haptics_M->ModelData.blockIO = ((void *) &double_w_haptics_B);

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&double_w_haptics_B.Sum[0]);
    for (i = 0; i < 40; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }
  }

  /* parameters */
  double_w_haptics_M->ModelData.defaultParam = ((real_T *) &double_w_haptics_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &double_w_haptics_X;
    double_w_haptics_M->ModelData.contStates = (x);
    (void) memset((char_T *)x,0,
                  sizeof(ContinuousStates_double_w_hapti));
  }

  /* states (dwork) */
  double_w_haptics_M->Work.dwork = ((void *) &double_w_haptics_DWork);
  (void) memset((char_T *) &double_w_haptics_DWork,0,
                sizeof(D_Work_double_w_haptics));

  {
    int_T i;
    real_T *dwork_ptr = (real_T *) &double_w_haptics_DWork.Memory_PreviousInput
      [0];
    for (i = 0; i < 17; i++) {
      dwork_ptr[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    double_w_haptics_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }
}

/* Model terminate function */
void double_w_haptics_terminate(void)
{
  /* S-Function Block: double_w_haptics/Falcon (falcon_block) */
  {
    t_error result;
    result = falcon_close(double_w_haptics_DWork.Falcon_Falcon);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(double_w_haptics_M, _rt_error_message);
      return;
    }
  }

  /* S-Function Block: <S6>/Block#1 */
  {
    if (rt_mech_visited_double_w_haptics_1460d8f1 == 1) {
      _rtMech_PWORK *mechWork = (_rtMech_PWORK *)
        double_w_haptics_DWork.Block1_PWORK;
      if (mechWork->mechanism->destroyEngine != NULL) {
        (mechWork->mechanism->destroyEngine)(mechWork->mechanism);
      }
    }

    if ((--rt_mech_visited_double_w_haptics_1460d8f1) == 0 ) {
      rt_mech_visited_loc_double_w_haptics_1460d8f1 = 0;
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
  double_w_haptics_output(tid);
}

void MdlUpdate(int_T tid)
{
  double_w_haptics_update(tid);
}

void MdlInitializeSizes(void)
{
  double_w_haptics_M->Sizes.numContStates = (4);/* Number of continuous states */
  double_w_haptics_M->Sizes.numY = (0);/* Number of model outputs */
  double_w_haptics_M->Sizes.numU = (0);/* Number of model inputs */
  double_w_haptics_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  double_w_haptics_M->Sizes.numSampTimes = (2);/* Number of sample times */
  double_w_haptics_M->Sizes.numBlocks = (44);/* Number of blocks */
  double_w_haptics_M->Sizes.numBlockIO = (15);/* Number of block outputs */
  double_w_haptics_M->Sizes.numBlockPrms = (95);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for Memory: '<S5>/Memory' */
  double_w_haptics_DWork.Memory_PreviousInput[0] = double_w_haptics_P.Memory_X0;
  double_w_haptics_DWork.Memory_PreviousInput[1] = double_w_haptics_P.Memory_X0;
  double_w_haptics_DWork.Memory_PreviousInput[2] = double_w_haptics_P.Memory_X0;

  /* InitializeConditions for Memory: '<S5>/Memory1' */
  double_w_haptics_DWork.Memory1_PreviousInput[0] =
    double_w_haptics_P.Memory1_X0;
  double_w_haptics_DWork.Memory1_PreviousInput[1] =
    double_w_haptics_P.Memory1_X0;
  double_w_haptics_DWork.Memory1_PreviousInput[2] =
    double_w_haptics_P.Memory1_X0;

  /* Derivative Block: '<S5>/Derivative' */
  double_w_haptics_DWork.Derivative_RWORK.TimeStampA = rtInf;
  double_w_haptics_DWork.Derivative_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for Memory: '<Root>/Memory' */
  double_w_haptics_DWork.Memory_PreviousInput_c[0] =
    double_w_haptics_P.Memory_X0_d;
  double_w_haptics_DWork.Memory_PreviousInput_c[1] =
    double_w_haptics_P.Memory_X0_d;
  double_w_haptics_DWork.Memory_PreviousInput_c[2] =
    double_w_haptics_P.Memory_X0_d;

  /* S-Function Block: <S6>/Block#1 */
  {
    static _rtMech_PWORK mechWork;
    static ErrorRecord errorRec;
    if (rtmIsFirstInitCond(double_w_haptics_M)) {
      const int locationFlag = __LINE__;
      if (rt_mech_visited_loc_double_w_haptics_1460d8f1 == 0 ) {
        rt_mech_visited_loc_double_w_haptics_1460d8f1 = locationFlag;
      }

      if (rt_mech_visited_loc_double_w_haptics_1460d8f1 == locationFlag ) {
        if ((++rt_mech_visited_double_w_haptics_1460d8f1) != 1) {
          static const char reentranterrormsg[] =
            "Attempting to use multiple instances of SimMechanics generated code";
          rtmSetErrorStatus(double_w_haptics_M, reentranterrormsg);
          return;
        }
      }

      mechWork.mechanism = rt_get_mechanism_double_w_haptics_1460d8f1();
      mechWork.mechanism->engineError = &errorRec;
      mechWork.mechanism->engineError->errorFlag = false;

      {
        static char errorMsg[1024];
        if ((mechWork.mechanism->mapRuntimeData)(mechWork.mechanism,
             double_w_haptics_P.Block1_SimMechanicsRuntimeParam, errorMsg,
             sizeof(errorMsg) - 1)) {
          rtmSetErrorStatus(double_w_haptics_M, errorMsg);
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
          , NULL
          , mech_Tt_fdXc5y2Dg685RDenWd1
          , NULL
          , mech_lXjmQCmQ9KYdo3NotOWF50
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
          , mech_Cgu0lKThtzqrZoLtCnwjJ_
          , mech_7aIKRF_YGZdePwxsVRxfZ2
          , NULL
          , NULL
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
          , NULL
          , NULL
          , mech_a_17m3gydYlTeUU7HvysF0
          , mech__MLGR2zPV8GQNF039XoEV2
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
          , mech_OHckGNNEJwON5eZqEeLzi0
          , NULL
          , mech__K9V_2xZBC8lWckjTxcwv2
          , NULL
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
          , mech_H2CpDYCpvxvkzfBP3eSON1
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
          , mech_th7tzcG4WkxfeSEgprwRI2
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
          , NULL
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
          , NULL
          , NULL
          , NULL
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
          , NULL
          , NULL
          , NULL
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
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
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
          , mech_YLlDEY62bKu6q8tuZBo5x0
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
          , mech_8iHff_rVIjjhbiiPfQqDA1
          , NULL
          , NULL
          , mech_5wQbk_zOuJGXAaiJyVzLQ1
          , NULL
          , NULL
          , NULL
          , NULL
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
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_wn4jlCEwb7bynhe7vagGC_
          , NULL
          , NULL
          , mech_ZVdknpwSY_5rh59_L8Z_s0
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_cR0B84p7D4fGeJs1kDmO0_
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
          rtmSetErrorStatus(double_w_haptics_M, errorMsg);
          return;
        }
      }

      mechWork.mechanism->state = &double_w_haptics_X.Block1_CSTATE[0];
      double_w_haptics_DWork.Block1_IWORK = 0U;
      mechWork.genSimData.tStart = (0.0);
      mechWork.genSimData.iwork = &double_w_haptics_DWork.Block1_IWORK;
      mechWork.genSimData.numInputPorts = 2;

      {
        static real_T *mech_inputSignals[3];
        mech_inputSignals[0] = (real_T *) double_w_haptics_B.Gain3;
        mech_inputSignals[1] = (real_T *) &double_w_haptics_B.Gain3[1];
        mech_inputSignals[2] = (real_T *) &double_w_haptics_B.Gain3[2];
        mechWork.genSimData.inputSignals[0] = mech_inputSignals;
      }

      {
        static real_T *mech_inputSignals[3];
        mech_inputSignals[0] = (real_T *) double_w_haptics_B._gravity_conversion;
        mech_inputSignals[1] = (real_T *)
          &double_w_haptics_B._gravity_conversion[1];
        mech_inputSignals[2] = (real_T *)
          &double_w_haptics_B._gravity_conversion[2];
        mechWork.genSimData.inputSignals[1] = mech_inputSignals;
      }

      mechWork.outSimData.numOutputPorts = 3;
      mechWork.outSimData.logOutput = false;
      mechWork.outSimData.outputSignals[0] = double_w_haptics_B.Block1_o1;
      mechWork.outSimData.outputSignals[1] = double_w_haptics_B.Block1_o2;
      mechWork.outSimData.outputSignals[2] = &double_w_haptics_B.Block1_o3;
      double_w_haptics_DWork.Block1_PWORK = &mechWork;
    }
  }

  /* S-Function Block: <S6>/Block#2 */
  {
    static _rtMech_PWORK mechWork;
    static ErrorRecord errorRec;
    if (rtmIsFirstInitCond(double_w_haptics_M)) {
      mechWork.mechanism = rt_get_mechanism_double_w_haptics_1460d8f1();
      mechWork.mechanism->engineError = &errorRec;
      mechWork.mechanism->engineError->errorFlag = false;
      mechWork.genSimData.tStart = (0.0);
      mechWork.genSimData.iwork = NULL;
      mechWork.genSimData.numInputPorts = 4;

      {
        static real_T *mech_inputSignals[3];
        mech_inputSignals[0] = (real_T *) double_w_haptics_B.Gain3;
        mech_inputSignals[1] = (real_T *) &double_w_haptics_B.Gain3[1];
        mech_inputSignals[2] = (real_T *) &double_w_haptics_B.Gain3[2];
        mechWork.genSimData.inputSignals[0] = mech_inputSignals;
      }

      {
        static real_T *mech_inputSignals[4];
        mech_inputSignals[0] = (real_T *) double_w_haptics_B.Block1_o2;
        mech_inputSignals[1] = (real_T *) &double_w_haptics_B.Block1_o2[1];
        mech_inputSignals[2] = (real_T *) &double_w_haptics_B.Block1_o2[2];
        mech_inputSignals[3] = (real_T *) &double_w_haptics_B.Block1_o2[3];
        mechWork.genSimData.inputSignals[1] = mech_inputSignals;
      }

      {
        static real_T *mech_inputSignals[1];
        mech_inputSignals[0] = (real_T *) &double_w_haptics_B.Block1_o3;
        mechWork.genSimData.inputSignals[2] = mech_inputSignals;
      }

      {
        static real_T *mech_inputSignals[3];
        mech_inputSignals[0] = (real_T *) double_w_haptics_B._gravity_conversion;
        mech_inputSignals[1] = (real_T *)
          &double_w_haptics_B._gravity_conversion[1];
        mech_inputSignals[2] = (real_T *)
          &double_w_haptics_B._gravity_conversion[2];
        mechWork.genSimData.inputSignals[3] = mech_inputSignals;
      }

      mechWork.outSimData.numOutputPorts = 1;
      mechWork.outSimData.logOutput = false;
      mechWork.outSimData.outputSignals[0] = &double_w_haptics_B.Block2;
      double_w_haptics_DWork.Block2_PWORK = &mechWork;
    }
  }

  /* S-Function Block: <S6>/Block#3 */
  {
    static _rtMech_PWORK mechWork;
    static ErrorRecord errorRec;
    if (rtmIsFirstInitCond(double_w_haptics_M)) {
      mechWork.mechanism = rt_get_mechanism_double_w_haptics_1460d8f1();
      mechWork.mechanism->engineError = &errorRec;
      mechWork.mechanism->engineError->errorFlag = false;
      double_w_haptics_DWork.Block3_IWORK = 1U;
      mechWork.genSimData.tStart = (0.0);
      mechWork.genSimData.iwork = &double_w_haptics_DWork.Block3_IWORK;
      mechWork.genSimData.numInputPorts = 1;

      {
        static real_T *mech_inputSignals[1];
        mech_inputSignals[0] = (real_T *) &double_w_haptics_B.Block2;
        mechWork.genSimData.inputSignals[0] = mech_inputSignals;
      }

      mechWork.outSimData.numOutputPorts = 1;
      mechWork.outSimData.logOutput = false;
      mechWork.outSimData.outputSignals[0] = &double_w_haptics_B.Block3;
      double_w_haptics_DWork.Block3_PWORK = &mechWork;
    }
  }
}

void MdlStart(void)
{
  /* S-Function Block: double_w_haptics/Falcon (falcon_block) */
  {
    t_error result;
    result = falcon_open(&double_w_haptics_DWork.Falcon_Falcon);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(double_w_haptics_M, _rt_error_message);
      return;
    }
  }

  MdlInitialize();
}

RT_MODEL_double_w_haptics *double_w_haptics(void)
{
  double_w_haptics_initialize(1);
  return double_w_haptics_M;
}

void MdlTerminate(void)
{
  double_w_haptics_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
