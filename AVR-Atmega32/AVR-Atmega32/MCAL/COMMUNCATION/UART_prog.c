#include "../../SERVICES/STDTypes.h"
#include "../../SERVICES/MemMap.h"
#include "../../SERVICES/Math.h"

#include "UART_int.h"

void USART_init(void)
{
	/*
	u8 local_UCSRCvalue=0;
	SetBit(local_UCSRCvalue,7);
	ClrBit(UCSRC,UCSRC_UCSZ0);
	ClrBit(UCSRC,UCSRC_UCSZ1);
	UCSRC=local_UCSRCvalue;
	*/
	
	ClrBit(UCSRA,UCSRA_U2X);
	

	SetBit(UCSRB,UCSRB_RXEN);
	SetBit(UCSRB,UCSRB_TXEN);
	UBRRL=102;
	
	
}


void UART_send(u8 data)
{
	while(!GetBit(UCSRA,UCSRA_UDRE));
	
	
	UDR=data;
}

u8 UART_recieve(void)
{
	while(!GetBit(UCSRA,UCSRA_RXC));
	
	
	return UDR;
	
}
u8 UART_recieve_periodec(u8*pdata)
{
	if(GetBit(UCSRA,UCSRA_RXC))
	{
		*pdata=UDR;
		return 1;
		
	};
	
	
	return 0;
	
}


void UART_SendString(u8 *str)
{
	for(u8 i=0;str[i];i++)
	{
		UART_send(str[i]);
	}
	UART_send(0);
	
	
}

u8 UART_ReceiveString(u8*str)
{
	u8 i=0;
	
	
	str[i]=UART_recieve();
	for(;str[i]!=0x0d;)
	{if(i==0)
	{
		HAL_LCDCharacter_SetCursor(1,0);
		HAL_LCDCharacter_WriteString("                ");
		HAL_LCDCharacter_SetCursor(1,i);
		HAL_LCDCharacter_WriteCharacter(str[i]);
	}
		i++;
		str[i]=UART_recieve();
		HAL_LCDCharacter_SetCursor(1,i);
		HAL_LCDCharacter_WriteCharacter(str[i]);
	}
	str[i]=0;
	if(i>2){return 1;}
		else{return 0;}
}



void UART_SendNumber(u32 number)
{
	/*u8 *p =number;
	UART_send(p[0]);
	UART_send(p[1]);
	UART_send(p[2]);
	UART_send(p[3]);*/

   UART_send((u8) number);
    UART_send((u8) (number>>8));
    UART_send((u8) (number>>16));
    UART_send((u8) (number>>24));

	
	
}


void UART_ReceiveNumber(u32 *pnumber)
{
	u8 b0=UART_recieve();
	u8 b1=UART_recieve();
	u8 b2=UART_recieve();
	u8 b3=UART_recieve();

	*pnumber=((u32)b0) |((u32)b1<<8) |((u32)b2<<16)|((u32)b3<<24);
	/*
	u8 *p= pnumber;
	p[0]=UART_recieve();
	p[1]=UART_recieve();
	p[2]=UART_recieve();
	p[3]=UART_recieve();
*/
}

 u32 endian_Convert_32bit(u32 number)
 {
	/* u8 *p=&number;
	 u8 temp;
	 p[0]=temp;
	 p[0]=p[3];
	 p[3]=temp;
	 p[1]=temp;
	 p[1]=p[2];
	 p[2]=temp;
	 */
	 
	 number =number>>24 | number<<24 | ((number >>8) & 0x0000ff00) |  ((number<<8) & 0x00ff0000)     ;                  
	 
 }
 
 
 
  void UART_SendStringChekSum(u8*str)
  {
	  u8 i;
	  u16 sum=0;
	  
	  for(i=0;str[i];i++)
	  {
		  sum+=str[i];
	  }
	  UART_send(i);
	  for(i=0;str[i];i++)
		{
			UART_send(str[i]);
			
		}
  
		UART_send((u8)sum);
     	UART_send(sum>>8);

	  
	  
  }


 u8 UART_RecieveStringChekSum(u8*str)
 { u8 i,*p,b0,b1;
	 u16 sum=0,sumreal=0;
	 p=&sum;
	u8 length = UART_recieve();
	
	 for(i=0;i<length;i++)
	 {
		 str[i]=UART_recieve();
		 sumreal+=str[i];
	 }
	 p[0]= UART_recieve();
	 p[1]=UART_recieve();
	// sum=b0|((u16)b1<<8);

	 if(sum==sumreal)
	 {
	 return 1;
	 }
	 else 
	 {
		  return 0;
		  }
 }
