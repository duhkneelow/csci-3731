//
//  Flip.h
//  7 (FlipFish header file)
//
//  Created by Daniel Nilo on 11/1/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#ifndef Flip_h
#define Flip_h
#include "Fish.h"

#include <stdio.h>
class Population;
class Angle;

// FlipFish subclass of regular Fish
class FlipFish : public Fish {
public:
    FlipFish(double x, double y, double speed, double distance, double dir, double t_rate, Population* p); // FlipFish constructor
    // Variables (direction and turn rate) based on Angle.cc file
    Angle direction;
    Angle turn_rate;
    virtual ~FlipFish(); // FlipFish destructor
    void swim(); // FlipFish swim() method
};

#endif /* Flip_h */
