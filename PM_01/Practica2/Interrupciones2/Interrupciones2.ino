//led
int led
long iBlink = 1000;
long timerBlink = millis();
int eLed = HIGH;

int led2

//Boton
int interruptor = 
long iButton = 100;
long timerButton = millis();

//contador
int contador = 0;

//Boton
int button



void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(interruptor,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if ( (millis() - timerButton) > iButton){
    int eButton = digitalRead(interruptor);
    Serial.print(eButton);
    if (eButton == 0) {
      cli();
      DDRD &= ~(1 << DDD1);
      PORTD |= (1 << PORTD1);
      EICRA |= (1 << ISC10);
      EIMSK |= (1 << INT1);
      sei();
      }
      ISR(INT1_vect)
      {
        digitalWrite(led2,HIGH);
        delay(1000);
        digitalWrite(led2,LOW);
        }
      timerButton = millis();
  }
  if ( (millis() - timerLed) > iBlink){
    blinkLed();
  }
}

void blinkLed(){
  if (eLed == LOW){
    eLed = HIGH;
  }
  else {
    eLed = LOW;
  }
  timerButton = millis();
  digitalWrite(led,eLed);
}
