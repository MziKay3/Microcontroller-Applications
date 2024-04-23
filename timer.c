/*
 * timer.c
 *
 * Created: 3/21/2024 9:25:58 AM
 *  Author: dspuser
 */
#define F_CPU 14745600UL
#include <avr/io.h>
#include <util/delay.h>
#include "timer.h" 
#include <avr/interrupt.h>
#include "digit.h"

void timer_init(){
	sei();
	//int N=0x5A00;
	
	int N=0x7080;
	TCCR1A=0;
	TCCR1B=(1<<2)|(1<<3);
	//TCCR1B=(1<<2)|(0<<1)|(0<<0);
	OCR1AH=(N>>8) & 0xFF;
	OCR1AL=N & 0xFF;
	TIMSK=(1<<4);
};

void led_tg(){
	static int led_state=0;
	if(led_state==0){	
		PORTB |= 1;
		led_state = 1;
	}else{
		PORTB &= ~1;
		led_state = 0;
	}
}

ISR(TIMER1_COMPA_vect){
	static int count=0;
	display_digit(count);//////////////ne folosim de intrerupere pentru a afisa
	count++;
	if(count==16)
	{
		count=0;
		//led_tg();
	}
}
