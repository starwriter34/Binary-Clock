//######################################################################################################
// Binary Clock using Neopixels.
//
// Author: Chris Oakley
// Email: modelpainter34@gmail.com
//
// Change Log
//
// Date: 07/14/2016
// Version 1.0.0 - Setup Hour, Minute, and Second selection string.
//
// Date: 10/6/2016
// Version 1.0.5 - Setup DS1307 RTC to get the time and also added LED brightness code.
//
// Date: 10/9/2016
// Version 1.0.6 - Changed from Adafruits NEOPIXEL Library to FastLED's Library. It solved a flickering problem
// that arose at the far end of the LED chain. The code is smaller with FastLED's Library. I also added
// the photocell circuit to control the brightness of the LEDs. Removed the library for the RTC and added
// the code to work with it directly.
//
// Date: 10/9/2016
// Version 1.0.7 - Added Daylight Savings Time. The function consists of two toggle switches; one will turn the
// function on or off, the second toggle will toggle whether the time springs forward or falls back.
//
// Date: 10/9/2016
// Version 1.0.8 - Added color themes.
//
// Date: 10/30/2016
// Version: 1.1.0 - Scrapped the code and started over. Themes is going to be scaled back to Dual Color themes and custom color. 
// Instead of the nested if statements, I went with a for loop instead. I still working on the code to be better. I believe if I
// setup an array to write the status of each digit, the code will be faster. A0-A2 will have pots on them to select a color.
//
// Things to add:
// Function:																	Finished: (Y/N)
//
// Themes:
//
// **    Night Time Theme Dual Color 10pm to 6am (Listed Below)
//            Red and Green, Red is Color_On and Green is Color_Off
//            Blue and Yellow, Blue is Color_On and Yellow is Color_Off
//            Purple and Orange, Purple is Color_On and Orange Color_Off
//            All LED's Off from 10pm to 6am
// **    Custom Color Choice
//
// Other Functions:
//
// **    Daylight Savings Time
// **    Manually Set Time
//
//
//######################################################################################################
// Pins used on Atmega328P
//######################################################################################################
//
// Analog:
// 			A0 -
//			A1 -
//			A2 -
//			A3 - Photocell
//			A4 - I2C for DS1307 RTC
//			A5 - I2C for DS1307 RTC
//
// Digital:
//			D0 - RX Serial
//			D1 - TX Serial
//			D2 - LED Data Line
//			D3 - Enable/Disable Daylight Savings Time
//			D4 - Daylight Savings Time +1 hour or -1 hour
//			D5 - Enable Dual Night Time Themes
//			D6 - Dual Night Time Themes Logic 1
//			D7 - Dual Night Time Themes Logic 2
//			D8 - Night Vision Safe (Red)
//			D9 - Activate Photocell
//			D10 - Standard Color Logic 1
//			D11 - Standard Color Logic 2
//			D12 - Standard Color Logic 3
//			D13 - Night Theme Override

//######################################################################################################
// FastLED Setup
//######################################################################################################

#include <FastLED.h>
#define NUM_LEDS 20
#define DATA_PIN 2
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

//######################################################################################################
// DS1307 Setup
//######################################################################################################

#include <Wire.h>										// Wire Library I2C
#define DS1307_I2C_ADDRESS 0x68							// DS1307 Address

byte decToBcd(byte val)									// Convert normal decimal numbers to binary coded decimal
{
	return ( (val / 10 * 16) + (val % 10) );
}

byte bcdToDec(byte val)									// Convert binary coded decimal to normal decimal numbers
{
	return ( (val / 16 * 10) + (val % 16) );
}

//######################################################################################################
// Begin variable declaration
//######################################################################################################
//######################################################################################################
//int LED_Array[20];
//######################################################################################################
// Photocell Variable - Used to set the brightness of the LED's.
//######################################################################################################

//int pcReading;

//######################################################################################################
// Themes Variables - There will always be two colors, one that is on and one that is off.
//######################################################################################################


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

