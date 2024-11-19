#include "config/video.h"
#include <string.h>
#include <stdio.h>

// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in seconds of movie (colored section)
//   durationCredits: duration in seconds of credits (black-and-white section)
//   fps: Frames Per Second of the video
//   unit: Unit of the output value. It could be 'bt' for bits, 'ko' for kilobytes, 'mo' for megabytes, 'go' for gigabytes
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
    long long colorSizeBits = (long long)colorFrames * w * h * colorBitsPerPixel;
    long long bwSizeBits = (long long)bwFrames * w * h * bwBitsPerPixel;

    // Total video size in bits
    long long totalSizeBits = colorSizeBits + bwSizeBits;

    // Variable to hold the size in the specified unit
    float size;

    // Convert total size to the specified unit
    if (strcmp(unit, "bt") == 0) {
        size = (float)totalSizeBits; // Size in bits
    } else if (strcmp(unit, "ko") == 0) {
        size = totalSizeBits / (8.0 * 1024); // Size in kilobytes
    } else if (strcmp(unit, "mo") == 0) {
        size = totalSizeBits / (8.0 * 1024 * 1024); // Size in megabytes
    } else if (strcmp(unit, "go") == 0) {
        size = totalSizeBits / (8.0 * 1024 * 1024 * 1024); // Size in gigabytes
    } else {
        // If the unit is not recognized, print an error and return -1
        printf("Invalid unit specified.\n");
        return -1;
    }

    return size; // Return the calculated size
}
