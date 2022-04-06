/* *****************************************************************************************
PL_smallEPD - A library for 1.1”, 1.4", 2.1" and 3.1" E-Paper displays (EPDs) from 
Plastic Logic based on UC8156 driver IC for Adafruit GFX core library. The communication is 
SPI-based, for more information about hook-up please check: https://github.com/plasticlogic.

Created by Robert Poser, Mar 30th 2021, Dresden/Germany. Released under BSD license
(3-clause BSD license), check license.md for more information.

We invested time and resources providing this open source code, please support Plasticlogic 
and open source hardware by purchasing this product @Plasticlogic
***************************************************************************************** */
#ifndef PL_smallEPD_h
#define PL_smallEPD_h

#include <Adafruit_GFX.h>         
#include <Adafruit_I2CDevice.h>
#include <SPI.h>

#define EPD_WIDTH   (146)
#define EPD_HEIGHT  (240)

 


#define EPD_BLACK 0x00
#define EPD_DGRAY 0x01
#define EPD_LGRAY 0x02
#define EPD_WHITE 0x03
#define EPD_COOVL 0xFF

#define EPD_UPD_FULL  0x00            // Triggers a Full update, 4 GL, 800ms
#define EPD_UPD_PART  0x01            // Triggers a Partial update, 4 GL, 800ms
#define EPD_UPD_MONO  0x02            // Triggers a Partial Mono update, 2 GL, 250ms
#define EPD_UPD_4GL_FULL    0x03      // Greyscale Full update, 4GL
#define EPD_UPD_4GL_PART    0x04      // Greyscale Partial update, 4GL
#define EPD_UPD_2GL_FULL    0x05      // Greyscale Full update, 2GL  
#define EPD_UPD_2GL_PART    0x06      // Greyscale Partial update, 4GL

#define EPD_UPD_GS0_TRAN    0x07      // Transparency Display Enable, Key Value GS0
#define EPD_UPD_GS1_TRAN    0x08      // Transparency Display Enable, Key Value GS1
#define EPD_UPD_GS2_TRAN    0x09      // Transparency Display Enable, Key Value GS2 
#define EPD_UPD_GS3_TRAN    0x0A      // Transparency Display Enable, Key Value GS3



#define EPD_REVISION          0x00  // Revision, Read only
#define EPD_PANELSETTING      0x01
#define EPD_DRIVERVOLTAGE     0x02
#define EPD_POWERCONTROL      0x03
#define EPD_BOOSTSETTING      0x04  
#define EPD_TCOMTIMING        0x06
#define EPD_INTTEMPERATURE    0x07
#define EPD_SETRESOLUTION     0x0C
#define EPD_WRITEPXRECTSET    0x0D
#define EPD_PIXELACESSPOS     0x0E
#define EPD_DATENTRYMODE      0x0F
#define EPD_DISPLAYENGINE     0x14
#define EPD_VCOMCONFIG        0x18
#define EPD_VCOMDCSETTING     0x1B
#define EPD_WAVEFORMSETTING   0x1C
#define EPD_BORDERSETTING     0x1D
#define EPD_POWERSEQUENCE     0x1F
#define EPD_SOFTWARERESET     0x20
#define EPD_PROGRAMMTP        0x40
#define EPD_MTPADDRESSSETTING 0x41
#define EPD_LOADMONOWF        0x44
#define EPD_REGREAD           0x80  

#define WAVEFORM_TYPE1        0x00  
#define WAVEFORM_TYPE2        0x02  

#define COLORTYPE_GREY        0x02
#define COLORTYPE_RED         0x08  
#define COLORTYPE_YELLOW      0x04  

#define SIZETYPE_11           0x08
#define SIZETYPE_14           0x04  
#define SIZETYPE_21           0x02  
#define SIZETYPE_31           0x01  

#define WAVEFORM_TRICOLOR_LENGTH      0x78  // waveform for tricolor length: 120 

extern int waveformType1_buffer[];
extern int waveformType2_buffer[];

class PL_smallEPD : public Adafruit_GFX {

public:
    PL_smallEPD(int8_t _cs, int8_t _rst=-1, int8_t _busy=-1);
    void begin(int8_t BGcolor=-1);
    void clear(byte c = EPD_WHITE, bool b2=false);
    virtual void clearScreen(int8_t BGcolor);
    void drawPixel(int16_t x, int16_t y, uint16_t color);
    void invert(bool b2=false);
    virtual void update(int updateMode=EPD_UPD_FULL, byte coovl=EPD_COOVL, bool manPow=false);
    void updateLectum(int updateMode=EPD_UPD_FULL, bool manPow=false);
    void setRotation(uint8_t o);
    void loadImg(const unsigned char *pic_name);
    void setVBorderColor(int color);
    void writeToPreviousBuffer();    
    uint8_t readTemperature(void);
    void deepSleep(void);
    int width, height;
    byte MAGICWORD;
    byte display_color;
    byte display_size;


    byte buffer[EPD_WIDTH * EPD_HEIGHT / 4];
    byte buffer2[EPD_WIDTH * EPD_HEIGHT / 4];

    void powerOn(void);
    void powerOff(void);
    void writeRegister(uint8_t address, int16_t val1, int16_t val2, int16_t val3, int16_t val4);
    void showImage(const unsigned char *pic_name, int updateMode = EPD_UPD_4GL_FULL, int colorType = COLORTYPE_GREY);
    void loadMAGICOWORD(const unsigned char *pic_name);
    void waveformTypeSetting(int waveform_type); 
    void colorRed(const unsigned char *pic_name, int updateMode);
    void colorRed_clear();
    void colorYellow(const unsigned char *pic_name, int updateMode);
    void setVcom(int vcom);
    void writeRegisterChar(uint8_t address, int *charbuffer, uint8_t size);


private:
    int _EPDsize, _buffersize;
    int cs, rst, busy;
    int cursorX, cursorY;
    int fontHeight=8, fontWidth=5;
    int nextline;
    byte getEPDsize(void);
    void waitForBusyInactive(void);
    byte readRegister(char address);
    int getPixel(int x, int y);
    void drawPixel2(int x, int y, int color);
    void scrambleBuffer(void);
    void writeBuffer(bool previous=false);
  };


#endif
