/*
 * Template_Simulink_Model_QuanserDCMotor.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Template_Simulink_Model_QuanserDCMotor".
 *
 * Model version              : 1.19
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Tue Jun 25 18:57:08 2019
 *
 * Target selection: quarc_linux_rt_armv7.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Template_Simulink_Model_QuanserDCMotor.h"
#include "Template_Simulink_Model_QuanserDCMotor_private.h"
#include "Template_Simulink_Model_QuanserDCMotor_dt.h"

/* Block signals (default storage) */
B_Template_Simulink_Model_Qua_T Template_Simulink_Model_Quans_B;

/* Continuous states */
X_Template_Simulink_Model_Qua_T Template_Simulink_Model_Quans_X;

/* Block states (default storage) */
DW_Template_Simulink_Model_Qu_T Template_Simulink_Model_Quan_DW;

/* Real-time model */
RT_MODEL_Template_Simulink_Mo_T Template_Simulink_Model_Quan_M_;
RT_MODEL_Template_Simulink_Mo_T *const Template_Simulink_Model_Quan_M =
  &Template_Simulink_Model_Quan_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Template_Simulink_Model_QuanserDCMotor_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Template_Simulink_Model_QuanserDCMotor_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILRead_o2;
  real_T *lastU;
  real_T rtb_Saturation;
  real_T tmp;
  if (rtmIsMajorTimeStep(Template_Simulink_Model_Quan_M)) {
    /* set solver stop time */
    if (!(Template_Simulink_Model_Quan_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Template_Simulink_Model_Quan_M->solverInfo,
                            ((Template_Simulink_Model_Quan_M->Timing.clockTickH0
        + 1) * Template_Simulink_Model_Quan_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Template_Simulink_Model_Quan_M->solverInfo,
                            ((Template_Simulink_Model_Quan_M->Timing.clockTick0
        + 1) * Template_Simulink_Model_Quan_M->Timing.stepSize0 +
        Template_Simulink_Model_Quan_M->Timing.clockTickH0 *
        Template_Simulink_Model_Quan_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Template_Simulink_Model_Quan_M)) {
    Template_Simulink_Model_Quan_M->Timing.t[0] = rtsiGetT
      (&Template_Simulink_Model_Quan_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Template_Simulink_Model_Quan_M)) {
    /* S-Function (hil_read_block): '<S2>/HIL Read' */

    /* S-Function Block: Template_Simulink_Model_QuanserDCMotor/Subsystem/HIL Read (hil_read_block) */
    {
      t_error result = hil_read
        (Template_Simulink_Model_Quan_DW.HILInitialize_Card,
         &Template_Simulink_Model_Quans_P.HILRead_analog_channels, 1U,
         &Template_Simulink_Model_Quans_P.HILRead_encoder_channels, 1U,
         NULL, 0U,
         NULL, 0U,
         &Template_Simulink_Model_Quan_DW.HILRead_AnalogBuffer,
         &Template_Simulink_Model_Quan_DW.HILRead_EncoderBuffer,
         NULL,
         NULL
         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Template_Simulink_Model_Quan_M, _rt_error_message);
      } else {
        Template_Simulink_Model_Quans_B.HILRead_o1 =
          Template_Simulink_Model_Quan_DW.HILRead_AnalogBuffer;
        rtb_HILRead_o2 = Template_Simulink_Model_Quan_DW.HILRead_EncoderBuffer;
      }
    }

    /* Gain: '<S2>/Gain' */
    Template_Simulink_Model_Quans_B.Gain =
      Template_Simulink_Model_Quans_P.Gain_Gain * rtb_HILRead_o2;

    /* Gain: '<S2>/Gain1' */
    Template_Simulink_Model_Quans_B.Gain1 =
      Template_Simulink_Model_Quans_P.Gain1_Gain *
      Template_Simulink_Model_Quans_B.Gain;
  }

  /* Derivative: '<S2>/Derivative' incorporates:
   *  SignalGenerator: '<Root>/Signal Generator'
   */
  tmp = Template_Simulink_Model_Quan_M->Timing.t[0];
  if ((Template_Simulink_Model_Quan_DW.TimeStampA >= tmp) &&
      (Template_Simulink_Model_Quan_DW.TimeStampB >= tmp)) {
    Template_Simulink_Model_Quans_B.Derivative = 0.0;
  } else {
    rtb_Saturation = Template_Simulink_Model_Quan_DW.TimeStampA;
    lastU = &Template_Simulink_Model_Quan_DW.LastUAtTimeA;
    if (Template_Simulink_Model_Quan_DW.TimeStampA <
        Template_Simulink_Model_Quan_DW.TimeStampB) {
      if (Template_Simulink_Model_Quan_DW.TimeStampB < tmp) {
        rtb_Saturation = Template_Simulink_Model_Quan_DW.TimeStampB;
        lastU = &Template_Simulink_Model_Quan_DW.LastUAtTimeB;
      }
    } else {
      if (Template_Simulink_Model_Quan_DW.TimeStampA >= tmp) {
        rtb_Saturation = Template_Simulink_Model_Quan_DW.TimeStampB;
        lastU = &Template_Simulink_Model_Quan_DW.LastUAtTimeB;
      }
    }

    Template_Simulink_Model_Quans_B.Derivative =
      (Template_Simulink_Model_Quans_B.Gain - *lastU) / (tmp - rtb_Saturation);
  }

  /* End of Derivative: '<S2>/Derivative' */
  if (rtmIsMajorTimeStep(Template_Simulink_Model_Quan_M)) {
    /* ManualSwitch: '<S3>/Noisy Signal Switch' incorporates:
     *  Constant: '<S3>/OFF'
     *  Constant: '<S3>/ON'
     */
    if (Template_Simulink_Model_Quans_P.NoisySignalSwitch_CurrentSettin == 1) {
      Template_Simulink_Model_Quans_B.NoisySignalSwitch =
        Template_Simulink_Model_Quans_P.OFF_Value;
    } else {
      Template_Simulink_Model_Quans_B.NoisySignalSwitch =
        Template_Simulink_Model_Quans_P.ON_Value;
    }

    /* End of ManualSwitch: '<S3>/Noisy Signal Switch' */
  }

  /* TransferFcn: '<S3>/Transfer Fcn' */
  rtb_Saturation = Template_Simulink_Model_Quans_P.TransferFcn_C *
    Template_Simulink_Model_Quans_X.TransferFcn_CSTATE;

  /* Switch: '<S3>/Switch' */
  if (Template_Simulink_Model_Quans_B.NoisySignalSwitch >
      Template_Simulink_Model_Quans_P.Switch_Threshold) {
    Template_Simulink_Model_Quans_B.Switch[0] =
      Template_Simulink_Model_Quans_B.Derivative;
  } else {
    Template_Simulink_Model_Quans_B.Switch[0] = rtb_Saturation;
  }

  Template_Simulink_Model_Quans_B.Switch[1] = rtb_Saturation;

  /* End of Switch: '<S3>/Switch' */

  /* SignalGenerator: '<Root>/Signal Generator' */
  rtb_Saturation = Template_Simulink_Model_Quans_P.SignalGenerator_Frequency *
    tmp;
  if (rtb_Saturation - floor(rtb_Saturation) >= 0.5) {
    rtb_Saturation = Template_Simulink_Model_Quans_P.SignalGenerator_Amplitude;
  } else {
    rtb_Saturation = -Template_Simulink_Model_Quans_P.SignalGenerator_Amplitude;
  }

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Saturation > Template_Simulink_Model_Quans_P.Saturation_UpperSat) {
    rtb_Saturation = Template_Simulink_Model_Quans_P.Saturation_UpperSat;
  } else {
    if (rtb_Saturation < Template_Simulink_Model_Quans_P.Saturation_LowerSat) {
      rtb_Saturation = Template_Simulink_Model_Quans_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   */
  Template_Simulink_Model_Quans_B.Sum = rtb_Saturation +
    Template_Simulink_Model_Quans_P.Constant_Value;

  /* Saturate: '<S2>/Saturation' */
  if (Template_Simulink_Model_Quans_B.Sum >
      Template_Simulink_Model_Quans_P.Saturation_UpperSat_h) {
    Template_Simulink_Model_Quans_B.Saturation =
      Template_Simulink_Model_Quans_P.Saturation_UpperSat_h;
  } else if (Template_Simulink_Model_Quans_B.Sum <
             Template_Simulink_Model_Quans_P.Saturation_LowerSat_d) {
    Template_Simulink_Model_Quans_B.Saturation =
      Template_Simulink_Model_Quans_P.Saturation_LowerSat_d;
  } else {
    Template_Simulink_Model_Quans_B.Saturation =
      Template_Simulink_Model_Quans_B.Sum;
  }

  /* End of Saturate: '<S2>/Saturation' */
  if (rtmIsMajorTimeStep(Template_Simulink_Model_Quan_M)) {
    /* S-Function (hil_write_block): '<S2>/HIL Write' */

    /* S-Function Block: Template_Simulink_Model_QuanserDCMotor/Subsystem/HIL Write (hil_write_block) */
    {
      t_error result;
      result = hil_write(Template_Simulink_Model_Quan_DW.HILInitialize_Card,
                         &Template_Simulink_Model_Quans_P.HILWrite_analog_channels,
                         1U,
                         NULL, 0U,
                         NULL, 0U,
                         NULL, 0U,
                         &Template_Simulink_Model_Quans_B.Saturation,
                         NULL,
                         NULL,
                         NULL
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Template_Simulink_Model_Quan_M, _rt_error_message);
      }
    }
  }

  /* TransferFcn: '<Root>/Identified' */
  Template_Simulink_Model_Quans_B.Identified = 0.0;
  Template_Simulink_Model_Quans_B.Identified +=
    Template_Simulink_Model_Quans_P.Identified_C *
    Template_Simulink_Model_Quans_X.Identified_CSTATE;

  /* TransferFcn: '<Root>/Manufacture Model' */
  Template_Simulink_Model_Quans_B.ManufactureModel = 0.0;
  Template_Simulink_Model_Quans_B.ManufactureModel +=
    Template_Simulink_Model_Quans_P.ManufactureModel_C *
    Template_Simulink_Model_Quans_X.ManufactureModel_CSTATE;
  if (rtmIsMajorTimeStep(Template_Simulink_Model_Quan_M)) {
  }
}

/* Model update function */
void Template_Simulink_Model_QuanserDCMotor_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<S2>/Derivative' */
  if (Template_Simulink_Model_Quan_DW.TimeStampA == (rtInf)) {
    Template_Simulink_Model_Quan_DW.TimeStampA =
      Template_Simulink_Model_Quan_M->Timing.t[0];
    lastU = &Template_Simulink_Model_Quan_DW.LastUAtTimeA;
  } else if (Template_Simulink_Model_Quan_DW.TimeStampB == (rtInf)) {
    Template_Simulink_Model_Quan_DW.TimeStampB =
      Template_Simulink_Model_Quan_M->Timing.t[0];
    lastU = &Template_Simulink_Model_Quan_DW.LastUAtTimeB;
  } else if (Template_Simulink_Model_Quan_DW.TimeStampA <
             Template_Simulink_Model_Quan_DW.TimeStampB) {
    Template_Simulink_Model_Quan_DW.TimeStampA =
      Template_Simulink_Model_Quan_M->Timing.t[0];
    lastU = &Template_Simulink_Model_Quan_DW.LastUAtTimeA;
  } else {
    Template_Simulink_Model_Quan_DW.TimeStampB =
      Template_Simulink_Model_Quan_M->Timing.t[0];
    lastU = &Template_Simulink_Model_Quan_DW.LastUAtTimeB;
  }

  *lastU = Template_Simulink_Model_Quans_B.Gain;

  /* End of Update for Derivative: '<S2>/Derivative' */
  if (rtmIsMajorTimeStep(Template_Simulink_Model_Quan_M)) {
    rt_ertODEUpdateContinuousStates(&Template_Simulink_Model_Quan_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Template_Simulink_Model_Quan_M->Timing.clockTick0)) {
    ++Template_Simulink_Model_Quan_M->Timing.clockTickH0;
  }

  Template_Simulink_Model_Quan_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Template_Simulink_Model_Quan_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Template_Simulink_Model_Quan_M->Timing.clockTick1)) {
      ++Template_Simulink_Model_Quan_M->Timing.clockTickH1;
    }

    Template_Simulink_Model_Quan_M->Timing.t[1] =
      Template_Simulink_Model_Quan_M->Timing.clockTick1 *
      Template_Simulink_Model_Quan_M->Timing.stepSize1 +
      Template_Simulink_Model_Quan_M->Timing.clockTickH1 *
      Template_Simulink_Model_Quan_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Template_Simulink_Model_QuanserDCMotor_derivatives(void)
{
  XDot_Template_Simulink_Model__T *_rtXdot;
  _rtXdot = ((XDot_Template_Simulink_Model__T *)
             Template_Simulink_Model_Quan_M->derivs);

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += Template_Simulink_Model_Quans_P.TransferFcn_A *
    Template_Simulink_Model_Quans_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += Template_Simulink_Model_Quans_B.Derivative;

  /* Derivatives for TransferFcn: '<Root>/Identified' */
  _rtXdot->Identified_CSTATE = 0.0;
  _rtXdot->Identified_CSTATE += Template_Simulink_Model_Quans_P.Identified_A *
    Template_Simulink_Model_Quans_X.Identified_CSTATE;
  _rtXdot->Identified_CSTATE += Template_Simulink_Model_Quans_B.Sum;

  /* Derivatives for TransferFcn: '<Root>/Manufacture Model' */
  _rtXdot->ManufactureModel_CSTATE = 0.0;
  _rtXdot->ManufactureModel_CSTATE +=
    Template_Simulink_Model_Quans_P.ManufactureModel_A *
    Template_Simulink_Model_Quans_X.ManufactureModel_CSTATE;
  _rtXdot->ManufactureModel_CSTATE += Template_Simulink_Model_Quans_B.Sum;
}

