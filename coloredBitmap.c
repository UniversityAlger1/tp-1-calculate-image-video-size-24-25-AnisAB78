#include "config/coloredBitmap.h"
#include <string.h>
#include <stdio.h>

// Parameters:
//   w: width of the image
//   h: height of the image
//   unit: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parameter)
float coloredBitmap(int w, int h, char* unit) {
    // Determine the number of bits per pixel (assuming 24 bits for RGB)
    int bitsPerPixel = 24;

    // Calculate the total number of bits
    int totalBits = w * h * bitsPerPixel;

    // Variable to hold the size in the specified unit
    float size;

    // Determine the size based on the unit
    if (strcmp(unit, "bt") == 0) {
        size = totalBits; // Size in bits
    } else if (strcmp(unit, "ko") == 0) {
        size = totalBits / (1024.0 * 8); // Size in kilobits
    } else if (strcmp(unit, "mo") == 0) {
        size = totalBits / (1024.0 * 1024.0 * 8); // Size in megabits
    } else if (strcmp(unit, "go") == 0) {
        size = totalBits / (1024.0 * 1024.0 * 1024.0 * 8); // Size in gigabits
    } else {
        // If the unit is not recognized, return -1 as an error code
        printf("Invalid unit specified.\n");
        return -1;
    }

    return size; // Return the calculated size
}
