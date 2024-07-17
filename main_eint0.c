#include"header.h"		   
u32 count;
main()
{
config_vic_for_eint0();
config_eint0();
while(1)
{
count++;
}
}
