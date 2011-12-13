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
boolean_T rt_map_mechanism_params_double_wo_haptics_9648c7ca(Mechanism * mechanism, const real_T * input, char_T * msg, uint32_T msg_size)
{
    static real_T work[374];
    real_T *output = 0;
    boolean_T error = 0;
    output = mechanism->runtimeData;
    memset(work, 0, sizeof(work));
    work[0] = 1.0;
    work[7] = 1.0;
    work[8] = 1.0;
    work[12] = 1.0;
    work[16] = 1.0;
    work[201] = 1.0;
    work[310] = 1.0;
    work[314] = 1.0;
    work[318] = 1.0;
    work[341] = 1.0;
    work[345] = 1.0;
    work[349] = 1.0;
    work[365] = 1.0;
    work[369] = 1.0;
    work[373] = 1.0;
    pmVectorFunction((work + 17), (input + 37), (work + 1), 0.0, 1.0, 0.0, 3, 1, 1, 0);
    pmVectorFunction((work + 20), (input + 40), (work + 1), 0.0, 0.01745329251994329500, 0.0, 3, 1, 1, 0);
    pmConvertToRotationMatrix(1, (work + 20), (work + 23));
    pmVectorFunction((work + 32), (input + 53), (work + 1), 0.0, 1.0, 0.0, 3, 1, 1, 0);
    pmVectorFunction((work + 35), (input + 56), (work + 1), 0.0, 0.01745329251994329500, 0.0, 3, 1, 1, 0);
    pmConvertToRotationMatrix(1, (work + 35), (work + 38));
    pmVectorFunction((work + 47), (input + 59), (work + 1), 0.0, 1.0, 0.0, 3, 1, 1, 0);
    pmVectorFunction((work + 50), (input + 62), (work + 1), 0.0, 0.01745329251994329500, 0.0, 3, 1, 1, 0);
    pmConvertToRotationMatrix(1, (work + 50), (work + 53));
    pmVectorFunction((work + 62), (input + 65), (work + 1), 0.0, 1.0, 0.0, 3, 1, 1, 0);
    pmVectorFunction((work + 65), (input + 68), (work + 1), 0.0, 0.01745329251994329500, 0.0, 3, 1, 1, 0);
    pmConvertToRotationMatrix(1, (work + 65), (work + 68));
    pmVectorFunction((work + 77), (input + 71), (work + 1), 0.0, 1.0, 0.0, 3, 1, 1, 0);
    pmVectorFunction((work + 80), (input + 74), (work + 1), 0.0, 0.01745329251994329500, 0.0, 3, 1, 1, 0);
    pmConvertToRotationMatrix(1, (work + 80), (work + 83));
    pmVectorFunction((work + 92), (input + 52), (work + 1), 0.0, 1.0, 0.0, 1, 1, 1, 0);
    pmVectorFunction((work + 93), (input + 43), (work + 1), 0.0, 1.0, 0.0, 9, 1, 1, 0);
    memcpy((work + 102), (work + 93), (9 * sizeof(double)));
    pmVectorFunction((work + 111), (input + 3), (work + 1), 0.0, 1.0, 0.0, 3, 1, 1, 0);
    pmVectorFunction((work + 114), (input + 6), (work + 1), 0.0, 0.01745329251994329500, 0.0, 3, 1, 1, 0);
    pmConvertToRotationMatrix(1, (work + 114), (work + 117));
    pmVectorFunction((work + 126), (input + 19), (work + 1), 0.0, 1.0, 0.0, 3, 1, 1, 0);
    pmVectorFunction((work + 129), (input + 22), (work + 1), 0.0, 0.01745329251994329500, 0.0, 3, 1, 1, 0);
    pmConvertToRotationMatrix(1, (work + 129), (work + 132));
    pmVectorFunction((work + 141), (input + 25), (work + 1), 0.0, 1.0, 0.0, 3, 1, 1, 0);
    pmVectorFunction((work + 144), (input + 28), (work + 1), 0.0, 0.01745329251994329500, 0.0, 3, 1, 1, 0);
    pmConvertToRotationMatrix(1, (work + 144), (work + 147));
    pmVectorFunction((work + 156), (input + 18), (work + 1), 0.0, 1.0, 0.0, 1, 1, 1, 0);
    pmVectorFunction((work + 157), (input + 9), (work + 1), 0.0, 1.0, 0.0, 9, 1, 1, 0);
    memcpy((work + 166), (work + 157), (9 * sizeof(double)));
    pmMult((work + 178), (input + 31), (input + 31), 3, 1, 3, 1, 1, 1, 3);
    work[178] = sqrt(work[178]);
    if (work[178] == 0.0)
    {
        strncpy(msg, "double_wo_haptics/Revolute1: Joint primitive R1 has an invalid axis.  Axis must evaluate to a 1-by-3 matrix.  Check and reconfigure primitive axis vector.", msg_size);
        error = 1;
        goto EXIT_POINT;
    }
    work[178] = (1.0 / work[178]);
    pmVectorFunction((work + 175), (input + 31), (work + 178), 1.0, 0.0, 0.0, 3, 1, 1, 0);
    pmMult((work + 182), input, input, 3, 1, 3, 1, 1, 1, 3);
    work[182] = sqrt(work[182]);
    if (work[182] == 0.0)
    {
        strncpy(msg, "double_wo_haptics/Revolute3: Joint primitive R1 has an invalid axis.  Axis must evaluate to a 1-by-3 matrix.  Check and reconfigure primitive axis vector.", msg_size);
        error = 1;
        goto EXIT_POINT;
    }
    work[182] = (1.0 / work[182]);
    pmVectorFunction((work + 179), input, (work + 182), 1.0, 0.0, 0.0, 3, 1, 1, 0);
    pmVectorFunction((work + 186), (input + 34), (work + 1), 0.0, 1.0, 0.0, 3, 1, 1, 0);
    pmVectorFunction((work + 189), (work + 183), (work + 1), 0.0, 0.01745329251994329500, 0.0, 3, 1, 1, 0);
    pmConvertToRotationMatrix(1, (work + 189), (work + 192));
    pmVectorFunction((work + 218), (work + 212), (work + 1), 0.0, 1.0, 0.0, 3, 1, 1, 0);
    pmVectorFunction((work + 221), (work + 215), (work + 1), 0.0, 0.01745329251994329500, 0.0, 3, 1, 1, 0);
    pmConvertToRotationMatrix(1, (work + 221), (work + 224));
    pmVectorFunction((work + 233), (input + 34), (work + 1), 0.0, 1.0, 0.0, 3, 1, 1, 0);
    pmVectorFunction((work + 236), (work + 183), (work + 1), 0.0, 0.01745329251994329500, 0.0, 3, 1, 1, 0);
    pmConvertToRotationMatrix(0, (work + 236), (work + 239));
    pmVectorFunction((work + 248), (work + 202), (work + 1), 0.0, 1.0, 0.0, 1, 1, 1, 0);
    pmVectorFunction((work + 249), (work + 203), (work + 1), 0.0, 1.0, 0.0, 9, 1, 1, 0);
    memcpy((work + 258), (work + 249), (9 * sizeof(double)));
    pmMult((work + 267), (work + 53), (work + 62), 3, 3, 3, 1, 1, 1, 1);
    pmVectorFunction((work + 270), (work + 47), (work + 267), 0.0, 1.0, 1.0, 3, 1, 1, 1);
    pmMult((work + 273), (work + 53), (work + 77), 3, 3, 3, 1, 1, 1, 1);
    pmVectorFunction((work + 276), (work + 47), (work + 273), 0.0, 1.0, 1.0, 3, 1, 1, 1);
    pmVectorFunction((work + 279), (work + 218), (work + 1), 0.0, -1.0, 0.0, 3, 1, 1, 0);
    pmVectorFunction((work + 282), (work + 17), (work + 32), 0.0, 1.0, -1.0, 3, 1, 1, 1);
    pmMult((work + 285), (work + 93), (work + 23), 3, 3, 3, 3, 1, 1, 2);
    pmMult((work + 93), (work + 23), (work + 285), 3, 3, 3, 3, 1, 1, 1);
    pmMult((work + 303), (work + 282), (work + 282), 3, 1, 3, 1, 1, 1, 3);
    pmVectorFunction((work + 285), (work + 8), (work + 303), 1.0, 0.0, 0.0, 9, 1, 1, 0);
    pmMult((work + 294), (work + 282), (work + 282), 3, 1, 3, 1, 1, 1, 2);
    pmVectorFunction((work + 285), (work + 285), (work + 294), 0.0, 1.0, -1.0, 9, 1, 1, 1);
    pmVectorFunction((work + 285), (work + 285), (work + 92), 1.0, 0.0, 0.0, 9, 1, 1, 0);
    pmVectorFunction((work + 93), (work + 93), (work + 285), 0.0, 1.0, 1.0, 9, 1, 1, 1);
    pmVectorFunction((work + 304), (work + 270), (work + 32), 0.0, 1.0, -1.0, 3, 1, 1, 1);
    pmVectorFunction((work + 307), (work + 276), (work + 32), 0.0, 1.0, -1.0, 3, 1, 1, 1);
    pmVectorFunction((work + 319), (work + 111), (work + 126), 0.0, 1.0, -1.0, 3, 1, 1, 1);
    pmMult((work + 322), (work + 157), (work + 117), 3, 3, 3, 3, 1, 1, 2);
    pmMult((work + 157), (work + 117), (work + 322), 3, 3, 3, 3, 1, 1, 1);
    pmMult((work + 340), (work + 319), (work + 319), 3, 1, 3, 1, 1, 1, 3);
    pmVectorFunction((work + 322), (work + 8), (work + 340), 1.0, 0.0, 0.0, 9, 1, 1, 0);
    pmMult((work + 331), (work + 319), (work + 319), 3, 1, 3, 1, 1, 1, 2);
    pmVectorFunction((work + 322), (work + 322), (work + 331), 0.0, 1.0, -1.0, 9, 1, 1, 1);
    pmVectorFunction((work + 322), (work + 322), (work + 156), 1.0, 0.0, 0.0, 9, 1, 1, 0);
    pmVectorFunction((work + 157), (work + 157), (work + 322), 0.0, 1.0, 1.0, 9, 1, 1, 1);
    work[350] = work[1];
    work[351] = work[1];
    work[352] = work[1];
    pmVectorFunction((work + 353), (work + 126), (work + 233), 0.0, 1.0, -1.0, 3, 1, 1, 1);
    work[356] = work[1];
    work[357] = work[1];
    work[358] = work[1];
    pmVectorFunction((work + 359), (work + 32), (work + 141), 0.0, 1.0, -1.0, 3, 1, 1, 1);
    work[362] = work[1];
    work[363] = work[1];
    work[364] = work[1];
    output[0] = work[92];
    memcpy((output + 1), (work + 102), (9 * sizeof(double)));
    output[10] = work[156];
    memcpy((output + 11), (work + 166), (9 * sizeof(double)));
    output[20] = work[248];
    memcpy((output + 21), (work + 258), (9 * sizeof(double)));
    memcpy((output + 30), (work + 224), (9 * sizeof(double)));
    memcpy((output + 39), (work + 239), (9 * sizeof(double)));
    memcpy((output + 48), (work + 23), (9 * sizeof(double)));
    memcpy((output + 57), (work + 38), (9 * sizeof(double)));
    memcpy((output + 66), (work + 53), (9 * sizeof(double)));
    memcpy((output + 75), (work + 68), (9 * sizeof(double)));
    memcpy((output + 84), (work + 83), (9 * sizeof(double)));
    memcpy((output + 93), (work + 117), (9 * sizeof(double)));
    memcpy((output + 102), (work + 132), (9 * sizeof(double)));
    memcpy((output + 111), (work + 147), (9 * sizeof(double)));
    memcpy((output + 120), (work + 192), (9 * sizeof(double)));
    memcpy((output + 129), (work + 218), (3 * sizeof(double)));
    memcpy((output + 132), (work + 233), (3 * sizeof(double)));
    memcpy((output + 135), (work + 17), (3 * sizeof(double)));
    memcpy((output + 138), (work + 32), (3 * sizeof(double)));
    memcpy((output + 141), (work + 47), (3 * sizeof(double)));
    memcpy((output + 144), (work + 270), (3 * sizeof(double)));
    memcpy((output + 147), (work + 276), (3 * sizeof(double)));
    memcpy((output + 150), (work + 111), (3 * sizeof(double)));
    memcpy((output + 153), (work + 126), (3 * sizeof(double)));
    memcpy((output + 156), (work + 141), (3 * sizeof(double)));
    memcpy((output + 159), (work + 186), (3 * sizeof(double)));
    memcpy((output + 162), (work + 279), (3 * sizeof(double)));
    output[165] = work[1];
    memcpy((output + 166), (work + 8), (9 * sizeof(double)));
    memcpy((output + 175), (work + 304), (3 * sizeof(double)));
    memcpy((output + 178), (work + 307), (3 * sizeof(double)));
    output[181] = work[201];
    output[182] = work[92];
    memcpy((output + 183), (work + 93), (9 * sizeof(double)));
    memcpy((output + 192), (work + 282), (3 * sizeof(double)));
    memcpy((output + 195), (work + 310), (9 * sizeof(double)));
    output[204] = work[156];
    memcpy((output + 205), (work + 157), (9 * sizeof(double)));
    memcpy((output + 214), (work + 319), (3 * sizeof(double)));
    memcpy((output + 217), (work + 341), (9 * sizeof(double)));
    output[226] = work[350];
    output[227] = work[351];
    output[228] = work[352];
    memcpy((output + 229), (work + 233), (3 * sizeof(double)));
    memcpy((output + 232), (work + 353), (3 * sizeof(double)));
    memcpy((output + 235), (work + 175), (3 * sizeof(double)));
    output[238] = work[356];
    output[239] = work[357];
    output[240] = work[358];
    memcpy((output + 241), (work + 141), (3 * sizeof(double)));
    memcpy((output + 244), (work + 359), (3 * sizeof(double)));
    memcpy((output + 247), (work + 179), (3 * sizeof(double)));
    output[250] = work[362];
    output[251] = work[363];
    output[252] = work[364];
    memcpy((output + 253), (work + 365), (9 * sizeof(double)));
EXIT_POINT:
    (void)msg;
    (void)msg_size;
    return error;
}
