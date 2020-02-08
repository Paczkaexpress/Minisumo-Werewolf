#include"Mause.h"

void Mouse_WriteByte(unsigned char data)
{
	signed char i;
	MSDA_OUT;               // SDA auf Output

	for (i=7; i>=0; i--)
	{
		MSCK_CLR;      //SCK auf Low, Daten vorbereiten
		if(data&(1<<i))      //Bit rausschieben
			MSDA_SET;
		else
			MSDA_CLR;

		MSCK_SET;      // SCK =1 Sensor uebernimmt auf steigender Flanke
		_delay_us(1);         //Sensor Zeit lassen um Bit zu holen
   }

	MSDA_IN;
	MSDA_CLR;
}

unsigned char Mouse_ReadByte()
{
	signed char i;
	unsigned char data=0;

	_delay_us(3);            //Sensor Zeit lassen um die Daten aus dem Register zu holen

	for (i=7; i>-1; i--)
	{
		MSCK_CLR;
		_delay_us(1);         //Sensor kurz Zeit lassen
		MSCK_SET;

		if(MSDA_ON)       //BIT einlesen
			data |= (1<<i);
		else
			data &= ~(1<<i);
	}
	lcd_variable((int)data,7,5);
	return data;
}

void Mouse_Write(unsigned char adr, unsigned char data)
{
	adr |= (1<<7);
	Mouse_WriteByte(adr);  //rl MSB muss 1 sein für Write Operation
	Mouse_WriteByte(data);
}


unsigned char Mouse_Read(unsigned char adr)
{
	Mouse_WriteByte(adr);
	return Mouse_ReadByte();
}

void Mouse_Init(void)
{
   MSCK_OUT;    // SCK auf Output
   MSDA_OUT;      //SDA auf Output

   MSCK_SET;   // SCK auf high
   MSDA_SET;     //SDA auf high

   Mouse_Write(0x00,0x80);
   Mouse_Write(0x00,0x01);
}

int Mouse_PozX(int posx)
{
	unsigned char ino;
	signed char x;
	ino=Mouse_Read(0x16);

    if(ino&(1<<7))
	{
    	x=Mouse_Read(0x17);
	    posx=posx+x;

	    if(ino&(1<<3))
	    {
	    	if(x<0) posx-=128;
	    	else posx+=128;
	    }
	}
    return posx;
}


int Mouse_PozY(int posy)
{
	unsigned char ino;
	signed char y;

	ino=Mouse_Read(0x16);

    if(ino&(1<<7))
	{
	    y=Mouse_Read(0x18);
	    posy=posy+y;

	    if(ino&(1<<4))
	    {
	    	if(y<0)posy-=128;
	    	else posy+=128;
	    }

	}
    return posy;
}
