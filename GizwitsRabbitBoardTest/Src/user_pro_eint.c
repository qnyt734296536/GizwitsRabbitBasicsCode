#include "user_pro_eint.h"
#include "Hal_Key.h"
#include "Hal_Pyr.h"
#include "Hal_Infrared_Tube.h"
#include "Hal_Inf_Receiver.h"


/**
*GPIO 外部中断的回调函数
*/
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	char state = 0;

	if(GPIO_Pin == INF_RECEIVER_PIN) //红外遥控接受头
	{
		state = HAL_GPIO_ReadPin(INF_RECEIVER_GPIO_TYPE, INF_RECEIVER_PIN);
		Pro_Inf_Receiver_Pin_Eint(state);
		
	}
	else if (GPIO_Pin == PYR_PIN)//热释电
	{
		state = HAL_GPIO_ReadPin(PYR_GPIO_TYPE, PYR_PIN);

		Set_Pyr_State(state);
		
		//printf("pyr state is %d\r\n",state);
	}
	
	else if (GPIO_Pin == INF_TUBE_PIN)//红外对管
	{
		state = HAL_GPIO_ReadPin(INF_TUBE_GPIO_TYPE, INF_TUBE_PIN);

		Set_InfTube_State(state);
		
		//printf("inf tube state is %d\r\n",state);
	}

	

}

