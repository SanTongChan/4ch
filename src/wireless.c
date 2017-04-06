/*
 * wireless.c
 *
 *  Created on: 2017-4-5
 *      Author: Administrator
 */
#include "wireless.h"
#include "led.h"
#include "logic.h"
#include "EFM8BB1_FlashPrimitives.h"
sbit WIRELESS_PIN = P1^2;
static uint8_t xdata decode_data[3] = {0};
static uint8_t xdata dev_params[13] = {0};
static bool wireless_flag = false;

#if 1
void savaParamtoFlash(void)
{
	uint8_t i = 0;
	FLASH_PageErase(FLASH_LAST);
	for(i = 0; i < 13; i++)
	{
		FLASH_ByteWrite(FLASH_LAST+i,dev_params[i]);
	}
	//FLASH_ByteWrite(FLASH_LAST + 12,work_mode_params);
}
void loadParamtoFlash(void)
{
	uint8_t i = 0;
	for(i = 0; i < 13; i++)
	{
		dev_params[i] = FLASH_ByteRead(FLASH_LAST+i);
		if(dev_params[i] == 0xff)
		{
			dev_params[i] = 0;
		}
	}
}
#if 0
void saveWorkParams(void)
{
	work_mode_params &= (device_def.device_work_mode << 4);
	work_mode_params |= device_def.device_channel_def[3].device_channel_mode << 3;
	work_mode_params |= device_def.device_channel_def[2].device_channel_mode << 2;
	work_mode_params |= device_def.device_channel_def[1].device_channel_mode << 1;
	work_mode_params |= device_def.device_channel_def[0].device_channel_mode << 0;
}
void loadWorkParams(void)
{
	device_def.device_work_mode = work_mode_params & (0x01 << 4);
	device_def.device_channel_def[3].device_channel_mode = work_mode_params & (0x01 << 3);
	device_def.device_channel_def[2].device_channel_mode = work_mode_params & (0x01 << 2);
	device_def.device_channel_def[1].device_channel_mode = work_mode_params & (0x01 << 1);
	device_def.device_channel_def[0].device_channel_mode = work_mode_params & (0x01 << 0);
}
#endif
void setParams13(uint8_t index)
{
	if(index == 4)
	{
		dev_params[12] &= 0xef;
		dev_params[12] &= device_def.device_work_mode << 4;
	}
	else
	{
		dev_params[12] &= (~(0x01 << index));
		dev_params[12] &= (device_def.device_channel_def[index].device_channel_mode << index);
	}
}
void getParams13(void)
{
	device_def.device_work_mode = dev_params[12] & (0x01 << 4);
	device_def.device_channel_def[3].device_channel_mode = dev_params[12] & (0x01 << 3);
	device_def.device_channel_def[2].device_channel_mode = dev_params[12] & (0x01 << 2);
	device_def.device_channel_def[1].device_channel_mode = dev_params[12] & (0x01 << 1);
	device_def.device_channel_def[0].device_channel_mode = dev_params[12] & (0x01 << 0);
}
#endif
bool decodeWireless(uint8_t *decode_data)
{
	static bool syn_flag = false;
	static uint8_t bit_cnt = 0;
	static uint8_t low_cnt = 0;
	static uint8_t high_cnt = 0;
	static uint8_t temp_val = 0;
    uint8_t index = 0;
	if(!syn_flag)
	{
		if(WIRELESS_PIN == 0)
		{
			low_cnt++;
		}
		if(WIRELESS_PIN == 1)
		{
			if(low_cnt > 60 && low_cnt < 150)
			{
				syn_flag = true;
			}
			low_cnt = 0;
		}
	}
	if(syn_flag)
	{
		if(WIRELESS_PIN == 1)
		{
			high_cnt++;
		}
		else
		{
			if((high_cnt) > 1 && high_cnt < 6)
			{
				bit_cnt++;
				temp_val = (temp_val << 1) | 0x01;
			}
			else if((high_cnt) > 6 && (high_cnt < 13))
			{
				bit_cnt++;
				temp_val = temp_val << 1;
			}
			else if(high_cnt > 0)
			{
				syn_flag = false;
				bit_cnt = 0;
				temp_val = 0;
			}
			high_cnt = 0;
			if(bit_cnt != 0 && bit_cnt % 8 == 0 )
			{
				index = (bit_cnt / 8) - 1;
				decode_data[index] = temp_val;
				if(bit_cnt == 24)
				{
					syn_flag = false;
					bit_cnt = 0;
					return true;
				}
			}
		}
	}
	return false;
}

