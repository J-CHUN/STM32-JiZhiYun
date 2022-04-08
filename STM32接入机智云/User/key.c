#include "key.h"
#include "delay.h"

/*key初始化*/
void KEY_GPIO_Config(void)
{
	//定义结构体变量，注意：只能放在{后面
	GPIO_InitTypeDef GPIO_InitStruct;
	
	//配置时钟
	RCC_APB2PeriphClockCmd(KEY_GPIO_CLK, ENABLE);
	//配置引脚
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;  //上拉输入模式
	GPIO_InitStruct.GPIO_Pin = KEY_GPIO_PIN;
	//GPIO_InitStruct.GPIO_Speed =  GPIO_Speed_50MHz;
	
	GPIO_Init(KEY_GPIO_PORT, &GPIO_InitStruct);
}

u8 KEY_Scan()
{
	if(KB0==0||KB1==0) //任意一个按键按下
	{
		delay_ms(5);
		if(KB0==0) 
		{
			while(KB0==0);//等待手松开
			return KB0_Value; 
		}
		else if(KB1==0)
		{
			while(KB1==0);
			return KB1_Value; 
		}
		//while(!GPIO_ReadInputDataBit(KEY_GPIO_PORT, KEY_GPIO_PIN));  //等待手松开
	}
	return 0;
}

