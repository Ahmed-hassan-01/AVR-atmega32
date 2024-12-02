/*
 * ADC_int.h
 *
 * Created: 9/24/2024 12:50:42 AM
 *  Author: momen
 */ 


#ifndef ADC_INT_H_
#define ADC_INT_H_


typedef enum{
	VREF_AREF,
	VREF_AVCC,
	VREF_256,
}ADC_Vref_et;

typedef enum{
	CH_0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7
	
}ADC_Channel_et;



typedef enum{
	ADC_SCALER_2=1,
	ADC_SCALER_4,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128,
}ADC_Prescaler_et;

typedef enum{
	OK,
	NOK,
	NULLPOINTER,
	
	}ADC_ErrorStatus;

typedef enum{
	IDLE,
	BUSY,
	NOTBUSY,
	
}ADC_BusyStatus;


void ADC_Init(ADC_Vref_et ref,ADC_Prescaler_et scaler);

u16 ADC_Read(ADC_Channel_et ch);


u16 ADC_Read_Synchronisation(ADC_Channel_et ch,u16* Copy_pu16Reading);

u16 ADC_Read_ASynchronisation(ADC_Channel_et ch,u16* Copy_Pu16Reading,void (*Copy_PvNotificationFunc)(void));




#endif /* ADC_INT_H_ */