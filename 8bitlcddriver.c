#include<lpc21xx.h>
#include"header.h"
#define RS 1<<8
#define RW 1<<9
#define EN 1<<10
void lcd_data(unsigned char data)
{
IOCLR0=0x7FF;
IOSET0= data;
IOSET0= RS;
IOCLR0= RW;
IOSET0= EN;
delay_ms(2);
IOCLR0= EN;
}

void lcd_cmd(unsigned char cmd)
{
IOCLR0=0x7FF;
IOSET0=cmd;
IOCLR0= RS;
IOCLR0= RW;
IOSET0= EN;
delay_ms(2);
IOCLR0= EN;
}

void lcd_init()
{
IODIR0=0X7FF;
IOCLR0= EN;
lcd_cmd(0x38);
lcd_cmd(0x0e);
lcd_cmd(0X01);
}
