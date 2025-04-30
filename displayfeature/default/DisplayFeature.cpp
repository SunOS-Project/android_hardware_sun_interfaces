/*
 * Copyright (C) 2025 The Nameless-CLO Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include "include/DisplayFeature.h"

#include <log/log.h>

#undef LOG_TAG
#define LOG_TAG "vendor.sun.hardware.displayfeature-service"

namespace aidl {
namespace vendor {
namespace sun {
namespace hardware {
namespace displayfeature {

ndk::ScopedAStatus DisplayFeature::hasFeature(Feature feature, bool* _aidl_return) {
    // Implement this
    *_aidl_return = false;
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus DisplayFeature::isFeatureEnabled(Feature feature, bool* _aidl_return) {
    hasFeature(feature, _aidl_return);
    if (!*_aidl_return) {
        *_aidl_return = false;
        ALOGE("isFeatureEnabled, feature %d is not supported", static_cast<int>(feature));
        return ndk::ScopedAStatus::fromExceptionCode(EX_UNSUPPORTED_OPERATION);
    }
    // Implement this
    *_aidl_return = false;
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus DisplayFeature::setFeatureEnabled(Feature feature, bool enabled) {
    bool featureSupported = false;
    hasFeature(feature, &featureSupported);
    if (!featureSupported) {
        ALOGE("setFeatureEnabled, feature %d is not supported", static_cast<int>(feature));
        return ndk::ScopedAStatus::fromExceptionCode(EX_UNSUPPORTED_OPERATION);
    }
    // Implement this
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus DisplayFeature::setColorMode(int colorMode) {
    if (colorMode < 0) {
        ALOGE("setColorMode, invalid colorMode %d", colorMode);
        return ndk::ScopedAStatus::fromExceptionCode(EX_ILLEGAL_ARGUMENT);
    }
    // Implement this
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus DisplayFeature::setDisplayOrientation(int orientation) {
    if (orientation < 0) {
        ALOGE("setDisplayOrientation, invalid orientation %d", orientation);
        return ndk::ScopedAStatus::fromExceptionCode(EX_ILLEGAL_ARGUMENT);
    }
    // Implement this
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus DisplayFeature::sendCommand(Command command, int* _aidl_return) {
    // Implement this
    *_aidl_return = -1;
    return ndk::ScopedAStatus::ok();
}

}  // namespace displayfeature
}  // namespace hardware
}  // namespace sun
}  // namespace vendor
}  // namespace aidl
