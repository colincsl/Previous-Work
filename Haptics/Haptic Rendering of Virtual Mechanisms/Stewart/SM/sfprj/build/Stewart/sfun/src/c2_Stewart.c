/* Include files */
#include "Stewart_sfun.h"
#include "c2_Stewart.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "Stewart_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc2_StewartInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c2_Stewart(void);
static void initialize_params_c2_Stewart(void);
static void enable_c2_Stewart(void);
static void disable_c2_Stewart(void);
static void ext_mode_exec_c2_Stewart(void);
static void finalize_c2_Stewart(void);
static void sf_c2_Stewart(void);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
 c2_chartNumber);
static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_c_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_d_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_e_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_f_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_g_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_h_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_i_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_j_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_k_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_l_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_m_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_n_sf_marshall(void *c2_chartInstance, void *c2_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c2_Stewart(void)
{
  uint8_T *c2_is_active_c2_Stewart;
  c2_is_active_c2_Stewart = (uint8_T *)ssGetDWork(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c2_is_active_c2_Stewart = 0U;
}

static void initialize_params_c2_Stewart(void)
{
}

static void enable_c2_Stewart(void)
{
}

static void disable_c2_Stewart(void)
{
}

static void ext_mode_exec_c2_Stewart(void)
{
}

static void finalize_c2_Stewart(void)
{
}

static void sf_c2_Stewart(void)
{
  uint8_T c2_previousEvent;
  real_T c2_i1;
  real_T c2_i2;
  real_T c2_i3;
  real_T c2_i4;
  real_T c2_i5;
  real_T c2_i6;
  real_T c2_f;
  real_T c2_force;
  real_T c2_o6;
  real_T c2_o5;
  real_T c2_o4;
  real_T c2_o3;
  real_T c2_o2;
  real_T c2_o1;
  real_T *c2_b_i1;
  real_T *c2_b_o1;
  real_T *c2_b_i2;
  real_T *c2_b_i3;
  real_T *c2_b_i4;
  real_T *c2_b_i5;
  real_T *c2_b_i6;
  real_T *c2_b_o2;
  real_T *c2_b_o3;
  real_T *c2_b_o4;
  real_T *c2_b_o5;
  real_T *c2_b_o6;
  real_T *c2_b_f;
  c2_b_i5 = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
  c2_b_o5 = (real_T *)ssGetOutputPortSignal(chartInstance.S, 5);
  c2_b_f = (real_T *)ssGetInputPortSignal(chartInstance.S, 6);
  c2_b_i1 = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c2_b_o6 = (real_T *)ssGetOutputPortSignal(chartInstance.S, 6);
  c2_b_o1 = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_b_o3 = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c2_b_i4 = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
  c2_b_o2 = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c2_b_i2 = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c2_b_i3 = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
  c2_b_o4 = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c2_b_i6 = (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_DATA_RANGE_CHECK(*c2_b_i1, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_b_o1, 9U);
  _SFD_DATA_RANGE_CHECK(*c2_b_i2, 7U);
  _SFD_DATA_RANGE_CHECK(*c2_b_i3, 10U);
  _SFD_DATA_RANGE_CHECK(*c2_b_i4, 11U);
  _SFD_DATA_RANGE_CHECK(*c2_b_i5, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_b_i6, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_b_o2, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_b_o3, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_b_o4, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_b_o5, 12U);
  _SFD_DATA_RANGE_CHECK(*c2_b_o6, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_b_f, 8U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  c2_i1 = *c2_b_i1;
  c2_i2 = *c2_b_i2;
  c2_i3 = *c2_b_i3;
  c2_i4 = *c2_b_i4;
  c2_i5 = *c2_b_i5;
  c2_i6 = *c2_b_i6;
  c2_f = *c2_b_f;
  sf_debug_symbol_scope_push(14U, 0U);
  sf_debug_symbol_scope_add("force", &c2_force, c2_n_sf_marshall);
  sf_debug_symbol_scope_add("o6", &c2_o6, c2_m_sf_marshall);
  sf_debug_symbol_scope_add("o5", &c2_o5, c2_l_sf_marshall);
  sf_debug_symbol_scope_add("o4", &c2_o4, c2_k_sf_marshall);
  sf_debug_symbol_scope_add("o3", &c2_o3, c2_j_sf_marshall);
  sf_debug_symbol_scope_add("o2", &c2_o2, c2_i_sf_marshall);
  sf_debug_symbol_scope_add("o1", &c2_o1, c2_h_sf_marshall);
  sf_debug_symbol_scope_add("f", &c2_f, c2_g_sf_marshall);
  sf_debug_symbol_scope_add("i6", &c2_i6, c2_f_sf_marshall);
  sf_debug_symbol_scope_add("i5", &c2_i5, c2_e_sf_marshall);
  sf_debug_symbol_scope_add("i4", &c2_i4, c2_d_sf_marshall);
  sf_debug_symbol_scope_add("i3", &c2_i3, c2_c_sf_marshall);
  sf_debug_symbol_scope_add("i2", &c2_i2, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("i1", &c2_i1, c2_sf_marshall);
  CV_EML_FCN(0, 0);
  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,6);
  c2_force = c2_f;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,8);
  if(CV_EML_IF(0, 0, c2_i1 > -0.1)) {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,9);
    c2_o1 = c2_force;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,10);
    c2_o2 = c2_force;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,11);
    c2_o3 = c2_force;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,12);
    c2_o4 = c2_force;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,13);
    c2_o5 = c2_force;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,14);
    c2_o6 = c2_force;
  } else {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,16);
    c2_o1 = 0.0;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,17);
    c2_o2 = 0.0;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,18);
    c2_o3 = 0.0;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,19);
    c2_o4 = 0.0;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,20);
    c2_o5 = 0.0;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,21);
    c2_o6 = 0.0;
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-21);
  sf_debug_symbol_scope_pop();
  *c2_b_o1 = c2_o1;
  *c2_b_o2 = c2_o2;
  *c2_b_o3 = c2_o3;
  *c2_b_o4 = c2_o4;
  *c2_b_o5 = c2_o5;
  *c2_b_o6 = c2_o6;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_StewartMachineNumber_,
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

