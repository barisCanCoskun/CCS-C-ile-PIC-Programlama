
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 4000000)

#use fast_io(b)
#use fast_io(c)

int i = 0;

#int_ccp1
void capture1_interrupt()
{
   output_toggle(pin_b0);
}

#int_ccp2
void compare2_interrupt()
{
   set_timer1(0);
   output_toggle(pin_b1);
}

void main()
{
   setup_psp(PSP_DISABLED);
   //setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED, 0, 1);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   /* setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF); */
   
   set_tris_b(0x00);
   set_tris_c(0x01);
   
   output_b(0x00);
   
   enable_interrupts(INT_CCP1);
   enable_interrupts(INT_CCP2);
   enable_interrupts(GLOBAL);
   
   setup_ccp1(CCP_COMPARE_set_on_match);
   setup_ccp2(CCP_COMPARE_INT);
   
   SETUP_timer_1(t1_external_sync | t1_div_by_1);
   
   CCP_1_HIGH = 0x00;
   CCP_1_LOW = 0x05;
   
   CCP_2_HIGH = 0x00;
   CCP_2_LOW = 0x0a;
   
   set_timer1(0);
   
   while(true);
   
}











