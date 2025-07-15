// Sample code for Air Quality Monitor with MQ135 (CO2) sensor and Blynk
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_DEVICE_NAME "AirQualityMonitor"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

char ssid[] = "YourWiFi";
char pass[] = "YourPassword";

int airSensor = A0;

void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
  int airValue = analogRead(airSensor);
  Blynk.virtualWrite(V0, airValue);
  delay(2000);
}
