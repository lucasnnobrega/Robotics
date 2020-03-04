/*
 * modeloSimulink.h
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

#ifndef RTW_HEADER_modeloSimulink_h_
#define RTW_HEADER_modeloSimulink_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef modeloSimulink_COMMON_INCLUDES_
# define modeloSimulink_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* modeloSimulink_COMMON_INCLUDES_ */

#include "modeloSimulink_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T TransferFcn;                  /* '<S1>/Transfer Fcn' */
  real_T TransferFcn1;                 /* '<S1>/Transfer Fcn1' */
  real_T IntegralGain;                 /* '<S54>/Integral Gain' */
  real_T Sum;                          /* '<S93>/Sum' */
  real_T IntegralGain_a;               /* '<S150>/Integral Gain' */
  real_T Sum_h;                        /* '<S189>/Sum' */
  real_T v1;                           /* '<S1>/Inverse Kinematics' */
  real_T v2;                           /* '<S1>/Inverse Kinematics' */
  real_T vx;                           /* '<S1>/Direte Kinematics2' */
  real_T vy;                           /* '<S1>/Direte Kinematics2' */
  real_T w;                            /* '<S1>/Direte Kinematics1' */
} B_modeloSimulink_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } ScopeV1_PWORK;                     /* '<S1>/Scope V1' */

  struct {
    void *LoggedData;
  } ScopeV2_PWORK;                     /* '<S1>/Scope V2' */
} DW_modeloSimulink_T;

/* Continuous states (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<S1>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE;          /* '<S1>/Transfer Fcn1' */
  real_T sX_CSTATE;                    /* '<S1>/sX' */
  real_T sY_CSTATE;                    /* '<S1>/sY' */
  real_T IntegratorT_CSTATE;           /* '<S1>/IntegratorT' */
  real_T Integrator_CSTATE;            /* '<S62>/Integrator' */
  real_T Integrator_CSTATE_j;          /* '<S158>/Integrator' */
} X_modeloSimulink_T;

