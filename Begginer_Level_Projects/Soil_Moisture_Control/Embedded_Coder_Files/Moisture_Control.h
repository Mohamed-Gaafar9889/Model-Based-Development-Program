/*
 * File: Moisture_Control.h
 *
 * Code generated for Simulink model 'Moisture_Control'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Feb 27 17:30:21 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR (32-bit)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Moisture_Control_h_
#define RTW_HEADER_Moisture_Control_h_
#ifndef Moisture_Control_COMMON_INCLUDES_
#define Moisture_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Moisture_Control_COMMON_INCLUDES_ */

#include <math.h>
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T MoistureDifference_State;     /* '<Root>/Merge' */
  real_T Add;                          /* '<S2>/Add' */
  real_T UnitDelay_DSTATE;             /* '<S2>/Unit Delay' */
  struct {
    int_T PrevIndex;
  } FromWorkspace_IWORK;               /* '<Root>/From Workspace' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace_PWORK;               /* '<Root>/From Workspace' */

  boolean_T Ckecking_Indicator_MODE;   /* '<Root>/Ckecking_Indicator' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Ckecking_Indicator_Trig_ZCE;/* '<Root>/Ckecking_Indicator' */
} PrevZCX;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [0 2.5 5 7.5 10 12.5 15]
   * Referenced by: '<S10>/2-D Lookup Table1'
   */
  real_T uDLookupTable1_tableData[7];

  /* Expression: [0 0.1 0.2 0.3 0.4 0.5 0.6]
   * Referenced by: '<S10>/2-D Lookup Table1'
   */
  real_T uDLookupTable1_bp01Data[7];
} ConstP;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Pump_State;                   /* '<Root>/Pump_State' */
  real_T Epected_Irrigation_Time;      /* '<Root>/Epected_Irrigation_Time' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* Zero-crossing (trigger) state */
extern PrevZCX rtPrevZCX;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void Moisture_Control_initialize(void);
extern void Moisture_Control_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Constant' : Unused code path elimination
 */

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
 * '<Root>' : 'Moisture_Control'
 * '<S1>'   : 'Moisture_Control/Activator'
 * '<S2>'   : 'Moisture_Control/Ckecking_Indicator'
 * '<S3>'   : 'Moisture_Control/DeActivator'
 * '<S4>'   : 'Moisture_Control/If Action Subsystem'
 * '<S5>'   : 'Moisture_Control/If Action Subsystem2'
 * '<S6>'   : 'Moisture_Control/Irrigation_Time_Calculator'
 * '<S7>'   : 'Moisture_Control/MATLAB Function'
 * '<S8>'   : 'Moisture_Control/Subsystem'
 * '<S9>'   : 'Moisture_Control/If Action Subsystem/MATLAB Function'
 * '<S10>'  : 'Moisture_Control/Irrigation_Time_Calculator/If Action Subsystem'
 * '<S11>'  : 'Moisture_Control/Irrigation_Time_Calculator/If Action Subsystem1'
 */
#endif                                 /* RTW_HEADER_Moisture_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
