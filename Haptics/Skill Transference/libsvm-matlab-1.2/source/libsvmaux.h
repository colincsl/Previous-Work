
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

#include "svm.h"

/* LIBSVM's svm_model is not available in svm.h */
struct svm_model
{
  struct svm_parameter param;
  int nr_class;
  int l;
  struct svm_node **SV;
  double **sv_coef;
  double *rho;
  double *probA;
  double *probB;
  int *label;
  int *nSV;
  int free_sv;
};

/* kernel struct */
typedef struct {
  enum { KERNEL_LINEAR,
         KERNEL_POLY,
         KERNEL_RADIAL,
         KERNEL_GAUSS,
         KERNEL_TANH
       } type;         /* kernel function type */
  int    degree;       /* degree of polynomial kernel */
  double offset;       /* offset for poly and tanh kernel */
  double gamma;        /* coefficient of radial kernel & tanh kernel */
  double *gammav;      /* coefficient vector of Gauss kernel */
  long   gamman;       /* length of coefficient vector */
} kernel;

/* optimizer options */
typedef struct {
  double tol;          /* tolerance of KKT check */
  int    shrink;       /* shrinking heuristics (0/1)*/
  double cache;        /* cache size in MB */
  double weight;       /* weight factor for class -1 (or wlabel) */
  int    wlabel;       /* label of class to be weigthed */
  int    verbose;      /* verbose mode (0/1) */
  int    style;        /* 0: C/eps style, 1: nu style */
  int    prob;         /* compute probability information (0/1) */
} options;

/* kernel names */
#define KNAME_LINEAR  "linear"
#define KNAME_POLY    "poly"
#define KNAME_GAUSS   "gauss"
#define KNAME_TANH    "tanh"

/* kernel parameter names */
#define FNAME_TYPE    "type"
#define FNAME_GAMMA   "gamma"
#define FNAME_OFFSET  "offset"
#define FNAME_DEGR    "degree"
#define FNAME_WIDTH   "width"

/* SVM field names */
#define FNAME_COEF    "coef"
#define FNAME_VECT    "vect"
#define FNAME_BIAS    "bias"
#define FNAME_KER     "ker"
#define FNAME_LABEL   "label"
#define FNAME_PROB    "prob"

/* SVM option names */
#define FNAME_TOL     "tol"
#define FNAME_SHRINK  "shrink"
#define FNAME_CACHE   "cache"
#define FNAME_WEIGHT  "weight"
#define FNAME_WLABEL  "wlabel"
#define FNAME_VERBOSE "verbose"
#define FNAME_STYLE   "style"
#define FNAME_PROBOPT "prob"

/* prototypes of MATLAB interface functions */
int getKernel(kernel*, const mxArray*, long);
int getOptionsStruct(const mxArray**, const mxArray*[], int);
int getOptions(options*, const mxArray*, long);
int dumpOptions(kernel*, options*, double, double, int);
int dumpSolution(options*,struct svm_model*, struct svm_problem*, double*, double, int, long, int);
int getSvm(const mxArray*, double**, double**, long*, long*, double*, kernel*);
int convOptions( struct svm_parameter*, double, double, kernel*, options*, int );
int convData(struct svm_problem*, double*, double*, int, long);
int buildSolution(mxArray**, const mxArray*, struct svm_model*,struct svm_problem*, options *opt, int, int, long);
