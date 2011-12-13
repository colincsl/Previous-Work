/* Include files */
#include "Maze_Omni_sfun.h"
#include "c5_Maze_Omni.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "Maze_Omni_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c5_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc5_Maze_OmniInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c5_Maze_Omni(void);
static void initialize_params_c5_Maze_Omni(void);
static void enable_c5_Maze_Omni(void);
static void disable_c5_Maze_Omni(void);
static void ext_mode_exec_c5_Maze_Omni(void);
static void finalize_c5_Maze_Omni(void);
static void sf_c5_Maze_Omni(void);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
 c5_chartNumber);
static void c5_DH(real_T c5_a_x, real_T c5_alpha_x, real_T c5_d_z, real_T
 c5_theta_z, real_T c5_A[16]);
static const mxArray *c5_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_b_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_c_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_d_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_e_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_f_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_g_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_h_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_i_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_j_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_k_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_l_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_m_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_n_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_o_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_p_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_q_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_r_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_s_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_t_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_u_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_v_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_w_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_x_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_y_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_ab_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_bb_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_cb_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_db_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_eb_sf_marshall(void *c5_chartInstance, void *c5_u);
static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[49]);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c5_Maze_Omni(void)
{
  uint8_T *c5_is_active_c5_Maze_Omni;
  c5_is_active_c5_Maze_Omni = (uint8_T *)ssGetDWork(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  *c5_is_active_c5_Maze_Omni = 0U;
}

static void initialize_params_c5_Maze_Omni(void)
{
}

static void enable_c5_Maze_Omni(void)
{
}

static void disable_c5_Maze_Omni(void)
{
}

static void ext_mode_exec_c5_Maze_Omni(void)
{
}

static void finalize_c5_Maze_Omni(void)
{
}

static void sf_c5_Maze_Omni(void)
{
  int32_T c5_i0;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  uint8_T c5_previousEvent;
  int32_T c5_i8;
  real_T c5_q[3];
  int32_T c5_i9;
  int32_T c5_i10;
  real_T c5_tool_offset[16];
  real_T c5_T_tool[16];
  real_T c5_p3[3];
  real_T c5_p2[3];
  real_T c5_p1[3];
  real_T c5_p0[3];
  real_T c5_z2[3];
  real_T c5_z1[3];
  real_T c5_z0[3];
  real_T c5_T03[16];
  real_T c5_T02[16];
  real_T c5_T01[16];
  real_T c5_A3[16];
  real_T c5_A2[16];
  real_T c5_A1[16];
  real_T c5_L2;
  real_T c5_L1;
  real_T c5_Jac[18];
  real_T c5_Rot[9];
  real_T c5_pos[3];
  real_T c5_dv0[16];
  int32_T c5_i11;
  int32_T c5_i12;
  real_T c5_dv1[16];
  int32_T c5_i13;
  int32_T c5_i14;
  real_T c5_A;
  real_T c5_B;
  real_T c5_x;
  real_T c5_y;
  real_T c5_b_y;
  real_T c5_dv2[16];
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  static real_T c5_dv3[3] = { 0.0, 0.0, 1.0 };
  int32_T c5_i26;
  int32_T c5_hoistedExpr;
  int32_T c5_i27;
  int32_T c5_b_hoistedExpr;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_c_hoistedExpr;
  int32_T c5_i30;
  int32_T c5_d_hoistedExpr;
  int32_T c5_i31;
  int32_T c5_e_hoistedExpr;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  int32_T c5_i36;
  int32_T c5_f_hoistedExpr;
  int32_T c5_g_hoistedExpr;
  int32_T c5_i37;
  int32_T c5_h_hoistedExpr;
  int32_T c5_i38;
  real_T c5_a[3];
  int32_T c5_i39;
  real_T c5_b[3];
  real_T c5_c1;
  real_T c5_c2;
  real_T c5_c3;
  real_T c5_c[3];
  int32_T c5_i40;
  real_T c5_b_a[3];
  int32_T c5_i41;
  real_T c5_b_b[3];
  real_T c5_b_c1;
  real_T c5_b_c2;
  real_T c5_b_c3;
  real_T c5_b_c[3];
  int32_T c5_i42;
  real_T c5_c_a[3];
  int32_T c5_i43;
  real_T c5_c_b[3];
  real_T c5_c_c1;
  real_T c5_c_c2;
  real_T c5_c_c3;
  real_T c5_c_c[3];
  int32_T c5_i44;
  int32_T c5_i45;
  int32_T c5_i46;
  int32_T c5_i47;
  int32_T c5_i48;
  int32_T c5_i49;
  int32_T c5_i50;
  int32_T c5_i51;
  int32_T c5_i52;
  int32_T c5_i53;
  int32_T c5_i54;
  real_T (*c5_b_pos)[3];
  real_T (*c5_b_Rot)[9];
  real_T (*c5_b_Jac)[18];
  real_T (*c5_b_q)[3];
  real_T (*c5_b_tool_offset)[16];
  c5_b_Rot = (real_T (*)[9])ssGetOutputPortSignal(chartInstance.S, 2);
  c5_b_pos = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
  c5_b_Jac = (real_T (*)[18])ssGetOutputPortSignal(chartInstance.S, 3);
  c5_b_q = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
  c5_b_tool_offset = (real_T (*)[16])ssGetInputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  for(c5_i0 = 0; c5_i0 < 3; c5_i0 = c5_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((*c5_b_pos)[c5_i0], 1U);
  }
  for(c5_i1 = 0; c5_i1 < 3; c5_i1 = c5_i1 + 1) {
    _SFD_DATA_RANGE_CHECK((*c5_b_q)[c5_i1], 4U);
  }
  for(c5_i2 = 0; c5_i2 < 3; c5_i2 = c5_i2 + 1) {
    for(c5_i3 = 0; c5_i3 < 3; c5_i3 = c5_i3 + 1) {
      _SFD_DATA_RANGE_CHECK((*c5_b_Rot)[c5_i3 + 3 * c5_i2], 0U);
    }
  }
  for(c5_i4 = 0; c5_i4 < 4; c5_i4 = c5_i4 + 1) {
    for(c5_i5 = 0; c5_i5 < 4; c5_i5 = c5_i5 + 1) {
      _SFD_DATA_RANGE_CHECK((*c5_b_tool_offset)[c5_i5 + 4 * c5_i4], 2U);
    }
  }
  for(c5_i6 = 0; c5_i6 < 3; c5_i6 = c5_i6 + 1) {
    for(c5_i7 = 0; c5_i7 < 6; c5_i7 = c5_i7 + 1) {
      _SFD_DATA_RANGE_CHECK((*c5_b_Jac)[c5_i7 + 6 * c5_i6], 3U);
    }
  }
  c5_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,2);
  for(c5_i8 = 0; c5_i8 < 3; c5_i8 = c5_i8 + 1) {
    c5_q[c5_i8] = (*c5_b_q)[c5_i8];
  }
  for(c5_i9 = 0; c5_i9 < 4; c5_i9 = c5_i9 + 1) {
    for(c5_i10 = 0; c5_i10 < 4; c5_i10 = c5_i10 + 1) {
      c5_tool_offset[c5_i10 + 4 * c5_i9] = (*c5_b_tool_offset)[c5_i10 + 4 *
        c5_i9];
    }
  }
  sf_debug_symbol_scope_push(21U, 0U);
  sf_debug_symbol_scope_add("T_tool", &c5_T_tool, c5_u_sf_marshall);
  sf_debug_symbol_scope_add("p3", &c5_p3, c5_t_sf_marshall);
  sf_debug_symbol_scope_add("p2", &c5_p2, c5_s_sf_marshall);
  sf_debug_symbol_scope_add("p1", &c5_p1, c5_r_sf_marshall);
  sf_debug_symbol_scope_add("p0", &c5_p0, c5_q_sf_marshall);
  sf_debug_symbol_scope_add("z2", &c5_z2, c5_p_sf_marshall);
  sf_debug_symbol_scope_add("z1", &c5_z1, c5_o_sf_marshall);
  sf_debug_symbol_scope_add("z0", &c5_z0, c5_n_sf_marshall);
  sf_debug_symbol_scope_add("T03", &c5_T03, c5_m_sf_marshall);
  sf_debug_symbol_scope_add("T02", &c5_T02, c5_l_sf_marshall);
  sf_debug_symbol_scope_add("T01", &c5_T01, c5_k_sf_marshall);
  sf_debug_symbol_scope_add("A3", &c5_A3, c5_j_sf_marshall);
  sf_debug_symbol_scope_add("A2", &c5_A2, c5_i_sf_marshall);
  sf_debug_symbol_scope_add("A1", &c5_A1, c5_h_sf_marshall);
  sf_debug_symbol_scope_add("L2", &c5_L2, c5_g_sf_marshall);
  sf_debug_symbol_scope_add("L1", &c5_L1, c5_f_sf_marshall);
  sf_debug_symbol_scope_add("Jac", &c5_Jac, c5_e_sf_marshall);
  sf_debug_symbol_scope_add("Rot", &c5_Rot, c5_d_sf_marshall);
  sf_debug_symbol_scope_add("pos", &c5_pos, c5_c_sf_marshall);
  sf_debug_symbol_scope_add("tool_offset", &c5_tool_offset, c5_b_sf_marshall);
  sf_debug_symbol_scope_add("q", &c5_q, c5_sf_marshall);
  CV_EML_FCN(0, 0);
  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  /*  Link lengths */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,6);
  c5_L1 = 0.132;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,7);
  c5_L2 = 0.132;
  /* Define A-matrices */
  /* A1= DH(a_i ,alpha_i    ,d_i    ,theta_i) */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,11);
  c5_DH(0.0, -1.5707963267948966E+000, 0.0, c5_q[0], c5_dv0);
  for(c5_i11 = 0; c5_i11 < 4; c5_i11 = c5_i11 + 1) {
    for(c5_i12 = 0; c5_i12 < 4; c5_i12 = c5_i12 + 1) {
      c5_A1[c5_i12 + 4 * c5_i11] = c5_dv0[c5_i12 + 4 * c5_i11];
    }
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,12);
  c5_DH(0.132, 0.0, 0.0, c5_q[1], c5_dv1);
  for(c5_i13 = 0; c5_i13 < 4; c5_i13 = c5_i13 + 1) {
    for(c5_i14 = 0; c5_i14 < 4; c5_i14 = c5_i14 + 1) {
      c5_A2[c5_i14 + 4 * c5_i13] = c5_dv1[c5_i14 + 4 * c5_i13];
    }
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,13);
  c5_A = 3.1415926535897931E+000;
  c5_B = 2.0;
  c5_x = c5_A;
  c5_y = c5_B;
  c5_b_y = c5_x / c5_y;
  c5_DH(0.132, 0.0, 0.0, c5_q[2] - c5_b_y, c5_dv2);
  for(c5_i15 = 0; c5_i15 < 4; c5_i15 = c5_i15 + 1) {
    for(c5_i16 = 0; c5_i16 < 4; c5_i16 = c5_i16 + 1) {
      c5_A3[c5_i16 + 4 * c5_i15] = c5_dv2[c5_i16 + 4 * c5_i15];
    }
  }
  /* Define T Matrices */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,16);
  for(c5_i17 = 0; c5_i17 < 4; c5_i17 = c5_i17 + 1) {
    for(c5_i18 = 0; c5_i18 < 4; c5_i18 = c5_i18 + 1) {
      c5_T01[c5_i18 + 4 * c5_i17] = c5_A1[c5_i18 + 4 * c5_i17];
    }
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,17);
  for(c5_i19 = 0; c5_i19 < 4; c5_i19 = c5_i19 + 1) {
    for(c5_i20 = 0; c5_i20 < 4; c5_i20 = c5_i20 + 1) {
      c5_T02[c5_i19 + 4 * c5_i20] = 0.0;
      for(c5_i21 = 0; c5_i21 < 4; c5_i21 = c5_i21 + 1) {
        c5_T02[c5_i19 + 4 * c5_i20] = c5_T02[c5_i19 + 4 * c5_i20] +
          c5_T01[c5_i19 + 4 * c5_i21] * c5_A2[c5_i21 + 4 * c5_i20];
      }
    }
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,18);
  for(c5_i22 = 0; c5_i22 < 4; c5_i22 = c5_i22 + 1) {
    for(c5_i23 = 0; c5_i23 < 4; c5_i23 = c5_i23 + 1) {
      c5_T03[c5_i22 + 4 * c5_i23] = 0.0;
      for(c5_i24 = 0; c5_i24 < 4; c5_i24 = c5_i24 + 1) {
        c5_T03[c5_i22 + 4 * c5_i23] = c5_T03[c5_i22 + 4 * c5_i23] +
          c5_T02[c5_i22 + 4 * c5_i24] * c5_A3[c5_i24 + 4 * c5_i23];
      }
    }
  }
  /* Axes of rotation in base coordinates.  */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,22);
  for(c5_i25 = 0; c5_i25 < 3; c5_i25 = c5_i25 + 1) {
    c5_z0[c5_i25] = c5_dv3[c5_i25];
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,23);
  for(c5_i26 = 0; c5_i26 < 3; c5_i26 = c5_i26 + 1) {
    c5_hoistedExpr = 0;
    c5_z1[c5_i26] = c5_T01[c5_i26 + 8];
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,24);
  for(c5_i27 = 0; c5_i27 < 3; c5_i27 = c5_i27 + 1) {
    c5_b_hoistedExpr = 0;
    c5_z2[c5_i27] = c5_T02[c5_i27 + 8];
  }
  /* Coordinate Frame origins in Base frame coordinates */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,28);
  for(c5_i28 = 0; c5_i28 < 3; c5_i28 = c5_i28 + 1) {
    c5_p0[c5_i28] = 0.0;
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,29);
  for(c5_i29 = 0; c5_i29 < 3; c5_i29 = c5_i29 + 1) {
    c5_c_hoistedExpr = 0;
    c5_p1[c5_i29] = c5_T01[c5_i29 + 12];
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,30);
  for(c5_i30 = 0; c5_i30 < 3; c5_i30 = c5_i30 + 1) {
    c5_d_hoistedExpr = 0;
    c5_p2[c5_i30] = c5_T02[c5_i30 + 12];
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,31);
  for(c5_i31 = 0; c5_i31 < 3; c5_i31 = c5_i31 + 1) {
    c5_e_hoistedExpr = 0;
    c5_p3[c5_i31] = c5_T03[c5_i31 + 12];
  }
  /* tool_offset given with respect to frame 3. */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,35);
  for(c5_i32 = 0; c5_i32 < 4; c5_i32 = c5_i32 + 1) {
    for(c5_i33 = 0; c5_i33 < 4; c5_i33 = c5_i33 + 1) {
      c5_T_tool[c5_i32 + 4 * c5_i33] = 0.0;
      for(c5_i34 = 0; c5_i34 < 4; c5_i34 = c5_i34 + 1) {
        c5_T_tool[c5_i32 + 4 * c5_i33] = c5_T_tool[c5_i32 + 4 * c5_i33] +
          c5_T03[c5_i32 + 4 * c5_i34] * c5_tool_offset[c5_i34 + 4 * c5_i33];
      }
    }
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,36);
  for(c5_i35 = 0; c5_i35 < 3; c5_i35 = c5_i35 + 1) {
    for(c5_i36 = 0; c5_i36 < 3; c5_i36 = c5_i36 + 1) {
      c5_f_hoistedExpr = 0;
      c5_g_hoistedExpr = 0;
      c5_Rot[c5_i36 + 3 * c5_i35] = c5_T03[c5_i36 + 4 * c5_i35];
    }
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,37);
  for(c5_i37 = 0; c5_i37 < 3; c5_i37 = c5_i37 + 1) {
    c5_h_hoistedExpr = 0;
    c5_pos[c5_i37] = c5_T_tool[c5_i37 + 12];
  }
  /* Formulation of the Jacobian */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%JACOBIAN%%%%%%%%%%%%%%%%%%%%%%%% */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,42);
  for(c5_i38 = 0; c5_i38 < 3; c5_i38 = c5_i38 + 1) {
    c5_a[c5_i38] = c5_z2[c5_i38];
  }
  for(c5_i39 = 0; c5_i39 < 3; c5_i39 = c5_i39 + 1) {
    c5_b[c5_i39] = c5_pos[c5_i39] - c5_p2[c5_i39];
  }
  c5_c1 = c5_a[1] * c5_b[2] - c5_a[2] * c5_b[1];
  c5_c2 = c5_a[2] * c5_b[0] - c5_a[0] * c5_b[2];
  c5_c3 = c5_a[0] * c5_b[1] - c5_a[1] * c5_b[0];
  c5_c[0] = c5_c1;
  c5_c[1] = c5_c2;
  c5_c[2] = c5_c3;
  for(c5_i40 = 0; c5_i40 < 3; c5_i40 = c5_i40 + 1) {
    c5_b_a[c5_i40] = c5_z1[c5_i40];
  }
  for(c5_i41 = 0; c5_i41 < 3; c5_i41 = c5_i41 + 1) {
    c5_b_b[c5_i41] = c5_pos[c5_i41] - c5_p1[c5_i41];
  }
  c5_b_c1 = c5_b_a[1] * c5_b_b[2] - c5_b_a[2] * c5_b_b[1];
  c5_b_c2 = c5_b_a[2] * c5_b_b[0] - c5_b_a[0] * c5_b_b[2];
  c5_b_c3 = c5_b_a[0] * c5_b_b[1] - c5_b_a[1] * c5_b_b[0];
  c5_b_c[0] = c5_b_c1;
  c5_b_c[1] = c5_b_c2;
  c5_b_c[2] = c5_b_c3;
  for(c5_i42 = 0; c5_i42 < 3; c5_i42 = c5_i42 + 1) {
    c5_c_a[c5_i42] = c5_dv3[c5_i42];
  }
  for(c5_i43 = 0; c5_i43 < 3; c5_i43 = c5_i43 + 1) {
    c5_c_b[c5_i43] = c5_pos[c5_i43] - c5_p0[c5_i43];
  }
  c5_c_c1 = c5_c_a[1] * c5_c_b[2] - c5_c_a[2] * c5_c_b[1];
  c5_c_c2 = c5_c_a[2] * c5_c_b[0] - c5_c_a[0] * c5_c_b[2];
  c5_c_c3 = c5_c_a[0] * c5_c_b[1] - c5_c_a[1] * c5_c_b[0];
  c5_c_c[0] = c5_c_c1;
  c5_c_c[1] = c5_c_c2;
  c5_c_c[2] = c5_c_c3;
  for(c5_i44 = 0; c5_i44 < 3; c5_i44 = c5_i44 + 1) {
    c5_Jac[c5_i44] = c5_c_c[c5_i44];
  }
  for(c5_i45 = 0; c5_i45 < 3; c5_i45 = c5_i45 + 1) {
    c5_Jac[c5_i45 + 6] = c5_b_c[c5_i45];
  }
  for(c5_i46 = 0; c5_i46 < 3; c5_i46 = c5_i46 + 1) {
    c5_Jac[c5_i46 + 12] = c5_c[c5_i46];
  }
  for(c5_i47 = 0; c5_i47 < 3; c5_i47 = c5_i47 + 1) {
    c5_Jac[c5_i47 + 3] = c5_z0[c5_i47];
  }
  for(c5_i48 = 0; c5_i48 < 3; c5_i48 = c5_i48 + 1) {
    c5_Jac[c5_i48 + 9] = c5_z1[c5_i48];
  }
  for(c5_i49 = 0; c5_i49 < 3; c5_i49 = c5_i49 + 1) {
    c5_Jac[c5_i49 + 15] = c5_z2[c5_i49];
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-42);
  sf_debug_symbol_scope_pop();
  for(c5_i50 = 0; c5_i50 < 3; c5_i50 = c5_i50 + 1) {
    (*c5_b_pos)[c5_i50] = c5_pos[c5_i50];
  }
  for(c5_i51 = 0; c5_i51 < 3; c5_i51 = c5_i51 + 1) {
    for(c5_i52 = 0; c5_i52 < 3; c5_i52 = c5_i52 + 1) {
      (*c5_b_Rot)[c5_i52 + 3 * c5_i51] = c5_Rot[c5_i52 + 3 * c5_i51];
    }
  }
  for(c5_i53 = 0; c5_i53 < 3; c5_i53 = c5_i53 + 1) {
    for(c5_i54 = 0; c5_i54 < 6; c5_i54 = c5_i54 + 1) {
      (*c5_b_Jac)[c5_i54 + 6 * c5_i53] = c5_Jac[c5_i54 + 6 * c5_i53];
    }
  }
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
  _sfEvent_ = c5_previousEvent;
  sf_debug_check_for_state_inconsistency(_Maze_OmniMachineNumber_,
   chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
 c5_chartNumber)
{
}

