
#include "../../SERVICES/STDTypes.h"

#include "../../SERVICES/Math.h"


#include "EXTI_int.h"
#include "EXTI_cfg.h"
#include "EXTI_private.h"




void EXTI_INT0Init(void)
{
	/*set sense control for int0*/
	
	 if(INT0_setup==FALLING_EDGE)
	 {
		 ClrBit(MCUCR,MCUCR_ISC00);
		 SetBit(MCUCR,MCUCR_ISC01);
		 
	 }
	 else if(INT0_setup==LOW_LEVEL)
	{
		ClrBit(MCUCR,MCUCR_ISC00);
		ClrBit(MCUCR,MCUCR_ISC01);
	}
	 else if(INT0_setup==RAISING_EDGE)
	 {
		 SetBit(MCUCR,MCUCR_ISC00);
		 SetBit(MCUCR,MCUCR_ISC01);
	 }
	 else if(INT0_setup==ONCHANGE)
	 {
		 SetBit(MCUCR,MCUCR_ISC00);
		 ClrBit(MCUCR,MCUCR_ISC01);
	 }
	
	
	/* Peripheral  Interupt Enable for INT0 */
	
	 SetBit(GICR,GICR_INT0);
	
}













void EXTI_INT1Init(void)
{
	
	 if(INT1_setup==FALLING_EDGE)
	 {
		 ClrBit(MCUCR,MCUCR_ISC10);
		 SetBit(MCUCR,MCUCR_ISC11);
		 
	 }
	 else if(INT1_setup==LOW_LEVEL)
	 {
		 ClrBit(MCUCR,MCUCR_ISC10);
		 ClrBit(MCUCR,MCUCR_ISC11);
	 }
	 else if(INT1_setup==RAISING_EDGE)
	 {
		 SetBit(MCUCR,MCUCR_ISC10);
		 SetBit(MCUCR,MCUCR_ISC11);
	 }
	 else if(INT1_setup==ONCHANGE)
	 {
		 SetBit(MCUCR,MCUCR_ISC10);
		 ClrBit(MCUCR,MCUCR_ISC11);
	 }
	 
	 
	 /* Peripheral  Interupt Enable for INT1 */
	 
	 SetBit(GICR,GICR_INT1);
	
	
	
}

void EXTI_INT2Init(void)
{
	if(INT2_setup==RAISING_EDGE)
	{
			SetBit(MCUCSR,MCUCSR_ISC2);
	}
	else if (INT2_setup==RAISING_EDGE)
	{
	
	    SetBit(MCUCSR,MCUCSR_ISC2);

	}
	
	
	/* Peripheral  Interrupt Enable for INT2 */
	
	SetBit(GICR,GICR_INT2);
}

