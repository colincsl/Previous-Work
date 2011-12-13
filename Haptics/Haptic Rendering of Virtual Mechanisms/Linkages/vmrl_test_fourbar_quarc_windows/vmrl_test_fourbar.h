/*
 * vmrl_test_fourbar.h
 *
 * Real-Time Workshop code generation for Simulink model "vmrl_test_fourbar.mdl".
 *
 * Model Version              : 1.21
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Tue Jan 12 17:03:46 2010
 */
#ifndef RTW_HEADER_vmrl_test_fourbar_h_
#define RTW_HEADER_vmrl_test_fourbar_h_
#ifndef vmrl_test_fourbar_COMMON_INCLUDES_
# define vmrl_test_fourbar_COMMON_INCLUDES_
#include <stddef.h>
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "rt_nonfinite.h"
#include "rtlibsrc.h"
#endif                                 /* vmrl_test_fourbar_COMMON_INCLUDES_ */

#include "vmrl_test_fourbar_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ((rtm)->Timing.mdlref_GlobalTID)
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ((rtm)->Timing.mdlref_GlobalTID = (val))
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ((rtm)->Timing.mdlref_TriggerTID)
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ((rtm)->Timing.mdlref_TriggerTID = (val))
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ((rtm)->ModelData.paramIsMalloced)
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ((rtm)->ModelData.paramIsMalloced = (val))
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ((rtm)->Timing.RateInteraction)
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ((rtm)->Timing.RateInteraction = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ((rtm)->modelMethodsInfo)
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ((rtm)->modelMethodsInfo = (val))
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->Work.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->Work.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->Work.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->Work.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTime
# define rtmGetVarNextHitTime(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTime
# define rtmSetVarNextHitTime(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsFirstInitCond
# define rtmIsFirstInitCond(rtm)       (vmrl_test_fourbar_M->Timing.t[0] == (rtmGetTStart((rtm))))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define vmrl_test_fourbar_rtModel      RT_MODEL_vmrl_test_fourbar

/* Block states (auto storage) for system '<S9>/Phi == pi' */
typedef struct {
  int8_T Phipi_SubsysRanBC;            /* '<S9>/Phi == pi' */
} rtDW_Phipi_vmrl_test_fourbar;

/* Block states (auto storage) for system '<S9>/General case' */
typedef struct {
  int8_T Generalcase_SubsysRanBC;      /* '<S9>/General case' */
} rtDW_Generalcase_vmrl_test_four;

/* Block signals (auto storage) */
typedef struct {
  real_T Block1_o1[60];                /* '<S15>/Block#1' */
  real_T Block1_o2[6];                 /* '<S15>/Block#1' */
  real_T Block1_o3;                    /* '<S15>/Block#1' */
  real_T Merge[4];                     /* '<S9>/Merge' */
  real_T gain_1[3];                    /* '<S1>/gain_1' */
  real_T Merge_d[4];                   /* '<S10>/Merge' */
  real_T gain_1_i[3];                  /* '<S5>/gain_1' */
  real_T Merge_m[4];                   /* '<S11>/Merge' */
  real_T gain_1_b[3];                  /* '<S3>/gain_1' */
  real_T Merge_g[4];                   /* '<S12>/Merge' */
  real_T gain_1_i3[3];                 /* '<S4>/gain_1' */
  real_T Merge_n[4];                   /* '<S13>/Merge' */
  real_T Merge_no[4];                  /* '<S14>/Merge' */
  real_T gain_1_j[3];                  /* '<S2>/gain_1' */
  real_T _gravity_conversion[3];       /* '<S15>/_gravity_conversion' */
  real_T Block2;                       /* '<S15>/Block#2' */
  real_T Block3;                       /* '<S15>/Block#3' */
} BlockIO_vmrl_test_fourbar;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  void *Block1_PWORK;                  /* '<S15>/Block#1' */
  void *VRSink_PWORK[27];              /* '<Root>/VR Sink' */
  void *Block2_PWORK;                  /* '<S15>/Block#2' */
  void *Block3_PWORK;                  /* '<S15>/Block#3' */
  int_T Block1_IWORK;                  /* '<S15>/Block#1' */
  int_T Block3_IWORK;                  /* '<S15>/Block#3' */
  int8_T If_ActiveSubsystem;           /* '<S9>/If' */
  int8_T Phi0_SubsysRanBC;             /* '<S9>/Phi == 0' */
  int8_T If_ActiveSubsystem_l;         /* '<S10>/If' */
  int8_T Phi0_SubsysRanBC_b;           /* '<S10>/Phi == 0' */
  int8_T If_ActiveSubsystem_i;         /* '<S11>/If' */
  int8_T Phi0_SubsysRanBC_n;           /* '<S11>/Phi == 0' */
  int8_T If_ActiveSubsystem_c;         /* '<S12>/If' */
  int8_T Phi0_SubsysRanBC_g;           /* '<S12>/Phi == 0' */
  int8_T If_ActiveSubsystem_b;         /* '<S13>/If' */
  int8_T Phi0_SubsysRanBC_l;           /* '<S13>/Phi == 0' */
  int8_T If_ActiveSubsystem_m;         /* '<S14>/If' */
  int8_T Phi0_SubsysRanBC_d;           /* '<S14>/Phi == 0' */
  rtDW_Generalcase_vmrl_test_four Generalcase_b;/* '<S14>/General case' */
  rtDW_Phipi_vmrl_test_fourbar Phipi_n;/* '<S14>/Phi == pi' */
  rtDW_Generalcase_vmrl_test_four Generalcase_l;/* '<S13>/General case' */
  rtDW_Phipi_vmrl_test_fourbar Phipi_j;/* '<S13>/Phi == pi' */
  rtDW_Generalcase_vmrl_test_four Generalcase_k;/* '<S12>/General case' */
  rtDW_Phipi_vmrl_test_fourbar Phipi_g;/* '<S12>/Phi == pi' */
  rtDW_Generalcase_vmrl_test_four Generalcase_g;/* '<S11>/General case' */
  rtDW_Phipi_vmrl_test_fourbar Phipi_e;/* '<S11>/Phi == pi' */
  rtDW_Generalcase_vmrl_test_four Generalcase_c;/* '<S10>/General case' */
  rtDW_Phipi_vmrl_test_fourbar Phipi_m;/* '<S10>/Phi == pi' */
  rtDW_Generalcase_vmrl_test_four Generalcase;/* '<S9>/General case' */
  rtDW_Phipi_vmrl_test_fourbar Phipi;  /* '<S9>/Phi == pi' */
} D_Work_vmrl_test_fourbar;

