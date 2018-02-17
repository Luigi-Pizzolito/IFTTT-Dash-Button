/*
 *  This sketch sends data via HTTP GET requests to data.sparkfun.com service.
 *
 */

#include <ESP8266WiFi.h>

const char* ssid     = "27-2B";
const char* password = "1357924680";

const char* host = "lurl.site90.com";

void setup() {
  Serial.begin(115200);
  delay(10);
  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
     would try to act as both a client and an access-point and could cause
     network-issues with your other WiFi-devices on your WiFi-network. */
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

int value = 0;

void loop() {
  //delay(5000);
  ++value;
  if (value == 11) {
    Serial.println("Session Terminated. Giving up after 10 tries.");
    Serial.println("entering deep sleep");
    delay(20);
    fail();
    ESP.deepSleep(0);
  }

 
  Serial.print("Try: ");
  Serial.println(value);
  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    delay(10);
    return;
  }
  
  // We now create a URI for the request
  String url = "/clara/";
  
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 60000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      //return;
      Serial.println("entering deep sleep");
      ESP.deepSleep(0);
    }
  }
  
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  client.stop();
  Serial.println();
  Serial.println("closing connection");
  Serial.println("entering deep sleep");
  yay();
  ESP.deepSleep(0);
}

void fail() {
  pinMode(LED_BUILTIN, OUTPUT); 
  digitalWrite(LED_BUILTIN, LOW); 
  delay(250);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(250);
  digitalWrite(LED_BUILTIN, LOW); 
  delay(250);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(250);
  digitalWrite(LED_BUILTIN, LOW); 
  delay(250);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(250);
  digitalWrite(LED_BUILTIN, LOW); 
  delay(250);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(250);
  digitalWrite(LED_BUILTIN, LOW); 
  delay(250);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(250);
  digitalWrite(LED_BUILTIN, LOW); 
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);
}

void yay() {
  pinMode(LED_BUILTIN, OUTPUT); 
  digitalWrite(LED_BUILTIN, LOW); 
  delay(1500);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(250);
  digitalWrite(LED_BUILTIN, LOW); 
  delay(350);
  digitalWrite(LED_BUILTIN, HIGH);
}

