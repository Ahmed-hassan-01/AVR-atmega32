
#include "SERVICES/MemMap.h"

#include "MCAL/DIO/DIO_int.h"

#include "HAL/MUX/MUX_Int.h"
#include "HAL/MUX/MUX_Cfg.h"
#include "HAL/7Segement/7Segement_int.h"
#include "HAL/LCD_Charcter/LCDCharcter_Int.h"
#include "MCAL/ADC/ADC_int.h"
#include "MCAL/COMMUNCATION/UART_int.h"
// 
// 
// #define DDRA  ((volatile char*) 0X3A)
// #define PORTA  ((volatile char*) 0X3B)
// #define PINA  ((volatile char*) 0X39)
// 
// #define DDRB  ((volatile char*) 0X37)
// #define PORTB  ((volatile char*) 0X38)
// #define PINB  ((volatile char*) 0X36)
// 
// #define DDRC  ((volatile char*) 0X34)
// #define PORTC  ((volatile char*) 0X35)
// #define PINC  ((volatile char*) 0X33)
// 
// 
// #define DDRD  ((volatile char*) 0X31)
// #define PORTD  ((volatile char*) 0X32)
// #define PIND  ((volatile char*) 0X30)
 #define F_CPU 16000000
 #include "util\delay.h"
// 
// 
// 
// 
// void SetBit(char *port,char bit)
// {
// 	
// 	*port=*port | (1<<bit);  
// 	
// 	
// }
// 
// void ClearBit(char *port,char bit)
// {
// 	*port=*port & (~(1<<bit));
// 	
// }
// 
// int GetBit(char *port,char bit)
// {
// 	return (*port>>bit) & 1;
// 	
// 	
// }
// 
// void TurnOn_8leds(char *PORT)
// {
// 	/*first task*/
// 		
// 		SetBit(PORT,0);
// 		_delay_ms(1000);
// 		ClearBit(PORT,0);
// 		SetBit(PORT,1);
// 		_delay_ms(1000);
// 		ClearBit(PORT,1);
// 		SetBit(PORT,2);
// 		_delay_ms(1000);
// 		ClearBit(PORT,2);
// 		SetBit(PORT,3);
// 		_delay_ms(1000);
// 		ClearBit(PORT,3);
// 		SetBit(PORT,4);
// 		_delay_ms(1000);
// 		ClearBit(PORT,4);
// 		SetBit(PORT,5);
// 		_delay_ms(1000);
// 		ClearBit(PORT,5);
// 		SetBit(PORT,6);
// 		_delay_ms(1000);
// 		ClearBit(PORT,6);
// 		SetBit(PORT,7);
// 		_delay_ms(1000);
// 		ClearBit(PORT,7);
// 		
// 	
// 	
// }
// 
// void Rverse_TurnOn_8leds(char *PORT)
// {
// 	SetBit(PORT,7);
// 	_delay_ms(1000);
// 	ClearBit(PORT,7);
// 	SetBit(PORT,6);
// 	_delay_ms(1000);
// 	ClearBit(PORT,6);
// 	SetBit(PORT,5);
// 	_delay_ms(1000);
// 	ClearBit(PORT,5);
// 	SetBit(PORT,4);
// 	_delay_ms(1000);
// 	ClearBit(PORT,4);
// 	SetBit(PORT,3);
// 	_delay_ms(1000);
// 	ClearBit(PORT,3);
// 	SetBit(PORT,2);
// 	_delay_ms(1000);
// 	ClearBit(PORT,2);
// 	SetBit(PORT,1);
// 	_delay_ms(1000);
// 	ClearBit(PORT,1);
// 	SetBit(PORT,0);
// 	_delay_ms(1000);
// 	ClearBit(PORT,0);
// 	
// 	
// 	
// }
// 
// void LoopInsid_8Led(char* PORT)
// {
// 	SetBit(PORT,0);
// 	SetBit(PORT,7);
// 	_delay_ms(1000);
// 	ClearBit(PORT,0);
// 	ClearBit(PORT,7);
// 	
// 	SetBit(PORT,1);
// 	SetBit(PORT,6);
// 	_delay_ms(1000);
// 	ClearBit(PORT,1);
// 	ClearBit(PORT,6);
// 
// 	SetBit(PORT,2);
// 	SetBit(PORT,5);
// 	_delay_ms(1000);
// 	ClearBit(PORT,2);
// 	ClearBit(PORT,5);
// 	
// 	SetBit(PORT,3);
// 	SetBit(PORT,4);
// 	_delay_ms(1000);
// 	ClearBit(PORT,3);
// 	ClearBit(PORT,4);
// 	
// 	
// 	
// }
// 
// 
// void LoopOutside_8Leds(char *PORT)
// {
// 	SetBit(PORT,3);
// 	SetBit(PORT,4);
// 	//_delay_ms(1000);
// 	ClearBit(PORT,3);
// 	ClearBit(PORT,4);
// 	
// 	SetBit(PORT,2);
// 	SetBit(PORT,5);
// 	_delay_ms(1000);
// 	ClearBit(PORT,2);
// 	ClearBit(PORT,5);
// 	
// 	SetBit(PORT,1);
// 	SetBit(PORT,6);
// 	_delay_ms(1000);
// 	ClearBit(PORT,1);
// 	ClearBit(PORT,6);
// 	
// 	SetBit(PORT,0);
// 	SetBit(PORT,7);
// 	//_delay_ms(1000);
// 	ClearBit(PORT,0);
// 	ClearBit(PORT,7);
// 	
// 	
// }
// 
// void LoopInsid_8LedWithoutTurnoff(char* PORT)
// {
// 	SetBit(PORT,0);
// 	SetBit(PORT,7);
// 	_delay_ms(1000);
// 	/*ClearBit(PORT,0);
// 	ClearBit(PORT,7);
// 	*/
// 	SetBit(PORT,1);
// 	SetBit(PORT,6);
// 	_delay_ms(1000);
// 	/*ClearBit(PORT,1);
// 	ClearBit(PORT,6);*/
// 
// 	SetBit(PORT,2);
// 	SetBit(PORT,5);
// 	_delay_ms(1000);
// 	/*ClearBit(PORT,2);
// 	ClearBit(PORT,5);*/
// 	
// 	SetBit(PORT,3);
// 	SetBit(PORT,4);
// 	_delay_ms(1000);
// /*	ClearBit(PORT,3);
// 	ClearBit(PORT,4); */
// 	
// 	
// 	
// }
// 
// 
// 
// void LoopOutside_8LedsTurnoff(char *PORT)
// {
// 	/*SetBit(PORT,3);
// 	SetBit(PORT,4);*/
// 	//_delay_ms(1000);
// 	ClearBit(PORT,3);
// 	ClearBit(PORT,4);
// 	
// 	/*SetBit(PORT,2);
// 	SetBit(PORT,5);*/
// 	_delay_ms(1000);
// 	ClearBit(PORT,2);
// 	ClearBit(PORT,5);
// 	
// /*	SetBit(PORT,1);
// 	SetBit(PORT,6); */
// 	_delay_ms(1000);
// 	ClearBit(PORT,1);
// 	ClearBit(PORT,6);
// 	
// 	/*SetBit(PORT,0);
// 	SetBit(PORT,7);*/
// 	_delay_ms(1000);
// 	ClearBit(PORT,0);
// 	ClearBit(PORT,7);
// 	_delay_ms(1000);
// 	
// }
// 
// void seven_segment(int n)
// {
// 	//char seven_segmentarr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
// 	char d0=n%10;
// 	char d10=n/10;
// 	
// 	SetBit(PORTB,2);
// 	ClearBit(PORTB,1);
// 	*PORTA=(*PORTA<<4)|d0;
// 	_delay_ms(10);
// 	SetBit(PORTB,1);
// 	ClearBit(PORTB,2);
// 	*PORTA=(*PORTA<<4)|d10;
// 		_delay_ms(10);
// 
// 	
// 	
// 	}
// 	
// 	
// 	void seven_hex(int n)
// 	{
// 		*PORTA=(*PORTA<<4)|n;
// 		
// 	}

