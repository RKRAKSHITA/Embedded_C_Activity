/**
 *@file main.c
 *@author Vichkshana (jsvichkshana@gmail.com)
 *@brief Main application for seat heater project
 *@version 0.1
 *@date 2021-04-29
 *
 *@copyright Copyright (c) 2021
 *
 */

#include <avr/io.h>
#include <util/delay.h>
#include "LED.h"
#include "ADC.h"
#include "PWM.h"
#include "USART.h"

/**
 *@brief Main funtion to adjust temperature of seat as per requirements
 *
 *@return int 
 */
int main(void)
{
    peripheral_init();
    InitADC();
    InitPwm();
    USARTInit(103);
    uint16_t temp;
    while(1)
    {
        if((!(PIND&(1<<PD0)))&&((!(PIND&(1<<PD1)))))
        {
            change_led_state(LED_ON);
            temp=ReadADC(0);
            _delay_ms(200);
            out_pwm(temp);
        }
        else
        {
          change_led_state(LED_OFF);
          _delay_ms(LED_OFF_TIME);
        }

    }

    return 0;
}
