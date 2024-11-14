#include <string.h>
#include "config/coloredBitmap.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   unit: Unit of the output value. It could be 'bt' for bits, 'ko' for kilobits, 'mo' for megabits, or 'go' for gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parameter)
float coloredBitmap(int w, int h, char* unit) {
   // Calculate the size in bits (24 bits per pixel)
   float size_in_bits = (float)(w * h * 24);

   // Convert size to the specified unit
   if (strcmp(unit, "bt") == 0) {
       return size_in_bits;
   } else if (strcmp(unit, "ko") == 0) {
       return size_in_bits / 1024.0;
   } else if (strcmp(unit, "mo") == 0) {
       return size_in_bits / (1024.0 * 1024.0);
   } else if (strcmp(unit, "go") == 0) {
       return size_in_bits / (1024.0 * 1024.0 * 1024.0);
   } else {
       // If the unit is invalid, return 0 or handle as appropriate
       return 0;
   }
}
