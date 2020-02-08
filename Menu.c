#include "Menu.h"

unsigned char LCD_Start[] PROGMEM =
{
#include "LCD/LCD_Start.h"
};
unsigned char LCD_start[] PROGMEM =
{
#include "LCD/Start.h"
};
unsigned char LCD_Menu[] PROGMEM =
{
#include "LCD/LCD_Menu.h"
};
unsigned char LCD_Debug[] PROGMEM =
{
#include "LCD/LCD_Debug.h"
};
unsigned char LCD_1[] PROGMEM =
{
#include "LCD/1.h"
};
unsigned char LCD_2[] PROGMEM =
{
#include "LCD/2.h"
};
unsigned char LCD_3[] PROGMEM =
{
#include "LCD/3.h"
};
unsigned char LCD_4[] PROGMEM =
{
#include "LCD/4.h"
};
unsigned char LCD_5[] PROGMEM =
{
#include "LCD/5.h"
};

EEMEM int A_Kontrast = 0b11011100;
int Kontrast = 0b11011100;

int Start_Delay = 1000;
short int Start_Second = 5;

void Menu_Start() //OK
{
	lcd_write_byte(LCD_CMD, 0x21);
	lcd_write_byte(LCD_CMD, 0x05);
	lcd_write_byte(LCD_CMD, 0x13);
	lcd_write_byte(LCD_CMD, eeprom_read_byte(&A_Kontrast));
	lcd_write_byte(LCD_CMD, 0x20);
	lcd_write_byte(LCD_CMD, 0x0C);

	while(1)
	{
		lcd_image(LCD_Start, 0, 0, 84, 6);

		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			Menu_Start_Timer();
		}

		if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			Menu_Start_Timer();
			break;
		}

		if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			Menu_Option();
		}
	}
}

void Menu_Option() //OK
{

	while(1)
	{
		lcd_image(LCD_Menu, 0, 0, 84, 6);

		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			Menu_Start();
		}

		if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			Menu_Option_Fight();
		}

		if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			Menu_Debug();
		}
	}
}

void Menu_Debug() //~~
{

	while(1)
	{
		lcd_image(LCD_Debug, 0, 0, 84, 6);

		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			Menu_Option();
		}
		if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			Menu_Start();
		}
	}
}

void Menu_Start_Timer() //~~
{

	int i;
	for(i=Start_Second;i>0;i--)
	{
		if(i==5)
		{
			BUZZER_SET;
			_delay_ms(30);
			BUZZER_CLR;
			lcd_image(LCD_5, 0, 0, 84, 6);
			_delay_ms(800);

			// tutaj zamieszczam timer o czasie trwania = przerwaniu
			// opcja wywo³yj¹ca brzêczyk
			// sprawdzanie czy stan dalmierzy siê nie zmieni³ ( wykrywanie falstartu)
		}
		else if(i==4)
		{
			BUZZER_SET;
			_delay_ms(30);
			BUZZER_CLR;
			lcd_image(LCD_4, 0, 0, 84, 6);
			_delay_ms(800);

			// tutaj zamieszczam timer o czasie trwania = przerwaniu
			// opcja wywo³yj¹ca brzêczyk
			// sprawdzanie czy stan dalmierzy siê nie zmieni³ ( wykrywanie falstartu)
		}
		else if(i==3)
		{
			BUZZER_SET;
			_delay_ms(30);
			BUZZER_CLR;
			lcd_image(LCD_3, 0, 0, 84, 6);
			_delay_ms(800);

			// tutaj zamieszczam timer o czasie trwania = przerwaniu
			// opcja wywo³yj¹ca brzêczyk
			// sprawdzanie czy stan dalmierzy siê nie zmieni³ ( wykrywanie falstartu)
		}
		else if(i==2)
		{
			BUZZER_SET;
			_delay_ms(30);
			BUZZER_CLR;
			lcd_image(LCD_2, 0, 0, 84, 6);
			_delay_ms(800);

			// tutaj zamieszczam timer o czasie trwania = przerwaniu
			// opcja wywo³yj¹ca brzêczyk
			// sprawdzanie czy stan dalmierzy siê nie zmieni³ ( wykrywanie falstartu)
		}
		else if(i==1)
		{
			BUZZER_SET;
			_delay_ms(30);
			BUZZER_CLR;
			lcd_image(LCD_1, 0, 0, 84, 6);
			_delay_ms(800);

			// tutaj zamieszczam timer o czasie trwania = przerwaniu
			// opcja wywo³yj¹ca brzêczyk
			// sprawdzanie czy stan dalmierzy siê nie zmieni³ ( wykrywanie falstartu)
		}
		else if(i==0)
		{
			lcd_image(LCD_start, 0, 0, 84, 6);
			BUZZER_SET;
			_delay_ms(100);
			BUZZER_CLR;
			// tutaj zamieszczam timer o czasie trwania = przerwaniu
			// opcja wywo³yj¹ca brzêczyk
			// sprawdzanie czy stan dalmierzy siê nie zmieni³ ( wykrywanie falstartu)
			break;
		}
	}
	Fight();
}

