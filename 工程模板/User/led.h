#ifndef __LED_H_
#define __LED_H_

#include "sys.h"

#define LED_GPIO_PIN GPIO_Pin_13
#define LED_GPIO_PORT GPIOC
#define LED_GPIO_CLK RCC_APB2Periph_GPIOC

#define LED1 PCout(13)

void LED_GPIO_Config(void);  //led≥ı ºªØ

#endif

