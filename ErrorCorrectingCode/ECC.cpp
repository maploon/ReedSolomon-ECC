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
#include <vector>

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))
#define MISELM (-1)
using namespace std;

unsigned int* DFT_encoding(unsigned int* m, int k, int n){
    if (k > n) {
        cerr << "message length is greater than number of code words\n";
        exit(1);
    }
    
    unsigned int* c = new unsigned int[n];
    if (!gf256_table_initialized){
        gf256_table_init();
    }
    
    for (int i = 0; i<n; i++) {
        c[i] = 0x0;
        for (int j = 0; j < k; j++) {
            unsigned int increment = gf256_mult(m[j], gf256_exp_table[(i*j)%255]);
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


unsigned int* gf256_decode(unsigned int* c, int k, int n){
    
    if (!gf256_table_initialized){
        gf256_table_init();
    }
    
    unsigned int** T = new unsigned int*[k];
    for(int i = 0; i < k; i++){
        T[i] = new unsigned int[k+1];
    }
    
    int num_codesymbols = 0;
    for (int i = 0; i < n; i++){
        if (c[i] <= 0xff) {
            T[num_codesymbols][k] = c[i];
            for (int j = 0; j < k; j++){
                T[num_codesymbols][j] = gf256_exp_table[(i*j)%255];
            }
            ++num_codesymbols;
        }
        if (num_codesymbols == k) break;
    }
    unsigned int* m = gf256_gauss(T, k);
    
    return m;
}

unsigned int* gf256_gauss(unsigned int** A, int n) {
//    int n = A.size();
    
    for (int i=0; i<n; i++) {
        // Search for maximum in this column
        unsigned int maxEl = A[i][i];
        int maxRow = i;
        for (int k=i+1; k<n; k++) {
            if (A[k][i] > maxEl) {
                maxEl = A[k][i];
                maxRow = k;
            }
        }
        
        // Swap maximum row with current row (column by column)
        for (int k=i; k<n+1;k++) {
            unsigned int tmp = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = tmp;
        }
        
        // Make all rows below this one 0 in current column
        for (int k=i+1; k<n; k++) {
            unsigned int c = gf256_addinv(gf256_div(A[k][i], A[i][i]));
            for (int j=i; j<n+1; j++) {
                if (i==j) {
                    A[k][j] = 0;
                } else {
                    A[k][j] = gf256_add(A[k][j], gf256_mult(c, A[i][j]));
                }
            }
        }
    }
    
    // Solve equation Ax=b for an upper triangular matrix A
    
    unsigned int* x = new unsigned int[n];
    for (int i=n-1; i>=0; i--) {
        x[i] = gf256_div(A[i][n],A[i][i]);
        for (int k=i-1;k>=0; k--) {
            A[k][n] = gf256_add(A[k][n],gf256_addinv(gf256_mult(A[k][i], x[i])));
        }
    }
    return x;
}

