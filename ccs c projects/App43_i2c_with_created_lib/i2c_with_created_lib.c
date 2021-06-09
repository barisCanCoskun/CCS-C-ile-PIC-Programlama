
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#use rs232 (baud = 9600, xmit = pin_c6, rcv = pin_c7, parity = N, stop = 1)

#use i2c(master, sda = pin_c4, scl = pin_c3, fast = 400000)

#include <kendi_input.c>
#include <kendi_2402.c>

byte veri, adres;
char islem;

void main()
{
   setup_psp(PSP_DISABLED);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED, 0, 1);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF);
   
   printf("\n\r*************************");
   printf("\n\r  24c02c Harici EEPROM Bilgi Okuma Yazma   ");
   printf("\n\r*************************");
   printf("\n\n\r Bir islem seciniz>");
   
   while(true){
      do{
         printf("\n\rOkuma (O) veya yazma (y) >");
         islem = getc();
         islem = toupper(islem);
         
         putc(islem);
      }while((islem != 'O') && (islem != 'Y'));
      
      if(islem == 'O'){
         printf("\n\rOkumak istediginiz adresi giriniz> ");
         adres = hex_oku2();
         
         printf("\n\rDeger = %X", eeprom_oku(adres));
      }
      
      if(islem == 'Y'){
         printf("\n\rBilgi yazmak istediginiz adresi giriniz> ");
         adres = hex_oku2();
         
         printf("\n\rBilgiyi giriniz> ");
         veri = hex_oku2();
         
         eeprom_yaz(adres, veri);
      }
      
   }
   
}

   









