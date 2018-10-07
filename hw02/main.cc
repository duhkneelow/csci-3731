//
// main.cc
// hw02 (Declaring functions in header file) (Regrade)
//
// Created by Daniel Nilo on 10/6/18.
// Copyright © 2018 Daniel Nilo. All rights reserved.
//

#include <stdio.h>

// code to declare factorial function
#include "factorial.h"

int main(int argc, const char * argv[]) {
    // Declare variables
    int n;
    long f;
    
    // Prints and scans number put by user
    printf("Enter an integer: ");
    scanf("%d", &n);
    
    if (n < 0)
        printf("Please enter a positive integer!\n"); /* If statement when user puts num < 0 */
    else{ /* Factorial process */
        f = factorial(n);
        printf("%d! = %ld\n", n, f);
    }
}
