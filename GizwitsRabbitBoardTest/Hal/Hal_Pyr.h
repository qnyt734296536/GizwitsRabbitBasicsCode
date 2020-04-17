#ifndef _HAL_PYR_H_
#define _HAL_PYR_H_

#include "common.h"

#define PYR_PIN	GPIO_PIN_4 //热释电PC4
#define PYR_GPIO_TYPE GPIOC


/**
*当时的电平
*有人高电平;没人低电平
*/
void Set_Pyr_State(char level);


/**
*获取热释电是否被触发
*/
uint8_t  Get_Pyr_State(void);


/**
*获取热释电是否被触发
*/
uint8_t Get_Pyr_State_Trigger(void);

#endif

