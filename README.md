# Binary-Clock with Neopixels By Chris Oakley
Binary Clock with NeoPixels Project

Created On: 7/10/2016

**Author:** Chris Oakley
**Email:** modelpainter34@gmail.com

# Change Log

**Date: 10/05/2016
Version 1.0.0** - Setup Hour, Minute, and Second selection string.

**Date: 10/6/2016
Version 1.0.5** - Setup DS1307 RTC to get the time and also added LED brightness code.

**Date: 10/9/2016
Version 1.0.6** - Changed from Adafruits NEOPIXEL Library to FastLED's Library. It solved a flickering problem
that arose at the far end of the LED chain. The code is smaller with FastLED's Library. I also added
the photocell circuit to control the brightness of the LEDs. Removed the library for the RTC and added
the code to work with it directly.

**Date: 10/9/2016
Version 1.0.7** - Added Daylight Savings Time. The function consists of two toggle switches; one will turn the
function on or off, the second toggle will toggle whether the time springs forward or falls back.

**Date: 10/9/2016
Version 1.0.8** - Added color themes.

**Things to add:**
**Function:																	Finished: (Y/N)**
Themes
Night Time Theme Dual Color(Such, as Red & Green or Opposites of color) (3)		Y
		Night Vision Safe(Red) (1)													Y
		Night Time (Purple) (1)															Y
		8 Color Choices (3)														   		Y

NTP Update RTC
Show the date
Daylight savings time													    			Y
Alarm function
