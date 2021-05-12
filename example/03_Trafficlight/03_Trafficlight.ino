#include <Arduino.h>
#include <Adafruit_GFX.h>           // Core library for graphics (GFX)  & text 
#include "PL_smallLegio.h"          // Display-specific library for 4pigment media (Legio, 6colors)

#include "IMG_trafficLight_r.h"     // Imported image (as bytestream) from PL Image Inverter tool 
#include "IMG_trafficLight_y.h"     // Imported image (as bytestream) from PL Image Inverter tool 
#include "IMG_trafficLight_g.h"     // Imported image (as bytestream) from PL Image Inverter tool 
#include "IMG_trafficLight_ryg.h"     // Imported image (as bytestream) from PL Image Inverter tool 

#define EPD_RST     12
#define EPD_BUSY    9
#define EPD_CS      5
                                    // Declare 4pigment based EPD instance with 6 colors
PL_smallLegio epd(EPD_CS, EPD_RST, EPD_BUSY);   

void setup() {  
    SPI.begin();                    // SPI initialisation, UC8156 supp. max 10Mhz (writing) & 
    SPI.beginTransaction(SPISettings(6000000, MSBFIRST, SPI_MODE0));      // 6.6Mhz (reading)

    epd.begin(EPD_BLACK);           // EPD initialisation & ClearScreen

    epd.showImage(IMG_trafficLight_r);     // Load image byte stream and trigger an update
    delay(10000);

    epd.clearScreen(EPD_BLACK);     // ClearScreen
    epd.showImage(IMG_trafficLight_y);     // Load image byte stream and trigger an update
    delay(10000);

    epd.clearScreen(EPD_BLACK);     // ClearScreen
    epd.showImage(IMG_trafficLight_g);     // Load image byte stream and trigger an update
    delay(10000);
}

void loop() {       
}
