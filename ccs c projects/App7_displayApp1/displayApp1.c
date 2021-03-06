
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#use fast_io(b)
#use fast_io(a)

const int digit[16] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7c, 0x07, 
                  0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};
const int digitAnod[16] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x83, 0xf8,
                     0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e};

signed int i;

void main()
{
   setup_psp(PSP_DISABLED);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED, 0, 1);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF);
   
   set_tris_a(0x00);
   set_tris_b(0x00);
   
   output_b(0x00);
   output_a(0x02);

   while(true){
      for(i = 10; i >= 0; i--){
         output_b(digit[i]);
         delay_ms(1000);
     }
   
   }
   
}
