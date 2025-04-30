/*
 * Copyright (C) 2025 The Nameless-CLO Project
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <aidl/vendor/sun/hardware/displayfeature/BnDisplayFeature.h>
#include <aidl/vendor/sun/hardware/displayfeature/Command.h>
#include <aidl/vendor/sun/hardware/displayfeature/Feature.h>

namespace aidl {
namespace vendor {
namespace sun {
namespace hardware {
namespace displayfeature {

struct DisplayFeature : public BnDisplayFeature {
public:
    ndk::ScopedAStatus hasFeature(Feature feature, bool* _aidl_return) override;
    ndk::ScopedAStatus isFeatureEnabled(Feature feature, bool* _aidl_return) override;
    ndk::ScopedAStatus setFeatureEnabled(Feature feature, bool enabled) override;
    ndk::ScopedAStatus setColorMode(int colorMode) override;
    ndk::ScopedAStatus setDisplayOrientation(int orientation) override;
    ndk::ScopedAStatus sendCommand(Command command, int* _aidl_return) override;
};

}  // namespace displayfeature
}  // namespace hardware
}  // namespace sun
}  // namespace vendor
}  // namespace aidl
