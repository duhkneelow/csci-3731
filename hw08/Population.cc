//
//  Population.cc
//  7 (Population fish pool)
//
//  Created by Daniel Nilo on 10/24/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#include "Population.h"
#include "Fish.h"
#include <iostream>

#define max_fishes 1000 /* Maximum amount of fish in pool/population */

// Constructor
Population::Population(){
    num = 0;
    fishes = new Fish*[max_fishes];
}

// Destructor
Population::~Population(){
    delete[] fishes; /* For death of fish */
}

// Add method
void Population::add(Fish *f){
    fishes[num] = f;
    num++;
}

// Remove method
void Population::remove(int index){
    if(num>0){
        num--;
        for(int i=index; i<num; i++){
            fishes[i] = fishes [i+1];
        }
    }
    else std::cout<<"Population: 0"<<std::endl; /* When all fish die */
}

// Size method
int Population::size() const{
    return num;
}

// Supposed to be a get method for a fish
Fish* Population::get_fish(int index) const{
    return fishes[index];
}

// Supposed to be a get method for # of fish in population pool
int Population::get_index(Fish* f) const{
    for(int i=0;i<num;i++){
        if(fishes[i] == f) return i;
    }
    return -1;
}
