#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

long duration;
int distance;

void setup() {

  pinMode(9, OUTPUT);   // TRIG
  pinMode(10, INPUT);   // ECHO

  lcd.begin(16, 2);
  lcd.print("Distance:");
}

void loop() {

  digitalWrite(9, LOW);
  delayMicroseconds(2);

  digitalWrite(9, HIGH);
  delayMicroseconds(10);
  digitalWrite(9, LOW);

  duration = pulseIn(10, HIGH);

  distance = duration * 0.034 / 2;

  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm   ");

  delay(300);
}