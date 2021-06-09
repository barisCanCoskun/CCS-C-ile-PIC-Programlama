
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#use standard_io(a)
#use standard_io(b)

char data;

void _8255_yazma (char x, char bilgi)
{
   switch(x){
      case 'k':
         output_a(0b00001101);
         output_b(bilgi);
         break;
      
      case 'a':
         output_a(0b00000001);
         output_b(bilgi);
         break;
      
      case 'b':
         output_a(0b00000101);
         output_b(bilgi);
         break;
      
      case 'c':
         output_a(0b00001001);
         output_b(bilgi);
         break;
      
      default:
         break;
   }
}

char _8255_okuma (char x)
{
   switch(x){
      case 'k':
         output_a(0b00001110);
         return (input_b());
      
      case 'a':
         output_a(0b00000010);
         return (input_b());
      
      case 'b':
         output_a(0b00000110);
         return (input_b());
      
      case 'c':
         output_a(0b00001010);
         return (input_b());
      
      default:
         break;
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
   
   _8255_yazma('k', 0b10001001);
   _8255_yazma('a', 0x00);
   
   while(true){
      data = _8255_okuma('c');
      _8255_yazma('a', data);
   }
   
}











