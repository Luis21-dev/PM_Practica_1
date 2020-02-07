double lectura= A0;
double salida= 48;
double comparador= 0;
double pot=A11;
double lecPot=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(lectura,INPUT);
  pinMode(salida,OUTPUT);
  pinMode(pot,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  comparador=analogRead(lectura);
  lecPot=analogRead(pot);
  Serial.print("leido: ");
  Serial.print((comparador/1023)*100);
  Serial.print("\t potenciometro: ");
  Serial.print((lecPot/1023)*100);
  Serial.println();  
  if(comparador>lecPot){
    digitalWrite(salida,HIGH);
  }
  else{
    digitalWrite(salida,LOW);
  }
  delay(1000);
}
