/* SimMechanics target specific file
 *      This file generated a part of SimMechanics code generation.
 */
#include "tmwtypes.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mtypes.h"
#include "simulation_data.h"
#include "sim_mechanics_imports.h"
#ifndef rt_mechanism_data_h
#define rt_mechanism_data_h
/*
 * SimMechanics run-time data structure for machine:
 *     double_w_haptics/Ground
 */
typedef struct {
    /*
     * run-time parameters for block:
     *     double_w_haptics/Body
     */
    struct {
        real_T    CGPos[3];
        real_T    CGRot[3];
        real_T    CS1Pos[3];
        real_T    CS1Rot[3];
        real_T    CS2Pos[3];
        real_T    CS2Rot[3];
        real_T    Inertia[9];
        real_T    Mass;
    } Body;
    /*
     * run-time parameters for block:
     *     double_w_haptics/Body1
     */
    struct {
        real_T    CGPos[3];
        real_T    CGRot[3];
        real_T    CS1Pos[3];
        real_T    CS1Rot[3];
        real_T    CS2Pos[3];
        real_T    CS2Rot[3];
        real_T    CS3Pos[3];
        real_T    CS3Rot[3];
        real_T    CS4Pos[3];
        real_T    CS4Rot[3];
        real_T    Inertia[9];
        real_T    Mass;
    } Body1;
    /*
     * run-time parameters for block:
     *     double_w_haptics/Ground
     */
    struct {
        real_T    CoordPosition[3];
    } Ground;
    /*
     * run-time parameters for block:
     *     double_w_haptics/Revolute1
     */
    struct {
        real_T    R1Axis[3];
    } Revolute1;
    /*
     * run-time parameters for block:
     *     double_w_haptics/Revolute3
     */
    struct {
        real_T    R1Axis[3];
    } Revolute3;
} MachineParameters_double_w_haptics_1460d8f1;
extern void rt_vector_to_machine_parameters_double_w_haptics_1460d8f1(const real_T *, MachineParameters_double_w_haptics_1460d8f1 *);
extern void rt_machine_parameters_to_vector_double_w_haptics_1460d8f1(const MachineParameters_double_w_haptics_1460d8f1 *, real_T *);


#endif /* rt_mechanism_data_h */
/* [EOF] rt_mechanism_data.h */
