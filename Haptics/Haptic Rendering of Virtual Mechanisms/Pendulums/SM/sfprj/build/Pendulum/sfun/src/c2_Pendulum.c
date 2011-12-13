/* Include files */
#include "Pendulum_sfun.h"
#include "c2_Pendulum.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "Pendulum_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc2_PendulumInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c2_Pendulum(void);
static void initialize_params_c2_Pendulum(void);
static void enable_c2_Pendulum(void);
static void disable_c2_Pendulum(void);
static void ext_mode_exec_c2_Pendulum(void);
static void finalize_c2_Pendulum(void);
static void sf_c2_Pendulum(void);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
 c2_chartNumber);
static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_c_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_d_sf_marshall(void *c2_chartInstance, void *c2_u);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[22]);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c2_Pendulum(void)
{
  uint8_T *c2_is_active_c2_Pendulum;
  c2_is_active_c2_Pendulum = (uint8_T *)ssGetDWork(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c2_is_active_c2_Pendulum = 0U;
}

static void initialize_params_c2_Pendulum(void)
{
}

static void enable_c2_Pendulum(void)
{
}

static void disable_c2_Pendulum(void)
{
}

static void ext_mode_exec_c2_Pendulum(void)
{
}

static void finalize_c2_Pendulum(void)
{
}

static void sf_c2_Pendulum(void)
{
  uint8_T c2_previousEvent;
  real_T c2_u;
  real_T c2_y;
  real_T c2_x;
  real_T c2_r;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_c_y = NULL;
  int32_T c2_i0;
  static char c2_cv0[2] = { 'g', 'o' };
  char c2_d_u[2];
  const mxArray *c2_d_y = NULL;
  int32_T c2_i1;
  static real_T c2_dv0[4] = { -15.0, 15.0, -15.0, 15.0 };
  real_T c2_e_u[4];
  const mxArray *c2_e_y = NULL;
  real_T *c2_f_u;
  c2_f_u = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_DATA_RANGE_CHECK(*c2_f_u, 0U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  c2_u = *c2_f_u;
  sf_debug_symbol_scope_push(4U, 0U);
  sf_debug_symbol_scope_add("y", &c2_y, c2_d_sf_marshall);
  sf_debug_symbol_scope_add("x", &c2_x, c2_c_sf_marshall);
  sf_debug_symbol_scope_add("r", &c2_r, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("u", &c2_u, c2_sf_marshall);
  CV_EML_FCN(0, 0);
  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,5);
  c2_r = 10.0;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,7);
  c2_b_x = c2_u;
  c2_c_x = c2_b_x;
  c2_c_x = cos(c2_c_x);
  c2_x = c2_r * c2_c_x;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,8);
  c2_d_x = c2_u;
  c2_e_x = c2_d_x;
  c2_e_x = sin(c2_e_x);
  c2_y = c2_r * c2_e_x;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,10);
  c2_b_u = c2_x;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  c2_c_u = c2_y;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create(&c2_c_u, "y", 0, 0U, 0U, 0));
  for(c2_i0 = 0; c2_i0 < 2; c2_i0 = c2_i0 + 1) {
    c2_d_u[c2_i0] = c2_cv0[c2_i0];
  }
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create(&c2_d_u, "y", 8, 0U, 1U, 2, 1, 2));
  sf_mex_call("plot", 0U, 3U, 14, c2_b_y, 14, c2_c_y, 14, c2_d_y);
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,11);
  for(c2_i1 = 0; c2_i1 < 4; c2_i1 = c2_i1 + 1) {
    c2_e_u[c2_i1] = c2_dv0[c2_i1];
  }
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create(&c2_e_u, "y", 0, 0U, 1U, 2, 1, 4));
  sf_mex_call("axis", 0U, 1U, 14, c2_e_y);
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-11);
  sf_debug_symbol_scope_pop();
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_PendulumMachineNumber_,
   chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
 c2_chartNumber)
{
}

