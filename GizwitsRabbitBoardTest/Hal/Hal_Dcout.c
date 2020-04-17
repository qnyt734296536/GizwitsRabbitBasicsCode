#include "Hal_Dcout.h"

#define DCOUT_PIN	GPIO_PIN_6 //12VÊä³ö PC6
#define DCOUT_GPIO_TYPE GPIOC

void Init_Dcout(void)
{
	HAL_GPIO_WritePin(DCOUT_GPIO_TYPE,DCOUT_PIN,GPIO_PIN_RESET);
}



void Set_Dcout_State(char on_off)
{
	if (on_off == 1)
	{
	
		HAL_GPIO_WritePin(DCOUT_GPIO_TYPE,DCOUT_PIN,GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(DCOUT_GPIO_TYPE,DCOUT_PIN,GPIO_PIN_RESET);
	}

}



void Test_Dcout(void)
{
	static uint16_t count=0;
	if(count ==0)
	{
		Set_Dcout_State(1);
	}
	else if(count ==1000)
	{
		Set_Dcout_State(0);
	}
	else if(count >1500)
  {
		count =0;
	}
	
	count++;

}