void Menu_Option_Fight()
{
	while(1)
		{
			lcd_text("##  Fight   ##", 0, 0);
			lcd_text("     Time     ", 0, 1);
			lcd_text("    Display   ", 0, 2);
			lcd_text("     Leds     ", 0, 3);
			lcd_text("    Sensors   ", 0, 4);
			lcd_text("     Back     ", 0, 5);


			if(BUTTON1_ON)
			{
				while(BUTTON1_ON);
				Menu_Option_Back();
			}
			else if(BUTTON2_ON)
			{
				while(BUTTON2_ON);
				//Menu_Option_Fight_???();
			}
			else if(BUTTON3_ON)
			{
				while(BUTTON3_ON);
				Menu_Option_Time();
			}
		}
}

void Menu_Option_Time() //OK
{

	while(1)
	{
		lcd_text("    Fight     ", 0, 0);
		lcd_text("##   Time   ##", 0, 1);
		lcd_text("    Display   ", 0, 2);
		lcd_text("     Leds     ", 0, 3);
		lcd_text("    Sensors   ", 0, 4);
		lcd_text("     Back     ", 0, 5);


		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			Menu_Option_Fight();
		}
		else if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			Menu_Option_Time_Delay();
		}
		else if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			Menu_Option_Display();
		}
	}
}

void Menu_Option_Display() //OK
{

	while(1)
	{
		lcd_text("    Fight     ", 0, 0);
		lcd_text("     Time     ", 0, 1);
		lcd_text("##  Display ##", 0, 2);
		lcd_text("     Leds     ", 0, 3);
		lcd_text("    Sensors   ", 0, 4);
		lcd_text("     Back     ", 0, 5);

		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			Menu_Option_Time();
		}
		else if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			Menu_Option_Display_Contrast_ON();
		}
		else if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			Menu_Option_Leds();
		}
	}
}

void Menu_Option_Leds() //OK
{

	while(1)
	{
		lcd_text("    Fight     ", 0, 0);
		lcd_text("     Time     ", 0, 1);
		lcd_text("    Display   ", 0, 2);
		lcd_text("##   Leds   ##", 0, 3);
		lcd_text("    Sensors   ", 0, 4);
		lcd_text("     Back     ", 0, 5);

		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			Menu_Option_Display();
		}
		else if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			Menu_Option_Leds_Test_ON();
		}
		else if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			Menu_Option_Sensors();
		}
	}
}

void Menu_Option_Sensors() //OK
{
	while(1)
	{
		lcd_text("    Fight     ", 0, 0);
		lcd_text("     Time     ", 0, 1);
		lcd_text("    Display   ", 0, 2);
		lcd_text("     Leds     ", 0, 3);
		lcd_text("##  Sensors ##", 0, 4);
		lcd_text("     Back     ", 0, 5);

		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			Menu_Option_Leds();
		}
		else if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			Menu_Option_Sensors_KTIR();
		}
		else if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			Menu_Option_Back();
		}
	}
}

void Menu_Option_Back() //OK
{
	while(1)
	{
		lcd_text("    Fight     ", 0, 0);
		lcd_text("     Time     ", 0, 1);
		lcd_text("    Display   ", 0, 2);
		lcd_text("     Leds     ", 0, 3);
		lcd_text("    Sensors   ", 0, 4);
		lcd_text("##   Back   ##", 0, 5);

		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			Menu_Option_Sensors();
		}
		else if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			Menu_Option();
		}
		else if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			Menu_Option_Fight();
		}
	}
}

