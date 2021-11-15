#ifndef  ADC_H
#define ADC_H


#include <stm32f103x6.h>
#include <stdint.h>
#include <utils.h>

void ADC_Init(void);
uint32_t ADC_GetInputInmV(void);



#endif

