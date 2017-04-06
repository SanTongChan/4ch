/*
 * logic.c
 *
 *  Created on: 2017-4-4
 *      Author: Administrator
 */

#include "logic.h"
#include "key.h"
#include "led.h"
#include "stdio.h"
#include "wireless.h"
DeviceDef device_def = {0};
//uint8_t work_mode_params = 0;
uint16_t time_level = 50;
uint32_t ad_val = 0 ;
uint16_t code table[20] = {3100,2700,2300,1900,1500,1200,900,600,300,0,350,300,250,200,150,130,110,90,70,50};

sbit RELAY1 = P1^4;
sbit RELAY2 = P1^3;
sbit RELAY3 = P0^7;
sbit RELAY4 = P1^1;

static void deviceStatusInit(void)
{
	loadParamtoFlash();
	getParams13();
}
void deviceInit(void)
{
	deviceStatusInit();
	keyInit();
	ledsOff();
}

void adScan(void)
{
	static uint32_t accumulator = 0;
	static uint16_t measure_cnt = 2048;
	static bool switch_ad_flag = false;
	uint32_t result = 0;
	uint8_t i = 0;
	ADC0CN0_ADINT = 0;
	accumulator += ADC0;
	measure_cnt--;
	if(measure_cnt == 0 && switch_ad_flag == false)
	{
		measure_cnt = 50;
		result = accumulator / 2048;
		accumulator = 0;
		result =  (result * 3300) / 1023;
		switch_ad_flag = true;
		ADC0MX = ADC0MX_ADC0MX__ADC0P6;
		for(i = 0; i < 10; i++)
		{
			if(result >= table[i])
			{
				time_level = table[i + 10];
				break;
			}
		}
	}
	else if(measure_cnt == 0 && switch_ad_flag == true)
	{
		measure_cnt = 50;
		result = accumulator / 50;
		accumulator = 0;
		ad_val =  (result * 3300) / 1023;
	}
}

void setKeyPin(uint8_t index,bool level)
{
	if(0 == index)
	{
		KEY1 = level;
	}
	else if(1 == index)
	{
		KEY2 = level;
	}
	else if(2 == index)
	{
		KEY3 = level;
	}
	else if(3 == index)
	{
		KEY4 = level;
	}
}
static uint8_t getReadRelayStatus(uint8_t index)
{
	if(index == 0)
	{
		return RELAY1;
	}
	else if(index == 1)
	{
		return RELAY2;
	}
	else if(index == 2)
	{
		return RELAY3;
	}
	else
	{
		return RELAY4;
	}
}
static void dealJogging(void)
{
    uint8_t i = 0;
    for(i = 0; i < 4; i++)
    {
        device_def.device_channel_def[i].time_cnt++;
        if(device_def.device_channel_def[i].device_channel_mode == DEVICE_CHANNEL_JOGGING)
        {
            if(getReadRelayStatus(i) == 1 && device_def.device_channel_def[i].jogging_flag == false)
            {
                device_def.device_channel_def[i].time_cnt = 0;
                device_def.device_channel_def[i].jogging_flag = true;
            }
            else if(device_def.device_channel_def[i].jogging_flag == true
                && device_def.device_channel_def[i].time_cnt == time_level - 5
                && getReadRelayStatus(i) == 1)
            {
                setKeyPin(i,false);
            }
            else if(device_def.device_channel_def[i].jogging_flag == true
                && device_def.device_channel_def[i].time_cnt == time_level
                && getReadRelayStatus(i) == 1)
            {
            	setKeyPin(i,true);
                device_def.device_channel_def[i].jogging_flag = false;
            }
            else if(getReadRelayStatus(i) == 0 && device_def.device_channel_def[i].jogging_flag == true)
            {
                device_def.device_channel_def[i].jogging_flag = false;
            }
        }
    }
}
static void setChannelStatusInLock(uint8_t index,uint8_t lock_channel)
{
    if(getReadRelayStatus(index) == 1 && lock_channel != (index + 1) && device_def.device_channel_def[index].time_cnt <=5)
    {
        setKeyPin(index,false);
    }
    else if(getReadRelayStatus(index) == 1 && lock_channel != (index + 1) && device_def.device_channel_def[index].time_cnt > 5)
    {
    	setKeyPin(index,true);
        device_def.device_channel_def[index].time_cnt = 0;
    }
}
static void dealLock(void)
{
    static uint8_t lock_channel = 0;
    static uint8_t last_lock_channel = 0;
    static uint8_t xdata last_relay_val[4] = {0};
    uint8_t xdata relay_val[4] = {0};
    uint8_t i = 0;
    relay_val[0] = RELAY1;
    relay_val[1] = RELAY2;
    relay_val[2] = RELAY3;
    relay_val[3] = RELAY4;
    for(i = 0; i < 4; i++)
    {
        if(relay_val[i] != last_relay_val[i] && relay_val[i] == 1)
        {
            lock_channel = i + 1;

        }
        last_relay_val[i] = relay_val[i];
        device_def.device_channel_def[i].time_cnt++;
    }

    if(last_lock_channel != lock_channel)
    {
        for(i = 0; i < 4; i++)
        {
            device_def.device_channel_def[i].time_cnt = 0;
        }
        last_lock_channel = lock_channel;
    }
    for(i = 0; i < 4; i++)
    {
        setChannelStatusInLock(i,lock_channel);
    }
}
void dealNormalMode(void)
{
	if(device_def.device_normal_state == DEVICE_LOCK)
	{
		dealLock();
	}
	else
	{
		dealJogging();
	}
}
