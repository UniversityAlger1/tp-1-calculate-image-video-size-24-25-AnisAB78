#include <string.h>
#include "config/video.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in seconds of movie (colored section)
//   durationCredits: duration in seconds of credits (black-and-white section)
//   fps: Frames Per Second of the video
//   unit: Unit of the output value. It could be 'bt' for bits, 'ko' for kilobits, 'mo' for megabits, 'go' for gigabits
// Return value
//   size of the video in the specified unit
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
   // Calculate total frames for each section
   int color_frames = durationMovie * fps;
   int bw_frames = durationCredits * fps;

   // Calculate the size in bits for each section
   float color_size_bits = (float)(color_frames * w * h * 24);
   float bw_size_bits = (float)(bw_frames * w * h * 8);

   // Total video size in bits
   float total_size_bits = color_size_bits + bw_size_bits;

   // Convert total size to the specified unit
   if (strcmp(unit, "bt") == 0) {
       return total_size_bits;
   } else if (strcmp(unit, "ko") == 0) {
       return total_size_bits / 1024.0;
   } else if (strcmp(unit, "mo") == 0) {
       return total_size_bits / (1024.0 * 1024.0);
   } else if (strcmp(unit, "go") == 0) {
       return total_size_bits / (1024.0 * 1024.0 * 1024.0);
   } else {
       // If the unit is invalid, return 0 or handle as appropriate
       return 0;
   }
}
