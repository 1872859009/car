#include "gpio.h"

void gpio_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //使能PA端口时钟
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //使能PA端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;				  
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz							//右侧距发信号
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA.3
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;				  
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz							//前侧距发信号
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA.4
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;				  
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz							//左侧距发信号
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA.5
 
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;				  
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz							//PB8\PB9 AN1-2  PA12\PA11 BN1-2
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA.5
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;				  
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz							//PB8\PB9 AN1-2  PA12\PA11 BN1-2
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA.5
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;				  
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz							//PB8\PB9 AN1-2  PA12\PA11 BN1-2
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA.5
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;				  
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz							//PB8\PB9 AN1-2  PA12\PA11 BN1-2
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA.5
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				  
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 
}




void GO(int L,int R)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_8);						 //PB8 输出高
	GPIO_SetBits(GPIOA,GPIO_Pin_2);					 //PB10 输出高
	GPIO_ResetBits(GPIOB,GPIO_Pin_9);					 //PB9 low
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);	 			 //PB11 low
	TIM_SetCompare1(TIM1,L);	
	TIM_SetCompare4(TIM1,R);
}

void Left(int L,int R)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_8);						 //PB8 输出高
	GPIO_SetBits(GPIOA,GPIO_Pin_12);					 //PB10 输出高
	GPIO_ResetBits(GPIOB,GPIO_Pin_9);					 //PB9 low
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);				 //PB11 low
	TIM_SetCompare1(TIM1,L);	
	TIM_SetCompare4(TIM1,R);
}

void Right(int L,int R)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_9);						 //PB8 输出高
	GPIO_SetBits(GPIOA,GPIO_Pin_2);					 //PB10 输出高
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);					 //PB9 low
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);				 //PB11 low
	TIM_SetCompare1(TIM1,L);	
	TIM_SetCompare4(TIM1,R);
}

void Behind(int L,int R)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_9);						 //PB8 输出高
	GPIO_SetBits(GPIOA,GPIO_Pin_12);					 //PB10 输出高
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);					 //PB9 low
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);				 //PB11 low
	TIM_SetCompare1(TIM1,L);	
	TIM_SetCompare4(TIM1,R);
}

void Stop()
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);
	GPIO_ResetBits(GPIOB,GPIO_Pin_9);
	GPIO_ResetBits(GPIOA,GPIO_Pin_12);
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);
}

