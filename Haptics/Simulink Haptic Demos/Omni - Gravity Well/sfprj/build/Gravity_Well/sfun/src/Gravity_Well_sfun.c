/* Include files */
#include "Gravity_Well_sfun.h"
#include "c1_Gravity_Well.h"
#include "c3_Gravity_Well.h"
#include "c4_Gravity_Well.h"
#include "c5_Gravity_Well.h"
#include "c7_Gravity_Well.h"
#include "c8_Gravity_Well.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint8_T _sfEvent_;
uint32_T _Gravity_WellMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void Gravity_Well_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void Gravity_Well_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Gravity_Well_method_dispatcher(SimStruct *simstructPtr, unsigned
 int chartFileNumber, int_T method, void *data)
{
  if(chartFileNumber==1) {
    c1_Gravity_Well_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  if(chartFileNumber==3) {
    c3_Gravity_Well_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  if(chartFileNumber==4) {
    c4_Gravity_Well_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  if(chartFileNumber==5) {
    c5_Gravity_Well_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  if(chartFileNumber==7) {
    c7_Gravity_Well_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  if(chartFileNumber==8) {
    c8_Gravity_Well_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  return 0;
}
unsigned int sf_Gravity_Well_process_check_sum_call( int nlhs, mxArray * plhs[],
 int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1562691747U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2181780510U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(997253598U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2820897347U);
    }else if(!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    }else if(!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1778840437U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2585333490U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(469234060U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3545393237U);
    }else if(nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch(chartFileNumber) {
       case 1:
        {
          extern void sf_c1_Gravity_Well_get_check_sum(mxArray *plhs[]);
          sf_c1_Gravity_Well_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_Gravity_Well_get_check_sum(mxArray *plhs[]);
          sf_c3_Gravity_Well_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_Gravity_Well_get_check_sum(mxArray *plhs[]);
          sf_c4_Gravity_Well_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_Gravity_Well_get_check_sum(mxArray *plhs[]);
          sf_c5_Gravity_Well_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_Gravity_Well_get_check_sum(mxArray *plhs[]);
          sf_c7_Gravity_Well_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_Gravity_Well_get_check_sum(mxArray *plhs[]);
          sf_c8_Gravity_Well_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(597643284U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3627036164U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4197951395U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(882897289U);
  }
  return 1;
#else
  return 0;
#endif
}

unsigned int sf_Gravity_Well_autoinheritance_info( int nlhs, mxArray * plhs[],
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
     case 1:
      {
        extern mxArray *sf_c1_Gravity_Well_get_autoinheritance_info(void);
        plhs[0] = sf_c1_Gravity_Well_get_autoinheritance_info();
        break;
      }

     case 3:
      {
        extern mxArray *sf_c3_Gravity_Well_get_autoinheritance_info(void);
        plhs[0] = sf_c3_Gravity_Well_get_autoinheritance_info();
        break;
      }

     case 4:
      {
        extern mxArray *sf_c4_Gravity_Well_get_autoinheritance_info(void);
        plhs[0] = sf_c4_Gravity_Well_get_autoinheritance_info();
        break;
      }

     case 5:
      {
        extern mxArray *sf_c5_Gravity_Well_get_autoinheritance_info(void);
        plhs[0] = sf_c5_Gravity_Well_get_autoinheritance_info();
        break;
      }

     case 7:
      {
        extern mxArray *sf_c7_Gravity_Well_get_autoinheritance_info(void);
        plhs[0] = sf_c7_Gravity_Well_get_autoinheritance_info();
        break;
      }

     case 8:
      {
        extern mxArray *sf_c8_Gravity_Well_get_autoinheritance_info(void);
        plhs[0] = sf_c8_Gravity_Well_get_autoinheritance_info();
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
unsigned int sf_Gravity_Well_get_eml_resolved_functions_info( int nlhs, mxArray
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
     case 1:
      {
        extern const mxArray
        *sf_c1_Gravity_Well_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray
          *)sf_c1_Gravity_Well_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
        *sf_c3_Gravity_Well_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray
          *)sf_c3_Gravity_Well_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
        *sf_c4_Gravity_Well_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray
          *)sf_c4_Gravity_Well_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
        *sf_c5_Gravity_Well_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray
          *)sf_c5_Gravity_Well_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
        *sf_c7_Gravity_Well_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray
          *)sf_c7_Gravity_Well_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
        *sf_c8_Gravity_Well_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray
          *)sf_c8_Gravity_Well_get_eml_resolved_functions_info();
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
void Gravity_Well_debug_initialize(void)
{
  _Gravity_WellMachineNumber_ =
  sf_debug_initialize_machine("Gravity_Well","sfun",0,6,0,0,0);
  sf_debug_set_machine_event_thresholds(_Gravity_WellMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_Gravity_WellMachineNumber_,0);
}

void Gravity_Well_register_exported_symbols(SimStruct* S)
{
}
