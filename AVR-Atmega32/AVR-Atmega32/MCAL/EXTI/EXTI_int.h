/*
 * EXTI_int.h
 *
 * Created: 9/22/2024 11:08:24 PM
 *  Author: momen
 */ 


#ifndef EXTI_INT_H_
#define EXTI_INT_H_
typedef enum{
	LOW_LEVEL,
	FALLING_EDGE,
	RAISING_EDGE,
	ONCHANGE,
	
}INTERRUPT_PinSetup;






void EXTI_INT0Init(void);
void EXTI_INT1Init(void);
void EXTI_INT2Init(void);



#endif /* EXTI_INT_H_ */