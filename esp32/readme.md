# Connecting ESP32 to Wi-Fi

These notes are paraphrased from: [Electronic Wings - ESP32 Wi-Fi Basics Getting Started](https://www.electronicwings.com/esp32/esp32-wi-fi-basics-getting-started)

## Mode 1: ESP32 Wi-Fi Station

```
WiFi.mode(WIFI_STA)
```

In this mode, ESP32 connects to the other network
such as a Wi-Fi router. In the connection process,
the Wi-Fi router assigns the unique IP address to
the ESP32.

The router is connected to the internet, so we can
request data from the internet i.e. Cloud, APIs,
also we can send the data to the internet.

## Mode 2: ESP32 Access Point

```
WiFi.mode(WIFI_AP)
```

In Access point mode, ESP32 creates its own Wi-Fi
network. It acts as a router and other devices can
connect to the ESP32 like smartphones and laptops.

This mode is mentioned as soft-AP (Soft Access Point).

## Mode 3: ESP32 Access point and Hotspot Mode

```
WiFi.mode(WIFI_AP_STA)
```

ESP32 acts in both modes at the same time.

## ESP32 Wi-Fi Connection Status

`WiFi.status()` returns one of the following values


| Constant          | Meaning                                               |
| ----------------- | ----------------------------------------------------- |
| WL_IDLE_STATUS    | temporary status assigned when WiFi.begin() is called |
| WL_NO_SSID_AVAIL  | when no SSID are available                            |
| WL_SCAN_COMPLETED | when connected to a WiFi network                      |
| WL_CONNECTED      | when the connection fails for all the attempts        |
| WL_CONNECT_FAILED | when the connection is lost                           |
| WL_DISCONNECTED   | when disconnected from a network                      |

## Disconnect from Wi-Fi Network

If we need to disconnect from Wi-Fi, Use

```
WiFi.disconnect();
```

## More Articles

* [ESP32 Wi-Fi Basics](https://www.electronicwings.com/esp32/esp32-wi-fi-basics-getting-started)
* [Reconnect ESP32 to Wi-Fi Network](https://www.electronicwings.com/esp32/reconnect-esp32-to-wi-fi-network-after-lost-connection)
* [MQTT on ESP32](https://www.electronicwings.com/esp32/esp32-mqtt-client)
* [ESP32 Bluetooth](https://www.electronicwings.com/esp32/esp32-bluetooth-getting-started)
* [Static IP Address](https://www.electronicwings.com/esp32/esp32-setting-static-ip-address)
* [HTTP on ESP32](https://www.electronicwings.com/esp32/http-client-on-esp32-with-arduino-ide)
* [ESP32 WiFi Server](https://www.electronicwings.com/esp32/how-to-create-esp32-wifi-server)
* [Telegram Group Control LED](https://www.electronicwings.com/esp32/control-the-led-appliance-using-telegram-group-with-esp32-)
* [Send Emails with SMTP](https://www.electronicwings.com/esp32/send-emails-using-esp32-with-smtp-server)
* [Google Sheets](https://www.electronicwings.com/esp32/esp32-publish-sensor-readings-on-google-sheets-)
* [Telegram Message](https://www.electronicwings.com/esp32/send-a-telegram-message-using-esp32)
* [LED Control using Telegram](https://www.electronicwings.com/esp32/control-the-led-using-telegram-message-and-esp32)
* [WhatsApp Message](https://www.electronicwings.com/esp32/send-a-whatsapp-message-using-esp32)
* [ESP32 OTA](https://www.electronicwings.com/esp32/esp32-ota-programming-using-arduino-ide-)
* [Email Temperature Alerts](https://www.electronicwings.com/esp32/temperature-alerts-on-email-using-esp32)
* [Telegram Temperature Alert](https://www.electronicwings.com/esp32/temperature-alert-on-telegram-using-esp32)
* [WhatsApp Temperature Alert](https://www.electronicwings.com/esp32/temperature-alert-on-whatsapp-using-esp32)
* [Whatsapp Controlled LED](https://www.electronicwings.com/esp32/control-the-led-using-whatsapp-message-with-esp32)
* [Temperature on Analog Gauge](https://www.electronicwings.com/esp32/analog-gauge-temperature-reading-using-esp32-server)
* [ESP32 Web Server SPIFFS](https://www.electronicwings.com/esp32/esp32-web-server-using-spiffs-spi-flash-file-system-)
* [ESP32 IOT Dashboard](https://www.electronicwings.com/esp32/esp32-iot-dashboard-)