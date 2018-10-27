//
//  Population.h
//  7
//
//  Created by Daniel Nilo on 10/24/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#ifndef Population_h
#define Population_h
#include <stdio.h>

class Fish;

class Population{
private:
    int num; /* number of fish */
    Fish** fishes; /* Array of pointers to fish */
    
public:
    Population(); /* constructor */
    virtual ~Population(); /* destructor */
    
    void add(Fish* f); /* (supposed to) add fish to population */
    void remove(int index); /* (supposed to) remove fish from population*/
    int size() const; /* population size */
    Fish* get_fish(int index) const; /* Fish info */
    int get_index(Fish* f) const; /* # of fish */
};

#endif /* Population_h */
