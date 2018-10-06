//
//  print.cc
//  3 (Declaring JPEG image functions using libjpeg) (Shout out to LuaDist)
//
//  Created by Daniel Nilo on 10/1/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#include <stdio.h>
#include <jpeglib.h>
#include <cstdlib>
#include <setjmp.h>
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

// Declaring function to write image into JPEG
void writeJPEG(char *magic, int width, int height, int maximum, int quality, int** p6){
    struct jpeg_compress_struct cInfo; /* working space for JPEG */
    struct jpeg_error_mgr jError; /* handles JPEG errors */
    JSAMPROW row_pointer[1]; /* JSAMPLE row pointer */
    int row_stride; /* for image rows */
    
    
    FILE* fw = fopen("test2.jpg", "wb"); /* setup for file pointer */
    if (!fw) {
        fprintf(stderr, "cannot open %s\n", "test2.jpg");
        exit(1);
    }
    
    cInfo.err = jpeg_std_error(&jError); /* sets up handler errors */
    jpeg_create_compress(&cInfo); /* initalizes compressing image object */
    jpeg_stdio_dest(&cInfo, fw); /* tells compressor about image file */
    
    cInfo.image_width = width; // width of image
    cInfo.image_height = height; // height of image
    cInfo.input_components = 3; // for RGB pixels
    cInfo.in_color_space = JCS_RGB; // Yay for color space!
    
    jpeg_set_defaults(&cInfo); // for default compression parameters
    jpeg_set_quality(&cInfo, quality, TRUE); //sets quality compression parameters
    
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
    
    jpeg_start_compress(&cInfo, TRUE); // starts compressing process
    
    row_stride = width * 3; // JSAMPLEs per row
    
    
    // Creates image in JPEG format
    while(cInfo.next_scanline < cInfo.image_height) {
        row_pointer[0] = (JSAMPROW) &array[cInfo.next_scanline * row_stride];
        jpeg_write_scanlines(&cInfo, row_pointer, 1);
    }
    
    jpeg_finish_compress(&cInfo); /* Finishes compressing image */
    fclose(fw); /* Closes file */
    jpeg_destroy_compress(&cInfo); /* Destroys compessing process */
}
