#if !defined(S_FUNCTION_NAME)
#define S_FUNCTION_NAME                vdmultRM_msf
#endif

#define S_FUNCTION_LEVEL               2

#if !defined(RTW_GENERATED_S_FUNCTION)
#define RTW_GENERATED_S_FUNCTION
#endif

#include <stdio.h>
#include <math.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define rt_logging_h
#include "vdmultRM_types.h"
#include "vdmultRM.h"
#include "vdmultRM_private.h"

MdlRefChildMdlRec childModels[1] = {
  "vdmultRM", "vdmultRM", 0, NULL };

static void mdlInitializeSizes(SimStruct *S)
{
  ssSetNumSFcnParams(S, 0);
  if (S->mdlInfo->genericFcn != NULL) {
    _GenericFcn fcn = S->mdlInfo->genericFcn;
    (fcn)(S, GEN_FCN_CHK_MODELREF_SOLVER_TYPE_EARLY, 2, NULL);
  }

  ssSetRTWGeneratedSFcn(S, 2);
  ssSetNumContStates(S, 0);
  ssSetNumDiscStates(S, 0);
  if (!ssSetNumInputPorts(S, 2))
    return;
  if (!ssSetInputPortVectorDimension(S, 0, 1))
    return;
  ssSetInputPortFrameData(S, 0, FRAME_NO);
  ssSetInputPortBusMode(S, 0, SL_NON_BUS_MODE)
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY)
  {
    ssSetInputPortDataType(S, 0, SS_DOUBLE);
  }

  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortRequiredContiguous(S, 0, 1);
  ssSetInputPortOptimOpts(S, 0, SS_NOT_REUSABLE_AND_GLOBAL);
  ssSetInputPortOverWritable(S, 0, FALSE);
  ssSetInputPortSampleTime(S, 0, 0.0);
  ssSetInputPortOffsetTime(S, 0, 0.0);
  if (!ssSetInputPortVectorDimension(S, 1, 1))
    return;
  ssSetInputPortFrameData(S, 1, FRAME_NO);
  ssSetInputPortBusMode(S, 1, SL_NON_BUS_MODE)
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY)
  {
    ssSetInputPortDataType(S, 1, SS_DOUBLE);
  }

  ssSetInputPortDirectFeedThrough(S, 1, 1);
  ssSetInputPortRequiredContiguous(S, 1, 1);
  ssSetInputPortOptimOpts(S, 1, SS_NOT_REUSABLE_AND_GLOBAL);
  ssSetInputPortOverWritable(S, 1, FALSE);
  ssSetInputPortSampleTime(S, 1, 0.0);
  ssSetInputPortOffsetTime(S, 1, 0.0);
  if (!ssSetNumOutputPorts(S, 1))
    return;
  if (!ssSetOutputPortVectorDimension(S, 0, 1))
    return;
  ssSetOutputPortFrameData(S, 0, FRAME_NO);
  ssSetOutputPortBusMode(S, 0, SL_NON_BUS_MODE)
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY)
  {
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 0, 0.0);
  ssSetOutputPortOffsetTime(S, 0, 0.0);
  ssSetOutputPortOkToMerge(S, 0, SS_OK_TO_MERGE);
  ssSetOutputPortOptimOpts(S, 0, SS_NOT_REUSABLE_AND_GLOBAL);
  rt_InitInfAndNaN(sizeof(real_T));

  {
    real_T minValue = rtMinusInf;
    real_T maxValue = rtInf;
    ssSetModelRefInputSignalDesignMin(S,0,&minValue);
    ssSetModelRefInputSignalDesignMax(S,0,&maxValue);
  }

  {
    real_T minValue = rtMinusInf;
    real_T maxValue = rtInf;
    ssSetModelRefInputSignalDesignMin(S,1,&minValue);
    ssSetModelRefInputSignalDesignMax(S,1,&maxValue);
  }

  {
    real_T minValue = rtMinusInf;
    real_T maxValue = rtInf;
    ssSetModelRefOutputSignalDesignMin(S,0,&minValue);
    ssSetModelRefOutputSignalDesignMax(S,0,&maxValue);
  }

  {
    static ssRTWStorageType storageClass[3] = { SS_RTW_STORAGE_AUTO,
      SS_RTW_STORAGE_AUTO, SS_RTW_STORAGE_AUTO };

    ssSetModelRefPortRTWStorageClasses(S, storageClass);
  }

  ssSetNumSampleTimes(S, PORT_BASED_SAMPLE_TIMES);
  ssSetNumRWork(S, 0);
  ssSetNumIWork(S, 0);
  ssSetNumPWork(S, 0);
  ssSetNumModes(S, 0);
  ssSetNumZeroCrossingSignals(S, 0);
  ssSetOutputPortIsNonContinuous(S, 0, 0);
  ssSetOutputPortIsFedByBlockWithModesNoZCs(S, 0, 0);
  ssSetInputPortIsNotDerivPort(S, 0, 1);
  ssSetInputPortIsNotDerivPort(S, 1, 1);
  ssSetModelReferenceSampleTimeInheritanceRule(S,
    DISALLOW_SAMPLE_TIME_INHERITANCE);
  ssSetOptimizeModelRefInitCode(S, 0);
  ssSetModelReferenceNormalModeSupport(S, MDL_START_AND_MDL_PROCESS_PARAMS_OK);
  ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE |
               SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME |
               SS_OPTION_SUPPORTS_ALIAS_DATA_TYPES |
               SS_OPTION_WORKS_WITH_CODE_REUSE |
               SS_OPTION_CALL_TERMINATE_ON_EXIT);
  if (S->mdlInfo->genericFcn != NULL) {
    ssRegModelRefChildModel(S,1,childModels);
  }

