/*
 * Mechanics.c
 *
 * Real-Time Workshop code generation for Simulink model "Mechanics.mdl".
 *
 * Model Version              : 1.52
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Thu Aug 27 15:50:26 2009
 */

#include "Mechanics.h"
#include "Mechanics_private.h"

/* Block signals (auto storage) */
BlockIO_Mechanics Mechanics_B;

/* Continuous states */
ContinuousStates_Mechanics Mechanics_X;

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
D_Work_Mechanics Mechanics_DWork;

/* Real-time model */
RT_MODEL_Mechanics Mechanics_M_;
RT_MODEL_Mechanics *Mechanics_M = &Mechanics_M_;

/* Projection for root system: '<Root>' */
void Mechanics_projection(void)
{
  /* S-Function Block: <S6>/Block#1 */
  {
    _rtMech_PWORK *mechWork = (_rtMech_PWORK *) Mechanics_DWork.Block1_PWORK;
    mechWork->genSimData.time = Mechanics_M->Timing.t[0];
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
        rtmSetErrorStatus(Mechanics_M, errorMsg);
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
  int_T nXc = 10;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y,x,
                nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Mechanics_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Mechanics_output(0);
  Mechanics_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++)
    hB[i] = h * rt_ODE3_B[1][i];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Mechanics_output(0);
  Mechanics_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++)
    hB[i] = h * rt_ODE3_B[2][i];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  Mechanics_output(0);
  Mechanics_projection();
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Mechanics_output(int_T tid)
{
  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Mechanics_M)) {
    Mechanics_M->Timing.t[0] = rtsiGetT(&Mechanics_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Mechanics_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&Mechanics_M->solverInfo,
                          ((Mechanics_M->Timing.clockTick0+1)*
      Mechanics_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Mechanics_M) &&
      Mechanics_M->Timing.TaskCounters.TID[1] == 0) {
    /* Level2 S-Function Block: '<Root>/Arduino' (QueryInstrument) */
    {
      SimStruct *rts = Mechanics_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<Root>/Gain' */
    Mechanics_B.Gain = Mechanics_P.Gain_Gain * Mechanics_B.Arduino;
  }

  /* S-Function Block: <S6>/Block#1 */
  {
    _rtMech_PWORK *mechWork = (_rtMech_PWORK *) Mechanics_DWork.Block1_PWORK;
    mechWork->genSimData.time = Mechanics_M->Timing.t[0];
    mechWork->outSimData.majorTimestep = rtmIsMajorTimeStep(Mechanics_M);
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
        rtmSetErrorStatus(Mechanics_M, errorMsg);
        return;
      }
    }
  }

  if (rtmIsMajorTimeStep(Mechanics_M) &&
      Mechanics_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S6>/_gravity_conversion' incorporates:
     *  Constant: '<S5>/SOURCE_BLOCK'
     */
    Mechanics_B._gravity_conversion[0] = Mechanics_P._gravity_conversion_Gain *
      Mechanics_P.SOURCE_BLOCK_Value[0];
    Mechanics_B._gravity_conversion[1] = Mechanics_P._gravity_conversion_Gain *
      Mechanics_P.SOURCE_BLOCK_Value[1];
    Mechanics_B._gravity_conversion[2] = Mechanics_P._gravity_conversion_Gain *
      Mechanics_P.SOURCE_BLOCK_Value[2];
  }

  /* S-Function Block: <S6>/Block#2 */
  {
    _rtMech_PWORK *mechWork = (_rtMech_PWORK *) Mechanics_DWork.Block2_PWORK;
    mechWork->genSimData.time = Mechanics_M->Timing.t[0];
    mechWork->outSimData.majorTimestep = rtmIsMajorTimeStep(Mechanics_M);
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
        rtmSetErrorStatus(Mechanics_M, errorMsg);
        return;
      }
    }
  }

  /* S-Function Block: <S6>/Block#3 */
  {
    _rtMech_PWORK *mechWork = (_rtMech_PWORK *) Mechanics_DWork.Block3_PWORK;
    mechWork->genSimData.time = Mechanics_M->Timing.t[0];
    mechWork->outSimData.majorTimestep = rtmIsMajorTimeStep(Mechanics_M);
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
        rtmSetErrorStatus(Mechanics_M, errorMsg);
        return;
      }
    }
  }

  UNUSED_PARAMETER(tid);
}

