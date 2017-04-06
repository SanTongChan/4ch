/*
 * key_driver.h
 *
 *  Created on: 2017-4-4
 *      Author: Administrator
 */

#include  "stdbool.h"

#ifndef KEY_DRIVER_H_
#define KEY_DRIVER_H_

#define  KEY_MAX_NUM      (5)
#define  KEY_SCAN_TIMES  (2)
#define  KEY_UP_TIMES     (2)
#define  KEY_LONG_TIMES   (500)
#define  KEY_TWICE_TIMES  (30)

typedef void (*KeyPressProcCb)(void);
typedef bool (*KeyIsPressCb)(void);

bool keyRegisterSingle(KeyIsPressCb _key_is_press,
                            KeyPressProcCb _key_short_press_proc_cb,
                            KeyPressProcCb _key_short_up_press_proc_cb,
                            KeyPressProcCb _key_long_press_proc_cb,
                            KeyPressProcCb _key_long_up_press_proc_cb,
                            KeyPressProcCb _key_press_twice_proc_cb);


void keyScan(void);

#endif /* KEY_DRIVER_H_ */
