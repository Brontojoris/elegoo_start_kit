#include <Arduino.h>

/*
Blink
Turns an LED on for one second, then off for one second, repeatedly.

http://www.arduino.cc/en/Tutorial/Blink

From Page 41 of UNO Starter Kit.pdf
*/

void setup() {
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
    digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
    delay(1000); // wait for a second
    digitalWrite(LED_BUILTIN, LOW); // turn the LED off by making the voltage LOW
    delay(1000); // wait for a second
}