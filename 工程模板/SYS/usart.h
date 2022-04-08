#ifndef __usart_H
#define __usart_H

#include <stm32f10x.h>
typedef struct __FILE FILE;


//�ⲿ���ô��ڽ���������ɵı���
extern u8 rx_flag;  		//����������ɱ�־λ rx_flag = 1
extern u8 rx_buffer[64];	//������ɺ������

void USART1_Init(u32 bound);
void USART2_Init(u32 bound);
void USART3_Init(u32 bound);

void UART1_SendString(char* s);
void UART2_SendString(char* s);
void UART3_SendString(char *pstr);

#endif


