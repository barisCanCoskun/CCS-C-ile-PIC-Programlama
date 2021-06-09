
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#use fast_io(b)

char i;

#int_ext
void ext_kesmesi()
{
   output_high(pin_b1);
   delay_ms(1000);
   output_low(pin_b1);
   delay_ms(3000);
   
   for(i = 0; i <= 9; i++){
      output_high(pin_b1);
      delay_ms(500);
      output_low(pin_b1);
      delay_ms(500);
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
   
   set_tris_b(0x01);
   output_b(0x00);
   
   ext_int_edge(H_TO_L);
   
   enable_interrupts(INT_EXT);
   enable_interrupts(GLOBAL);
   
   while(true);
   
}











