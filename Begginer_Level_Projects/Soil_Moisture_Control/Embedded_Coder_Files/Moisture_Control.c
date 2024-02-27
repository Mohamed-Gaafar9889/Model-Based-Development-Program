/*
 * File: Moisture_Control.c
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

#include "Moisture_Control.h"
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include <stddef.h>
#include <math.h>
#include <float.h>
#include "solver_zc.h"
#define NumBitsPerChar                 8U
#ifndef slZcHadEvent
#define slZcHadEvent(ev, zcsDir)       (((ev) & (zcsDir)) != 0x00 )
#endif

#ifndef slZcUnAliasEvents
#define slZcUnAliasEvents(evL, evR)    ((((slZcHadEvent((evL), (SL_ZCS_EVENT_N2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2P))) || (slZcHadEvent((evL), (SL_ZCS_EVENT_P2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2N)))) ? (SL_ZCS_EVENT_NUL) : (evR)))
#endif

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

/* Used by FromWorkspace Block: '<Root>/From Workspace' */
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? floor((v) + 0.5) : ceil((v) - 0.5) )
#endif

/* Block signals and states (default storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real_T rt_remd_snf(real_T u0, real_T u1);
static real_T look1_binlx(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);
static ZCEventType rt_ZCFcn(ZCDirection zcDir, ZCSigState *prevZc, real_T
  currValue);

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

/* Detect zero crossings events. */
static ZCEventType rt_ZCFcn(ZCDirection zcDir, ZCSigState *prevZc, real_T
  currValue)
{
  slZcEventType zcsDir;
  slZcEventType tempEv;
  ZCEventType zcEvent = NO_ZCEVENT;    /* assume */

  /* zcEvent matrix */
  static const slZcEventType eventMatrix[4][4] = {
    /*          ZER              POS              NEG              UNK */
    { SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_Z2P, SL_ZCS_EVENT_Z2N, SL_ZCS_EVENT_NUL },/* ZER */

    { SL_ZCS_EVENT_P2Z, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_P2N, SL_ZCS_EVENT_NUL },/* POS */

    { SL_ZCS_EVENT_N2Z, SL_ZCS_EVENT_N2P, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL },/* NEG */

    { SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL }/* UNK */
  };

  /* get prevZcEvent and prevZcSign from prevZc */
  const slZcEventType prevEv = (slZcEventType)(((uint8_T)(*prevZc)) >> 2);
  const slZcSignalSignType prevSign = (slZcSignalSignType)(((uint8_T)(*prevZc))
    & (uint8_T)0x03);

  /* get current zcSignal sign from current zcSignal value */
  const slZcSignalSignType currSign = (slZcSignalSignType)((currValue) > 0.0 ?
    SL_ZCS_SIGN_POS :
    ((currValue) < 0.0 ? SL_ZCS_SIGN_NEG : SL_ZCS_SIGN_ZERO));

  /* get current zcEvent based on prev and current zcSignal value */
  slZcEventType currEv = eventMatrix[prevSign][currSign];

  /* get slZcEventType from ZCDirection */
  switch (zcDir) {
   case ANY_ZERO_CROSSING:
    zcsDir = SL_ZCS_EVENT_ALL;
    break;

   case FALLING_ZERO_CROSSING:
    zcsDir = SL_ZCS_EVENT_ALL_DN;
    break;

   case RISING_ZERO_CROSSING:
    zcsDir = SL_ZCS_EVENT_ALL_UP;
    break;

   default:
    zcsDir = SL_ZCS_EVENT_NUL;
    break;
  }

  /* had event, check if zc happened */
  if (slZcHadEvent(currEv, zcsDir)) {
    currEv = (slZcEventType)(slZcUnAliasEvents(prevEv, currEv));
  } else {
    currEv = SL_ZCS_EVENT_NUL;
  }

  /* Update prevZc */
  tempEv = (slZcEventType)(currEv << 2);/* shift left by 2 bits */
  *prevZc = (ZCSigState)((currSign) | (tempEv));
  if ((currEv & SL_ZCS_EVENT_ALL_DN) != 0) {
    zcEvent = FALLING_ZCEVENT;
  } else if ((currEv & SL_ZCS_EVENT_ALL_UP) != 0) {
    zcEvent = RISING_ZCEVENT;
  } else {
    zcEvent = NO_ZCEVENT;
  }

  return zcEvent;
}                                      /* rt_ZCFcn */

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

