
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

#include <string.h>
#include <math.h>
#include "mex.h"
#include "libsvmaux.h"


/*----------------------------------------------------------------------------*\
| Fetch kernel function from MATLAB.                                           |
\*----------------------------------------------------------------------------*/

int getKernel(             /* Return: 0 on success, 1 on failure */
  kernel *ker,             /* [out] kernel as needed by the algorithms */
  const mxArray *mlker,    /* [in] kernel as provided by MATLAB */
  long n )                 /* [in] input dimension (n<=0: adjust it to mlker) */

{
  long k, m;               /* counters */
  int d;                   /* flag */
  char strbuf[mxMAXNAM];   /* buffer for contents of type field */
  mxArray *F, *F2;         /* fields of MATLAB struct */

  /* --- check if type field is a string --- */

  if ( (F=mxGetField(mlker,0,FNAME_TYPE)) == NULL ||
       mxIsEmpty(F) ||
       mxGetNumberOfDimensions(F) > 2 ||
       !mxIsChar(F) )
    return 1;
  else
    mxGetString(F,strbuf,mxMAXNAM+1);

  /* --- check if "mlker" is a valid linear kernel --- */

  if ( !strcmp(strbuf,KNAME_LINEAR) ) {
    ker->type = KERNEL_LINEAR;
    return 0;
  }

  /* --- check if "mlker" is a valid polynomial kernel --- */

  else if ( !strcmp(strbuf,KNAME_POLY) &&
            (F=mxGetField(mlker,0,FNAME_DEGR)) != NULL &&
            mxGetNumberOfElements(F) == 1 &&
            mxIsDouble(F) &&
            !mxIsComplex(F) &&
            mxGetScalar(F) >= 1 &&
            (F2=mxGetField(mlker,0,FNAME_OFFSET)) != NULL &&
            mxGetNumberOfElements(F2) == 1 &&
            mxIsDouble(F2) &&
            !mxIsComplex(F2)) {
    if ( (int)mxGetScalar(F) == 1 && mxGetScalar(F2) == 0.0 )
      ker->type = KERNEL_LINEAR;
    else {
      ker->type = KERNEL_POLY;
      ker->degree = (int)mxGetScalar(F);
      ker->offset = mxGetScalar(F2);
    }
    return 0;
  }

  /* --- check if "mlker" is a valid Gauss kernel --- */

  else if ( !strcmp(strbuf,KNAME_GAUSS) &&
            (F=mxGetField(mlker,0,FNAME_WIDTH)) != NULL &&
            !mxIsEmpty(F) &&
            mxGetNumberOfDimensions(F) <= 2 &&
            (mxGetN(F) == 1 || mxGetM(F) == 1) &&
            mxIsDouble(F) &&
            !mxIsComplex(F) )
  {
    m = mxGetNumberOfElements(F);
    if (n<1)               /* if n is not specified: */
      n = m;               /* take it from MATLAB struct */
    else if (m>n)          /* if more widths than dimensions: */
      m = n;               /* ignore the rest */

    for (k=0; k<m; k++) {  /* all widths positive? */
      if (mxGetPr(F)[k] <= 0)
        return 1;
    }
    d = 0;                 /* different vector elements? */
    for (k=1; k<m; k++) {
      if (mxGetPr(F)[k] != mxGetScalar(F))
        d = 1;
    }
    if (m == 1 || d == 0) {    /* use scalar gamma */
      ker->type = KERNEL_RADIAL;
      ker->gamma = 0.5/(mxGetScalar(F)*mxGetScalar(F));
    }
    else {                 /* use gamma vector */
      ker->type = KERNEL_GAUSS;
      ker->gamman = n;
      ker->gammav = mxMalloc(n*sizeof(double));
      for (k=0; k<m; k++)
        ker->gammav[k] = 0.5/(mxGetPr(F)[k]*mxGetPr(F)[k]);
      for ( ; k<n; k++)
        ker->gammav[k] = ker->gammav[m-1];
    }
    return 0;
  }

  /* --- check if "mlker" is a valid tanh kernel --- */

  else if ( !strcmp(strbuf,KNAME_TANH) &&
            (F=mxGetField(mlker,0,FNAME_GAMMA)) != NULL &&
            mxGetNumberOfElements(F) == 1 &&
            mxIsDouble(F) &&
            !mxIsComplex(F) &&
            mxGetScalar(F) > 0 &&
            (F2=mxGetField(mlker,0,FNAME_OFFSET)) != NULL &&
            mxGetNumberOfElements(F2) == 1 &&
            mxIsDouble(F2) &&
            !mxIsComplex(F2) &&
            mxGetScalar(F2) < 0 ) {
    ker->type = KERNEL_TANH;
    ker->gamma = mxGetScalar(F);
    ker->offset = mxGetScalar(F2);
    return 0;
  }

  /* --- otherwise return an error --- */

  return 1;
}


