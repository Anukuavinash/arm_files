 #include"header.h"
u32 count1,count2,flag;
u8 temp;
u8 a[30];
u8 i=0;
main()
{
uart0_init(9600);
/*config_vic_for_uart0();
config_uart0();
while(1)
{
count1++;
if(flag==1)
{
     flag=0;
     if(a[i-1]=='\r')
	 {
	 a[i]='\0';
	 uart0_tx_string(a);
	 uart0_tx_string("\r\n");
	 i=0;
	 a[i]='\0';

	 }
}
}*/
uart0_tx_float(23.45);
}

void uart0_handler(void) __irq
{
a[i]=U0RBR;
i++;
flag=1;
//count2++;
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
U0IER=1;
}
