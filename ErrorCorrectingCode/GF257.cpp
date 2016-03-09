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
    
    
    return gf257_exp_table[(gf257_log_table[x] - gf257_log_table[y])%256];
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
    
    return gf257_exp_table[(-gf257_log_table[x])%256];
}