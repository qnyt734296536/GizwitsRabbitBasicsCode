#ifndef _HAL_RELAY_H_
#define _HAL_RELAY_H_

#include "common.h"

#define RELAY_STATE_OFF 0   //继电器关闭
#define RELAY_STATE_ON 1    //继电器打开

/**
*初始化继电器
*/
void Init_Relay(void);

/**
*控制继电器开关
*高电平Out2,低电平out1
*/
void Control_Relay(char state);



void Test_Relay(void);
#endif

