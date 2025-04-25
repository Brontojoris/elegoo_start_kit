#include <Arduino.h>
//www.elegoo.com
//2016.12.9

int ledPin = 13;  // LED on Pin 13 of Arduino
int pirPin = 7; // Input for HC-S501
int initCountDown = 0; // Docs says I gotta wait 1 minute, but in practice, no. So forcing OFF
int blockCountDown = 0; // Doc says theres an ignore periond, but in practice not so much
int pirValue; // Place to store read PIR Value

void setup() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    pinMode(pirPin, INPUT);
    digitalWrite(ledPin, LOW);
    Serial.println("PIR Sensor: setup()");
}

void loop() {
    pirValue = digitalRead(pirPin);
    digitalWrite(ledPin, pirValue);

    if (initCountDown > 0) {
        Serial.print("Ready in "); Serial.print(initCountDown); Serial.println(" seconds");
        initCountDown = initCountDown -1;
    }
    if (blockCountDown > 0) {
        Serial.print("PIR Sensor blocked for "); Serial.print(blockCountDown); Serial.println(" seconds");
        blockCountDown = blockCountDown -1;
    }
    if (pirValue > 0) {
        Serial.println("PIR Sensed a change");
        //blockCountDown = 3;
    }else {
        Serial.println("No change");
    }
    delay(1000);
}