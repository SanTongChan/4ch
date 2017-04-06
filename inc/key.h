/*
 * key.h
 *
 *  Created on: 2017-4-4
 *      Author: Administrator
 */

#ifndef KEY_H_
#define KEY_H_
#include "global.h"

sbit KEY1 = P1^0;
sbit KEY2 = P0^3;
sbit KEY3 = P0^2;
sbit KEY4 = P1^5;

void keyInit(void);

#endif /* KEY_H_ */
