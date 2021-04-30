/**
 *@file LED.c
 *@author Rakshita.R.K()
 *@brief 
 *@version 0.1
 *@date 2021-04-29
 *
 *@copyright Copyright (c) 2021
 *
 */
#include "LED.h"
/**
 *@brief initialise port for switches
 *
 */
void peripheral_init(void)
{
	/* Configure LED Pin */
	DDRB |= (1 << DDB0);
	DDRD &= ~(1<<PD0);
	DDRD &= ~(1<<PD1);
	PORTD |= (1<<PD0); //SET D0
	PORTD |= (1<<PD1);
}
/**
 *@brief Change the state of LED
 *
 *@param state 
 */

void change_led_state(uint8_t state)
{
	LED_PORT = (state << LED_PIN);
}
