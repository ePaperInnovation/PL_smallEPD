Example 05_ShowImage
===============================================================

In this example we will learn how to upload and show our first own picture on the 2.1" Legio Epaper screen.

### Preparing a picture
With the program of your choice (e.g. [GIMP](https://www.gimp.org)), please prepare and save your own custom picture with the following conditions:
- Resolution: 240 x 146 pixels
- RGB color space (Red/Green/Blue): Red (255/0/0), Green (0/255/0), Yellow (255/255/0), Blue (0/0/255), Black (0/0/0), White(255/255/255)
- File format: PNG or BMP

### Converting the picture to a bytestream - PLImageConverter
Next we will convert the previously created picture to a bytestream in a .h-File, which can be directly added to the microntroller project. 

Please open the file in the [PLImageConverter tool ](https://www.plasticlogic.com/wp-content/uploads/SupportFiles/PLImageConverter.zip) and copy the newly created .h-File to your Arduino project folder.

### Loading the picture on the screen
Now please open the sketch **File > Examples > PL_smallEPD > Examples > 05_ShowImage** and add the name of your just added .h-File to the include section.

```cpp
#include "pic_name_xyz.h"            // Imported image (as bytestream) from PL Image Inverter tool 
```

That's it, after compiling and upload the new sketch you should see the picture on the screen.