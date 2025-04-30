/*
 * Copyright (C) 2025 The Nameless-CLO Project
 * SPDX-License-Identifier: Apache-2.0
 */

package vendor.sun.hardware.displayfeature;

@VintfStability
@Backing(type="int")
enum Feature {
    DC_DIMMING = 1 << 0,
    EDGE_TOUCH = 1 << 1,
    HIGH_SAMPLE_TOUCH = 1 << 2,
    HBM_MODE = 1 << 3,
    SDR2HDR = 1 << 4,
    MEMC_FHD = 1 << 5,
    MEMC_QHD = 1 << 6,
    VIDEO_OSIE = 1 << 7,
    LTPO = 1 << 8,
}
