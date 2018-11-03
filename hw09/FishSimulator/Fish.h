//
//  Fish.h
//  7 (Regular fish class)
//
//  Created by Daniel Nilo on 10/24/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#ifndef Fish_h
#define Fish_h
#include "Angle.h"
#include <stdio.h>
class Angle;
class Population;

class Fish{
    protected:
        double x; /* x coordinate */
        double y; /* y coordinate */
        double speed;
        double distance;
        /* Angle direction; direction based on Angle.cc
        Angle turn_rate;  turn rate based on Angle.cc */
        Population* p; /* pointer to population pool */
    public:
        Fish(double x, double y, double speed, double distance, Population* p); /* constructor */
        virtual ~Fish(); /* destructor */
        Fish* next; /* points to next fish */
        virtual void swim()=0;  /*pure virtual swim method */
        double getDistance() const; /* gets distance */
};

#endif /* Fish_h */
