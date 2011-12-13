/* Include files */
#include "Gravity_Well_sfun.h"
#include "c7_Gravity_Well.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "Gravity_Well_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c7_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc7_Gravity_WellInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c7_Gravity_Well(void);
static void initialize_params_c7_Gravity_Well(void);
static void enable_c7_Gravity_Well(void);
static void disable_c7_Gravity_Well(void);
static void ext_mode_exec_c7_Gravity_Well(void);
static void finalize_c7_Gravity_Well(void);
static void sf_c7_Gravity_Well(void);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
 c7_chartNumber);
static real_T c7_mpower(real_T c7_a);
static const mxArray *c7_sf_marshall(void *c7_chartInstance, void *c7_u);
static const mxArray *c7_b_sf_marshall(void *c7_chartInstance, void *c7_u);
static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[44]);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c7_Gravity_Well(void)
{
  uint8_T *c7_is_active_c7_Gravity_Well;
  c7_is_active_c7_Gravity_Well = (uint8_T *)ssGetDWork(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c7_is_active_c7_Gravity_Well = 0U;
}

static void initialize_params_c7_Gravity_Well(void)
{
}

static void enable_c7_Gravity_Well(void)
{
}

static void disable_c7_Gravity_Well(void)
{
}

static void ext_mode_exec_c7_Gravity_Well(void)
{
}

static void finalize_c7_Gravity_Well(void)
{
}

static void sf_c7_Gravity_Well(void)
{
  int32_T c7_i0;
  uint8_T c7_previousEvent;
  int32_T c7_i1;
  real_T c7_diff[3];
  real_T c7_mag;
  real_T c7_x;
  int32_T c7_i2;
  static char c7_cv0[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't', ':', 'd',
    'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };
  char c7_x1[31];
  int32_T c7_i3;
  static char c7_cv1[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm', 'p',
    'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e', 's',
    'u', 'l', 't', 's', ' ', 'f',
    'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u', 's', 'e',
    ' ', '\'', 's', 'q', 'r', 't'
    , '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')', '\'', '.' };
  char c7_x2[77];
  int32_T c7_i4;
  char c7_u[31];
  const mxArray *c7_y = NULL;
  int32_T c7_i5;
  char c7_b_u[77];
  const mxArray *c7_b_y = NULL;
  real_T *c7_b_mag;
  real_T (*c7_b_diff)[3];
  c7_b_diff = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  c7_b_mag = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  for(c7_i0 = 0; c7_i0 < 3; c7_i0 = c7_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((*c7_b_diff)[c7_i0], 1U);
  }
  _SFD_DATA_RANGE_CHECK(*c7_b_mag, 0U);
  c7_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,4);
  for(c7_i1 = 0; c7_i1 < 3; c7_i1 = c7_i1 + 1) {
    c7_diff[c7_i1] = (*c7_b_diff)[c7_i1];
  }
  sf_debug_symbol_scope_push(2U, 0U);
  sf_debug_symbol_scope_add("mag", &c7_mag, c7_b_sf_marshall);
  sf_debug_symbol_scope_add("diff", &c7_diff, c7_sf_marshall);
  CV_EML_FCN(0, 0);
  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,5);
  c7_x = (c7_mpower(c7_diff[0]) + c7_mpower(c7_diff[1])) + c7_mpower(c7_diff[2]);
  c7_mag = c7_x;
  if(c7_mag < 0.0) {
    for(c7_i2 = 0; c7_i2 < 31; c7_i2 = c7_i2 + 1) {
      c7_x1[c7_i2] = c7_cv0[c7_i2];
    }
    for(c7_i3 = 0; c7_i3 < 77; c7_i3 = c7_i3 + 1) {
      c7_x2[c7_i3] = c7_cv1[c7_i3];
    }
    for(c7_i4 = 0; c7_i4 < 31; c7_i4 = c7_i4 + 1) {
      c7_u[c7_i4] = c7_x1[c7_i4];
    }
    c7_y = NULL;
    sf_mex_assign(&c7_y, sf_mex_create(&c7_u, "y", 8, 0U, 1U, 2, 1, 31));
    for(c7_i5 = 0; c7_i5 < 77; c7_i5 = c7_i5 + 1) {
      c7_b_u[c7_i5] = c7_x2[c7_i5];
    }
    c7_b_y = NULL;
    sf_mex_assign(&c7_b_y, sf_mex_create(&c7_b_u, "y", 8, 0U, 1U, 2, 1, 77));
    sf_mex_call("error", 0U, 2U, 14, c7_y, 14, c7_b_y);
  }
  c7_mag = sqrt(c7_mag);
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-5);
  sf_debug_symbol_scope_pop();
  *c7_b_mag = c7_mag;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,4);
  _sfEvent_ = c7_previousEvent;
  sf_debug_check_for_state_inconsistency(_Gravity_WellMachineNumber_,
   chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
 c7_chartNumber)
{
}

