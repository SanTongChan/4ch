/*
 * key.c
 *
 *  Created on: 2017-4-4
 *      Author: Administrator
 *      3296  825  1029    1238   1441   1648
 */
#include "key.h"
#include "driver/key_driver.h"
#include "logic.h"
#include "led.h"
#include "wireless.h"

static bool key5_is_press(void)
{
    if(ad_val >= 750 && ad_val <= 900)
    {
        return true;
    }
    return false;
}
static bool key4_is_press(void)
{
	if(ad_val >= 950 && ad_val <= 1100)
	{
		return true;
	}
	return false;
}
static bool key3_is_press(void)
{
	if(ad_val >= 1150 && ad_val <= 1300)
	{
		return true;
	}
	return false;
}
static bool key2_is_press(void)
{
	if(ad_val >= 1350 && ad_val <= 1500)
	{
		return true;
	}
	return false;
}
static bool key1_is_press(void)
{
	if(ad_val >= 1550 && ad_val <= 1700)
	{
		return true;
	}
	return false;
}
/*单击不抬键已经校验过*/
static void key1_short_press(void)
{
    if(DEVICE_433 == device_def.device_work_mode)
    {
    	ledChannel1On();
        return;
    }
    KEY1 = 0;
}
static void key2_short_press(void)
{
	if(DEVICE_433 == device_def.device_work_mode)
	{
		ledChannel2On();
		return;
	}
    KEY2 = 0;
}
static void key3_short_press(void)
{
	if(DEVICE_433 == device_def.device_work_mode)
	{
		ledChannel3On();
		return;
	}
    KEY3 = 0;
}
static void key4_short_press(void)
{
	if(DEVICE_433 == device_def.device_work_mode)
	{
		ledChannel4On();
		return;
	}
    KEY4 = 0;
}
/*双击搞定*/
static void key1_twice_press(void)
{
	if(DEVICE_NORMAL == device_def.device_work_mode && DEVICE_NOLOCK == device_def.device_normal_state)
	{
		if(device_def.device_channel_def[0].device_channel_mode == DEVICE_CHANNEL_SELFLOCK)
		{
			device_def.device_channel_def[0].device_channel_mode = DEVICE_CHANNEL_JOGGING;
			ledChannel1On();
		}
		else if(device_def.device_channel_def[0].device_channel_mode == DEVICE_CHANNEL_JOGGING)
		{
			device_def.device_channel_def[0].device_channel_mode = DEVICE_CHANNEL_SELFLOCK;
			ledChannel1Off();
		}
		setParams13(0);
		savaParamtoFlash();
	}
}
static void key2_twice_press(void)
{
	if(DEVICE_NORMAL == device_def.device_work_mode && DEVICE_NOLOCK == device_def.device_normal_state)
	{
		if(device_def.device_channel_def[1].device_channel_mode == DEVICE_CHANNEL_SELFLOCK)
		{
			device_def.device_channel_def[1].device_channel_mode = DEVICE_CHANNEL_JOGGING;
			ledChannel2On();
		}
		else if(device_def.device_channel_def[1].device_channel_mode == DEVICE_CHANNEL_JOGGING)
		{
			device_def.device_channel_def[1].device_channel_mode = DEVICE_CHANNEL_SELFLOCK;
			ledChannel2Off();
		}
		setParams13(1);
		savaParamtoFlash();
	}
}
static void key3_twice_press(void)
{
	if(DEVICE_NORMAL == device_def.device_work_mode && DEVICE_NOLOCK == device_def.device_normal_state)
	{
		if(device_def.device_channel_def[2].device_channel_mode == DEVICE_CHANNEL_SELFLOCK)
		{
			device_def.device_channel_def[2].device_channel_mode = DEVICE_CHANNEL_JOGGING;
			ledChannel3On();
		}
		else if(device_def.device_channel_def[2].device_channel_mode == DEVICE_CHANNEL_JOGGING)
		{
			device_def.device_channel_def[2].device_channel_mode = DEVICE_CHANNEL_SELFLOCK;
			ledChannel3Off();
		}
		setParams13(2);
		savaParamtoFlash();
	}
}
static void key4_twice_press(void)
{
	if(DEVICE_NORMAL == device_def.device_work_mode && DEVICE_NOLOCK == device_def.device_normal_state)
	{
		if(device_def.device_channel_def[3].device_channel_mode == DEVICE_CHANNEL_SELFLOCK)
		{
			device_def.device_channel_def[3].device_channel_mode = DEVICE_CHANNEL_JOGGING;
			ledChannel4On();
		}
		else if(device_def.device_channel_def[3].device_channel_mode == DEVICE_CHANNEL_JOGGING)
		{
			device_def.device_channel_def[3].device_channel_mode = DEVICE_CHANNEL_SELFLOCK;
			ledChannel4Off();
		}
		setParams13(3);
		savaParamtoFlash();
	}
}
static void key5_twice_press(void)
{
	if(device_def.device_work_mode == DEVICE_NORMAL)
	{
		if(device_def.device_normal_state == DEVICE_NOLOCK)
		{
			device_def.device_normal_state = DEVICE_LOCK;
			ledModeOn();
		}
		else if(device_def.device_normal_state == DEVICE_LOCK)
		{
			device_def.device_normal_state = DEVICE_NOLOCK;
			device_def.device_channel_def[0].device_channel_mode = DEVICE_CHANNEL_SELFLOCK;
			device_def.device_channel_def[1].device_channel_mode = DEVICE_CHANNEL_SELFLOCK;
			device_def.device_channel_def[2].device_channel_mode = DEVICE_CHANNEL_SELFLOCK;
			device_def.device_channel_def[3].device_channel_mode = DEVICE_CHANNEL_SELFLOCK;
			ledModeOff();
		}
		setParams13(0);
		setParams13(1);
		setParams13(2);
		setParams13(3);
		setParams13(4);
		savaParamtoFlash();
		ledSetChannelsValue(0xff);
	}
}
static void key1_short_up_press(void)
{
    KEY1 = 1;
    if(device_def.device_work_mode == DEVICE_SETTING)
    {
    	device_def.device_work_mode = DEVICE_NORMAL;
    }
    else if(device_def.device_work_mode == DEVICE_433)
	{
		device_def.device_channel_def[0].device_status = DEVICE_STATUS_STUDY;
		device_def.device_channel_def[1].device_status = DEVICE_STATUS_IDLE;
		device_def.device_channel_def[2].device_status = DEVICE_STATUS_IDLE;
		device_def.device_channel_def[3].device_status = DEVICE_STATUS_IDLE;
		ledChannel1Off();
	}
}
static void key2_short_up_press(void)
{
	KEY2 = 1;
	if(device_def.device_work_mode == DEVICE_SETTING)
	{
		device_def.device_work_mode = DEVICE_NORMAL;
	}
	else if(device_def.device_work_mode == DEVICE_433)
	{
		device_def.device_channel_def[0].device_status = DEVICE_STATUS_IDLE;
		device_def.device_channel_def[1].device_status = DEVICE_STATUS_STUDY;
		device_def.device_channel_def[2].device_status = DEVICE_STATUS_IDLE;
		device_def.device_channel_def[3].device_status = DEVICE_STATUS_IDLE;
		ledChannel2Off();
	}
}
static void key3_short_up_press(void)
{
    KEY3 = 1;
    if(device_def.device_work_mode == DEVICE_SETTING)
	{
		device_def.device_work_mode = DEVICE_NORMAL;
	}
	else if(device_def.device_work_mode == DEVICE_433)
	{
		device_def.device_channel_def[0].device_status = DEVICE_STATUS_IDLE;
		device_def.device_channel_def[1].device_status = DEVICE_STATUS_IDLE;
		device_def.device_channel_def[2].device_status = DEVICE_STATUS_STUDY;
		device_def.device_channel_def[3].device_status = DEVICE_STATUS_IDLE;
		ledChannel3Off();
	}
}
static void key4_short_up_press(void)
{
    KEY4 = 1;
    if(device_def.device_work_mode == DEVICE_SETTING)
	{
		device_def.device_work_mode = DEVICE_NORMAL;
	}
	else if(device_def.device_work_mode == DEVICE_433)
	{
		device_def.device_channel_def[0].device_status = DEVICE_STATUS_IDLE;
		device_def.device_channel_def[1].device_status = DEVICE_STATUS_IDLE;
		device_def.device_channel_def[2].device_status = DEVICE_STATUS_IDLE;
		device_def.device_channel_def[3].device_status = DEVICE_STATUS_STUDY;
		ledChannel4Off();
	}
}
static void key5_short_up_press(void)
{
	uint8_t temp = 0;
	if(device_def.device_work_mode == DEVICE_433)
	{
		device_def.device_work_mode =  DEVICE_NORMAL;
		wirelessLedOff();
		if(device_def.device_normal_state == DEVICE_LOCK)
		{
			ledModeOn();
		}
		else
		{
			ledModeOff();
			temp = device_def.device_channel_def[3].device_channel_mode << 3
					| device_def.device_channel_def[2].device_channel_mode << 2
					| device_def.device_channel_def[1].device_channel_mode << 1
					| device_def.device_channel_def[0].device_channel_mode << 0;
			ledSetChannelsValue(~temp);
		}
	}
}
static void key1_long_press(void)
{
    if(device_def.device_work_mode == DEVICE_NORMAL)
    {
    	device_def.device_work_mode = DEVICE_SETTING;
    }
    else if(device_def.device_work_mode == DEVICE_433)
    {
    	//清空flash
    	device_def.device_channel_def[0].device_status = DEVICE_STATUS_IDLE;
    	ledChannel1Off();
    }
 }
