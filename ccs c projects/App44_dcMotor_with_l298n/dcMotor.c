
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#define buton_ileri pin_a0
#define buton_geri  pin_a1
#define buton_stop  pin_a2
#define input1       pin_b0
#define input2        pin_b1
#define enable_a    pin_b2
#define enable_b    pin_b3

void main()
{
   setup_psp(PSP_DISABLED);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED, 0, 1);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF);
   
   output_high(enable_a);
   output_low(enable_b);
   
   while(true){
      
      if(input(buton_ileri)){
         output_high(input1);
         output_low(input2);
      }
      
      if(input(buton_geri)){
         output_low(input1);
         output_high(input2);
      }
      
      if(input(buton_stop)){
         output_low(input1);
         output_low(input2);
      }
      
      /*if(input(buton_stop)){
         output_high(input1);
         output_high(input2);
      }*/
   }
   
}

   









