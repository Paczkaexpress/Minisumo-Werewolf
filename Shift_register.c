#include <avr/io.h>
#include <avr/delay.h>
#include <avr/iom128.h>
#include "Shift_register.h"

void Shift_register(int a)
{
		SR_STCP_SET;
		SR_STCP_CLR;
			for(int i=0;i<16;i++)
			{
				SR_DATA_CLR;
				if(a&1)
					SR_DATA_SET;
				SR_SHCP_SET;
				SR_SHCP_CLR;
				a>>=1;
			}
			SR_STCP_SET;
			SR_STCP_CLR;
}