void Menu_Option_Time_Delay() //OK
{
	while(1)
	{
		lcd_text("     Time:    ", 0, 0);
		lcd_text("-Delay     <==", 0, 1);
		lcd_text("-Wait         ", 0, 2);
		lcd_text("-Back         ", 0, 3);
        lcd_text("              ", 0, 4);
        lcd_text("              ", 0, 5);

		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			Menu_Option_Time_Back();
		}
		else if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			Menu_Option_Time_Delay_ON();
		}
		else if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			Menu_Option_Time_Wait();
		}
	}
}

void Menu_Option_Time_Wait() //OK
{
	while(1)
	{
		lcd_text("     Time:    ", 0, 0);
		lcd_text("-Delay        ", 0, 1);
		lcd_text("-Wait      <==", 0, 2);
		lcd_text("-Back         ", 0, 3);
		lcd_text("              ", 0, 4);
		lcd_text("              ", 0, 5);
		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			Menu_Option_Time_Delay();
		}
		else if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			Menu_Option_Time_Wait_ON();
		}
		else if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			Menu_Option_Time_Back();
		}
	}
}

void Menu_Option_Time_Back() //OK
{
	while(1)
	{
		lcd_text("     Time:    ", 0, 0);
		lcd_text("-Delay        ", 0, 1);
		lcd_text("-Wait         ", 0, 2);
		lcd_text("-Back      <==", 0, 3);
		lcd_text("              ", 0, 4);
		lcd_text("              ", 0, 5);

		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			Menu_Option_Time_Wait();
		}
		else if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			Menu_Option_Time();
		}
		else if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			Menu_Option_Time_Delay();
		}
	}
}

void Menu_Option_Sensors_KTIR() //OK
{
	while(1)
	{
		lcd_text("   Sensors:   ", 0, 0);
		lcd_text("-Mouse        ", 0, 1);
		lcd_text("-Back         ", 0, 2);
		lcd_text("-KTIR      <==", 0, 3);
		lcd_text("-Sharp        ", 0, 4);
		lcd_text("-Encoder      ", 0, 5);

		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			Menu_Option_Sensors_Back();
		}
		else if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			Menu_Option_Sensors_KTIR_Test();
		}
		else if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			Menu_Option_Sensors_Sharp();
		}
	}
}

void Menu_Option_Sensors_Sharp() //OK
{

	while(1)
	{
		lcd_text("   Sensors:   ", 0, 0);
		lcd_text("-Back         ", 0, 1);
		lcd_text("-KTIR         ", 0, 2);
		lcd_text("-Sharp     <==", 0, 3);
		lcd_text("-Encoder      ", 0, 4);
		lcd_text("-Accelerometr ", 0, 5);

		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			Menu_Option_Sensors_KTIR();
		}
		else if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			Menu_Option_Sensors_Sharp_Test();
		}
		else if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			Menu_Option_Sensors_Encoder();
		}
	}

}

void Menu_Option_Sensors_Encoder() //~~
{
	while(1)
	{
		lcd_text("   Sensors:   ", 0, 0);
		lcd_text("-KTIR         ", 0, 1);
		lcd_text("-Sharp        ", 0, 2);
		lcd_text("-Encoder   <==", 0, 3);
		lcd_text("-Accelerometr ", 0, 4);
		lcd_text("-Bluetooth    ", 0, 5);

		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			Menu_Option_Sensors_Sharp();
		}
		//else if(BUTTON2_ON) Menu_Option_Sensors_Encoder_Test();
		else if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			Menu_Option_Sensors_Accelerometr();
		}
	}
}

void Menu_Option_Sensors_Accelerometr() //OK
{
	while(1)
	{
		lcd_text("   Sensors:   ", 0, 0);
		lcd_text("-Sharp        ", 0, 1);
		lcd_text("-Encoder      ", 0, 2);
		lcd_text("-Acceleromet<=", 0, 3);
		lcd_text("-Bluetooth    ", 0, 4);
		lcd_text("-Mouse         ", 0, 5);

		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			Menu_Option_Sensors_Encoder();
		}
		else if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			Menu_Option_Sensors_Accelerometr_Test();
		}
		else if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			Menu_Option_Sensors_Bluetooth();
		}
	}
}

void Menu_Option_Sensors_Bluetooth()
{
	while(1)
	{
		lcd_text("   Sensors:   ", 0, 0);
		lcd_text("-Encoder      ", 0, 1);
		lcd_text("-Accelerometr ", 0, 2);
		lcd_text("-Bluetooth <==", 0, 3);
		lcd_text("-Mouse        ", 0, 4);
		lcd_text("-Back         ", 0, 5);

		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			Menu_Option_Sensors_Accelerometr();
		}
		else if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			//Menu_Option_Sensors_Bluetooth_ON();
		}
		else if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			Menu_Option_Sensors_Mouse();
		}
	}
}

