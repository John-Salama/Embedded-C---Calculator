/*
 * calculator.c
 *
 * Created: 3/23/2022 11:36:23 PM
 * Author : john
 */ 

#include "calculator.h"
#include "LCD.h"


int main(void)
{
    DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0x0F;
	LCD_INTI();
	LCD_POSITION(0,5);
	LCD_STRING("HELLO");
	_delay_ms(30);
	while (1) 
	{	
		calculator();	
	}
}

