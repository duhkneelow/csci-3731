//
//  Angle.cc
//  7 (Angle constructor and operators)
//
//  Created by Daniel Nilo on 10/24/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <cmath>
#include "Angle.h"
#ifndef M_PI
#define M_PI 3.14159
#endif

/* Constructor for Angle */
Angle::Angle(int x) {
    degrees = x;
    while(degrees>= 360.0) degrees -= 360.0;
    while(degrees<    0.0) degrees += 360.0;
    have_sin = false;
    have_cos = false;
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
    sinValue = false;
    cosValue = false;
}

double Angle::getCos() const {
    if(!have_cos){
        cosValue = sin(degrees*M_PI/180.0);
        have_cos = true;
    }
    return cosValue;
}

double Angle::getSin() const {
    if(!have_sin){
        sinValue = sin(degrees*M_PI/180.0);
        have_sin = true;
    }
    return sinValue;
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

/* print method using friend */
std::ostream& operator<<(std::ostream& out, const Angle& a) {
    out << "The angle is now " << a.getX() << " degrees.";
    return out;
}
