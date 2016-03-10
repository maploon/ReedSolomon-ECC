//
//  GF257.hpp
//  ErrorCorrectingCode
//
//  Created by Feng Gui on 3/5/16.
//  Copyright © 2016 Feng Gui. All rights reserved.
//

#ifndef GF257_hpp
#define GF257_hpp

#include <stdio.h>

extern unsigned int gf257_gen;
extern unsigned int gf257_exp_table[257], gf257_log_table[257];
extern bool gf257_table_initialized;

void gf257_table_init();
unsigned int gf257_add(unsigned int x, unsigned int y);
unsigned int gf257_mult_basic(unsigned int x, unsigned int y);
unsigned int gf257_mult(unsigned int x, unsigned int y);
unsigned int gf257_div(unsigned int x, unsigned int y);
unsigned int gf257_addinv(unsigned int x);
unsigned int gf257_multinv(unsigned int x);

unsigned int* gf257_gauss(unsigned int** A, int n);


#endif /* GF257_hpp */
