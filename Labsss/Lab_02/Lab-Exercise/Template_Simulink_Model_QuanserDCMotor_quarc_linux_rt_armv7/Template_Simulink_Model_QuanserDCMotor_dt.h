/*
 * Template_Simulink_Model_QuanserDCMotor_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_card)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_card"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Template_Simulink_Model_Quans_B.HILRead_o1), 0, 0, 11 }
  ,

  { (char_T *)(&Template_Simulink_Model_Quan_DW.HILInitialize_AOVoltages), 0, 0,
    10 },

  { (char_T *)(&Template_Simulink_Model_Quan_DW.HILInitialize_Card), 14, 0, 1 },

  { (char_T *)(&Template_Simulink_Model_Quan_DW.HILRead_PWORK), 11, 0, 6 },

  { (char_T *)(&Template_Simulink_Model_Quan_DW.HILInitialize_DOStates), 6, 0, 6
  },

  { (char_T *)(&Template_Simulink_Model_Quan_DW.HILInitialize_POSortedChans), 7,
    0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  6U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Template_Simulink_Model_Quans_P.HILRead_analog_channels), 7, 0,
    3 },

  { (char_T *)(&Template_Simulink_Model_Quans_P.ON_Value), 0, 0, 33 },

  { (char_T *)(&Template_Simulink_Model_Quans_P.HILInitialize_EIInitial), 6, 0,
    5 },

  { (char_T *)(&Template_Simulink_Model_Quans_P.HILInitialize_AIChannels), 7, 0,
    7 },

  { (char_T *)(&Template_Simulink_Model_Quans_P.HILInitialize_Active), 8, 0, 37
  },

  { (char_T *)(&Template_Simulink_Model_Quans_P.NoisySignalSwitch_CurrentSettin),
    3, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] Template_Simulink_Model_QuanserDCMotor_dt.h */
