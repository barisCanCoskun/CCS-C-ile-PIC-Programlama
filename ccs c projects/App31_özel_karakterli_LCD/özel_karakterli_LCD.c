
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

//#define use_portb_lcd TRUE

#include<ozel_karakter_LCD.c>

float x = 23.5;

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
   ozel_karakterler();
   
   while(true){
      imlec(1, 1);
      printf(lcd_veri, "?ZEL KARAKTERL?");
      
      imlec(2, 1);
      printf(lcd_veri, "LCD UYGULAMASI");
      delay_ms(1000);
      
      lcd_komut(0x01);
      
      printf(lcd_veri, "?ZEL KARAKTERLER");
      imlec(2, 1);
      printf(lcd_veri, "?"); delay_ms(1000);
      printf(lcd_veri, "?"); delay_ms(1000);
      printf(lcd_veri, "?"); delay_ms(1000);
      printf(lcd_veri, "?"); delay_ms(1000);
      printf(lcd_veri, "?"); delay_ms(1000);
      printf(lcd_veri, "?"); delay_ms(1000);
      printf(lcd_veri, "?"); delay_ms(1000);
      printf(lcd_veri, "I"); delay_ms(1000);
      
      lcd_komut(0x01);
      printf(lcd_veri, "SICAKLIK %f?C", x); 
     delay_ms(3000);
      lcd_komut(0x01);
   }
   
}











