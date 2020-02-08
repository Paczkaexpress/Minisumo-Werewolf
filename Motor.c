#include <avr/io.h>
#include <avr/iom128.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <avr/signal.h>
#include <avr/sleep.h>
#include "KTIR.h"
#include "Motor.h"

void Engine(int Left,int Right)
{
	FORWARD_LEFT_CLR;
	FORWARD_RIGHT_CLR;
	BACKWARD_LEFT_CLR;
	BACKWARD_RIGHT_CLR;

	//Left = (Left * 255)/100;
	//Right = (Right * 255)/100;
	if(Left>0)
	{
		FORWARD_LEFT_SET;
		OCR3A = Left;
	}
	else if(Left<0)
	{
		BACKWARD_LEFT_SET;
		OCR3A = -Left;
	}
	if(Right>0)
	{
		FORWARD_RIGHT_SET;
		OCR3B = Right;
	}
	else if(Right<0)
	{
		BACKWARD_RIGHT_SET;
		OCR3B = -Right;
	}
	if(Right == 0 && Left == 0)
	{
		OCR3A = 250;
		OCR3B = 250;
		FORWARD_LEFT_SET;
		FORWARD_RIGHT_SET;
		BACKWARD_LEFT_SET;
		BACKWARD_RIGHT_SET;
	}
}
