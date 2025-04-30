/*
 * Copyright (C) 2025 The Nameless-CLO Project
 * SPDX-License-Identifier: Apache-2.0
 */

package vendor.sun.hardware.battery;

@VintfStability
@Backing(type="int")
enum ChargingStatus {
    UNKNOWN = -1,
    FAST_CHARGING = 2,
    DASH_CHARGING = 101,
    WARP_CHARGING = 102,
    VOOC_CHARGING = 103,
    TURBO_CHARGING = 104,
}
