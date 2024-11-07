//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: quietdriver.cpp
//
// Code generated for Simulink model 'quietdriver'.
//
// Model version                  : 5.32
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Thu Nov  7 01:41:40 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "quietdriver.h"
#include "rtwtypes.h"
#include "quietdriver_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

// Model step function
void quietdriver::step()
{
  {
    SL_Bus_quietdriver_std_msgs_Float64 rtb_BusAssignment;
    SL_Bus_quietdriver_std_msgs_Float64 rtb_SourceBlock_o2_e_0;
    real_T lastTime;
    real_T rtb_Derivative;
    real_T *lastU;
    boolean_T b_varargout_1;

    // Outputs for Atomic SubSystem: '<Root>/space-gap'
    // MATLABSystem: '<S5>/SourceBlock'
    b_varargout_1 = Sub_quietdriver_82.getLatestMessage(&rtb_SourceBlock_o2_e_0);

    // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S9>/Enable'

    // Start for MATLABSystem: '<S5>/SourceBlock'
    if (b_varargout_1) {
      // SignalConversion generated from: '<S9>/In1'
      quietdriver_B.In1_ml = rtb_SourceBlock_o2_e_0;
    }

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/space-gap'

    // Derivative: '<S3>/Derivative'
    rtb_Derivative = (&quietdriver_M)->Timing.t[0];
    if ((quietdriver_DW.TimeStampA >= rtb_Derivative) &&
        (quietdriver_DW.TimeStampB >= rtb_Derivative)) {
      rtb_Derivative = 0.0;
    } else {
      lastTime = quietdriver_DW.TimeStampA;
      lastU = &quietdriver_DW.LastUAtTimeA;
      if (quietdriver_DW.TimeStampA < quietdriver_DW.TimeStampB) {
        if (quietdriver_DW.TimeStampB < rtb_Derivative) {
          lastTime = quietdriver_DW.TimeStampB;
          lastU = &quietdriver_DW.LastUAtTimeB;
        }
      } else if (quietdriver_DW.TimeStampA >= rtb_Derivative) {
        lastTime = quietdriver_DW.TimeStampB;
        lastU = &quietdriver_DW.LastUAtTimeB;
      }

      rtb_Derivative = (quietdriver_B.In1_ml.Data - *lastU) / (rtb_Derivative -
        lastTime);
    }

    // End of Derivative: '<S3>/Derivative'

    // Outputs for Atomic SubSystem: '<Root>/speed-gap'
    // MATLABSystem: '<S7>/SourceBlock'
    b_varargout_1 = Sub_quietdriver_81.getLatestMessage(&rtb_SourceBlock_o2_e_0);

    // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S11>/Enable'

    // Start for MATLABSystem: '<S7>/SourceBlock'
    if (b_varargout_1) {
      // SignalConversion generated from: '<S11>/In1'
      quietdriver_B.In1 = rtb_SourceBlock_o2_e_0;
    }

    // End of Start for MATLABSystem: '<S7>/SourceBlock'
    // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/speed-gap'

    // Outputs for Atomic SubSystem: '<Root>/space-gap1'
    // MATLABSystem: '<S6>/SourceBlock'
    b_varargout_1 = Sub_quietdriver_83.getLatestMessage(&rtb_SourceBlock_o2_e_0);

    // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S10>/Enable'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    if (b_varargout_1) {
      // SignalConversion generated from: '<S10>/In1'
      quietdriver_B.In1_m = rtb_SourceBlock_o2_e_0;
    }

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/space-gap1'

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

    // Sum: '<S3>/Add5' incorporates:
    //   Constant: '<S3>/¦Ã'
    //   Constant: '<S3>/¦Ó'
    //   DotProduct: '<S3>/Dot Product'
    //   DotProduct: '<S3>/Dot Product2'
    //   DotProduct: '<S3>/Dot Product3'
    //   Sum: '<S3>/Add2'

    rtb_Derivative = (rtb_Derivative * 0.5 + quietdriver_B.In1.Data) +
      (quietdriver_B.In1_m.Data - 3.0 * quietdriver_B.In1_f.Data);

    // Saturate: '<S3>/Saturation1'
    if (rtb_Derivative > 100.0) {
      // BusAssignment: '<Root>/Bus Assignment'
      rtb_BusAssignment.Data = 100.0;
    } else if (rtb_Derivative < -100.0) {
      // BusAssignment: '<Root>/Bus Assignment'
      rtb_BusAssignment.Data = -100.0;
    } else {
      // BusAssignment: '<Root>/Bus Assignment'
      rtb_BusAssignment.Data = rtb_Derivative;
    }

    // End of Saturate: '<S3>/Saturation1'

    // Outputs for Atomic SubSystem: '<Root>/Publish'
    // MATLABSystem: '<S2>/SinkBlock'
    Pub_quietdriver_84.publish(&rtb_BusAssignment);

    // End of Outputs for SubSystem: '<Root>/Publish'
  }

  {
    real_T *lastU;

    // Update for Derivative: '<S3>/Derivative'
    if (quietdriver_DW.TimeStampA == (rtInf)) {
      quietdriver_DW.TimeStampA = (&quietdriver_M)->Timing.t[0];
      lastU = &quietdriver_DW.LastUAtTimeA;
    } else if (quietdriver_DW.TimeStampB == (rtInf)) {
      quietdriver_DW.TimeStampB = (&quietdriver_M)->Timing.t[0];
      lastU = &quietdriver_DW.LastUAtTimeB;
    } else if (quietdriver_DW.TimeStampA < quietdriver_DW.TimeStampB) {
      quietdriver_DW.TimeStampA = (&quietdriver_M)->Timing.t[0];
      lastU = &quietdriver_DW.LastUAtTimeA;
    } else {
      quietdriver_DW.TimeStampB = (&quietdriver_M)->Timing.t[0];
      lastU = &quietdriver_DW.LastUAtTimeB;
    }

    *lastU = quietdriver_B.In1_ml.Data;

    // End of Update for Derivative: '<S3>/Derivative'
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  (&quietdriver_M)->Timing.t[0] =
    ((time_T)(++(&quietdriver_M)->Timing.clockTick0)) * (&quietdriver_M)
    ->Timing.stepSize0;

  {
    // Update absolute timer for sample time: [0.2s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 0.2, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    (&quietdriver_M)->Timing.clockTick1++;
  }
}

