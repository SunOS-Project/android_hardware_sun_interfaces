/*
 * Copyright (C) 2025 The Nameless-CLO Project
 * SPDX-License-Identifier: Apache-2.0
 */
///////////////////////////////////////////////////////////////////////////////
// THIS FILE IS IMMUTABLE. DO NOT EDIT IN ANY CASE.                          //
///////////////////////////////////////////////////////////////////////////////

// This file is a snapshot of an AIDL file. Do not edit it manually. There are
// two cases:
// 1). this is a frozen version file - do not edit this in any case.
// 2). this is a 'current' file. If you make a backwards compatible change to
//     the interface (from the latest frozen version), the build system will
//     prompt you to update this file with `m <name>-update-api`.
//
// You must not make a backward incompatible change to any AIDL file built
// with the aidl_interface module type with versions property set. The module
// type is used to build AIDL files in a way that they can be used across
// independently updatable components of the system. If a device is shipped
// with such a backward incompatible change, it has a high risk of breaking
// later when a module using the interface is updated, e.g., Mainline modules.

package vendor.sun.hardware.displayfeature;
@Backing(type="int") @VintfStability
enum Feature {
  DC_DIMMING = (1 << 0) /* 1 */,
  EDGE_TOUCH = (1 << 1) /* 2 */,
  HIGH_SAMPLE_TOUCH = (1 << 2) /* 4 */,
  HBM_MODE = (1 << 3) /* 8 */,
  SDR2HDR = (1 << 4) /* 16 */,
  MEMC_FHD = (1 << 5) /* 32 */,
  MEMC_QHD = (1 << 6) /* 64 */,
  VIDEO_OSIE = (1 << 7) /* 128 */,
  LTPO = (1 << 8) /* 256 */,
}
