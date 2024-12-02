

#ifndef SEGEMENT_CFG_H_
#define SEGEMENT_CFG_H_
#include "../../SERVICES/STDTypes.h"
#include "../../MCAL/DIO/DIO_int.h"

typedef enum{
	
	FIRST4PINS,
	LAST4PINS,
	
	}HAL_7Segment_SetupPins_t;

#define HAl_7Segment_EnablePin1  PINB1

 #define HAl_7Segment_EnablePin2  PINB2

#define HAl_7Segment_Port1      PA

#define SetupPins   FIRST4PINS

#endif /* 7SEGEMENT_CFG_H_ */