//
//  Log.cc
//  7
//
//  Created by Daniel Nilo on 10/24/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#include "Log.h"
#include <string>
#include <iostream>

Log::Log() {
    this->logIn = false;
}

Log::~Log(){
    
}

// Implement getInstance()
const Log& Log::getInstance() {
    static Log instance;
    return instance;
}

// print() method for main file
void Log::print(const std::string& thing) const {
    std::cout << "Yay fish!" << thing << std::endl;
}

void Log::active(bool turn) const {
    if (logIn != turn) {
        logIn = turn;
    }
}
