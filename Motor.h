/*
 * Motor.h
 *
 *  Created on: 02-08-2012
 *      Author: Mateusz
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#define PWM1_SET      		PORTE |=  (1<<3)
#define PWM1_CLR       		PORTE &= ~(1<<3)
#define PWM1_OUT  			DDRE  |=  (1<<3)

#define PWM2_SET      		PORTE |=  (1<<4)
#define PWM2_CLR       		PORTE &= ~(1<<4)
#define PWM2_OUT  			DDRE  |=  (1<<4)

#define BACKWARD_LEFT_SET    PORTB |=  (1<<2)
#define BACKWARD_LEFT_CLR    PORTB &= ~(1<<2)
#define BACKWARD_LEFT_OUT  	DDRB  |=  (1<<2)

#define BACKWARD_RIGHT_SET    PORTB |=  (1<<7)
#define BACKWARD_RIGHT_CLR    PORTB &= ~(1<<7)
#define BACKWARD_RIGHT_OUT 	 DDRB  |=  (1<<7)

#define FORWARD_LEFT_SET    PORTB |=  (1<<3)
#define FORWARD_LEFT_CLR    PORTB &= ~(1<<3)
#define FORWARD_LEFT_OUT  	 DDRB  |=  (1<<3)

#define FORWARD_RIGHT_SET   PORTB |=  (1<<6)
#define FORWARD_RIGHT_CLR   PORTB &= ~(1<<6)
#define FORWARD_RIGHT_OUT 	 DDRB  |=  (1<<6)

void Engine(int Left,int Right);

#endif /* MOTOR_H_ */
