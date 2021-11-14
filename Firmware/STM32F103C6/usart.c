#include <usart.h>

void usart1_init(){
	GPIOA->ODR|=(1<<10); //pull-up PA10
	GPIOA->CRH =0x444448B4; //RX1=input with pull-up (PA10), TX1 = alt func output 50MHz (PA9)
	USART1->CR1=0x2024; //
	USART1->BRR=7500; //72MHz/960bps=7500;
}

void usart1_sendByte(unsigned char c){
	while((USART1->SR&(1<<6))==0); //wait until the TC flag is set
	USART1->DR=c;
}
void usart1_sendStr(char* str){
	while(*str!=0){
		usart1_sendByte(*str);
		str++;
	}
}

void usart1_sendInt(unsigned int i){
	char str[10];
	sprintf(str,"%d",i);
	usart1_sendStr(str);
}
