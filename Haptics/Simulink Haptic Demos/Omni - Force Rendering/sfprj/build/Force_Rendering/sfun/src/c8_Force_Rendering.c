/* Include files */
#include "Force_Rendering_sfun.h"
#include "c8_Force_Rendering.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "Force_Rendering_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c8_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc8_Force_RenderingInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c8_Force_Rendering(void);
static void initialize_params_c8_Force_Rendering(void);
static void enable_c8_Force_Rendering(void);
static void disable_c8_Force_Rendering(void);
static void ext_mode_exec_c8_Force_Rendering(void);
static void finalize_c8_Force_Rendering(void);
static void sf_c8_Force_Rendering(void);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
 c8_chartNumber);
static const mxArray *c8_sf_marshall(void *c8_chartInstance, void *c8_u);
static const mxArray *c8_b_sf_marshall(void *c8_chartInstance, void *c8_u);
static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[23]);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c8_Force_Rendering(void)
{
  uint8_T *c8_is_active_c8_Force_Rendering;
  c8_is_active_c8_Force_Rendering = (uint8_T *)ssGetDWork(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c8_is_active_c8_Force_Rendering = 0U;
}

static void initialize_params_c8_Force_Rendering(void)
{
}

static void enable_c8_Force_Rendering(void)
{
}

static void disable_c8_Force_Rendering(void)
{
}

static void ext_mode_exec_c8_Force_Rendering(void)
{
}

static void finalize_c8_Force_Rendering(void)
{
}

static void sf_c8_Force_Rendering(void)
{
  int32_T c8_i0;
  int32_T c8_i1;
  uint8_T c8_previousEvent;
  int32_T c8_i2;
  real_T c8_m[3];
  real_T c8_q[3];
  int32_T c8_i3;
  real_T c8_A;
  real_T c8_B;
  real_T c8_x;
  real_T c8_y;
  real_T c8_b_y;
  int32_T c8_i4;
  real_T (*c8_b_q)[3];
  real_T (*c8_b_m)[3];
  c8_b_q = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c8_b_m = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  for(c8_i0 = 0; c8_i0 < 3; c8_i0 = c8_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((*c8_b_m)[c8_i0], 0U);
  }
  for(c8_i1 = 0; c8_i1 < 3; c8_i1 = c8_i1 + 1) {
    _SFD_DATA_RANGE_CHECK((*c8_b_q)[c8_i1], 1U);
  }
  c8_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,3);
  for(c8_i2 = 0; c8_i2 < 3; c8_i2 = c8_i2 + 1) {
    c8_m[c8_i2] = (*c8_b_m)[c8_i2];
  }
  sf_debug_symbol_scope_push(2U, 0U);
  sf_debug_symbol_scope_add("q", &c8_q, c8_b_sf_marshall);
  sf_debug_symbol_scope_add("m", &c8_m, c8_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,2);
  for(c8_i3 = 0; c8_i3 < 3; c8_i3 = c8_i3 + 1) {
    c8_q[c8_i3] = c8_m[c8_i3];
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,3);
  c8_q[0] = c8_m[0];
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,4);
  c8_q[1] = c8_m[1];
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,5);
  c8_A = 3.1415926535897931E+000;
  c8_B = 2.0;
  c8_x = c8_A;
  c8_y = c8_B;
  c8_b_y = c8_x / c8_y;
  c8_q[2] = (c8_m[2] - c8_m[1]) - c8_b_y;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-5);
  sf_debug_symbol_scope_pop();
  for(c8_i4 = 0; c8_i4 < 3; c8_i4 = c8_i4 + 1) {
    (*c8_b_q)[c8_i4] = c8_q[c8_i4];
  }
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,3);
  _sfEvent_ = c8_previousEvent;
  sf_debug_check_for_state_inconsistency(_Force_RenderingMachineNumber_,
   chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
 c8_chartNumber)
{
}

static const mxArray *c8_sf_marshall(void *c8_chartInstance, void *c8_u)
{
  const mxArray *c8_y = NULL;
  int32_T c8_i5;
  real_T c8_b_u[3];
  const mxArray *c8_b_y = NULL;
  c8_y = NULL;
  for(c8_i5 = 0; c8_i5 < 3; c8_i5 = c8_i5 + 1) {
    c8_b_u[c8_i5] = (*((real_T (*)[3])c8_u))[c8_i5];
  }
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create(&c8_b_u, "y", 0, 0U, 1U, 1, 3));
  sf_mex_assign(&c8_y, c8_b_y);
  return c8_y;
}

