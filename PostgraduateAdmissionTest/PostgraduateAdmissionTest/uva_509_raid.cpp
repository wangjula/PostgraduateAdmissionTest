//
//  uva_509_raid.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/5/14.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "uva_509_raid.hpp"

#include <iostream>
#include <cstdio> //oj不支持cout << uppercase << hex << h，用printf("%X", h)重写
using namespace std;
const int maxd = 8;
const int maxs = 65;
const int maxb = 110;
int ds[maxd][maxs*maxb];

bool Chk(int d, int bs, int p) {
    for (int j = 0; j < bs; ++j) {
        int mis = 0, sum = 0, ei = 0;
        for (int i = 0; i < d; ++i) {
            if (ds[i][j] > 1) {
                ++mis;
                ei = i;
            } else {
                sum += ds[i][j];
            }
        }
        if (mis > 1) {
            return false;
        } else if (mis == 1) {
            ds[ei][j] = sum % 2 == p ? 0 : 1;
        } else {
            if (sum % 2 != p) {
                return false;
            }
        }
    }
    return true;
}

void Cont(int d, int s, int b) {
    int cnt = 0, h = 0;
    for (int j = 0; j < b; ++j) {
        int vj = j % d;
        int sj = s * j;
        for (int i = 0; i < d; ++i) {
            if (vj == i) {
                continue;
            }
            for (int k = 0; k < s; ++k) {
                cnt = (cnt + 1) % 4;
                h = (h << 1) + ds[i][sj + k];
                if (cnt == 0) {
                    printf("%X", h);
                    h = 0;
                }
            }
        }
    }
    if (cnt > 0) {
        h = h << (4 - cnt);
        printf("%X", h);
    }
    printf("\n");
}

int test_uva_509_raid() {
    ios::sync_with_stdio(false);
    int d, s, b, no = 0;
    char t, c;
    while (cin >> d && d != 0) {
        cin >> s >> b;
        cin >> t;
        for (int i = 0; i < d; ++i) {
            for (int j = 0; j < s * b; ++j) {
                cin >> c;
                ds[i][j] = c - '0';
            }
        }
        
        int p = t == 'E' ? 0 : 1;
        if (Chk(d, b*s, p)) {
            printf("Disk set %d is valid, contents are: ", ++no);
            Cont(d, s, b);
        } else {
            printf("Disk set %d is invalid.\n", ++no);
        }
    }
	return 0;
}
