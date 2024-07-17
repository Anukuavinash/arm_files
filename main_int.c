#include"header.h"
main()
{
int i=0;
lcd_init();
while(1)
{
for(i=0;i<16;i++)
{
lcd_cmd(0X80+i);
lcd_integer(100);
lcd_cmd(0xc0+i);
lcd_integer(-12345);
lcd_cmd(0X01);
}
}
}
