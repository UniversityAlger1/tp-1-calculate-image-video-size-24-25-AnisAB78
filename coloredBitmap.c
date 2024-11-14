#include "config/coloredBitmap.h"
#include <string.h>

float coloredBitmap(int w, int h, char* unit) {
    // Calculate the total size in bits (24 bits per pixel for color)
    long long totalSizeBits = (long long)w * h * 24;

    // Convert the size to the desired unit
    float convertedSize = 0.0;
    if (strcmp(unit, "bt") == 0) {
        convertedSize = (float)totalSizeBits; // Bits
    } else if (strcmp(unit, "ko") == 0) {
        convertedSize = (float)totalSizeBits / 1024; // Kilobits
    } else if (strcmp(unit, "mo") == 0) {
        convertedSize = (float)totalSizeBits / (1024 * 1024); // Megabits
    } else if (strcmp(unit, "go") == 0) {
        convertedSize = (float)totalSizeBits / (1024 * 1024 * 1024); // Gigabits
    }

    return convertedSize;
}
