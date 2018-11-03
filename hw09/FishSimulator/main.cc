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
    // Fishes (I know you wanted me to use a for loop, but when I used it, I had the same issue where I had no fish after the time was at 1 when I ran my code from last week's assignment)
    Fish* f1 = new FlipFish(0.0, 0.0, 5.0, 10.0, 20.0, 31.0, &p);
    Fish* f2 = new FlipFish(0.0, 0.0, 10.0, 5.0, 13.0, 33.0, &p);
    Fish* f3 = new FlipFish(0.0, 0.0, 15.0, 1.0, 26.0, 40.0, &p);
    Fish* f4 = new FlipFish(0.0, 0.0, 20.0, 12.0, 19.0, 22.0, &p);
    Fish* f5 = new FlipFish(0.0, 0.0, 25.0, 13.0, 21.0, 24.0, &p);
    Fish* f6 = new DrunkFish(0.0, 0.0, 5.0, 10.0, &p);
    Fish* f7 = new DrunkFish(0.0, 0.0, 10.0, 25.0, &p);
    Fish* f8 = new DrunkFish(0.0, 0.0, 15.0, 50.0, &p);
    Fish* f9 = new DrunkFish(0.0, 0.0, 20.0, 75.0, &p);
    Fish* f10 = new DrunkFish(0.0, 0.0, 25.0, 90.0, &p);
    p.add(f1);
    p.add(f2);
    p.add(f3);
    p.add(f4);
    p.add(f5);
    p.add(f6);
    p.add(f7);
    p.add(f8);
    p.add(f9);
    p.add(f10);
    
    int time = 0; /* Declare time as integer */
    // Flip and drunk fish starting positions
    std::cout<<"Flip fish #1 start position: "<<f1->getDistance()<<std::endl;
    std::cout<<"Flip fish #2 start position: "<<f2->getDistance()<<std::endl;
    std::cout<<"Flip fish #3 start position: "<<f3->getDistance()<<std::endl;
    std::cout<<"Flip fish #4 start position: "<<f4->getDistance()<<std::endl;
    std::cout<<"Flip fish #5 start position: "<<f5->getDistance()<<std::endl;
    std::cout<<"Drunk fish #1 start position: "<<f6->getDistance()<<std::endl;
    std::cout<<"Drunk fish #2 start position: "<<f7->getDistance()<<std::endl;
    std::cout<<"Drunk fish #3 start position: "<<f8->getDistance()<<std::endl;
    std::cout<<"Drunk fish #4 start position: "<<f9->getDistance()<<std::endl;
    std::cout<<"Drunk fish #5 start position: "<<f10->getDistance()<<std::endl;
    
    while(true){
        time++;
        std::cout<<"Time: "<<time<<std::endl; /* Time counter */
        
        for(int i=0; i<p.size(); i++){
            std::cout<< p.get_fish(i)->getDistance()<<" = fish " << p.get_fish(i) <<" distance "<<"\n";
            p.get_fish(i)->swim(); /* Swimming fish (just keep swimming) */
            
            /* Returns distance in getDistance() method from Fish.cc */
            if(p.get_fish(i)->getDistance()>=100){
                std::cout<< p.get_fish(i) <<" is dead in "<< time << " minutes" << std::endl;
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
