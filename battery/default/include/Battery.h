/*
 * Copyright (C) 2025 The Nameless-CLO Project
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <aidl/vendor/sun/hardware/battery/BnBattery.h>
#include <aidl/vendor/sun/hardware/battery/ChargingStatus.h>
#include <aidl/vendor/sun/hardware/battery/Feature.h>

namespace aidl {
namespace vendor {
namespace sun {
namespace hardware {
namespace battery {

struct Battery : public BnBattery {
public:
    ndk::ScopedAStatus hasFeature(Feature feature, bool* _aidl_return) override;
    ndk::ScopedAStatus isFeatureEnabled(Feature feature, bool* _aidl_return) override;
    ndk::ScopedAStatus setFeatureEnabled(Feature feature, bool enabled) override;
    ndk::ScopedAStatus readChargingStatus(ChargingStatus* _aidl_return) override;
};

}  // namespace battery
}  // namespace hardware
}  // namespace sun
}  // namespace vendor
}  // namespace aidl