/* Model update function */
void Mechanics_update(int_T tid)
{
  if (rtmIsMajorTimeStep(Mechanics_M)) {
    rt_ertODEUpdateContinuousStates(&Mechanics_M->solverInfo);
  }

  /* Update absolute time for base rate */
  if (!(++Mechanics_M->Timing.clockTick0))
    ++Mechanics_M->Timing.clockTickH0;
  Mechanics_M->Timing.t[0] = Mechanics_M->Timing.clockTick0 *
    Mechanics_M->Timing.stepSize0 + Mechanics_M->Timing.clockTickH0 *
    Mechanics_M->Timing.stepSize0 * 4294967296.0;
  if (rtmIsMajorTimeStep(Mechanics_M) &&
      Mechanics_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [35.0s, 0.0s] */
    if (!(++Mechanics_M->Timing.clockTick1))
      ++Mechanics_M->Timing.clockTickH1;
    Mechanics_M->Timing.t[1] = Mechanics_M->Timing.clockTick1 *
      Mechanics_M->Timing.stepSize1 + Mechanics_M->Timing.clockTickH1 *
      Mechanics_M->Timing.stepSize1 * 4294967296.0;
  }

  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void Mechanics_derivatives(void)
{
  /* S-Function Block: <S6>/Block#1 */
  {
    _rtMech_PWORK *mechWork = (_rtMech_PWORK *) Mechanics_DWork.Block1_PWORK;
    if (sFcnDerivativesMethod(mechWork->mechanism, &((StateDerivatives_Mechanics
           *) Mechanics_M->ModelData.derivs)->Block1_CSTATE[0])) {
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
        rtmSetErrorStatus(Mechanics_M, errorMsg);
        return;
      }
    }
  }
}

