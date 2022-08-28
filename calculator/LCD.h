/*
 * LCD.h
 *
 * Created: 3/26/2022 2:59:40 AM
 *  Author: john
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define rs PC0
#define rw PC1
#define en PC2
#define LCD_DATA PORTB

//send command to LCD
void LCD_CMD(unsigned char cmd);

//send char to LCD
void LCD_Write(unsigned char data);

//initialize the LCD
void LCD_INTI(void);

//Send string to the LCD
void LCD_STRING(char *Str);

//change the position of the cursor
void LCD_POSITION(unsigned char X , unsigned char Y);

//Send int to the LCD
void LCD_INT(int X);

//Send float to the LCD
void LCD_FLOAT(float X);





#endif /* LCD_H_ */