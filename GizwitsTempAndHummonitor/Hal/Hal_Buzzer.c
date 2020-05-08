#include "Hal_Buzzer.h"

#define BUZZER_PIN	GPIO_PIN_5 //蜂鸣器PC5
#define BUZZER_GPIO_TYPE GPIOC


/**
*初始化蜂鸣器
*/
void Init_Buzzer(void)
{
	HAL_GPIO_WritePin(BUZZER_GPIO_TYPE,BUZZER_PIN,GPIO_PIN_RESET);
}


/**
*控制蜂鸣器响几声
*/
void Control_Buzzer(char num, char ms)
{
	char i =0;
	do
	{
		HAL_GPIO_WritePin(BUZZER_GPIO_TYPE,BUZZER_PIN,GPIO_PIN_SET);
		Delay_Ms(ms);
		HAL_GPIO_WritePin(BUZZER_GPIO_TYPE,BUZZER_PIN,GPIO_PIN_RESET);
		Delay_Ms(ms);
	}while(i++ < num);

}


void Test_Buzzer(void)
{
	static uint16_t count =0;
	if(count<10)
	{
		HAL_GPIO_WritePin(BUZZER_GPIO_TYPE,BUZZER_PIN,GPIO_PIN_SET);
	}
	else if(count <500)
	{
		HAL_GPIO_WritePin(BUZZER_GPIO_TYPE,BUZZER_PIN,GPIO_PIN_RESET);
	}
	
	else if(count > 1000)
	{
		count = 0;
	}
	
	count++;
}


