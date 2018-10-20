//
//  angle.cc
//  7 (Angle constructor and operators)
//
//  Created by Daniel Nilo on 10/17/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include "angle.h"

/* Constructor for Angle */
Angle::Angle(int x) {
    if (x > 360) {
        this->degrees = x % 360;
    }  else if (x < 0) {
        x = x % 360;
        this->degrees = x + 360;
    } else {
        this->degrees = x;
    }
}

/* Destructor for Angle */
Angle::~Angle() {
    
}

/* Gets degrees for Angle */
int Angle::getX() const {
    return degrees;
}

/* Sets degrees for Angle */
void Angle::set(int x) {
    this->degrees = x;
}

/* Adds angles (+) */
Angle Angle::operator+(const Angle& a) const {
    double result = degrees + a.getX();
    if (result > 360) {
        return Angle(result - 360);
    }
    return Angle(result);
}

/* Adds angles from previous addition(+=) */
const Angle& Angle::operator+=(const Angle& a) {
    degrees += a.getX();
    if (degrees > 360) {
        degrees -= 360;
    }
    return *this;
}

/* Subtracts angles (-) */
Angle Angle::operator-(const Angle& a) const {
    double result = degrees - a.getX();
    if (result < 0) {
        return Angle(result + 360);
    }
    return Angle(result);
}

/* Subtracts angles from previous subtraction(-=) */
const Angle& Angle::operator-=(const Angle& a) {
    degrees -= a.getX();
    if (degrees < 0) {
        degrees += 360;
    }
    return *this;
}

/* Multiplies angles with a double (*) */
Angle Angle::operator*(const Angle& a) const {
    int result = degrees * a.getX();
    if (result > 360) {
        return Angle(result % 360);
    }
    return Angle(result);
}

/* Multiplies angles with a double from previous multiplication (*=) */
const Angle& Angle::operator*=(const Angle& a) {
    degrees *= a.getX();
    if (degrees > 360) {
        degrees = degrees % 360;
    }
    return *this;
}

/* Divides angles with a double (/) */
Angle Angle::operator/(const Angle& a) const {
    if (a.getX() == 0) {
        return Angle(degrees);
    }
    return Angle(degrees/a.getX());
}

/* Divides angles with a double from previous division (/=) */
const Angle& Angle::operator/=(const Angle& a) {
    if (a.getX() != 0) {
        degrees /= a.getX();
    }
    return *this;
}

/* Compares angles */
bool Angle::operator==(const Angle& a) const {
    return degrees == a.getX();
}

/* Assigns angles */
const Angle& Angle::operator=(const Angle& a) {
    this->degrees = a.getX();
    return *this;
}

/* Assigns double */
const Angle& Angle::operator=(double x) {
    this->degrees = (double)x;
    return *this;
}

/* print() method) */
void Angle:: print () const{
    std::cout << "The angle is now " << this->degrees << " degrees." <<std::endl;
}
