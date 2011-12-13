/* Include files */
#include "Puncture_Through_Wall_Falcon_sfun.h"
#include "c2_Puncture_Through_Wall_Falcon.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "Puncture_Through_Wall_Falcon_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc2_Puncture_Through_Wall_FalconInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c2_Puncture_Through_Wall_Falcon(void);
static void initialize_params_c2_Puncture_Through_Wall_Falcon(void);
static void enable_c2_Puncture_Through_Wall_Falcon(void);
static void disable_c2_Puncture_Through_Wall_Falcon(void);
static void ext_mode_exec_c2_Puncture_Through_Wall_Falcon(void);
static void finalize_c2_Puncture_Through_Wall_Falcon(void);
static void sf_c2_Puncture_Through_Wall_Falcon(void);
static void c2_c2_Puncture_Through_Wall_Falcon(void);
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
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[38]);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c2_Puncture_Through_Wall_Falcon(void)
{
  uint8_T *c2_is_active_c2_Puncture_Through_Wall_Falcon;
  c2_is_active_c2_Puncture_Through_Wall_Falcon = (uint8_T
    *)ssGetDWork(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c2_is_active_c2_Puncture_Through_Wall_Falcon = 0U;
}

static void initialize_params_c2_Puncture_Through_Wall_Falcon(void)
{
}

static void enable_c2_Puncture_Through_Wall_Falcon(void)
{
}

static void disable_c2_Puncture_Through_Wall_Falcon(void)
{
}

static void ext_mode_exec_c2_Puncture_Through_Wall_Falcon(void)
{
}

static void finalize_c2_Puncture_Through_Wall_Falcon(void)
{
}

static void sf_c2_Puncture_Through_Wall_Falcon(void)
{
  int32_T c2_i0;
  int32_T c2_i1;
  int32_T c2_i2;
  uint8_T c2_previousEvent;
  real_T *c2_dir;
  real_T *c2_stiffness;
  real_T *c2_Fbreak;
  real_T *c2_dir_prev;
  real_T *c2_prev_flag;
  real_T *c2_flag;
  real_T (*c2_Force_prev)[3];
  real_T (*c2_Force)[3];
  real_T (*c2_x)[3];
  c2_x = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
  c2_Force_prev = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  c2_prev_flag = (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
  c2_flag = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c2_Fbreak = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
  c2_dir_prev = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
  c2_Force = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c2_dir = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c2_stiffness = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  for(c2_i0 = 0; c2_i0 < 3; c2_i0 = c2_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_Force_prev)[c2_i0], 8U);
  }
  for(c2_i1 = 0; c2_i1 < 3; c2_i1 = c2_i1 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_Force)[c2_i1], 4U);
  }
  for(c2_i2 = 0; c2_i2 < 3; c2_i2 = c2_i2 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_x)[c2_i2], 1U);
  }
  _SFD_DATA_RANGE_CHECK(*c2_dir, 7U);
  _SFD_DATA_RANGE_CHECK(*c2_stiffness, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_Fbreak, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_dir_prev, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_prev_flag, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_flag, 2U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c2_c2_Puncture_Through_Wall_Falcon();
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_Puncture_Through_Wall_FalconMachineNumber_,
   chartInstance.chartNumber, chartInstance.
   instanceNumber);
}