static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_c_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_d_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray *sf_c2_Pendulum_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[22];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i2;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 22));
  for(c2_i2 = 0; c2_i2 < 22; c2_i2 = c2_i2 + 1) {
    c2_r0 = &c2_info[c2_i2];
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->context, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
     "nameCaptureInfo", c2_i2);
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->name, "nameCaptureInfo", 13, 0U,
      0U, 2, 1, strlen(c2_r0->name)), "name",
     "nameCaptureInfo", c2_i2);
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->dominantType, "nameCaptureInfo",
      13, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
     "dominantType", "nameCaptureInfo", c2_i2);
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->resolved, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved",
     "nameCaptureInfo", c2_i2);
    sf_mex_addfield(c2_m0, sf_mex_create(&c2_r0->fileLength, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileLength", "nameCaptureInfo", c2_i2);
    sf_mex_addfield(c2_m0, sf_mex_create(&c2_r0->fileTime1, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i2);
    sf_mex_addfield(c2_m0, sf_mex_create(&c2_r0->fileTime2, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i2);
  }
  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[22])
{
  c2_info[0].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isfloat.m";
  c2_info[0].name = "isa";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c2_info[0].fileLength = 791U;
  c2_info[0].fileTime1 = 1160450218U;
  c2_info[0].fileTime2 = 0U;
  c2_info[1].context = "";
  c2_info[1].name = "plot";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved = "[MB]$matlabroot$/toolbox/matlab/graph2d/plot";
  c2_info[1].fileLength = 0U;
  c2_info[1].fileTime1 = 0U;
  c2_info[1].fileTime2 = 0U;
  c2_info[2].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c2_info[2].name = "class";
  c2_info[2].dominantType = "char";
  c2_info[2].resolved = "[B]class";
  c2_info[2].fileLength = 0U;
  c2_info[2].fileTime1 = 0U;
  c2_info[2].fileTime2 = 0U;
  c2_info[3].context = "";
  c2_info[3].name = "mtimes";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved = "[B]mtimes";
  c2_info[3].fileLength = 0U;
  c2_info[3].fileTime1 = 0U;
  c2_info[3].fileTime2 = 0U;
  c2_info[4].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[4].name = "nargin";
  c2_info[4].dominantType = "";
  c2_info[4].resolved = "[B]nargin";
  c2_info[4].fileLength = 0U;
  c2_info[4].fileTime1 = 0U;
  c2_info[4].fileTime2 = 0U;
  c2_info[5].context = "";
  c2_info[5].name = "sin";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[5].fileLength = 769U;
  c2_info[5].fileTime1 = 1163970754U;
  c2_info[5].fileTime2 = 0U;
  c2_info[6].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isscalar.m";
  c2_info[6].name = "length";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[6].fileLength = 347U;
  c2_info[6].fileTime1 = 1163970770U;
  c2_info[6].fileTime2 = 0U;
  c2_info[7].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[7].name = "isfloat";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isfloat.m";
  c2_info[7].fileLength = 182U;
  c2_info[7].fileTime1 = 1160450220U;
  c2_info[7].fileTime2 = 0U;
  c2_info[8].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[8].name = "eml_numel";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_numel.m";
  c2_info[8].fileLength = 278U;
  c2_info[8].fileTime1 = 1163970802U;
  c2_info[8].fileTime2 = 0U;
  c2_info[9].context = "";
  c2_info[9].name = "axis";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved = "[M]$matlabroot$/toolbox/matlab/graph2d/axis.m";
  c2_info[9].fileLength = 0U;
  c2_info[9].fileTime1 = 0U;
  c2_info[9].fileTime2 = 0U;
  c2_info[10].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[10].name = "size";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved = "[B]size";
  c2_info[10].fileLength = 0U;
  c2_info[10].fileTime1 = 0U;
  c2_info[10].fileTime2 = 0U;
  c2_info[11].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[11].name = "gt";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved = "[B]gt";
  c2_info[11].fileLength = 0U;
  c2_info[11].fileTime1 = 0U;
  c2_info[11].fileTime2 = 0U;
  c2_info[12].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_numel.m";
  c2_info[12].name = "numel";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved = "[B]numel";
  c2_info[12].fileLength = 0U;
  c2_info[12].fileTime1 = 0U;
  c2_info[12].fileTime2 = 0U;
  c2_info[13].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[13].name = "isscalar";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isscalar.m";
  c2_info[13].fileLength = 243U;
  c2_info[13].fileTime1 = 1160450304U;
  c2_info[13].fileTime2 = 0U;
  c2_info[14].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c2_info[14].name = "eml_is_float_class";
  c2_info[14].dominantType = "char";
  c2_info[14].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[14].fileLength = 273U;
  c2_info[14].fileTime1 = 1160450344U;
  c2_info[14].fileTime2 = 0U;
  c2_info[15].context = "";
  c2_info[15].name = "cos";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[15].fileLength = 772U;
  c2_info[15].fileTime1 = 1163970724U;
  c2_info[15].fileTime2 = 0U;
  c2_info[16].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[16].name = "eml_assert";
  c2_info[16].dominantType = "char";
  c2_info[16].resolved = "[B]eml_assert";
  c2_info[16].fileLength = 0U;
  c2_info[16].fileTime1 = 0U;
  c2_info[16].fileTime2 = 0U;
  c2_info[17].context = "";
  c2_info[17].name = "uminus";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved = "[B]uminus";
  c2_info[17].fileLength = 0U;
  c2_info[17].fileTime1 = 0U;
  c2_info[17].fileTime2 = 0U;
  c2_info[18].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[18].name = "isreal";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved = "[B]isreal";
  c2_info[18].fileLength = 0U;
  c2_info[18].fileTime1 = 0U;
  c2_info[18].fileTime2 = 0U;
  c2_info[19].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[19].name = "ischar";
  c2_info[19].dominantType = "char";
  c2_info[19].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/strfun/ischar.m";
  c2_info[19].fileLength = 244U;
  c2_info[19].fileTime1 = 1160450434U;
  c2_info[19].fileTime2 = 0U;
  c2_info[20].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c2_info[20].name = "strcmp";
  c2_info[20].dominantType = "char";
  c2_info[20].resolved = "[B]strcmp";
  c2_info[20].fileLength = 0U;
  c2_info[20].fileTime1 = 0U;
  c2_info[20].fileTime2 = 0U;
  c2_info[21].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c2_info[21].name = "eq";
  c2_info[21].dominantType = "double";
  c2_info[21].resolved = "[B]eq";
  c2_info[21].fileLength = 0U;
  c2_info[21].fileTime1 = 0U;
  c2_info[21].fileTime2 = 0U;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c2_Pendulum_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2259550127U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3931396054U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(522479283U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(363504643U);
}

mxArray *sf_c2_Pendulum_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2859409092U);
    pr[1] = (double)(2042434603U);
    pr[2] = (double)(3776126764U);
    pr[3] = (double)(3859451355U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxCreateDoubleMatrix(0,0,mxREAL));
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
        chartAlreadyPresent = sf_debug_initialize_chart(_PendulumMachineNumber_,
         2,
         1,
         1,
         1,
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
          init_script_number_translation(_PendulumMachineNumber_,chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_PendulumMachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_PendulumMachineNumber_,
           chartInstance.chartNumber,
           0,
           0,
           0);

          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"u",0,c2_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,178);
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
          real_T *c2_u;
          c2_u = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_u);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_PendulumMachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c2_Pendulum(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c2_Pendulum();
  initialize_c2_Pendulum();
}

static void sf_opaque_enable_c2_Pendulum(void *chartInstanceVar)
{
  enable_c2_Pendulum();
}

static void sf_opaque_disable_c2_Pendulum(void *chartInstanceVar)
{
  disable_c2_Pendulum();
}

static void sf_opaque_gateway_c2_Pendulum(void *chartInstanceVar)
{
  sf_c2_Pendulum();
}

static void sf_opaque_ext_mode_exec_c2_Pendulum(void *chartInstanceVar)
{
  ext_mode_exec_c2_Pendulum();
}

static void sf_opaque_terminate_c2_Pendulum(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) ||
   sim_mode_is_external(chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }
  finalize_c2_Pendulum();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_Pendulum(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  if(sf_machine_global_initializer_called()) {
    initialize_params_c2_Pendulum();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr =
  "100 S1x2'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}";
  sf_set_encoded_dwork_info(S, dworkEncStr);
}

static void mdlSetWorkWidths_c2_Pendulum(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("Pendulum",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("Pendulum",2,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"Pendulum",2,1);
    }
    sf_set_rtw_dwork_info(S,"Pendulum",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(2331382434U));
  ssSetChecksum1(S,(3948447051U));
  ssSetChecksum2(S,(949604586U));
  ssSetChecksum3(S,(1194545969U));

  ssSetmdlDerivatives(S, NULL);

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_Pendulum(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Pendulum", 2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_Pendulum(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway = sf_opaque_gateway_c2_Pendulum;
  chartInstance.chartInfo.initializeChart = sf_opaque_initialize_c2_Pendulum;
  chartInstance.chartInfo.terminateChart = sf_opaque_terminate_c2_Pendulum;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c2_Pendulum;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c2_Pendulum;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c2_Pendulum;
  chartInstance.chartInfo.mdlStart = mdlStart_c2_Pendulum;
  chartInstance.chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_Pendulum;
  chartInstance.chartInfo.extModeExec = sf_opaque_ext_mode_exec_c2_Pendulum;
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

void c2_Pendulum_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_Pendulum(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_Pendulum(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_Pendulum(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c2_Pendulum_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

