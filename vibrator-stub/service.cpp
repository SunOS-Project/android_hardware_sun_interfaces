/*
 * Copyright (c) 2020, The Linux Foundation. All rights reserved.
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

#define LOG_TAG "android.hardware.vibrator-stub"

#include <android-base/logging.h>
#include <android-base/properties.h>
#include <android/binder_manager.h>
#include <android/binder_process.h>
#include <stdlib.h>
#include <thread>

#include "Vibrator.h"
#include "richtap/RichtapVibrator.h"

using aidl::android::hardware::vibrator::Vibrator;
using aidl::vendor::aac::hardware::richtap::vibrator::RichtapVibrator;

using std::literals::chrono_literals::operator""s;

using ::android::base::GetProperty;
using ::android::base::WaitForProperty;

constexpr char kHapticCalibrateProp[] = "vendor.haptic.calibrate.done";
constexpr char kVibratorReady[] = "sys.nameless.feature.vibrator.ready";
constexpr char kSupportRichtapProp[] = "sys.nameless.feature.vibrator.richtap";
constexpr char kRichtapDevProp[] = "sys.nameless.feature.vibrator.richtap_dev";
constexpr char kRichtapConfigProp[] = "sys.nameless.feature.vibrator.richtap_config";

int main() {
    if (!WaitForProperty(kVibratorReady, "1", 500s)) {
        return EXIT_FAILURE;
    }

    ABinderProcess_setThreadPoolMaxThreadCount(0);
    std::shared_ptr<Vibrator> vib = ndk::SharedRefBase::make<Vibrator>();

    const std::string supportRichtap = GetProperty(kSupportRichtapProp, "false");
    if (supportRichtap == "1" || supportRichtap == "true") {
        ndk::SpAIBinder vibBinder = vib->asBinder();

        // making the extension service
        std::shared_ptr<RichtapVibrator> cvib = ndk::SharedRefBase::make<RichtapVibrator>();

        // need to attach the extension to the same binder we will be registering
        CHECK(STATUS_OK == AIBinder_setExtension(vibBinder.get(), cvib->asBinder().get()));

        const std::string richtapDev = GetProperty(kRichtapDevProp, "");
        const std::string richtapConfig = GetProperty(kRichtapConfigProp, "");
        setenv("RICHTAP_DEVICE_PATH", richtapDev.c_str(), 1);
        setenv("ENV_RICHTAP_CONFIG_PATH", richtapConfig.c_str(), 1);

        const std::string instance = std::string() + Vibrator::descriptor + "/default";
        binder_status_t status = AServiceManager_addService(vib->asBinder().get(), instance.c_str());
        CHECK(status == STATUS_OK);

        std::thread initThread([&]() {
            WaitForProperty(kHapticCalibrateProp, "1", 500s);
            cvib->init(nullptr);
        });
        initThread.detach();
    } else {
        const std::string instance = std::string() + Vibrator::descriptor + "/default";
        binder_status_t status = AServiceManager_addService(vib->asBinder().get(), instance.c_str());
        CHECK(status == STATUS_OK);
    }

    ABinderProcess_joinThreadPool();
    return EXIT_FAILURE;  // should not reach
}
