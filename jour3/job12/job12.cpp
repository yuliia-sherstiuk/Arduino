#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Adresse I2C, colonnes, lignes

void setup() {
  lcd.begin();
  lcd.backlight();  // Allume le rétroéclairage
  lcd.setCursor(0, 0);
  lcd.print("Hello World !");
}

void loop() {
  // Rien ici
}