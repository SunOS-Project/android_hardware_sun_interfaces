/*
 * Copyright (C) 2025 The Nameless-CLO Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include "include/VibratorExt.h"

#include <log/log.h>

#undef LOG_TAG
#define LOG_TAG "vendor.nameless.hardware.vibratorExt-service"

namespace aidl {
namespace vendor {
namespace nameless {
namespace hardware {
namespace vibratorExt {

static const LevelRange kUnknownLevelRange = {
    .maxLevel = 0,
    .defaultLevel = 0
};

ndk::ScopedAStatus VibratorExt::initVibrator() {
    // Implement this
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus VibratorExt::vibratorOn(Effect effectId, long duration, long* _aidl_return) {
    // Implement this
    *_aidl_return = duration;
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus VibratorExt::vibratorOff() {
    // Implement this
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus VibratorExt::setAmplitude(float amplitude) {
    if (amplitude <= 0.0 || amplitude > 1.0) {
        ALOGE("setAmplitude, invalid amplitude %f", amplitude);
        return ndk::ScopedAStatus::fromExceptionCode(EX_ILLEGAL_ARGUMENT);
    }
    // Implement this
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus VibratorExt::setHapticStyle(Style style) {
    // Implement this
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus VibratorExt::getStrengthLevelRange(Type type, LevelRange* _aidl_return) {
    // Implement this
    *_aidl_return = kUnknownLevelRange;
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus VibratorExt::setStrengthLevel(Type type, int level) {
    if (level < 0) {
        ALOGE("setStrengthLevel, invalid level %d", level);
        return ndk::ScopedAStatus::fromExceptionCode(EX_ILLEGAL_ARGUMENT);
    }
    // Implement this
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus VibratorExt::isEffectSupported(Effect effectId, bool* _aidl_return) {
    // Implement this
    *_aidl_return = false;
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus VibratorExt::isHapticStyleSupported(Style style, bool* _aidl_return) {
    // Implement this
    *_aidl_return = false;
    return ndk::ScopedAStatus::ok();
}

}  // namespace vibratorExt
}  // namespace hardware
}  // namespace nameless
}  // namespace vendor
}  // namespace aidl
