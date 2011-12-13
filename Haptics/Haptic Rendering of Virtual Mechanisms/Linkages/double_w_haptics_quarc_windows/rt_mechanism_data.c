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
#include "rt_mechanism_data.h"
/*
 * Convert runtime parameter vector for machine to structure
 */
void rt_vector_to_machine_parameters_double_w_haptics_1460d8f1(const real_T *_mech_rtP, MachineParameters_double_w_haptics_1460d8f1 *_mech_rtS)
{
    /*
     * get runtime parameters for block:
     *     double_w_haptics/Body
     */
    memcpy(_mech_rtS->Body.CGPos, _mech_rtP + 3, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body.CGRot, _mech_rtP + 6, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body.CS1Pos, _mech_rtP + 19, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body.CS1Rot, _mech_rtP + 22, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body.CS2Pos, _mech_rtP + 25, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body.CS2Rot, _mech_rtP + 28, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body.Inertia, _mech_rtP + 9, sizeof(real_T) * 9);
    _mech_rtS->Body.Mass = _mech_rtP[18];
    /*
     * get runtime parameters for block:
     *     double_w_haptics/Body1
     */
    memcpy(_mech_rtS->Body1.CGPos, _mech_rtP + 37, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body1.CGRot, _mech_rtP + 40, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body1.CS1Pos, _mech_rtP + 53, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body1.CS1Rot, _mech_rtP + 56, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body1.CS2Pos, _mech_rtP + 59, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body1.CS2Rot, _mech_rtP + 62, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body1.CS3Pos, _mech_rtP + 65, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body1.CS3Rot, _mech_rtP + 68, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body1.CS4Pos, _mech_rtP + 71, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body1.CS4Rot, _mech_rtP + 74, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body1.Inertia, _mech_rtP + 43, sizeof(real_T) * 9);
    _mech_rtS->Body1.Mass = _mech_rtP[52];
    /*
     * get runtime parameters for block:
     *     double_w_haptics/Ground
     */
    memcpy(_mech_rtS->Ground.CoordPosition, _mech_rtP + 34, sizeof(real_T) * 3);
    /*
     * get runtime parameters for block:
     *     double_w_haptics/Revolute1
     */
    memcpy(_mech_rtS->Revolute1.R1Axis, _mech_rtP + 31, sizeof(real_T) * 3);
    /*
     * get runtime parameters for block:
     *     double_w_haptics/Revolute3
     */
    memcpy(_mech_rtS->Revolute3.R1Axis, _mech_rtP + 0, sizeof(real_T) * 3);
}

/*
 * Convert structure for machine to runtime parameter vector
 */
void rt_machine_parameters_to_vector_double_w_haptics_1460d8f1(const MachineParameters_double_w_haptics_1460d8f1 *_mech_rtS, real_T *_mech_rtP)
{
    /*
     * arrange runtime parameters for block:
     *     double_w_haptics/Body
     */
    memcpy(_mech_rtP + 3, _mech_rtS->Body.CGPos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 6, _mech_rtS->Body.CGRot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 19, _mech_rtS->Body.CS1Pos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 22, _mech_rtS->Body.CS1Rot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 25, _mech_rtS->Body.CS2Pos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 28, _mech_rtS->Body.CS2Rot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 9, _mech_rtS->Body.Inertia, sizeof(real_T) * 9);
    _mech_rtP[18] = _mech_rtS->Body.Mass;
    /*
     * arrange runtime parameters for block:
     *     double_w_haptics/Body1
     */
    memcpy(_mech_rtP + 37, _mech_rtS->Body1.CGPos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 40, _mech_rtS->Body1.CGRot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 53, _mech_rtS->Body1.CS1Pos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 56, _mech_rtS->Body1.CS1Rot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 59, _mech_rtS->Body1.CS2Pos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 62, _mech_rtS->Body1.CS2Rot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 65, _mech_rtS->Body1.CS3Pos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 68, _mech_rtS->Body1.CS3Rot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 71, _mech_rtS->Body1.CS4Pos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 74, _mech_rtS->Body1.CS4Rot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 43, _mech_rtS->Body1.Inertia, sizeof(real_T) * 9);
    _mech_rtP[52] = _mech_rtS->Body1.Mass;
    /*
     * arrange runtime parameters for block:
     *     double_w_haptics/Ground
     */
    memcpy(_mech_rtP + 34, _mech_rtS->Ground.CoordPosition, sizeof(real_T) * 3);
    /*
     * arrange runtime parameters for block:
     *     double_w_haptics/Revolute1
     */
    memcpy(_mech_rtP + 31, _mech_rtS->Revolute1.R1Axis, sizeof(real_T) * 3);
    /*
     * arrange runtime parameters for block:
     *     double_w_haptics/Revolute3
     */
    memcpy(_mech_rtP + 0, _mech_rtS->Revolute3.R1Axis, sizeof(real_T) * 3);
}

/* [EOF] rt_mechanism_data.c */