static real_T c7_mpower(real_T c7_a)
{
  real_T c7_b_a;
  real_T c7_b;
  real_T c7_ak;
  real_T c7_bk;
  real_T c7_x;
  real_T c7_b_x;
  int32_T c7_i6;
  static char c7_cv2[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e', 'r', ':',
    'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };
  char c7_x1[32];
  int32_T c7_i7;
  static char c7_cv3[102] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm', 'p'
    , 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e', 's',
    'u', 'l', 't', 's', ',',
    ' ', 'm', 'a', 'k', 'e', ' ', 'a', 't', ' ', 'l', 'e', 'a', 's', 't', ' ',
    'o', 'n', 'e', ' ', 'i', 'n'
    , 'p', 'u', 't', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ',', ' ', 'e', '.',
    'g', '.', ' ', '\'', 'p',
    'o', 'w', 'e', 'r', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'a', ')',
    ',', 'b', ')', '\'', '.' };
  char c7_x2[102];
  int32_T c7_i8;
  char c7_u[32];
  const mxArray *c7_y = NULL;
  int32_T c7_i9;
  char c7_b_u[102];
  const mxArray *c7_b_y = NULL;
  c7_b_a = c7_a;
  c7_b = 2.0;
  c7_ak = c7_b_a;
  c7_bk = c7_b;
  if(c7_ak < 0.0) {
    c7_x = c7_bk;
    c7_b_x = c7_x;
    c7_b_x = floor(c7_b_x);
    if(c7_b_x != c7_bk) {
      for(c7_i6 = 0; c7_i6 < 32; c7_i6 = c7_i6 + 1) {
        c7_x1[c7_i6] = c7_cv2[c7_i6];
      }
      for(c7_i7 = 0; c7_i7 < 102; c7_i7 = c7_i7 + 1) {
        c7_x2[c7_i7] = c7_cv3[c7_i7];
      }
      for(c7_i8 = 0; c7_i8 < 32; c7_i8 = c7_i8 + 1) {
        c7_u[c7_i8] = c7_x1[c7_i8];
      }
      c7_y = NULL;
      sf_mex_assign(&c7_y, sf_mex_create(&c7_u, "y", 8, 0U, 1U, 2, 1, 32));
      for(c7_i9 = 0; c7_i9 < 102; c7_i9 = c7_i9 + 1) {
        c7_b_u[c7_i9] = c7_x2[c7_i9];
      }
      c7_b_y = NULL;
      sf_mex_assign(&c7_b_y, sf_mex_create(&c7_b_u, "y", 8, 0U, 1U, 2, 1, 102));
      sf_mex_call("error", 0U, 2U, 14, c7_y, 14, c7_b_y);
    }
  }
  return pow(c7_ak, c7_bk);
}

