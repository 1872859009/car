#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "pwm.h"
#include "gpio.h"
#include "read.h"
#include "Timer.h"
#include "ai.h"
#include "HMC5883.h"
#include "ps2.h"
#include "Serial.h"
#include "Serial3.h"
#include "OLED.h"
void ps2_control(void);
void Normol(void);
void Follow(void);
void Clean(void);

uint8_t KeyNum;
uint8_t PS2_Mode,Last_PS2_Mode;
uint8_t a,b,c;
float	zuo,qian,you;

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	PS2_Init();
	TIM1_PWM_Init(3600-1,0);		//不分频。PWM频率=72000/(3600)=20Khz
	TIM1_2_PWM_Init(3600-1,0);	//不分频。PWM频率=72000/(3600)=20Khz
	TIM2_Cap_Init(0XFFFF,72-1);		//以1Mhz的频率计数 
	TIM4_Cap_Init(0XFFFF,72-1);
	TIM3_Cap_Init(0XFFFF,72-1);
	Serial_Init();
	Serial3_Init();
	gpio_Init();
	while(1)
	{	

	switch(Serial_GetRxData())
	{ case 0:c=0;break;
		case 1:c=1;break;
		case 2:c=2;break;
		case 3:c=3;break;
		case 4:b=4;break;
		case 5:b=5;break;
	}	
		
		
		
		if(c==1)
		{
			Normol();
			Clean();
			
			
		}
		
		
		if(c==2)
		{
		  ps2_control();
			Clean();
		}
		
		
		if(c==3)
		{
			
      Follow();
			
		}

		if(c==0)
		{
			
      Stop();
			
		}
	
	
		

	
	}	
}




void ps2_control(void)
{
	
	  KeyNum = ps2_key_serch();
		PS2_Mode = ps2_mode_get();
		
		if (PS2_Mode != Last_PS2_Mode)
		{
			GO(0,0);
		}
		   
		if (PS2_Mode == PSB_REDLIGHT_MODE)
		{
			unsigned char ps2_lx,ps2_ly;
			
			ps2_lx = ps2_get_anolog_data(PSS_LX);
			ps2_ly = ps2_get_anolog_data(PSS_LY);
			
			if ( ps2_ly == 0x00)
			{
				GO(1000,1000);
			}
			else if (ps2_ly == 0xff)
			{
				Behind(1000,1000);
			}
			else if (ps2_lx == 0x00)
			{
				Left(1000,1000);
			}
			else if (ps2_lx == 0xff)
			{
				Right(1000,1000);
			}
			else
			{
				if (ps2_get_key_state(PSB_L1))
				{
//					Car_TurnLeft(1000);
				}
				else if (ps2_get_key_state(PSB_L2))
				{
//					Car_TurnRight(1000);
				}				
				else
				{
					GO(0,0);
				}			
			}
			
			
		}


		
		else if (PS2_Mode == PSB_GREENLIGHT_MODE)
		{
			if (KeyNum)
			{
				if (ps2_get_key_state(PSB_PAD_UP))
				{
					GO(1000,1000);
				}
				else if (ps2_get_key_state(PSB_PAD_DOWN))
				{
					Behind(1000,1000);
				}
				else if (ps2_get_key_state(PSB_PAD_LEFT))
				{
					Left(1000,1000);
				}
				else if (ps2_get_key_state(PSB_PAD_RIGHT))
				{
					Right(1000,1000);
				}	
				else if (ps2_get_key_state(PSB_L1))
				{
//					Car_TurnLeft(1000);
				}
				else if (ps2_get_key_state(PSB_L2))
				{
//					Car_TurnRight(1000);
				}				
				else
				{
					GO(0,0);
				}
						
			}
			else
			{
				GO(0,0);
			}
		}
		else
		{
			GO(0,0);
		}
		Last_PS2_Mode = PS2_Mode;
		Delay_ms(20);}

void Normol(void)
{
	
	  zuo=read_zuo();
		qian=read_qian();
		you=read_you();
		
		calculate(qian,zuo,you);

}

void Follow(void)
{
	a=Serial3_GetRxData();
			if(a==4)
		    {Left(500,500);}
		
			if(a==5)
		    {Right(500,500);}
		
			if(a==6||a==0)
		    {Stop();}
			if(a==7)
		    {GO(500,500);}
			if(a==8)
				{
				 Behind(500,500);
				}

}
void Clean(void)
{
		if(b==4)
		{
      GPIO_SetBits(GPIOB,GPIO_Pin_5);
		}
		if(b==5)
		{
			
      GPIO_ResetBits(GPIOB,GPIO_Pin_5);
			
		}


}