u16 ADC_reading,ADC_Copy;
void ADC_Notification (void);
/*
int main(void)
{*/
 	//MCAL_DIO_InitPORT(PD,PORTOUTPUT);
 	//MCAL_DIO_InitPORT(PB,PORTOUTPUT);
// 
	// HAL_LCDCharacter_Init8bit();
	/*
	HAL_LCDCharacter_WriteCharacter('g');
	 HAL_LCDCharacter_WriteNumber(-2542100);
HAL_LCDCharacter_SetCursor(1,5);
 HAL_LCDCharacter_WriteString("Mo'men");
 _delay_ms(100);
//   HAL_LCDCharacter_clear();

*
// HAL_LCDCharacter_WriteStringEndFirst("mo2men");
 HAL_LCDCharacter_WriteNumber(-5295555);
 HAL_LCDCharacter_Writebinary(255);

*/
//	HAL_LCDCharacter_Writehex(130);
	//Keybad_int();
	//u8 k;
/*
MCAL_DIO_InitPORT(PA,PORTINPUT);
MCAL_DIO_InitPORT(PD,PORTOUTPUT);
MCAL_DIO_InitPORT(PB,PORTOUTPUT);

		MCAL_DIO_Init(PINC6,OUTPUT);
		MCAL_DIO_Init(PINC7,OUTPUT);

 HAL_LCDCharacter_Init8bit();

 ADC_Init(VREF_AVCC,ADC_SCALER_128);
 GIE_Enable();

u16 adcread=0,temp,c=0;
adcread = ADC_Read(CH_0);
u16 millivolt;u8 temperature;
//HAL_LCDCharacter_WriteNumber(adcread);
//temp=adcread;
	while(1)
	{
		

		 ADC_Read_ASynchronisation(0,&ADC_reading,ADC_Notification);

		
		//_delay_ms(200);
		//	Keybad_calc();
			
			// Keybad_converter();
	}
	
	
}

void ADC_Notification (void)
{
		
		MCAL_DIO_WritePort(PD,ADC_reading);
		MCAL_DIO_WritePin(PINC6,GetBit(ADC_reading,8));
		MCAL_DIO_WritePin(PINC7,GetBit(ADC_reading,9));
		if(ADC_Copy!=ADC_reading)
		{			HAL_LCDCharacter_clear();
					HAL_LCDCharacter_WriteNumber(ADC_reading);

		}
	
	ADC_Copy=ADC_reading;
}
*/

