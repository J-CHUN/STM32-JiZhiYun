#ifndef __KEY_H_
#define __KEY_H_

#include "stm32f10x.h"
#include "sys.h"

#define KEY_GPIO_PIN (GPIO_Pin_0|GPIO_Pin_1)
#define KEY_GPIO_PORT GPIOB
#define KEY_GPIO_CLK RCC_APB2Periph_GPIOB

//ʹ��λ��������
#define KB0 PBin(0)
#define KB1 PBin(1)

//�����������ֵ  
#define KB0_Value 1
#define KB1_Value 2


void KEY_GPIO_Config(void);  //key��ʼ��
u8 KEY_Scan(void);


#endif

