#include<lpc21XX.h>
#include"header.h"
#define LED (1<<18)
#define  SW ((IOPIN0>>14)&1)
main()
{
int c=0;
T0PR=15000000-1;
IODIR0=LED;
IOSET0=LED;
while(1)
{
if(SW==0)
{
c=0;
T0PC=0;
T0TC=0;
T0TCR=1;
while(SW==0);
c++;
while(T0TC<1)
{
if(SW==0)
c++;
while(SW==0);

if(c==2 && T0TC<1)
IOCLR0=LED;
if(c==1 && T0TC<1)
IOSET0=LED;
}
}
}

}
