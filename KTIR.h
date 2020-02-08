/*
 * KTIR.h
 *
 *  Created on: 06-04-2012
 *      Author: Mateusz
 */

#ifndef KTIR_H_
#define KTIR_H_

// Definicja czujników pod³o¿a

#define KTIR5_SET        	PORTF |=  (1<<0)
#define KTIR5_CLR       	PORTF &= ~(1<<0)
#define KTIR5_IN   			DDRF  |=  (0<<0)
#define KTIR5_ON			Get_ADC(0)<180

#define KTIR6_SET        	PORTF |=  (1<<1)
#define KTIR6_CLR       	PORTF &= ~(1<<1)
#define KTIR6_IN   			DDRF  |=  (0<<1)
#define KTIR6_ON			!(PINF & (1<<1))

#define KTIR7_SET        	PORTF |=  (1<<2)
#define KTIR7_CLR       	PORTF &= ~(1<<2)
#define KTIR7_IN   			DDRF  |=  (0<<2)
#define KTIR7_ON			!(PINF & (1<<2))

#define KTIR8_SET        	PORTF |=  (1<<3)
#define KTIR8_CLR       	PORTF &= ~(1<<3)
#define KTIR8_IN   			DDRF  |=  (0<<3)
#define KTIR8_ON			Get_ADC(3)<180

#define KTIR3_SET        	PORTF |=  (1<<4)
#define KTIR3_CLR       	PORTF &= ~(1<<4)
#define KTIR3_IN   			DDRF  |=  (0<<4)
#define KTIR3_ON			!(PINF & (1<<4))

#define KTIR4_SET        	PORTF |=  (1<<5)
#define KTIR4_CLR       	PORTF &= ~(1<<5)
#define KTIR4_IN   			DDRF  |=  (0<<5)
#define KTIR4_ON			Get_ADC(5)<180

#define KTIR2_SET        	PORTF |=  (1<<6)
#define KTIR2_CLR       	PORTF &= ~(1<<6)
#define KTIR2_IN   			DDRF  |=  (0<<6)
#define KTIR2_ON			!(PINF & (1<<6))

#define KTIR1_SET        	PORTF |=  (1<<7)
#define KTIR1_CLR       	PORTF &= ~(1<<7)
#define KTIR1_IN   			DDRF  |=  (0<<7)
#define KTIR1_ON			Get_ADC(7)<180


//Definicja Sharpów

#define SHARP5_SET        	PORTA |=  (1<<7)
#define SHARP5_CLR       	PORTA &= ~(1<<7)
#define SHARP5_IN   		DDRA  |=  (0<<7)
#define SHARP5_ON			!(PINA & (1<<7))

#define SHARP6_SET        	PORTA |=  (1<<6)
#define SHARP6_CLR       	PORTA &= ~(1<<6)
#define SHARP6_IN   		DDRA  |=  (0<<6)
#define SHARP6_ON			!(PINA & (1<<6))

#define SHARP3_SET        	PORTA |=  (1<<5)
#define SHARP3_CLR       	PORTA &= ~(1<<5)
#define SHARP3_IN   		DDRA  |=  (0<<5)
#define SHARP3_ON			!(PINA & (1<<5))

#define SHARP4_SET        	PORTA |=  (1<<4)
#define SHARP4_CLR       	PORTA &= ~(1<<4)
#define SHARP4_IN   		DDRA  |=  (0<<4)
#define SHARP4_ON			!(PINA & (1<<4))

#define SHARP1_SET        	PORTA |=  (1<<3)
#define SHARP1_CLR       	PORTA &= ~(1<<3)
#define SHARP1_IN   		DDRA  |=  (0<<3)
#define SHARP1_ON			!(PINA & (1<<3))

#define SHARP2_SET        	PORTA |=  (1<<2)
#define SHARP2_CLR       	PORTA &= ~(1<<2)
#define SHARP2_IN   		DDRA  |=  (0<<2)
#define SHARP2_ON			!(PINA & (1<<2))

void KTIR(int a);
int Get_ADC(char number);
#endif /* KTIR_H_ */