static void c2_c2_Puncture_Through_Wall_Falcon(void)
{
  int32_T c2_i3;
  real_T c2_Force_prev[3];
  int32_T c2_i4;
  real_T c2_x[3];
  real_T c2_stiffness;
  real_T c2_Fbreak;
  real_T c2_dir_prev;
  real_T c2_prev_flag;
  real_T c2_touching;
  real_T c2_av;
  real_T c2_x2wall;
  real_T c2_x1wall;
  real_T c2_flag;
  real_T c2_dir;
  real_T c2_Force[3];
  int32_T c2_i5;
  real_T c2_d0;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_xk;
  real_T c2_d_x;
  boolean_T c2_b;
  real_T c2_e_x;
  real_T c2_b_y;
  real_T c2_b_dir;
  real_T c2_dv0[3];
  int32_T c2_i6;
  real_T c2_f_x;
  real_T c2_c_y;
  real_T c2_c_dir;
  real_T c2_dv1[3];
  int32_T c2_i7;
  real_T c2_g_x;
  real_T c2_d_y;
  int32_T c2_i8;
  real_T *c2_b_stiffness;
  real_T *c2_b_Fbreak;
  real_T *c2_b_dir_prev;
  real_T *c2_b_prev_flag;
  real_T *c2_d_dir;
  real_T *c2_b_flag;
  real_T (*c2_b_Force)[3];
  real_T (*c2_b_Force_prev)[3];
  real_T (*c2_h_x)[3];
  c2_h_x = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
  c2_b_Force_prev = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  c2_b_prev_flag = (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
  c2_b_flag = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c2_b_Fbreak = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
  c2_b_dir_prev = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
  c2_b_Force = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c2_d_dir = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c2_b_stiffness = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,1);
  for(c2_i3 = 0; c2_i3 < 3; c2_i3 = c2_i3 + 1) {
    c2_Force_prev[c2_i3] = (*c2_b_Force_prev)[c2_i3];
  }
  for(c2_i4 = 0; c2_i4 < 3; c2_i4 = c2_i4 + 1) {
    c2_x[c2_i4] = (*c2_h_x)[c2_i4];
  }
  c2_stiffness = *c2_b_stiffness;
  c2_Fbreak = *c2_b_Fbreak;
  c2_dir_prev = *c2_b_dir_prev;
  c2_prev_flag = *c2_b_prev_flag;
  sf_debug_symbol_scope_push(13U, 0U);
  sf_debug_symbol_scope_add("touching", &c2_touching, c2_m_sf_marshall);
  sf_debug_symbol_scope_add("av", &c2_av, c2_l_sf_marshall);
  sf_debug_symbol_scope_add("x2wall", &c2_x2wall, c2_k_sf_marshall);
  sf_debug_symbol_scope_add("x1wall", &c2_x1wall, c2_j_sf_marshall);
  sf_debug_symbol_scope_add("flag", &c2_flag, c2_i_sf_marshall);
  sf_debug_symbol_scope_add("dir", &c2_dir, c2_h_sf_marshall);
  sf_debug_symbol_scope_add("Force", &c2_Force, c2_g_sf_marshall);
  sf_debug_symbol_scope_add("prev_flag", &c2_prev_flag, c2_f_sf_marshall);
  sf_debug_symbol_scope_add("dir_prev", &c2_dir_prev, c2_e_sf_marshall);
  sf_debug_symbol_scope_add("Fbreak", &c2_Fbreak, c2_d_sf_marshall);
  sf_debug_symbol_scope_add("stiffness", &c2_stiffness, c2_c_sf_marshall);
  sf_debug_symbol_scope_add("x", &c2_x, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("Force_prev", &c2_Force_prev, c2_sf_marshall);
  CV_EML_FCN(0, 0);
  /* DESCRIPTION--------------------------------------------------------------- */
  /* Determine the force. The magnitude of the force is penetration into the wall */
  /* The direction of force depends on the which of the wall the avatar is on.  */
  /* The wall is implemented in the x-z */
  /* INPUTS-------------------------------------------------------------------- */
  /* Force_prev - force in the previous sample time */
  /* x - position of the avatar */
  /* stiffness - stiffness of wall */
  /* Fbreak - force required to break the wall */
  /* dir_prev - the side of the wall where the avatar was in the previous sample time */
  /* dir_flag - the value of flag in the previous sample time. flag is 1 when  */
  /* the wall is broken, flag is 0 when the wall is solid. */
  /* OUTPUTS------------------------------------------------------------------- */
  /* Force - magnitude and direction of force to be applied */
  /* dir - the side of the wall where the avatar is. If the avatar is strictly */
  /* on the left dir = -1, if avatar is strictly on the right, dir = 1, else the */
  /* avatar is touching or penetrating the wall and keep the previous direction */
  /*  flag - flag is 1 when the wall is broken , flag is 0 when wall is solid */
  /* The y coordinate of the left side of the wall */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,24);
  c2_x1wall = -0.01;
  /* The y coordinate of teh right side of the wall */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,26);
  c2_x2wall = 0.01;
  /* The y coordinate of the avatar */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,29);
  c2_av = c2_x[1];
  /* declare variables */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,32);
  c2_dir = c2_dir_prev;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,33);
  c2_touching = 0.0;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,34);
  for(c2_i5 = 0; c2_i5 < 3; c2_i5 = c2_i5 + 1) {
    c2_Force[c2_i5] = 0.0;
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,35);
  c2_d0 = c2_prev_flag;
  c2_flag = c2_d0;
  sf_mex_printf("%s =\\n", "flag");
  c2_u = c2_d0;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create(&c2_u, "y", 0, 0U, 0U, 0));
  sf_mex_call("disp", 0U, 1U, 14, c2_y);
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,39);
  if(CV_EML_COND(0, 0, c2_av >= c2_x1wall)) {
    if(CV_EML_COND(0, 1, c2_av <= c2_x2wall)) {
      goto label_1;
    }
  }
  c2_b_x = c2_Force_prev[1];
  c2_c_x = c2_b_x;
  c2_xk = c2_c_x;
  c2_d_x = c2_xk;
  c2_b = rtIsNaN(c2_d_x);
  if(c2_b) {
    c2_c_x = rtNaN;
  } else if(c2_xk > 0.0) {
    c2_c_x = 1.0;
  } else if(c2_xk < 0.0) {
    c2_c_x = -1.0;
  }
  if(CV_EML_COND(0, 2, c2_c_x == c2_dir)) {
  } else {
    CV_EML_MCDC(0, 0, false);
    CV_EML_IF(0, 0, false);
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,42);
    c2_touching = 0.0;
    goto label_2;
  }
  label_1:;
  CV_EML_MCDC(0, 0, true);
  CV_EML_IF(0, 0, true);
  /* If inside the wall or pushing agains the wall, touching = 1, else 0. touching */
  /* indicates when the wall is being touched. */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,40);
  c2_touching = 1.0;
  label_2:;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,47);
  if(CV_EML_IF(0, 1, c2_prev_flag == 1.0)) {
    /* if the wall is broken, keep its state as broken, until the avatar is completly */
    /* on one side of teh wall and not inside it. */
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,48);
    c2_flag = 1.0;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,49);
    if(CV_EML_COND(0, 3, c2_av < c2_x1wall)) {
    } else if(CV_EML_COND(0, 4, c2_av > c2_x2wall)) {
    } else {
      CV_EML_MCDC(0, 1, false);
      CV_EML_IF(0, 2, false);
      goto label_3;
    }
    CV_EML_MCDC(0, 1, true);
    CV_EML_IF(0, 2, true);
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,50);
    c2_flag = 0.0;
    label_3:;
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,56);
  if(CV_EML_COND(0, 5, c2_dir == -1.0)) {
    if(CV_EML_COND(0, 6, c2_touching) != 0.0) {
      if(CV_EML_COND(0, 7, c2_av > c2_x1wall)) {
        if(CV_EML_COND(0, 8, c2_flag == 0.0)) {
          CV_EML_MCDC(0, 2, true);
          CV_EML_IF(0, 3, true);
          /*  If the wall is solid and the avatar is touchign the wall */
          /* Calcualte the force based on the side of the wall the avatar is. */
          _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,57);
          c2_e_x = c2_av - c2_x1wall;
          c2_b_y = fabs(c2_e_x);
          c2_b_dir = c2_dir * c2_stiffness;
          c2_dv0[0] = 0.0;
          c2_dv0[1] = c2_b_y;
          c2_dv0[2] = 0.0;
          for(c2_i6 = 0; c2_i6 < 3; c2_i6 = c2_i6 + 1) {
            c2_Force[c2_i6] = c2_b_dir * c2_dv0[c2_i6];
          }
          goto label_4;
        }
      }
    }
  }
  CV_EML_MCDC(0, 2, false);
  CV_EML_IF(0, 3, false);
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,58);
  if(CV_EML_COND(0, 9, c2_dir == 1.0)) {
    if(CV_EML_COND(0, 10, c2_touching) != 0.0) {
      if(CV_EML_COND(0, 11, c2_av < c2_x2wall)) {
        if(CV_EML_COND(0, 12, c2_flag == 0.0)) {
          CV_EML_MCDC(0, 3, true);
          CV_EML_IF(0, 4, true);
          _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,59);
          c2_f_x = c2_av - c2_x2wall;
          c2_c_y = fabs(c2_f_x);
          c2_c_dir = c2_dir * c2_stiffness;
          c2_dv1[0] = 0.0;
          c2_dv1[1] = c2_c_y;
          c2_dv1[2] = 0.0;
          for(c2_i7 = 0; c2_i7 < 3; c2_i7 = c2_i7 + 1) {
            c2_Force[c2_i7] = c2_c_dir * c2_dv1[c2_i7];
          }
          goto label_4;
        }
      }
    }
  }
  CV_EML_MCDC(0, 3, false);
  CV_EML_IF(0, 4, false);
  label_4:;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,63);
  c2_g_x = c2_Force[1];
  c2_d_y = fabs(c2_g_x);
  if(CV_EML_IF(0, 5, c2_d_y >= c2_Fbreak)) {
    /* If force is above break force, change the status of the wall to broken */
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,64);
    c2_flag = 1.0;
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,69);
  if(CV_EML_IF(0, 6, c2_av < c2_x1wall)) {
    /*  if avatar is on the left, dir = -1, elseif avatar is on theright dir = 1 */
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,70);
    c2_dir = -1.0;
  } else {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,71);
    if(CV_EML_IF(0, 7, c2_av > c2_x2wall)) {
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,72);
      c2_dir = 1.0;
    }
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-72);
  sf_debug_symbol_scope_pop();
  for(c2_i8 = 0; c2_i8 < 3; c2_i8 = c2_i8 + 1) {
    (*c2_b_Force)[c2_i8] = c2_Force[c2_i8];
  }
  *c2_d_dir = c2_dir;
  *c2_b_flag = c2_flag;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
 c2_chartNumber)
{
}

