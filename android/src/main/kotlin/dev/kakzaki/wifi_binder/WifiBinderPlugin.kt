package dev.kakzaki.wifi_binder
import android.content.Context
import android.net.*
import android.os.Build
import io.flutter.embedding.engine.plugins.FlutterPlugin
import io.flutter.plugin.common.MethodCall
import io.flutter.plugin.common.MethodChannel
import io.flutter.plugin.common.MethodChannel.MethodCallHandler


/** WifiBinderPlugin */
class WifiBinderPlugin: FlutterPlugin, MethodCallHandler {
  private lateinit var channel: MethodChannel
  private lateinit var context: Context

  override fun onAttachedToEngine(binding: FlutterPlugin.FlutterPluginBinding) {
    context = binding.applicationContext
    channel = MethodChannel(binding.binaryMessenger, "wifi_binder")
    channel.setMethodCallHandler(this)
  }

  override fun onMethodCall(call: MethodCall, result: MethodChannel.Result) {
    val cm = context.getSystemService(Context.CONNECTIVITY_SERVICE) as ConnectivityManager
    when (call.method) {
      "bindWifiOnly" -> {
        val request = NetworkRequest.Builder()
          .addTransportType(NetworkCapabilities.TRANSPORT_WIFI)
          .build()
        cm.requestNetwork(request, object : ConnectivityManager.NetworkCallback() {
          override fun onAvailable(network: Network) {
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
              cm.bindProcessToNetwork(network)
            } else {
              ConnectivityManager.setProcessDefaultNetwork(network)
            }
            result.success(true)
          }
        })
      }
      "unbindNetwork" -> {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
          cm.bindProcessToNetwork(null)
        } else {
          ConnectivityManager.setProcessDefaultNetwork(null)
        }
        result.success(true)
      }
      else -> result.notImplemented()
    }
  }

  override fun onDetachedFromEngine(binding: FlutterPlugin.FlutterPluginBinding) {
    channel.setMethodCallHandler(null)
  }
}
