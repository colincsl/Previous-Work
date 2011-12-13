/*
 * Crane.c
 *
 * Real-Time Workshop code generation for Simulink model "Crane.mdl".
 *
 * Model Version              : 1.65
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Tue Jan 12 17:09:02 2010
 */

#include "Crane.h"
#include "Crane_private.h"
#include <stdio.h>
#include "Crane_dt.h"

/* Block signals (auto storage) */
BlockIO_Crane Crane_B;

/* Continuous states */
ContinuousStates_Crane Crane_X;

/* Block states (auto storage) */
D_Work_Crane Crane_DWork;

/* Real-time model */
RT_MODEL_Crane Crane_M_;
RT_MODEL_Crane *Crane_M = &Crane_M_;

/* Projection for root system: '<Root>' */
void Crane_projection(void)
{
  /* S-Function Block: <S10>/Block#1 */
  {
    _rtMech_PWORK *mechWork = (_rtMech_PWORK *) Crane_DWork.Block1_PWORK;
    mechWork->genSimData.time = Crane_M->Timing.t[0];
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
        rtmSetErrorStatus(Crane_M, errorMsg);
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
  int_T nXc = 21;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Crane_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  Crane_output(0);
  Crane_projection();
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Crane_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_Falcon_o1[3];
  real_T rtb_Gain4[3];
  boolean_T rtb_Falcon_o2[4];

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Crane_M)) {
    Crane_M->Timing.t[0] = rtsiGetT(&Crane_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Crane_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&Crane_M->solverInfo,
                          ((Crane_M->Timing.clockTick0+1)*
      Crane_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  {
    real_T rtb_Product_idx;
    real_T rtb_Product_idx_0;
    real_T rtb_Product_idx_1;
    real_T rtb_Product1_idx;
    real_T rtb_Product1_idx_0;
    real_T rtb_Product1_idx_1;

    /* S-Function Block: <S10>/Block#1 */
    {
      _rtMech_PWORK *mechWork = (_rtMech_PWORK *) Crane_DWork.Block1_PWORK;
      mechWork->genSimData.time = Crane_M->Timing.t[0];
      mechWork->outSimData.majorTimestep = rtmIsMajorTimeStep(Crane_M);
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
          rtmSetErrorStatus(Crane_M, errorMsg);
          return;
        }
      }
    }

    /* Gain: '<S2>/gain_1' */
    Crane_B.gain_1[0] = Crane_P.gain_1_Gain * Crane_B.Block1_o1[0];
    Crane_B.gain_1[1] = Crane_P.gain_1_Gain * Crane_B.Block1_o1[1];
    Crane_B.gain_1[2] = Crane_P.gain_1_Gain * Crane_B.Block1_o1[2];
    if (rtmIsMajorTimeStep(Crane_M) &&
        Crane_M->Timing.TaskCounters.TID[1] == 0) {
      /* Memory: '<Root>/Memory' */
      Crane_B.Memory[0] = Crane_DWork.Memory_PreviousInput[0];
      Crane_B.Memory[1] = Crane_DWork.Memory_PreviousInput[1];
      Crane_B.Memory[2] = Crane_DWork.Memory_PreviousInput[2];
    }

    /* Sum: '<S9>/Sum' */
    Crane_B.Sum[0] = Crane_B.Memory[0] - Crane_B.gain_1[0];
    Crane_B.Sum[1] = Crane_B.Memory[1] - Crane_B.gain_1[1];
    Crane_B.Sum[2] = Crane_B.Memory[2] - Crane_B.gain_1[2];

    /* Product: '<S9>/Product' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    rtb_Product_idx = Crane_P.Constant2_Value * Crane_B.Sum[0];
    rtb_Product_idx_0 = Crane_P.Constant2_Value * Crane_B.Sum[1];
    rtb_Product_idx_1 = Crane_P.Constant2_Value * Crane_B.Sum[2];

    /* Integrator: '<S9>/Integrator' */
    rtb_Gain4[0] = Crane_X.Integrator_CSTATE[0];
    rtb_Gain4[1] = Crane_X.Integrator_CSTATE[1];
    rtb_Gain4[2] = Crane_X.Integrator_CSTATE[2];

    /* Product: '<S9>/Product1' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    rtb_Product1_idx = Crane_P.Constant5_Value * rtb_Gain4[0];
    rtb_Product1_idx_0 = Crane_P.Constant5_Value * rtb_Gain4[1];
    rtb_Product1_idx_1 = Crane_P.Constant5_Value * rtb_Gain4[2];

    /* Derivative Block: '<S9>/Derivative' */
    {
      real_T t = Crane_M->Timing.t[0];
      real_T timeStampA = Crane_DWork.Derivative_RWORK.TimeStampA;
      real_T timeStampB = Crane_DWork.Derivative_RWORK.TimeStampB;
      if (timeStampA >= t && timeStampB >= t) {
        rtb_Gain4[0] = 0.0;
        rtb_Gain4[1] = 0.0;
        rtb_Gain4[2] = 0.0;
      } else {
        real_T deltaT;
        real_T *lastBank = &Crane_DWork.Derivative_RWORK.TimeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastBank += 4;
          }
        } else if (timeStampA >= t) {
          lastBank += 4;
        }

        deltaT = t - *lastBank++;
        rtb_Gain4[0] = (Crane_B.Sum[0] - *lastBank++) / deltaT;
        rtb_Gain4[1] = (Crane_B.Sum[1] - *lastBank++) / deltaT;
        rtb_Gain4[2] = (Crane_B.Sum[2] - *lastBank++) / deltaT;
      }
    }

    /* Sum: '<S9>/Sum1' incorporates:
     *  Constant: '<Root>/Constant6'
     *  Product: '<S9>/Product2'
     */
    Crane_B.Sum1[0] = (rtb_Product_idx + rtb_Product1_idx) +
      Crane_P.Constant6_Value * rtb_Gain4[0];
    Crane_B.Sum1[1] = (rtb_Product_idx_0 + rtb_Product1_idx_0) +
      Crane_P.Constant6_Value * rtb_Gain4[1];
    Crane_B.Sum1[2] = (rtb_Product_idx_1 + rtb_Product1_idx_1) +
      Crane_P.Constant6_Value * rtb_Gain4[2];

    /* Gain: '<Root>/Gain4' */
    rtb_Gain4[0] = Crane_P.Gain4_Gain * Crane_B.Sum1[0];
    rtb_Gain4[1] = Crane_P.Gain4_Gain * Crane_B.Sum1[1];
    rtb_Gain4[2] = Crane_P.Gain4_Gain * Crane_B.Sum1[2];

    /* Saturate: '<Root>/Saturation' */
    Crane_B.Saturation[0] = rt_SATURATE(rtb_Gain4[2],
      Crane_P.Saturation_LowerSat, Crane_P.Saturation_UpperSat);
    Crane_B.Saturation[1] = rt_SATURATE(rtb_Gain4[0],
      Crane_P.Saturation_LowerSat, Crane_P.Saturation_UpperSat);
    Crane_B.Saturation[2] = rt_SATURATE(rtb_Gain4[1],
      Crane_P.Saturation_LowerSat, Crane_P.Saturation_UpperSat);
    if (rtmIsMajorTimeStep(Crane_M) &&
        Crane_M->Timing.TaskCounters.TID[1] == 0) {
      /* S-Function Block: Crane/Falcon (falcon_block) */
      {
        t_error result;
        double force_vector[3];
        double position[3];
        t_int read_buttons;
        force_vector[0] = Crane_B.Saturation[0];
        force_vector[1] = Crane_B.Saturation[1];
        force_vector[2] = Crane_B.Saturation[2];

        /* read the position and buttons, and output the requested force to the falcon */
        result = falcon_read_write(Crane_DWork.Falcon_Falcon, position,
          &read_buttons, force_vector);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Crane_M, _rt_error_message);
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

      /* Gain: '<Root>/Gain3' */
      Crane_B.Gain3[0] = Crane_P.Gain3_Gain * rtb_Falcon_o1[0];
      Crane_B.Gain3[1] = Crane_P.Gain3_Gain * rtb_Falcon_o1[1];
      Crane_B.Gain3[2] = Crane_P.Gain3_Gain * rtb_Falcon_o1[2];

      /* Constant: '<Root>/Constant' */
      Crane_B.Constant = Crane_P.Constant_Value;

      /* Stop: '<Root>/Stop Simulation' */
      if (rtb_Falcon_o2[0] || rtb_Falcon_o2[1] || rtb_Falcon_o2[2] ||
          rtb_Falcon_o2[3]) {
        rtmSetStopRequested(Crane_M, 1);
      }

      /* Gain: '<Root>/Gain2' incorporates:
       *  Constant: '<Root>/Constant1'
       */
      Crane_B.Gain2 = Crane_P.Gain2_Gain * Crane_P.Constant1_Value;

      /* Gain: '<Root>/Gain1' incorporates:
       *  Constant: '<Root>/Constant3'
       */
      Crane_B.Gain1 = Crane_P.Gain1_Gain * Crane_P.Constant3_Value;
    }

    /* Gain: '<Root>/Gain' incorporates:
     *  Sin: '<Root>/Sine Wave'
     */
    Crane_B.Gain = (sin(Crane_P.SineWave_Freq * Crane_M->Timing.t[0] +
                        Crane_P.SineWave_Phase) * Crane_P.SineWave_Amp +
                    Crane_P.SineWave_Bias) * Crane_P.Gain_Gain;
    if (rtmIsMajorTimeStep(Crane_M) &&
        Crane_M->Timing.TaskCounters.TID[1] == 0) {
      /* Gain: '<S10>/_gravity_conversion' incorporates:
       *  Constant: '<S8>/SOURCE_BLOCK'
       */
      Crane_B._gravity_conversion[0] = Crane_P._gravity_conversion_Gain *
        Crane_P.SOURCE_BLOCK_Value[0];
      Crane_B._gravity_conversion[1] = Crane_P._gravity_conversion_Gain *
        Crane_P.SOURCE_BLOCK_Value[1];
      Crane_B._gravity_conversion[2] = Crane_P._gravity_conversion_Gain *
        Crane_P.SOURCE_BLOCK_Value[2];
    }

    /* S-Function Block: <S10>/Block#2 */
    {
      _rtMech_PWORK *mechWork = (_rtMech_PWORK *) Crane_DWork.Block2_PWORK;
      mechWork->genSimData.time = Crane_M->Timing.t[0];
      mechWork->outSimData.majorTimestep = rtmIsMajorTimeStep(Crane_M);
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
          rtmSetErrorStatus(Crane_M, errorMsg);
          return;
        }
      }
    }

    /* S-Function Block: <S10>/Block#3 */
    {
      _rtMech_PWORK *mechWork = (_rtMech_PWORK *) Crane_DWork.Block3_PWORK;
      mechWork->genSimData.time = Crane_M->Timing.t[0];
      mechWork->outSimData.majorTimestep = rtmIsMajorTimeStep(Crane_M);
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
          rtmSetErrorStatus(Crane_M, errorMsg);
          return;
        }
      }
    }
  }

  UNUSED_PARAMETER(tid);
}

