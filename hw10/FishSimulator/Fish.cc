//
//  Fish.cc
//  5 (Regular Fish methods)
//
//  Created by Daniel Nilo on 11/7/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#include "Fish.h"
#include <cstdlib>
#include <cmath>

// Fish constructor
Fish::Fish(double x, double y, double speed, double distance){
    this->x = x;
    this->y = y;
    this->speed = speed;
    this->distance = distance;
}

Fish::~Fish() {
  // Fish destructor
}

/* Swim method (thank you Ed)
void Fish::swim() {
    int choice = rand() % 3;
    if (choice == 0) {
        direction -= turn_rate;
    } else if (choice == 2) {
        direction += turn_rate;
    }
    x += speed * direction.getCos();
    y += speed * direction.getSin();
    distance = sqrt((x*x) + (y*y)); // Distance calculation of fish
}*/

// getDistance() method
double Fish::getDistance() const {
    return distance;
}
