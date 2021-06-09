#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

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
   
   set_tris_b(0x00);
   
   output_b(0x00);

   basla:
   
   output_toggle(pin_b0);
   delay_ms(500);
   output_toggle(pin_b1);
   delay_ms(500);
   output_toggle(pin_b2);
   delay_ms(500);
   output_toggle(pin_b3);
   delay_ms(500);
   output_toggle(pin_b4);
   delay_ms(500);
   output_toggle(pin_b5);
   delay_ms(500);
   output_toggle(pin_b6);
   delay_ms(500);
   output_toggle(pin_b7);
   delay_ms(500);
   
   goto basla;
   
}