/* Model initialize function */
void Template_Simulink_Model_QuanserDCMotor_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S2>/HIL Initialize' */

  /* S-Function Block: Template_Simulink_Model_QuanserDCMotor/Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qab_controls", "0",
                      &Template_Simulink_Model_Quan_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Template_Simulink_Model_Quan_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_watchdog_clear
      (Template_Simulink_Model_Quan_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Template_Simulink_Model_Quan_M, _rt_error_message);
      return;
    }

    if ((Template_Simulink_Model_Quans_P.HILInitialize_AIPStart && !is_switching)
        || (Template_Simulink_Model_Quans_P.HILInitialize_AIPEnter &&
            is_switching)) {
      result = hil_set_analog_input_ranges
        (Template_Simulink_Model_Quan_DW.HILInitialize_Card,
         &Template_Simulink_Model_Quans_P.HILInitialize_AIChannels, 1U,
         &Template_Simulink_Model_Quans_P.HILInitialize_AILow,
         &Template_Simulink_Model_Quans_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Template_Simulink_Model_Quan_M, _rt_error_message);
        return;
      }
    }

    if ((Template_Simulink_Model_Quans_P.HILInitialize_AOPStart && !is_switching)
        || (Template_Simulink_Model_Quans_P.HILInitialize_AOPEnter &&
            is_switching)) {
      result = hil_set_analog_output_ranges
        (Template_Simulink_Model_Quan_DW.HILInitialize_Card,
         &Template_Simulink_Model_Quans_P.HILInitialize_AOChannels, 1U,
         &Template_Simulink_Model_Quans_P.HILInitialize_AOLow,
         &Template_Simulink_Model_Quans_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Template_Simulink_Model_Quan_M, _rt_error_message);
        return;
      }
    }

    if ((Template_Simulink_Model_Quans_P.HILInitialize_AOStart && !is_switching)
        || (Template_Simulink_Model_Quans_P.HILInitialize_AOEnter &&
            is_switching)) {
      result = hil_write_analog
        (Template_Simulink_Model_Quan_DW.HILInitialize_Card,
         &Template_Simulink_Model_Quans_P.HILInitialize_AOChannels, 1U,
         &Template_Simulink_Model_Quans_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Template_Simulink_Model_Quan_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions
      (Template_Simulink_Model_Quan_DW.HILInitialize_Card, NULL, 0U,
       &Template_Simulink_Model_Quans_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Template_Simulink_Model_Quan_M, _rt_error_message);
      return;
    }

    if ((Template_Simulink_Model_Quans_P.HILInitialize_DOStart && !is_switching)
        || (Template_Simulink_Model_Quans_P.HILInitialize_DOEnter &&
            is_switching)) {
      result = hil_write_digital
        (Template_Simulink_Model_Quan_DW.HILInitialize_Card,
         &Template_Simulink_Model_Quans_P.HILInitialize_DOChannels, 1U,
         (t_boolean *) &Template_Simulink_Model_Quans_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Template_Simulink_Model_Quan_M, _rt_error_message);
        return;
      }
    }

    if ((Template_Simulink_Model_Quans_P.HILInitialize_EIPStart && !is_switching)
        || (Template_Simulink_Model_Quans_P.HILInitialize_EIPEnter &&
            is_switching)) {
      Template_Simulink_Model_Quan_DW.HILInitialize_QuadratureModes[0] =
        Template_Simulink_Model_Quans_P.HILInitialize_EIQuadrature;
      Template_Simulink_Model_Quan_DW.HILInitialize_QuadratureModes[1] =
        Template_Simulink_Model_Quans_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (Template_Simulink_Model_Quan_DW.HILInitialize_Card,
         Template_Simulink_Model_Quans_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &Template_Simulink_Model_Quan_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Template_Simulink_Model_Quan_M, _rt_error_message);
        return;
      }
    }

    if ((Template_Simulink_Model_Quans_P.HILInitialize_EIStart && !is_switching)
        || (Template_Simulink_Model_Quans_P.HILInitialize_EIEnter &&
            is_switching)) {
      Template_Simulink_Model_Quan_DW.HILInitialize_InitialEICounts[0] =
        Template_Simulink_Model_Quans_P.HILInitialize_EIInitial;
      Template_Simulink_Model_Quan_DW.HILInitialize_InitialEICounts[1] =
        Template_Simulink_Model_Quans_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts
        (Template_Simulink_Model_Quan_DW.HILInitialize_Card,
         Template_Simulink_Model_Quans_P.HILInitialize_EIChannels, 2U,
         &Template_Simulink_Model_Quan_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Template_Simulink_Model_Quan_M, _rt_error_message);
        return;
      }
    }

    if ((Template_Simulink_Model_Quans_P.HILInitialize_POPStart && !is_switching)
        || (Template_Simulink_Model_Quans_P.HILInitialize_POPEnter &&
            is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;
      result = hil_set_pwm_mode
        (Template_Simulink_Model_Quan_DW.HILInitialize_Card,
         &Template_Simulink_Model_Quans_P.HILInitialize_POChannels, 1U,
         (t_pwm_mode *) &Template_Simulink_Model_Quans_P.HILInitialize_POModes);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Template_Simulink_Model_Quan_M, _rt_error_message);
        return;
      }

      if (Template_Simulink_Model_Quans_P.HILInitialize_POModes ==
          PWM_DUTY_CYCLE_MODE ||
          Template_Simulink_Model_Quans_P.HILInitialize_POModes ==
          PWM_ONE_SHOT_MODE ||
          Template_Simulink_Model_Quans_P.HILInitialize_POModes == PWM_TIME_MODE
          || Template_Simulink_Model_Quans_P.HILInitialize_POModes ==
          PWM_RAW_MODE) {
        Template_Simulink_Model_Quan_DW.HILInitialize_POSortedChans =
          Template_Simulink_Model_Quans_P.HILInitialize_POChannels;
        Template_Simulink_Model_Quan_DW.HILInitialize_POSortedFreqs =
          Template_Simulink_Model_Quans_P.HILInitialize_POFrequency;
        num_duty_cycle_modes++;
      } else {
        Template_Simulink_Model_Quan_DW.HILInitialize_POSortedChans =
          Template_Simulink_Model_Quans_P.HILInitialize_POChannels;
        Template_Simulink_Model_Quan_DW.HILInitialize_POSortedFreqs =
          Template_Simulink_Model_Quans_P.HILInitialize_POFrequency;
        num_frequency_modes++;
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency
          (Template_Simulink_Model_Quan_DW.HILInitialize_Card,
           &Template_Simulink_Model_Quan_DW.HILInitialize_POSortedChans,
           num_duty_cycle_modes,
           &Template_Simulink_Model_Quan_DW.HILInitialize_POSortedFreqs);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Template_Simulink_Model_Quan_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle
          (Template_Simulink_Model_Quan_DW.HILInitialize_Card,
           &Template_Simulink_Model_Quan_DW.HILInitialize_POSortedChans,
           num_frequency_modes,
           &Template_Simulink_Model_Quan_DW.HILInitialize_POSortedFreqs);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Template_Simulink_Model_Quan_M, _rt_error_message);
          return;
        }
      }

      result = hil_set_pwm_configuration
        (Template_Simulink_Model_Quan_DW.HILInitialize_Card,
         &Template_Simulink_Model_Quans_P.HILInitialize_POChannels, 1U,
         (t_pwm_configuration *)
         &Template_Simulink_Model_Quans_P.HILInitialize_POConfiguration,
         (t_pwm_alignment *)
         &Template_Simulink_Model_Quans_P.HILInitialize_POAlignment,
         (t_pwm_polarity *)
         &Template_Simulink_Model_Quans_P.HILInitialize_POPolarity);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Template_Simulink_Model_Quan_M, _rt_error_message);
        return;
      }

      result = hil_set_pwm_deadband
        (Template_Simulink_Model_Quan_DW.HILInitialize_Card,
         &Template_Simulink_Model_Quans_P.HILInitialize_POChannels, 1U,
         &Template_Simulink_Model_Quans_P.HILInitialize_POLeading,
         &Template_Simulink_Model_Quans_P.HILInitialize_POTrailing);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Template_Simulink_Model_Quan_M, _rt_error_message);
        return;
      }
    }

    if ((Template_Simulink_Model_Quans_P.HILInitialize_POStart && !is_switching)
        || (Template_Simulink_Model_Quans_P.HILInitialize_POEnter &&
            is_switching)) {
      result = hil_write_pwm(Template_Simulink_Model_Quan_DW.HILInitialize_Card,
        &Template_Simulink_Model_Quans_P.HILInitialize_POChannels, 1U,
        &Template_Simulink_Model_Quans_P.HILInitialize_POInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Template_Simulink_Model_Quan_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for Derivative: '<S2>/Derivative' */
  Template_Simulink_Model_Quan_DW.TimeStampA = (rtInf);
  Template_Simulink_Model_Quan_DW.TimeStampB = (rtInf);

  /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn' */
  Template_Simulink_Model_Quans_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Identified' */
  Template_Simulink_Model_Quans_X.Identified_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Manufacture Model' */
  Template_Simulink_Model_Quans_X.ManufactureModel_CSTATE = 0.0;
}

