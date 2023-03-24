 /******************************************************************************
 *
 * Module: TIMER0
 *
 * File Name: timer0.c
 *
 * Description: source file for the timer0 driver
 *
 * Author: Hesham Shehata
 *
 *******************************************************************************/
 
 #include "../PWM/timer0.h"

#include <avr/io.h>
 
 void PWM_Timer0_Start(uint8_t duty_cycle)
 {
	
	TCNT0 = 0; // Set Timer Initial Value to 0
	
	OCR0  = (uint8_t)(((uint16_t)(duty_cycle*256))/100); // Set Compare Value
	
	DDRB  = DDRB | (1<<PB3); // Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC
	 /* Configure timer control register 
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */ 
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
	 
 }
