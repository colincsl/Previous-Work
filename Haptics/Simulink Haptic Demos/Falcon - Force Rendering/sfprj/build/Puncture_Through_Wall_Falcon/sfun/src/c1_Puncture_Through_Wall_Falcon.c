/* Include files */
#include "Puncture_Through_Wall_Falcon_sfun.h"
#include "c1_Puncture_Through_Wall_Falcon.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "Puncture_Through_Wall_Falcon_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c1_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc1_Puncture_Through_Wall_FalconInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c1_Puncture_Through_Wall_Falcon(void);
static void initialize_params_c1_Puncture_Through_Wall_Falcon(void);
static void enable_c1_Puncture_Through_Wall_Falcon(void);
static void disable_c1_Puncture_Through_Wall_Falcon(void);
static void ext_mode_exec_c1_Puncture_Through_Wall_Falcon(void);
static void finalize_c1_Puncture_Through_Wall_Falcon(void);
static void sf_c1_Puncture_Through_Wall_Falcon(void);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
 c1_chartNumber);
static const mxArray *c1_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_b_sf_marshall(void *c1_chartInstance, void *c1_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c1_Puncture_Through_Wall_Falcon(void)
{
  uint8_T *c1_is_active_c1_Puncture_Through_Wall_Falcon;
  c1_is_active_c1_Puncture_Through_Wall_Falcon = (uint8_T
    *)ssGetDWork(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c1_is_active_c1_Puncture_Through_Wall_Falcon = 0U;
}

static void initialize_params_c1_Puncture_Through_Wall_Falcon(void)
{
}

static void enable_c1_Puncture_Through_Wall_Falcon(void)
{
}

static void disable_c1_Puncture_Through_Wall_Falcon(void)
{
}

static void ext_mode_exec_c1_Puncture_Through_Wall_Falcon(void)
{
}

static void finalize_c1_Puncture_Through_Wall_Falcon(void)
{
}

static void sf_c1_Puncture_Through_Wall_Falcon(void)
{
  int32_T c1_i0;
  int32_T c1_i1;
  uint8_T c1_previousEvent;
  int32_T c1_i2;
  real_T c1_u[3];
  real_T c1_y[3];
  int32_T c1_i3;
  real_T c1_b_u[3];
  const mxArray *c1_b_y = NULL;
  int32_T c1_i4;
  real_T c1_d0;
  real_T c1_d1;
  int32_T c1_i5;
  real_T (*c1_c_y)[3];
  real_T (*c1_c_u)[3];
  c1_c_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c1_c_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  for(c1_i0 = 0; c1_i0 < 3; c1_i0 = c1_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_c_u)[c1_i0], 1U);
  }
  for(c1_i1 = 0; c1_i1 < 3; c1_i1 = c1_i1 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_c_y)[c1_i1], 0U);
  }
  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  for(c1_i2 = 0; c1_i2 < 3; c1_i2 = c1_i2 + 1) {
    c1_u[c1_i2] = (*c1_c_u)[c1_i2];
  }
  sf_debug_symbol_scope_push(2U, 0U);
  sf_debug_symbol_scope_add("y", &c1_y, c1_b_sf_marshall);
  sf_debug_symbol_scope_add("u", &c1_u, c1_sf_marshall);
  CV_EML_FCN(0, 0);
  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,4);
  sf_mex_printf("%s =\\n", "u");
  for(c1_i3 = 0; c1_i3 < 3; c1_i3 = c1_i3 + 1) {
    c1_b_u[c1_i3] = c1_u[c1_i3];
  }
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create(&c1_b_u, "y", 0, 0U, 1U, 1, 3));
  sf_mex_call("disp", 0U, 1U, 14, c1_b_y);
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,5);
  for(c1_i4 = 0; c1_i4 < 3; c1_i4 = c1_i4 + 1) {
    c1_y[c1_i4] = 0.0;
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,6);
  c1_d0 = _SFD_NOT_NAN_CHECK("", c1_u[0]);
  c1_d1 = c1_d0 < 0.0 ? ceil(c1_d0 - 0.5) : floor(c1_d0 + 0.5);
 c1_y[0] = (real_T)(int8_T)(c1_d1 <= 127.0 ? c1_d1 >= -128.0 ? c1_d1 : -128.0 :
    127.0);
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-6);
  sf_debug_symbol_scope_pop();
  for(c1_i5 = 0; c1_i5 < 3; c1_i5 = c1_i5 + 1) {
    (*c1_c_y)[c1_i5] = c1_y[c1_i5];
  }
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency(_Puncture_Through_Wall_FalconMachineNumber_,
   chartInstance.chartNumber, chartInstance.
   instanceNumber);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
 c1_chartNumber)
{
}

