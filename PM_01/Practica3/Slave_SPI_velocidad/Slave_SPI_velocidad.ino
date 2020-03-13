#include<SPI.h> //libreria

int INH1 = 5;
int INH2 = 6;
int ENA = 7;
int estado[]  = {0, 0};
byte pos;
int sentido = 0;
boolean received;
int vel = 0; //0%
int Slavereceived, Slavesend;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(INH1, OUTPUT);
  pinMode(INH2, OUTPUT);
  pinMode(ENA, OUTPUT);
  SPCR |= bit (SPE);
  pinMode(MISO, OUTPUT);
  SPI.attachInterrupt();
}
ISR (SPI_STC_vect)
{
  byte c = SPDR;
  int buf = 2;

  if (pos < 1) {
    estado[pos++] = c;
  }

  if (c == '\n') {
    received = true;
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  if (received) {
    if (( estado[1] == 0) && (estado[0] == 1)) { // aumentar en sentido horario 0 - 1
      if (sentido == 0) {
        if ((vel + 10) < 256) {
          vel = vel + 10;
        }
        else {
          vel = 255;
        }
      }
      if (sentido == 1) {
        if ((vel - 10) >= 0) {
          vel = vel - 10;
        }
        else {
          vel = abs(vel - 10);
          sentido = 0;
        }
      }
    }

    if (( estado[1] == 1) && (estado[0] == 0)) { // aumentar en sentido anti horario 1 - 0
      if (sentido == 0) {
        if ((vel - 10) >= 0 ) {
          vel = vel - 10;
        }
        else {
          vel = abs(vel - 10);
          sentido = 1;
        }
      }
      if (sentido == 1) {
        if ((vel + 10) < 256) {
          vel = vel + 10;
        }
        else {
          vel = 255;
        }
      }
    }

    if (sentido == 0) {  //girar horario
      digitalWrite(INH1, LOW);
      digitalWrite(INH2, HIGH);
    }
    if (sentido == 1) {  //girar anti horario
      digitalWrite(INH1, HIGH);
      digitalWrite(INH2, LOW);
    }

    analogWrite(ENA, vel);

    received = false;
  }
}