#if SS_SFCN_FOR_SIM

  if (S->mdlInfo->genericFcn != NULL &&
      ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    mr_vdmultRM_MdlInfoRegFcn(S, "vdmultRM");
  }

#endif

  if (!ssSetNumDWork(S, 1)) {
    return;
  }

#if SS_SFCN_FOR_SIM

  {
    int mdlrefDWTypeId;
    ssRegMdlRefDWorkType(S, &mdlrefDWTypeId);
    if (mdlrefDWTypeId == INVALID_DTYPE_ID )
      return;
    if (!ssSetDataTypeSize(S, mdlrefDWTypeId, sizeof(rtMdlrefDWork_mr_vdmultRM)))
      return;
    ssSetDWorkDataType(S, 0, mdlrefDWTypeId);
    ssSetDWorkWidth(S, 0, 1);
  }

#endif

  ssSetNeedAbsoluteTime(S, 1);
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
}

#define MDL_SET_INPUT_PORT_SAMPLE_TIME
#if defined(MATLAB_MEX_FILE)

static void mdlSetInputPortSampleTime(SimStruct *S,int_T portIdx,real_T
  sampleTime,real_T offsetTime)
{
  int i;
  for (i = 0 ; i < 2; ++i) {
    ssSetInputPortSampleTime(S,i,sampleTime);
    ssSetInputPortOffsetTime(S,i,offsetTime);
  }

  for (i = 0 ; i < 1; ++i) {
    if (ssGetOutputPortSampleTime(S,i) == rtInf &&
        ssGetOutputPortOffsetTime(S,i) == 0.0) {
      continue;
    }

    ssSetOutputPortSampleTime(S,i,sampleTime);
    ssSetOutputPortOffsetTime(S,i,offsetTime);
  }
}

#endif

#define MDL_SET_OUTPUT_PORT_SAMPLE_TIME
#if defined(MATLAB_MEX_FILE)

static void mdlSetOutputPortSampleTime(SimStruct *S,int_T portIdx,real_T
  sampleTime,real_T offsetTime)
{
  int i;
  for (i = 0 ; i < 2; ++i) {
    ssSetInputPortSampleTime(S,i,sampleTime);
    ssSetInputPortOffsetTime(S,i,offsetTime);
  }

  for (i = 0 ; i < 1; ++i) {
    if (ssGetOutputPortSampleTime(S,i) == rtInf &&
        ssGetOutputPortOffsetTime(S,i) == 0.0) {
      continue;
    }

    ssSetOutputPortSampleTime(S,i,sampleTime);
    ssSetOutputPortOffsetTime(S,i,offsetTime);
  }
}

