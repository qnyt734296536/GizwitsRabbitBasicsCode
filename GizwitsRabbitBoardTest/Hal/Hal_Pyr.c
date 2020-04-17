#include "Hal_pyr.h"

static uint8_t  gPyrState = 0;
static uint8_t  gTrigger = 0;

/**
*当时的电平
*有人高电平;没人低电平
*/
void Set_Pyr_State(char level)
{
	gPyrState = level;
	if(gPyrState == 1)
	{
		gTrigger =1;
	}
	//printf("Set Pyr levle is %d, PyrState is %d\r\n",level,gPyrState);
}


/**
*获取热释电是否被触发
*/
uint8_t Get_Pyr_State_Trigger(void)
{
	uint8_t state = 0;
	
	if(gTrigger == 1)
	{
		gTrigger = 0;
		state = 1;
	}
	return state;
}



uint8_t Get_Pyr_State(void)
{

	return gPyrState;
}

