int ledV = 11;
int ledA = 10;
int ledR = 12;
int ledV2 = 50;


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
  
  delay(500)                //0.5s
  digitalWrite(ledR, LOW);
  delay(500)                //1.0s
  digitalWrite(ledR, HIGH);
  digitalWrite(ledA, LOW);
  delay(500)                //1.5s
  digitalWrite(ledR, LOW);
  delay(500)                //2.0s
  digitalWrite(ledR, HIGH);
  digitalWrite(ledA, HIGH);
  digitalWrite(ledV, LOW);
  delay(500)                //2.5s
  digitalWrite(ledR, LOW);
  delay(500)                //3.0s
  digitalWrite(ledR, HIGH);
  digitalWrite(ledA, LOW);
  delay(500)                //3.5s
  digitalWrite(ledR, LOW);
  delay(500)                //4.0s
  digitalWrite(ledR, HIGH);
  digitalWrite(ledA, HIGH);
  digitalWrite(ledV, HIGH);
  digitalWrite(ledR2, LOW);
  delay(500)                //4.5s
  digitalWrite(ledR, LOW);
  delay(500)                //5.0s
  digitalWrite(ledR, HIGH);
  digitalWrite(ledA, LOW);
  delay(500)                //5.5s
  digitalWrite(ledR, LOW);
  delay(500)                //6.0s
  digitalWrite(ledR, HIGH);
  digitalWrite(ledA, HIGH);
  digitalWrite(ledV, LOW);
  delay(500)                //6.5s
  digitalWrite(ledR, LOW);
  delay(500)                //7.0s
  digitalWrite(ledR, HIGH);
  digitalWrite(ledA, LOW);
  delay(500)                //7.5s
  digitalWrite(ledR, LOW);
  delay(500)                //8.0s

  
  


}
