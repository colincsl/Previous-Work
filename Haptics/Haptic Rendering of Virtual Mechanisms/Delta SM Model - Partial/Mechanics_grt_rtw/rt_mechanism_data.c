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
void rt_vector_to_machine_parameters_Mechanics_c90d139d(const real_T *_mech_rtP, MachineParameters_Mechanics_c90d139d *_mech_rtS)
{
    /*
     * get runtime parameters for block:
     *     Mechanics/Body
     */
    memcpy(_mech_rtS->Body.CGPos, _mech_rtP + 182, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body.CGRot, _mech_rtP + 185, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body.CS1Pos, _mech_rtP + 198, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body.CS1Rot, _mech_rtP + 201, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body.CS2Pos, _mech_rtP + 204, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body.CS2Rot, _mech_rtP + 207, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body.Inertia, _mech_rtP + 188, sizeof(real_T) * 9);
    _mech_rtS->Body.Mass = _mech_rtP[197];
    /*
     * get runtime parameters for block:
     *     Mechanics/Body1
     */
    memcpy(_mech_rtS->Body1.CGPos, _mech_rtP + 71, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body1.CGRot, _mech_rtP + 74, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body1.CS1Pos, _mech_rtP + 99, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body1.CS1Rot, _mech_rtP + 102, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body1.CS2Pos, _mech_rtP + 105, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body1.CS2Rot, _mech_rtP + 108, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body1.CS3Pos, _mech_rtP + 93, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body1.CS3Rot, _mech_rtP + 96, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body1.CS4Pos, _mech_rtP + 87, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body1.CS4Rot, _mech_rtP + 90, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body1.Inertia, _mech_rtP + 77, sizeof(real_T) * 9);
    _mech_rtS->Body1.Mass = _mech_rtP[86];
    /*
     * get runtime parameters for block:
     *     Mechanics/Body2
     */
    memcpy(_mech_rtS->Body2.CGPos, _mech_rtP + 114, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body2.CGRot, _mech_rtP + 117, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body2.CS1Pos, _mech_rtP + 130, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body2.CS1Rot, _mech_rtP + 133, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body2.CS2Pos, _mech_rtP + 136, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body2.CS2Rot, _mech_rtP + 139, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body2.Inertia, _mech_rtP + 120, sizeof(real_T) * 9);
    _mech_rtS->Body2.Mass = _mech_rtP[129];
    /*
     * get runtime parameters for block:
     *     Mechanics/Body3
     */
    memcpy(_mech_rtS->Body3.CGPos, _mech_rtP + 40, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body3.CGRot, _mech_rtP + 43, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body3.CS1Pos, _mech_rtP + 56, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body3.CS1Rot, _mech_rtP + 59, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body3.CS2Pos, _mech_rtP + 62, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body3.CS2Rot, _mech_rtP + 65, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body3.Inertia, _mech_rtP + 46, sizeof(real_T) * 9);
    _mech_rtS->Body3.Mass = _mech_rtP[55];
    /*
     * get runtime parameters for block:
     *     Mechanics/Body4
     */
    memcpy(_mech_rtS->Body4.CGPos, _mech_rtP + 151, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body4.CGRot, _mech_rtP + 154, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body4.CS1Pos, _mech_rtP + 167, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body4.CS1Rot, _mech_rtP + 170, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body4.CS2Pos, _mech_rtP + 173, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body4.CS2Rot, _mech_rtP + 176, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body4.Inertia, _mech_rtP + 157, sizeof(real_T) * 9);
    _mech_rtS->Body4.Mass = _mech_rtP[166];
    /*
     * get runtime parameters for block:
     *     Mechanics/Body5
     */
    memcpy(_mech_rtS->Body5.CGPos, _mech_rtP + 3, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body5.CGRot, _mech_rtP + 6, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body5.CS1Pos, _mech_rtP + 25, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body5.CS1Rot, _mech_rtP + 28, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body5.CS2Pos, _mech_rtP + 31, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body5.CS2Rot, _mech_rtP + 34, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body5.CS3Pos, _mech_rtP + 19, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body5.CS3Rot, _mech_rtP + 22, sizeof(real_T) * 3);
    memcpy(_mech_rtS->Body5.Inertia, _mech_rtP + 9, sizeof(real_T) * 9);
    _mech_rtS->Body5.Mass = _mech_rtP[18];
    /*
     * get runtime parameters for block:
     *     Mechanics/Ground
     */
    memcpy(_mech_rtS->Ground.CoordPosition, _mech_rtP + 213, sizeof(real_T) * 3);
    /*
     * get runtime parameters for block:
     *     Mechanics/Ground1
     */
    memcpy(_mech_rtS->Ground1.CoordPosition, _mech_rtP + 145, sizeof(real_T) * 3);
    /*
     * get runtime parameters for block:
     *     Mechanics/Revolute
     */
    memcpy(_mech_rtS->Revolute.R1Axis, _mech_rtP + 210, sizeof(real_T) * 3);
    /*
     * get runtime parameters for block:
     *     Mechanics/Revolute1
     */
    memcpy(_mech_rtS->Revolute1.R1Axis, _mech_rtP + 142, sizeof(real_T) * 3);
    /*
     * get runtime parameters for block:
     *     Mechanics/Revolute2
     */
    memcpy(_mech_rtS->Revolute2.R1Axis, _mech_rtP + 179, sizeof(real_T) * 3);
    /*
     * get runtime parameters for block:
     *     Mechanics/Revolute3
     */
    memcpy(_mech_rtS->Revolute3.R1Axis, _mech_rtP + 111, sizeof(real_T) * 3);
    /*
     * get runtime parameters for block:
     *     Mechanics/Revolute4
     */
    memcpy(_mech_rtS->Revolute4.R1Axis, _mech_rtP + 68, sizeof(real_T) * 3);
    /*
     * get runtime parameters for block:
     *     Mechanics/Revolute5
     */
    memcpy(_mech_rtS->Revolute5.R1Axis, _mech_rtP + 148, sizeof(real_T) * 3);
    /*
     * get runtime parameters for block:
     *     Mechanics/Revolute6
     */
    memcpy(_mech_rtS->Revolute6.R1Axis, _mech_rtP + 37, sizeof(real_T) * 3);
    /*
     * get runtime parameters for block:
     *     Mechanics/Revolute7
     */
    memcpy(_mech_rtS->Revolute7.R1Axis, _mech_rtP + 0, sizeof(real_T) * 3);
}