static void c5_DH(real_T c5_a_x, real_T c5_alpha_x, real_T c5_d_z, real_T
 c5_theta_z, real_T c5_A[16])
{
  real_T c5_A_R_x[16];
  real_T c5_A_T_x[16];
  real_T c5_A_T_z[16];
  real_T c5_A_R_z[16];
  real_T c5_x;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_h_x;
  int32_T c5_i55;
  static real_T c5_dv4[4] = { 0.0, 0.0, 1.0, 0.0 };
  int32_T c5_i56;
  static real_T c5_dv5[4] = { 0.0, 0.0, 0.0, 1.0 };
  int32_T c5_i57;
  static real_T c5_dv6[4] = { 1.0, 0.0, 0.0, 0.0 };
  int32_T c5_i58;
  static real_T c5_dv7[4] = { 0.0, 1.0, 0.0, 0.0 };
  int32_T c5_i59;
  int32_T c5_i60;
  int32_T c5_i61;
  int32_T c5_i62;
  real_T c5_i_x;
  real_T c5_j_x;
  real_T c5_k_x;
  real_T c5_l_x;
  real_T c5_m_x;
  real_T c5_n_x;
  real_T c5_o_x;
  real_T c5_p_x;
  int32_T c5_i63;
  int32_T c5_i64;
  int32_T c5_i65;
  int32_T c5_i66;
  real_T c5_dv8[16];
  int32_T c5_i67;
  int32_T c5_i68;
  int32_T c5_i69;
  real_T c5_dv9[16];
  int32_T c5_i70;
  int32_T c5_i71;
  int32_T c5_i72;
  int32_T c5_i73;
  sf_debug_symbol_scope_push(9U, 0U);
  sf_debug_symbol_scope_add("A_R_x", &c5_A_R_x, c5_eb_sf_marshall);
  sf_debug_symbol_scope_add("A_T_x", &c5_A_T_x, c5_db_sf_marshall);
  sf_debug_symbol_scope_add("A_T_z", &c5_A_T_z, c5_cb_sf_marshall);
  sf_debug_symbol_scope_add("A_R_z", &c5_A_R_z, c5_bb_sf_marshall);
  sf_debug_symbol_scope_add("A", c5_A, c5_ab_sf_marshall);
  sf_debug_symbol_scope_add("theta_z", &c5_theta_z, c5_y_sf_marshall);
  sf_debug_symbol_scope_add("d_z", &c5_d_z, c5_x_sf_marshall);
  sf_debug_symbol_scope_add("alpha_x", &c5_alpha_x, c5_w_sf_marshall);
  sf_debug_symbol_scope_add("a_x", &c5_a_x, c5_v_sf_marshall);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,49);
  c5_x = c5_theta_z;
  c5_b_x = c5_x;
  c5_b_x = cos(c5_b_x);
  c5_c_x = c5_theta_z;
  c5_d_x = c5_c_x;
  c5_d_x = sin(c5_d_x);
  c5_e_x = c5_theta_z;
  c5_f_x = c5_e_x;
  c5_f_x = sin(c5_f_x);
  c5_g_x = c5_theta_z;
  c5_h_x = c5_g_x;
  c5_h_x = cos(c5_h_x);
  c5_A_R_z[0] = c5_h_x;
  c5_A_R_z[4] = -c5_f_x;
  c5_A_R_z[8] = 0.0;
  c5_A_R_z[12] = 0.0;
  c5_A_R_z[1] = c5_d_x;
  c5_A_R_z[5] = c5_b_x;
  c5_A_R_z[9] = 0.0;
  c5_A_R_z[13] = 0.0;
  for(c5_i55 = 0; c5_i55 < 4; c5_i55 = c5_i55 + 1) {
    c5_A_R_z[2 + 4 * c5_i55] = c5_dv4[c5_i55];
  }
  for(c5_i56 = 0; c5_i56 < 4; c5_i56 = c5_i56 + 1) {
    c5_A_R_z[3 + 4 * c5_i56] = c5_dv5[c5_i56];
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,54);
  for(c5_i57 = 0; c5_i57 < 4; c5_i57 = c5_i57 + 1) {
    c5_A_T_z[4 * c5_i57] = c5_dv6[c5_i57];
  }
  for(c5_i58 = 0; c5_i58 < 4; c5_i58 = c5_i58 + 1) {
    c5_A_T_z[1 + 4 * c5_i58] = c5_dv7[c5_i58];
  }
  c5_A_T_z[2] = 0.0;
  c5_A_T_z[6] = 0.0;
  c5_A_T_z[10] = 1.0;
  c5_A_T_z[14] = c5_d_z;
  for(c5_i59 = 0; c5_i59 < 4; c5_i59 = c5_i59 + 1) {
    c5_A_T_z[3 + 4 * c5_i59] = c5_dv5[c5_i59];
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,61);
  c5_A_T_x[0] = 1.0;
  c5_A_T_x[4] = 0.0;
  c5_A_T_x[8] = 0.0;
  c5_A_T_x[12] = c5_a_x;
  for(c5_i60 = 0; c5_i60 < 4; c5_i60 = c5_i60 + 1) {
    c5_A_T_x[1 + 4 * c5_i60] = c5_dv7[c5_i60];
  }
  for(c5_i61 = 0; c5_i61 < 4; c5_i61 = c5_i61 + 1) {
    c5_A_T_x[2 + 4 * c5_i61] = c5_dv4[c5_i61];
  }
  for(c5_i62 = 0; c5_i62 < 4; c5_i62 = c5_i62 + 1) {
    c5_A_T_x[3 + 4 * c5_i62] = c5_dv5[c5_i62];
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,66);
  c5_i_x = c5_alpha_x;
  c5_j_x = c5_i_x;
  c5_j_x = cos(c5_j_x);
  c5_k_x = c5_alpha_x;
  c5_l_x = c5_k_x;
  c5_l_x = sin(c5_l_x);
  c5_m_x = c5_alpha_x;
  c5_n_x = c5_m_x;
  c5_n_x = sin(c5_n_x);
  c5_o_x = c5_alpha_x;
  c5_p_x = c5_o_x;
  c5_p_x = cos(c5_p_x);
  for(c5_i63 = 0; c5_i63 < 4; c5_i63 = c5_i63 + 1) {
    c5_A_R_x[4 * c5_i63] = c5_dv6[c5_i63];
  }
  c5_A_R_x[1] = 0.0;
  c5_A_R_x[5] = c5_p_x;
  c5_A_R_x[9] = -c5_n_x;
  c5_A_R_x[13] = 0.0;
  c5_A_R_x[2] = 0.0;
  c5_A_R_x[6] = c5_l_x;
  c5_A_R_x[10] = c5_j_x;
  c5_A_R_x[14] = 0.0;
  for(c5_i64 = 0; c5_i64 < 4; c5_i64 = c5_i64 + 1) {
    c5_A_R_x[3 + 4 * c5_i64] = c5_dv5[c5_i64];
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,71);
  for(c5_i65 = 0; c5_i65 < 4; c5_i65 = c5_i65 + 1) {
    for(c5_i66 = 0; c5_i66 < 4; c5_i66 = c5_i66 + 1) {
      c5_dv8[c5_i65 + 4 * c5_i66] = 0.0;
      for(c5_i67 = 0; c5_i67 < 4; c5_i67 = c5_i67 + 1) {
        c5_dv8[c5_i65 + 4 * c5_i66] = c5_dv8[c5_i65 + 4 * c5_i66] +
          c5_A_R_z[c5_i65 + 4 * c5_i67] * c5_A_T_z[c5_i67 + 4 * c5_i66];
      }
    }
  }
  for(c5_i68 = 0; c5_i68 < 4; c5_i68 = c5_i68 + 1) {
    for(c5_i69 = 0; c5_i69 < 4; c5_i69 = c5_i69 + 1) {
      c5_dv9[c5_i68 + 4 * c5_i69] = 0.0;
      for(c5_i70 = 0; c5_i70 < 4; c5_i70 = c5_i70 + 1) {
        c5_dv9[c5_i68 + 4 * c5_i69] = c5_dv9[c5_i68 + 4 * c5_i69] +
          c5_dv8[c5_i68 + 4 * c5_i70] * c5_A_T_x[c5_i70 + 4 * c5_i69];
      }
    }
  }
  for(c5_i71 = 0; c5_i71 < 4; c5_i71 = c5_i71 + 1) {
    for(c5_i72 = 0; c5_i72 < 4; c5_i72 = c5_i72 + 1) {
      c5_A[c5_i71 + 4 * c5_i72] = 0.0;
      for(c5_i73 = 0; c5_i73 < 4; c5_i73 = c5_i73 + 1) {
        c5_A[c5_i71 + 4 * c5_i72] = c5_A[c5_i71 + 4 * c5_i72] + c5_dv9[c5_i71 +
          4 * c5_i73] * c5_A_R_x[c5_i73 + 4 * c5_i72];
      }
    }
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-71);
  sf_debug_symbol_scope_pop();
}

