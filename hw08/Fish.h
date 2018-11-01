//
//  Fish.h
//  7
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
    private:
        double x; /* x coordinate */
        double y; /* y coordinate */
        double speed;
        double distance;
        Angle direction; /* direction based on Angle.cc */
        Angle turn_rate; /* turn rate based on Angle.cc */
        Population* p; /* pointer to population pool */
    public:
        Fish(double x, double y, double speed, double distance, double dir, double t_rate, Population* p); /* constructor */
        virtual ~Fish(); /* destructor */
        Fish* next; /* points to next fish */
        void swim(); /* swim method */
        double getDistance() const; /* gets distance */
};

class DrunkFish : public Fish {
public:
    DrunkFish(double x, double y, double speed, double distance, double dir, double t_rate, Population* p);
    virtual void swim() const;
};
#endif /* Fish_h */
