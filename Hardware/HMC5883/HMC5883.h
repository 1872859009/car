#ifndef _HMC5883_H_
#define _HMC5883_H_
#include "stm32f10x.h"

void HMC5883_WriteReg(uint8_t RegAddress, uint8_t Data);
uint8_t HMC5883_ReadReg(uint8_t RegAddress);
void HMC5883_Init(void);
//void HMC5883_GetData(int16_t *X,int16_t *Y,int16_t *Z);



typedef struct
{
	uint8_t  X_DataH;		//X高八位
	uint8_t  X_DataL;	 	//X低八位
	uint8_t  Y_DataH;	 	//Y高八位
	uint8_t  Y_DataL;	 	//Y低八位
	uint8_t  Z_DataH;	 	//Z高八位
	uint8_t  Z_DataL;	  //Z低八位               
}HMC5883_Data_TypeDef;




void HMC5883_GetData(HMC5883_Data_TypeDef *HMC5883_Data);
#endif

