#include "common.h"
#include "user_pro.h"
#include "delay.h"
#include "Hal_Relay.h"
#include "Hal_Buzzer.h"
#include "Hal_Temp_Hum.h"
#include "gizwits_product.h"

extern dataPoint_t currentDataPoint;

DeviceInfo_T gDeviceInfo;






void SetDeviceInfo(dataPoint_t data)
{
	
	printf("server send data to rabbit\r\n");

	gDeviceInfo.workMode =data.valuealarm_mode;
	gDeviceInfo.relay = data.valuerelay ;
	gDeviceInfo.buzzer = data.valuebuzzer;
	gDeviceInfo.changeFlag = 1;
	
}

void UserProInit(void)
{
	Delay_Init(72);
	Init_Buzzer();
	Init_Relay();
}


void UserPro(void)
{
	static int time = 0;
	uint8_t alarming = 0;
	uint8_t temperature = 0, humidity = 0;
	if(gizGetTimerCount()-time > 3000)
	{
		time = gizGetTimerCount();
		dht11ReadData(&temperature, &humidity);
		
		printf("T=%d,H=%d\r\n",temperature, humidity);
		printf("Alarm T_H=%f,T_D=%f\r\n",currentDataPoint.valuetemperature_up, currentDataPoint.valuetemperature_down);
		printf("Alarm H_H=%f,H_D=%f\r\n",currentDataPoint.valuehumidity_up, currentDataPoint.valuehumidity_down);
		printf("workMode =%d\r\n",gDeviceInfo.workMode);
		if(temperature <currentDataPoint.valuetemperature_down 
			|| temperature > currentDataPoint.valuetemperature_up)
		{
			printf("temp alarming\r\n");
			alarming=1;
		}
		
		if (humidity <currentDataPoint.valuehumidity_down 
			|| humidity > currentDataPoint.valuehumidity_up)
		{
			printf("hum alarming\r\n");
			alarming=1;
		}

		
		if(gDeviceInfo.workMode == 1)//×Ô¶¯
		{
			if(alarming==1)
			{
				gDeviceInfo.buzzer=1;
				gDeviceInfo.relay = 1;
				Control_Relay(1);
				Control_Buzzer(3,50);
			}
			else
			{
				gDeviceInfo.buzzer=0;
				gDeviceInfo.relay = 0;
				Control_Relay(0);
			}
		
		}
		
		currentDataPoint.valuetemperature = temperature;
		currentDataPoint.valuehumidity = humidity;
		
	}
	
	if(gDeviceInfo.workMode == 0)
	{
			if(	gDeviceInfo.changeFlag ==1)
			{	
				gDeviceInfo.changeFlag = 0;
				Control_Relay(gDeviceInfo.relay);
			}
			
			if(gDeviceInfo.buzzer==1)
			{
				Control_Buzzer(3,50);
			}
	}
	
	

	
	
	currentDataPoint.valuebuzzer = gDeviceInfo.buzzer;
	currentDataPoint.valuerelay = gDeviceInfo.relay;
}


