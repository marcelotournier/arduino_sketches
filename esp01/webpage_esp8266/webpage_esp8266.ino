/*
 * Very simple webserver prototype, just to test ESP wifi.
 * 
 * Once connecting the board, you will see the output in the serial monitor.
 * 
 * Change the "ssid" and "password" values to match your router's
 * 
 * Go to the url to see a "hello world" page
 * 
*/

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);
 
const char* ssid = "YOUR_WIFI_NETWORK_NAME_HERE";  //type your ssid
const char* password = "YOUR_WIFI_PASSWORD_HERE";  //type your password
 
void setup() {
  Serial.begin(115200); //Begin Serial at 115200 Baud
  WiFi.begin(ssid, password);  //Connect to the WiFi network
  
  while (WiFi.status() != WL_CONNECTED) {  //Wait for connection
      delay(500);
      Serial.println("Waiting to connect...");
  }
  
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //Print the local IP
  
  server.on("/", handle_index); //Handle Index page
  
  server.begin(); //Start the server
  Serial.println("Server listening");
}

void loop() {
  server.handleClient(); //Handling of incoming client requests
}

void handle_index() {
  //Print Hello at opening homepage
  server.send(200, "text/plain", "Hello! This is an index page.");
}
