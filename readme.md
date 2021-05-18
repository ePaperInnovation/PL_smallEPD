Plastic Logic PL_smallEPD Arduino Library
===============================================================

Welcome to the `PL_smallEPD` docs! This is a library for UC8156-based  E-Paper displays (EPD) from Plastic Logic for Adafruits GFX library. 


![2.1" Legio E-Paper](https://user-images.githubusercontent.com/21104467/113095639-1842a280-91f4-11eb-926a-6373e361ff16.png) 
[*2.1" Legio E-Paper from Plastic Logic*](https://www.plasticlogic.com)

### So, what is PL_smallEPD?

`PL_smallEPD` is an easy to use Epaper library intended to be used in combination with Plastic Logics breakout-board having Adafruits Feather form-factor. The eInk-based, reflective ePaper display mimics the appearance of natural paper and is capable of holding text and images indefinitely, even without electricity. This makes this screen perfect for your next battery-driven, connected project where the display content changes rarely.

## Installation

Please check whether you have an actual release of the **Arduino IDE** installed or download the latest version from [here](https://www.arduino.cc/en/Main/Software). 

### Adding Adafruit Feather nRF52840 board
Next please [add](https://learn.adafruit.com/introducing-the-adafruit-nrf52840-feather/arduino-bsp-setup) the new board to the Arduino IDE: Please go to FILE > PREFERENCES and add `https://www.adafruit.com/package_adafruit_index.json` as an **Additional Board Manager URL**. After restart of the IDE please open the **Boards Manager** from the **Tools -> Board** menu and install **Adafruit nRF52 by Adafruit**. It will take a few minutes to finish installing the cross-compiling toolchain and associated tools. Then please select the board **Adafruit Feather nRF52840 Express**, and after connecting the board via USB, please select the newly appeared serial COM port for your device under **Tools --> Port** and you should be ready to go for flashing your own programs!

### Adding the library Adafruit_GFX
This library is part of the Arduino **Library Manager**. Please search for `Adafruit GFX` within the Manager and download this library.

### Adding the library PL_smallEPD
Please download the library from this Github repo to your local Arduino/library folder. After restarting the Arduino IDE you can find the first examples under **File > Examples > PL_smallEPD > Examples**.

### Example: Hello World!

This is the shortest possible demo and shows how to address the ePaper:


```cpp
#include <Arduino.h>
#include <Adafruit_GFX.h>           // Core library for graphics (GFX)  & text 
#include <PL_smallEPD.h>            // Generic library for UC8156-based EPDs from Plastic Logic
#include "PL_smallLegio.h"      	// Display-specific library for 4pigment media (Legio, 6colors)

#define EPD_CS      5  
#define EPD_BUSY    9
#define EPD_RST     12

//PL_smallEPD epd(EPD_CS, EPD_RST, EPD_BUSY);	// "Lectum" EPD (2 pigment system, 4 greylevels)  -or- 
PL_smallLegio epd(EPD_CS, EPD_RST, EPD_BUSY);   // "Legio" EPD (4 pigment system, 6 colors)

void setup() {  
    SPI.begin();                    
    SPI.beginTransaction(SPISettings(6000000, MSBFIRST, SPI_MODE0));
  
    display.begin();                
    display.print("Hello World!");
    display.update();               
}

void loop() {              
}
```


Distributors
-------------------
2.1" Legio ePaper displays are available at [Plastic Logic](https://www.plasticlogic.com/product/2-1-legio-colour-display/).

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

Created by Zhongke Dai & Robert Poser, Mar 30th 2021, Dresden/Germany. Released under BSD license
(3-clause BSD license), check license.md for more information.

