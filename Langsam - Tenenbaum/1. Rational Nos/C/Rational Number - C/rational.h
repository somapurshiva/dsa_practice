//
//  rational.h
//  Rational Number - C
//
//  Created by Shiva Somapur on 28/01/21.
//  Copyright © 2021 Shiva Somapur. All rights reserved.
//

#ifndef rational_h
#define rational_h

#include <stdio.h>

#endif /* rational_h */

typedef struct {
    int numerator;
    int denominator;
} RATIONAL;

RATIONAL reduce (RATIONAL *inrat) {
    int a, b, rem;
    RATIONAL outrat;

    if (inrat->numerator > inrat->denominator) {
        a = inrat->numerator;
        b = inrat->denominator;
    } else {
        a = inrat->denominator;
        b = inrat->numerator;
    }
    
    while (b != 0) {
        rem = a % b;
        a = b;
        b = rem;
    }
    
    outrat.numerator = inrat->numerator/a;
    outrat.denominator = inrat->denominator/a;
    
    return outrat;
}

#define TRUE 1
#define FALSE 0

int equal (RATIONAL *rat1, RATIONAL *rat2) {
    RATIONAL r1, r2;
    
    r1 = reduce(rat1);
    r2 = reduce(rat2);
    
    if (r1.numerator == r2.numerator && r1.denominator == r2.denominator) {
        return (TRUE);
    } else {
        return (FALSE);
    }
}

RATIONAL multiply (RATIONAL *r1, RATIONAL *r2) {
    RATIONAL rat3;
    
    rat3.numerator = r1->numerator * r2->numerator;
    rat3.denominator = r1->denominator * r2->denominator;
    
    return reduce(&rat3);
}

RATIONAL divide (RATIONAL *r1, RATIONAL *r2) {
    RATIONAL rat3;
    
    rat3.numerator = r1->numerator * r2->denominator;
    rat3.denominator = r1->denominator * r2->numerator;
    
    return reduce(&rat3);
}

RATIONAL add (RATIONAL *r1, RATIONAL *r2) {
    RATIONAL rat3;
    
    rat3.numerator = r1->numerator * r2->denominator + r1->denominator * r2->numerator;
    rat3.denominator = r1->denominator * r2->denominator;
    
    return reduce(&rat3);
}

RATIONAL subtract (RATIONAL *r1, RATIONAL *r2) {
    RATIONAL rat3;
    
    rat3.numerator = r1->numerator * r2->denominator - r1->denominator * r2->numerator;
    rat3.denominator = r1->denominator * r2->denominator;
    
    return reduce(&rat3);
}
