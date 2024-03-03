/*
 * File: Car_Blinkers.h
 *
 * Code generated for Simulink model 'Car_Blinkers'.
 *
 * Model version                  : 7.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Mar  3 04:08:50 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Car_Blinkers_h_
#define RTW_HEADER_Car_Blinkers_h_
#ifndef Car_Blinkers_COMMON_INCLUDES_
#define Car_Blinkers_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* Car_Blinkers_COMMON_INCLUDES_ */

#include <stddef.h>
#include "zero_crossing_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define Car_Blinkers_M                 (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#ifndef struct_tag_04b6x6tDldj9IrIH2gmbjG
#define struct_tag_04b6x6tDldj9IrIH2gmbjG

struct tag_04b6x6tDldj9IrIH2gmbjG
{
  int16_T __dummy;
};

#endif                                 /* struct_tag_04b6x6tDldj9IrIH2gmbjG */

#ifndef typedef_d_arduinodriver_ArduinoDigitalI
#define typedef_d_arduinodriver_ArduinoDigitalI

typedef struct tag_04b6x6tDldj9IrIH2gmbjG d_arduinodriver_ArduinoDigitalI;

#endif                             /* typedef_d_arduinodriver_ArduinoDigitalI */

#ifndef struct_tag_HaWnjzA2iiR2NMKNB2VNI
#define struct_tag_HaWnjzA2iiR2NMKNB2VNI

struct tag_HaWnjzA2iiR2NMKNB2VNI
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  d_arduinodriver_ArduinoDigitalI DigitalIODriverObj;
  real_T SampleTime;
};

#endif                                 /* struct_tag_HaWnjzA2iiR2NMKNB2VNI */

#ifndef typedef_codertarget_arduinobase_blocks_
#define typedef_codertarget_arduinobase_blocks_

typedef struct tag_HaWnjzA2iiR2NMKNB2VNI codertarget_arduinobase_blocks_;

#endif                             /* typedef_codertarget_arduinobase_blocks_ */

#ifndef struct_tag_04b6x6tDldj9IrIH2gmbjG
#define struct_tag_04b6x6tDldj9IrIH2gmbjG

struct tag_04b6x6tDldj9IrIH2gmbjG
{
  int16_T __dummy;
};

#endif                                 /* struct_tag_04b6x6tDldj9IrIH2gmbjG */

#ifndef typedef_b_arduinodriver_ArduinoDigitalI
#define typedef_b_arduinodriver_ArduinoDigitalI

typedef struct tag_04b6x6tDldj9IrIH2gmbjG b_arduinodriver_ArduinoDigitalI;

#endif                             /* typedef_b_arduinodriver_ArduinoDigitalI */

#ifndef struct_tag_AYWgtFscQm3mLUJYb3A20C
#define struct_tag_AYWgtFscQm3mLUJYb3A20C

struct tag_AYWgtFscQm3mLUJYb3A20C
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigitalI DigitalIODriverObj;
};

#endif                                 /* struct_tag_AYWgtFscQm3mLUJYb3A20C */

#ifndef typedef_codertarget_arduinobase_block_k
#define typedef_codertarget_arduinobase_block_k

typedef struct tag_AYWgtFscQm3mLUJYb3A20C codertarget_arduinobase_block_k;

#endif                             /* typedef_codertarget_arduinobase_block_k */