static void key2_long_press(void)
{
	if(device_def.device_work_mode != DEVICE_SETTING
	    		&& device_def.device_work_mode != DEVICE_433)
	{
		device_def.device_work_mode = DEVICE_SETTING;
	}
	else if(device_def.device_work_mode == DEVICE_433)
	{
		//清空键值
		device_def.device_channel_def[1].device_status = DEVICE_STATUS_IDLE;
		ledChannel2Off();
	}
}
static void key3_long_press(void)
{
	if(device_def.device_work_mode != DEVICE_SETTING
	    		&& device_def.device_work_mode != DEVICE_433)
	{
		device_def.device_work_mode = DEVICE_SETTING;
	}
	else if(device_def.device_work_mode == DEVICE_433)
	{
		//清空键值
		device_def.device_channel_def[2].device_status = DEVICE_STATUS_IDLE;
		ledChannel3Off();
	}
}
static void key4_long_press(void)
{
	if(device_def.device_work_mode != DEVICE_SETTING
	    		&& device_def.device_work_mode != DEVICE_433)
	{
		device_def.device_work_mode = DEVICE_SETTING;
	}
	else if(device_def.device_work_mode == DEVICE_433)
	{
		//清空键值
		device_def.device_channel_def[3].device_status = DEVICE_STATUS_IDLE;
		ledChannel4Off();
	}
}
static void key5_long_press(void)
{
	uint8_t temp = 0;
    if(device_def.device_work_mode == DEVICE_NORMAL)
    {
    	device_def.device_work_mode = DEVICE_433;
    	device_def.device_channel_def[0].device_status = DEVICE_STATUS_IDLE;
    	device_def.device_channel_def[1].device_status = DEVICE_STATUS_IDLE;
    	device_def.device_channel_def[2].device_status = DEVICE_STATUS_IDLE;
    	device_def.device_channel_def[3].device_status = DEVICE_STATUS_IDLE;
    	ledSetChannelsValue(0xff);
    	ledModeOff();
     	ledChannel1Off();
    	wirelessLedOn();
    }
    else if(device_def.device_work_mode == DEVICE_433)
	{
		device_def.device_work_mode =  DEVICE_NORMAL;
		wirelessLedOff();
		if(device_def.device_normal_state == DEVICE_LOCK)
		{
			ledModeOn();
		}
		else
		{
			ledModeOff();
			temp = device_def.device_channel_def[3].device_channel_mode << 3
					| device_def.device_channel_def[2].device_channel_mode << 2
					| device_def.device_channel_def[1].device_channel_mode << 1
					| device_def.device_channel_def[0].device_channel_mode << 0;
			ledSetChannelsValue(~temp);
		}
	}
}

static void key1_long_up_press(void)
{
    KEY1 = 1;
}
static void key2_long_up_press(void)
{
	KEY2 = 1;
}
static void key3_long_up_press(void)
{
	KEY3 = 1;
}
static void key4_long_up_press(void)
{
	KEY4 = 1;
}
static void registerKeys(void)
{
    keyRegisterSingle(key1_is_press,key1_short_press,key1_short_up_press,
                        key1_long_press,key1_long_up_press,key1_twice_press);
    keyRegisterSingle(key2_is_press,key2_short_press,key2_short_up_press,
                        key2_long_press,key2_long_up_press,key2_twice_press);
    keyRegisterSingle(key3_is_press,key3_short_press,key3_short_up_press,
                        key3_long_press,key3_long_up_press,key3_twice_press);
    keyRegisterSingle(key4_is_press,key4_short_press,key4_short_up_press,
                        key4_long_press,key4_long_up_press,key4_twice_press);
    keyRegisterSingle(key5_is_press,NULL,key5_short_up_press,
                        key5_long_press,NULL,key5_twice_press);
}
void keyInit(void)
{
	registerKeys();
}

