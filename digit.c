/*
 * digit.c
 *
 * Created: 4/4/2024 8:34:48 AM
 *  Author: dspuser
 */ 

#define F_CPU 14745600UL
#include <avr/io.h>
#include "digit.h"
#include <stdint.h>

/////////////////////////////////////////////////afisaj hexa
static const uint8_t digitmap[16] = {
	0xC0,//0
	0xF9,//1
	0xA4,//2
	0xB0,//3
	0x99,//4
	0x92,//5
	0x82,//6
	0xF8,//7
	0x80,//8
	0x90,//9
	0x88,//A
	0x83,//B
	0xC6,//C
	0xA1,//D
	0x86,//E
	0x8E//F
};

///////////////////////////////////////////////initializare afisaj
void init_digit(void){
	DDRA |= 0xFF;
}

//////////////////////////////////////////////afisare
void display_digit(uint8_t digit){
	PORTA = digitmap[digit];
}

/////////////////////////////////////////////resetare afisaj
void clear_digit(void){
	PORTA |= 0xFF;
}