static const mxArray *c2_e_sf_marshall(void *c2_chartInstance, void *c2_u)
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

static const mxArray *c2_f_sf_marshall(void *c2_chartInstance, void *c2_u)
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

static const mxArray *c2_g_sf_marshall(void *c2_chartInstance, void *c2_u)
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

static const mxArray *c2_h_sf_marshall(void *c2_chartInstance, void *c2_u)
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

static const mxArray *c2_i_sf_marshall(void *c2_chartInstance, void *c2_u)
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

static const mxArray *c2_j_sf_marshall(void *c2_chartInstance, void *c2_u)
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

static const mxArray *c2_k_sf_marshall(void *c2_chartInstance, void *c2_u)
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

static const mxArray *c2_l_sf_marshall(void *c2_chartInstance, void *c2_u)
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

static const mxArray *c2_m_sf_marshall(void *c2_chartInstance, void *c2_u)
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

static const mxArray *c2_n_sf_marshall(void *c2_chartInstance, void *c2_u)
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

const mxArray *sf_c2_Stewart_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[2];
  c2_ResolvedFunctionInfo (*c2_b_info)[2];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i0;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_b_info = &c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "gt";
  (*c2_b_info)[0].dominantType = "double";
  (*c2_b_info)[0].resolved = "[B]gt";
  (*c2_b_info)[0].fileLength = 0U;
  (*c2_b_info)[0].fileTime1 = 0U;
  (*c2_b_info)[0].fileTime2 = 0U;
  (*c2_b_info)[1].context = "";
  (*c2_b_info)[1].name = "uminus";
  (*c2_b_info)[1].dominantType = "double";
  (*c2_b_info)[1].resolved = "[B]uminus";
  (*c2_b_info)[1].fileLength = 0U;
  (*c2_b_info)[1].fileTime1 = 0U;
  (*c2_b_info)[1].fileTime2 = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 2));
  for(c2_i0 = 0; c2_i0 < 2; c2_i0 = c2_i0 + 1) {
    c2_r0 = &c2_info[c2_i0];
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->context, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
     "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->name, "nameCaptureInfo", 13, 0U,
      0U, 2, 1, strlen(c2_r0->name)), "name",
     "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->dominantType, "nameCaptureInfo",
      13, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
     "dominantType", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->resolved, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved",
     "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create(&c2_r0->fileLength, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileLength", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create(&c2_r0->fileTime1, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create(&c2_r0->fileTime2, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i0);
  }
  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c2_Stewart_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1967822693U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3187024322U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(99266552U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3988667804U);
}

