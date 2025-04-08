const int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
// Augmenter la luminosité
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(ledPin, brightness);
    delay(10);
  }

// Diminuer la luminosité
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(ledPin, brightness);
    delay(10);
  }
}