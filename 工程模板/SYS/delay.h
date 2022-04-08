#ifndef __DELAY_H
#define __DELAY_H
#include "stm32f10x.h"
/*只能短延时，最大延时约1864ms
若系统时钟为8分频（9MHz）
9000--1ms
2^24--~1864ms */
void delay_init(void);  //延时函数初始化
void delay_ms(u16 nms); //延时ms单位


#endif
