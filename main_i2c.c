#include"header.h"
main()
{
u8 h,m,s;
i2c_init();
lcd_init();
uart0_init(9600);

i2c_byte_write_frame(0xD0,0x02,0x50);
i2c_byte_write_frame(0xD0,0x01,0x59);
i2c_byte_write_frame(0xD0,0x00,0x57);

while(1)
{
  h=i2c_byte_read_frame(0xD0,0x02);
  //h=h&0x1f;
  m=i2c_byte_read_frame(0xD0,0x01);
  s=i2c_byte_read_frame(0xD0,0x00);
  lcd_cmd(0x80);
  lcd_data((h/16)+48);
  lcd_data((h%16)+48);
  lcd_data(':');
  lcd_data((m/16)+48);
  lcd_data((m%16)+48);
  lcd_data(':');
  lcd_data((s/16)+48);
  lcd_data((s%16)+48);
}

}
