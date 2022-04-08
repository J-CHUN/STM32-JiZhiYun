/**********************************************
STM32接入机智云--实现数据上传和命令下发
********************************************/
#include "stm32f10x.h"
#include <stdio.h>
#include "delay.h"
#include "timer3.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "bh1750.h"

#include "gizwits_product.h"   //需要包含的头文件

/* 用户区当前设备状态结构体*/
dataPoint_t currentDataPoint;


//协议初始化
void Gizwits_Init(void)
{	
	TIM3_Init(9,7199);//1MS系统定时
	USART3_Init(9600);//WIFI初始化
	memset((uint8_t*)&currentDataPoint, 0, sizeof(dataPoint_t));//设备状态结构体初始化
	gizwitsInit();//缓冲区初始化
}


//用户数据采集
void userHandle(void)
{
	 //光照数据采集
	float light = LIght_Intensity();
	currentDataPoint.valueLight = light; //添加传感器数据采集
	
    //判断当前LED1开关量
	if(LED1==0)
		currentDataPoint.valueLEDSwitch = 1;   //开
    else 
		currentDataPoint.valueLEDSwitch = 0;   //关
 }

int main(void)
{
	u8 keyValue;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	delay_init();          //延时函数初始化
	USART1_Init(9600);     //串口1初始化
	LED_GPIO_Config();     //LED初始化
	KEY_GPIO_Config();     //按键初始化
	BH1750_Init();
	Gizwits_Init();
    
	printf("--------机智云-协议移植测试实验----------\r\n");
	printf("KB0:AirLink连接模式\t KB1:WIFI复位\r\n\r\n");
	
	while(1)
	{
		userHandle(); //用户数据采集
		gizwitsHandle((dataPoint_t *)&currentDataPoint);//协议处理

		 keyValue = KEY_Scan();  //扫描按键是否按下
		if(keyValue==KB0_Value)  //KB0按键按下
		{
			printf("WIFI进入AirLink连接模式\r\n");
			gizwitsSetMode(WIFI_AIRLINK_MODE);//Air-link模式接入
		}			
		if(keyValue==KB1_Value)  //KB1按键按下
		{  
			printf("WIFI复位，请重新配置连接\r\n");
			gizwitsSetMode(WIFI_RESET_MODE);//WIFI复位
		}
		delay_ms(200);
	}
}