/*----------------------------------------------------------------------------*\
| Fetch MATLAB SVM struct into multiple variables.                             |
\*----------------------------------------------------------------------------*/

int getSvm(                /* Return: 0 on success, 1 on failure */
  const mxArray *mlsvm,    /* [in] SVM as provided by MATLAB */
  double **a,              /* [out] *a points to the SVM coefficients */
  double **xs,             /* [out] *xs points to the support vectors */
  long    *Ns,             /* [out] number of support vectors */
  long    *n,              /* [out] input dimension */
  double  *b,              /* [out] bias term */
  kernel  *ker )           /* [out] kernel function struct */

{
  mxArray *F;              /* field of MATLAB struct */

  /* --- check for valid SVM coefficients --- */

  if ( (F=mxGetField(mlsvm,0,FNAME_COEF)) == NULL ||
       mxIsEmpty(F) ||
       mxGetNumberOfDimensions(F) > 2 ||
       !mxIsDouble(F) ||
       mxIsComplex(F) )
    return 1;

  /* --- check for valid support vectors --- */

  if ( (F=mxGetField(mlsvm,0,FNAME_VECT)) == NULL ||
       mxIsEmpty(F) ||
       mxGetNumberOfDimensions(F) > 2 ||
       !mxIsDouble(F) ||
       mxIsComplex(F) ||
       mxGetM(F) != mxGetM(mxGetField(mlsvm,0,FNAME_COEF)) )
    return 1;

  /* --- check for valid bias term --- */

  if ( (F=mxGetField(mlsvm,0,FNAME_BIAS)) == NULL ||
       mxGetNumberOfElements(F) != 1 ||
       !mxIsDouble(F) ||
       mxIsComplex(F) )
    return 1;

  /* --- try to get kernel struct using getKernel() --- */

  if ( (F=mxGetField(mlsvm,0,FNAME_KER)) == NULL ||
       getKernel(ker,F,mxGetN(mxGetField(mlsvm,0,FNAME_VECT))) )
    return 1;

  /* --- get all other data --- */

  *a  = mxGetPr(mxGetField(mlsvm,0,FNAME_COEF));
  *xs = mxGetPr(mxGetField(mlsvm,0,FNAME_VECT));
  *Ns = mxGetM(mxGetField(mlsvm,0,FNAME_VECT));
  *n  = mxGetN(mxGetField(mlsvm,0,FNAME_VECT));
  *b  = mxGetScalar(mxGetField(mlsvm,0,FNAME_BIAS));

  return 0;
}


/*----------------------------------------------------------------------------*\
| Get pointer to MATLAB option struct; convert key/value pairs if necessary.   |
\*----------------------------------------------------------------------------*/

int getOptionsStruct(         /* Return: always 0 */
  const mxArray **mlopt,      /* [out] pointer to MATLAB options struct */
  const mxArray *optlist[],   /* [in] pointer to the element after the kernel */
  int nopt )                  /* [in] number of elements after the kernel */