static const mxArray *c5_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i74;
  real_T c5_b_u[3];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for(c5_i74 = 0; c5_i74 < 3; c5_i74 = c5_i74 + 1) {
    c5_b_u[c5_i74] = (*((real_T (*)[3])c5_u))[c5_i74];
  }
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 1, 3));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_b_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i75;
  int32_T c5_i76;
  real_T c5_b_u[16];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for(c5_i75 = 0; c5_i75 < 4; c5_i75 = c5_i75 + 1) {
    for(c5_i76 = 0; c5_i76 < 4; c5_i76 = c5_i76 + 1) {
      c5_b_u[c5_i76 + 4 * c5_i75] = (*((real_T (*)[16])c5_u))[c5_i76 + 4 *
        c5_i75];
    }
  }
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 2, 4, 4));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_c_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i77;
  real_T c5_b_u[3];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for(c5_i77 = 0; c5_i77 < 3; c5_i77 = c5_i77 + 1) {
    c5_b_u[c5_i77] = (*((real_T (*)[3])c5_u))[c5_i77];
  }
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 1, 3));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_d_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i78;
  int32_T c5_i79;
  real_T c5_b_u[9];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for(c5_i78 = 0; c5_i78 < 3; c5_i78 = c5_i78 + 1) {
    for(c5_i79 = 0; c5_i79 < 3; c5_i79 = c5_i79 + 1) {
      c5_b_u[c5_i79 + 3 * c5_i78] = (*((real_T (*)[9])c5_u))[c5_i79 + 3 *
        c5_i78];
    }
  }
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 2, 3, 3));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_e_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i80;
  int32_T c5_i81;
  real_T c5_b_u[18];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for(c5_i80 = 0; c5_i80 < 3; c5_i80 = c5_i80 + 1) {
    for(c5_i81 = 0; c5_i81 < 6; c5_i81 = c5_i81 + 1) {
      c5_b_u[c5_i81 + 6 * c5_i80] = (*((real_T (*)[18])c5_u))[c5_i81 + 6 *
        c5_i80];
    }
  }
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 2, 6, 3));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_f_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  c5_b_u = *((real_T *)c5_u);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_g_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  c5_b_u = *((real_T *)c5_u);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_h_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i82;
  int32_T c5_i83;
  real_T c5_b_u[16];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for(c5_i82 = 0; c5_i82 < 4; c5_i82 = c5_i82 + 1) {
    for(c5_i83 = 0; c5_i83 < 4; c5_i83 = c5_i83 + 1) {
      c5_b_u[c5_i83 + 4 * c5_i82] = (*((real_T (*)[16])c5_u))[c5_i83 + 4 *
        c5_i82];
    }
  }
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 2, 4, 4));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_i_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i84;
  int32_T c5_i85;
  real_T c5_b_u[16];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for(c5_i84 = 0; c5_i84 < 4; c5_i84 = c5_i84 + 1) {
    for(c5_i85 = 0; c5_i85 < 4; c5_i85 = c5_i85 + 1) {
      c5_b_u[c5_i85 + 4 * c5_i84] = (*((real_T (*)[16])c5_u))[c5_i85 + 4 *
        c5_i84];
    }
  }
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 2, 4, 4));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_j_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i86;
  int32_T c5_i87;
  real_T c5_b_u[16];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for(c5_i86 = 0; c5_i86 < 4; c5_i86 = c5_i86 + 1) {
    for(c5_i87 = 0; c5_i87 < 4; c5_i87 = c5_i87 + 1) {
      c5_b_u[c5_i87 + 4 * c5_i86] = (*((real_T (*)[16])c5_u))[c5_i87 + 4 *
        c5_i86];
    }
  }
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 2, 4, 4));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_k_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i88;
  int32_T c5_i89;
  real_T c5_b_u[16];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for(c5_i88 = 0; c5_i88 < 4; c5_i88 = c5_i88 + 1) {
    for(c5_i89 = 0; c5_i89 < 4; c5_i89 = c5_i89 + 1) {
      c5_b_u[c5_i89 + 4 * c5_i88] = (*((real_T (*)[16])c5_u))[c5_i89 + 4 *
        c5_i88];
    }
  }
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 2, 4, 4));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_l_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i90;
  int32_T c5_i91;
  real_T c5_b_u[16];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for(c5_i90 = 0; c5_i90 < 4; c5_i90 = c5_i90 + 1) {
    for(c5_i91 = 0; c5_i91 < 4; c5_i91 = c5_i91 + 1) {
      c5_b_u[c5_i91 + 4 * c5_i90] = (*((real_T (*)[16])c5_u))[c5_i91 + 4 *
        c5_i90];
    }
  }
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 2, 4, 4));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_m_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i92;
  int32_T c5_i93;
  real_T c5_b_u[16];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for(c5_i92 = 0; c5_i92 < 4; c5_i92 = c5_i92 + 1) {
    for(c5_i93 = 0; c5_i93 < 4; c5_i93 = c5_i93 + 1) {
      c5_b_u[c5_i93 + 4 * c5_i92] = (*((real_T (*)[16])c5_u))[c5_i93 + 4 *
        c5_i92];
    }
  }
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 2, 4, 4));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_n_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i94;
  real_T c5_b_u[3];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for(c5_i94 = 0; c5_i94 < 3; c5_i94 = c5_i94 + 1) {
    c5_b_u[c5_i94] = (*((real_T (*)[3])c5_u))[c5_i94];
  }
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 1, 3));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_o_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i95;
  real_T c5_b_u[3];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for(c5_i95 = 0; c5_i95 < 3; c5_i95 = c5_i95 + 1) {
    c5_b_u[c5_i95] = (*((real_T (*)[3])c5_u))[c5_i95];
  }
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 1, 3));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_p_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i96;
  real_T c5_b_u[3];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for(c5_i96 = 0; c5_i96 < 3; c5_i96 = c5_i96 + 1) {
    c5_b_u[c5_i96] = (*((real_T (*)[3])c5_u))[c5_i96];
  }
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 1, 3));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_q_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i97;
  real_T c5_b_u[3];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for(c5_i97 = 0; c5_i97 < 3; c5_i97 = c5_i97 + 1) {
    c5_b_u[c5_i97] = (*((real_T (*)[3])c5_u))[c5_i97];
  }
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 1, 3));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_r_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i98;
  real_T c5_b_u[3];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for(c5_i98 = 0; c5_i98 < 3; c5_i98 = c5_i98 + 1) {
    c5_b_u[c5_i98] = (*((real_T (*)[3])c5_u))[c5_i98];
  }
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 1, 3));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_s_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i99;
  real_T c5_b_u[3];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for(c5_i99 = 0; c5_i99 < 3; c5_i99 = c5_i99 + 1) {
    c5_b_u[c5_i99] = (*((real_T (*)[3])c5_u))[c5_i99];
  }
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 1, 3));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_t_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i100;
  real_T c5_b_u[3];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for(c5_i100 = 0; c5_i100 < 3; c5_i100 = c5_i100 + 1) {
    c5_b_u[c5_i100] = (*((real_T (*)[3])c5_u))[c5_i100];
  }
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 1, 3));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_u_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i101;
  int32_T c5_i102;
  real_T c5_b_u[16];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for(c5_i101 = 0; c5_i101 < 4; c5_i101 = c5_i101 + 1) {
    for(c5_i102 = 0; c5_i102 < 4; c5_i102 = c5_i102 + 1) {
      c5_b_u[c5_i102 + 4 * c5_i101] = (*((real_T (*)[16])c5_u))[c5_i102 + 4 *
        c5_i101];
    }
  }
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 2, 4, 4));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_v_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  c5_b_u = *((real_T *)c5_u);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_w_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  c5_b_u = *((real_T *)c5_u);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_x_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  c5_b_u = *((real_T *)c5_u);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_y_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  c5_b_u = *((real_T *)c5_u);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_ab_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i103;
  int32_T c5_i104;
  real_T c5_b_u[16];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for(c5_i103 = 0; c5_i103 < 4; c5_i103 = c5_i103 + 1) {
    for(c5_i104 = 0; c5_i104 < 4; c5_i104 = c5_i104 + 1) {
      c5_b_u[c5_i104 + 4 * c5_i103] = (*((real_T (*)[16])c5_u))[c5_i104 + 4 *
        c5_i103];
    }
  }
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 2, 4, 4));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_bb_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i105;
  int32_T c5_i106;
  real_T c5_b_u[16];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for(c5_i105 = 0; c5_i105 < 4; c5_i105 = c5_i105 + 1) {
    for(c5_i106 = 0; c5_i106 < 4; c5_i106 = c5_i106 + 1) {
      c5_b_u[c5_i106 + 4 * c5_i105] = (*((real_T (*)[16])c5_u))[c5_i106 + 4 *
        c5_i105];
    }
  }
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 2, 4, 4));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_cb_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i107;
  int32_T c5_i108;
  real_T c5_b_u[16];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for(c5_i107 = 0; c5_i107 < 4; c5_i107 = c5_i107 + 1) {
    for(c5_i108 = 0; c5_i108 < 4; c5_i108 = c5_i108 + 1) {
      c5_b_u[c5_i108 + 4 * c5_i107] = (*((real_T (*)[16])c5_u))[c5_i108 + 4 *
        c5_i107];
    }
  }
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 2, 4, 4));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_db_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i109;
  int32_T c5_i110;
  real_T c5_b_u[16];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for(c5_i109 = 0; c5_i109 < 4; c5_i109 = c5_i109 + 1) {
    for(c5_i110 = 0; c5_i110 < 4; c5_i110 = c5_i110 + 1) {
      c5_b_u[c5_i110 + 4 * c5_i109] = (*((real_T (*)[16])c5_u))[c5_i110 + 4 *
        c5_i109];
    }
  }
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 2, 4, 4));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_eb_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i111;
  int32_T c5_i112;
  real_T c5_b_u[16];
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  for(c5_i111 = 0; c5_i111 < 4; c5_i111 = c5_i111 + 1) {
    for(c5_i112 = 0; c5_i112 < 4; c5_i112 = c5_i112 + 1) {
      c5_b_u[c5_i112 + 4 * c5_i111] = (*((real_T (*)[16])c5_u))[c5_i112 + 4 *
        c5_i111];
    }
  }
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create(&c5_b_u, "y", 0, 0U, 1U, 2, 4, 4));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

