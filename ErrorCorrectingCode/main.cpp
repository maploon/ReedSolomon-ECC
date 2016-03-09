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
    unsigned int m[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 34, 45, 67, 23, 89, 53, 12, 54, 67, 1, 1, 34, 45, 67, 23, 89, 53, 12, 54, 67, 1, 1, 34, 45, 67, 23, 89, 53, 12, 54, 67, 1, 1, 34, 45, 67, 23, 89, 53, 12, 54, 67, 1, 1, 34, 45, 67, 23, 89, 53, 12, 54, 67};

    int n = 20;
    int k = 69;
    unsigned int* c = FFT_encoding(m, k);
    
    for(int i = 0; i < 256; i++){
        cout << c[i] << " ";
    }
    
    
//    gf257_table_init();
//    printf("%d ", gf257_mult(234, 25));

//
//    for (int i = 0; i < 256; i++){
//        printf("%x ", gf256_log_table[i]);
//        if (i%16 == 15) cout << endl;
//    }
    
    return 0;
}
