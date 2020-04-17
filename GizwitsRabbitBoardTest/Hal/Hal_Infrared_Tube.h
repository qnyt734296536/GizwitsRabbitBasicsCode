#ifndef _HAL_INFRARED_TUBE_H_
#define _HAL_INFRARED_TUBE_H_
#include "common.h"

#define INF_TUBE_PIN	GPIO_PIN_1 //红外对管PB1
#define INF_TUBE_GPIO_TYPE GPIOB


/**
*设置红外对射管状态
*有人高电平;没人低电平
*/
void Set_InfTube_State(char level);



uint8_t Get_InfTube_State(void);

/**
*获红外对管是否被触发
*/
uint8_t Get_InfTube_State_Trigger(void);


#endif

