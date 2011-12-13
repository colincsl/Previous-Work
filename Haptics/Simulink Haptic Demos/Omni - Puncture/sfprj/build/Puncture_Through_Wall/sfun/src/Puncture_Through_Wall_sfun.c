/* Include files */
#include "Puncture_Through_Wall_sfun.h"
#include "c2_Puncture_Through_Wall.h"
#include "c3_Puncture_Through_Wall.h"
#include "c4_Puncture_Through_Wall.h"
#include "c5_Puncture_Through_Wall.h"
#include "c8_Puncture_Through_Wall.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint8_T _sfEvent_;
uint32_T _Puncture_Through_WallMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void Puncture_Through_Wall_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void Puncture_Through_Wall_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Puncture_Through_Wall_method_dispatcher(SimStruct *simstructPtr,
 unsigned int chartFileNumber, int_T method, void *data)
{
  if(chartFileNumber==2) {
    c2_Puncture_Through_Wall_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  if(chartFileNumber==3) {
    c3_Puncture_Through_Wall_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  if(chartFileNumber==4) {
    c4_Puncture_Through_Wall_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  if(chartFileNumber==5) {
    c5_Puncture_Through_Wall_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  if(chartFileNumber==8) {
    c8_Puncture_Through_Wall_method_dispatcher(simstructPtr, method, data);
    return 1;
  }
  return 0;
}
unsigned int sf_Puncture_Through_Wall_process_check_sum_call( int nlhs, mxArray
 * plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1279818146U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1274118310U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2588770341U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1990866008U);
    }else if(!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    }else if(!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2842705630U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2451040814U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(507617392U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1661966988U);
    }else if(nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch(chartFileNumber) {
       case 2:
        {
          extern void sf_c2_Puncture_Through_Wall_get_check_sum(mxArray *plhs[]);
          sf_c2_Puncture_Through_Wall_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_Puncture_Through_Wall_get_check_sum(mxArray *plhs[]);
          sf_c3_Puncture_Through_Wall_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_Puncture_Through_Wall_get_check_sum(mxArray *plhs[]);
          sf_c4_Puncture_Through_Wall_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_Puncture_Through_Wall_get_check_sum(mxArray *plhs[]);
          sf_c5_Puncture_Through_Wall_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_Puncture_Through_Wall_get_check_sum(mxArray *plhs[]);
          sf_c8_Puncture_Through_Wall_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1475169084U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1458018394U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2436486080U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2114292031U);
  }
  return 1;
#else
  return 0;
#endif
}

unsigned int sf_Puncture_Through_Wall_autoinheritance_info( int nlhs, mxArray *
 plhs[], int nrhs, const mxArray * prhs[] )
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
        extern mxArray
        *sf_c2_Puncture_Through_Wall_get_autoinheritance_info(void);
        plhs[0] = sf_c2_Puncture_Through_Wall_get_autoinheritance_info();
        break;
      }

     case 3:
      {
        extern mxArray
        *sf_c3_Puncture_Through_Wall_get_autoinheritance_info(void);
        plhs[0] = sf_c3_Puncture_Through_Wall_get_autoinheritance_info();
        break;
      }

     case 4:
      {
        extern mxArray
        *sf_c4_Puncture_Through_Wall_get_autoinheritance_info(void);
        plhs[0] = sf_c4_Puncture_Through_Wall_get_autoinheritance_info();
        break;
      }

     case 5:
      {
        extern mxArray
        *sf_c5_Puncture_Through_Wall_get_autoinheritance_info(void);
        plhs[0] = sf_c5_Puncture_Through_Wall_get_autoinheritance_info();
        break;
      }

     case 8:
      {
        extern mxArray
        *sf_c8_Puncture_Through_Wall_get_autoinheritance_info(void);
        plhs[0] = sf_c8_Puncture_Through_Wall_get_autoinheritance_info();
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
unsigned int sf_Puncture_Through_Wall_get_eml_resolved_functions_info( int nlhs,
 mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
        *sf_c2_Puncture_Through_Wall_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray
          *)sf_c2_Puncture_Through_Wall_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
        *sf_c3_Puncture_Through_Wall_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray
          *)sf_c3_Puncture_Through_Wall_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
        *sf_c4_Puncture_Through_Wall_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray
          *)sf_c4_Puncture_Through_Wall_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
        *sf_c5_Puncture_Through_Wall_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray
          *)sf_c5_Puncture_Through_Wall_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
        *sf_c8_Puncture_Through_Wall_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray
          *)sf_c8_Puncture_Through_Wall_get_eml_resolved_functions_info();
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
void Puncture_Through_Wall_debug_initialize(void)
{
  _Puncture_Through_WallMachineNumber_ =
    sf_debug_initialize_machine("Puncture_Through_Wall","sfun",0,5,0,0,0);
  sf_debug_set_machine_event_thresholds(_Puncture_Through_WallMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_Puncture_Through_WallMachineNumber_,0);
}

void Puncture_Through_Wall_register_exported_symbols(SimStruct* S)
{
}