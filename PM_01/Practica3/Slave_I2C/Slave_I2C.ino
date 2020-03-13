#include <Wire.h> //libreria

int INH1 = 9;
int INH2 = 8;
int ENA = 3;
int vel = 250; 

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

  int estado[]  = {0, 0};

  if (Wire.available() == 2) { //2 bits enviados
    estado[0] = Wire.read();  //1er bit
    Serial.print("Combinaciòn: ");
    Serial.print(estado[0]);
  }

  if (Wire.available() == 1) { //2do bit
    estado[1] = Wire.read();
    Serial.println(estado[1]);
  }

  if (( estado[1] == 0) && (estado[0] == 0)) { // paro lento
    digitalWrite(INH1, LOW);
    digitalWrite(INH2, LOW);
  }
  if (( estado[1] == 1) && (estado[0] == 0)) { // horario
    digitalWrite(INH1, LOW);
    digitalWrite(INH2, HIGH);
  }
  if (( estado[1] == 0) && (estado[0] == 1)) { // anti horario
    digitalWrite(INH1, HIGH);
    digitalWrite(INH2, LOW);
  }
  if (( estado[1] == 1) && (estado[0] == 1)) { // paro abrupto
    digitalWrite(INH1, HIGH);
    digitalWrite(INH2, HIGH);
  }
  analogWrite(ENA, vel);
}
