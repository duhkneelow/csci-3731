//
//  main.cc
//  7 (Making new angle numbers)
//
//  Created by Daniel Nilo on 10/17/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include "angle.h"

int main(int argc, const char * argv[]) {
    /* Declaring angle degrees */
    Angle a1(180);
    Angle a2(181);
    
    double d1 = 3.0; /* Declaring double for operators requiring it */
    
    /* Operator overloading necessities */
    Angle a11 = 5.0;
    Angle a13 = a11 + a2;
    
    Angle a3 = a1 + a2; /* + operator */
    
    /* More operator overloading necessities */
    Angle a12 = a3;
    Angle a14 = a12 * d1;
    
    Angle a4(a3); /* += operator */
    a4 += a2;
    
    Angle a5 = a1 - a2; /* - operator */
    
    Angle a6(a5); /* -= operator */
    a6 -= a2;
    
    Angle a7 = a1 * d1; /* * operator */
    
    Angle a8(a7); /* *= operator */
    a8 *= d1;
    
    Angle a9  = a1 / d1; /* / operator */
    
    Angle a10(a9); /* /= operator */
    a10 /= d1;
    
    a3.print(); /* prints out result for + operator */
    a4.print(); /* prints out result for += operator */
    a5.print(); /* prints out result for - operator */
    a6.print(); /* prints out result for -= operator */
    a7.print(); /* prints out result for * operator */
    a8.print(); /* prints out result for *= operator */
    a9.print(); /* prints out result for / operator */
    a10.print(); /* prints out result for /= operator */
    a13.print(); /* prints out result for + overloading operator */
    a14.print(); /* prints out result for * overloading operator */
    
    /* if statement to compare two angles */
    if (a1 == a2) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }
}