/*
void __vector_1 (void) __attribute__((signal));

void __vector_1 (void)
{
	MCAL_DIO_WritePin(PIND3,HIGH);
	_delay_ms(2000);
		MCAL_DIO_WritePin(PIND3,LOW);

}
*/

/*

stop watch
#define stop_watch_bt1  PIND6
#define stop_watch_bt2  PIND2
#define stop_watch_btmode  PINB0

typedef enum{
	normal,
	callibration,
}stop_watch_mode_t;

int main(void)
{
	MCAL_DIO_InitPORT(PA,PORTOUTPUT);
	
	MCAL_DIO_WriteFirst4bitPort(PA,0xff);
	
//test rip motion 



MCAL_DIO_Init(PIND3,OUTPUT);
MCAL_DIO_Init(PINB0,INFREE);

while(1)
{
	if(MCAL_DIO_ReadPin(PINB0)==HIGH) 
	{	
		MCAL_DIO_WritePin(PIND3,HIGH);

	 while((MCAL_DIO_ReadPin(PINB0)==HIGH));
	}
	else if(MCAL_DIO_ReadPin(PINB0)==LOW)
	{
		MCAL_DIO_WritePin(PIND3,LOW);
	}
	
}


}

*/


// 	volatile char c=0;
//    int i;
//    
//    *DDRA=0xf0;
//    *PORTC=0;
//    *DDRB= 0b00000110;
//    *PORTB=0b00000110;
//    *DDRC=0xff;
//    
   
//    
//    DIO_Init(PINA0,OUTPUT);
//       DIO_Init(PINB1,OUTPUT);
// 
//          DIO_Init(PINC2,OUTPUT);
// 
//       DIO_Init(PIND3,OUTPUT);
//       DIO_Init(PINA2,OUTPUT);
// 
//    
//    
//    
// MCAL_DIO_InitPORT(PD,PORTOUTPUT);
// 
// MCAL_DIO_InitPORT(PA,PORTOUTPUT);
// 
// MCAL_DIO_InitPORT(PB,PORTOUTPUT);
// 
// MCAL_DIO_InitPORT(PD,PORTOUTPUT);
// 
// MCAL_DIO_InitPORT(PC,PORTOUTPUT);

