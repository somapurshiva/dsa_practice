//
//  rational.cpp
//  Rational - C++
//
//  Created by Shiva Somapur on 28/01/21.
//  Copyright © 2021 Shiva Somapur. All rights reserved.
//

#include "rational.hpp"
#include <iostream>

Rational::Rational(void) {
    numerator = 0;
    denominator = 1;
}

Rational::Rational(long i) {
    numerator = i;
    denominator = 1;
}

Rational::Rational(long num, long denom) {
    numerator = num;
    denominator = denom;
}

void Rational::setrational(long n, long d) {
    numerator = n;
    denominator = d;
    reduce();
}

void Rational::reduce(void) {
    long a, b, rem;
    int sign;
    
    if (numerator == 0)
        denominator = 1;
    sign = 1;
    if (numerator < 0 && denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    } else if (numerator < 0) {
        numerator = -numerator;
        sign = -1;
    } else if (denominator < 0) {
        denominator = -denominator;
        sign = -1;
    }
    
    if (numerator > denominator) {
        a = numerator;
        b = denominator;
    } else {
        a = denominator;
        b = numerator;
    }
    
    while (b != 0) {
        rem = a % b;
        a = b;
        b = rem;
    }
    
    numerator = sign * numerator / a;
    denominator = denominator / a;
}

Rational Rational::add(Rational r) {
    long k, denom, num;
    Rational rn1(denominator, r.denominator);
    
    reduce();
    r.reduce();
    rn1.reduce();
    
    k = rn1.denominator;
    
    denom = denominator * k;
    
    num = numerator * k + r.numerator * (denom / r.denominator);
    
    rn1.setrational(num, denom);
    rn1.reduce();
    
    return rn1;
}

Rational Rational::multiply(Rational r) {
    Rational rnl, rnl1(numerator, r.denominator), rnl2(r.numerator, denominator);
    long num, denom;
    
    reduce();
    r.reduce();
    
//    rnl1.setrational(numerator, r.denominator);
    rnl1.reduce();
    
//    rnl2.setrational(r.numerator, denominator);
    rnl2.reduce();
    
    num = rnl1.numerator * rnl2.numerator;
    denom = rnl1.denominator * rnl2.denominator;
    
    rnl.setrational(num, denom);
    
    return rnl;
}

Rational Rational::divide(Rational r) {
    Rational rnl(r.denominator, r.numerator);
    
//    rnl.setrational(r.denominator, r.numerator);
    
    return multiply(rnl);
}

bool Rational::equal(Rational r) {
    reduce();
    r.reduce();
    
    if (numerator == r.numerator && denominator == r.denominator)
        return true;
    else
        return false;
}

void Rational::print() {
    std::cout << numerator << "/" << denominator << std::endl;
}

Rational Rational::add(long i) {
    Rational r(i, 1);
    
//    r.setrational(i, 1);
    return add(r);
}

void Integer::setrational(long num, long denom) {
    if (denom != 1)
        perror("ERROR: non-integer assigned to Integer variable");
    numerator = num;
    denominator = 1;
}

void Integer::setrational(long num) {
    numerator = num;
    denominator = 1;
}

Integer::Integer(void) {
    numerator = 0;
    denominator = 1;
}

Integer::Integer(long i) {
    numerator = i;
    denominator = 1;
}