static const mxArray *c1_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i6;
  real_T c1_b_u[3];
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  for(c1_i6 = 0; c1_i6 < 3; c1_i6 = c1_i6 + 1) {
    c1_b_u[c1_i6] = (*((real_T (*)[3])c1_u))[c1_i6];
  }
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create(&c1_b_u, "y", 0, 0U, 1U, 1, 3));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_b_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i7;
  real_T c1_b_u[3];
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  for(c1_i7 = 0; c1_i7 < 3; c1_i7 = c1_i7 + 1) {
    c1_b_u[c1_i7] = (*((real_T (*)[3])c1_u))[c1_i7];
  }
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create(&c1_b_u, "y", 0, 0U, 1U, 1, 3));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

const mxArray
*sf_c1_Puncture_Through_Wall_Falcon_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_ResolvedFunctionInfo c1_info[2];
  c1_ResolvedFunctionInfo (*c1_b_info)[2];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i8;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_b_info = &c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "zeros";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved = "[B]zeros";
  (*c1_b_info)[0].fileLength = 0U;
  (*c1_b_info)[0].fileTime1 = 0U;
  (*c1_b_info)[0].fileTime2 = 0U;
  (*c1_b_info)[1].context = "";
  (*c1_b_info)[1].name = "int8";
  (*c1_b_info)[1].dominantType = "double";
  (*c1_b_info)[1].resolved = "[B]int8";
  (*c1_b_info)[1].fileLength = 0U;
  (*c1_b_info)[1].fileTime1 = 0U;
  (*c1_b_info)[1].fileTime2 = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 2));
  for(c1_i8 = 0; c1_i8 < 2; c1_i8 = c1_i8 + 1) {
    c1_r0 = &c1_info[c1_i8];
    sf_mex_addfield(c1_m0, sf_mex_create(c1_r0->context, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c1_r0->context)), "context",
     "nameCaptureInfo", c1_i8);
    sf_mex_addfield(c1_m0, sf_mex_create(c1_r0->name, "nameCaptureInfo", 13, 0U,
      0U, 2, 1, strlen(c1_r0->name)), "name",
     "nameCaptureInfo", c1_i8);
    sf_mex_addfield(c1_m0, sf_mex_create(c1_r0->dominantType, "nameCaptureInfo",
      13, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)),
     "dominantType", "nameCaptureInfo", c1_i8);
    sf_mex_addfield(c1_m0, sf_mex_create(c1_r0->resolved, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved",
     "nameCaptureInfo", c1_i8);
    sf_mex_addfield(c1_m0, sf_mex_create(&c1_r0->fileLength, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileLength", "nameCaptureInfo", c1_i8);
    sf_mex_addfield(c1_m0, sf_mex_create(&c1_r0->fileTime1, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c1_i8);
    sf_mex_addfield(c1_m0, sf_mex_create(&c1_r0->fileTime2, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c1_i8);
  }
  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c1_Puncture_Through_Wall_Falcon_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(897653793U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2661691418U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2036391632U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1819226076U);
}

mxArray *sf_c1_Puncture_Through_Wall_Falcon_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(130584216U);
    pr[1] = (double)(1989216233U);
    pr[2] = (double)(303598171U);
    pr[3] = (double)(1744496417U);
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

static void chart_debug_initialization(SimStruct *S, unsigned int
 fullDebuggerInitialization)
{
  if(ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
    /* do this only if simulation is starting */
    if(!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent =
          sf_debug_initialize_chart(_Puncture_Through_Wall_FalconMachineNumber_,
         1,
         1,
         1,
         2,
         0,
         0,
         0,
         0,
         0,
         &(chartInstance.chartNumber),
         &(chartInstance.instanceNumber),
         ssGetPath(S),
         (void *)S);
        if(chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_Puncture_Through_Wall_FalconMachineNumber_,chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_Puncture_Through_Wall_FalconMachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_Puncture_Through_Wall_FalconMachineNumber_,
           chartInstance.chartNumber,
           0,
           0,
           0);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,1.0,0,"u",0,c1_sf_marshall);
          }
          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,1.0,0,"y",0,c1_b_sf_marshall);
          }
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }
        _SFD_CV_INIT_CHART(0,0,0,0);
        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,140);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(0,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL,
           0,NULL,NULL);
        }

        {
          real_T (*c1_u)[3];
          real_T (*c1_y)[3];
          c1_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
          c1_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_u);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_y);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_Puncture_Through_Wall_FalconMachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c1_Puncture_Through_Wall_Falcon(void
 *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c1_Puncture_Through_Wall_Falcon();
  initialize_c1_Puncture_Through_Wall_Falcon();
}

