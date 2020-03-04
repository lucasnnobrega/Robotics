/*
 * modeloSimulink.c
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

/* Block signals (default storage) */
B_modeloSimulink_T modeloSimulink_B;

/* Continuous states */
X_modeloSimulink_T modeloSimulink_X;

/* Block states (default storage) */
DW_modeloSimulink_T modeloSimulink_DW;

/* Real-time model */
RT_MODEL_modeloSimulink_T modeloSimulink_M_;
RT_MODEL_modeloSimulink_T *const modeloSimulink_M = &modeloSimulink_M_;

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 7;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  modeloSimulink_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  modeloSimulink_step();
  modeloSimulink_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  modeloSimulink_step();
  modeloSimulink_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  modeloSimulink_step();
  modeloSimulink_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void modeloSimulink_step(void)
{
  real_T rtb_Step;
  real_T rtb_Step1;
  real_T rtb_v;
  if (rtmIsMajorTimeStep(modeloSimulink_M)) {
    /* set solver stop time */
    if (!(modeloSimulink_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&modeloSimulink_M->solverInfo,
                            ((modeloSimulink_M->Timing.clockTickH0 + 1) *
        modeloSimulink_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&modeloSimulink_M->solverInfo,
                            ((modeloSimulink_M->Timing.clockTick0 + 1) *
        modeloSimulink_M->Timing.stepSize0 +
        modeloSimulink_M->Timing.clockTickH0 *
        modeloSimulink_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(modeloSimulink_M)) {
    modeloSimulink_M->Timing.t[0] = rtsiGetT(&modeloSimulink_M->solverInfo);
  }

  /* TransferFcn: '<S1>/Transfer Fcn' */
  modeloSimulink_B.TransferFcn = 0.0;
  modeloSimulink_B.TransferFcn += modeloSimulink_P.TransferFcn_C *
    modeloSimulink_X.TransferFcn_CSTATE;

  /* TransferFcn: '<S1>/Transfer Fcn1' */
  modeloSimulink_B.TransferFcn1 = 0.0;
  modeloSimulink_B.TransferFcn1 += modeloSimulink_P.TransferFcn1_C *
    modeloSimulink_X.TransferFcn1_CSTATE;

  /* MATLAB Function: '<S1>/Direte Kinematics1' */
  rtb_v = (modeloSimulink_B.TransferFcn + modeloSimulink_B.TransferFcn1) / 2.0;
  modeloSimulink_B.w = (modeloSimulink_B.TransferFcn -
                        modeloSimulink_B.TransferFcn1) / 0.34;

  /* Step: '<S1>/Step' incorporates:
   *  Step: '<S1>/Step1'
   */
  rtb_Step1 = modeloSimulink_M->Timing.t[0];
  if (rtb_Step1 < modeloSimulink_P.Step_Time) {
    rtb_Step = modeloSimulink_P.Step_Y0;
  } else {
    rtb_Step = modeloSimulink_P.Step_YFinal;
  }

  /* End of Step: '<S1>/Step' */

  /* Step: '<S1>/Step1' */
  if (rtb_Step1 < modeloSimulink_P.Step1_Time) {
    rtb_Step1 = modeloSimulink_P.Step1_Y0;
  } else {
    rtb_Step1 = modeloSimulink_P.Step1_YFinal;
  }

  /* MATLAB Function: '<S1>/Inverse Kinematics' */
  rtb_Step1 = rtb_Step1 * 0.34 / 2.0;
  modeloSimulink_B.v1 = rtb_Step - rtb_Step1;
  modeloSimulink_B.v2 = rtb_Step1 + rtb_Step;
  if (rtmIsMajorTimeStep(modeloSimulink_M)) {
  }

  /* MATLAB Function: '<S1>/Direte Kinematics2' incorporates:
   *  Integrator: '<S1>/IntegratorT'
   */
  modeloSimulink_B.vx = cos(0.017453292519943295 *
    modeloSimulink_X.IntegratorT_CSTATE) * rtb_v;
  modeloSimulink_B.vy = sin(0.017453292519943295 *
    modeloSimulink_X.IntegratorT_CSTATE) * rtb_v;

  /* Sum: '<S1>/Sum' */
  rtb_v = modeloSimulink_B.v1 - modeloSimulink_B.TransferFcn;

  /* Gain: '<S54>/Integral Gain' */
  modeloSimulink_B.IntegralGain = modeloSimulink_P.PIDController_I * rtb_v;

  /* Sum: '<S93>/Sum' incorporates:
   *  Gain: '<S81>/Proportional Gain'
   *  Integrator: '<S62>/Integrator'
   */
  modeloSimulink_B.Sum = modeloSimulink_P.PIDController_P * rtb_v +
    modeloSimulink_X.Integrator_CSTATE;

  /* Sum: '<S1>/Sum1' */
  rtb_v = modeloSimulink_B.v2 - modeloSimulink_B.TransferFcn1;

  /* Gain: '<S150>/Integral Gain' */
  modeloSimulink_B.IntegralGain_a = modeloSimulink_P.PIDController1_I * rtb_v;

  /* Sum: '<S189>/Sum' incorporates:
   *  Gain: '<S177>/Proportional Gain'
   *  Integrator: '<S158>/Integrator'
   */
  modeloSimulink_B.Sum_h = modeloSimulink_P.PIDController1_P * rtb_v +
    modeloSimulink_X.Integrator_CSTATE_j;
  if (rtmIsMajorTimeStep(modeloSimulink_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(modeloSimulink_M->rtwLogInfo,
                        (modeloSimulink_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(modeloSimulink_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(modeloSimulink_M)!=-1) &&
          !((rtmGetTFinal(modeloSimulink_M)-
             (((modeloSimulink_M->Timing.clockTick1+
                modeloSimulink_M->Timing.clockTickH1* 4294967296.0)) * 0.04)) >
            (((modeloSimulink_M->Timing.clockTick1+
               modeloSimulink_M->Timing.clockTickH1* 4294967296.0)) * 0.04) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(modeloSimulink_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&modeloSimulink_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++modeloSimulink_M->Timing.clockTick0)) {
      ++modeloSimulink_M->Timing.clockTickH0;
    }

    modeloSimulink_M->Timing.t[0] = rtsiGetSolverStopTime
      (&modeloSimulink_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.04s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.04, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      modeloSimulink_M->Timing.clockTick1++;
      if (!modeloSimulink_M->Timing.clockTick1) {
        modeloSimulink_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void modeloSimulink_derivatives(void)
{
  XDot_modeloSimulink_T *_rtXdot;
  _rtXdot = ((XDot_modeloSimulink_T *) modeloSimulink_M->derivs);

  /* Derivatives for TransferFcn: '<S1>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += modeloSimulink_P.TransferFcn_A *
    modeloSimulink_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += modeloSimulink_B.Sum;

  /* Derivatives for TransferFcn: '<S1>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += modeloSimulink_P.TransferFcn1_A *
    modeloSimulink_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += modeloSimulink_B.Sum_h;

  /* Derivatives for Integrator: '<S1>/sX' */
  _rtXdot->sX_CSTATE = modeloSimulink_B.vx;

  /* Derivatives for Integrator: '<S1>/sY' */
  _rtXdot->sY_CSTATE = modeloSimulink_B.vy;

  /* Derivatives for Integrator: '<S1>/IntegratorT' */
  _rtXdot->IntegratorT_CSTATE = modeloSimulink_B.w;

  /* Derivatives for Integrator: '<S62>/Integrator' */
  _rtXdot->Integrator_CSTATE = modeloSimulink_B.IntegralGain;

  /* Derivatives for Integrator: '<S158>/Integrator' */
  _rtXdot->Integrator_CSTATE_j = modeloSimulink_B.IntegralGain_a;
}

/* Model initialize function */
void modeloSimulink_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)modeloSimulink_M, 0,
                sizeof(RT_MODEL_modeloSimulink_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&modeloSimulink_M->solverInfo,
                          &modeloSimulink_M->Timing.simTimeStep);
    rtsiSetTPtr(&modeloSimulink_M->solverInfo, &rtmGetTPtr(modeloSimulink_M));
    rtsiSetStepSizePtr(&modeloSimulink_M->solverInfo,
                       &modeloSimulink_M->Timing.stepSize0);
    rtsiSetdXPtr(&modeloSimulink_M->solverInfo, &modeloSimulink_M->derivs);
    rtsiSetContStatesPtr(&modeloSimulink_M->solverInfo, (real_T **)
                         &modeloSimulink_M->contStates);
    rtsiSetNumContStatesPtr(&modeloSimulink_M->solverInfo,
      &modeloSimulink_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&modeloSimulink_M->solverInfo,
      &modeloSimulink_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&modeloSimulink_M->solverInfo,
      &modeloSimulink_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&modeloSimulink_M->solverInfo,
      &modeloSimulink_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&modeloSimulink_M->solverInfo, (&rtmGetErrorStatus
      (modeloSimulink_M)));
    rtsiSetRTModelPtr(&modeloSimulink_M->solverInfo, modeloSimulink_M);
  }

  rtsiSetSimTimeStep(&modeloSimulink_M->solverInfo, MAJOR_TIME_STEP);
  modeloSimulink_M->intgData.y = modeloSimulink_M->odeY;
  modeloSimulink_M->intgData.f[0] = modeloSimulink_M->odeF[0];
  modeloSimulink_M->intgData.f[1] = modeloSimulink_M->odeF[1];
  modeloSimulink_M->intgData.f[2] = modeloSimulink_M->odeF[2];
  modeloSimulink_M->intgData.f[3] = modeloSimulink_M->odeF[3];
  modeloSimulink_M->contStates = ((X_modeloSimulink_T *) &modeloSimulink_X);
  rtsiSetSolverData(&modeloSimulink_M->solverInfo, (void *)
                    &modeloSimulink_M->intgData);
  rtsiSetSolverName(&modeloSimulink_M->solverInfo,"ode4");
  rtmSetTPtr(modeloSimulink_M, &modeloSimulink_M->Timing.tArray[0]);
  rtmSetTFinal(modeloSimulink_M, 100.0);
  modeloSimulink_M->Timing.stepSize0 = 0.04;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    modeloSimulink_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(modeloSimulink_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(modeloSimulink_M->rtwLogInfo, (NULL));
    rtliSetLogT(modeloSimulink_M->rtwLogInfo, "tout");
    rtliSetLogX(modeloSimulink_M->rtwLogInfo, "");
    rtliSetLogXFinal(modeloSimulink_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(modeloSimulink_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(modeloSimulink_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(modeloSimulink_M->rtwLogInfo, 0);
    rtliSetLogDecimation(modeloSimulink_M->rtwLogInfo, 1);
    rtliSetLogY(modeloSimulink_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(modeloSimulink_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(modeloSimulink_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &modeloSimulink_B), 0,
                sizeof(B_modeloSimulink_T));

  /* states (continuous) */
  {
    (void) memset((void *)&modeloSimulink_X, 0,
                  sizeof(X_modeloSimulink_T));
  }

  /* states (dwork) */
  (void) memset((void *)&modeloSimulink_DW, 0,
                sizeof(DW_modeloSimulink_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(modeloSimulink_M->rtwLogInfo, 0.0,
    rtmGetTFinal(modeloSimulink_M), modeloSimulink_M->Timing.stepSize0,
    (&rtmGetErrorStatus(modeloSimulink_M)));

  /* InitializeConditions for TransferFcn: '<S1>/Transfer Fcn' */
  modeloSimulink_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S1>/Transfer Fcn1' */
  modeloSimulink_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/sX' */
  modeloSimulink_X.sX_CSTATE = modeloSimulink_P.sX_IC;

  /* InitializeConditions for Integrator: '<S1>/sY' */
  modeloSimulink_X.sY_CSTATE = modeloSimulink_P.sY_IC;

  /* InitializeConditions for Integrator: '<S1>/IntegratorT' */
  modeloSimulink_X.IntegratorT_CSTATE = modeloSimulink_P.IntegratorT_IC;

  /* InitializeConditions for Integrator: '<S62>/Integrator' */
  modeloSimulink_X.Integrator_CSTATE =
    modeloSimulink_P.PIDController_InitialConditionF;

  /* InitializeConditions for Integrator: '<S158>/Integrator' */
  modeloSimulink_X.Integrator_CSTATE_j =
    modeloSimulink_P.PIDController1_InitialCondition;
}

/* Model terminate function */
void modeloSimulink_terminate(void)
{
  /* (no terminate code required) */
}
