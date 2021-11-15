
#include <system_measure.h>

//RC_FACTOR: R*C=T --> C = T/RC_FACTOR, T[us] and C[nF] for R=10Kohm
#define RC_FACTOR 10
#define PI 3.14159265358
#define C_VALUE 10



volatile uint32_t temp=0,capacitanceM=0,inductanceL;
volatile float measures[30],L;

void System_Init(void){
	GPIOB->CRL = 0x44444443; //configure PB0 as output

	//Configuration for measuring C	

	//Configuration for measuring L
	//Tim2 config
	RCC->APB1ENR |= (1<<0); //enable TIM2 clock to use as InputCapture
	GPIOA->CRL = 0x44444844; /* PA2 (TIM2 CH3): input pull-up */
	GPIOA->ODR |= (1<<2);
	TIM2->CCMR2 = 0x001; /* Pin TIM2_CH3 as input for channel 3 */
	TIM2->CCER = (1<< 8); /*CC3P = 0 (rising), CC3E = 1 (enable)*/
	TIM2->PSC = 72-1; //F_clk=1000000Hz=1MHz
	TIM2->ARR = 50000-1; //Count up to 50000 -> ?maximum freq= 5seconds?
}

uint32_t System_MeasureC(void){
	capacitanceM=0;
	GPIOB->BSRR=(1<<16); //clear to discharge capacitor in case it was charged
	delay_ms(300); //wait until discharge
	TIMER1_Start(); //start timer
	GPIOB->BSRR=(1<<0); //start charging capacitor
	while(1){ //while Vc<trigger
		temp=ADC_GetInputInmV();
		if(temp>=2086){
			capacitanceM=(TIMER1_GetValue())*(1000000UL/(F_CLK_TIM1)); //time in us
			capacitanceM=capacitanceM/RC_FACTOR;
			usart1_sendStr("Stopped at [mv] -> ");
			usart1_sendInt(temp);
			usart1_sendStr(". Capacitance [uF] -> ");
			usart1_sendInt(capacitanceM);
			usart1_sendStr("\n\r");
			TIMER1_Stop();
			break; //break the while
		}
	}
	return capacitanceM;

}
uint32_t System_MeasureL(void){
	volatile uint32_t i,t=0,t0=0,T=0,min,max,imin,imax;
	GPIOB->BSRR=(1<<0); //start charging LC circuit
	delay_ms(300); //wait a little
	GPIOB->BSRR=(1<<16); //bsrr set to 0, now we meassure L
	TIM2->CR1 = 1;/* start counting up  ACTIVATE TIM2*/
	for(i=0;i<30;i++){
		while((TIM2->SR &(1<<3)) == 0); /* wait until the CC3IF flag sets */
		t = TIM2->CCR3;/* read the captured value */
		T = t-t0; //t0=0
		t0=t;
		measures[i]=T; //save T measure in array
	}
	//Filter out minimum and maximum (excluding first and last 5 measures)
	min=measures[0];
	max=measures[0];
	for(i=5;i<24;i++){
		if(measures[i]<min){
			min=measures[i];
			imin=i;
		}
		if(measures[i]>max){
			max=measures[i];
			imax=i;
		}
	}
	//Filter out first and last 5 measures
	for(i=5;i<24;i++){ //skip first 5 measures and last 5, minimum and maximum value
		if(i==imin || i==imax)
			continue;
		L=(measures[i]*measures[i])/(PI*PI*4*C_VALUE); //calculate L
		inductanceL=inductanceL+(uint32_t)L;
	}

	inductanceL=inductanceL/18; 
	usart1_sendStr("Value of Inductance:  ");
	usart1_sendInt((uint16_t)inductanceL); /* send the difference */
	usart1_sendStr("\n\r"); /* go to new line */		
	return inductanceL;
}
