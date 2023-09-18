#include <avr/io.h>
#include <util/delay.h>

#define RED 0
#define YELLOW 1 
#define GREEN 2

void delay_2s(void);


int main(void)
{
	
	DDRC |= 0b111;
	
	
	/* Replace with your application code */
	while (1)
	{
		PORTC |= (1<<RED);
		delay_2s();
		PORTC &= ~(1<<RED);
		PORTC |= (1<<YELLOW);
		delay_2s();
		PORTC &= ~(1<<YELLOW);
		PORTC |= (1<<GREEN);
		delay_2s();
		PORTC &= ~(1<<GREEN);	
	}
}

void delay_2s(){
	char overflows = 0;
	TCNT0 = 0;
	TCCR0 = 0b101;
	while(1){
		if (TIFR & (1<<TOV0)){
			overflows += 1;
			TIFR = 1;
		}
		if (overflows == 7 & TCNT0 == 168){
			break;
		}
	}
	TIFR = 1;
	TCCR0 = 0;
}

