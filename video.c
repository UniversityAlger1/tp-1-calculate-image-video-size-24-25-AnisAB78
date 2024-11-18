#include "config/video.h"
#include <string.h>
#include <stdio.h>

// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in seconds of movie (colored section)
//   durationCredits: duration in seconds of credits (black-and-white section)
//   fps: Frames Per Second of the video
//   unit: Unit of the output value. It could be 'bt' for bits, 'ko' for kilobits, 'mo' for megabits, 'go' for gigabits
// Return value:
//   size of the video in the specified unit
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Number of bits per pixel for each section
    const int colorBitsPerPixel = 24; // RGB video (colored section)
    const int bwBitsPerPixel = 8;    // Black-and-white video (credits section)

    // Calculate total frames for each section
    int colorFrames = durationMovie * fps;
    int bwFrames = durationCredits * fps;

    // Calculate the size in bits for each section
    int colorSizeBits = colorFrames * w * h * colorBitsPerPixel;
    int bwSizeBits = bwFrames * w * h * bwBitsPerPixel;

    // Total video size in bits
    int totalSizeBits = colorSizeBits + bwSizeBits;

    // Variable to hold the size in the specified unit
    float size;

    // Convert total size to the specified unit
    if (strcmp(unit, "bt") == 0) {
        size = totalSizeBits; // Size in bits
    } else if (strcmp(unit, "ko") == 0) {
        size = totalSizeBits / (1024.0 * 8); // Size in kilobits
    } else if (strcmp(unit, "mo") == 0) {
        size = totalSizeBits / (1024.0 * 1024.0 * 8); // Size in megabits
    } else if (strcmp(unit, "go") == 0) {
        size = totalSizeBits / (1024.0 * 1024.0 * 1024.0 * 8); // Size in gigabits
    } else {
        // If the unit is not recognized, print an error and return -1
        printf("Invalid unit specified.\n");
        return -1;
    }

    return size; // Return the calculated size
}