/* Continuous states (auto storage) */
typedef struct {
  real_T Block1_CSTATE[6];             /* '<S15>/Block#1' */
} ContinuousStates_vmrl_test_fourbar;

/* State derivatives (auto storage) */
typedef struct {
  real_T Block1_CSTATE[6];             /* '<S15>/Block#1' */
} StateDerivatives_vmrl_test_fourbar;

/* State disabled  */
typedef struct {
  boolean_T Block1_CSTATE[6];          /* '<S15>/Block#1' */
} StateDisabled_vmrl_test_fourbar;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            vmrl_test_fourbar_B
#define BlockIO                        BlockIO_vmrl_test_fourbar
#define rtX                            vmrl_test_fourbar_X
#define ContinuousStates               ContinuousStates_vmrl_test_fourbar
#define rtP                            vmrl_test_fourbar_P
#define Parameters                     Parameters_vmrl_test_fourbar
#define rtDWork                        vmrl_test_fourbar_DWork
#define D_Work                         D_Work_vmrl_test_fourbar

/* Parameters for system: '<S9>/Phi == pi' */
struct rtP_Phipi_vmrl_test_fourbar {
  real_T Shiftright_table[24];         /* Expression: [1 1 1;-1 1 1;1 1 -1;1 1 1;1 -1 1;1 1 1;1 1 1;1 1 1]
                                        * '<S23>/Shift right'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * '<S23>/Gain1'
                                        */
  real_T VRRot_Pi_Y0[4];               /* Expression: [0 0 0 pi]
                                        * 'synthesized block'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * '<S22>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * '<S22>/Gain'
                                        */
  real_T DeadZone_Start;               /* Expression: -maxzero
                                        * '<S23>/Dead Zone'
                                        */
  real_T DeadZone_End;                 /* Expression: maxzero
                                        * '<S23>/Dead Zone'
                                        */
  real_T Pi1_Value[3];                 /* Expression: [1 1 1]
                                        * '<S23>/Pi1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * '<S23>/Switch'
                                        */
  real_T Pi_Value;                     /* Expression: pi
                                        * '<S22>/Pi'
                                        */
  real_T Switch_Threshold_h;           /* Expression: maxzero
                                        * '<S22>/Switch'
                                        */
};

