

#include "../../SERVICES/STDTypes.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../LCD_Charcter/LCDCharcter_Int.h"
#include "Keybad_CFG.h"

#define F_CPU   16000000
#include <util/delay.h>

void Keybad_int(void)
{	
	u8 i=0;
	
	for(i=0;i<4;i++)
	{
		MCAL_DIO_Init(keybadlinkARR[i].row,OUTPUT);
		MCAL_DIO_WritePin(keybadlinkARR[i].row,HIGH);
	}
	for(i=0;i<4;i++)
	{
		MCAL_DIO_Init(keybadlinkARR[i].col,INPULL);
	}
	
	
}









 u8 Keybad_read(void)
 {
	 u8 k='T',i,j,flag=0;
	 for(j=0;j<ROWS;j++)
	 {
		 MCAL_DIO_WritePin(keybadlinkARR[j].row,LOW);
	 for(i=0;i<COL;i++)
	 {
		 if(MCAL_DIO_ReadPin(keybadlinkARR[i].col)==LOW)
		 { while(MCAL_DIO_ReadPin(keybadlinkARR[i].col)==LOW);
			 k=Kebad_ARR[j][i];
			
			 flag=1;
			 
			 break;
			 
		 }
		 
		 if(flag==1)
		 {break;}
	 }
	 MCAL_DIO_WritePin(keybadlinkARR[j].row,HIGH);
	
	 }
	  return k;
	 
 }




void Keybad_calc(void)
{
	u8 k,flag=0,flagop=0,flagnewnum=0;u32 num1=0,num2=0;u8 operator;u32 result=0;
	//HAL_LCDCharacter_WriteCharacter('o');
	while(result==0)
	{
		//HAL_LCDCharacter_WriteCharacter('k');
	
	k= Keybad_read();
	if(k!='T')
	{
		if(flagnewnum==0)
		{
			HAL_LCDCharacter_clear();
			flagnewnum=1;
		}
		
		if(k>='0'&&k<='9')
		{	HAL_LCDCharacter_WriteCharacter(k);
			if(flag==0)
			{
				num1=(num1*10) + (k -'0');
			}
			else if(flag==1)
			{
				num2= (num2*10) + (k -'0');
			}
			
		}
		
		else if(((k=='+' )||(k=='-' )||( k=='/' )||(k=='*')) && flagop==0)
		{
			HAL_LCDCharacter_WriteCharacter(k);
			switch(k){
				
				case '+': operator = '+' ;flag=1;flagop=1; break;
				case '-': operator = '-' ;flag=1;flagop=1; break;
				case '/': operator = '/';flag=1; flagop=1; break;
				case '*': operator = '*' ;flag=1;flagop=1; break;
				default:break;
				
				
			        }
			
		}
		
		else if(k == '=')
		{	HAL_LCDCharacter_WriteCharacter(k);
			switch(operator){
				
				case '+': result= num1 + num2 ; HAL_LCDCharacter_SetCursor(1 ,0);  HAL_LCDCharacter_WriteNumber(result); break;
				case '-': result= num1 - num2 ; HAL_LCDCharacter_SetCursor(1 ,0);  HAL_LCDCharacter_WriteNumber(result); break;
				case '/': result= num1 / num2 ; HAL_LCDCharacter_SetCursor(1 ,0);  HAL_LCDCharacter_WriteNumber(result); break;
				case '*': result= num1 * num2 ; HAL_LCDCharacter_SetCursor(1 ,0);  HAL_LCDCharacter_WriteNumber(result); break;
				default:break;
			
			
			
		                      }
		
	   }
	   else if(k== 'c')
	   {
		    HAL_LCDCharacter_clear();
			break;

	   }
	
	}
  }
	
}







void Keybad_converter(void)
{
	
	
	
	HAL_LCDCharacter_WriteString("converter");
	HAL_LCDCharacter_SetCursor(1,0);
	HAL_LCDCharacter_WriteString("Mo'men");
	_delay_ms(1000);
	HAL_LCDCharacter_clear();
	HAL_LCDCharacter_WriteString("Welcome");
	_delay_ms(1000);
	HAL_LCDCharacter_clear();

    
		u8 k,from='T',to='T';
//choose convert from what?	
	HAL_LCDCharacter_WriteString("Convert From");
			
	HAL_LCDCharacter_SetCursor(1,0);
	
	HAL_LCDCharacter_WriteString("1 B");
	HAL_LCDCharacter_WriteString("    ");
	
    HAL_LCDCharacter_WriteString("2 D");
	
    HAL_LCDCharacter_WriteString("3  H");
	_delay_ms(1000);
	while(from != 'T')
	{
		from=Keybad_read();
		HAL_LCDCharacter_WriteCharacter('o');
	}
	
	
	//choose convert to what?	
	
	HAL_LCDCharacter_clear();
	HAL_LCDCharacter_WriteString("Convert to");	
	HAL_LCDCharacter_SetCursor(1,0);
	HAL_LCDCharacter_WriteString("1 B");
	HAL_LCDCharacter_WriteString("    ");
	HAL_LCDCharacter_WriteString("2 D");
	HAL_LCDCharacter_WriteString("3  H");
		_delay_ms(1000);

	while(to!='T')
	{
		to=Keybad_read();
	}
	HAL_LCDCharacter_clear();
	
	HAL_LCDCharacter_SetCursor(1,0);
	HAL_LCDCharacter_WriteString("                 ");
	HAL_LCDCharacter_SetCursor(1,0);
	
	u8 numD,numB,numH,tempbinary,temp,i,j,flagb;
	while(k != '=')
	{

	k= Keybad_read();
	if(k!='T')
	{
// 		if(flagnewnum==0)
// 		{
// 			HAL_LCDCharacter_clear();
// 			flagnewnum=1;
// 		}
		
		
		
		if(k>='0'&&k<='9' && (from ==2 || from ==1))
		{	
			if(from == '2')
			{
				numD=(numD*10) + (k -'0');
			}
			
			if(from == '1')
			{
				numB=(numB*10) + (k -'0');
			
			}
			
		}	

		
		
		
		if(from==2&&k == '=')
		{
			switch(to)
			{
			case '1': HAL_LCDCharacter_Writebinary(numD);break;
			case '2': HAL_LCDCharacter_WriteNumber(numD);break;
			case '3': HAL_LCDCharacter_Writehex(numD);break;
			default:break;
			}
			

		}
		
		if(from=='1'&&k == '=')
		{ 
			for( i=0;i<8;i++)
			{
				temp=numB%10;
				for(j=0;j<i;j++)
				{	
					temp=temp*2;
				}
				
				tempbinary=tempbinary+temp;
				numB/=10;
			}
		
		HAL_LCDCharacter_WriteNumber(tempbinary);
		}
		
		
			
		}
	 	
	}
		
		
		
		
	     



}