// 
// MCAL_DIO_Init(PINA0,OUTPUT);
// MCAL_DIO_Init(PINA1,OUTPUT);
// 
// MCAL_DIO_Init(PINA2,OUTPUT);
// 
// MCAL_DIO_Init(PINA3,OUTPUT);


/*

//stop watch  


MCAL_DIO_Init(PINA4,OUTPUT);
MCAL_DIO_Init(PINA5,OUTPUT);
MCAL_DIO_Init(PINA6,OUTPUT);
MCAL_DIO_Init(PINA7,OUTPUT);

MCAL_DIO_Init(PINB0,OUTPUT);
MCAL_DIO_Init(PINB1,OUTPUT);
MCAL_DIO_Init(PINB2,OUTPUT);
MCAL_DIO_Init(PIND3,OUTPUT);

MCAL_DIO_Init(PIND2,INFREE);
MCAL_DIO_Init(PIND6,INFREE);
MCAL_DIO_Init(PINB0,INFREE);

volatile u8 i=0,j;volatile u8 x=30;

stop_watch_mode_t mode=normal;
 HAL_MUX_Initiate();
HAL_MUX_InputPINS_t s;
    while (1) 
    {
// 		for(i=0;i<100;i++)
// 		{
// 			for(j=0;j<50;i++)
// 			{
// 				HAL_seven_segment_mux(i);
// 			}
// 			
// 		}
		/*
		
		while(mode==normal)
		{	
			for(i=0;i<50;i++)
			{
               HAL_seven_segment_mux(x);
			   if (MCAL_DIO_ReadPin(stop_watch_btmode)==HIGH)
			   {
				   mode=callibration;
				   MCAL_DIO_WritePin(PIND3,HIGH);
				   while(MCAL_DIO_ReadPin(stop_watch_btmode)==HIGH);
				   break;
			}
			}
		x--;
		
			
		}
	
		
			while(mode==callibration)
			{	 HAL_seven_segment_mux(x);
				if(MCAL_DIO_ReadPin(stop_watch_bt1)==HIGH)
				{
					x=x+10;
					if(x>99)
					{
						x=(x%10);
					}
					HAL_seven_segment_mux(x);
					while(MCAL_DIO_ReadPin(stop_watch_bt1)==HIGH);
				}
				if(MCAL_DIO_ReadPin(stop_watch_bt2)==HIGH)
				{ 
					if(x%10==9)
					{
						x=((x/10)*10);
						x--;
					}
					x=x+1;
					
					HAL_seven_segment_mux(x);
				 while(MCAL_DIO_ReadPin(stop_watch_bt2)==HIGH);


				}
				
				if (MCAL_DIO_ReadPin(stop_watch_btmode)==HIGH)
				{
					mode=normal;
					HAL_seven_segment_mux(x);
					MCAL_DIO_WritePin(PIND3,LOW);
while((MCAL_DIO_ReadPin(stop_watch_btmode)==HIGH));		
		}
			}
}


*/
		
		/*
		for(s=HAL_MUXinputPIN0;s<HAL_MUXinputPIN7;s++)
		{
			 HAL_MUX_WritePin(s);	
			 _delay_ms(200);
		}
	
	
		
		
		

}
}
	*/	

				
		
		/*first task*/
		// TurnOn_8leds(PORTB);
		
		/***************************************************/
		
		/*task 2*/
		/* Rverse_TurnOn_8leds(PORTB);
		TurnOn_8leds(PORTB);*/
		
		/*task3*/
		/*
		LoopInsid_8Led(PORTB);
		LoopOutside_8Leds(PORTB);
	*/
	    /*task4 */ 
		/*
		LoopInsid_8LedWithoutTurnoff(PORTB);
		LoopOutside_8LedsTurnoff(PORTB);
		*/
		
		
		/*task session DIO Input*/
		//task 1
		/*
		if(GetBit(PIND,2))
		{
			//for repounsing
			_delay_ms(20);
				
			for(int i;!GetBit(PIND,6);i++)
			{
				*PORTB=*PORTB<<1;
			_delay_ms(200);
			if(*PORTB==128)
			{
				*PORTB=1;
				_delay_ms(200);
			}
			}
		}
		
		
			
		
	
	if(GetBit(PIND,6))
	{
		_delay_ms(20);

		/*PORTB=0b10000000;
		for(int i;!GetBit(PIND,2);i++)
		{
			*PORTB=*PORTB>>1;
			_delay_ms(200);
			if(*PORTB==1)
			{
				*PORTB=128;
				_delay_ms(200);
			}
			
		}
	}
	*/
		
		
		
		
		//task 2
		/*
		if(GetBit(PIND,2))
		{
			//for repounsing
			_delay_ms(20);
				
			for(int i;GetBit(PIND,2);i++)
			{
				*PORTB=*PORTB<<1;
			_delay_ms(200);
			if(*PORTB==128)
			{
				*PORTB=1;
				_delay_ms(200);
			}
			
		}
		}
		
	
	if(GetBit(PIND,6))
	{
		

		/*PORTB=0b10000000;
		for(int i;GetBit(PIND,6);i++)
		{
			*PORTB=*PORTB>>1;
			_delay_ms(200);
			if(*PORTB==1)
			{
				*PORTB=128;
				_delay_ms(200);
			}
			
		}
		
	}
		
		*/
		
		
		
		//task3
		
		
		
		/*
		
		if(flag1%2==0)
		{
				*PORTB=*PORTB<<1;
				_delay_ms(200);
				if(*PORTB==128)
				{
					*PORTB=1;
					_delay_ms(200);
				}
		}
			
		else
		{
			*PORTB=*PORTB>>1;
			_delay_ms(200);
			if(*PORTB==1)
			{
				*PORTB=128;
				_delay_ms(200);
			}
		}
		
		if(GetBit(PIND,2))
		{  
			flag1++;
			while(GetBit(PIND,2));
		}

	*/
		
		/*
		
		for( i=0x00;i<100;i++)
		
		{
			c=0;
			while(c<50)
			{seven_segment(i);
				c++;
			}
		}
		
		*/
		
		//task motor
	/*	
		*PORTC=1;
		_delay_ms(1000);
		*PORTC=2;
				_delay_ms(1000);
*/

