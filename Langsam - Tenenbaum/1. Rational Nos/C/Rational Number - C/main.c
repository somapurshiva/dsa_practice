//
//  main.c
//  Rational Number - C
//
//  Created by Shiva Somapur on 28/01/21.
//  Copyright © 2021 Shiva Somapur. All rights reserved.
//

#include "rational.h"

int main(int argc, const char * argv[]) {
    RATIONAL testrat, retrat;
    testrat.numerator = 9828;
    testrat.denominator = 8289;
    
    retrat = reduce(&testrat);
    
    printf("%d/%d\n", retrat.numerator, retrat.denominator);
    printf("%d/%d\n", testrat.numerator, testrat.denominator);
    
    printf("Are these equal: %d/%d & %d/%d? %d\n", testrat.numerator, testrat.denominator,
           retrat.numerator, retrat.denominator, equal(&testrat, &retrat));
    
    RATIONAL mulrat = multiply(&testrat, &retrat);
    
    printf("Multiplying both results in: %d/%d\n", mulrat.numerator, mulrat.denominator);
    
    RATIONAL divrat = divide(&testrat, &retrat);
    
    printf("Dividing both results in: %d/%d\n", divrat.numerator, divrat.denominator);
    
    RATIONAL addrat = add(&testrat, &retrat);
    
    printf("Adding both results in: %d/%d\n", addrat.numerator, addrat.denominator);
    
    RATIONAL subrat = subtract(&testrat, &retrat);
    
    printf("Subtracting both results in: %d/%d\n", subrat.numerator, subrat.denominator);
    
    return 0;
}
