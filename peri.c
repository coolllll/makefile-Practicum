#include <avr/io.h>
#include "peri.h"
void init_peripheral()
{
	DDRC &= ~(1<<PC3 | 1<<PC4);
	DDRC |= (1<<PC0 | 1<<PC1 | 1<<PC2);
	PORTC &= ~(1<<PC0 | 1<<PC1 | 1<<PC2);
	PORTC |= 1<<PC3;
	PORTC &=~(1<<PC4);
}
void set_led(uint8_t pin,uint8_t state)
{
	PORTC &= ~(1<<pin);
	PORTC |= state<<pin;
}
void set_led_value(uint8_t value)
{
	set_led(PC0,(value>>PC0)&1);
	set_led(PC1,(value>>PC1)&1);
	set_led(PC2,(value>>PC2)&1);
}
void clear_led()
{
	set_led(PC0,0);
	set_led(PC1,0);
	set_led(PC2,0);
}
uint16_t read_adc(uint8_t channel)
{
	ADMUX =(0<<REFS1)|(1<<REFS0)|(0<<ADLAR)|(channel & 0b1111);
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADSC);
	while((ADCSRA & (1<<ADSC)))
		;
	return ADC;
}
