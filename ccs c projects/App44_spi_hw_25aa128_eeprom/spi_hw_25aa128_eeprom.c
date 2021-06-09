
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#use rs232 (baud = 9600, xmit = pin_c6, rcv = pin_c7, parity = N, stop = 1)

#include<input.c>
#include<stdlib.h>

#define CS PIN_C2

int8 _adres[4], veri, adres_high, adres_low, i;
int16 adres;
char islem;

#int_ssp
void SPI_interrupt()
{
   output_high(pin_c0);
   delay_ms(250);
   output_low(pin_c0);
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
   
   setup_spi(spi_master | spi_L_to_H | spi_clk_div_4);
   
   enable_interrupts(int_ssp);
   enable_interrupts(global);
   
   printf("\n\r*************************");
   printf("\n\r  25AA128 Harici EEPROM Bilgi Okuma Yazma   ");
   printf("\n\r*************************");
   //printf("\n\n\r Bir islem seciniz>");
   
   OUTPUT_high(cs);
   
   while(true){
      do{
         printf("\n\n\r1-Belirtilen adresteki veriyi oku");
         printf("\n\r2-Belirtilen adresten itibaren sona kadar tum adresleri oku");
         printf("\n\r3-Belirtilen adrese istenen veriyi yaz");
         printf("\n\r4-Tum bellege ayni veriyi yaz");
         printf("\n\r5-Status register icerigini oku");
         printf("\n\r6-Status register icerigine yaz");
         printf("\n\rBir islem seciniz(1, 2, 3, 4, 5, 6) >");
         
         islem = getc();
         putc(islem);
      }while((islem != '1') && (islem != '2') && (islem != '3') && (islem != '4') && (islem != '5') && (islem != '6'));
      
      if(islem == '1'){
         printf("\n\rOkumak istediginiz adresi giriniz> ");
         get_string(_adres, 4);
         
         adres = atol(_adres);
         
         adres_high = make8(adres, 1);
         adres_low = make8(adres, 0);
         
         printf("\n\rVeri okunuyor...");
         
         output_low(cs);
         spi_write(0x03);
         delay_ms(5);
         spi_write(adres_high);
         
         delay_ms(5);
         spi_write(adres_low);
         
         delay_ms(5);
         printf("\n\rAdres = %04lu  Deger = 0x%02X", adres, spi_read(0));
         
         output_high(cs);
         delay_ms(5);
      }
      // Belirtilen adresten itibaren sona kadar tüm adresleri oku
      if(islem == '2'){
         printf("\n\rOkumaya baslamak istediginiz adresi giriniz> ");
         get_string(_adres, 4);
         
         adres = atol(_adres);
         
         adres_high = make8(adres, 1);
         adres_low = make8(adres, 0);
         
         printf("\n\rVeriler okunuyor...");
         
         output_low(cs);
         spi_write(0x03);
         delay_ms(5);
         spi_write(adres_high);
         
         delay_ms(5);
         spi_write(adres_low);
         
         delay_ms(5);
         
         for(; adres <= 0x3FFF; adres++){
            printf("\n\rAdres = %04lu   Deger = 0x%02X", adres, spi_read(0));
            delay_ms(5);
       }
         
         output_high(cs);
         delay_ms(5);
      }
      
      if(islem == '3'){
         printf("\n\rBilgi yazmak istediginiz adresi giriniz> ");
         get_string(_adres, 4);
         
         adres = atol(_adres);
         
         adres_high = make8(adres, 1);
         adres_low = make8(adres, 0);
         
         printf("\n\rBilgiyi giriniz> ");
         veri = gethex();
         printf("\n\rVeri yaziliyor...");
         
         output_low(cs);
         spi_write(0x06); //WREN
         delay_ms(5);
         output_high(cs);
         
         output_low(cs);
         spi_write(0x02); 
         
       delay_ms(5);
         spi_write(adres_high);
         
         delay_ms(5);
         spi_write(adres_low);
         
         delay_ms(5);
         spi_write(veri);
         
         delay_ms(5);
         output_high(cs);
         delay_ms(5);
         printf("\n\rYazma islemi bitti.");
      }
      //Tum bellege ayni veriyi yaz
      if(islem == '4'){
         
       disable_interrupts(global);
         printf("\n\rBilgiyi giriniz(girilen bilgi tum bellege yazilacak)> ");
         veri = gethex();
         
         printf("\n\rVeri yaziliyor...");
         
         for(adres = 0; adres <= 16384; adres += 64){
            adres_high = make8(adres, 1);
            adres_low = make8(adres, 0);
            
            output_low(cs);
            spi_write(0x06);
            delay_ms(5);
            output_high(cs);
            delay_ms(5);
            
            output_low(cs);
            spi_write(0x02);
            delay_ms(5);
            spi_write(adres_high);
            
            delay_ms(5);
            spi_write(adres_low);
            
            delay_ms(5);
            
            for(i = 0; i <= 64; i++){
               spi_write(veri);
               
               delay_ms(5);
          }
            
            output_high(cs);
            delay_ms(5);
       }
       printf("\n\rYazma islemi bitti.");
       enable_interrupts(global);
         
      }
      //status register oku
      if(islem == '5'){
         
         output_low(cs);
         spi_write(0x06);
         delay_ms(5);
         output_high(cs);
         
         output_low(cs);
         spi_write(0x05); //RDSR
         delay_ms(5);
         printf("\n\rStatus Register Deger = 0x%02X", spi_read(0));
         
         output_high(cs);
         delay_ms(5);
      }
      
      //status registera yaz
      if(islem == '6'){
         
         printf("\n\rStatus Register' a veriyi giriniz> ");
         veri = gethex();
         printf("\n\rStatus Register' a veri yaziliyor...");
         
         output_low(cs);
         spi_write(0x06); //WREN
         delay_ms(5);
         output_high(cs);
         
         output_low(cs);
         spi_write(0x01); //WRSR
         delay_ms(5);
         
         spi_write(veri); 
         delay_ms(5);
         
         output_high(cs);
         printf("\n\rYazma islemi bitti.");
      }
   }
   
}

   









