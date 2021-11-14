#ifndef LCD_H
#define LCD_H

#include <stm32f103x6.h>
#include <utils.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LCD_CLR 0	//DB0: clear display

//PARA CAMBIAR EL PUERTO CAMBIAR GPIOx DONDE x CORRESPONDE AL PUERTO
#define LCD_PORT 		GPIOB->CRH
#define LCD_PIN_IN 		GPIOB->IDR			//Input Data Register
#define LCD_PIN_OUT 	GPIOB->ODR			//Output Data Register

//Since BRR and BSRR are opposite of each other, 
//you can use both if you don't want to do the bit shift left operation
#define LCD_PORT_BSRR	GPIOB->BSRR
#define LCD_PORT_BRR	GPIOB->BRR 

#define LCD_RS 10
#define LCD_RW 12
#define LCD_EN 11

// cursor position to DDRAM mapping
#define LCD_LINE0_DDRAMADDR 0x00
#define LCD_LINE1_DDRAMADDR 0x40
#define LCD_LINE2_DDRAMADDR 0x14
#define LCD_LINE3_DDRAMADDR 0x54
#define LCD_DDRAM 7	//DB7: set DD RAM address -> 1<<LCD_DDRAM => 0x80


/*CABECERAS*/
uint8_t string_len(char* data);
void LCDinit(void);			//Initializes LCD
void LCDsendChar(uint8_t);		//forms data ready to send to 74HC164
void LCDsendCommand(uint8_t);	//forms data ready to send to 74HC164
//void lcd_putValue (uint8_t value); la moví porque es privada
void LCDstring(uint8_t*, uint8_t);	//Outputs string to LCD
void LCDSendInt(unsigned int i); //Outputs int as string to LCD

//TODO - Son necesarias para la MEF
void LCDGotoXY(uint8_t, uint8_t);	//Cursor to X Y position
void LCDclr(void);				//Clears LCD
void LCDcursorOFF(void);		//Cursor OFF

/*
//En un futuro owo
void LCDhome(void);			//LCD cursor home
void LCDescribeDato(int val,unsigned int field_length); // Agrego Funcion para escribir Enteros
void CopyStringtoLCD(const uint8_t*, uint8_t, uint8_t);//copies flash string to LCD at x,y
void LCDdefinechar(const uint8_t *,uint8_t);//write char to LCD CGRAM 
void LCDshiftRight(uint8_t);	//shift by n characters Right
void LCDshiftLeft(uint8_t);	//shift by n characters Left
void LCDcursorOn(void);		//Underline cursor ON
void LCDcursorOnBlink(void);	//Underline blinking cursor ON
void LCDblank(void);			//LCD blank but not cleared
void LCDvisible(void);			//LCD visible
void LCDcursorLeft(uint8_t);	//Shift cursor left by n
void LCDcursorRight(uint8_t);	//shif cursor right by n
*/

#endif

