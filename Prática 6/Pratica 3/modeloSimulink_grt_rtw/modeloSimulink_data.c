/*
 * modeloSimulink_data.c
 *
 * Code generation for model "modeloSimulink".
 *
 * Model version              : 1.24
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Wed Jan 22 12:17:09 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "modeloSimulink.h"
#include "modeloSimulink_private.h"

/* Block parameters (default storage) */
P_modeloSimulink_T modeloSimulink_P = {
  /* Mask Parameter: PIDController_I
   * Referenced by: '<S54>/Integral Gain'
   */
  0.87,

  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S150>/Integral Gain'
   */
  0.87,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S62>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S158>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S81>/Proportional Gain'
   */
  13.68,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S177>/Proportional Gain'
   */
  13.68,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S1>/Transfer Fcn'
   */
  -0.008209152,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S1>/Transfer Fcn'
   */
  0.752236084,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<S1>/Transfer Fcn1'
   */
  -0.008209152,

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<S1>/Transfer Fcn1'
   */
  0.752236084,

  /* Expression: 0
   * Referenced by: '<S1>/sX'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/sY'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Step'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Step'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Step'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Step1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Step1'
   */
  0.0,

  /* Expression: 90
   * Referenced by: '<S1>/Step1'
   */
  90.0,

  /* Expression: 0
   * Referenced by: '<S1>/IntegratorT'
   */
  0.0
};
