#include <LiquidCrystal.h>

int motor = 13;
int tempPin = A0;
int tempVal;
int temperature;

// Use safe pins for LCD (not 0 or 1)
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  pinMode(tempPin, INPUT);
  pinMode(motor, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  tempVal = analogRead(tempPin);
  temperature = (tempVal * 500) / 1024;

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C   ");

  if (temperature > 25) {
    digitalWrite(motor, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Motor: ON ");
  } else {
    digitalWrite(motor, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Motor: OFF");
  }

  delay(1000);
}
