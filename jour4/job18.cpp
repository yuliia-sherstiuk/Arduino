#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int position = 0;
unsigned long lastTime = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Chargement...");
}

void loop() {
  if (millis() - lastTime >= 3000 && position < 16) {
    lcd.setCursor(position, 1);
    lcd.write(byte(255)); 
    position++;
    lastTime = millis();
  }
}
