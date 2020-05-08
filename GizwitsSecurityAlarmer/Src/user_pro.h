#ifndef _USER_PRO_H_
#define _USER_PRO_H_

#include "gizwits_product.h"

typedef struct _device_info_
{
	uint8_t workMode;
	uint8_t pyr;
	uint8_t inf_tube;

}DeviceInfo_T;


void UserProInit(void);

void UserPro(void);


void SetDeviceInfo(dataPoint_t data);
#endif