// *PORTC=1;
// _delay_ms(30000);
// *PORTC=2;
// _delay_ms(30000);
// 
// 		
// 		


	
	
/*
	
	u8 UART_receivestringchecksum(u8*str)
	{
		
		u8 end=UART_recieve();
		
		for(u8 i=0;str[end];i++)
		{
			
		}
	}
	
	*/
 

void ledon(u8 num)
{
		HAL_LCDCharacter_SetCursor(1,0);
			HAL_LCDCharacter_WriteString("ledon");

	MCAL_DIO_WritePin(PINC7,HIGH);
}
void lcd_num(u8 num)
{
	HAL_LCDCharacter_SetCursor(1,0);
	HAL_LCDCharacter_WriteNumber(num);
}

void lcd_str(void)
{
	HAL_LCDCharacter_SetCursor(1,0);
	HAL_LCDCharacter_WriteString("lcd_str ok");
}
typedef struct{
	
	u8*str;
	void (*pf)(u8);
	
	}task_t;

task_t arr[]={{"LedOn",ledon},{"lcdnum",lcd_num},{"lcdstr",lcd_str}
};



//function to extract string and search in  the array
u8 numbf=0;
u8 extract(u8*str)
{
	u8 i=0,j=0,string[20]="0",length=0,flag=0,index=0,k=3,flagerror=1;
	//extract string
	for(i=0;str[i];i++)
	{
		if(str[i]!='_')
		{
			string[i]=str[i];
		}
		else
		{
			flagerror=0;
			break;
		}
	}
	
	string[i]=0;
	length=i;
	//search for string
	for(i=0;i<k;i++)
	{
		for(j=0;arr[i].str[j];j++)
		{
			if(arr[i].str[j]==string[j])
			{
				
				if(length==j+1)
				{
					flag=1;
					index=i;
					
					break;
				}
				//continue;
			}
			
			else
			{
				break;
			}
		}
		if(flag==1)
		{
			break;
			
		}
		
	}
	//extract number
	for(i=length+1;str[i];i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			numbf= (numbf*10) +(str[i]-'0');
		}
	}
	
	if(flag==1&&flagerror==0)
	{
		
		
		return index;
	}
	else
	{
		return 55;
	}
	
};
/*-----------------------------------------------------------------------------*/
/*
int main(void)
{
 USART_init();
 _delay_ms(50);
 MCAL_DIO_InitPORT(PC,PORTOUTPUT);
 MCAL_DIO_Init(PIND7,OUTPUT);
  MCAL_DIO_Init(PIND6,OUTPUT);

 MCAL_DIO_Init(PIND5,OUTPUT);

 HAL_LCDCharacter_Init8bit();
 //_delay_ms(50);
 		HAL_LCDCharacter_WriteString("Rx");

u8 str[20];
while(1)
{
	UART_ReceiveString(str);
	
		HAL_LCDCharacter_WriteNumber(99);
		HAL_LCDCharacter_WriteString("Rx");
		//  HAL_LCDCharacter_clear();
		HAL_LCDCharacter_SetCursor(1,0);
		HAL_LCDCharacter_WriteString(str);
	
	
}
}
*/

