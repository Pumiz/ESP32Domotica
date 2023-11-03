// Include the library files
#include <BlynkSimpleEsp32.h>
#include <WiFiClient.h>
#include <Wire.h>

#define BLYNK_TEMPLATE_ID "TMPL2hJWNJaVw"
#define BLYNK_TEMPLATE_NAME "ESP32Domotica"
#define PIN_RELAY 4

BlynkTimer timer;

// Enter your Auth token
char auth[] = "HjUNOxsKGQ3rb9_Y9BqwrtRiYtRaGxNB";

// Enter your WIFI SSID and password
char ssid[] = "Estudiantes";
char pass[] = "educar_2018";

void setup() {
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  pinMode(PIN_RELAY, OUTPUT);
  digitalWrite(PIN_RELAY, HIGH);

  Serial.println("Cargando sistema");
}

// Get the button value
BLYNK_WRITE(V1) {
  bool PIN_RELAY = param.asInt();
  if (PIN_RELAY == 1) {
    digitalWrite(PIN_RELAY, LOW);
    Serial.println("Motor encendido");
  } else {
    digitalWrite(PIN_RELAY, HIGH);
    Serial.println("Motor encendido");
  }
}

void loop() {
  Blynk.run(); // Run the Blynk library
  delay(200);
}