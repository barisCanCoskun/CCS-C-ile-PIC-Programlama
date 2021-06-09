
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#use fast_io(a)
#use fast_io(b)

int kesme = 0;

#int_timer2
void timer2_interrupt()
{
   //set_timer1(60);
   kesme++;
    
   output_high(pin_b0);
   output_low(pin_b0);
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
   
   set_tris_a(0x01);
   set_tris_b(0x00);
   
   output_b(0x00);
   
   setup_timer_2(T2_DIV_BY_16, 250, 16);
   
   //set_timer2(5);
   
   enable_interrupts(int_timer2);
   enable_interrupts(GLOBAL);
   
   while(true){
      if(input(pin_a0))
         output_b(kesme);
   }
   
}











