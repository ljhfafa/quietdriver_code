//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: quietdriver.cpp
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
#include "quietdriver.h"
#include <math.h>
#include "rtwtypes.h"
#include "quietdriver_types.h"

// Model step function
void quietdriver::step()
{
  SL_Bus_quietdriver_std_msgs_Float64 rtb_BusAssignment;
  SL_Bus_quietdriver_std_msgs_Float64 rtb_SourceBlock_o2_e_0;
  real_T u0;
  boolean_T b_varargout_1;

  // Outputs for Atomic SubSystem: '<Root>/space-gap'
  // MATLABSystem: '<S5>/SourceBlock'
  b_varargout_1 = Sub_quietdriver_82.getLatestMessage(&rtb_SourceBlock_o2_e_0);

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S9>/Enable'

  // Start for MATLABSystem: '<S5>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S9>/In1'
    quietdriver_B.In1_m = rtb_SourceBlock_o2_e_0;
  }

  // End of Start for MATLABSystem: '<S5>/SourceBlock'
  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/space-gap'

  // Outputs for Atomic SubSystem: '<Root>/speed-gap'
  // MATLABSystem: '<S6>/SourceBlock'
  b_varargout_1 = Sub_quietdriver_81.getLatestMessage(&rtb_SourceBlock_o2_e_0);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S10>/Enable'

  // Start for MATLABSystem: '<S6>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S10>/In1'
    quietdriver_B.In1 = rtb_SourceBlock_o2_e_0;
  }

  // End of Start for MATLABSystem: '<S6>/SourceBlock'
  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/speed-gap'

  // Outputs for Atomic SubSystem: '<Root>/car-speed'
  // MATLABSystem: '<S4>/SourceBlock'
  b_varargout_1 = Sub_quietdriver_80.getLatestMessage(&rtb_SourceBlock_o2_e_0);

  // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S8>/Enable'

  // Start for MATLABSystem: '<S4>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S8>/In1'
    quietdriver_B.In1_f = rtb_SourceBlock_o2_e_0;
  }

  // End of Start for MATLABSystem: '<S4>/SourceBlock'
  // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/car-speed'

  // MATLAB Function: '<S3>/MATLAB Function'
  u0 = static_cast<real_T>(fabs(quietdriver_B.In1_m.Data /
    (quietdriver_B.In1_f.Data + 0.5) - 4.0) >= 1.0) * (0.6 *
    quietdriver_B.In1.Data) + (quietdriver_B.In1_m.Data -
    (quietdriver_B.In1_f.Data + 0.5) * 4.0) * 0.05;
  if (!(u0 >= -3.0)) {
    u0 = -3.0;
  }

  if (u0 <= 1.5) {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = u0;
  } else {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = 1.5;
  }

  // End of MATLAB Function: '<S3>/MATLAB Function'

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S2>/SinkBlock'
  Pub_quietdriver_84.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
}

// Model initialize function
void quietdriver::initialize()
{
  {
    int32_T i;
    char_T b_zeroDelimTopic[18];
    char_T b_zeroDelimTopic_1[16];
    char_T b_zeroDelimTopic_0[14];
    static const char_T b_zeroDelimTopic_2[18] = "/egocar/lead_dist";
    static const char_T b_zeroDelimTopic_3[14] = "/egocar/vel_x";
    static const char_T b_zeroDelimTopic_4[18] = "/egocar/cmd_accel";
    static const char_T b_zeroDelimTopic_5[16] = "/egocar/rel_vel";

    // SystemInitialize for Atomic SubSystem: '<Root>/space-gap'
    // Start for MATLABSystem: '<S5>/SourceBlock'
    quietdriver_DW.obj_h.matlabCodegenIsDeleted = false;
    quietdriver_DW.obj_h.isInitialized = 1;
    for (i = 0; i < 18; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_2[i];
    }

    Sub_quietdriver_82.createSubscriber(&b_zeroDelimTopic[0], 1);
    quietdriver_DW.obj_h.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/space-gap'

    // SystemInitialize for Atomic SubSystem: '<Root>/car-speed'
    // Start for MATLABSystem: '<S4>/SourceBlock'
    quietdriver_DW.obj_j.matlabCodegenIsDeleted = false;
    quietdriver_DW.obj_j.isInitialized = 1;
    for (i = 0; i < 14; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_3[i];
    }

    Sub_quietdriver_80.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    quietdriver_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/car-speed'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S2>/SinkBlock'
    quietdriver_DW.obj.matlabCodegenIsDeleted = false;
    quietdriver_DW.obj.isInitialized = 1;
    for (i = 0; i < 18; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_4[i];
    }

    Pub_quietdriver_84.createPublisher(&b_zeroDelimTopic[0], 1);
    quietdriver_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'

    // SystemInitialize for Atomic SubSystem: '<Root>/speed-gap'
    // Start for MATLABSystem: '<S6>/SourceBlock'
    quietdriver_DW.obj_e.matlabCodegenIsDeleted = false;
    quietdriver_DW.obj_e.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      b_zeroDelimTopic_1[i] = b_zeroDelimTopic_5[i];
    }

    Sub_quietdriver_81.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    quietdriver_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/speed-gap'
  }
}

// Model terminate function
void quietdriver::terminate()
{
  // Terminate for Atomic SubSystem: '<Root>/space-gap'
  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!quietdriver_DW.obj_h.matlabCodegenIsDeleted) {
    quietdriver_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/space-gap'

  // Terminate for Atomic SubSystem: '<Root>/speed-gap'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!quietdriver_DW.obj_e.matlabCodegenIsDeleted) {
    quietdriver_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/speed-gap'

  // Terminate for Atomic SubSystem: '<Root>/car-speed'
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!quietdriver_DW.obj_j.matlabCodegenIsDeleted) {
    quietdriver_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/car-speed'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S2>/SinkBlock'
  if (!quietdriver_DW.obj.matlabCodegenIsDeleted) {
    quietdriver_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

const char_T* quietdriver::RT_MODEL_quietdriver_T::getErrorStatus() const
{
  return (errorStatus);
}

void quietdriver::RT_MODEL_quietdriver_T::setErrorStatus(const char_T* const
  volatile aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

// Constructor
quietdriver::quietdriver() :
  quietdriver_B(),
  quietdriver_DW(),
  quietdriver_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
quietdriver::~quietdriver()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
quietdriver::RT_MODEL_quietdriver_T * quietdriver::getRTM()
{
  return (&quietdriver_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