{
  /* --- in case of input struct pass struct to getOptions -- */

  if (mxIsStruct(optlist[0])) {
    if (nopt == 1 && mxGetNumberOfElements(optlist[0]) == 1)
      *mlopt = optlist[0];
    else
      mexErrMsgTxt("Invalid argument (options).");
  }

  /* --- check for key/value structure --- */

  else {
    mxArray *temp;            /* needed since **mlopt must not be changed */
    char strbuf[mxMAXNAM];    /* string buffer */
    int k;

    if (nopt % 2 == 1)
      mexErrMsgTxt("Invalid options structure (string,value)");
    for (k=0; k<nopt; k+=2) {
      if ( !mxIsChar(optlist[k]) ||
           mxGetM(optlist[k]) != 1 &&
           mxGetN(optlist[k]) != 1 )
        mexErrMsgTxt("Invalid options structure (string,value)");
    }

    temp = mxCreateStructMatrix(1,1,0,NULL);
    for (k=0; k<nopt; k+=2) {
      mxGetString(optlist[k],strbuf,mxMAXNAM+1);
      mxSetFieldByNumber(temp, 0, mxAddField(temp, strbuf),
      mxDuplicateArray(optlist[k+1]));
    }
    *mlopt = temp;
  }

  return 0;
}


/*----------------------------------------------------------------------------*\
| Fetch MATLAB options into struct variable.                                   |
\*----------------------------------------------------------------------------*/

int getOptions(            /* Return: 0 on success, 1 on failure */
  options       *opt,      /* [out] struct for optimizer options */
  const mxArray *mlopt,    /* [in] options as provided by MATLAB */
  long           N )       /* [in] number of data */

