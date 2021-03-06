
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#use fast_io(b)
#use fast_io(c)

int S[] = {0xF9, 0xC9, 0xC9, 0xC9, 0x4F};
int E[] = {0xFF, 0xC9, 0xC9, 0xC9, 0x41};
int N[] = {0x1F, 0x08, 0x04, 0x02, 0x1F};
int i[] = {0x00, 0x00, 0x5F, 0x00, 0x00};
int V[] = {0x1C, 0x02, 0x01, 0x02, 0x1C};
int Y[] = {0x40, 0x20, 0x1F, 0x20, 0x40};
int O[] = {0xFF, 0x41, 0x41, 0x41, 0xFF};
int R[] = {0xFF, 0x4C, 0x4A, 0x79, 0x00};
int U[] = {0xFF, 0x01, 0x01, 0x01, 0xFF};
int M[] = {0x1F, 0x08, 0x04, 0x08, 0x1F};
int K[] = {0xFF, 0x08, 0x14, 0x42, 0x81};

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
      matris_karakter_gonder(S, 20);
      matris_karakter_gonder(E, 20);
      matris_karakter_gonder(N, 20);
      matris_karakter_gonder(i, 20);
      matris_karakter_gonder(S, 20);
      matris_karakter_gonder(E, 20);
      matris_karakter_gonder(V, 20);
      matris_karakter_gonder(i, 20);
      matris_karakter_gonder(Y, 20);
      matris_karakter_gonder(O, 20);
      matris_karakter_gonder(R, 20);
      matris_karakter_gonder(U, 20);
      matris_karakter_gonder(M, 20);
      output_b(0x00);
      delay_ms(200);
       matris_karakter_gonder(M, 20);
      output_b(0x00);
      delay_ms(200);
      matris_karakter_gonder(M, 20);
      output_b(0x00);
      delay_ms(1000);
      matris_karakter_gonder(M, 20);
      matris_karakter_gonder(i, 20);
      matris_karakter_gonder(N, 20);
      output_b(0x00);
      delay_ms(300);
      matris_karakter_gonder(N, 20);
      matris_karakter_gonder(O, 20);
      matris_karakter_gonder(S, 20);
      matris_karakter_gonder(K, 20);
   }
   
}











