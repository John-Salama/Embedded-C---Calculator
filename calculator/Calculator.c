/*
 * Calculator.c
 *
 * Created: 3/24/2022 8:57:57 PM
 *  Author: john
 */ 
 
#include "calculator.h"
#include "LCD.h"
#include "Keypad.h"

void calculator(void) 
{
	//initialize and clear the LCD
	LCD_INTI(); // 8bit / 2 line 
	
	char x[10] = "";
	char op = ' ';
	char y[10] = "";
	int px = 0;
	int py = 0;
	char key1 = ' ';
	char key2 = ' ';
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while(keypad_2() != '+' && keypad_2() != '-' && keypad_2() != '/' && keypad_2() != 'x' && keypad_2() != 'C' && keypad_2() != '=')
	{
		key1 = keypad_2();
		if(key1 != 'N' && key1 != '+' && key1 != '-' && key1 != '/' && key1 != 'x' && key1 != 'C' && key1 != '='){
			
			x[px] = key1;
			_delay_ms(10);
			px++;
			LCD_Write(key1);
			_delay_ms(10);
		}
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	_delay_ms(10);
	op = keypad_2();
	if(op != 'C'){
	LCD_Write(op);
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while(keypad_2() != 'C' && keypad_2() != '=' && op != 'C')
	{
		key2 = keypad_2();
		if(key2 != 'N' && key2 != '+' && key2 != '-' && key2 != '/' && key2 != 'x' && key2 != 'C' && key2 != '='){
				
			_delay_ms(10);		
			y[py] = keypad_2();

			py++;
			LCD_Write(key2);
			_delay_ms(10);
		}
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(op != 'C'){
px = atoi(x);
py = atoi(y);
if(keypad_2()=='='){
LCD_CMD(0x01);
if(op == '+')
LCD_INT(px+py);
if(op == '-')
LCD_INT(px-py);
if(op == 'x')
LCD_INT(px*py);
if(op == '/')
LCD_FLOAT((float)px/py);
LCD_POSITION(1,5);
LCD_STRING("Press C");
}
while(keypad_2() != 'C'){}
LCD_CMD(0x01);
}	
}