{
  int k,l;                 /* counter */
  mxArray *F;              /* field of options struct */
  char strbuf[mxMAXNAM];
  char strbuf2[mxMAXNAM];
  float temp;

  for (k=0; k<mxGetNumberOfFields(mlopt); k++) {
    F = mxGetFieldByNumber(mlopt,0,k);

    /* --- Treat option FNAME_TOL --- */

    if ( !strcmp(mxGetFieldNameByNumber(mlopt,k),FNAME_TOL) ) {
      if ( mxGetNumberOfElements(F) == 1 &&
           mxIsDouble(F) &&
           !mxIsComplex(F) &&
           mxGetScalar(F) >= 0 )
        opt->tol = mxGetScalar(F);
      else
        mexWarnMsgTxt("Invalid option \"" FNAME_TOL "\" ignored.");
    }

    /* --- Treat option FNAME_CACHE --- */

    else if ( !strcmp(mxGetFieldNameByNumber(mlopt,k),FNAME_CACHE) ) {
      if ( mxGetNumberOfElements(F) == 1 &&
           mxIsDouble(F) &&
           !mxIsComplex(F) &&
           mxGetScalar(F) >= 1 )
        opt->cache = (double)(sizeof(double)*N*(long)mxGetScalar(F))/(1024.0*1024.0);

      else if ( mxIsChar(F) &&
                !mxIsEmpty(F) &&
                mxGetM(F) == 1 &&
                mxGetNumberOfDimensions(F) == 2 ) {
        mxGetString(F,strbuf,mxMAXNAM+1);

        for (l=0;l<mxMAXNAM;l++)
          strbuf[l]=tolower(strbuf[l]);

        if ( sscanf(strbuf,"%g",&temp) != EOF &&
             sscanf(strbuf,"%*g %s",strbuf2) != EOF ) {
          if ( strcmp(strbuf2,"mb") == 0 )
            opt->cache = (double)temp;
          else if ( strcmp(strbuf2,"kb") == 0 )
            opt->cache = (double)temp/1024;
          else
            mexWarnMsgTxt("Invalid option \"" FNAME_CACHE "\" ignored.");
        }
        else
          mexWarnMsgTxt("Invalid option \"" FNAME_CACHE "\" ignored.");
      }
      else
        mexWarnMsgTxt("Invalid option \"" FNAME_CACHE "\" ignored.");
    }

    /*  --- Treat option FNAME_SHRINK --- */

    else if ( !strcmp(mxGetFieldNameByNumber(mlopt,k),FNAME_SHRINK) ) {
      if ( mxGetNumberOfElements(F) == 1 &&
           mxIsDouble(F) &&
           !mxIsComplex(F) &&
           mxGetScalar(F) >= 0 )
        opt->shrink = (int)mxGetScalar(F);
      else
        mexWarnMsgTxt("Invalid option \"" FNAME_SHRINK "\" ignored.");
    }

    /* --- Treat option FNAME_WEIGHT --- */

    else if ( !strcmp(mxGetFieldNameByNumber(mlopt,k),FNAME_WEIGHT) ) {
      if ( mxGetNumberOfElements(F) == 1 &&
           mxIsDouble(F) &&
           !mxIsComplex(F) &&
           mxGetScalar(F) >= 0 )
        opt->weight = mxGetScalar(F);
      else
        mexWarnMsgTxt("Invalid option \"" FNAME_WEIGHT "\" ignored.");
    }

    /* --- Treat option FNAME_WLABEL --- */

    else if ( !strcmp(mxGetFieldNameByNumber(mlopt,k),FNAME_WLABEL) ) {
      if ( mxGetNumberOfElements(F) == 1 &&
           mxIsDouble(F) &&
           !mxIsComplex(F) )
        opt->wlabel = (int)mxGetScalar(F);
      else
        mexWarnMsgTxt("Invalid option \"" FNAME_WLABEL "\" ignored.");
    }

    /* --- Treat option FNAME_VERBOSE --- */

    else if ( !strcmp(mxGetFieldNameByNumber(mlopt,k),FNAME_VERBOSE) ) {
      if ( mxGetNumberOfElements(F) == 1 &&
           mxIsDouble(F) &&
           !mxIsComplex(F) &&
           mxGetScalar(F) >= 0 )
      opt->verbose = (int)mxGetScalar(F);
    else
      mexWarnMsgTxt("Invalid option \"" FNAME_VERBOSE "\" ignored.");
    }

    /* --- Treat option FNAME_STYLE --- */

    else if ( !strcmp(mxGetFieldNameByNumber(mlopt,k),FNAME_STYLE) ) {
      if ( mxIsChar(F) &&
           !mxIsEmpty(F) &&
           mxGetM(F) == 1 &&
           mxGetNumberOfDimensions(F) == 2) {
        if (mxGetScalar(F) == 'n')
          opt->style = 1;
        else
          opt->style = 0;
      }
      else
        mexWarnMsgTxt("Invalid option \"" FNAME_STYLE "\" ignored.");
    }

    /* --- Treat option FNAME_PROBOPT --- */

    else if ( !strcmp(mxGetFieldNameByNumber(mlopt,k),FNAME_PROBOPT) ) {
      if ( mxGetNumberOfElements(F) == 1 &&
           mxIsDouble(F) &&
           !mxIsComplex(F) &&
           mxGetScalar(F) >= 0 )
        opt->prob = (int)mxGetScalar(F);
      else
        mexWarnMsgTxt("Invalid option \"" FNAME_PROBOPT "\" ignored.");
    }
  }

  return 0;
}


/*----------------------------------------------------------------------------*\
| Dump information about settings into MATLAB window.                          |
\*----------------------------------------------------------------------------*/

int dumpOptions(           /* Return: always 0 */
  kernel  *ker,            /* [in] kernel struct */
  options *opt,            /* [in] option struct */
  double   C,              /* [in] C or nu */
  double   e,              /* [in] epsilon or nu */
  int      svmproblem )    /* [in] 0: SVR, 1: SVC, 2: One-Class */

