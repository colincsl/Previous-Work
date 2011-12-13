/* Include files */
#include "Maze_Omni_sfun.h"
#include "c3_Maze_Omni.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "Maze_Omni_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c3_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc3_Maze_OmniInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c3_Maze_Omni(void);
static void initialize_params_c3_Maze_Omni(void);
static void enable_c3_Maze_Omni(void);
static void disable_c3_Maze_Omni(void);
static void ext_mode_exec_c3_Maze_Omni(void);
static void finalize_c3_Maze_Omni(void);
static void sf_c3_Maze_Omni(void);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
 c3_chartNumber);
static const mxArray *c3_sf_marshall(void *c3_chartInstance, void *c3_u);
static const mxArray *c3_b_sf_marshall(void *c3_chartInstance, void *c3_u);
static const mxArray *c3_c_sf_marshall(void *c3_chartInstance, void *c3_u);
static const mxArray *c3_d_sf_marshall(void *c3_chartInstance, void *c3_u);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[50]);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c3_Maze_Omni(void)
{
  uint8_T *c3_is_active_c3_Maze_Omni;
  c3_is_active_c3_Maze_Omni = (uint8_T *)ssGetDWork(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c3_is_active_c3_Maze_Omni = 0U;
}

static void initialize_params_c3_Maze_Omni(void)
{
}

static void enable_c3_Maze_Omni(void)
{
}

static void disable_c3_Maze_Omni(void)
{
}

static void ext_mode_exec_c3_Maze_Omni(void)
{
}

static void finalize_c3_Maze_Omni(void)
{
}

static void sf_c3_Maze_Omni(void)
{
  int32_T c3_i0;
  int32_T c3_i1;
  uint8_T c3_previousEvent;
  int32_T c3_i2;
  real_T c3_u[3];
  real_T c3_total;
  real_T c3_MAX_CURRENT;
  real_T c3_y[3];
  int32_T c3_i3;
  int32_T c3_i4;
  real_T c3_x[3];
  int32_T c3_i5;
  real_T c3_b_x[3];
  real_T c3_d0;
  real_T c3_k;
  real_T c3_b_k;
  int32_T c3_i6;
  real_T c3_c_x[3];
  real_T c3_d_x;
  int32_T c3_i7;
  int32_T c3_c_k;
  int32_T c3_d_k;
  real_T c3_e_x;
  real_T c3_r;
  real_T c3_A;
  real_T c3_B;
  real_T c3_f_x;
  real_T c3_b_y;
  real_T c3_c_y;
  int32_T c3_i8;
  int32_T c3_i9;
  int32_T c3_i10;
  real_T (*c3_d_y)[3];
  real_T (*c3_b_u)[3];
  c3_d_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c3_b_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  for(c3_i0 = 0; c3_i0 < 3; c3_i0 = c3_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_b_u)[c3_i0], 1U);
  }
  for(c3_i1 = 0; c3_i1 < 3; c3_i1 = c3_i1 + 1) {
    _SFD_DATA_RANGE_CHECK((*c3_d_y)[c3_i1], 0U);
  }
  c3_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  for(c3_i2 = 0; c3_i2 < 3; c3_i2 = c3_i2 + 1) {
    c3_u[c3_i2] = (*c3_b_u)[c3_i2];
  }
  sf_debug_symbol_scope_push(4U, 0U);
  sf_debug_symbol_scope_add("total", &c3_total, c3_d_sf_marshall);
  sf_debug_symbol_scope_add("MAX_CURRENT", &c3_MAX_CURRENT, c3_c_sf_marshall);
  sf_debug_symbol_scope_add("y", &c3_y, c3_b_sf_marshall);
  sf_debug_symbol_scope_add("u", &c3_u, c3_sf_marshall);
  CV_EML_FCN(0, 0);
  /*  Smart Saturation: allows channels to go up to 1.6A  */
  /*  unless the total exceeds 2.2A in which case all channels */
  /*  are scaled so that the cumulative current is equal to 2.2A. */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,6);
  for(c3_i3 = 0; c3_i3 < 3; c3_i3 = c3_i3 + 1) {
    c3_y[c3_i3] = 0.0;
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,7);
  c3_MAX_CURRENT = 2.2;
  /*  Define the maximum cumulative current here */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,9);
  for(c3_i4 = 0; c3_i4 < 3; c3_i4 = c3_i4 + 1) {
    c3_x[c3_i4] = c3_u[c3_i4];
  }
  for(c3_i5 = 0; c3_i5 < 3; c3_i5 = c3_i5 + 1) {
    c3_b_x[c3_i5] = 0.0;
  }
  c3_d0 = 1.0;
  for(c3_k = c3_d0; c3_k <= 3.0; c3_k = c3_k + 1.0) {
    c3_b_k = c3_k;
    c3_b_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("y",
     (int32_T)_SFD_INTEGER_CHECK("k", c3_b_k), 1, 3, 1, 0) - 1] =
      fabs(c3_x[(int32_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK("x", (int32_T)_SFD_INTEGER_CHECK("k", c3_b_k),
      1, 3, 1, 0) - 1]);
  }
  for(c3_i6 = 0; c3_i6 < 3; c3_i6 = c3_i6 + 1) {
    c3_c_x[c3_i6] = c3_b_x[c3_i6];
  }
  c3_d_x = c3_c_x[0];
  c3_total = c3_d_x;
  c3_i7 = 2;
  for(c3_c_k = c3_i7; c3_c_k < 4; c3_c_k = c3_c_k + 1) {
    c3_d_k = c3_c_k;
    c3_e_x = c3_c_x[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("x",
     _SFD_INTEGER_CHECK("k", (real_T)c3_d_k), 1, 3, 1, 0) - 1];
    c3_r = c3_e_x;
    c3_total = c3_total + c3_r;
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,10);
  if(CV_EML_IF(0, 0, c3_total > c3_MAX_CURRENT)) {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,11);
    c3_A = 2.2;
    c3_B = c3_total;
    c3_f_x = c3_A;
    c3_b_y = c3_B;
    c3_c_y = c3_f_x / c3_b_y;
    for(c3_i8 = 0; c3_i8 < 3; c3_i8 = c3_i8 + 1) {
      c3_y[c3_i8] = c3_c_y * c3_u[c3_i8];
    }
  } else {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,13);
    for(c3_i9 = 0; c3_i9 < 3; c3_i9 = c3_i9 + 1) {
      c3_y[c3_i9] = c3_u[c3_i9];
    }
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-13);
  sf_debug_symbol_scope_pop();
  for(c3_i10 = 0; c3_i10 < 3; c3_i10 = c3_i10 + 1) {
    (*c3_d_y)[c3_i10] = c3_y[c3_i10];
  }
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c3_previousEvent;
  sf_debug_check_for_state_inconsistency(_Maze_OmniMachineNumber_,
   chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
 c3_chartNumber)
{
}

