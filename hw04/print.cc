//
//  print.cc
//  6 (Declaring PPM image functions)
//
//  Created by Daniel Nilo on 9/19/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#include <stdio.h>
#include "print.h"

// Declaring function to read PPM image
char* readPPM(char *magic, int *width, int *height, int *maximum){
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
    // Returns the array
    return p6;
}

// Declaring function to write PPM image
void writePPM(char *magic, int *width, int *height, int *maximum, char *p6){
    // Creates another PPM image called test2.ppm
    FILE* fw = fopen("test2.ppm", "wb");
    int size = *width * *height * 3;
    // Prints out attributes
    fprintf(fw, "%s %d %d %d\n", magic, *width, *height, *maximum);
    // Writes out PPM image size
    fwrite(p6, sizeof(char), size, fw);
    // Closes file
    fclose(fw);
}
