


#ifndef DIO_INT_H_
#define DIO_INT_H_

#include "../../SERVICES/STDTypes.h"

typedef enum 
{
	PA,
	PB,
	PC,
	PD,
	
	}MCAL_DIO_Port_t;


typedef enum{
	
	LOW,
	HIGH,
	
	}MCAL_DIO_Voltage_t;








typedef enum
{
	PINA0=0,
	PINA1,
	PINA2,	
    PINA3,
    PINA4,
    PINA5,
    PINA6,
    PINA7,
	
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,    
	
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	
	TOTAL_Pins,
}MCAL_DIO_Pin_t;


typedef enum
{
	INPULL,
	INFREE,
	OUTPUT,
	
}MCAL_DIO_PinStatus_t;

typedef enum
{
	PORTINPUT=0,
	PORTOUTPUT=1,
	
}MCAL_DIO_PortStatus_t;




void MCAL_DIO_Init(MCAL_DIO_Pin_t Pin, MCAL_DIO_PinStatus_t Status);
void MCAL_DIO_WritePin(MCAL_DIO_Pin_t Pin, MCAL_DIO_Voltage_t Volt);
MCAL_DIO_Voltage_t MCAL_DIO_ReadPin(MCAL_DIO_Pin_t Pin);
void MCAL_DIO_TogglePin(MCAL_DIO_Pin_t Pin);
void MCAL_DIO_WritePort(MCAL_DIO_Port_t Port,u8 data);

void MCAL_DIO_InitPORT(MCAL_DIO_Port_t Port,MCAL_DIO_PortStatus_t status);

u8  MCAL_DIO_readPort(MCAL_DIO_Port_t Port);
MCAL_DIO_Voltage_t MCAL_DIO_ReadPin(MCAL_DIO_Pin_t Pin);

void MCAL_DIO_Writelast4bitPort(MCAL_DIO_Port_t Port,u8 data);

void MCAL_DIO_WriteFirst4bitPort(MCAL_DIO_Port_t Port,u8 data);

#endif /* DIO_INT_H_ */