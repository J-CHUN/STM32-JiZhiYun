/**********************************************
STM32���������--ʵ�������ϴ��������·��Ĺ���ģ��
********************************************/
#include "stm32f10x.h"
#include <stdio.h>
#include "delay.h"
#include "timer3.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "bh1750.h"


int main(void)
{
	u8 keyValue;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	delay_init();          //��ʱ������ʼ��
	USART1_Init(9600);     //����1��ʼ��
	LED_GPIO_Config();     //LED��ʼ��
	KEY_GPIO_Config();     //������ʼ��
	BH1750_Init();
    
	printf("--------������-Э����ֲ����ʵ��----------\r\n");
	printf("KB0:AirLink����ģʽ\t KB1:WIFI��λ\r\n\r\n");
	
	while(1)
	{
		 keyValue = KEY_Scan();  //ɨ�谴���Ƿ���
		if(keyValue==KB0_Value)  //KB0��������
		{
			printf("WIFI����AirLink����ģʽ\r\n");
		}			
		if(keyValue==KB1_Value)  //KB1��������
		{  
			printf("WIFI��λ����������������\r\n");
			
		}
		delay_ms(200);
	}
}


