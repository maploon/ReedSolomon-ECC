//
//  GF256.hpp
//  ErrorCorrectingCode
//
//  Created by Feng Gui on 3/5/16.
//  Copyright © 2016 Feng Gui. All rights reserved.
//

#ifndef GF256_hpp
#define GF256_hpp

#include <stdio.h>

extern unsigned int gf256_gen;
extern unsigned int gf256_exp_table[256], gf256_log_table[256];
extern unsigned int gf256_irred;
extern bool gf256_table_initialized;

void gf256_table_init();
unsigned int gf256_add(unsigned int x, unsigned int y);
unsigned int gf256_mult_basic(unsigned int x, unsigned int y);
unsigned int gf256_mult(unsigned int x, unsigned int y);
unsigned int gf256_div(unsigned int x, unsigned int y);
unsigned int gf256_addinv(unsigned int x);
unsigned int gf256_multinv(unsigned int x);

#endif /* GF256_hpp */
