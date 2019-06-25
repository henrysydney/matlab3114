/*
 * Template_Simulink_Model_QuanserDCMotor_data.c
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

/* Block parameters (default storage) */
P_Template_Simulink_Model_Qua_T Template_Simulink_Model_Quans_P = {
  /* Mask Parameter: HILRead_analog_channels
   * Referenced by: '<S2>/HIL Read'
   */
  0U,

  /* Mask Parameter: HILWrite_analog_channels
   * Referenced by: '<S2>/HIL Write'
   */
  0U,

  /* Mask Parameter: HILRead_encoder_channels
   * Referenced by: '<S2>/HIL Read'
   */
  0U,

  /* Expression: 1
   * Referenced by: '<S3>/ON'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S3>/OFF'
   */
  0.0,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<S2>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<S2>/HIL Initialize'
   */
  -10.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<S2>/HIL Initialize'
   */
  5.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<S2>/HIL Initialize'
   */
  -5.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_frequency
   * Referenced by: '<S2>/HIL Initialize'
   */
  19540.791402051782,

  /* Expression: pwm_leading_deadband
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_trailing_deadband
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: pi/1024
   * Referenced by: '<S2>/Gain'
   */
  0.0030679615757712823,

  /* Expression: 180/pi
   * Referenced by: '<S2>/Gain1'
   */
  57.295779513082323,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S3>/Transfer Fcn'
   */
  -125.0,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S3>/Transfer Fcn'
   */
  125.0,

  /* Expression: 0
   * Referenced by: '<S3>/Switch'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<Root>/Signal Generator'
   */
  2.0,

  /* Expression: 1/4
   * Referenced by: '<Root>/Signal Generator'
   */
  0.25,

  /* Expression: 3
   * Referenced by: '<Root>/Saturation'
   */
  3.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: 5
   * Referenced by: '<S2>/Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S2>/Saturation'
   */
  -5.0,

  /* Computed Parameter: Identified_A
   * Referenced by: '<Root>/Identified'
   */
  -5.8139534883720936,

  /* Computed Parameter: Identified_C
   * Referenced by: '<Root>/Identified'
   */
  138.95348837209303,

  /* Computed Parameter: ManufactureModel_A
   * Referenced by: '<Root>/Manufacture Model'
   */
  -10.023113777662424,

  /* Computed Parameter: ManufactureModel_C
   * Referenced by: '<Root>/Manufacture Model'
   */
  238.6455661348196,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POModes
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POConfiguration
   * Referenced by: '<S2>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POAlignment
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPolarity
   * Referenced by: '<S2>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<S2>/HIL Initialize'
   */
  0U,

  /* Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<S2>/HIL Initialize'
   */
  0U,

  /* Computed Parameter: HILInitialize_DOChannels
   * Referenced by: '<S2>/HIL Initialize'
   */
  0U,

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<S2>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<S2>/HIL Initialize'
   */
  4U,

  /* Computed Parameter: HILInitialize_POChannels
   * Referenced by: '<S2>/HIL Initialize'
   */
  0U,

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<S2>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<S2>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<S2>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILRead_Active
   * Referenced by: '<S2>/HIL Read'
   */
  1,

  /* Computed Parameter: HILWrite_Active
   * Referenced by: '<S2>/HIL Write'
   */
  0,

  /* Computed Parameter: NoisySignalSwitch_CurrentSettin
   * Referenced by: '<S3>/Noisy Signal Switch'
   */
  1U
};
