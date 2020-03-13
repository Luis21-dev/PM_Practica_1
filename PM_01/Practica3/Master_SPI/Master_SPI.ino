#include<SPI.h> //libreria

int S0 = 10;
int S1 = 11;
int accion[] = {0, 0};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(S0, INPUT);
  pinMode(S1, INPUT);
  SPI.begin();
  digitalWrite(SS, HIGH);
  SPI.setClockDivider(SPI_CLOCK_DIV8);
}

void loop() {
  // put your main code here, to run repeatedly:
  accion[0] = digitalRead(S0); //leer push button
  accion[1] = digitalRead(S1);
  Serial.print("Botones: \t");
  Serial.print(accion[1]);
  Serial.println(accion[0]);
  digitalWrite(SS, LOW); //activar slave
  SPI.transfer (accion[0]);
  SPI.transfer (accion[1]);
  SPI.transfer ("\n");
  digitalWrite(SS, HIGH); //desactivar slave
}
