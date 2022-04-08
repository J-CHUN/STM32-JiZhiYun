#include "delay.h"
#include "stm32f10x.h"  //������Ҫ��ͷ�ļ�


/****************
1ȷ��ʱ��
2��װ��ֵ
3��ռ�����
4����������
5��ѯ
6�رռ�����
7����ռ�������
****************/

void delay_init()
{
	//((SysTick_Type*)(0xE000E010))->CTRL &= ~(1<<2);  //1<<2-->100-->~011��2λΪ0����8��Ƶ
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);//1��ϵͳʱ�ӣ�72M����8��Ƶ 
}



void delay_ms(u16 nms)
{
	u32 temp;
	//9MHz~~1/9us-->1/9us*9000 = 1ms
	//SysTick��((SysTick_Type*)(0xE000E010))ͬ
	SysTick->LOAD = (u32)nms*9000 ;
	//((SysTick_Type*)(0xE000E010))->LOAD = (u32)nms*9000 ;  //2����װ��ֵ
	((SysTick_Type*)(0xE000E010))->VAL = 0x00;         //3����ռ�����
	((SysTick_Type*)(0xE000E010))->CTRL |= 0X01;       //4��������������CTRL��0λΪ��ʱ��ʹ��λ
	do
	{
		temp = ((SysTick_Type*)(0xE000E010))->CTRL ;   //5����ѯ
	}while(!(temp&(1<<16)));  //1<<16--->1_0000_0000_0000_0000,����0�˳�ѭ��
	((SysTick_Type*)(0xE000E010))->CTRL &= ~(1<<0);       //6���رռ�����
	((SysTick_Type*)(0xE000E010))->VAL = 0x00;         //7����ռ�����
}