/* Block signals and states (default storage) for system '<S1>/Counter_Button1' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S4>/Unit Delay' */
  boolean_T Counter_Button1_MODE;      /* '<S1>/Counter_Button1' */
} DW_Counter_Button1;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_Counter_Button1 Counter_Button3;  /* '<S1>/Counter_Button3' */
  DW_Counter_Button1 Counter_Button2;  /* '<S1>/Counter_Button2' */
  DW_Counter_Button1 Counter_Button1_d;/* '<S1>/Counter_Button1' */
  codertarget_arduinobase_blocks_ obj; /* '<Root>/Digital Input2' */
  codertarget_arduinobase_blocks_ obj_p;/* '<Root>/Digital Input1' */
  codertarget_arduinobase_blocks_ obj_pp;/* '<Root>/Digital Input' */
  codertarget_arduinobase_block_k obj_c;/* '<Root>/Digital Output1' */
  codertarget_arduinobase_block_k obj_h;/* '<Root>/Digital Output' */
  real_T LEd1_state;                   /* '<S13>/Merge' */
  real_T LEd2_state;                   /* '<S13>/Merge1' */
  real_T y;                            /* '<S3>/MATLAB Function' */
  real_T Merge;                        /* '<S24>/Merge' */
  real_T Merge1;                       /* '<S24>/Merge1' */
  real_T Activation_Signal;            /* '<S16>/MATLAB Function' */
  real_T Switch;                       /* '<S22>/Switch' */
  real_T y_e;                          /* '<S12>/MATLAB Function1' */
  real_T y_b;                          /* '<S11>/MATLAB Function' */
  real_T Add;                          /* '<S6>/Add' */
  real_T Add_a;                        /* '<S5>/Add' */
  real_T Add_p;                        /* '<S4>/Add' */
  real_T UnitDelay_DSTATE;             /* '<S16>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S16>/Unit Delay1' */
  real_T UnitDelay_DSTATE_e;           /* '<S22>/Unit Delay' */
  real_T y_g;                          /* '<S1>/MATLAB Function' */
  uint32_T Counter_ClkEphState;        /* '<S3>/Counter' */
  uint32_T Counter_RstEphState;        /* '<S3>/Counter' */
  uint32_T Counter_ClkEphState_p;      /* '<S11>/Counter' */
  uint32_T Counter_RstEphState_d;      /* '<S11>/Counter' */
  uint32_T Counter1_ClkEphState;       /* '<S12>/Counter1' */
  uint32_T Counter1_RstEphState;       /* '<S12>/Counter1' */
  uint8_T Counter_Count;               /* '<S3>/Counter' */
  uint8_T Counter_Count_h;             /* '<S11>/Counter' */
  uint8_T Counter1_Count;              /* '<S12>/Counter1' */
  boolean_T AND;                       /* '<S20>/AND' */
  boolean_T AND_d;                     /* '<S21>/AND' */
  boolean_T UnitDelay_DSTATE_a;        /* '<S20>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_m;        /* '<S21>/Unit Delay' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Leds_signals_Trig_ZCE;    /* '<S2>/Leds_signals' */
  ZCSigState First_Button_checker_Trig_ZCE;/* '<S16>/First_Button_checker' */
} PrevZCX;

/* Parameters for system: '<S1>/Counter_Button1' */
struct P_Counter_Button1_ {
  real_T Counter_For_Debouncing_Y0;
                                /* Computed Parameter: Counter_For_Debouncing_Y0
                                 * Referenced by: '<S4>/Counter_For_Debouncing'
                                 */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S4>/Unit Delay'
                                        */
};

/* Parameters for system: '<S1>/Counter_Button1' */
typedef struct P_Counter_Button1_ P_Counter_Button1;

/* Parameters for system: '<S2>/Led1On' */
struct P_Led1On_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S14>/Constant1'
                                        */
};

/* Parameters for system: '<S2>/Led1On' */
typedef struct P_Led1On_ P_Led1On;

/* Parameters for system: '<S2>/Alarm' */
struct P_Alarm_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S10>/Constant1'
                                        */
};

/* Parameters for system: '<S2>/Alarm' */
typedef struct P_Alarm_ P_Alarm;

/* Parameters for system: '<S24>/If Action Subsystem' */
struct P_IfActionSubsystem_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S25>/Constant'
                                        */
};

/* Parameters for system: '<S24>/If Action Subsystem' */
typedef struct P_IfActionSubsystem_ P_IfActionSubsystem;

