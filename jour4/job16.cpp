#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int startHours = 13;
int startMinutes = 26;
int startSeconds = 0;

unsigned long startMillis;

void setup() {
  lcd.begin(16, 2);
  startMillis = millis(); 
}

void loop() {
  unsigned long elapsedMillis = millis() - startMillis;
  unsigned long totalSeconds = elapsedMillis / 1000 + startHours * 3600 + startMinutes * 60 + startSeconds;

  int s = totalSeconds % 60;
  int m = (totalSeconds / 60) % 60;
  int h = (totalSeconds / 3600) % 24;

  lcd.setCursor(0, 0);
  lcd.print("Heure: ");
  if (h < 10) lcd.print("0");
  lcd.print(h);
  lcd.print(":");
  if (m < 10) lcd.print("0");
  lcd.print(m);
  lcd.print(":");
  if (s < 10) lcd.print("0");
  lcd.print(s);

  delay(1000);
}