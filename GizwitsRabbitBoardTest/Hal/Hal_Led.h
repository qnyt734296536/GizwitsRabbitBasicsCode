#ifndef _HAL_LED_H_
#define _HAL_LED_H_
#include <stm32f1xx.h>


//定义LED编号
#define LED1 1
#define LED2 2
#define LED3 3
#define LED4 4


/**
*控制开发板上的4个LED
*/
void Control_Led(char led,char state);


/**
*测试 LED
*/
void Test_Led(void);

#endif

