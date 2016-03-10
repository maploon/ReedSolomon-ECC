//
//  GF256.cpp
//  ErrorCorrectingCode
//
//  Created by Feng Gui on 3/5/16.
//  Copyright © 2016 Feng Gui. All rights reserved.
//

/*
 * AES Fast implementation and generator of exponential and logarithm tables for GF<256> using any generator.
 *
 * In this example, it comes with 0x03.
 *
 * Possible generators are:
 *
 * 03 05 06 09 0b 0e 11 12 13 14 17 18 19 1a 1c 1e
 * 1f 21 22 23 27 28 2a 2c 30 31 3c 3e 3f 41 45 46
 * 47 48 49 4b 4c 4e 4f 52 54 56 57 58 59 5a 5b 5f
 * 64 65 68 69 6d 6e 70 71 76 77 79 7a 7b 7e 81 84
 * 86 87 88 8a 8e 8f 90 93 95 96 98 99 9b 9d a0 a4
 * a5 a6 a7 a9 aa ac ad b2 b4 b7 b8 b9 ba be bf c0
 * c1 c4 c8 c9 ce cf d0 d6 d7 da dc dd de e2 e3 e5
 * e6 e7 e9 ea eb ee f0 f1 f4 f5 f6 f8 fb fd fe ff
 *
 */

#include "GF256.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

/* Generator of GF(256) */
unsigned int gf256_gen = 0x03;

/* Irreducible polynomial for GF(256), i.e. x^8+x^4+x^3+x+1 */
unsigned int gf256_irred = 0x11b;

/* Exponent and Logarithm table*/
unsigned int gf256_exp_table[256], gf256_log_table[256];

bool gf256_table_initialized = false;

/* initializing exponent and logarithm table */
void gf256_table_init(){

    gf256_exp_table[0] = 0x01;
    for (unsigned int i = 0x01; i < 0x100; i++){
        gf256_exp_table[i] = gf256_mult_basic(gf256_gen, gf256_exp_table[i-1]);
    }
    for (unsigned int i = 0x00; i < 0xff; i++) {
        gf256_log_table[gf256_exp_table[i]] = i;
    }
}

/* Addition on field GF(256) */
unsigned int gf256_add(unsigned int x, unsigned int y){
    return x^y;
}

unsigned int gf256_mult_basic(unsigned int x, unsigned int y) {
    unsigned int a = x, b = y, c = 0, t;
    while (a != 0) {
        if ((a & 1) != 0)
            c = c ^ b;
        t = b & 0x80;
        b = b << 1;
        if (t != 0)
            b = b ^ 0x1b;
        a = a >> 1;
    }
    return (c&0xff);
}

/* Multiplication on GF(256) */
unsigned int gf256_mult(unsigned int x, unsigned int y){
    if (!gf256_table_initialized) {
        gf256_table_init();
        gf256_table_initialized = true;
    }
    if (x == 0x0 || y == 0x0) return 0x0;
    
    return gf256_exp_table[((unsigned int)gf256_log_table[x] + (unsigned int)gf256_log_table[y])%255];
}

/* Division on GF(256) */
unsigned int gf256_div(unsigned int x, unsigned int y){
    if (!gf256_table_initialized) {
        gf256_table_init();
        gf256_table_initialized = true;
    }
    
    
    if(gf256_log_table[x] > gf256_log_table[y])
        return gf256_exp_table[gf256_log_table[x] - gf256_log_table[y]];
    else
        return gf256_exp_table[gf256_log_table[x] +255- gf256_log_table[y]];
}

/* Additive inverse */
unsigned int gf256_addinv(unsigned int x){
    return x;
}

/* Multiplicative inverse */
unsigned int gf256_multinv(unsigned int x){
    if (!gf256_table_initialized) {
        gf256_table_init();
        gf256_table_initialized = true;
    }
    
    return gf256_exp_table[255-gf256_log_table[x]];
}