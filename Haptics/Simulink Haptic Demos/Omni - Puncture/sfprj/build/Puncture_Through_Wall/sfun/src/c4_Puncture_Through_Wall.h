#ifndef __c4_Puncture_Through_Wall_h__
#define __c4_Puncture_Through_Wall_h__

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
} c4_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
} SFc4_Puncture_Through_WallInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
const mxArray *sf_c4_Puncture_Through_Wall_get_eml_resolved_functions_info(void);

/* Function Definitions */

extern void sf_c4_Puncture_Through_Wall_get_check_sum(mxArray *plhs[]);
extern void c4_Puncture_Through_Wall_method_dispatcher(SimStruct *S, int_T
 method, void *data);

#endif

