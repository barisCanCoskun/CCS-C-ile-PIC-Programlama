
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#use fast_io(b)
#use fast_io(a)

#define display1 pin_a0
#define display2 pin_a1
#define buton pin_a2

char birler = 0, onlar = 0, sayi = 0;

const int digit[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7c, 0x07, 
                       0x7f, 0x6f};

void main()
{
   setup_psp(PSP_DISABLED);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED, 0, 1);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF);
   
   set_tris_a(0xfc);
   set_tris_b(0x00);
   
   output_low(display1);
   output_low(display2);

   while(true){
      birler = sayi % 10;
      onlar = sayi / 10;
      
      output_high(display2);
      output_b(digit[birler]);
      delay_ms(25);
      output_low(display2);
      output_high(display1);
      output_b(digit[onlar]);
      delay_ms(25);
      output_low(display1);
      
      if(input(buton)){
         delay_ms(10);
         
         sayi++;
         
         if(sayi == 100)
            sayi = 0;
         
         birler = sayi % 10;
         onlar = sayi / 10;  
           
         while(input(buton)){
            output_high(display2);
            output_b(digit[birler]);
            delay_ms(5);
            output_low(display2);
            output_high(display1);
            output_b(digit[onlar]);
            delay_ms(5);
            output_low(display1);
         }
         
      }
      
   }
   
}











