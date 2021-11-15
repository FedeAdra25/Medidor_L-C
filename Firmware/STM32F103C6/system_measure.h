#ifndef  SYSTEM_MEASURE_H
#define SYSTEM_MEASURE_H


#include <stm32f103x6.h>
#include <stdint.h>
#include <utils.h>
#include <timer1.h>
#include <adc.h>
#include <usart.h>

#define VOLTAGE_AT_TAU 2086

void System_Init(void);

uint32_t System_MeasureC(void);
uint32_t System_MeasureL(void);

#endif

