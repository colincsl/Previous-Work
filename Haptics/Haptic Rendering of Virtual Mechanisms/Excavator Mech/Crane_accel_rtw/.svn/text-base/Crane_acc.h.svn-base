/*
 * Crane_acc.h
 *
 * Real-Time Workshop code generation for Simulink model "Crane_acc.mdl".
 *
 * Model Version              : 1.32
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Tue Jun 02 13:39:54 2009
 */
#ifndef RTW_HEADER_Crane_acc_h_
#define RTW_HEADER_Crane_acc_h_
#ifndef Crane_acc_COMMON_INCLUDES_
# define Crane_acc_COMMON_INCLUDES_
#include <math.h>
#include <stdlib.h>
#define S_FUNCTION_NAME                simulink_only_sfcn
#define S_FUNCTION_LEVEL               2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#endif                                 /* Crane_acc_COMMON_INCLUDES_ */

#include "Crane_acc_types.h"

/* Block signals (auto storage) */
typedef struct {
  real_T B_0_3_0;                      /* '<Root>/Gain' */
  real_T B_0_4_0[14];                  /* '<S5>/Block#1' */
  real_T B_0_4_1;                      /* '<S5>/Block#1' */
  real_T B_0_6_0[3];                   /* '<S5>/_gravity_conversion' */
  real_T B_0_7_0;                      /* '<S5>/Block#2' */
  real_T B_0_8_0;                      /* '<S5>/Block#3' */
} BlockIO;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  void *Block1_PWORK;                  /* '<S5>/Block#1' */
  void *Block2_PWORK;                  /* '<S5>/Block#2' */
  void *Block3_PWORK;                  /* '<S5>/Block#3' */
  int_T Block1_IWORK;                  /* '<S5>/Block#1' */
  int_T Block3_IWORK;                  /* '<S5>/Block#3' */
  char pad_Block3_IWORK[4];
} D_Work;

/* Continuous states (auto storage) */
typedef struct {
  real_T Block1_CSTATE[14];            /* '<S5>/Block#1' */
} ContinuousStates;

/* State derivatives (auto storage) */
typedef struct {
  real_T Block1_CSTATE[14];            /* '<S5>/Block#1' */
} StateDerivatives;

/* State disabled  */
typedef struct {
  boolean_T Block1_CSTATE[14];         /* '<S5>/Block#1' */
} StateDisabled;

/* Parameters (auto storage) */
struct Parameters {
  real_T P_0;                          /* Expression: 1
                                        * '<Root>/Sine Wave'
                                        */
  real_T P_1;                          /* Expression: 0
                                        * '<Root>/Sine Wave'
                                        */
  real_T P_2;                          /* Expression: 1
                                        * '<Root>/Sine Wave'
                                        */
  real_T P_3;                          /* Expression: 0
                                        * '<Root>/Sine Wave'
                                        */
  real_T P_4;                          /* Expression: 1000
                                        * '<Root>/Gain'
                                        */
  real_T P_5[2];                       /* Computed Parameter: SimMechanicsRuntimeParametersSize
                                        * '<S5>/Block#1'
                                        */
  real_T P_6[361];                     /* Computed Parameter: SimMechanicsRuntimeParameters
                                        * '<S5>/Block#1'
                                        */
  real_T P_7[3];                       /* Expression: Gravity
                                        * '<S4>/SOURCE_BLOCK'
                                        */
  real_T P_8;                          /* Expression: -1
                                        * '<S5>/_gravity_conversion'
                                        */
};

extern Parameters rtDefaultParameters; /* parameters */

#endif                                 /* RTW_HEADER_Crane_acc_h_ */
