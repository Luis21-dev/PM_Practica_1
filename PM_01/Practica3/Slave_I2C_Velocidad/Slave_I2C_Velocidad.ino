#include <Wire.h> //libreria

//Boton derecho - horario
//Boton izquierdo - anti horario 

int INH1 = 9;
int INH2 = 8;
int ENA = 3;
int vel = 0; //0%
int sentido = 0;

void setup() {
  Serial.begin(9600);
  pinMode(INH1, OUTPUT);
  pinMode(INH2, OUTPUT);
  pinMode(ENA, OUTPUT);
  Wire.begin(1);
  Wire.onReceive(receiveEvent);
}

void loop() {

}

void receiveEvent(int combinacion) {

  int estado[]  = {0, 0};

  if (Wire.available() == 2) { //2 bits enviados
    estado[0] = Wire.read();  //1er bit
  }

  if (Wire.available() == 1) { //2do bit
    estado[1] = Wire.read();
  }
  
  if (( estado[1] == 0) && (estado[0] == 1)) { // aumentar en sentido horario 0 - 1
    if (sentido == 0){
      if ((vel+10) <256){
        vel = vel +10;
      }
      else{
        vel = 255;
      }
    }
    if (sentido ==1){
      if ((vel-10) >= 0){
        vel = vel -10;
      }
      else{
        vel = abs(vel-10);
        sentido = 0;
      }
    }
  }

    if (( estado[1] == 1) && (estado[0] == 0)) { // aumentar en sentido anti horario 1 - 0
    if (sentido == 0){
      if ((vel-10)>= 0 ){
        vel = vel -10;
      }
      else{
        vel = abs(vel-10);
        sentido = 1;
      }
    }
    if (sentido == 1){
      if ((vel+10) < 256){
        vel = vel + 10;
      }
      else{
        vel = 255;
      }
    }
  }
  
  if (sentido == 0){   //girar horario
    digitalWrite(INH1, HIGH);
    digitalWrite(INH2, LOW);
  }
  if (sentido == 1){   //girar anti horario
    digitalWrite(INH1, LOW);
    digitalWrite(INH2, HIGH);
  }

  analogWrite(ENA, vel);
   Serial.println(vel);
}
