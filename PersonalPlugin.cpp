#include "PersonalPlugin.h"

#include "StreamDockCPPSDK/StreamDockSDK/NlohmannJSONUtils.h"
#include "StreamDockCPPSDK/StreamDockSDK/HSDLogger.h"

std::shared_ptr<HSDAction> PersonalPlugin::GetOrCreateAction(const std::string& action, const std::string& context)
{
    auto it = mActions.find(context);
    if (it != mActions.end()) {
        return it->second;
    }

    if (action == "com.hotspot.streamdockcppsdk.demo.myaction1" ||
        action == "com.hotspot.streamdockcppsdk.demo.myaction2") {
        auto impl = std::make_shared<BrightnessAction>(
            mConnectionManager,
            action,
            context
            );
        mActions.emplace(context, impl);
        return impl;
    }

    HSDLogger::LogMessage("Asked to get or create unknown action: " + action);
    return nullptr;
}

void PersonalPlugin::DidReceiveGlobalSettings(const nlohmann::json& payload)
{
    HSDLogger::LogMessage("Received global settings");
    HSDLogger::LogMessage("Global settings: " + payload.dump());

    // Do plugin-wide stuff here, e.g. reconnect to application being
    // controlled

    for (const auto& action : mActions) {
        // ... then pass it on to each action, e.g.:
        // action->setApplicationConnection(myConnectionObject);
    }
}
