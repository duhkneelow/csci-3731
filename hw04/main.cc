//
//  main.cc
//  6 (Reading PPM image files)
//
//  Created by Daniel Nilo on 9/19/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#include <stdio.h>
#include "print.h"

int main(int argc, const char * argv[]) {
    // Declare PPM attributes
    char magic[2];
    int width, height, maximum, size = 0;
    // Create array and point to it based on readPPM function
    char *p6 = readPPM(magic, &width, &height, &maximum, &size);
    
    // If statement if not PPM image
    if (p6 == NULL){
        printf("What file is this?");
    }
    else {
        // Otherwise, codes to print out PPM image attributes
        printf("Width= %d, Height= %d\n", width, height);
        printf("Maximum pixel number= %d\n", maximum);
        printf("Size of image= %d\n\n", size);
        
        // Codes to indicate PPM image being copied
        printf("Copying image:\n");
        writePPM(magic, &width, &height, &maximum, &size, p6);
        printf("New image created!\n");
    }
}