#endif

#define MDL_SET_WORK_WIDTHS

static void mdlSetWorkWidths(SimStruct *S)
{
  if (S->mdlInfo->genericFcn != NULL) {
    real_T stopTime = 20.0;
    int_T hwSettings[8];
    real_T lifeSpan = rtInf;
    _GenericFcn fcn = S->mdlInfo->genericFcn;
    boolean_T hasDiscTs = 0;
    if (!(fcn)(S, GEN_FCN_CHK_MODELREF_SOLVER_TYPE, 2, &hasDiscTs))
      return;
    if (!(fcn)(S, GEN_FCN_CHK_MODELREF_SOLVER_NAME, 2, (void *)
               "FixedStepDiscrete"))
      return;
    if (!(fcn)(S, GEN_FCN_CHK_MODELREF_SOLVER_MODE, SOLVER_MODE_SINGLETASKING,
               NULL))
      return;
    if (!(fcn)(S, GEN_FCN_CHK_MODELREF_STOP_TIME, -1, &stopTime))
      return;
    hwSettings[0] = 8;
    hwSettings[1] = 16;
    hwSettings[2] = 32;
    hwSettings[3] = 32;
    hwSettings[4] = 2;
    hwSettings[5] = 0;
    hwSettings[6] = 32;
    hwSettings[7] = 1;
    if (!(fcn)(S, GEN_FCN_CHK_MODELREF_HARDWARE_SETTINGS, 8, hwSettings))
      return;
    if (!(fcn)(S, GEN_FCN_CHK_MODELREF_LIFE_SPAN, -1, &lifeSpan))
      return;
  }
}

#define MDL_START

static void mdlStart(SimStruct *S)
{
  rtMdlrefDWork_mr_vdmultRM *dw = (rtMdlrefDWork_mr_vdmultRM *) ssGetDWork(S, 0);
  void *sysRanPtr = NULL;
  int sysTid = 0;
  ssGetContextSysRanBCPtr(S, &sysRanPtr);
  ssGetContextSysTid(S, &sysTid);

  {
    static const char* toFileNames[] = { "" };

    static const char* fromFileNames[] = { "" };

    if (!ssSetModelRefFromFiles(S, 0,fromFileNames))
      return;
    if (!ssSetModelRefToFiles(S, 0,toFileNames))
      return;
  }

  mr_vdmultRM_initialize(S, ssGetSampleTimeTaskID(S, 0), &(dw->rtm), sysRanPtr,
    sysTid, NULL, NULL, 0, -1);
  ssSetModelMappingInfoPtr(S, &(dw->rtm.DataMapInfo.mmi));
  if (S->mdlInfo->genericFcn != NULL) {
    _GenericFcn fcn = S->mdlInfo->genericFcn;
    boolean_T hasDiscTs = 0;
    real_T startTime = 0.0;
    real_T fixedStep = 0.4;
    if (!(fcn)(S, GEN_FCN_CHK_MODELREF_START_TIME, -1, &startTime))
      return;
    if (!(fcn)(S, GEN_FCN_CHK_MODELREF_FIXED_STEP, (int_T)hasDiscTs, &fixedStep))
      return;
  }
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
  const real_T *InPort_0 = (real_T *) ssGetInputPortSignal(S, 0);
  const real_T *InPort_1 = (real_T *) ssGetInputPortSignal(S, 1);
  real_T *OutPort_0 = (real_T *) ssGetOutputPortSignal(S, 0);
  rtMdlrefDWork_mr_vdmultRM *dw = (rtMdlrefDWork_mr_vdmultRM *) ssGetDWork(S, 0);
  if (tid != CONSTANT_TID) {
    mr_vdmultRM(InPort_0, InPort_1, OutPort_0);
  }
}

static void mdlTerminate(SimStruct *S)
{
  rtMdlrefDWork_mr_vdmultRM *dw = (rtMdlrefDWork_mr_vdmultRM *) ssGetDWork(S, 0);
}

#ifdef MATLAB_MEX_FILE
#include "simulink.c"
#include "fixedpoint.c"
#else
#include "cg_sfun.h"
#endif
