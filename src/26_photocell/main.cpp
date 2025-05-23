#include <Arduino.h>

int lightPin = 0;
int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

int leds = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
}
void updateShiftRegister()
{
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, leds);
    digitalWrite(latchPin, HIGH);
}
void loop()
{
    int reading  = analogRead(lightPin);
    Serial.println(reading);
    int numLEDSLit = reading / 5;  //1023 / 9 / 2
    if (numLEDSLit > 8) numLEDSLit = 8;
    leds = 0;   // no LEDs lit to start
    for (int i = 0; i < numLEDSLit; i++)
    {
        leds = leds + (1 << i);  // sets the i'th bit
    }
    updateShiftRegister();
    delay(250);
}