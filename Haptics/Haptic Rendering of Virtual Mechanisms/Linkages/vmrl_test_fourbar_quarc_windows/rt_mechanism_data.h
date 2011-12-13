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
 *     vmrl_test_fourbar/Ground
 */
typedef struct {
    /*
     * run-time parameters for block:
     *     vmrl_test_fourbar/Body
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
        real_T    Inertia[9];
        real_T    Mass;
    } Body;
    /*
     * run-time parameters for block:
     *     vmrl_test_fourbar/Body1
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
     *     vmrl_test_fourbar/Body2
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
        real_T    Inertia[9];
        real_T    Mass;
    } Body2;
    /*
     * run-time parameters for block:
     *     vmrl_test_fourbar/Body3
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
        real_T    Inertia[9];
        real_T    Mass;
    } Body3;
    /*
     * run-time parameters for block:
     *     vmrl_test_fourbar/Body4
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
        real_T    Inertia[9];
        real_T    Mass;
    } Body4;
    /*
     * run-time parameters for block:
     *     vmrl_test_fourbar/Ground
     */
    struct {
        real_T    CoordPosition[3];
    } Ground;
    /*
     * run-time parameters for block:
     *     vmrl_test_fourbar/Ground2
     */
    struct {
        real_T    CoordPosition[3];
    } Ground2;
    /*
     * run-time parameters for block:
     *     vmrl_test_fourbar/Revolute
     */
    struct {
        real_T    R1Axis[3];
    } Revolute;
    /*
     * run-time parameters for block:
     *     vmrl_test_fourbar/Revolute1
     */
    struct {
        real_T    R1Axis[3];
    } Revolute1;
    /*
     * run-time parameters for block:
     *     vmrl_test_fourbar/Revolute2
     */
    struct {
        real_T    R1Axis[3];
    } Revolute2;
    /*
     * run-time parameters for block:
     *     vmrl_test_fourbar/Revolute3
     */
    struct {
        real_T    R1Axis[3];
    } Revolute3;
    /*
     * run-time parameters for block:
     *     vmrl_test_fourbar/Weld
     */
    struct {
        real_T    WAxis[3];
    } Weld;
    /*
     * run-time parameters for block:
     *     vmrl_test_fourbar/Weld1
     */
    struct {
        real_T    WAxis[3];
    } Weld1;
} MachineParameters_vmrl_test_fourbar_1d6fdf5b;
extern void rt_vector_to_machine_parameters_vmrl_test_fourbar_1d6fdf5b(const real_T *, MachineParameters_vmrl_test_fourbar_1d6fdf5b *);
extern void rt_machine_parameters_to_vector_vmrl_test_fourbar_1d6fdf5b(const MachineParameters_vmrl_test_fourbar_1d6fdf5b *, real_T *);


#endif /* rt_mechanism_data_h */
/* [EOF] rt_mechanism_data.h */
