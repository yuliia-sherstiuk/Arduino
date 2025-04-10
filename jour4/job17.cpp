#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int bouton = 7;

bool enCours = false;
unsigned long startTime = 0;

void setup() {
  pinMode(bouton, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.print("Chronometre");
}

void loop() {
  if (digitalRead(bouton) == LOW) {
    delay(200);
    while (digitalRead(bouton) == LOW);
    enCours = !enCours;
    if (enCours) startTime = millis();
  }

  if (enCours) {
    unsigned long temps = (millis() - startTime) / 1000;
    int s = temps % 60;
    int m = (temps / 60) % 60;
    int h = (temps / 3600) % 24;

    lcd.setCursor(0, 1);
    if (h < 10) lcd.print("0");
    lcd.print(h); lcd.print(":");
    if (m < 10) lcd.print("0");
    lcd.print(m); lcd.print(":");
    if (s < 10) lcd.print("0");
    lcd.print(s);
    lcd.print(" ");
  }
}
