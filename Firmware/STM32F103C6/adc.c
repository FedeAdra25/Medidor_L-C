#include <adc.h>


void ADC_Init(void){
	GPIOA->CRL&=0xFFFFFF0F;  // PA1(ADC_IN1) as analog input
	ADC1->CR2=1; //ADON=1 power-up
	ADC1->SMPR2=1<<3; //SMP1=001
	delay_ms(1); //wait a little bit to make sure adc is stable
}
uint32_t ADC_GetInputInmV(void){
	volatile uint32_t volts;
	ADC1->SQR3=1; //choose channel 1 as input
	ADC1->CR2=1; //ADON=1 (start conversion)		
	while((ADC1->SR&(1<<1))==0); //wait until the EOC flag is set		
	volts=(ADC1->DR*3300)/4096; //res*Vref / steps = ~ Vin[mV]
	return volts;
}