void Menu_Option_Sensors_Mouse() //OK
{
	while(1)
	{
		lcd_text("   Sensors:   ", 0, 0);
		lcd_text("-Accelerometr ", 0, 1);
		lcd_text("-Bluetooth    ", 0, 2);
		lcd_text("-Mouse     <==", 0, 3);
		lcd_text("-Back         ", 0, 4);
		lcd_text("-KTIR         ", 0, 5);

		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			Menu_Option_Sensors_Bluetooth();
		}
		else if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			Menu_Option_Sensors_Mouse_Test_ON();
		}
		else if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			Menu_Option_Sensors_Back();
		}
	}
}

void Menu_Option_Sensors_Back() //OK
{
	while(1)
	{
		lcd_text("   Sensors:   ", 0, 0);
		lcd_text("-Bluetooth    ", 0, 1);
		lcd_text("-Mouse        ", 0, 2);
		lcd_text("-Back      <==", 0, 3);
		lcd_text("-KTIR         ", 0, 4);
		lcd_text("-Sharp        ", 0, 5);

		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			Menu_Option_Sensors_Mouse();
		}
		else if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			Menu_Option_Sensors();
		}
		else if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			Menu_Option_Sensors_KTIR();
		}
	}
}

void Menu_Option_Time_Wait_ON() //OK
{
	lcd_clean();

	while(1)
	{
		lcd_text("     Wait:    ", 0, 0);
		lcd_variable(Start_Second,7,1);
		lcd_panel(Start_Second,5,2);

		if(BUTTON1_ON)
		{
			Start_Second--;
			while(BUTTON1_ON);
		}
		else if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			Menu_Option_Time_Wait();
		}
		else if(BUTTON3_ON)
		{
			Start_Second++;
			while(BUTTON3_ON);
		}

		if(Start_Second>5)Start_Second = 5;
		if(Start_Second<0)Start_Second = 0;
	}
}

void Menu_Option_Time_Delay_ON() //OK
{
	while(1)
	{
		lcd_text("     Delay:    ", 0, 0);
		lcd_variable(Start_Delay,7,1);
		lcd_panel(Start_Delay,5,2);
		lcd_text("               ", 0, 3);
		lcd_text("               ", 0, 4);
		lcd_text("               ", 0, 5);

		if(BUTTON1_ON)
		{
			Start_Delay-=5;
			while(BUTTON1_ON);
		}
		else if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			Menu_Option_Time_Delay();
		}
		else if(BUTTON3_ON)
		{
			Start_Delay+=5;
			while(BUTTON3_ON);
		}

		if(Start_Second>5)Start_Second = 5;
		if(Start_Second<0)Start_Second = 0;
	}
}

void Menu_Option_Display_Contrast_ON() //OK
{
	eeprom_busy_wait();
	Kontrast = eeprom_read_byte(&A_Kontrast);
	lcd_clean();

	while(1)
	{
		lcd_text("  Contrast:   ", 0, 0);
		lcd_variable(Kontrast,7,1);
		lcd_panel(Kontrast,250,2);

		if(BUTTON1_ON)
		{
			Kontrast=Kontrast-2;

			LCD_RESET_CLR;

			_delay_ms(2);
			LCD_RESET_SET;
			LCD_SCE_SET;

			lcd_write_byte(LCD_CMD, 0x21);
			lcd_write_byte(LCD_CMD, 0x05);
			lcd_write_byte(LCD_CMD, 0x13);
			lcd_write_byte(LCD_CMD, Kontrast);
			lcd_write_byte(LCD_CMD, 0x20);
			lcd_write_byte(LCD_CMD, 0x0C);

			while(BUTTON1_ON);
		}
		else if(BUTTON2_ON)
		{
			eeprom_busy_wait();
			eeprom_write_byte(&A_Kontrast,Kontrast);
			while(BUTTON2_ON);
			Menu_Option_Display();
		}
		else if(BUTTON3_ON)
		{
			Kontrast=Kontrast+2;

			LCD_RESET_CLR;

			_delay_ms(2);
			LCD_RESET_SET;
			LCD_SCE_SET;

			lcd_write_byte(LCD_CMD, 0x21);
			lcd_write_byte(LCD_CMD, 0x05);
			lcd_write_byte(LCD_CMD, 0x13);
			lcd_write_byte(LCD_CMD, Kontrast);
			lcd_write_byte(LCD_CMD, 0x20);
			lcd_write_byte(LCD_CMD, 0x0C);

			while(BUTTON3_ON);
		}

		if(Kontrast>250)Start_Second = 250;
		if(Kontrast<100)Kontrast = 100;
	}
}

