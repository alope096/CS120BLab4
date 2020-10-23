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
    switch(state){
        case Start:
           state =
        break;
        case buttonUnpressed:
           state =
        break;
        case buttonPressed:
           state =
        break;
        case ButtonReleased:
           state =
        break;
        default:
        break;
    }
    switch(state){
        case Start:
        break;
        case buttonUnpressed:
           state =
        break;
        case buttonPressed:
           state =
        break;
        case ButtonReleased:
           state =
        break;
        default:
        break;
    }
}

int main(void) {
    /* Insert DDR and PORT initializations */

    /* Insert your solution below */
    while (1) {

    }
    return 1;
}
