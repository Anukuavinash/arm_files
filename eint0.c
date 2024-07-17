#include"header.h"
#define LED (1<<17)
u32 flag=1;
extern int count;
void eint0_handler(void) __irq
{
/*static int flag;
flag^=1;
if(flag)
IOCLR0=LED;
else
IOSET0=LED;
flag^=1;
if(flag)
IOSET0=1<<19;
else
IOCLR0=1<<19;*/
count++;
EXTINT=1;  // clear EINT0 interrupt flag
VICVectAddr=0; // to finish isr execution
}
void config_vic_for_eint0(void)
{
VICIntSelect=0;	   // all interrupts are type of irq
VICVectCntl0=14 | (1<<5);	  //assign interrupt to slot 0 and enable the interrupt
VICVectAddr0=(u32)eint0_handler;  //assign isr address to slot0
VICIntEnable |=(1<<14);  // enable eint1 in vic
}
void config_eint0(void)
{
EXTPOLAR=0; // EINT1 is active low
EXTMODE=1<<1;	// EINT1 is edge triggered
PINSEL1|=1;	 // po.16 as eint0
IODIR0|=1<<17;   // p0.17 as output
}