static real_T look1_binlx(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else if ((u1 != 0.0) && (u1 != trunc(u1))) {
    real_T q;
    q = fabs(u0 / u1);
    if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q)) {
      y = 0.0 * u0;
    } else {
      y = fmod(u0, u1);
    }
  } else {
    y = fmod(u0, u1);
  }

  return y;
}

/* Model step function */
void Moisture_Control_step(void)
{
  /* local block i/o variables */
  real_T rtb_Moisture_Measurement;
  ZCEventType zcEvent;

  /* FromWorkspace: '<Root>/From Workspace' */
  {
    real_T *pDataValues = (real_T *) rtDW.FromWorkspace_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) rtDW.FromWorkspace_PWORK.TimePtr;
    int_T currTimeIndex = rtDW.FromWorkspace_IWORK.PrevIndex;
    real_T t = rtM->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[30]) {
      currTimeIndex = 29;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    rtDW.FromWorkspace_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_Moisture_Measurement = pDataValues[currTimeIndex];
        } else {
          rtb_Moisture_Measurement = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex = currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_Moisture_Measurement = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 31;
      }
    }
  }

  /* Outputs for Enabled and Triggered SubSystem: '<Root>/Ckecking_Indicator' incorporates:
   *  EnablePort: '<S2>/Enable'
   *  TriggerPort: '<S2>/Trigger'
   */
  /* MATLAB Function: '<Root>/MATLAB Function' */
  zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,
                     &rtPrevZCX.Ckecking_Indicator_Trig_ZCE,
                     ((real_T)((rtb_Moisture_Measurement < 0.3) ||
    (rtb_Moisture_Measurement >= 0.6))));
  if (!rtDW.Ckecking_Indicator_MODE) {
    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
    rtDW.UnitDelay_DSTATE = 0.0;
    rtDW.Ckecking_Indicator_MODE = true;
  }

  if (zcEvent != NO_ZCEVENT) {
    /* Sum: '<S2>/Add' incorporates:
     *  Constant: '<S2>/Constant'
     *  UnitDelay: '<S2>/Unit Delay'
     */
    rtDW.Add = rtDW.UnitDelay_DSTATE + 1.0;

    /* Update for UnitDelay: '<S2>/Unit Delay' */
    rtDW.UnitDelay_DSTATE = rtDW.Add;
  }

  /* End of Outputs for SubSystem: '<Root>/Ckecking_Indicator' */

  /* If: '<Root>/Moisture_Checking' */
  if (rtb_Moisture_Measurement < 0.3) {
    /* Outputs for IfAction SubSystem: '<Root>/Activator' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* Merge: '<Root>/Merge' incorporates:
     *  Constant: '<S1>/Constant'
     *  SignalConversion generated from: '<S1>/activate'
     */
    rtDW.MoistureDifference_State = 1.0;

    /* End of Outputs for SubSystem: '<Root>/Activator' */
  } else if (rtb_Moisture_Measurement >= 0.6) {
    /* Outputs for IfAction SubSystem: '<Root>/DeActivator' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Merge: '<Root>/Merge' incorporates:
     *  Constant: '<S3>/Constant'
     *  SignalConversion generated from: '<S3>/deactivate'
     */
    rtDW.MoistureDifference_State = 0.0;

    /* End of Outputs for SubSystem: '<Root>/DeActivator' */
  } else if ((rtb_Moisture_Measurement < 0.6) && (rtb_Moisture_Measurement > 0.3))
  {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* MATLAB Function: '<S4>/MATLAB Function' */
    if (rtDW.Add == 0.0) {
      /* Merge: '<Root>/Merge' incorporates:
       *  SignalConversion generated from: '<S4>/y'
       */
      rtDW.MoistureDifference_State = 0.0;
    } else {
      /* Merge: '<Root>/Merge' incorporates:
       *  SignalConversion generated from: '<S4>/y'
       */
      rtDW.MoistureDifference_State = !(rt_remd_snf(rtDW.Add, 2.0) == 0.0);
    }

    /* End of MATLAB Function: '<S4>/MATLAB Function' */
    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */
  }

  /* End of If: '<Root>/Moisture_Checking' */

  /* If: '<Root>/If' */
  if (rtDW.MoistureDifference_State > 0.0) {
    /* Outputs for IfAction SubSystem: '<Root>/Irrigation_Time_Calculator' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* If: '<S6>/If' incorporates:
     *  Constant: '<S6>/Upper_Limit'
     *  Sum: '<S6>/Subtract'
     */
    if ((0.6 - rtb_Moisture_Measurement > 0.0) && (0.6 -
         rtb_Moisture_Measurement <= 0.6)) {
      /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem' incorporates:
       *  ActionPort: '<S10>/Action Port'
       */
      /* Outport: '<Root>/Epected_Irrigation_Time' incorporates:
       *  Lookup_n-D: '<S10>/2-D Lookup Table1'
       *  Merge: '<Root>/Merge1'
       */
      rtY.Epected_Irrigation_Time = look1_binlx(0.6 - rtb_Moisture_Measurement,
        rtConstP.uDLookupTable1_bp01Data, rtConstP.uDLookupTable1_tableData, 6U);

      /* End of Outputs for SubSystem: '<S6>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S11>/Action Port'
       */
      /* Outport: '<Root>/Epected_Irrigation_Time' incorporates:
       *  Constant: '<S11>/Constant'
       *  Merge: '<Root>/Merge1'
       *  SignalConversion generated from: '<S11>/Irrigation_Time1'
       */
      rtY.Epected_Irrigation_Time = 0.0;

      /* End of Outputs for SubSystem: '<S6>/If Action Subsystem1' */
    }

    /* End of If: '<S6>/If' */
    /* End of Outputs for SubSystem: '<Root>/Irrigation_Time_Calculator' */
  } else {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Outport: '<Root>/Epected_Irrigation_Time' incorporates:
     *  Merge: '<Root>/Merge1'
     *  SignalConversion generated from: '<S5>/Out1'
     */
    rtY.Epected_Irrigation_Time = 0.0;

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem2' */
  }

  /* End of If: '<Root>/If' */

  /* Outport: '<Root>/Pump_State' incorporates:
   *  Switch: '<S8>/Switch'
   */
  rtY.Pump_State = (rtDW.MoistureDifference_State > 0.0);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  rtM->Timing.t[0] =
    ((time_T)(++rtM->Timing.clockTick0)) * rtM->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    rtM->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Moisture_Control_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&rtM->solverInfo, &rtM->Timing.simTimeStep);
    rtsiSetTPtr(&rtM->solverInfo, &rtmGetTPtr(rtM));
    rtsiSetStepSizePtr(&rtM->solverInfo, &rtM->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&rtM->solverInfo, (&rtmGetErrorStatus(rtM)));
    rtsiSetRTModelPtr(&rtM->solverInfo, rtM);
  }

  rtsiSetSimTimeStep(&rtM->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&rtM->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(rtM, &rtM->Timing.tArray[0]);
  rtM->Timing.stepSize0 = 0.001;

  /* Start for FromWorkspace: '<Root>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0,
      9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0, 20.0,
      21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.042857142857142858,
      0.085714285714285715, 0.12857142857142856, 0.17142857142857143,
      0.21428571428571427, 0.25714285714285712, 0.3, 0.34285714285714286,
      0.38571428571428568, 0.42857142857142855, 0.47142857142857142,
      0.51428571428571423, 0.55714285714285716, 0.6, 0.6, 0.55999999999999994,
      0.52, 0.48, 0.43999999999999995, 0.39999999999999997, 0.36,
      0.31999999999999995, 0.27999999999999997, 0.24, 0.19999999999999996,
      0.15999999999999998, 0.12000000000000005, 0.07999999999999996,
      0.039999999999999925, 0.0 } ;

    rtDW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    rtDW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    rtDW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  rtPrevZCX.Ckecking_Indicator_Trig_ZCE = UNINITIALIZED_ZCSIG;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
