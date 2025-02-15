/*
 * Copyright (C) 2025 The Nameless-CLO Project
 * SPDX-License-Identifier: Apache-2.0
 */
///////////////////////////////////////////////////////////////////////////////
// THIS FILE IS IMMUTABLE. DO NOT EDIT IN ANY CASE.                          //
///////////////////////////////////////////////////////////////////////////////

// This file is a snapshot of an AIDL file. Do not edit it manually. There are
// two cases:
// 1). this is a frozen version file - do not edit this in any case.
// 2). this is a 'current' file. If you make a backwards compatible change to
//     the interface (from the latest frozen version), the build system will
//     prompt you to update this file with `m <name>-update-api`.
//
// You must not make a backward incompatible change to any AIDL file built
// with the aidl_interface module type with versions property set. The module
// type is used to build AIDL files in a way that they can be used across
// independently updatable components of the system. If a device is shipped
// with such a backward incompatible change, it has a high risk of breaking
// later when a module using the interface is updated, e.g., Mainline modules.

package vendor.nameless.hardware.vibratorExt;
@Backing(type="int") @VintfStability
enum Effect {
  CLICK,
  DOUBLE_CLICK,
  TICK,
  THUD,
  POP,
  HEAVY_CLICK,
  DURATION_DEFAULT = 100,
  DURATION_STRENGTH_LEVEL1,
  DURATION_STRENGTH_LEVEL2,
  DURATION_STRENGTH_LEVEL3,
  DURATION_STRENGTH_LEVEL4,
  DURATION_STRENGTH_LEVEL5,
  DURATION_STRENGTH_LEVEL6,
  DURATION_STRENGTH_LEVEL7,
  DURATION_STRENGTH_LEVEL8,
  DURATION_STRENGTH_LEVEL9,
  DURATION_STRENGTH_LEVEL10,
  DURATION_NOTIFICATION,
  DURATION_ALARM_CALL,
  RINGTONE_WALTZ = 500,
  RINGTONE_CUT,
  RINGTONE_CLOCK,
  RINGTONE_SHORT,
  RAMP_DOWN = 1000,
  CUSTOM_EFFECT_START = 2000,
  ALERT_SLIDER_BOTTOM,
  ALERT_SLIDER_MIDDLE,
  BACK_GESTURE,
  BUTTON_CLICK,
  CLEAR_ALL_NOTIFICATION,
  CLEAR_ALL_RECENT,
  EXPAND_PANEL,
  INDEXABLE_WIDGET,
  KEYBOARD_PRESS,
  LOCKSCREEN_SHORTCUT,
  OFF_SCREEN_GESTURE,
  PLUG_IN,
  QUICK_CAMERA,
  SCREEN_OFF,
  SCREEN_ON,
  SCREENSHOT,
  SLIDER_EDGE,
  SLIDER_STEP,
  SWITCH_TOGGLE,
  UNIFIED_ERROR,
  UNIFIED_SUCCESS,
  CUSTOM_EFFECT_END,
}
