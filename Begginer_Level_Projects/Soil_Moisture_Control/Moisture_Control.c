/*
 * File: Moisture_Control.c
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

#include "Moisture_Control.h"
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "solver_zc.h"
#ifndef slZcHadEvent
#define slZcHadEvent(ev, zcsDir)       (((ev) & (zcsDir)) != 0x00 )
#endif

#ifndef slZcUnAliasEvents
#define slZcUnAliasEvents(evL, evR)    ((((slZcHadEvent((evL), (SL_ZCS_EVENT_N2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2P))) || (slZcHadEvent((evL), (SL_ZCS_EVENT_P2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2N)))) ? (SL_ZCS_EVENT_NUL) : (evR)))
#endif

/* Block signals and states (default storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;
static real_T look1_binlx(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
static ZCEventType rt_ZCFcn(ZCDirection zcDir, ZCSigState *prevZc, real_T
  currValue);

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

/* Model step function for TID0 */
void Moisture_Control_step0(void)      /* Sample time: [0.001s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID1 */
void Moisture_Control_step1(void)      /* Sample time: [1.0s, 0.0s] */
{
  ZCEventType zcEvent;

  /* If: '<Root>/Moisture_Checking' incorporates:
   *  Inport: '<Root>/Moisture_Sensor'
   */
  if (rtU.Moisture_Sensor < 0.3) {
    /* Outputs for IfAction SubSystem: '<Root>/Activator' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* Merge: '<Root>/Merge' incorporates:
     *  Constant: '<S1>/Constant'
     *  SignalConversion generated from: '<S1>/activate'
     */
    rtDW.MoistureDifference_State = 1.0;

    /* End of Outputs for SubSystem: '<Root>/Activator' */
  } else if (rtU.Moisture_Sensor >= 0.6) {
    /* Outputs for IfAction SubSystem: '<Root>/DeActivator' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Merge: '<Root>/Merge' incorporates:
     *  Constant: '<S3>/Constant'
     *  SignalConversion generated from: '<S3>/deactivate'
     */
    rtDW.MoistureDifference_State = 0.0;

    /* End of Outputs for SubSystem: '<Root>/DeActivator' */
  }

  /* End of If: '<Root>/Moisture_Checking' */

  /* Outputs for Triggered SubSystem: '<Root>/System_Activation' incorporates:
   *  TriggerPort: '<S5>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&rtPrevZCX.System_Activation_Trig_ZCE,
                     (rtDW.MoistureDifference_State));
  if (zcEvent != NO_ZCEVENT) {
    /* SignalConversion generated from: '<S5>/Irrigation_System_On' */
    rtDW.OutportBufferForIrrigation_Syst = 1.0;
  }

  /* End of Outputs for SubSystem: '<Root>/System_Activation' */

  /* Outputs for Enabled SubSystem: '<Root>/Irrigation_Time_Calculator' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  if (rtDW.OutportBufferForIrrigation_Syst > 0.0) {
    /* If: '<S4>/If' incorporates:
     *  Constant: '<S4>/Upper_Limit'
     *  Inport: '<Root>/Moisture_Sensor'
     *  Sum: '<S4>/Subtract'
     */
    if ((0.6 - rtU.Moisture_Sensor > 0.0) && (0.6 - rtU.Moisture_Sensor <= 0.6))
    {
      /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem' incorporates:
       *  ActionPort: '<S6>/Action Port'
       */
      /* Merge: '<S4>/Merge' incorporates:
       *  Gain: '<S6>/Gain1'
       *  Lookup_n-D: '<S6>/2-D Lookup Table1'
       */
      rtDW.Merge = look1_binlx(0.6 - rtU.Moisture_Sensor,
        rtConstP.uDLookupTable1_bp01Data, rtConstP.uDLookupTable1_tableData, 6U)
        * 60.0;

      /* End of Outputs for SubSystem: '<S4>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S7>/Action Port'
       */
      /* Merge: '<S4>/Merge' incorporates:
       *  Constant: '<S7>/Constant'
       *  SignalConversion generated from: '<S7>/Irrigation_Time1'
       */
      rtDW.Merge = 0.0;

      /* End of Outputs for SubSystem: '<S4>/If Action Subsystem1' */
    }

    /* End of If: '<S4>/If' */
  }

  /* End of Outputs for SubSystem: '<Root>/Irrigation_Time_Calculator' */

  /* Outputs for Enabled SubSystem: '<Root>/Counter ' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (rtDW.MoistureDifference_State > 0.0) {
    if (!rtDW.Counter_MODE) {
      /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
      rtDW.UnitDelay_DSTATE = 0.0;
      rtDW.Counter_MODE = true;
    }

    /* Sum: '<S2>/Add' incorporates:
     *  Constant: '<S2>/Constant'
     *  UnitDelay: '<S2>/Unit Delay'
     */
    rtDW.Add = rtDW.UnitDelay_DSTATE + 1.0;

    /* Update for UnitDelay: '<S2>/Unit Delay' */
    rtDW.UnitDelay_DSTATE = rtDW.Add;
  } else {
    rtDW.Counter_MODE = false;
  }

  /* End of Outputs for SubSystem: '<Root>/Counter ' */

  /* Outport: '<Root>/Pump_State' incorporates:
   *  Sum: '<Root>/Subtract'
   *  Switch: '<Root>/Operating_Time'
   */
  rtY.Pump_State = (rtDW.Merge - rtDW.Add > 0.0);
}

/* Model initialize function */
void Moisture_Control_initialize(void)
{
  rtPrevZCX.System_Activation_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* SystemInitialize for Triggered SubSystem: '<Root>/System_Activation' */
  /* SystemInitialize for SignalConversion generated from: '<S5>/Irrigation_System_On' */
  rtDW.OutportBufferForIrrigation_Syst = 1.0;

  /* End of SystemInitialize for SubSystem: '<Root>/System_Activation' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
