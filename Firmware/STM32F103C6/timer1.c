#include <timer1.h>

void TIMER1_Init(void){	
	TIM1->ARR=0xFFFF; //top register set to maximum value
	TIM1->PSC=720-1;
	TIM1->CNT=0x0000; //initial value of counter
	TIM1->CR1 = 0x00;/* up counting, stopped */
}
void TIMER1_Start(void){
	TIM1->CNT=0x0000; //reset timer
	TIM1->CR1 |= 1; //start timer if not started
}

void TIMER1_Stop(void){
	TIM1->CNT=0x0000; //reset timer
	TIM1->CR1 &= ~(1); //start timer if not started
}
uint32_t TIMER1_GetValue(void){
	volatile uint32_t value;
	value = TIM1->CNT;
	return value;
}
