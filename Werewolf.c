#include <avr/io.h>
#include <avr/iom128.h>
#include <util/delay.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <avr/signal.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include "Shift_register.h"
#include "Buzzer.h"
#include "Nokia3310.h"
#include "Button.h"
#include "KTIR.h"
#include "Motor.h"
#include "Menu.h"
#include "Mause.h"

static void Inicialization(void);
void Fight();

int main(void)
{
	Inicialization();
	lcd_clean();
	Menu_Start();
	Fight();
}
void Inicialization(void)
{
	//konfiguracja przerwañ
	TCCR0 = (1 << CS02); // preskaler 256
	TIMSK = (1 << TOIE0) | (1<<TOIE3);
	//Konfiguracja PWM
	TCCR3A |= (1<<WGM32) | (1<<WGM30) | (1<<COM3A1) | (1<<COM3B1);
	TCCR3A &= ~(1<<COM3C1) & ~(1<<COM3C0);
	TCCR3B = (1<<CS31);

	//inicjalizacja KTIR
	KTIR1_IN;
	KTIR2_IN;
	KTIR3_IN;
	KTIR4_IN;
	KTIR5_IN;
	KTIR6_IN;
	KTIR7_IN;
	KTIR8_IN;

	/*KTIR1_SET;
	KTIR2_SET;
	KTIR3_SET;
	KTIR4_SET;
	KTIR5_SET;
	KTIR6_SET;
	KTIR7_SET;
	KTIR8_SET;*/
	//inicjalizacja przycisków
	BUTTON1_IN;
	BUTTON2_IN;
	BUTTON3_IN;
	BUTTON1_SET;
	BUTTON2_SET;
	BUTTON3_SET;
	//inicjalizacja buzzerów
	BUZZER_OUT;
	BUZZER_CLR;

	//inicjalizacja rejestru przesuwanego
	SR_OEI_OUT;
	SR_DATA_OUT;
	SR_STCP_OUT;
	SR_SHCP_OUT;
	SR_RESET_OUT;

	SR_RESET_SET;
	SR_OEI_CLR;

	//inicjalizajcja sterownika silników
	FORWARD_LEFT_OUT;
	FORWARD_RIGHT_OUT;
	BACKWARD_LEFT_OUT;
	BACKWARD_RIGHT_OUT;
	PWM1_OUT;
	PWM2_OUT;
	//inicjalizacja I2C
	SCL_OUT;
	SDA_OUT;
	SDA_SET;
	SCL_SET;

	TWBR=0x20;
    TWSR=(0<<TWPS1)|(0<<TWPS0);
	//inicjalizacja wyswietlacza
	LCD_RESET_OUT;
	LCD_SCE_OUT;
	LCD_DC_OUT;
	LCD_SDIN_OUT;
	LCD_SCLK_OUT;
	LCD_RESET_CLR;

	//eeprom_busy_wait();
	//int Kontrast = eeprom_read_byte(0);

	_delay_ms(2);
	LCD_RESET_SET;
	LCD_SCE_SET;

	lcd_write_byte(LCD_CMD, 0x21);
	lcd_write_byte(LCD_CMD, 0x05);
	lcd_write_byte(LCD_CMD, 0x13);
	lcd_write_byte(LCD_CMD, 0xb11000000);
	lcd_write_byte(LCD_CMD, 0x20);
	lcd_write_byte(LCD_CMD, 0x0C);

	Mouse_Init();

	sei();


}
ISR( TIMER0_OVF_vect)
{
	KTIR(0);
	TCNT0 = 8; // 32768/256=128*/
}
