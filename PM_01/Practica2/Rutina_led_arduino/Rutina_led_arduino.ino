int ledR = 11;
int ledA = 10;
int ledV = 12;
int ledR2 = 51;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledR, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledV, OUTPUT);
  pinMode(ledR2, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledR, HIGH); //0.5s
  digitalWrite(ledA, HIGH); //1.0s
  digitalWrite(ledV, HIGH); //2.0s
  digitalWrite(ledR2, HIGH);//4.0s
  
  delay(250);                //0.5s
  digitalWrite(ledR, LOW);
  delay(250);                //1.0s
  digitalWrite(ledR, HIGH);
  digitalWrite(ledA, LOW);
  delay(250);                //1.5s
  digitalWrite(ledR, LOW);
  delay(250);                //2.0s
  digitalWrite(ledR, HIGH);
  digitalWrite(ledA, HIGH);
  digitalWrite(ledV, LOW);
  delay(250);                //2.5s
  digitalWrite(ledR, LOW);
  delay(250);                //3.0s
  digitalWrite(ledR, HIGH);
  digitalWrite(ledA, LOW);
  delay(250);                //3.5s
  digitalWrite(ledR, LOW);
  delay(250);                //4.0s
  digitalWrite(ledR, HIGH);
  digitalWrite(ledA, HIGH);
  digitalWrite(ledV, HIGH);
  digitalWrite(ledR2, LOW);
  delay(250);                //4.5s
  digitalWrite(ledR, LOW);
  delay(250);                //5.0s
  digitalWrite(ledR, HIGH);
  digitalWrite(ledA, LOW);
  delay(250);                //5.5s
  digitalWrite(ledR, LOW);
  delay(250);                //6.0s
  digitalWrite(ledR, HIGH);
  digitalWrite(ledA, HIGH);
  digitalWrite(ledV, LOW);
  delay(250);                //6.5s
  digitalWrite(ledR, LOW);
  delay(250);                //7.0s
  digitalWrite(ledR, HIGH);
  digitalWrite(ledA, LOW);
  delay(250);                //7.5s
  digitalWrite(ledR, LOW);
  delay(250);                //8.0s

  
  


}
