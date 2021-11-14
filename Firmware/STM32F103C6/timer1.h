#ifndef  TIMER1_H
#define TIMER1_H

#define F_CLK_TIM1 100000UL

#include <stm32f103x6.h>
#include <stdint.h>

void TIMER1_Init(void);
void TIMER1_Start(void);
void TIMER1_Stop(void);

uint32_t TIMER1_GetValue(void);

#endif
