/*
 * Button.h
 *
 *  Created on: 04-04-2012
 *      Author: Mateusz
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#define BUTTON2_IN 			DDRC  |=  (0<<2)
#define BUTTON2_SET 		PORTC |=  (1<<2)
#define BUTTON2_ON			!(PINC & (1<<2))

#define BUTTON1_IN 			DDRC  |=  (0<<1)
#define BUTTON1_SET 		PORTC |=  (1<<1)
#define BUTTON1_ON			!(PINC & (1<<1))

#define BUTTON3_IN 			DDRC  |=  (0<<0)
#define BUTTON3_SET 		PORTC |=  (1<<0)
#define BUTTON3_ON			!(PINC & (1<<0))

#endif /* BUTTON_H_ */