/* Model update function */
void Crane_update(int_T tid)
{
  if (rtmIsMajorTimeStep(Crane_M) &&
      Crane_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory: '<Root>/Memory' */
    Crane_DWork.Memory_PreviousInput[0] = Crane_B.Gain3[1];
    Crane_DWork.Memory_PreviousInput[1] = Crane_B.Gain3[2];
    Crane_DWork.Memory_PreviousInput[2] = Crane_B.Constant;
  }

  /* Derivative Block: '<S9>/Derivative' */
  {
    real_T timeStampA = Crane_DWork.Derivative_RWORK.TimeStampA;
    real_T timeStampB = Crane_DWork.Derivative_RWORK.TimeStampB;
    real_T *lastBank = &Crane_DWork.Derivative_RWORK.TimeStampA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastBank += 4;
      } else if (timeStampA >= timeStampB) {
        lastBank += 4;
      }
    }

    *lastBank++ = Crane_M->Timing.t[0];
    *lastBank++ = Crane_B.Sum[0];
    *lastBank++ = Crane_B.Sum[1];
    *lastBank++ = Crane_B.Sum[2];
  }

  if (rtmIsMajorTimeStep(Crane_M)) {
    rt_ertODEUpdateContinuousStates(&Crane_M->solverInfo);
  }

  /* Update absolute time for base rate */
  if (!(++Crane_M->Timing.clockTick0))
    ++Crane_M->Timing.clockTickH0;
  Crane_M->Timing.t[0] = Crane_M->Timing.clockTick0 * Crane_M->Timing.stepSize0
    + Crane_M->Timing.clockTickH0 * Crane_M->Timing.stepSize0 * 4294967296.0;
  if (rtmIsMajorTimeStep(Crane_M) &&
      Crane_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    if (!(++Crane_M->Timing.clockTick1))
      ++Crane_M->Timing.clockTickH1;
    Crane_M->Timing.t[1] = Crane_M->Timing.clockTick1 *
      Crane_M->Timing.stepSize1 + Crane_M->Timing.clockTickH1 *
      Crane_M->Timing.stepSize1 * 4294967296.0;
  }

  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void Crane_derivatives(void)
{
  /* S-Function Block: <S10>/Block#1 */
  {
    _rtMech_PWORK *mechWork = (_rtMech_PWORK *) Crane_DWork.Block1_PWORK;
    if (sFcnDerivativesMethod(mechWork->mechanism, &((StateDerivatives_Crane *)
          Crane_M->ModelData.derivs)->Block1_CSTATE[0])) {
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
        rtmSetErrorStatus(Crane_M, errorMsg);
        return;
      }
    }
  }

  /* Derivatives for Integrator: '<S9>/Integrator' */
  ((StateDerivatives_Crane *) Crane_M->ModelData.derivs)->Integrator_CSTATE[0] =
    Crane_B.Sum[0];
  ((StateDerivatives_Crane *) Crane_M->ModelData.derivs)->Integrator_CSTATE[1] =
    Crane_B.Sum[1];
  ((StateDerivatives_Crane *) Crane_M->ModelData.derivs)->Integrator_CSTATE[2] =
    Crane_B.Sum[2];
}