/* Parameters (default storage) */
struct P_ {
  uint8_T Counter_InitialCount;        /* Mask Parameter: Counter_InitialCount
                                        * Referenced by: '<S3>/Counter'
                                        */
  uint8_T Counter_InitialCount_f;      /* Mask Parameter: Counter_InitialCount_f
                                        * Referenced by: '<S11>/Counter'
                                        */
  uint8_T Counter1_InitialCount;       /* Mask Parameter: Counter1_InitialCount
                                        * Referenced by: '<S12>/Counter1'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input'
                                        */
  real_T DigitalInput1_SampleTime;     /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input1'
                                        */
  real_T DigitalInput2_SampleTime;     /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input2'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T initialization_state_Y0; /* Computed Parameter: initialization_state_Y0
                                   * Referenced by: '<S22>/initialization_state'
                                   */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S22>/Unit Delay'
                                        */
  real_T Output_Y0;                    /* Computed Parameter: Output_Y0
                                        * Referenced by: '<S16>/Output'
                                        */
  real_T UnitDelay_InitialCondition_h; /* Expression: 0
                                        * Referenced by: '<S16>/Unit Delay'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S16>/Unit Delay1'
                                        */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S24>/Merge'
                                       */
  real_T Merge1_InitialOutput;       /* Computed Parameter: Merge1_InitialOutput
                                      * Referenced by: '<S24>/Merge1'
                                      */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Constant3_Value;              /* Expression: 2
                                        * Referenced by: '<S3>/Constant3'
                                        */
  real_T Constant_Value_e;             /* Expression: 2
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Constant1_Value_e;            /* Expression: 2
                                        * Referenced by: '<S12>/Constant1'
                                        */
  real_T Merge_InitialOutput_o;     /* Computed Parameter: Merge_InitialOutput_o
                                     * Referenced by: '<S13>/Merge'
                                     */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S13>/Switch'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T Merge1_InitialOutput_m;   /* Computed Parameter: Merge1_InitialOutput_m
                                    * Referenced by: '<S13>/Merge1'
                                    */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S13>/Switch1'
                                        */
  boolean_T UnitDelay_InitialCondition_i;
                             /* Computed Parameter: UnitDelay_InitialCondition_i
                              * Referenced by: '<S20>/Unit Delay'
                              */
  boolean_T UnitDelay_InitialCondition_j;
                             /* Computed Parameter: UnitDelay_InitialCondition_j
                              * Referenced by: '<S21>/Unit Delay'
                              */
  P_IfActionSubsystem IfActionSubsystem7;/* '<S24>/If Action Subsystem7' */
  P_IfActionSubsystem IfActionSubsystem5;/* '<S24>/If Action Subsystem5' */
  P_IfActionSubsystem IfActionSubsystem4;/* '<S24>/If Action Subsystem4' */
  P_IfActionSubsystem IfActionSubsystem2;/* '<S24>/If Action Subsystem2' */
  P_IfActionSubsystem IfActionSubsystem1;/* '<S24>/If Action Subsystem1' */
  P_IfActionSubsystem IfActionSubsystem_b;/* '<S24>/If Action Subsystem' */
  P_Alarm Ledsoff;                     /* '<S2>/Ledsoff' */
  P_Alarm Alarm_h;                     /* '<S2>/Alarm' */
  P_Led1On Led2on;                     /* '<S2>/Led2on' */
  P_Led1On Led1On_a;                   /* '<S2>/Led1On' */
  P_Counter_Button1 Counter_Button3;   /* '<S1>/Counter_Button3' */
  P_Counter_Button1 Counter_Button2;   /* '<S1>/Counter_Button2' */
  P_Counter_Button1 Counter_Button1_d; /* '<S1>/Counter_Button1' */
};

/* Parameters (default storage) */
typedef struct P_ P;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[3];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P rtP;

/* Block signals and states (default storage) */
extern DW rtDW;

/* Zero-crossing (trigger) state */
extern PrevZCX rtPrevZCX;

