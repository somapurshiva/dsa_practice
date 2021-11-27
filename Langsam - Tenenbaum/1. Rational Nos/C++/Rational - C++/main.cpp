//
//  main.cpp
//  Rational - C++
//
//  Created by Shiva Somapur on 28/01/21.
//  Copyright © 2021 Shiva Somapur. All rights reserved.
//

#include "rational.hpp"

int main(int argc, const char * argv[]) {
    Rational rn1(1,2), rn2(1,3);
    Integer in(1);

    rn1.print();
    rn2.print();
    
    Rational rn3 = rn1.add(rn2);
    rn3.print();
    
    Rational rn4 = rn1.multiply(rn2);
    rn4.print();
    
    Rational rn5 = rn1.divide(rn2);
    rn5.print();
    
    in.divide(rn5).print();

    return 0;
}
