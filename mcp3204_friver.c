#include<lpc21xx.h>
#include"header.h"
#define CS0 (1<<7)

u32 mcp3204_read(u8 ch_num)
{
u32 result=0;
u8 byteh=0,bytel=0;
ch_num<<=6;	 // set ch_num to 6 and 7 bit
IOCLR0=CS0;	  // CS0=0
	spi0(0x06);
	byteh=spi0(ch_num);
	bytel=spi0(0x00);
IOSET0=CS0;	   // CS0=1
byteh &=0x0f;  // mask higher nibble
result=(byteh <<8)|bytel;	 // merge 12 bits ADC result
return result;
}
