#include "delay.h"
#include "stm32f10x.h"  //包含需要的头文件


/****************
1确定时钟
2重装数值
3清空计数器
4启动计数器
5查询
6关闭计数器
7（清空计数器）
****************/

void delay_init()
{
	//((SysTick_Type*)(0xE000E010))->CTRL &= ~(1<<2);  //1<<2-->100-->~011第2位为0，则8分频
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);//1、系统时钟（72M）的8分频 
}



void delay_ms(u16 nms)
{
	u32 temp;
	//9MHz~~1/9us-->1/9us*9000 = 1ms
	//SysTick与((SysTick_Type*)(0xE000E010))同
	SysTick->LOAD = (u32)nms*9000 ;
	//((SysTick_Type*)(0xE000E010))->LOAD = (u32)nms*9000 ;  //2、重装数值
	((SysTick_Type*)(0xE000E010))->VAL = 0x00;         //3、清空计数器
	((SysTick_Type*)(0xE000E010))->CTRL |= 0X01;       //4、启动计数器，CTRL第0位为定时器使能位
	do
	{
		temp = ((SysTick_Type*)(0xE000E010))->CTRL ;   //5、查询
	}while(!(temp&(1<<16)));  //1<<16--->1_0000_0000_0000_0000,减到0退出循环
	((SysTick_Type*)(0xE000E010))->CTRL &= ~(1<<0);       //6、关闭计数器
	((SysTick_Type*)(0xE000E010))->VAL = 0x00;         //7、清空计数器
}