{
  mexPrintf("--------------------\n");
  mexPrintf("OPTIONS\n");
  switch ( svmproblem ) {
    case 0: if (opt->style == 0) {
              mexPrintf("SVM type:    EPS-SVR\n");
              mexPrintf("Bound C:     %g\n",C);
              mexPrintf("Epsilon:     %g\n",e);
            }
            else {
              mexPrintf("SVM type:    NU-SVR\n");
              mexPrintf("Bound C:     %g\n",C);
              mexPrintf("Nu:          %g\n",e);
            }
            break;

    case 1: if (opt->style == 0) {
              mexPrintf("SVM type:    C-SVC\n");
              mexPrintf("Bound C:     %g\n",C);
            }
            else {
              mexPrintf("SVM type:    NU-SVC\n");
              mexPrintf("Nu:          %g\n",C);
            }
            break;

    case 2: mexPrintf("SVM type:    ONE-CLASS\n");
            mexPrintf("Nu:          %g\n",C);
            break;
  }

  /* --- Kernel section --- */

  switch ( ker->type ) {
    case KERNEL_LINEAR:
      mexPrintf("Kernel:      Linear\n");
      break;

    case KERNEL_POLY:
      mexPrintf("Kernel:      Polynomial\n");
      mexPrintf("Degree:      %d\n",ker->degree);
      mexPrintf("Offset:      %g\n",ker->offset);
      break;

    case KERNEL_RADIAL:
      mexPrintf("Kernel:      Gauss\n");   /* 'radial' only for internal use */
      mexPrintf("Width:       %g\n",1/sqrt(2*ker->gamma));
      break;

    case KERNEL_GAUSS:
      mexPrintf("Kernel:      Gauss\n");
      mexPrintf("Width:       Vector, size %d\n", ker->gamman);
      break;

    case KERNEL_TANH:
      mexPrintf("Kernel:      Tanh\n");
      mexPrintf("Gamma:       %g\n",ker->gamma);
      mexPrintf("Offset:      %g\n",ker->offset);
      break;
  }

  /* --- Options section --- */

  if ( svmproblem==1 && opt->style==0 ) {
    mexPrintf("Weight:      %g\n",opt->weight);
    mexPrintf("Wght. Label: %d\n",opt->wlabel);
  }
  mexPrintf("Tolerance:   %g\n",opt->tol);
  mexPrintf("Shrinking:   %s\n",(opt->shrink ? "Yes" : "No"));
  mexPrintf("Cache:       %2.2g MB\n",opt->cache);
  if ( svmproblem==1 )
    mexPrintf("Probability: %s\n",(opt->prob ? "Yes" : "No"));
  mexPrintf("--------------------\n");

  return 0;
}


/*----------------------------------------------------------------------------*\
| Dump information about solution into MATLAB window.                          |
\*----------------------------------------------------------------------------*/

int dumpSolution(             /* Return: always 0 */
  options *opt,               /* [in] option struct */
  struct svm_model *model,    /* [in] the model calculated by LIBSVM */
  struct svm_problem *prob,   /* [in] LIBSVM problem struct */
  double  *y,                 /* [in] output data */
  double   C,                 /* [in] C or nu */
  int      svmproblem,        /* [in] 0: SVR, 1: SVC, 2: One-Class */
  long     N,                 /* [in] number of data */
  int      adjust )           /* [in] 0: -, 1: adjust to labels +1/-1 */

