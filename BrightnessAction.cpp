#include "BrightnessAction.h"

#include "StreamDockCPPSDK/StreamDockSDK/NlohmannJSONUtils.h"
#include "StreamDockCPPSDK/StreamDockSDK/HSDLogger.h"

void BrightnessAction::DidReceiveSettings(const nlohmann::json& payload) {
    HSDLogger::LogMessage("DidReceiveSettings");
}

void BrightnessAction::KeyDown(const nlohmann::json& payload) {
    HSDLogger::LogMessage("KeyDown");
    if (NlohmannJSONUtils::GetIntByName(payload, "state") == 0) {
        SetState(1);
    }
    else {
        SetState(0);
    }
}

void BrightnessAction::KeyUp(const nlohmann::json& payload) {
    // Log in release and debug builds
    HSDLogger::LogMessage("KeyUp");
    ShowOK();
    // Only log in debug builds (C++20-style format strings):
    nlohmann::json settings = payload["settings"];
    HSDLogger::LogMessage("Settings: " + settings.dump());
}

void BrightnessAction::WillAppear(const nlohmann::json& payload) {
    HSDLogger::LogMessage("WillAppear");
}

void BrightnessAction::SendToPlugin(const nlohmann::json& payload) {
    HSDLogger::LogMessage("Received message from property inspector: " + payload.dump());
}