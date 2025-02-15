/*
 * Copyright (C) 2025 The Nameless-CLO Project
 * SPDX-License-Identifier: Apache-2.0
 */

package vendor.nameless.hardware.vibratorExt;

import vendor.nameless.hardware.vibratorExt.Effect;
import vendor.nameless.hardware.vibratorExt.LevelRange;
import vendor.nameless.hardware.vibratorExt.Style;
import vendor.nameless.hardware.vibratorExt.Type;

@VintfStability
interface IVibratorExt {
    void initVibrator();
    long vibratorOn(in Effect effectId, in long duration);
    void vibratorOff();
    void setAmplitude(in float amplitude);
    void setHapticStyle(in Style style);
    LevelRange getStrengthLevelRange(in Type type);
    void setStrengthLevel(in Type type, in int level);
    boolean isEffectSupported(in Effect effectId);
    boolean isHapticStyleSupported(in Style style);
}
