
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#use fast_io(b)
#use fast_io(c)

int kesme = 0;

#int_timer1
void timer1_interrupt()
{
   set_timer1(65530);
   kesme++;
    
   output_b(kesme);
   
   if(kesme == 255)
      kesme = 0;
      
}

void main()
{
   setup_psp(PSP_DISABLED);
   setup_timer_1(T1_DISABLED); //  silinebilir
   setup_timer_2(T2_DISABLED, 0, 1);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF);
   
   set_tris_b(0x00);
   set_tris_c(0x01);
   
   output_b(0x00);
   
   setup_timer_1(T1_EXTERNAL | T1_DIV_BY_2);
   
   set_timer1(65530);
   
   enable_interrupts(int_timer1);
   enable_interrupts(GLOBAL);
   
   while(true);
   
}











