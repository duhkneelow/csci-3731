//
// factorial.cc
// hw02 (Defining factorial function) (Regrade!)
//
// Created by Daniel Nilo on 10/6/18.
// Copyright © 2018 Daniel Nilo. All rights reserved.
//

// include header file for consistency with definition and declaration
#include "factorial.h"

// code to define factorial function
long factorial(int n){
    if (n == 0)
        return 1;
    else
        return(n * factorial(n-1));
}
