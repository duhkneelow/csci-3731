//
//  print.h
//  6 (Defining PPM image functions using 2d arrays)
//
//  Created by Daniel Nilo on 9/24/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#ifndef print_h
#define print_h
// Defining functions to read and write PPM image
int** readPPM(char *magic, int *width, int *height, int *maximum);
void writePPM(char *magic, int width, int height, int maximum, int** p6);
#endif /* print_h */
