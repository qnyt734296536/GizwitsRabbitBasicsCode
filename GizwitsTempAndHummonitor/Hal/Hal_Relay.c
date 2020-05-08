#include "Hal_Relay.h"


#define RELAY_PIN	GPIO_PIN_3 //继电器PB3
#define RELAY_GPIO_TYPE GPIOB


/**
*初始化继电器
*/
void Init_Relay(void)
{
	HAL_GPIO_WritePin(RELAY_GPIO_TYPE,RELAY_PIN,GPIO_PIN_RESET);
}


/**
*控制继电器开关
*高电平Out2,低电平out1
*/
void Control_Relay(char state)
{
		if (state == 1)
		{
			HAL_GPIO_WritePin(RELAY_GPIO_TYPE,RELAY_PIN,GPIO_PIN_SET);
		}
		else
		{
			HAL_GPIO_WritePin(RELAY_GPIO_TYPE,RELAY_PIN,GPIO_PIN_RESET);
		}
}




void Test_Relay(void)
{
	static uint16_t count =0;
	if(count == 1)
	{
		Control_Relay(RELAY_STATE_ON);
	}
	else if(count ==1000)
	{
		Control_Relay(RELAY_STATE_OFF);
	}
	else if(count >1500)
  {
		count =0;
	}
	count++;
}


