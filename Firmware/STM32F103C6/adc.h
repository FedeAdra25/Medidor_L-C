#ifndef  ADC_H
#define ADC_H


#include <stm32f103x6.h>
#include <stdint.h>
#include <utils.h>

//This library sets GPIOA->CRL to 0x44444404 only for using PA1 as analog input

void ADC_Init(void);
uint32_t ADC_GetInputInmV(void);



#endif

