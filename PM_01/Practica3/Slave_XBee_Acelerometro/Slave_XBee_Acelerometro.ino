//#include <SoftwareSerial.h> //libreria

//SoftwareSerial XBee(2, 3);

int INH1 = 9;
int INH2 = 8;
int ENA = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //XBee.begin(9600);
  pinMode(INH1, OUTPUT);
  pinMode(INH2, OUTPUT);
  pinMode(ENA, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
}

void receiveEvent(int combinacion) {

  int vel = 0;
  int estado = 0;
  //vel = XBee.read();
  //estado = XBee.read();

  
  //if (XBee.available()) { //2do bit
  if (Serial.available()){
    if(Serial.read() == 'D'){
      estado = 1;
    }
    else{
      estado = 0;
    }    
  }
   if (Serial.available()){
    vel = int(Serial.read());
  }
  
  //if (XBee.available()) { //2do bit
   
  //}

  if ( estado == 1) {
    
    digitalWrite(INH1, LOW);
    digitalWrite(INH2, HIGH);
  }

  if (estado == 0){
    digitalWrite(INH1, HIGH);
    digitalWrite(INH2, LOW);
  }
  analogWrite(ENA, vel);

  
  Serial.print(estado);
  Serial.print(" ");
  Serial.println(vel);
}
