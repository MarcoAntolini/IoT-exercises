#include "Arduino.h"

#define SENSOR A0
#define FREQ 5
#define MSS 1023

int input, current;
double voltage;

void setup() {
    pinMode(SENSOR, INPUT);
    Serial.begin(9600);
}

void loop() {
    input = analogRead(A0);
    if(input != current) {
        current = input;
        voltage = ((double)input / MSS) * FREQ;
        Serial.println(String(current) + " -> in volt: " + voltage);
        delay(1000/FREQ);
    }
}