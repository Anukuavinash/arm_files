#include"header.h"
#define LED1 (1<<17)
int count=0;
main()
{
  	     config_vic_timer();
		 en_timer0_int();
		 while(1)
		 {
		   IOCLR0=LED1;
		   delay_ms(10);
		   IOSET0=LED1;
		   delay_ms(10);

		 }
}


