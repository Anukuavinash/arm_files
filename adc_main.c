#include"header.h"
main()
{
//u32 adc_out;
u32 temp;
float vout;						   
//float temperature;
uart0_init(9600);
adc_init();
uart0_tx_string("ADC\r\n");
while(1)
{
//adc_out=adc_read(1);
temp=adc_read(2);
//vout=(adc_out*3.3)/1023;
vout=(temp *3.3)/1023;
//temperature=(vout-0.5)/0.01;
uart0_tx_integer(temp);
uart0_tx(' ');
uart0_tx_float(vout);
uart0_tx('v');
uart0_tx_string("\r\n");
delay_ms(100);
}
}
