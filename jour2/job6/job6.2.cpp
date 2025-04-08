const int led1 = 2;
const int led2 = 3;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  digitalWrite(led1, HIGH);
  delay(300);
  digitalWrite(led1, LOW);
  delay(300);

  digitalWrite(led2, HIGH);
  delay(700);
  digitalWrite(led2, LOW);
  delay(700);
}
