//https://github.com/FastLED/FastLED/wiki
#include <FastLED.h>

#define NUM_LEDS 144

#define DATA_PIN 2

CRGB leds[NUM_LEDS];
int c=random(3);
void setup() {
  pinMode(3,INPUT_PULLUP);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
}

void loop() {
  if(digitalRead(3)==0){
    c++;
    if(c>2)c=0;
  }
  if (c== 0) {
    //  流れる
    for (int i = 0; i < NUM_LEDS - 6; i++) {
      leds[i] = CRGB( 255, 0, 0);
      leds[i + 3] = CRGB( 0, 255, 0);
      leds[i + 6] = CRGB( 0, 0, 255);
      FastLED.show();
      delay(20);
      leds[i] = CRGB( 0, 0, 0);
      FastLED.show();
    }
  }
  if (c== 1) {
    // random
    for (int i = 0; i < 50; i++) {
      leds[rand() % 144] = CRGB( rand() % 255, rand() % 255, rand() % 255);
    }
    FastLED.show();
    delay(200);
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB( 0, 0, 0);
    }
    FastLED.show();
  }

  if (c== 2) {
    for (int i = 0; i < NUM_LEDS; i++) {
      if (i % 2 == 0) {
        switch ((i / 2) % 3) {
          case 0:
            leds[i] = CRGB( 255, 0, 0);
            break;
          case 1:
            leds[i] = CRGB( 0, 255, 0);
            break;
          case 2:
            leds[i] = CRGB( 0, 0, 255);
            break;
        }
      }
    }
    FastLED.show();
    delay(200);
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB( 0, 0, 0);
    }
    FastLED.show();
    for (int i = 0; i < NUM_LEDS; i++) {
      if (i % 2 == 0) {
        switch ((i / 2) % 3) {
          case 0:
            leds[i + 1] = CRGB( 255, 0, 0);
            break;
          case 1:
            leds[i + 1] = CRGB( 0, 255, 0);
            break;
          case 2:
            leds[i + 1] = CRGB( 0, 0, 255);
            break;
        }
      }
    }
    FastLED.show();
    delay(200);
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB( 0, 0, 0);
    }
    FastLED.show();
  }
}
