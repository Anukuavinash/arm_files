#include<lpc21XX.h>
#include"header.h"
main()
{
int i;
lcd_init();
//lcd_cmd(0X80);
//lcd_data('A');
//lcd_data('Z');
while(1)
{
for(i=0;i<16;i++)
{
lcd_cmd(0x80 +i);
lcd_string_rot("Avinash",i);
delay_ms(200);
lcd_cmd(0X01);
}
}
}
