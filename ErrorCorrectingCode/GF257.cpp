//
//  GF257.cpp
//  ErrorCorrectingCode
//
//  Created by Feng Gui on 3/5/16.
//  Copyright © 2016 Feng Gui. All rights reserved.
//

/*
 * AES Fast implementation and generator of exponential and logarithm tables for GF<257> using any generator.
 *
 * In this example, it comes with 0x03.
 *
 * Possible generators are:
 *
 */

#include "GF257.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

/* Generator of GF(257) */
unsigned int gf257_gen = 0x3;

/* Exponent and Logarithm table*/
unsigned int gf257_exp_table[257], gf257_log_table[257];

bool gf257_table_initialized = false;

/* initializing exponent and logarithm table */
void gf257_table_init(){
    
    gf257_exp_table[0] = 0x01;
    for (unsigned int i = 0x01; i < 0x101; i++){
        gf257_exp_table[i] = gf257_mult_basic(gf257_gen, gf257_exp_table[i-1]);
    }
    for (unsigned int i = 0x00; i < 0x101; i++) {
        gf257_log_table[gf257_exp_table[i]] = i;
    }
}

/* Addition on field GF(257) */
unsigned int gf257_add(unsigned int x, unsigned int y){
    return (x+y)%257;
}

unsigned int gf257_mult_basic(unsigned int x, unsigned int y) {
    return (x*y)%257;
}

/* Multiplication on GF(257) */
unsigned int gf257_mult(unsigned int x, unsigned int y){
    if (!gf257_table_initialized) {
        gf257_table_init();
        gf257_table_initialized = true;
    }
    if (x == 0x0 || y ==0x0) return 0x0;

    return gf257_exp_table[(gf257_log_table[x] + gf257_log_table[y])%256];
}

/* Division on GF(257) */
unsigned int gf257_div(unsigned int x, unsigned int y){
    if (!gf257_table_initialized) {
        gf257_table_init();
        gf257_table_initialized = true;
    }
    
    
    if(gf257_log_table[x] > gf257_log_table[y])
        return gf257_exp_table[gf257_log_table[x] - gf257_log_table[y]];
    else
        return gf257_exp_table[gf257_log_table[x] +256 - gf257_log_table[y]];
}

/* Additive inverse */
unsigned int gf257_addinv(unsigned int x){
    return 257-x;
}

/* Multiplicative inverse */
unsigned int gf257_multinv(unsigned int x){
    if (!gf257_table_initialized) {
        gf257_table_init();
        gf257_table_initialized = true;
    }
    
    return gf257_exp_table[(-gf257_log_table[x])%257];
}

unsigned int* gf257_gauss(unsigned int** A, int n) {
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
            unsigned int c = gf257_addinv(gf257_div(A[k][i], A[i][i]));
            for (int j=i; j<n+1; j++) {
                if (i==j) {
                    A[k][j] = 0;
                } else {
                    A[k][j] = gf257_add(A[k][j], gf257_mult(c, A[i][j]));
                }
            }
        }
    }
    
    // Solve equation Ax=b for an upper triangular matrix A
    
    unsigned int* x = new unsigned int[n];
    for (int i=n-1; i>=0; i--) {
        x[i] = gf257_div(A[i][n],A[i][i]);
        for (int k=i-1;k>=0; k--) {
            A[k][n] = gf257_add(A[k][n],gf257_addinv(gf257_mult(A[k][i], x[i])));
        }
    }
    return x;
}