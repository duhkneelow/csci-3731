//
//  Flip.h
//  5 (FlipFish header file)
//
//  Created by Daniel Nilo on 11/7/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#ifndef Flip_h
#define Flip_h
#include "Fish.h"
#include "Angle.h"

#include <stdio.h>

// FlipFish subclass of regular Fish
class FlipFish : public Fish {
public:
    FlipFish(double x, double y, double speed, double distance, double dir, double t_rate); // FlipFish constructor
    // Variables (direction and turn rate) based on Angle.h file
    Angle<double> direction;
    Angle<double> turn_rate;
    virtual ~FlipFish(); // FlipFish destructor
    void swim(); // FlipFish swim() method
};

#endif /* Flip_h */