/* Model terminate function */
void Template_Simulink_Model_QuanserDCMotor_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S2>/HIL Initialize' */

  /* S-Function Block: Template_Simulink_Model_QuanserDCMotor/Subsystem/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(Template_Simulink_Model_Quan_DW.HILInitialize_Card);
    hil_monitor_stop_all(Template_Simulink_Model_Quan_DW.HILInitialize_Card);
    is_switching = false;
    if ((Template_Simulink_Model_Quans_P.HILInitialize_AOTerminate &&
         !is_switching) || (Template_Simulink_Model_Quans_P.HILInitialize_AOExit
         && is_switching)) {
      num_final_analog_outputs = 1U;
    }

    if ((Template_Simulink_Model_Quans_P.HILInitialize_DOTerminate &&
         !is_switching) || (Template_Simulink_Model_Quans_P.HILInitialize_DOExit
         && is_switching)) {
      num_final_digital_outputs = 1U;
    }

    if ((Template_Simulink_Model_Quans_P.HILInitialize_POTerminate &&
         !is_switching) || (Template_Simulink_Model_Quans_P.HILInitialize_POExit
         && is_switching)) {
      num_final_pwm_outputs = 1U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        || num_final_digital_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(Template_Simulink_Model_Quan_DW.HILInitialize_Card
                         ,
                         &Template_Simulink_Model_Quans_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         ,
                         &Template_Simulink_Model_Quans_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         ,
                         &Template_Simulink_Model_Quans_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , NULL, 0
                         ,
                         &Template_Simulink_Model_Quans_P.HILInitialize_AOFinal
                         ,
                         &Template_Simulink_Model_Quans_P.HILInitialize_POFinal
                         , (t_boolean *)
                         &Template_Simulink_Model_Quans_P.HILInitialize_DOFinal
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (Template_Simulink_Model_Quan_DW.HILInitialize_Card,
             &Template_Simulink_Model_Quans_P.HILInitialize_AOChannels,
             num_final_analog_outputs,
             &Template_Simulink_Model_Quans_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm
            (Template_Simulink_Model_Quan_DW.HILInitialize_Card,
             &Template_Simulink_Model_Quans_P.HILInitialize_POChannels,
             num_final_pwm_outputs,
             &Template_Simulink_Model_Quans_P.HILInitialize_POFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (Template_Simulink_Model_Quan_DW.HILInitialize_Card,
             &Template_Simulink_Model_Quans_P.HILInitialize_DOChannels,
             num_final_digital_outputs, (t_boolean *)
             &Template_Simulink_Model_Quans_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Template_Simulink_Model_Quan_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Template_Simulink_Model_Quan_DW.HILInitialize_Card);
    hil_monitor_delete_all(Template_Simulink_Model_Quan_DW.HILInitialize_Card);
    hil_close(Template_Simulink_Model_Quan_DW.HILInitialize_Card);
    Template_Simulink_Model_Quan_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  Template_Simulink_Model_QuanserDCMotor_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Template_Simulink_Model_QuanserDCMotor_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Template_Simulink_Model_QuanserDCMotor_initialize();
}

void MdlTerminate(void)
{
  Template_Simulink_Model_QuanserDCMotor_terminate();
}

/* Registration function */
RT_MODEL_Template_Simulink_Mo_T *Template_Simulink_Model_QuanserDCMotor(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Template_Simulink_Model_Quan_M, 0,
                sizeof(RT_MODEL_Template_Simulink_Mo_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Template_Simulink_Model_Quan_M->solverInfo,
                          &Template_Simulink_Model_Quan_M->Timing.simTimeStep);
    rtsiSetTPtr(&Template_Simulink_Model_Quan_M->solverInfo, &rtmGetTPtr
                (Template_Simulink_Model_Quan_M));
    rtsiSetStepSizePtr(&Template_Simulink_Model_Quan_M->solverInfo,
                       &Template_Simulink_Model_Quan_M->Timing.stepSize0);
    rtsiSetdXPtr(&Template_Simulink_Model_Quan_M->solverInfo,
                 &Template_Simulink_Model_Quan_M->derivs);
    rtsiSetContStatesPtr(&Template_Simulink_Model_Quan_M->solverInfo, (real_T **)
                         &Template_Simulink_Model_Quan_M->contStates);
    rtsiSetNumContStatesPtr(&Template_Simulink_Model_Quan_M->solverInfo,
      &Template_Simulink_Model_Quan_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Template_Simulink_Model_Quan_M->solverInfo,
      &Template_Simulink_Model_Quan_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&Template_Simulink_Model_Quan_M->solverInfo,
       &Template_Simulink_Model_Quan_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&Template_Simulink_Model_Quan_M->solverInfo,
       &Template_Simulink_Model_Quan_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Template_Simulink_Model_Quan_M->solverInfo,
                          (&rtmGetErrorStatus(Template_Simulink_Model_Quan_M)));
    rtsiSetRTModelPtr(&Template_Simulink_Model_Quan_M->solverInfo,
                      Template_Simulink_Model_Quan_M);
  }

  rtsiSetSimTimeStep(&Template_Simulink_Model_Quan_M->solverInfo,
                     MAJOR_TIME_STEP);
  Template_Simulink_Model_Quan_M->intgData.f[0] =
    Template_Simulink_Model_Quan_M->odeF[0];
  Template_Simulink_Model_Quan_M->contStates = ((real_T *)
    &Template_Simulink_Model_Quans_X);
  rtsiSetSolverData(&Template_Simulink_Model_Quan_M->solverInfo, (void *)
                    &Template_Simulink_Model_Quan_M->intgData);
  rtsiSetSolverName(&Template_Simulink_Model_Quan_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      Template_Simulink_Model_Quan_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Template_Simulink_Model_Quan_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Template_Simulink_Model_Quan_M->Timing.sampleTimes =
      (&Template_Simulink_Model_Quan_M->Timing.sampleTimesArray[0]);
    Template_Simulink_Model_Quan_M->Timing.offsetTimes =
      (&Template_Simulink_Model_Quan_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Template_Simulink_Model_Quan_M->Timing.sampleTimes[0] = (0.0);
    Template_Simulink_Model_Quan_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    Template_Simulink_Model_Quan_M->Timing.offsetTimes[0] = (0.0);
    Template_Simulink_Model_Quan_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Template_Simulink_Model_Quan_M,
             &Template_Simulink_Model_Quan_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Template_Simulink_Model_Quan_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Template_Simulink_Model_Quan_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Template_Simulink_Model_Quan_M, 10.0);
  Template_Simulink_Model_Quan_M->Timing.stepSize0 = 0.001;
  Template_Simulink_Model_Quan_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  Template_Simulink_Model_Quan_M->Sizes.checksums[0] = (3724876104U);
  Template_Simulink_Model_Quan_M->Sizes.checksums[1] = (1079413250U);
  Template_Simulink_Model_Quan_M->Sizes.checksums[2] = (25263752U);
  Template_Simulink_Model_Quan_M->Sizes.checksums[3] = (658407566U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    Template_Simulink_Model_Quan_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Template_Simulink_Model_Quan_M->extModeInfo,
      &Template_Simulink_Model_Quan_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Template_Simulink_Model_Quan_M->extModeInfo,
                        Template_Simulink_Model_Quan_M->Sizes.checksums);
    rteiSetTPtr(Template_Simulink_Model_Quan_M->extModeInfo, rtmGetTPtr
                (Template_Simulink_Model_Quan_M));
  }

  Template_Simulink_Model_Quan_M->solverInfoPtr =
    (&Template_Simulink_Model_Quan_M->solverInfo);
  Template_Simulink_Model_Quan_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Template_Simulink_Model_Quan_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Template_Simulink_Model_Quan_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Template_Simulink_Model_Quan_M->blockIO = ((void *)
    &Template_Simulink_Model_Quans_B);
  (void) memset(((void *) &Template_Simulink_Model_Quans_B), 0,
                sizeof(B_Template_Simulink_Model_Qua_T));

  /* parameters */
  Template_Simulink_Model_Quan_M->defaultParam = ((real_T *)
    &Template_Simulink_Model_Quans_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Template_Simulink_Model_Quans_X;
    Template_Simulink_Model_Quan_M->contStates = (x);
    (void) memset((void *)&Template_Simulink_Model_Quans_X, 0,
                  sizeof(X_Template_Simulink_Model_Qua_T));
  }

  /* states (dwork) */
  Template_Simulink_Model_Quan_M->dwork = ((void *)
    &Template_Simulink_Model_Quan_DW);
  (void) memset((void *)&Template_Simulink_Model_Quan_DW, 0,
                sizeof(DW_Template_Simulink_Model_Qu_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Template_Simulink_Model_Quan_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Template_Simulink_Model_Quan_M->Sizes.numContStates = (3);/* Number of continuous states */
  Template_Simulink_Model_Quan_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  Template_Simulink_Model_Quan_M->Sizes.numY = (0);/* Number of model outputs */
  Template_Simulink_Model_Quan_M->Sizes.numU = (0);/* Number of model inputs */
  Template_Simulink_Model_Quan_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Template_Simulink_Model_Quan_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Template_Simulink_Model_Quan_M->Sizes.numBlocks = (24);/* Number of blocks */
  Template_Simulink_Model_Quan_M->Sizes.numBlockIO = (10);/* Number of block outputs */
  Template_Simulink_Model_Quan_M->Sizes.numBlockPrms = (86);/* Sum of parameter "widths" */
  return Template_Simulink_Model_Quan_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
