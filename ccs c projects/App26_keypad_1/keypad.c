
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#use fast_io(b)
#use fast_io(d)

#byte portb = 0x06

#define sut1 pin_d0
#define sut2 pin_d1
#define sut3 pin_d2
#define sut4 pin_d3

#define sat1 pin_d4
#define sat2 pin_d5
#define sat3 pin_d6
#define sat4 pin_d7

char tus = 0;

char keypad_read()
{
   output_d(0x00);
   
   output_high(sat1);
   if(input(sut1)){
      delay_ms(20);
      tus = 1;
   }
   if(input(sut2)){
      delay_ms(20);
      tus = 2;
   }
   if(input(sut3)){
      delay_ms(20);
      tus = 3;
   }
   if(input(sut4)){
      delay_ms(20);
      tus = 0xA;
   }
   output_low(sat1);
   
   output_high(sat2);
   if(input(sut1)){
      delay_ms(20);
      tus = 4;
   }
   if(input(sut2)){
      delay_ms(20);
      tus = 5;
   }
   if(input(sut3)){
      delay_ms(20);
      tus = 6;
   }
   if(input(sut4)){
      delay_ms(20);
      tus = 0xB;
   }
   output_low(sat2);
   
   output_high(sat3);
   if(input(sut1)){
      delay_ms(20);
      tus = 7;
   }
   if(input(sut2)){
      delay_ms(20);
      tus = 8;
   }
   if(input(sut3)){
      delay_ms(20);
      tus = 9;
   }
   if(input(sut4)){
      delay_ms(20);
      tus = 0xC;
   }
   output_low(sat3);
   
   output_high(sat4);
   if(input(sut1)){
      delay_ms(20);
      tus = 0xE;
   }
   if(input(sut2)){
      delay_ms(20);
      tus = 0;
   }
   if(input(sut3)){
      delay_ms(20);
      tus = 0xF;
   }
   if(input(sut4)){
      delay_ms(20);
      tus = 0xD;
   }
   output_low(sat4);
   
   return tus;
}

void main()
{
   setup_psp(PSP_DISABLED);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED, 0, 1);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF); 
   
   set_tris_b(0x00);
   set_tris_d(0x0f);
   
   output_b(0x00);
   
   while(true)
      portb = keypad_read();
   
}











