/* *****************************************************************************************
PL_smallEPD - A library for 1.1”, 1.4", 2.1" and 3.1" E-Paper displays (EPDs) from 
Plastic Logic based on UC8156 driver IC for Adafruit GFX core library. The communication is 
SPI-based, for more information about hook-up please check: https://github.com/plasticlogic.

Created by Robert Poser, Mar 30th 2021, Dresden/Germany. Released under BSD license
(3-clause BSD license), check license.md for more information.

We invested time and resources providing this open source code, please support Plasticlogic 
and open source hardware by purchasing this product @Plasticlogic
***************************************************************************************** */
#ifndef PL_smallLegio_h
#define PL_smallLegio_h

#include "PL_smallEPD.h"
#include <Adafruit_GFX.h> 

#define EPD_YELLOW  0x04
#define EPD_GREEN   0x05
#define EPD_RED     0x06
#define EPD_BLUE    0x07

#define BUFFER_BW_START       0x0A
#define BUFFER_YELLOW_START   0x2242  
#define BUFFER_GREEN_START    0x447A  
#define BUFFER_RED_START      0x66B2  
#define BUFFER_BLUE_START     0x88EA   

class PL_smallLegio : public PL_smallEPD {

public:
    PL_smallLegio(int8_t _cs, int8_t _rst, int8_t _busy);
    void clearScreen(int8_t BGcolor);
    void showImage(const unsigned char *pic_name); 
    void loadImage(const unsigned char *pic_name, int BUFFER_COLOR_START=BUFFER_BW_START);
    void setSourceVoltage(int v);
    void setTPCOM(int v, bool VkbConsidered=false);
    void update(int updateMode=EPD_UPD_FULL, byte coovl=EPD_COOVL, bool manPow=false);
    void updateLegio(byte color);


private:
    int cs, rst, busy;
};

#endif
