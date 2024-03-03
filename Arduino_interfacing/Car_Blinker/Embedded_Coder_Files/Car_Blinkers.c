/*
 * File: Car_Blinkers.c
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

#include "Car_Blinkers.h"
#include "rtwtypes.h"
#include <stddef.h>
#include "zero_crossing_types.h"
#include <math.h>
#include <float.h>
#define NumBitsPerChar                 8U

/* Block signals and states (default storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern uint32_T MWDSP_EPH_R_D(real_T evt, uint32_T *sta);
extern real_T rt_modd_snf(real_T u0, real_T u1);
extern real_T rt_roundd_snf(real_T u);
static void Counter_Button1_Init(real_T *rty_Counter_For_Debouncing,
  DW_Counter_Button1 *localDW, P_Counter_Button1 *localP);
static void Counter_Button1_Reset(DW_Counter_Button1 *localDW, P_Counter_Button1
  *localP);
static void Counter_Button1_Disable(DW_Counter_Button1 *localDW);
static void Counter_Button1(RT_MODEL * const rtM, boolean_T rtu_Enable, real_T
  *rty_Counter_For_Debouncing, DW_Counter_Button1 *localDW, P_Counter_Button1
  *localP);
static void MATLABFunction(real_T rtu_u, real_T *rty_y);
static void Led1On(real_T *rty_Led1, real_T *rty_Led2, P_Led1On *localP);
static void Alarm(real_T *rty_Led_One, real_T *rty_Led_two, P_Alarm *localP);
static void IfActionSubsystem(real_T *rty_Out1, P_IfActionSubsystem *localP);
static void rate_scheduler(void);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);

#define NOT_USING_NONFINITE_LITERALS   1

extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static void rt_InitInfAndNaN(size_t realSize);
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
static real_T rtGetInf(void);
static real32_T rtGetInfF(void);
static real_T rtGetMinusInf(void);
static real32_T rtGetMinusInfF(void);

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0.0F } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
static void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  boolean_T result = (boolean_T) 0;
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  if (bitsPerReal == 32U) {
    result = rtIsNaNF((real32_T)value);
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.fltVal = value;
    result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                         ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                          (tmpVal.bitVal.words.wordL != 0) ));
  }

  return result;
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  IEEESingle tmp;
  tmp.wordL.wordLreal = value;
  return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                     (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }

  (rtM->Timing.TaskCounters.TID[2])++;
  if ((rtM->Timing.TaskCounters.TID[2]) > 399) {/* Sample time: [0.4s, 0.0s] */
    rtM->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * System initialize for enable system:
 *    '<S1>/Counter_Button1'
 *    '<S1>/Counter_Button2'
 *    '<S1>/Counter_Button3'
 */
static void Counter_Button1_Init(real_T *rty_Counter_For_Debouncing,
  DW_Counter_Button1 *localDW, P_Counter_Button1 *localP)
{
  /* InitializeConditions for UnitDelay: '<S4>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localP->UnitDelay_InitialCondition;

  /* SystemInitialize for Outport: '<S4>/Counter_For_Debouncing' */
  *rty_Counter_For_Debouncing = localP->Counter_For_Debouncing_Y0;
}

/*
 * System reset for enable system:
 *    '<S1>/Counter_Button1'
 *    '<S1>/Counter_Button2'
 *    '<S1>/Counter_Button3'
 */
