#include <Wire.h> //libreria

int S0 = 10;
int S1 = 11;
int accion[] = {0, 0};

void setup() {
  // put your setup code here, to run once:
  Wire.begin(1);
  pinMode(S0,INPUT);
  pinMode(S1, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(1); //iniciar transmision
  accion[0] = digitalRead(S0); //leer push button
  accion[1] = digitalRead(S1);
  Serial.print("Botones: \t");
  Serial.print(accion[1]);
  Serial.println(accion[0]);
  Wire.write(accion[1]);  //enviamos las acciones
  Wire.write(accion[0]);
  Wire.endTransmission();  //terminamos la transmision
}
