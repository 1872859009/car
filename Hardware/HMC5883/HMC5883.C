#include "stm32f10x.h"                 
#include "HMC5883.h"
#include "Delay.h"
#include "MyI2C.h"
#include "HMC5883_Reg.h"
#define HMC5883_WRITE_ADDRESS		0x3C
#define HMC5883_READ_ADDRESS    0X3D
void HMC5883_WriteReg(uint8_t RegAddress, uint8_t Data)
{
	MyI2C_Start();						//I2C起始
	MyI2C_SendByte(HMC5883_WRITE_ADDRESS);	//发送从机地址，读写位为0，表示即将写入
	MyI2C_ReceiveAck();					//接收应答
	MyI2C_SendByte(RegAddress);			//发送寄存器地址
	MyI2C_ReceiveAck();					//接收应答
	MyI2C_SendByte(Data);				//发送要写入寄存器的数据
	MyI2C_ReceiveAck();					//接收应答
	MyI2C_Stop();						//I2C终止
}

uint8_t HMC5883_ReadReg(uint8_t RegAddress)
{
	
	uint8_t Data;
	
	MyI2C_Start();						//I2C起始
	MyI2C_SendByte(HMC5883_WRITE_ADDRESS);	//发送从机地址，读写位为0，表示即将写入
	MyI2C_ReceiveAck();					//接收应答
	MyI2C_SendByte(RegAddress);			//发送寄存器地址
	MyI2C_ReceiveAck();					//接收应答
	
	MyI2C_Start();						//I2C重复起始
	MyI2C_SendByte(HMC5883_READ_ADDRESS);	//发送从机地址，读写位为1，表示即将读取
	MyI2C_ReceiveAck();					//接收应答
	Data = MyI2C_ReceiveByte();			//接收指定寄存器的数据
	MyI2C_SendAck(1);					//发送应答，给从机非应答，终止从机的数据输出
	MyI2C_Stop();						//I2C终止

	return Data;
}

void HMC5883_Init(void)
{
	MyI2C_Init();									//先初始化底层的I2C
	Delay_ms(100);
	/*HMC5883寄存器初始化，需要对照HMC5883手册的寄存器描述配置，此处仅配置了部分重要的寄存器*/
	HMC5883_WriteReg(Configuration_Register_A, 0x70);		
	HMC5883_WriteReg(Configuration_Register_B, 0x20);		
  HMC5883_WriteReg(Mode_Register, 0x00);
}


//void HMC5883_GetData(int16_t *X,int16_t *Y,int16_t *Z)
//{
//	uint16_t DataH, DataL;
//	DataH = HMC5883_ReadReg(Data_Output_X_MSB_Register);		//读取X轴的高8位数据
//	DataL = HMC5883_ReadReg(Data_Output_X_LSB_Register);		//读取X轴的低8位数据
//	*X = (DataH << 8) | DataL;						//数据拼接，通过输出参数返回
//	
//	DataH = HMC5883_ReadReg(Data_Output_Y_MSB_Register);		//读取Y轴的高8位数据
//	DataL = HMC5883_ReadReg(Data_Output_Y_LSB_Register);		//读取Y轴的低8位数据
//	*Y = (DataH << 8) | DataL;						//数据拼接，通过输出参数返回
//	
//	DataH = HMC5883_ReadReg(Data_Output_Z_MSB_Register);		//读取Z轴的高8位数据
//	DataL = HMC5883_ReadReg(Data_Output_Z_LSB_Register);		//读取Z轴的低8位数据
//	*Z = (DataH << 8) | DataL;						//数据拼接，通过输出参数返回
//}

void HMC5883_GetData(HMC5883_Data_TypeDef *HMC5883_Data)
{

	HMC5883_Data -> X_DataH=HMC5883_ReadReg(Data_Output_X_MSB_Register);
  HMC5883_Data -> X_DataL=HMC5883_ReadReg(Data_Output_X_LSB_Register);
	HMC5883_Data -> Y_DataH=HMC5883_ReadReg(Data_Output_Y_MSB_Register);
  HMC5883_Data -> Y_DataL=HMC5883_ReadReg(Data_Output_Y_LSB_Register);
	HMC5883_Data -> Z_DataH=HMC5883_ReadReg(Data_Output_Z_MSB_Register);
  HMC5883_Data -> Z_DataL=HMC5883_ReadReg(Data_Output_Z_LSB_Register);
  Delay_ms(10);
	

}
