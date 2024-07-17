#include"header.h"
#define LED 1<<17
#define SW1 ((IOPIN0>>14)&1)
//#define SW2 ((IOPIN0>>15)&1)
main()
{
int i=0;
IODIR0=7<<17;
IOSET0=7<<17;
while(1)
{
if(SW1==0)
{
while(SW1==0);
if(i==0)
IOCLR0=LED;
else
IOSET0=LED;
i=!i;
}
}
}
