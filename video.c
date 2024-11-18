#include <string.h>
#include "config/video.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in seconds of the movie (colored image)
//   durationCredits: duration in seconds of credits (black/white image)
//   unit: Unit of the output value. It could be 'bt' for bytes, 'ko' for kilobits, 'mo' for megabits, 'go' for gigabits
// Return value
//   colored video size (based on the unit passed parameter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Bits per pixel for colored image (24 bits)
    int bitsPerPixel = 24;

    float clrImage = w * h * bitsPerPixel * durationMovie * fps;
    float BImage = w * h * durationCredits * fps;
    float sizeInBits = clrImage + BImage; // Add to total size in bits



    // Convert size based on the requested unit
    if (strcmp(unit, "bt") == 0) {
        return sizeInBits / 8; // Convert to bytes
    } else if (strcmp(unit, "ko") == 0) {
        return sizeInBits / (1024 * 8); // Convert to kilobits
    } else if (strcmp(unit, "mo") == 0) {
        return sizeInBits / (1024 * 1024 * 8); // Convert to megabits
    } else if (strcmp(unit, "go") == 0) {
        return sizeInBits / (1024 * 1024 * 1024 * 8); // Convert to gigabits
    } else {
        // If the unit is not recognized, return -1 or some error value
        return -1.0f;
    }
}