static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i9;
  real_T c2_b_u[3];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for(c2_i9 = 0; c2_i9 < 3; c2_i9 = c2_i9 + 1) {
    c2_b_u[c2_i9] = (*((real_T (*)[3])c2_u))[c2_i9];
  }
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 1U, 1, 3));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i10;
  real_T c2_b_u[3];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for(c2_i10 = 0; c2_i10 < 3; c2_i10 = c2_i10 + 1) {
    c2_b_u[c2_i10] = (*((real_T (*)[3])c2_u))[c2_i10];
  }
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 1U, 1, 3));
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
  int32_T c2_i11;
  real_T c2_b_u[3];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for(c2_i11 = 0; c2_i11 < 3; c2_i11 = c2_i11 + 1) {
    c2_b_u[c2_i11] = (*((real_T (*)[3])c2_u))[c2_i11];
  }
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 1U, 1, 3));
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

const mxArray
*sf_c2_Puncture_Through_Wall_Falcon_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[38];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i12;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 38));
  for(c2_i12 = 0; c2_i12 < 38; c2_i12 = c2_i12 + 1) {
    c2_r0 = &c2_info[c2_i12];
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->context, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
     "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->name, "nameCaptureInfo", 13, 0U,
      0U, 2, 1, strlen(c2_r0->name)), "name",
     "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->dominantType, "nameCaptureInfo",
      13, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
     "dominantType", "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->resolved, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved",
     "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create(&c2_r0->fileLength, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileLength", "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create(&c2_r0->fileTime1, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create(&c2_r0->fileTime2, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i12);
  }
  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[38])
{
  c2_info[0].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_numel.m";
  c2_info[0].name = "numel";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[B]numel";
  c2_info[0].fileLength = 0U;
  c2_info[0].fileTime1 = 0U;
  c2_info[0].fileTime2 = 0U;
  c2_info[1].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c2_info[1].name = "eml_guarded_nan";
  c2_info[1].dominantType = "";
  c2_info[1].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c2_info[1].fileLength = 549U;
  c2_info[1].fileTime1 = 1160446740U;
  c2_info[1].fileTime2 = 0U;
  c2_info[2].context = "";
  c2_info[2].name = "abs";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[2].fileLength = 1031U;
  c2_info[2].fileTime1 = 1163970702U;
  c2_info[2].fileTime2 = 0U;
  c2_info[3].context = "";
  c2_info[3].name = "sign";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c2_info[3].fileLength = 892U;
  c2_info[3].fileTime1 = 1163970754U;
  c2_info[3].fileTime2 = 0U;
  c2_info[4].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[4].name = "isempty";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved = "[B]isempty";
  c2_info[4].fileLength = 0U;
  c2_info[4].fileTime1 = 0U;
  c2_info[4].fileTime2 = 0U;
  c2_info[5].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[5].name = "size";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved = "[B]size";
  c2_info[5].fileLength = 0U;
  c2_info[5].fileTime1 = 0U;
  c2_info[5].fileTime2 = 0U;
  c2_info[6].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[6].name = "double";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved = "[B]double";
  c2_info[6].fileLength = 0U;
  c2_info[6].fileTime1 = 0U;
  c2_info[6].fileTime2 = 0U;
  c2_info[7].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c2_info[7].name = "nargin";
  c2_info[7].dominantType = "";
  c2_info[7].resolved = "[B]nargin";
  c2_info[7].fileLength = 0U;
  c2_info[7].fileTime1 = 0U;
  c2_info[7].fileTime2 = 0U;
  c2_info[8].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[8].name = "eml_isa_uint";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c2_info[8].fileLength = 288U;
  c2_info[8].fileTime1 = 1163970798U;
  c2_info[8].fileTime2 = 0U;
  c2_info[9].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/nan.m";
  c2_info[9].name = "cast";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[9].fileLength = 907U;
  c2_info[9].fileTime1 = 1160446618U;
  c2_info[9].fileTime2 = 0U;
  c2_info[10].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[10].name = "zeros";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved = "[B]zeros";
  c2_info[10].fileLength = 0U;
  c2_info[10].fileTime1 = 0U;
  c2_info[10].fileTime2 = 0U;
  c2_info[11].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c2_info[11].name = "eq";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved = "[B]eq";
  c2_info[11].fileLength = 0U;
  c2_info[11].fileTime1 = 0U;
  c2_info[11].fileTime2 = 0U;
  c2_info[12].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[12].name = "isinteger";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isinteger.m";
  c2_info[12].fileLength = 254U;
  c2_info[12].fileTime1 = 1160446620U;
  c2_info[12].fileTime2 = 0U;
  c2_info[13].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[13].name = "isscalar";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isscalar.m";
  c2_info[13].fileLength = 243U;
  c2_info[13].fileTime1 = 1160446704U;
  c2_info[13].fileTime2 = 0U;
  c2_info[14].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c2_info[14].name = "eml_is_float_class";
  c2_info[14].dominantType = "char";
  c2_info[14].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[14].fileLength = 273U;
  c2_info[14].fileTime1 = 1160446744U;
  c2_info[14].fileTime2 = 0U;
  c2_info[15].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c2_info[15].name = "isreal";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved = "[B]isreal";
  c2_info[15].fileLength = 0U;
  c2_info[15].fileTime1 = 0U;
  c2_info[15].fileTime2 = 0U;
  c2_info[16].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c2_info[16].name = "class";
  c2_info[16].dominantType = "char";
  c2_info[16].resolved = "[B]class";
  c2_info[16].fileLength = 0U;
  c2_info[16].fileTime1 = 0U;
  c2_info[16].fileTime2 = 0U;
  c2_info[17].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c2_info[17].name = "isnumeric";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isnumeric.m";
  c2_info[17].fileLength = 250U;
  c2_info[17].fileTime1 = 1160446622U;
  c2_info[17].fileTime2 = 0U;
  c2_info[18].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c2_info[18].name = "eml_assert";
  c2_info[18].dominantType = "char";
  c2_info[18].resolved = "[B]eml_assert";
  c2_info[18].fileLength = 0U;
  c2_info[18].fileTime1 = 0U;
  c2_info[18].fileTime2 = 0U;
  c2_info[19].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isnumeric.m";
  c2_info[19].name = "isa";
  c2_info[19].dominantType = "double";
  c2_info[19].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c2_info[19].fileLength = 791U;
  c2_info[19].fileTime1 = 1160446618U;
  c2_info[19].fileTime2 = 0U;
  c2_info[20].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isnumeric.m";
  c2_info[20].name = "gt";
  c2_info[20].dominantType = "double";
  c2_info[20].resolved = "[B]gt";
  c2_info[20].fileLength = 0U;
  c2_info[20].fileTime1 = 0U;
  c2_info[20].fileTime2 = 0U;
  c2_info[21].context = "";
  c2_info[21].name = "plus";
  c2_info[21].dominantType = "double";
  c2_info[21].resolved = "[B]plus";
  c2_info[21].fileLength = 0U;
  c2_info[21].fileTime1 = 0U;
  c2_info[21].fileTime2 = 0U;
  c2_info[22].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c2_info[22].name = "eml_is_integer_class";
  c2_info[22].dominantType = "char";
  c2_info[22].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m";
  c2_info[22].fileLength = 462U;
  c2_info[22].fileTime1 = 1160446744U;
  c2_info[22].fileTime2 = 0U;
  c2_info[23].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c2_info[23].name = "lt";
  c2_info[23].dominantType = "double";
  c2_info[23].resolved = "[B]lt";
  c2_info[23].fileLength = 0U;
  c2_info[23].fileTime1 = 0U;
  c2_info[23].fileTime2 = 0U;
  c2_info[24].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c2_info[24].name = "eml_numel";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_numel.m";
  c2_info[24].fileLength = 278U;
  c2_info[24].fileTime1 = 1163970802U;
  c2_info[24].fileTime2 = 0U;
  c2_info[25].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[25].name = "islogical";
  c2_info[25].dominantType = "double";
  c2_info[25].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/islogical.m";
  c2_info[25].fileLength = 186U;
  c2_info[25].fileTime1 = 1160446622U;
  c2_info[25].fileTime2 = 0U;
  c2_info[26].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[26].name = "isfloat";
  c2_info[26].dominantType = "double";
  c2_info[26].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isfloat.m";
  c2_info[26].fileLength = 182U;
  c2_info[26].fileTime1 = 1160446620U;
  c2_info[26].fileTime2 = 0U;
  c2_info[27].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c2_info[27].name = "strcmp";
  c2_info[27].dominantType = "char";
  c2_info[27].resolved = "[B]strcmp";
  c2_info[27].fileLength = 0U;
  c2_info[27].fileTime1 = 0U;
  c2_info[27].fileTime2 = 0U;
  c2_info[28].context = "";
  c2_info[28].name = "ge";
  c2_info[28].dominantType = "double";
  c2_info[28].resolved = "[B]ge";
  c2_info[28].fileLength = 0U;
  c2_info[28].fileTime1 = 0U;
  c2_info[28].fileTime2 = 0U;
  c2_info[29].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c2_info[29].name = "isnan";
  c2_info[29].dominantType = "double";
  c2_info[29].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[29].fileLength = 514U;
  c2_info[29].fileTime1 = 1160446704U;
  c2_info[29].fileTime2 = 0U;
  c2_info[30].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[30].name = "ischar";
  c2_info[30].dominantType = "char";
  c2_info[30].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/strfun/ischar.m";
  c2_info[30].fileLength = 244U;
  c2_info[30].fileTime1 = 1160446834U;
  c2_info[30].fileTime2 = 0U;
  c2_info[31].context = "";
  c2_info[31].name = "mtimes";
  c2_info[31].dominantType = "double";
  c2_info[31].resolved = "[B]mtimes";
  c2_info[31].fileLength = 0U;
  c2_info[31].fileTime1 = 0U;
  c2_info[31].fileTime2 = 0U;
  c2_info[32].context = "";
  c2_info[32].name = "le";
  c2_info[32].dominantType = "double";
  c2_info[32].resolved = "[B]le";
  c2_info[32].fileLength = 0U;
  c2_info[32].fileTime1 = 0U;
  c2_info[32].fileTime2 = 0U;
  c2_info[33].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isscalar.m";
  c2_info[33].name = "length";
  c2_info[33].dominantType = "double";
  c2_info[33].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[33].fileLength = 347U;
  c2_info[33].fileTime1 = 1163970770U;
  c2_info[33].fileTime2 = 0U;
  c2_info[34].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[34].name = "not";
  c2_info[34].dominantType = "logical";
  c2_info[34].resolved = "[B]not";
  c2_info[34].fileLength = 0U;
  c2_info[34].fileTime1 = 0U;
  c2_info[34].fileTime2 = 0U;
  c2_info[35].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c2_info[35].name = "uminus";
  c2_info[35].dominantType = "double";
  c2_info[35].resolved = "[B]uminus";
  c2_info[35].fileLength = 0U;
  c2_info[35].fileTime1 = 0U;
  c2_info[35].fileTime2 = 0U;
  c2_info[36].context = "";
  c2_info[36].name = "minus";
  c2_info[36].dominantType = "double";
  c2_info[36].resolved = "[B]minus";
  c2_info[36].fileLength = 0U;
  c2_info[36].fileTime1 = 0U;
  c2_info[36].fileTime2 = 0U;
  c2_info[37].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c2_info[37].name = "nan";
  c2_info[37].dominantType = "char";
  c2_info[37].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/nan.m";
  c2_info[37].fileLength = 1496U;
  c2_info[37].fileTime1 = 1163970774U;
  c2_info[37].fileTime2 = 0U;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c2_Puncture_Through_Wall_Falcon_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(683160824U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2952259294U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3902431948U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(799497459U);
}

mxArray *sf_c2_Puncture_Through_Wall_Falcon_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1239856489U);
    pr[1] = (double)(1243958934U);
    pr[2] = (double)(1955566055U);
    pr[3] = (double)(2272247839U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);
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
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }
  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,mxREAL));
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);
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
         2,
         1,
         1,
         9,
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
            _SFD_SET_DATA_PROPS(8,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,1.0,0,"Force_prev",0,c2_sf_marshall);
          }
          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(4,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,1.0,0,"Force",0,c2_g_sf_marshall);
          }
          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,1.0,0,"x",0,c2_b_sf_marshall);
          }
          _SFD_SET_DATA_PROPS(7,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"dir",0,c2_h_sf_marshall);
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"stiffness",0,c2_c_sf_marshall);
          _SFD_SET_DATA_PROPS(6,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Fbreak",0,c2_d_sf_marshall);
          _SFD_SET_DATA_PROPS(5,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"dir_prev",0,c2_e_sf_marshall);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"prev_flag",0,c2_f_sf_marshall);
          _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"flag",0,c2_i_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,8,0,0,0,13,4);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2534);
        _SFD_CV_INIT_EML_IF(0,0,1604,1670,1689,1715);
        _SFD_CV_INIT_EML_IF(0,1,1841,1858,-1,-2);
        _SFD_CV_INIT_EML_IF(0,2,1877,1906,-1,-2);
        _SFD_CV_INIT_EML_IF(0,3,2063,2115,2164,2271);
        _SFD_CV_INIT_EML_IF(0,4,2164,2219,-1,-2);
        _SFD_CV_INIT_EML_IF(0,5,2345,2371,-1,2389);
        _SFD_CV_INIT_EML_IF(0,6,2467,2481,2496,2531);
        _SFD_CV_INIT_EML_IF(0,7,2496,2514,-1,-2);
        {
          static int condStart[] = {1608,1624,1643};
          static int condEnd[] = {1620,1636,1669};
          static int pfixExpr[] = {0,1,-3,2,-2};
          _SFD_CV_INIT_EML_MCDC(0,0,1607,1670,3,0,&(condStart[0]),&(condEnd[0]),5,&(pfixExpr[0]));
        }
        {
          static int condStart[] = {1881,1895};
          static int condEnd[] = {1891,1905};
          static int pfixExpr[] = {0,1,-2};
          _SFD_CV_INIT_EML_MCDC(0,1,1881,1905,2,3,&(condStart[0]),&(condEnd[0]),3,&(pfixExpr[0]));
        }
        {
          static int condStart[] = {2066,2079,2091,2106};
          static int condEnd[] = {2075,2087,2102,2115};
          static int pfixExpr[] = {0,1,-3,2,-3,3,-3};
          _SFD_CV_INIT_EML_MCDC(0,2,2066,2115,4,5,&(condStart[0]),&(condEnd[0]),7,&(pfixExpr[0]));
        }
        {
          static int condStart[] = {2171,2183,2195,2210};
          static int condEnd[] = {2179,2191,2206,2219};
          static int pfixExpr[] = {0,1,-3,2,-3,3,-3};
          _SFD_CV_INIT_EML_MCDC(0,3,2171,2219,4,9,&(condStart[0]),&(condEnd[0]),7,&(pfixExpr[0]));
        }
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
          real_T (*c2_Force_prev)[3];
          real_T (*c2_Force)[3];
          real_T (*c2_x)[3];
          real_T *c2_dir;
          real_T *c2_stiffness;
          real_T *c2_Fbreak;
          real_T *c2_dir_prev;
          real_T *c2_prev_flag;
          real_T *c2_flag;
          c2_x = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 1);
          c2_Force_prev = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S,
           0);
          c2_prev_flag = (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
          c2_flag = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
          c2_Fbreak = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
          c2_dir_prev = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
          c2_Force = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
          c2_dir = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
          c2_stiffness = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
          _SFD_SET_DATA_VALUE_PTR(8U, c2_Force_prev);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_Force);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_x);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_dir);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_stiffness);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_Fbreak);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_dir_prev);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_prev_flag);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_flag);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_Puncture_Through_Wall_FalconMachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c2_Puncture_Through_Wall_Falcon(void
 *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c2_Puncture_Through_Wall_Falcon();
  initialize_c2_Puncture_Through_Wall_Falcon();
}

