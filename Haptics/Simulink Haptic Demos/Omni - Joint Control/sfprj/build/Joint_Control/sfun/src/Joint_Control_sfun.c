/* Include files */
#include "Joint_Control_sfun.h"
#include "c3_Joint_Control.h"
#include "c4_Joint_Control.h"
#include "c8_Joint_Control.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint8_T _sfEvent_;
uint32_T _Joint_ControlMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void Joint_Control_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void Joint_Control_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Joint_Control_method_dispatcher(SimStruct *simstructPtr,
 unsigned int chartFileNumber, int_T method, void *data)
{
  if(chartFileNumber==3) {
    c3_Joint_Control_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  if(chartFileNumber==4) {
    c4_Joint_Control_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  if(chartFileNumber==8) {
    c8_Joint_Control_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  return 0;
}
unsigned int sf_Joint_Control_process_check_sum_call( int nlhs, mxArray *
 plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3575415230U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(37938401U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3505806622U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3970204084U);
    }else if(!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    }else if(!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2805102212U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3947815265U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3916876336U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3921283294U);
    }else if(nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch(chartFileNumber) {
       case 3:
        {
          extern void sf_c3_Joint_Control_get_check_sum(mxArray *plhs[]);
          sf_c3_Joint_Control_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_Joint_Control_get_check_sum(mxArray *plhs[]);
          sf_c4_Joint_Control_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_Joint_Control_get_check_sum(mxArray *plhs[]);
          sf_c8_Joint_Control_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(570448906U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3021889091U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(331506758U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1650795723U);
  }
  return 1;
#else
  return 0;
#endif
}

unsigned int sf_Joint_Control_autoinheritance_info( int nlhs, mxArray * plhs[],
 int nrhs, const mxArray * prhs[] )
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
     case 3:
      {
        extern mxArray *sf_c3_Joint_Control_get_autoinheritance_info(void);
        plhs[0] = sf_c3_Joint_Control_get_autoinheritance_info();
        break;
      }

     case 4:
      {
        extern mxArray *sf_c4_Joint_Control_get_autoinheritance_info(void);
        plhs[0] = sf_c4_Joint_Control_get_autoinheritance_info();
        break;
      }

     case 8:
      {
        extern mxArray *sf_c8_Joint_Control_get_autoinheritance_info(void);
        plhs[0] = sf_c8_Joint_Control_get_autoinheritance_info();
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
unsigned int sf_Joint_Control_get_eml_resolved_functions_info( int nlhs, mxArray
 * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 3:
      {
        extern const mxArray
        *sf_c3_Joint_Control_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray
          *)sf_c3_Joint_Control_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
        *sf_c4_Joint_Control_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray
          *)sf_c4_Joint_Control_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
        *sf_c8_Joint_Control_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray
          *)sf_c8_Joint_Control_get_eml_resolved_functions_info();
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
void Joint_Control_debug_initialize(void)
{
  _Joint_ControlMachineNumber_ =
  sf_debug_initialize_machine("Joint_Control","sfun",0,3,0,0,0);
  sf_debug_set_machine_event_thresholds(_Joint_ControlMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_Joint_ControlMachineNumber_,0);
}

void Joint_Control_register_exported_symbols(SimStruct* S)
{
}
