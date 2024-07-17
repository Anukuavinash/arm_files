#include"header.h"
extern u32 flag,count2;
extern u8 temp;
void uart0_handler(void) __irq
{
int num=U0IIR &0x0E;
if(num==0x4)
{
temp=U0RBR;
U0THR=temp;
}
if(num==0x2)
{
}
flag=1;
count2++;
VICVectAddr=0; // to finish isr execution
}
void config_vic_for_uart0(void)
{
VICIntSelect=0;	   // all interrupts are type of irq
VICVectCntl0=6 | (1<<5);	  //assign interrupt to slot 0 and enable the interrupt
VICVectAddr0=(u32)uart0_handler;  //assign isr address to slot0
VICIntEnable |=(1<<6);  // enable eint0 in vic
}
void config_uart0(void)
{
U0IER=3;
}