/* Model initialize function */
void Mechanics_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));    /* initialize real-time model */
  (void) memset((char_T *)Mechanics_M,0,
                sizeof(RT_MODEL_Mechanics));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Mechanics_M->solverInfo,
                          &Mechanics_M->Timing.simTimeStep);
    rtsiSetTPtr(&Mechanics_M->solverInfo, &rtmGetTPtr(Mechanics_M));
    rtsiSetStepSizePtr(&Mechanics_M->solverInfo, &Mechanics_M->Timing.stepSize0);
    rtsiSetdXPtr(&Mechanics_M->solverInfo, &Mechanics_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Mechanics_M->solverInfo,
                         &Mechanics_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Mechanics_M->solverInfo,
      &Mechanics_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Mechanics_M->solverInfo, (&rtmGetErrorStatus
      (Mechanics_M)));
    rtsiSetRTModelPtr(&Mechanics_M->solverInfo, Mechanics_M);
  }

  rtsiSetSimTimeStep(&Mechanics_M->solverInfo, MAJOR_TIME_STEP);
  Mechanics_M->ModelData.intgData.y = Mechanics_M->ModelData.odeY;
  Mechanics_M->ModelData.intgData.f[0] = Mechanics_M->ModelData.odeF[0];
  Mechanics_M->ModelData.intgData.f[1] = Mechanics_M->ModelData.odeF[1];
  Mechanics_M->ModelData.intgData.f[2] = Mechanics_M->ModelData.odeF[2];
  Mechanics_M->ModelData.contStates = ((real_T *) &Mechanics_X);
  rtsiSetSolverData(&Mechanics_M->solverInfo, (void *)
                    &Mechanics_M->ModelData.intgData);
  rtsiSetSolverName(&Mechanics_M->solverInfo,"ode3");
  Mechanics_M->solverInfoPtr = (&Mechanics_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Mechanics_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Mechanics_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Mechanics_M->Timing.sampleTimes = (&Mechanics_M->Timing.sampleTimesArray[0]);
    Mechanics_M->Timing.offsetTimes = (&Mechanics_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Mechanics_M->Timing.sampleTimes[0] = (0.0);
    Mechanics_M->Timing.sampleTimes[1] = (35.0);

    /* task offsets */
    Mechanics_M->Timing.offsetTimes[0] = (0.0);
    Mechanics_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Mechanics_M, &Mechanics_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Mechanics_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Mechanics_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Mechanics_M, -1);
  Mechanics_M->Timing.stepSize0 = 35.0;
  Mechanics_M->Timing.stepSize1 = 35.0;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    Mechanics_M->rtwLogInfo = &rt_DataLoggingInfo;
    rtliSetLogFormat(Mechanics_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(Mechanics_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(Mechanics_M->rtwLogInfo, 1);
    rtliSetLogVarNameModifier(Mechanics_M->rtwLogInfo, "rt_");
    rtliSetLogT(Mechanics_M->rtwLogInfo, "tout");
    rtliSetLogX(Mechanics_M->rtwLogInfo, "");
    rtliSetLogXFinal(Mechanics_M->rtwLogInfo, "");
    rtliSetSigLog(Mechanics_M->rtwLogInfo, "");
    rtliSetLogXSignalInfo(Mechanics_M->rtwLogInfo, NULL);
    rtliSetLogXSignalPtrs(Mechanics_M->rtwLogInfo, NULL);
    rtliSetLogY(Mechanics_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Mechanics_M->rtwLogInfo, NULL);
    rtliSetLogYSignalPtrs(Mechanics_M->rtwLogInfo, NULL);
  }

  Mechanics_M->solverInfoPtr = (&Mechanics_M->solverInfo);
  Mechanics_M->Timing.stepSize = (35.0);
  rtsiSetFixedStepSize(&Mechanics_M->solverInfo, 35.0);
  rtsiSetSolverMode(&Mechanics_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Mechanics_M->ModelData.blockIO = ((void *) &Mechanics_B);

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&Mechanics_B.Arduino);
    for (i = 0; i < 18; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }
  }

  /* parameters */
  Mechanics_M->ModelData.defaultParam = ((real_T *) &Mechanics_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Mechanics_X;
    Mechanics_M->ModelData.contStates = (x);
    (void) memset((char_T *)x,0,
                  sizeof(ContinuousStates_Mechanics));
  }

  /* states (dwork) */
  Mechanics_M->Work.dwork = ((void *) &Mechanics_DWork);
  (void) memset((char_T *) &Mechanics_DWork,0,
                sizeof(D_Work_Mechanics));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &Mechanics_M->NonInlinedSFcns.sfcnInfo;
    Mechanics_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Mechanics_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &Mechanics_M->Sizes.numSampTimes);
    rtssSetTPtrPtr(sfcnInfo, &rtmGetTPtr(Mechanics_M));
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Mechanics_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Mechanics_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(Mechanics_M));
    rtssSetStepSizePtr(sfcnInfo, &Mechanics_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(Mechanics_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Mechanics_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &Mechanics_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &Mechanics_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &Mechanics_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &Mechanics_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Mechanics_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Mechanics_M->solverInfoPtr);
  }

  Mechanics_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&Mechanics_M->NonInlinedSFcns.childSFunctions[0],0,
                  1*sizeof(SimStruct));
    Mechanics_M->childSfunctions =
      (&Mechanics_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    Mechanics_M->childSfunctions[0] =
      (&Mechanics_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: Mechanics/<Root>/Arduino (QueryInstrument) */
    {
      SimStruct *rts = Mechanics_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = Mechanics_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = Mechanics_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = Mechanics_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Mechanics_M->NonInlinedSFcns.blkInfo2[0]);
        ssSetRTWSfcnInfo(rts, Mechanics_M->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Mechanics_M->NonInlinedSFcns.methods2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Mechanics_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Mechanics_B.Arduino));
        }
      }

      /* path info */
      ssSetModelName(rts, "Arduino");
      ssSetPath(rts, "Mechanics/Arduino");
      ssSetRTModel(rts,Mechanics_M);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Mechanics_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 39);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&Mechanics_P.Arduino_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&Mechanics_P.Arduino_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&Mechanics_P.Arduino_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&Mechanics_P.Arduino_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&Mechanics_P.Arduino_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&Mechanics_P.Arduino_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&Mechanics_P.Arduino_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&Mechanics_P.Arduino_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&Mechanics_P.Arduino_P9_Size[0]);
        ssSetSFcnParam(rts, 9, (mxArray*)&Mechanics_P.Arduino_P10_Size[0]);
        ssSetSFcnParam(rts, 10, (mxArray*)&Mechanics_P.Arduino_P11_Size[0]);
        ssSetSFcnParam(rts, 11, (mxArray*)&Mechanics_P.Arduino_P12_Size[0]);
        ssSetSFcnParam(rts, 12, (mxArray*)&Mechanics_P.Arduino_P13_Size[0]);
        ssSetSFcnParam(rts, 13, (mxArray*)&Mechanics_P.Arduino_P14_Size[0]);
        ssSetSFcnParam(rts, 14, (mxArray*)&Mechanics_P.Arduino_P15_Size[0]);
        ssSetSFcnParam(rts, 15, (mxArray*)&Mechanics_P.Arduino_P16_Size[0]);
        ssSetSFcnParam(rts, 16, (mxArray*)&Mechanics_P.Arduino_P17_Size[0]);
        ssSetSFcnParam(rts, 17, (mxArray*)&Mechanics_P.Arduino_P18_Size[0]);
        ssSetSFcnParam(rts, 18, (mxArray*)&Mechanics_P.Arduino_P19_Size[0]);
        ssSetSFcnParam(rts, 19, (mxArray*)&Mechanics_P.Arduino_P20_Size[0]);
        ssSetSFcnParam(rts, 20, (mxArray*)&Mechanics_P.Arduino_P21_Size[0]);
        ssSetSFcnParam(rts, 21, (mxArray*)&Mechanics_P.Arduino_P22_Size[0]);
        ssSetSFcnParam(rts, 22, (mxArray*)&Mechanics_P.Arduino_P23_Size[0]);
        ssSetSFcnParam(rts, 23, (mxArray*)&Mechanics_P.Arduino_P24_Size[0]);
        ssSetSFcnParam(rts, 24, (mxArray*)&Mechanics_P.Arduino_P25_Size[0]);
        ssSetSFcnParam(rts, 25, (mxArray*)&Mechanics_P.Arduino_P26_Size[0]);
        ssSetSFcnParam(rts, 26, (mxArray*)&Mechanics_P.Arduino_P27_Size[0]);
        ssSetSFcnParam(rts, 27, (mxArray*)&Mechanics_P.Arduino_P28_Size[0]);
        ssSetSFcnParam(rts, 28, (mxArray*)&Mechanics_P.Arduino_P29_Size[0]);
        ssSetSFcnParam(rts, 29, (mxArray*)&Mechanics_P.Arduino_P30_Size[0]);
        ssSetSFcnParam(rts, 30, (mxArray*)&Mechanics_P.Arduino_P31_Size[0]);
        ssSetSFcnParam(rts, 31, (mxArray*)&Mechanics_P.Arduino_P32_Size[0]);
        ssSetSFcnParam(rts, 32, (mxArray*)&Mechanics_P.Arduino_P33_Size[0]);
        ssSetSFcnParam(rts, 33, (mxArray*)&Mechanics_P.Arduino_P34_Size[0]);
        ssSetSFcnParam(rts, 34, (mxArray*)&Mechanics_P.Arduino_P35_Size[0]);
        ssSetSFcnParam(rts, 35, (mxArray*)&Mechanics_P.Arduino_P36_Size[0]);
        ssSetSFcnParam(rts, 36, (mxArray*)&Mechanics_P.Arduino_P37_Size[0]);
        ssSetSFcnParam(rts, 37, (mxArray*)&Mechanics_P.Arduino_P38_Size[0]);
        ssSetSFcnParam(rts, 38, (mxArray*)&Mechanics_P.Arduino_P39_Size[0]);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &Mechanics_DWork.Arduino_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Mechanics_M->NonInlinedSFcns.Sfcn0.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Mechanics_DWork.Arduino_PWORK);
      }

      /* registration */
      QueryInstrument(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 35.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }
  }
}

