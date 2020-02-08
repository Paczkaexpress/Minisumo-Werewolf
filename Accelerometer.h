/*
 * Accelerometer.h
 *
 *  Created on: 20-08-2012
 *      Author: Mateusz
 */

#ifndef ACCELEROMETER_H_
#define ACCELEROMETER_H_

#include <avr/io.h>
#include <avr/iom128.h>
#include <util/delay.h>
#include <avr/signal.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include "Shift_register.h"
#include "Buzzer.h"
#include "Nokia3310.h"
#include "Button.h"
#include "KTIR.h"
#include "Accelerometer.h"

#define SCL_SET PORTD |=  (1<<0)
#define SCL_CLR PORTD &= ~(1<<0)
#define SCL_OUT DDRD  |=  (1<<0)
#define SCL_IN  DDRD  &= ~(1<<0)

#define SDA_SET PORTD |=  (1<<1)
#define SDA_CLR PORTD &= ~(1<<1)
#define SDA_OUT DDRD  |=  (1<<1)
#define SDA_IN  DDRD  &= ~(1<<1)

int accelerometer_x();
int accelerometer_y();
int accelerometer_z();
int Acc_Start();
int Acc_Send(unsigned char);
#endif /* ACCELEROMETER_H_ */
