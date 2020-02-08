#ifndef SHIFT_REGISTER_H_
#define SHIFT_REGISTER_H_

//output enable input (active LOW)
#define SR_OEI_SET        	PORTB |=  (1<<5)
#define SR_OEI_CLR       	PORTB &= ~(1<<5)
#define SR_OEI_OUT   		DDRB  |=  (1<<5)
//shift register clock input
#define SR_STCP_SET        	PORTB |=  (1<<4)
#define SR_STCP_CLR       	PORTB &= ~(1<<4)
#define SR_STCP_OUT   		DDRB  |=  (1<<4)
// master reset (active LOW)
#define SR_RESET_SET        PORTE |=  (1<<2)
#define SR_RESET_CLR       	PORTE &= ~(1<<2)
#define SR_RESET_OUT   		DDRE  |=  (1<<2)
// storage register clock input
#define SR_SHCP_SET        	PORTE |=  (1<<6)
#define SR_SHCP_CLR       	PORTE &= ~(1<<6)
#define SR_SHCP_OUT   		DDRE  |=  (1<<6)
//serial data input
#define SR_DATA_SET      	PORTE |=  (1<<7)
#define SR_DATA_CLR      	PORTE &= ~(1<<7)
#define SR_DATA_OUT  		DDRE  |=  (1<<7)
//Led
#define LED_KTIR1_ON		a  |= 	  (1<<3) // ok 0,3,5,6,7,8,11,13,14,15
#define LED_KTIR1_OFF		a  &=    ~(1<<3)

#define LED_KTIR2_ON		a  |= 	  (1<<10)// 0,5,6,7,8,11,13,14,15
#define LED_KTIR2_OFF		a  &=    ~(1<<10)

#define LED_KTIR3_ON		a  |= 	  (1<<4)//!
#define LED_KTIR3_OFF		a  &=    ~(1<<4)

#define LED_KTIR4_ON		a  |= 	  (1<<8) //ok  0,5,6,7,8,11,13,14,15
#define LED_KTIR4_OFF		a  &=    ~(1<<8)

#define LED_KTIR5_ON		a  |= 	  (1<<14) //ok  0,5,6,7,8,11,13,14,15
#define LED_KTIR5_OFF		a  &=    ~(1<<14)

#define LED_KTIR6_ON		a  |= 	  (1<<1)//!
#define LED_KTIR6_OFF		a  &=    ~(1<<1)

#define LED_KTIR7_ON		a  |= 	  (1<<0)//!
#define LED_KTIR7_OFF		a  &=    ~(1<<0)

#define LED_KTIR8_ON		a  |= 	  (1<<2)
#define LED_KTIR8_OFF		a  &=    ~(1<<2)

#define LED_SHARP1_ON		a  |= 	  (1<<5)  //ok
#define LED_SHARP1_OFF		a  &=    ~(1<<5)

#define LED_SHARP2_ON		a  |= 	  (1<<7)  //ok  0,5,6,7,8,11,13,14,15
#define LED_SHARP2_OFF		a  &=    ~(1<<7)

#define LED_SHARP3_ON		a  |= 	  (1<<11) //ok
#define LED_SHARP3_OFF		a  &=    ~(1<<11)

#define LED_SHARP4_ON		a  |= 	  (1<<15) //OK
#define LED_SHARP4_OFF		a  &=    ~(1<<15)

#define LED_SHARP5_ON		a  |= 	  (1<<0)  //ok
#define LED_SHARP5_OFF		a  &=    ~(1<<0)

#define LED_SHARP6_ON		a  |= 	  (1<<6) //OK  0,5,6,7,8,11,13,14,15
#define LED_SHARP6_OFF		a  &=    ~(1<<6)

#define LED_TEST1_ON		a  |= 	  (1<<4)
#define LED_TEST1_OFF		a  &=    ~(1<<4)

#define LED_TEST2_ON		a  |= 	  (1<<13)
#define LED_TEST2_OFF		a  &=    ~(1<<13)//ok 0,5,6,7,8,11,13,14,15

void Shift_register(int a);

#endif /* SHIFT_REGISTER_H_ */
