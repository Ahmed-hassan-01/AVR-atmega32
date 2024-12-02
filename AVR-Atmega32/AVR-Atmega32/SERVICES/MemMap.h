/*
 * MemMap.h
 *
 * Created: 9/10/2024 1:51:09 PM
 *  Author: momen
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_

/*DIO REGISTERS*/

#define DDRA  (*(volatile char*) 0X3A)
#define PORTA  (*(volatile char*) 0X3B)
#define PINA  (*(volatile char*) 0X39)

#define DDRB  (*(volatile char*) 0X37)
#define PORTB  (*(volatile char*) 0X38)
#define PINB  (*(volatile char*) 0X36)

#define DDRC  (*(volatile char*) 0X34)
#define PORTC  (*(volatile char*) 0X35)
#define PINC  (*(volatile char*) 0X33)


#define DDRD  (*(volatile char*) 0X31)
#define PORTD  (*(volatile char*) 0X32)
#define PIND  (*(volatile char*) 0X30)


/*ADC REGISTERS*/
#define ADMUX  (*(volatile char*) 0X27)
#define ADMUX_REFS1  7 
#define ADMUX_REFS0  6 
#define ADMUX_ADLAR  5

#define ADCSRA  (*(volatile char*) 0x26)
#define ADCSRA_ADPS0 0
#define ADCSRA_ADPS1 1
#define ADCSRA_ADPS2 2
#define ADCSRA_ADIE  3
#define ADCSRA_ADIF  4
#define ADCSRA_ADATE 5
#define ADCSRA_ADSC  6
#define ADCSRA_ADEN  7

#define ADCH  (*(volatile char*) 0X25)

#define ADCL  (*(volatile char*) 0X24)

#define  ADC    (*(volatile u16*)0x24)


/*UART registers*/
#define UDR (*(volatile char*) 0x2C)
#define UCSRA (*(volatile char*) 0x2B)
#define UCSRA_RXC     7
#define UCSRA_TXC     6
#define UCSRA_UDRE    5
#define UCSRA_FE      4
#define UCSRA_DOR     3
#define UCSRA_PE      2
#define UCSRA_U2X     1
#define UCSRA_MPCM    0



#define UCSRB (*(volatile char*) 0x2A)
#define UCSRB_RXCIE     7
#define UCSRB_TXCIE     6
#define UCSRB_UDRIE     5
#define UCSRB_RXEN      4
#define UCSRB_TXEN      3
#define UCSRB_UCSZ2     2
#define UCSRB_RXB8      1
#define UCSRB_TXB8      0

#define UCSRC (*(volatile char*) 0x40)
#define UCSRC_URSEL     7
#define UCSRC_UMSEL     6
#define UCSRC_UPM1      5
#define UCSRC_UPM0      4
#define UCSRC_USBS      3
#define UCSRC_UCSZ1     2
#define UCSRC_UCSZ0     1
#define UCSRC_UCPOL     0

#define UBRRL (*(volatile char*) 0x29)



#endif /* MEMMAP_H_ */