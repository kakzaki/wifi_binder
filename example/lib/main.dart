import 'package:flutter/material.dart';
import 'package:wifi_binder/wifi_binder.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({super.key});

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  final _wifiBinderPlugin = WifiBinder();

  @override
  void initState() {
    super.initState();
    _wifiBinderPlugin.bindWifiOnly();
  }

  @override
  void dispose() {
    _wifiBinderPlugin.unbindNetwork();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(title: const Text('Plugin example app')),
        body: Center(child: Text('Running on: bindWifiOnly\n')),
      ),
    );
  }
}
