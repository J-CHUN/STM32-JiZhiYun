/**********************************************
STM32���������--ʵ�������ϴ��������·�
********************************************/
#include "stm32f10x.h"
#include <stdio.h>
#include "delay.h"
#include "timer3.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "bh1750.h"

#include "gizwits_product.h"   //��Ҫ������ͷ�ļ�

/* �û�����ǰ�豸״̬�ṹ��*/
dataPoint_t currentDataPoint;


//Э���ʼ��
void Gizwits_Init(void)
{	
	TIM3_Init(9,7199);//1MSϵͳ��ʱ
	USART3_Init(9600);//WIFI��ʼ��
	memset((uint8_t*)&currentDataPoint, 0, sizeof(dataPoint_t));//�豸״̬�ṹ���ʼ��
	gizwitsInit();//��������ʼ��
}


//�û����ݲɼ�
void userHandle(void)
{
	 //�������ݲɼ�
	float light = LIght_Intensity();
	currentDataPoint.valueLight = light; //��Ӵ��������ݲɼ�
	
    //�жϵ�ǰLED1������
	if(LED1==0)
		currentDataPoint.valueLEDSwitch = 1;   //��
    else 
		currentDataPoint.valueLEDSwitch = 0;   //��
 }

int main(void)
{
	u8 keyValue;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	delay_init();          //��ʱ������ʼ��
	USART1_Init(9600);     //����1��ʼ��
	LED_GPIO_Config();     //LED��ʼ��
	KEY_GPIO_Config();     //������ʼ��
	BH1750_Init();
	Gizwits_Init();
    
	printf("--------������-Э����ֲ����ʵ��----------\r\n");
	printf("KB0:AirLink����ģʽ\t KB1:WIFI��λ\r\n\r\n");
	
	while(1)
	{
		userHandle(); //�û����ݲɼ�
		gizwitsHandle((dataPoint_t *)&currentDataPoint);//Э�鴦��

		 keyValue = KEY_Scan();  //ɨ�谴���Ƿ���
		if(keyValue==KB0_Value)  //KB0��������
		{
			printf("WIFI����AirLink����ģʽ\r\n");
			gizwitsSetMode(WIFI_AIRLINK_MODE);//Air-linkģʽ����
		}			
		if(keyValue==KB1_Value)  //KB1��������
		{  
			printf("WIFI��λ����������������\r\n");
			gizwitsSetMode(WIFI_RESET_MODE);//WIFI��λ
		}
		delay_ms(200);
	}
}