{
  mexPrintf("SOLUTION\n");
  mexPrintf("#SVs:        %d\n",model->l);


  /* --- determin bounded support vectors --- */

  if ( model->sv_coef != NULL && (model->param.svm_type == C_SVC ||
                                  model->param.svm_type == EPSILON_SVR ||
                                  model->param.svm_type == NU_SVR) ) {
    long i;                         /* counter */
    long bsv = 0;                   /* number of bounded SVs */
    for (i=0; i<model->l; i++) {    /* determine bounded SVs */
      if ( fabs(model->sv_coef[0][i]) == C )
        bsv++;
    }
    mexPrintf("#BSVs:       %d\n",bsv);
  }

  /* --- compute bias term --- */

  if (model->rho != NULL) {
    double f = 1;                 /* correction factor, see buildSolution */
    if (adjust>0 && model->label != NULL)
      f = model->label[0];
    mexPrintf("Bias:        %g\n",-f*model->rho[0]);
  }

  /* --- compute epsilon for NU-SVR --- */

  if (opt->style == 1 && svmproblem == 0) {
    double eps = 0;               /* computed epsilon value */
    long   c = 0;                 /* number of free SVs */
    long   k,g;                   /* counters */

    for (k=0; k<model->l; k++) {
      if (fabs(model->sv_coef[0][k]) < C && model->sv_coef[0][k] != 0.0) {
        for (g=0; g<N; g++) {
          if (prob->x[g] == model->SV[k]) {
            eps += fabs(y[g]-svm_predict(model,model->SV[k]));
            c++;
            break;
          }
        }
      }
    }
    mexPrintf("Epsilon:     %g\n",eps/c);
  }
  mexPrintf("--------------------\n");

  return 0;
}


/*----------------------------------------------------------------------------*\
| Convert options to LIBSVM parameter struct.                                  |
\*----------------------------------------------------------------------------*/

int convOptions(                /* Return: always 0 */
  struct svm_parameter *param,  /* [out] LIBSVM parameter struct */
  double C,                     /* [in] upper bound for Lagrange multipliers */
  double e,                     /* [in] epsilon for regression case */
  kernel *ker,                  /* [in] kernel struct */
  options *opt,                 /* [in] options struct */
  int svmproblem )              /* [in] 0: SVR, 1: SVC, 2: One-Class */

{
  param->eps = opt->tol;
  param->cache_size = opt->cache;
  param->shrinking = opt->shrink;
  param->probability = opt->prob;

  /* --- set SVM type, C, epsilon and nu --- */

  if (svmproblem == 1) {            /* classification case */
    if (opt->style == 1) {          /* the 'nu' case check */
      param->nu = C;
      param->svm_type = NU_SVC;
    }
    else {
      param->C = C;
      param->svm_type = C_SVC;
    }
  }
  else if (svmproblem == 0 ) {      /* regression case */
    param->C = C;
    if (opt->style == 1) {          /* the 'nu' case check */
      param->nu = e;
      param->svm_type = NU_SVR;
    }
    else {
      param->p = e;
      param->svm_type = EPSILON_SVR;
    }
  }
  else {                            /* one-class case */
    param->nu = C;
    param->svm_type = ONE_CLASS;
  }

  /* --- acivate weighting if needed --- */

  if (opt->weight == 1) {
    param->nr_weight = 0;
    param->weight_label = NULL;
    param->weight = NULL;
  }
  else {
    param->nr_weight = 1;
    param->weight_label = (int*)malloc(1*sizeof(int));
    param->weight_label[0] = opt->wlabel;
    param->weight = (double*)malloc(sizeof(double));
    param->weight[0] = opt->weight;
  }

  /* --- get parameters from given MATLAB option struct --- */

  if (ker->type == KERNEL_LINEAR) {       /* if it shall be a linear kernel */
    param->kernel_type = LINEAR;          /* make it a linear one */
  }
  else if (ker->type == KERNEL_POLY) {    /* if it shall be a polyl kernel */
    param->kernel_type = POLY;            /* make it a polynomial one */
    param->gamma = 1;                     /* k(x,y)=(gamma*x'*y+coef0)^degree */
    param->degree = ker->degree;          /* degree of polynomial kernel */
    param->coef0 = ker->offset;           /* coef0 is offset in svmas */
  }
  else if (ker->type == KERNEL_TANH) {    /* if it shall be a tanh kernel */
    param->kernel_type = SIGMOID;         /* make it a sigmoid one */
    param->gamma = ker->gamma;            /* k(x,y)=(gamma*x'*y+coef0)^degree */
    param->coef0 = ker->offset;           /* coef0 is offset in svmas */
  }
  else if (ker->type == KERNEL_RADIAL) {  /* if it shall be a Gauss kernel */
    param->kernel_type = RBF;             /* use the RBF one, it's the same */
    param->gamma = ker->gamma;            /* and use the same gamma-value */
  }

  return 0;
}


