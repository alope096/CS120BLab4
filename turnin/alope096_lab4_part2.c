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

enum States{Start,begin,increment,max,decrement, min, reset} state;

void Tick() {
    unsigned char button_increment = PINA & 0x01;
    unsigned char button_decrement = PINA & 0x02;
    static unsigned char cntavail;

    switch(state){
        case Start:
           state = begin;
        break;
        case begin:
           if((button_increment && !button_decrement) && (cntavail<9)){
             state = increment;
           }
           else if((!button_increment && button_decrement) && (cntavail>0)){
             state = decrement;
           }
           else if((!button_increment && !button_decrement)){
             state = reset;
           }
           else{
             state = begin;
           }
        break;

        case increment:
           if((cntavail = 9)){
             state = max;
           }
           else if((button_increment && !button_decrement) && (cntavail<9)){
             state = increment;
           }
           else if((!button_increment && button_decrement) && (cntavail>0)){
             state = decrement;
           }
           else if((button_increment && button_decrement)){
             state = reset;
           }
           else{
             state = increment;
           }
        break;

        case max:
           if((!button_increment && !button_decrement) && (cntavail>0)){
             state = decrement;
           }
           else if((button_increment && button_decrement)){
             state = reset;
           }
           else{
             state = max;
           }
        break;

        case decrement:
           if((cntavail == 0)){
             state = min;
           }
           else if((!button_increment && button_decrement) && (cntavail>0)){
             state = decrement;
           }
            else if((button_increment && !button_decrement) && (cntavail<9)){
             state = increment;
           }
           else if((button_increment && button_decrement)){
             state = reset;
           }
           else{
             state = decrement;
           }
        break;

        case min:
           if((button_increment && !button_decrement) && (cntavail<9)){
             state = increment;
           }
           else if((button_increment && button_decrement)){
             state = reset;
           }
           
           else{
             state = min;
           }
        break;

        case reset:
           if((button_increment && !button_decrement) && (cntavail<9)){
             state = increment;
           }
           else if((!button_increment && button_decrement) && (cntavail>0)){
             state = decrement;
           }
           else{
             state = reset;
           }
        break;

        default:
           state = Start;
        break;
    }
    switch(state){
        case Start:
        break;
        case begin:
           cntavail = 7;
        break;
        case increment:
           cntavail = cntavail +1;
        break;
        case decrement:
           cntavail = cntavail -1;
        break;
        case max:
        break;
        case min:
        break;
        case reset:
           cntavail =0;
        break;
        default:
        break;
    }
   PORTC = cntavail;
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
   
   
    
    state = Start;

    /* Insert your solution below */
    while (1) {
        Tick();

    }
    return 1;
}
