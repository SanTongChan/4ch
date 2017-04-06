/*
 * led.h
 *
 *  Created on: 2017-4-4
 *      Author: Administrator
 */

#ifndef  _LED_H_
#define  _LED_H_

#include "global.h"

sbit SER = P2^0;
sbit SCK = P0^1;
sbit RCK = P0^0;

#define  LEDS_OFF       (0X3F)
#define  LEDS_ON        (0X00)
#define  LED_CHANNEL1   (0Xfe)
#define  LED_CHANNEL2   (0Xfd)
#define  LED_CHANNEL3   (0Xfb)
#define  LED_CHANNEL4   (0Xf7)
#define  LED_MODE       (0Xef)
#define  LED_WIRELESS   (0Xdf)
#define  LED_CHANNELS_OFF (0x1f)

void SendTo595(void);
void wirelessLedOn(void);
void wirelessLedOff(void);
void wirelessOn500msOff500ms(uint8_t key_val);
void wirelessOn50msOff50ms(uint8_t key_val);
//void wirelessOn200msOff200ms(uint8_t key_val);
void wirelessScan(void);
void ledChannel1On(void);
void ledChannel1Off(void);
void ledChannel2On(void);
void ledChannel2Off(void);
void ledChannel3On(void);
void ledChannel3Off(void);
void ledChannel4On(void);
void ledChannel4Off(void);
void ledModeOn(void);
void ledModeOff(void);
void ledsOff(void);
void ledsOn(void);
void ledSetChannelsValue(uint8_t val);
#endif /* _LED_H_ */
