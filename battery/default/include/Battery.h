/*
 * Copyright (C) 2025 The Nameless-CLO Project
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <aidl/vendor/nameless/hardware/battery/BnBattery.h>
#include <aidl/vendor/nameless/hardware/battery/ChargingStatus.h>
#include <aidl/vendor/nameless/hardware/battery/Feature.h>

namespace aidl {
namespace vendor {
namespace nameless {
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
}  // namespace nameless
}  // namespace vendor
}  // namespace aidl
