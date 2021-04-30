/**
 *@file pwm.c
 *@author Rakshita.R.K()
 *@brief 
 *@version 0.1
 *@date 2021-04-29
 *
 *@copyright Copyright (c) 2021
 *
 */
#include <avr/io.h>
#include "ADC.h"
#include <util/delay.h>
#include "USART.h"

/**
 *@brief Initialse timer 1 with 64 prescalar
 *
 */
void InitPwm(void)
{
    TCCR1A |= (1<<COM1A1)|(1<<WGM10)|(1<<WGM11);
    TCCR1B |= (1<<WGM12)|(1<CS11)|(1<<CS10); //64 prescalar
    DDRB |= (1<<PB1);
}

/**
 *@brief Generate PWM signal based on desired duty cycle and write the corresponding temp in serial monitor
 *
 *@param temp 
 */

void out_pwm(uint16_t temp)
{
    if(temp>=0 && temp<=200)
    {
        OCR1A=205;          //20% duty cycle
        USARTWriteData(20);
    }
    if(temp>=201 && temp<=500)
    {
        OCR1A=410;          //40% duty cycle
        USARTWriteData(25);
    }
    if(temp>=501 && temp<=700)
    {
        OCR1A=717;          //70% duty cycle
        USARTWriteData(29);
    }
    if(temp>=701 && temp<=1024)
    {
        OCR1A=973;          //95% duty cycle
        USARTWriteData(33);
    }

}