/*----------------------------------------------------------------------------*\
| Convert data to LIBSVM problem struct.                                       |
\*----------------------------------------------------------------------------*/

int convData(                 /* Return: always 0 */
  struct svm_problem *prob,   /* [out] LIBSVM problem struct */
  double *x,                  /* [in] input data */
  double *y,                  /* [in] output data */
  int n,                      /* [in] input dimension */
  long N )                    /* [in] number of data */

{
  struct svm_node *x_space;   /* svm_nodes needed to create the svm-problem */
  int j1;                     /* rows in x-matrix */
  int i;                      /* coloumns in x-matrix */
  int j2;                     /* counter for svm_nodes*/

  /* --- allocate needed memory --- */

  prob->l = N;
  prob->x = mxMalloc(N*sizeof(struct svm_node *));
  prob->y = mxMalloc(N*sizeof(double));
  x_space = mxMalloc(N*(n+1)*sizeof(struct svm_node));

  /* --- build the SVM nodes --- */

  j1 = 0;
  for(i=0;i<N;i++) {                   /* iterate rows */
    prob->x[i] = x_space+j1;           /* set pointer to the svm_node */
    if (y==NULL)
      prob->y[i] = 1;
    else
      prob->y[i] = y[i];

    for(j2=0;j2<n;j2++) {              /* iterate columns in current row */
      x_space[j1].index=j2;            /* create index-value of svm_node */
      x_space[j1].value=x[i+N*j2];     /* create value-value of svm_node */
      j1++;
    }
    x_space[j1].index = -1;
    j1++;
  }

  return 0;
}


/*----------------------------------------------------------------------------*\
| Build MATLAB solution from LIBSVM model.                                     |
\*----------------------------------------------------------------------------*/

int buildSolution(           /* Return: always 0 */
  mxArray **solut,           /* [out] solution struct (empty on entry) */
  const mxArray *mlker,      /* [in] kernel as provided by MATLAB */
  struct svm_model *model,   /* [in] the model calculated by LIBSVM */
  struct svm_problem *prob,  /* [in] LIBSVM problem struct */
  options *opt,              /* [in] options struct */
  int nlhs,                  /* [in] number of output arguments */
  int svmproblem,            /* [in] 0: SVR, 1: SVC, 2: One-Class */
  long N )                   /* [in] number of input data */

