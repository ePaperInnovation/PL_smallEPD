Plastic Logic PL_smallEPD Arduino Library
===============================================================

Welcome to the PL_smallEPD docs! This is a library for UC8156-based  E-Paper displays (EPD) from Plastic Logic for Adafruits GFX library. 


![Paperino E-Paper Shield for Particle, Breakout Board and Driver Module](https://user-images.githubusercontent.com/21104467/29744828-50b878b2-8aad-11e7-8448-8b2f45289c4c.png)  
[*Paperino E-Paper Shield for Particle, Breakout Board and Driver Module*](https://www.crowdsupply.com/robert-poser/paperino)

### So, what is PL_smallEPD?

PL-smallEPD is an easy to use Epaper library intended to be used in combination with Plastic Logics breakout-board having Adafruits Feather form-factor. The eInk-based, reflective ePaper display mimics the appearance of natural paper and is capable of holding text and images indefinitely, even without electricity. This makes this screen perfect for your next battery-driven, connected project where the display content changes rarely.

How To Use
-------------------

### Installation

(This library is part of the Arduino **Library Manager**. Please search for `PL_smallEPD` within the Manager and download the library, that’s it!) Please download this library from Github to your Arduino/library folder. Included are several example sketches, they are useful to learn the basics about this ePaper screen.

### Example: Hello World!

This is the [first](https://robpo.github.io/Paperino/exampleHelloWorld/), and shortest possible demo and shows how to address the ePaper:


```cpp
#include <Arduino.h>
#include <Adafruit_GFX.h>           // Core library for graphics (GFX)  & text 
#include <PL_smallEPD.h>            // Generic library for UC8156-based EPDs from Plastic Logic
#include "PL_smallLegio.h"      	// Display-specific library for 4pigment media (Legio, 6colors)

#define EPD_RST     12
#define EPD_BUSY    9
#define EPD_CS      5  

//PL_smallEPD(EPD_CS, EPD_RST, EPD_BUSY);			// 4 Greylevel "Lectum" EPD (2 pigment system)  -or- 
PL_smallLegio epd(EPD_CS, EPD_RST, EPD_BUSY);   // 6 Color "Legio" EPD (4 pigment system)

void setup() {  
    SPI.begin();                    
    SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0));
  
    display.begin();                
    display.print("Hello World!");
    display.update();               
}

void loop() {              
}
```


### More…

Once this example is successfully running, please have a look at the following sketches: [GFX demo](https://robpo.github.io/Paperino/exampleGFXdemo/) shows how to draw all the letters, rectangles and dots. The [Graylevel](https://robpo.github.io/Paperino/example4GLs/) sketch explains how to use the four different graylevels in your next project. [Update modes](https://robpo.github.io/Paperino/exampleUpdateMode/) describes three different ways of updating an ePaper screen.

Distributors
-------------------
Legio ePaper displays are available at [Plastic Logic](https://www.plasticlogic.com/product/2-1-legio-colour-display/), 

Projects
-------------------
These demo projects are for your inspiration! What will you implement with PL_smallEPD? Tell us, we’ll love to add your project here!

Changelog
-------------------
- [v1.0.00 (03/2021)](https://github.com/RobPo/Paperino/archive/v1.1.01.zip) - Initial release

License Information
-------------------
PL_smallEPD - A library for 1.1”, 1.4", 2.1" and 3.1" E-Paper displays (EPDs) from Plastic Logic 
based on UC8156 driver IC for Adafruit GFX core library. The communication is SPI-based, 
for more information about hook-up please check: https://github.com/plasticlogic/PL_smallEPD.

Created by Robert Poser & Zhongke Dai, Mar 30th 2021, Dresden/Germany. Released under BSD license
(3-clause BSD license), check license.md for more information.

We invested time and resources providing this open source code, please support Plasticlogic 
and open source hardware by purchasing this product @Plasticlogic
