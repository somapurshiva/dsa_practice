//
//  rational.hpp
//  Rational - C++
//
//  Created by Shiva Somapur on 28/01/21.
//  Copyright © 2021 Shiva Somapur. All rights reserved.
//

#ifndef rational_hpp
#define rational_hpp

#include <stdio.h>

#endif /* rational_hpp */

class Rational {
protected:
    long numerator;
    long denominator;
    void reduce (void);
public:
    Rational(void);
    Rational(long);
    Rational(long, long);
    Rational add(Rational);
    Rational add(long);
    Rational multiply(Rational);
    Rational divide(Rational);
    bool equal(Rational);
    void print(void);
    void setrational(long, long);
};

class Integer:public Rational {
public:
    Integer(void);
    Integer(long);
    void setrational(long, long);
    void setrational(long);
};
