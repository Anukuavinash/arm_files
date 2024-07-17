#include<lpc21xx.h>
#define LED (1<<18)
#include"header.h"
int flag=0;
extern int count;
   void TIMER_INTERRUPT(void) __irq
   {
     flag^=1;
	 if(flag)
	  IOSET0=LED;
	  else
	  IOCLR0=LED;
      count++;
	  T1PC=0;
	  T1IR=1;	
	  T1TC=0;
	  VICVectAddr=0;
	  T1TCR=1;
       
   }
   void config_vic_timer(void)
   {
      VICIntSelect=0;
	  VICVectCntl0=5 |(1<<5);
	  VICVectAddr0=(int)TIMER_INTERRUPT;
	  VICIntEnable|=(1<<5);
	  IODIR0=7<<17;
   }
   void en_timer0_int(void)
   {
     T1PC=0;
     T1PR=15000000-1;
     T1TC=0;
     //T1IR=1;
	 T1MCR=7;
	 T1MR0=1;
	 T1TCR=1;
   }
