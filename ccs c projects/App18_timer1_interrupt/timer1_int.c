
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#use fast_io(b)

char i = 0;

#int_timer1
void timer1_interrupt()
{
   set_timer1(63036);
   i++;
   
   if(i == 50)
      output_high(pin_b0);
   
   if(i == 100){
      output_low(pin_b0);
      i = 0;
   }
   
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
   output_b(0x00);
   
   setup_timer_1(T1_INTERNAL | T1_DIV_BY_8);
   
   set_timer1(63036);
   
   enable_interrupts(int_timer1);
   enable_interrupts(GLOBAL);
   
   while(true);
   
}











