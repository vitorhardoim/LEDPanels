#include <FastLED.h>
#include <ESP8266WiFi.h>
#define LED_TYPE NEOPIXEL
#define DATA_PIN 13
#define LEDS_IN_PANEL 12
#define NUM_PANELS 4
#include "animator.h"
#include "blynkController.h"
#include <BlynkSimpleEsp8266.h>

Animator anim(LEDS_IN_PANEL, NUM_PANELS);
//Blynk Variables
int brightness;

char auth[] = "h4IPfFLa4xnlSAaKL4vurCz3Or8_dDr7"; //Codigo Blynk do projeto
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "DRUMMOND2.4";
char pass[] = "CARLOSVCSD22";

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, IPAddress(192, 168, 0, 6), 8080);
  
  anim.startAnimator();
  anim.updatePanelColor(0, CHSV(0,0,0));
  anim.updatePanelColor(1, CHSV(0,0,0));
  anim.updatePanelColor(2, CHSV(0,0,0));
  anim.updatePanelColor(3, CHSV(0,0,0));

  FastLED.clear();  // clear all pixel data
  FastLED.show();
}

BLYNK_WRITE(V2) // Brilho
{
  brightness = param.asInt();
}

void loop() {
  Blynk.run();

  anim.fade(0, brightness);
  anim.fade(1, brightness);
  anim.fade(2, brightness);
  anim.fade(3, brightness);

  FastLED.show();
}