// Model initialize function
void quietdriver::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&(&quietdriver_M)->solverInfo, &(&quietdriver_M)
                          ->Timing.simTimeStep);
    rtsiSetTPtr(&(&quietdriver_M)->solverInfo, (&quietdriver_M)->getTPtrPtr());
    rtsiSetStepSizePtr(&(&quietdriver_M)->solverInfo, &(&quietdriver_M)
                       ->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&(&quietdriver_M)->solverInfo, (&quietdriver_M)
                          ->getErrorStatusPtr());
    rtsiSetRTModelPtr(&(&quietdriver_M)->solverInfo, (&quietdriver_M));
  }

  rtsiSetSimTimeStep(&(&quietdriver_M)->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&(&quietdriver_M)->solverInfo, false);
  rtsiSetIsContModeFrozen(&(&quietdriver_M)->solverInfo, false);
  rtsiSetSolverName(&(&quietdriver_M)->solverInfo,"FixedStepDiscrete");
  (&quietdriver_M)->setTPtr(&(&quietdriver_M)->Timing.tArray[0]);
  (&quietdriver_M)->Timing.stepSize0 = 0.2;

  {
    int32_T i;
    char_T b_zeroDelimTopic[18];
    char_T b_zeroDelimTopic_1[16];
    char_T b_zeroDelimTopic_0[14];
    static const char_T b_zeroDelimTopic_2[18] = "/egocar/lead_dist";
    static const char_T b_zeroDelimTopic_3[14] = "/egocar/vel_x";
    static const char_T b_zeroDelimTopic_4[18] = "/egocar/cmd_accel";
    static const char_T b_zeroDelimTopic_5[16] = "/egocar/rel_vel";

    // InitializeConditions for Derivative: '<S3>/Derivative'
    quietdriver_DW.TimeStampA = (rtInf);
    quietdriver_DW.TimeStampB = (rtInf);

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
    // Start for MATLABSystem: '<S7>/SourceBlock'
    quietdriver_DW.obj_e.matlabCodegenIsDeleted = false;
    quietdriver_DW.obj_e.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      b_zeroDelimTopic_1[i] = b_zeroDelimTopic_5[i];
    }

    Sub_quietdriver_81.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    quietdriver_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/speed-gap'

    // SystemInitialize for Atomic SubSystem: '<Root>/space-gap1'
    // Start for MATLABSystem: '<S6>/SourceBlock'
    quietdriver_DW.obj_k.matlabCodegenIsDeleted = false;
    quietdriver_DW.obj_k.isInitialized = 1;
    for (i = 0; i < 18; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_2[i];
    }

    Sub_quietdriver_83.createSubscriber(&b_zeroDelimTopic[0], 1);
    quietdriver_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/space-gap1'
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
  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  if (!quietdriver_DW.obj_e.matlabCodegenIsDeleted) {
    quietdriver_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/speed-gap'

  // Terminate for Atomic SubSystem: '<Root>/space-gap1'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!quietdriver_DW.obj_k.matlabCodegenIsDeleted) {
    quietdriver_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/space-gap1'

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

time_T** quietdriver::RT_MODEL_quietdriver_T::getTPtrPtr()
{
  return &(Timing.t);
}

const char_T* quietdriver::RT_MODEL_quietdriver_T::getErrorStatus() const
{
  return (errorStatus);
}

void quietdriver::RT_MODEL_quietdriver_T::setErrorStatus(const char_T* const
  aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

time_T* quietdriver::RT_MODEL_quietdriver_T::getTPtr() const
{
  return (Timing.t);
}

void quietdriver::RT_MODEL_quietdriver_T::setTPtr(time_T* aTPtr)
{
  (Timing.t = aTPtr);
}

const char_T** quietdriver::RT_MODEL_quietdriver_T::getErrorStatusPtr()
{
  return &errorStatus;
}

boolean_T quietdriver::RT_MODEL_quietdriver_T::isMajorTimeStep() const
{
  return ((Timing.simTimeStep) == MAJOR_TIME_STEP);
}

boolean_T quietdriver::RT_MODEL_quietdriver_T::isMinorTimeStep() const
{
  return ((Timing.simTimeStep) == MINOR_TIME_STEP);
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
