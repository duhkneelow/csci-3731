//
//  Drunk.h
//  7 (DrunkFish header file)
//
//  Created by Daniel Nilo on 10/30/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#ifndef Drunk_h
#define Drunk_h
#include "Fish.h"

#include <stdio.h>
class Population;

// DrunkFish subclass of regular Fish
class DrunkFish : public Fish {
public:
    DrunkFish(double x, double y, double speed, double distance, Population* p); // DrunkFish constructor
    virtual ~DrunkFish(); // DrunkFish destructor
    void swim(); // DrunkFish swim() method
};

#endif /* Drunk_h */
