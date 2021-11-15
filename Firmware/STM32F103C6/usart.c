#include <usart.h>

void usart1_init(){
	GPIOA->ODR|=(1<<10); //pull-up PA10
	GPIOA->CRH =0x444448B4; //RX1=input with pull-up (PA10), TX1 = alt func output 50MHz (PA9)
	USART1->CR1=0x2004; // 0010 0000 0000 0100 -> Enable USART, 8N1, Receiver enable
	USART1->BRR=7500; //72MHz/9600bps=7500; for some reason USART1
}												//doesn't use 36MHz clock by default and uses the 72MHz

void usart1_sendByte(unsigned char c){
	while((USART1->SR&(1<<6))==0); //wait until the TC flag is set
	USART1->DR=c;
}
void usart1_sendStr(char* str){
	while(*str!=0){ //while char act is not '\0'
		usart1_sendByte(*str); //print it
		str++; //go to next char
	}
}

void usart1_sendInt(unsigned int i){
	char str[10]; //local variable to store string
	sprintf(str,"%d",i); //transform i to a string and store it in str
	usart1_sendStr(str); //print it in the USART1 str
}
