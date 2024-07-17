#include<lpc21xx.h>
#include<stdio.h>
#include"header.h"
//extern unsigned int flag;

#define RDR (U0LSR&1)
#define THRE ((U0LSR>>5)&1)
#define SW1 ((IOPIN0>>14)&1)

void uart0_init(u32 baud)
{
	u32 pclk;
	u32 result=0;
	u32 a[]={15,60,30,15,15};
	pclk=a[VPBDIV]*1000000;
	result=pclk/(16*baud);
	PINSEL0|=0X5;
	U0LCR=0X83;
	U0DLL=result&0xFF;
	U0DLM=(result>>8)&0xFF;
	U0LCR=0X03;
}



void uart0_tx(u8 data)
{
	U0THR=data;
	while(THRE==0);
}


u8 uart0_rx(void)
{
u8 temp;
//	while(1){
//	if(sw==0)
//	{
//	while(sw==0);
//	return;
//	}
//	 if(RDR==0)
//	 break;
//
//
   //while(RDR==0 && flag==1);
   while(RDR==0);
		temp=U0RBR;
   //while(RDR==0);	
	return temp;
}

void uart0_tx_string(s8 *ptr)
{
	while(*ptr)
	{
		//U0THR=*ptr;
		//while(THRE==0);
		uart0_tx(*ptr);
		ptr++;
	}
}

void uart0_rx_string(s8 *ptr,u8 len)
{
u8 i;
for(i=0;i<len;i++)
{
	while(RDR==0);
	ptr[i]=U0RBR;
if(ptr[i]=='\r')
break;
}
ptr[i]='\0';
}


 
void uart0_rx_password(s8 *ptr,u8 len)
{
u8 i=0;
while(i<len)
{
while(RDR==0);
ptr[i]=U0RBR;
  if(ptr[i]=='\r')
    break;
if(ptr[i]==8 && i)
{
   uart0_tx(8);
  // uart0_tx(' ');
   //uart0_tx(8);
    i--;
}
else if(ptr[i]!=8 && ptr[i]!='\r')
{
	uart0_tx('*');
	i++;
}
}
	ptr[i]='\0';
}

void uart0_tx_float(float f)
{
/*s8 arr[10];
sprintf(arr,"%.1f",num);
uart0_tx_string(arr); */
int num1;
if(f==0)
{
	uart0_tx_string("0.0");
	return;
}
if(f<0)
{
	  uart0_tx('-');
	  f=-f;
}
num1=f;
uart0_tx_integer(num1);
uart0_tx('.');
f=f-num1;
num1=f*1000000;
uart0_tx_integer(num1);

}

void uart0_tx_integer(s32 num)
{
	s8 arr[10];
	sprintf(arr,"%d",num);
	uart0_tx_string(arr);
} 
