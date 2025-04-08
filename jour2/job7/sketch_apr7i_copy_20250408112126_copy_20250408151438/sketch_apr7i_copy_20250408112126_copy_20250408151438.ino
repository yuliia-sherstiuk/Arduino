const int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
// Augmenter la luminosité
  for (int brightness = 0; brightness <= 300; brightness++) {
    analogWrite(ledPin, brightness);
    delay(30);
  }

// Diminuer la luminosité
  for (int brightness = 300; brightness >= 0; brightness--) {
    analogWrite(ledPin, brightness);
    delay(5);
  }
}