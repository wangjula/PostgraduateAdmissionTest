//
//  uva_202_repeating_decimals.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/4/18.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "uva_202_repeating_decimals.hpp"

#include <iostream>
#include <cstring>
using namespace std;

int test_uva_202_repeating_decimals() {
    const int Max_Len = 50 + 1;
    const int Max_Hash_Size = 3000 + 1;
    const char * REPEAT = " = number of digits in repeating cycle";
    int n, m;
    
    int a[Max_Len], ht[Max_Hash_Size];
    while (cin >> n >> m) {
        int cnt = 0, rp_st = 0, rp_ed = 0, old_n = n;
        memset(a, 0, sizeof(a));
        memset(ht, -1, sizeof(ht));
        a[0] = n / m;
        int r = n % m;
        n = r * 10;
        while (true) {
            ++cnt;
            if (ht[r] != -1) {
                rp_st = ht[r];
                rp_ed = cnt;
                break;
            }
            
            if (cnt < Max_Len) {
                a[cnt] = n / m;
            }
            ht[r] = cnt;
            r = n % m;
            n = r * 10;
        }
        
        cout << old_n << "/" << m << " = " << a[0] << ".";
        for (int i = 1; i < rp_st && i < Max_Len; ++i) {
            cout << a[i];
        }
        
        int rp_sz = rp_ed - rp_st;
        cout << "(";
        for (int i = rp_st; (i < rp_st + 50) && (i < rp_ed); ++i) {
            cout << a[i];
        }
        if (rp_sz > 50) {
            cout << "...";
        }
        cout << ")" << endl;
        cout << "   " << rp_sz << REPEAT << endl << endl;
    }
    
	return 0;
}
