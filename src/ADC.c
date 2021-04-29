#include <avr/io.h>
#include <util/delay.h>

void InitADC()
{
    ADMUX=(1<<REFS0);
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
}
 uint16_t ReadADC(uint8_t ch)
 {
   //Select ADC channel ch 0 to 7
   ADMUX&=0xf8;
   ch=ch&0b00000111;
   ADMUX|=ch;
   //Start single conversation
   ADCSRA|=(1<<ADSC);
   //Wait for conversation to complete
   while(!(ADCSRA&(1<<ADIF)));
   //Clear ADIF by adding 1 to it
   ADCSRA|=(1<<ADIF);
   return(ADC);
 }




