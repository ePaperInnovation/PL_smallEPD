Example 05_ShowImage
===============================================================

In this example we will learn how to upload and show our first own picture on the 2.1" Legio Epaper screen.

### Prepare a picture
Please prepare and save your own custom picture with the following conditions:
- Resolution: 240 x 146 pixels
- RGB color space (Red/Green/Blue): Red (255/0/0), Green (0/255/0), Yellow (255/255/0), Blue (0/0/255), Black (0/0/0), White(255/255/255)
- File format: PNG or BMP

### Converting the picture to a bytestream - PLImageConverter
Next we will convert the previously created picture to a bytestream in a .h-File, which can be directly added to the microntroller project. 

Please open the file in the [PLImageConverter tool ](https://www.plasticlogic.com/wp-content/uploads/SupportFiles/PLImageConverter.zip) and copy the newly created .h-File to your Arduino project folder.

### Loading the picture on the screen
Please open the sketch **File > Examples > PL_smallEPD > Examples > 05_ShowImage** and add the name of your just added .h-File to the include section.

```cpp
#include "pic_name_xyz.h"            // Imported image (as bytestream) from PL Image Inverter tool 
```


License Information
-------------------
PL_smallEPD - A library for 1.1”, 1.4", 2.1" and 3.1" E-Paper displays (EPDs) from Plastic Logic 
based on UC8156 driver IC for Adafruit GFX core library. The communication is SPI-based, 
for more information about hook-up please check: https://github.com/plasticlogic/PL_smallEPD.

Created by Zhongke Dai & Robert Poser, Mar 30th 2021, Dresden/Germany. Released under BSD license
(3-clause BSD license), check license.md for more information.

