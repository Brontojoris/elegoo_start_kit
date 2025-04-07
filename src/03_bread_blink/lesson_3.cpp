#include <Arduino.h>

int ledOnTime;
int ledOffTime;

// the setup function runs once when you press reset or power the board
void setup() {
    Serial.begin(9600);
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);
    randomSeed(analogRead(0));
}

// the loop function runs over and over again forever
void loop() {
    ledOnTime = random(5000)+100;
    ledOffTime = random(500)+100;
    Serial.println('ledOnTime', ledOnTime);
    Serial.println('ledOffTime', ledOffTime);
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(ledOnTime);                      // wait for a second
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    delay(ledOffTime);                      // wait for a second
}
