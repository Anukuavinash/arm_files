#include"header.h"
main()
{
int i,j=1;
IODIR0=0xff;
/*for(i=0,j=7;i<8;i++,j--)
{
IOCLR0=1<<i|1<<j;
delay_ms(100);
IOSET0=1<<i|1<<j;
delay_ms(100);
} */
while(1)
{
for(i=0;i<4;i++)
{
	    IOSET0=1<<(i*2)+j;
        delay_ms(100);
		IOCLR0=1<<(i*2)+j;
		delay_ms(100);

}
j=!j;
}
}
