#include "key.h"
#include "delay.h"

/*key��ʼ��*/
void KEY_GPIO_Config(void)
{
	//����ṹ�������ע�⣺ֻ�ܷ���{����
	GPIO_InitTypeDef GPIO_InitStruct;
	
	//����ʱ��
	RCC_APB2PeriphClockCmd(KEY_GPIO_CLK, ENABLE);
	//��������
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;  //��������ģʽ
	GPIO_InitStruct.GPIO_Pin = KEY_GPIO_PIN;
	//GPIO_InitStruct.GPIO_Speed =  GPIO_Speed_50MHz;
	
	GPIO_Init(KEY_GPIO_PORT, &GPIO_InitStruct);
}

u8 KEY_Scan()
{
	if(KB0==0||KB1==0) //����һ����������
	{
		delay_ms(5);
		if(KB0==0) 
		{
			while(KB0==0);//�ȴ����ɿ�
			return KB0_Value; 
		}
		else if(KB1==0)
		{
			while(KB1==0);
			return KB1_Value; 
		}
		//while(!GPIO_ReadInputDataBit(KEY_GPIO_PORT, KEY_GPIO_PIN));  //�ȴ����ɿ�
	}
	return 0;
}

