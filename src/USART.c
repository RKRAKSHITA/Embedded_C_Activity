/**
 *@file uart.c
 *@author Rakshita.R.K()
 *@brief 
 *@version 0.1
 *@date 2021-04-29
 *
 *@copyright Copyright (c) 2021
 *
 */
#include <avr/io.h>
#include "USART.h"

/**
 *@brief Initialise USART to print temperature values on monitor
 *
 *@param ubrr_val baud rate
 */
void USARTInit(uint16_t ubrr_val)
{
    //SET BAUD RATE
    UBRR0L=ubrr_val;
    UBRR0H=(ubrr_val>>8)&0x00ff;
    UCSR0C=(1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);
    UCSR0B=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);

}

/**
 *@brief To write the data to UDR and print in serial monitor
 *
 *@param data 
 */
void USARTWriteData(uint8_t data)
{
    while(!(UCSR0A & (1<<UDRE0)))
    {

    }
    UDR0=data;
}
