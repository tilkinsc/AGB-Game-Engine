/*
 * interrupt.h
 *
 *  Created on: Oct 20, 2016
 *      Author: Cody
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

typedef void (*intrp)();

const intrp IntrTable[13];

void interrupt_ignore();

#endif /* INTERRUPT_H_ */
