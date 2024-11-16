#include "config/coloredBitmap.h"
#include <string.h>

// Parameters:
//   w: width of the image
//   h: height of the image
//   unit: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value:
//   colored image size Bitmap (based on the unit passed parameter)
float coloredBitmap(int w, int h, char* unit) {
    // Each pixel of a colored Bitmap uses 24 bits (8 bits per color channel: R, G, B)
    const int bits_per_pixel = 24; 
    long long total_bits = (long long)w * h * bits_per_pixel;

    if (strcmp(unit, "bt") == 0) {
        // Return size in bits
        return (float)total_bits;
    } else if (strcmp(unit, "ko") == 0) {
        // Convert bits to kilobits: 1 kilobit = 1024 bits
        return (float)total_bits / 1024;
    } else if (strcmp(unit, "mo") == 0) {
        // Convert bits to megabits: 1 megabit = 1024 * 1024 bits
        return (float)total_bits / (1024 * 1024);
    } else if (strcmp(unit, "go") == 0) {
        // Convert bits to gigabits: 1 gigabit = 1024 * 1024 * 1024 bits
        return (float)total_bits / (1024 * 1024 * 1024);
    } else {
        // Invalid unit
        return -1;
    }
}
