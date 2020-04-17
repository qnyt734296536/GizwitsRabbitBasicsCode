#include "Hal_Infrared_Tube.h"

static uint8_t gInfTubeState = 1;
static uint8_t  gTrigger = 0;

/**
*设置红外对射管状态
*低电平遮挡，高电平没遮挡
*/
void Set_InfTube_State(char level)
{
	gInfTubeState = level;
	if(gInfTubeState == 0)
	{
		gTrigger = 1;
	}
	printf("Set infTube levle is %d, gInfState is %d\r\n",level,gInfTubeState);
}


/**
*获取红外对管状态
*0表示没遮挡,1表示遮挡
*/
uint8_t Get_InfTube_State(void)
{
	uint8_t state=0;
	state = gInfTubeState==1?0:1;
	return state;
}



/**
*获红外对管是否被触发
*/
uint8_t Get_InfTube_State_Trigger(void)
{
	uint8_t state = 0;
	
	if(gTrigger == 1)
	{
		gTrigger = 0;
		state = 1;
	}
	return state;
}


