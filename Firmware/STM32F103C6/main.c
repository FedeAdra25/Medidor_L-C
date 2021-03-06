/* Main.c file generated by New Project wizard
 *
 * Created:   Tue Nov 9 2021
 * Processor: STM32F103C6
 * Compiler:  Keil for ARM
 */

#include <main.h>


volatile uint32_t capacitance=0,inductance=0; //capacitance and inductance in uF and uH
int main (void)
 { 
   // RCC first cuz simulation crashes otherwise :(
	RCC->APB2ENR|= 0xFC | (1<<9) | (1<<14) | (1<<11); //enable clock for GPIO, ADC1 clock, usart1 and TIM1.
	RCC->APB1ENR|= (1<<11); //enable TIM2 (L measure uses it)

	System_Init();
	LCDinit();
	usart1_init();
	ADC_Init();
	TIMER1_Init();
	LCDclr();	
   while (1){
		LCDGotoXY(0,0);
		//delay_ms(100);
		capacitance = System_MeasureC();
		LCDstring("C= ",3);
		LCDSendInt(capacitance);
		LCDstring("nF", 2); // 1% error aprox
		LCDGotoXY(0,1);
		//delay_ms(100);
		inductance = System_MeasureL();
		LCDstring("F= ", 3);
		LCDSendInt(inductance);
		LCDstring("uH", 2); //10% error aprox
	}
   return 0;
 }


