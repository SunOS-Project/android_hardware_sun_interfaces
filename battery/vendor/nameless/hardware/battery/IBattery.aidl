/*
 * Copyright (C) 2025 The Nameless-CLO Project
 * SPDX-License-Identifier: Apache-2.0
 */

package vendor.nameless.hardware.battery;

import vendor.nameless.hardware.battery.ChargingStatus;
import vendor.nameless.hardware.battery.Feature;

@VintfStability
interface IBattery {
    boolean hasFeature(in Feature feature);
    boolean isFeatureEnabled(in Feature feature);
    void setFeatureEnabled(in Feature feature, in boolean enabled);
    ChargingStatus readChargingStatus();
}
