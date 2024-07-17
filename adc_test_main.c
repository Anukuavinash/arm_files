#include"header.h"
main()
{
u8 cmd,cmd2,cmd3;
u32 temp_external,temp_onchip; 
uart0_init(9600);
spi0_init();
adc_init();
while(1)
{
L1:
 uart0_tx_string("a.Test onchip Adc of lpc2129\r\n");
 uart0_tx_string("b.Test Mcp3204 External Adc\r\n");
 uart0_tx_string("options.....");
 cmd=uart0_rx();
 uart0_tx(cmd);
  uart0_tx_string("\r\n");
 switch(cmd)
 {
 L2:
 case 'a':
   uart0_tx_string("1.read Ain0\r\n");
   uart0_tx_string("2.read Ain1\r\n");
   uart0_tx_string("3.read Ain2\r\n");
   uart0_tx_string("4.read Ain3\r\n");
   uart0_tx_string("options......");
   cmd2=uart0_rx();
   uart0_tx(cmd2);
   uart0_tx_string("\r\n");
   switch(cmd2)
   {
   case '1':temp_onchip=adc_read(0);break;
   case '2':temp_onchip=adc_read(1);break;
	case '3':temp_onchip=adc_read(2);break;
   case '4':temp_onchip=adc_read(3);break;
   default:uart0_tx_string("wrong cmd\r\n");goto L2;
   }
   
		uart0_tx_integer(temp_onchip);
		uart0_tx_string("\r\n");
   break;
 case 'b':
 L3:
   uart0_tx_string("1.read CH0\r\n");
   uart0_tx_string("2.read CH1\r\n");
   uart0_tx_string("3.read CH2\r\n");
   uart0_tx_string("4.read CH3\r\n");
   uart0_tx_string("options......");
   cmd3=uart0_rx();
   uart0_tx(cmd3);
   uart0_tx_string("\r\n");
   switch(cmd3)
   {
   case '1':temp_external=mcp3204_read(0);break;
   case '2':temp_external=mcp3204_read(1);break;
   case '3':temp_external=mcp3204_read(2);break; 
   case '4':temp_external=mcp3204_read(3); break;
   default:uart0_tx_string("wrong cmd\r\n");goto L3;
   }
            uart0_tx_integer(temp_external);
		    uart0_tx_string("\r\n");
   break;
 default: goto L1;

}

}
}
