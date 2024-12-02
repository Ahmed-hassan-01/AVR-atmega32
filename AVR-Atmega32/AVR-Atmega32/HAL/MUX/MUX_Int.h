/*
 * MUX_Int.h
 *
 * Created: 9/10/2024 5:06:31 PM
 *  Author: momen
 */ 


#ifndef MUX_INT_H_
#define MUX_INT_H_

#include "../../SERVICES/STDTypes.h"
/*
typedef enum{
MUXENABLEPIN,
MUXinputPIN0,
MUXinputPIN1,
MUXinputPIN2,
MUXinputPIN3,
MUXinputPIN4,
MUXinputPIN5,
MUXinputPIN6,
MUXinputPIN7,

MUXControlPIN0,
MUXControlPIN1,
MUXControlPIN2,

MUXOutputPIN, 
}MUX_Pin_t;


*/
typedef enum{

	MUX_LOW,
    MUX_HIGH,
	
}MUX_Value_t;


typedef enum{
HAL_MUXinputPIN0,
HAL_MUXinputPIN1,
HAL_MUXinputPIN2,
HAL_MUXinputPIN3,
HAL_MUXinputPIN4,
HAL_MUXinputPIN5,
HAL_MUXinputPIN6,
HAL_MUXinputPIN7,
	
}HAL_MUX_InputPINS_t;



void HAL_MUX_Initiate(void);


void HAL_MUX_WritePin(HAL_MUX_InputPINS_t u8PinX);



#endif /* MUX_INT_H_ */