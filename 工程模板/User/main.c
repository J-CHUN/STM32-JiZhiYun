/**********************************************
STM32接入机智云--实现数据上传和命令下发的工程模板
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
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	delay_init();          //延时函数初始化
	USART1_Init(9600);     //串口1初始化
	LED_GPIO_Config();     //LED初始化
	KEY_GPIO_Config();     //按键初始化
	BH1750_Init();
    
	printf("--------机智云-协议移植测试实验----------\r\n");
	printf("KB0:AirLink连接模式\t KB1:WIFI复位\r\n\r\n");
	
	while(1)
	{
		 keyValue = KEY_Scan();  //扫描按键是否按下
		if(keyValue==KB0_Value)  //KB0按键按下
		{
			printf("WIFI进入AirLink连接模式\r\n");
		}			
		if(keyValue==KB1_Value)  //KB1按键按下
		{  
			printf("WIFI复位，请重新配置连接\r\n");
			
		}
		delay_ms(200);
	}
}


