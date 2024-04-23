/*
 * UART.c
 *
 * Created: 4/18/2024 8:04:27 AM
 * Author : dspuser
 */ 

#include <avr/io.h>
#define F_CPU 14745600UL
#include <avr/io.h>
#include <util/delay.h>
#include "digit.h"
#include "timer.h" 
#include "uart.h"

int main(void)
{
    /* Replace with your application code */
	uart_init();
	//char c='a';
	char *st="Ana ";
    while (1){
		//send_ch(c);
		send_str(st);
		_delay_ms(100);
	}
}

