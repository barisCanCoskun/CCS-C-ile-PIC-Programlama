
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#use fast_io(b)

#define data pin_b0
#define clock pin_b1

int digit[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x83, 0xF8, 0x80, 0x90};

char i = 0, j = 0;

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
   
   while(true){
      for(i = 0; i <= 9; i++){
      	for(j = 0; j <= 7; j++){
      		output_bit(data, bit_test(digit[i], j));
      		
      		output_high(clock);
      		output_low(clock);
		  }
		delay_ms(500);
	  }
   }
   
}











