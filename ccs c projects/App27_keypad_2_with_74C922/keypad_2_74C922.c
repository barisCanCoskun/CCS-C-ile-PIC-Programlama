
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#use fast_io(b)
#use fast_io(c)

#byte portc = 0x07

char const keys[] = {1, 2, 3, 0,
                4, 5, 6, 0,
                7, 8, 9, 0,
                0x0f, 0, 0x0f, 0};

#int_ext
void dis_kesme()
{
   portc = keys[portc>>4];
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
   
   set_tris_b(0x01);
   set_tris_c(0xF0);
   
   ext_int_edge(L_TO_H);
   //ext_int_edge(H_TO_L);
   
   enable_interrupts(INT_EXT);
   enable_interrupts(GLOBAL);   
   
   portc = 0;
   
   while(true);
}











