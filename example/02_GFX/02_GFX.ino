#include <Arduino.h>
#include <Adafruit_GFX.h>           // Core library for graphics (GFX)  & text 
#include "PL_smallLegio.h"        // Display-specific library for 4pigment media (Legio, 6colors)

#define EPD_CS      5  
#define EPD_BUSY    9
#define EPD_RST     12

PL_smallLegio display(EPD_CS, EPD_RST, EPD_BUSY);   // "Legio" EPD (4 pigment system, 6 colors)

void setup() {  
    SPI.begin();                    
    SPI.beginTransaction(SPISettings(6000000, MSBFIRST, SPI_MODE0));
  
    display.begin(EPD_BLACK);                

    display.fillRect(40,40,25,25, EPD_BLACK);  
    display.fillRect(80,80,25,25, EPD_BLACK);
    display.fillRect(40,80,25,25, EPD_BLACK);
    display.fillRect(40,80,25,25, EPD_BLACK);
    display.updateLegio(EPD_BLACK);

    display.clear();
    display.fillRect(40,40,25,25, EPD_BLACK);   
    display.updateLegio(EPD_RED);

    display.clear();
    display.fillRect(40,80,25,25, EPD_BLACK);
    display.fillRect(80,80,25,25, EPD_BLACK);
    display.updateLegio(EPD_YELLOW);
    
    display.clear();
    display.fillRect(40,80,25,25, EPD_BLACK);
    display.updateLegio(EPD_GREEN);

    display.clear();
    display.fillRect(80,40,25,25, EPD_BLACK);      
    display.updateLegio(EPD_BLUE);
}

void loop() {              
}
