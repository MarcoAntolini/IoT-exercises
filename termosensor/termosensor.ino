#include "Arduino.h"

#define SENSOR 0

int input = 0;
float temperature = 0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    input = analogRead(SENSOR);
    temperature = ((input * 0.00488) - 0.5) / 0.01;
    Serial.println(temperature);
    delay(500);
}