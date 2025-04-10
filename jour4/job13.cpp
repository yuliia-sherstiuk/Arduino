#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
byte smiley[8] = {
  B00000,
  B01010,
  B01010,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000
};

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, smiley); 
  lcd.setCursor(0, 0);
  lcd.write(byte(0)); 
}

void loop() {
  
}