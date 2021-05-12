#include <Arduino.h>
#include <Adafruit_GFX.h>           // Core library for graphics (GFX)  & text 
#include "PL_smallLegio.h"          // Display-specific library for 4pigment media (Legio, 6colors)

#define EPD_CS      5  
#define EPD_BUSY    9
#define EPD_RST     12
                                    // Declare 4pigment based EPD instance with 6 colors
PL_smallLegio epd(EPD_CS, EPD_RST, EPD_BUSY);   

void setup() {  
    SPI.begin();                         // Bus initialisation, UC8156 supp. max 10Mhz (writing)
    SPI.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE0));//and 6.6Mhz (reading)
  
    epd.begin(EPD_BLACK);                // E-Paper initialisation and refresh screen 
    epd.println("Hello World");
    epd.updateLegio(EPD_BLACK);
}

void loop() {              
}
