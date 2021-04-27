/**
 * @file project_main.c
 * @author Rakshita.R.K ()
 * @brief Project to Blink an LED at 1000ms ON and 500 ms OFF Interval
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "project_config.h"

#include "user_utils.h"
#include "blink.h"

/**
 * @brief Initialize all the Peripherals and pin configurations
 * 
 */
void peripheral_init(void)
{
	/* Configure LED Pin */
	DDRB |= (1 << DDB0); //SET B0=1
	DDRD &= ~(1<<PD0);
	DDRD &= ~(1<<PD1);
	PORTD |= (1<<PD0); //SET D0
	PORTD |= (1<<PD1);
}

void change_led_state(uint8_t state)
{
	LED_PORT = (state << LED_PIN);
}


/**
 * @brief Main function where the code execution starts
 * 
 * @return int Return 0 if the program completes successfully
 * @note PORTB0 is in sink config. i.e when pin is Low, the LED will turn OFF
 * @note PORTB0 is in sink config. i.e when pin is High, the LED will turn ON
 */
int main(void)
{
	/* Initialize Peripherals */
	peripheral_init();

	for(;;)
	{
        if((!(PIND&(1<<PD0)))&&((!(PIND&(1<<PD1)))))
		{
			change_led_state(LED_ON);
			delay_ms(LED_ON_TIME);
		}
		else
		{
        	change_led_state(LED_OFF);
			delay_ms(LED_OFF_TIME);	
		}
	}
	return 0;
}