static void Counter_Button1_Reset(DW_Counter_Button1 *localDW, P_Counter_Button1
  *localP)
{
  /* InitializeConditions for UnitDelay: '<S4>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localP->UnitDelay_InitialCondition;
}

/*
 * Disable for enable system:
 *    '<S1>/Counter_Button1'
 *    '<S1>/Counter_Button2'
 *    '<S1>/Counter_Button3'
 */
static void Counter_Button1_Disable(DW_Counter_Button1 *localDW)
{
  localDW->Counter_Button1_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S1>/Counter_Button1'
 *    '<S1>/Counter_Button2'
 *    '<S1>/Counter_Button3'
 */
static void Counter_Button1(RT_MODEL * const rtM, boolean_T rtu_Enable, real_T
  *rty_Counter_For_Debouncing, DW_Counter_Button1 *localDW, P_Counter_Button1
  *localP)
{
  /* Outputs for Enabled SubSystem: '<S1>/Counter_Button1' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    if (rtu_Enable) {
      if (!localDW->Counter_Button1_MODE) {
        Counter_Button1_Reset(localDW, localP);
        localDW->Counter_Button1_MODE = true;
      }
    } else if (localDW->Counter_Button1_MODE) {
      Counter_Button1_Disable(localDW);
    }
  }

  if (localDW->Counter_Button1_MODE) {
    /* Sum: '<S4>/Add' incorporates:
     *  Constant: '<S4>/Constant'
     *  UnitDelay: '<S4>/Unit Delay'
     */
    *rty_Counter_For_Debouncing = localP->Constant_Value +
      localDW->UnitDelay_DSTATE;

    /* Update for UnitDelay: '<S4>/Unit Delay' */
    localDW->UnitDelay_DSTATE = *rty_Counter_For_Debouncing;
  }

  /* End of Outputs for SubSystem: '<S1>/Counter_Button1' */
}

/*
 * Output and update for atomic system:
 *    '<S1>/MATLAB Function'
 *    '<S1>/MATLAB Function1'
 *    '<S1>/MATLAB Function2'
 */
static void MATLABFunction(real_T rtu_u, real_T *rty_y)
{
  *rty_y = 0.0;
  if (rtu_u == 10.0) {
    *rty_y = 1.0;
  }
}

/*
 * Output and update for action system:
 *    '<S2>/Led1On'
 *    '<S2>/Led2on'
 */
static void Led1On(real_T *rty_Led1, real_T *rty_Led2, P_Led1On *localP)
{
  /* SignalConversion generated from: '<S14>/Led1' incorporates:
   *  Constant: '<S14>/Constant'
   */
  *rty_Led1 = localP->Constant_Value;

  /* SignalConversion generated from: '<S14>/Led2' incorporates:
   *  Constant: '<S14>/Constant1'
   */
  *rty_Led2 = localP->Constant1_Value;
}

/*
 * Output and update for action system:
 *    '<S2>/Alarm'
 *    '<S2>/Ledsoff'
 */
static void Alarm(real_T *rty_Led_One, real_T *rty_Led_two, P_Alarm *localP)
{
  /* SignalConversion generated from: '<S10>/Led_One' incorporates:
   *  Constant: '<S10>/Constant'
   */
  *rty_Led_One = localP->Constant_Value;

  /* SignalConversion generated from: '<S10>/Led_two' incorporates:
   *  Constant: '<S10>/Constant1'
   */
  *rty_Led_two = localP->Constant1_Value;
}

/*
 * Output and update for action system:
 *    '<S24>/If Action Subsystem'
 *    '<S24>/If Action Subsystem1'
 *    '<S24>/If Action Subsystem2'
 *    '<S24>/If Action Subsystem4'
 *    '<S24>/If Action Subsystem5'
 *    '<S24>/If Action Subsystem7'
 */
static void IfActionSubsystem(real_T *rty_Out1, P_IfActionSubsystem *localP)
{
  /* SignalConversion generated from: '<S25>/Out1' incorporates:
   *  Constant: '<S25>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
}

uint32_T MWDSP_EPH_R_D(real_T evt, uint32_T *sta)
{
  uint32_T previousState;
  uint32_T retVal;
  int16_T curState;
  int16_T lastzcevent;
  int16_T newState;
  int16_T newStateR;

  /* S-Function (sdspcount2): '<S3>/Counter' */
  /* Detect rising edge events */
  previousState = *sta;
  retVal = 0UL;
  lastzcevent = 0;
  newState = 5;
  newStateR = 5;
  if (evt > 0.0) {
    curState = 2;
  } else {
    curState = !(evt < 0.0);
  }

  if (*sta == 5UL) {
    newStateR = curState;
  } else if ((uint32_T)curState != *sta) {
    if (*sta == 3UL) {
      if ((uint16_T)curState == 1U) {
        newStateR = 1;
      } else {
        lastzcevent = 2;
        previousState = 1UL;
      }
    }

    if (previousState == 4UL) {
      if ((uint16_T)curState == 1U) {
        newStateR = 1;
      } else {
        lastzcevent = 3;
        previousState = 1UL;
      }
    }

    if ((previousState == 1UL) && ((uint16_T)curState == 2U)) {
      retVal = 2UL;
    }

    if (previousState == 0UL) {
      retVal = 2UL;
    }

    if ((uint16_T)retVal == (uint16_T)lastzcevent) {
      retVal = 0UL;
    }

    if (((uint16_T)curState == 1U) && ((uint16_T)retVal == 2U)) {
      newState = 3;
    } else {
      newState = curState;
    }
  }

  if ((uint16_T)newStateR != 5U) {
    *sta = (uint32_T)newStateR;
    retVal = 0UL;
  }

  if ((uint16_T)newState != 5U) {
    *sta = (uint32_T)newState;
  }

  /* End of S-Function (sdspcount2): '<S3>/Counter' */
  return retVal;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void Car_Blinkers_step(void)
{
  real_T rtb_Counter1;
  real_T rtb_Mod;
  real_T rtb_Out_Signal;
  real_T rtb_y;
  real_T rtb_y_p;
  uint8_T tmp;
  boolean_T rtb_Button1 = false;
  boolean_T rtb_Button2 = false;
  boolean_T rtb_Button3 = false;
  boolean_T tmp_0;
  if (rtM->Timing.TaskCounters.TID[2] == 0) {
    /* Logic: '<S20>/AND' incorporates:
     *  Constant: '<S20>/Constant'
     *  Logic: '<S20>/NOT'
     *  UnitDelay: '<S20>/Unit Delay'
     */
    rtDW.AND = ((rtP.Constant_Value_k != 0.0) && (!rtDW.UnitDelay_DSTATE_a));
  }

  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<Root>/Digital Input' */
    if (rtDW.obj_pp.SampleTime != rtP.DigitalInput_SampleTime) {
      rtDW.obj_pp.SampleTime = rtP.DigitalInput_SampleTime;
    }

    rtb_Button1 = readDigitalPin(11);

    /* End of MATLABSystem: '<Root>/Digital Input' */
  }

  /* Outputs for Enabled SubSystem: '<S1>/Counter_Button1' */
  Counter_Button1(rtM, rtb_Button1, &rtDW.Add_p, &rtDW.Counter_Button1_d,
                  &rtP.Counter_Button1_d);

  /* End of Outputs for SubSystem: '<S1>/Counter_Button1' */

  /* MATLAB Function: '<S1>/MATLAB Function' */
  MATLABFunction(rtDW.Add_p, &rtDW.y_g);
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<Root>/Digital Input1' */
    if (rtDW.obj_p.SampleTime != rtP.DigitalInput1_SampleTime) {
      rtDW.obj_p.SampleTime = rtP.DigitalInput1_SampleTime;
    }

    rtb_Button2 = readDigitalPin(12);

    /* End of MATLABSystem: '<Root>/Digital Input1' */
  }

  /* Outputs for Enabled SubSystem: '<S1>/Counter_Button2' */
  Counter_Button1(rtM, rtb_Button2, &rtDW.Add_a, &rtDW.Counter_Button2,
                  &rtP.Counter_Button2);

  /* End of Outputs for SubSystem: '<S1>/Counter_Button2' */

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  MATLABFunction(rtDW.Add_a, &rtb_y_p);
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* MATLABSystem: '<Root>/Digital Input2' */
    if (rtDW.obj.SampleTime != rtP.DigitalInput2_SampleTime) {
      rtDW.obj.SampleTime = rtP.DigitalInput2_SampleTime;
    }

    rtb_Button3 = readDigitalPin(13);

    /* End of MATLABSystem: '<Root>/Digital Input2' */
  }

  /* Outputs for Enabled SubSystem: '<S1>/Counter_Button3' */
  Counter_Button1(rtM, rtb_Button3, &rtDW.Add, &rtDW.Counter_Button3,
                  &rtP.Counter_Button3);

  /* End of Outputs for SubSystem: '<S1>/Counter_Button3' */

  /* MATLAB Function: '<S1>/MATLAB Function2' */
  MATLABFunction(rtDW.Add, &rtb_y);

  /* MATLAB Function: '<S3>/MATLAB Function' */
  rtDW.y = 0.0;
  if ((rtDW.y_g == 1.0) || (rtb_y_p == 1.0)) {
    rtDW.y = 1.0;
  }

  /* End of MATLAB Function: '<S3>/MATLAB Function' */

  /* S-Function (sdspcount2): '<S3>/Counter' */
  if (MWDSP_EPH_R_D(rtDW.y, &rtDW.Counter_RstEphState) != 0UL) {
    rtDW.Counter_Count = rtP.Counter_InitialCount;
  }

  if (MWDSP_EPH_R_D(rtb_y, &rtDW.Counter_ClkEphState) != 0UL) {
    if (rtDW.Counter_Count < 255) {
      rtDW.Counter_Count++;
    } else {
      rtDW.Counter_Count = 0U;
    }
  }

  /* Math: '<S3>/Mod' incorporates:
   *  Constant: '<S3>/Constant3'
   *  S-Function (sdspcount2): '<S3>/Counter'
   */
  rtb_Out_Signal = rt_modd_snf((real_T)rtDW.Counter_Count, rtP.Constant3_Value);

  /* MATLAB Function: '<S11>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S12>/MATLAB Function1'
   *  MATLAB Function: '<S16>/MATLAB Function'
   */
  rtDW.y_b = 0.0;
  rtb_Button2 = ((rtDW.y_g == 1.0) && (rtb_y_p == 0.0));

  /* Outputs for Triggered SubSystem: '<S2>/Leds_signals' incorporates:
   *  TriggerPort: '<S16>/Trigger'
   */
  rtb_Button3 = (rtb_Button2 && (rtb_y == 0.0));

  /* End of Outputs for SubSystem: '<S2>/Leds_signals' */
  if ((!rtb_Button3) && ((rtDW.y_g == 0.0) && ((rtb_y_p == 1.0) || (rtb_y == 1.0))))
  {
    rtDW.y_b = 1.0;
  }

  /* End of MATLAB Function: '<S11>/MATLAB Function' */

  /* S-Function (sdspcount2): '<S11>/Counter' */
  if (MWDSP_EPH_R_D(rtDW.y_b, &rtDW.Counter_RstEphState_d) != 0UL) {
    rtDW.Counter_Count_h = rtP.Counter_InitialCount_f;
  }

  if (MWDSP_EPH_R_D(rtDW.y_g, &rtDW.Counter_ClkEphState_p) != 0UL) {
    if (rtDW.Counter_Count_h < 255) {
      rtDW.Counter_Count_h++;
    } else {
      rtDW.Counter_Count_h = 0U;
    }
  }

  /* Math: '<S11>/Mod' incorporates:
   *  Constant: '<S11>/Constant'
   *  S-Function (sdspcount2): '<S11>/Counter'
   */
  rtb_Mod = rt_modd_snf((real_T)rtDW.Counter_Count_h, rtP.Constant_Value_e);

  /* MATLAB Function: '<S12>/MATLAB Function1' incorporates:
   *  MATLAB Function: '<S16>/MATLAB Function'
   */
  rtDW.y_e = 0.0;

  /* Outputs for Triggered SubSystem: '<S2>/Leds_signals' incorporates:
   *  TriggerPort: '<S16>/Trigger'
   */
  tmp_0 = ((rtDW.y_g == 0.0) && (rtb_y_p == 1.0) && (rtb_y == 0.0));

  /* End of Outputs for SubSystem: '<S2>/Leds_signals' */
  if ((!tmp_0) && (rtb_Button2 || (rtb_y == 1.0))) {
    rtDW.y_e = 1.0;
  }

  /* S-Function (sdspcount2): '<S12>/Counter1' */
  if (MWDSP_EPH_R_D(rtDW.y_e, &rtDW.Counter1_RstEphState) != 0UL) {
    rtDW.Counter1_Count = rtP.Counter1_InitialCount;
  }

  if (MWDSP_EPH_R_D(rtb_y_p, &rtDW.Counter1_ClkEphState) != 0UL) {
    if (rtDW.Counter1_Count < 255) {
      rtDW.Counter1_Count++;
    } else {
      rtDW.Counter1_Count = 0U;
    }
  }

  /* Math: '<S12>/Mod1' incorporates:
   *  Constant: '<S12>/Constant1'
   *  S-Function (sdspcount2): '<S12>/Counter1'
   */
  rtb_Counter1 = rt_modd_snf((real_T)rtDW.Counter1_Count, rtP.Constant1_Value_e);

  /* Logic: '<S2>/OR' */
  rtb_Button1 = ((rtb_y_p != 0.0) || (rtDW.y_g != 0.0) || (rtb_y != 0.0));

  /* Outputs for Triggered SubSystem: '<S2>/Leds_signals' incorporates:
   *  TriggerPort: '<S16>/Trigger'
   */
  if (rtb_Button1 && (rtPrevZCX.Leds_signals_Trig_ZCE != POS_ZCSIG)) {
    /* MATLAB Function: '<S16>/MATLAB Function' incorporates:
     *  UnitDelay: '<S16>/Unit Delay'
     *  UnitDelay: '<S16>/Unit Delay1'
     */
    rtDW.Activation_Signal = 0.0;
    if (rtb_Button3 && (rtb_Mod != 0.0)) {
      rtDW.Activation_Signal = 1.0;
    } else if ((rtb_Button3 && (rtb_Mod == 0.0)) || (tmp_0 && (rtb_Counter1 ==
                 0.0))) {
      rtDW.Activation_Signal = 3.0;
    } else if (tmp_0 && (rtb_Counter1 != 0.0)) {
      rtDW.Activation_Signal = -1.0;
    } else {
      rtb_Button2 = ((rtDW.y_g == 0.0) && (rtb_y_p == 0.0));
      if (rtb_Button2 && (rtb_Out_Signal == 1.0)) {
        rtDW.Activation_Signal = 2.0;
      } else if (rtb_Button2 && (rtb_Out_Signal == 0.0)) {
        rtDW.Activation_Signal = rtDW.UnitDelay_DSTATE;
      }
    }

    if ((rtDW.UnitDelay1_DSTATE == 0.0) && (rtb_Out_Signal == 0.0) &&
        (rtDW.UnitDelay_DSTATE == 0.0) && (rtDW.y_g == 0.0) && (rtb_y_p == 0.0))
    {
      rtDW.Activation_Signal = 3.0;
    }

    if ((rtDW.UnitDelay_DSTATE == -1.0) && (rtb_Counter1 != 0.0)) {
      rtDW.Activation_Signal = 3.0;
    }

    if ((rtDW.UnitDelay_DSTATE == 1.0) && (rtb_Mod != 0.0)) {
      rtDW.Activation_Signal = 3.0;
    }

    /* If: '<S16>/If' */
    if (rtDW.Activation_Signal == 1.0) {
      /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem' incorporates:
       *  ActionPort: '<S25>/Action Port'
       */
      IfActionSubsystem(&rtDW.Merge, &rtP.IfActionSubsystem_b);

      /* End of Outputs for SubSystem: '<S24>/If Action Subsystem' */
    } else if (rtDW.Activation_Signal == -1.0) {
      /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S26>/Action Port'
       */
      IfActionSubsystem(&rtDW.Merge, &rtP.IfActionSubsystem1);

      /* End of Outputs for SubSystem: '<S24>/If Action Subsystem1' */
    } else if (rtDW.Activation_Signal == 3.0) {
      /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S27>/Action Port'
       */
      IfActionSubsystem(&rtDW.Merge, &rtP.IfActionSubsystem2);

      /* End of Outputs for SubSystem: '<S24>/If Action Subsystem2' */
    }

    /* End of If: '<S16>/If' */

    /* SwitchCase: '<S24>/Switch Case' */
    switch ((int32_T)rtDW.Merge) {
     case 1L:
      /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S28>/Action Port'
       */
      IfActionSubsystem(&rtDW.Merge1, &rtP.IfActionSubsystem4);

      /* End of Outputs for SubSystem: '<S24>/If Action Subsystem4' */
      break;

     case -1L:
      /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S29>/Action Port'
       */
      IfActionSubsystem(&rtDW.Merge1, &rtP.IfActionSubsystem5);

      /* End of Outputs for SubSystem: '<S24>/If Action Subsystem5' */
      break;

     case 3L:
      /* Outputs for IfAction SubSystem: '<S24>/If Action Subsystem7' incorporates:
       *  ActionPort: '<S30>/Action Port'
       */
      IfActionSubsystem(&rtDW.Merge1, &rtP.IfActionSubsystem7);

      /* End of Outputs for SubSystem: '<S24>/If Action Subsystem7' */
      break;
    }

    /* End of SwitchCase: '<S24>/Switch Case' */

    /* Logic: '<S16>/OR' */
    rtb_Button2 = ((rtDW.y_g != 0.0) || (rtb_y_p != 0.0));

    /* Outputs for Triggered SubSystem: '<S16>/First_Button_checker' incorporates:
     *  TriggerPort: '<S22>/Trigger'
     */
    if (rtb_Button2 && (rtPrevZCX.First_Button_checker_Trig_ZCE != POS_ZCSIG)) {
      /* Switch: '<S22>/Switch' incorporates:
       *  Constant: '<S22>/Constant'
       */
      rtDW.Switch = rtP.Constant_Value_d;

      /* Update for UnitDelay: '<S22>/Unit Delay' */
      rtDW.UnitDelay_DSTATE_e = rtDW.Switch;
    }

    rtPrevZCX.First_Button_checker_Trig_ZCE = rtb_Button2;

    /* End of Outputs for SubSystem: '<S16>/First_Button_checker' */

    /* Update for UnitDelay: '<S16>/Unit Delay' */
    rtDW.UnitDelay_DSTATE = rtDW.Merge1;

    /* Update for UnitDelay: '<S16>/Unit Delay1' */
    rtDW.UnitDelay1_DSTATE = rtDW.Switch;
  }

  rtPrevZCX.Leds_signals_Trig_ZCE = rtb_Button1;

  /* End of Outputs for SubSystem: '<S2>/Leds_signals' */

  /* If: '<S2>/If' */
  if (rtDW.Activation_Signal == 1.0) {
    /* Outputs for IfAction SubSystem: '<S2>/Led1On' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    Led1On(&rtDW.LEd1_state, &rtDW.LEd2_state, &rtP.Led1On_a);

    /* End of Outputs for SubSystem: '<S2>/Led1On' */
  } else if (rtDW.Activation_Signal == -1.0) {
    /* Outputs for IfAction SubSystem: '<S2>/Led2on' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    Led1On(&rtDW.LEd1_state, &rtDW.LEd2_state, &rtP.Led2on);

    /* End of Outputs for SubSystem: '<S2>/Led2on' */
  } else if (rtDW.Activation_Signal == 2.0) {
    /* Outputs for IfAction SubSystem: '<S2>/Alarm' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    Alarm(&rtDW.LEd1_state, &rtDW.LEd2_state, &rtP.Alarm_h);

    /* End of Outputs for SubSystem: '<S2>/Alarm' */
  } else if (rtDW.Activation_Signal == 3.0) {
    /* Outputs for IfAction SubSystem: '<S2>/Ledsoff' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    Alarm(&rtDW.LEd1_state, &rtDW.LEd2_state, &rtP.Ledsoff);

    /* End of Outputs for SubSystem: '<S2>/Ledsoff' */
  }

  /* End of If: '<S2>/If' */

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/Constant'
   */
  if (rtDW.LEd1_state > rtP.Switch_Threshold) {
    rtDW.y_g = rtDW.AND;
  } else {
    rtDW.y_g = rtP.Constant_Value;
  }

  /* MATLABSystem: '<Root>/Digital Output' incorporates:
   *  Switch: '<S13>/Switch'
   */
  rtDW.y_g = rt_roundd_snf(rtDW.y_g);
  if (rtDW.y_g < 256.0) {
    if (rtDW.y_g >= 0.0) {
      tmp = (uint8_T)rtDW.y_g;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(8, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output' */
  if (rtM->Timing.TaskCounters.TID[2] == 0) {
    /* Logic: '<S21>/AND' incorporates:
     *  Constant: '<S21>/Constant'
     *  Logic: '<S21>/NOT'
     *  UnitDelay: '<S21>/Unit Delay'
     */
    rtDW.AND_d = ((rtP.Constant_Value_f != 0.0) && (!rtDW.UnitDelay_DSTATE_m));
  }

  /* Switch: '<S13>/Switch1' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  if (rtDW.LEd2_state > rtP.Switch1_Threshold) {
    rtDW.y_g = rtDW.AND_d;
  } else {
    rtDW.y_g = rtP.Constant1_Value;
  }

  /* MATLABSystem: '<Root>/Digital Output1' incorporates:
   *  Switch: '<S13>/Switch1'
   */
  rtDW.y_g = rt_roundd_snf(rtDW.y_g);
  if (rtDW.y_g < 256.0) {
    if (rtDW.y_g >= 0.0) {
      tmp = (uint8_T)rtDW.y_g;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(9, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output1' */
  if (rtM->Timing.TaskCounters.TID[2] == 0) {
    /* Update for UnitDelay: '<S20>/Unit Delay' */
    rtDW.UnitDelay_DSTATE_a = rtDW.AND;

    /* Update for UnitDelay: '<S21>/Unit Delay' */
    rtDW.UnitDelay_DSTATE_m = rtDW.AND_d;
  }

  rate_scheduler();
}

/* Model initialize function */
void Car_Blinkers_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtPrevZCX.First_Button_checker_Trig_ZCE = POS_ZCSIG;
  rtPrevZCX.Leds_signals_Trig_ZCE = POS_ZCSIG;

  /* InitializeConditions for UnitDelay: '<S20>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_a = rtP.UnitDelay_InitialCondition_i;

  /* InitializeConditions for S-Function (sdspcount2): '<S3>/Counter' */
  rtDW.Counter_ClkEphState = 5UL;
  rtDW.Counter_RstEphState = 5UL;
  rtDW.Counter_Count = rtP.Counter_InitialCount;

  /* InitializeConditions for S-Function (sdspcount2): '<S11>/Counter' */
  rtDW.Counter_ClkEphState_p = 5UL;
  rtDW.Counter_RstEphState_d = 5UL;
  rtDW.Counter_Count_h = rtP.Counter_InitialCount_f;

  /* InitializeConditions for S-Function (sdspcount2): '<S12>/Counter1' */
  rtDW.Counter1_ClkEphState = 5UL;
  rtDW.Counter1_RstEphState = 5UL;
  rtDW.Counter1_Count = rtP.Counter1_InitialCount;

  /* InitializeConditions for UnitDelay: '<S21>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_m = rtP.UnitDelay_InitialCondition_j;

  /* SystemInitialize for Enabled SubSystem: '<S1>/Counter_Button1' */
  Counter_Button1_Init(&rtDW.Add_p, &rtDW.Counter_Button1_d,
                       &rtP.Counter_Button1_d);

  /* End of SystemInitialize for SubSystem: '<S1>/Counter_Button1' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/Counter_Button2' */
  Counter_Button1_Init(&rtDW.Add_a, &rtDW.Counter_Button2, &rtP.Counter_Button2);

  /* End of SystemInitialize for SubSystem: '<S1>/Counter_Button2' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/Counter_Button3' */
  Counter_Button1_Init(&rtDW.Add, &rtDW.Counter_Button3, &rtP.Counter_Button3);

  /* End of SystemInitialize for SubSystem: '<S1>/Counter_Button3' */

  /* SystemInitialize for Triggered SubSystem: '<S2>/Leds_signals' */
  /* InitializeConditions for UnitDelay: '<S16>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtP.UnitDelay_InitialCondition_h;

  /* InitializeConditions for UnitDelay: '<S16>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE = rtP.UnitDelay1_InitialCondition;

  /* SystemInitialize for Merge: '<S24>/Merge' */
  rtDW.Merge = rtP.Merge_InitialOutput;

  /* SystemInitialize for Merge: '<S24>/Merge1' */
  rtDW.Merge1 = rtP.Merge1_InitialOutput;

  /* SystemInitialize for Triggered SubSystem: '<S16>/First_Button_checker' */
  /* InitializeConditions for UnitDelay: '<S22>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_e = rtP.UnitDelay_InitialCondition;

  /* SystemInitialize for Switch: '<S22>/Switch' incorporates:
   *  Outport: '<S22>/initialization_state'
   */
  rtDW.Switch = rtP.initialization_state_Y0;

  /* End of SystemInitialize for SubSystem: '<S16>/First_Button_checker' */

  /* SystemInitialize for Outport: '<S16>/Output' */
  rtDW.Activation_Signal = rtP.Output_Y0;

  /* End of SystemInitialize for SubSystem: '<S2>/Leds_signals' */

  /* SystemInitialize for Merge: '<S13>/Merge' */
  rtDW.LEd1_state = rtP.Merge_InitialOutput_o;

  /* SystemInitialize for Merge: '<S13>/Merge1' */
  rtDW.LEd2_state = rtP.Merge1_InitialOutput_m;

  /* Start for MATLABSystem: '<Root>/Digital Input' */
  rtDW.obj_pp.matlabCodegenIsDeleted = false;
  rtDW.obj_pp.SampleTime = rtP.DigitalInput_SampleTime;
  rtDW.obj_pp.isInitialized = 1L;
  digitalIOSetup(11, 0);
  rtDW.obj_pp.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Input1' */
  rtDW.obj_p.matlabCodegenIsDeleted = false;
  rtDW.obj_p.SampleTime = rtP.DigitalInput1_SampleTime;
  rtDW.obj_p.isInitialized = 1L;
  digitalIOSetup(12, 0);
  rtDW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Input2' */
  rtDW.obj.matlabCodegenIsDeleted = false;
  rtDW.obj.SampleTime = rtP.DigitalInput2_SampleTime;
  rtDW.obj.isInitialized = 1L;
  digitalIOSetup(13, 0);
  rtDW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  rtDW.obj_h.matlabCodegenIsDeleted = false;
  rtDW.obj_h.isInitialized = 1L;
  digitalIOSetup(8, 1);
  rtDW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  rtDW.obj_c.matlabCodegenIsDeleted = false;
  rtDW.obj_c.isInitialized = 1L;
  digitalIOSetup(9, 1);
  rtDW.obj_c.isSetupComplete = true;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
