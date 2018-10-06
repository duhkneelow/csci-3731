//
//  main.cc
//  3 (Reading JPEG image files using libjpeg) (Shoutout to LuaDist)
//
//  Created by Daniel Nilo on 10/1/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#include <stdio.h>
#include <jpeglib.h>
#include <cstdlib>
#include <setjmp.h>
#include "print.h"

int main(int argc, const char * argv[]) {
    // Declare PPM attributes
    char magic[3];
    int width, height, maximum = 0;
    // Create array and point to it based on readPPM function
    int** p6 = readPPM(magic, &width, &height, &maximum);
    
    // Creates new image in JPEG version when p6 is not null
    if (p6 != NULL){
        writeJPEG(magic, width, height, maximum, 50, p6);
    }
    else{
        printf("What in the world are you doing?\n");
    }
    
    delete [] *p6;
    delete [] p6;
    p6 = NULL;
}
