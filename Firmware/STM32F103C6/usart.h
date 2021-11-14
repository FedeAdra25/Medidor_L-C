
#ifndef  USART_H
#define USART_H


#include <stm32f103x6.h>
#include <stdint.h>
#include <stdio.h>
#include <utils.h>

void usart1_init(void);
void usart1_sendByte(unsigned char c);
void usart1_sendStr(char* str);
void usart1_sendInt(unsigned int i);

#endif

