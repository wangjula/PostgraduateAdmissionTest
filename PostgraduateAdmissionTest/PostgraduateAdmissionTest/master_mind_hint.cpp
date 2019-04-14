//
//  master_mind_hint.cpp
//  PostgraduateAdmissionTest
//
//  Created by 王久亮 on 2019/4/2.
//  Copyright © 2019年 王久亮. All rights reserved.
//

#include "master_mind_hint.hpp"

void test_master_mind_hint() {
    const int maxn = 100 + 10;
    int a[maxn], b[maxn];
    
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        
        int A, B, turn = 0;
        printf("Game %d:\n", ++turn);
        while (true) {
            A = 0;
            B = 0;
            for (int i = 0; i < n; ++i) {
                scanf("%d", &b[i]);
                if (a[i] == b[i]) {
                    ++A;
                }
            }
            
            if (b[0] == 0) {
                break;
            }
            
            for (int d = 1; d<= 9; ++d) {
                int c1 = 0, c2 = 0;
                for (int i = 0; i < n; ++i) {
                    if (a[i] == d) {
                        ++c1;
                    }
                    if (b[i] == d) {
                        ++c2;
                    }
                }
                B += c1 < c2 ? c1 : c2;
            }
            
            printf("    (%d, %d)\n", A, B - A);
        }
        
    }
}
