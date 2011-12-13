
/*============================================================================*\
| MATLAB Interface for LIBSVM, Version 1.2                                     |
|                                                                              |
| Copyright (C) 2004-2005 Michael Vogt                                         |
| Written by Michael Vogt, Atanas Ayarov and Bennet Gedan                      |
|                                                                              |
| This program is free software; you can redistribute it and/or modify it      |
| under the terms of the GNU General Public License as published by the Free   |
| Software Foundation; either version 2 of the License, or (at your option)    |
| any later version.                                                           |
\*============================================================================*/

#include <math.h>
#include "mex.h"
#include "libsvmaux.h"


/*----------------------------------------------------------------------------*\
| Calculate kernel function.                                                   |
\*----------------------------------------------------------------------------*/

double calcKernel(     /* Return: kernel function value K(x1,x2) */
  double *x1,          /* [in] first input vector (n elements) */
  long    N1,          /* [in] offset between the elements of x1 */
  double *x2,          /* [in] second input vector (n elements) */
  long    N2,          /* [in] offset between the elements of x2 */
  long    n,           /* [in] input dimension of x1 and x2 */
  kernel *ker )        /* [in] kernel function struct */

{
  register double s = 0;
  register double t = 0;
  register long k;

  switch (ker->type) {

  case KERNEL_LINEAR:
    for (k=0; k<n; k++, x1+=N1, x2+=N2)
      t += (*x2) * (*x1);
    return t;

  case KERNEL_POLY:
    t = ker->offset;
    s = 1;
    for (k=0; k<n; k++, x1+=N1, x2+=N2)
      t += (*x2) * (*x1);
    for (k=0; k<ker->degree; k++)
      s *= t;
    return s;

  case KERNEL_RADIAL:
    for (k=0; k<n; k++, x1+=N1, x2+=N2)
      t -= (*x2-*x1) * (*x2-*x1);
    return exp(t*ker->gamma);

  case KERNEL_GAUSS:
    for (k=0; k<n; k++, x1+=N1, x2+=N2)
      t -= (*x2-*x1) * (*x2-*x1) * ker->gammav[k];
    return exp(t);

  case KERNEL_TANH:
    t = ker->offset;
    for (k=0; k<n; k++, x1+=N1, x2+=N2)
      t += (*x2) * (*x1);
    return tanh(t*ker->gamma);

  default:
    return 0;
  }
}


/*----------------------------------------------------------------------------*\
| MATLAB gateway function.                                                     |
\*----------------------------------------------------------------------------*/

void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[] )

{
  double  *xd;      /* input data, size Nd*n */
  double  *xs;      /* SVM data, size Ns*n */
  double  *y;       /* output data, size Nd*1 */
  double  *a;       /* SVM coefficients, size Ns*1 */
  double   b;       /* bias term, scalar */
  long     Nd;      /* number of input data */
  long     Ns;      /* number of SVM data */
  long     n;       /* dimension of input space */
  long     d;       /* number of output dimensions */
  int     *dy;      /* dimensions of output vector*/
  long     i,j;     /* counters */
  kernel   ker;     /* kernel function */
  mxArray *F;       /* field of MATLAB struct */

  if (nrhs!=2)
    mexErrMsgTxt("Invalid number of input arguments.");

  if (nlhs>2)
    mexErrMsgTxt("Invalid number of output arguments.");

  /* --- check input arguments --- */

  if ( mxGetNumberOfElements(prhs[0]) != 1 ||
       !mxIsStruct(prhs[0]) ||
       getSvm(prhs[0],&a,&xs,&Ns,&n,&b,&ker) )
    mexErrMsgTxt("Invalid first argument (support vector machine).");

  if ( mxIsEmpty(prhs[1]) ||
       !mxIsDouble(prhs[1]) ||
       mxIsComplex(prhs[1]) )
    mexErrMsgTxt("Invalid second argument (input data).");

  if (nlhs > 1) {
    if ( (F=mxGetField(prhs[0],0,FNAME_PROB)) == NULL ||
         mxIsEmpty(F) ||
         mxGetNumberOfDimensions(F) > 2 ||
         !mxIsDouble(F) ||
         mxIsComplex(F) ||
         mxGetNumberOfElements(F) != 2 )
      mexErrMsgTxt("SVM does not contain valid probability information.");
  }

  /* --- get input arguments --- */

  d  = mxGetNumberOfDimensions(prhs[1]);   /* get true number of input dims */
  dy = (int*)mxGetDimensions(prhs[1]);
  while ( d>2 && dy[d-1]==1 )
    d--;

  if ( dy[d-1]==n )                   /* compute number of output dims */
    d--;
  else if ( n>1 )
    mexErrMsgTxt("Sizes of SVM and input data do not match.");

  xd = mxGetPr(prhs[1]);              /* get input data */
  Nd = 1;
  for (i=0; i<d; i++)
    Nd *= dy[i];

  /* --- compute SVM output --- */

  plhs[0] = mxCreateNumericArray(d,dy,mxDOUBLE_CLASS,mxREAL);
  y = mxGetPr(plhs[0]);

  for (i=0; i<Nd; i++) {
    y[i] = b;
    for (j=0; j<Ns; j++)
      y[i] += a[j]*calcKernel(xd+i,Nd,xs+j,Ns,n,&ker);
  }

  /* --- compute probabilities  --- */

  if (nlhs > 1) {
    double *p;         /* probability matrix */
    double  predict;   /* temporary computation value */
    double  probA = (mxGetPr(mxGetField(prhs[0],0,FNAME_PROB)))[0];
    double  probB = (mxGetPr(mxGetField(prhs[0],0,FNAME_PROB)))[1];

    plhs[1] = mxCreateNumericArray(d,dy,mxDOUBLE_CLASS,mxREAL);
    p = mxGetPr(plhs[1]);

    /* probability computation due to svm.cpp */
    #define min_prob 1e-7

    for (i=0; i<Nd; i++) {
      predict = y[i]*probA + probB;
      if (predict<0)
        predict = 1.0/(1.0+exp(predict));
      else
        predict = 1.0-1.0/(1.0+exp(-predict));

      if (y[i]<0)      /* always use PREDICTED class */
        predict = 1-predict;

      p[i] = (predict > 1-min_prob) ? 1-min_prob : predict;
    }
  }
}
