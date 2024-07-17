#include"header.h"
#include<string.h>
main()
{
s8 *p1="4900C8971305";
s8 *p2="020010A3A617";
s8 *p3="4900C910A030";
s8 arr[13];
uart0_init(9600);
lcd_init();
IODIR0=7<<17;
while(1)
{
uart0_rx_string(arr,12);

lcd_cmd(0x01);
lcd_string(arr);
uart0_tx_string(arr);
if((strcmp((const char *)arr,(const char *)p1))==0)
{
uart0_tx_string("\r\navinash");
IOSET0=1<<17;
}
else if(strcmp((const char *)arr,(const char *)p2)==0)
{
uart0_tx_string("\r\nakram");
IOSET0=2<<17;
}
else if(strcmp((const char *)arr,(const char *)p3)==0)
{
uart0_tx_string("\r\nnaveen");
IOSET0=4<<17;
}
else
  uart0_tx_string("wrong");
}
}
