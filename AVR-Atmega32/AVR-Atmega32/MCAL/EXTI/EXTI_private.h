/*
 * EXTI_private.h
 *
 * Created: 9/22/2024 11:08:13 PM
 *  Author: momen
 */ 


#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define    GICR           *((volatile u8*)0x5B)

#define	  GICR_INT1       7
#define	  GICR_INT0		  6
#define	  GICR_INT2       5
 


#define    GIFR              *((volatile u8*)0x5A)

#define	 GIFR_INTF1       7
#define	 GIFR_INTF0		  6
#define	 GIFR_INTF2       5


#define    MCUCR             *((volatile u8*)0x55)

#define	  MCUCR_ISC11       3
#define	  MCUCR_ISC10		2
#define	  MCUCR_ISC01       1
#define	  MCUCR_ISC00       0





#define    MCUCSR            *((volatile u8*)0x54)

#define	  MCUCSR_ISC2       6


#endif /* EXTI_PRIVATE_H_ */