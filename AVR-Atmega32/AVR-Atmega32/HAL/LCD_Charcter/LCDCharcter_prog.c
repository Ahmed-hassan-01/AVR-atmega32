
#include "../../SERVICES/STDTypes.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "LCDCharcter_CFG.h"

#define F_CPU 16000000
#include "util\delay.h"

void HAL_LCDCharacter_WriteIns8bit(u8 data)
{
	MCAL_DIO_WritePort(LCD_Port,data);	
	MCAL_DIO_WritePin(LCD_PinRS,LOW);
		MCAL_DIO_WritePin(LCD_PinRw,LOW);
		MCAL_DIO_WritePin(LCD_PinEn,HIGH);

	
	_delay_ms(1);
	MCAL_DIO_WritePin(LCD_PinEn,LOW);
		_delay_ms(1);

	
}
void HAL_LCDCharacter_WriteINS4bit(u8 data)
{
	if(LCD_Pins_Setup==FIRST4PINS)
	{MCAL_DIO_WriteFirst4bitPort(LCD_Port,data);
	MCAL_DIO_WritePin(LCD_PinRS,LOW);
	MCAL_DIO_WritePin(LCD_PinRw,LOW);
			MCAL_DIO_WritePin(LCD_PinEn,HIGH);

	
		_delay_ms(1);
			MCAL_DIO_WritePin(LCD_PinEn,LOW);
					_delay_ms(1);


	}
	if(LCD_Pins_Setup==LAST4PINS)
	{	MCAL_DIO_Writelast4bitPort(LCD_Port,data);
		MCAL_DIO_WritePin(LCD_PinRS,LOW);
		MCAL_DIO_WritePin(LCD_PinRw,LOW);
	    MCAL_DIO_WritePin(LCD_PinEn,HIGH);
		_delay_ms(1);
	    MCAL_DIO_WritePin(LCD_PinEn,LOW);
		_delay_ms(1);

	}
	
}

void HAL_LCDCharacter_WriteData8bit(u8 data)
{  MCAL_DIO_WritePort(LCD_Port,data);
	MCAL_DIO_WritePin(LCD_PinRS,HIGH);
	MCAL_DIO_WritePin(LCD_PinRw,LOW);
    MCAL_DIO_WritePin(LCD_PinEn,HIGH);
	_delay_ms(1);
   MCAL_DIO_WritePin(LCD_PinEn,LOW);
	_delay_ms(1);

	
}
void HAL_LCDCharacter_WriteData4bit(u8 data)
{
	if(LCD_Pins_Setup==FIRST4PINS)
	{	MCAL_DIO_WriteFirst4bitPort(LCD_Port,data);
		MCAL_DIO_WritePin(LCD_PinRS,HIGH);
		MCAL_DIO_WritePin(LCD_PinRw,LOW);
		
		 MCAL_DIO_WritePin(LCD_PinEn,HIGH);
		 _delay_ms(1);
		 MCAL_DIO_WritePin(LCD_PinEn,LOW);
		 _delay_ms(1);
	}
	if(LCD_Pins_Setup==LAST4PINS)
	{	
		MCAL_DIO_Writelast4bitPort(LCD_Port,data);
		MCAL_DIO_WritePin(LCD_PinRS,HIGH);
		MCAL_DIO_WritePin(LCD_PinRw,LOW);
		
		 MCAL_DIO_WritePin(LCD_PinEn,HIGH);
		 _delay_ms(1);
		 MCAL_DIO_WritePin(LCD_PinEn,LOW);
		 _delay_ms(1);
	}
	
}

void HAL_LCDCharacter_Init8bit(void)
{
	_delay_ms(50);
	HAL_LCDCharacter_WriteIns8bit(0b00111000);//Function et  0b00 1 DL N F --  //DL=1 ->8bit    DL=0 ->4bit  //N=0 -> 1 line display   N=1 -> 2 line display   //F=0 -> 5*7dots     F=1 -> 5*10dots 
	HAL_LCDCharacter_WriteIns8bit(0b00001100);//Display OFF ON ob00001 D C B  //D=0:display OFF D=1:display ON   //c=0: Cursor OFF c=1: Cursor ON //B=0:blink cursor OFF B=1:blink cursor ON
	HAL_LCDCharacter_WriteIns8bit(0b00000001);//Display clear
	_delay_ms(1);
	HAL_LCDCharacter_WriteIns8bit(0b00000010);//Entry Mode ob000000 I/D  sh   //I/D Increament Mode =1:increament  //sh shifmode =0: NOshift
	
}

void HAL_LCDCharacter_Init4bit(void)
{
	
	_delay_ms(50);
	//Function et  0b00 1 DL N F --  //DL=1 ->8bit    DL=0 ->4bit  //N=0 -> 1 line display   N=1 -> 2 line display   //F=0 -> 5*7dots     F=1 -> 5*10dots
	HAL_LCDCharacter_WriteINS4bit(2);
	HAL_LCDCharacter_WriteINS4bit(2);
	HAL_LCDCharacter_WriteINS4bit(12);//Display clear
	
	
	//Display OFF ON ob00001 D C B  //D=0:display OFF D=1:display ON   //c=0: Cursor OFF c=1: Cursor ON //B=0:blink cursor OFF B=1:blink cursor ON
	HAL_LCDCharacter_WriteINS4bit(0);
	HAL_LCDCharacter_WriteINS4bit(12);
		
HAL_LCDCharacter_WriteINS4bit(0);//desplay clear
HAL_LCDCharacter_WriteINS4bit(1);
		_delay_ms(1);
	//Entry Mode ob000000 I/D  sh   //I/D Increament Mode =1:increament  //sh shifmode =0: NOshift
	HAL_LCDCharacter_WriteINS4bit(0);
	HAL_LCDCharacter_WriteINS4bit(6);
	
}