static const mxArray *c8_b_sf_marshall(void *c8_chartInstance, void *c8_u)
{
  const mxArray *c8_y = NULL;
  int32_T c8_i6;
  real_T c8_b_u[3];
  const mxArray *c8_b_y = NULL;
  c8_y = NULL;
  for(c8_i6 = 0; c8_i6 < 3; c8_i6 = c8_i6 + 1) {
    c8_b_u[c8_i6] = (*((real_T (*)[3])c8_u))[c8_i6];
  }
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create(&c8_b_u, "y", 0, 0U, 1U, 1, 3));
  sf_mex_assign(&c8_y, c8_b_y);
  return c8_y;
}

const mxArray *sf_c8_Force_Rendering_get_eml_resolved_functions_info(void)
{
  const mxArray *c8_nameCaptureInfo = NULL;
  c8_ResolvedFunctionInfo c8_info[23];
  const mxArray *c8_m0 = NULL;
  int32_T c8_i7;
  c8_ResolvedFunctionInfo *c8_r0;
  c8_nameCaptureInfo = NULL;
  c8_info_helper(c8_info);
  sf_mex_assign(&c8_m0, sf_mex_createstruct("nameCaptureInfo", 1, 23));
  for(c8_i7 = 0; c8_i7 < 23; c8_i7 = c8_i7 + 1) {
    c8_r0 = &c8_info[c8_i7];
    sf_mex_addfield(c8_m0, sf_mex_create(c8_r0->context, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c8_r0->context)), "context",
     "nameCaptureInfo", c8_i7);
    sf_mex_addfield(c8_m0, sf_mex_create(c8_r0->name, "nameCaptureInfo", 13, 0U,
      0U, 2, 1, strlen(c8_r0->name)), "name",
     "nameCaptureInfo", c8_i7);
    sf_mex_addfield(c8_m0, sf_mex_create(c8_r0->dominantType, "nameCaptureInfo",
      13, 0U, 0U, 2, 1, strlen(c8_r0->dominantType)),
     "dominantType", "nameCaptureInfo", c8_i7);
    sf_mex_addfield(c8_m0, sf_mex_create(c8_r0->resolved, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c8_r0->resolved)), "resolved",
     "nameCaptureInfo", c8_i7);
    sf_mex_addfield(c8_m0, sf_mex_create(&c8_r0->fileLength, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileLength", "nameCaptureInfo", c8_i7);
    sf_mex_addfield(c8_m0, sf_mex_create(&c8_r0->fileTime1, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c8_i7);
    sf_mex_addfield(c8_m0, sf_mex_create(&c8_r0->fileTime2, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c8_i7);
  }
  sf_mex_assign(&c8_nameCaptureInfo, c8_m0);
  return c8_nameCaptureInfo;
}

static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[23])
{
  c8_info[0].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[0].name = "isreal";
  c8_info[0].dominantType = "double";
  c8_info[0].resolved = "[B]isreal";
  c8_info[0].fileLength = 0U;
  c8_info[0].fileTime1 = 0U;
  c8_info[0].fileTime2 = 0U;
  c8_info[1].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c8_info[1].name = "rdivide";
  c8_info[1].dominantType = "double";
  c8_info[1].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[1].fileLength = 4533U;
  c8_info[1].fileTime1 = 1177099748U;
  c8_info[1].fileTime2 = 0U;
  c8_info[2].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c8_info[2].name = "class";
  c8_info[2].dominantType = "char";
  c8_info[2].resolved = "[B]class";
  c8_info[2].fileLength = 0U;
  c8_info[2].fileTime1 = 0U;
  c8_info[2].fileTime2 = 0U;
  c8_info[3].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isscalar.m";
  c8_info[3].name = "length";
  c8_info[3].dominantType = "double";
  c8_info[3].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c8_info[3].fileLength = 347U;
  c8_info[3].fileTime1 = 1163970770U;
  c8_info[3].fileTime2 = 0U;
  c8_info[4].context = "";
  c8_info[4].name = "mrdivide";
  c8_info[4].dominantType = "double";
  c8_info[4].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c8_info[4].fileLength = 653U;
  c8_info[4].fileTime1 = 1160446802U;
  c8_info[4].fileTime2 = 0U;
  c8_info[5].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c8_info[5].name = "isscalar";
  c8_info[5].dominantType = "double";
  c8_info[5].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isscalar.m";
  c8_info[5].fileLength = 243U;
  c8_info[5].fileTime1 = 1160446704U;
  c8_info[5].fileTime2 = 0U;
  c8_info[6].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isnumeric.m";
  c8_info[6].name = "isa";
  c8_info[6].dominantType = "double";
  c8_info[6].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c8_info[6].fileLength = 791U;
  c8_info[6].fileTime1 = 1160446618U;
  c8_info[6].fileTime2 = 0U;
  c8_info[7].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c8_info[7].name = "nargin";
  c8_info[7].dominantType = "";
  c8_info[7].resolved = "[B]nargin";
  c8_info[7].fileLength = 0U;
  c8_info[7].fileTime1 = 0U;
  c8_info[7].fileTime2 = 0U;
  c8_info[8].context = "";
  c8_info[8].name = "pi";
  c8_info[8].dominantType = "";
  c8_info[8].resolved = "[B]pi";
  c8_info[8].fileLength = 0U;
  c8_info[8].fileTime1 = 0U;
  c8_info[8].fileTime2 = 0U;
  c8_info[9].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[9].name = "isinteger";
  c8_info[9].dominantType = "double";
  c8_info[9].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isinteger.m";
  c8_info[9].fileLength = 254U;
  c8_info[9].fileTime1 = 1160446620U;
  c8_info[9].fileTime2 = 0U;
  c8_info[10].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c8_info[10].name = "eml_numel";
  c8_info[10].dominantType = "double";
  c8_info[10].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_numel.m";
  c8_info[10].fileLength = 278U;
  c8_info[10].fileTime1 = 1163970802U;
  c8_info[10].fileTime2 = 0U;
  c8_info[11].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c8_info[11].name = "size";
  c8_info[11].dominantType = "double";
  c8_info[11].resolved = "[B]size";
  c8_info[11].fileLength = 0U;
  c8_info[11].fileTime1 = 0U;
  c8_info[11].fileTime2 = 0U;
  c8_info[12].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[12].name = "isnumeric";
  c8_info[12].dominantType = "double";
  c8_info[12].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isnumeric.m";
  c8_info[12].fileLength = 250U;
  c8_info[12].fileTime1 = 1160446622U;
  c8_info[12].fileTime2 = 0U;
  c8_info[13].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c8_info[13].name = "ischar";
  c8_info[13].dominantType = "char";
  c8_info[13].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/strfun/ischar.m";
  c8_info[13].fileLength = 244U;
  c8_info[13].fileTime1 = 1160446834U;
  c8_info[13].fileTime2 = 0U;
  c8_info[14].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c8_info[14].name = "eml_is_float_class";
  c8_info[14].dominantType = "char";
  c8_info[14].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c8_info[14].fileLength = 273U;
  c8_info[14].fileTime1 = 1160446744U;
  c8_info[14].fileTime2 = 0U;
  c8_info[15].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isscalar.m";
  c8_info[15].name = "gt";
  c8_info[15].dominantType = "double";
  c8_info[15].resolved = "[B]gt";
  c8_info[15].fileLength = 0U;
  c8_info[15].fileTime1 = 0U;
  c8_info[15].fileTime2 = 0U;
  c8_info[16].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c8_info[16].name = "strcmp";
  c8_info[16].dominantType = "char";
  c8_info[16].resolved = "[B]strcmp";
  c8_info[16].fileLength = 0U;
  c8_info[16].fileTime1 = 0U;
  c8_info[16].fileTime2 = 0U;
  c8_info[17].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c8_info[17].name = "eq";
  c8_info[17].dominantType = "double";
  c8_info[17].resolved = "[B]eq";
  c8_info[17].fileLength = 0U;
  c8_info[17].fileTime1 = 0U;
  c8_info[17].fileTime2 = 0U;
  c8_info[18].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c8_info[18].name = "eml_is_integer_class";
  c8_info[18].dominantType = "char";
  c8_info[18].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m";
  c8_info[18].fileLength = 462U;
  c8_info[18].fileTime1 = 1160446744U;
  c8_info[18].fileTime2 = 0U;
  c8_info[19].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_numel.m";
  c8_info[19].name = "numel";
  c8_info[19].dominantType = "double";
  c8_info[19].resolved = "[B]numel";
  c8_info[19].fileLength = 0U;
  c8_info[19].fileTime1 = 0U;
  c8_info[19].fileTime2 = 0U;
  c8_info[20].context = "";
  c8_info[20].name = "minus";
  c8_info[20].dominantType = "double";
  c8_info[20].resolved = "[B]minus";
  c8_info[20].fileLength = 0U;
  c8_info[20].fileTime1 = 0U;
  c8_info[20].fileTime2 = 0U;
  c8_info[21].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c8_info[21].name = "eml_assert";
  c8_info[21].dominantType = "char";
  c8_info[21].resolved = "[B]eml_assert";
  c8_info[21].fileLength = 0U;
  c8_info[21].fileTime1 = 0U;
  c8_info[21].fileTime2 = 0U;
  c8_info[22].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c8_info[22].name = "ge";
  c8_info[22].dominantType = "double";
  c8_info[22].resolved = "[B]ge";
  c8_info[22].fileLength = 0U;
  c8_info[22].fileTime1 = 0U;
  c8_info[22].fileTime2 = 0U;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c8_Force_Rendering_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2360150138U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(200929811U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3898969174U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2719754842U);
}

mxArray *sf_c8_Force_Rendering_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(15288773U);
    pr[1] = (double)(2358491514U);
    pr[2] = (double)(1554106539U);
    pr[3] = (double)(1471443881U);
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
          sf_debug_initialize_chart(_Force_RenderingMachineNumber_,
         8,
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
          init_script_number_translation(_Force_RenderingMachineNumber_,chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_Force_RenderingMachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_Force_RenderingMachineNumber_,
           chartInstance.chartNumber,
           0,
           0,
           0);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,1.0,0,"m",0,c8_sf_marshall);
          }
          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,1.0,0,"q",0,c8_b_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,94);
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
          real_T (*c8_m)[3];
          real_T (*c8_q)[3];
          c8_q = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
          c8_m = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c8_m);
          _SFD_SET_DATA_VALUE_PTR(1U, c8_q);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_Force_RenderingMachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c8_Force_Rendering(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c8_Force_Rendering();
  initialize_c8_Force_Rendering();
}

