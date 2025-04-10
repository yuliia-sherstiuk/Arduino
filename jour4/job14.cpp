LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int bouton = 7;
bool enPause = false;
unsigned long lastTime = 0;
unsigned long compteur = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(bouton, INPUT_PULLUP);
  lcd.setCursor(0, 0);
  lcd.print("B1 G3 Logiciel & Immersif "); 

void loop() {
  if (digitalRead(bouton) == LOW) {
    delay(200);
    enPause = !enPause;
    while (digitalRead(bouton) == LOW); 
  }

  if (!enPause && millis() - lastTime >= 1000) {
    compteur++;
    lastTime = millis();
    lcd.setCursor(0, 1);
    lcd.print("Temps: ");
    lcd.print(compteur);
    lcd.print("    "); 
  }
}