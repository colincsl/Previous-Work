#ifndef RTW_HEADER_vdmultRM_h_
#define RTW_HEADER_vdmultRM_h_
#include "rtw_modelmap.h"
#ifndef vdmultRM_COMMON_INCLUDES_
# define vdmultRM_COMMON_INCLUDES_
#include <math.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_nonfinite.h"
#endif

#include "vdmultRM_types.h"

struct RT_MODEL_vdmultRM {
  struct SimStruct_tag *_mdlRefSfcnS;
  struct {
    rtwCAPI_ModelMappingInfo mmi;
    rtwCAPI_ModelMapLoggingInstanceInfo mmiLogInstanceInfo;
    sysRanDType* systemRan[2];
    int_T systemTid[2];
  } DataMapInfo;
};

typedef struct {
  RT_MODEL_vdmultRM rtm;
} rtMdlrefDWork_mr_vdmultRM;

extern void mr_vdmultRM_initialize(SimStruct * _mdlRefSfcnS, int_T mdlref_TID0,
  RT_MODEL_vdmultRM *vdmultRM_M, void *sysRanPtr, int contextTid,
  rtwCAPI_ModelMappingInfo *rt_ParentMMI, const char_T *rt_ChildPath, int_T
  rt_ChildMMIIdx, int_T rt_CSTATEIdx);
extern void mr_vdmultRM_MdlInfoRegFcn(SimStruct* mdlRefSfcnS, char_T *modelName);
extern void mr_vdmultRM(const real_T *rtu_0, const real_T *rtu_1, real_T *rty_0);

#endif
