/*
 * LCDCharcter_CFG.h
 *
 * Created: 9/16/2024 11:42:36 PM
 *  Author: momen
 */ 


#ifndef LCDCHARCTER_CFG_H_
#define LCDCHARCTER_CFG_H_

#include "LCDCharcter_Int.h"
// protues config

#define LCD_Port   PA
/*
#define LCD_Pin0   PINA0
#define LCD_Pin1   PINA1
#define LCD_Pin2   PINA2
#define LCD_Pin3   PINA3
#define LCD_Pin4   PINA4
#define LCD_Pin5   PINA5
#define LCD_Pin6   PINA6
#define LCD_Pin7   PINA7
*/

#define LCD_PinEn   PINB2
#define LCD_PinRw   PINB1
#define LCD_PinRS   PINC0

#define LCD_Pins_Setup LAST4PINS
#define LCD_setup LCD_8bit

/*
#define LCD_Port   PC
#define LCD_PinEn   PIND5
#define LCD_PinRw   PIND6
#define LCD_PinRS   PIND7

#define LCD_Pins_Setup LAST4PINS
#define LCD_setup LCD_8bit
*/
#endif /* LCDCHARCTER_CFG_H_ */