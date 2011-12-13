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
/* rt_mechanism.c - body for module rt_mechanism */
#include "rt_mechanism.h"
#include "rt_mechanism_map.h"
int32_T rt_mech_visited_double_w_haptics_1460d8f1 = 0;
int32_T rt_mech_visited_loc_double_w_haptics_1460d8f1 = 0;
Mechanism *rt_get_mechanism_double_w_haptics_1460d8f1(void)
{
    static Mechanism *_mechanism = 0;
    static pmArrayRead pmArrayRead_table[34];
    static real_T real_T_table[275];
    static AxisRead AxisRead_table[2];
    static pmArrayRead *pmArrayRead_ptr_table[8];
    static NameArrayRead NameArrayRead_table[3];
    static int32_T int32_T_table[14];
    static IndexArrayRead IndexArrayRead_table[9];
    static Sensor Sensor_table[2];
    static BodySensor BodySensor_table[3];
    static BodyActuator BodyActuator_table[6];
    static GeneralJointEngine GeneralJointEngine_table[3];
    static Joint Joint_table[3];
    static BodyEngine BodyEngine_table[3];
    static Body Body_table[3];
    static Joint *Joint_ptr_table[3];
    static Branch Branch_table[2];
    static Body *Body_ptr_table[3];
    static Connect Connect_table[1];
    static Branch *Branch_ptr_table[5];
    static Recursion Recursion_table[1];
    static Connect *Connect_ptr_table[1];
    static MachineData MachineData_table[1];
    static WarningFlags WarningFlags_table[1];
    static Mechanism Mechanism_table[1];
    if(_mechanism == 0) {
        /* starting table: pmArrayRead_table */
        memset(pmArrayRead_table, 0, sizeof(pmArrayRead_table));
        pmArrayRead_table[0].iszero = 1;
        pmArrayRead_table[0].type = 1;
        pmArrayRead_table[1].type = 1;
        pmArrayRead_table[1].n = 3U;
        pmArrayRead_table[1].real = real_T_table + 175U;
        pmArrayRead_table[2].type = 1;
        pmArrayRead_table[2].n = 1U;
        pmArrayRead_table[2].real = real_T_table + 178U;
        pmArrayRead_table[3].type = 1;
        pmArrayRead_table[3].n = 9U;
        pmArrayRead_table[3].real = real_T_table + 179U;
        pmArrayRead_table[4].type = 1;
        pmArrayRead_table[4].n = 3U;
        pmArrayRead_table[4].real = real_T_table + 188U;
        pmArrayRead_table[5].type = 1;
        pmArrayRead_table[5].n = 3U;
        pmArrayRead_table[5].real = real_T_table + 191U;
        pmArrayRead_table[6].type = 1;
        pmArrayRead_table[6].n = 1U;
        pmArrayRead_table[6].real = real_T_table + 194U;
        pmArrayRead_table[7].type = 1;
        pmArrayRead_table[7].n = 1U;
        pmArrayRead_table[7].real = real_T_table + 195U;
        pmArrayRead_table[8].type = 1;
        pmArrayRead_table[8].n = 9U;
        pmArrayRead_table[8].real = real_T_table + 196U;
        pmArrayRead_table[9].type = 1;
        pmArrayRead_table[9].n = 3U;
        pmArrayRead_table[9].real = real_T_table + 205U;
        pmArrayRead_table[10].type = 1;
        pmArrayRead_table[10].n = 9U;
        pmArrayRead_table[10].real = real_T_table + 208U;
        pmArrayRead_table[11].type = 1;
        pmArrayRead_table[11].n = 1U;
        pmArrayRead_table[11].real = real_T_table + 217U;
        pmArrayRead_table[12].type = 1;
        pmArrayRead_table[12].n = 9U;
        pmArrayRead_table[12].real = real_T_table + 218U;
        pmArrayRead_table[13].type = 1;
        pmArrayRead_table[13].n = 3U;
        pmArrayRead_table[13].real = real_T_table + 227U;
        pmArrayRead_table[14].type = 1;
        pmArrayRead_table[14].n = 9U;
        pmArrayRead_table[14].real = real_T_table + 230U;
        pmArrayRead_table[15].type = 1;
        pmArrayRead_table[15].n = 1U;
        pmArrayRead_table[15].real = real_T_table + 239U;
        pmArrayRead_table[16].type = 1;
        pmArrayRead_table[16].n = 1U;
        pmArrayRead_table[16].real = real_T_table + 240U;
        pmArrayRead_table[17].type = 1;
        pmArrayRead_table[17].n = 1U;
        pmArrayRead_table[17].real = real_T_table + 241U;
        pmArrayRead_table[18].type = 1;
        pmArrayRead_table[18].n = 3U;
        pmArrayRead_table[18].real = real_T_table + 242U;
        pmArrayRead_table[19].type = 1;
        pmArrayRead_table[19].n = 3U;
        pmArrayRead_table[19].real = real_T_table + 245U;
        pmArrayRead_table[20].type = 1;
        pmArrayRead_table[20].n = 3U;
        pmArrayRead_table[20].real = real_T_table + 248U;
        pmArrayRead_table[21].type = 1;
        pmArrayRead_table[21].n = 1U;
        pmArrayRead_table[21].real = real_T_table + 251U;
        pmArrayRead_table[22].type = 1;
        pmArrayRead_table[22].n = 1U;
        pmArrayRead_table[22].real = real_T_table + 252U;
        pmArrayRead_table[23].type = 1;
        pmArrayRead_table[23].n = 1U;
        pmArrayRead_table[23].real = real_T_table + 253U;
        pmArrayRead_table[24].type = 1;
        pmArrayRead_table[24].n = 3U;
        pmArrayRead_table[24].real = real_T_table + 254U;
        pmArrayRead_table[25].type = 1;
        pmArrayRead_table[25].n = 3U;
        pmArrayRead_table[25].real = real_T_table + 257U;
        pmArrayRead_table[26].type = 1;
        pmArrayRead_table[26].n = 3U;
        pmArrayRead_table[26].real = real_T_table + 260U;
        pmArrayRead_table[27].type = 1;
        pmArrayRead_table[27].n = 1U;
        pmArrayRead_table[27].real = real_T_table + 263U;
        pmArrayRead_table[28].type = 1;
        pmArrayRead_table[28].n = 1U;
        pmArrayRead_table[28].real = real_T_table + 264U;
        pmArrayRead_table[29].type = 1;
        pmArrayRead_table[29].n = 1U;
        pmArrayRead_table[29].real = real_T_table + 265U;
        pmArrayRead_table[30].type = 1;
        pmArrayRead_table[30].n = 9U;
        pmArrayRead_table[30].real = real_T_table + 266U;
        pmArrayRead_table[31].iszero = 1;
        pmArrayRead_table[31].type = 1;
        pmArrayRead_table[31].n = 3U;
        pmArrayRead_table[31].real = real_T_table + 7U;
        pmArrayRead_table[32].type = 1;
        pmArrayRead_table[32].n = 3U;
        pmArrayRead_table[32].real = real_T_table + 10U;
        pmArrayRead_table[33].type = 1;
        pmArrayRead_table[33].n = 6U;
        pmArrayRead_table[33].real = real_T_table + 1U;
        /* starting table: real_T_table */
        memset(real_T_table, 0, sizeof(real_T_table));
        real_T_table[0] = 1.0;
        /* starting table: AxisRead_table */
        memset(AxisRead_table, 0, sizeof(AxisRead_table));
        AxisRead_table[0].n = 1;
        AxisRead_table[0].subaxis = pmArrayRead_ptr_table + 6U;
        AxisRead_table[1].n = 1;
        AxisRead_table[1].subaxis = pmArrayRead_ptr_table + 7U;
        /* starting table: pmArrayRead_ptr_table */
        memset(pmArrayRead_ptr_table, 0, sizeof(pmArrayRead_ptr_table));
        pmArrayRead_ptr_table[0] = pmArrayRead_table + 4U;
        pmArrayRead_ptr_table[1] = pmArrayRead_table;
        pmArrayRead_ptr_table[2] = pmArrayRead_table + 5U;
        pmArrayRead_ptr_table[3] = pmArrayRead_table + 6U;
        pmArrayRead_ptr_table[4] = pmArrayRead_table;
        pmArrayRead_ptr_table[5] = pmArrayRead_table + 33U;
        pmArrayRead_ptr_table[6] = pmArrayRead_table + 20U;
        pmArrayRead_ptr_table[7] = pmArrayRead_table + 26U;
        /* starting table: NameArrayRead_table */
        memset(NameArrayRead_table, 0, sizeof(NameArrayRead_table));
        NameArrayRead_table[0].n = 1;
        NameArrayRead_table[0].type = int32_T_table + 6U;
        NameArrayRead_table[1].n = 1;
        NameArrayRead_table[1].type = int32_T_table + 2U;
        NameArrayRead_table[2].n = 1;
        NameArrayRead_table[2].type = int32_T_table + 10U;
        /* starting table: int32_T_table */
        memset(int32_T_table, 0, sizeof(int32_T_table));
        int32_T_table[0] = 8;
        int32_T_table[1] = 2;
        int32_T_table[2] = 1;
        int32_T_table[3] = 5;
        int32_T_table[4] = 3;
        int32_T_table[5] = 6;
        int32_T_table[6] = 2;
        int32_T_table[7] = 5;
        int32_T_table[8] = 6;
        int32_T_table[9] = 6;
        int32_T_table[10] = 2;
        int32_T_table[11] = 5;
        int32_T_table[12] = 6;
        int32_T_table[13] = 6;
        /* starting table: IndexArrayRead_table */
        memset(IndexArrayRead_table, 0, sizeof(IndexArrayRead_table));
        IndexArrayRead_table[0].n = 1;
        IndexArrayRead_table[0].index = int32_T_table + 11U;
        IndexArrayRead_table[1].n = 1;
        IndexArrayRead_table[1].index = int32_T_table + 4U;
        IndexArrayRead_table[2].n = 1;
        IndexArrayRead_table[2].index = int32_T_table + 13U;
        IndexArrayRead_table[3].n = 1;
        IndexArrayRead_table[3].index = int32_T_table + 9U;
        IndexArrayRead_table[4].n = 1;
        IndexArrayRead_table[4].index = int32_T_table + 5U;
        IndexArrayRead_table[5].n = 1;
        IndexArrayRead_table[5].index = int32_T_table + 3U;
        IndexArrayRead_table[6].n = 1;
        IndexArrayRead_table[6].index = int32_T_table + 12U;
        IndexArrayRead_table[7].n = 1;
        IndexArrayRead_table[7].index = int32_T_table + 7U;
        IndexArrayRead_table[8].n = 1;
        IndexArrayRead_table[8].index = int32_T_table + 8U;
        /* starting table: Sensor_table */
        memset(Sensor_table, 0, sizeof(Sensor_table));
        /* starting table: BodySensor_table */
        memset(BodySensor_table, 0, sizeof(BodySensor_table));
        BodySensor_table[1].n = 1U;
        BodySensor_table[1].sensorType = int32_T_table;
        BodySensor_table[1].pos_0 = pmArrayRead_ptr_table;
        BodySensor_table[1].T = pmArrayRead_ptr_table + 1U;
        BodySensor_table[1].outputScaling = real_T_table;
        /* starting table: BodyActuator_table */
        memset(BodyActuator_table, 0, sizeof(BodyActuator_table));
        BodyActuator_table[1].n = 1U;
        BodyActuator_table[1].actuatorType = int32_T_table + 1U;
        BodyActuator_table[1].pos_0 = pmArrayRead_ptr_table + 2U;
        BodyActuator_table[1].force = pmArrayRead_ptr_table + 5U;
        BodyActuator_table[1].T = pmArrayRead_ptr_table + 4U;
        BodyActuator_table[1].inputScaling = pmArrayRead_ptr_table + 3U;
        /* starting table: GeneralJointEngine_table */
        memset(GeneralJointEngine_table, 0, sizeof(GeneralJointEngine_table));
        GeneralJointEngine_table[0].lockTolerance = pmArrayRead_table + 15U;
        GeneralJointEngine_table[0].primitives = NameArrayRead_table + 1U;
        GeneralJointEngine_table[0].eventList = IndexArrayRead_table + 5U;
        GeneralJointEngine_table[0].poweredList = IndexArrayRead_table + 1U;
        GeneralJointEngine_table[0].icpoweredList = IndexArrayRead_table + 4U;
        GeneralJointEngine_table[0].icposition = pmArrayRead_table + 16U;
        GeneralJointEngine_table[0].icvelocity = pmArrayRead_table + 17U;
        GeneralJointEngine_table[1].scale = 1.0;
        GeneralJointEngine_table[1].axis = AxisRead_table;
        GeneralJointEngine_table[1].lockTolerance = pmArrayRead_table + 21U;
        GeneralJointEngine_table[1].primitives = NameArrayRead_table;
        GeneralJointEngine_table[1].eventList = IndexArrayRead_table + 7U;
        GeneralJointEngine_table[1].poweredList = IndexArrayRead_table + 8U;
        GeneralJointEngine_table[1].icpoweredList = IndexArrayRead_table + 3U;
        GeneralJointEngine_table[1].icposition = pmArrayRead_table + 22U;
        GeneralJointEngine_table[1].icvelocity = pmArrayRead_table + 23U;
        GeneralJointEngine_table[1].sensor = Sensor_table;
        GeneralJointEngine_table[2].scale = 1.0;
        GeneralJointEngine_table[2].axis = AxisRead_table + 1U;
        GeneralJointEngine_table[2].lockTolerance = pmArrayRead_table + 27U;
        GeneralJointEngine_table[2].primitives = NameArrayRead_table + 2U;
        GeneralJointEngine_table[2].eventList = IndexArrayRead_table;
        GeneralJointEngine_table[2].poweredList = IndexArrayRead_table + 6U;
        GeneralJointEngine_table[2].icpoweredList = IndexArrayRead_table + 2U;
        GeneralJointEngine_table[2].icposition = pmArrayRead_table + 28U;
        GeneralJointEngine_table[2].icvelocity = pmArrayRead_table + 29U;
        GeneralJointEngine_table[2].sensor = Sensor_table + 1U;
        /* starting table: Joint_table */
        memset(Joint_table, 0, sizeof(Joint_table));
        Joint_table[0].blockName = "PermeatingWeld";
        Joint_table[0].pos_0 = pmArrayRead_table + 31U;
        Joint_table[0].rel_0 = pmArrayRead_table + 31U;
        Joint_table[0].type = 2;
        Joint_table[0].compile = GeneralJointEngine_table;
        Joint_table[0].pred = Joint_table;
        Joint_table[1].blockName = "double_w_haptics/Revolute1";
        Joint_table[1].pos_0 = pmArrayRead_table + 18U;
        Joint_table[1].rel_0 = pmArrayRead_table + 19U;
        Joint_table[1].type = 2;
        Joint_table[1].compile = GeneralJointEngine_table + 1U;
        Joint_table[1].pred = Joint_table;
        Joint_table[2].blockName = "double_w_haptics/Revolute3";
        Joint_table[2].pos_0 = pmArrayRead_table + 24U;
        Joint_table[2].rel_0 = pmArrayRead_table + 25U;
        Joint_table[2].type = 2;
        Joint_table[2].compile = GeneralJointEngine_table + 2U;
        Joint_table[2].pred = Joint_table + 1U;
        /* starting table: BodyEngine_table */
        memset(BodyEngine_table, 0, sizeof(BodyEngine_table));
        BodyEngine_table[0].J_0 = pmArrayRead_table + 3U;
        BodyEngine_table[0].pos_0 = pmArrayRead_table + 1U;
        BodyEngine_table[0].mass = pmArrayRead_table + 2U;
        BodyEngine_table[0].sensor = BodySensor_table + 2U;
        BodyEngine_table[0].input = BodyActuator_table;
        BodyEngine_table[0].massinertia = BodyActuator_table + 5U;
        BodyEngine_table[1].J_0 = pmArrayRead_table + 8U;
        BodyEngine_table[1].pos_0 = pmArrayRead_table + 9U;
        BodyEngine_table[1].mass = pmArrayRead_table + 7U;
        BodyEngine_table[1].sensor = BodySensor_table + 1U;
        BodyEngine_table[1].input = BodyActuator_table + 1U;
        BodyEngine_table[1].massinertia = BodyActuator_table + 4U;
        BodyEngine_table[1].transform2D = pmArrayRead_table + 10U;
        BodyEngine_table[2].J_0 = pmArrayRead_table + 12U;
        BodyEngine_table[2].pos_0 = pmArrayRead_table + 13U;
        BodyEngine_table[2].mass = pmArrayRead_table + 11U;
        BodyEngine_table[2].sensor = BodySensor_table;
        BodyEngine_table[2].input = BodyActuator_table + 2U;
        BodyEngine_table[2].massinertia = BodyActuator_table + 3U;
        BodyEngine_table[2].transform2D = pmArrayRead_table + 14U;
        /* starting table: Body_table */
        memset(Body_table, 0, sizeof(Body_table));
        Body_table[0].blockName = "PermeatingBody";
        Body_table[0].compile = BodyEngine_table;
        Body_table[0].pred = Body_table;
        Body_table[1].blockName = "double_w_haptics/Body1";
        Body_table[1].compile = BodyEngine_table + 1U;
        Body_table[1].pred = Body_table + 2U;
        Body_table[2].blockName = "double_w_haptics/Body";
        Body_table[2].compile = BodyEngine_table + 2U;
        Body_table[2].pred = Body_table;
        /* starting table: Joint_ptr_table */
        memset(Joint_ptr_table, 0, sizeof(Joint_ptr_table));
        Joint_ptr_table[0] = Joint_table;
        Joint_ptr_table[1] = Joint_table + 2U;
        Joint_ptr_table[2] = Joint_table + 1U;
        /* starting table: Branch_table */
        memset(Branch_table, 0, sizeof(Branch_table));
        Branch_table[0].njoints = 1;
        Branch_table[0].body = Body_ptr_table;
        Branch_table[0].joint = Joint_ptr_table;
        Branch_table[0].pred = Branch_table;
        Branch_table[1].njoints = 2;
        Branch_table[1].body = Body_ptr_table + 1U;
        Branch_table[1].joint = Joint_ptr_table + 1U;
        Branch_table[1].pred = Branch_table;
        /* starting table: Body_ptr_table */
        memset(Body_ptr_table, 0, sizeof(Body_ptr_table));
        Body_ptr_table[0] = Body_table;
        Body_ptr_table[1] = Body_table + 1U;
        Body_ptr_table[2] = Body_table + 2U;
        /* starting table: Connect_table */
        memset(Connect_table, 0, sizeof(Connect_table));
        Connect_table[0].n = 1;
        Connect_table[0].branch = Branch_ptr_table + 2U;
        /* starting table: Branch_ptr_table */
        memset(Branch_ptr_table, 0, sizeof(Branch_ptr_table));
        Branch_ptr_table[0] = Branch_table + 1U;
        Branch_ptr_table[1] = Branch_table;
        Branch_ptr_table[2] = Branch_table + 1U;
        Branch_ptr_table[3] = Branch_table + 1U;
        Branch_ptr_table[4] = Branch_table;
        /* starting table: Recursion_table */
        memset(Recursion_table, 0, sizeof(Recursion_table));
        Recursion_table[0].nLeafBranches = 1;
        Recursion_table[0].nTrunkBranches = 1;
        Recursion_table[0].leaf = Branch_ptr_table;
        Recursion_table[0].trunk = Branch_ptr_table + 1U;
        Recursion_table[0].trunkConnectors = Connect_ptr_table;
        /* starting table: Connect_ptr_table */
        memset(Connect_ptr_table, 0, sizeof(Connect_ptr_table));
        Connect_ptr_table[0] = Connect_table;
        /* starting table: MachineData_table */
        memset(MachineData_table, 0, sizeof(MachineData_table));
        MachineData_table[0].numBlock1States = 4;
        MachineData_table[0].numBlock1Outputs = 3;
        MachineData_table[0].numBlock2Inputs = 3;
        MachineData_table[0].rTol = 0.0001;
        MachineData_table[0].aTol = 0.0001;
        MachineData_table[0].sqrtEps = 1.4901161193847656E-008;
        MachineData_table[0].linearAssemblyTolerance = 0.001;
        MachineData_table[0].angularAssemblyTolerance = 0.001;
        MachineData_table[0].redundancyAnalysisToleranceType = 1;
        MachineData_table[0].redundancyAnalysisTolerance = 1.0E-014;
        MachineData_table[0].system = "double_w_haptics/Ground";
        MachineData_table[0].gravity = pmArrayRead_table + 32U;
        MachineData_table[0].recurse = Recursion_table;
        MachineData_table[0].mode = 2;
        MachineData_table[0].solve = 1;
        MachineData_table[0].linFixedPerturbation = 1;
        MachineData_table[0].linPerturbationSize = 0.00001;
        /* starting table: WarningFlags_table */
        memset(WarningFlags_table, 0, sizeof(WarningFlags_table));
        WarningFlags_table[0].warnOnRedundantConstraints = 1;
        /* starting table: Mechanism_table */
        memset(Mechanism_table, 0, sizeof(Mechanism_table));
        Mechanism_table[0].nbranches = 2;
        Mechanism_table[0].generatingCode = 1;
        Mechanism_table[0].branch = Branch_ptr_table + 3U;
        Mechanism_table[0].data = MachineData_table;
        Mechanism_table[0].nruntimeData = 262U;
        Mechanism_table[0].runtimeData = real_T_table + 13U;
        Mechanism_table[0].allowedSimulationDimensions = 4;
        Mechanism_table[0].transform2D = pmArrayRead_table + 30U;
        Mechanism_table[0].warningFlags = WarningFlags_table;
        _mechanism = Mechanism_table;
        _mechanism->mapRuntimeData = rt_map_mechanism_params_double_w_haptics_1460d8f1;
    }
    return _mechanism;
}
