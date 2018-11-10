//
//  Angle.h
//  5 (Angle template)
//
//  Created by Daniel Nilo on 11/7/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#ifndef Angle_h
#define Angle_h

#include <stdio.h>
#include <iostream>
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159
#endif

template<class A> class Angle {
private:
    A degrees; /* Declare degrees as int */
    mutable double sinValue;
    mutable double cosValue;
    mutable bool have_sin;
    mutable bool have_cos;
    
public:
    /* Constructor for Angle */
    Angle(A x) {
        degrees = x;
        while(degrees>= 360.0) degrees -= 360.0;
        while(degrees<    0.0) degrees += 360.0;
        have_sin = false;
        have_cos = false;
    }
    
    /* Destructor for Angle */
    virtual ~Angle() {
        
    }
    
    /* Gets degrees for Angle */
    A getX() const {
        return degrees;
    }
    
    /* Sets degrees for Angle */
    void set(A x) {
        this->degrees = x;
        sinValue = false;
        cosValue = false;
    }
    
    double getCos() const {
        if(!have_cos){
            cosValue = sin(degrees*M_PI/180.0);
            have_cos = true;
        }
        return cosValue;
    }
    
    double getSin() const {
        if(!have_sin){
            sinValue = sin(degrees*M_PI/180.0);
            have_sin = true;
        }
        return sinValue;
    }
    
    /* Adds angles (+) */
    Angle operator+(const Angle& a) const {
        double result = degrees + a.getX();
        if (result > 360) {
            return Angle(result - 360);
        }
        return Angle(result);
    }
    
    /* Adds angles from previous addition(+=) */
    const Angle& operator+=(const Angle& a) {
        degrees += a.getX();
        if (degrees > 360) {
            degrees -= 360;
        }
        return *this;
    }
    
    /* Subtracts angles (-) */
    Angle operator-(const Angle& a) const {
        double result = degrees - a.getX();
        if (result < 0) {
            return Angle(result + 360);
        }
        return Angle(result);
    }
    
    /* Subtracts angles from previous subtraction(-=) */
    const Angle& operator-=(const Angle& a) {
        degrees -= a.getX();
        if (degrees < 0) {
            degrees += 360;
        }
        return *this;
    }
    
    /* Compares angles */
    bool operator==(const Angle& a) const {
        return degrees == a.getX();
    }
    
    /* Assigns angles */
    const Angle& operator=(const Angle& a) {
        this->degrees = a.getX();
        return *this;
    }
    
    /* Assigns double */
    const Angle& operator=(double x) {
        this->degrees = (double)x;
        return *this;
    }
    
    /* print method using friend */
    friend std::ostream& operator<<(std::ostream& out, const Angle& a) {
        out << "The angle is now " << a.getX() << " degrees.";
        return out;
    }
};

#endif /* Angle_h */
