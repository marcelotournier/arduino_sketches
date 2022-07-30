/*
 * Very simple webserver prototype, just to test ESP wifi.
 * 
 * Once connecting the board, you will see the output in the serial monitor.
 * 
 * Change the "ssid" and "password" values to match your router's
 * configs
*/

#include <ESP8266WiFi.h>

const char* ssid = "YOUR_WIFI_NETWORK_NAME_HERE";  //type your ssid
const char* password = "YOUR_WIFI_PASSWORD_HERE";  //type your password

void setup()
{
  Serial.begin(115200);
  Serial.println();
  
  WiFi.begin(ssid, password);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {}
