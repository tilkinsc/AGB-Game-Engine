/*
 * interrupt.c
 *
 *  Created on: Oct 20, 2016
 *      Author: Cody
 */

#include "interrupt.h"

void interrupt_ignore() {}

const intrp IntrTable[13] = {
    interrupt_ignore,   /* V Blank interrupt */
    interrupt_ignore,   /* H Blank interrupt */
    interrupt_ignore,   /* V Counter interrupt */
    interrupt_ignore,   /* Timer 0 interrupt */
    interrupt_ignore,   /* Timer 1 interrupt */
    interrupt_ignore,   /* Timer 2 interrupt */
    interrupt_ignore,   /* Timer 3 interrupt */
    interrupt_ignore,   /* Serial communication interrupt */
    interrupt_ignore,   /* DMA 0 interrupt */
    interrupt_ignore,   /* DMA 1 interrupt */
    interrupt_ignore,   /* DMA 2 interrupt */
    interrupt_ignore,   /* DMA 3 interrupt */
    interrupt_ignore,   /* Key interrupt */
};
