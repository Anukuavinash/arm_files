#include"header.h"
#define SI ((I2CONSET>>3)&1)

void i2c_byte_write_frame(u8 sa,u8 mr,u8 data)
{
	/*1. GENERATE START CONDITION*/
	I2CONCLR=(1<<3);
	I2CONSET=(1<<5);
	while(SI==0);
	I2CONCLR=(1<<5);

	/*2.SEND SLAVE+WRITE ADDRESS * CHECK ACK*/

	I2DAT=sa;
	I2CONCLR=(1<<3);
	while(SI==0);
	if(I2STAT==0x20)
	{
		uart0_tx_string("error:sa+w\r\n");
		goto exit;
	}
	/*3.SEND MEMORY ADDRESS & CHECK ACK*/
	I2DAT=mr;
	I2CONCLR=(1<<3);
	while(SI==0);

	if(I2STAT==0X30)
	{
		uart0_tx_string("error:MEMORY ADD\r\n");
		goto exit;
	}
	/*4.SEND DATA & CHECK ACK*/
	I2DAT=data;
	I2CONCLR=(1<<3);
	while(SI==0);
	if(I2STAT==0X30)
	{
		uart0_tx_string("error:DATA\r\n");
		goto exit;
	}
	/*5.GENERATE STOP CONDITION*/

exit:
	I2CONCLR=(1<<3);
	I2CONSET=(1<<4);
}

u8 i2c_byte_read_frame(u8 sa,u8 mr)
{
    u8 temp;
	/*1. GENERATE START CONDITION*/
	//I2CONCLR=(1<<3);
	I2CONSET=(1<<5);
	I2CONCLR=(1<<3);
	while(SI==0);
	I2CONCLR=(1<<5);

	/*2.SEND SLAVE+WRITE ADDRESS * CHECK ACK*/

	I2DAT=sa;
	I2CONCLR=(1<<3);
	while(SI==0);
	if(I2STAT==0x20)
	{
		uart0_tx_string("error:sa+w\r\n");
		goto exit;
	}
	/*3.SEND MEMORY ADDRESS & CHECK ACK*/
	I2DAT=mr;
	I2CONCLR=(1<<3);
	while(SI==0);

	if(I2STAT==0X30)
	{
		uart0_tx_string("error:MEMORY ADD\r\n");
		goto exit;
	}
	/*4.GENERATE RESTART CONDITION */

	//I2CONCLR=(1<<3);
	I2CONSET=(1<<5);
	I2CONCLR=(1<<3);
	while(SI==0);
	I2CONCLR=(1<<5);

	/*5.SEND SLAVE+READ & CHECK ACK*/
	I2DAT=sa|1;
	I2CONCLR=(1<<3);
	while(SI==0);
	if(I2STAT==0X48)
	{
		uart0_tx_string("error:sa+r\r\n");
		goto exit;
	}

	/*6.READ DATA & SEND NOACK*/
	I2CONCLR=(1<<3);
	while(SI==0);
	temp=I2DAT;
	/*7.GENERATE STOP CONDITION*/

exit:
	I2CONCLR=(1<<3);
	I2CONSET=(1<<4);

	/*8.RETURN RECEIVED DATA*/
	return temp;

}

void i2c_init()
{
	PINSEL0|=0x50; // P0.2---->SCL, P0.3------>SDA
	I2SCLH=I2SCLL=75; // 100 KPBS MASTER SPEED
	I2CONSET=(1<<6);  // ENABLE I2C PERIPHERAL & MASTER MODE

}

