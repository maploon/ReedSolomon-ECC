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

using namespace std;

int main(int argc, const char * argv[]) {
    gf256_table_init();
    gf257_table_init();

    for (int i = 0; i < 257; i++) {
        printf("%d ", gf257_exp_table[i]);
        if ((i+1)%16 == 0)
            printf("\n");
    }
    
    cout << endl << endl;
    for (int i = 0; i < 257; i++) {
        printf("%d ", gf257_log_table[i]);
        if ((i+1)%16 == 0)
            printf("\n");
    }
    
    printf("\n\n%d\n", gf257_addinv(32));
    return 0;
}
