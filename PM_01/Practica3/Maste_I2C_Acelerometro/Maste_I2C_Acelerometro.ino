#include <Wire.h> //libreria

int posicion = 0;
int ejeX = A7;
int vel = 0;
int estado = 0;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(1);
  pinMode(ejeX,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(1); //iniciar transmision
  posicion = analogRead(ejeX);

  
  delay(100);

  if (posicion <335) { 
    estado = 1;
    vel = map(posicion, 335, 269, 0, 255);
  }
 
  if (posicion > 336){
    estado = 0;
    vel = map(posicion, 336, 404, 0, 255);
  }
  
  Wire.write(vel);
  Wire.write(estado);
  
  Serial.print(posicion);
  Serial.print(" ");
  
  Serial.println(vel);
  
  Wire.endTransmission();  //terminamos la transmision
}