/* Parameters for system: '<S9>/General case' */
struct rtP_Generalcase_vmrl_test_fourb {
  real_T Constant_Value;               /* Expression: 1
                                        * '<S20>/Constant'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.5
                                        * '<S20>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: 2
                                        * '<S20>/Gain'
                                        */
};

/* Parameters (auto storage) */
struct Parameters_vmrl_test_fourbar {
  real_T Block1_SimMechanicsRuntimeParam[200];/* Computed Parameter: SimMechanicsRuntimeParameters
                                               * '<S15>/Block#1'
                                               */
  real_T gain_2_Gain;                  /* Expression: 1
                                        * '<S1>/gain_2'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * '<S9>/Constant'
                                        */
  real_T gain_1_Gain;                  /* Expression: 1
                                        * '<S1>/gain_1'
                                        */
  real_T gain_2_Gain_n;                /* Expression: 1
                                        * '<S5>/gain_2'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * '<S10>/Constant'
                                        */
  real_T gain_1_Gain_m;                /* Expression: 1
                                        * '<S5>/gain_1'
                                        */
  real_T gain_2_Gain_n0;               /* Expression: 1
                                        * '<S3>/gain_2'
                                        */
  real_T Constant_Value_e;             /* Expression: 1
                                        * '<S11>/Constant'
                                        */
  real_T gain_1_Gain_p;                /* Expression: 1
                                        * '<S3>/gain_1'
                                        */
  real_T gain_2_Gain_o;                /* Expression: 1
                                        * '<S4>/gain_2'
                                        */
  real_T Constant_Value_a;             /* Expression: 1
                                        * '<S12>/Constant'
                                        */
  real_T gain_1_Gain_k;                /* Expression: 1
                                        * '<S4>/gain_1'
                                        */
  real_T Constant_Value_ej;            /* Expression: 1
                                        * '<S13>/Constant'
                                        */
  real_T gain_2_Gain_d;                /* Expression: 1
                                        * '<S2>/gain_2'
                                        */
  real_T Constant_Value_b;             /* Expression: 1
                                        * '<S14>/Constant'
                                        */
  real_T gain_1_Gain_h;                /* Expression: 1
                                        * '<S2>/gain_1'
                                        */
  real_T SOURCE_BLOCK_Value[3];        /* Expression: Gravity
                                        * '<S8>/SOURCE_BLOCK'
                                        */
  real_T _gravity_conversion_Gain;     /* Expression: -1
                                        * '<S15>/_gravity_conversion'
                                        */
  real_T VRRot_0_Y0[4];                /* Expression: [0 1 0 0]
                                        * 'synthesized block'
                                        */
  real_T Trace3Phi0_Value[4];          /* Expression: [0 1 0 0]
                                        * '<S21>/Trace=3=>Phi=0'
                                        */
  real_T VRRot_0_Y0_i[4];              /* Expression: [0 1 0 0]
                                        * 'synthesized block'
                                        */
  real_T Trace3Phi0_Value_h[4];        /* Expression: [0 1 0 0]
                                        * '<S26>/Trace=3=>Phi=0'
                                        */
  real_T VRRot_0_Y0_d[4];              /* Expression: [0 1 0 0]
                                        * 'synthesized block'
                                        */
  real_T Trace3Phi0_Value_i[4];        /* Expression: [0 1 0 0]
                                        * '<S31>/Trace=3=>Phi=0'
                                        */
  real_T VRRot_0_Y0_b[4];              /* Expression: [0 1 0 0]
                                        * 'synthesized block'
                                        */
  real_T Trace3Phi0_Value_b[4];        /* Expression: [0 1 0 0]
                                        * '<S36>/Trace=3=>Phi=0'
                                        */
  real_T VRRot_0_Y0_e[4];              /* Expression: [0 1 0 0]
                                        * 'synthesized block'
                                        */
  real_T Trace3Phi0_Value_o[4];        /* Expression: [0 1 0 0]
                                        * '<S41>/Trace=3=>Phi=0'
                                        */
  real_T VRRot_0_Y0_l[4];              /* Expression: [0 1 0 0]
                                        * 'synthesized block'
                                        */
  real_T Trace3Phi0_Value_e[4];        /* Expression: [0 1 0 0]
                                        * '<S46>/Trace=3=>Phi=0'
                                        */
  rtP_Generalcase_vmrl_test_fourb Generalcase_b;/* '<S9>/General case' */
  rtP_Phipi_vmrl_test_fourbar Phipi_n; /* '<S9>/Phi == pi' */
  rtP_Generalcase_vmrl_test_fourb Generalcase_l;/* '<S9>/General case' */
  rtP_Phipi_vmrl_test_fourbar Phipi_j; /* '<S9>/Phi == pi' */
  rtP_Generalcase_vmrl_test_fourb Generalcase_k;/* '<S9>/General case' */
  rtP_Phipi_vmrl_test_fourbar Phipi_g; /* '<S9>/Phi == pi' */
  rtP_Generalcase_vmrl_test_fourb Generalcase_g;/* '<S9>/General case' */
  rtP_Phipi_vmrl_test_fourbar Phipi_e; /* '<S9>/Phi == pi' */
  rtP_Generalcase_vmrl_test_fourb Generalcase_c;/* '<S9>/General case' */
  rtP_Phipi_vmrl_test_fourbar Phipi_m; /* '<S9>/Phi == pi' */
  rtP_Generalcase_vmrl_test_fourb Generalcase;/* '<S9>/General case' */
  rtP_Phipi_vmrl_test_fourbar Phipi;   /* '<S9>/Phi == pi' */
};

