//
//  Flip.cc
//  5 (FlipFish methods)
//
//  Created by Daniel Nilo on 11/7/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#include "Flip.h"
#include <cstdlib>
#include <cmath>
// Flip fish constructor with regular Fish (Fish.cc file) as superclass
FlipFish::FlipFish(double x, double y, double speed, double distance, double dir, double t_rate)
    : Fish (x, y, speed, distance), direction(dir), turn_rate(t_rate){
    
}

FlipFish::~FlipFish(){
    // Flip fish destructor
}

// Flip fish method (based on regular fish's method in last week's assignment)
void FlipFish::swim() {
    int choice = rand() % 3;
    if (choice == 0) {
        direction -= turn_rate;
    } else if (choice == 2) {
        direction += turn_rate;
    }
    x += speed * direction.getCos();
    y += speed * direction.getSin();
    distance = sqrt((x*x) + (y*y));
}
