#include "ai.h"
#include "gpio.h"
#include "Delay.h"
#include "pwm.h"
#include "stm32f10x.h"

void calculate(float head,float left,float right )
{
	if((head>15)&&(left>15)&&(right>15))			//直走
			{
//				if(head>100)
//				{
//					Left(460,460);
//					delay_ms(80);
//				}
//				else
				
				{
					GO(450,450);
					Delay_ms(200);
				}
				
			}
			else if(((right<left)&&(head<15)))		//左转
			{
				Behind(430,430);
				Delay_ms(40);
				Left(460,460);
				Delay_ms(80);
			}
			else if(((left<right)&&(head<15)))		//右转
			{
				Behind(430,430);
				Delay_ms(40);
				Right(460,460);
				Delay_ms(80);
			}
			else if(left<15)								//	右微调
			{	
				Right(460,460);
				Delay_ms(50);
			}
			
			else if(right<15)								//	左微调
			{	
				Left(460,460);
				Delay_ms(50);
			}
//			if((head<20)||(left<15)||(right<15))
//			{


//				if((head<8)||(left<5)||(right<5))
//				{
//					Behind(880,500);
//					Delay_ms(50);
//				}
//				else if(left<10)							//15
//				{
//					Right(920,500);
//					Delay_ms(50);
//				}
//				else if(right<10)			  //15
//				{
//					
//					Left(920,500);
//					Delay_ms(50);
//				}
//				else
//					GO(880,880);
//			}
//			
//			else if((head>30)&&(left>120)&&(right>50)&&(head<40))   //left 110,right 45
//			{
//					Left(900,900);
//					Delay_ms(5000);
//					GO(900,900);
//					Delay_ms(2500);
//			}
//			else GO(900,900);


//if((head>15)&&(left>15)&&(right>15))
//{
//		GO(900,900);

//}

//if((head>15)&&(left>15)&&(right>15))




























}
