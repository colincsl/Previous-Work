/* Include files */
#include "Puncture_Through_Wall_sfun.h"
#include "c4_Puncture_Through_Wall.h"

/* Type Definitions */

/* Named Constants */
#define c4_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc4_Puncture_Through_WallInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c4_Puncture_Through_Wall(void);
static void initialize_params_c4_Puncture_Through_Wall(void);
static void enable_c4_Puncture_Through_Wall(void);
static void disable_c4_Puncture_Through_Wall(void);
static void finalize_c4_Puncture_Through_Wall(void);
static void sf_c4_Puncture_Through_Wall(void);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
 c4_chartNumber);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c4_Puncture_Through_Wall(void)
{
  uint8_T *c4_is_active_c4_Puncture_Through_Wall;
  c4_is_active_c4_Puncture_Through_Wall = (uint8_T *)ssGetDWork(chartInstance.S,
   1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c4_is_active_c4_Puncture_Through_Wall = 0U;
}

static void initialize_params_c4_Puncture_Through_Wall(void)
{
}

static void enable_c4_Puncture_Through_Wall(void)
{
}

static void disable_c4_Puncture_Through_Wall(void)
{
}

static void finalize_c4_Puncture_Through_Wall(void)
{
}

static void sf_c4_Puncture_Through_Wall(void)
{
  uint8_T c4_previousEvent;
  int32_T c4_i0;
  real_T c4_t[3];
  real_T c4_y[3];
  real_T c4_u[3];
  const mxArray *c4_b_y = NULL;
  real_T (*c4_c_y)[3];
  real_T (*c4_b_t)[3];
  c4_b_t = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  c4_c_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  c4_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  for(c4_i0 = 0; c4_i0 < 3; c4_i0 = c4_i0 + 1) {
    c4_t[c4_i0] = (*c4_b_t)[c4_i0];
    /*  Smart Saturation: allows channels to go up to 1.6A  */
    /*  unless the total exceeds 2.2A in which case all channels */
    /*  are scaled so that the cumulative current is equal to 2.2A. */
    c4_y[c4_i0] = 0.0;
  }
  sf_mex_printf("%s =\\n", "y");
  for(c4_i0 = 0; c4_i0 < 3; c4_i0 = c4_i0 + 1) {
    c4_u[c4_i0] = 0.0;
  }
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create(&c4_u, "y", 0, 0U, 1U, 1, 3));
  sf_mex_call("disp", 0U, 1U, 14, c4_b_y);
  c4_y[0] = c4_t[0];
  c4_y[2] = c4_t[2];
  c4_y[1] = c4_t[1] - c4_t[2];
  for(c4_i0 = 0; c4_i0 < 3; c4_i0 = c4_i0 + 1) {
    (*c4_c_y)[c4_i0] = c4_y[c4_i0];
  }
  _sfEvent_ = c4_previousEvent;
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
 c4_chartNumber)
{
}

