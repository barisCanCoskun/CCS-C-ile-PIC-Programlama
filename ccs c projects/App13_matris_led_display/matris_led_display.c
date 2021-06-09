
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#use fast_io(b)
#use fast_io(c)

int A[] = {0x1F, 0x28, 0x48, 0x28, 0x1F};
int B[] = {0xFF, 0x49, 0x49, 0x49, 0x36};
int C[] = {0x3E, 0x41, 0x41, 0x41, 0x22};
int D[] = {0xFF, 0x41, 0x41, 0x41, 0x3E};
int E[] = {0xFF, 0xC9, 0xC9, 0xC9, 0x41};
int arti[] = {0x08, 0x08, 0x3E, 0x08, 0x08};
int cift_ok[] = {0x14, 0x22, 0xFF, 0x22, 0x14};

int sutunSec(char s)
{
   switch(s){
      case 0:
         return (0x01);
      case 1:
         return (0x02);
      case 2:
         return (0x04);
      case 3:
         return (0x08);
      case 4:
         return (0x10);
   }
}

void matris_karakter_gonder(char harf[], int tekrar)
{
   int  i, j, k;
   
   for(i = 1; i <= tekrar; i++)
      
      for(k = 1; k <= 10; k++)
         
         for(j = 0; j <= 4; j++){
            output_c(sutunSec(j));
            output_b(harf[j]);
            
            delay_ms(1);
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
   
   set_tris_b(0x00);
   set_tris_c(0x00);

   while(true){
      matris_karakter_gonder(A, 20);
      matris_karakter_gonder(B, 20);
      matris_karakter_gonder(C, 20);
      matris_karakter_gonder(D, 20);
      matris_karakter_gonder(E, 20);
      matris_karakter_gonder(arti, 20);
      matris_karakter_gonder(cift_ok, 20);
   }
   
}











