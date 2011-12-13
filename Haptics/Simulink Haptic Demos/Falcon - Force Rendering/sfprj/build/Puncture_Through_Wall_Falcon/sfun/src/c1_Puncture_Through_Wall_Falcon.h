#ifndef __c1_Puncture_Through_Wall_Falcon_h__
#define __c1_Puncture_Through_Wall_Falcon_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"

/* Type Definitions */

typedef struct {
  char *context;
  char *name;
  char *dominantType;
  char *resolved;
  uint32_T fileLength;
  uint32_T fileTime1;
  uint32_T fileTime2;
} c1_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  ChartInfoStruct chartInfo;
} SFc1_Puncture_Through_Wall_FalconInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
const mxArray
*sf_c1_Puncture_Through_Wall_Falcon_get_eml_resolved_functions_info(void);

/* Function Definitions */

extern void sf_c1_Puncture_Through_Wall_Falcon_get_check_sum(mxArray *plhs[]);
extern void c1_Puncture_Through_Wall_Falcon_method_dispatcher(SimStruct *S,
 int_T method, void *data);

#endif

