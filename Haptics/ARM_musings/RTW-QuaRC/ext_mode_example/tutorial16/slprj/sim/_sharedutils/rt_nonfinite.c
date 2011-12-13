/*
 * rt_nonfinite.c
 *
 * Real-Time Workshop code generation for Simulink model "vdmultRM.mdl".
 *
 * Model Version              : 1.7
 * Real-Time Workshop version : 7.0  (R2007b)  02-Aug-2007
 * C source code generated on : Wed Jun 10 17:09:32 2009
 *
 */

/*
 * Abstract:
 *      Real-Time Workshop function to intialize non-finites,
 *      (Inf, NaN and -Inf).
 */
#include "rt_nonfinite.h"

#define NumBitsPerChar                  8

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;

real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;

/* Function: rt_InitInfAndNaN ==================================================
 * Abstract:
 *	Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 *	generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
void rt_InitInfAndNaN(size_t realSize) {
  size_t bitsPerReal = realSize * (NumBitsPerChar);

  typedef struct {
    uint32_T fraction : 23;
    uint32_T exponent : 8;
    uint32_T sign : 1;
  } LittleEndianIEEESingle;

  typedef struct {
    struct {
      uint32_T fraction2;
    } wordH;
    struct {
      uint32_T fraction1 : 20;
      uint32_T exponent : 11;
      uint32_T sign : 1;
    } wordL;
  } LittleEndianIEEEDouble;

  (*(LittleEndianIEEESingle*)&rtInfF).sign = 0;
  (*(LittleEndianIEEESingle*)&rtInfF).exponent = 0xFF;
  (*(LittleEndianIEEESingle*)&rtInfF).fraction = 0;
  rtMinusInfF = rtInfF;
  rtNaNF = rtInfF;
  (*(LittleEndianIEEESingle*)&rtMinusInfF).sign = 1;
  (*(LittleEndianIEEESingle*)&rtNaNF).fraction = 0x7FFFFF;

  if (bitsPerReal == 32) {
    (*(LittleEndianIEEESingle*)&rtInf).sign = 0;
    (*(LittleEndianIEEESingle*)&rtInf).exponent = 0xFF;
    (*(LittleEndianIEEESingle*)&rtInf).fraction = 0;
    rtMinusInf = rtInf;
    rtNaN = rtInf;
    (*(LittleEndianIEEESingle*)&rtMinusInf).sign = 1;
    (*(LittleEndianIEEESingle*)&rtNaN).fraction = 0x7FFFFF;
  } else {
    (*(LittleEndianIEEEDouble*)&rtInf).wordL.sign = 0;
    (*(LittleEndianIEEEDouble*)&rtInf).wordL.exponent = 0x7FF;
    (*(LittleEndianIEEEDouble*)&rtInf).wordL.fraction1 = 0;
    (*(LittleEndianIEEEDouble*)&rtInf).wordH.fraction2 = 0;

    rtMinusInf = rtInf;
    (*(LittleEndianIEEEDouble*)&rtMinusInf).wordL.sign = 1;
    (*(LittleEndianIEEEDouble*)&rtNaN).wordL.sign = 0;
    (*(LittleEndianIEEEDouble*)&rtNaN).wordL.exponent = 0x7FF;
    (*(LittleEndianIEEEDouble*)&rtNaN).wordL.fraction1 = 0xFFFFF;
    (*(LittleEndianIEEEDouble*)&rtNaN).wordH.fraction2 = 0xFFFFFFFF;
  }
}

/* Function: rtIsInf ==================================================
 * Abstract:
 *	Test if value is infinite
 */
boolean_T rtIsInf(real_T value) {
  return ((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Function: rtIsInfF =================================================
 * Abstract:
 *	Test if single-precision value is infinite
 */
boolean_T rtIsInfF(real32_T value) {
  return(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Function: rtIsNaN ==================================================
 * Abstract:
 *	Test if value is not a number
 */
boolean_T rtIsNaN(real_T value) {
  return _isnan(value)? TRUE:FALSE;
}

/* Function: rtIsNaNF =================================================
 * Abstract:
 *	Test if single-precision value is not a number
 */
boolean_T rtIsNaNF(real32_T value) {
  return _isnan((real_T)value)? true:false;
}

#undef NumBitsPerChar

/* end rt_nonfinite.c */
