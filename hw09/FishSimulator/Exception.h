//
//  Exception.h
//  7 (Exception class)
//
//  Created by Daniel Nilo on 11/1/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#ifndef Exception_h
#define Exception_h

#include <stdio.h>
#include <stdexcept>

// Exception class with runtime error as subclass
class Exception : public std::runtime_error {
    public:
        Exception(const std::string& message);
};

#endif /* Exception_h */
