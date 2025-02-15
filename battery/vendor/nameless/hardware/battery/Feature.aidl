/*
 * Copyright (C) 2025 The Nameless-CLO Project
 * SPDX-License-Identifier: Apache-2.0
 */

package vendor.nameless.hardware.battery;

@VintfStability
@Backing(type="int")
enum Feature {
    SUSPEND_CHARGING = 1 << 0,
    WIRELESS_CHARGING_QUIET_MODE = 1 << 1,
    WIRELESS_CHARGING_RX = 1 << 2,
    WIRELESS_CHARGING_TX = 1 << 3,
}
