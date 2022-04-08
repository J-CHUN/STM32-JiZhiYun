#include "timer3.h"
#include "gizwits_product.h"

/**********
1ʹ�ܶ�ʱ��ʱ�� RCC_APB1PeriphClockCmd();
2��ʼ����ʱ��������ARR,PSC  TIM_TimeBaseInit()
3��ʱ���ж����ã�ͬʱ����NVIC  TIM_ITConfig() ,NVIC_Init()
4ʹ�ܶ�ʱ��  TIM_Cmd(TIM3,ENABLE)
4��д�жϷ�����
*********/

/*arr����װ��ֵ��psc��Ԥ��Ƶϵ��,fsk:72MHz
���ʱ��=��psc+1��(arr+1)/fsk*/
void TIM3_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;      //����ṹ�����
	NVIC_InitTypeDef        NVIC_InitStruct;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);  //1ʹ�ܶ�ʱ��ʱ��
	
	TIM_TimeBaseInitStruct.TIM_Period = arr;           //��װ��ֵ
	TIM_TimeBaseInitStruct.TIM_Prescaler = psc;    //Ԥ��Ƶϵ��
	TIM_TimeBaseInitStruct.TIM_ClockDivision = 0;   //ʱ�ӷָ�
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;  //���ϼ���ģʽ
	
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStruct);   //2��ʼ����ʱ��
	
	NVIC_InitStruct.NVIC_IRQChannel =  TIM3_IRQn ;         //�ж�Դ
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;  //��ռ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;          //��Ӧ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;           //�ж�ʹ��
	
	TIM_ITConfig(TIM3,TIM_IT_Update, ENABLE);  //3��ʱ���ж����ã�ͬʱ����NVIC
	NVIC_Init(&NVIC_InitStruct);
	
	TIM_Cmd(TIM3,ENABLE);           //4ʹ�ܶ�ʱ��
	
}


//��ʱ��3�жϷ������
void TIM3_IRQHandler(void)   //TIM3�ж�
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //���TIM3�����жϷ������
	{
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  //���TIMx�����жϱ�־ 
		gizTimerMs();
	}
}
