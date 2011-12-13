#include "vdmultRM.h"
#include "rtw_capi.h"
#include "vdmultRM_private.h"

static rtwCAPI_Signals rtBlockSignals[] = {

  {
    0, 0, NULL, NULL, 0, 0, 0, 0, 0
  }
};

static rtwCAPI_LoggingBusElement rtBusElements[] = {
  { 0, rtwCAPI_signal }
};

static rtwCAPI_LoggingBusSignals rtBusSignals[] = {

  { NULL, NULL, 0, 0, NULL }
};

static rtwCAPI_States rtBlockStates[] = {

  {
    0, -1, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0
  }
};

static rtwCAPI_DataTypeMap rtDataTypeMap[] = {

  {
    "", "", 0, 0, 0, 0, 0, 0
  }
};

static rtwCAPI_ElementMap rtElementMap[] = {

  { NULL, 0, 0, 0, 0 },
};

static rtwCAPI_DimensionMap rtDimensionMap[] = {

  {
    rtwCAPI_SCALAR, 0, 0, 0
  }
};

static uint_T rtDimensionArray[] = { 0 };

static rtwCAPI_FixPtMap rtFixPtMap[] = {

  { NULL, NULL, rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

static rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {

  {
    NULL, NULL, 0, 0
  }
};

static int_T rtContextSystems[2];
static rtwCAPI_LoggingMetaInfo loggingMetaInfo[] = {
  { 0, 0, "", 0 }
};

static rtwCAPI_ModelMapLoggingStaticInfo mmiStaticInfoLogging = {
  2, rtContextSystems, loggingMetaInfo, 0, rtBusSignals
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {

  { rtBlockSignals, 0 },

  { NULL, 0,
    NULL, 0 },

  { rtBlockStates, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float", &mmiStaticInfoLogging
};

static void vdmultRM_InitializeSystemRan(sysRanDType *systemRan[],
  int_T systemTid[], void *rootSysRanPtr, int rootTid)
{
  systemRan[0] = (sysRanDType *) rootSysRanPtr;
  systemRan[1] = NULL;
  systemTid[1] = vdmultRM_GlobalTID[0];
  systemTid[0] = rootTid;
  rtContextSystems[0] = 0;
  rtContextSystems[1] = 0;
}

void vdmultRM_InitializeDataMapInfo(RT_MODEL_vdmultRM *vdmultRM_M
  , void *sysRanPtr, int contextTid)
{
  rtwCAPI_SetVersion(vdmultRM_M->DataMapInfo.mmi, 1);
  rtwCAPI_SetStaticMap(vdmultRM_M->DataMapInfo.mmi, &mmiStatic);
  rtwCAPI_SetLoggingStaticMap(vdmultRM_M->DataMapInfo.mmi, &mmiStaticInfoLogging);
  rtwCAPI_SetPath(vdmultRM_M->DataMapInfo.mmi, NULL);
  rtwCAPI_SetFullPath(vdmultRM_M->DataMapInfo.mmi, NULL);
  rtwCAPI_SetInstanceLoggingInfo(vdmultRM_M->DataMapInfo.mmi,
    &vdmultRM_M->DataMapInfo.mmiLogInstanceInfo);
  rtwCAPI_SetChildMMIArray(vdmultRM_M->DataMapInfo.mmi, NULL);
  rtwCAPI_SetChildMMIArrayLen(vdmultRM_M->DataMapInfo.mmi, 0);
  vdmultRM_InitializeSystemRan(vdmultRM_M->DataMapInfo.systemRan,
    vdmultRM_M->DataMapInfo.systemTid, sysRanPtr, contextTid);
  rtwCAPI_SetSystemRan(vdmultRM_M->DataMapInfo.mmi,
                       vdmultRM_M->DataMapInfo.systemRan);
  rtwCAPI_SetSystemTid(vdmultRM_M->DataMapInfo.mmi,
                       vdmultRM_M->DataMapInfo.systemTid);
  rtwCAPI_SetGlobalTIDMap(vdmultRM_M->DataMapInfo.mmi, &vdmultRM_GlobalTID[0]);
}
