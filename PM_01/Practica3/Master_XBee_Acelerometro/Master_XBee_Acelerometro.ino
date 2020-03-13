//#include <SoftwareSerial.h> //libreria

//SoftwareSerial XBee(2, 3);

int posicion = 0;
int ejeX = A5;
int vel = 0;
int estado = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //XBee.begin(9600);
  pinMode(ejeX,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  posicion = analogRead(ejeX);
  
  delay(100);

  if (posicion <335) { 
    //estado = 1;
    Serial.write('D');
    vel = map(posicion, 335, 269, 0, 255);
    
  }
 
  if (posicion > 336){
    //estado = 0;
    Serial.write('I');
    vel = map(posicion, 336, 404, 0, 255);
  }
  
  Serial.write(vel);
  //XBee.write(vel);
  //XBee.write(estado);
  
  
  //Serial.write(vel);
  //Serial.write(estado);

  Serial.print(posicion);
  Serial.print(" ");
  Serial.print(vel);
  Serial.print(" ");
  Serial.println(estado);
}
