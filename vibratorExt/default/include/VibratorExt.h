/*
 * Copyright (C) 2025 The Nameless-CLO Project
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <aidl/vendor/sun/hardware/vibratorExt/BnVibratorExt.h>
#include <aidl/vendor/sun/hardware/vibratorExt/Effect.h>
#include <aidl/vendor/sun/hardware/vibratorExt/LevelRange.h>
#include <aidl/vendor/sun/hardware/vibratorExt/Style.h>
#include <aidl/vendor/sun/hardware/vibratorExt/Type.h>

namespace aidl {
namespace vendor {
namespace sun {
namespace hardware {
namespace vibratorExt {

struct VibratorExt : public BnVibratorExt {
public:
    ndk::ScopedAStatus initVibrator() override;
    ndk::ScopedAStatus vibratorOn(Effect effectId, long duration, long* _aidl_return) override;
    ndk::ScopedAStatus vibratorOff() override;
    ndk::ScopedAStatus setAmplitude(float amplitude) override;
    ndk::ScopedAStatus setHapticStyle(Style style) override;
    ndk::ScopedAStatus getStrengthLevelRange(Type type, LevelRange* _aidl_return) override;
    ndk::ScopedAStatus setStrengthLevel(Type type, int level) override;
    ndk::ScopedAStatus isEffectSupported(Effect effectId, bool* _aidl_return) override;
    ndk::ScopedAStatus isHapticStyleSupported(Style style, bool* _aidl_return) override;
};

}  // namespace vibratorExt
}  // namespace hardware
}  // namespace sun
}  // namespace vendor
}  // namespace aidl
