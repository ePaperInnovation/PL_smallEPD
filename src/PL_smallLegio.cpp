/* *****************************************************************************************
PL_smallEPD - A library for 1.1”, 1.4", 2.1" and 3.1" E-Paper displays (EPDs) from 
Plastic Logic based on UC8156 driver IC for Adafruit GFX core library. The communication is 
SPI-based, for more information about hook-up please check: https://github.com/plasticlogic.

Created by Robert Poser, Mar 30th 2021, Dresden/Germany. Released under BSD license
(3-clause BSD license), check license.md for more information.

We invested time and resources providing this open source code, please support Plasticlogic 
and open source hardware by purchasing this product @Plasticlogic
***************************************************************************************** */
#include "PL_smallLegio.h"

PL_smallLegio::PL_smallLegio(int8_t _cs, int8_t _rst, int8_t _busy) : PL_smallEPD(_cs, _rst, _busy) {
    cs = _cs;
    rst = _rst;
    busy = _busy;
}

void PL_smallLegio::clearScreen(int8_t BGcolor) {
    if (BGcolor>=0) {  
        setSourceVoltage(15000);
        powerOn();
        for (int i = 0; i < 3; i++) {
            clear(EPD_WHITE);
            setTPCOM(+12000);
            updateLectum(EPD_UPD_FULL, true);
            delay(1);
            clear(EPD_BLACK);
            setTPCOM(-18000);
            updateLectum(EPD_UPD_FULL, true);
            delay(1);
        }
        clear(EPD_BLACK); //BLACK
        setTPCOM(-15000);
        updateLectum(EPD_UPD_FULL, true);
        delay(1);
        clear(EPD_BLACK);
        setTPCOM(-15000);
        updateLectum(EPD_UPD_FULL, true);
        delay(1);
        if (BGcolor == EPD_WHITE) {
            clear(EPD_WHITE);
            updateLegio(EPD_BLACK);
        }
        clear(EPD_BLACK);
        if (BGcolor == EPD_YELLOW)
            updateLegio(EPD_YELLOW);
        if (BGcolor == EPD_GREEN) {
            updateLegio(EPD_YELLOW);
            clear(EPD_BLACK);
            updateLegio(EPD_GREEN);
        }
        if (BGcolor == EPD_RED)
            updateLegio(EPD_RED);
        if (BGcolor == EPD_BLUE) {
            clear(EPD_WHITE);
            updateLegio(EPD_BLACK);
            clear(EPD_BLACK);
            updateLegio(EPD_BLUE);
        }
        clear(EPD_WHITE);
        powerOff();
    }
}

void PL_smallLegio::loadImage(const unsigned char *pic_name, int BUFFER_COLOR_START) {
    for (uint16_t j = 0; j < sizeof(buffer); j++)
        buffer[j] = pgm_read_byte_near(pic_name + BUFFER_COLOR_START + j);
}

void PL_smallLegio::showImage(const unsigned char *pic_name) {
    if ((byte)pic_name[3] & 0x80) {
        loadImage(pic_name, BUFFER_BW_START);
        updateLegio(EPD_BLACK);
    }
    if ((byte)pic_name[3] & 0x40) {
        loadImage(pic_name, BUFFER_YELLOW_START);
        updateLegio(EPD_YELLOW);
    }
    if ((byte)pic_name[3] & 0x20) {
        loadImage(pic_name, BUFFER_GREEN_START);
        updateLegio(EPD_GREEN);
    }
    if ((byte)pic_name[3] & 0x10) {
        loadImage(pic_name, BUFFER_RED_START);
        updateLegio(EPD_RED);
    }
    if ((byte)pic_name[3] & 0x08) {
        loadImage(pic_name, BUFFER_BLUE_START);
        updateLegio(EPD_BLUE);
    }
}

void PL_smallLegio::setTPCOM(int v, bool VkbConsidered) {
    if (v >= -2800)
        writeRegister(0x1B, lowByte((v + 2800) / 30), highByte((v + 2800) / 30), -1, -1);
    else
        writeRegister(0x1B, lowByte((v + 2800) / 30 * (-1)), highByte((v + 2800) / 30 * (-1)) | 4, -1, -1);
    
}

void PL_smallLegio::setSourceVoltage(int v) {
    v = round(v / 1000);
    int x = (v - 8) / 1 * 2 << 4;
    x = x | (v - 8) / 1 * 2;
    writeRegister(EPD_DRIVERVOLTAGE, 0x25, x, -1, -1);
}

void PL_smallLegio::update(int updateMode, byte coovl, bool manPow) {
    updateLegio(EPD_BLACK);
}

void PL_smallLegio::updateLegio(byte color) {
    //powerOn();
    switch (color) {
    case EPD_BLACK: // BLACK & WHITE --> +13V/-13V
        setTPCOM(0);
        setSourceVoltage(13000);
        /*      invert();
      for (int i=0; i<1; i++) {
            clear(EPD_LGRAY, true);                        
            writeToPreviousBuffer();
            update(EPD_UPD_FULL);
            delay(1);    
      }
      invert();
*/
        for (int i = 0; i < 3; i++) {
            clear(EPD_LGRAY, true);
            writeToPreviousBuffer();
            updateLectum(EPD_UPD_FULL);
            delay(1);
        }
        break;
    case EPD_YELLOW: // YELLOW    --> 0V/+30V
        setTPCOM(15000);
        setSourceVoltage(15000);
        for (int i = 0; i < 3; i++) {
            clear(EPD_LGRAY, true);
            writeToPreviousBuffer();
            invert();
            updateLectum(EPD_UPD_FULL);
            invert();
        }
        break;
    case EPD_GREEN: // GREEN     --> +11V/-11V
        setTPCOM(0);
        setSourceVoltage(12000);
        clear(EPD_WHITE, true);
        writeToPreviousBuffer();
        updateLectum(EPD_UPD_FULL);
        delay(1);
        break;
    case EPD_RED: // RED
        setSourceVoltage(10000);
        for (int i = 0; i < 2; i++) {
            clear(EPD_LGRAY, true);
            writeToPreviousBuffer();
            invert();
            setTPCOM(10000);
            updateLectum(EPD_UPD_MONO);
            invert();
            delay(10);
            clear(EPD_LGRAY, true);
            writeToPreviousBuffer();
            setTPCOM(-10000);
            updateLectum(EPD_UPD_MONO);
            delay(10);
        }
        break;
    case EPD_BLUE:
        for (int i = 0; i < 2; i++) {
            clear(EPD_LGRAY, true);
            writeToPreviousBuffer();
            setTPCOM(-12000);
            setSourceVoltage(12000);
            updateLectum(EPD_UPD_MONO);
            delay(1);
            clear(EPD_LGRAY, true);
            invert();
            writeToPreviousBuffer();
            setTPCOM(12000);
            setSourceVoltage(12000);
            updateLectum(EPD_UPD_MONO);
            invert();
            delay(1);
        }
        setSourceVoltage(12000);
        setTPCOM(-12000);
        for (int i = 0; i < 2; i++) {
            clear(EPD_LGRAY, true);
            writeToPreviousBuffer();
            updateLectum(EPD_UPD_MONO);
            delay(1);
        }
        break;
    }
    //powerOff();
    delay(1);
}