static void sf_opaque_enable_c1_Puncture_Through_Wall_Falcon(void
 *chartInstanceVar)
{
  enable_c1_Puncture_Through_Wall_Falcon();
}

static void sf_opaque_disable_c1_Puncture_Through_Wall_Falcon(void
 *chartInstanceVar)
{
  disable_c1_Puncture_Through_Wall_Falcon();
}

static void sf_opaque_gateway_c1_Puncture_Through_Wall_Falcon(void
 *chartInstanceVar)
{
  sf_c1_Puncture_Through_Wall_Falcon();
}

static void sf_opaque_ext_mode_exec_c1_Puncture_Through_Wall_Falcon(void
 *chartInstanceVar)
{
  ext_mode_exec_c1_Puncture_Through_Wall_Falcon();
}

static void sf_opaque_terminate_c1_Puncture_Through_Wall_Falcon(void
 *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) ||
   sim_mode_is_external(chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }
  finalize_c1_Puncture_Through_Wall_Falcon();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_Puncture_Through_Wall_Falcon(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  if(sf_machine_global_initializer_called()) {
    initialize_params_c1_Puncture_Through_Wall_Falcon();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr =
  "100 S1x2'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}";
  sf_set_encoded_dwork_info(S, dworkEncStr);
}

static void mdlSetWorkWidths_c1_Puncture_Through_Wall_Falcon(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("Puncture_Through_Wall_Falcon",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("Puncture_Through_Wall_Falcon",1,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"Puncture_Through_Wall_Falcon",1,1);
      sf_mark_chart_reusable_outputs(S,"Puncture_Through_Wall_Falcon",1,1);
    }
    sf_set_rtw_dwork_info(S,"Puncture_Through_Wall_Falcon",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(1955887450U));
  ssSetChecksum1(S,(2245123369U));
  ssSetChecksum2(S,(3315190904U));
  ssSetChecksum3(S,(1221045441U));

  ssSetmdlDerivatives(S, NULL);

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_Puncture_Through_Wall_Falcon(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Puncture_Through_Wall_Falcon", 1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_Puncture_Through_Wall_Falcon(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_Puncture_Through_Wall_Falcon;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c1_Puncture_Through_Wall_Falcon;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c1_Puncture_Through_Wall_Falcon;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c1_Puncture_Through_Wall_Falcon;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c1_Puncture_Through_Wall_Falcon;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c1_Puncture_Through_Wall_Falcon;
  chartInstance.chartInfo.mdlStart = mdlStart_c1_Puncture_Through_Wall_Falcon;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_Puncture_Through_Wall_Falcon;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c1_Puncture_Through_Wall_Falcon;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo))); /* register the chart instance with simstruct */

  if(!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }
  chart_debug_initialization(S,1);
}

void c1_Puncture_Through_Wall_Falcon_method_dispatcher(SimStruct *S, int_T
 method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_Puncture_Through_Wall_Falcon(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_Puncture_Through_Wall_Falcon(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_Puncture_Through_Wall_Falcon(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c1_Puncture_Through_Wall_Falcon_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

