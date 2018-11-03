//
//  Drunk.cc
//  7 (DrunkFish methods)
//
//  Created by Daniel Nilo on 10/30/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#include "Drunk.h"
#include <cstdlib>
#include <cmath>
// Drunk fish constructor with Fish (based on regular Fish.cc file) as superclass
DrunkFish::DrunkFish(double x, double y, double speed, double distance, Population* p)
    : Fish (x, y, speed, distance, p) {
    
}

DrunkFish::~DrunkFish(){
    // Drunk fish destructor
}

// Drunk fish swim method (thanks Ed)
void DrunkFish::swim() {
    int choice = rand() % 4;
    if(choice == 0) x += speed;
    else if(choice == 1) y += speed;
    else if(choice == 2) x -= speed;
    else y -= speed;
    
    distance = sqrt((x*x) + (y*y));
}
