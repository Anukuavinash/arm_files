#include<lpc21XX.h>
#include"header.h"
#define LED (7<<17)
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
if(c>2)
continue;
}

while(T0TC<8)
{
   if(SW==0)
   c++;
   while(SW==0);

if(c==2 && T0TC<8)
IOCLR0=1<<17;
if(c==1 && T0TC>5)
IOSET0=1<<17;
}
}
if(T0TC==8)
T0TCR=0;
}
}
