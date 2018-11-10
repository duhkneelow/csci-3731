//
//  Fish.h
//  5 (Regular fish class)
//
//  Created by Daniel Nilo on 11/7/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#ifndef Fish_h
#define Fish_h
#include <stdio.h>

class Fish{
    protected:
        double x; /* x coordinate */
        double y; /* y coordinate */
        double speed;
        double distance;
    public:
        Fish(double x, double y, double speed, double distance); /* constructor */
        virtual ~Fish(); /* destructor */
        virtual void swim()=0;  /*pure virtual swim method */
        double getDistance() const; /* gets distance */
};

#endif /* Fish_h */
