//
//  print.h
//  3 (Defining JPEG image functions using libjpeg) (Shoutout to LuaDist)
//
//  Created by Daniel Nilo on 10/1/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#ifndef print_h
#define print_h
// Defining functions to read and write image from PPM to JPEG
int** readPPM(char *magic, int *width, int *height, int *maximum);
void writeJPEG(char *magic, int width, int height, int maximum, int quality, int** p6);
#endif /* print_h */
