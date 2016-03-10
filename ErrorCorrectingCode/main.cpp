//
//  main.cpp
//  ErrorCorrectingCode
//
//  Created by Feng Gui on 3/5/16.
//  Copyright © 2016 Feng Gui. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include "GF256.hpp"
#include "GF257.hpp"
#include "ECC.hpp"

using namespace std;

int main(int argc, const char* argv[]) {
    
    /* test for encode */
//    unsigned int m[] = {1, 1, 1, 1, 1, 1, 1,1,1,1};
//
//    int n = 20;
//    int k = 10;
//    unsigned int* c = FFT_encoding(m, k);
//    
//    for(int i = 0; i < 256; i++){
//        cout << (unsigned int)c[i] << " ";
//    }
    
    
    
    
    /* test for gf256_decode */
//    unsigned int c[] = {78, 180, 14, 230, 141, 250, 69, 97, 0x100, 157, 70, 116, 71, 50, 228, 223, 46, 101, 222, 246, 185, 166, 0x100, 121, 0, 224, 33, 84, 94, 115, 5, 126, 167, 223, 226, 67, 99, 54, 177, 213, 79, 33, 203, 76, 72, 65, 61, 113, 60, 118, 139, 176, 183, 255, 167, 212, 197, 62, 195, 182, 4, 107, 219, 186, 193, 94, 143, 0x100, 170, 235, 60, 26, 101, 233, 181, 94, 82, 11, 12, 121, 141, 56, 48, 220, 254, 38, 78, 30, 168, 81, 115, 158, 239, 214, 29, 26, 92, 176, 8, 225, 50, 228, 237, 255, 15, 100, 171, 96, 76, 200, 80, 206, 48, 125, 215, 212, 34, 20, 25, 61, 125, 0x100, 50, 62, 201, 137, 36, 176, 78, 76, 97, 187, 23, 50, 121, 66, 55, 81, 145, 168, 58, 3, 107, 135, 14, 237, 252, 19, 241, 17, 129, 28, 108, 80, 113, 202, 173, 179, 35, 199, 236, 103, 206, 148, 109, 10, 22, 229, 11, 159, 42, 33, 196, 51, 93, 184, 58, 87, 151, 237, 89, 84, 158, 174, 181, 119, 71, 228, 91, 174, 128, 235, 223, 251, 253, 219, 26, 161, 72, 254, 133, 134, 149, 96, 12, 236, 95, 171, 25, 63, 226, 177, 45, 101, 39, 68, 117, 5, 223, 45, 48, 93, 97, 173, 46, 154, 62, 199, 75, 91, 50, 140, 60, 110, 194, 66, 77, 196, 222, 228, 204, 144, 217, 34, 123, 159, 27, 67, 0, 215, 5, 42, 201, 150, 163};
//    
//    int n = 255;
//    int k = 69;
//    unsigned int* m = gf256_decode(c, k, n);
//    
//    for(int i = 0; i < k; i++){
//        cout << (unsigned int)m[i] << " ";
//    }

    
    
    
    /* test for gf257_decode */
    unsigned int c[] = {188L, 131L, 243L, 69L, 99L, 244L, 45L, 47L, 80L, 131L, 194L, 37L, 40L, 105L, 163L, 135L, 72L, 159L, 244L, 51L, 200L, 219L, 112L, 6L, 42L, 244L, 176L, 124L, 104L, 11L, 175L, 194L, 76L, 170L, 256L, 39L, 165L, 32L, 209L, 220L, 182L, 185L, 17L, 70L, 210L, 236L, 119L, 161L, 203L, 75L, 255L, 217L, 43L, 202L, 106L, 246L, 105L, 214L, 97L, 214L, 152L, 138L, 89L, 2L, 32L, 85L, 216L, 46L, 228L, 254L, 136L, 226L, 168L, 181L, 68L, 173L, 125L, 219L, 149L, 188L, 163L, 253L, 199L, 20L, 110L, 61L, 3L, 72L, 112L, 249L, 237L, 165L, 101L, 61L, 214L, 208L, 180L, 250L, 144L, 151L, 242L, 81L, 246L, 61L, 190L, 121L, 222L, 96L, 91L, 95L, 7L, 16L, 34L, 245L, 203L, 94L, 28L, 139L, 204L, 93L, 120L, 229L, 121L, 231L, 104L, 176L, 192L, 47L, 94L, 77L, 138L, 188L, 235L, 98L, 42L, 43L, 33L, 171L, 220L, 24L, 63L, 212L, 138L, 221L, 20L, 253L, 76L, 213L, 122L, 63L, 136L, 247L, 77L, 226L, 252L, 160L, 78L, 30L, 66L, 126L, 210L, 41L, 240L, 8L, 37L, 52L, 233L, 77L, 11L, 132L, 36L, 112L, 248L, 137L, 194L, 17L, 7L, 131L, 35L, 125L, 168L, 10L, 34L, 151L, 27L, 168L, 137L, 81L, 156L, 83L, 22L, 85L, 190L, 2L, 134L, 74L, 144L, 162L, 59L, 158L, 217L, 148L, 198L, 178L, 64L, 122L, 62L, 60L, 173L, 19L, 144L, 254L, 44L, 48L, 107L, 236L, 42L, 234L, 246L, 212L, 65L, 164L, 190L, 110L, 167L, 89L, 123L, 142L, 96L, 207L, 194L, 70L, 85L, 158L, 15L, 148L, 256L, 111L, 226L, 26L, 11L, 18L, 35L, 17L, 206L, 227L, 130L, 39L, 237L, 137L, 79L, 78L, 244L, 233L, 15L, 19L};
    
    int n = 256;
    int k = 69;
    unsigned int* m = gf257_decode(c, k, n);
    
    for(int i = 0; i < k; i++){
        cout << (unsigned int)m[i] << " ";
    }


    
    
    
    /* test for field operations */
//    gf257_table_init();
//    printf("%d ", gf257_mult(234, 25));

//
//    for (int i = 0; i < 256; i++){
//        printf("%x ", gf256_log_table[i]);
//        if (i%16 == 15) cout << endl;
//    }
    
    return 0;
}
