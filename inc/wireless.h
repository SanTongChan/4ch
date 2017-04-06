/*
 * wireless.h
 *
 *  Created on: 2017-4-5
 *      Author: Administrator
 */

#ifndef WIRELESS_H_
#define WIRELESS_H_

#include "global.h"

void decode(void);
void wireless_scan(void);
void savaParamtoFlash(void);
void loadParamtoFlash(void);
void setParams13(uint8_t index);
void getParams13(void);
#endif /* WIRELESS_H_ */
