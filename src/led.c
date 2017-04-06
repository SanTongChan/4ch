#include "led.h"
#include <SI_EFM8BB1_Register_Enums.h>
#include "stdio.h"
#include "logic.h"

static uint8_t led_val = 0xff;
enum
{
    LED_OFF         = 0x00, //LEDœ®√
    LED_ON          = 0x01, //LED≥£¡¡
    LED_FLASH       = 0x82, //LED…¡À∏
};

typedef struct
{
	uint8_t speed;
	uint8_t speed_cnt;
	uint8_t speed_on;
	uint8_t speed_off;
	uint8_t flag;
	uint8_t blink_cnt;
	uint8_t blink_cnt_on;
	uint8_t lock;
	uint8_t key_val;
	uint8_t lock_on;
}_led_ctl;
_led_ctl wireless_led;


static bool wirelessLedIsOn(uint8_t key_val)
{
	if(0x00 == (led_val & (~key_val)))
	{
		return true;
	}
	else
	{
		return false;
	}
}
static void  wirelessLedTog(uint8_t key_val)
{
	if(0x00 == (led_val & (~key_val)))//¡¡
	{
		led_val |= (~key_val);
	}
	else
	{
		led_val &= key_val;
	}
	SendTo595();
}
void wirelessScan(void)
{
    if((wireless_led.flag & 0x80)
    	&& (wireless_led.blink_cnt_on <= wireless_led.blink_cnt
    		|| 0 == wireless_led.blink_cnt)
    	)
    {
        wireless_led.speed_cnt++;
        if(wireless_led.speed_cnt >= wireless_led.speed)
        {

            if(wirelessLedIsOn(wireless_led.key_val))
            {
            	if(wireless_led.blink_cnt == wireless_led.blink_cnt_on)
            	{
            		wireless_led.lock = false;
            	}
            	wireless_led.blink_cnt_on++;
                wireless_led.speed = wireless_led.speed_off;
            }
            else
            {
                wireless_led.speed = wireless_led.speed_on;
            }
            wireless_led.speed_cnt = 0;
            wirelessLedTog(wireless_led.key_val);
            if(wireless_led.blink_cnt < wireless_led.blink_cnt_on
				&& wireless_led.lock_on == true
				&& device_def.device_work_mode == DEVICE_433)
			{
				wireless_led.lock_on = false;
				wirelessLedTog(wireless_led.key_val);
			}
        }
    }
}

void wirelessLedOn(void)
{
	wireless_led.flag = LED_ON;
	led_val &= LED_WIRELESS;
	SendTo595();
}
void wirelessLedOff(void)
{
	wireless_led.flag = LED_OFF;
	led_val |= (~LED_WIRELESS);
	SendTo595();
}
void wirelessOn500msOff500ms(uint8_t key_val)
{
	if(!wireless_led.lock)
	{
		wireless_led.speed = 20;
		wireless_led.speed_off = 20;
		wireless_led.speed_on = 20;
		wireless_led.blink_cnt_on = 0;
		wireless_led.blink_cnt = 4;
		wireless_led.lock = true;
		wireless_led.flag = LED_FLASH;
		wireless_led.key_val = key_val;
		wireless_led.lock_on = false;
	}
}
void wirelessOn50msOff50ms(uint8_t key_val)
{
	if(!wireless_led.lock)
	{
		wireless_led.speed = 5;
		wireless_led.speed_off = 5;
		wireless_led.speed_on = 5;
		wireless_led.blink_cnt_on = 0;
		wireless_led.blink_cnt = 1;
		wireless_led.flag = LED_FLASH;
		wireless_led.key_val  = key_val;
		wireless_led.lock_on = true;
	}
}

void ledChannel1On(void)
{
	led_val &= LED_CHANNEL1;
	SendTo595();
}
void ledChannel1Off(void)
{
	led_val |= (~LED_CHANNEL1);
	SendTo595();
}
void ledChannel2On(void)
{
	led_val &= LED_CHANNEL2;
	SendTo595();
}
void ledChannel2Off(void)
{
	led_val |= (~LED_CHANNEL2);
	SendTo595();
}

void ledChannel3On(void)
{
	led_val &= LED_CHANNEL3;
	SendTo595();
}
void ledChannel3Off(void)
{
	led_val |= (~LED_CHANNEL3);
	SendTo595();
}
void ledChannel4On(void)
{
	led_val &= LED_CHANNEL4;
	SendTo595();
}
void ledChannel4Off(void)
{
	led_val |= (~LED_CHANNEL4);
	SendTo595();
}

void ledModeOn(void)
{
	led_val &= LED_MODE;
	SendTo595();
}
void ledModeOff(void)
{
	led_val |= (~LED_MODE);
	SendTo595();
}
void ledsOff(void)
{
	led_val = LEDS_OFF;
	SendTo595();
}
void ledsOn(void)
{
	led_val = LEDS_ON;
	SendTo595();
}
void ledSetChannelsValue(uint8_t val)
{
	led_val |= 0x0f;
	led_val &= val;
	SendTo595();
}
void SendTo595(void)
{
	char i=0;
	uint8_t temp = led_val;
	for(i = 0; i < 8; i++)
	{
		SER = temp>>7;
		temp= temp<<1;
		SCK = 1;
		_nop_();
		_nop_();
		SCK = 0;
	}
	RCK = 1;
	_nop_();
	_nop_();
	RCK = 0;
}
