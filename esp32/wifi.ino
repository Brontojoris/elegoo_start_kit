#include <WiFi.h>

/* WI-FI MODE

# Mode 1: ESP32 Wi-Fi Station

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

# Mode 2: ESP32 Access Point

```
WiFi.mode(WIFI_AP)
```

In Access point mode, ESP32 creates its own Wi-Fi
network. It acts as a router and other devices can
connect to the ESP32 like smartphones and laptops.

This mode is mentioned as soft-AP (Soft Access Point). 

# Mode 3: ESP32 Access point and Hotspot Mode 

```
WiFi.mode(WIFI_AP_STA)
```

ESP32 acts in both modes at the same time.

# ESP32 Wi-Fi Connection Status

WiFi.status() returns one of the following values

WL_IDLE_STATUS     temporary status assigned when WiFi.begin() is called
WL_NO_SSID_AVAIL   when no SSID are available
WL_SCAN_COMPLETED	 scan networks is completed
WL_CONNECTED	     when connected to a WiFi network
WL_CONNECT_FAILED	 when the connection fails for all the attempts
WL_CONNECTION_LOST when the connection is lost
WL_DISCONNECTED	   when disconnected from a network

# Disconnect from Wi-Fi Network
If we need to disconnect from Wi-Fi, Use

```
WiFi.disconnect();
```
*/

const char* ssid = "<WiFi SSID>";
const char* password = "<wifi-password>>";

void initWiFi() {
 WiFi.mode(WIFI_STA);    //Set Wi-Fi Mode as station
 WiFi.begin(ssid, password);   
 
 Serial.println("Connecting to WiFi ..");
 while (WiFi.status() != WL_CONNECTED) {
   Serial.print('.');
   delay(1000);
 }
 
 Serial.println(WiFi.localIP());
 Serial.print("RRSI: ");
 Serial.println(WiFi.RSSI());
}

void setup() {
 Serial.begin(115200);
 initWiFi();
}

void loop() {
  // Log some info to console
  Serial.println(WiFi.RSSI());
  delay(2000);
}
