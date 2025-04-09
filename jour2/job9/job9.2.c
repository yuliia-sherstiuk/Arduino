const int buttonPin = 2;
const int ledPin = 13;

unsigned long lastPressTime = 0;
unsigned long longPressDuration = 1000;
unsigned long clickWindow = 500;

int clickCount = 0;
bool ledOn = false;
bool blinking = false;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  static bool lastButtonState = false;
  static unsigned long buttonPressedTime = 0;

  bool currentState = digitalRead(buttonPin);

  
  if (currentState != lastButtonState) {
    delay(50); 
    lastButtonState = currentState;

    if (currentState == HIGH) {
     
      buttonPressedTime = millis();
    } else {
      
      unsigned long pressDuration = millis() - buttonPressedTime;

      if (pressDuration >= longPressDuration) {
        
        ledOn = false;
        blinking = false;
        digitalWrite(ledPin, LOW);
        clickCount = 0;
      } else {
        
        clickCount++;
        lastPressTime = millis();
      }
    }
  }

 
  if (clickCount > 0 && (millis() - lastPressTime > clickWindow)) {
    if (clickCount == 1) {
      ledOn = true;
      blinking = false;
    } else if (clickCount == 2) {
      ledOn = true;
      blinking = false;
    } else if (clickCount == 3) {
      blinking = true;
    }
    clickCount = 0;
  }

  
  if (blinking) {
    static unsigned long lastBlink = 0;
    static bool ledState = false;

    if (millis() - lastBlink >= 500) {
      ledState = !ledState;
      digitalWrite(ledPin, ledState ? HIGH : LOW);
      lastBlink = millis();
    }
  } else {
  
    digitalWrite(ledPin, ledOn ? HIGH : LOW);
  }
}