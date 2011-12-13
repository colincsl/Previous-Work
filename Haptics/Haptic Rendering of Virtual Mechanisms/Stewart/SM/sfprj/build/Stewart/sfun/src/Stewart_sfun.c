/* Include files */
#include "Stewart_sfun.h"
#include "c2_Stewart.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint8_T _sfEvent_;
uint32_T _StewartMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void Stewart_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void Stewart_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Stewart_method_dispatcher(SimStruct *simstructPtr, unsigned int
 chartFileNumber, int_T method, void *data)
{
  if(chartFileNumber==2) {
    c2_Stewart_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  return 0;
}
unsigned int sf_Stewart_process_check_sum_call( int nlhs, mxArray * plhs[], int
 nrhs, const mxArray * prhs[] )
{
#ifdef MATLAB_MEX_FILE
  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) ) return 0;
  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if(strcmp(commandName,"sf_get_check_sum")) return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if(nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if(!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1318766175U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3292526589U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1939123649U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1388072158U);
    }else if(!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    }else if(!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2092369889U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(151807565U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4237017808U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1477988202U);
    }else if(nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch(chartFileNumber) {
       case 2:
        {
          extern void sf_c2_Stewart_get_check_sum(mxArray *plhs[]);
          sf_c2_Stewart_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    }else if(!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(256657037U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(491452467U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1530433343U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4215106033U);
    }else {
      return 0;
    }
  } else{
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(219302547U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(72503906U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2252782750U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2756667164U);
  }
  return 1;
#else
  return 0;
#endif
}

unsigned int sf_Stewart_autoinheritance_info( int nlhs, mxArray * plhs[], int
 nrhs, const mxArray * prhs[] )
{
#ifdef MATLAB_MEX_FILE
  char commandName[32];
  if (nrhs<2 || !mxIsChar(prhs[0]) ) return 0;
  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if(strcmp(commandName,"get_autoinheritance_info")) return 0;
  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch(chartFileNumber) {
     case 2:
      {
        extern mxArray *sf_c2_Stewart_get_autoinheritance_info(void);
        plhs[0] = sf_c2_Stewart_get_autoinheritance_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }
  return 1;
#else
  return 0;
#endif
}
unsigned int sf_Stewart_get_eml_resolved_functions_info( int nlhs, mxArray *
 plhs[], int nrhs, const mxArray * prhs[] )
{
#ifdef MATLAB_MEX_FILE
  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0])) return 0;
  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if(strcmp(commandName,"get_eml_resolved_functions_info")) return 0;
  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch(chartFileNumber) {
     case 2:
      {
        extern const mxArray
        *sf_c2_Stewart_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray
          *)sf_c2_Stewart_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }
  return 1;
#else
  return 0;
#endif
}
void Stewart_debug_initialize(void)
{
  _StewartMachineNumber_ =
  sf_debug_initialize_machine("Stewart","sfun",0,1,0,0,0);
  sf_debug_set_machine_event_thresholds(_StewartMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_StewartMachineNumber_,0);
}

void Stewart_register_exported_symbols(SimStruct* S)
{
}