/* State derivatives (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<S1>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE;          /* '<S1>/Transfer Fcn1' */
  real_T sX_CSTATE;                    /* '<S1>/sX' */
  real_T sY_CSTATE;                    /* '<S1>/sY' */
  real_T IntegratorT_CSTATE;           /* '<S1>/IntegratorT' */
  real_T Integrator_CSTATE;            /* '<S62>/Integrator' */
  real_T Integrator_CSTATE_j;          /* '<S158>/Integrator' */
} XDot_modeloSimulink_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn_CSTATE;        /* '<S1>/Transfer Fcn' */
  boolean_T TransferFcn1_CSTATE;       /* '<S1>/Transfer Fcn1' */
  boolean_T sX_CSTATE;                 /* '<S1>/sX' */
  boolean_T sY_CSTATE;                 /* '<S1>/sY' */
  boolean_T IntegratorT_CSTATE;        /* '<S1>/IntegratorT' */
  boolean_T Integrator_CSTATE;         /* '<S62>/Integrator' */
  boolean_T Integrator_CSTATE_j;       /* '<S158>/Integrator' */
} XDis_modeloSimulink_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Parameters (default storage) */
struct P_modeloSimulink_T_ {
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S54>/Integral Gain'
                                        */
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S150>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;/* Mask Parameter: PIDController_InitialConditionF
                                          * Referenced by: '<S62>/Integrator'
                                          */
  real_T PIDController1_InitialCondition;/* Mask Parameter: PIDController1_InitialCondition
                                          * Referenced by: '<S158>/Integrator'
                                          */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S81>/Proportional Gain'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S177>/Proportional Gain'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S1>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S1>/Transfer Fcn'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S1>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S1>/Transfer Fcn1'
                                        */
  real_T sX_IC;                        /* Expression: 0
                                        * Referenced by: '<S1>/sX'
                                        */
  real_T sY_IC;                        /* Expression: 0
                                        * Referenced by: '<S1>/sY'
                                        */
  real_T Step_Time;                    /* Expression: 1
                                        * Referenced by: '<S1>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S1>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<S1>/Step'
                                        */
  real_T Step1_Time;                   /* Expression: 1
                                        * Referenced by: '<S1>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<S1>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: 90
                                        * Referenced by: '<S1>/Step1'
                                        */
  real_T IntegratorT_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/IntegratorT'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_modeloSimulink_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_modeloSimulink_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[7];
  real_T odeF[4][7];
  ODE4_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_modeloSimulink_T modeloSimulink_P;

/* Block signals (default storage) */
extern B_modeloSimulink_T modeloSimulink_B;

/* Continuous states (default storage) */
extern X_modeloSimulink_T modeloSimulink_X;

/* Block states (default storage) */
extern DW_modeloSimulink_T modeloSimulink_DW;

/* Model entry point functions */
extern void modeloSimulink_initialize(void);
extern void modeloSimulink_step(void);
extern void modeloSimulink_terminate(void);

/* Real-time Model object */
extern RT_MODEL_modeloSimulink_T *const modeloSimulink_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'modeloSimulink'
 * '<S1>'   : 'modeloSimulink/Robo'
 * '<S2>'   : 'modeloSimulink/VW Graph'
 * '<S3>'   : 'modeloSimulink/XY Graph'
 * '<S4>'   : 'modeloSimulink/Robo/Direte Kinematics1'
 * '<S5>'   : 'modeloSimulink/Robo/Direte Kinematics2'
 * '<S6>'   : 'modeloSimulink/Robo/Inverse Kinematics'
 * '<S7>'   : 'modeloSimulink/Robo/PID Controller'
 * '<S8>'   : 'modeloSimulink/Robo/PID Controller1'
 * '<S9>'   : 'modeloSimulink/Robo/interno'
 * '<S10>'  : 'modeloSimulink/Robo/PID Controller/Anti-windup'
 * '<S11>'  : 'modeloSimulink/Robo/PID Controller/D Gain'
 * '<S12>'  : 'modeloSimulink/Robo/PID Controller/Filter'
 * '<S13>'  : 'modeloSimulink/Robo/PID Controller/Filter ICs'
 * '<S14>'  : 'modeloSimulink/Robo/PID Controller/I Gain'
 * '<S15>'  : 'modeloSimulink/Robo/PID Controller/Ideal P Gain'
 * '<S16>'  : 'modeloSimulink/Robo/PID Controller/Ideal P Gain Fdbk'
 * '<S17>'  : 'modeloSimulink/Robo/PID Controller/Integrator'
 * '<S18>'  : 'modeloSimulink/Robo/PID Controller/Integrator ICs'
 * '<S19>'  : 'modeloSimulink/Robo/PID Controller/N Copy'
 * '<S20>'  : 'modeloSimulink/Robo/PID Controller/N Gain'
 * '<S21>'  : 'modeloSimulink/Robo/PID Controller/P Copy'
 * '<S22>'  : 'modeloSimulink/Robo/PID Controller/Parallel P Gain'
 * '<S23>'  : 'modeloSimulink/Robo/PID Controller/Reset Signal'
 * '<S24>'  : 'modeloSimulink/Robo/PID Controller/Saturation'
 * '<S25>'  : 'modeloSimulink/Robo/PID Controller/Saturation Fdbk'
 * '<S26>'  : 'modeloSimulink/Robo/PID Controller/Sum'
 * '<S27>'  : 'modeloSimulink/Robo/PID Controller/Sum Fdbk'
 * '<S28>'  : 'modeloSimulink/Robo/PID Controller/Tracking Mode'
 * '<S29>'  : 'modeloSimulink/Robo/PID Controller/Tracking Mode Sum'
 * '<S30>'  : 'modeloSimulink/Robo/PID Controller/postSat Signal'
 * '<S31>'  : 'modeloSimulink/Robo/PID Controller/preSat Signal'
 * '<S32>'  : 'modeloSimulink/Robo/PID Controller/Anti-windup/Back Calculation'
 * '<S33>'  : 'modeloSimulink/Robo/PID Controller/Anti-windup/Cont. Clamping Ideal'
 * '<S34>'  : 'modeloSimulink/Robo/PID Controller/Anti-windup/Cont. Clamping Parallel'
 * '<S35>'  : 'modeloSimulink/Robo/PID Controller/Anti-windup/Disabled'
 * '<S36>'  : 'modeloSimulink/Robo/PID Controller/Anti-windup/Disc. Clamping Ideal'
 * '<S37>'  : 'modeloSimulink/Robo/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S38>'  : 'modeloSimulink/Robo/PID Controller/Anti-windup/Passthrough'
 * '<S39>'  : 'modeloSimulink/Robo/PID Controller/D Gain/Disabled'
 * '<S40>'  : 'modeloSimulink/Robo/PID Controller/D Gain/External Parameters'
 * '<S41>'  : 'modeloSimulink/Robo/PID Controller/D Gain/Internal Parameters'
 * '<S42>'  : 'modeloSimulink/Robo/PID Controller/Filter/Cont. Filter'
 * '<S43>'  : 'modeloSimulink/Robo/PID Controller/Filter/Differentiator'
 * '<S44>'  : 'modeloSimulink/Robo/PID Controller/Filter/Disabled'
 * '<S45>'  : 'modeloSimulink/Robo/PID Controller/Filter/Disc. Backward Euler Filter'
 * '<S46>'  : 'modeloSimulink/Robo/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S47>'  : 'modeloSimulink/Robo/PID Controller/Filter/Disc. Trapezoidal Filter'
 * '<S48>'  : 'modeloSimulink/Robo/PID Controller/Filter ICs/Disabled'
 * '<S49>'  : 'modeloSimulink/Robo/PID Controller/Filter ICs/External IC'
 * '<S50>'  : 'modeloSimulink/Robo/PID Controller/Filter ICs/Internal IC - Differentiator'
 * '<S51>'  : 'modeloSimulink/Robo/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S52>'  : 'modeloSimulink/Robo/PID Controller/I Gain/Disabled'
 * '<S53>'  : 'modeloSimulink/Robo/PID Controller/I Gain/External Parameters'
 * '<S54>'  : 'modeloSimulink/Robo/PID Controller/I Gain/Internal Parameters'
 * '<S55>'  : 'modeloSimulink/Robo/PID Controller/Ideal P Gain/External Parameters'
 * '<S56>'  : 'modeloSimulink/Robo/PID Controller/Ideal P Gain/Internal Parameters'
 * '<S57>'  : 'modeloSimulink/Robo/PID Controller/Ideal P Gain/Passthrough'
 * '<S58>'  : 'modeloSimulink/Robo/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S59>'  : 'modeloSimulink/Robo/PID Controller/Ideal P Gain Fdbk/External Parameters'
 * '<S60>'  : 'modeloSimulink/Robo/PID Controller/Ideal P Gain Fdbk/Internal Parameters'
 * '<S61>'  : 'modeloSimulink/Robo/PID Controller/Ideal P Gain Fdbk/Passthrough'
 * '<S62>'  : 'modeloSimulink/Robo/PID Controller/Integrator/Continuous'
 * '<S63>'  : 'modeloSimulink/Robo/PID Controller/Integrator/Disabled'
 * '<S64>'  : 'modeloSimulink/Robo/PID Controller/Integrator/Discrete'
 * '<S65>'  : 'modeloSimulink/Robo/PID Controller/Integrator ICs/Disabled'
 * '<S66>'  : 'modeloSimulink/Robo/PID Controller/Integrator ICs/External IC'
 * '<S67>'  : 'modeloSimulink/Robo/PID Controller/Integrator ICs/Internal IC'
 * '<S68>'  : 'modeloSimulink/Robo/PID Controller/N Copy/Disabled'
 * '<S69>'  : 'modeloSimulink/Robo/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S70>'  : 'modeloSimulink/Robo/PID Controller/N Copy/External Parameters'
 * '<S71>'  : 'modeloSimulink/Robo/PID Controller/N Copy/Internal Parameters'
 * '<S72>'  : 'modeloSimulink/Robo/PID Controller/N Gain/Disabled'
 * '<S73>'  : 'modeloSimulink/Robo/PID Controller/N Gain/External Parameters'
 * '<S74>'  : 'modeloSimulink/Robo/PID Controller/N Gain/Internal Parameters'
 * '<S75>'  : 'modeloSimulink/Robo/PID Controller/N Gain/Passthrough'
 * '<S76>'  : 'modeloSimulink/Robo/PID Controller/P Copy/Disabled'
 * '<S77>'  : 'modeloSimulink/Robo/PID Controller/P Copy/External Parameters Ideal'
 * '<S78>'  : 'modeloSimulink/Robo/PID Controller/P Copy/Internal Parameters Ideal'
 * '<S79>'  : 'modeloSimulink/Robo/PID Controller/Parallel P Gain/Disabled'
 * '<S80>'  : 'modeloSimulink/Robo/PID Controller/Parallel P Gain/External Parameters'
 * '<S81>'  : 'modeloSimulink/Robo/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S82>'  : 'modeloSimulink/Robo/PID Controller/Parallel P Gain/Passthrough'
 * '<S83>'  : 'modeloSimulink/Robo/PID Controller/Reset Signal/Disabled'
 * '<S84>'  : 'modeloSimulink/Robo/PID Controller/Reset Signal/External Reset'
 * '<S85>'  : 'modeloSimulink/Robo/PID Controller/Saturation/Enabled'
 * '<S86>'  : 'modeloSimulink/Robo/PID Controller/Saturation/Passthrough'
 * '<S87>'  : 'modeloSimulink/Robo/PID Controller/Saturation Fdbk/Disabled'
 * '<S88>'  : 'modeloSimulink/Robo/PID Controller/Saturation Fdbk/Enabled'
 * '<S89>'  : 'modeloSimulink/Robo/PID Controller/Saturation Fdbk/Passthrough'
 * '<S90>'  : 'modeloSimulink/Robo/PID Controller/Sum/Passthrough_I'
 * '<S91>'  : 'modeloSimulink/Robo/PID Controller/Sum/Passthrough_P'
 * '<S92>'  : 'modeloSimulink/Robo/PID Controller/Sum/Sum_PD'
 * '<S93>'  : 'modeloSimulink/Robo/PID Controller/Sum/Sum_PI'
 * '<S94>'  : 'modeloSimulink/Robo/PID Controller/Sum/Sum_PID'
 * '<S95>'  : 'modeloSimulink/Robo/PID Controller/Sum Fdbk/Disabled'
 * '<S96>'  : 'modeloSimulink/Robo/PID Controller/Sum Fdbk/Enabled'
 * '<S97>'  : 'modeloSimulink/Robo/PID Controller/Sum Fdbk/Passthrough'
 * '<S98>'  : 'modeloSimulink/Robo/PID Controller/Tracking Mode/Disabled'
 * '<S99>'  : 'modeloSimulink/Robo/PID Controller/Tracking Mode/Enabled'
 * '<S100>' : 'modeloSimulink/Robo/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S101>' : 'modeloSimulink/Robo/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S102>' : 'modeloSimulink/Robo/PID Controller/postSat Signal/Feedback_Path'
 * '<S103>' : 'modeloSimulink/Robo/PID Controller/postSat Signal/Forward_Path'
 * '<S104>' : 'modeloSimulink/Robo/PID Controller/preSat Signal/Feedback_Path'
 * '<S105>' : 'modeloSimulink/Robo/PID Controller/preSat Signal/Forward_Path'
 * '<S106>' : 'modeloSimulink/Robo/PID Controller1/Anti-windup'
 * '<S107>' : 'modeloSimulink/Robo/PID Controller1/D Gain'
 * '<S108>' : 'modeloSimulink/Robo/PID Controller1/Filter'
 * '<S109>' : 'modeloSimulink/Robo/PID Controller1/Filter ICs'
 * '<S110>' : 'modeloSimulink/Robo/PID Controller1/I Gain'
 * '<S111>' : 'modeloSimulink/Robo/PID Controller1/Ideal P Gain'
 * '<S112>' : 'modeloSimulink/Robo/PID Controller1/Ideal P Gain Fdbk'
 * '<S113>' : 'modeloSimulink/Robo/PID Controller1/Integrator'
 * '<S114>' : 'modeloSimulink/Robo/PID Controller1/Integrator ICs'
 * '<S115>' : 'modeloSimulink/Robo/PID Controller1/N Copy'
 * '<S116>' : 'modeloSimulink/Robo/PID Controller1/N Gain'
 * '<S117>' : 'modeloSimulink/Robo/PID Controller1/P Copy'
 * '<S118>' : 'modeloSimulink/Robo/PID Controller1/Parallel P Gain'
 * '<S119>' : 'modeloSimulink/Robo/PID Controller1/Reset Signal'
 * '<S120>' : 'modeloSimulink/Robo/PID Controller1/Saturation'
 * '<S121>' : 'modeloSimulink/Robo/PID Controller1/Saturation Fdbk'
 * '<S122>' : 'modeloSimulink/Robo/PID Controller1/Sum'
 * '<S123>' : 'modeloSimulink/Robo/PID Controller1/Sum Fdbk'
 * '<S124>' : 'modeloSimulink/Robo/PID Controller1/Tracking Mode'
 * '<S125>' : 'modeloSimulink/Robo/PID Controller1/Tracking Mode Sum'
 * '<S126>' : 'modeloSimulink/Robo/PID Controller1/postSat Signal'
 * '<S127>' : 'modeloSimulink/Robo/PID Controller1/preSat Signal'
 * '<S128>' : 'modeloSimulink/Robo/PID Controller1/Anti-windup/Back Calculation'
 * '<S129>' : 'modeloSimulink/Robo/PID Controller1/Anti-windup/Cont. Clamping Ideal'
 * '<S130>' : 'modeloSimulink/Robo/PID Controller1/Anti-windup/Cont. Clamping Parallel'
 * '<S131>' : 'modeloSimulink/Robo/PID Controller1/Anti-windup/Disabled'
 * '<S132>' : 'modeloSimulink/Robo/PID Controller1/Anti-windup/Disc. Clamping Ideal'
 * '<S133>' : 'modeloSimulink/Robo/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S134>' : 'modeloSimulink/Robo/PID Controller1/Anti-windup/Passthrough'
 * '<S135>' : 'modeloSimulink/Robo/PID Controller1/D Gain/Disabled'
 * '<S136>' : 'modeloSimulink/Robo/PID Controller1/D Gain/External Parameters'
 * '<S137>' : 'modeloSimulink/Robo/PID Controller1/D Gain/Internal Parameters'
 * '<S138>' : 'modeloSimulink/Robo/PID Controller1/Filter/Cont. Filter'
 * '<S139>' : 'modeloSimulink/Robo/PID Controller1/Filter/Differentiator'
 * '<S140>' : 'modeloSimulink/Robo/PID Controller1/Filter/Disabled'
 * '<S141>' : 'modeloSimulink/Robo/PID Controller1/Filter/Disc. Backward Euler Filter'
 * '<S142>' : 'modeloSimulink/Robo/PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S143>' : 'modeloSimulink/Robo/PID Controller1/Filter/Disc. Trapezoidal Filter'
 * '<S144>' : 'modeloSimulink/Robo/PID Controller1/Filter ICs/Disabled'
 * '<S145>' : 'modeloSimulink/Robo/PID Controller1/Filter ICs/External IC'
 * '<S146>' : 'modeloSimulink/Robo/PID Controller1/Filter ICs/Internal IC - Differentiator'
 * '<S147>' : 'modeloSimulink/Robo/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S148>' : 'modeloSimulink/Robo/PID Controller1/I Gain/Disabled'
 * '<S149>' : 'modeloSimulink/Robo/PID Controller1/I Gain/External Parameters'
 * '<S150>' : 'modeloSimulink/Robo/PID Controller1/I Gain/Internal Parameters'
 * '<S151>' : 'modeloSimulink/Robo/PID Controller1/Ideal P Gain/External Parameters'
 * '<S152>' : 'modeloSimulink/Robo/PID Controller1/Ideal P Gain/Internal Parameters'
 * '<S153>' : 'modeloSimulink/Robo/PID Controller1/Ideal P Gain/Passthrough'
 * '<S154>' : 'modeloSimulink/Robo/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S155>' : 'modeloSimulink/Robo/PID Controller1/Ideal P Gain Fdbk/External Parameters'
 * '<S156>' : 'modeloSimulink/Robo/PID Controller1/Ideal P Gain Fdbk/Internal Parameters'
 * '<S157>' : 'modeloSimulink/Robo/PID Controller1/Ideal P Gain Fdbk/Passthrough'
 * '<S158>' : 'modeloSimulink/Robo/PID Controller1/Integrator/Continuous'
 * '<S159>' : 'modeloSimulink/Robo/PID Controller1/Integrator/Disabled'
 * '<S160>' : 'modeloSimulink/Robo/PID Controller1/Integrator/Discrete'
 * '<S161>' : 'modeloSimulink/Robo/PID Controller1/Integrator ICs/Disabled'
 * '<S162>' : 'modeloSimulink/Robo/PID Controller1/Integrator ICs/External IC'
 * '<S163>' : 'modeloSimulink/Robo/PID Controller1/Integrator ICs/Internal IC'
 * '<S164>' : 'modeloSimulink/Robo/PID Controller1/N Copy/Disabled'
 * '<S165>' : 'modeloSimulink/Robo/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S166>' : 'modeloSimulink/Robo/PID Controller1/N Copy/External Parameters'
 * '<S167>' : 'modeloSimulink/Robo/PID Controller1/N Copy/Internal Parameters'
 * '<S168>' : 'modeloSimulink/Robo/PID Controller1/N Gain/Disabled'
 * '<S169>' : 'modeloSimulink/Robo/PID Controller1/N Gain/External Parameters'
 * '<S170>' : 'modeloSimulink/Robo/PID Controller1/N Gain/Internal Parameters'
 * '<S171>' : 'modeloSimulink/Robo/PID Controller1/N Gain/Passthrough'
 * '<S172>' : 'modeloSimulink/Robo/PID Controller1/P Copy/Disabled'
 * '<S173>' : 'modeloSimulink/Robo/PID Controller1/P Copy/External Parameters Ideal'
 * '<S174>' : 'modeloSimulink/Robo/PID Controller1/P Copy/Internal Parameters Ideal'
 * '<S175>' : 'modeloSimulink/Robo/PID Controller1/Parallel P Gain/Disabled'
 * '<S176>' : 'modeloSimulink/Robo/PID Controller1/Parallel P Gain/External Parameters'
 * '<S177>' : 'modeloSimulink/Robo/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S178>' : 'modeloSimulink/Robo/PID Controller1/Parallel P Gain/Passthrough'
 * '<S179>' : 'modeloSimulink/Robo/PID Controller1/Reset Signal/Disabled'
 * '<S180>' : 'modeloSimulink/Robo/PID Controller1/Reset Signal/External Reset'
 * '<S181>' : 'modeloSimulink/Robo/PID Controller1/Saturation/Enabled'
 * '<S182>' : 'modeloSimulink/Robo/PID Controller1/Saturation/Passthrough'
 * '<S183>' : 'modeloSimulink/Robo/PID Controller1/Saturation Fdbk/Disabled'
 * '<S184>' : 'modeloSimulink/Robo/PID Controller1/Saturation Fdbk/Enabled'
 * '<S185>' : 'modeloSimulink/Robo/PID Controller1/Saturation Fdbk/Passthrough'
 * '<S186>' : 'modeloSimulink/Robo/PID Controller1/Sum/Passthrough_I'
 * '<S187>' : 'modeloSimulink/Robo/PID Controller1/Sum/Passthrough_P'
 * '<S188>' : 'modeloSimulink/Robo/PID Controller1/Sum/Sum_PD'
 * '<S189>' : 'modeloSimulink/Robo/PID Controller1/Sum/Sum_PI'
 * '<S190>' : 'modeloSimulink/Robo/PID Controller1/Sum/Sum_PID'
 * '<S191>' : 'modeloSimulink/Robo/PID Controller1/Sum Fdbk/Disabled'
 * '<S192>' : 'modeloSimulink/Robo/PID Controller1/Sum Fdbk/Enabled'
 * '<S193>' : 'modeloSimulink/Robo/PID Controller1/Sum Fdbk/Passthrough'
 * '<S194>' : 'modeloSimulink/Robo/PID Controller1/Tracking Mode/Disabled'
 * '<S195>' : 'modeloSimulink/Robo/PID Controller1/Tracking Mode/Enabled'
 * '<S196>' : 'modeloSimulink/Robo/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S197>' : 'modeloSimulink/Robo/PID Controller1/Tracking Mode Sum/Tracking Mode'
 * '<S198>' : 'modeloSimulink/Robo/PID Controller1/postSat Signal/Feedback_Path'
 * '<S199>' : 'modeloSimulink/Robo/PID Controller1/postSat Signal/Forward_Path'
 * '<S200>' : 'modeloSimulink/Robo/PID Controller1/preSat Signal/Feedback_Path'
 * '<S201>' : 'modeloSimulink/Robo/PID Controller1/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_modeloSimulink_h_ */
