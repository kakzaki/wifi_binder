//
//  Generated file. Do not edit.
//

// clang-format off

#include "generated_plugin_registrant.h"

#include <wifi_binder/wifi_binder_plugin.h>

void fl_register_plugins(FlPluginRegistry* registry) {
  g_autoptr(FlPluginRegistrar) wifi_binder_registrar =
      fl_plugin_registry_get_registrar_for_plugin(registry, "WifiBinderPlugin");
  wifi_binder_plugin_register_with_registrar(wifi_binder_registrar);
}