void Menu_Option_Leds_Test_ON() //OK
{
	while(1)
	{
		KTIR(65535);
		if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			Menu_Option_Leds();
		}
	}
}

void Menu_Option_Sensors_KTIR_Test() //OK
{
	while(1)
	{
		lcd_text("     KTIR:    ", 0, 0);
		lcd_text("-Test      <==", 0, 1);
		lcd_text("-Sensitive    ", 0, 2);
		lcd_text("-Back         ", 0, 3);
		lcd_text("              ", 0, 4);
		lcd_text("              ", 0, 5);


		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			Menu_Option_Sensors_KTIR_Back();
		}
		else if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			Menu_Option_Sensors_KTIR_Test_ON();
		}
		else if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			Menu_Option_Sensors_KTIR_Sensitive();
		}
	}
}

void Menu_Option_Sensors_KTIR_Sensitive()
{
	while(1)
	{
		lcd_text("     KTIR:    ", 0, 0);
		lcd_text("-Test         ", 0, 1);
		lcd_text("-Sensitive <==", 0, 2);
		lcd_text("-Back         ", 0, 3);
		lcd_text("              ", 0, 4);
		lcd_text("              ", 0, 5);


		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			Menu_Option_Sensors_KTIR_Test();
		}
		else if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			//Menu_Option_Sensors_KTIR_Sensitive_ON();
		}
		else if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			Menu_Option_Sensors_KTIR_Back();
		}
	}
}

void Menu_Option_Sensors_KTIR_Back() //OK
{
	while(1)
	{
		lcd_text("     KTIR:    ", 0, 0);
		lcd_text("-Test         ", 0, 1);
		lcd_text("-Sensitive    ", 0, 2);
		lcd_text("-Back      <==", 0, 3);
		lcd_text("              ", 0, 4);
		lcd_text("              ", 0, 5);


		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			Menu_Option_Sensors_KTIR_Sensitive();
		}
		else if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			Menu_Option_Sensors_KTIR();
		}
		else if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			Menu_Option_Sensors_KTIR_Test();
		}
	}
}

void Menu_Option_Sensors_Sharp_Test()
{
	while(1)
	{
		lcd_text("     Sharp:   ", 0, 0);
		lcd_text("-Test      <==", 0, 1);
		lcd_text("-Back         ", 0, 2);
		lcd_text("-             ", 0, 3);
		lcd_text("              ", 0, 4);
		lcd_text("              ", 0, 5);


		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			//Menu_Option_Sensors_KTIR_Back();
		}
		else if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			//Menu_Option_Sensors_KTIR_Test_ON();
		}
		else if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			//Menu_Option_Sensors_KTIR_Sensitive();
		}
	}
}

void Menu_Option_Sensors_Accelerometr_Test() //OK
{
	while(1)
	{
		lcd_text("      Acc:    ", 0, 0);
		lcd_text("-Test      <==", 0, 1);
		lcd_text("-Enable       ", 0, 2);
		lcd_text("-Sens         ", 0, 3);
		lcd_text("-Back         ", 0, 4);
		lcd_text("              ", 0, 5);


		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			Menu_Option_Sensors_Accelerometr_Back();
		}
		else if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			Menu_Option_Sensors_Accelerometr_Test_ON();
		}
		else if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			Menu_Option_Sensors_Accelerometr_Enable();
		}
	}
}

void Menu_Option_Sensors_Accelerometr_Enable() //~~
{
	while(1)
	{
		lcd_text("      Acc:    ", 0, 0);
		lcd_text("-Test         ", 0, 1);
		lcd_text("-Enable    <==", 0, 2);
		lcd_text("-Sens         ", 0, 3);
		lcd_text("-Back         ", 0, 4);
		lcd_text("              ", 0, 5);


		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			Menu_Option_Sensors_Accelerometr_Test();
		}
		else if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			//Menu_Option_Sensors_Accelerometr_Enable_ON();
		}
		else if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			Menu_Option_Sensors_Accelerometr_Sens();
		}
	}
}

