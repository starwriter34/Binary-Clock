//######################################################################################################
// FastLED Setup
//######################################################################################################

#include <FastLED.h>
#define NUM_LEDS 20
#define DATA_PIN 2
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

//######################################################################################################
// Themes Variables - There will always be two colors, one that is on and one that is off.
//######################################################################################################

unsigned long color_On = Red;
unsigned long color_Off = Black;

//######################################################################################################
// Clock and Date Variables
//######################################################################################################

int second;
int minute;
int hour;
int dayofWeek;
int day;
int month;
int year;

void setup()
{

	FastLED.addLeds<WS2812B, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);

}

void loop()
{
	FastLED.setBrightness(64);

	if (hour == 0)
	{
		hour = 24;
	}

//######################################################################################################
// Setting up the single digits of hours, minutes, and seconds.
//######################################################################################################

	int hourUnit = hour % 10;
	int minuteUnit = minute % 10;
	int secondUnit = second % 10;


//######################################################################################################
// Single Seconds 0-9
//######################################################################################################
	if(secondUnit == 1 || secondUnit == 3 || secondUnit == 5 || secondUnit == 7 || secondUnit == 9)
	{
		leds[0] = color_On;
		FastLED.show();

	}
	else
	{
		leds[0] = color_Off;
		FastLED.show();
	}

	if(secondUnit == 2 || secondUnit == 3 || secondUnit == 6 || secondUnit == 7)
	{
		leds[1] = color_On;
		FastLED.show();
	}
	else
	{
		leds[1] = color_Off;
		FastLED.show();
	}

	if(secondUnit == 4 || secondUnit == 5 || secondUnit == 6 || secondUnit == 7)
	{
		leds[2] = color_On;
		FastLED.show();
	}
	else
	{
		leds[2] = color_Off;
		FastLED.show();
	}

	if(secondUnit == 8 || secondUnit == 9)
	{
		leds[3] = color_On;
		FastLED.show();
	}
	else
	{
		leds[3] = color_Off;
		FastLED.show();
	}
//######################################################################################################
// Tens of seconds 10-50
//######################################################################################################
	if((second >= 10 && second < 20) || (second >= 30 && second < 40) || (second >= 50 && second < 60))
	{
		leds[6] = color_On;
		FastLED.show();
	}
	else
	{
		leds[6] = color_Off;
		FastLED.show();
	}

	if(second >= 20 && second < 40)
	{
		leds[5] = color_On;
		FastLED.show();
	}
	else
	{
		leds[5] = color_Off;
		FastLED.show();
	}

	if(second >= 40 && second < 60)
	{
		leds[4] = color_On;
		FastLED.show();
	}
	else
	{
		leds[4] = color_Off;
		FastLED.show();

	}

//######################################################################################################
// Single Minutes 0-9
//######################################################################################################
	if(minuteUnit == 1 || minuteUnit == 3 || minuteUnit == 5 || minuteUnit == 7 || minuteUnit == 9)
	{
		leds[7] = color_On;
		FastLED.show();
	}
	else
	{
		leds[7] = color_Off;
		FastLED.show();
	}

	if(minuteUnit == 2 || minuteUnit == 3 || minuteUnit == 6 || minuteUnit == 7)
	{
		leds[8] = color_On;
		FastLED.show();
	}
	else
	{
		leds[8] = color_Off;
		FastLED.show();
	}

	if(minuteUnit == 4 || minuteUnit == 5 || minuteUnit == 6 || minuteUnit == 7)
	{
		leds[9] = color_On;
		FastLED.show();
	}
	else
	{
		leds[9] = color_Off;
		FastLED.show();
	}

	if(minuteUnit == 8 || minuteUnit == 9)
	{
		leds[10] = color_On;
		FastLED.show();
	}
	else
	{
		leds[10] = color_Off;
		FastLED.show();
	}
//######################################################################################################
//Tens of Minutes 10-50
//######################################################################################################
	if((minute >= 10 && minute < 20) || (minute >= 30 && minute < 40) || (minute >= 50 && minute < 60))
	{
		leds[13] = color_On;
		FastLED.show();
	}
	else
	{
		leds[13] = color_Off;
		FastLED.show();
	}

	if(minute >= 20 && minute < 40)
	{
		leds[12] = color_On;
		FastLED.show();
	}
	else
	{
		leds[12] = color_Off;
		FastLED.show();
	}

	if(minute >= 40 && minute < 60)
	{
		leds[11] = color_On;
		FastLED.show();
	}
	else
	{
		leds[11] = color_Off;
		FastLED.show();
	}
//######################################################################################################
// Single Hours 0-9
//######################################################################################################
	if(hourUnit == 1 || hourUnit == 3 || hourUnit == 5 || hourUnit == 7 || hourUnit == 9)
	{
		leds[14] = color_On;
		FastLED.show();
	}
	else
	{
		leds[14] = color_Off;
		FastLED.show();
	}

	if(hourUnit == 2 || hourUnit == 3 || hourUnit == 6 || hourUnit == 7)
	{
		leds[15] = color_On;
		FastLED.show();
	}
	else
	{
		leds[15] = color_Off;
		FastLED.show();
	}

	if(hourUnit == 4 || hourUnit == 5 || hourUnit == 6 || hourUnit == 7)
	{
		leds[16] = color_On;
		FastLED.show();
	}
	else
	{
		leds[16] = color_Off;
		FastLED.show();
	}

	if(hourUnit == 8 || hourUnit == 9)
	{
		leds[17] = color_On;
		FastLED.show();
	}
	else
	{
		leds[17] = color_Off;
		FastLED.show();
	}
//######################################################################################################
//Tens of Hours 10-20
//######################################################################################################
	if(hour >= 10 && hour < 20)
	{
		leds[19] = color_On;
		FastLED.show();
	}
	else
	{
		leds[19] = color_Off;
		FastLED.show();
	}

	if(hour >= 20 && hour <= 24)
	{
		leds[18] = color_On;
		FastLED.show();
	}
	else
	{
		leds[18] = color_Off;
		FastLED.show();
	}

	if (second >= 60)
	{
		minute++;
		second = 0;
	}
	else
	{
		second++;
	}

	if(minute >= 60)
	{
		hour++;
		minute = 0;
	}
	else
	{
		minute++;
	}

	if(hour >= 24)
	{
		hour = 1;
	}
	else
	{
		hour++;
	}
	delay(250);
}
