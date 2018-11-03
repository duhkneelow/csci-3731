//
//  Angle.h
//  7 (Angle class)
//
//  Created by Daniel Nilo on 10/24/18.
//  Copyright © 2018 Daniel Nilo. All rights reserved.
//

#ifndef Angle_h
#define Angle_h

#include <stdio.h>
#include <iostream>

class Angle {
private:
    int degrees; /* Declare degrees as int */
    mutable double sinValue;
    mutable double cosValue;
    mutable bool have_sin;
    mutable bool have_cos;
    
public:
    Angle(int x); /* For constructor */
    virtual ~Angle(); /* Virtual command (for destructor) */
    
    int getX() const; /* Get method for degrees */
    void set(int x); /* Set method for degrees */
    
    double getSin() const;
    double getCos() const;
    
    Angle operator+(const Angle& a) const; /* + operator */
    const Angle& operator+=(const Angle& a); /* += operator */
    Angle operator-(const Angle& a) const; /* - operator */
    const Angle& operator-=(const Angle& a); /* -= operator */
    bool operator==(const Angle& a) const; /* compares angles */
    const Angle& operator=(const Angle& a); /* angle operator */
    const Angle& operator=(double x); /* double operator */
    
    friend std::ostream& operator<<(std::ostream& out, const Angle& a); /* print using friends */
};

#endif /* Angle_h */
