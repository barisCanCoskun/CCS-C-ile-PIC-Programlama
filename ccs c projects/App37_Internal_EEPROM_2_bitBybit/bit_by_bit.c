
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#use fast_io(a)

#define use_portb_lcd true
#include <lcd.c>

#include <math.h>

int16 i;
unsigned int8 eeprom_adres, data[1] = {0};

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
   
   lcd_init();
   
   printf(lcd_putc, "\fEEPROM Adres=");
   
   lcd_gotoxy(1, 2);
   printf(lcd_putc, "EEPROM Veri =");
   
   while(true){
      
      for(i = 0; i <= 2047; i++){
         while(!input(PIN_A0));
         delay_ms(40);
         
         shift_left(data, 1, input(PIN_A1));
         
         eeprom_adres = floor(i / 8);
         write_eeprom(eeprom_adres, data[0]);
         
         lcd_gotoxy(14, 1);
         printf(lcd_putc, "%3u", eeprom_adres);
         
         lcd_gotoxy(14, 2);
         printf(lcd_putc, "%x", read_eeprom(eeprom_adres));
         
         while(input(PIN_A0));
      }
   }
   
}

   