mxArray *sf_c2_Stewart_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1162244029U);
    pr[1] = (double)(4163145554U);
    pr[2] = (double)(1799314560U);
    pr[3] = (double)(1373286662U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);
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
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }
    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }
    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }
    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }
    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }
    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }
    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }
  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,mxREAL));
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);
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
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }
    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }
    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }
    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }
    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }
    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
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
        chartAlreadyPresent = sf_debug_initialize_chart(_StewartMachineNumber_,
         2,
         1,
         1,
         13,
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
          init_script_number_translation(_StewartMachineNumber_,chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_StewartMachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_StewartMachineNumber_,
           chartInstance.chartNumber,
           0,
           0,
           0);

          _SFD_SET_DATA_PROPS(5,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"i1",0,c2_sf_marshall);
          _SFD_SET_DATA_PROPS(9,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"o1",0,c2_h_sf_marshall);
          _SFD_SET_DATA_PROPS(7,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"i2",0,c2_b_sf_marshall);
          _SFD_SET_DATA_PROPS(10,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"i3",0,c2_c_sf_marshall);
          _SFD_SET_DATA_PROPS(11,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"i4",0,c2_d_sf_marshall);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"i5",0,c2_e_sf_marshall);
          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"i6",0,c2_f_sf_marshall);
          _SFD_SET_DATA_PROPS(3,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"o2",0,c2_i_sf_marshall);
          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"o3",0,c2_j_sf_marshall);
          _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"o4",0,c2_k_sf_marshall);
          _SFD_SET_DATA_PROPS(12,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"o5",0,c2_l_sf_marshall);
          _SFD_SET_DATA_PROPS(6,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"o6",0,c2_m_sf_marshall);
          _SFD_SET_DATA_PROPS(8,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"f",0,c2_g_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,330);
        _SFD_CV_INIT_EML_IF(0,0,165,176,261,329);
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
          real_T *c2_i1;
          real_T *c2_o1;
          real_T *c2_i2;
          real_T *c2_i3;
          real_T *c2_i4;
          real_T *c2_i5;
          real_T *c2_i6;
          real_T *c2_o2;
          real_T *c2_o3;
          real_T *c2_o4;
          real_T *c2_o5;
          real_T *c2_o6;
          real_T *c2_f;
          c2_i5 = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
          c2_o5 = (real_T *)ssGetOutputPortSignal(chartInstance.S, 5);
          c2_f = (real_T *)ssGetInputPortSignal(chartInstance.S, 6);
          c2_i1 = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c2_o6 = (real_T *)ssGetOutputPortSignal(chartInstance.S, 6);
          c2_o1 = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c2_o3 = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
          c2_i4 = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
          c2_o2 = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
          c2_i2 = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c2_i3 = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
          c2_o4 = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
          c2_i6 = (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_i1);
          _SFD_SET_DATA_VALUE_PTR(9U, c2_o1);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_i2);
          _SFD_SET_DATA_VALUE_PTR(10U, c2_i3);
          _SFD_SET_DATA_VALUE_PTR(11U, c2_i4);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_i5);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_i6);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_o2);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_o3);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_o4);
          _SFD_SET_DATA_VALUE_PTR(12U, c2_o5);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_o6);
          _SFD_SET_DATA_VALUE_PTR(8U, c2_f);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_StewartMachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c2_Stewart(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c2_Stewart();
  initialize_c2_Stewart();
}

static void sf_opaque_enable_c2_Stewart(void *chartInstanceVar)
{
  enable_c2_Stewart();
}

static void sf_opaque_disable_c2_Stewart(void *chartInstanceVar)
{
  disable_c2_Stewart();
}

static void sf_opaque_gateway_c2_Stewart(void *chartInstanceVar)
{
  sf_c2_Stewart();
}

static void sf_opaque_ext_mode_exec_c2_Stewart(void *chartInstanceVar)
{
  ext_mode_exec_c2_Stewart();
}

static void sf_opaque_terminate_c2_Stewart(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) ||
   sim_mode_is_external(chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }
  finalize_c2_Stewart();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_Stewart(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  if(sf_machine_global_initializer_called()) {
    initialize_params_c2_Stewart();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr =
  "100 S1x2'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}";
  sf_set_encoded_dwork_info(S, dworkEncStr);
}

static void mdlSetWorkWidths_c2_Stewart(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("Stewart",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("Stewart",2,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"Stewart",2,7);
      sf_mark_chart_reusable_outputs(S,"Stewart",2,6);
    }
    sf_set_rtw_dwork_info(S,"Stewart",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(1857552433U));
  ssSetChecksum1(S,(705653709U));
  ssSetChecksum2(S,(3827589661U));
  ssSetChecksum3(S,(2235062707U));

  ssSetmdlDerivatives(S, NULL);

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_Stewart(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Stewart", 2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_Stewart(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway = sf_opaque_gateway_c2_Stewart;
  chartInstance.chartInfo.initializeChart = sf_opaque_initialize_c2_Stewart;
  chartInstance.chartInfo.terminateChart = sf_opaque_terminate_c2_Stewart;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c2_Stewart;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c2_Stewart;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c2_Stewart;
  chartInstance.chartInfo.mdlStart = mdlStart_c2_Stewart;
  chartInstance.chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_Stewart;
  chartInstance.chartInfo.extModeExec = sf_opaque_ext_mode_exec_c2_Stewart;
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

void c2_Stewart_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_Stewart(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_Stewart(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_Stewart(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c2_Stewart_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

