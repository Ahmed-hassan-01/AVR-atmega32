/*
 * Keybad_CFG.h
 *
 * Created: 9/20/2024 8:39:56 PM
 *  Author: momen
 */ 


#ifndef KEYBAD_CFG_H_
#define KEYBAD_CFG_H_

#define ROWS 4
#define COL  4




typedef enum{
	keypad_PinRow1=PINA0,
	keypad_PinRow2=PINB4,
	keypad_PinRow3=PINA2,
	keypad_PinRow4=PINB5,
				  
	}Keybad_PinsRow;


typedef enum{
	
	
	keypad_PinCol1=PINA4,
	keypad_PinCol2=PINB6,
	keypad_PinCol3=PINA6,
	keypad_PinCol4=PINB7,
	
}Keybad_PinsCol;

typedef struct{
	Keybad_PinsRow row;
	Keybad_PinsCol col;
	
	}Keybad_link_Row_col;

Keybad_link_Row_col keybadlinkARR[4]={{PINA0,PINA4},
									   {PINB4,PINB6},
										   {PINA2,PINA6},
											   {PINB5,PINB7} };


u8 Kebad_ARR[4][4]={{'7','8','9','/'},
					{'4','5','6','*'},
					{'1','2','3','-'},
					{'c','0','=','+'}};





#endif /* KEYBAD_CFG_H_ */