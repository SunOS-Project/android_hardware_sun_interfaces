/*
 * Copyright (C) 2025 The Nameless-CLO Project
 * SPDX-License-Identifier: Apache-2.0
 */

package vendor.nameless.hardware.displayfeature;

import vendor.nameless.hardware.displayfeature.Command;
import vendor.nameless.hardware.displayfeature.Feature;

@VintfStability
interface IDisplayFeature {
    boolean hasFeature(in Feature feature);
    boolean isFeatureEnabled(in Feature feature);
    void setFeatureEnabled(in Feature feature, in boolean enabled);
    void setColorMode(in int colorMode);
    void setDisplayOrientation(in int orientation);
    int sendCommand(in Command command);
}
