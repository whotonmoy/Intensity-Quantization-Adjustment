# Intensity-Quantization-Adjustment
Intensity Quantization Adjustment for Grayscale Image: Enhancing Image Quality

It is a program that reads “rose.raw” as the input image; change the intensity quantization level; and save the new image into a new file in raw format. The original image uses 8 bits per pixel, thus having 256 intensity levels. 

The program has been tested by converting intensity level to the following 4 new levels respectively:
1. 128 levels (by setting the least significant bit of each pixel to 0) e.g. if a pixel’s original value in binary is 10110101, the new value will be 10110100.
2. 64 levels (by setting the two least significant bits of each pixel to 0’s)
3. 32 levels (by setting the three least significant bits of each pixel to 0’s)
4. 16 levels (by setting the four least significant bits of each pixel to 0’s)

This was an assignment that I did in my second to last semester(Winter 2023) for Image Processing Course (CS 425).