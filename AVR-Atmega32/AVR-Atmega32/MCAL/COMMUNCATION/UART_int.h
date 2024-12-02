/*
 * UART_Interface.h
 *
 * Created: 11/16/2024 2:04:45 PM
 *  Author: momen
 */ 



void UART_send(u8 data);

u8 UART_recieve(void);
u8 UART_recieve_periodec(u8 *data);
void USART_init(void);

void UART_SendString(u8 *data);

u8 UART_ReceiveString(u8 *data);

void UART_SendNumber(u32 number);
void UART_ReceiveNumber(u32 *number);
 
 u32 endian_Convert_32bit(u32 number);
 
 void UART_SendStringChekSum(u8*str);
 u8 UART_RecieveStringChekSum(u8*str);
 