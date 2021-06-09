
#include <16f877.h>

#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD

#use delay (clock = 20000000)

//#define use_portb_lcd TRUE

#include <HDM64GS12.c>
#include <graphics.c>

char yazi1[] = "GAZI";
char yazi2[] = "UNIVERSITY";
int i, x1, y1, x2, y2;

void main()
{
   setup_psp(PSP_DISABLED);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED, 0, 1);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF); 
   
   glcd_init(ON);
   
   while(true){
      glcd_init(ON);
      glcd_text57(39, 5, yazi1, 2, ON);
      glcd_text57(5, 30, yazi2, 2, ON);
      delay_ms(2000);
      
      glcd_init(ON);
      x1 = 5;
      y1 = 5;
      x2 = 100;
      y2 = 5;
      
      for(i = 1; i <= 6; i++){
       
      glcd_line(x1, y1, x2, y2, ON);
       
      y2 = y1 += 10;
       x2 -= 10;
       delay_ms(1000);
     }
      glcd_init(ON);
      
      x1 = y1 = 10;
      
      for(i = 1; i <= 120; i++){
         glcd_pixel(x1, y1, ON);
         
         y1 = x1++;
         delay_ms(50);
     }
     glcd_init(ON);
     
     x1 = 5;
     y2 = 60;
     
     for(i = 1; i <= 8; i++){
        glcd_bar(x1, 0, x1, y2, 10, ON);
        delay_ms(1000);
        x1 += 15;
        y2 -= 5;
     }
     glcd_init(ON);
     
     for(i = 0; i <= 30; i += 5){
        glcd_circle(60, 30, i, NO, ON);
        delay_ms(1000);
     }
     glcd_init(ON);
     
     x1 = 5;
     y1 = 5;
     x2 = 120;
     y2 = 63;
     
     for(i = 1; i <= 6; i++){
        glcd_rect(x1, y1, x2, y2, NO, ON);
        
        y1 = x1 += 5;
        x2 -= 5;
        y2 -= 5;
        delay_ms(500);
     }
     
   }
   
}











