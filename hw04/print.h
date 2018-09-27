//
//  print.h
//  6 (Defining PPM image functions)
//
//  Created by Daniel Nilo on 9/19/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#ifndef print_h
#define print_h
// Defining functions to read and write PPM image
char* readPPM(char *magic, int *width, int *height, int *maximum);
void writePPM(char *magic, int *width, int *height, int *maximum, char *p6);
#endif /* print_h */
