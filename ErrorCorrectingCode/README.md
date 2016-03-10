
Author: Feng Gui
Date: 3/9/2016

The Project ErrorCorrectionCode is made of three parts:
1. Operations on Galois Field of 2^8 elements
2. Operations on Galois Field of 257 elements (This makes sense since 257 is a prime)
3. Encoding and Decoding functions.

----- GF256.cpp -----
GF256.cpp has the following functions:
    
    void gf256_table_init();
    unsigned int gf256_add(unsigned int x, unsigned int y);
    unsigned int gf256_mult_basic(unsigned int x, unsigned int y);
    unsigned int gf256_mult(unsigned int x, unsigned int y);
    unsigned int gf256_div(unsigned int x, unsigned int y);
    unsigned int gf256_addinv(unsigned int x);
    unsigned int gf256_multinv(unsigned int x);
    unsigned int* gf256_gauss(unsigned int** A, int n);


The purpose of these functions are clear by their names. 
gf256_table_init() initiate the exponent and the logarithm table of GF(256) with a fixed generator. 
gf256_gauss function takes a n*(n+1) matrix as a system of n linear functions in the field GF(256). gf256_gauss returns the solution of this system of linear functions using Gaussian elimination. 


----- GF257.cpp -----
GF257.cpp has the following functions:
    
    void gf257_table_init();
    unsigned int gf257_add(unsigned int x, unsigned int y);
    unsigned int gf257_mult_basic(unsigned int x, unsigned int y);
    unsigned int gf257_mult(unsigned int x, unsigned int y);
    unsigned int gf257_div(unsigned int x, unsigned int y);
    unsigned int gf257_addinv(unsigned int x);
    unsigned int gf257_multinv(unsigned int x);
    unsigned int* gf257_gauss(unsigned int** A, int n);


The purpose of these functions are also clear by their names. 
gf257_table_init() initiate the exponent and the logarithm table of GF(257) with a fixed generator. 
gf257_gauss function takes a n*(n+1) matrix as a system of n linear functions in the field GF(257). gf257_gauss returns the solution of this system of linear functions using Gaussian elimination. 


----- ECC.cpp -----
ECC.cpp has the following functions:

    unsigned int* DFT_encoding(unsigned int* m,int k, int n);
    unsigned int* FFT_encoding(unsigned int* m, int k);
    unsigned int* recursive_FFT(unsigned int* m, int n);
    unsigned int* gf256_decode(unsigned int* c, int k, int n);
    unsigned int* gf257_decode(unsigned int* c, int k, int n);

DFT_encoding takes a messege m with length k and encoded to codewords with n symbols. It functions on GF(256) field. 
FFT_encoding is a faster encoding algorithm using GF(257) and fast fourier transformation. It takes a message m and encoded to codewords with 256 symbols. recursive_FFT is a helper function to implement FFT. 
gf256_decode takes codewords c with length n and decoded to the original message with length k. The codewords can have at most 2s = (n-k) erasures to make sure it can be decoded. The erasures are indicated by any unsigned int that is not in GF(256), i.e. any positive integer greater than 255.
Similarly, gf257_decode takes codewords c with length n (= 256) and decoded to the original message with length k. The codewords can have at most 2s = (n-k) erasures to make sure it can be decoded. The erasures are indicated by any unsigned int that is not in GF(257), i.e. any positive integer greater than 256.