const mxArray *sf_c4_Puncture_Through_Wall_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_ResolvedFunctionInfo c4_info[2];
  c4_ResolvedFunctionInfo (*c4_b_info)[2];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i1;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_b_info = &c4_info;
  (*c4_b_info)[0].context = "";
  (*c4_b_info)[0].name = "ctranspose";
  (*c4_b_info)[0].dominantType = "double";
  (*c4_b_info)[0].resolved = "[B]ctranspose";
  (*c4_b_info)[0].fileLength = 0U;
  (*c4_b_info)[0].fileTime1 = 0U;
  (*c4_b_info)[0].fileTime2 = 0U;
  (*c4_b_info)[1].context = "";
  (*c4_b_info)[1].name = "minus";
  (*c4_b_info)[1].dominantType = "double";
  (*c4_b_info)[1].resolved = "[B]minus";
  (*c4_b_info)[1].fileLength = 0U;
  (*c4_b_info)[1].fileTime1 = 0U;
  (*c4_b_info)[1].fileTime2 = 0U;
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 2));
  for(c4_i1 = 0; c4_i1 < 2; c4_i1 = c4_i1 + 1) {
    c4_r0 = &c4_info[c4_i1];
    sf_mex_addfield(c4_m0, sf_mex_create(c4_r0->context, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c4_r0->context)), "context",
     "nameCaptureInfo", c4_i1);
    sf_mex_addfield(c4_m0, sf_mex_create(c4_r0->name, "nameCaptureInfo", 13, 0U,
      0U, 2, 1, strlen(c4_r0->name)), "name",
     "nameCaptureInfo", c4_i1);
    sf_mex_addfield(c4_m0, sf_mex_create(c4_r0->dominantType, "nameCaptureInfo",
      13, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)),
     "dominantType", "nameCaptureInfo", c4_i1);
    sf_mex_addfield(c4_m0, sf_mex_create(c4_r0->resolved, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved",
     "nameCaptureInfo", c4_i1);
    sf_mex_addfield(c4_m0, sf_mex_create(&c4_r0->fileLength, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileLength", "nameCaptureInfo", c4_i1);
    sf_mex_addfield(c4_m0, sf_mex_create(&c4_r0->fileTime1, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c4_i1);
    sf_mex_addfield(c4_m0, sf_mex_create(&c4_r0->fileTime2, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c4_i1);
  }
  sf_mex_assign(&c4_nameCaptureInfo, c4_m0);
  return c4_nameCaptureInfo;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c4_Puncture_Through_Wall_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2424140381U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(831610729U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1159458045U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3157583317U);
}

mxArray *sf_c4_Puncture_Through_Wall_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(677216795U);
    pr[1] = (double)(3101977016U);
    pr[2] = (double)(2395616803U);
    pr[3] = (double)(401488537U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }
    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }
  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,mxREAL));
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }
    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }
  return(mxAutoinheritanceInfo);
}

static void sf_opaque_initialize_c4_Puncture_Through_Wall(void *chartInstanceVar)
{
  initialize_params_c4_Puncture_Through_Wall();
  initialize_c4_Puncture_Through_Wall();
}

static void sf_opaque_enable_c4_Puncture_Through_Wall(void *chartInstanceVar)
{
  enable_c4_Puncture_Through_Wall();
}

static void sf_opaque_disable_c4_Puncture_Through_Wall(void *chartInstanceVar)
{
  disable_c4_Puncture_Through_Wall();
}

static void sf_opaque_gateway_c4_Puncture_Through_Wall(void *chartInstanceVar)
{
  sf_c4_Puncture_Through_Wall();
}

static void sf_opaque_terminate_c4_Puncture_Through_Wall(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) ||
   sim_mode_is_external(chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }
  finalize_c4_Puncture_Through_Wall();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_Puncture_Through_Wall(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  if(sf_machine_global_initializer_called()) {
    initialize_params_c4_Puncture_Through_Wall();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr =
  "100 S1x2'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}";
  sf_set_encoded_dwork_info(S, dworkEncStr);
}

static void mdlSetWorkWidths_c4_Puncture_Through_Wall(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("Puncture_Through_Wall",4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("Puncture_Through_Wall",4,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"Puncture_Through_Wall",4,1);
      sf_mark_chart_reusable_outputs(S,"Puncture_Through_Wall",4,1);
    }
    sf_set_rtw_dwork_info(S,"Puncture_Through_Wall",4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(3120693966U));
  ssSetChecksum1(S,(4172049892U));
  ssSetChecksum2(S,(856923551U));
  ssSetChecksum3(S,(3655993862U));

  ssSetmdlDerivatives(S, NULL);

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c4_Puncture_Through_Wall(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Puncture_Through_Wall", 4);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_Puncture_Through_Wall(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_Puncture_Through_Wall;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c4_Puncture_Through_Wall;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c4_Puncture_Through_Wall;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c4_Puncture_Through_Wall;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c4_Puncture_Through_Wall;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c4_Puncture_Through_Wall;
  chartInstance.chartInfo.mdlStart = mdlStart_c4_Puncture_Through_Wall;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_Puncture_Through_Wall;
  chartInstance.chartInfo.extModeExec = NULL;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo))); /* register the chart instance with simstruct */

  if(!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }
}

void c4_Puncture_Through_Wall_method_dispatcher(SimStruct *S, int_T method, void
 *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_Puncture_Through_Wall(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_Puncture_Through_Wall(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_Puncture_Through_Wall(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c4_Puncture_Through_Wall_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