/* Model terminate function */
void Mechanics_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/Arduino' (QueryInstrument) */
  {
    SimStruct *rts = Mechanics_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* S-Function Block: <S6>/Block#1 */
  {
    if (rt_mech_visited_Mechanics_c90d139d == 1) {
      _rtMech_PWORK *mechWork = (_rtMech_PWORK *) Mechanics_DWork.Block1_PWORK;
      if (mechWork->mechanism->destroyEngine != NULL) {
        (mechWork->mechanism->destroyEngine)(mechWork->mechanism);
      }
    }

    if ((--rt_mech_visited_Mechanics_c90d139d) == 0 ) {
      rt_mech_visited_loc_Mechanics_c90d139d = 0;
    }
  }
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Mechanics_output(tid);
}

void MdlUpdate(int_T tid)
{
  Mechanics_update(tid);
}

void MdlInitializeSizes(void)
{
  Mechanics_M->Sizes.numContStates = (10);/* Number of continuous states */
  Mechanics_M->Sizes.numY = (0);       /* Number of model outputs */
  Mechanics_M->Sizes.numU = (0);       /* Number of model inputs */
  Mechanics_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Mechanics_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Mechanics_M->Sizes.numBlocks = (32); /* Number of blocks */
  Mechanics_M->Sizes.numBlockIO = (7); /* Number of block outputs */
  Mechanics_M->Sizes.numBlockPrms = (387);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* S-Function Block: <S6>/Block#1 */
  {
    static _rtMech_PWORK mechWork;
    static ErrorRecord errorRec;
    if (rtmIsFirstInitCond(Mechanics_M)) {
      const int locationFlag = __LINE__;
      if (rt_mech_visited_loc_Mechanics_c90d139d == 0 ) {
        rt_mech_visited_loc_Mechanics_c90d139d = locationFlag;
      }

      if (rt_mech_visited_loc_Mechanics_c90d139d == locationFlag ) {
        if ((++rt_mech_visited_Mechanics_c90d139d) != 1) {
          static const char reentranterrormsg[] =
            "Attempting to use multiple instances of SimMechanics generated code";
          rtmSetErrorStatus(Mechanics_M, reentranterrormsg);
          return;
        }
      }

      mechWork.mechanism = rt_get_mechanism_Mechanics_c90d139d();
      mechWork.mechanism->engineError = &errorRec;
      mechWork.mechanism->engineError->errorFlag = false;

      {
        static char errorMsg[1024];
        if ((mechWork.mechanism->mapRuntimeData)(mechWork.mechanism,
             Mechanics_P.Block1_SimMechanicsRuntimeParam, errorMsg, sizeof
             (errorMsg) - 1)) {
          rtmSetErrorStatus(Mechanics_M, errorMsg);
          return;
        }
      }

      {
        static mech_method_table_t _mech_method_table = {
          NULL
          , NULL
          , mech_J8kgSsAbBVUDRlh2AoGly2
          , mech_tOtTtRSarBnv8RbwyBskF2
          , NULL
          , NULL
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
          , NULL
          , NULL
          , NULL
          , mech_p7HTt0mzGU5UBJblmCyCZ1
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_2kOp06aWX46uNz_XcnB181
          , NULL
          , mech__lIfz1Oc1rvdgYh1y1_de_
          , NULL
          , mech_5P5CoVyIhI5M5ReZPjsrv0
          , NULL
          , NULL
          , NULL
          , mech_i6H5Q2FkwAxt3m4HW8hv71
          , mech_pt62D8N9Y5u9B9V1eJuBf_
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_uqxMTgo3_PyYbUfmePoCO2
          , NULL
          , mech_OS2PsA89biZ1x_qmyjj3J2
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_UPuqULKFWBaBlK_GxYcLa0
          , NULL
          , NULL
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
          , mech_QcFKRlMiyke_3Z0bo0evL0
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
          , mech_gZh_XkSd1LafYqzmy5XlX1
          , mech_a_17m3gydYlTeUU7HvysF0
          , mech__MLGR2zPV8GQNF039XoEV2
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_LEfaVuRoeRM_6TC8sRJgw0
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
          , NULL
          , mech_RiOQp0gsOV_fayu4zFTTm2
          , NULL
          , NULL
          , NULL
          , mech__4bqWfNpOsb8u2HaHsF5l_
          , NULL
          , mech_aMhF8aUJa3oMQka5tPT3D_
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
          , mech_eixMVOlWwzwa5IZ2NdYFb1
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_H2CpDYCpvxvkzfBP3eSON1
          , mech_NhG0wKNsr_veIvK_xtxsT_
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_1e5NgvgamMfojT1CCIS46_
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
          , NULL
          , mech_of4JKrLWfwqq9Yv_JaZ652
          , NULL
          , mech__qtM_wCDCLbue_EmPHBZd0
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_nOAsdZgTbArlpB4jb56j9_
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_Uu7joU8H9eUeastwolDVg0
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_A9A4RALK60iujBPmEZW4y2
          , NULL
          , NULL
          , NULL
          , mech_AtEvyHXQJCn6fd3I4T7l_2
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_gJyl4ucbKAvii0KrBGB1Y2
          , NULL
          , mech_mCv0ii4b755Uoyixufw2a2
          , NULL
          , mech_yk_siV8V9MJjcl8w2eOxM0
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_hK3VRHnV7tGo36UBw0KZp2
          , NULL
          , mech_2KtcbpF_zrG2uVb5efpsS0
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_5aXEh857soU6OYzHccPM12
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
          , NULL
          , mech_9SO2sDmF0ipcJt3wUIG712
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
          , NULL
          , mech_AbSjJpVb_mGkzUBUwq6Ux_
          , mech_kyrP38xSp1YnrhC4s5b3A1
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_5x9rXGkyDa4F41T8OezM__
          , NULL
          , mech_JDM1y6iRYKUTGsBvhwcfV2
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
          , NULL
          , mech_1TsY7Di0epHYMYEwFeJRd1
          , NULL
          , mech_0rUGOkGiISDqU_WlodsSp_
          , NULL
          , mech_pDa3h4kToJ2jSy9YR9Ydf0
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_TpBlMCrl8a0w_hht9hsfc1
          , NULL
          , mech_cFbniMssjI9w_C47I_WXl_
          , NULL
          , NULL
          , NULL
          , NULL
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
          , NULL
          , mech_Nl3XtWFGWS5uz1d5veXsd2
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_DuPpsVxDWShgP9Xiwxuui_
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_eCAm5yLntfjR0nO0eiLu50
          , NULL
          , NULL
          , mech_2OyNvCoa31E0xRJwdl5zn2
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
          , NULL
          , mech_bueTeoLQyYYtUHbnuoJW92
          , NULL
          , NULL
          , mech_WfHVpj_Wtm8tj_R51JUQ_2
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
          , mech_chydrhSD8XAbPmZqIIRqi0
          , NULL
          , mech_mTdld1poZ5U5IgQYSmots2
          , NULL
          , mech_x2iNsxmyumA_ryRMuUqE_0
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , NULL
          , mech_YiE1N3jXDC7778QLv6Us82
          , NULL
          , mech_JxjRMaHtTB7uFQfBm3mFX1
          , NULL
          , mech_RhXDBpT8CJx1HFDA9w5yD2
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
          rtmSetErrorStatus(Mechanics_M, errorMsg);
          return;
        }
      }

      mechWork.mechanism->state = &Mechanics_X.Block1_CSTATE[0];
      Mechanics_DWork.Block1_IWORK = 0U;
      mechWork.genSimData.tStart = (0.0);
      mechWork.genSimData.iwork = &Mechanics_DWork.Block1_IWORK;
      mechWork.genSimData.numInputPorts = 3;

      {
        static real_T *mech_inputSignals[3];
        mech_inputSignals[0] = (real_T *) &Mechanics_B.Gain;
        mech_inputSignals[1] = (real_T *) &Mechanics_P.Constant2_Value;
        mech_inputSignals[2] = (real_T *) &Mechanics_P.Constant3_Value;
        mechWork.genSimData.inputSignals[0] = mech_inputSignals;
      }

      {
        static real_T *mech_inputSignals[1];
        mech_inputSignals[0] = (real_T *) &Mechanics_P.Constant1_Value;
        mechWork.genSimData.inputSignals[1] = mech_inputSignals;
      }

      {
        static real_T *mech_inputSignals[3];
        mech_inputSignals[0] = (real_T *) Mechanics_B._gravity_conversion;
        mech_inputSignals[1] = (real_T *) &Mechanics_B._gravity_conversion[1];
        mech_inputSignals[2] = (real_T *) &Mechanics_B._gravity_conversion[2];
        mechWork.genSimData.inputSignals[2] = mech_inputSignals;
      }

      mechWork.outSimData.numOutputPorts = 2;
      mechWork.outSimData.logOutput = false;
      mechWork.outSimData.outputSignals[0] = Mechanics_B.Block1_o1;
      mechWork.outSimData.outputSignals[1] = &Mechanics_B.Block1_o2;
      Mechanics_DWork.Block1_PWORK = &mechWork;
    }
  }

  /* S-Function Block: <S6>/Block#2 */
  {
    static _rtMech_PWORK mechWork;
    static ErrorRecord errorRec;
    if (rtmIsFirstInitCond(Mechanics_M)) {
      mechWork.mechanism = rt_get_mechanism_Mechanics_c90d139d();
      mechWork.mechanism->engineError = &errorRec;
      mechWork.mechanism->engineError->errorFlag = false;
      mechWork.genSimData.tStart = (0.0);
      mechWork.genSimData.iwork = NULL;
      mechWork.genSimData.numInputPorts = 4;

      {
        static real_T *mech_inputSignals[1];
        mech_inputSignals[0] = (real_T *) &Mechanics_P.Constant1_Value;
        mechWork.genSimData.inputSignals[0] = mech_inputSignals;
      }

      {
        static real_T *mech_inputSignals[10];
        mech_inputSignals[0] = (real_T *) Mechanics_B.Block1_o1;
        mech_inputSignals[1] = (real_T *) &Mechanics_B.Block1_o1[1];
        mech_inputSignals[2] = (real_T *) &Mechanics_B.Block1_o1[2];
        mech_inputSignals[3] = (real_T *) &Mechanics_B.Block1_o1[3];
        mech_inputSignals[4] = (real_T *) &Mechanics_B.Block1_o1[4];
        mech_inputSignals[5] = (real_T *) &Mechanics_B.Block1_o1[5];
        mech_inputSignals[6] = (real_T *) &Mechanics_B.Block1_o1[6];
        mech_inputSignals[7] = (real_T *) &Mechanics_B.Block1_o1[7];
        mech_inputSignals[8] = (real_T *) &Mechanics_B.Block1_o1[8];
        mech_inputSignals[9] = (real_T *) &Mechanics_B.Block1_o1[9];
        mechWork.genSimData.inputSignals[1] = mech_inputSignals;
      }

      {
        static real_T *mech_inputSignals[1];
        mech_inputSignals[0] = (real_T *) &Mechanics_B.Block1_o2;
        mechWork.genSimData.inputSignals[2] = mech_inputSignals;
      }

      {
        static real_T *mech_inputSignals[3];
        mech_inputSignals[0] = (real_T *) Mechanics_B._gravity_conversion;
        mech_inputSignals[1] = (real_T *) &Mechanics_B._gravity_conversion[1];
        mech_inputSignals[2] = (real_T *) &Mechanics_B._gravity_conversion[2];
        mechWork.genSimData.inputSignals[3] = mech_inputSignals;
      }

      mechWork.outSimData.numOutputPorts = 1;
      mechWork.outSimData.logOutput = false;
      mechWork.outSimData.outputSignals[0] = &Mechanics_B.Block2;
      Mechanics_DWork.Block2_PWORK = &mechWork;
    }
  }

  /* S-Function Block: <S6>/Block#3 */
  {
    static _rtMech_PWORK mechWork;
    static ErrorRecord errorRec;
    if (rtmIsFirstInitCond(Mechanics_M)) {
      mechWork.mechanism = rt_get_mechanism_Mechanics_c90d139d();
      mechWork.mechanism->engineError = &errorRec;
      mechWork.mechanism->engineError->errorFlag = false;
      Mechanics_DWork.Block3_IWORK = 1U;
      mechWork.genSimData.tStart = (0.0);
      mechWork.genSimData.iwork = &Mechanics_DWork.Block3_IWORK;
      mechWork.genSimData.numInputPorts = 1;

      {
        static real_T *mech_inputSignals[1];
        mech_inputSignals[0] = (real_T *) &Mechanics_B.Block2;
        mechWork.genSimData.inputSignals[0] = mech_inputSignals;
      }

      mechWork.outSimData.numOutputPorts = 1;
      mechWork.outSimData.logOutput = false;
      mechWork.outSimData.outputSignals[0] = &Mechanics_B.Block3;
      Mechanics_DWork.Block3_PWORK = &mechWork;
    }
  }
}

void MdlStart(void)
{
  /* Level2 S-Function Block: '<Root>/Arduino' (QueryInstrument) */
  {
    SimStruct *rts = Mechanics_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  MdlInitialize();
}

RT_MODEL_Mechanics *Mechanics(void)
{
  Mechanics_initialize(1);
  return Mechanics_M;
}

void MdlTerminate(void)
{
  Mechanics_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
