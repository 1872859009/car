#ifndef __TIMER_H
#define __TIMER_H

void Timer_Init(void);
uint16_t Timer_GetCounter(void);
void TIM2_Cap_Init(u16 arr,u16 psc);
void TIM3_Cap_Init(u16 arr,u16 psc);
void TIM4_Cap_Init(u16 arr,u16 psc);

#endif
