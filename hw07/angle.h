//
//  angle.h
//  7 (Angle class)
//
//  Created by Daniel Nilo on 10/17/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#ifndef angle_h
#define angle_h

#include <stdio.h>

class Angle {
private:
    int degrees; /* Declare degrees as int */
    
public:
    Angle(int x); /* For constructor */
    virtual ~Angle(); /* Virtual command (for destructor) */
    
    int getX() const; /* Get method for degrees */
    void set(int x); /* Set method for degrees */
    
    Angle operator+(const Angle& a) const; /* + operator */
    const Angle& operator+=(const Angle& a); /* += operator */
    Angle operator-(const Angle& a) const; /* - operator */
    const Angle& operator-=(const Angle& a); /* -= operator */
    Angle operator*(const Angle& a) const; /* * operator */
    const Angle& operator*=(const Angle& a); /* *= operator */
    Angle operator/(const Angle& a) const; /* / operator */
    const Angle& operator/=(const Angle& a); /* /= operator */
    bool operator==(const Angle& a) const; /* compares angles */
    const Angle& operator=(const Angle& a); /* angle operator */
    const Angle& operator=(double x); /* double operator */
    
    void print() const; /* print operator for print method (in angle.cc file) */
};

#endif /* angle_h */
