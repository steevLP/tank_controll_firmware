#include <Arduino.h>
#include <FastLED.h>

#define GUN_DRIVE_MOTOR 23
#define DATA_PIN 14
#define NUM_LEDS 16

//Pin Definition
#define NAV_MOTOR_L_B 2
#define NAV_MOTOR_L_F 0
#define NAV_MOTOR_R_F 4
#define NAV_MOTOR_R_B 16

#define BAUD 9600

CRGB leds[16];

void drive(int a, int b, int c, int d) {
    analogWrite(NAV_MOTOR_L_F,a);
    analogWrite(NAV_MOTOR_R_F,b);
    analogWrite(NAV_MOTOR_L_B,c);
    analogWrite(NAV_MOTOR_R_B,d);
}

void setup() {

    // Initialize Serial
    Serial.begin(BAUD);

    // Utillity Pins
    pinMode(GUN_DRIVE_MOTOR, OUTPUT);
        
    // Movement Controlls    
    pinMode(NAV_MOTOR_L_F, OUTPUT);
    pinMode(NAV_MOTOR_L_B, OUTPUT);
    pinMode(NAV_MOTOR_R_F, OUTPUT);
    pinMode(NAV_MOTOR_R_B, OUTPUT);

    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

    FastLED.clear();
    FastLED.show();

}

void loop() {
    drive(0, 255, 0, 0);
}