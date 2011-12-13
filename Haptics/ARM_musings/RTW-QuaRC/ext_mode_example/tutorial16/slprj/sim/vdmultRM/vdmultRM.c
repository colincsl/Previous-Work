#include "vdmultRM_capi.h"
#include "vdmultRM.h"
#include "vdmultRM_private.h"

int_T vdmultRM_GlobalTID[1];
static RegMdlInfo rtMdlInfo_vdmultRM[35] = {
  { "rtMdlrefDWork_mr_vdmultRM", MDL_INFO_NAME_MDLREF_DWORK, 0, 0, (void *)
    "vdmultRM" },

  { "rtZCSV_mr_vdmultRM", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "rtXdis_mr_vdmultRM", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "rtXdot_mr_vdmultRM", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "rtX_mr_vdmultRM", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "rtRTM_mr_vdmultRM", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "rtZCE_mr_vdmultRM", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "rtC_mr_vdmultRM", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "rtP_mr_vdmultRM", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "rtDW_mr_vdmultRM", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "rtB_mr_vdmultRM", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "mr_vdmultRM_ZCSV", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "mr_vdmultRM_Xdis", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "mr_vdmultRM_Xdot", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "mr_vdmultRM_X", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "mr_vdmultRM_RTM", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "mr_vdmultRM_ZCE", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "mr_vdmultRM_C", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "mr_vdmultRM_P", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "mr_vdmultRM_DW", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "mr_vdmultRM_B", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "mr_vdmultRM_rty_0", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "mr_vdmultRM_rtu_1", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "mr_vdmultRM_rtu_0", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "mr_vdmultRM_Term", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "mr_vdmultRM_initialize", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689,
    (void *) "vdmultRM" },

  { "mr_vdmultRM_Start", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "mr_vdmultRM", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 0, 1, (void *) "vdmultRM" },

  { "vdmultRM", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 0, 1, NULL },

  { "RT_MODEL_vdmultRM", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "vdmultRM_GlobalTID", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "vdmultRM_ConstP", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void *)
    "vdmultRM" },

  { "ConstParam_vdmultRM", MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT, 1, 647586689, (void
    *) "vdmultRM" },

  { "vdmultRM.h", MDL_INFO_MODEL_FILENAME, 0, 1, NULL },

  { "vdmultRM.c", MDL_INFO_MODEL_FILENAME, 0, 1, NULL } };

void mr_vdmultRM(const real_T *rtu_0, const real_T *rtu_1, real_T *rty_0)
{
  (*rty_0) = (1.0 - (*rtu_0) * (*rtu_0)) * (*rtu_1) * 1.0;
}

void mr_vdmultRM_initialize(SimStruct * _mdlRefSfcnS, int_T mdlref_TID0,
  RT_MODEL_vdmultRM *vdmultRM_M, void *sysRanPtr, int contextTid,
  rtwCAPI_ModelMappingInfo *rt_ParentMMI, const char_T *rt_ChildPath, int_T
  rt_ChildMMIIdx, int_T rt_CSTATEIdx)
{
  rt_InitInfAndNaN(sizeof(real_T));
  (void) memset((char_T *)vdmultRM_M,0,
                sizeof(RT_MODEL_vdmultRM));
  vdmultRM_GlobalTID[0] = mdlref_TID0;
  vdmultRM_M->_mdlRefSfcnS = (_mdlRefSfcnS);
  vdmultRM_InitializeDataMapInfo(vdmultRM_M, sysRanPtr, contextTid);
  if ((rt_ParentMMI != NULL) && (rt_ChildPath != NULL)) {
    rtwCAPI_SetChildMMI(*rt_ParentMMI, rt_ChildMMIIdx,
                        &(vdmultRM_M->DataMapInfo.mmi));
    rtwCAPI_SetPath(vdmultRM_M->DataMapInfo.mmi, rt_ChildPath);
    rtwCAPI_MMISetContStateStartIndex(vdmultRM_M->DataMapInfo.mmi, rt_CSTATEIdx);
  }
}

void mr_vdmultRM_MdlInfoRegFcn(SimStruct* mdlRefSfcnS, char_T *modelName)
{
  ssRegModelRefMdlInfo(mdlRefSfcnS, modelName, rtMdlInfo_vdmultRM, 35);
}
