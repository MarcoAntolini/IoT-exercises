#include "Arduino.h"

#define SENSOR A0
#define MIN_TEMP ((double)-40)
#define MAX_TEMP ((double)125)
#define MIN_VOLT ((double)0.1)
#define MAX_VOLT ((double)1.7)
#define DELTA_VOLT ((double)0.01)

void setup()
{
    Serial.begin(9600);
    analogReference(EXTERNAL);
}

void loop()
{
    int value = analogRead(SENSOR);
    double voltageOutput = ((double)value) * 5 / 1024;
    double temperature = MIN_TEMP + (voltageOutput - MIN_VOLT) / DELTA_VOLT;
    Serial.println(String(value) + " -> (voltageOutput in volt) " + voltageOutput + " -> (temperature in °C) " + temperature);
}

// #define SENSOR 0

// int input = 0;
// float temperature = 0;

// void setup()
// {
//     Serial.begin(9600);
// }

// void loop()
// {
//     input = analogRead(SENSOR);
//     temperature = ((input * 0.00488) - 0.5) / 0.01;
//     Serial.println(temperature);
//     delay(500);
// }