
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#use fast_io(a)

#define use_portb_lcd true
#include <lcd.c>

int16 adres = 0, deger = 0;

void main()
{
   setup_psp(PSP_DISABLED);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED, 0, 1);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF);
   
   set_tris_a(0x01);
   
   lcd_init();
   
   printf(lcd_putc, "\fProgram Kodlari");
   delay_ms(1000);
   
   printf(lcd_putc, "\fAdres      Kod");
   
   while(!(adres == 0x3FFF)){
      deger = read_program_eeprom(adres);
      
      lcd_gotoxy(1, 2);
      printf(lcd_putc, "%lx      %lx", adres, deger);
      
      delay_ms(500);
      adres++;
      
      if(input(pin_a0)){
         delay_ms(20);
         write_program_eeprom(adres, 0x0000);
      }
   }
   
   printf(lcd_putc, "\fProgram Bitti...");
}

   









