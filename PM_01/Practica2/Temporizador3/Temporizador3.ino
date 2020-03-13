int contador = 0;

void setup(){
  Serial.begin(9600);
  cli();
  TCCR1B = 0; TCCR1A = 0;
  TCCR1B |= (1 << CS12);
  TCNT1 = 3036; // 65536-(16MHz/(256/1Hz)) = 65536-(16000000/256) = 65536-62500 = 3036
  TIMSK1 |= (1 << TOIE1);
  sei();
  DDRB = DDRB | B11111100; 
  }
  ISR(TIMER1_OVF_vect){
    // Código a ejecutar al activarse la interrupción
    contador = (contador+1)%12;
    Serial.println(contador);
    }

void loop() {
  // put your main code here, to run repeatedly:
  if (contador == 0){
    asm(
      "sbi 0x05,0x02 \n\t"
      "sbi 0x05,0x07 \n\t"
      "cbi 0x05,0x06 \n\t"
      "cbi 0x05,0x04 \n\t"
      );
      
  }
  if (contador == 5){
    asm(
      "cbi 0x05,0x02 \n\t"
      "sbi 0x05,0x03 \n\t"
      );
  }
  if (contador == 6){
    asm(
      "cbi 0x05,0x03 \n\t"
      "sbi 0x05,0x04 \n\t"
      "sbi 0x05,0x05 \n\t"
      "cbi 0x05,0x07 \n\t"
      );
    
  }
  if (contador == 11){
    asm(
      "cbi 0x05,0x05 \n\t"
      "sbi 0x05,0x06 \n\t"
      );
  }
  

}
