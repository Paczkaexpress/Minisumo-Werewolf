/*
 * Buzzer.h
 *
 *  Created on: 03-04-2012
 *      Author: Mateusz
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#define BUZZER_CLR      PORTE |=  (1<<5)
#define BUZZER_SET      PORTE &= ~(1<<5)
#define BUZZER_OUT   	DDRE  |=  (1<<5)

#endif /* BUZZER_H_ */