/* Real-time Model Data Structure */
struct RT_MODEL_vmrl_test_fourbar {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    real_T *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    real_T *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeF[1][6];
    ODE1_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;

  /*
   * Work:
   * The following substructure contains information regarding
   * the work vectors in the model.
   */
  struct {
    void *dwork;
  } Work;
};

/* Block parameters (auto storage) */
extern Parameters_vmrl_test_fourbar vmrl_test_fourbar_P;

/* Block signals (auto storage) */
extern BlockIO_vmrl_test_fourbar vmrl_test_fourbar_B;

/* Continuous states (auto storage) */
extern ContinuousStates_vmrl_test_fourbar vmrl_test_fourbar_X;

/* Block states (auto storage) */
extern D_Work_vmrl_test_fourbar vmrl_test_fourbar_DWork;

/* Model entry point functions */
extern void vmrl_test_fourbar_initialize(boolean_T firstTime);
extern void vmrl_test_fourbar_output(int_T tid);
extern void vmrl_test_fourbar_update(int_T tid);
extern void vmrl_test_fourbar_terminate(void);

/* Real-time Model object */
extern RT_MODEL_vmrl_test_fourbar *vmrl_test_fourbar_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : vmrl_test_fourbar
 * '<S1>'   : vmrl_test_fourbar/Body Sensor2
 * '<S2>'   : vmrl_test_fourbar/Body Sensor3
 * '<S3>'   : vmrl_test_fourbar/Body Sensor4
 * '<S4>'   : vmrl_test_fourbar/Body Sensor5
 * '<S5>'   : vmrl_test_fourbar/BodySensor
 * '<S6>'   : vmrl_test_fourbar/Ground
 * '<S7>'   : vmrl_test_fourbar/Ground2
 * '<S8>'   : vmrl_test_fourbar/Machine Environment
 * '<S9>'   : vmrl_test_fourbar/R
 * '<S10>'  : vmrl_test_fourbar/R1
 * '<S11>'  : vmrl_test_fourbar/R2
 * '<S12>'  : vmrl_test_fourbar/R3
 * '<S13>'  : vmrl_test_fourbar/R4
 * '<S14>'  : vmrl_test_fourbar/R5
 * '<S15>'  : vmrl_test_fourbar/Ground/_mech_engine
 * '<S16>'  : vmrl_test_fourbar/Ground/_mech_engine/actuators
 * '<S17>'  : vmrl_test_fourbar/Ground/_mech_engine/sensors
 * '<S18>'  : vmrl_test_fourbar/Ground/_mech_engine/actuators/stub actuators
 * '<S19>'  : vmrl_test_fourbar/Ground/_mech_engine/sensors/stub sensors
 * '<S20>'  : vmrl_test_fourbar/R/General case
 * '<S21>'  : vmrl_test_fourbar/R/Phi == 0
 * '<S22>'  : vmrl_test_fourbar/R/Phi == pi
 * '<S23>'  : vmrl_test_fourbar/R/Phi == pi/Logic for flipping axis signs
 * '<S24>'  : vmrl_test_fourbar/R/Phi == pi/Logic for flipping axis signs/Compare To Zero
 * '<S25>'  : vmrl_test_fourbar/R1/General case
 * '<S26>'  : vmrl_test_fourbar/R1/Phi == 0
 * '<S27>'  : vmrl_test_fourbar/R1/Phi == pi
 * '<S28>'  : vmrl_test_fourbar/R1/Phi == pi/Logic for flipping axis signs
 * '<S29>'  : vmrl_test_fourbar/R1/Phi == pi/Logic for flipping axis signs/Compare To Zero
 * '<S30>'  : vmrl_test_fourbar/R2/General case
 * '<S31>'  : vmrl_test_fourbar/R2/Phi == 0
 * '<S32>'  : vmrl_test_fourbar/R2/Phi == pi
 * '<S33>'  : vmrl_test_fourbar/R2/Phi == pi/Logic for flipping axis signs
 * '<S34>'  : vmrl_test_fourbar/R2/Phi == pi/Logic for flipping axis signs/Compare To Zero
 * '<S35>'  : vmrl_test_fourbar/R3/General case
 * '<S36>'  : vmrl_test_fourbar/R3/Phi == 0
 * '<S37>'  : vmrl_test_fourbar/R3/Phi == pi
 * '<S38>'  : vmrl_test_fourbar/R3/Phi == pi/Logic for flipping axis signs
 * '<S39>'  : vmrl_test_fourbar/R3/Phi == pi/Logic for flipping axis signs/Compare To Zero
 * '<S40>'  : vmrl_test_fourbar/R4/General case
 * '<S41>'  : vmrl_test_fourbar/R4/Phi == 0
 * '<S42>'  : vmrl_test_fourbar/R4/Phi == pi
 * '<S43>'  : vmrl_test_fourbar/R4/Phi == pi/Logic for flipping axis signs
 * '<S44>'  : vmrl_test_fourbar/R4/Phi == pi/Logic for flipping axis signs/Compare To Zero
 * '<S45>'  : vmrl_test_fourbar/R5/General case
 * '<S46>'  : vmrl_test_fourbar/R5/Phi == 0
 * '<S47>'  : vmrl_test_fourbar/R5/Phi == pi
 * '<S48>'  : vmrl_test_fourbar/R5/Phi == pi/Logic for flipping axis signs
 * '<S49>'  : vmrl_test_fourbar/R5/Phi == pi/Logic for flipping axis signs/Compare To Zero
 */
#endif                                 /* RTW_HEADER_vmrl_test_fourbar_h_ */
