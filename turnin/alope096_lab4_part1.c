/*	Author: lab
 *  Partner(s) Name: none
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States{Start,buttonUnpressed,buttonPressed,ButtonReleased} state;

void Tick() {
    unsigned char button = PINA & 0x01;
    unsigned char led;
    switch(state){
        case Start:
           state = buttonUnpressed;
        break;
        case buttonUnpressed:
           state = button?buttonPressed:buttonUnpressed;
        break;
        case buttonPressed:
           state = button?buttonPressed:ButtonReleased;
        break;
        case ButtonReleased:
           state = button?buttonUnpressed:ButtonReleased;
        break;
        default:
           state = Start;
        break;
    }
    switch(state){
        case Start:
        break;
        case buttonUnpressed:
           led = 0x01;
        break;
        case buttonPressed:
           led = 0x02;
        break;
        case ButtonReleased:
        break;
        default:
        break;
    }
   PORTB = led;
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
   
   
    
    state = Start;

    /* Insert your solution below */
    while (1) {
        Tick();

    }
    return 1;
}
