//
//  main.cpp
//  ErrorCorrectingCode
//
//  Created by Feng Gui on 3/5/16.
//  Copyright © 2016 Feng Gui. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include "GF256.hpp"
#include "GF257.hpp"
#include "ECC.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    unsigned char m[] = {1,2,3};

    int n = 9;
    unsigned char* c = DFT_encoding(m, 3, n);
    printf("%x %x %x %x %x", c[0], c[1], c[2], c[3], c[9]);
    
    return 0;
}