/* Model entry point functions */
extern void Car_Blinkers_initialize(void);
extern void Car_Blinkers_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'Car_Blinkers'
 * '<S1>'   : 'Car_Blinkers/Generting_Pulse_every_turnOn_AndSolvig_Debouncing'
 * '<S2>'   : 'Car_Blinkers/LEDs_Operation'
 * '<S3>'   : 'Car_Blinkers/checking_how_many_Warning_Was_clicked'
 * '<S4>'   : 'Car_Blinkers/Generting_Pulse_every_turnOn_AndSolvig_Debouncing/Counter_Button1'
 * '<S5>'   : 'Car_Blinkers/Generting_Pulse_every_turnOn_AndSolvig_Debouncing/Counter_Button2'
 * '<S6>'   : 'Car_Blinkers/Generting_Pulse_every_turnOn_AndSolvig_Debouncing/Counter_Button3'
 * '<S7>'   : 'Car_Blinkers/Generting_Pulse_every_turnOn_AndSolvig_Debouncing/MATLAB Function'
 * '<S8>'   : 'Car_Blinkers/Generting_Pulse_every_turnOn_AndSolvig_Debouncing/MATLAB Function1'
 * '<S9>'   : 'Car_Blinkers/Generting_Pulse_every_turnOn_AndSolvig_Debouncing/MATLAB Function2'
 * '<S10>'  : 'Car_Blinkers/LEDs_Operation/Alarm'
 * '<S11>'  : 'Car_Blinkers/LEDs_Operation/Button1_Clicks_inrow'
 * '<S12>'  : 'Car_Blinkers/LEDs_Operation/Button2_Clicks_inrow'
 * '<S13>'  : 'Car_Blinkers/LEDs_Operation/Final_Leds_States'
 * '<S14>'  : 'Car_Blinkers/LEDs_Operation/Led1On'
 * '<S15>'  : 'Car_Blinkers/LEDs_Operation/Led2on'
 * '<S16>'  : 'Car_Blinkers/LEDs_Operation/Leds_signals'
 * '<S17>'  : 'Car_Blinkers/LEDs_Operation/Ledsoff'
 * '<S18>'  : 'Car_Blinkers/LEDs_Operation/Button1_Clicks_inrow/MATLAB Function'
 * '<S19>'  : 'Car_Blinkers/LEDs_Operation/Button2_Clicks_inrow/MATLAB Function1'
 * '<S20>'  : 'Car_Blinkers/LEDs_Operation/Final_Leds_States/Subsystem'
 * '<S21>'  : 'Car_Blinkers/LEDs_Operation/Final_Leds_States/Subsystem2'
 * '<S22>'  : 'Car_Blinkers/LEDs_Operation/Leds_signals/First_Button_checker'
 * '<S23>'  : 'Car_Blinkers/LEDs_Operation/Leds_signals/MATLAB Function'
 * '<S24>'  : 'Car_Blinkers/LEDs_Operation/Leds_signals/Save_Previous_Status'
 * '<S25>'  : 'Car_Blinkers/LEDs_Operation/Leds_signals/Save_Previous_Status/If Action Subsystem'
 * '<S26>'  : 'Car_Blinkers/LEDs_Operation/Leds_signals/Save_Previous_Status/If Action Subsystem1'
 * '<S27>'  : 'Car_Blinkers/LEDs_Operation/Leds_signals/Save_Previous_Status/If Action Subsystem2'
 * '<S28>'  : 'Car_Blinkers/LEDs_Operation/Leds_signals/Save_Previous_Status/If Action Subsystem4'
 * '<S29>'  : 'Car_Blinkers/LEDs_Operation/Leds_signals/Save_Previous_Status/If Action Subsystem5'
 * '<S30>'  : 'Car_Blinkers/LEDs_Operation/Leds_signals/Save_Previous_Status/If Action Subsystem7'
 * '<S31>'  : 'Car_Blinkers/checking_how_many_Warning_Was_clicked/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_Car_Blinkers_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
