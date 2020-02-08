#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <avr/iom128.h>
#include "Nokia3310.h"

unsigned char LCD_Font[] PROGMEM = {
#include "LCD/LCD_Font.h"
};

void lcd_write_byte(unsigned char tryb, unsigned char data )
{
    unsigned char m;

    LCD_SCE_CLR;

    if(tryb) LCD_DC_SET; else LCD_DC_CLR;

    for(m=0x80; m; m>>=1)
    {
       if(data & m)
          LCD_SDIN_SET;
       else
          LCD_SDIN_CLR;

       LCD_SCLK_SET;
       LCD_NOP;
       LCD_SCLK_CLR;
    }

    LCD_SCE_SET;
}

void lcd_image(unsigned char img[],char x0,char y0,char w,char h)
{
   unsigned int i,j,k;

   for(i=0,j=0,k=0; i<h; i++)
   {
      /* Komenda  LCD "Set Y address of RAM" */
      lcd_write_byte(LCD_CMD, 0x40|(i+y0));
      /* Komenda "Set X address of RAM"*/
      lcd_write_byte(LCD_CMD, 0x80|(x0));

      /* Kopiowanie z FLASH do pamiêci obrazu LCD  */
      for(j=0; j<w ; j++,k++)
         lcd_write_byte(LCD_DATA, pgm_read_byte(&img[k]));
   }
}

void lcd_clean()
{
   unsigned int i,j;

   for(i=0; i<6; i++)
   {
	  lcd_write_byte(LCD_CMD, 0x40|i);
	  lcd_write_byte(LCD_CMD, 0x80);

      for(j=0; j<84 ; j++)
         lcd_write_byte(LCD_DATA,0x00);
   }
}

void lcd_text(char s[], unsigned char x, unsigned char y)
{
   unsigned int c,j;
   unsigned char i,k;

   // Kody polskich literek z ogonkami
   char pl[] = {'¹','æ','ê','³','ñ','ó','œ','Ÿ','¿','¥','Æ','Ê','£','Ñ','Ó','Œ','','¯'};

   // Ustawia po³o¿enia pierwszej litery tekstu na ekranie LCD
   lcd_write_byte(LCD_CMD, LCD_SETY|(y));
   lcd_write_byte(LCD_CMD, LCD_SETX|(x));

   // Rysuje znak po znaku
   for(k=0; (c = s[k]); k++)
   {
      // Dopasowuje kody znaków z ogonkami
      for(i=0; (i<18) && (pl[i]!=c); i++) ;
      if(i<18) c= 0x80+i;

      // Kopiuje jeden znak(6x8) z FLASH do pamiêci obrazu LCD
      for(i=0, j=(c-32)*6; i<6; i++,j++)
           lcd_write_byte(LCD_DATA, pgm_read_byte(&LCD_Font[j]));
   }
}

void lcd_panel(int pocz,int max,unsigned char y) //y to po³o¿enie wykresu na osi y, pocz wartosc aktualna, max wartosc maksymalna
{
	// 80 pixeli = 100% wype³nienia Wykresu
	int pixel = (pocz*80)/max;
	//ustawiam wykres na wspu³rzêdnych X=0;Y=y
	   lcd_write_byte(LCD_CMD, LCD_SETY|(y));
	   lcd_write_byte(LCD_CMD, LCD_SETX|(0));

	      for(int j=0; j<84 ;j++)
	      {
	    	  if(j==0 || j == 83) 					lcd_write_byte(LCD_DATA, 0x00);
	    	  else if(j==1 || j == 82 || pixel+2>j) lcd_write_byte(LCD_DATA, 0x7e);
	    	  else 									lcd_write_byte(LCD_DATA, 0x42);
	      }
}

void lcd_variable(int zmienna,short int start,short int y) // zmienna waypisywana wartosc , start kolumna od której zaczynamy wypisywaæ, y to po³o¿enie na osi Y
{
	char s[14];
	for(int i = 13;i>=0;i--)
	{
		if(i<start) s[i] = ' ';
		else if(zmienna < 0)
		{
			s[i] = '-';
			zmienna = abs(zmienna);
		}
		else if(zmienna > 0)
		{
			s[i] = (char)(zmienna%10)+48;
			zmienna = zmienna / 10;
		}
		else s[i] = ' ';
	}
	lcd_text(s,0,y);
}
