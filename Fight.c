#include <avr/io.h>
#include <avr/iom128.h>
#include <util/delay.h>
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

void Fight() {
	int przud = 0;
	int Left = 0,Right = 0;
	int attack = 0;
	int fast_start = 1;
	while (1)
	{

		if(KTIR1_ON && KTIR8_ON)
		{
			Engine(-100, 100);
			przud = 1;
			_delay_ms(30);
		}
		else if(KTIR4_ON && KTIR5_ON)
		{
			Engine(100, -100);
			przud = 0;
			_delay_ms(30);
		}
		else if (KTIR1_ON)
		{
			Run_Back(-10);
			if (fast_start == 1) {Engine(-200, -100);_delay_ms(40);}
			else Engine(-180, -120);
			przud = 0;
			fast_start = 0;
			_delay_ms(20);
		}
		else if (KTIR4_ON)
		{
			Run_Back(-10);
			if (fast_start == 1) {Engine(-100, -200);_delay_ms(40);}
			else Engine(-120, -180);
			przud = 0;
			fast_start = 0;
			_delay_ms(20);

		} else if (KTIR5_ON) {
			Run_Back(10);
			if (fast_start == 1) {Engine(200, 100);_delay_ms(30);}
			else Engine(180, 120);
			przud = 1;
			fast_start = 0;
			_delay_ms(30);

		} else if (KTIR8_ON) {
			Run_Back(10);
			if (fast_start == 1) {Engine(100, 200);_delay_ms(30);}
			else Engine(120, 180);
			przud = 1;
			fast_start = 0;
			_delay_ms(30);

		}
		else if(attack > 0 && !(SHARP1_ON && SHARP2_ON) && !(SHARP4_ON && SHARP5_ON))
		{
			Engine(0,0);
			_delay_ms(2);
			attack --;
		}
		else if (SHARP1_ON && SHARP2_ON) {
			przud = 0;
			Engine(140, 140);
			attack = 5;
		} else if (SHARP1_ON) {
			przud = 0;
			Engine(110, 70);
			Left = 1;
			Right = 0;
		} else if (SHARP2_ON) {
			przud = 0;
			Engine(70, 110);
			Left = 0;
			Right = 1;
		} else if (SHARP4_ON && SHARP5_ON) {
			przud = 1;
			Engine(-140, -140);
			attack = 5;
		} else if (SHARP5_ON) {
			przud = 1;
			Engine(-110, -70);
			Left = 1;
			Right = 0;
		} else if (SHARP4_ON) {
			przud = 1;
			Engine(-70, -110);
			Left = 0;
			Right = 1;
		}
		else if(fast_start == 1)
		{
			if(Left == 1)
			Engine(140 * przud - 140 * (1-przud) , 180 * przud - 180 * (1-przud));
			else
			Engine(180 * przud - 180 * (1-przud) , 140 * przud -140 * (1-przud));
			_delay_ms(50);
			fast_start = 0;
		}
		else if (SHARP3_ON) {
			Left = 0;
			Right = 1;
			Engine(120, -70);
			while (!SHARP1_ON && !SHARP2_ON && !SHARP4_ON && !SHARP5_ON && !KTIR1_ON && !KTIR4_ON && !KTIR5_ON && !KTIR8_ON)
				_delay_ms(1);
		} else if (SHARP6_ON)
		{
			Left = 1;
			Right = 0;
			Engine(-120, +70);
			while (!SHARP1_ON && !SHARP2_ON && !SHARP4_ON && !SHARP5_ON
					&& !KTIR1_ON && !KTIR4_ON && !KTIR5_ON && !KTIR8_ON)
				_delay_ms(1);
		}
		else if(fast_start == 1)
		{
			if(Left == 1)
			Engine(140 * przud - 140 * (1-przud) , 180 * przud - 180 * (1-przud));
			else
			Engine(180 * przud - 180 * (1-przud) , 140 * przud -140 * (1-przud));
			_delay_ms(30);
			fast_start = 0;
		}
		else
		{
			if(Left == 1)
			Engine(60 * przud - 60 * (1-przud) , 80 * przud - 80 * (1-przud));
			else
			Engine(80 * przud - 80 * (1-przud) , 60 * przud -60 * (1-przud));
		}
	}
}

void Surrender() {
	while (1) {
		if (KTIR1_ON)
			Engine(70, 50);
		else if (KTIR4_ON)
			Engine(50, 70);
		else if (KTIR8_ON)
			Engine(-50, -70);
		else if (KTIR5_ON)
			Engine(-70, -50);
	}
}

void Run_Back(int a)
{
	if(a<=0)
	{
		for(int i=7;i>0;i--)
		{
			Engine(-200, -200);
			_delay_ms(3);
			Engine(0, 0);
			_delay_ms(3);
		}
	}
	else
	{
		for(int i=7;i>0;i--)
		{
			Engine(200, 200);
			_delay_ms(3);
			Engine(0, 0);
			_delay_ms(3);
		}
	}
}

