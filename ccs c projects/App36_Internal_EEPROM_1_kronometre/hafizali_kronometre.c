
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#use fast_io(a)

#define use_portb_lcd true
#include <lcd.c>

int8 _10ms = 0;
unsigned int8 saniye = 0;

#int_timer0
void timer0_interrupt()
{
   set_timer0(217);
   _10ms++;
   
   if(_10ms == 100){
      _10ms = 0;
      saniye++;
      if(saniye == 255)
         saniye = 0;
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
   
   set_tris_a(0x0F);
   
   lcd_init();
   
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_256);
   
   set_timer0(217);
   
   lcd_gotoxy(1, 1);
   printf(lcd_putc, "Sure=%03u.%02d", saniye, _10ms);
   
   lcd_gotoxy(1, 2);
   printf(lcd_putc, "Sonuc=%03u.%02d", read_eeprom(0), read_eeprom(1));
   
   while(true){
      if(input(pin_a3)){
         saniye = _10ms = 0;
         write_eeprom(0, saniye);
         
         write_eeprom(1, _10ms);
         
         lcd_gotoxy(1, 1);
         printf(lcd_putc, "Sure=%03u.%02d", saniye, _10ms);
         
         lcd_gotoxy(1, 2);
         printf(lcd_putc, "Sonuc=%03u.%02d", saniye, _10ms);
         
         while(input(pin_a3));
      }
      
      if(input(pin_a0)){
         while(!input(pin_a2)){
            enable_interrupts(INT_timer0);
            enable_interrupts(GLOBAL);
            
            lcd_gotoxy(1, 1);
            printf(lcd_putc, "Sure=%03u.%02d", saniye, _10ms);
            
            lcd_gotoxy(1, 2);
            printf(lcd_putc, "Sonuc=%03u.%02d", read_eeprom(0), read_eeprom(1));
            
            if(input(pin_a1)){
               write_eeprom(0, saniye);
         
               write_eeprom(1, _10ms);
               
               lcd_gotoxy(7, 2);
               printf(lcd_putc, "%03u.%02d", read_eeprom(0), read_eeprom(1));
               
               while(input(pin_a1));
            }
            
            lcd_gotoxy(6, 1);
            printf(lcd_putc, "%03u.%02d", saniye, _10ms);
         }
         
         disable_interrupts(GLOBAL);
      }
         
   }
   
}

   









