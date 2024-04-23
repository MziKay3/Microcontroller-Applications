/*
 * uart.c
 *
 * Created: 4/18/2024 8:06:31 AM
 *  Author: dspuser
 */ 
#define F_CPU 14745600UL
#include <avr/io.h>
#include "uart.h"

void uart_init(void){

	//set RXD(PD0) input and set TXD(PD1) output
	DDRD &= ~(1<<0);
	DDRD |=(1<<1);
/*
	enable transmition and reception
	set data size for communication
	set baud rate speed
	set the baud rate
	set URSEL to 1 to gain access
	initialize stop and parity with 0
*/
	UBRRL = 0x5F;
	UBRRH = 0;

	UCSRB = 0x18;
	UCSRC = 0x86;
	
	
	
}

void send_ch(char c){
	while(!(UCSRA & (1<<5)));
	UDR = c;
}

void send_str(char *str){
	char i=0;
	while(str[i]!='\0'){
		send_ch(str[i]);
		i++;
	}
}