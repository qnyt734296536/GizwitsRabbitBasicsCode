#include "common.h"
#include "user_pro.h"
#include "delay.h"
#include "Hal_Pyr.h"
#include "Hal_Buzzer.h"
#include "Hal_Infrared_Tube.h"

#include "gizwits_product.h"

extern dataPoint_t currentDataPoint;

DeviceInfo_T gDeviceInfo;



/**
*GPIO 外部中断的回调函数
*/
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	char state = 0;
	
	if (GPIO_Pin == PYR_PIN)//热释电
	{
		state = HAL_GPIO_ReadPin(PYR_GPIO_TYPE, PYR_PIN);

		Set_Pyr_State(state);
		
	}

	else if (GPIO_Pin == INF_TUBE_PIN)//红外对管
	{
		state = HAL_GPIO_ReadPin(INF_TUBE_GPIO_TYPE, INF_TUBE_PIN);

		Set_InfTube_State(state);
	}

}



void SetDeviceInfo(dataPoint_t data)
{
	
	printf("server send data to rabbit\r\n");
	gDeviceInfo.workMode =data.valuefortify;

	
}

void UserProInit(void)
{
	Delay_Init(72);
	Init_Buzzer();
}


void UserPro(void)
{
	
	static uint8_t trigger;
	static int time = 0;
	//如果被触发了
	if(Get_Pyr_State_Trigger())
	{
		printf("pyr have people workMode is %d\r\n",gDeviceInfo.workMode);
		trigger = 1;
		time = gizGetTimerCount();
	}
	
	if(Get_InfTube_State_Trigger())
	{
		printf("inf tube  have people workMode is %d\r\n",gDeviceInfo.workMode);
		trigger = 1;
		time = gizGetTimerCount();
	}
	
	if(trigger == 1) //触发后检查
	{
		if(gDeviceInfo.workMode == 1) //设防
		{
			Control_Buzzer(3,50);
		}
		currentDataPoint.valuealaram_flag = 1;
		
	}
	
	if(gizGetTimerCount() - time > 10000) //触发报警后10秒停止报警
	{
			trigger = 0; 
	}
	
	if(trigger == 0)
	{
		currentDataPoint.valuealaram_flag = 0;
	}
	
	
	currentDataPoint.valuepyr = Get_Pyr_State();
	currentDataPoint.valueinf_tube = Get_InfTube_State()==1?0:1;	//低电平表示遮挡

}