/* Model initialize function */
void Crane_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));    /* initialize real-time model */
  (void) memset((char_T *)Crane_M,0,
                sizeof(RT_MODEL_Crane));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Crane_M->solverInfo, &Crane_M->Timing.simTimeStep);
    rtsiSetTPtr(&Crane_M->solverInfo, &rtmGetTPtr(Crane_M));
    rtsiSetStepSizePtr(&Crane_M->solverInfo, &Crane_M->Timing.stepSize0);
    rtsiSetdXPtr(&Crane_M->solverInfo, &Crane_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Crane_M->solverInfo, &Crane_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Crane_M->solverInfo, &Crane_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Crane_M->solverInfo, (&rtmGetErrorStatus(Crane_M)));
    rtsiSetRTModelPtr(&Crane_M->solverInfo, Crane_M);
  }

  rtsiSetSimTimeStep(&Crane_M->solverInfo, MAJOR_TIME_STEP);
  Crane_M->ModelData.intgData.f[0] = Crane_M->ModelData.odeF[0];
  Crane_M->ModelData.contStates = ((real_T *) &Crane_X);
  rtsiSetSolverData(&Crane_M->solverInfo, (void *)&Crane_M->ModelData.intgData);
  rtsiSetSolverName(&Crane_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Crane_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Crane_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Crane_M->Timing.sampleTimes = (&Crane_M->Timing.sampleTimesArray[0]);
    Crane_M->Timing.offsetTimes = (&Crane_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Crane_M->Timing.sampleTimes[0] = (0.0);
    Crane_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    Crane_M->Timing.offsetTimes[0] = (0.0);
    Crane_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Crane_M, &Crane_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Crane_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Crane_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Crane_M, -1);
  Crane_M->Timing.stepSize0 = 0.001;
  Crane_M->Timing.stepSize1 = 0.001;

  /* external mode info */
  Crane_M->Sizes.checksums[0] = (2478158774U);
  Crane_M->Sizes.checksums[1] = (3803381746U);
  Crane_M->Sizes.checksums[2] = (277883647U);
  Crane_M->Sizes.checksums[3] = (670793414U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Crane_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &Crane_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, Crane_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(Crane_M));
  }

  Crane_M->solverInfoPtr = (&Crane_M->solverInfo);
  Crane_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Crane_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Crane_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Crane_M->ModelData.blockIO = ((void *) &Crane_B);

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&Crane_B.Block1_o1[0]);
    for (i = 0; i < 49; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }
  }

  /* parameters */
  Crane_M->ModelData.defaultParam = ((real_T *) &Crane_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Crane_X;
    Crane_M->ModelData.contStates = (x);
    (void) memset((char_T *)x,0,
                  sizeof(ContinuousStates_Crane));
  }

  /* states (dwork) */
  Crane_M->Work.dwork = ((void *) &Crane_DWork);
  (void) memset((char_T *) &Crane_DWork,0,
                sizeof(D_Work_Crane));

  {
    int_T i;
    real_T *dwork_ptr = (real_T *) &Crane_DWork.Memory_PreviousInput[0];
    for (i = 0; i < 11; i++) {
      dwork_ptr[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    Crane_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void Crane_terminate(void)
{
  /* S-Function Block: <S10>/Block#1 */
  {
    if (rt_mech_visited_Crane_63fd34a2 == 1) {
      _rtMech_PWORK *mechWork = (_rtMech_PWORK *) Crane_DWork.Block1_PWORK;
      if (mechWork->mechanism->destroyEngine != NULL) {
        (mechWork->mechanism->destroyEngine)(mechWork->mechanism);
      }
    }

    if ((--rt_mech_visited_Crane_63fd34a2) == 0 ) {
      rt_mech_visited_loc_Crane_63fd34a2 = 0;
    }
  }

  /* S-Function Block: Crane/Falcon (falcon_block) */
  {
    t_error result;
    result = falcon_close(Crane_DWork.Falcon_Falcon);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Crane_M, _rt_error_message);
      return;
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
  Crane_output(tid);
}

void MdlUpdate(int_T tid)
{
  Crane_update(tid);
}

void MdlInitializeSizes(void)
{
  Crane_M->Sizes.numContStates = (21); /* Number of continuous states */
  Crane_M->Sizes.numY = (0);           /* Number of model outputs */
  Crane_M->Sizes.numU = (0);           /* Number of model inputs */
  Crane_M->Sizes.sysDirFeedThru = (0); /* The model is not direct feedthrough */
  Crane_M->Sizes.numSampTimes = (2);   /* Number of sample times */
  Crane_M->Sizes.numBlocks = (72);     /* Number of blocks */
  Crane_M->Sizes.numBlockIO = (16);    /* Number of block outputs */
  Crane_M->Sizes.numBlockPrms = (416); /* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* S-Function Block: <S10>/Block#1 */
  {
    static _rtMech_PWORK mechWork;
    static ErrorRecord errorRec;
    if (rtmIsFirstInitCond(Crane_M)) {
      const int locationFlag = __LINE__;
      if (rt_mech_visited_loc_Crane_63fd34a2 == 0 ) {
        rt_mech_visited_loc_Crane_63fd34a2 = locationFlag;
      }

      if (rt_mech_visited_loc_Crane_63fd34a2 == locationFlag ) {
        if ((++rt_mech_visited_Crane_63fd34a2) != 1) {
          static const char reentranterrormsg[] =
            "Attempting to use multiple instances of SimMechanics generated code";
          rtmSetErrorStatus(Crane_M, reentranterrormsg);
          return;
        }
      }

      mechWork.mechanism = rt_get_mechanism_Crane_63fd34a2();
      mechWork.mechanism->engineError = &errorRec;
      mechWork.mechanism->engineError->errorFlag = false;

      {
        static char errorMsg[1024];
        if ((mechWork.mechanism->mapRuntimeData)(mechWork.mechanism,
             Crane_P.Block1_SimMechanicsRuntimeParam, errorMsg, sizeof(errorMsg)
             - 1)) {
          rtmSetErrorStatus(Crane_M, errorMsg);
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
          , mech_Tt_fdXc5y2Dg685RDenWd1
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
          , mech_5elGLjuzc_o2OZlMimjjB_
          , NULL
          , mech_fdwS_emZl_Uj5lI3bYvhs2
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
          , mech_YztKdAZO5p7GRfDKfvoXW1
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
          , mech_Ex5PbKjcSSZ8tPXho_PO21
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
          , mech_xzWgpT4bC8HsDOUfxzyco2
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
          , mech_EKlukb99PwiNfFGFVJAMt0
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
          , mech_6gOcy_frSK3pr3fotSpZ01
          , NULL
          , mech_6Nrjcn2psflsJ58sd_kGN1
          , NULL
          , mech_pyb_Ibgk3i3azXzDVP60L2
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
          , mech_ymRm6WqqRgP1QctkBKj7J1
          , NULL
          , mech_Vtow2gQfjWqPxtWw2FRuj2
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_ANoHgRb4tp27Dm9QJ3CSQ1
          , NULL
          , mech_bggDCJ_sH1c4QbaoCwPZA0
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
          , mech_ZhhaN1zDKqxW9B7FjH_rB1
          , NULL
          , mech___qxZewAikckuQQLfasEv2
          , NULL
          , mech_jJW235w_bLXS1hf4LJi_b0
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
          rtmSetErrorStatus(Crane_M, errorMsg);
          return;
        }
      }

      mechWork.mechanism->state = &Crane_X.Block1_CSTATE[0];
      Crane_DWork.Block1_IWORK = 0U;
      mechWork.genSimData.tStart = (0.0);
      mechWork.genSimData.iwork = &Crane_DWork.Block1_IWORK;
      mechWork.genSimData.numInputPorts = 2;

      {
        static real_T *mech_inputSignals[6];
        mech_inputSignals[0] = (real_T *) &Crane_B.Gain2;
        mech_inputSignals[1] = (real_T *) &Crane_B.Sum1[0];
        mech_inputSignals[2] = (real_T *) &Crane_B.Sum1[1];
        mech_inputSignals[3] = (real_T *) &Crane_B.Sum1[2];
        mech_inputSignals[4] = (real_T *) &Crane_B.Gain1;
        mech_inputSignals[5] = (real_T *) &Crane_B.Gain;
        mechWork.genSimData.inputSignals[0] = mech_inputSignals;
      }

      {
        static real_T *mech_inputSignals[3];
        mech_inputSignals[0] = (real_T *) Crane_B._gravity_conversion;
        mech_inputSignals[1] = (real_T *) &Crane_B._gravity_conversion[1];
        mech_inputSignals[2] = (real_T *) &Crane_B._gravity_conversion[2];
        mechWork.genSimData.inputSignals[1] = mech_inputSignals;
      }

      mechWork.outSimData.numOutputPorts = 3;
      mechWork.outSimData.logOutput = false;
      mechWork.outSimData.outputSignals[0] = Crane_B.Block1_o1;
      mechWork.outSimData.outputSignals[1] = Crane_B.Block1_o2;
      mechWork.outSimData.outputSignals[2] = &Crane_B.Block1_o3;
      Crane_DWork.Block1_PWORK = &mechWork;
    }
  }

  /* InitializeConditions for Memory: '<Root>/Memory' */
  Crane_DWork.Memory_PreviousInput[0] = Crane_P.Memory_X0;
  Crane_DWork.Memory_PreviousInput[1] = Crane_P.Memory_X0;
  Crane_DWork.Memory_PreviousInput[2] = Crane_P.Memory_X0;

  /* InitializeConditions for Integrator: '<S9>/Integrator' */
  Crane_X.Integrator_CSTATE[0] = Crane_P.Integrator_IC;
  Crane_X.Integrator_CSTATE[1] = Crane_P.Integrator_IC;
  Crane_X.Integrator_CSTATE[2] = Crane_P.Integrator_IC;

  /* Derivative Block: '<S9>/Derivative' */
  Crane_DWork.Derivative_RWORK.TimeStampA = rtInf;
  Crane_DWork.Derivative_RWORK.TimeStampB = rtInf;

  /* S-Function Block: <S10>/Block#2 */
  {
    static _rtMech_PWORK mechWork;
    static ErrorRecord errorRec;
    if (rtmIsFirstInitCond(Crane_M)) {
      mechWork.mechanism = rt_get_mechanism_Crane_63fd34a2();
      mechWork.mechanism->engineError = &errorRec;
      mechWork.mechanism->engineError->errorFlag = false;
      mechWork.genSimData.tStart = (0.0);
      mechWork.genSimData.iwork = NULL;
      mechWork.genSimData.numInputPorts = 4;

      {
        static real_T *mech_inputSignals[6];
        mech_inputSignals[0] = (real_T *) &Crane_B.Gain2;
        mech_inputSignals[1] = (real_T *) &Crane_B.Sum1[0];
        mech_inputSignals[2] = (real_T *) &Crane_B.Sum1[1];
        mech_inputSignals[3] = (real_T *) &Crane_B.Sum1[2];
        mech_inputSignals[4] = (real_T *) &Crane_B.Gain1;
        mech_inputSignals[5] = (real_T *) &Crane_B.Gain;
        mechWork.genSimData.inputSignals[0] = mech_inputSignals;
      }

      {
        static real_T *mech_inputSignals[18];
        mech_inputSignals[0] = (real_T *) Crane_B.Block1_o2;
        mech_inputSignals[1] = (real_T *) &Crane_B.Block1_o2[1];
        mech_inputSignals[2] = (real_T *) &Crane_B.Block1_o2[2];
        mech_inputSignals[3] = (real_T *) &Crane_B.Block1_o2[3];
        mech_inputSignals[4] = (real_T *) &Crane_B.Block1_o2[4];
        mech_inputSignals[5] = (real_T *) &Crane_B.Block1_o2[5];
        mech_inputSignals[6] = (real_T *) &Crane_B.Block1_o2[6];
        mech_inputSignals[7] = (real_T *) &Crane_B.Block1_o2[7];
        mech_inputSignals[8] = (real_T *) &Crane_B.Block1_o2[8];
        mech_inputSignals[9] = (real_T *) &Crane_B.Block1_o2[9];
        mech_inputSignals[10] = (real_T *) &Crane_B.Block1_o2[10];
        mech_inputSignals[11] = (real_T *) &Crane_B.Block1_o2[11];
        mech_inputSignals[12] = (real_T *) &Crane_B.Block1_o2[12];
        mech_inputSignals[13] = (real_T *) &Crane_B.Block1_o2[13];
        mech_inputSignals[14] = (real_T *) &Crane_B.Block1_o2[14];
        mech_inputSignals[15] = (real_T *) &Crane_B.Block1_o2[15];
        mech_inputSignals[16] = (real_T *) &Crane_B.Block1_o2[16];
        mech_inputSignals[17] = (real_T *) &Crane_B.Block1_o2[17];
        mechWork.genSimData.inputSignals[1] = mech_inputSignals;
      }

      {
        static real_T *mech_inputSignals[1];
        mech_inputSignals[0] = (real_T *) &Crane_B.Block1_o3;
        mechWork.genSimData.inputSignals[2] = mech_inputSignals;
      }

      {
        static real_T *mech_inputSignals[3];
        mech_inputSignals[0] = (real_T *) Crane_B._gravity_conversion;
        mech_inputSignals[1] = (real_T *) &Crane_B._gravity_conversion[1];
        mech_inputSignals[2] = (real_T *) &Crane_B._gravity_conversion[2];
        mechWork.genSimData.inputSignals[3] = mech_inputSignals;
      }

      mechWork.outSimData.numOutputPorts = 1;
      mechWork.outSimData.logOutput = false;
      mechWork.outSimData.outputSignals[0] = &Crane_B.Block2;
      Crane_DWork.Block2_PWORK = &mechWork;
    }
  }

  /* S-Function Block: <S10>/Block#3 */
  {
    static _rtMech_PWORK mechWork;
    static ErrorRecord errorRec;
    if (rtmIsFirstInitCond(Crane_M)) {
      mechWork.mechanism = rt_get_mechanism_Crane_63fd34a2();
      mechWork.mechanism->engineError = &errorRec;
      mechWork.mechanism->engineError->errorFlag = false;
      Crane_DWork.Block3_IWORK = 1U;
      mechWork.genSimData.tStart = (0.0);
      mechWork.genSimData.iwork = &Crane_DWork.Block3_IWORK;
      mechWork.genSimData.numInputPorts = 1;

      {
        static real_T *mech_inputSignals[1];
        mech_inputSignals[0] = (real_T *) &Crane_B.Block2;
        mechWork.genSimData.inputSignals[0] = mech_inputSignals;
      }

      mechWork.outSimData.numOutputPorts = 1;
      mechWork.outSimData.logOutput = false;
      mechWork.outSimData.outputSignals[0] = &Crane_B.Block3;
      Crane_DWork.Block3_PWORK = &mechWork;
    }
  }
}

void MdlStart(void)
{
  /* S-Function Block: Crane/Falcon (falcon_block) */
  {
    t_error result;
    result = falcon_open(&Crane_DWork.Falcon_Falcon);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Crane_M, _rt_error_message);
      return;
    }
  }

  MdlInitialize();
}

RT_MODEL_Crane *Crane(void)
{
  Crane_initialize(1);
  return Crane_M;
}

void MdlTerminate(void)
{
  Crane_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
