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
 *     Mechanics/Ground
 */
typedef struct {
    /*
     * run-time parameters for block:
     *     Mechanics/Body
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
     *     Mechanics/Body1
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
     *     Mechanics/Body2
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
    } Body2;
    /*
     * run-time parameters for block:
     *     Mechanics/Body3
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
    } Body3;
    /*
     * run-time parameters for block:
     *     Mechanics/Body4
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
    } Body4;
    /*
     * run-time parameters for block:
     *     Mechanics/Body5
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
    } Body5;
    /*
     * run-time parameters for block:
     *     Mechanics/Ground
     */
    struct {
        real_T    CoordPosition[3];
    } Ground;
    /*
     * run-time parameters for block:
     *     Mechanics/Ground1
     */
    struct {
        real_T    CoordPosition[3];
    } Ground1;
    /*
     * run-time parameters for block:
     *     Mechanics/Revolute
     */
    struct {
        real_T    R1Axis[3];
    } Revolute;
    /*
     * run-time parameters for block:
     *     Mechanics/Revolute1
     */
    struct {
        real_T    R1Axis[3];
    } Revolute1;
    /*
     * run-time parameters for block:
     *     Mechanics/Revolute2
     */
    struct {
        real_T    R1Axis[3];
    } Revolute2;
    /*
     * run-time parameters for block:
     *     Mechanics/Revolute3
     */
    struct {
        real_T    R1Axis[3];
    } Revolute3;
    /*
     * run-time parameters for block:
     *     Mechanics/Revolute4
     */
    struct {
        real_T    R1Axis[3];
    } Revolute4;
    /*
     * run-time parameters for block:
     *     Mechanics/Revolute5
     */
    struct {
        real_T    R1Axis[3];
    } Revolute5;
    /*
     * run-time parameters for block:
     *     Mechanics/Revolute6
     */
    struct {
        real_T    R1Axis[3];
    } Revolute6;
    /*
     * run-time parameters for block:
     *     Mechanics/Revolute7
     */
    struct {
        real_T    R1Axis[3];
    } Revolute7;
} MachineParameters_Mechanics_c90d139d;
extern void rt_vector_to_machine_parameters_Mechanics_c90d139d(const real_T *, MachineParameters_Mechanics_c90d139d *);
extern void rt_machine_parameters_to_vector_Mechanics_c90d139d(const MachineParameters_Mechanics_c90d139d *, real_T *);


#endif /* rt_mechanism_data_h */
/* [EOF] rt_mechanism_data.h */
