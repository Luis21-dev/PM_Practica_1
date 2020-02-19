void setup()
{
DDRB = DDRB | B01111000; // Data Direction Register B: Inputs 0-6, Output 7
}

void loop()
{

asm (
"inicio: \n\t" 
"sbi 0x05,0x05 \n\t"
"sbi 0x05,0x04 \n\t"
"sbi 0x05,0x03 \n\t"
"sbi 0x05,0x06 \n\t"
"call tiempo \n\t"  //1/2 s
"cbi 0x05,0x05 \n\t"
"call tiempo \n\t"  // 1s
"sbi 0x05,0x05 \n\t"
"cbi 0x05,0x04 \n\t"
"call tiempo \n\t"  //1.5s
"cbi 0x05,0x05 \n\t"
"call tiempo \n\t" //2s
"sbi 0x05,0x05 \n\t"
"sbi 0x05,0x04 \n\t"
"cbi 0x05,0x06 \n\t"
"call tiempo \n\t" //2.5s
"cbi 0x05,0x05 \n\t"
"call tiempo \n\t" //3s
"sbi 0x05,0x05 \n\t"
"cbi 0x05,0x04 \n\t"
"call tiempo \n\t" //3.5s
"cbi 0x05,0x05 \n\t"
"call tiempo \n\t" //4s
"sbi 0x05,0x05 \n\t"
"sbi 0x05,0x04 \n\t"
"sbi 0x05,0x06 \n\t"
"cbi 0x05,0x03 \n\t"
"call tiempo \n\t" //4.5s
"cbi 0x05,0x05 \n\t"
"call tiempo \n\t" //5s
"sbi 0x05,0x05 \n\t"
"cbi 0x05,0x04 \n\t"
"call tiempo \n\t" //5.5s
"cbi 0x05,0x05 \n\t"
"call tiempo \n\t" //6s
"sbi 0x05,0x05 \n\t"
"sbi 0x05,0x04 \n\t"
"cbi 0x05,0x06 \n\t"
"call tiempo \n\t" //6.5s
"cbi 0x05,0x05 \n\t"
"call tiempo \n\t" //7s
"sbi 0x05,0x05 \n\t"
"cbi 0x05,0x04 \n\t"
"call tiempo \n\t" //7.5s
"cbi 0x05,0x05 \n\t"
"call tiempo \n\t" //8s
"sbi 0x05,0x05 \n\t"
"sbi 0x05,0x04 \n\t"
"sbi 0x05,0x06 \n\t"
"sbi 0x05,0x03 \n\t"
"jmp main \n\t"

"tiempo: \n\t"
"LDI r22, 19 \n\t"
"LOOP_3: \n\t"
"LDI r21, 255 \n\t"
"LOOP_2: \n\t"
"LDI r20, 255 \n\t"
"LOOP_1: \n\t"
"DEC r20 \n\t"
"BRNE LOOP_1 \n\t"
"DEC r21 \n\t"
"BRNE LOOP_2 \n\t"
"DEC r22 \n\t"
"BRNE LOOP_3 \n\t"
"ret \n\t"
);
}
