//#include "timer2.h"
#include "sys.h"  //包含需要的头文件

/**********
1使能定时器时钟 RCC_APB1PeriphClockCmd();
2初始化定时器，配置ARR,PSC  TIM_TimeBaseInit()
3定时器中断配置，同时配置NVIC  TIM_ITConfig() ,NVIC_Init()
4使能定时器  TIM_Cmd(TIM3,ENABLE)
4编写中断服务函数
*********/

/*arr：重装载值，psc：预分频系数,fsk:72MHz
溢出时间=（psc+1）(arr+1)/fsk*/
void TIM2_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;      //定义结构体变量
	NVIC_InitTypeDef        NVIC_InitStruct;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);  //1使能定时器时钟
	
	TIM_TimeBaseInitStruct.TIM_Period = arr;           //重装载值
	TIM_TimeBaseInitStruct.TIM_Prescaler = psc;    //预分频系数
	TIM_TimeBaseInitStruct.TIM_ClockDivision = 0;   //时钟分割
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;  //向上计数模式
	
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);   //2初始化定时器
	
	NVIC_InitStruct.NVIC_IRQChannel =  TIM2_IRQn ;         //中断源
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;  //抢占优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;          //响应优先级
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;           //中断使能
	
	TIM_ITConfig(TIM2,TIM_IT_Update, ENABLE);  //3定时器中断配置，同时配置NVIC
	NVIC_Init(&NVIC_InitStruct);
	
	TIM_Cmd(TIM2,ENABLE);           //4使能定时器
	
}




