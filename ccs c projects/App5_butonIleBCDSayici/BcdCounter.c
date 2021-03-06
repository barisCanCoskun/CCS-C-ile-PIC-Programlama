#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#use fast_io(b)
#use fast_io(a)

#define buton pin_A0

int i = 1;

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

   while(true){
      if(input(buton)){
         delay_ms(100);
         
         output_b(i);
         i++;
         
         while(input(buton));
         
         if(i == 10)
            i = 0;
      }
   
   }
   
}
