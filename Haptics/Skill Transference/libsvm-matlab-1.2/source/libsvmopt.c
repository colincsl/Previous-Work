
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

#include "mex.h"
#include "libsvmaux.h"


/*----------------------------------------------------------------------------*\
| MATLAB gateway function.                                                     |
\*----------------------------------------------------------------------------*/

void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[] )

{
  double  *x;             /* input data, size N*n */
  double  *y;             /* output data, size N*1 */
  double   C;             /* upper bound for Lagrange multipliers */
  double   e;             /* insensitivity zone epsilon */
  long     n;             /* dimension of input space */
  long     N;             /* number of input data */
  long     k;             /* counter */
  int      d0,d1;         /* true number of dimensions of arguments #0 and #1 */
  int      label1,label2; /* different class labels */
  kernel   ker;           /* kernel function */
  options  opt;           /* optimizer settings */
  const mxArray *mlopt;   /* mxArray for getOptionsStruct and getOptions */

  struct svm_problem prob;      /* LIBSVM problem (i.e. data) */
  struct svm_parameter param;   /* LIBSVM parameters */
  struct svm_model *model;      /* calculated LIBSVM model */

  if (nrhs<4)
    mexErrMsgTxt("Invalid number of input arguments.");

  /* --- get input and output data --- */

  if ( mxIsEmpty(prhs[0]) ||
       !mxIsDouble(prhs[0]) ||
       mxIsComplex(prhs[0]) )
    mexErrMsgTxt("Invalid first argument (input data).");

  d0 = mxGetNumberOfDimensions(prhs[0]);    /* compute true number of dims #0 */
  while ( mxGetDimensions(prhs[0])[d0-1] == 1 )
    d0--;

  if ( mxIsEmpty(prhs[1]) ) {               /* one-class SVM */
    n = mxGetDimensions(prhs[0])[d0-1];
    N = mxGetNumberOfElements(prhs[0])/n;
  }
  else if ( !mxIsDouble(prhs[1]) ||
            mxIsComplex(prhs[1]) ) {
    mexErrMsgTxt("Invalid second argument (output data).");
  }
  else {
    d1 = mxGetNumberOfDimensions(prhs[1]);  /* compute true number of dims #1 */
    while ( mxGetDimensions(prhs[1])[d1-1] == 1 )
      d1--;

    if ( d1 == d0 )                         /* exatly 1 regressor */
      n = 1;
    else if ( d1 == d0-1 )                  /* more than 1 regressor */
      n = mxGetDimensions(prhs[0])[d1];
    else
      mexErrMsgTxt("Sizes of input and output data do not match.");

    N = 1;                                  /* get number of data */
    for (k=0; k<d1; k++) {
      if ( mxGetDimensions(prhs[1])[k] != mxGetDimensions(prhs[0])[k] )
        mexErrMsgTxt("Sizes of first and second argument do not match.");
      else
        N *= mxGetDimensions(prhs[1])[k];
    }
  }

  if ( mxGetNumberOfElements(prhs[2]) != 1 ||
       !mxIsDouble(prhs[2]) ||
       mxIsComplex(prhs[2]) ||
       mxGetScalar(prhs[2]) <= 0 )
    mexErrMsgTxt("Invalid third argument (upper bound).");

  x = mxGetPr(prhs[0]);             /* get the input arguments */
  y = mxGetPr(prhs[1]);
  C = mxGetScalar(prhs[2]);

  /* set default values */
  opt.tol     = 1e-3;               /* tolerance for KKT check */
  opt.shrink  = 1;                  /* enable shrinking */
  opt.cache   = 40.0;               /* cache size in MB */
  opt.weight  = 1.0;                /* weight for class wlabel */
  opt.wlabel  = -1;                 /* class to be weighted */
  opt.verbose = 0;                  /* no verbosity */
  opt.style   = 0;                  /* C/eps style */
  opt.prob    = 0;                  /* no probability information */

  /* --- SVM classification --- */

  if ( mxGetNumberOfElements(prhs[3]) == 1 &&
       mxIsStruct(prhs[3]) ) {

    /* check lables for struct output (1 argument) */
    if ( !mxIsEmpty(prhs[1]) && nlhs == 1 ) { /* allow different class labels */
      label1 = (int)y[0];
      for (k=0; k<N; k++) {
        label2 = (int)y[k];
        if (label1 != label2)
          break;
      }
      for (k=0; k<N; k++)
        if ( y[k]!=label1 && y[k]!=label2 )
          mexErrMsgTxt("Only two different class labels are allowed.");
    }

    /* check lables for vector output (2 arguments) */
    if ( !mxIsEmpty(prhs[1]) && nlhs>1 ) {  /* class labels must be -1 or +1 */
      for (k=0; k<N; k++)
        if ( y[k]!=1 && y[k]!=-1 )
          mexErrMsgTxt("Only class labels +1 and -1 are allowed.");
      label1 = +1;
      label2 = -1;
    }

    /* get kernel and options */
    if ( getKernel(&ker,prhs[3],n) ||
         ker.type == KERNEL_GAUSS )
      mexErrMsgTxt("Invalid fourth argument (kernel function).");

    if ( nrhs>4 ) {
      getOptionsStruct(&mlopt,prhs+4,nrhs-4);
      getOptions(&opt,mlopt,N);
    }

    /* compute probability information only if it can be returned */
    if ( nlhs>1 )
      opt.prob = 0;

    /* check if weighting makes sense */
    if ( !mxIsEmpty(prhs[1]) &&
         opt.wlabel!=label1 && opt.wlabel!=label2 ) {
      opt.weight = 1;
      mexWarnMsgTxt("Class to be weighted does not exist.");
    }

    /* check nu value (C is treated as nu) */
    if ( opt.style == 1 && C > 1 )
      mexErrMsgTxt("nu must be in the range (0,1]");

    /* solve the classification problem */
    if ( mxIsEmpty(prhs[1]) ) {
      if ( C > 1 )
        mexErrMsgTxt("nu must be in the range (0,1]");
      convOptions(&param,C,0,&ker,&opt,2);
    }
    else {
      convOptions(&param,C,0,&ker,&opt,1);
    }
    convData(&prob,x,y,n,N);

    /* dump information about options and settings into MATLAB window */
    e = -1;
    if (opt.verbose > 0) {
      if ( mxIsEmpty(prhs[1]) )
        dumpOptions(&ker,&opt,C,e,2);
      else
        dumpOptions(&ker,&opt,C,e,1);
    }

    /* compute the solution */
    model = svm_train(&prob,&param);
    if ( mxIsEmpty(prhs[1]) )
      buildSolution(plhs,prhs[3],model,&prob,&opt,nlhs,2,N);
    else
      buildSolution(plhs,prhs[3],model,&prob,&opt,nlhs,1,N);


    /* dump information about solution into MATLAB window */
    if (opt.verbose > 0) {
      if ( mxIsEmpty(prhs[1]) )
        dumpSolution(&opt,model,&prob,y,C,2,N,(nlhs>1));
      else
        dumpSolution(&opt,model,&prob,y,C,1,N,(nlhs>1));
    }

    /* the model is no longer needed */
    svm_destroy_model(model);
  }

  /* --- SVM regression --- */

  else if ( !mxIsEmpty(prhs[1]) &&   /* one-class SVM not allowed */
            mxGetNumberOfElements(prhs[3]) == 1 &&
            mxIsDouble(prhs[3]) &&
            !mxIsComplex(prhs[3]) &&
            mxGetScalar(prhs[3]) >= 0 ) {

    if (nrhs<5)
      mexErrMsgTxt("Invalid number of input arguments.");

    if ( mxGetNumberOfElements(prhs[4]) != 1 ||
         !mxIsStruct(prhs[4]) )
      mexErrMsgTxt("Invalid fifth argument (kernel function).");

    /* get epsilon, kernel and options */
    e = mxGetScalar(prhs[3]);

    if ( getKernel(&ker,prhs[4],n) ||
         ker.type == KERNEL_GAUSS )
      mexErrMsgTxt("Invalid fourth argument (kernel function).");

    if ( nrhs>5 ) {
      getOptionsStruct(&mlopt,prhs+5,nrhs-5);
      getOptions(&opt,mlopt,N);
    }

    /* check nu value (e is treated as nu) */
    if ( opt.style == 1 && e > 1 )
      mexErrMsgTxt("Invalid fourth argument (nu).");

    /* solve the regression problem */
    convOptions(&param,C,e,&ker,&opt,0);
    convData(&prob,x,y,n,N);

    /* dump information about options and settings into MATLAB window */
    if (opt.verbose > 0)
      dumpOptions(&ker,&opt,C,e,0);

    model = svm_train(&prob,&param);
    buildSolution(plhs,prhs[4],model,&prob,&opt,nlhs,0,N);

    /* dump information about solution into MATLAB window */
    if (opt.verbose > 0)
      dumpSolution(&opt,model,&prob,y,C,0,N,(nlhs>1));

    /* the model is no longer needed */
    svm_destroy_model(model);
  }

  else
    mexErrMsgTxt("Invalid fourth argument (kernel function).");

}
