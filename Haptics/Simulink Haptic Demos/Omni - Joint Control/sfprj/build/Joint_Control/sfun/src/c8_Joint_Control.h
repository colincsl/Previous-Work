#ifndef __c8_Joint_Control_h__
#define __c8_Joint_Control_h__

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
} c8_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  ChartInfoStruct chartInfo;
} SFc8_Joint_ControlInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
const mxArray *sf_c8_Joint_Control_get_eml_resolved_functions_info(void);

/* Function Definitions */

extern void sf_c8_Joint_Control_get_check_sum(mxArray *plhs[]);
extern void c8_Joint_Control_method_dispatcher(SimStruct *S, int_T method, void
 *data);

#endif

