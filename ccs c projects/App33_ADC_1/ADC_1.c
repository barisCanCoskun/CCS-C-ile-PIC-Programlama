
#include <16f877.h>

#device ADC = 10

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#use fast_io(c)
#use fast_io(e)

#define use_portb_lcd TRUE
#include <lcd.c>

#INT_AD
void ADC_Interrupt()
{
   output_high(pin_c5);
   delay_ms(200);
   output_low(pin_c5);
}

unsigned long int bilgi;
float voltaj;

void main()
{
   setup_psp(PSP_DISABLED);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED, 0, 1);
   //setup_adc_ports(NO_ANALOGS);
   //setup_adc(ADC_OFF);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF); 
   
   set_tris_c(0x00);
   set_tris_e(0x0F);
   
   output_c(0x00);
   
   setup_adc(adc_clock_div_32);
   setup_adc_ports(ALL_ANALOG);
   
   enable_interrupts(INT_AD);
   enable_interrupts(GLOBAL);
   
   lcd_init();
   
   printf(lcd_putc, "\f ADC UYGULAMASI ");
   delay_ms(1500);
   
   while(true){
      set_adc_channel(5);
      
      delay_us(20);
      
      bilgi = read_adc();
      
      voltaj = 0.0048828125 * bilgi;
      
      printf(lcd_putc, "\fAN5 Kanali");
      delay_ms(1500);
      printf(lcd_putc, "\fDijital = %lu", bilgi);
      
      printf(lcd_putc, "\nVoltaj = %fV", voltaj);
      
      delay_ms(2500);
      
      set_adc_channel(6);
      
      delay_us(20);
      
      bilgi = read_adc();
      
      voltaj = 0.0048828125 * bilgi;
      
      printf(lcd_putc, "\fAN6 Kanali");
      delay_ms(1500);
      printf(lcd_putc, "\fDijital = %lu", bilgi);
      
      printf(lcd_putc, "\nVoltaj = %fV", voltaj);
      
      delay_ms(2500);
      
      set_adc_channel(7);
      
      delay_us(20);
      
      bilgi = read_adc();
      
      voltaj = 0.0048828125 * bilgi;
      
      printf(lcd_putc, "\fAN7 Kanali");
      delay_ms(1500);
      printf(lcd_putc, "\fDijital = %lu", bilgi);
      
      printf(lcd_putc, "\nVoltaj = %fV", voltaj);
      
      delay_ms(2500);
   }
   
}











