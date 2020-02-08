#include <avr/io.h>
#include <avr/iom128.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <avr/signal.h>
#include <avr/sleep.h>
#include "Shift_register.h"
#include "Buzzer.h"
#include "Nokia3310.h"
#include "Button.h"
#include "KTIR.h"

void KTIR(int a)
{
	if (KTIR1_ON)
	LED_KTIR1_ON;

	if (KTIR2_ON)
	LED_KTIR2_ON;

	if (KTIR3_ON)
	LED_KTIR3_ON;

	if (KTIR4_ON)
	LED_KTIR4_ON;

	if (KTIR5_ON)
	LED_KTIR5_ON;

	if (KTIR6_ON)
	LED_KTIR6_ON;

	if (KTIR7_ON)
	LED_KTIR7_ON;

	if (KTIR8_ON)
	LED_KTIR8_ON;

	if (SHARP1_ON)
	LED_SHARP1_ON;

	if (SHARP2_ON)
	LED_SHARP2_ON;

	if (SHARP3_ON)
	LED_SHARP3_ON;

	if (SHARP4_ON)
	LED_SHARP4_ON;

	if (SHARP5_ON)
	LED_SHARP5_ON;

	if (SHARP6_ON)
	LED_SHARP6_ON;

	Shift_register(a);
}

int Get_ADC(char number)
{
	ADMUX &= ~(1<<0) & ~(1<<1) & ~(1<<2);
	ADMUX |= (1<<REFS0) | (1<<ADLAR); //porównuje z AVCC,  AREF--||--GND
	ADMUX |= number;

    ADCSRA = (1<<ADEN)|(1<<ADSC)|(1<<ADPS1)|(1<<ADPS2);
    while(ADCSRA & (1 << ADSC));
    return ADCH;
}

/*ISR(ADC_vect)
{
	ADCSR &= ~(1<<ADSC);
}*/
