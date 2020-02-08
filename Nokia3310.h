
#ifndef NOKIA3310_H_
#define NOKIA3310_H_

#define LCD_RESET_SET     	PORTC |=  (1<<7)
#define LCD_RESET_CLR      	PORTC &= ~(1<<7)
#define LCD_RESET_OUT 		DDRC  |=  (1<<7)

#define LCD_SCE_SET     	PORTC |=  (1<<6)
#define LCD_SCE_CLR      	PORTC &= ~(1<<6)
#define LCD_SCE_OUT   		DDRC  |=  (1<<6)

#define LCD_DC_SET     		PORTC |=  (1<<5)
#define LCD_DC_CLR     		PORTC &= ~(1<<5)
#define LCD_DC_OUT   		DDRC  |=  (1<<5)

#define LCD_SDIN_SET      	PORTC |=  (1<<4)
#define LCD_SDIN_CLR      	PORTC &= ~(1<<4)
#define LCD_SDIN_OUT   	  	DDRC  |=  (1<<4)

#define LCD_SCLK_SET      	PORTC |=  (1<<3)
#define LCD_SCLK_CLR      	PORTC &= ~(1<<3)
#define LCD_SCLK_OUT   	  	DDRC  |=  (1<<3)

#define LCD_X 				84
#define LCD_Y 				6

#define LCD_CMD     		0
#define LCD_DATA    		1

#define LCD_SETX 			0x80
#define LCD_SETY  			0x40

#define LCD_NOP asm volatile("nop\n\t""nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" ::)

#define LCD_HOME lcd_write_byte(LCD_CMD, 0x40);lcd_write_byte(LCD_CMD, 0x80);
#define LCD_GOTO(x,y) lcd_write_byte(LCD_CMD, 0x40|(y));lcd_write_byte(LCD_CMD, 0x80|(x));

void lcd_write_byte(unsigned char tryb, unsigned char data );
void lcd_image(unsigned char img[],char x0,char y0,char w,char h);
void lcd_text(char s[], unsigned char x, unsigned char y);
void lcd_panel(int pocz,int max,unsigned char y);
void lcd_clean();

#endif /* NOKIA3310_H_ */
