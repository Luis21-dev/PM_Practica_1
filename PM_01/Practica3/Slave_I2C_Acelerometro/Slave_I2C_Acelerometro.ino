#include <Wire.h> //libreria

int INH1 = 9;
int INH2 = 8;
int ENA = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(INH1, OUTPUT);
  pinMode(INH2, OUTPUT);
  pinMode(ENA, OUTPUT);
  Wire.begin(1);
  Wire.onReceive(receiveEvent);
}

void loop() {
  // put your main code here, to run repeatedly:
}

void receiveEvent(int combinacion) {

  int vel = 0;
  int estado = 0;
  
  if (Wire.available() == 2) { //2do bit
    vel = Wire.read();
    Serial.print(estado);
  }
  if (Wire.available() == 1) { //2do bit
    estado = Wire.read();
    Serial.print(" ");
    Serial.println(vel);
  }

  if ( estado == 1) {
    
    digitalWrite(INH1, LOW);
    digitalWrite(INH2, HIGH);
  }

  if (estado == 0){
    digitalWrite(INH1, HIGH);
    digitalWrite(INH2, LOW);
  }
  analogWrite(ENA, vel);
}
