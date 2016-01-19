/*
  This program is a functional PID controller based on the Arduino DUE!

  Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
  library works with all LCD displays that are compatible with the
  Hitachi HD44780 driver. There are many of them out there, and you
  can usually tell them by the 16-pin interface.
  The circuit:
   LCD RS pin to digital pin 12
   LCD Enable pin to digital pin 11
   LCD D4 pin to digital pin 5
   LCD D5 pin to digital pin 4
   LCD D6 pin to digital pin 3
   LCD D7 pin to digital pin 2
   LCD R/W pin to ground
   LCD VSS pin to ground
   LCD VCC pin to 5V
   10K resistor:
   ends to +5V and ground
   wiper to LCD VO pin (pin 3)
  http://www.arduino.cc/en/Tutorial/LiquidCrystal
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int digi_lock_switch_1 = 13;
int anain_trigger_time_1 = 13;

// initial settings
void setup() {
  // initialize the LCD
  lcd.begin(16, 2);
  lcd.print("HELLO LOCKER     ");
  lcd.setCursor(0, 1);
  lcd.print("A0:     V");
  
  //initialize buttons and switches
  pinMode(digi_lock_switch_1, INPUT);
  
  //initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// main program
void loop() {
  //read the analog button
  analogReadResolution(12);
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage_A0 = sensorValue * (3.0 / 4095.0);
  
  //char buf[48];
  //snprintf (snprintf, sizeof(buf), "%f", x);
  //voltage_A0_str = sprintf ( voltage_A0, "%f", 2 );
  lcd.setCursor(4, 1);
  lcd.print(voltage_A0);
  lcd.setCursor(10, 1);
  lcd.print("      ");
  lcd.setCursor(10, 1);
  lcd.print(sensorValue);
  
  lcd.setCursor(8, 1);
  // print the number of seconds since reset:
  //lcd.print(millis());

  //set button to change display
  int digi_lock_switch_1_val = digitalRead(digi_lock_switch_1);

  if (digi_lock_switch_1_val == HIGH) {
    lcd.setCursor(0, 0);
    lcd.print("Danke Robert   ");
  }
  
  if (digi_lock_switch_1_val == LOW) {
    lcd.setCursor(0, 0);
    lcd.print("Bitte Gerhard  ");
  }

  delay(100);
}

