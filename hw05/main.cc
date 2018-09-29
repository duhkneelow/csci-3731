//
//  main.cc
//  6 (Reading PPM image files using 2d arrays)
//
//  Created by Daniel Nilo on 9/24/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#include <stdio.h>
#include "print.h"

int main(int argc, const char * argv[]) {
    // Declare PPM attributes
    char magic[3];
    int width, height, maximum = 0;
    // Create array and point to it based on readPPM function
    int** p6 = readPPM(magic, &width, &height, &maximum);
    
    // Creates new image when p6 is not null
    if (p6 != NULL){
        // Codes to print out PPM image attributes
        printf("Image type= %s\n", magic);
        printf("Width= %d, Height= %d\n", width, height);
        printf("Maximum pixel number= %d\n", maximum);
        
        // Codes to indicate PPM image being copied
        printf("Copying image:\n");
        writePPM(magic, width, height, maximum, p6);
        printf("New image created!\n");
    }
    else{
        printf("What in the world are you doing?"\n);
    }
    
    delete [] *p6;
    delete [] p6;
    p6 = NULL;
}