static const mxArray *c7_sf_marshall(void *c7_chartInstance, void *c7_u)
{
  const mxArray *c7_y = NULL;
  int32_T c7_i10;
  real_T c7_b_u[3];
  const mxArray *c7_b_y = NULL;
  c7_y = NULL;
  for(c7_i10 = 0; c7_i10 < 3; c7_i10 = c7_i10 + 1) {
    c7_b_u[c7_i10] = (*((real_T (*)[3])c7_u))[c7_i10];
  }
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create(&c7_b_u, "y", 0, 0U, 1U, 1, 3));
  sf_mex_assign(&c7_y, c7_b_y);
  return c7_y;
}

static const mxArray *c7_b_sf_marshall(void *c7_chartInstance, void *c7_u)
{
  const mxArray *c7_y = NULL;
  real_T c7_b_u;
  const mxArray *c7_b_y = NULL;
  c7_y = NULL;
  c7_b_u = *((real_T *)c7_u);
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create(&c7_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c7_y, c7_b_y);
  return c7_y;
}

const mxArray *sf_c7_Gravity_Well_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo = NULL;
  c7_ResolvedFunctionInfo c7_info[44];
  const mxArray *c7_m0 = NULL;
  int32_T c7_i11;
  c7_ResolvedFunctionInfo *c7_r0;
  c7_nameCaptureInfo = NULL;
  c7_info_helper(c7_info);
  sf_mex_assign(&c7_m0, sf_mex_createstruct("nameCaptureInfo", 1, 44));
  for(c7_i11 = 0; c7_i11 < 44; c7_i11 = c7_i11 + 1) {
    c7_r0 = &c7_info[c7_i11];
    sf_mex_addfield(c7_m0, sf_mex_create(c7_r0->context, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c7_r0->context)), "context",
     "nameCaptureInfo", c7_i11);
    sf_mex_addfield(c7_m0, sf_mex_create(c7_r0->name, "nameCaptureInfo", 13, 0U,
      0U, 2, 1, strlen(c7_r0->name)), "name",
     "nameCaptureInfo", c7_i11);
    sf_mex_addfield(c7_m0, sf_mex_create(c7_r0->dominantType, "nameCaptureInfo",
      13, 0U, 0U, 2, 1, strlen(c7_r0->dominantType)),
     "dominantType", "nameCaptureInfo", c7_i11);
    sf_mex_addfield(c7_m0, sf_mex_create(c7_r0->resolved, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c7_r0->resolved)), "resolved",
     "nameCaptureInfo", c7_i11);
    sf_mex_addfield(c7_m0, sf_mex_create(&c7_r0->fileLength, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileLength", "nameCaptureInfo", c7_i11);
    sf_mex_addfield(c7_m0, sf_mex_create(&c7_r0->fileTime1, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c7_i11);
    sf_mex_addfield(c7_m0, sf_mex_create(&c7_r0->fileTime2, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c7_i11);
  }
  sf_mex_assign(&c7_nameCaptureInfo, c7_m0);
  return c7_nameCaptureInfo;
}

static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[44])
{
  c7_info[0].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_numel.m";
  c7_info[0].name = "numel";
  c7_info[0].dominantType = "double";
  c7_info[0].resolved = "[B]numel";
  c7_info[0].fileLength = 0U;
  c7_info[0].fileTime1 = 0U;
  c7_info[0].fileTime2 = 0U;
  c7_info[1].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/check_arg";
  c7_info[1].name = "false";
  c7_info[1].dominantType = "";
  c7_info[1].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c7_info[1].fileLength = 631U;
  c7_info[1].fileTime1 = 1163970766U;
  c7_info[1].fileTime2 = 0U;
  c7_info[2].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c7_info[2].name = "isscalar";
  c7_info[2].dominantType = "double";
  c7_info[2].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isscalar.m";
  c7_info[2].fileLength = 243U;
  c7_info[2].fileTime1 = 1160446704U;
  c7_info[2].fileTime2 = 0U;
  c7_info[3].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c7_info[3].name = "ge";
  c7_info[3].dominantType = "double";
  c7_info[3].resolved = "[B]ge";
  c7_info[3].fileLength = 0U;
  c7_info[3].fileTime1 = 0U;
  c7_info[3].fileTime2 = 0U;
  c7_info[4].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c7_info[4].name = "isnumeric";
  c7_info[4].dominantType = "double";
  c7_info[4].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isnumeric.m";
  c7_info[4].fileLength = 250U;
  c7_info[4].fileTime1 = 1160446622U;
  c7_info[4].fileTime2 = 0U;
  c7_info[5].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c7_info[5].name = "floor";
  c7_info[5].dominantType = "double";
  c7_info[5].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c7_info[5].fileLength = 595U;
  c7_info[5].fileTime1 = 1163970736U;
  c7_info[5].fileTime2 = 0U;
  c7_info[6].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c7_info[6].name = "cast";
  c7_info[6].dominantType = "double";
  c7_info[6].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c7_info[6].fileLength = 907U;
  c7_info[6].fileTime1 = 1160446618U;
  c7_info[6].fileTime2 = 0U;
  c7_info[7].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c7_info[7].name = "logical";
  c7_info[7].dominantType = "double";
  c7_info[7].resolved = "[B]logical";
  c7_info[7].fileLength = 0U;
  c7_info[7].fileTime1 = 0U;
  c7_info[7].fileTime2 = 0U;
  c7_info[8].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c7_info[8].name = "power";
  c7_info[8].dominantType = "double";
  c7_info[8].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c7_info[8].fileLength = 4842U;
  c7_info[8].fileTime1 = 1177099746U;
  c7_info[8].fileTime2 = 0U;
  c7_info[9].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c7_info[9].name = "plus";
  c7_info[9].dominantType = "double";
  c7_info[9].resolved = "[B]plus";
  c7_info[9].fileLength = 0U;
  c7_info[9].fileTime1 = 0U;
  c7_info[9].fileTime2 = 0U;
  c7_info[10].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c7_info[10].name = "eml_scalexp_size";
  c7_info[10].dominantType = "double";
  c7_info[10].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c7_info[10].fileLength = 923U;
  c7_info[10].fileTime1 = 1160446756U;
  c7_info[10].fileTime2 = 0U;
  c7_info[11].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c7_info[11].name = "isstruct";
  c7_info[11].dominantType = "double";
  c7_info[11].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isstruct.m";
  c7_info[11].fileLength = 179U;
  c7_info[11].fileTime1 = 1160446624U;
  c7_info[11].fileTime2 = 0U;
  c7_info[12].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/check_arg";
  c7_info[12].name = "ne";
  c7_info[12].dominantType = "double";
  c7_info[12].resolved = "[B]ne";
  c7_info[12].fileLength = 0U;
  c7_info[12].fileTime1 = 0U;
  c7_info[12].fileTime2 = 0U;
  c7_info[13].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c7_info[13].name = "eml_alloc";
  c7_info[13].dominantType = "double";
  c7_info[13].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c7_info[13].fileLength = 2151U;
  c7_info[13].fileTime1 = 1179464470U;
  c7_info[13].fileTime2 = 0U;
  c7_info[14].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c7_info[14].name = "eml_numel";
  c7_info[14].dominantType = "double";
  c7_info[14].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_numel.m";
  c7_info[14].fileLength = 278U;
  c7_info[14].fileTime1 = 1163970802U;
  c7_info[14].fileTime2 = 0U;
  c7_info[15].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c7_info[15].name = "size";
  c7_info[15].dominantType = "double";
  c7_info[15].resolved = "[B]size";
  c7_info[15].fileLength = 0U;
  c7_info[15].fileTime1 = 0U;
  c7_info[15].fileTime2 = 0U;
  c7_info[16].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c7_info[16].name = "eml_error";
  c7_info[16].dominantType = "char";
  c7_info[16].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c7_info[16].fileLength = 585U;
  c7_info[16].fileTime1 = 1177099720U;
  c7_info[16].fileTime2 = 0U;
  c7_info[17].context = "";
  c7_info[17].name = "sqrt";
  c7_info[17].dominantType = "double";
  c7_info[17].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c7_info[17].fileLength = 1276U;
  c7_info[17].fileTime1 = 1177099708U;
  c7_info[17].fileTime2 = 0U;
  c7_info[18].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isscalar.m";
  c7_info[18].name = "length";
  c7_info[18].dominantType = "double";
  c7_info[18].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c7_info[18].fileLength = 347U;
  c7_info[18].fileTime1 = 1163970770U;
  c7_info[18].fileTime2 = 0U;
  c7_info[19].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c7_info[19].name = "eq";
  c7_info[19].dominantType = "double";
  c7_info[19].resolved = "[B]eq";
  c7_info[19].fileLength = 0U;
  c7_info[19].fileTime1 = 0U;
  c7_info[19].fileTime2 = 0U;
  c7_info[20].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/check_arg";
  c7_info[20].name = "imag";
  c7_info[20].dominantType = "double";
  c7_info[20].resolved = "[B]imag";
  c7_info[20].fileLength = 0U;
  c7_info[20].fileTime1 = 0U;
  c7_info[20].fileTime2 = 0U;
  c7_info[21].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/check_arg";
  c7_info[21].name = "true";
  c7_info[21].dominantType = "";
  c7_info[21].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c7_info[21].fileLength = 625U;
  c7_info[21].fileTime1 = 1163970786U;
  c7_info[21].fileTime2 = 0U;
  c7_info[22].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c7_info[22].name = "zeros";
  c7_info[22].dominantType = "double";
  c7_info[22].resolved = "[B]zeros";
  c7_info[22].fileLength = 0U;
  c7_info[22].fileTime1 = 0U;
  c7_info[22].fileTime2 = 0U;
  c7_info[23].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c7_info[23].name = "isreal";
  c7_info[23].dominantType = "double";
  c7_info[23].resolved = "[B]isreal";
  c7_info[23].fileLength = 0U;
  c7_info[23].fileTime1 = 0U;
  c7_info[23].fileTime2 = 0U;
  c7_info[24].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/check_arg";
  c7_info[24].name = "isvector";
  c7_info[24].dominantType = "double";
  c7_info[24].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isvector.m";
  c7_info[24].fileLength = 284U;
  c7_info[24].fileTime1 = 1160446706U;
  c7_info[24].fileTime2 = 0U;
  c7_info[25].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c7_info[25].name = "eml_assert_valid_size_arg";
  c7_info[25].dominantType = "double";
  c7_info[25].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c7_info[25].fileLength = 1097U;
  c7_info[25].fileTime1 = 1163970788U;
  c7_info[25].fileTime2 = 0U;
  c7_info[26].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c7_info[26].name = "class";
  c7_info[26].dominantType = "char";
  c7_info[26].resolved = "[B]class";
  c7_info[26].fileLength = 0U;
  c7_info[26].fileTime1 = 0U;
  c7_info[26].fileTime2 = 0U;
  c7_info[27].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c7_info[27].name = "eml_is_integer_class";
  c7_info[27].dominantType = "char";
  c7_info[27].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m";
  c7_info[27].fileLength = 462U;
  c7_info[27].fileTime1 = 1160446744U;
  c7_info[27].fileTime2 = 0U;
  c7_info[28].context = "";
  c7_info[28].name = "mpower";
  c7_info[28].dominantType = "double";
  c7_info[28].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c7_info[28].fileLength = 3116U;
  c7_info[28].fileTime1 = 1177099746U;
  c7_info[28].fileTime2 = 0U;
  c7_info[29].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c7_info[29].name = "eml_scalexp_compatible";
  c7_info[29].dominantType = "double";
  c7_info[29].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c7_info[29].fileLength = 422U;
  c7_info[29].fileTime1 = 1160446754U;
  c7_info[29].fileTime2 = 0U;
  c7_info[30].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c7_info[30].name = "ischar";
  c7_info[30].dominantType = "char";
  c7_info[30].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/strfun/ischar.m";
  c7_info[30].fileLength = 244U;
  c7_info[30].fileTime1 = 1160446834U;
  c7_info[30].fileTime2 = 0U;
  c7_info[31].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c7_info[31].name = "double";
  c7_info[31].dominantType = "double";
  c7_info[31].resolved = "[B]double";
  c7_info[31].fileLength = 0U;
  c7_info[31].fileTime1 = 0U;
  c7_info[31].fileTime2 = 0U;
  c7_info[32].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c7_info[32].name = "eml_assert";
  c7_info[32].dominantType = "char";
  c7_info[32].resolved = "[B]eml_assert";
  c7_info[32].fileLength = 0U;
  c7_info[32].fileTime1 = 0U;
  c7_info[32].fileTime2 = 0U;
  c7_info[33].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c7_info[33].name = "lt";
  c7_info[33].dominantType = "double";
  c7_info[33].resolved = "[B]lt";
  c7_info[33].fileLength = 0U;
  c7_info[33].fileTime1 = 0U;
  c7_info[33].fileTime2 = 0U;
  c7_info[34].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c7_info[34].name = "eml_is_float_class";
  c7_info[34].dominantType = "char";
  c7_info[34].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c7_info[34].fileLength = 273U;
  c7_info[34].fileTime1 = 1160446744U;
  c7_info[34].fileTime2 = 0U;
  c7_info[35].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c7_info[35].name = "strcmp";
  c7_info[35].dominantType = "char";
  c7_info[35].resolved = "[B]strcmp";
  c7_info[35].fileLength = 0U;
  c7_info[35].fileTime1 = 0U;
  c7_info[35].fileTime2 = 0U;
  c7_info[36].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c7_info[36].name = "ndims";
  c7_info[36].dominantType = "double";
  c7_info[36].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/ndims.m";
  c7_info[36].fileLength = 236U;
  c7_info[36].fileTime1 = 1163970776U;
  c7_info[36].fileTime2 = 0U;
  c7_info[37].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c7_info[37].name = "isinteger";
  c7_info[37].dominantType = "double";
  c7_info[37].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isinteger.m";
  c7_info[37].fileLength = 254U;
  c7_info[37].fileTime1 = 1160446620U;
  c7_info[37].fileTime2 = 0U;
  c7_info[38].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isnumeric.m";
  c7_info[38].name = "isa";
  c7_info[38].dominantType = "double";
  c7_info[38].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c7_info[38].fileLength = 791U;
  c7_info[38].fileTime1 = 1160446618U;
  c7_info[38].fileTime2 = 0U;
  c7_info[39].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c7_info[39].name = "nargin";
  c7_info[39].dominantType = "";
  c7_info[39].resolved = "[B]nargin";
  c7_info[39].fileLength = 0U;
  c7_info[39].fileTime1 = 0U;
  c7_info[39].fileTime2 = 0U;
  c7_info[40].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c7_info[40].name = "isempty";
  c7_info[40].dominantType = "double";
  c7_info[40].resolved = "[B]isempty";
  c7_info[40].fileLength = 0U;
  c7_info[40].fileTime1 = 0U;
  c7_info[40].fileTime2 = 0U;
  c7_info[41].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/check_arg";
  c7_info[41].name = "real";
  c7_info[41].dominantType = "double";
  c7_info[41].resolved = "[B]real";
  c7_info[41].fileLength = 0U;
  c7_info[41].fileTime1 = 0U;
  c7_info[41].fileTime2 = 0U;
  c7_info[42].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/check_arg";
  c7_info[42].name = "isfloat";
  c7_info[42].dominantType = "double";
  c7_info[42].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isfloat.m";
  c7_info[42].fileLength = 182U;
  c7_info[42].fileTime1 = 1160446620U;
  c7_info[42].fileTime2 = 0U;
  c7_info[43].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c7_info[43].name = "gt";
  c7_info[43].dominantType = "double";
  c7_info[43].resolved = "[B]gt";
  c7_info[43].fileLength = 0U;
  c7_info[43].fileTime1 = 0U;
  c7_info[43].fileTime2 = 0U;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c7_Gravity_Well_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(806306749U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1107469597U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(420498669U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1186853967U);
}

mxArray *sf_c7_Gravity_Well_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1046794762U);
    pr[1] = (double)(3064820153U);
    pr[2] = (double)(2559731207U);
    pr[3] = (double)(2342963824U);
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
          sf_debug_initialize_chart(_Gravity_WellMachineNumber_,
         7,
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
          init_script_number_translation(_Gravity_WellMachineNumber_,chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_Gravity_WellMachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_Gravity_WellMachineNumber_,
           chartInstance.chartNumber,
           0,
           0,
           0);

          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,1.0,0,"diff",0,c7_sf_marshall);
          }
          _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"mag",0,c7_b_sf_marshall);
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,152);
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
          real_T (*c7_diff)[3];
          real_T *c7_mag;
          c7_diff = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
          c7_mag = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(1U, c7_diff);
          _SFD_SET_DATA_VALUE_PTR(0U, c7_mag);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_Gravity_WellMachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c7_Gravity_Well(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c7_Gravity_Well();
  initialize_c7_Gravity_Well();
}

