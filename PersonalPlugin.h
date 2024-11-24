#pragma once

#include "StreamDockCPPSDK/StreamDockSDK/HSDPlugin.h"
#include "BrightnessAction.h"
#include <set>
#include <mutex>
#include <map>

class PersonalPlugin : public HSDPlugin
{
public:
    using HSDPlugin::HSDPlugin;

    virtual std::shared_ptr<HSDAction> GetOrCreateAction(const std::string& action, const std::string& context) override;

    // Overriding from ESDBasePlugin
    virtual void DidReceiveGlobalSettings(const nlohmann::json& payload) override;
    
private:
    std::mutex mVisibleContextsMutex;
    std::set<std::string> mVisibleContexts;
    std::map<std::string, std::shared_ptr<BrightnessAction>> mActions;
};

