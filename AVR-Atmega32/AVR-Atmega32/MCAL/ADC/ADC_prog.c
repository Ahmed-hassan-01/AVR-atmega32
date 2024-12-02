

#include "../../SERVICES/STDTypes.h"
#include "../../SERVICES/MemMap.h"
#include "../../SERVICES/Math.h"


#include "ADC_int.h"
#include "ADC_cfg.h"


static u16* ADC_pu16Reading=NULL;
static void(*ADC_pvCallBackNotificationFunc)(void)=NULL;
ADC_BusyStatus  busystate=NOTBUSY;
void ADC_Init(ADC_Vref_et ref,ADC_Prescaler_et scaler)
{
	/*prescaler*/
	
	ADCSRA&=0XF8;//B11111000
	scaler&=0x07;//000000111
	ADCSRA|=scaler;
// 	
// 	SetBit(ADCSRA,ADCSRA_ADPS0);
// 		SetBit(ADCSRA,ADCSRA_ADPS1);
// 	SetBit(ADCSRA,ADCSRA_ADPS2);


	
	/* v ref*/
	
	switch(ref)
	{
		case VREF_AREF:
		ClrBit(ADMUX,ADMUX_REFS1);
		ClrBit(ADMUX,ADMUX_REFS0);
		break;
		case VREF_AVCC:
		
		ClrBit(ADMUX,ADMUX_REFS1);
		SetBit(ADMUX,ADMUX_REFS0);
		break;
		case VREF_256:
		
		SetBit(ADMUX,ADMUX_REFS1);
		SetBit(ADMUX,ADMUX_REFS0);
		break;
		
	}
	/* Activate Left adjust result */
	//	SetBit(ADMUX,ADMUX_ADLAR);
	
	/* ADC enable*/
	SetBit(ADCSRA,ADCSRA_ADEN);
	
	
	

	
}

u16 ADC_Read(ADC_Channel_et ch)
{
	u16 adc;
	
	/* set mux with channel*/
	ADMUX &= 0b11100000;
	ADMUX |= ch;
	
	/* start conversion */
	SetBit(ADCSRA,ADCSRA_ADSC);
	
	
	/* wait ADC to end conversion*/
	/*busy waiting until conversion ended*/
	while(GetBit(ADCSRA,ADCSRA_ADIF)==0);
	
	/*clear the conversion complete flag*/
	SetBit(ADCSRA,ADCSRA_ADIF);
	
	
	
	/* get read*/
	
	
	adc=(ADCH<<8)|ADCL;
	adc=ADC;
	return ADC;
}





u16 ADC_Read_Synchronisation(ADC_Channel_et ch,u16* Copy_pu16Reading)
{
	u16 adc;
	u16 counter=0;
	ADC_ErrorStatus status=OK;
	
	if(busystate==NOTBUSY)
	{	
		busystate =BUSY;
		/* set mux with channel*/
	ADMUX &= 0b11100000;
	ADMUX |= ch;
	
	/* start conversion */
	SetBit(ADCSRA,ADCSRA_ADSC);
	
	
	/* wait ADC to end conversion*/
	/*busy waiting until conversion ended*/
	while(GetBit(ADCSRA,ADCSRA_ADIF)==0 && counter<ADC_TimeOut)
	{
		counter++;
	}
	
	if(counter==ADC_TimeOut)
	{
		
		/*the conversion doesn't complete*/
		status =NOK;
		
		
	}
	else
	{
		/*the conversion complete*/

		/*clear the conversion complete flag*/
	SetBit(ADCSRA,ADCSRA_ADIF);
	
	
	
	/* get read*/
	

	*Copy_pu16Reading=ADC;
	busystate =NOTBUSY;

	}
	
	}
	else
	{
		
	}
	return status;
}



u16 ADC_Read_ASynchronisation(ADC_Channel_et ch,u16* Copy_Pu16Reading,void (*Copy_PvNotificationFunc)(void))
{
	u16 adc;
	ADC_ErrorStatus status=OK;
	if(busystate==NOTBUSY)
	{
		if(( Copy_Pu16Reading==NULL)||(Copy_PvNotificationFunc==NULL))
	{
		status=NULLPOINTER;
	}
	else
	{
		/*initialize the reading variable globally*/
		ADC_pu16Reading=Copy_Pu16Reading;
	
	/*initialize the callback notification func globally*/

	ADC_pvCallBackNotificationFunc=Copy_PvNotificationFunc;
		
	/* set mux with channel*/
	ADMUX &= 0b11100000;
	ADMUX |= ch;
	
	/* start conversion */
	SetBit(ADCSRA,ADCSRA_ADSC);
	
	
	/* ADC interrupt enable*/
	SetBit(ADCSRA,ADCSRA_ADIE);


		
		
	}
	}
	
	
	return status;
	
}


void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	busystate=NOTBUSY;
	/*Read ADC Result*/
	*ADC_pu16Reading=ADC;
	
	/*invoke the callback notification func*/
	ADC_pvCallBackNotificationFunc();
	
	/*  disable ADC conversion complete interrupt  */
	ClrBit(ADCSRA,ADCSRA_ADIE);
	
}