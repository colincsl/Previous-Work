/*
 * Mechanics_private.h
 *
 * Real-Time Workshop code generation for Simulink model "Mechanics.mdl".
 *
 * Model Version              : 1.52
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Thu Aug 27 15:50:26 2009
 */
#ifndef RTW_HEADER_Mechanics_private_h_
#define RTW_HEADER_Mechanics_private_h_
#include "rtwtypes.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   /* do nothing */
# else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

#include "mech_std.h"
#include "mtypes.h"
#include "simulation_data.h"
#include "mech_method_table.h"
#include "rt_mechanism.h"
#include "sim_mechanics_imports.h"

/*
 * simulation data structure for SimMechanics, one for each SFunction
 */
typedef struct {
  Mechanism *mechanism;
  SimulationDataGeneral genSimData;
  SimulationDataOutputs outSimData;
} _rtMech_PWORK;

/* private model entry point functions */
extern void Mechanics_derivatives(void);
extern void QueryInstrument(SimStruct *rts);

#endif                                 /* RTW_HEADER_Mechanics_private_h_ */
