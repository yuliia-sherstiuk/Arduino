#include <LiquidCrystal.h>


LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);


const int ledPins[] = {2, 3, 4, 5, 6};
const int buttonPins[] = {7, 8, 9, 10, 11};
const int buzzerPin = 12;

const int NUM_COLORS = 5;
const int MAX_SEQUENCE = 100;

int sequence[MAX_SEQUENCE];
int level = 1;
int score = 0;
int inputIndex = 0;
bool gameActive = true;
int difficultyDelay = 500;

void setup() {
  // LCD
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(" Jeu de Memoire ");
  delay(2000);

  // Пины
  for (int i = 0; i < NUM_COLORS; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT_PULLUP); 
  }

  pinMode(buzzerPin, OUTPUT);
  randomSeed(analogRead(A0)); 

  startGame();
}

void loop() {
  if (!gameActive) return;

  showSequence();
  getPlayerInput();
}

void startGame() {
  level = 1;
  score = 0;
  difficultyDelay = 500;
  gameActive = true;
  generateSequence();
}

void generateSequence() {
  for (int i = 0; i < MAX_SEQUENCE; i++) {
    sequence[i] = random(0, NUM_COLORS); // 0 à 4
  }
}

void showSequence() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Niveau: ");
  lcd.print(level);
  lcd.setCursor(0, 1);
  lcd.print("Score: ");
  lcd.print(score);

  delay(1000);

  for (int i = 0; i < level; i++) {
    int led = sequence[i];
    digitalWrite(ledPins[led], HIGH);
    delay(difficultyDelay);
    digitalWrite(ledPins[led], LOW);
    delay(200);
  }
}

void getPlayerInput() {
  inputIndex = 0;

  while (inputIndex < level) {
    for (int i = 0; i < NUM_COLORS; i++) {
      if (digitalRead(buttonPins[i]) == LOW) {
        delay(50); // антидребезг
        while (digitalRead(buttonPins[i]) == LOW);

        flashLed(i);

        if (i != sequence[inputIndex]) {
          playError();
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Erreur!");
          lcd.setCursor(0, 1);
          lcd.print("Redemarrage...");
          delay(2000);
          startGame();
          return;
        }

        inputIndex++;
      }
    }
  }

  score++;
  level++;

 
  if (level % 30 == 0) {
    difficultyDelay = max(200, difficultyDelay - 50);
  }
}

void flashLed(int index) {
  digitalWrite(ledPins[index], HIGH);
  delay(150);
  digitalWrite(ledPins[index], LOW);
}

void playError() {
  tone(buzzerPin, 1000, 700);
  delay(700);
  noTone(buzzerPin);
}