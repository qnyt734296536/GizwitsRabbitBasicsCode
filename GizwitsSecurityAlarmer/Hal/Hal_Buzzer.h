#ifndef _HAL_BUZZER_H_
#define _HAL_BUZZER_H_

#include "common.h"


/**
*初始化蜂鸣器
*/
void Init_Buzzer(void);

/**
*控制蜂鸣器响几声
*/
void Control_Buzzer(char num, char ms);


void Test_Buzzer(void);

#endif

