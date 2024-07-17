#include<lpc21xx.h>
#include"header.h"
extern unsigned int flag;
int count=0;
#define BULB (1<<17)
#define FAN (1<<18)
#define SW1 ((IOPIN0>>14)&1)
#define SW2 ((IOPIN0>>15)&1)
#define SW3 ((IOPIN0>>16)&1)
main()
{
//u8 i=0;
u8 cmd;
IODIR0=7<<17;
IOSET0=7<<17;
config_vic_for_eint0();
config_eint0();
uart0_init(9600);
 while(1)
 {
 /*if(SW1==0)
 {
   
   while(SW1==0);
   	i=!i;
     if(i==1)
     IOCLR0=1<<19;
	 else
	 IOSET0=1<<19;
 }*/
 if(flag)
 {
   if(SW2==0)
   {  
      while(SW2==0);
      if((IOPIN0>>17&1)==0)
      IOSET0=BULB;
	  else
	  IOCLR0=BULB;
	  
   }
   else if(SW3==0)
   { 
     while(SW3==0);
     if((IOPIN0>>18&1)==0)
     IOSET0=FAN;
	 else
	 IOCLR0=FAN;
	 
   }
 }
else
{
uart0_tx_string("\r\n MENU");
uart0_tx_string("\r\n a.BULB ON");
uart0_tx_string("\r\n b.BULB OFF");
uart0_tx_string("\r\n c.FAN ON");
uart0_tx_string("\r\n d.FAN OFF");
uart0_tx_string("\r\n e.BULB and FAN ON");
uart0_tx_string("\r\n f.BULB and FAN OFF");
uart0_tx_string("\r\n options....");
cmd=uart0_rx();
switch(cmd)
{
case 'a': IOSET0=BULB;break;
case 'b': IOCLR0=BULB;break;
case 'c': IOSET0=FAN;break;
case 'd': IOCLR0=FAN;break;
case 'e': IOSET0=BULB;
          IOSET0=FAN;
		  break;
case 'f': IOCLR0=BULB;
          IOCLR0=FAN;
		  break;
default:uart0_tx_string("WRONG COMMAND");
}

}

  }
}
