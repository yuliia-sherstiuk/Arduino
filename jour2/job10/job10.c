int brochePot = A0;       
int led1 = 9;             
int led2 = 10;            

void setup() {
  pinMode(led1, OUTPUT);  
  pinMode(led2, OUTPUT);  
}

void loop() {
  int valeurPot = analogRead(brochePot);         
  int luminosite1 = map(valeurPot, 0, 1023, 0, 255);    
  int luminosite2 = map(valeurPot, 0, 1023, 255, 0);    

  analogWrite(led1, luminosite1);  
  analogWrite(led2, luminosite2);  
}