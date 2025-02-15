/*
 * Copyright (C) 2025 The Nameless-CLO Project
 * SPDX-License-Identifier: Apache-2.0
 */

#include "include/Battery.h"

#include <log/log.h>

#undef LOG_TAG
#define LOG_TAG "vendor.nameless.hardware.battery-service"

namespace aidl {
namespace vendor {
namespace nameless {
namespace hardware {
namespace battery {

ndk::ScopedAStatus Battery::hasFeature(Feature feature, bool* _aidl_return) {
    // Implement this
    *_aidl_return = false;
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus Battery::isFeatureEnabled(Feature feature, bool* _aidl_return) {
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

ndk::ScopedAStatus Battery::setFeatureEnabled(Feature feature, bool enabled) {
    bool featureSupported = false;
    hasFeature(feature, &featureSupported);
    if (!featureSupported) {
        ALOGE("setFeatureEnabled, feature %d is not supported", static_cast<int>(feature));
        return ndk::ScopedAStatus::fromExceptionCode(EX_UNSUPPORTED_OPERATION);
    }
    // Implement this
    return ndk::ScopedAStatus::ok();
}

ndk::ScopedAStatus Battery::readChargingStatus(ChargingStatus* _aidl_return) {
    // Implement this
    *_aidl_return = ChargingStatus::UNKNOWN;
    return ndk::ScopedAStatus::ok();
}

}  // namespace battery
}  // namespace hardware
}  // namespace nameless
}  // namespace vendor
}  // namespace aidl