void Menu_Option_Sensors_Accelerometr_Sens() //~~
{
	while(1)
	{
		lcd_text("      Acc:    ", 0, 0);
		lcd_text("-Test         ", 0, 1);
		lcd_text("-Enable       ", 0, 2);
		lcd_text("-Sens      <==", 0, 3);
		lcd_text("-Back         ", 0, 4);
		lcd_text("              ", 0, 5);


		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			Menu_Option_Sensors_Accelerometr_Enable();
		}
		else if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			//Menu_Option_Sensors_Accelerometr_Enable_ON();
		}
		else if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			Menu_Option_Sensors_Accelerometr_Back();
		}
	}
}

void Menu_Option_Sensors_Accelerometr_Back() //OK
{
	while(1)
	{
		lcd_text("      Acc:    ", 0, 0);
		lcd_text("-Test         ", 0, 1);
		lcd_text("-Enable       ", 0, 2);
		lcd_text("-Sens         ", 0, 3);
		lcd_text("-Back      <==", 0, 4);
		lcd_text("              ", 0, 5);


		if(BUTTON1_ON)
		{
			while(BUTTON1_ON);
			Menu_Option_Sensors_Accelerometr_Sens();
		}
		else if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			Menu_Option_Sensors_Accelerometr();
		}
		else if(BUTTON3_ON)
		{
			while(BUTTON3_ON);
			Menu_Option_Sensors_Accelerometr_Test();
		}
	}
}

void Menu_Option_Sensors_Accelerometr_Test_ON() //~~
{
	int x=0;
	int y=0;
	int z=0;

	while(1)
	{
		x = accelerometer_x();
		y = accelerometer_y();
		z = accelerometer_z();

		lcd_variable(x,10,0);
		lcd_panel(50,100,1);
		lcd_variable(y,10,2);
		lcd_panel(50,100,3);
		lcd_variable(z,10,4);
		lcd_panel(50,100,5);

		if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			Menu_Option_Sensors_Accelerometr_Test();
		}
	}
}

void Menu_Option_Sensors_KTIR_Test_ON()
{
	char test[] = "00000000";

	while(1)
	{
		if(test == 0)
		{
			lcd_text("     Test:    ", 0, 0);
			lcd_text("              ", 0, 1);
			lcd_text(" KTIR:        ", 0, 2);
			lcd_text("   00000000   ", 0, 3);
			lcd_text("              ", 0, 4);
			lcd_text("              ", 0, 5);
		}
		else
		{
			lcd_text("     Test:    ", 0, 0);
			lcd_text("              ", 0, 1);
			lcd_text(" KTIR:        ", 0, 2);
			lcd_text(test, 3, 3);
			lcd_text("              ", 0, 4);
			lcd_text("              ", 0, 5);
		}
		if(KTIR1_ON && test[0] == '0')
			test[0] = '1';
		else if(KTIR2_ON && test[1] == '0')
			test[1] = '1';
		else if(KTIR3_ON && test[2] == '0')
			test[2] = '1';
		else if(KTIR4_ON && test[3] == '0')
			test[3] = '1';
		else if(KTIR5_ON && test[4] == '0')
			test[4] = '1';
		else if(KTIR6_ON && test[5] == '0')
			test[5] = '1';
		else if(KTIR7_ON && test[6] == '0')
			test[6] = '1';
		else if(KTIR8_ON && test[7] == '0')
			test[7] = '1';
		if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			Menu_Option_Sensors_KTIR_Test();
		}
	}
}

void Menu_Option_Sensors_Mouse_Test_ON()
{
	int mouse_x = 0,x = 0;
	int mouse_y = 0,y = 0;

	while(1)
	{
		mouse_x = Mouse_PozX(x);
		mouse_y = Mouse_PozY(y);
		x = mouse_x;
		y = mouse_y;

		lcd_text("     Mouse:   ", 0, 0);
		lcd_text("-X Poz        ", 5, 1);
		lcd_variable(mouse_x,7,2);
		lcd_text("-Y Poz        ", 5, 3);
		lcd_variable(mouse_y,7,4);

		if(BUTTON2_ON)
		{
			while(BUTTON2_ON);
			Menu_Option_Sensors_Mouse();
		}
	}
}
