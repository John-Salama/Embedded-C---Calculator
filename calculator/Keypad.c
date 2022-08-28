/*
 * KEYPAD1.c
 *
 * Created: 3/24/2022 8:55:10 PM
 *  Author: john
 */ 
#include "Keypad.h"

const char matrix [4][4] = {
{'7','8','9','/'},
{'4','5','6','x'},
{'1','2','3','-'},
{'C','0','=','+'}
};

char keypad_2(void) {
	DDRD |= (1<<PORTD0) | (1<<PORTD1) | (1<<PORTD2) | (1<<PORTD3);
	DDRD &= ~ ((1<<PORTD4) | (1<<PORTD5) | (1<<PORTD6) | (1<<PORTD7));

	for(int i=0; i<4; i++) {
		PORTD = (1<<i);
		for (int j = 0 ; j < 4 ; j++){
			if(PIND & (1<<(j+4)))
			return matrix[i][j];
		}
	}
	return 'N';
}

char KEYPAD(void)
{
	PORTD |=  (1<<PIND0);
	PORTD &= ~(1<<PIND1);
	PORTD &= ~(1<<PIND2);
	PORTD &= ~(1<<PIND3);
	if (PIND & 0x10) return '7';
	if (PIND & 0x20) return '8';
	if (PIND & 0x40) return '9';
	if (PIND & 0x80) return'/';

	PORTD &= ~(1<<PIND0);
	PORTD |=  (1<<PIND1);
	PORTD &= ~(1<<PIND2);
	PORTD &= ~(1<<PIND3);
	if (PIND & 0x10) return '4';
	if (PIND & 0x20) return '5';
	if (PIND & 0x40) return '6';
	if (PIND & 0x80) return'x';

	PORTD &= ~(1<<PIND0);
	PORTD &= ~(1<<PIND1);
	PORTD |=  (1<<PIND2);
	PORTD &= ~(1<<PIND3);
	if (PIND & 0x10) return '1';
	if (PIND & 0x20) return '2';
	if (PIND & 0x40) return '3';
	if (PIND & 0x80) return'-';

	PORTD &= ~(1<<PIND0);
	PORTD &= ~(1<<PIND1);
	PORTD &= ~(1<<PIND2);
	PORTD |= (1<<PIND3);
	if (PIND & 0x10) return'C';
	if (PIND & 0x20) return '0';
	if (PIND & 0x40) return'=';
	if (PIND & 0x80) return'+';

	return 'N';

}

