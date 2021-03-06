
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#define use_portb_lcd true
#include <lcd.c>

#use rs232 (baud = 9600, xmit = pin_C6, rcv = pin_C7, parity = N, stop = 1)

char klavye[80];
char satir2[50];

#int_rda
void serialCommunication_interrupt()
{
   disable_interrupts(int_rda);
   output_high(pin_c5);
   
   gets(klavye);
   
   printf("\n\rYazdiginiz Metin>   %s\n", klavye);
   
   printf(lcd_putc, "\f%s", klavye);
   
   gets(satir2);
   
   printf("\n\rYazdiginiz 2. Metin>   %s\n", satir2);
   lcd_gotoxy(1, 2);
   printf(lcd_putc, "%s", satir2);
   
   output_low(pin_c5);
   
   printf("\n\rKlavyeden bir metin giriniz ve enter tusuna basiniz>");
   
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
   
   output_low(pin_c5);
   lcd_init();
   
   printf("\r**********  Merhaba  *********");
   
   printf("\n\rKlavyeden girdišiniz bilgiler LCD' de gorunecektir\n\n");
   
   printf("\n\rKlavyeden bir metin giriniz ve enter tusuna basiniz>");
   
   enable_interrupts(global);
   
   while(true){
      enable_interrupts(int_rda);
   }
   
}

   









