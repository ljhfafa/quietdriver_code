//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: quietdriver.h
//
// Code generated for Simulink model 'quietdriver'.
//
// Model version                  : 5.36
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Tue Nov 19 01:06:44 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef quietdriver_h_
#define quietdriver_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "quietdriver_types.h"
#include <stddef.h>

// Class declaration for model quietdriver
class quietdriver
{
  // public data and function members
 public:
  // Block signals (default storage)
  struct B_quietdriver_T {
    SL_Bus_quietdriver_std_msgs_Float64 In1;// '<S10>/In1'
    SL_Bus_quietdriver_std_msgs_Float64 In1_m;// '<S9>/In1'
    SL_Bus_quietdriver_std_msgs_Float64 In1_f;// '<S8>/In1'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_quietdriver_T {
    ros_slroscpp_internal_block_P_T obj;// '<S2>/SinkBlock'
    ros_slroscpp_internal_block_S_T obj_e;// '<S6>/SourceBlock'
    ros_slroscpp_internal_block_S_T obj_h;// '<S5>/SourceBlock'
    ros_slroscpp_internal_block_S_T obj_j;// '<S4>/SourceBlock'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_quietdriver_T {
    const char_T * volatile errorStatus;
    const char_T* getErrorStatus() const;
    void setErrorStatus(const char_T* const volatile aErrorStatus);
  };

  // Real-Time Model get method
  quietdriver::RT_MODEL_quietdriver_T * getRTM();

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  quietdriver();

  // Destructor
  ~quietdriver();

  // private data and function members
 private:
  // Block signals
  B_quietdriver_T quietdriver_B;

  // Block states
  DW_quietdriver_T quietdriver_DW;

  // Real-Time Model
  RT_MODEL_quietdriver_T quietdriver_M;
};

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'quietdriver'
//  '<S1>'   : 'quietdriver/Blank Message1'
//  '<S2>'   : 'quietdriver/Publish'
//  '<S3>'   : 'quietdriver/Subsystem'
//  '<S4>'   : 'quietdriver/car-speed'
//  '<S5>'   : 'quietdriver/space-gap'
//  '<S6>'   : 'quietdriver/speed-gap'
//  '<S7>'   : 'quietdriver/Subsystem/MATLAB Function'
//  '<S8>'   : 'quietdriver/car-speed/Enabled Subsystem'
//  '<S9>'   : 'quietdriver/space-gap/Enabled Subsystem'
//  '<S10>'  : 'quietdriver/speed-gap/Enabled Subsystem'

#endif                                 // quietdriver_h_

//
// File trailer for generated code.
//
// [EOF]
//
