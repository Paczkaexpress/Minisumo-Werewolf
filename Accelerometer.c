#include "Accelerometer.h"
#include <compat/twi.h>

int accelerometer_x()
{
	int Position = 0;

	//komenda start
	if(Acc_Start() ==  0)
	{
		lcd_text("    HUJ!!!    ",0,0);
		lcd_text("B³¹d przy wys-",0,1);
		lcd_text("³aniu komendy ",0,2);
		lcd_text("START         ",0,3);
		_delay_ms(100);
	}

	if (Acc_Send(0x3A) == 0)
	{
		lcd_text("    HUJ!!!    ",0,0);
		lcd_text("B³¹d przy wys-",0,1);
		lcd_text("³aniu adresu! ",0,2);
		_delay_ms(100);
	}

	if (Acc_Send(0x2F) == 0)
	{
		/*lcd_text("    HUJ!!!    ",0,0);
		lcd_text("B³¹d przy wys-",0,1);
		lcd_text("³aniu funkcji!",0,2);
		_delay_ms(100);*/
	}

	if(Acc_Start())
	{
		lcd_text("    HUJ!!!    ",0,0);
		lcd_text("B³¹d przy wys-",0,1);
		lcd_text("³aniu komendy ",0,2);
		lcd_text(" 2 START      ",0,3);
		_delay_ms(100);
	}
	if(Acc_Send(0x3B) == 0)
	{
		lcd_text("    HUJ!!!    ",0,0);
		lcd_text("B³¹d przy odb-",0,1);
		lcd_text("ieraniu danych",0,2);
		_delay_ms(100);
	}

	TWCR = (1<<TWINT) | (0|TWEA) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	Position = TWDR;

	TWCR =(1 << TWINT) | (1<<TWEN) | (1<<TWSTO);   // Wys³anie ¿¹dania "STOP".
	while(TWCR & (1<<TWSTO));

	return Position;
}

int accelerometer_y()
{
	int Position = 0;

	//komenda start
	if(Acc_Start() ==  0)
	{
		lcd_text("    HUJ!!!    ",0,0);
		lcd_text("B³¹d przy wys-",0,1);
		lcd_text("³aniu komendy ",0,2);
		lcd_text("START         ",0,3);
		_delay_ms(100);
	}

	if (Acc_Send(0x3A) == 0)
	{
		lcd_text("    HUJ!!!    ",0,0);
		lcd_text("B³¹d przy wys-",0,1);
		lcd_text("³aniu adresu! ",0,2);
		_delay_ms(100);
	}

	if (Acc_Send(0x03) == 0)
	{
		/*lcd_text("    HUJ!!!    ",0,0);
		lcd_text("B³¹d przy wys-",0,1);
		lcd_text("³aniu funkcji!",0,2);
		_delay_ms(100);*/
	}

	if(Acc_Start())
	{
		lcd_text("    HUJ!!!    ",0,0);
		lcd_text("B³¹d przy wys-",0,1);
		lcd_text("³aniu komendy ",0,2);
		lcd_text(" 2 START      ",0,3);
		_delay_ms(100);
	}
	if(Acc_Send(0x3B) == 0)
	{
		lcd_text("    HUJ!!!    ",0,0);
		lcd_text("B³¹d przy odb-",0,1);
		lcd_text("ieraniu danych",0,2);
		_delay_ms(100);
	}

	TWCR = (1<<TWINT) | (0|TWEA) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	Position = TWDR;

	TWCR =(1 << TWINT) | (1<<TWEN) | (1<<TWSTO);   // Wys³anie ¿¹dania "STOP".
	while(TWCR & (1<<TWSTO));

	return Position;
}
int accelerometer_z()
{
	int Position = 0;

	//komenda start
	if(Acc_Start() ==  0)
	{
		lcd_text("    HUJ!!!    ",0,0);
		lcd_text("B³¹d przy wys-",0,1);
		lcd_text("³aniu komendy ",0,2);
		lcd_text("START         ",0,3);
		_delay_ms(100);
	}

	if (Acc_Send(0x3A) == 0)
	{
		lcd_text("    HUJ!!!    ",0,0);
		lcd_text("B³¹d przy wys-",0,1);
		lcd_text("³aniu adresu! ",0,2);
		_delay_ms(100);
	}

	if (Acc_Send(0x06) == 0)
	{
		/*lcd_text("    HUJ!!!    ",0,0);
		lcd_text("B³¹d przy wys-",0,1);
		lcd_text("³aniu funkcji!",0,2);
		_delay_ms(100);*/
	}

	if(Acc_Start())
	{
		lcd_text("    HUJ!!!    ",0,0);
		lcd_text("B³¹d przy wys-",0,1);
		lcd_text("³aniu komendy ",0,2);
		lcd_text(" 2 START      ",0,3);
		_delay_ms(100);
	}
	if(Acc_Send(0x3B) == 0)
	{
		lcd_text("    HUJ!!!    ",0,0);
		lcd_text("B³¹d przy odb-",0,1);
		lcd_text("ieraniu danych",0,2);
		_delay_ms(100);
	}

	TWCR = (1<<TWINT) | (0|TWEA) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	Position = TWDR;

	TWCR =(1 << TWINT) | (1<<TWEN) | (1<<TWSTO);   // Wys³anie ¿¹dania "STOP".
	while(TWCR & (1<<TWSTO));

	return Position;
}
int Acc_Start()
{
	uint8_t   twst;
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN); // wysy³am komende start

	while (!(TWCR & (1<<TWINT))); // czekam na cos

	twst = TW_STATUS & 0xF8;

	if((TWSR & 0xF8) != 0x08)
		return 0;
	else
		return 1;
}
int Acc_Send(unsigned char Adress)
{
	uint8_t   twst;
	TWDR = Adress ; // adres urz¹dzenia
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	twst = TW_STATUS & 0xF8;
	if ( (twst != TW_MT_SLA_ACK) && (twst != TW_MR_SLA_ACK) )
	{
		return 0;
	}
	else
		return 1;
}
