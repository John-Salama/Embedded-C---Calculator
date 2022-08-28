/*
 * LCD.c
 *
 * Created: 3/24/2022 8:53:16 PM
 *  Author: john
 */ 
#include "LCD.h"


void LCD_CMD(unsigned char cmd)
{
	LCD_DATA = cmd;
	PORTC &= ~(1<<rs);
	PORTC &= ~(1<<rw);
	PORTC |= (1<<en);
	_delay_ms(2);
	PORTC &= ~(1<<en);
}


void LCD_Write(unsigned char data)
{
	LCD_DATA = data;
	PORTC |= (1<<rs);
	PORTC &= ~(1<<rw);
	PORTC |= (1<<en);
	_delay_ms(2);
	PORTC &= ~(1<<en);
}


void LCD_INTI(void)
{
	LCD_CMD(0x38);
	_delay_ms(2);
	LCD_CMD(0x01);
	_delay_ms(2);
// 	LCD_CMD(0x02);
// 	_delay_ms(2);
	LCD_CMD(0x06);
	_delay_ms(2);
	LCD_CMD(0x80);
	_delay_ms(2);
	LCD_CMD(0x0C); //on the screen and initialize the cursor
	_delay_ms(2);
}


void LCD_STRING(char *Str)
{
	for (int i =0; Str[i]!=0;i++)
	{
		LCD_Write(Str[i]);
	}
}


void LCD_POSITION(unsigned char X , unsigned char Y)
{
	uint8_t ADRS = 0;
	if (X == 0)	// 0 for the first row
	ADRS = 0X80;
	else if (X ==1)    // 1 for the second column
	ADRS = 0XC0;
	if(Y <16 && Y >= 0) // y = 0~15 --> the number of coloumn
	ADRS += Y;
	LCD_CMD(ADRS);
}


void LCD_INT(int X)
{
	char str[10];
	for (int i = 0; i < 10; i++)
	str[i] =' ';
	if (X>=0)
	itoa(X,str,10);
	LCD_STRING(str);
}


void LCD_FLOAT(float X)
{
	char str[10];
	for (int i = 0; i < 10; i++)
	str[i] = ' ';
	if (X>=0)
	sprintf(str,"%3.2f",X);
	LCD_STRING(str);
}