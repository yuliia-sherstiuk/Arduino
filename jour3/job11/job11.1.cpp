const int bouton = 2; 
const int led = 8;
const int moteur = 9;  

bool ledAllumee = false;
bool moteurAllume = false;
unsigned long tempsDebut = 0;

void setup() {
  pinMode(bouton, INPUT);
  pinMode(led, OUTPUT);
  pinMode(moteur, OUTPUT);
}

void loop() {
  if (digitalRead(bouton) == HIGH) {
    delay(200); // Anti-rebond

    if (!ledAllumee && !moteurAllume) {
      digitalWrite(led, HIGH);
      ledAllumee = true;
      tempsDebut = millis();
    } 
    else if (moteurAllume) {
      digitalWrite(moteur, LOW);
      moteurAllume = false;
    }
  }

  
  if (ledAllumee && millis() - tempsDebut >= 15000) {
    digitalWrite(led, LOW);
    ledAllumee = false;
    digitalWrite(moteur, HIGH);
    moteurAllume = true;
  }
}