/*
 * Convert structure for machine to runtime parameter vector
 */
void rt_machine_parameters_to_vector_Mechanics_c90d139d(const MachineParameters_Mechanics_c90d139d *_mech_rtS, real_T *_mech_rtP)
{
    /*
     * arrange runtime parameters for block:
     *     Mechanics/Body
     */
    memcpy(_mech_rtP + 182, _mech_rtS->Body.CGPos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 185, _mech_rtS->Body.CGRot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 198, _mech_rtS->Body.CS1Pos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 201, _mech_rtS->Body.CS1Rot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 204, _mech_rtS->Body.CS2Pos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 207, _mech_rtS->Body.CS2Rot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 188, _mech_rtS->Body.Inertia, sizeof(real_T) * 9);
    _mech_rtP[197] = _mech_rtS->Body.Mass;
    /*
     * arrange runtime parameters for block:
     *     Mechanics/Body1
     */
    memcpy(_mech_rtP + 71, _mech_rtS->Body1.CGPos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 74, _mech_rtS->Body1.CGRot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 99, _mech_rtS->Body1.CS1Pos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 102, _mech_rtS->Body1.CS1Rot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 105, _mech_rtS->Body1.CS2Pos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 108, _mech_rtS->Body1.CS2Rot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 93, _mech_rtS->Body1.CS3Pos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 96, _mech_rtS->Body1.CS3Rot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 87, _mech_rtS->Body1.CS4Pos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 90, _mech_rtS->Body1.CS4Rot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 77, _mech_rtS->Body1.Inertia, sizeof(real_T) * 9);
    _mech_rtP[86] = _mech_rtS->Body1.Mass;
    /*
     * arrange runtime parameters for block:
     *     Mechanics/Body2
     */
    memcpy(_mech_rtP + 114, _mech_rtS->Body2.CGPos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 117, _mech_rtS->Body2.CGRot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 130, _mech_rtS->Body2.CS1Pos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 133, _mech_rtS->Body2.CS1Rot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 136, _mech_rtS->Body2.CS2Pos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 139, _mech_rtS->Body2.CS2Rot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 120, _mech_rtS->Body2.Inertia, sizeof(real_T) * 9);
    _mech_rtP[129] = _mech_rtS->Body2.Mass;
    /*
     * arrange runtime parameters for block:
     *     Mechanics/Body3
     */
    memcpy(_mech_rtP + 40, _mech_rtS->Body3.CGPos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 43, _mech_rtS->Body3.CGRot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 56, _mech_rtS->Body3.CS1Pos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 59, _mech_rtS->Body3.CS1Rot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 62, _mech_rtS->Body3.CS2Pos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 65, _mech_rtS->Body3.CS2Rot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 46, _mech_rtS->Body3.Inertia, sizeof(real_T) * 9);
    _mech_rtP[55] = _mech_rtS->Body3.Mass;
    /*
     * arrange runtime parameters for block:
     *     Mechanics/Body4
     */
    memcpy(_mech_rtP + 151, _mech_rtS->Body4.CGPos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 154, _mech_rtS->Body4.CGRot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 167, _mech_rtS->Body4.CS1Pos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 170, _mech_rtS->Body4.CS1Rot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 173, _mech_rtS->Body4.CS2Pos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 176, _mech_rtS->Body4.CS2Rot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 157, _mech_rtS->Body4.Inertia, sizeof(real_T) * 9);
    _mech_rtP[166] = _mech_rtS->Body4.Mass;
    /*
     * arrange runtime parameters for block:
     *     Mechanics/Body5
     */
    memcpy(_mech_rtP + 3, _mech_rtS->Body5.CGPos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 6, _mech_rtS->Body5.CGRot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 25, _mech_rtS->Body5.CS1Pos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 28, _mech_rtS->Body5.CS1Rot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 31, _mech_rtS->Body5.CS2Pos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 34, _mech_rtS->Body5.CS2Rot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 19, _mech_rtS->Body5.CS3Pos, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 22, _mech_rtS->Body5.CS3Rot, sizeof(real_T) * 3);
    memcpy(_mech_rtP + 9, _mech_rtS->Body5.Inertia, sizeof(real_T) * 9);
    _mech_rtP[18] = _mech_rtS->Body5.Mass;
    /*
     * arrange runtime parameters for block:
     *     Mechanics/Ground
     */
    memcpy(_mech_rtP + 213, _mech_rtS->Ground.CoordPosition, sizeof(real_T) * 3);
    /*
     * arrange runtime parameters for block:
     *     Mechanics/Ground1
     */
    memcpy(_mech_rtP + 145, _mech_rtS->Ground1.CoordPosition, sizeof(real_T) * 3);
    /*
     * arrange runtime parameters for block:
     *     Mechanics/Revolute
     */
    memcpy(_mech_rtP + 210, _mech_rtS->Revolute.R1Axis, sizeof(real_T) * 3);
    /*
     * arrange runtime parameters for block:
     *     Mechanics/Revolute1
     */
    memcpy(_mech_rtP + 142, _mech_rtS->Revolute1.R1Axis, sizeof(real_T) * 3);
    /*
     * arrange runtime parameters for block:
     *     Mechanics/Revolute2
     */
    memcpy(_mech_rtP + 179, _mech_rtS->Revolute2.R1Axis, sizeof(real_T) * 3);
    /*
     * arrange runtime parameters for block:
     *     Mechanics/Revolute3
     */
    memcpy(_mech_rtP + 111, _mech_rtS->Revolute3.R1Axis, sizeof(real_T) * 3);
    /*
     * arrange runtime parameters for block:
     *     Mechanics/Revolute4
     */
    memcpy(_mech_rtP + 68, _mech_rtS->Revolute4.R1Axis, sizeof(real_T) * 3);
    /*
     * arrange runtime parameters for block:
     *     Mechanics/Revolute5
     */
    memcpy(_mech_rtP + 148, _mech_rtS->Revolute5.R1Axis, sizeof(real_T) * 3);
    /*
     * arrange runtime parameters for block:
     *     Mechanics/Revolute6
     */
    memcpy(_mech_rtP + 37, _mech_rtS->Revolute6.R1Axis, sizeof(real_T) * 3);
    /*
     * arrange runtime parameters for block:
     *     Mechanics/Revolute7
     */
    memcpy(_mech_rtP + 0, _mech_rtS->Revolute7.R1Axis, sizeof(real_T) * 3);
}

/* [EOF] rt_mechanism_data.c */