const mxArray *sf_c5_Maze_Omni_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_ResolvedFunctionInfo c5_info[49];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i113;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_info_helper(c5_info);
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 49));
  for(c5_i113 = 0; c5_i113 < 49; c5_i113 = c5_i113 + 1) {
    c5_r0 = &c5_info[c5_i113];
    sf_mex_addfield(c5_m0, sf_mex_create(c5_r0->context, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c5_r0->context)), "context",
     "nameCaptureInfo", c5_i113);
    sf_mex_addfield(c5_m0, sf_mex_create(c5_r0->name, "nameCaptureInfo", 13, 0U,
      0U, 2, 1, strlen(c5_r0->name)), "name",
     "nameCaptureInfo", c5_i113);
    sf_mex_addfield(c5_m0, sf_mex_create(c5_r0->dominantType, "nameCaptureInfo",
      13, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)),
     "dominantType", "nameCaptureInfo", c5_i113);
    sf_mex_addfield(c5_m0, sf_mex_create(c5_r0->resolved, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved",
     "nameCaptureInfo", c5_i113);
    sf_mex_addfield(c5_m0, sf_mex_create(&c5_r0->fileLength, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileLength", "nameCaptureInfo", c5_i113);
    sf_mex_addfield(c5_m0, sf_mex_create(&c5_r0->fileTime1, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c5_i113);
    sf_mex_addfield(c5_m0, sf_mex_create(&c5_r0->fileTime2, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c5_i113);
  }
  sf_mex_assign(&c5_nameCaptureInfo, c5_m0);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[49])
{
  c5_info[0].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c5_info[0].name = "rdivide";
  c5_info[0].dominantType = "double";
  c5_info[0].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[0].fileLength = 4533U;
  c5_info[0].fileTime1 = 1177099748U;
  c5_info[0].fileTime2 = 0U;
  c5_info[1].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c5_info[1].name = "eml_check_dim";
  c5_info[1].dominantType = "double";
  c5_info[1].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c5_info[1].fileLength = 1470U;
  c5_info[1].fileTime1 = 1177099718U;
  c5_info[1].fileTime2 = 0U;
  c5_info[2].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c5_info[2].name = "all";
  c5_info[2].dominantType = "logical";
  c5_info[2].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c5_info[2].fileLength = 2066U;
  c5_info[2].fileTime1 = 1166598650U;
  c5_info[2].fileTime2 = 0U;
  c5_info[3].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c5_info[3].name = "ischar";
  c5_info[3].dominantType = "char";
  c5_info[3].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/strfun/ischar.m";
  c5_info[3].fileLength = 244U;
  c5_info[3].fileTime1 = 1160446834U;
  c5_info[3].fileTime2 = 0U;
  c5_info[4].context = "";
  c5_info[4].name = "uminus";
  c5_info[4].dominantType = "double";
  c5_info[4].resolved = "[B]uminus";
  c5_info[4].fileLength = 0U;
  c5_info[4].fileTime1 = 0U;
  c5_info[4].fileTime2 = 0U;
  c5_info[5].context = "";
  c5_info[5].name = "ctranspose";
  c5_info[5].dominantType = "double";
  c5_info[5].resolved = "[B]ctranspose";
  c5_info[5].fileLength = 0U;
  c5_info[5].fileTime1 = 0U;
  c5_info[5].fileTime2 = 0U;
  c5_info[6].context = "";
  c5_info[6].name = "cos";
  c5_info[6].dominantType = "double";
  c5_info[6].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c5_info[6].fileLength = 772U;
  c5_info[6].fileTime1 = 1163970724U;
  c5_info[6].fileTime2 = 0U;
  c5_info[7].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c5_info[7].name = "floor";
  c5_info[7].dominantType = "double";
  c5_info[7].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c5_info[7].fileLength = 595U;
  c5_info[7].fileTime1 = 1163970736U;
  c5_info[7].fileTime2 = 0U;
  c5_info[8].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c5_info[8].name = "isscalar";
  c5_info[8].dominantType = "double";
  c5_info[8].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isscalar.m";
  c5_info[8].fileLength = 243U;
  c5_info[8].fileTime1 = 1160446704U;
  c5_info[8].fileTime2 = 0U;
  c5_info[9].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c5_info[9].name = "not";
  c5_info[9].dominantType = "logical";
  c5_info[9].resolved = "[B]not";
  c5_info[9].fileLength = 0U;
  c5_info[9].fileTime1 = 0U;
  c5_info[9].fileTime2 = 0U;
  c5_info[10].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c5_info[10].name = "eq";
  c5_info[10].dominantType = "double";
  c5_info[10].resolved = "[B]eq";
  c5_info[10].fileLength = 0U;
  c5_info[10].fileTime1 = 0U;
  c5_info[10].fileTime2 = 0U;
  c5_info[11].context = "";
  c5_info[11].name = "sin";
  c5_info[11].dominantType = "double";
  c5_info[11].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c5_info[11].fileLength = 769U;
  c5_info[11].fileTime1 = 1163970754U;
  c5_info[11].fileTime2 = 0U;
  c5_info[12].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c5_info[12].name = "islogical";
  c5_info[12].dominantType = "logical";
  c5_info[12].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/islogical.m";
  c5_info[12].fileLength = 186U;
  c5_info[12].fileTime1 = 1160446622U;
  c5_info[12].fileTime2 = 0U;
  c5_info[13].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c5_info[13].name = "ge";
  c5_info[13].dominantType = "double";
  c5_info[13].resolved = "[B]ge";
  c5_info[13].fileLength = 0U;
  c5_info[13].fileTime1 = 0U;
  c5_info[13].fileTime2 = 0U;
  c5_info[14].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c5_info[14].name = "size";
  c5_info[14].dominantType = "double";
  c5_info[14].resolved = "[B]size";
  c5_info[14].fileLength = 0U;
  c5_info[14].fileTime1 = 0U;
  c5_info[14].fileTime2 = 0U;
  c5_info[15].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c5_info[15].name = "intmax";
  c5_info[15].dominantType = "char";
  c5_info[15].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c5_info[15].fileLength = 1575U;
  c5_info[15].fileTime1 = 1160446696U;
  c5_info[15].fileTime2 = 0U;
  c5_info[16].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c5_info[16].name = "isempty";
  c5_info[16].dominantType = "logical";
  c5_info[16].resolved = "[B]isempty";
  c5_info[16].fileLength = 0U;
  c5_info[16].fileTime1 = 0U;
  c5_info[16].fileTime2 = 0U;
  c5_info[17].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c5_info[17].name = "int32";
  c5_info[17].dominantType = "double";
  c5_info[17].resolved = "[B]int32";
  c5_info[17].fileLength = 0U;
  c5_info[17].fileTime1 = 0U;
  c5_info[17].fileTime2 = 0U;
  c5_info[18].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c5_info[18].name = "eml_nonsingleton_dim";
  c5_info[18].dominantType = "logical";
  c5_info[18].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m";
  c5_info[18].fileLength = 454U;
  c5_info[18].fileTime1 = 1160446750U;
  c5_info[18].fileTime2 = 0U;
  c5_info[19].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c5_info[19].name = "nargin";
  c5_info[19].dominantType = "";
  c5_info[19].resolved = "[B]nargin";
  c5_info[19].fileLength = 0U;
  c5_info[19].fileTime1 = 0U;
  c5_info[19].fileTime2 = 0U;
  c5_info[20].context = "";
  c5_info[20].name = "cross";
  c5_info[20].dominantType = "double";
  c5_info[20].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c5_info[20].fileLength = 2893U;
  c5_info[20].fileTime1 = 1163970838U;
  c5_info[20].fileTime2 = 0U;
  c5_info[21].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c5_info[21].name = "strcmp";
  c5_info[21].dominantType = "char";
  c5_info[21].resolved = "[B]strcmp";
  c5_info[21].fileLength = 0U;
  c5_info[21].fileTime1 = 0U;
  c5_info[21].fileTime2 = 0U;
  c5_info[22].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c5_info[22].name = "le";
  c5_info[22].dominantType = "int32";
  c5_info[22].resolved = "[B]le";
  c5_info[22].fileLength = 0U;
  c5_info[22].fileTime1 = 0U;
  c5_info[22].fileTime2 = 0U;
  c5_info[23].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[23].name = "isnumeric";
  c5_info[23].dominantType = "double";
  c5_info[23].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isnumeric.m";
  c5_info[23].fileLength = 250U;
  c5_info[23].fileTime1 = 1160446622U;
  c5_info[23].fileTime2 = 0U;
  c5_info[24].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[24].name = "isreal";
  c5_info[24].dominantType = "double";
  c5_info[24].resolved = "[B]isreal";
  c5_info[24].fileLength = 0U;
  c5_info[24].fileTime1 = 0U;
  c5_info[24].fileTime2 = 0U;
  c5_info[25].context = "";
  c5_info[25].name = "pi";
  c5_info[25].dominantType = "";
  c5_info[25].resolved = "[B]pi";
  c5_info[25].fileLength = 0U;
  c5_info[25].fileTime1 = 0U;
  c5_info[25].fileTime2 = 0U;
  c5_info[26].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m";
  c5_info[26].name = "ne";
  c5_info[26].dominantType = "double";
  c5_info[26].resolved = "[B]ne";
  c5_info[26].fileLength = 0U;
  c5_info[26].fileTime1 = 0U;
  c5_info[26].fileTime2 = 0U;
  c5_info[27].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c5_info[27].name = "isfloat";
  c5_info[27].dominantType = "double";
  c5_info[27].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isfloat.m";
  c5_info[27].fileLength = 182U;
  c5_info[27].fileTime1 = 1160446620U;
  c5_info[27].fileTime2 = 0U;
  c5_info[28].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c5_info[28].name = "isvector";
  c5_info[28].dominantType = "double";
  c5_info[28].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isvector.m";
  c5_info[28].fileLength = 284U;
  c5_info[28].fileTime1 = 1160446706U;
  c5_info[28].fileTime2 = 0U;
  c5_info[29].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c5_info[29].name = "lt";
  c5_info[29].dominantType = "double";
  c5_info[29].resolved = "[B]lt";
  c5_info[29].fileLength = 0U;
  c5_info[29].fileTime1 = 0U;
  c5_info[29].fileTime2 = 0U;
  c5_info[30].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isnumeric.m";
  c5_info[30].name = "isa";
  c5_info[30].dominantType = "double";
  c5_info[30].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c5_info[30].fileLength = 791U;
  c5_info[30].fileTime1 = 1160446618U;
  c5_info[30].fileTime2 = 0U;
  c5_info[31].context = "";
  c5_info[31].name = "mtimes";
  c5_info[31].dominantType = "double";
  c5_info[31].resolved = "[B]mtimes";
  c5_info[31].fileLength = 0U;
  c5_info[31].fileTime1 = 0U;
  c5_info[31].fileTime2 = 0U;
  c5_info[32].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[32].name = "isinteger";
  c5_info[32].dominantType = "double";
  c5_info[32].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isinteger.m";
  c5_info[32].fileLength = 254U;
  c5_info[32].fileTime1 = 1160446620U;
  c5_info[32].fileTime2 = 0U;
  c5_info[33].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isscalar.m";
  c5_info[33].name = "gt";
  c5_info[33].dominantType = "double";
  c5_info[33].resolved = "[B]gt";
  c5_info[33].fileLength = 0U;
  c5_info[33].fileTime1 = 0U;
  c5_info[33].fileTime2 = 0U;
  c5_info[34].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c5_info[34].name = "class";
  c5_info[34].dominantType = "char";
  c5_info[34].resolved = "[B]class";
  c5_info[34].fileLength = 0U;
  c5_info[34].fileTime1 = 0U;
  c5_info[34].fileTime2 = 0U;
  c5_info[35].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c5_info[35].name = "true";
  c5_info[35].dominantType = "";
  c5_info[35].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c5_info[35].fileLength = 625U;
  c5_info[35].fileTime1 = 1163970786U;
  c5_info[35].fileTime2 = 0U;
  c5_info[36].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c5_info[36].name = "eml_is_float_class";
  c5_info[36].dominantType = "char";
  c5_info[36].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c5_info[36].fileLength = 273U;
  c5_info[36].fileTime1 = 1160446744U;
  c5_info[36].fileTime2 = 0U;
  c5_info[37].context = "";
  c5_info[37].name = "mrdivide";
  c5_info[37].dominantType = "double";
  c5_info[37].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c5_info[37].fileLength = 653U;
  c5_info[37].fileTime1 = 1160446802U;
  c5_info[37].fileTime2 = 0U;
  c5_info[38].context = "";
  c5_info[38].name = "minus";
  c5_info[38].dominantType = "double";
  c5_info[38].resolved = "[B]minus";
  c5_info[38].fileLength = 0U;
  c5_info[38].fileTime1 = 0U;
  c5_info[38].fileTime2 = 0U;
  c5_info[39].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c5_info[39].name = "eml_index_class";
  c5_info[39].dominantType = "";
  c5_info[39].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[39].fileLength = 953U;
  c5_info[39].fileTime1 = 1160446742U;
  c5_info[39].fileTime2 = 0U;
  c5_info[40].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c5_info[40].name = "logical";
  c5_info[40].dominantType = "double";
  c5_info[40].resolved = "[B]logical";
  c5_info[40].fileLength = 0U;
  c5_info[40].fileTime1 = 0U;
  c5_info[40].fileTime2 = 0U;
  c5_info[41].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_check_dim.m";
  c5_info[41].name = "nargout";
  c5_info[41].dominantType = "";
  c5_info[41].resolved = "[B]nargout";
  c5_info[41].fileLength = 0U;
  c5_info[41].fileTime1 = 0U;
  c5_info[41].fileTime2 = 0U;
  c5_info[42].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c5_info[42].name = "false";
  c5_info[42].dominantType = "";
  c5_info[42].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c5_info[42].fileLength = 631U;
  c5_info[42].fileTime1 = 1163970766U;
  c5_info[42].fileTime2 = 0U;
  c5_info[43].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c5_info[43].name = "eml_numel";
  c5_info[43].dominantType = "double";
  c5_info[43].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_numel.m";
  c5_info[43].fileLength = 278U;
  c5_info[43].fileTime1 = 1163970802U;
  c5_info[43].fileTime2 = 0U;
  c5_info[44].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_numel.m";
  c5_info[44].name = "numel";
  c5_info[44].dominantType = "double";
  c5_info[44].resolved = "[B]numel";
  c5_info[44].fileLength = 0U;
  c5_info[44].fileTime1 = 0U;
  c5_info[44].fileTime2 = 0U;
  c5_info[45].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c5_info[45].name = "ndims";
  c5_info[45].dominantType = "double";
  c5_info[45].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/ndims.m";
  c5_info[45].fileLength = 236U;
  c5_info[45].fileTime1 = 1163970776U;
  c5_info[45].fileTime2 = 0U;
  c5_info[46].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c5_info[46].name = "eml_is_integer_class";
  c5_info[46].dominantType = "char";
  c5_info[46].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m";
  c5_info[46].fileLength = 462U;
  c5_info[46].fileTime1 = 1160446744U;
  c5_info[46].fileTime2 = 0U;
  c5_info[47].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c5_info[47].name = "eml_assert";
  c5_info[47].dominantType = "char";
  c5_info[47].resolved = "[B]eml_assert";
  c5_info[47].fileLength = 0U;
  c5_info[47].fileTime1 = 0U;
  c5_info[47].fileTime2 = 0U;
  c5_info[48].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isscalar.m";
  c5_info[48].name = "length";
  c5_info[48].dominantType = "double";
  c5_info[48].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c5_info[48].fileLength = 347U;
  c5_info[48].fileTime1 = 1163970770U;
  c5_info[48].fileTime2 = 0U;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c5_Maze_Omni_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2506065470U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3840263923U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2708411733U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3364613131U);
}

mxArray *sf_c5_Maze_Omni_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3136776785U);
    pr[1] = (double)(485951302U);
    pr[2] = (double)(3370327567U);
    pr[3] = (double)(1557467889U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);
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
      pr[0] = (double)(4);
      pr[1] = (double)(4);
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
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
      pr[0] = (double)(6);
      pr[1] = (double)(3);
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
        chartAlreadyPresent = sf_debug_initialize_chart(_Maze_OmniMachineNumber_,
         5,
         1,
         1,
         5,
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
            _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,1.0,0,"pos",0,c5_c_sf_marshall);
          }
          {
            unsigned int dimVector[1];
            dimVector[0]= 3;
            _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,1.0,0,"q",0,c5_sf_marshall);
          }
          {
            unsigned int dimVector[2];
            dimVector[0]= 3;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,1.0,0,"Rot",0,c5_d_sf_marshall);
          }
          {
            unsigned int dimVector[2];
            dimVector[0]= 4;
            dimVector[1]= 4;
            _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,1.0,0,"tool_offset",0,c5_b_sf_marshall);
          }
          {
            unsigned int dimVector[2];
            dimVector[0]= 6;
            dimVector[1]= 3;
            _SFD_SET_DATA_PROPS(3,2,0,1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,1.0,0,"Jac",0,c5_e_sf_marshall);
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
        _SFD_CV_INIT_EML(0,2,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,882);
        _SFD_CV_INIT_EML_FCN(0,1,"DH",884,-1,1362);
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
          real_T (*c5_pos)[3];
          real_T (*c5_q)[3];
          real_T (*c5_Rot)[9];
          real_T (*c5_tool_offset)[16];
          real_T (*c5_Jac)[18];
          c5_Rot = (real_T (*)[9])ssGetOutputPortSignal(chartInstance.S, 2);
          c5_pos = (real_T (*)[3])ssGetOutputPortSignal(chartInstance.S, 1);
          c5_Jac = (real_T (*)[18])ssGetOutputPortSignal(chartInstance.S, 3);
          c5_q = (real_T (*)[3])ssGetInputPortSignal(chartInstance.S, 0);
          c5_tool_offset = (real_T (*)[16])ssGetInputPortSignal(chartInstance.S,
           1);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_pos);
          _SFD_SET_DATA_VALUE_PTR(4U, c5_q);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_Rot);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_tool_offset);
          _SFD_SET_DATA_VALUE_PTR(3U, c5_Jac);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_Maze_OmniMachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c5_Maze_Omni(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c5_Maze_Omni();
  initialize_c5_Maze_Omni();
}

