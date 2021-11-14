###############################################################################
# Makefile for project 
###############################################################################

## General options
PROJECT = 
MCU = STM32F103C6
COMPILER = "Keil for ARM"
TARGET = Debug
SHELL = C:\WINDOWS\system32\cmd.exe

## Tools general options
ASMFLAGS=--cpu=cortex-m3 --thumb -g
CCFLAGS=--cpu=cortex-m3 --thumb -I.. -IC:/Keil_v5/ARM/CMSIS/Include -g -O0
LDFLAGS=--scatter ../stm32f103x6.sct

## Processing Tools
CC=armcc.exe
LD=armlink.exe
ASM=armasm.exe
BIN2HEX=fromelf.exe
#  H:/Fede/Facultad/2021/2do cuatrimestre/Taller de proyecto I/Prácticas/Práctica 3/Project/Firmware/STM32F103C6/Debug/Debug.elf: TOOL=LD
#     H:/Fede/Facultad/2021/2do cuatrimestre/Taller de proyecto I/Prácticas/Práctica 3/Project/Firmware/STM32F103C6/Debug/main.o: TOOL=CC
#        H:/Fede/Facultad/2021/2do cuatrimestre/Taller de proyecto I/Prácticas/Práctica 3/Project/Firmware/STM32F103C6/main.c
#     H:/Fede/Facultad/2021/2do cuatrimestre/Taller de proyecto I/Prácticas/Práctica 3/Project/Firmware/STM32F103C6/Debug/SYSTEM~1.o: TOOL=CC
#        H:/Fede/Facultad/2021/2do cuatrimestre/Taller de proyecto I/Prácticas/Práctica 3/Project/Firmware/STM32F103C6/system_stm32f1xx.c
#     H:/Fede/Facultad/2021/2do cuatrimestre/Taller de proyecto I/Prácticas/Práctica 3/Project/Firmware/STM32F103C6/Debug/STARTU~1.o: TOOL=ASM
#        H:/Fede/Facultad/2021/2do cuatrimestre/Taller de proyecto I/Prácticas/Práctica 3/Project/Firmware/STM32F103C6/startup_stm32f103.s
#     H:/Fede/Facultad/2021/2do cuatrimestre/Taller de proyecto I/Prácticas/Práctica 3/Project/Firmware/STM32F103C6/Debug/utils.o: TOOL=CC
#        H:/Fede/Facultad/2021/2do cuatrimestre/Taller de proyecto I/Prácticas/Práctica 3/Project/Firmware/STM32F103C6/utils.c
#     H:/Fede/Facultad/2021/2do cuatrimestre/Taller de proyecto I/Prácticas/Práctica 3/Project/Firmware/STM32F103C6/Debug/lcd.o: TOOL=CC
#        H:/Fede/Facultad/2021/2do cuatrimestre/Taller de proyecto I/Prácticas/Práctica 3/Project/Firmware/STM32F103C6/lcd.c
#     H:/Fede/Facultad/2021/2do cuatrimestre/Taller de proyecto I/Prácticas/Práctica 3/Project/Firmware/STM32F103C6/Debug/seos.o: TOOL=CC
#        H:/Fede/Facultad/2021/2do cuatrimestre/Taller de proyecto I/Prácticas/Práctica 3/Project/Firmware/STM32F103C6/seos.c
#     H:/Fede/Facultad/2021/2do cuatrimestre/Taller de proyecto I/Prácticas/Práctica 3/Project/Firmware/STM32F103C6/Debug/timer1.o: TOOL=CC
#        H:/Fede/Facultad/2021/2do cuatrimestre/Taller de proyecto I/Prácticas/Práctica 3/Project/Firmware/STM32F103C6/timer1.c
#     H:/Fede/Facultad/2021/2do cuatrimestre/Taller de proyecto I/Prácticas/Práctica 3/Project/Firmware/STM32F103C6/Debug/adc.o: TOOL=CC
#        H:/Fede/Facultad/2021/2do cuatrimestre/Taller de proyecto I/Prácticas/Práctica 3/Project/Firmware/STM32F103C6/adc.c
#     H:/Fede/Facultad/2021/2do cuatrimestre/Taller de proyecto I/Prácticas/Práctica 3/Project/Firmware/STM32F103C6/Debug/SYSTEM~2.o: TOOL=CC
#        H:/Fede/Facultad/2021/2do cuatrimestre/Taller de proyecto I/Prácticas/Práctica 3/Project/Firmware/STM32F103C6/system_measure.c
#     H:/Fede/Facultad/2021/2do cuatrimestre/Taller de proyecto I/Prácticas/Práctica 3/Project/Firmware/STM32F103C6/Debug/usart.o: TOOL=CC
#        H:/Fede/Facultad/2021/2do cuatrimestre/Taller de proyecto I/Prácticas/Práctica 3/Project/Firmware/STM32F103C6/usart.c

# Build tree:
all:	Debug

Debug:	Debug.elf

Debug.elf:	main.o SYSTEM~1.o STARTU~1.o utils.o lcd.o seos.o timer1.o adc.o SYSTEM~2.o usart.o 
	$(LD)  $(LDFLAGS)  "main.o" "SYSTEM~1.o" "STARTU~1.o" "utils.o" "lcd.o" "seos.o" "timer1.o" "adc.o" "SYSTEM~2.o" "usart.o" --output "Debug.elf"

main.o:	../main.c 
	$(CC) $(CCFLAGS)  "../main.c" -c -o "main.o"

SYSTEM~1.o:	../system_stm32f1xx.c 
	$(CC) $(CCFLAGS)  "../system_stm32f1xx.c" -c -o "SYSTEM~1.o"

STARTU~1.o:	../startup_stm32f103.s 
	$(ASM) $(ASMFLAGS)  "../startup_stm32f103.s" -o "STARTU~1.o"

utils.o:	../utils.c 
	$(CC) $(CCFLAGS)  "../utils.c" -c -o "utils.o"

lcd.o:	../lcd.c 
	$(CC) $(CCFLAGS)  "../lcd.c" -c -o "lcd.o"

seos.o:	../seos.c 
	$(CC) $(CCFLAGS)  "../seos.c" -c -o "seos.o"

timer1.o:	../timer1.c 
	$(CC) $(CCFLAGS)  "../timer1.c" -c -o "timer1.o"

adc.o:	../adc.c 
	$(CC) $(CCFLAGS)  "../adc.c" -c -o "adc.o"

SYSTEM~2.o:	../system_measure.c 
	$(CC) $(CCFLAGS)  "../system_measure.c" -c -o "SYSTEM~2.o"

usart.o:	../usart.c 
	$(CC) $(CCFLAGS)  "../usart.c" -c -o "usart.o"

# tidy - delete all temporary files which are not involved in the target generation
tidy:

# cleanup - delete all generated files
clean:	tidy
	rm -rf Debug.elf
	rm -rf main.o
	rm -rf SYSTEM~1.o
	rm -rf STARTU~1.o
	rm -rf utils.o
	rm -rf lcd.o
	rm -rf seos.o
	rm -rf timer1.o
	rm -rf adc.o
	rm -rf SYSTEM~2.o
	rm -rf usart.o