static void sf_opaque_enable_c8_Force_Rendering(void *chartInstanceVar)
{
  enable_c8_Force_Rendering();
}

static void sf_opaque_disable_c8_Force_Rendering(void *chartInstanceVar)
{
  disable_c8_Force_Rendering();
}

static void sf_opaque_gateway_c8_Force_Rendering(void *chartInstanceVar)
{
  sf_c8_Force_Rendering();
}

static void sf_opaque_ext_mode_exec_c8_Force_Rendering(void *chartInstanceVar)
{
  ext_mode_exec_c8_Force_Rendering();
}

static void sf_opaque_terminate_c8_Force_Rendering(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) ||
   sim_mode_is_external(chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }
  finalize_c8_Force_Rendering();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_Force_Rendering(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  if(sf_machine_global_initializer_called()) {
    initialize_params_c8_Force_Rendering();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr =
  "100 S1x2'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}";
  sf_set_encoded_dwork_info(S, dworkEncStr);
}

static void mdlSetWorkWidths_c8_Force_Rendering(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("Force_Rendering",8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("Force_Rendering",8,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"Force_Rendering",8,1);
      sf_mark_chart_reusable_outputs(S,"Force_Rendering",8,1);
    }
    sf_set_rtw_dwork_info(S,"Force_Rendering",8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(3590998851U));
  ssSetChecksum1(S,(3980622259U));
  ssSetChecksum2(S,(4059684619U));
  ssSetChecksum3(S,(596273749U));

  ssSetmdlDerivatives(S, NULL);

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c8_Force_Rendering(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Force_Rendering", 8);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_Force_Rendering(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_Force_Rendering;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c8_Force_Rendering;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c8_Force_Rendering;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c8_Force_Rendering;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c8_Force_Rendering;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c8_Force_Rendering;
  chartInstance.chartInfo.mdlStart = mdlStart_c8_Force_Rendering;
  chartInstance.chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c8_Force_Rendering;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c8_Force_Rendering;
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

void c8_Force_Rendering_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_Force_Rendering(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_Force_Rendering(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_Force_Rendering(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c8_Force_Rendering_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

