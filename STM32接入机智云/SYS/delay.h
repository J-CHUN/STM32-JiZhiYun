#ifndef __DELAY_H
#define __DELAY_H
#include "stm32f10x.h"
/*ֻ�ܶ���ʱ�������ʱԼ1864ms
��ϵͳʱ��Ϊ8��Ƶ��9MHz��
9000--1ms
2^24--~1864ms */
void delay_init(void);  //��ʱ������ʼ��
void delay_ms(u16 nms); //��ʱms��λ


#endif
