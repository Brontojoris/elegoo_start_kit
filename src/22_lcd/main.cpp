#include <Arduino.h>
//www.elegoo.com
//2016.12.9

/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);


void frog() {
    lcd.clear();

    byte image22[8] = {B00010, B00100, B01000, B01000, B01001, B00100, B01111, B00000};
    byte image06[8] = {B00000, B00001, B00010, B00010, B00100, B01000, B01000, B00100};
    byte image07[8] = {B00000, B11011, B00100, B00000, B10001, B10001, B00000, B00000};
    byte image08[8] = {B00000, B10000, B01000, B01000, B00100, B00010, B00010, B00100};
    byte image23[8] = {B10001, B01110, B00000, B00000, B00000, B10001, B11111, B00000};
    byte image24[8] = {B01000, B00100, B00010, B00010, B10010, B00100, B11110, B00000};

    lcd.createChar(0, image22);
    lcd.createChar(1, image06);
    lcd.createChar(2, image07);
    lcd.createChar(3, image08);
    lcd.createChar(4, image23);
    lcd.createChar(5, image24);

    lcd.setCursor(5, 1);
    lcd.write(byte(0));
    lcd.setCursor(5, 0);
    lcd.write(byte(1));
    lcd.setCursor(6, 0);
    lcd.write(byte(2));
    lcd.setCursor(7, 0);
    lcd.write(byte(3));
    lcd.setCursor(6, 1);
    lcd.write(byte(4));
    lcd.setCursor(7, 1);
    lcd.write(byte(5));
}



void setup() {
    // initialize LCD and set up the number of columns and rows:
    lcd.begin(16, 2);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Hello Barney!");
}

void loop() {
    delay(2000);
    frog();
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Hello Barney!");
}