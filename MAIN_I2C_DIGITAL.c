#include"header.h"
main()
{
u8 h,m,s,dow,mm,yy,dd,l;
s8 *a[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
i2c_init();
lcd_init();
uart0_init(9600);

i2c_byte_write_frame(0xD0,0x02,0x71);
i2c_byte_write_frame(0xD0,0x01,0x59);
i2c_byte_write_frame(0xD0,0x00,0x57);
i2c_byte_write_frame(0xD0,0x03,5);
i2c_byte_write_frame(0xD0,0x04,0x11);
i2c_byte_write_frame(0xD0,0x05,0x07);
i2c_byte_write_frame(0xD0,0x06,0x24);

while(1)
{
  h=i2c_byte_read_frame(0xD0,0x02);
  l=h&(1<<5);
  h=h&0x1f;									    
  m=i2c_byte_read_frame(0xD0,0x01);
  s=i2c_byte_read_frame(0xD0,0x00);
  dow=i2c_byte_read_frame(0xD0,0x03);
  dd=i2c_byte_read_frame(0xD0,0x04);
  mm=i2c_byte_read_frame(0xD0,0x05);
  yy=i2c_byte_read_frame(0xD0,0x06);
  lcd_cmd(0x80);
  lcd_data((h/16)+48);
  lcd_data((h%16)+48);
  lcd_data(':');
  lcd_data((m/16)+48);
  lcd_data((m%16)+48);
  lcd_data(':');
  lcd_data((s/16)+48);
  lcd_data((s%16)+48);
  if(l==0)
  lcd_string("  AM");
  else
  lcd_string("  PM");
     
  lcd_cmd(0xc0);
  lcd_data((dd/16)+48);
  lcd_data((dd%16)+48);
  lcd_data('/');
  lcd_data((mm/16)+48);
  lcd_data((mm%16)+48);
  lcd_data('/');
  lcd_data((yy/16)+48);
  lcd_data((yy%16)+48);
  lcd_string("  ");
  lcd_string(a[dow-1]);


  
}

}
