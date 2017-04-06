/*
 * logic.h
 *
 *  Created on: 2017-4-4
 *      Author: Administrator
 */

#ifndef LOGIC_H_
#define LOGIC_H_
#include "stdbool.h"
#include "stdint.h"

#if 1
typedef enum
{
    DEVICE_NORMAL = 0,
    DEVICE_433 = 1,
    DEVICE_SETTING = 2,
}DeviceWorkMode;
typedef enum
{
    DEVICE_CHANNEL_SELFLOCK = 0,
    DEVICE_CHANNEL_JOGGING = 1,
}DeviceChannelMode;
typedef enum
{
	DEVICE_NOLOCK = 0,
	DEVICE_LOCK = 1,
}DeviceNormalState;
typedef enum
{
    DEVICE_STATUS_STUDY = 1,
    DEVICE_STATUS_CLEAR  = 2,
    DEVICE_STATUS_IDLE = 3,
}DeviceWorkStatus;

typedef enum
{
    DEVICE_LOCK_CHENNEL1 = 0,
    DEVICE_LOCK_CHENNEL2 = 1,
    DEVICE_LOCK_CHENNEL3 = 2,
    DEVICE_LOCK_CHENNEL4 = 3,
}DeviceChannel;
typedef struct
{
    DeviceChannelMode device_channel_mode;
    DeviceWorkStatus device_status;
    uint8_t jogging_flag;
    uint16_t time_cnt;
    uint16_t wireless_flag;
    uint8_t wireless_study_flag;
    uint32_t wireless_lastval;
}DeviceChannelDef;

typedef struct
{
    DeviceChannelDef device_channel_def[4];
    DeviceWorkMode device_work_mode;
    DeviceNormalState device_normal_state;
}DeviceDef;
extern DeviceDef device_def;
#endif

void deviceInit(void);
void adScan(void);
//void saveWorkParams(void);
//void loadWorkParams(void);
void setKeyPin(uint8_t index,bool level);
void dealNormalMode(void);
#endif /* LOGIC_H_ */
