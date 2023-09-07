#include <avr/io.h>
#include <util/delay.h>

#define RED 0
#define YELLOW 1 
#define GREEN 2


int main(void)
{
	
	DDRC |= 0b111;
	
	/* Replace with your application code */
	while (1)
	{
		PORTC |= (1<<RED);
		_delay_ms(2000);
		PORTC &= ~(1<<RED);
		PORTC |= (1<<YELLOW);
		_delay_ms(2000);
		PORTC &= ~(1<<YELLOW);
		PORTC |= (1<<GREEN);
		_delay_ms(2000);
		PORTC &= ~(1<<GREEN);	
	}
}

