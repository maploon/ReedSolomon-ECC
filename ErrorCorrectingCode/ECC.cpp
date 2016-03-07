//
//  ECC.cpp
//  ErrorCorrectingCode
//
//  Created by Feng Gui on 3/6/16.
//  Copyright © 2016 Feng Gui. All rights reserved.
//

#include "ECC.hpp"
#include "GF256.hpp"
#include "GF257.hpp"
#include <iostream>
#include <string.h>

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

using namespace std;

unsigned char* DFT_encoding(unsigned char* m, int k, int n){
    if (k > n) {
        cerr << "message length is greater than number of code words\n";
        exit(1);
    }
    
    unsigned char* c = new unsigned char[n];
    gf256_table_init();
    
    for (int i = 0; i<n; i++) {
        c[i] = 0x0;
        for (int j = 0; j < k; j++) {
            unsigned char increment = gf256_mult(m[j], gf256_exp_table[gf256_mult(i, j)]);
            c[i] = gf256_add(c[i], increment);
        }
    }
    
    return c;
}

unsigned int* FFT_encoding(unsigned int* m, int k){
    // send to recursive FFT
    unsigned int* msg = new unsigned int[256];
    memset(msg, 0, 256);
    for(int i = 0 ; i < k; i++) {
        msg[i] = m[i];
    }
    
    unsigned int* c = recursive_FFT(msg, 256);
    
    return c;
}

unsigned int* recursive_FFT(unsigned int* m, int n){
    
    return 0;
}
