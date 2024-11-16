#include "config/video.h"
#include <string.h>

// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in seconds of the movie (colored image)
//   durationCredits: duration in seconds of the credits (black-and-white image)
//   fps: Frames Per Second of the video
//   unit: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value:
//   Total video size (based on the unit passed as a parameter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Constants for bit depths
    const int bits_per_pixel_color = 24; // Color image (RGB)
    const int bits_per_pixel_bw = 8;    // Black-and-white image

    // Calculate total number of frames for movie and credits
    long long total_frames_movie = (long long)durationMovie * fps;
    long long total_frames_credits = (long long)durationCredits * fps;

    // Calculate total bits for movie and credits
    long long total_bits_movie = (long long)w * h * bits_per_pixel_color * total_frames_movie;
    long long total_bits_credits = (long long)w * h * bits_per_pixel_bw * total_frames_credits;

    // Total size in bits
    long long total_bits = total_bits_movie + total_bits_credits;

    // Convert to the requested unit
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
