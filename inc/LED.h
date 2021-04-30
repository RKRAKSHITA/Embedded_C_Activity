 /**
 *@file LED.h
 *@author Rakshita.R.K()
 *@brief Header files to change state of LED
 *@version 0.1
 *@date 2021-04-29
 *
 *@copyright Copyright (c) 2021
 *
 */
#ifndef LED_H_INCLUDED
#define LED_H_INCLUDED

#define LED_ON 	(0x01)			/**< LED state HIGH */
#define LED_OFF	(0x00)			/**< LED state LOW */

#define LED_ON_TIME     (1000)  /**< LED ON time in milli seconds  */
#define LED_OFF_TIME    (500)   /**< LED OFF time in milli seconds */

#define F_CPU 16000000UL 	/**< Clock Frequency of MCU is 16 MHz */

#define LED_PORT (PORTB)    /**< LED Port Number */
#define LED_PIN  (PORTB0)   /**< LED Pin number  */

#include <avr/io.h>

void peripheral_init(void);
void change_led_state(uint8_t state);

#endif // LED_H_INCLUDED
