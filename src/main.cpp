#include <Wire.h>
#include <WiFiClient.h>


#define BLYNK_TEMPLATE_ID "TMPL2hJWNJaVw"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "HjUNOxsKGQ3rb9_Y9BqwrtRiYtRaGxNB"
#include <BlynkSimpleEsp32.h>
#define sensor 33
#define relay 4

BlynkTimer timer;

// Enter your Auth token
const char auth[] = "HjUNOxsKGQ3rb9_Y9BqwrtRiYtRaGxNB";

//Enter your WIFI SSID and password
const char ssid[] = "Estudiantes";
const char pass[] = "educar_2018";

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  Serial.println("Cargando sistema");
}

//Get the button value
BLYNK_WRITE(V0) {
  bool Relay = param.asInt();
  if (Relay == 1) {
    digitalWrite(relay, LOW);
    Serial.println("Motor apagado");
  } else {
    digitalWrite(relay, HIGH);
    Serial.println("Motor andando");
  }
}

void loop() {
  Blynk.run();//Run the Blynk library

  delay(200);

}