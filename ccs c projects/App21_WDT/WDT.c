
#include <16f877.h>

#fuses XT, WDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#use fast_io(a)
#use fast_io(b)

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
   
   setup_wdt(wdt_2304ms);
   
   while(true){
      output_toggle(pin_b0);
      
      while(input(pin_a0))
         restart_wdt();
      
      sleep();
   }
   
}











