//
//  ECC.hpp
//  ErrorCorrectingCode
//
//  Created by Feng Gui on 3/6/16.
//  Copyright © 2016 Feng Gui. All rights reserved.
//

#ifndef ECC_hpp
#define ECC_hpp

#include <stdio.h>

unsigned int* DFT_encoding(unsigned int* m,int k, int n);
unsigned int* FFT_encoding(unsigned int* m, int k);
unsigned int* recursive_FFT(unsigned int* m, int n);
unsigned int* gf256_decode(unsigned int* c, int k, int n);
unsigned int* gf257_decode(unsigned int* c, int k, int n);
#endif /* ECC_hpp */
