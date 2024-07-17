#include<lpc21xx.h>
#include"header.h"

void lcd_data(u8 data)
{
   // FOR hIGHER NIBBLE
   IOCLR1=0XFE<<16;
	 IOSET1=(data & 0XF0)<<16;
	 IOSET1=1<<17;
	 IOCLR1=1<<18;
	 IOSET1=1<<19;											 
	 delay_ms(2);
	 IOCLR1=1<<19;

	  // FOR LOWER NIBBLE

	 IOCLR1=0XFE<<16;
	 IOSET1=(data & 0X0F)<<20;
	 IOSET1=1<<17;
	 IOCLR1=1<<18;
	 IOSET1=1<<19;
	 delay_ms(2);
	 IOCLR1=1<<19;

}

void lcd_cmd(u8 cmd)
{
// for higher nibble

   IOCLR1=0XFE<<16;
	 IOSET1=(cmd & 0XF0)<<16;
	 IOCLR1=1<<17;
	 IOCLR1=1<<18;
	 IOSET1=1<<19;
	 delay_ms(20);
	 IOCLR1=1<<19;

//for lower nibble
	 IOCLR1=0XFE<<16;
	 IOSET1=(cmd & 0X0F)<<20;
	 IOCLR1=1<<17;
	 IOCLR1=1<<18;
	 IOSET1=1<<19;
	 delay_ms(20);
	 IOCLR1=1<<19;


}

void lcd_init()
{
        IODIR1=0XFE<<16;				// setting all pins as output direction
		PINSEL2=0X0;			 //configure gpio pins
		IOCLR1=1<<19;		 //EN
		lcd_cmd(0X02);		// enable 4bit mode
		lcd_cmd(0X28);	 //select 4bit mode
		lcd_cmd(0X0E);	// enable cursor
		lcd_cmd(0X01)	;  // clears the screen
}

void lcd_string(s8 *ptr)
{
while(*ptr)
{
lcd_data(*ptr) ;
ptr++;
}
}

void lcd_string_rot(s8 *ptr,u32 i)
{
int j=0,z=0;
while(*ptr)
{
lcd_data(*ptr) ;
ptr++;
z++;
if(i+z >15)
{
lcd_cmd(0X80+j);
j++;
}
}
}



void lcd_integer(s32 num)
{
int a[10],i;
if(num==0)
{
lcd_data('0');
}
if(num<0)
{
lcd_data('-');
num = -num;
}
i=0;
while(num>0)
{
a[i]=num%10+48;
num=num/10;
i++;
}
for(i=i-1;i>=0;i--)
{
lcd_data(a[i]);
}
//IOCLR1=1<<19;
}

