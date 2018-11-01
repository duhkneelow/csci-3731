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
#include <cmath>
#include "Angle.h"
#include "Fish.h"
#include "Population.h"
#include "Log.h"

int main(int argc, const char * argv[]) {
    const Log& log = Log::getInstance();
    log.print(""); /* Prints message based on method in Log.cc */
    Population p; /* Declare population variable */
    // Fishes
    Fish* f1 = new Fish(0.0, 0.0, 5.0, 0.0, 10.0, 30.0, &p);
    Fish* f2 = new Fish(0.0, 0.0, 5.0, 50.0, 90.0, 50.0, &p);
    p.add(f1);
    p.add(f2);
    
    int time = 0; /* Declare time as integer */
    std::cout<<"Fish #1 start position: "<<f1->getDistance()<<std::endl; /* Fish #1 starting position */
    std::cout<<"Fish #2 start position: "<<f2->getDistance()<<std::endl; /* Fish #2 starting position */
    
    while(true){
        time++;
        std::cout<<"Time: "<<time<<std::endl; /* Time counter */
        
        for(int i=0; i<p.size(); i++){
            std::cout<< p.get_fish(i)->getDistance()<<" = fish " << p.get_fish(i) <<" distance "<<"\n";
            p.get_fish(i)->swim(); /* Swimming fish (just keep swimming) */
            
            /* Supposed to return distance in getDistance() method from Fish.cc */
            if(p.get_fish(i)->getDistance()>=100){
                std::cout<< p.get_fish(i) <<" is dead in "<< time << " minutes" << std::endl;
                p.remove(i);
            }
        }
        std::cout<< " " << std::endl;
        std::cout << "# of fish in pool: " << p.size() << std::endl;
        if(p.size()<=0) break; /* RIP fish */
    }
    std::cout<<"RIP (October 26, 2018--)!"<<std::endl;
    return 0;
}
