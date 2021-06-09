
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#use fast_io(b)

#define use_portb_lcd TRUE

#include <lcd.c>

int x;
float y;
char z;

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
   
   lcd_init();
   
   x = 10;
   y = 32.6;
   
   while(true){
      lcd_send_byte(0, 0x0d);
      
      printf(lcd_putc, "\f    CCS C");
      delay_ms(1000);
      
      printf(lcd_putc, "\n   Derleyicisi");
      delay_ms(1000);
      
      lcd_gotoxy(1, 2);
      printf(lcd_putc, "\fX DEGERI = %d", x);
      delay_ms(1000);
      
      printf(lcd_putc, "\f\nY DEGERI = %f", y);
      delay_ms(1000);
      
      printf(lcd_putc, "\fDIRENC");
      delay_ms(1000);
      
      z = lcd_getc(3, 1);
      
      printf(lcd_putc, "\f%c", z);
      delay_ms(2000);
      
   }
}