static void sf_opaque_enable_c2_Puncture_Through_Wall_Falcon(void
 *chartInstanceVar)
{
  enable_c2_Puncture_Through_Wall_Falcon();
}

static void sf_opaque_disable_c2_Puncture_Through_Wall_Falcon(void
 *chartInstanceVar)
{
  disable_c2_Puncture_Through_Wall_Falcon();
}

static void sf_opaque_gateway_c2_Puncture_Through_Wall_Falcon(void
 *chartInstanceVar)
{
  sf_c2_Puncture_Through_Wall_Falcon();
}

static void sf_opaque_ext_mode_exec_c2_Puncture_Through_Wall_Falcon(void
 *chartInstanceVar)
{
  ext_mode_exec_c2_Puncture_Through_Wall_Falcon();
}

static void sf_opaque_terminate_c2_Puncture_Through_Wall_Falcon(void
 *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) ||
   sim_mode_is_external(chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }
  finalize_c2_Puncture_Through_Wall_Falcon();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_Puncture_Through_Wall_Falcon(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  if(sf_machine_global_initializer_called()) {
    initialize_params_c2_Puncture_Through_Wall_Falcon();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr =
  "100 S1x2'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}";
  sf_set_encoded_dwork_info(S, dworkEncStr);
}

static void mdlSetWorkWidths_c2_Puncture_Through_Wall_Falcon(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("Puncture_Through_Wall_Falcon",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("Puncture_Through_Wall_Falcon",2,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"Puncture_Through_Wall_Falcon",2,6);
      sf_mark_chart_reusable_outputs(S,"Puncture_Through_Wall_Falcon",2,3);
    }
    sf_set_rtw_dwork_info(S,"Puncture_Through_Wall_Falcon",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(1729898635U));
  ssSetChecksum1(S,(1034377060U));
  ssSetChecksum2(S,(1989315575U));
  ssSetChecksum3(S,(2416778737U));

  ssSetmdlDerivatives(S, NULL);

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_Puncture_Through_Wall_Falcon(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Puncture_Through_Wall_Falcon", 2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_Puncture_Through_Wall_Falcon(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_Puncture_Through_Wall_Falcon;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c2_Puncture_Through_Wall_Falcon;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c2_Puncture_Through_Wall_Falcon;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c2_Puncture_Through_Wall_Falcon;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c2_Puncture_Through_Wall_Falcon;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c2_Puncture_Through_Wall_Falcon;
  chartInstance.chartInfo.mdlStart = mdlStart_c2_Puncture_Through_Wall_Falcon;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_Puncture_Through_Wall_Falcon;
  chartInstance.chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c2_Puncture_Through_Wall_Falcon;
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

void c2_Puncture_Through_Wall_Falcon_method_dispatcher(SimStruct *S, int_T
 method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_Puncture_Through_Wall_Falcon(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_Puncture_Through_Wall_Falcon(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_Puncture_Through_Wall_Falcon(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c2_Puncture_Through_Wall_Falcon_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

