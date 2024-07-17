#include"header.h"
#define LED (1<<18)
#define  SW ((IOPIN0>>14)&1)
main()
{
int c=0;
IODIR0=1<<18;
while(1)
{
if(SW==0)
{
while(SW==0);
IOCLR0=LED;
else
IOSET0=LED;
}
}
}
