#include "led.h"

/*led��ʼ��*/
void LED_GPIO_Config(void)
{
	//����ṹ�������ע�⣺ֻ�ܷ���{����
	GPIO_InitTypeDef GPIO_InitStruct;
	//����ʱ��
	RCC_APB2PeriphClockCmd(LED_GPIO_CLK, ENABLE);
	//��������
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = LED_GPIO_PIN;
	GPIO_InitStruct.GPIO_Speed =  GPIO_Speed_50MHz;
	
	GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);
}


