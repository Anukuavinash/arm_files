#include<lpc21xx.h>
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;

//extern void delay_sec(u32);
//extern void delay_ms(u32);
extern void lcd_init(void);
extern void lcd_data(u8);
extern void lcd_cmd(u8);
extern void lcd_string(s8 *);
extern void lcd_string_rot(s8 *,u32);
extern void lcd_integer(s32);
extern void uart0_init(u32 baud);
extern void uart0_tx(u8 data);
extern u8 uart0_rx(void);
extern void uart0_tx_string(s8 *ptr);
extern void delay_sec(u32 sec);
extern void delay_ms(u32 ms);
extern void uart0_rx_string(s8 *,u8);
extern void uart0_rx_password(s8 *,u8);
extern void uart0_tx_float(float num);
extern u32 adc_read(u8 ch_num);
extern void adc_init(void);
extern void uart0_tx_integer(s32 num);
extern void config_vic_for_eint0(void);
extern void config_eint0(void);
extern void config_vic_for_uart0(void);
extern void config_uart0(void);
extern void config_vic_timer(void);
extern void en_timer0_int(void);
extern void spi0_init(void);
extern u8 spi0(u8 data);
extern u32 mcp3204_read(u8 ch_num);
extern void i2c_init(void);
extern u8 i2c_byte_read_frame(u8 sa,u8 mr);
extern void i2c_byte_write_frame(u8 sa,u8 mr,u8 data);

