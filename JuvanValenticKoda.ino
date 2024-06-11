#include <LiquidCrystal.h>

const int photoresistorPin = A0;//pin za foto resistor

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


const float calibrationFactor = 0.52; //kalibracija

void setup() {
  lcd.begin(16, 2);
  lcd.print("Lux Meter Test");
}

void loop() {
  int sensorValue = analogRead(photoresistorPin);

  float lux = (1023 - sensorValue) * calibrationFactor -3;

  lcd.setCursor(0, 1);
  lcd.print("Lux: ");
  lcd.print(lux);

  delay(1000);
}
