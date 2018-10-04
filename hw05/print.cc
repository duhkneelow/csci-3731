//
//  print.cc
//  6 (Declaring PPM image functions using 2d arrays)
//
//  Created by Daniel Nilo on 9/24/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#include <stdio.h>
#include "print.h"

// Declaring function to read PPM image
int** readPPM(char *magic, int *width, int *height, int *maximum){
    // Opens and reads PPM image
    FILE* fp = fopen("test.ppm", "rb");
    
    // Reads PPM attributes
    fscanf(fp, "%s %d %d %d\n", magic, width, height, maximum);
    // If statement for indicating PPM image
    if(magic[0] != 'P' && magic[1] != '6'){
        printf("The image is NOT in ppm format!\n");
        return NULL;
    }

    // Figures out size of image
    int size = *width * *height * 3;
    // Code to allocate array for pixels of PPM image
    char* p6 = new char[size];
    // Reads PPM image size
    fread(p6, sizeof(char), size, fp);
    // Closes file
    fclose(fp);
    // Allocate two-dimensional array
    int** array = new int*[*height];
    *array = new int[*width * *height];
    for(int i=1; i<*height; ++i){
        array[i] = array[i-1] + *width;
    }
    printf("Completed reading in ppm file!\n");
    // Write loop for pixels
    for (int i=0; i<*width * *height; ++i){
        unsigned char* byte = (unsigned char*)(*array+i);
        printf("Pointer to each int, i: %d\n", i);
        byte[0] = (char) 255;
        byte[1] = p6[i*3];
        byte[2] = p6[(i*3)+1];
        byte[3] = p6[(i*3)+2];
    }
    // Returns the array
    printf("returning the 2d array...\n");
    return array;
}

// Declaring function to write PPM image
void writePPM(char *magic, int width, int height, int maximum, int** p6){
    // Creates another PPM image called test2.ppm
    FILE* fw = fopen("test2.ppm", "wb");
    // Declare size
    int size = width * height * 3;
    // Code for array of chars
    unsigned char* array = new unsigned char[size];
    // Copying two-dimensional array into one-dimensional array
    int* flat = *p6;
    int n = width * height;
    // Storing into char array
    for (int i = 0; i < n; ++i) {
        unsigned char* byte = (unsigned char*)(flat + i);
        array[i * 3] = byte[1];
        array[(i * 3) + 1] = byte[2];
        array[(i * 3) + 2] = byte[3];
    }
    // Prints out attributes
    fprintf(fw, "%s %d %d %d\n", magic, width, height, maximum);
    // Writes out PPM image size
    fwrite(array, sizeof(char), size, fw);
    // Closes file
    fclose(fw);
}
