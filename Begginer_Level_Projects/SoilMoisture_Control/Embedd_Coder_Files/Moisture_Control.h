/*
 * File: Moisture_Control.h
 *
 * Code generated for Simulink model 'Moisture_Control'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Feb 27 03:36:57 2024
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
#endif                                 /* Moisture_Control_COMMON_INCLUDES_ */

#include "zero_crossing_types.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T MoistureDifference_State;     /* '<Root>/Merge' */
  real_T OutportBufferForIrrigation_Syst;/* '<S5>/Constant' */
  real_T Merge;                        /* '<S4>/Merge' */
  real_T Add;                          /* '<S2>/Add' */
  real_T UnitDelay_DSTATE;             /* '<S2>/Unit Delay' */
  boolean_T Counter_MODE;              /* '<Root>/Counter ' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState System_Activation_Trig_ZCE;/* '<Root>/System_Activation' */
} PrevZCX;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [0 5 10 15 20 25 30]
   * Referenced by: '<S6>/2-D Lookup Table1'
   */
  real_T uDLookupTable1_tableData[7];

  /* Expression: [0 0.1 0.2 0.3 0.4 0.5 0.6]
   * Referenced by: '<S6>/2-D Lookup Table1'
   */
  real_T uDLookupTable1_bp01Data[7];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Moisture_Sensor;              /* '<Root>/Moisture_Sensor' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Pump_State;                   /* '<Root>/Pump_State' */
} ExtY;

/* Block signals and states (default storage) */
extern DW rtDW;

/* Zero-crossing (trigger) state */
extern PrevZCX rtPrevZCX;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void Moisture_Control_initialize(void);
extern void Moisture_Control_step0(void);
extern void Moisture_Control_step1(void);

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
 * '<S2>'   : 'Moisture_Control/Counter '
 * '<S3>'   : 'Moisture_Control/DeActivator'
 * '<S4>'   : 'Moisture_Control/Irrigation_Time_Calculator'
 * '<S5>'   : 'Moisture_Control/System_Activation'
 * '<S6>'   : 'Moisture_Control/Irrigation_Time_Calculator/If Action Subsystem'
 * '<S7>'   : 'Moisture_Control/Irrigation_Time_Calculator/If Action Subsystem1'
 */
#endif                                 /* RTW_HEADER_Moisture_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