//######################################################################################################
// Pin Array
//######################################################################################################

//int ledPins[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A3, A2, A1, A0};
//int pinCount = 15;

//######################################################################################################
//######################################################################################################
// End variable declaration
//######################################################################################################
//######################################################################################################

void setup()
{

	Wire.begin();

	FastLED.addLeds<WS2812B, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);

//	for(int currentPin = 0; currentPin < pinCount; currentPin++)
//	{
//		pinMode(ledPins[currentPin], INPUT);
//	}

//	for(int currentPin = 0; currentPin < pinCount; currentPin++)
//	{
//		digitalWrite(ledPins[currentPin], LOW);
//	}

//	Serial.begin(9600);
// seconds, minute, hour, dayofWeek, day, month, year
//setDateDs1307(30, 13, 21,3,25,10,16);
}

void loop()
{

	FastLED.setBrightness(64);


//######################################################################################################
//Get Time and convert to hours, minutes, and seconds
//######################################################################################################

	Wire.beginTransmission(DS1307_I2C_ADDRESS);
	Wire.write(0x00);
	Wire.endTransmission();
	Wire.requestFrom(DS1307_I2C_ADDRESS, 7);

	second = bcdToDec(Wire.read() & 0X7f);
	minute = bcdToDec(Wire.read());
	hour = bcdToDec(Wire.read() & 0x3f);
	dayofWeek = bcdToDec(Wire.read());
	day = bcdToDec(Wire.read());
	month = bcdToDec(Wire.read());
	year = bcdToDec(Wire.read());

	if (hour == 0)
	{
		hour = 24;
	}

	unsigned long color_On = CRGB::Red;
	unsigned long color_Off = CRGB::Black;
//int lastSecond;
// Units of time Math
//if (second>=lastSecond || second==0)

	int secondUnit = second % 10;
	int secondTensUnit  = (second - secondUnit) / 10;
	int minuteUnit = minute % 10;
	int minuteTensUnit = (minute - minuteUnit) / 10;
	int hourUnit = hour % 10;
	int hourTensUnit = (hour - hourUnit) / 10;

// Seconds Setup

	for (int i = 3; i >= 0; i--)
	{
		if (bitRead(secondUnit, i) == 1)
		{
			leds[i] = CRGB::Red;
		}
		else
		{
			(bitRead(secondUnit, i) == 0);
			leds[i] = CRGB::Black;
		}

	}

	for (int i = 0; i <= 2; i++)
	{
		if (bitRead(secondTensUnit, i) == 1)
		{
			leds[6 - i] = CRGB::Red;
		}
		else
		{
			(bitRead(secondTensUnit, i) == 0);
			leds[6 - i] = CRGB::Black;
		}

	}
// Minutes

	for (int i = 3; i >= 0; i--)
	{
		if (bitRead(minuteUnit, i) == 1)
		{
			leds[7 + i] = CRGB::Blue;
		}
		else
		{
			(bitRead(minuteUnit, i) == 0);
			leds[7 + i] = CRGB::Black;
		}

	}

	for (int i = 0; i <= 2; i++)
	{
		if (bitRead(minuteTensUnit, i) == 1)
		{
			leds[13 - i] = CRGB::Blue;
		}
		else
		{
			(bitRead(minuteTensUnit, i) == 0);
			leds[13 - i] = CRGB::Black;
		}

	}


//hours

	for (int i = 3; i >= 0; i--)
	{
		if (bitRead(hourUnit, i) == 1)
		{
			leds[14 + i] = CRGB::Green;
		}
		else
		{
			(bitRead(hourUnit, i) == 0);
			leds[14 + i] = CRGB::Black;
		}

	}

	for (int i = 0; i <= 1; i++)
	{
		if (bitRead(hourTensUnit, i) == 1)
		{
			leds[19 - i] = CRGB::Green;
		}
		else
		{
			(bitRead(hourTensUnit, i) == 0);
			leds[19 - i] = CRGB::Black;
		}

	}

FastLED.show();
}
