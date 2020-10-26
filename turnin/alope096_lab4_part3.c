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

enum States{Start,locked,buttonHpressed,buttonHreleased,buttonYpress,buttonYrelease, insideButton}state;

void Tick() {
    unsigned char button_Y = PINA & 0x02;
    unsigned char button_H = PINA & 0x04;
    unsigned char button_PA7 = PINA & 0x80;
    unsigned char lockedUnlocked;

    switch(state){
        case Start:
           state = locked;
        break;

        case locked:
           state = button_H? buttonHpressed: locked;
        break;

        case buttonHpressed:
            if(!button_H){
                state = buttonHreleased;
            }
            else if(button_Y){
                state = buttonYpress;
            }
            else if(button_PA7){
                state = insideButton;
            }
            else{
                state = buttonHpressed;
            }
        break;

        case buttonHreleased:
            if(button_H){
                state = buttonHpressed;
            }
            else if(button_Y){
                state = buttonYpress;
            }
            else if(button_PA7){
                state = insideButton;
            }
            else{
                state = buttonHreleased;
            }
        break;

        case buttonYpress:
            if(!button_Y){
                state = buttonYrelease;
            }
            else if(button_H){
                state = buttonHpressed;
            }
            else if(button_PA7){
                state = insideButton;
            }
            else{
                state = buttonYpress;
            }
        break;

        case buttonYrelease:
           if(button_Y){
                state = buttonYpress;
            }
            else if(button_H){
                state = buttonHpressed;
            }
            else if(button_PA7){
                state = insideButton;
            }
            else{
                state = buttonYrelease;
            }

        break;

        case insideButton:
           state = locked;
          
        break;

        default:
           state = Start;
        break;
    }
    switch(state){
        case Start:
        break;
        case locked:
        break;
        case buttonHpressed:
        break;
        case buttonHreleased:
        break;
        case buttonYpress:
        break;
        case buttonYrelease:
           lockedUnlocked = Start;
        break;
        case insideButton:
           lockedUnlocked = Start;
        break;
        default:
        break;
    }
   PORTB = lockedUnlocked;
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