void decode(void)
{
	if(decodeWireless(decode_data))
	{
		//wirelessLedTog();
		wireless_flag  = true;
	}
}
static void wirelessStudy(uint8_t index)
{
    uint8_t i = 0;
    uint32_t temp_val = 0;
    if(device_def.device_channel_def[index].wireless_study_flag == false)
    {
        device_def.device_channel_def[index].wireless_lastval =
        				((((decode_data[0] << 8) | decode_data[1]) << 8) | decode_data[2]);
        device_def.device_channel_def[index].wireless_study_flag = true;
    }
    else
    {
        if(device_def.device_channel_def[index].wireless_study_flag == true)
        {
            if(device_def.device_channel_def[index].wireless_lastval ==
            		((((decode_data[0] << 8) | decode_data[1]) << 8) | decode_data[2]))
            {
                for(i = 0; i < 12; i = i + 3)
				{
					temp_val = ((((dev_params[i] << 8) | dev_params[i+1]) << 8) | dev_params[i+2]);
					if(device_def.device_channel_def[index].wireless_lastval == temp_val)
					{
						dev_params[i] = 0;
						dev_params[i + 1] = 0;
						dev_params[i + 2] = 0;
						break;
					}
				}
                dev_params[index * 3] = decode_data[0];
                dev_params[index * 3 + 1] = decode_data[1];
                dev_params[index * 3 + 2] = decode_data[2];
                /*存flash*/
                //FLASH_ByteWrite();
                //savaParamtoFlash();
				FLASH_PageErase(FLASH_LAST);
				for(i = 0; i < 13; i++)
				{
					FLASH_ByteWrite(FLASH_LAST+i,dev_params[i]);
				}
                device_def.device_channel_def[index].device_status = DEVICE_STATUS_IDLE;
                wirelessOn500msOff500ms(~(0x01 << index));
            }
            device_def.device_channel_def[index].wireless_study_flag = false;
            device_def.device_channel_def[index].wireless_lastval = 0;
        }
    }
}
static void wirelessAction(void)
{
    uint8_t i = 0;
    uint32_t temp_val = 0;
    if(wireless_flag == true)
    {
    	for(i = 0; i < 12; i = i + 3)
		{
			if(dev_params[i] == decode_data[0]
			   && dev_params[i + 1] == decode_data[1]
			   && dev_params[i + 2] == decode_data[2])
			{
				device_def.device_channel_def[i/3].wireless_flag = true;
				//按键处理
				if(device_def.device_work_mode != DEVICE_433)
				{
					setKeyPin(i / 3,false);
				}
				//闪灯
				wirelessOn50msOff50ms(LED_WIRELESS);
				break;
			}
		}
    }
    else
	{
    	for(i = 0; i < 4; i++)
    	{
			if(device_def.device_channel_def[i].wireless_flag == true)
			{
				device_def.device_channel_def[i].wireless_flag = false;
				//按键处理
				if(device_def.device_work_mode != DEVICE_433)
				{
					setKeyPin(i,true);
				}
			}
    	}
	}
}
void wireless_scan(void)
{
	uint8_t i = 0;
	for(i = 0; i < 4; i++)
	{
		if((DEVICE_STATUS_STUDY == device_def.device_channel_def[i].device_status)
			&& DEVICE_433 == device_def.device_work_mode
			&& (wireless_flag == true))
		{
			wirelessStudy(i);
			wireless_flag = false;
			return;
		}
	}
	wirelessAction();
	wireless_flag = false;
}
