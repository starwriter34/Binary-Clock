# Binary-Clock with Neopixels By Chris Oakley
Binary Clock with NeoPixels Project

Created On: 7/10/2016

**Author:** Chris Oakley

**Website:** [Axiom Thesis](http://www.axiomthesis.com)

**Email:** modelpainter34@gmail.com

## Change Log

**Date: 07/14/2016 - Version 0.9.0** - Setup Test Code for LEDs.

**Date: 10/05/2016 - Version 1.0.0** - Setup Hour, Minute, and Second selection string.

**Date: 10/6/2016 - Version 1.0.5** - Setup DS1307 RTC to get the time and also added LED brightness code.

**Date: 10/9/2016 - Version 1.0.6** - Changed from Adafruits NEOPIXEL Library to FastLED's Library. It solved a flickering problem
that arose at the far end of the LED chain. The code is smaller with FastLED's Library. I also added
the photocell circuit to control the brightness of the LEDs. Removed the library for the RTC and added
the code to work with it directly.

**Date: 10/9/2016 - Version 1.0.7** - Added Daylight Savings Time. The function consists of two toggle switches; one will turn the
function on or off, the second toggle will toggle whether the time springs forward or falls back.

**Date: 10/9/2016 - Version 1.0.8** - Added color themes.

**Date: 10/30/2016 - Version 1.1.0** - Scrapped the code and started over. Themes is going to be scaled back to Dual Color themes
and custom color. Instead of the nested if statements, I went with a for loop instead. I still working on the code to be better. I
believe if I setup an array to write the status of each digit, the code will be faster. A0-A2 will have pots on them to select a color.
Back to the Drawing Board. :)

**Things to add:**
**Function:**

- [ ] Night Themes (Dual Color)
- [ ] Color Choices
- [ ] NTP Update of RTC
- [ ] Show the Date
- [ ] Daylight Savings time
- [ ] Alarm Function
- [ ] Manually Setting the Time
- [ ] Manually Changing the Color
