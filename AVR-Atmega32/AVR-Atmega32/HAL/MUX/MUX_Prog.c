
#include "../../SERVICES/STDTypes.h"
#include "../../MCAL/DIO/DIO_int.h"

#include "MUX_int.h"
#include "MUX_Cfg.h"
//#include "MUX_Private.h"


 void HAL_MUX_Initiate(void)
{

MCAL_DIO_Init(HAL_MUXENABLEPIN,HIGH);
		 
MCAL_DIO_Init(HAL_MUXControlPIN0,HIGH);
MCAL_DIO_Init(HAL_MUXControlPIN1,HIGH);
MCAL_DIO_Init(HAL_MUXControlPIN2,HIGH);
MCAL_DIO_Init(HAL_MUXENABLEPIN,HIGH);



// MCAL_DIO_Init(HAL_MUXinputPIN0,HIGH);
// MCAL_DIO_Init(HAL_MUXinputPIN1,HIGH);
// MCAL_DIO_Init(HAL_MUXinputPIN2,HIGH);
// MCAL_DIO_Init(HAL_MUXinputPIN3,HIGH);
// MCAL_DIO_Init(HAL_MUXinputPIN4,HIGH);
// MCAL_DIO_Init(HAL_MUXinputPIN5,HIGH);
// MCAL_DIO_Init(HAL_MUXinputPIN6,HIGH);
// MCAL_DIO_Init(HAL_MUXinputPIN7,HIGH);

}

void HAL_MUX_WritePin(HAL_MUX_InputPINS_t u8PinX)
	{
		switch(u8PinX)
		{
			case HAL_MUXinputPIN0 :	MCAL_DIO_WritePin(HAL_MUXENABLEPIN,LOW);					 MCAL_DIO_WritePin(HAL_MUXControlPIN0,LOW);MCAL_DIO_WritePin(HAL_MUXControlPIN1,LOW);MCAL_DIO_WritePin(HAL_MUXControlPIN2,LOW);break;
			case HAL_MUXinputPIN1 :	MCAL_DIO_WritePin(HAL_MUXENABLEPIN,LOW);					 MCAL_DIO_WritePin(HAL_MUXControlPIN0,HIGH);MCAL_DIO_WritePin(HAL_MUXControlPIN1,LOW);MCAL_DIO_WritePin(HAL_MUXControlPIN2,LOW);break;
			case HAL_MUXinputPIN2 :	MCAL_DIO_WritePin(HAL_MUXENABLEPIN,LOW);					 MCAL_DIO_WritePin(HAL_MUXControlPIN0,LOW);MCAL_DIO_WritePin(HAL_MUXControlPIN1,HIGH);MCAL_DIO_WritePin(HAL_MUXControlPIN2,LOW);break;
			case HAL_MUXinputPIN3 :	MCAL_DIO_WritePin(HAL_MUXENABLEPIN,LOW);					 MCAL_DIO_WritePin(HAL_MUXControlPIN0,HIGH);MCAL_DIO_WritePin(HAL_MUXControlPIN1,HIGH);MCAL_DIO_WritePin(HAL_MUXControlPIN2,LOW);break;
			case HAL_MUXinputPIN4 :	MCAL_DIO_WritePin(HAL_MUXENABLEPIN,LOW);					 MCAL_DIO_WritePin(HAL_MUXControlPIN0,LOW);MCAL_DIO_WritePin(HAL_MUXControlPIN1,LOW);MCAL_DIO_WritePin(HAL_MUXControlPIN2,HIGH);break;
			case HAL_MUXinputPIN5 :	MCAL_DIO_WritePin(HAL_MUXENABLEPIN,LOW);					 MCAL_DIO_WritePin(HAL_MUXControlPIN0,HIGH);MCAL_DIO_WritePin(HAL_MUXControlPIN1,LOW);MCAL_DIO_WritePin(HAL_MUXControlPIN2,HIGH);break;
			case HAL_MUXinputPIN6 :	MCAL_DIO_WritePin(HAL_MUXENABLEPIN,LOW);					 MCAL_DIO_WritePin(HAL_MUXControlPIN0,LOW);MCAL_DIO_WritePin(HAL_MUXControlPIN1,HIGH);MCAL_DIO_WritePin(HAL_MUXControlPIN2,HIGH);break;
			case HAL_MUXinputPIN7 :	MCAL_DIO_WritePin(HAL_MUXENABLEPIN,LOW);					 MCAL_DIO_WritePin(HAL_MUXControlPIN0,HIGH);MCAL_DIO_WritePin(HAL_MUXControlPIN1,HIGH);MCAL_DIO_WritePin(HAL_MUXControlPIN2,HIGH);break;

		}
	

}
