//
//  main.cpp
//  Infix-Postfix-Eval
//
//  Created by Shiva Somapur on 05/10/21.
//

#include <iostream>
#include "routine.h"

int main(int argc, const char * argv[]) {
    char in[250], post[250];
    long double res;
    
    std::cin >> in;
//    std::cout << in << std::endl;
    postfix(in, post);
    std::cout << post << std::endl;
    res = eval(post);
    std::cout << res << std::endl;
    return 0;
}
