/*
 * main.h
 *
 *  Created on: Sep 27, 2023
 *      Author: Lenovo
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <math.h>
#include "StdTypes.h"


#define HIGH 1111
#define LOW 1000

#define SET_BIT(REG, BIT_NUM)       (REG |= (1 << BIT_NUM))
#define SET_REG(REG, VALUE)         (REG |= VALUE)
#define CLR_BIT(REG, BIT_NUM)       (REG &= (~(1 << BIT_NUM)))
#define TGL_BIT(REG, BIT_NUM)       (REG ^= (1 << BIT_NUM))
#define GET_BIT(REG, BIT_NUM)       (REG & (1<< BIT_NUM))

#endif /* MAIN_H_ */