int main(void)
{
/*	
 USART_init();
 _delay_ms(200);
 	MCAL_DIO_InitPORT(PA,PORTOUTPUT);
	 	MCAL_DIO_InitPORT(PB,PORTOUTPUT);
		MCAL_DIO_Init(PINC0,OUTPUT);

		 HAL_LCDCharacter_Init8bit();
	*/
	
//u8 str[]="mo2atoo";
//for(u8 i=0;str[i];i++)
{
	//UART_send(str[i]);
}

 USART_init();
 _delay_ms(50);
  //avr config
  /*
 MCAL_DIO_InitPORT(PC,PORTOUTPUT);
 MCAL_DIO_Init(PIND7,OUTPUT);
 MCAL_DIO_Init(PIND6,OUTPUT);

 MCAL_DIO_Init(PIND5,OUTPUT);
 MCAL_DIO_Init(PIND3,OUTPUT);
*/
 //protues config
 
 MCAL_DIO_InitPORT(PA,PORTOUTPUT);
 MCAL_DIO_Init(PINC0,OUTPUT);
 MCAL_DIO_Init(PINB1,OUTPUT);

 MCAL_DIO_Init(PINB2,OUTPUT);
 MCAL_DIO_Init(PIND3,OUTPUT);
 HAL_LCDCharacter_Init8bit();

//	HAL_LCDCharacter_WriteString("Rx");


u8 str[20],y=0,flag=0;
u8 volatile check =0;

HAL_LCDCharacter_SetCursor(0,0);
HAL_LCDCharacter_WriteString("Rx");
	while(1)
	{
		numbf=0;
		check=0;
		

	
			HAL_LCDCharacter_SetCursor(1,0);
	//	HAL_LCDCharacter_WriteString("start");

		UART_ReceiveString(str) ;
		 
			 
		//HAL_LCDCharacter_clear();
		/*HAL_LCDCharacter_WriteString("                                   ");
		HAL_LCDCharacter_SetCursor(1,0);
		HAL_LCDCharacter_WriteString("                                   ");
			 HAL_LCDCharacter_SetCursor(0,0);
*/
		
			//  HAL_LCDCharacter_clear();

		 HAL_LCDCharacter_SetCursor(1,0);
		 					
		 	// HAL_LCDCharacter_WriteString(str);
//arr[1].pf(70);
		// HAL_LCDCharacter_WriteString(str);
		 check=extract(str);
	     	if(check!=55)
				{
					HAL_LCDCharacter_SetCursor(1,0);
					HAL_LCDCharacter_WriteString("                ");
					HAL_LCDCharacter_SetCursor(1,0);

					arr[check].pf(numbf);

				}
				else{
					HAL_LCDCharacter_WriteString("not found");
				}
		
		 
//else
{			//  HAL_LCDCharacter_clear();

	// HAL_LCDCharacter_SetCursor(1,0);
	// HAL_LCDCharacter_WriteString("error");
}

HAL_LCDCharacter_SetCursor(0,10);
HAL_LCDCharacter_WriteNumber(y);
y++;

if(y==10)
{
	y=0;
}

	}
	
	
}
		
	