static void sf_opaque_enable_c7_Gravity_Well(void *chartInstanceVar)
{
  enable_c7_Gravity_Well();
}

static void sf_opaque_disable_c7_Gravity_Well(void *chartInstanceVar)
{
  disable_c7_Gravity_Well();
}

static void sf_opaque_gateway_c7_Gravity_Well(void *chartInstanceVar)
{
  sf_c7_Gravity_Well();
}

static void sf_opaque_ext_mode_exec_c7_Gravity_Well(void *chartInstanceVar)
{
  ext_mode_exec_c7_Gravity_Well();
}

static void sf_opaque_terminate_c7_Gravity_Well(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) ||
   sim_mode_is_external(chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }
  finalize_c7_Gravity_Well();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_Gravity_Well(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  if(sf_machine_global_initializer_called()) {
    initialize_params_c7_Gravity_Well();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr =
  "100 S1x2'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}";
  sf_set_encoded_dwork_info(S, dworkEncStr);
}

static void mdlSetWorkWidths_c7_Gravity_Well(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("Gravity_Well",7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("Gravity_Well",7,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"Gravity_Well",7,1);
      sf_mark_chart_reusable_outputs(S,"Gravity_Well",7,1);
    }
    sf_set_rtw_dwork_info(S,"Gravity_Well",7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(1171580190U));
  ssSetChecksum1(S,(3064717448U));
  ssSetChecksum2(S,(3627269406U));
  ssSetChecksum3(S,(3471808091U));

  ssSetmdlDerivatives(S, NULL);

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c7_Gravity_Well(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Gravity_Well", 7);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_Gravity_Well(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway = sf_opaque_gateway_c7_Gravity_Well;
  chartInstance.chartInfo.initializeChart = sf_opaque_initialize_c7_Gravity_Well;
  chartInstance.chartInfo.terminateChart = sf_opaque_terminate_c7_Gravity_Well;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c7_Gravity_Well;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c7_Gravity_Well;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c7_Gravity_Well;
  chartInstance.chartInfo.mdlStart = mdlStart_c7_Gravity_Well;
  chartInstance.chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c7_Gravity_Well;
  chartInstance.chartInfo.extModeExec = sf_opaque_ext_mode_exec_c7_Gravity_Well;
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

void c7_Gravity_Well_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_Gravity_Well(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_Gravity_Well(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_Gravity_Well(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c7_Gravity_Well_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

