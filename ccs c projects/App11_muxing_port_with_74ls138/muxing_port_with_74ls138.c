
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#use fast_io(b)

char i = 0;

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
   
   while(true){
      for(i = 0; i <= 7; i++){
          output_b(i | 0b00000000);
          delay_ms(250);
      }
      for(i = 0; i <= 7; i++){
          output_b(i | 0b00010000);
          delay_ms(250);
      }
      for(i = 0; i <= 7; i++){
          output_b(i | 0b00100000);
          delay_ms(250);
      }
      for(i = 0; i <= 7; i++){
          output_b(i | 0b00110000);
          delay_ms(250);
      }
   }
   
}











