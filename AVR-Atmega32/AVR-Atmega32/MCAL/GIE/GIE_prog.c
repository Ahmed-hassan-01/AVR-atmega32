



#include "../../SERVICES/STDTypes.h"
#include "../../SERVICES/Math.h"

#include "GIE_int.h"

#include "GIE_private.h"

void GIE_Enable(void)
{
	
	SetBit(SREG,SREG_I);
	
}



void GIE_Disable(void)
{
	
	ClrBit(SREG,SREG_I);

	
}