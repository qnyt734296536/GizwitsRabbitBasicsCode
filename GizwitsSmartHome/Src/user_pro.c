#include "common.h"
#include "user_pro.h"
#include "delay.h"
#include "Hal_Pyr.h"
#include "Hal_Rgb_My9291.h"
#include "Hal_Relay.h"
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
		
		//LOG("pyr state is %d\r\n",state);
	}

	

}



void SetDeviceInfo(dataPoint_t data)
{
	
	printf("server send data to rabbit\r\n");
	gDeviceInfo.r =data.valuergb_r;
	gDeviceInfo.g =data.valuergb_g;
	gDeviceInfo.b =data.valuergb_b;
	gDeviceInfo.workMode =data.valuecontrol_mode;
	gDeviceInfo.relay = data.valuerelay ;
	
	gDeviceInfo.changeFlag = 1;
	
}

void UserProInit(void)
{
	Delay_Init(72);
	Init_My9291();
	Init_Relay();
}


void UserPro(void)
{
	
	static uint8_t trigger;
	//如果被触发了
	if(Get_Pyr_State_Trigger())
	{
		printf("pyr have people workMode is %d\r\n",gDeviceInfo.workMode);
		trigger = 1;
		if(gDeviceInfo.workMode == 1) //自动模式
		{
			//打开LED，打开继电器,等时间到了自动关闭
			
			gDeviceInfo.relay = 1;
			if(gDeviceInfo.r==0 && gDeviceInfo.g==0 && gDeviceInfo.b== 0)
			{
				gDeviceInfo.r=4095;
				gDeviceInfo.g=4095;
				gDeviceInfo.b=4095;
			}
			My9291_Send_Duty(gDeviceInfo.r,gDeviceInfo.g,gDeviceInfo.b,0);
			Control_Relay(gDeviceInfo.relay);
		}
	}
	
	if(trigger == 1) //触发后检查
	{
		if(Get_Pyr_State() == 0)
		{
			printf("pyr no people workMode is %d\r\n",gDeviceInfo.workMode);
			trigger = 0;
			if(gDeviceInfo.workMode == 1) //自动模式
			{
				//打开LED，打开继电器,等时间到了自动关闭
				
			  gDeviceInfo.relay = 0;
				My9291_Send_Duty(0,0,0,0);
				Control_Relay(gDeviceInfo.relay);
			}
		}
	}
	
	//手动控制
	if(gDeviceInfo.workMode == 0)
	{
		if(gDeviceInfo.changeFlag == 1)
		{
			gDeviceInfo.changeFlag =0;
			My9291_Send_Duty(gDeviceInfo.r,gDeviceInfo.g,gDeviceInfo.b,0);
			Control_Relay(gDeviceInfo.relay);
		}
	}
	
	
	currentDataPoint.valuepyr = Get_Pyr_State();
	currentDataPoint.valuerelay = gDeviceInfo.relay;
	currentDataPoint.valuergb_r = gDeviceInfo.r;
	currentDataPoint.valuergb_g = gDeviceInfo.g;
	currentDataPoint.valuergb_b = gDeviceInfo.b;
	

}


