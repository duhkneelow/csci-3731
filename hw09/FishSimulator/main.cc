//
//  main.cc
//  7 (Hopefully a fish simulator)
//
//  Created by Daniel Nilo on 10/24/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <cmath>
#include "Angle.h"
#include "Drunk.h"
#include "Exception.h"
#include "Fish.h"
#include "Flip.h"
#include "Population.h"
#include "Log.h"

int main(int argc, const char * argv[]) {
    const Log& log = Log::getInstance();
    log.print(""); /* Prints message based on method in Log.cc */
    Population p; /* Declare population variable */
    // Fishes
    int amount = 100;
    int flipCount = 0;
    int drunkCount = 0;
    if (amount > 0) {
        for (int i = 0; i < amount; ++i) {
            Fish* f1 = new FlipFish(0.0, 0.0, 5.0, 0.0, 10.0, 30.0, &p);
            ++flipCount;
            Fish* f2 = new DrunkFish(0.0, 0.0, 5.0, 50.0, &p);
            ++drunkCount;
        }
    } else {
        throw Exception("There needs to be 1 fish in the pool.");
    }
    
    int time = 0; /* Declare time as integer */
    
    while(true){
        time++;
        std::cout<<"Time: "<<time<<std::endl; /* Time counter */
        
        for(int i=0; i<p.size(); i++){
            std::cout<< p.get_fish(i)->getDistance()<<" = fish " << p.get_fish(i) <<" distance "<<"\n";
            p.get_fish(i)->swim(); /* Swimming fish (just keep swimming) */
            
            /* Returns distance in getDistance() method from Fish.cc */
            if(p.get_fish(i)->getDistance()>=100){
                /*std::cout<< p.get_fish(i) <<" is dead in "<< time << " minutes" << std::endl;*/
                const std::type_info& type = typeid(p.get_fish(i));
                if (type == typeid(DrunkFish)) {
                    --drunkCount;
                }
                else {
                    --flipCount;
                }
                p.remove(i);
            }
        }
        std::cout<< " " << std::endl;
        std::cout << "# of fish in pool: " << p.size() << std::endl;
        if(p.size()<=0) break; /* RIP fish */
    }
    std::cout<<"RIP (November 1, 2018--)!"<<std::endl;
    return 0;
}
