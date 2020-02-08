/*
 * Menu.h
 *
 *  Created on: 14-08-2012
 *      Author: Mateusz
 */

#ifndef MENU_H_
#define MENU_H_

#include <avr/io.h>
#include <avr/iom128.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include <avr/signal.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include "Shift_register.h"
#include "Buzzer.h"
#include "Nokia3310.h"
#include "Button.h"
#include "KTIR.h"
#include "Accelerometer.h"
#include "Mause.h"

void Menu_Start();
void Menu_Debug();
void Menu_Option();

void Menu_Start_Timer();
void Menu_Option_Time();
void Menu_Option_Display();
void Menu_Option_Leds();
void Menu_Option_Sensors();
void Menu_Option_Back();

void Menu_Option_Time_Delay();
void Menu_Option_Time_Wait();
void Menu_Option_Time_Back();

void Menu_Option_Display_Contrast();
void Menu_Option_Display_Enable();
void Menu_Option_Display_Back();

void Menu_Option_Leds_Test();
void Menu_Option_Leds_Enable();
void Menu_Option_Leds_Back();

void Menu_Option_Sensors_KTIR();
void Menu_Option_Sensors_Sharp();
void Menu_Option_Sensors_Encoder();
void Menu_Option_Sensors_Accelerometr();
void Menu_Option_Sensors_Bluetooth();
void Menu_Option_Sensors_Back();

void Menu_Option_Time_Wait_ON();
void Menu_Option_Time_Delay_ON();

void Menu_Option_Display_Contrast_ON();
void Menu_Option_Display_Enable_ON();
void Menu_Option_Leds_Test_ON();

void Menu_Option_Sensors_KTIR_Test();
void Menu_Option_Sensors_Sharp_Test();
void Menu_Option_Sensors_Accelerometr_Test();
void Menu_Option_Sensors_Accelerometr_Enable();
void Menu_Option_Sensors_Accelerometr_Sens();
void Menu_Option_Sensors_Accelerometr_Back();
void Menu_Option_Sensors_Accelerometr_Test_ON();

#endif /* MENU_H_ */
