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
    if (!gf256_table_initialized){
        gf256_table_init();
    }
    
    for (int i = 0; i<n; i++) {
        c[i] = 0x0;
        for (int j = 0; j < k; j++) {
            unsigned char increment = gf256_mult(m[j], gf256_exp_table[(i*j)%255]);
            c[i] = gf256_add(c[i], increment);
        }
    }
    
    return c;
}

unsigned int* FFT_encoding(unsigned int* m, int k){
    // send to recursive FFT
    
    if (!gf257_table_initialized){
        gf257_table_init();
    }
    
    unsigned int* msg = new unsigned int[256];
    memset(msg, 0, 256);
    for(int i = 0 ; i < k; i++) {
        msg[i] = m[i];
    }
    
    unsigned int* c = recursive_FFT(msg, 256);
    
    return c;
}

unsigned int* recursive_FFT(unsigned int* m, int n){
    
    if (n == 1)
        return m;
    
    unsigned int omega_n = gf257_exp_table[256/n];
    unsigned int omega = 1;
    
    unsigned int* even = new unsigned int[n/2];
    unsigned int* odd  = new unsigned int[n/2];
    
    for (int i = 0; i < n/2; i++) {
        even[i] = m[2*i];
        odd[i] = m[2*i+1];
    }
    
    unsigned int* even_fft = recursive_FFT(even, n/2);
    unsigned int* odd_fft = recursive_FFT(odd, n/2);

    unsigned int* fft = new unsigned int[n];
    for (int k = 0; k < n/2; k++) {
        fft[k] = gf257_add(even_fft[k], gf257_mult(omega, odd_fft[k]));
        fft[k+n/2] = gf257_add(even_fft[k], gf257_addinv(gf257_mult(omega, odd_fft[k])));
        omega = gf257_mult(omega, omega_n);
    }
    
    return fft;
}
