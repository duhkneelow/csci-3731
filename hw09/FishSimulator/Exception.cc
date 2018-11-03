//
//  Exception.cc
//  7 (Exception constructor)
//
//  Created by Daniel Nilo on 11/1/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#include "Exception.h"

// Exception constructor
Exception::Exception(const std::string& message)
    : std::runtime_error(message) {
}
