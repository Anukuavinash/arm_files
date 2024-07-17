#include"header.h"
#define  SW ((IOPIN0>>14)&1)
main()
{
int count;
IODIR0=7<<17;
while(1)
{
for(count=0;count<7;)
{
if(SW==0)
{
count++;
IOCLR0=count<<17;
while(SW==0);
IOSET0=count<<17;
}

}
}
}
