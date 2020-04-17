#include "Hal_led.h"
#include "gpio.h"


/**
*控制开发板上的4个LED
*/
void Control_Led(char led,char state)
{
	
	if (state == 1)
	{
		if (led == LED1)
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET);//PC7
		}
		if (led == LED2)
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);//PC8
		}
		if (led == LED3)
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);//PC9
		}
		if (led == LED4)
		{
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);//PA8
		}
	}
	else
	{
		if (led == LED1)
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_RESET);//PC7
		}
		if (led == LED2)
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);//PC8
		}
		if (led == LED3)
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);//PC9
		}
		if (led == LED4)
		{
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);//PA8
		}
	
	}
}


/**
*测试 LED
*/
void Test_Led(void)
{
	static uint16_t count = 0;
	//LOG("Test_Led!");
	if (count == 200)
	{
		Control_Led(LED1,1);
		Control_Led(LED2,1);
		Control_Led(LED3,1);
		Control_Led(LED4,1);
	}
	else if(count == 400)
	{
		Control_Led(LED1,0);
		Control_Led(LED2,0);
		Control_Led(LED3,0);
		Control_Led(LED4,0);
	}
	else if(count >600)
  {
		count =0;
	}
	count ++;

}

