#include "config/video.h"
#include <string.h>

float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Calculate the number of frames in each section
    int framesMovie = durationMovie * fps;
    int framesCredits = durationCredits * fps;

    // Calculate the size in bytes for each section
    int frameSizeColor = w * h * 3;     // 3 bytes per pixel for color
    int frameSizeBW = w * h * 1;        // 1 byte per pixel for black-and-white

    // Total size in bytes for each section
    long long sizeColor = (long long)framesMovie * frameSizeColor;
    long long sizeBW = (long long)framesCredits * frameSizeBW;

    // Total size in bytes
    long long totalSizeBytes = sizeColor + sizeBW;

    // Convert to the desired unit
    float convertedSize = 0.0;
    if (strcmp(unit, "bt") == 0) {
        convertedSize = (float)totalSizeBytes; // Bytes
    } else if (strcmp(unit, "ko") == 0) {
        convertedSize = (float)totalSizeBytes / 1024; // Kilobytes
    } else if (strcmp(unit, "mo") == 0) {
        convertedSize = (float)totalSizeBytes / (1024 * 1024); // Megabytes
    } else if (strcmp(unit, "go") == 0) {
        convertedSize = (float)totalSizeBytes / (1024 * 1024 * 1024); // Gigabytes
    }

    return convertedSize;
}
