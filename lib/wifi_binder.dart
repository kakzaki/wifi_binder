import 'package:flutter/services.dart';

class WifiBinder {
  final MethodChannel _channel = MethodChannel('wifi_binder');

  Future<void> bindWifiOnly() async {
    await _channel.invokeMethod('bindWifiOnly');
  }

  Future<void> unbindNetwork() async {
    await _channel.invokeMethod('unbindNetwork');
  }
}
