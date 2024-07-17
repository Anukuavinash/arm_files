#include"header.h"
#include<string.h>
#define SW ((IOPIN0>>15)&1)
u8 *p="AVINASH";
main()
{
static u8 c=0,j=0;
s8 arr[8];
uart0_init(9600);
while(1)
{
   if(c<3)
   {
   uart0_tx_string("\r\n ENTER PASSWORD:");
   uart0_rx_password(arr,7);
   while(uart0_rx()!='\r');
   if(strcmp((const char *)arr,(const char *)p)==0)
   {
   uart0_tx_string("\r\n PASSWORD IS CORRECT");
   c=0;
   }
   else
   {
   uart0_tx_string("\r\n PASSWORD IS WRONG");
   c++;
   }
   }
   else if(j>1)
   {
   uart0_tx_string("\r\nBLOCKED");
   j++;
   }
   }
   
}