static void sf_opaque_enable_c5_Maze_Omni(void *chartInstanceVar)
{
  enable_c5_Maze_Omni();
}

static void sf_opaque_disable_c5_Maze_Omni(void *chartInstanceVar)
{
  disable_c5_Maze_Omni();
}

static void sf_opaque_gateway_c5_Maze_Omni(void *chartInstanceVar)
{
  sf_c5_Maze_Omni();
}

static void sf_opaque_ext_mode_exec_c5_Maze_Omni(void *chartInstanceVar)
{
  ext_mode_exec_c5_Maze_Omni();
}

static void sf_opaque_terminate_c5_Maze_Omni(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) ||
   sim_mode_is_external(chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }
  finalize_c5_Maze_Omni();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_Maze_Omni(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  if(sf_machine_global_initializer_called()) {
    initialize_params_c5_Maze_Omni();
  }
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  char *dworkEncStr =
  "100 S1x2'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}";
  sf_set_encoded_dwork_info(S, dworkEncStr);
}

static void mdlSetWorkWidths_c5_Maze_Omni(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("Maze_Omni",5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("Maze_Omni",5,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"Maze_Omni",5,2);
      sf_mark_chart_reusable_outputs(S,"Maze_Omni",5,3);
    }
    sf_set_rtw_dwork_info(S,"Maze_Omni",5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetChecksum0(S,(4140743614U));
  ssSetChecksum1(S,(1371884172U));
  ssSetChecksum2(S,(4290802150U));
  ssSetChecksum3(S,(2197096048U));

  ssSetmdlDerivatives(S, NULL);

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c5_Maze_Omni(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Maze_Omni", 5);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_Maze_Omni(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway = sf_opaque_gateway_c5_Maze_Omni;
  chartInstance.chartInfo.initializeChart = sf_opaque_initialize_c5_Maze_Omni;
  chartInstance.chartInfo.terminateChart = sf_opaque_terminate_c5_Maze_Omni;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c5_Maze_Omni;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c5_Maze_Omni;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c5_Maze_Omni;
  chartInstance.chartInfo.mdlStart = mdlStart_c5_Maze_Omni;
  chartInstance.chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_Maze_Omni;
  chartInstance.chartInfo.extModeExec = sf_opaque_ext_mode_exec_c5_Maze_Omni;
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

void c5_Maze_Omni_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_Maze_Omni(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_Maze_Omni(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_Maze_Omni(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c5_Maze_Omni_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

