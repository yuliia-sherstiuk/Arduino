int leds[] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup() {
  for (int i = 0; i < 10; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(leds[i], HIGH);
    delay(30);
    digitalWrite(leds[i], LOW);

  }
}
