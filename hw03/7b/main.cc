//
//  main.cc
//  7b (Swapping values of two variables)
//
//  Created by Daniel Nilo on 9/12/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#include <stdio.h>
#include "swap.h"

int main(int argc, const char * argv[]) {
    // Declare variables
    int a, b;
    
    // Call first integer
    printf("Enter an integer\n");
    scanf("%d", &a);
    printf("You entered %d\n", a);
    
    // Call second integer
    printf("Enter another integer\n");
    scanf("%d", &b);
    printf("You entered %d\n", b);
    
    // Call out swap function
    swap(&a, &b);
    
    // Print out
    printf("The values of the variables are %d %d\n", a, b);
}
