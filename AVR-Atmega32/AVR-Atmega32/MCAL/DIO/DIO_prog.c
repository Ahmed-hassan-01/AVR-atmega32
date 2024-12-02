
#include "../../SERVICES/STDTypes.h"
#include "../../SERVICES/MemMap.h"
#include "../../SERVICES/Math.h"


#include "DIO_int.h"
#include "DIO_private.h"
#include "DIO_cfg.h"



void MCAL_DIO_Init(MCAL_DIO_Pin_t Pin, MCAL_DIO_PinStatus_t Status)
{ 
	volatile  ptru8 RegDDRPtr;
volatile  ptru8 RegPORTPtr;
		if(Pin<=PINA7)
		{	RegDDRPtr = (u8*)&DDRA;
			RegPORTPtr=(u8*)&PORTA;
		}
		else if (Pin<=PINB7)
		{
			RegDDRPtr= (u8*)&DDRB;
			RegPORTPtr=(u8*)&PORTB;
			Pin-=PINB0;
		}
		else if (Pin<=PINC7)
		{
			RegDDRPtr= (u8*)&DDRC;
			RegPORTPtr=(u8*)&PORTC;
			Pin-=PINC0;

		}
		
		else if (Pin<=PIND7)
		{
			RegDDRPtr= (u8*)&DDRD;
			RegPORTPtr=(u8*)&PORTD;
			Pin-=PIND0;

		}
		
		
		switch(Status){
			case INPULL: ClrBit(*RegDDRPtr,Pin);SetBit(*RegPORTPtr,Pin);break;
			case INFREE: ClrBit(*RegDDRPtr,Pin);ClrBit(*RegPORTPtr,Pin);break;
			case OUTPUT: SetBit(*RegDDRPtr,Pin);break;
		}
	

	
// 	switch(Status){
// 		
// 		case INPUT: 
// 		if(Pin<=PINA7)
// 		{ClrBit(DDRA,Pin);break; }
// 		else if (Pin<=PINB7)	
// 		{
// 			ClrBit(DDRB,(Pin-PINA7));break; 
// 		}
// 		else if (Pin<=PINC7)
// 		{
// 			ClrBit(DDRC,(Pin-PINB7));break;
// 		}
// 		
// 		else if (Pin<=PIND7)
// 		{
// 			ClrBit(DDRD,(Pin-PINC7));break;
// 		}
// 		
// 		
// 		
// 		case OUTPUT:
// 		if(Pin<=PINA7)
// 		{SetBit(DDRA,Pin);break; }
// 		else if (Pin<=PINB7)
// 		{
// 			SetBit(DDRB,(Pin-PINB0));break;
// 		}
// 		else if (Pin<=PINC7)
// 		{
// 			SetBit(DDRC,(Pin-PINC0));break;
// 		}
// 		
// 		else if (Pin<=PIND7)
// 		{
// 			SetBit(DDRD,(Pin-PIND0));break;
// 		}
// 		
// 	}
	
	
}



void MCAL_DIO_WritePin(MCAL_DIO_Pin_t Pin, MCAL_DIO_Voltage_t Volt)
{
	
	switch(Volt)
	{
		
	case LOW:
	if(Pin<=PINA7)
	{ClrBit(PORTA,Pin);break; }
	else if (Pin<=PINB7)
	{
		ClrBit(PORTB,(Pin-PINB0));break;
	}
	else if (Pin<=PINC7)
	{
		ClrBit(PORTC,(Pin-PINC0));break;
	}
	
	else if (Pin<=PIND7)
	{
		ClrBit(PORTD,(Pin-PIND0));break;
	}
	
	
	
	case HIGH:
	if(Pin<=PINA7)
	{SetBit(PORTA,Pin);break; }
	else if (Pin<=PINB7)
	{
		SetBit(PORTB,(Pin-PINB0));break;
	}
	else if (Pin<=PINC7)
	{
		SetBit(PORTC,(Pin-PINC0));break;
	}
	
	else if (Pin<=PIND7)
	{
		SetBit(PORTD,(Pin-PIND0));break;
	}
	
}
	
	
	
}



MCAL_DIO_Voltage_t MCAL_DIO_ReadPin(MCAL_DIO_Pin_t Pin)
{
	MCAL_DIO_Voltage_t Volt;
	if(Pin<=PINA7)
	{
		Volt= GetBit(PINA,Pin);
		
	}
	else if(Pin<=PINB7)
	{
		Volt= GetBit(PINB,(Pin-PINB0));
		
	}
   else if(Pin<=PINC7)
	{
		Volt= GetBit(PINC,(Pin-PINC0));
		
	}
  else if(Pin<=PIND7)
	{
		Volt= GetBit(PIND,(Pin-PIND0));
		
	}
	return Volt;
}

void MCAL_DIO_TogglePin(MCAL_DIO_Pin_t Pin)
{
	if(Pin<=PINA7)
	{
		 ToggleBit(PORTA,Pin);
		
	}
	else if(Pin<=PINB7)
	{
		 ToggleBit(PORTB,(Pin-PINB0));
		
	}
	else if(Pin<=PINC7)
	{
		 ToggleBit(PORTB,(Pin-PINC0));
		
	}
	else if(Pin<=PIND7)
	{
		 ToggleBit(PORTB,(Pin-PIND0));
		
	}
	
	
}
	
	
	
void MCAL_DIO_WritePort(MCAL_DIO_Port_t Port,u8 data)
{
	switch(Port)
	{ case PA: PORTA = data;break;
	  case PB: PORTB = data;break;
	  case PC: PORTC = data;break;
	  case PD: PORTD = data;break;
		
	}
	
}	


	


void MCAL_DIO_Writelast4bitPort(MCAL_DIO_Port_t Port,u8 data)
{		data =data&0x0f;
	switch(Port)
	{ case PA: PORTA   = PORTA&0x0f; PORTA= PORTA ^ (data<<4)  ;break;
		case PB: PORTB = (data<<4)  ; break;
		case PC: PORTC = (data<<4)  ; break;
		case PD: PORTD = (data<<4)  ; break;
		
	}
	
}


void MCAL_DIO_WriteFirst4bitPort(MCAL_DIO_Port_t Port,u8 data)
{		data =data&0x0f;
	switch(Port)
	{   case PA: PORTA = PORTA&0xf0; PORTA= PORTA ^ (data)  ;break;
		case PB: PORTB = PORTB&0xf0; PORTB= PORTB ^ (data)  ; break;
		case PC: PORTC = PORTC&0xf0; PORTC= PORTC ^ (data)  ; break;
		case PD: PORTD = PORTD&0xf0; PORTD= PORTD ^ (data)  ; break;
		
	}
	
}



void MCAL_DIO_InitPORT(MCAL_DIO_Port_t Port,MCAL_DIO_PortStatus_t status)
{
	
	switch(status)
	{
		
	
	case PORTOUTPUT:
			switch(Port)
			{
				case PA: DDRA=0xff;break;
				case PB: DDRB=0xff;break;
				case PC: DDRC=0xff;break;
				case PD: DDRD=0xff;break;

			}break;
	case PORTINPUT:	
	switch(Port)
	{
		case PA: DDRA=0;break;
		case PB: DDRB=0;break;
		case PC: DDRC=0;break;
		case PD: DDRD=0;break;

	}break;
	}
}







u8  MCAL_DIO_readPort(MCAL_DIO_Port_t Port)
{
		u8 data;
switch(Port)
{	case PA: data= PINA ; break;
	case PB:data= PINB ;break;
	case PC:data= PINC ;break;
	case PD:data= PIND;break;
	
}


}