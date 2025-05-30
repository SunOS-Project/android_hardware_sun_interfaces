/*
 * Copyright (c) 2018,2020, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <aidl/android/hardware/vibrator/BnVibrator.h>

namespace aidl {
namespace android {
namespace hardware {
namespace vibrator {

class Vibrator : public BnVibrator {
private:
    bool mSupportExternalControl = false;
public:
    Vibrator();
    ndk::ScopedAStatus getCapabilities(int32_t* _aidl_return) override;
    ndk::ScopedAStatus off() override;
    ndk::ScopedAStatus on(int32_t timeoutMs,
            const std::shared_ptr<IVibratorCallback>& callback) override;
    ndk::ScopedAStatus perform(Effect effect, EffectStrength strength,
            const std::shared_ptr<IVibratorCallback>& callback,
            int32_t* _aidl_return) override;
    ndk::ScopedAStatus getSupportedEffects(std::vector<Effect>* _aidl_return) override;
    ndk::ScopedAStatus setAmplitude(float amplitude) override;
    ndk::ScopedAStatus setExternalControl(bool enabled) override;
    ndk::ScopedAStatus getCompositionDelayMax(int32_t* maxDelayMs);
    ndk::ScopedAStatus getCompositionSizeMax(int32_t* maxSize);
    ndk::ScopedAStatus getSupportedPrimitives(std::vector<CompositePrimitive>* supported) override;
    ndk::ScopedAStatus getPrimitiveDuration(CompositePrimitive primitive,
                                            int32_t* durationMs) override;
    ndk::ScopedAStatus compose(const std::vector<CompositeEffect>& composite,
                               const std::shared_ptr<IVibratorCallback>& callback) override;
    ndk::ScopedAStatus getSupportedAlwaysOnEffects(std::vector<Effect>* _aidl_return) override;
    ndk::ScopedAStatus alwaysOnEnable(int32_t id, Effect effect, EffectStrength strength) override;
    ndk::ScopedAStatus alwaysOnDisable(int32_t id) override;
    ndk::ScopedAStatus getResonantFrequency(float* _aidl_return) override;
    ndk::ScopedAStatus getQFactor(float* _aidl_return) override;
    ndk::ScopedAStatus getFrequencyResolution(float* _aidl_return) override;
    ndk::ScopedAStatus getFrequencyMinimum(float* _aidl_return) override;
    ndk::ScopedAStatus getBandwidthAmplitudeMap(std::vector<float>* _aidl_return) override;
    ndk::ScopedAStatus getPwlePrimitiveDurationMax(int32_t* _aidl_return) override;
    ndk::ScopedAStatus getPwleCompositionSizeMax(int32_t* _aidl_return) override;
    ndk::ScopedAStatus getSupportedBraking(std::vector<::aidl::android::hardware::vibrator::Braking>* _aidl_return) override;
    ndk::ScopedAStatus composePwle(const std::vector<::aidl::android::hardware::vibrator::PrimitivePwle>& in_composite, const std::shared_ptr<::aidl::android::hardware::vibrator::IVibratorCallback>& in_callback) override;
};

}  // namespace vibrator
}  // namespace hardware
}  // namespace android
}  // namespace aidl
