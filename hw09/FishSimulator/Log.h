//
//  Log.h
//  7 (Log class)
//
//  Created by Daniel Nilo on 10/24/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#ifndef Log_h
#define Log_h

#include <stdio.h>
#include <string>

class Log {
private:
    Log(); /* private constructor */
    virtual ~Log();
    mutable bool logIn;
public:
    static const Log& getInstance(); /* static method */
    void print(const std::string& thing) const;
    void active(bool turn) const;
};

#endif /* Log_h */
