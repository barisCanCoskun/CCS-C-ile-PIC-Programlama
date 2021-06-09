
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

//#define use_portb_lcd TRUE

#include <benim_LCD.c>

void main()
{
   setup_psp(PSP_DISABLED);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED, 0, 1);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF); 
   
   lcd_hazirla();
   
   while(true){
      imlec(1, 1);
      printf(lcd_veri, "Kendi LCD Dosya");
      delay_ms(1000);
      
      imlec(2, 4);
      printf(lcd_veri, "Denememiz");
      delay_ms(1000);
      
      lcd_komut(0x01);
      lcd_komut(0x0E);
      
      imlec(1, 6);
      printf(lcd_veri, "C"); delay_ms(1000);
      printf(lcd_veri, "C"); delay_ms(1000);
      printf(lcd_veri, "S"); delay_ms(1000);
      printf(lcd_veri, " C"); delay_ms(1000);
      
      
      lcd_komut(0x01);
   }
   
}