void HAL_LCDCharacter_clear(void)
{
	if(LCD_setup==LCD_4bit)
	{
		HAL_LCDCharacter_WriteINS4bit(0);//desplay clear 4bit
		HAL_LCDCharacter_WriteINS4bit(1);
		_delay_ms(1);
	}
	else if(LCD_setup==LCD_8bit)
	{
		HAL_LCDCharacter_WriteIns8bit(0b00000001);//Display clear 8bit
		_delay_ms(1);
	}
	
}



void HAL_LCDCharacter_WriteCharacter(u8 character)
{
	if(LCD_setup==LCD_4bit)
	{
		HAL_LCDCharacter_WriteData4bit(character);//desplay clear 4bit
		
	}
	else if(LCD_setup==LCD_8bit)
	{
		HAL_LCDCharacter_WriteData8bit(character);//Display clear 8bit
		
	}
	
	
}

void HAL_LCDCharacter_WriteNumber(s32 number)
{
	u8 str[32];
	s8 i=0,j=0;
	if(number==0)
	{
		HAL_LCDCharacter_WriteCharacter('0');
	}
	if(number<0)
	{
		HAL_LCDCharacter_WriteCharacter('-');
		number*=-1;
	}
	
	
	while(number)
	{
		str[i]=number%10;
		
		number=number/10;
		i++;
	}
	
	for(j=i-1;j>=0;j--)
	{
		HAL_LCDCharacter_WriteCharacter(str[j]+'0');
	}
	
}
	
	
	
void HAL_LCDCharacter_Writebinary(u8 number)
{
	s8 i=0;
	
	for(i=7;i>=0;i--)
	{
		
		HAL_LCDCharacter_WriteCharacter(GetBit(number,i)+'0');
		
	}
	
	
	
}


void HAL_LCDCharacter_Writehex(u8 number)
{
	u8 Lni= number & 0x0f;
	
	u8 Hni= number >>4;
	
	
	if(Hni<10)
	{
		HAL_LCDCharacter_WriteCharacter(Hni+'0');
	}
	if(Hni>10)
	{
		HAL_LCDCharacter_WriteCharacter((Hni-10)+'A');
	}
	if(Lni<10)
	{
		HAL_LCDCharacter_WriteCharacter(Lni+'0');
	}
	if(Lni>10)
	{
		HAL_LCDCharacter_WriteCharacter((Lni-10)+'A');
	}
	

	
	
}




void HAL_LCDCharacter_WriteString(char* str)
{
	int i=0;
	for(i=0;str[i];i++)
	{
		HAL_LCDCharacter_WriteCharacter(str[i]);
	}
	
}



void HAL_LCDCharacter_SetCursor(u8 line ,u8 cell)
{
	if(LCD_setup==LCD_4bit)
	{
		if(line ==0 )
		{
			HAL_LCDCharacter_WriteINS4bit(0x80|cell);
		}
		else if(line ==1)
		{
			HAL_LCDCharacter_WriteINS4bit(0xc0|cell);
		}
		
	}
	else if(LCD_setup==LCD_8bit)
	{
		
		if(line ==0 )
		{
			HAL_LCDCharacter_WriteIns8bit(0x80|cell);
		}
		else if(line ==1)
		{
			HAL_LCDCharacter_WriteIns8bit(0xC0|cell);
		}
		
	}
	
}


void HAL_LCDCharacter_WriteStringEndFirst(char* str)
{
	int i=0,length=0;
	for(i=0;str[i];i++)
	{
		length++;
	}HAL_LCDCharacter_SetCursor(0,length);
	for(i=length-1;i>=0;i--)
	{
		HAL_LCDCharacter_WriteCharacter(str[i]);
// 		HAL_LCDCharacter_WriteIns8bit(0b00000011);  //Entry Mode ob000000 I/D  sh   //I/D Increament Mode =1:increament  //sh shifmode =0: NOshift
		HAL_LCDCharacter_WriteIns8bit(0b00010000);
		HAL_LCDCharacter_WriteIns8bit(0b00010000);


		_delay_ms(300);
	}
	
}


void HAL_LCDCharacter_StringSnake(u8* str)
{
	int x=0,y=0,i,length=0;
	for(i=0;str[i];i++)
	{
		length++;
	}
	while(1)
	{
		
		HAL_LCDCharacter_SetCursor(x,y);
		HAL_LCDCharacter_WriteString(str);
		_delay_ms(50);
		HAL_LCDCharacter_SetCursor(x,y);
		HAL_LCDCharacter_WriteCharacter(' ');
		y++;
		if(y==16&&x==0)
		{
			x=1;
			y=0;
			HAL_LCDCharacter_clear();
		}
		else if(y==16&&x==1)
		{
			x=0;
			y=0;
		HAL_LCDCharacter_clear();

		}
	}
	
	
	
	
}