static const mxArray *c3_sf_marshall(void *c3_chartInstance, void *c3_u)
{
  const mxArray *c3_y = NULL;
  int32_T c3_i11;
  real_T c3_b_u[3];
  const mxArray *c3_b_y = NULL;
  c3_y = NULL;
  for(c3_i11 = 0; c3_i11 < 3; c3_i11 = c3_i11 + 1) {
    c3_b_u[c3_i11] = (*((real_T (*)[3])c3_u))[c3_i11];
  }
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create(&c3_b_u, "y", 0, 0U, 1U, 1, 3));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static const mxArray *c3_b_sf_marshall(void *c3_chartInstance, void *c3_u)
{
  const mxArray *c3_y = NULL;
  int32_T c3_i12;
  real_T c3_b_u[3];
  const mxArray *c3_b_y = NULL;
  c3_y = NULL;
  for(c3_i12 = 0; c3_i12 < 3; c3_i12 = c3_i12 + 1) {
    c3_b_u[c3_i12] = (*((real_T (*)[3])c3_u))[c3_i12];
  }
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create(&c3_b_u, "y", 0, 0U, 1U, 1, 3));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static const mxArray *c3_c_sf_marshall(void *c3_chartInstance, void *c3_u)
{
  const mxArray *c3_y = NULL;
  real_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  c3_y = NULL;
  c3_b_u = *((real_T *)c3_u);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create(&c3_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

static const mxArray *c3_d_sf_marshall(void *c3_chartInstance, void *c3_u)
{
  const mxArray *c3_y = NULL;
  real_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  c3_y = NULL;
  c3_b_u = *((real_T *)c3_u);
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create(&c3_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c3_y, c3_b_y);
  return c3_y;
}

const mxArray *sf_c3_Maze_Omni_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_ResolvedFunctionInfo c3_info[50];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i13;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 50));
  for(c3_i13 = 0; c3_i13 < 50; c3_i13 = c3_i13 + 1) {
    c3_r0 = &c3_info[c3_i13];
    sf_mex_addfield(c3_m0, sf_mex_create(c3_r0->context, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c3_r0->context)), "context",
     "nameCaptureInfo", c3_i13);
    sf_mex_addfield(c3_m0, sf_mex_create(c3_r0->name, "nameCaptureInfo", 13, 0U,
      0U, 2, 1, strlen(c3_r0->name)), "name",
     "nameCaptureInfo", c3_i13);
    sf_mex_addfield(c3_m0, sf_mex_create(c3_r0->dominantType, "nameCaptureInfo",
      13, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)),
     "dominantType", "nameCaptureInfo", c3_i13);
    sf_mex_addfield(c3_m0, sf_mex_create(c3_r0->resolved, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved",
     "nameCaptureInfo", c3_i13);
    sf_mex_addfield(c3_m0, sf_mex_create(&c3_r0->fileLength, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileLength", "nameCaptureInfo", c3_i13);
    sf_mex_addfield(c3_m0, sf_mex_create(&c3_r0->fileTime1, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c3_i13);
    sf_mex_addfield(c3_m0, sf_mex_create(&c3_r0->fileTime2, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c3_i13);
  }
  sf_mex_assign(&c3_nameCaptureInfo, c3_m0);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[50])
{
  c3_info[0].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c3_info[0].name = "eml_nonsingleton_dim";
  c3_info[0].dominantType = "logical";
  c3_info[0].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m";
  c3_info[0].fileLength = 454U;
  c3_info[0].fileTime1 = 1160446750U;
  c3_info[0].fileTime2 = 0U;
  c3_info[1].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c3_info[1].name = "true";
  c3_info[1].dominantType = "";
  c3_info[1].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c3_info[1].fileLength = 625U;
  c3_info[1].fileTime1 = 1163970786U;
  c3_info[1].fileTime2 = 0U;
  c3_info[2].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isscalar.m";
  c3_info[2].name = "length";
  c3_info[2].dominantType = "double";
  c3_info[2].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c3_info[2].fileLength = 347U;
  c3_info[2].fileTime1 = 1163970770U;
  c3_info[2].fileTime2 = 0U;
  c3_info[3].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[3].name = "islogical";
  c3_info[3].dominantType = "double";
  c3_info[3].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/islogical.m";
  c3_info[3].fileLength = 186U;
  c3_info[3].fileTime1 = 1160446622U;
  c3_info[3].fileTime2 = 0U;
  c3_info[4].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m";
  c3_info[4].name = "ne";
  c3_info[4].dominantType = "double";
  c3_info[4].resolved = "[B]ne";
  c3_info[4].fileLength = 0U;
  c3_info[4].fileTime1 = 0U;
  c3_info[4].fileTime2 = 0U;
  c3_info[5].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m/sumwork";
  c3_info[5].name = "plus";
  c3_info[5].dominantType = "double";
  c3_info[5].resolved = "[B]plus";
  c3_info[5].fileLength = 0U;
  c3_info[5].fileTime1 = 0U;
  c3_info[5].fileTime2 = 0U;
  c3_info[6].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_numel.m";
  c3_info[6].name = "numel";
  c3_info[6].dominantType = "double";
  c3_info[6].resolved = "[B]numel";
  c3_info[6].fileLength = 0U;
  c3_info[6].fileTime1 = 0U;
  c3_info[6].fileTime2 = 0U;
  c3_info[7].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c3_info[7].name = "rdivide";
  c3_info[7].dominantType = "double";
  c3_info[7].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[7].fileLength = 4533U;
  c3_info[7].fileTime1 = 1177099748U;
  c3_info[7].fileTime2 = 0U;
  c3_info[8].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c3_info[8].name = "le";
  c3_info[8].dominantType = "int32";
  c3_info[8].resolved = "[B]le";
  c3_info[8].fileLength = 0U;
  c3_info[8].fileTime1 = 0U;
  c3_info[8].fileTime2 = 0U;
  c3_info[9].context = "";
  c3_info[9].name = "sum";
  c3_info[9].dominantType = "double";
  c3_info[9].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[9].fileLength = 2616U;
  c3_info[9].fileTime1 = 1163970698U;
  c3_info[9].fileTime2 = 0U;
  c3_info[10].context = "";
  c3_info[10].name = "zeros";
  c3_info[10].dominantType = "double";
  c3_info[10].resolved = "[B]zeros";
  c3_info[10].fileLength = 0U;
  c3_info[10].fileTime1 = 0U;
  c3_info[10].fileTime2 = 0U;
  c3_info[11].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[11].name = "nargin";
  c3_info[11].dominantType = "";
  c3_info[11].resolved = "[B]nargin";
  c3_info[11].fileLength = 0U;
  c3_info[11].fileTime1 = 0U;
  c3_info[11].fileTime2 = 0U;
  c3_info[12].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[12].name = "isfloat";
  c3_info[12].dominantType = "double";
  c3_info[12].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isfloat.m";
  c3_info[12].fileLength = 182U;
  c3_info[12].fileTime1 = 1160446620U;
  c3_info[12].fileTime2 = 0U;
  c3_info[13].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m/eml_isequal";
  c3_info[13].name = "all";
  c3_info[13].dominantType = "logical";
  c3_info[13].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c3_info[13].fileLength = 2066U;
  c3_info[13].fileTime1 = 1166598650U;
  c3_info[13].fileTime2 = 0U;
  c3_info[14].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isnumeric.m";
  c3_info[14].name = "isa";
  c3_info[14].dominantType = "double";
  c3_info[14].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c3_info[14].fileLength = 791U;
  c3_info[14].fileTime1 = 1160446618U;
  c3_info[14].fileTime2 = 0U;
  c3_info[15].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c3_info[15].name = "strcmp";
  c3_info[15].dominantType = "char";
  c3_info[15].resolved = "[B]strcmp";
  c3_info[15].fileLength = 0U;
  c3_info[15].fileTime1 = 0U;
  c3_info[15].fileTime2 = 0U;
  c3_info[16].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c3_info[16].name = "ischar";
  c3_info[16].dominantType = "char";
  c3_info[16].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/strfun/ischar.m";
  c3_info[16].fileLength = 244U;
  c3_info[16].fileTime1 = 1160446834U;
  c3_info[16].fileTime2 = 0U;
  c3_info[17].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c3_info[17].name = "isequal";
  c3_info[17].dominantType = "double";
  c3_info[17].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c3_info[17].fileLength = 2071U;
  c3_info[17].fileTime1 = 1163970770U;
  c3_info[17].fileTime2 = 0U;
  c3_info[18].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c3_info[18].name = "eml_numel";
  c3_info[18].dominantType = "double";
  c3_info[18].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_numel.m";
  c3_info[18].fileLength = 278U;
  c3_info[18].fileTime1 = 1163970802U;
  c3_info[18].fileTime2 = 0U;
  c3_info[19].context = "";
  c3_info[19].name = "abs";
  c3_info[19].dominantType = "double";
  c3_info[19].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[19].fileLength = 1031U;
  c3_info[19].fileTime1 = 1163970702U;
  c3_info[19].fileTime2 = 0U;
  c3_info[20].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c3_info[20].name = "size";
  c3_info[20].dominantType = "double";
  c3_info[20].resolved = "[B]size";
  c3_info[20].fileLength = 0U;
  c3_info[20].fileTime1 = 0U;
  c3_info[20].fileTime2 = 0U;
  c3_info[21].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c3_info[21].name = "floor";
  c3_info[21].dominantType = "double";
  c3_info[21].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c3_info[21].fileLength = 595U;
  c3_info[21].fileTime1 = 1163970736U;
  c3_info[21].fileTime2 = 0U;
  c3_info[22].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c3_info[22].name = "eml_is_float_class";
  c3_info[22].dominantType = "char";
  c3_info[22].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c3_info[22].fileLength = 273U;
  c3_info[22].fileTime1 = 1160446744U;
  c3_info[22].fileTime2 = 0U;
  c3_info[23].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[23].name = "isinteger";
  c3_info[23].dominantType = "double";
  c3_info[23].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isinteger.m";
  c3_info[23].fileLength = 254U;
  c3_info[23].fileTime1 = 1160446620U;
  c3_info[23].fileTime2 = 0U;
  c3_info[24].context = "";
  c3_info[24].name = "mtimes";
  c3_info[24].dominantType = "double";
  c3_info[24].resolved = "[B]mtimes";
  c3_info[24].fileLength = 0U;
  c3_info[24].fileTime1 = 0U;
  c3_info[24].fileTime2 = 0U;
  c3_info[25].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c3_info[25].name = "intmax";
  c3_info[25].dominantType = "char";
  c3_info[25].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c3_info[25].fileLength = 1575U;
  c3_info[25].fileTime1 = 1160446696U;
  c3_info[25].fileTime2 = 0U;
  c3_info[26].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c3_info[26].name = "eml_check_dim";
  c3_info[26].dominantType = "double";
  c3_info[26].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c3_info[26].fileLength = 1470U;
  c3_info[26].fileTime1 = 1177099718U;
  c3_info[26].fileTime2 = 0U;
  c3_info[27].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[27].name = "eml_isa_uint";
  c3_info[27].dominantType = "double";
  c3_info[27].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c3_info[27].fileLength = 288U;
  c3_info[27].fileTime1 = 1163970798U;
  c3_info[27].fileTime2 = 0U;
  c3_info[28].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[28].name = "isempty";
  c3_info[28].dominantType = "double";
  c3_info[28].resolved = "[B]isempty";
  c3_info[28].fileLength = 0U;
  c3_info[28].fileTime1 = 0U;
  c3_info[28].fileTime2 = 0U;
  c3_info[29].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c3_info[29].name = "int32";
  c3_info[29].dominantType = "double";
  c3_info[29].resolved = "[B]int32";
  c3_info[29].fileLength = 0U;
  c3_info[29].fileTime1 = 0U;
  c3_info[29].fileTime2 = 0U;
  c3_info[30].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[30].name = "isscalar";
  c3_info[30].dominantType = "double";
  c3_info[30].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isscalar.m";
  c3_info[30].fileLength = 243U;
  c3_info[30].fileTime1 = 1160446704U;
  c3_info[30].fileTime2 = 0U;
  c3_info[31].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[31].name = "eml_assert";
  c3_info[31].dominantType = "char";
  c3_info[31].resolved = "[B]eml_assert";
  c3_info[31].fileLength = 0U;
  c3_info[31].fileTime1 = 0U;
  c3_info[31].fileTime2 = 0U;
  c3_info[32].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m/sumwork";
  c3_info[32].name = "isvector";
  c3_info[32].dominantType = "double";
  c3_info[32].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isvector.m";
  c3_info[32].fileLength = 284U;
  c3_info[32].fileTime1 = 1160446706U;
  c3_info[32].fileTime2 = 0U;
  c3_info[33].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c3_info[33].name = "logical";
  c3_info[33].dominantType = "double";
  c3_info[33].resolved = "[B]logical";
  c3_info[33].fileLength = 0U;
  c3_info[33].fileTime1 = 0U;
  c3_info[33].fileTime2 = 0U;
  c3_info[34].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m/sumwork";
  c3_info[34].name = "cast";
  c3_info[34].dominantType = "double";
  c3_info[34].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c3_info[34].fileLength = 907U;
  c3_info[34].fileTime1 = 1160446618U;
  c3_info[34].fileTime2 = 0U;
  c3_info[35].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c3_info[35].name = "double";
  c3_info[35].dominantType = "double";
  c3_info[35].resolved = "[B]double";
  c3_info[35].fileLength = 0U;
  c3_info[35].fileTime1 = 0U;
  c3_info[35].fileTime2 = 0U;
  c3_info[36].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[36].name = "not";
  c3_info[36].dominantType = "logical";
  c3_info[36].resolved = "[B]not";
  c3_info[36].fileLength = 0U;
  c3_info[36].fileTime1 = 0U;
  c3_info[36].fileTime2 = 0U;
  c3_info[37].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c3_info[37].name = "nargout";
  c3_info[37].dominantType = "";
  c3_info[37].resolved = "[B]nargout";
  c3_info[37].fileLength = 0U;
  c3_info[37].fileTime1 = 0U;
  c3_info[37].fileTime2 = 0U;
  c3_info[38].context = "";
  c3_info[38].name = "mrdivide";
  c3_info[38].dominantType = "double";
  c3_info[38].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c3_info[38].fileLength = 653U;
  c3_info[38].fileTime1 = 1160446802U;
  c3_info[38].fileTime2 = 0U;
  c3_info[39].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c3_info[39].name = "lt";
  c3_info[39].dominantType = "double";
  c3_info[39].resolved = "[B]lt";
  c3_info[39].fileLength = 0U;
  c3_info[39].fileTime1 = 0U;
  c3_info[39].fileTime2 = 0U;
  c3_info[40].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c3_info[40].name = "ge";
  c3_info[40].dominantType = "double";
  c3_info[40].resolved = "[B]ge";
  c3_info[40].fileLength = 0U;
  c3_info[40].fileTime1 = 0U;
  c3_info[40].fileTime2 = 0U;
  c3_info[41].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m/eml_isequal";
  c3_info[41].name = "ndims";
  c3_info[41].dominantType = "double";
  c3_info[41].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/ndims.m";
  c3_info[41].fileLength = 236U;
  c3_info[41].fileTime1 = 1163970776U;
  c3_info[41].fileTime2 = 0U;
  c3_info[42].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[42].name = "isreal";
  c3_info[42].dominantType = "double";
  c3_info[42].resolved = "[B]isreal";
  c3_info[42].fileLength = 0U;
  c3_info[42].fileTime1 = 0U;
  c3_info[42].fileTime2 = 0U;
  c3_info[43].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c3_info[43].name = "false";
  c3_info[43].dominantType = "";
  c3_info[43].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c3_info[43].fileLength = 631U;
  c3_info[43].fileTime1 = 1163970766U;
  c3_info[43].fileTime2 = 0U;
  c3_info[44].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c3_info[44].name = "eml_is_integer_class";
  c3_info[44].dominantType = "char";
  c3_info[44].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m";
  c3_info[44].fileLength = 462U;
  c3_info[44].fileTime1 = 1160446744U;
  c3_info[44].fileTime2 = 0U;
  c3_info[45].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[45].name = "gt";
  c3_info[45].dominantType = "double";
  c3_info[45].resolved = "[B]gt";
  c3_info[45].fileLength = 0U;
  c3_info[45].fileTime1 = 0U;
  c3_info[45].fileTime2 = 0U;
  c3_info[46].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c3_info[46].name = "eq";
  c3_info[46].dominantType = "double";
  c3_info[46].resolved = "[B]eq";
  c3_info[46].fileLength = 0U;
  c3_info[46].fileTime1 = 0U;
  c3_info[46].fileTime2 = 0U;
  c3_info[47].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c3_info[47].name = "class";
  c3_info[47].dominantType = "char";
  c3_info[47].resolved = "[B]class";
  c3_info[47].fileLength = 0U;
  c3_info[47].fileTime1 = 0U;
  c3_info[47].fileTime2 = 0U;
  c3_info[48].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[48].name = "isnumeric";
  c3_info[48].dominantType = "double";
  c3_info[48].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isnumeric.m";
  c3_info[48].fileLength = 250U;
  c3_info[48].fileTime1 = 1160446622U;
  c3_info[48].fileTime2 = 0U;
  c3_info[49].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c3_info[49].name = "eml_index_class";
  c3_info[49].dominantType = "";
  c3_info[49].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[49].fileLength = 953U;
  c3_info[49].fileTime1 = 1160446742U;
  c3_info[49].fileTime2 = 0U;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c3_Maze_Omni_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3213949455U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2972633944U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3278330228U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3382447488U);
}

mxArray *sf_c3_Maze_Omni_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3712764182U);
    pr[1] = (double)(627272230U);
    pr[2] = (double)(224265117U);
    pr[3] = (double)(3379235871U);
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
        chartAlreadyPresent = sf_debug_initialize_chart(_Maze_OmniMachineNumber_,
         3,
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
          init_script_number_translation(_Maze_OmniMachineNumber_,chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_Maze_OmniMachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_Maze_OmniMachineNumber_,
           chartInstance.chartNumber,
           0,
           0,
           0);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,1.0,0,"u",0,c3_sf_marshall);
          }
          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,1.0,0,"y",0,c3_b_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,371);
        _SFD_CV_INIT_EML_IF(0,0,298,322,352,371);
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
          real_T (*c3_u)[3];
          real_T (*c3_y)[3];
          c3_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
          c3_u = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_u);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_y);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_Maze_OmniMachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c3_Maze_Omni(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c3_Maze_Omni();
  initialize_c3_Maze_Omni();
}

