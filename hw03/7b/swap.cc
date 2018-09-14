//
//  swap.cc
//  7b (Backbone of value swap)
//
//  Created by Daniel Nilo on 9/12/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#include "swap.h"

// Declare pointers
void swap (int* a, int* b){
    // Declare temp as int and set it to 0
    int temp = 0;
    // Store pointer a data in temp
    temp = *a;
    // Store pointer b data in pointer a data
    *a = *b;
    // Store temp in pointer b data
    *b = temp;
}
