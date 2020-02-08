/*
 * SHARP.h
 *
 *  Created on: 01-08-2012
 *      Author: Mateusz
 */

#ifndef SHARP_H_
#define SHARP_H_

#define SHARP1_SET        	PORTA |=  (1<<7)
#define SHARP1_CLR       	PORTA &= ~(1<<7)
#define SHARP1_IN   		DDRA  |=  (0<<7)
#define SHARP1_ON			!(PINA & (1<<7))

#define SHARP2_SET        	PORTA |=  (1<<6)
#define SHARP2_CLR       	PORTA &= ~(1<<6)
#define SHARP2_IN   		DDRA  |=  (0<<6)
#define SHARP2_ON			!(PINA & (1<<6))

#define SHARP3_SET        	PORTA |=  (1<<5)
#define SHARP3_CLR       	PORTA &= ~(1<<5)
#define SHARP3_IN   		DDRA  |=  (0<<5)
#define SHARP3_ON			!(PINA & (1<<5))

#define SHARP4_SET        	PORTA |=  (1<<4)
#define SHARP4_CLR       	PORTA &= ~(1<<4)
#define SHARP4_IN   		DDRA  |=  (0<<4)
#define SHARP4_ON			!(PINA & (1<<4))

#define SHARP5_SET        	PORTA |=  (1<<3)
#define SHARP5_CLR       	PORTA &= ~(1<<3)
#define SHARP5_IN   		DDRA  |=  (0<<3)
#define SHARP5_ON			!(PINA & (1<<3))

#define SHARP6_SET        	PORTA |=  (1<<2)
#define SHARP6_CLR       	PORTA &= ~(1<<2)
#define SHARP6_IN   		DDRA  |=  (0<<2)
#define SHARP6_ON			!(PINA & (1<<2))

#endif /* SHARP_H_ */
