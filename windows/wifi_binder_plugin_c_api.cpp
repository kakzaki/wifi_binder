#include "include/wifi_binder/wifi_binder_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "wifi_binder_plugin.h"

void WifiBinderPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  wifi_binder::WifiBinderPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
