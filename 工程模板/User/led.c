#include "led.h"

/*led初始化*/
void LED_GPIO_Config(void)
{
	//定义结构体变量，注意：只能放在{后面
	GPIO_InitTypeDef GPIO_InitStruct;
	//配置时钟
	RCC_APB2PeriphClockCmd(LED_GPIO_CLK, ENABLE);
	//配置引脚
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = LED_GPIO_PIN;
	GPIO_InitStruct.GPIO_Speed =  GPIO_Speed_50MHz;
	
	GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);
}


