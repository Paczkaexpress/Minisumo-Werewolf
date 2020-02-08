/*
 * Mause.h
 *
 *  Created on: 15-09-2012
 *      Author: Mateusz
 */

#ifndef MAUSE_H_
#define MAUSE_H_

#include <avr/io.h>
#include <avr/iom128.h>
#include <util/delay.h>


#define MSCK_OUT	DDRD |= (1<<3)
#define MSCK_SET	PORTD |= (1<<3)
#define MSCK_CLR	PORTD &= ~(1<<3)
#define MSCK_IN     DDRD &= ~(1<<3)      /*!< PIN nummer fuer Maus-SCK  */

#define MSDA_OUT	DDRD |= (1<<2)
#define MSDA_SET	PORTD |= (1<<2)
#define MSDA_CLR	PORTD &= ~(1<<2)
#define MSDA_IN     DDRD &= ~(1<<2)
#define MSDA_ON 	(PIND & (1<<2))

void Mouse_WriteByte(unsigned char);
unsigned char Mouse_ReadByte();
void Mouse_Write(unsigned char, unsigned char);
unsigned char Mouse_Read(unsigned char);
void Mouse_Init();
int Mouse_PozX(int);
int Mouse_PozY(int);


#endif /* MAUSE_H_ */
