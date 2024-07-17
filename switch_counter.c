#include"header.h"
#define SW1 ((IOPIN0>>14)&1)
#define SW2 ((IOPIN0>>15)&1)
#define SW3 ((IOPIN0>>16)&1)
main()
{
int c=0;
T0PR=15000-1;
while(1)
{
while(SW1==0 && c!=59)
{
T0PC=0;
T0TC=0;
T0TCR=1;
while(T0TC<1);
 c++;
}
if(SW2==0)
{
c--;
while(SW2==0);
//c--;
}
while(SW3==0 && c)
{
T0PC=0;
T0TC=0;
T0TCR=1;
while(T0TC<1);
c--;
} 

}
}
