/*
 * LCDCharcter_Int.h
 *
 * Created: 9/16/2024 11:42:09 PM
 *  Author: momen
 */ 


#ifndef LCDCHARCTER_INT_H_
#define LCDCHARCTER_INT_H_

typedef enum{
	LCD_4bit,
	LCD_8bit,
}LCD_setup;


typedef enum{
	FIRST4PINS,
	LAST4PINS
	}LCD_Pins_Setup;


void HAL_LCDCharacter_Init8bit(void);

void HAL_LCDCharacter_Init4bit(void);

void HAL_LCDCharacter_WriteIns8bit(u8 data);
void HAL_LCDCharacter_WriteINS4bit(u8 data);

void HAL_LCDCharacter_WriteData8bit(u8 data);
void HAL_LCDCharacter_WriteData4bit(u8 data);

void HAL_LCDCharacter_WriteCharacter(u8 character);

void HAL_LCDCharacter_WriteNumber(s32 number);

void HAL_LCDCharacter_Writebinary(u8 number);

void HAL_LCDCharacter_Writehex(u8 number);

void HAL_LCDCharacter_WriteString(char* str);

void HAL_LCDCharacter_clear(void);

void HAL_LCDCharacter_SetCursor(u8 line ,u8 cell);

void HAL_LCDCharacter_StringSnake(u8 *str);
void HAL_LCDCharacter_WriteStringEndFirst(char* str);

#endif /* LCDCHARCTER_INT_H_ */