//
//  main.cc
//  5 (Fish simulator with templates)
//
//  Created by Daniel Nilo on 11/7/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <cmath>
#include <typeinfo>
#include <vector>
#include "Angle.h"
#include "Drunk.h"
#include "Exception.h"
#include "Fish.h"
#include "Flip.h"
#include "Log.h"

int main(int argc, const char * argv[]) {
    const Log& log = Log::getInstance();
    log.print(""); /* Prints message based on method in Log.cc */
    std::vector<Fish*> p; /* Fish vector */
    // Fishes
    int amount = 50;
    int flipCount = 0;
    int drunkCount = 0;
    if (amount > 0) {
        for (int i = 0; i < amount; ++i) {
            // Fish generator
            Fish* f1 = new FlipFish(0.0, 0.0, 5.0, 0.0, 10.0, 30.0);
            p.push_back(f1);
            ++flipCount;
            Fish* f2 = new DrunkFish(0.0, 0.0, 5.0, 50.0);
            p.push_back(f2);
            ++drunkCount;
        }
    } else {
        throw Exception("There needs to be 1 fish in the pool.");
    }
    
    int time = 0; /* Declare time as integer */
    
    while(true){
        time++;
        std::cout<<"Time: "<<time<<std::endl; /* Time counter */
        
        for(std::vector<Fish*>::iterator it=p.begin(); it!=p.end(); ++it){
            (*it)->swim(); /* Fish's swim method */
        
            /* Indicates each fish and its distance */
            std::cout<<(*it)->getDistance()<<" = fish "<<(*it)<<" distance "<<"\n";
        
            /* Removes fish if distance is greater or equal to 100 */
            if((*it)->getDistance()>=100){
                p.erase(it);
                break;
            }
        }

        std::cout<< " " << std::endl;
        std::cout << "# of fish in pool: " << p.size() << std::endl;
        if(p.size()<=0) break; /* RIP fish (simulation ender if all fish die)*/
    }
    std::cout<<"RIP (November 9, 2018--)!"<<std::endl;
    return 0;
}
