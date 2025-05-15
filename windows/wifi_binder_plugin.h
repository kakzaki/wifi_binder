#ifndef FLUTTER_PLUGIN_WIFI_BINDER_PLUGIN_H_
#define FLUTTER_PLUGIN_WIFI_BINDER_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace wifi_binder {

class WifiBinderPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  WifiBinderPlugin();

  virtual ~WifiBinderPlugin();

  // Disallow copy and assign.
  WifiBinderPlugin(const WifiBinderPlugin&) = delete;
  WifiBinderPlugin& operator=(const WifiBinderPlugin&) = delete;

  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

}  // namespace wifi_binder

#endif  // FLUTTER_PLUGIN_WIFI_BINDER_PLUGIN_H_
