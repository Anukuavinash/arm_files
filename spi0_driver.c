#include<lpc21xx.h>
#include"header.h"

#define CS0 (1<<7)
#define SPIF ((S0SPSR>>7)&1)
void spi0_init(void)
{
PINSEL0|=0x1500;   //spio functionality selected
IODIR0|=CS0;	  // po.7 (cs0) as o/p direction
IOSET0=CS0;		  // diselect the slave
S0SPCR=0x20;	  // cpol=cpha=0,master mode,MSB first,spi0 interrupt disable
S0SPCCR=15;		  //spi0 clock is 1mbps
}
u8 spi0(u8 data)
{
S0SPDR=data;   // data from master to slave
while(SPIF==0);// monitoring flag
return S0SPDR; // data from slave to master
}