static void sf_opaque_enable_c3_Maze_Omni(void *chartInstanceVar)
{
  enable_c3_Maze_Omni();
}

static void sf_opaque_disable_c3_Maze_Omni(void *chartInstanceVar)
{
  disable_c3_Maze_Omni();
}

static void sf_opaque_gateway_c3_Maze_Omni(void *chartInstanceVar)
{
  sf_c3_Maze_Omni();
}

static void sf_opaque_ext_mode_exec_c3_Maze_Omni(void *chartInstanceVar)
{
  ext_mode_exec_c3_Maze_Omni();
}

static void sf_opaque_terminate_c3_Maze_Omni(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) ||
   sim_mode_is_external(chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }
  finalize_c3_Maze_Omni();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_Maze_Omni(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  if(sf_machine_global_initializer_called()) {
    initialize_params_c3_Maze_Omni();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr =
  "100 S1x2'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}";
  sf_set_encoded_dwork_info(S, dworkEncStr);
}

static void mdlSetWorkWidths_c3_Maze_Omni(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("Maze_Omni",3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("Maze_Omni",3,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"Maze_Omni",3,1);
      sf_mark_chart_reusable_outputs(S,"Maze_Omni",3,1);
    }
    sf_set_rtw_dwork_info(S,"Maze_Omni",3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(851498068U));
  ssSetChecksum1(S,(394555368U));
  ssSetChecksum2(S,(2583960205U));
  ssSetChecksum3(S,(2467641011U));

  ssSetmdlDerivatives(S, NULL);

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_Maze_Omni(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Maze_Omni", 3);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_Maze_Omni(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway = sf_opaque_gateway_c3_Maze_Omni;
  chartInstance.chartInfo.initializeChart = sf_opaque_initialize_c3_Maze_Omni;
  chartInstance.chartInfo.terminateChart = sf_opaque_terminate_c3_Maze_Omni;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c3_Maze_Omni;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c3_Maze_Omni;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c3_Maze_Omni;
  chartInstance.chartInfo.mdlStart = mdlStart_c3_Maze_Omni;
  chartInstance.chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_Maze_Omni;
  chartInstance.chartInfo.extModeExec = sf_opaque_ext_mode_exec_c3_Maze_Omni;
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

void c3_Maze_Omni_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_Maze_Omni(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_Maze_Omni(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_Maze_Omni(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c3_Maze_Omni_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

