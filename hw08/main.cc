//
//  main.cc
//  7 (What is supposed to be an aquarium full of fish)
//
//  Created by Daniel Nilo on 10/24/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include "Angle.h"
#include "Fish.h"
#include "Population.h"
#include "Log.h"

int main(int argc, const char * argv[]) {
    const Log& log = Log::getInstance();
    log.print(""); /* Prints message based on method in Log.cc */
    Population p; /* Declare population variable */
    // Fishes
    Fish* f1 = new Fish(0.0, 0.0, 5.0, 0.0, Angle(0), Angle(0), &p);
    Fish* f2 = new Fish(0.0, 0.0, 5.0, 50.0,  Angle(0), Angle(0), &p);
    
    int time = 0; /* Declare time as integer */
    for(int i=0; i<p.size(); i++){
        std::cout<< &f1 <<std::endl; /* Supposed to be for fish's starting position */
        std::cout<< &f2 <<std::endl;
    }
    
    while(true){
        time++;
        std::cout<<"Time: "<<time<<std::endl; /* Time counter */
        
        for(int i=0; i<p.size(); i++){
            p.get_fish(i)->swim(); /* Swimming fish (just keep swimming) */
        }
        
        for(int i=0; i<p.size(); i++){
            std::cout<< p.get_fish(i) <<std::endl; /* Supposed to be new position for fish */
        }
        
        for(int i=0; i<p.size(); i++){
            Fish* fish = p.get_fish(i);
            /* Supposed to return distance in getDistance() method from Fish.cc */
            if(fish->getDistance()>=100){
                std::cout<< "" << &f1 <<" is dead"<<std::endl;
                std::cout<< "" << &f2 <<" is dead"<<std::endl;
                delete &f1;
                delete &f2;
            }
        }
        if(p.size()<=0) break; /* RIP fish */
        
    }
    std::cout<<"RIP (October 26, 2018--)!"<<std::endl;
    
    return 0;
}
