#ifndef __SERIAL3_H
#define __SERIAL3_H

#include "stm32f10x.h"  

extern  char Serial3_RxPacket[];
extern uint8_t Serial3_RxFlag;
extern volatile uint32_t receive_counter;	// 定义GPS接收计数器


void Serial3_Init(void);
void Serial3_SendByte(uint8_t Byte);
void Serial3_SendArray(uint8_t *Array, uint16_t Length);
void Serial3_SendString(char *String);
void Serial3_SendNumber(uint32_t Number, uint8_t Length);
void Serial3_Printf(char *format, ...);
uint8_t Serial3_GetRxData(void);
void GPS(void);
#endif
