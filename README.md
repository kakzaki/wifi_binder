Berikut adalah isi lengkap `README.md` untuk plugin Flutter `wifi_binder`, termasuk deskripsi, setup, penggunaan, dan troubleshooting:

---

# 📶 wifi\_binder\

A Flutter plugin to **force network traffic over Wi-Fi only**, even when mobile data is turned on. Useful for connecting to local-only Wi-Fi devices such as **dashcams**, **IoT devices**, or **local servers**.

> 🛠 This plugin currently supports **Android only**, and is written in **Kotlin**.

---

## ✨ Features

* ✅ Bind process-level networking to Wi-Fi
* 🔄 Unbind to resume normal routing (use both mobile and Wi-Fi)
* ⚡ Works without turning off mobile data manually
* 🛑 Android only (iOS not supported)

---

## 🚀 Getting Started

### 1. Add the Plugin to Your Project

Download or clone this repository and place it inside a `packages/` directory, or any location in your project.

Update your `pubspec.yaml`:

```yaml
dependencies:
  wifi_binder:
    path: ./packages/wifi_binder
```

---

### 2. Import and Use in Code

```dart
import 'package:wifi_binder/wifi_binder.dart';

/// Forces all traffic through the currently connected Wi-Fi
await WifiBinder.bindWifiOnly();

/// Unbinds the network and restores default behavior
await WifiBinder.unbindNetwork();
```

---

## 📱 Android Setup

### 1. Permissions

In your `AndroidManifest.xml` (usually under `android/app/src/main/`), add:

```xml
<uses-permission android:name="android.permission.ACCESS_NETWORK_STATE"/>
<uses-permission android:name="android.permission.CHANGE_NETWORK_STATE"/>
```

### 2. Minimum SDK

In `android/app/build.gradle`, set:

```gradle
minSdkVersion 23
```

---

## ✅ Example Use Case

If you're building a dashcam viewer app:

* The app connects to dashcam Wi-Fi (e.g., `192.168.0.1`)
* Mobile data is still ON (by default Android routes requests via mobile)
* With this plugin, your video stream or requests are forced to use Wi-Fi

---

## ❗ Limitations

* 🔸 Android only
* 🔸 Not intended for background tasks or multi-process routing
* 🔸 May not work if user switches Wi-Fi after binding (call `bindWifiOnly()` again)
* ⚠️ Ensure the Wi-Fi connection is already established before calling bind

---

## 🧪 Testing

Use on a real Android device connected to a Wi-Fi network with no internet access (e.g., dashcam hotspot). Ensure mobile data is active to validate that the plugin correctly routes over Wi-Fi.

---

## 🔧 Troubleshooting

| Problem                               | Solution                                                              |
| ------------------------------------- | --------------------------------------------------------------------- |
| Network still using mobile data       | Ensure `bindWifiOnly()` is called **after** Wi-Fi is connected        |
| `setProcessDefaultNetwork` deprecated | The plugin uses `bindProcessToNetwork` automatically for Android ≥ 23 |
| iOS not supported                     | iOS doesn’t allow custom network binding at this level                |
| App crash on start                    | Check `minSdkVersion >= 23` and permissions are granted               |

---

## 📂 Plugin Structure

```
wifi_binder/
├── lib/
│   └── wifi_binder.dart
├── android/
│   └── src/main/kotlin/... (Kotlin logic)
├── pubspec.yaml
└── README.md
```

---

## 📜 License

This project is licensed under the MIT License.

---

Jika kamu ingin README ini dalam Bahasa Indonesia atau ingin dipublikasikan ke pub.dev, tinggal beri tahu saja.

