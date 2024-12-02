
#include "../../SERVICES/STDTypes.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "7Segement_CFG.c"
#include "7Segement_int.h"


 #define F_CPU 8000000
 #include "util\delay.h"

void HAL_seven_segment_mux(int n)
{
	
	u8 d0=n%10;
	u8 d10=n/10;

   MCAL_DIO_WritePin(HAl_7Segment_EnablePin1, HIGH);
	MCAL_DIO_WritePin(HAl_7Segment_EnablePin2, LOW);
	if(SetupPins==FIRST4PINS)
	{
		 MCAL_DIO_WritePort(HAl_7Segment_Port1,d0);
	}
	else
	{
		  MCAL_DIO_Writelast4bitPort(HAl_7Segment_Port1,d0);
	}
  
	
	_delay_ms(10);
	MCAL_DIO_WritePin(HAl_7Segment_EnablePin2, HIGH);
	MCAL_DIO_WritePin(HAl_7Segment_EnablePin1, LOW);
	if(SetupPins==FIRST4PINS)
	{
		MCAL_DIO_WritePort(HAl_7Segment_Port1,d10);
	}
	else
	{
		MCAL_DIO_Writelast4bitPort(HAl_7Segment_Port1,d10);
	}
	
	

		_delay_ms(10);



	}
	
	
void HAL_seven_segment(int n)
{

// u8 d0=n%10;
// u8 d10=n/10;
	MCAL_DIO_WritePort(HAl_7Segment_Port1,n);
	
}