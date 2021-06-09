
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#use fast_io(a)
#use fast_io(b)

#define arttir pin_a0
#define azalt pin_a1
#define buton pin_a2

char birler = 0, onlar = 0, sayi = 0;

const int digit[10] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 
                       0x08, 0x09};

void main()
{
   setup_psp(PSP_DISABLED);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED, 0, 1);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF);
   
   set_tris_a(0x03);
   set_tris_b(0x00);

   while(true){
      output_b(digit[birler] | (0b00010000));
      delay_ms(5);
      
      output_b(digit[onlar] | (0b00100000));
      delay_ms(5);
      
      if(input(arttir)){
         sayi++;
         
         birler = sayi % 10;
         onlar = sayi / 10;
         
         while(input(arttir)){
            output_b(digit[birler] | (0b00010000));
            delay_ms(5);
      
            output_b(digit[onlar] | (0b00100000));
            delay_ms(5);
         }
      }
      
      if(input(azalt) && sayi != 0){
         sayi--;
         
         birler = sayi % 10;
         onlar = sayi / 10;
         
         while(input(azalt)){
            output_b(digit[birler] | (0b00010000));
            delay_ms(5);
      
            output_b(digit[onlar] | (0b00100000));
            delay_ms(5);
         }
      }
      
      if(sayi == 100)
         sayi = 0;
   }
   
}











