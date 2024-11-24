#include "PersonalPlugin.h"

#include "StreamDockCPPSDK/StreamDockSDK/HSDMain.h"

int main(int argc, const char** argv) {
  auto plugin = std::make_unique<PersonalPlugin>();
  return esd_main(argc, argv, plugin.get());
}
