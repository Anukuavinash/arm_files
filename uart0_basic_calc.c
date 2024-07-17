#include"header.h"
main()

{
s8 s[21],j=0;
int num1,num2,num3=0,i;
uart0_init(9600);
while(1)
{
uart0_tx_string("\r\nEnter expression:");
uart0_rx_string(s,20);
uart0_tx_string(s);

for(num1=0,i=0;(s[i]>='0' && s[i]<='9');i++)
{			  
   num1=num1*10+(s[i]-48);
}

j=s[i];

for(++i,num2=0;s[i];i++)				    
{
  num2=num2*10+(s[i]-48);
}

uart0_tx_string("\r\nResult:");

if(num2==0 && j=='/')
{
uart0_tx_string("\r\n floating point exception error");
continue;
}

switch(j)
{
case '+':num3=num1+num2;break;
case '-': num3=num1-num2;break;
case '*': num3=num1*num2;break;
case '/': num3=num1/num2;break;
case '%': num3=num1%num2;break;
default	: uart0_tx_string("wrong option\r\n");
}
uart0_tx_integer(num3);
num3=0;

}
}