{
  long i,j,k,g;              /* counters */
  long Nsv;                  /* number of support vectors */
  long n;                    /* input dimension */
  double f;                  /* correction factor */
  double *a;                 /* coefficients in MATLAB struct */
  double *x;                 /* support vectors in MATLAB struct */
  double **sv_coef;          /* computed SVM coefficients */
  struct svm_node **SV;      /* support vectors */
  struct svm_node *row;      /* row of SV */
  const char *fields[] = {FNAME_COEF, FNAME_VECT, FNAME_BIAS, FNAME_KER};

  /* --- determine correction factor --- */

  f = 1;                     /* regression, and class. with arbitrary labels */
  if (nlhs>1 && model->label != NULL)  /* class. with labels +1 and -1 */
    f = model->label[0];     /* first label is regarded as +1 (!) */

  /* --- return reduced coef vector, indices, and bias --- */

  if (nlhs>2) {
    solut[0] = mxCreateDoubleMatrix(model->l,1,mxREAL);
    solut[1] = mxCreateDoubleMatrix(model->l,1,mxREAL);
    solut[2] = mxCreateDoubleMatrix(1,1,mxREAL);

    mxGetPr(solut[2])[0] = -f*model->rho[0];

    for (g=0;g<model->l;g++) {
      for (k=0;k<N;k++) {
        if (prob->x[k] == model->SV[g] ) {
          mxGetPr(solut[0])[g] = f*model->sv_coef[0][g];
          mxGetPr(solut[1])[g] = k+1;
          break;
        }
      }
    }
  }

  /* --- return complete coef vector, and bias --- */

  else if (nlhs>1) {
    solut[0] = mxCreateDoubleMatrix(N,1,mxREAL);
    solut[1] = mxCreateDoubleMatrix(1,1,mxREAL);

    mxGetPr(solut[1])[0] = -f*model->rho[0];

    for (g=0;g<model->l;g++) {
      for (k=0;k<N;k++) {
        if (model->SV[g] == prob->x[k]) {
          mxGetPr(solut[0])[k] = f*model->sv_coef[0][g];
          break;
        }
      }
    }
  }

  /* --- return SVM struct --- */

  else {
    Nsv = model->l;
    sv_coef = model->sv_coef;
    SV = model->SV;

    /* find the input dimension */
    n = 0;
    for (i=0; i<Nsv; i++) {
      row = SV[i];
      j = 0;
      while (row[j].index != -1) {
        if (row[j].index > n)
          n = row[j].index;
        j++;
      }
    }
    n++;  /* because indices start from 0 */

    /* prepare the solution struct */
    *solut = mxCreateStructMatrix(1,1,4,fields);

    mxSetField(*solut,0,FNAME_COEF,mxCreateDoubleMatrix(Nsv,1,mxREAL));
    mxSetField(*solut,0,FNAME_VECT,mxCreateDoubleMatrix(Nsv,n,mxREAL));
    a = mxGetPr(mxGetField(*solut,0,FNAME_COEF));
    x = mxGetPr(mxGetField(*solut,0,FNAME_VECT));

    mxSetField(*solut,0,FNAME_BIAS,mxCreateDoubleMatrix(1,1,mxREAL));
    mxGetPr(mxGetField(*solut,0,FNAME_BIAS))[0] = -f * *(model->rho);

    mxSetField(*solut,0,FNAME_KER,mxDuplicateArray(mlker));

    if ( svmproblem == 1 && model->label != NULL ) {
      mxAddField(*solut,FNAME_LABEL);
      mxSetField(*solut,0,FNAME_LABEL,mxCreateDoubleMatrix(1,2,mxREAL));
      mxGetPr(mxGetField(*solut,0,FNAME_LABEL))[0] = model->label[0];
      mxGetPr(mxGetField(*solut,0,FNAME_LABEL))[1] = model->label[1];
    }

    if ( svmproblem == 1 && opt->prob != 0 &&
         model->probA != NULL && model->probB != NULL) {
      mxAddField(*solut,FNAME_PROB);
      mxSetField(*solut,0,FNAME_PROB,mxCreateDoubleMatrix(1,2,mxREAL));
      mxGetPr(mxGetField(*solut,0,FNAME_PROB))[0] = model->probA[0];
      mxGetPr(mxGetField(*solut,0,FNAME_PROB))[1] = model->probB[0];
    }

    /* copy LIBSVM model to MATLAB */
    for (i=0; i<Nsv; i++) {
      a[i] = f * sv_coef[0][i];  /* we are using only output #0 */
      row = SV[i];
      j = 0;
      while (row[j].index != -1) {
        /* x points to a row of the MATLAB matrix */
        x[Nsv*(row[j].index)] = row[j].value;
        j++;
      }
      x++;
    }
  }

  return 0;
}
