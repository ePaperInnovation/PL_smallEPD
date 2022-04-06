#include <Arduino.h>
#include <Adafruit_GFX.h>           // Core library for graphics (GFX)  & text 
#include <PL_smallEPD.h>            // Generic library for UC8156-based EPDs from Plastic Logic
#include "PL_smallLegio.h"          // Display-specific library for 4pigment media (Legio, 6colors)

#include "pricetag.h" 
#define EPD_RST     12
#define EPD_BUSY    9
#define EPD_CS      5
    

 
 
PL_smallEPD epd(EPD_CS, EPD_RST, EPD_BUSY);     
//PL_smallLegio epd(EPD_CS, EPD_RST, EPD_BUSY);     

void setup() {  

    SPI.begin();                    // SPI initialisation, UC8156 supp. max 10Mhz (writing) & 
    SPI.beginTransaction(SPISettings(6000000, MSBFIRST, SPI_MODE0));      // 6.6Mhz (reading) 
    epd.begin(EPD_BLACK);           // EPD initialisation & ClearScreen
    epd.showImage(pricetag, EPD_UPD_4GL_FULL, COLORTYPE_RED);     // Load image byte stream and trigger an update
    //     delay(5000);                 // delay 5 seconds
    //  epd.colorRed_clear();           // clear screen

  
}

void loop() {        
}
