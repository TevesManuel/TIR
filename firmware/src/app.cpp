#include <Arduino.h>
#include <IRremote.h>

#define IR_SENSOR 8
#define LED 13

IRrecv irRecv;

void setup() {
    pinMode(LED, OUTPUT);
}

void loop() {
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
}
