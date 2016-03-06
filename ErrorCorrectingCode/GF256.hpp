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

extern unsigned char gf256_gen;
extern unsigned char gf256_exp_table[256], gf256_log_table[256];
extern unsigned int gf256_irred;

void gf256_table_init();
unsigned char gf256_add(unsigned char x, unsigned char y);
unsigned char gf256_mult_basic(unsigned char x, unsigned char y);
unsigned char gf256_mult(unsigned char x, unsigned char y);
unsigned char gf256_div(unsigned char x, unsigned char y);
unsigned char gf256_addinv(unsigned char x);
unsigned char gf256_multinv(unsigned char x);

#endif /* GF256_hpp */
